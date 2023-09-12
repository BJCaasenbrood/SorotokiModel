function Fd = assembleDragForceShapes(Shapes)

    Ns   = Shapes.NNode;
    R    = Shapes.system.Backbone(1:3,1:3,:);
    Vlin = Shapes.system.Velocity(4:6,:,:);
    Jv   = Shapes.system.Jacobian(4:6,:,:);
    Rho  = Shapes.system.Drag;
    Fd   = sparse(Shapes.NJoint,1); 

    Ct = 0.01;
    Cp = 1;

    taper  = min(max(Shapes.geometry.TubeRamp,1e-6),1-1e-6);
    Radius = Shapes.geometry.TubeRadiusA * linspace(1,1-taper,Ns);

    for ii = 1:numel(Shapes.beamsolver.Space)
        
        if ii == numel(Shapes.beamsolver.Space)
            1;
        end

        VV = (Vlin(:,:,ii));
        V2 = VV .* abs(VV);
        At = 2 * pi * Radius(ii);
        Ap = 2 * Radius(ii);

        % Fd = Fd - 0.5 * Rho * Jv(:,:,ii).' * ... 
        %      (R(:,:,ii) * [Ct*At; Cp*Ap; Cp*Ap] .* V2);
        
        Fd = Fd - 0.5 * Rho * Jv(:,:,ii).' * (R(:,:,ii) * [Ct*At; Cp*Ap; Cp*Ap] .* V2);     
    end
end