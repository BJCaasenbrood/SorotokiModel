function Model = compute(Model,varargin)

    % p = inputParser;
    % addOptional(p,'full',true);
    % parse(p,varargin{:});

    x = Model.solver.sol.x;
    t = Model.solver.Time;

    F = Model.system.Systems{1}.flow(x,0,t);
    H = Model.system.Systems{1}.hessian(x,0,t);
    
    Model.system.fResidual = F;
    Model.system.Hessian   = H;
end