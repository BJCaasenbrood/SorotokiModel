function Shapes = addDrag(Shapes,varargin)
    if ~isfield(Shapes.system,'Drag')
    	Shapes.system.Drag = struct;
    	Shapes.system.Drag.params = struct;
    end
    	
    if numel(varargin) == 1
        Shapes.system.Drag.params.Rho = abs(varargin{1});
        Shapes.system.Drag.params.Cp  = 1.00;   
        Shapes.system.Drag.params.Ct  = 0.01;     
    elseif numel(varargin) == 2
    	Shapes.system.Drag.params.Rho = abs(varargin{1});
        Shapes.system.Drag.params.Cp  = clamp(varargin{2}, 0, 1);
        Shapes.system.Drag.params.Ct  = 0.01;
    elseif numel(varargin) == 3
    	Shapes.system.Drag.params.Rho = abs(varargin{1});
        Shapes.system.Drag.params.Cp  = clamp(varargin{2}, 0, 1);        
        Shapes.system.Drag.params.Ct  = clamp(varargin{3}, 0, 1); 
    else
        Shapes.system.Drag.params.Rho = 0.0;
        Shapes.system.Drag.params.Ct  = 0.0;
        Shapes.system.Drag.params.Cp  = 0.0; 
    end
end
