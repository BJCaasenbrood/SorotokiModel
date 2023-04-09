classdef solveroptionsX
    
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

        Xi0;
        g0;
        gL;

        ThetaEval;
        Xi0Eval;
        KttEval;
        MttEval;
    end
    
    methods
        function obj = solveroptionsX
            obj.sol           = struct;
            obj.Residual      = 1e6;
            obj.AbsTolerance  = 1e-3;
            obj.RelTolerance  = 1e-3;
            obj.StepTolerance = 1e-6;
            obj.MaxIteration  = 1e3;
            obj.Display       = false;
            obj.isConverged   = false;
            obj.Iteration     = 1;
            obj.SubIteration  = 1;
            obj.Bisection     = 1;
            obj.Space          = 0;
            obj.SpaceHorizon   = 1;
            obj.SpaceStep      = 1e-3;
            obj.g0            = eye(4);
            obj.Xi0           = [0,0,0,1,0,0].';
        end
    end
end

