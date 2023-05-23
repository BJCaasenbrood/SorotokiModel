clr;

% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 15;
Xd = [20,0,50];

mat = NeoHookean(0.01,0.49);
mat.contact.TangentFriction = 0;
shp = Shapes(chebyspace(60,M),[0,M,0,0,0,0],'Material',mat);
shp = shp.setRadius([5,5,0.8]);

shp.solver.TimeStep = 1/120;
shp.solver.TimeHorizon = 5;

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
    t = shp.solver.Time;
    J = shp.system.Jacobian;
    fe = shp.system.fElastic;
    fg = shp.system.fBody;
    g  = shp.system.Backbone;

    P = backbone(g);
    [~,d] = distance2curve(Xd,P);
    [~,I] = min(d);

    kp  = 3;
    W   = zeros(60,1);
    W(1:I) = 1./abs(d(1:I) + 1);
    e   = 0;
    rho = 10;

    for ii = 1:I
        b = Xd(:) - P(ii,:).';
        Q = J(4:6,:,end);
        A = Q * Q.' + rho.^2 * eye(3); 
        e = e + Q.' * (A \ b) ;
    end

    tau = fe + kp * e;
    view(0,0);
    axis tight;
end