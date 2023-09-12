function [P, F] = assembleActuatorGroupShapes(Shapes, s)

    M  = numel(Shapes.system.Actuator);
    P0 = zeros(numel(s), 3);
    P  = zeros(numel(s), 3, M);
    F  = zeros(numel(s), 3, M);

    TubeRadiusA = Shapes.geometry.TubeRadiusA;
    TubeRadiusB = Shapes.geometry.TubeRadiusB;
    TubeRadiusAlpha = Shapes.geometry.TubeRadiusAlpha;

    if isempty(Shapes.geometry.TubeRamp)
        Scale = @(x) 1;
    else
        Scale = @(x) (1 - Shapes.geometry.TubeRamp * x);
    end

    Dir0 = Shapes.beamsolver.g0(1:3,1:3) * ...
        Shapes.beamsolver.Xi0Eval(4:6,:,1);

    for ii = 1:M
        R = Scale(s(:)) .* Shapes.system.Actuator{ii}(s(:));
        [P0(:,2), P0(:,3)] = unit2squircle(R, ...
            TubeRadiusAlpha,TubeRadiusA,TubeRadiusB);

        P(:, :, ii) = P0 + (s(:).' .* Dir0(:) * Shapes.Length).';
        F(:, :, ii) = P0;
    end

end
