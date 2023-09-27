function Shapes = assembleContactMeshShapes(Shapes)
    
    curve = Shapes.beamsolver.Space * Shapes.Length;
    TubeRadiusA = Shapes.geometry.TubeRadiusA;
    TubeRadiusB = Shapes.geometry.TubeRadiusB;
    TubeRamp  = Shapes.geometry.TubeRamp;
    
    ramp = min(max(TubeRamp,1e-6),1-1e-6);
    rmax = max(TubeRadiusA,TubeRadiusB);
    
    if numel(ramp) == 1
      R = rmax * linspace(1,1-ramp,Shapes.NNode);
    else
      x = linspace(0,1,numel(ramp));
      y = linspace(0,1,Shapes.NNode);
      R = rmax * interp1(x,ramp(:),y);
    end
    
    % R is the radius without rounded end-cap
    R = R(:);

    % end has no contact sphere
    R(end) = 1e-3;

    Shapes.system.ContactMesh.Node = curve;
    Shapes.system.ContactMesh.ContactDistance = R;

end