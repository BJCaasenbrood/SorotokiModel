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

sdf = sSphere(20,[40,0,-15]);
con = Gmodel(sdf);
con.Texture = matcap_diffuse(0.25);
con.render();

shp = shp.addContact(sdf);

shp = showRenderShapes(shp);
view(30,30);

shp = shp.compute(zeros(5,1));