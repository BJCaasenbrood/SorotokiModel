%clr;
% clr;
shp = preset.shapes.octarm;
shp = shp.addGravity();

figure(101);
view(30,30);

% shp.solver.MaxIteration = 20;
% shp.solver.TimeStep    = 1/50;
% shp.solver.TimeHorizon = 5;
% shp.simulate;

% mdl = Model(shp);

% mdl.solver.MaxIteration = 5;
% mdl.solver.TimeStep = 1/100;
% mdl.solver.TimeHorizon = 5;

% mdl = mdl.simulate;

% shp.solver.sol.x = mdl.solver.sol.x(1:5);
% shp.show();
% Q = [1;4;0;0;0] * 1e-2;

shp = shp.simulate();

% tic;
% [g] = shp.string(Q);
% toc;

% shp.system.Mass
% p = backbone(g);
% % hold on;
% fplot(p,'LineW',3);
% axis equal;
% view(30,30);

% sum(sqrt(sum(diff(p).^2,2)))
% axis tight;

