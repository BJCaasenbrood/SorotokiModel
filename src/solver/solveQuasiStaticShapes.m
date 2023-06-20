function Shapes = solveQuasiStaticShapes(Shapes, varargin)
  
Ceq = [];
qc  = [];    

% if isfield(Shapes.system,'Displace')
%     Shapes = Shapes.compute();
%     qc  = Fem.system.Ic;
%     nc  = numel(find(Fem.system.Ic));
%     Ceq = Fem.system.cMatrix;
% end

NSteps = round(Shapes.solver.TimeHorizon/Shapes.solver.TimeStep);

if Shapes.solver.isLog
    progBar = ProgressBar(NSteps,'Title', 'Solve static Shapes');
end

Shapes.solver.Time = 0;

    while Shapes.solver.Time < Shapes.solver.TimeHorizon

        beta = Shapes.solver.Time / Shapes.solver.TimeHorizon;
        Shapes.options.loadingFactor = clamp(beta,0,1);
        Shapes.solver.Residual  = Inf;
        Shapes.solver.Iteration = 1;

        x0 = Shapes.solver.sol.x;

        while norm(Shapes.solver.Residual) > Shapes.solver.RelTolerance && ...
            Shapes.solver.Iteration < Shapes.solver.MaxIteration 

            Shapes = Shapes.compute();

            % linear solve
            if isempty(Ceq)
                b = Shapes.system.fResidual;
                A = Shapes.system.Tangent;
            else
                b = [Fem.system.fResidual + Ceq.'*Fem.solver.sol.u(qc); ...
                    -Fem.system.cResidual];
            
                A = [Fem.system.Tangent, ...
                    Ceq.'; Ceq, zeros(nc)];
            end

            dfdq1 = A \ b;

            if Shapes.solver.Iteration > 1
                minL = sqrt(1+th) * lam0;
                %maxL = 0.5 * norm([x1;u1] - [x0;u0])/norm(dfdq1 - dfdq0);
                maxL = 0.5 * norm(x1 - x0)/norm(dfdq1 - dfdq0);
                lam1 = clamp(min([minL, maxL]),1e-3,Inf);
                th   = lam1/lam0;
            else
                lam0 = 1;
                lam1 = lam0;
                th   = +Inf;
            end

            Shapes.solver.Residual  = b;
            Shapes.solver.Iteration = Shapes.solver.Iteration + 1;

            dfdq0 = dfdq1;
            x0 = Shapes.solver.sol.x;
            x1 = Shapes.solver.sol.x - lam1 * dfdq1;

            % u0 = Fem.solver.sol.u(qc);
            % u1 = Fem.solver.sol.u(qc) - lam1 * dfdq1(nq+(1:nc));

            % Fem.solver.sol.u(qc) = u1;
            Shapes.solver.sol.x = x1;
            lam0 = lam1;
        end

        if Shapes.solver.isLog
            progBar([], [], []);
        end

        Shapes.solver.Time = clamp(Shapes.solver.Time + Shapes.solver.TimeStep,...
            0,Shapes.solver.TimeHorizon);

        if ~isempty(Shapes.options.Display)
            Shapes = Shapes.options.Display(Shapes);
        end
    end

    if Shapes.solver.isLog
        progBar.release();
        fprintf('\n');
    end
end
