function TendonEval = computeTendonNetworkShapes(Shapes,s)

    M = numel(Shapes.Muscle);
    P = zeros(numel(s),3,M);
    F = zeros(numel(s),3,M);
    r = Shapes.TubeRadiusA;

    Xi03 = Shapes.xia0(4:6);

    for ii = 1:M
        fnc = Shapes.Muscle{ii};
        P0  = R(s). * fnc(s);
        P(:,:,ii) = P0.' + (s.*(Xi03(:))*Shapes.Length).';
        F(:,:,ii) = P0.';
    end

end