function dx = flow(StateSpace,x,varargin)

t = 0;
u = 0;

if ~isempty(varargin)
    u = varargin{1}(:);
    if numel(varargin)>1
        t = varargin{2};
    end
end

if ~StateSpace.options.isNonlinear
    dx = StateSpace.system.A*x + StateSpace.system.B*u;
else
    dx = feval(StateSpace.system.f, x, u, t);
end
end