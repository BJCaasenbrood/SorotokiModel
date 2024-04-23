function Shapes = addGravity(Shapes,varargin)
    if isempty(varargin)
        varargin{1} = [0; 0;-9810];
    end
    
    if numel(varargin{1}) == 3
        Shapes.system.Gravity = varargin{1};    
    elseif numel(varargin{1}) == 1
        Shapes.system.Gravity = [0; 0; varargin{1}];
    end
end