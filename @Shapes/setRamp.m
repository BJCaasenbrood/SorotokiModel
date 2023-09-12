function Shapes = setRamp(Shapes,x)
    % clamp tube-ramp value to [0,1]
    Shapes.geometry.TubeRamp = clamp(x,0,1);
end