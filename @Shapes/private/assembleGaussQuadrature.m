function Shapes = assembleGaussQuadrature(Shapes)
n = Shapes.beamsolver.GaussPrecisionLocal;
% m = Shapes.beamsolver.GaussPrecisionGlobal;

% get local gauss interp points for [-1,1]
[wl, pl] = gaussQuadrature(n);

% for [0,1]
Shapes.beamsolver.evalGauss.weights = 0.5*wl;
Shapes.beamsolver.evalGauss.points  = 0.5*pl + 0.5;

% points along curve required.
s  = linspace(0,Shapes.Length,Shapes.NNode);
Sl = zeros(n+2,1,numel(s)-1);
Wl = zeros(n,1,numel(s)-1);

% shift local gauss points from [a,b] |-> [-1,1]
for ii = 1:numel(s)-1
    a = s(ii);
    b = s(ii+1);
    Sl(:,1,ii) = [a; 0.5*(b-a)*pl + 0.5*(b+a); b];
    Wl(:,1,ii) = 0.5*(b-a)*wl;
end

Shapes.beamsolver.evalLocal.weights = squeeze(Wl);
Shapes.beamsolver.evalLocal.points  = squeeze(Sl);

% % get global gauss interp points for [-1,1]
% [wg, pg] = gaussQuadrature(m);

% Sg = 0.5*Shapes.Length*pg + 0.5*Shapes.Length;
% Wg = 0.5*Shapes.Length*wg;

% Shapes.beamsolver.evalGlobal.weights = Wg;
% Shapes.beamsolver.evalGlobal.points  = Sg;

end