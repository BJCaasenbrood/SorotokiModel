%--------------------------------------------------------------- add muscle
function Shapes = addActuator(Shapes,varargin)
    if ~isfield(Shapes.system,'Actuator')
        Shapes.system.Actuator = {varargin{1}};
    else
        Shapes.system.Actuator{end+1,1} = varargin{1};
    end
end