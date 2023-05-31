function Shapes = rebuildShapes(Shapes,varargin)

Shapes = vararginParser(Shapes,varargin{:});

set = 1:6;
I6  = eye(6);
Xa  = [];

for ii = 1:6
    for jj = 1:Shapes.options.NModal(ii)
        Xa = [Xa,set(ii)];
    end
end

Shapes.NJoint = sum(Shapes.options.NModal);
Shapes.NDim  = 2*Shapes.NJoint;
Shapes.solver.sol.x  = zeros(Shapes.NJoint,1) + 1e-6;
Shapes.solver.sol.dx = zeros(Shapes.NJoint,1);

Shapes.beamsolver.DofMap = I6(:,Xa);
Shapes.beamsolver.Space  = linspace(0,1,Shapes.NNode);
Shapes.beamsolver.SpaceStep = Shapes.Length/(Shapes.NNode);

Geval = Shapes.system.InputMap(zeros(Shapes.NJoint,1));
Shapes.NInput = size(Geval,2);
[Jtt, Att] = Shapes.geometry.Sdf.inertia;

P = eye(3);
P = [P(:,3),P(:,1),P(:,2)];

Shapes.beamsolver.Att = Att;
Shapes.beamsolver.Jtt = P.'*Jtt*P;
Shapes.beamsolver.Mtt = Shapes.Material.params.Rho * ...
    blkdiag(Shapes.beamsolver.Jtt,Shapes.beamsolver.Att*eye(3));

% linear approximation of the stiffness
[~,Ktt] = Shapes.Material.PiollaStress(eye(3));
Ktt = 4.15*diag(voightextraction(Ktt));

% E  = Shapes.Material.getModulus();
% Nu = Shapes.Material.Nu;
% G  = E/(2*(Nu+1));
% KK = pi*diag([G,E,E,E,G,G]);
Jsec = blkdiag(Shapes.beamsolver.Jtt,Shapes.beamsolver.Att*eye(3));
Shapes.beamsolver.Ktt = diag(diag(Jsec))*Ktt;
Shapes.beamsolver.Dtt = Shapes.Material.params.Zeta * ...
    Shapes.beamsolver.Ktt;
  
if ~isempty(Shapes.Fem)
    Shapes = GenerateRadialFilter(Shapes);
end

if ~isempty(Shapes.system.pod.PODR) || ~isempty(Shapes.system.pod.PODQ)
    
    if length(Shapes.system.pod.PODQ) ~= Shapes.NNode
        X = linspace(0,Shapes.Length,length(Shapes.system.pod.PODQ));
        Shapes.system.pod.PODR = interp1(X,Shapes.system.pod.PODR, ...
            Shapes.beamsolver.Space*Shapes.Length);
        Shapes.system.pod.PODQ = interp1(X,Shapes.system.pod.PODQ, ...
            Shapes.beamsolver.Space*Shapes.Length);
    end
    
    % ensure orthonormality
    if Shapes.options.isOrthonormal
        Shapes.system.pod.PODR = gsogpoly(Shapes.system.pod.PODR,Shapes.beamsolver.Space);
        Shapes.system.pod.PODQ = gsogpoly(Shapes.system.pod.PODQ,Shapes.beamsolver.Space);
    end
    
    k = 1;
    for ii = 1:numel(Shapes.options.NModal)
        for jj = 1:Shapes.options.NModal(ii)
            if ii == 1
                Shapes.system.pod.POD(:,k) = Shapes.system.pod.PODR(:,jj);
            else
                Shapes.system.pod.POD(:,k) = Shapes.system.pod.PODQ(:,jj);
            end
            k = k+1;
        end
    end
    
    % rebuild shape-function matrix
    Shapes.system.pod.Theta = @(x) ShapeFunction(Shapes,x);
end

if ~isa(Shapes.beamsolver.Xi0,'function_handle')
    Shapes.beamsolver.Xi0 = @(x) IntrinsicFunction(Shapes,x);   
end

