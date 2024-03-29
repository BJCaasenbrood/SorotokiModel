classdef Shapes

    properties (Access = public)
        Sdf;
        Fem;
        Gmodel;
        Material;

        options;
        beamsolver;
        geometry;
        childern;
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
function obj = Shapes(Basis,ModalDof,varargin) 

    obj.options    = shapesoptions;
    obj.beamsolver = beamoptions;
    obj.solver     = solveroptions;
    obj.geometry   = geometryoptions;
    obj.system     = struct;
    obj.system.pod = struct;
    
    obj.options.NModal = ModalDof;
    obj.options.Table  = double(ModalDof > 0); 
    obj.options.NDof   = sum(obj.options.Table);

    obj.NNode = size(Basis,1);
    obj.system.pod.PODQ = Basis;
    obj.system.pod.PODR = Basis;
    
    obj.Length = 100;
    obj.beamsolver.Space = linspace(0,1,obj.NNode); 
    obj.beamsolver.SpaceStep = obj.Length/(obj.NNode);
    
    obj.system.Gravity = zeros(3,1);
    obj.Material = NeoHookean(1.0,0.33);
    
    obj.options.FilterRadius        = 10;
    obj.options.isRampCompensation  = false;
    obj.solver.Regularization       = 333;
    obj.solver.MaxIteration         = 100;
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
    + Shapes.system.fCoriolis - Shapes.system.fInput + Shapes.system.fBody ...
    - Shapes.system.fDrag;

end
%--------------------------------------------------------- compute jacobian
% function [dx, Shapes] = flow(Shapes,q,varargin)
% if ~isempty(varargin)
%     u = varargin{1}(:);
%     t = varargin{2}(:);
% else
%     t = 0;
%     u = zeros(Shapes.NInput,1);
% end

% if numel(varargin) == 3
%     Build = varargin{3};
% else
%     Build = true;
% end
    
% NQ   = Shapes.NJoint;
% Q    = q(1:NQ);
% dQ   = q(NQ+1:2*NQ);
    
% if Build
% [g,J,eta] = computeForwardKinematicsFast_mex(Q,dQ,... % states
%     Shapes.ds,...         % spatial steps
%     Shapes.g0(1:3,4),...         % position zero
%     Shapes.g0(1:3,1:3),...       % phi zero
%     Shapes.Xi0Eval,...    % intrinsic strain vector
%     Shapes.ThetaEval,...  % evaluated Theta matrix
%     Shapes.Ba);

% [M_,C_,K_,R_,fg_,~,...
%     gam_,Phi_,J_,dJdt_,Grav,Kin] = computeLagrangianFast_mex(...
%     Q,dQ,...
%     Shapes.ds,...
%     Shapes.g0(1:3,4),...
%     Shapes.g0(1:3,1:3),...
%     Shapes.Xi0Eval,...
%     Shapes.ThetaEval,...
%     Shapes.MuscleEval,...
%     Shapes.Ba,...
%     Shapes.KttEval,...
%     Shapes.MttEval,...
%     Shapes.Material.Damping,...
%     Shapes.Gravity);

% % overwrite dynamics
% Shapes.Log.EL.M     = M_;
% Shapes.Log.EL.C     = C_;
% Shapes.Log.EL.R     = R_;
% Shapes.Log.EL.K     = K_;
% Shapes.Log.EL.fg    = fg_;
% Shapes.Log.EL.J     = J_;
% Shapes.Log.EL.dJdt  = dJdt_;
% Shapes.Log.EL.fc    = 0;
% Shapes.Log.EL.dfcdq = 0;

% % overwrite energies
% Shapes.Log.PH.Kinetic = Kin;
% Shapes.Log.PH.Elastic = 0.5*Q.'*K_*Q;
% Shapes.Log.PH.Gravity = Grav;
% Shapes.Log.PH.dVdq    = K_*Q + fg_;

% % if isempty(Shapes.Muscle)
% %    Shapes.Log.EL.G = eye(Shapes.NJoint);
% % else
% %    Shapes.Log.EL.G = G_; 
% % end

% Shapes.Log.EL.G = Shapes.InputMap(Shapes);

% % if ~isempty(Shapes.Muscle)
% %    P = computeMuscleGroups(Shapes); 
% % end

% % pre-compute Minverse
% Minv = M_\eye(numel(Q));
% Shapes.Log.EL.Minv = Minv;

% Shapes.Log.t    = t;
% Shapes.Log.q    = Q;
% Shapes.Log.dq   = dQ;
% Shapes.Log.p    = M_*dQ;

% Shapes.Log.FK.g    = g;
% Shapes.Log.FK.J    = J;
% Shapes.Log.FK.eta  = eta;
% Shapes.Log.FK.Node = reshape(g(1:3,4,:),3,[]).';
% Shapes.Log.FK.L    = sum(sqrt(sum(diff(Shapes.Log.FK.Node).^2,2))) ...
%     + Shapes.Length/Shapes.NNode;

% Shapes.Log.FK.gam = gam_;
% Shapes.Log.FK.Phi = Phi_;

% if ~isempty(Shapes.Contact)
%    [Fc,Wc,Wt] = computeContactWrench(Shapes,Q,dQ);
   
%    Shapes.Log.EL.fc = Fc;
% %    
% %    if norm(Fc) > 0
% %        [Kc, Dc] = computeContactJacobian(Shapes,Q,dQ);
% %        Shapes.Log.EL.K = Shapes.Log.EL.K + Kc;
% %        Shapes.Log.EL.R = Shapes.Log.EL.R + Dc;
% %    end

%    Nds = Shapes.Log.FK.Node;
%    I = ~~sign(sum(abs(Wc),2));
   
%    Shapes.Log.Con.Wc = Wc(I,:);    % Wrench normal contact
%    Shapes.Log.Con.Wt = Wt(I,:);    % Wrench tangent contact
%    Shapes.Log.Con.Node = Nds(I,:);
% end

% end

% % flow field
% dx = [dQ; ...
%      Shapes.Log.EL.Minv*(Shapes.Log.EL.G*u - Shapes.Log.EL.C*dQ - ...
%            Shapes.Log.EL.K*Q - Shapes.Log.EL.R*dQ - ...
%            Shapes.Log.EL.fg  + Shapes.Log.EL.fc)];
    
% end  
%--------------------------------------------------------- compute jacobian
% function H = hessian(Shapes,~,varargin)

% Minv = Shapes.Log.EL.Minv;
% Nq   = Shapes.NJoint;

% H                      = zeros(Shapes.NDim,Shapes.NDim);
% H(1:Nq,Nq+1:2*Nq)      = eye(Nq);
% H(Nq+1:2*Nq,1:Nq)      = -Minv*(Shapes.Log.EL.K + Shapes.Log.EL.dfcdq);
% H(Nq+1:2*Nq,Nq+1:2*Nq) = -Minv*(Shapes.Log.EL.R + Shapes.Log.EL.C);

% end
%----------------------------------------------------- tangent point energy
end

end

