function H = hessian(Fluidics)
    
    x = Fluidics.solver.sol.x;
    t = Fluidics.solver.Time;

    if isfield(Fluidics.solver.sol,'u')
        u = Fluidics.solver.u;
    else
        u = 0;
    end
 
    eps = 1e-6;
    H   = zeros(Fluidics.NDim);
    f0  = flowDynamicsFluidics(Fluidics,x,u,t);
    dx  = eye(Fluidics.NDim)*eps;
    
    for ii = 1:Fluidics.NDim
        f1 = flowDynamicsFluidics(Fluidics, x + dx(:,ii),u,t);
        H(:,ii) = (f1 - f0)/eps;
    end
 
end