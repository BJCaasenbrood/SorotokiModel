function H = hessian(RigidBody)
    
    x = RigidBody.solver.sol.x;
    t = RigidBody.solver.Time;

    if isfield(RigidBody.solver.sol,'u')
        u = RigidBody.solver.u;
    else
        u = zeros(6,1);
    end
 
    eps = RigidBody.solver.StepTolerance;
    H   = zeros(RigidBody.NDim);
    f0  = flowDynamicsRigidBody(RigidBody,x,u,t);
    dx  = eye(RigidBody.NDim) * eps;
    
    for ii = 1:RigidBody.NDim
        f1 = flowDynamicsRigidBody(RigidBody, x + dx(:,ii),u,t);
        H(:,ii) = (f1 - f0)/eps;
    end
 
end