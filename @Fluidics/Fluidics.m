classdef Fluidics

properties (Access = public)
    options;
    system;
    solver;
    params;

    NDim;
    NInput;
end

%------------------------------------------------------------------- Public
%--------------------------------------------------------------------------
methods  
%------------------------------------------------------------------ FLUDICS
function obj = Fluidics(varargin) 
    obj.NDim = 3;
    obj.params.Polytropic  = 1;
    obj.params.GasConstant = 8.31446261815324 * 1e3;  %mJ * K-1 * mol-1
    obj.params.Atmosphere  = 101.325; % kPA
    obj.params.Temperature = 293.15;  % Kelvin
    obj.params.Leakage     = 1e-6;
    obj.params.Kp          = 0.1;
    obj.params.Ki          = 0.00;

    obj.options = fluidicsoptions;
    obj.solver = solveroptions;
    obj.system = struct;
    
    obj.solver.RelTolerance = 1e-1;
    obj.solver.MaxIteration = 5;
    obj.solver.Residual     = zeros(obj.NDim,1);
    obj.solver.sol.x        = zeros(obj.NDim,1);

    obj.system.PVCurve  = @(x) (4/3) * pi * 20^3;
    obj.system.MassFlow = @(x) 1.0;

    obj = vararginParser(obj,varargin);
end
%---------------------------------------------------- set vessel input type    
function Fluidics = setType(Fluidics,varargin)
    if strcmp(varargin{1},'Mass')
        Fluidics.options.Type = 'Mass';
    elseif strcmp(varargin{1},'Pressure')
        Fluidics.options.Type = 'Pressure';
    else
       error('Type must be either: Mass or Pressure');
    end
end
%--------------------------------------------------------------- set volume     
function Fluidics = setPV(Fluidics,varargin)
    if isa(varargin{1},'function_handle')
        Fluidics.system.PVCurve = varargin{1};
    elseif isa(varargin{1},'double')
        Fluidics.system.PVCurve = @(x) varargin{1};
    else
        error('PV-curve must be either a double or function_handle');
    end     
end 
%--------------------------------------------------------------- set volume    
function Fluidics = setRegulator(Fluidics,varargin)
    for ii = 1:numel(varargin)
        if islogical(varargin{ii})
            Fluidics.options.isRegulated = varargin{1};
        elseif strcmpi(varargin{ii},'on')
            Fluidics.options.isRegulated = true;
        elseif strcmpi(varargin{ii},'off')
            Fluidics.options.isRegulated = false;
        elseif strcmpi(varargin{ii},'mass')
            Fluidics.options.Type = 'Mass';
        elseif strcmpi(varargin{ii},'pressure')
            Fluidics.options.isRegulated = 'Pressure';
        end
    end
end
end
end
