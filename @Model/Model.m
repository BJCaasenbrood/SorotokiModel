classdef Model

properties (Access = public)
    Systems;    

    system;
    options;
    solver;
    NDim;         % Total state dimension
    NIn;          % Total input dimension
end

 %--------------------------------------------------------------------------
methods  
%----------------------------------------------- MODAL SHAPE RECONSTRUCTION
function obj = Model(Input,varargin) 
    
    obj.options = modeloptions;
    obj.solver  = solveroptions;
    obj.system  = struct;

    obj.NDim = 0;
    obj.NIn  = 0;

    if ~isempty(Input)
        obj.NDim = Input.getDimension;        
        obj.NIn  = Input.getNumberInputs;        
        obj.system.Systems{1} = Input;
        obj.system.NState{1} = Input.getDimension;
        obj.system.NInput{1} = Input.getNumberInputs;

        if isa(Input,'Shapes')
            obj.solver.sol.x = [Input.solver.sol.x; Input.solver.sol.dx];
        else
            obj.solver.sol.x = Input.solver.sol.x;
        end
    else

    end

    for ii = 1:2:length(varargin)
        obj.(varargin{ii}) = varargin{ii+1};
    end

end
    

end
end
