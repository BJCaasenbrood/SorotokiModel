% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 3;
shp = Shapes(chebyspace(30,M),[0,M,0,0,0,0]);
shp.Material = NeoHookean(0.5,0.3);
shp = shp.rebuild();
shp = shp.addGravity;

shp = showRenderShapes(shp);
view(30,30);
axis([-10 0 -5 5 -120 10]);

shp.solver.TimeStep = 1/50;
shp.solver.TimeHorizon = 5;

shp.system.Controller = @(x) Control(x);

shp = solveDynamicShapes(shp);

function tau = Control(shp)
    t = shp.solver.Time;
    tau = zeros(shp.NJoint,1);
    tau(1) = 120 * sin(pi*t);
end