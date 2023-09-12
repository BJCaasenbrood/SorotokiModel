function Shapes = assembleContactMeshShapes(Shapes)

    TubeRadiusA = Shapes.geometry.TubeRadiusA;
    TubeRadiusB = Shapes.geometry.TubeRadiusB;
    TubeRadiusAlpha = Shapes.geometry.TubeRadiusAlpha;
    TubeRamp = Shapes.geometry.TubeRamp;
    
    p0 = Shapes.beamsolver.g0(1:3,4);
    g  = string(Shapes,zeros(Shapes.NJoint,1));
    
    Node = [p0.'; reshape(g(1:3,4,1:end),3,[]).'];
    
    L = sum(sqrt(sum(diff(Node).^2,2))) + ...
        Shapes.Length/Shapes.NNode;
    
    [x,y,z] = rtubeplot(Node.',...
        TubeRadiusA,...
        TubeRadiusB,...
        TubeRadiusAlpha,...
        16,1e-6,...
        TubeRamp);
    
    fv = surf2patch(x,y,z,'triangles');
    V  = unique(fv.vertices,'rows');

    [xy,~,t] = distance2curve(Node,V);

    relNode = V - xy;

    Shapes.system.ContactMesh = struct;
    Shapes.system.ContactMesh.g  = zeros(4,4,numel(t));
    Shapes.system.ContactMesh.Ia = round(t * Shapes.NNode);

    for ii = 1:numel(t)
        Shapes.system.ContactMesh.g(1:4,1:4,ii) = eye(4);
        Shapes.system.ContactMesh.g(1:3,4,ii) = relNode(ii,:);
    end

end