function Shapes = assembleGlobalShapes(Shapes)

Q  = Shapes.solver.sol.x;
dQ = Shapes.solver.sol.dx;
G0 = Shapes.solver.sol.g0;

if ~isempty(Shapes.options.loadingFactor)
   beta = Shapes.options.loadingFactor;
else
   beta = 1;
end

if ~isfield(Shapes.system,'Drag')
    [RhoD, Ct, Cp] = deal(0);
else
    RhoD = Shapes.system.Drag.params.Rho;
    Ct = Shapes.system.Drag.params.Ct;
    Cp = Shapes.system.Drag.params.Cp;
end

ViscousDragParameters = [RhoD; Ct; Cp; 
    Shapes.geometry.TubeRadiusA; Shapes.geometry.TubeRamp];

% compute the forward kinematics beam, jacobian and dJacdt
[g, J, Jt] = computeFreeForwardKinematicsGaussFast(Q,dQ,...
    G0(1:3,4),...         % position zero
    G0(1:3,1:3),...       % phi zero
    Shapes.beamsolver.evalLocal.Xi0,...     % intrinsic strain vector
    Shapes.beamsolver.evalLocal.Theta,...   % evaluated Theta matrix
    Shapes.beamsolver.DofMap,...            % dof to strain mapping
    Shapes.beamsolver.BaseDofMap,...        % dof to base vel mapping
    Shapes.beamsolver.evalLocal.weights,... % gauss weights
    Shapes.beamsolver.evalLocal.points);    % gauss points    

% keyboard;

% compute inertia, coriolis, stiffness and gravity vector
[M_, C_, K_, fg_, D_] = computeFreeLagrangianGaussFast_mex(Q,dQ,...
    g, J, Jt,...      
    Shapes.beamsolver.evalLocal.Theta,...          
    Shapes.beamsolver.DofMap,... 
    Shapes.beamsolver.BaseDofMap,... 
    Shapes.beamsolver.evalLocal.MttEval,...
    Shapes.beamsolver.evalLocal.KttEval,...
    ViscousDragParameters,...
    Shapes.system.Gravity,...
    Shapes.beamsolver.evalLocal.weights,...
    Shapes.beamsolver.evalLocal.points);         

% transform jacobian from local into global (static) frame
[J, dJdt_, eta] = computeFrameChangeFast(dQ,g,J,Jt);

% derive damping matrix from stiffness matrices
R_ = K_ * Shapes.Material.params.Zeta;

% assign dynamic variables
Shapes.system.Mass      = M_;
Shapes.system.Damping   = R_;
Shapes.system.Coriolis  = C_;
Shapes.system.Viscous   = D_;
Shapes.system.Stiffness = K_;
Shapes.system.Tangent   = K_;

% assign kinematic variables
Shapes.system.Jacobian   = J;
Shapes.system.dJacobian  = dJdt_;
Shapes.system.Backbone   = g;
Shapes.system.Velocity   = eta;

% assign forces
Shapes.system.fBody      = beta * fg_;
Shapes.system.fElastic   = K_ * Q;
Shapes.system.fDamping   = R_ * dQ;
Shapes.system.fCoriolis  = C_ * dQ;
Shapes.system.fDrag      = D_ * dQ;

if isfield(Shapes.system,'Actuator')
    Shapes.system.Input = G;
    Shapes.system.InputMap = @(x) G;
else
    Shapes.system.Input = Shapes.system.InputMap([]);
end
    
end
































% function Shapes = assembleGlobalShapes(Shapes)

%     Q  = Shapes.solver.sol.x;
%     dQ = Shapes.solver.sol.dx;
    
%     beta = 1;
%     if ~isempty(Shapes.options.loadingFactor)
%        beta = Shapes.options.loadingFactor;
%     end
    
%     % [g, J, Jt] = computeForwardKinematicsGaussFast_mex(Q,dQ,...
%     %     Shapes.beamsolver.g0(1:3,4),...         % position zero
%     %     Shapes.beamsolver.g0(1:3,1:3),...       % phi zeroclc
%     %     Shapes.beamsolver.evalLocal.Xi0,...     % intrinsic strain vector
%     %     Shapes.beamsolver.evalLocal.Theta,...   % evaluated Theta matrix
%     %     Shapes.beamsolver.DofMap,...            % dof to strain mapping
%     %     Shapes.beamsolver.evalLocal.weights,...
%     %     Shapes.beamsolver.evalLocal.points);    % gauss weights    
    
