clr;

% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 6;
Xd = [50,0,20];

shp = Shapes(chebyspace(30,M),[0,M,M,0,0,0],'Material',NeoHookean(0.01,0.3));
shp = shp.addGravity([0;0;-500]);
shp = shp.setBase(roty(pi/2));
shp = shp.setRadius([5,5,0.7]);

shp = shp.rebuild();
shp.solver.TimeStep = 1/60;
shp.solver.TimeHorizon = 15;

sdf = sSphere(12.5,[20,0,15]);
obj = sSphere(2,Xd);
shp = shp.addContact(sdf);
con = Gmodel(sdf,'Texture',matcap_diffuse(0.2));
con.render();
obj = Gmodel(obj,'Texture',matcap_diffuse(0.82));
obj.render();

shp.system.Controller = @(x) Control(x,Xd);
shp = solveDynamicShapes(shp);

T = shp.solver.sol.tout;
Y = shp.solver.sol.yout;

%%
function tau = Control(shp,Xd)
    t = shp.solver.Time;
    J = shp.system.Jacobian(4:6,:,end);
    ve = shp.system.Velocity(4:6,:,end);
    fe = shp.system.fElastic;
    fg = shp.system.fBody;
    x  = shp.system.Backbone(1:3,4,end);

    kd = 1e-5;
    kp = 1e-5;
    
    tau = fe + fg + kp * J.'*(Xd(:) - x) - kd * J.' * ve;
    axis tight;
    view(30,30);
end