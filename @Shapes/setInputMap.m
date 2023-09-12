function Shapes = setInputMap(Shapes,varargin)
    Shapes.system.InputMap = varargin{1};
    G0 = Shapes.system.InputMap(Shapes);
    Shapes.NInput = size(G0,2);
end