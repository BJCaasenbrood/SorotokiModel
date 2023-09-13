function Shapes = addContact(Shapes,varargin)
    if isa(varargin{1},'Sdf')
        % sdf = varargin{1};
        % varargin{1} = @(x) sdf.eval(x);
        Shapes.system.ContactSDF = varargin{1};
    end
        
    if numel(varargin) < 2
        varargin{2} = [0,0]; 
    end

    Shapes = addContactShapes(Shapes,varargin{1:end});
end