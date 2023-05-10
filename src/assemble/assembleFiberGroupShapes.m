function [P, F] = assembleFiberGroupShapes(Shapes, s)

    M = numel(Shapes.system.Fiber);
    P = zeros(numel(s), 3, M);
    F = zeros(numel(s), 3, M);
    r = Shapes.TubeRadiusA;

    if isempty(Shapes.TubeRamp)
        R = @(x) r;
    else
        R = @(x) r * (1 - Shapes.TubeRamp * x);
    end

    Xi03 = Shapes.xia0(4:6);

    for ii = 1:M
        fnc = Shapes.system.Fiber{ii};
        P0 = R(s) .* fnc(s);
        P(:, :, ii) = P0.' + (s .* (Xi03(:)) * Shapes.Length).';
        F(:, :, ii) = P0.';
    end

end
