function test_suite = test_log_spiral
% 09-Apr-2023 14:01:52
% Auto-generated test script

% % Initialize the test suite
% runtests('test');
% 
% end
% 
% function test
clr;
N = 300;
X = linspace(1e-3,1,N).';
shp = Shapes(-log(flipud(X)),[0,1,0,0,0,0],'isOrthonormal',false);

g = shp.string([-2]*0.01);
p = backbone(g);

fplot(p,'LineW',3);
axis equal;
view(0,0);

end
