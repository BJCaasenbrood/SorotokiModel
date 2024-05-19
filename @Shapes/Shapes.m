classdef Shapes

    properties (Access = public)
        Sdf;
        Fem;
        Gmodel;
        Material;

        options;
        beamsolver;
        geometry;
        childern;
        solver;
        system;
        pod;

        Length;     
        NDim;       % State dimensions
        NJoint;     % Joint dimension (i.e, NDim/2)
        NInput;     % Number of inputs
        NNode;      % Number of nodes (spatial discretization)
    end
   
%--------------------------------------------------------------------------
methods  
%----------------------------------------------- MODAL SHAPE RECONSTRUCTION
function obj = Shapes(Basis,ModalDof,varargin) 

    obj.options    = shapesoptions;
    obj.beamsolver = beamoptions;
    obj.solver     = solveroptions;
    obj.geometry   = geometryoptions;
    obj.system     = struct;
    obj.system.pod = struct;

    if nargin < 3
        BaseDof = [0,0,0,0,0,0];
    elseif numel(varargin{1}) == 6 && ~isa(varargin{1},'char')
        BaseDof = varargin{1};
        varargin = {varargin{2:end}};
    else
        BaseDof = [0,0,0,0,0,0];
    end

    obj.options.NModal = ModalDof;
    obj.options.Table  = [double(ModalDof > 0)]; 
    obj.options.NDof   = sum(obj.options.Table);

    obj.options.NBase     = BaseDof;
    obj.options.BaseTable = [double(BaseDof > 0)]; 
    obj.options.NBaseDof  = sum(obj.options.BaseTable);

    obj.NNode = size(Basis,1);
    obj.system.pod.PODQ = Basis;
    obj.system.pod.PODR = Basis;
    
    obj.Length = 100;
    obj.beamsolver.Space = linspace(0,1,obj.NNode); 
    obj.beamsolver.SpaceStep = obj.Length/(obj.NNode);
    
    obj.system.Gravity = zeros(3,1);
    obj.Material = NeoHookean(1.0,0.33);
    
    obj.options.FilterRadius        = 10;
    obj.options.isRampCompensation  = false;
    obj.solver.Regularization       = 333;
    obj.solver.MaxIteration         = 100;
    obj.options.Texture = matcap_bluebase;

    obj = vararginParser(obj,varargin{:});

    obj.NJoint = sum(obj.options.NModal) + sum(obj.options.NBase);
    obj.NDim   = 2*obj.NJoint;

    if ~isfield(obj.system,'InputMap')
        obj.system.InputMap = @(x) eye(obj.NJoint);
        obj.NInput = obj.NJoint;
    end
    
    obj = rebuild(obj);
end  

end

end