%     % [M_, C_, K_, fg_] = computeLagrangianGaussFast_mex(Q,dQ,...
%     %     g,...       % evaluated transformation
%     %     J,...       % evaluated Jacobian matrix
%     %     Jt,...      % evalatured time-Jacobian
%     %     Shapes.beamsolver.evalLocal.Theta,...            % dof to strain mapping
%     %     Shapes.beamsolver.DofMap,...                     % dof to strain mapping
%     %     Shapes.beamsolver.evalLocal.MttEval,...
%     %     Shapes.beamsolver.evalLocal.KttEval,...
%     %     Shapes.beamsolver.evalLocal.DttEval,...
%     %     Shapes.system.Gravity,...
%     %     Shapes.beamsolver.evalLocal.weights,...
%     %     Shapes.beamsolver.evalLocal.points);         
    
%     % [g, J, eta] = computeForwardKinematicsFast_mex(Q,dQ,... % states
%     %     Shapes.beamsolver.SpaceStep,...     % spatial steps
%     %     Shapes.beamsolver.g0(1:3,4),...     % position zero
%     %     Shapes.beamsolver.g0(1:3,1:3),...   % phi zero
%     %     Shapes.beamsolver.Xi0Eval,...       % intrinsic strain vector
%     %     Shapes.beamsolver.ThetaEval,...     % evaluated Theta matrix
%     %     Shapes.beamsolver.DofMap);
    
%     [J, dJdt_, eta] = computeFrameChangeFast(dQ,g,J,Jt);
%     R_ = K_ * Shapes.Material.params.Zeta;
    
%     % D_ = K_ * 0;
%     % [M_, C_, K_,R_,D_,fg_,G,...
%     %     ~,~,~,dJdt_,~,~] = computeLagrangianFast_mex(Q,dQ,...
%     %     Shapes.beamsolver.SpaceStep,...    % spatial steps
%     %     Shapes.beamsolver.g0(1:3,4),...    % position zero
%     %     Shapes.beamsolver.g0(1:3,1:3),...  % phi zeroclc
%     %     Shapes.beamsolver.Xi0Eval,...      % intrinsic strain vector
%     %     Shapes.beamsolver.ThetaEval,...    % evaluated Theta matrix
%     %     Shapes.beamsolver.ActuatorEval,...
%     %     Shapes.beamsolver.DofMap,...
%     %     Shapes.beamsolver.KttEval,...
%     %     Shapes.beamsolver.MttEval,...
%     %     Shapes.beamsolver.DttEval,...
%     %     Shapes.Material.params.Zeta,...
%     %     Shapes.system.Gravity);
    
%     gg = 0;
    
%     % if ( norm(Shapes.system.Gravity) > 0 ) && Shapes.solver.Iteration < 2
%     % [gg] = computeGradientGvecFast_mex(Q,...
%     %     Shapes.beamsolver.SpaceStep,...    % spatial steps
%     %     Shapes.beamsolver.g0(1:3,4),...    % position zero
%     %     Shapes.beamsolver.g0(1:3,1:3),...  % phi zeroclc
%     %     Shapes.beamsolver.Xi0Eval,...      % intrinsic strain vector
%     %     Shapes.beamsolver.ThetaEval,...    % evaluated Theta matrix
%     %     Shapes.beamsolver.DofMap,...
%     %     Shapes.beamsolver.MttEval,...
%     %     Shapes.system.Gravity);
%     % end
    
%         Shapes.system.Mass       = M_;
%         Shapes.system.Damping    = R_;
%         Shapes.system.Coriolis   = C_;
%         Shapes.system.Viscous    = K_ * 0;
%         Shapes.system.Stiffness  = K_;
%         Shapes.system.Tangent    = K_ + beta * gg;
%         Shapes.system.Jacobian   = J;
%         Shapes.system.dJacobian  = dJdt_;
%         Shapes.system.Backbone   = g;
%         Shapes.system.Velocity   = eta;
    
%         Shapes.system.fBody      = beta * fg_;
%         Shapes.system.fElastic   = K_ * Q;
%         Shapes.system.fDamping   = R_ * dQ;
%         Shapes.system.fCoriolis  = C_ * dQ;
%         Shapes.system.fDrag      = 0*K_ * dQ;
    
%         if isfield(Shapes.system,'Actuator')
%             Shapes.system.Input = G;
%             Shapes.system.InputMap = @(x) G;
%         else
%             Shapes.system.Input = Shapes.system.InputMap([]);
%         end
        
%     end
