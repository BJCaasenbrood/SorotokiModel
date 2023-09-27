function [dx, Fluidics] = flow(Fluidics)

    x = Fluidics.solver.sol.x;
    t = Fluidics.solver.Time;

    if isfield(Fluidics.solver.sol,'u')
        u = Fluidics.solver.u;
    else
        u = 0;
    end

    [dx, Fluidics] = flowDynamicsFluidics(Fluidics, x(:), u(:), t);
    
end