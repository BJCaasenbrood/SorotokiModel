% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 5;
N = 70;
s = linspace(0,1,N).';
Z = (exp(s)-1)/2;
Y = chebyspace(N,M);

mat = NeoHookean(0.1,0.3);
mat.params.Zeta = 0.1;

shp = Shapes(Y,[0,M,0,0,0,0],'Material',mat);
shp.options.isRampCompensation = true;
shp = shp.rebuild();

[W,P] = Gfit(shp,Z);

shp = shp.setInputMap(@(x) shp.system.Tangent * W);

shp.system.Controller  = @(x) Control(x);
shp.solver.TimeStep    = 1/125;
shp.solver.TimeHorizon = 5;

shp.solver.sol.x = initialCond;
shp = solveDynamicShapes(shp);

function tau = Control(shp)
    tau = .2;
end

function [W, POD] = Gfit(shp,Actuation)
POD = shp.system.pod.POD;
Lam = diag(trapz(shp.beamsolver.Space,POD.*POD));
W = Lam\trapz(shp.beamsolver.Space,POD.*Actuation).';
end

function q0 = initialCond
    q0 = [-0.1766; -0.1182; -0.0159; -0.0011; 0.0004];
end

% for ii = 1:numel(q)
%     shp = showRenderShapes(shp);
%     view(30,30);
%     pause(.1);
% end



% sdf = sSphere(20,[50,-20,15]);
% obj = sSphere(2,Xd);
% shp = shp.addContact(sdf);
% con = Gmodel(sdf,'Texture',matcap_diffuse(0.2));
% con.render();
% obj = Gmodel(obj,'Texture',matcap_diffuse(0.82));
% obj.render();

% shp.system.Controller = @(x) Control(x,Xd);
% shp = solveDynamicShapes(shp);

% T = shp.solver.sol.tout;
% Y = shp.solver.sol.yout;

% %%
% function tau = Control(shp,Xd)
%     t = shp.solver.Time;
%     J = shp.system.Jacobian(4:6,:,end);
%     fe = shp.system.fElastic;
%     fg = shp.system.fBody;
%     x  = shp.system.Backbone(1:3,4,end);

%     kp = 1e-4;
    
%     tau = fe + fg + kp * J.'*(Xd(:) - x);
% end