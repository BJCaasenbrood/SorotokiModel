% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 7;
shp = Shapes(chebyspace(300,M),[0,M,M,0,0,0]);

mat = NeoHookean(0.1,0.3);
mat.contact.TangentFriction = 0.3;
shp.Material = mat;
shp = shp.rebuild();

shp = showRenderShapes(shp);
sdf = sSphere(15,[30,1,-35]);
shp = shp.addContact(sdf);
con = Gmodel(sdf,'Texture',matcap_diffuse(0.2));
con.render();

shp.solver.TimeStep = 1/75;
shp.solver.TimeHorizon = 5;

shp.system.Controller = @(x) Control(x);

shp = solveDynamicShapes(shp);

function tau = Control(shp)
    t = shp.solver.Time;
    tau = zeros(shp.NJoint,1);
    tau(1) = 40 * clamp(0.25*t,0,2);
end