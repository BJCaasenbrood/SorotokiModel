function Shapes = addGravity(Shapes,varargin)
    if isempty(varargin)
        varargin{1} = [0; 0;-9810];
    end
    Shapes.system.Gravity = varargin{1};    
end