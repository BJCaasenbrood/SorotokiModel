function Shapes = addSetpointShapes(Shapes,varargin)
if ~isfield(Shapes.system,'Setpoint')
    Shapes.system.Setpoint = {};
end

if numel(varargin) > 1
    fDof = varargin{1};
    if ~isa(varargin{2},'function_handle')
        func = @(t) varargin{2} * clamp(t,0,1);
    end
else
    fDof = Shapes.NNode;
    if ~isa(varargin{1},'function_handle')
        func = @(t) varargin{1} * clamp(t,0,1);
    end
end

[n,~] = size(Shapes.system.Setpoint);

Shapes.system.Setpoint{n+1,1} = fDof;
Shapes.system.Setpoint{n+1,2} = func;
end