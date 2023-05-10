function Shapes = addContactShapes(Shapes,varargin)   
    if ~isfield(Shapes.system,'Contact')
        Shapes.system.Load = {};
    end

    SDF = varargin{1};
    % if ~isa(varargin{2},'function_handle')
    %     func = @(t) varargin{2} * clamp(t,0,1);
    % end

    [n,~] = size(Shapes.system.Load);

    Shapes.system.Contact{n+1,1} = SDF;
    Shapes.system.Contact{n+1,2} = zeros(3,1);
end