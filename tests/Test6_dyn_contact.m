% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 7;
shp = Shapes(chebyspace(60,M),[M,M,0,0,0,0]);
shp = shp.rebuild();
shp = shp.addGravity([0;0;-6000]);

% shp = showRenderShapes(shp);
sdf = sSphere(15,[30,0,-35]);
% con = Gmodel(sdf,'Texture',matcap_diffuse(0.2));
% con.render();

shp = shp.addContact(sdf);

shp.solver.TimeStep = 1/75;
shp.solver.TimeHorizon = 15;

shp.system.Controller = @(x) Control(x);

shp = solveDynamicShapes(shp);

%%
function tau = Control(shp)
    t = shp.solver.Time;
    tau = zeros(shp.NJoint,1);
    tau(1) = 40 * clamp(0.25*t,0,2);
end