function Shapes = set(Shapes,varargin)
    Shapes = vararginParser(Shapes,varargin{:});
end

function obj = vararginParser(obj,varargin)

    % keyboard
    for ii = 1:2:length(varargin)
        
        if isprop(obj, varargin{ii})
            obj.(varargin{ii}) = varargin{ii + 1};
        end

        if isprop(obj,'options')
            if isprop(obj.options, varargin{ii})
                obj.options.(varargin{ii}) = varargin{ii + 1};
            end
        end

        if isprop(obj, 'solver')
            if isprop(obj.solver, varargin{ii})
                obj.solver.(varargin{ii}) = varargin{ii + 1};
            end
        end
    end

end
