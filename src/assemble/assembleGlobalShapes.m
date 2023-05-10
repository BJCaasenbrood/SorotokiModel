function Shapes = assembleGlobalShapes(Shapes)

Q  = Shapes.solver.sol.x;
dQ = Shapes.solver.sol.dx;

[g,J,eta] = computeForwardKinematicsFast_mex(Q,dQ,... % states
    Shapes.beamsolver.SpaceStep,...         % spatial steps
    Shapes.beamsolver.g0(1:3,4),...         % position zero
    Shapes.beamsolver.g0(1:3,1:3),...       % phi zero
    Shapes.beamsolver.Xi0Eval,...    % intrinsic strain vector
    Shapes.beamsolver.ThetaEval,...  % evaluated Theta matrix
    Shapes.beamsolver.DofMap);

[M_,C_,K_,R_,fg_,~,...
    ~,~,~,dJdt_,~,~] = computeLagrangianFast_mex(Q,dQ,...
    Shapes.beamsolver.SpaceStep,...         % spatial steps
    Shapes.beamsolver.g0(1:3,4),...         % position zero
    Shapes.beamsolver.g0(1:3,1:3),...       % phi zeroclc
    Shapes.beamsolver.Xi0Eval,...    % intrinsic strain vector
    Shapes.beamsolver.ThetaEval,...  % evaluated Theta matrix
    Shapes.beamsolver.FiberEval,...
    Shapes.beamsolver.DofMap,...
    Shapes.beamsolver.KttEval,...
    Shapes.beamsolver.MttEval,...
    Shapes.Material.params.Zeta,...
    Shapes.system.Gravity);

    Shapes.system.Mass       = M_;
    Shapes.system.Damping    = R_;
    Shapes.system.Coriolis   = C_;
    Shapes.system.Tangent    = K_;
    Shapes.system.Jacobian   = J;
    Shapes.system.dJacobian  = dJdt_;
    Shapes.system.Backbone   = g;
    Shapes.system.Velocity   = eta;

    Shapes.system.fBody      = fg_;
    Shapes.system.fElastic   = K_ * Q;
    Shapes.system.fDamping   = R_ * dQ;
    Shapes.system.fCoriolis  = C_ * dQ;

end