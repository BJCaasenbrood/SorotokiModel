classdef Shapes

    properties (Access = public)
        Sdf;
        Fem;
        Gmodel;
        Material;

        options;
        beamsolver;
        solver;
        system;
        pod;

        Length;     
        NDim;       % State dimensions
        NJoint;     % Joint dimension (i.e, NDim/2)
        NInput;
        NNode;      % Number of nodes (spatial discretization)
    end
   
%--------------------------------------------------------------------------
methods  
%----------------------------------------------- MODAL SHAPE RECONSTRUCTION
function obj = Shapes(Input,NModal,varargin) 

    obj.options    = shapesoptions;
    obj.beamsolver = beamoptions;
    obj.solver     = solveroptions;
    obj.system     = struct;
    obj.pod        = struct;

    obj.options.NModal = NModal;
    obj.options.Table  = double(NModal > 0); 
    obj.options.NDof   = sum(obj.options.Table);
    obj.options.Display = @(x) showRenderShapes(x);

    obj.NNode = size(Input,1);
    obj.pod.PODQ = Input;
    obj.pod.PODR = Input;
    
    obj.Length = 100;
    obj.beamsolver.Space = linspace(0,1,obj.NNode); 
    obj.beamsolver.SpaceStep = obj.Length/(obj.NNode);
    
    obj.system.Gravity = zeros(3,1);

    % cross-section SDF
    obj.Sdf      = sCircle(5);
    obj.Material = NeoHookean(0.33,0.33);
    
    obj.options.FilterRadius        = 10;
    obj.options.ContactDistance     = 1e-3;
    obj.options.isVolumetricContact = true;
    obj.options.isRampCompensation  = false;
    obj.solver.Regularization       = 333;
    obj.solver.MaxIteration         = 30;

    obj = vararginParser(obj,varargin{:});

    obj.NJoint = sum(obj.options.NModal);
    obj.NDim   = 2*obj.NJoint;

    if ~isfield(obj.system,'InputMap')
        obj.system.InputMap = @(x) eye(obj.NJoint);
        obj.NInput = obj.NJoint;
    end
    
    obj = rebuild(obj);
end
%---------------------------------------------------------------------- get     
function varargout = get(Shapes,varargin)
    if nargin > 1
        varargout{nargin-1,1} = [];
        for ii = 1:length(varargin)
            varargout{ii,1} = Shapes.(varargin{ii});
        end
    else
        varargout = Shapes.(varargin);
    end
end       
%---------------------------------------------------------------------- set
function Shapes = set(Shapes,varargin)
    Shapes = vararginParser(Shapes,varargin);
end
%----------------------------------------------------------- set base SE(3)
function Shapes = setBase(Shapes,varargin)
if numel(varargin{1}) == 9 || numel(varargin{1}) == 3
    Shapes.g0 = SE3(varargin{1});
else
    Shapes.g0 = varargin{1};
end     
end
%--------------------------------------------------------------- set radius
function Shapes = setRadius(Shapes,varargin)
   if numel(varargin) == 1 && numel(varargin{1}) == 1
       Shapes.TubeRadiusA = varargin{1};
       Shapes.TubeRadiusB = varargin{1};
   elseif numel(varargin) == 1 && numel(varargin{1}) == 2
      R = varargin{1};
      Shapes.TubeRadiusA = R(1);
      Shapes.TubeRadiusB = R(2); 
   elseif numel(varargin) == 1 && numel(varargin{1}) == 3
      R = varargin{1};
      Shapes.TubeRadiusA = R(1);
      Shapes.TubeRadiusB = R(2);  
      Shapes.TubeRadiusAlpha = R(3);
   end
   
   Shapes.Sdf = sCircle(Shapes.TubeRadiusA);
   Shapes = rebuild(Shapes);
end
%----------------------------------------------------------------- set ramp
function Shapes = setRamp(Shapes,x)
    y = clamp(x,0,1);  
    Shapes.TubeRamp = y;
end
%-------------------------------------------------------------- set gravity 
function Shapes = setInputMap(Shapes,varargin)
    Shapes.InputMap = varargin{1};
    G0 = Shapes.InputMap(Shapes);
    Shapes.NInput = size(G0,2);
end
%-------------------------------------------------------------- set gravity 
function Shapes = setMaterial(Shapes,varargin)
   Shapes.Material = varargin{1};
end
%------------------------------------------------------------  add setpoint
function Shapes = addSetpoint(Shapes,varargin)
    if isa(varargin{1},'char')
        %varargin{1} = findNodeMesh(Shapes.Mesh.Node,varargin{1});
    end
    Shapes = addSetpointShapes(Shapes,varargin{1:end});
