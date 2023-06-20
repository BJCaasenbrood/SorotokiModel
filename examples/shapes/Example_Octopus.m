% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 10;
Xd = [30,0,60];

mat = NeoHookean(0.1,0.49);
shp = Shapes(chebyspace(50,M),[0,M,0,0,0,0],'Material',mat);
shp = shp.setRadius([5,5,0.9]);
shp.system.Drag = 6000e-12;
shp.options.isRampCompensation = true;
shp.options.isSelfContact = false;
shp.solver.TimeStep = 1/60;
shp.solver.TimeHorizon = 5;

sdf = sSphere(10,[60,0,30]);
con = Gmodel(sdf,'Texture',matcap_diffuse(0.82));
con.render();

shp = shp.addContact(sdf);

obj = sSphere(2,Xd);
obj = Gmodel(obj,'Texture',matcap_diffuse(0.82));
obj.render();

shp.system.Controller = @(x) Control(x,Xd);
shp = shp.rebuild();
shp = solveDynamicShapes(shp);

T = shp.solver.sol.tout;
Y = shp.solver.sol.yout;
%%
function tau = Control(shp,Xd)
    J = shp.system.Jacobian;
    fe = shp.system.fElastic;
    g  = shp.system.Backbone;

    P = backbone(g);
    [~,d] = distance2curve(Xd,P);
    [~,I] = min(d);

    kp  = 12500;
    e   = 0;
    rho = 1e3;

    for ii = I
        b = Xd(:) - P(ii-3,:).';
        Q = J(4:6,:,ii-3);
        A = Q * Q.' + rho.^2 * eye(3); 
        e = e + Q.' * (A \ b) ;
    end

    tau = (kp * e);
    view(30,30);
    axis tight
end