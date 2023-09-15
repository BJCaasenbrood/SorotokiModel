classdef StateSpace

    properties (Access = public)
        options;
        solver;
        system;
        % NDim;         % state dimensions
        % NInput;       % input dimension
        % Nonlinear;    % nonlinear (1) or linear ODE (0)
        % X0;           % initial conditions
        % A;            % state matrix 
        % B;            % input matrix
        % C;            % output matrix
        % Flow;         % system flow
        % Hessian;      % global Hessian matrix
    end
   
%--------------------------------------------------------------------------
methods  
%----------------------------------------------- MODAL SHAPE RECONSTRUCTION
function obj = StateSpace(Input,X0,varargin) 

    obj.options = modeloptions;
    obj.solver  = solveroptions;
    obj.system  = struct;

    assert( isa(Input,'cell') || isa(Input,'function_handle'), ...
           ['Input must be a cell; for linear ODE: {A,B,C} or ',...
           'for nonlinear ode: {@f, @dfdq} or {@f}']); 
    
    if  isa(Input,'function_handle') 
        Input = {Input};
    end

    % construct linear ODE
    if isa(Input{1},'double')
        obj.options.isNonlinear = false;
        obj.solver.sol.x = X0(:);
        obj.system.A = Input{1};
        obj.system.B = Input{2};
        
        assert( size(obj.system.A,1) == numel(obj.solver.sol.x) , ...
            'Dimension error, matrix A have different dimension than X0'); 
        assert( size(obj.system.B,1) == numel(obj.solver.sol.x) , ...
            'Dimension error, matrix B have different dimension than X0'); 

    elseif isa(Input{1},'function_handle')

        obj.options.isNonlinear = true;
        obj.solver.sol.x = X0(:);
        obj.system.f = Input{1};

        assert( size(obj.system.f(X0(:),0,0),1) == numel(X0) , ...
            'Dimension error, flow have different dimension than X0'); 

        if numel(Input) > 1
            obj.system.dfdx = Input{2};

            assert( size(obj.system.dfdx(X0(:),0,0),1) == numel(X0) , ...
                'Dimension error, hessian have different dimension than X0'); 
        end
    end

    for ii = 1:2:length(varargin)
        obj.(varargin{ii}) = varargin{ii+1};
    end
end

end
end

