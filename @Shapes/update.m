function Shapes = update(Shapes, varargin)

if nargin > 1
    Shapes.solver.TimeStep = varargin{1};
end    

rho    = 1.0;
alphaM = (2*rho - 1)/(rho + 1);
alphaF = (rho)/(rho + 1);

gamma = 0.5 - alphaM + alphaF;
beta  = 0.25*(1 - alphaM + alphaF)^2;

if Shapes.solver.Time < Shapes.solver.TimeStep

    % preallocate solutions
    if ~isinf(Shapes.solver.TimeHorizon)
        NSteps = round(Shapes.solver.TimeHorizon/Shapes.solver.TimeStep);
        Shapes.solver.sol.yout = zeros(NSteps,Shapes.NJoint);
        Shapes.solver.sol.tout = zeros(NSteps,1);
    end
    Shapes.solver.SubIteration = 1;
        
    if ~isfield(Shapes.solver.sol,'ddx')
        Shapes.solver.sol.ddx = Shapes.solver.sol.dx * 0;
        Shapes = Shapes.compute();
    
        A = Shapes.system.Mass;
        b = - Shapes.system.fResidual - (Shapes.system.Damping ...
            + Shapes.system.Coriolis ) * Shapes.solver.sol.dx;
    
        Shapes.solver.sol.ddx = A \ b;
    end
end

dt  = Shapes.solver.TimeStep;
Shapes.solver.Residual  = +Inf;
Shapes.solver.Iteration = 1;

x0   = Shapes.solver.sol.x;
dx0  = Shapes.solver.sol.dx;
ddx0 = Shapes.solver.sol.ddx;
ddxf = Shapes.solver.sol.ddx;
tf   = Shapes.solver.Time;

while norm(Shapes.solver.Residual) > Shapes.solver.RelTolerance && ...
    Shapes.solver.Iteration < Shapes.solver.MaxIteration 

    dxf = dx0 + dt * ((1-gamma)*ddxf + gamma*ddx0);
    xf  = x0  + dt * dx0 + 0.5 * dt*dt * ...
         ((1-2*beta)*ddxf + 2*beta*ddx0);

    x1   = (1-alphaF)*xf + alphaF*x0;
    dx1  = (1-alphaF)*dxf + alphaF*dx0;     
    ddx1 = (1-alphaF)*ddx0 + alphaF*ddxf;      

    Shapes.solver.sol.x   = x1;
    Shapes.solver.sol.dx  = dx1;
    Shapes.solver.sol.ddx = ddx1;
    Shapes.solver.Time    = tf + dt - alphaF*dt;

    % compute full-model    
    if Shapes.solver.Iteration < 50
        Shapes = Shapes.compute();
    else
         Shapes = Shapes.compute('nobuild',true);
    end

    A = (1-alphaF) * beta * dt * dt * Shapes.system.Tangent + ...
        (1-alphaF) * gamma * dt * Shapes.system.Damping + ...
        (1-alphaF) * gamma * dt * Shapes.system.Coriolis + ...
        (1-alphaM) * Shapes.system.Mass;

    b = Shapes.system.Mass * ddx1 + Shapes.system.fResidual;

    % % linear solve
    % if isempty(Ceq)
    %     b = Fem.system.fResidual;
    %     A = Fem.system.Tangent;
    % else
    %     b = [Fem.system.fResidual + Ceq.'*Fem.solver.sol.u(qc); ...
    %             -Fem.system.cResidual];
        
    %     A = [Fem.system.Tangent, Ceq.'; Ceq, zeros(nc)];
    % end

    % linear solve
    dfdq1 = A \ b;

    % adaptive gradient descent
    if Shapes.solver.Iteration > 1
        minL = sqrt(1+th) * lam0;
        maxL = 0.5 * norm(ddxf_ - ddx0)/norm(dfdq1 - dfdq0);
        lam1 = clamp(min([minL, maxL]),0,Inf);
    else
        lam0 = 1;
        lam1 = lam0;
        th   = +Inf;
    end

    Shapes.solver.Residual  = b;
    Shapes.solver.Iteration = Shapes.solver.Iteration + 1;

    ddxf_ = ddx0;
    ddx0  = ddx0 - lam1 * dfdq1;
    dfdq0 = dfdq1;
end

if ~isinf(Shapes.solver.TimeHorizon)
    step = Shapes.solver.SubIteration;
    Shapes.solver.sol.yout(step,:) = Shapes.solver.sol.x;
    Shapes.solver.sol.tout(step) = Shapes.solver.Time;
    Shapes.solver.SubIteration = Shapes.solver.SubIteration + 1;
end

Shapes.solver.Time = clamp(tf + Shapes.solver.TimeStep,...
    0, Shapes.solver.TimeHorizon);

Shapes.solver.sol.dx = dx0 + dt * ((1-gamma)*ddxf + gamma * ddx0);    
Shapes.solver.sol.x  = x0 + dt * dx0 + 0.5 * dt*dt * ...
    ((1 - 2*beta)*ddxf + 2 * beta * ddx0);

end