if ~isempty(Shapes.system.pod.Theta) 
    
% precompute Theta matrix
FncT = @(x) Shapes.system.pod.Theta(x);
FncX = @(x) Shapes.beamsolver.Xi0(x);
s   = sort([Shapes.beamsolver.Space*Shapes.Length,...
            Shapes.beamsolver.Space*Shapes.Length + ...
            (2/3)*Shapes.beamsolver.SpaceStep]);

[nx,ny] = size(FncT(0));
Shapes.beamsolver.ThetaEval = zeros(nx,ny,numel(s));
Shapes.beamsolver.Xi0Eval   = zeros(6,1,numel(s));
Shapes.beamsolver.KttEval   = zeros(6,6,numel(s));
Shapes.beamsolver.MttEval   = zeros(6,6,numel(s));

for ii = 1:numel(s)
    Shapes.beamsolver.ThetaEval(:,:,ii) = FncT(s(ii));
    Shapes.beamsolver.Xi0Eval(:,1,ii)   = FncX(s(ii));
    if Shapes.options.isRampCompensation
        TubeRamp = 0.8;
        alpha = lerp(1,1-TubeRamp,ii/numel(s));
        Shapes.beamsolver.KttEval(:,:,ii)   = (alpha)^2 * Shapes.beamsolver.Ktt;
        Shapes.beamsolver.MttEval(:,:,ii)   = (alpha)^2 * Shapes.beamsolver.Mtt;
    else
        Shapes.beamsolver.KttEval(:,:,ii)   = Shapes.beamsolver.Ktt;
        Shapes.beamsolver.MttEval(:,:,ii)   = Shapes.beamsolver.Mtt;
    end
end
end

if isfield(Shapes.system,'Fiber')
    M = numel(Shapes.system.Fiber);
    N = numel(s);
    h = mean(diff(s/Shapes.Length));
    
    Shapes.system.FiberEval = zeros(N,6,M);
    [~, P0] = computeFiberBundle(Shapes,s/Shapes.Length);
    
    for ii = 1:M
       % compute derivative along the tendon 
       [~,dP0] = gradient(P0(:,:,ii),h); 

       Shapes.system.FiberEval(:,1:3,ii) = P0(:,:,ii);
       Shapes.system.FiberEval(:,4:6,ii) = dP0;
    end
    
    Shapes.NInput = M;
else
   N = 2 * numel(Shapes.beamsolver.Space);
   Shapes.beamsolver.FiberEval = zeros(N,6,1);
end

Shapes = assembleContactMeshShapes(Shapes);
Shapes = compute(Shapes);

end

%--------------------------------------------- isomorphism from R3 to so(3)
function y = voightextraction(X)
    y(1,1) = X(2,3);
    y(2,1) = 2*X(4,4);
    y(3,1) = 2*X(4,4);
    y(4,1) = X(1,1);
    y(5,1) = X(2,1);
    y(6,1) = X(3,1);
end

%---------------------------------------------------------------------- set
function P = ShapeFunction(Shapes,X)

    k  = 1;
    X0 = Shapes.beamsolver.Space;
    Pc = cell(Shapes.options.NDof,1); 
    %X  = zclamp(X,0,Shapes.Length); % make bounded
    X = zclamp(X/Shapes.Length,0,1);

    % construct shape-matrix 
    for jj = 1:6
        for ii = 1:Shapes.options.NModal(jj)
            
            if jj < 4
                THETA = Shapes.system.pod.PODR(:,ii);   % angular strains
            else
                THETA = Shapes.system.pod.PODQ(:,ii);  % linear strains
            end
            % not sure if interp1 is best/fastest option? 
            % maybe inverse lerp?
            Pc{k,1} = interp1(X0,THETA,X);
            k = k + 1;
        end
    end

    P = blkdiag(Pc{:});

end
%---------------------------------------------------------------------- set
function P = IntrinsicFunction(Shapes,X)
    P = Shapes.beamsolver.Xi0;
end
%--------------------------------------------- isomorphism from R3 to so(3)