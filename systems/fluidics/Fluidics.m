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
    obj.solver.Residual = zeros(obj.NDim,1);
    obj.solver.sol.x  = zeros(obj.NDim,1);

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
%--------------------------------------------------------------------- flow
function [dx, Fluidics] = flow(Fluidics)

    x = Fluidics.solver.sol.x;
    t = Fluidics.solver.Time;

    if isfield(Fluidics.solver.sol,'u')
        u = Fluidics.solver.u;
    else
        u = 0;
    end

    [dx, Fluidics] = flowDynamicsFluidics(Fluidics, x(:), u(:), t);
end
%------------------------------------------------------------------ hessian
function H = hessian(Fluidics)
    
    x = Fluidics.solver.sol.x;
    t = Fluidics.solver.Time;

    if isfield(Fluidics.solver.sol,'u')
        u = Fluidics.solver.u;
    else
        u = 0;
    end
 
    eps = 1e-6;
    H   = zeros(Fluidics.NDim);
    f0  = flowDynamicsFluidics(Fluidics,x,u,t);
    dx  = eye(Fluidics.NDim)*eps;
    
    for ii = 1:Fluidics.NDim
        f1 = flowDynamicsFluidics(Fluidics, x + dx(:,ii),u,t);
        H(:,ii) = (f1 - f0)/eps;
    end
 
end
end
end


    % properties (Access = public)
    %     NDim;         % state dimensions
    %     NInput;       % input dimension
    %     Nonlinear;    % nonlinear true
    %     X0;           % initial conditions
        
    %     Type;         % Mass or Pressure regulated
    %     isRegulated;  % Internal controller
       
    %     Polytropic;   % Polytropic coefficient
    %     GasConstant;  % Gas constant in mJ * K-1 * mol-1
    %     Temperature;  % Temperature
    %     Atmosphere;   % Atmosphere pressure (1 bar)
    %     Leakage;      % Leakage (kpa / s)

    %     Kp;           % Fluidic P-action gain
    %     Ki;           % Fluidic I-action gain

    %     Volume;       % Volume function
    %     MassFlow;     % Mass-vs-pressure flow
        
    %     Log;          % log file
    % end
