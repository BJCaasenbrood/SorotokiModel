function Shapes = solveInvKinShapes(Shapes,varargin)

    Ceq  = [];
    lam0 = 1;
    Shapes.solver.RelTolerance = 1e-3;    
    Shapes.solver.Residual     = Inf;
    Shapes.solver.Iteration    = 1;

    rho = Shapes.solver.Regularization;
    x0 = Shapes.solver.sol.x + 1e-5;

    if ~isempty(varargin)
        pd = varargin{1};
    else
        pd = Shapes.system.Setpoint{2}(1);
    end

    while norm(Shapes.solver.Residual) > Shapes.solver.RelTolerance && ...
        Shapes.solver.Iteration < Shapes.solver.MaxIteration 

        [g, J] = Shapes.string(Shapes.solver.sol.x);
        pos    = backbone(g);
    
        if isempty(Ceq)
            if numel(pd) == 3
                b = (pos(end,:)).' - pd(:);
                Q = J(4:6,:,end);
                A = Q * Q.' + rho.^2 * eye(3); 
            else
                b = 50*wedge(logmapSE3(g(:,:,end)\pd));
                b = kron([0,0;0,1],eye(3)) * b;
                Q = J(:,:,end);
                A = Q * Q.' + rho.^2 * eye(6); 
            end
        else

        end

        dfdq1 = Q.' * (A \ b);

        if Shapes.solver.Iteration > 1
            minL = sqrt(1+th) * lam0;
            maxL = 0.5 * norm(x1 - x0)/norm(dfdq1 - dfdq0);
            lam1 = clamp(min([minL, maxL]),1e-6,+Inf);
            th   = lam1/lam0;
        else
            lam1 = lam0;
            th   = +Inf;
        end

        % if  Shapes.solver.Display && (mod(Shapes.solver.Iteration,Shapes.solver.DisplayAtEvery) == 0 || ...
        %     Shapes.solver.Iteration == 1)

        %     log(Shapes.solver.Iteration, norm(b), lam1 + 1e-6);
        % end

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
    
    % if  Shapes.solver.Display
    %     log(Shapes.solver.Iteration, norm(b), lam1 + 1e-6);
    %     fprintf('\n');
    % end 
end

function log(ii,f,g)
    if ii < 2
        fprinttable({'Iteration','Residual','lambda'}, [ii, f,g],'open',true);
    else
        fprinttable({'Iteration','Residual','lambda'}, [ii,f,g], 'addrow',true,'open',true);
    end
end