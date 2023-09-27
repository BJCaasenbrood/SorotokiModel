function [dx, RigidBody] = flow(RigidBody)

    x = RigidBody.solver.sol.x;
    t = RigidBody.solver.Time;

    if isfield(RigidBody.solver.sol,'u')
        u = RigidBody.solver.u;
    else
        u = zeros(6,1);
    end

    [dx, RigidBody] = flowDynamicsRigidBody(RigidBody, x(:), u(:), t);
end