end
%-------------------------------------------------------------- set gravity 
function Shapes = addGravity(Shapes,varargin)
if isempty(varargin)
     %vec = -9810*Shapes.xia0(4:6);
     varargin{1} = [0;0;-9810];%vec(:);
end
Shapes.system.Gravity = varargin{1};    
end
%-------------------------------------------------------------- set gravity 
function Shapes = addContact(Shapes,varargin)
if isa(varargin{1},'Sdf')
    sdf = varargin{1};
    varargin{1} = @(x) sdf.eval(x);
    Shapes.system.ContactSDF = sdf;
end
    
if numel(varargin) < 2
    varargin{2} = [0,0]; 
end

Shapes = addContactShapes(Shapes,varargin{1:end});
end
%--------------------------------------------------------------- add muscle
function Shapes = addMuscle(Shapes,varargin)
    Shapes.Muscle{end+1} = varargin{1};
end
%------------------------------------------------------------ set reference
function Shapes = reference(Shapes,varargin)

if numel(varargin) == 2
    % two points curve
    X_ = varargin{1}; XL = varargin{2};
    
    % build Cosserat curve in reference
    Shapes.Node0 = [linspace(X_(1),XL(1),Shapes.NNode).', ...
        linspace(X0(2),XL(2),Shapes.NNode).'];
    
    %B = boxhull(Shapes.Node0);
    Shapes.Length = sqrt((XL(1)-X0(1))^2 + (XL(2)-X0(2))^2);
elseif numel(varargin) == 1 && size(varargin{1},2) == 2
    Shapes.Node0 = varargin{1};
    Shapes.NNode = length(Shapes.Node0);
    Shapes.Length = sum(sqrt(sum(diff(Shapes.Node0).^2,2)),1);
end

% build discretization of curve domain
Shapes.Sigma = linspace(0,Shapes.Length,Shapes.NNode);    
Shapes.ds    = Shapes.Length/(Shapes.NNode);

% finds associated nodes from Fem mesh.
if isempty(Shapes.Fem)
    Shapes = GenerateRadialFilter(Shapes);
end

Shapes = rebuild(Shapes);

end   
%------------------------------------------------------------ set reference
function Shapes = rebuild(Shapes,varargin)
    
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
[Jtt, Att] = Shapes.Sdf.inertia;

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

if ~isempty(Shapes.pod.PODR) || ~isempty(Shapes.pod.PODQ)
    
    if length(Shapes.pod.PODQ) ~= Shapes.NNode
        X = linspace(0,Shapes.Length,length(Shapes.pod.PODQ));
        Shapes.pod.PODR = interp1(X,Shapes.pod.PODR, ...
            Shapes.beamsolver.Space*Shapes.Length);
        Shapes.pod.PODQ = interp1(X,Shapes.pod.PODQ, ...
            Shapes.beamsolver.Space*Shapes.Length);
    end
    
    % ensure orthonormality
    if Shapes.options.isOrthonormal
        Shapes.pod.PODR = gsogpoly(Shapes.pod.PODR,Shapes.beamsolver.Space);
        Shapes.pod.PODQ = gsogpoly(Shapes.pod.PODQ,Shapes.beamsolver.Space);
    end
    
    k = 1;
    Shapes.pod.POD = [];
    for ii = 1:numel(Shapes.options.NModal)
        for jj = 1:Shapes.options.NModal(ii)
            if ii == 1
                Shapes.pod.POD(:,k) = Shapes.pod.PODR(:,jj);
            else
                Shapes.pod.POD(:,k) = Shapes.pod.PODQ(:,jj);
            end
            k = k+1;
        end
    end
    
    % rebuild shape-function matrix
    Shapes.pod.Theta = @(x) ShapeFunction(Shapes,x);
end

if ~isa(Shapes.beamsolver.Xi0,'function_handle')
    Shapes.beamsolver.Xi0 = @(x) IntrinsicFunction(Shapes,x);   
end

if ~isempty(Shapes.pod.Theta) 
    
% precompute Theta matrix
FncT = @(x) Shapes.pod.Theta(x);
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
        alpha = lerp(1,1-Shapes.TubeRamp,ii/numel(s));
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

end 
%--------------------------------------------------------------------------
function [Shapes,Kf,Gf] = reconstruct(Shapes,varargin)
    
fem = Shapes.Fem;
t   = fem.Log.t;

set = 1:6;
I6  = eye(6);
xa  = set(logical(Shapes.Table));
Xa  = [];

for ii = 1:numel(xa)
    for jj = 1:Shapes.NModal(ii)
        Xa = [Xa,xa(ii)];
    end
end

Shapes.NDof = sum(Shapes.Table);
Shapes.NDim = sum(Shapes.NModal);
Shapes.Ba   = I6(:,Xa);

Shapes.Gamma = [];
Shapes.Kappa = [];

if isempty(varargin)
   DATASET = 1:numel(t);
else 
   DATASET = unique(round(varargin{1}));
   if DATASET(1) <= 0 
      DATASET = numel(t);
   end
end

for ii = DATASET
    
   N = Shapes.Fem.Log.Node{ii};
   R = Shapes.Fem.Log.Rotation{ii};
   S = Shapes.Fem.Log.Stretch{ii};
 
   [Kf, Gf] = ReconstructField(Shapes,N,R,S);

   Shapes.Gamma = [Shapes.Gamma, Gf-1];
   Shapes.Kappa = [Shapes.Kappa, Kf];
end

% SVD decompostion of snapshot reconstructions
[Ur,Sr,~] = svd(full(Shapes.Kappa*Shapes.Kappa.'));
[Uq,Sq,~] = svd(full(Shapes.Gamma*Shapes.Gamma.'));

Er = (diag(Sr).^0.5);
Eq = (diag(Sq).^0.5);

Shapes.PODEnergy{2} = Eq/sum(Eq);
Shapes.PODEnergy{1} = Er/sum(Er);

for ii = 1:10
    PODr = Ur(:,ii);
    Shapes.PODR = [Shapes.PODR,PODr];
end

% gram–schmidt orthogonalization, i.e., int_X y1*y2 ds = 1
Shapes.PODR = gsogpoly(Shapes.PODR,Shapes.Sigma);

for ii = 1:10
    PODq = Uq(:,ii);
    Shapes.PODQ = [Shapes.PODQ, PODq];
end

% gram–schmidt orthogonalization
Shapes.PODQ = gsogpoly(Shapes.PODQ,Shapes.Sigma);

k = 1;
Shapes.POD = [];
for ii = 1:numel(Shapes.NModal)
for jj = 1:Shapes.NModal(ii)
    if ii == 1
        Shapes.POD(:,k) = Shapes.PODR(:,jj);
    else
        Shapes.POD(:,k) = Shapes.PODQ(:,jj);
    end
    k = k+1;
end
end
    
% rebuild shape-function matrix
Shapes.Theta = @(x) ShapeFunction(Shapes,x);

% rebuild shape-function matrix
Shapes = Shapes.rebuild();

end
%--------------------------------------------------------- compute jacobian
function [g, J] = string(Shapes,q)
    
assert(numel(q) == Shapes.NJoint,['Dimension of joint inconstistent ',...
        'with POD matrix. Please check your input dimensions dim(q).']);

% ensures robustness for near-zero singularities in some PCC models
q = q(:) + 1e-12;

[g, J] = computeForwardKinematicsFast_mex(q,q*0,... % states
    Shapes.beamsolver.SpaceStep,...         % spatial steps
    Shapes.beamsolver.g0(1:3,4),...         % position zero
    Shapes.beamsolver.g0(1:3,1:3),...       % phi zeroclc
    Shapes.beamsolver.Xi0Eval,...    % intrinsic strain vector
    Shapes.beamsolver.ThetaEval,...  % evaluated Theta matrix
    Shapes.beamsolver.DofMap);
end
%--------------------------------------------------------- compute jacobian
function Shapes = compute(Shapes,varargin)

noBuild = false;
for ii = 1:2:numel(varargin)
    if strcmpi(varargin{ii},'nobuild')
        noBuild = varargin{ii+1};
    end
end

if ~noBuild
    Shapes = assembleGlobalShapes(Shapes);
else
    Shapes = assembleGlobalQuickShapes(Shapes);
end

Shapes = assembleBoundaryShapes(Shapes);

Shapes.system.fResidual = Shapes.system.fElastic + Shapes.system.fDamping ... 
    + Shapes.system.fCoriolis - Shapes.system.fInput + Shapes.system.fBody;

end
%--------------------------------------------------------- compute jacobian
function [dx, Shapes] = flow(Shapes,q,varargin)
if ~isempty(varargin)
    u = varargin{1}(:);
    t = varargin{2}(:);
else
    t = 0;
    u = zeros(Shapes.NInput,1);
end

if numel(varargin) == 3
    Build = varargin{3};
else
    Build = true;
end
    
NQ   = Shapes.NJoint;
Q    = q(1:NQ);
dQ   = q(NQ+1:2*NQ);
    
if Build
[g,J,eta] = computeForwardKinematicsFast_mex(Q,dQ,... % states
    Shapes.ds,...         % spatial steps
    Shapes.g0(1:3,4),...         % position zero
    Shapes.g0(1:3,1:3),...       % phi zero
    Shapes.Xi0Eval,...    % intrinsic strain vector
    Shapes.ThetaEval,...  % evaluated Theta matrix
    Shapes.Ba);

[M_,C_,K_,R_,fg_,~,...
    gam_,Phi_,J_,dJdt_,Grav,Kin] = computeLagrangianFast_mex(...
    Q,dQ,...
    Shapes.ds,...
    Shapes.g0(1:3,4),...
    Shapes.g0(1:3,1:3),...
    Shapes.Xi0Eval,...
    Shapes.ThetaEval,...
    Shapes.MuscleEval,...
    Shapes.Ba,...
    Shapes.KttEval,...
    Shapes.MttEval,...
    Shapes.Material.Damping,...
    Shapes.Gravity);

% overwrite dynamics
Shapes.Log.EL.M     = M_;
Shapes.Log.EL.C     = C_;
Shapes.Log.EL.R     = R_;
Shapes.Log.EL.K     = K_;
Shapes.Log.EL.fg    = fg_;
Shapes.Log.EL.J     = J_;
Shapes.Log.EL.dJdt  = dJdt_;
Shapes.Log.EL.fc    = 0;
Shapes.Log.EL.dfcdq = 0;

% overwrite energies
Shapes.Log.PH.Kinetic = Kin;
Shapes.Log.PH.Elastic = 0.5*Q.'*K_*Q;
Shapes.Log.PH.Gravity = Grav;
Shapes.Log.PH.dVdq    = K_*Q + fg_;

% if isempty(Shapes.Muscle)
%    Shapes.Log.EL.G = eye(Shapes.NJoint);
% else
%    Shapes.Log.EL.G = G_; 
% end

Shapes.Log.EL.G = Shapes.InputMap(Shapes);

% if ~isempty(Shapes.Muscle)
%    P = computeMuscleGroups(Shapes); 
% end

% pre-compute Minverse
Minv = M_\eye(numel(Q));
Shapes.Log.EL.Minv = Minv;

Shapes.Log.t    = t;
Shapes.Log.q    = Q;
Shapes.Log.dq   = dQ;
Shapes.Log.p    = M_*dQ;

Shapes.Log.FK.g    = g;
Shapes.Log.FK.J    = J;
Shapes.Log.FK.eta  = eta;
Shapes.Log.FK.Node = reshape(g(1:3,4,:),3,[]).';
Shapes.Log.FK.L    = sum(sqrt(sum(diff(Shapes.Log.FK.Node).^2,2))) ...
    + Shapes.Length/Shapes.NNode;

Shapes.Log.FK.gam = gam_;
Shapes.Log.FK.Phi = Phi_;

if ~isempty(Shapes.Contact)
   [Fc,Wc,Wt] = computeContactWrench(Shapes,Q,dQ);
   
   Shapes.Log.EL.fc = Fc;
%    
%    if norm(Fc) > 0
%        [Kc, Dc] = computeContactJacobian(Shapes,Q,dQ);
%        Shapes.Log.EL.K = Shapes.Log.EL.K + Kc;
%        Shapes.Log.EL.R = Shapes.Log.EL.R + Dc;
%    end

   Nds = Shapes.Log.FK.Node;
   I = ~~sign(sum(abs(Wc),2));
   
   Shapes.Log.Con.Wc = Wc(I,:);    % Wrench normal contact
   Shapes.Log.Con.Wt = Wt(I,:);    % Wrench tangent contact
   Shapes.Log.Con.Node = Nds(I,:);
end

end

% flow field
dx = [dQ; ...
     Shapes.Log.EL.Minv*(Shapes.Log.EL.G*u - Shapes.Log.EL.C*dQ - ...
           Shapes.Log.EL.K*Q - Shapes.Log.EL.R*dQ - ...
           Shapes.Log.EL.fg  + Shapes.Log.EL.fc)];
    
end  
%--------------------------------------------------------- compute jacobian
function H = hessian(Shapes,~,varargin)

Minv = Shapes.Log.EL.Minv;
Nq   = Shapes.NJoint;

H                      = zeros(Shapes.NDim,Shapes.NDim);
H(1:Nq,Nq+1:2*Nq)      = eye(Nq);
H(Nq+1:2*Nq,1:Nq)      = -Minv*(Shapes.Log.EL.K + Shapes.Log.EL.dfcdq);
H(Nq+1:2*Nq,Nq+1:2*Nq) = -Minv*(Shapes.Log.EL.R + Shapes.Log.EL.C);

end
%----------------------------------------------------- tangent point energy
end

methods (Access = private)
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
                THETA = Shapes.pod.PODR(:,ii);   % angular strains
            else
                THETA = Shapes.pod.PODQ(:,ii);  % linear strains
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
end
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