function Shapes = assembleBoundaryShapes(Shapes)

    Ft  = sparse(Shapes.NJoint,1);  % init contraction force
    Fnc = sparse(Shapes.NJoint,1);  % init normal contact force
    Ftc = sparse(Shapes.NJoint,1);  % init tangent contact force
    Fsc = sparse(Shapes.NJoint,1);  % init normal contact force
    Fst = sparse(Shapes.NJoint,1);  % init normal contact force
    F   = sparse(Shapes.NJoint,1);  % init global force vector
    
    % adding controller loads
    if isfield(Shapes.system,'Controller') 
         u = Shapes.system.Controller(Shapes);
         G = Shapes.system.InputMap(Shapes);
         F = G * u;

         Shapes.system.fControl = u;
    elseif isfield(Shapes.system,'fControl') && ~isfield(Shapes.system,'Controller') 
        G = Shapes.system.InputMap(Shapes);
        F = G * Shapes.system.fControl;
    else
        G = Shapes.system.InputMap(Shapes);
        F = zeros(Shapes.NJoint,1);
    end
    
    % adding contact loads
    if isfield(Shapes.system,'Contact') 
        [Fnc, Ftc, Knc, Ktc]  = assembleContactShapes(Shapes);
        Shapes.system.Tangent = Shapes.system.Tangent + Knc + Ktc; 
        Shapes.system.Damping = Shapes.system.Damping + (Knc + Ktc) * Shapes.solver.TimeStep;
        Shapes.system.fDamping = Shapes.system.fDamping ...
            + (Knc + Ktc) * Shapes.solver.TimeStep * Shapes.solver.sol.dx;
    end

    if Shapes.options.isSelfContact
        [Fsc, Fst, Ksn, Dsn] = assembleSelfContactShapes(Shapes);
        Shapes.system.Tangent = Shapes.system.Tangent + Ksn;  
        Shapes.system.Damping = Shapes.system.Damping + Dsn;     
        % Shapes.system.fDamping = Shapes.system.fDamping ...
            % + Dsn * Shapes.solver.sol.dx;
    end

    
    Shapes.system.fContact = Fnc + Fsc + Fst;
    Shapes.system.fTangent = Ftc;
    Shapes.system.fInput   = F + Ft + Fnc + Ftc + Fsc + Fst;
    
end
    
    