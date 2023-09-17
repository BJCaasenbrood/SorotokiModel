function dx = flow(Shapes,x,varargin)

    t  = 0;
    u  = 0;
    nq = Shapes.NJoint;
    
    if ~isempty(varargin)
        u = varargin{1}(:);
        if numel(varargin)>1
            t = varargin{2};
        end
    end

    Shapes.solver.Time   = t;
    Shapes.solver.sol.x  = x(1:nq);
    Shapes.solver.sol.dx = x(nq+(1:nq));

    Shapes = Shapes.compute();

    Minv = Shapes.system.Mass \ eye(nq);

    dx = zeros(nq * 2, 1);
    dx(1:nq)      = Shapes.solver.sol.dx;
    dx(nq+(1:nq)) = -Minv * Shapes.system.fResidual;

end