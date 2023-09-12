% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 3;
shp = Shapes(chebyspace(20,M),[0,M,M,0,0,0]);
shp.Material = NeoHookean(1,0.3);
shp.Material.params.Zeta = 1e-3;

shp = shp.setRadius([5,5,0.5]);

shp = shp.rebuild();
shp = shp.addGravity;

shp.solver.TimeStep = 1/250;
shp.solver.TimeHorizon = 5;

shp.system.Controller = @(x) Control(x);
shp = solveDynamicShapes(shp);

T = shp.solver.sol.tout;
Y = shp.solver.sol.yout;

%%
function tau = Control(shp)
    t = shp.solver.Time;
    tau = zeros(shp.NJoint,1);
    view(30,30);
    if t < 1e-2
        axis([-50 120, -5, 5, -90, 5]);
    end
end