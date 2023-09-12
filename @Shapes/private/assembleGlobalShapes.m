function Shapes = assembleGlobalShapes(Shapes)

Q  = Shapes.solver.sol.x;
dQ = Shapes.solver.sol.dx;

beta = 1;
if ~isempty(Shapes.options.loadingFactor)
   beta = Shapes.options.loadingFactor;
end

[g,J,eta] = computeForwardKinematicsFast_mex(Q,dQ,... % states
    Shapes.beamsolver.SpaceStep,...     % spatial steps
    Shapes.beamsolver.g0(1:3,4),...     % position zero
    Shapes.beamsolver.g0(1:3,1:3),...   % phi zero
    Shapes.beamsolver.Xi0Eval,...       % intrinsic strain vector
    Shapes.beamsolver.ThetaEval,...     % evaluated Theta matrix
    Shapes.beamsolver.DofMap);

[M_,C_,K_,R_,D_,fg_,G,...
    ~,~,~,dJdt_,~,~] = computeLagrangianFast_mex(Q,dQ,...
    Shapes.beamsolver.SpaceStep,...    % spatial steps
    Shapes.beamsolver.g0(1:3,4),...    % position zero
    Shapes.beamsolver.g0(1:3,1:3),...  % phi zeroclc
    Shapes.beamsolver.Xi0Eval,...      % intrinsic strain vector
    Shapes.beamsolver.ThetaEval,...    % evaluated Theta matrix
    Shapes.beamsolver.ActuatorEval,...
    Shapes.beamsolver.DofMap,...
    Shapes.beamsolver.KttEval,...
    Shapes.beamsolver.MttEval,...
    Shapes.beamsolver.DttEval,...
    Shapes.Material.params.Zeta,...
    Shapes.system.Gravity);

gg = 0;
if ( norm(Shapes.system.Gravity) > 0 ) && Shapes.solver.Iteration < 2
[gg] = computeGradientGvecFast_mex(Q,...
    Shapes.beamsolver.SpaceStep,...    % spatial steps
    Shapes.beamsolver.g0(1:3,4),...    % position zero
    Shapes.beamsolver.g0(1:3,1:3),...  % phi zeroclc
    Shapes.beamsolver.Xi0Eval,...      % intrinsic strain vector
    Shapes.beamsolver.ThetaEval,...    % evaluated Theta matrix
    Shapes.beamsolver.DofMap,...
    Shapes.beamsolver.MttEval,...
    Shapes.system.Gravity);
end

    Shapes.system.Mass       = M_;
    Shapes.system.Damping    = R_;
    Shapes.system.Coriolis   = C_;
    Shapes.system.Viscous    = D_;
    Shapes.system.Stiffness  = K_;
    Shapes.system.Tangent    = K_ + beta * gg;
    Shapes.system.Jacobian   = J;
    Shapes.system.dJacobian  = dJdt_;
    Shapes.system.Backbone   = g;
    Shapes.system.Velocity   = eta;

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