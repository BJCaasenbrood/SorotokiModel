%clr;
%clr;
% clf;
shp = preset.shapes.octarm;
shp = shp.addGravity();
shp = shp.rebuild;
% 
% shp.options.Display = [];
% 
shp = shp.simulate();
% % figure(101);
% % view(30,30);

% Q = [1;0;1;0;0] * 1e-2;


% tic
% [g, J] = shp.string(Q);
% toc


% tic
% [g, J] = shp.string(Q,true);
% toc

% [p, ux, uy, uz] = backbone(g);
% fplot(p,'LineW',3); hold on;
% fquiver(p,ux,0.25,'r','LineW',3);
% fquiver(p,uy,0.25,'g','LineW',3);
% fquiver(p,uz,0.25,'b','LineW',3);

% axis equal;

% J(:,:,end)

% % % shp.system.Mass
% % p = backbone(g);
% % hold on;
% % fplot(p,'LineW',3);
% % axis equal;
% % view(30,30);

% sum(sqrt(sum(diff(p).^2,2)))
% % axis tight;

