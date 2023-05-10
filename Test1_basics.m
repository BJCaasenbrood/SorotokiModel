clr;

N = 300;
M = 10;

%Y = chebyspace(N,M);
Y = zeros(N,M);
for ii = 1:M
    x = linspace(0,1,300).';
    Y(:,ii) = x.^(ii-1);
end

shp = Shapes(Y, [0,M,0,0,0,0]);
q0 = zeros(shp.NJoint,1) + 1e-3;
pd = [60,0,20];

fplot(pd,'bo'); hold on;

ii = 1;
e = Inf;
r = 6000;

while norm(e) > 0.1
    [g, J] = shp.string(q0);
    [p, ux] = backbone(g);

    e = pd - p(end,:);

    Jv   = J(4:6,:,end);
    Jinv = Jv.' * inv(Jv * Jv.' + r.^2 * eye(3) );

    dq = Jinv*e(:);
    q0 = q0 + 2*dq;

    h = fplot(p,'LineW',3,'Color','k');
    axis equal;
    xlim([0,120]);
    zlim([-50,50]);
    view(0,0);
    drawnow;
    delete(h);
end

h = fplot(p,'LineW',3,'Color','k');
