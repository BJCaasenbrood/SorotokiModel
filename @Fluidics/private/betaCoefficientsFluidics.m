function [B1, B2] = betaCoefficientsFluidics(Fluidics,x,dx)
    Nv = Fluidics.params.Polytropic;
    Rv = Fluidics.params.GasConstant;
    Tv = Fluidics.params.Temperature;

    V  = Fluidics.system.PVCurve(x);
    dVdx = (Fluidics.system.PVCurve(x + 1e-6) - V)/1e-6;

    B1 = Nv * Rv * Tv / V;
    B2 = Nv * dVdx * dx / V;
end    
