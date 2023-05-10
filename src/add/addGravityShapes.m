function Shapes = addGravityShapes(Shapes,varargin)   

    if ~isa(varargin{2},'function_handle')
        func = varargin{2};
    end

    Shapes.system.Gravity = func;
end