% 08-May-2023 16:13:56
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;
M = 5;
X = [55,0,5];
shp = Shapes(chebyspace(100,M),[0,M,0,0,0,0]);

shp = shp.addSetpoint(X);
shp = shp.set('Regularization',100);
shp = solveInvKinShapes(shp);

obj = Gmodel(sSphere(2,X));
obj.Texture = matcap_diffuse(0.95);
obj.render();

shp = showRenderShapes(shp);
view(30,30);

% set(gcf,'ButtonDownFcn',@ImageClickCallback);

% function ImageClickCallback ( objectHandle , eventData )
% axesHandle  = get(objectHandle,'Parent');
% coordinates = get(axesHandle,'CurrentPoint'); 
% coordinates = coordinates(1,1:2)
% % message     = sprintf('x: %.1f , y: %.1f',coordinates (1) ,coordinates (2));
% % helpdlg(message);
% end