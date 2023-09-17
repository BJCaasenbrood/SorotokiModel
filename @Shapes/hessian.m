function H = hessian(Shapes,x,varargin)

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
    
    H = zeros(nq * 2, nq * 2);
    H(1:nq,nq+(1:nq))      = eye(nq);
    H(nq+(1:nq),1:nq)      = -Minv * Shapes.system.Tangent;
    H(nq+(1:nq),nq+(1:nq)) = -Minv * (Shapes.system.Damping - Shapes.system.Viscous + Shapes.system.Coriolis);

end