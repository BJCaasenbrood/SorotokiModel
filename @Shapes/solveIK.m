function [Shapes, x1, g] = solveIK(Shapes,varargin)

    Ceq  = [];
    lam0 = 1;
    Shapes.solver.Residual  = Inf;
    Shapes.solver.Iteration = 1;

    % solverType = 'virtual';
    solverType = 'dampedinverse';

    rho = Shapes.solver.Regularization;
    x0 = Shapes.solver.sol.x;

    if ~isempty(varargin)
        nd = Shapes.NNode;
        pd = varargin{1};
        I  = round(linspace(0,nd,1+size(pd,1)));
        I  = I(2:end);

        if numel(varargin) > 1
            I = varargin{2};
        end
    else
        pd = Shapes.system.Setpoint{2}(1);
    end

    while norm(Shapes.solver.Residual) > Shapes.solver.RelTolerance && ...
        Shapes.solver.Iteration < Shapes.solver.MaxIteration 

        dfdq1 = 0;
        [g, J] = Shapes.string(Shapes.solver.sol.x);
        pos    = backbone(g);

        for ii = 1:numel(I)
            if isempty(Ceq)
                if numel(pd(ii,:)) == 3
                    b = (pos(I(ii),:)).' - pd(ii,:).';
                    Q = J(4:6,:,I(ii));
                    A = Q * Q.' + rho.^2 * eye(3);
                else
                    b = 50*wedge(logmapSE3(g(:,:,end)\pd));
                    b = kron([0,0;0,1],eye(3)) * b;
                    Q = J(:,:,end);
                    A = Q * Q.' + rho.^2 * eye(6);
                end
            else
                % ....
            end

            if strcmpi(solverType,'virtual')
                alpha = Shapes.solver.TimeStep;
                dfdq1 = dfdq1 +  alpha * Q.' * b;
            elseif strcmpi(solverType,'dampedinverse')
                dfdq1 = dfdq1 + Q.' * ( A \ b );
            end
    
            if isfield(Shapes.system,'SubTask')
                alpha = (1/rho.^3);
                Qpinv = Q.' / (A);
                grad = Shapes.system.SubTask(Shapes);
                dfdq1 = dfdq1 + alpha * (eye(Shapes.NJoint) - Qpinv * Q) * grad;
            end
        end

        if Shapes.solver.Iteration > 1
            minL = sqrt(1+th) * lam0;
            maxL = norm(x1 - x0)/norm(dfdq1 - dfdq0);
            lam1 = clamp(min([minL, maxL]),0,Inf);
            th   = lam1/lam0;
        else
            lam1 = lam0;
            th   = +Inf;
        end

        if norm(Shapes.solver.Residual - b) <= Shapes.solver.RelTolerance
            Shapes.solver.Bisection = Shapes.solver.Bisection + 1;
            if  Shapes.solver.Bisection >=  Shapes.solver.MaxBisection
               break; 
            end
        end

        Shapes.solver.Residual  = b;
        Shapes.solver.Iteration = Shapes.solver.Iteration + 1;

        dfdq0 = dfdq1;
        x0    = Shapes.solver.sol.x;
        x1    = Shapes.solver.sol.x - lam1 * dfdq1;

        Shapes.solver.sol.x = x1;
        lam0 = lam1;
    end
end
