function [dx, Fluidics] = flowDynamicsFluidics(Fluidics, x, u, t)
    kp = Fluidics.params.Kp;
    ki = Fluidics.params.Ki;
    mu = Fluidics.params.Leakage;

    u = Fluidics.system.Control(Fluidics);

    if isfield(Fluidics.system,'P')
        J  = Fluidics.system.P;
    else
        J = 0;
    end

    if numel(u) == 1
        e  = u - x(1);
        dJ = 0;
    elseif numel(u) == 2
        e  = u(1) - x(1);
        J  = clamp(u(2), 1e-6, 10);
        dJ = 0;
    else
        e  = u(1) - x(1);
        J  = clamp(u(2), 1e-6, 10);
        dJ = u(3);
    end

    % compressible gas coefficients
    Nv = Fluidics.params.Polytropic;
    Rv = Fluidics.params.GasConstant;
    Tv = Fluidics.params.Temperature;

    V    = Fluidics.system.PVCurve(J);
    dVdx = (Fluidics.system.PVCurve(J + 1e-6) - V)/1e-6;

    B1 = Nv * Rv * Tv / V;
    B2 = Nv * dVdx * dJ / V;

    % internal control-loop
    if Fluidics.options.isRegulated
        dmdt = kp*e + ki*x(3);
    else
        dmdt = u(1);
    end

    Flux = Fluidics.system.MassFlow(x(1)) * dmdt;

    dx(1,1) = B1*Flux - B2*x(1) - mu*x(1);
    dx(2,1) = Flux;
    dx(3,1) = e;

    Fluidics.system.P = x(1);
    Fluidics.system.Q = Flux;
    Fluidics.system.M = x;
end