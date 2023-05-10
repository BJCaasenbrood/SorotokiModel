% 08-May-2023 14:16:17
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;

N = 30;
M = 3;

Y   = pwlspace(N,M,false);
shp = Shapes(Y, [0,M,0,0,0,0]);

Q0 = diag(linspace(1,shp.NJoint,shp.NJoint)) * 15e-3;

for ii = 1:shp.NJoint
    g = shp.string(Q0(:,ii));
    p = backbone(g);

    fplot(p(:,[1,3]),'LineW',2); hold on;
    axis([-80,120,-80,80]);
    axis equal;
end