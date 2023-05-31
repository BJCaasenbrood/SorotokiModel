classdef Shapes

    properties (Access = public)
        Sdf;        % (if assigned) SDF model
        Fem;        % (if assigned) Fem model
        Gmodel;     % Rendering model
        Material;   % Materials properties

        options;    % general options
        beamsolver; % structural solver (pre-compute)
        geometry;   % geometry information of shape
        solver;     % dynamic solver 
        system;     % system struct

        Length;     % Length of the soft shape
        NDim;       % State dimensions
        NJoint;     % Joint dimension (i.e, NDim/2)
        NInput;     % Input dimension 
        NNode;      % Number of nodes (spatial discretization)
    end
   
%--------------------------------------------------------------------------
methods  
%----------------------------------------------- MODAL SHAPE RECONSTRUCTION
function obj = Shapes(Input,NModal,varargin) 

    obj.options    = shapesoptions;
    obj.beamsolver = beamoptions;
    obj.solver     = solveroptions;
    obj.geometry   = geometryoptions;
    obj.system     = struct;
    obj.system.pod = struct;

    obj.options.NModal = NModal;
    obj.options.Table  = double(NModal > 0); 
    obj.options.NDof   = sum(obj.options.Table);
    obj.options.Display = @(x) showRenderShapes(x);

    obj.NNode = size(Input,1);
    obj.system.pod.PODQ = Input;
    obj.system.pod.PODR = Input;
    
    obj.Length = 100;
    obj.beamsolver.Space = linspace(0,1,obj.NNode); 
    obj.beamsolver.SpaceStep = obj.Length/(obj.NNode);
    
    obj.system.Gravity = zeros(3,1);
    obj.Material = NeoHookean(0.33,0.33);
    
    obj.options.FilterRadius        = 10;
    obj.options.ContactDistance     = 1e-3;
    obj.options.isVolumetricContact = true;
    obj.options.isRampCompensation  = false;
    obj.solver.Regularization       = 333;
    obj.solver.MaxIteration         = 30;
    obj.options.Texture = matcap_bluebase;

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
    Shapes.beamsolver.g0 = SE3(varargin{1});
else
    Shapes.beamsolver.g0 = varargin{1};
end     
end
%--------------------------------------------------------------- set radius
function Shapes = setRadius(Shapes,varargin)
   if numel(varargin) == 1 && numel(varargin{1}) == 1
       Shapes.geometry.TubeRadiusA = varargin{1};
       Shapes.geometry.TubeRadiusB = varargin{1};
   elseif numel(varargin) == 1 && numel(varargin{1}) == 2
      R = varargin{1};
      Shapes.geometry.TubeRadiusA = R(1);
      Shapes.geometry.TubeRadiusB = R(2); 
   elseif numel(varargin) == 1 && numel(varargin{1}) == 3
      R = varargin{1};
      Shapes.geometry.TubeRadiusA = R(1);
      Shapes.geometry.TubeRadiusB = R(2);  
      Shapes.geometry.TubeRamp = R(3);
    elseif numel(varargin) == 1 && numel(varargin{1}) == 4
        R = varargin{1};
        Shapes.geometry.TubeRadiusA = R(1);
        Shapes.geometry.TubeRadiusB = R(2);  
        Shapes.geometry.TubeRamp    = R(3);      
        Shapes.geometry.TubeAlpha   = R(4);      
   end
   
   Shapes.geometry.Sdf = sCircle(Shapes.geometry.TubeRadiusA);
   Shapes = rebuild(Shapes);
end
%----------------------------------------------------------------- set ramp
function Shapes = setRamp(Shapes,x)
    y = clamp(x,0,1);  
    Shapes.TubeRamp = y;
end
%-------------------------------------------------------------- set gravity 
function Shapes = setInputMap(Shapes,varargin)
    Shapes.system.InputMap = varargin{1};
    G0 = Shapes.system.InputMap(Shapes);
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
        varargin{1} = [0; 0;-9810];
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
function Shapes = rebuild(Shapes,varargin)
    Shapes = rebuildShapes(Shapes);
end 
%--------------------------------------------------- increment dynamic time
function Shapes = update_states(Shapes)
    Shapes = updateStatesShapes(Shapes);
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

t = 0;
u = zeros(Shapes.NInput,1);    
if ~isempty(varargin)
    u = varargin{1}(:);
    t = varargin{2}(:);
end

Build = true;
if numel(varargin) == 3
    Build = varargin{3};  
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

end

