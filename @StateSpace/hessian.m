function H = hessian(StateSpace,x,varargin)

t = 0;
u = 0;

if ~isempty(varargin)
    u = varargin{1}(:);
    if numel(varargin)>1
        t = varargin{2};
    end
end

if ~StateSpace.options.isNonlinear
    H = StateSpace.system.A;
else
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

end
