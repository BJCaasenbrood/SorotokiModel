function varargout = dynamics(StateSpace,x,varargin)

    t = 0; 
    u = 0;
    
    if ~isempty(varargin)
        u = varargin{1}(:);
        if numel(varargin)>1
            t = varargin{2};
        end
    end
    
    if ~StateSpace.options.isNonlinear
        y{1} = StateSpace.system.A*x + StateSpace.system.B*u;
        y{2} = StateSpace.system.A;
    else
        y{1} = feval(StateSpace.system.f, x, u, t);

        if ~isfield(StateSpace.system,'dfdx')
            eps = StateSpace.solver.StepTolerance;
            H = zeros(StateSpace.getDimension);
            f0 = feval(StateSpace.system.f, x, u, t);
            dx = eye(StateSpace.getDimension)*eps;

            % finite difference
            for ii = 1:StateSpace.getDimension
                f1 = feval(StateSpace.system.f, x + dx(:,ii),u,t);
                H(:,ii) = (f1 - f0)/eps;
            end

            y{2} = H;
        else
            y{2} = StateSpace.system.dfdx(x,u,t);
        end

    end

    varargout = y(:);
end

function = estimateHessian()
if ~isfield(StateSpace.system,'dfdx')
    eps = StateSpace.solver.StepTolerance;
    H = zeros(StateSpace.getDimension);
    f0 = flow(StateSpace,x,u,t);
    dx = eye(StateSpace.getDimension)*eps;
    for ii = 1:StateSpace.getDimension
        f1 = flow(StateSpace,x + dx(:,ii),u,t);
        H(:,ii) = (f1-f0)/eps;
    end
else
    H = StateSpace.system.dfdx(x,u,t);
end
end