classdef Model

properties (Access = public)
    Systems;    

    options;
    solver;
    % NDim;         % Total state dimension
    % NIn;          % Total input dimension
    % NSys;         % Number of subsystems
    % NState;       % Number of states per system
    % NInput;       % Number of inputs per system
    % TimeStep;     % Solver timesteps
    % TimeEnd;      % Finite time horizon
    % Systems;      % Cell of subsystems
    % Controller;   % Global system controller
    % Update;       % Update externals (pre-call to controller)
    % Log;          % Logger
    
    % t;            % Time
    % X;            % States
    % X0;           % Initial conditions
    % U;            % Inputs
    % Y;            % Outputs
    % K;            % Linear controller
end

% properties (Access = private)
%     Flow;         % system flow
%     Hessian;      % global Hessian matrix
    
%     Xtmp;         % Temporary states
%     Utmp;         % Temporary inputs
    
%     MaxIteration;
%     MaxRebuild;
%     ResidualNorm;
    
%     ShowProcess; 
% end

 %--------------------------------------------------------------------------
methods  
%----------------------------------------------- MODAL SHAPE RECONSTRUCTION
function obj = Model(Input,varargin) 
    
    obj.options = modeloptions;
    obj.solver  = solveroptions;
    
    % obj.NSys = 1;
    % obj.MaxIteration = 50;
    % obj.MaxRebuild   = 3;
    % obj.ResidualNorm = 1e-6;
    % obj.TimeEnd  = 10;
    % obj.TimeStep = 1/60;
    % obj.ShowProcess = true;
    % obj.Log = struct;

    % obj.NDim = Input.NDim;        
    % obj.NIn  = Input.NInput;        
    % obj.Systems{1} = Input;
    % obj.NState{1}  = Input.NDim;
    % obj.NInput{1}  = Input.NInput;

    for ii = 1:2:length(varargin)
        obj.(varargin{ii}) = varargin{ii+1};
    end
    
    %obj = obj.rebuild();
    
end
%---------------------------------------------------------------------- get     
function varargout = get(Model,varargin)
    if nargin > 1
        varargout{nargin-1,1} = [];
        for ii = 1:length(varargin)
            varargout{ii,1} = Model.(varargin{ii});
        end
    else
        varargout = Model.(varargin);
    end
end       

end
end