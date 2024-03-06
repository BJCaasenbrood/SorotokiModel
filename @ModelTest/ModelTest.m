classdef ModelTest < matlab.unittest.TestCase

    methods (Test)

        function testStateSpace(testCase)
            [amp, b, alpha, beta, w] = deal(0.45, 0.5, -1, 1, 2);
            f = @(x,u,t) [ x(2); -b*x(2)-alpha*x(1)-beta*x(1)^3+amp*sin(w*t)];
            H = @(x,u,t) [ 0, 1; -alpha-3*beta*x(1)^2, -b];

            sys = StateSpace({f,H},[0.5021; 0.17606]);
            mdl = Model(sys);

            testCase.verifyClass(mdl,'Model');
        end

        function testSimulate(testCase)
            [amp, b, alpha, beta, w] = deal(0.45, 0.5, -1, 1, 2);
            f = @(x,u,t) [ x(2); -b*x(2)-alpha*x(1)-beta*x(1)^3+amp*sin(w*t)];
            H = @(x,u,t) [ 0, 1; -alpha-3*beta*x(1)^2, -b];

            sys = StateSpace({f,H},[0.5021; 0.17606]);
            mdl = Model(sys);

            mdl = mdl.set('MaxIteration',2,...
                'RelTolerance',1e-9,...
                'TimeStep',0.1,...
                'TimeHorizon',50);

            mdl = mdl.simulate();

            hasNaN = any(isnan(mdl.solver.sol.x));
            
            % Verify a solution
            testCase.verifyFalse(hasNaN);
            testCase.verifyClass(mdl,'Model');
        end

        function testSE3Interpolate(testCase)


        end
    end
end
