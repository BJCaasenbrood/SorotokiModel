function Model = addSystem(Model,varargin)
    for ii = 1:numel(varargin)
        Model.Systems{end+1} = varargin{1};
    end
    
    Model = rebuild(Model);
end
