function [Fsc, Fst, Ksn, Dsn] = assembleSelfContactShapes(Shapes)

    n  = Shapes.NNode;
    p  = backbone(Shapes.system.Backbone); 
    R0 = Shapes.geometry.TubeRadiusA;
    omegaN = Shapes.Material.getContactReaction;
    omegaT = Shapes.Material.getContactFriction;
    JvT = pagetranspose(Shapes.system.Jacobian(4:6,:,:));
    
    Fsc = sparse(Shapes.NJoint,1);
    Fst = sparse(Shapes.NJoint,1);
    Ksn = sparse(Shapes.NJoint,Shapes.NJoint);
    %Dsn = sparse(Shapes.NJoint,Shapes.NJoint);
    ramp = min(max(Shapes.geometry.TubeRamp,1e-6),1-1e-6);

    if numel(ramp) == 1
        R = R0*linspace(1,1-ramp,n);
    else
        R = R0*interp1(x,ramp(:),y);
    end
   
    isContact = false;
    fContact  = zeros(3,1,n);
    fFriction = zeros(3,1,n);

    %generate set of edges
    Edge = Shapes.system.ContactEdge;

    for ii = 1:size(Edge,1)

        E11 = Edge(ii,1);
        E12 = Edge(ii,1) + 1;
        E21 = Edge(ii,2);
        E22 = Edge(ii,2) + 1;

        [D,pc,qc,W] = sdLines(p([E11;E12],:), p([E21;E22],:));

        % penetration depth
        R1 = R(E11);
        R2 = R(E21);

        U = D - R1 - R2;
        
        if (U < 0) && sum(W) ~= 1
            isContact = true;
    
            Vlin = Shapes.system.Velocity(4:6,:,[E11,E21]);
            V1 = Vlin(:,:,1) - Vlin(:,:,2);
            V2 = -V1;

            N1 = (pc(:)-qc(:))./sqrt(sum((pc(:)-qc(:)).^2)+1e-12);
            N2 = -N1;

            T1(1,1) = -N1(2); 
            T1(2,1) = N1(1); 
            T1(3,1) = N1(3); 
            T2 = -T1;

            % assemble contact normal forces
            fContact(1:3,1,E11) = -omegaN * (1-W(1)) * (U) * N1;
            fContact(1:3,1,E12) = -omegaN * (W(1)) * (U) * N1;
            fContact(1:3,1,E21) = -omegaN * (1-W(2)) * (U) * N2;
            fContact(1:3,1,E22) = -omegaN * (W(2)) * (U) * N2;

            % assemble contact normal friction forces
            fFriction(1:3,1,E11) = -omegaT * (1-W(1)) * dot(V1,N1) * N1;
            fFriction(1:3,1,E12) = -omegaT * (W(1)) * dot(V1,N1) * N1;
            fFriction(1:3,1,E21) = -omegaT * (1-W(2)) * dot(V2,N2) * N2;
            fFriction(1:3,1,E22) = -omegaT * (W(2)) * dot(V2,N2) * N2;

            EE = [E11,E12,E21,E22];
            NN = [N1,N1,N2,N2];
            WW = [(1-W(1)),W(1),(1-W(2)),W(2)];

            % assemble contact stiffness matrix
            for jj = 1:4
                kk = JvT(:,:,EE(jj)) * NN(:,jj);
                Ksn = Ksn + omegaN * kk * (kk).';
            end
        end
    end

    if isContact
        Fsc = sum(pagemtimes(JvT, 1e-1*fContact),3);
        Fst = 0*sum(pagemtimes(JvT, fFriction),3);
    end

    Dsn = Ksn * (omegaT/omegaN);
end