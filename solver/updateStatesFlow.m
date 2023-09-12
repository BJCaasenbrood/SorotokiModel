function ode = updateStatesFlow(ode)

    if ode.solver.Time < ode.solver.TimeStep
        NSteps = round(ode.solver.TimeHorizon/ode.solver.TimeStep);
        ode.solver.sol.yout = zeros(NSteps,ode.NDim);
        ode.solver.sol.tout = zeros(NSteps,1);
        ode.solver.SubIteration = 1;

        assert(ismethod(ode,'flow'),'No function call flow found.');
        assert(ismethod(ode,'hessian'),'No function call hessian found.');
    end

    In = eye(ode.NDim);
    dt = ode.solver.TimeStep;
    ode.solver.Residual  = +Inf;
    ode.solver.Iteration = 1;
    
    x0 = ode.solver.sol.x;
    tf = ode.solver.Time;
    
    while norm(ode.solver.Residual) > ode.solver.RelTolerance && ...
        ode.solver.Iteration < ode.solver.MaxIteration 

        if ode.solver.Iteration == 1
            ode.solver.sol.x    = x0;
            ode.solver.sol.Time = tf;
            [f1, ode] = ode.flow();
            
            b = -dt * f1;
        else
            ode.solver.sol.Time = tf + dt;
            [f2, ode] = ode.flow();
        
            b = x1 - x0 - 0.5 * dt * (f1 + f2);
        end
    
        A = -(-0.5*dt*ode.hessian() + In);
        dfdq1 = A \ b;

        if ode.solver.Iteration > 1
            minL = sqrt(1+th) * lam0;
            maxL = 0.5 * norm(x1 - x0)/norm(dfdq1 - dfdq0);
            lam1 = clamp(min([minL, maxL]),0.1,+Inf);
            th   = lam1/lam0;
        else
            lam0 = 1;
            lam1 = lam0;
            th   = +Inf;
        end

        ode.solver.Residual  = b;
        ode.solver.Iteration = ode.solver.Iteration + 1;

        dfdq0 = dfdq1;
        x1 = ode.solver.sol.x + lam1 * dfdq1;

        ode.solver.sol.x = x1;
        lam0 = lam1;

    end
    
    step = ode.solver.SubIteration;
    ode.solver.sol.yout(step,:) = ode.solver.sol.x;
    ode.solver.sol.tout(step)   = ode.solver.Time;
    ode.solver.SubIteration     = ode.solver.SubIteration + 1;
    
    ode.solver.Time = clamp(tf + ode.solver.TimeStep,...
        0,ode.solver.TimeHorizon);
    
end