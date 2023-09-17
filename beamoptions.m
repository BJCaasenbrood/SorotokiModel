classdef beamoptions
    
    properties
        sol;
        Residual;
        AbsTolerance;
        RelTolerance;
        StepTolerance;
        MaxIteration;
        MaxSubIteration;
        MaxBisection;
        Iteration;
        SubIteration;
        Bisection;
        isConverged;
        Flag;
        Display;
        DofMap;
        Space;
        SpaceHorizon;
        SpaceStep;

        GaussPrecisionLocal;  % for forward kinematics
        GaussPrecisionGlobal; % for full body

        evalGauss;
        evalLocal;
        evalGlobal;

        Xi0;
        g0;
        gL;

        Att;
        Jtt;
        Ktt;
        Mtt;
        Dtt;

        ThetaEval;
        ActuatorEval;
        Xi0Eval;
        KttEval;
        MttEval;
        DttEval;
    end
    
    methods
        function obj = beamoptions
            obj.sol           = struct;
            obj.Residual      = Inf;
            obj.AbsTolerance  = 1e-3;
            obj.RelTolerance  = 1e-3;
            obj.StepTolerance = 1e-6;
            obj.MaxIteration  = 1e3;
            obj.Display       = false;
            obj.isConverged   = false;
            obj.Iteration     = 1;
            obj.SubIteration  = 1;
            obj.Bisection     = 1;
            obj.Space         = 0;
            obj.SpaceHorizon  = 1;
            obj.SpaceStep     = 1e-3;
            obj.g0            = eye(4);
            obj.Xi0           = [0,0,0,1,0,0].';

            obj.GaussPrecisionLocal  = 5;
            obj.GaussPrecisionGlobal = 25;
        end
    end
end

