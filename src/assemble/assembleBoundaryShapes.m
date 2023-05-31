function Shapes = assembleBoundaryShapes(Shapes)

    Fnc = sparse(Shapes.NJoint,1);  % init normal contact force
    Ftc = sparse(Shapes.NJoint,1);  % init tangent contact force
    Fd  = sparse(Shapes.NJoint,1);  % init drag force
    F   = sparse(Shapes.NJoint,1);  % init global force vector

    G = 1;
    % evaluate input map
    if isfield(Shapes.system,'InputMap')
        G = Shapes.system.InputMap(Shapes);
        Shapes.system.Input = G;
    end

    % adding controller loads
    if isfield(Shapes.system,'Controller') 
         u = Shapes.system.Controller(Shapes);
         F = G * u;
    end
    
    % adding contact loads
    if isfield(Shapes.system,'Contact') 
        [Fnc, Ftc, Knc, Ktc]  = assembleContactShapes(Shapes);
        Shapes.system.Tangent = Shapes.system.Tangent + Knc + Ktc; 
    end

    if isfield(Shapes.system,'Drag')
        [Fd]  = assembleDragForceShapes(Shapes);
    end
        
    Shapes.system.fContact = Fnc;
    Shapes.system.fTangent = Ftc;
    Shapes.system.fInput   = F + Fnc + Ftc + Fd;
    
end
    
    