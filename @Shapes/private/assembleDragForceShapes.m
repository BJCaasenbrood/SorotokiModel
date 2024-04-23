function [Fd, Dd] = assembleDragForceShapes(Shapes)

    Ns   = Shapes.NNode;
    R    = Shapes.system.Backbone(1:3,1:3,:);
    Vlin = Shapes.system.Velocity(4:6,:,:);
    Jv   = Shapes.system.Jacobian(4:6,:,:);
    Rho  = Shapes.system.Drag;
    Fd   = sparse(Shapes.NJoint,1); 
    Dd   = sparse(Shapes.NJoint,Shapes.NJoint); 

    Ct = 0.01;
    Cp = 0.49;

    taper  = min(max(Shapes.geometry.TubeRamp,1e-6),1-1e-6);
    Radius = Shapes.geometry.TubeRadiusA * linspace(1,1-taper,Ns);

    for ii = 1:numel(Shapes.beamsolver.Space)

        VV = R(:,:,ii) * Vlin(:,:,ii);
        V2 = VV .* abs(VV);

        At = 2 * pi * Radius(ii);
        Ap = 2 * Radius(ii);

        % deriv of R*[(J dq) .* abs(J * dq)]
        dV2ddq = R(:,:,ii) * (Jv(:,:,ii) .* abs(VV) + VV .* sign(VV) .* Jv(:,:,ii));

        
        Fd = Fd - 0.5 * Rho * Jv(:,:,ii).' * ([Ct*At; Cp*Ap; Cp*Ap] .* V2);    
        Dd = Dd + 0.5 * Rho * Jv(:,:,ii).' * ([Ct*At; Cp*Ap; Cp*Ap] .* dV2ddq);
    end
end