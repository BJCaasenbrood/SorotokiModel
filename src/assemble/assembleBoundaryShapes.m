function Shapes = assembleBoundaryShapes(Shapes)

    Ft  = sparse(Shapes.NJoint,1);  % init contraction force
    Fnc = sparse(Shapes.NJoint,1);  % init normal contact force
    Ftc = sparse(Shapes.NJoint,1);  % init tangent contact force
    F   = sparse(Shapes.NJoint,1);  % init global force vector
    
    % adding controller loads
    if isfield(Shapes.system,'Controller') 
         F = Shapes.system.Controller(Shapes);
    end
    
    % adding contact loads
    if isfield(Shapes.system,'Contact') 
        [Fnc, Ftc, Knc, Ktc] = assembleContactShapes(Shapes);
        Shapes.system.Tangent = Shapes.system.Tangent + Knc + Ktc; 
    end
        
    Shapes.system.fContact = Fnc;
    Shapes.system.fTangent = Ftc;
    Shapes.system.fInput   = F + Ft + Fnc + Ftc;
    
end
    
    