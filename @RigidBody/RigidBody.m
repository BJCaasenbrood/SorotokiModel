classdef RigidBody

    properties (Access = public)
        options;
        system;
        solver;
        params;
        Gmodel;
    
        NDim;
        NInput;
    end
    
    properties (Access = private)
        Mtt;          % inertia tensor
    end
   
%--------------------------------------------------------------------------
methods  
%----------------------------------------------- MODAL SHAPE RECONSTRUCTION
function obj = RigidBody(Inertia,varargin) 
    
    % [q1,q2,q2,q4,px,py,pz,w1,w2,w3,a1,a2,a3]
    % [1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11,12,13]
    obj.NDim = 13;
    obj.Mtt = Inertia;

    obj.options = rigidbodyoptions;
    obj.solver = solveroptions;
    obj.system = struct;

    obj.system.Gravity = [0;0;0];

    obj.solver.RelTolerance = 1e-1;
    obj.solver.MaxIteration = 5;
    obj.solver.Residual = zeros(obj.NDim,1);
    obj.solver.sol.x = zeros(obj.NDim,1);

    obj.solver.sol.x(1) = 1;
    
    obj = vararginParser(obj,varargin);
end

end
end