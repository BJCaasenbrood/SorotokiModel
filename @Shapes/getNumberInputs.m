function nu = getNumberInputs(Shapes)
    Geval = Shapes.system.InputMap(zeros(Shapes.NJoint,1));
    nu = size(Geval,2);
end

