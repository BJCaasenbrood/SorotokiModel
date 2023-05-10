function Shapes = showRenderShapes(Shapes,varargin)

TubeRadiusA = 5;
TubeRadiusB = 5;
TubeRadiusAlpha = 1e-6;
TubeRamp = 0.8;

if nargin < 2
    q = Shapes.solver.sol.x;
else
    q = varargin{1};
end

p0 = Shapes.beamsolver.g0(1:3,4);
g  = string(Shapes,q);

Node = [p0.'; reshape(g(1:3,4,1:end),3,[]).'];

L = sum(sqrt(sum(diff(Node).^2,2))) + ...
    Shapes.Length/Shapes.NNode;

Stretch = L/Shapes.Length;

[x,y,z] = rtubeplot(Node.',...
    TubeRadiusA,...
    TubeRadiusB,...
    TubeRadiusAlpha,...
    16,1e-6,...
    TubeRamp*(Stretch));

fv = surf2patch(x,y,z,'triangles');
v = fv.vertices;
f = fv.faces;

if isempty(Shapes.Gmodel)
    Shapes.Gmodel = Gmodel(v,f);
    Shapes.Gmodel.render();
else
    Shapes.Gmodel.Node = v;
    Shapes.Gmodel.update();
end
end