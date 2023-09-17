function Model = simulate(Model, varargin)

% warning off;

In     = eye(Model.NDim);
NSteps = round(Model.solver.TimeHorizon/Model.solver.TimeStep);

if Model.solver.isLog
    progBar = ProgressBar(NSteps + 1,'Title', 'Solving...');
end

Model.solver.Time = 0;

% preallocate solutions
Model.solver.sol.yout = zeros(NSteps,Model.NDim);
Model.solver.sol.tout = zeros(NSteps,1);
Model.solver.SubIteration = 1;

FLAG = 3;

while Model.solver.Time < Model.solver.TimeHorizon
    
    dt  = Model.solver.TimeStep;
    Model.solver.Residual  = Inf;
    Model.solver.Iteration = 1;
    
    x0 = Model.solver.sol.x;
    xf = Model.solver.sol.x;
    tf = Model.solver.Time;

    if FLAG == 1
        k1 = Model.system.Systems{1}.flow(x0, 0, tf);
        k2 = Model.system.Systems{1}.flow(x0 + dt * k1, 0, tf + dt);
        x0 = x0 + (dt/2) * (k1 + k2);
    elseif FLAG == 2
        k1 = Model.system.Systems{1}.flow(x0, 0, tf);
        k2 = Model.system.Systems{1}.flow(x0 + (2/3)*dt * k1, 0, tf + (2/3)*dt);
        x0 = x0 + dt * ((1/4)*k1 + (3/4)*k2);
    elseif FLAG == 3 

        % guess for y_{n+0.5}
        % k1 = Model.system.Systems{1}.flow(x0, 0, tf);
        % k2 = Model.system.Systems{1}.flow(x0 + dt * k1, 0, tf + dt);
        % x0 = 0.5 * (x0 + (x0 + (dt/2) * (k1 + k2)));

        while norm(Model.solver.Residual) > Model.solver.RelTolerance && ...
            Model.solver.Iteration < Model.solver.MaxIteration

            Model.solver.sol.x = x0;

            FF = Model.system.Systems{1}.flow(x0,0,tf+dt/2);
            HH = Model.system.Systems{1}.hessian(x0,0,tf+dt/2);

            A = In - 0.5 * dt * HH;
            b = (x0 - xf) - 0.5 *dt * FF;

            % linear solve
            dfdq1 = A \ b;
            
            % adaptive gradient descent
            if Model.solver.Iteration > 1
                minL = sqrt(1+th) * lam0;
                maxL = norm(xf_ - x0)/norm(dfdq1 - dfdq0);
                lam1 = clamp(min([minL, maxL]), 0, 1e3);
            else
                lam0 = 1;
                lam1 = lam0;
                th   = +1e3;
            end

            Model.solver.Residual  = b;
            Model.solver.Iteration = Model.solver.Iteration + 1;

            % update local state solution
            xf_ = x0;
            x0  = x0 - lam1 * dfdq1;
            dfdq0 = dfdq1;

            % disp( norm(b) )
        end
    end

    if FLAG == 3
        x0 = 2 * x0 - xf;
    end

    if Model.solver.isLog
        progBar([], [], []);
    end

    step = Model.solver.SubIteration;
    Model.solver.sol.yout(step,:) = Model.solver.sol.x;
    Model.solver.sol.tout(step)   = Model.solver.Time;
    Model.solver.SubIteration     = Model.solver.SubIteration + 1;

    Model.solver.Time = clamp(tf + Model.solver.TimeStep,...
        0, Model.solver.TimeHorizon);
 
    Model.solver.sol.x = x0;
end

if Model.solver.isLog
    progBar.release();
    fprintf('\n');
end

end