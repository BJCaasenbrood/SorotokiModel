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
Shapes.NDim   = 2 * Shapes.NJoint;

Shapes.solver.sol.x  = zeros(Shapes.NJoint,1);
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
% Ktt = diag(voightextraction(Ktt));
% E  = Shapes.Material.getModulus();
% Nu = Shapes.Material.Nu;
% G  = E/(2*(Nu+1));
% KK = pi*diag([G,E,E,E,G,G]);

Jsec = blkdiag(Shapes.beamsolver.Jtt,Shapes.beamsolver.Att*eye(3));
Shapes.beamsolver.Ktt = diag(diag(Jsec)) * Ktt;
Dsec = blkdiag(zeros(3),diag([0.1,1,1]) * Shapes.beamsolver.Att*eye(3));

if isfield(Shapes.system,'Drag')
    Shapes.beamsolver.Dtt = diag(diag(Dsec)) * Shapes.system.Drag;
else
    Shapes.beamsolver.Dtt = Ktt * 0;
end

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
    Shapes.pod.POD = [];
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

Xi0 = Shapes.beamsolver.Xi0;
if numel(Xi0) == 6
    Shapes.system.pod.Xi0 = @(x) Xi0(:);
else
    Shapes.system.pod.Xi0 = @(x) IntrinsicFunction(Shapes, x);
end

if ~isempty(Shapes.system.pod.Theta) 
    Shapes = assembleGaussQuadrature(Shapes);    
    Shapes = assembleGaussEvals(Shapes);        
end

if isfield(Shapes.system,'Actuator')
    M = numel(Shapes.system.Actuator);
    N = numel(s);
    h = mean(diff(s/Shapes.Length));
    
    Shapes.system.FiberEval = zeros(N,6,M);
    [P0, F0] = assembleActuatorGroupShapes(Shapes,s/Shapes.Length);

    for ii = 1:M
        Shapes.system.ActuatorMesh{ii} = zeros(4,4,numel(s));
    for jj = 1:numel(s)
        Shapes.system.ActuatorMesh{ii}(1:3,4,jj) = P0(jj,1:3);
        Shapes.system.ActuatorMesh{ii}(1:3,1:3,jj) = Shapes.beamsolver.g0(1:3,1:3);
    end
    end
    
    for ii = 1:M
       % compute derivative along the actuator direction 
       [~,dP0] = gradient(F0(:,:,ii),h); 

       %dN0 = dP0 ./ (vecnorm(F0,2,2) + 1e-6);
       Shapes.beamsolver.ActuatorEval(:,1:3,ii) = F0(:,:,ii);
       Shapes.beamsolver.ActuatorEval(:,4:6,ii) = dP0;
    end
    
    Shapes.NInput = M;
else
%    N = 2 * numel(Shapes.beamsolver.Space);
%    Shapes.beamsolver.ActuatorEval = zeros(N,6,1);
end

Shapes = assembleContactMeshShapes(Shapes);
Shapes = assembleSelfContactEdge(Shapes);
Shapes = compute(Shapes);

end

%%
function Xi = ShapeFunction(Shapes,X)

    k  = 1;
    X0 = Shapes.beamsolver.Space;
    Pc = cell(Shapes.options.NDof,1); 
    X  = zclamp(X/Shapes.Length,0,1);

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

    Xi = blkdiag(Pc{:});
end

%%
function Xi = IntrinsicFunction(Shapes,X)
    X0 = Shapes.beamsolver.Space;
    S0 = Shapes.beamsolver.Xi0;
    X  = zclamp(X/Shapes.Length,0,1);
    
    Xi = zeros(6,1);

    for jj = 1:6
        Xi(jj) = interp1(X0, S0(:,jj), X);
    end
end

%%
function y = voightextraction(X)
    y(1,1) = X(2,3);
    y(2,1) = 2*X(6,6);
    y(3,1) = 2*X(6,6);
    y(4,1) = X(1,1);
    y(5,1) = X(2,1);
    y(6,1) = X(3,1);
end