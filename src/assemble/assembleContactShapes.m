function [Fnc, Ftc, Knc, Ktc] = assembleContactShapes(Shapes)

    omegaN = Shapes.Material.getContactReaction;
    omegaT = Shapes.Material.getContactFriction;
    
    Knc = sparse(Shapes.NJoint,Shapes.NJoint);
    Ktc = sparse(Shapes.NJoint,Shapes.NJoint);
    Fnc = sparse(Shapes.NJoint,1); 
    Ftc = sparse(Shapes.NJoint,1); 
    SDF = Shapes.system.Contact{1};
    
    g = Shapes.system.Backbone;

    Ia  = Shapes.system.ContactMesh.Ia;
    gC  = Shapes.system.ContactMesh.g(:,:,Ia~=0);
    J   = Shapes.system.Jacobian(:,:,Ia(Ia~=0));
    Eta = Shapes.system.Velocity(:,:,Ia(Ia~=0));

    gContact = pagemtimes(g(:,:,Ia(Ia~=0)),gC);

    Y = backbone(gContact);

    eps = 1e-6;
    d   = SDF(Y);
    Intersect = find((d(:,end))<eps);
    
    if ~isempty(Intersect)

        I = Intersect;
        
        n1 = (SDF(Y(I,:)+repmat([eps,0,0],size(Y(I,:),1),1))-d(I,end))/eps;
        n2 = (SDF(Y(I,:)+repmat([0,eps,0],size(Y(I,:),1),1))-d(I,end))/eps;
        n3 = (SDF(Y(I,:)+repmat([0,0,eps],size(Y(I,:),1),1))-d(I,end))/eps;

        B = (d(I,end));
    
        Ux = B.*n1(:,end);
        Uy = B.*n2(:,end);
        Uz = B.*n3(:,end);
    
        % normal vector, tangent vector
        N(:,1) =  n1(:,end);
        N(:,2) =  n2(:,end);
        N(:,3) =  n3(:,end);

        T = zeros(3,1,numel(I));
        T(2,:,:) =  n1(:,end);
        T(1,:,:) = -n2(:,end);
        T(3,:,:) =  n3(:,end);

        JvT = pagetranspose(J(4:6,:,I));

        fContact = zeros(3,1,numel(I));
        fContact(1,:,:) = -omegaN * Ux;
        fContact(2,:,:) = -omegaN * Uy;
        fContact(3,:,:) = -omegaN * Uz;

        Fnc = sum(pagemtimes(JvT, fContact),3);
    
        V0 = Eta(4:6,:,I);
        Vn = V0./sqrt(sum((V0.^2),1) + 1e-2);
        Ffric = pagemtimes(pagetranspose(Vn),T) .* T; 

        RF = zeros(1,1,numel(I));
        RF(1,1,:) = sqrt(sum(((omegaN * [-Ux, -Uy, -Uz]).^2),2));

        fFriction = zeros(3,1,numel(I));
        fFriction(1,:,:) = -omegaT * Ffric(1,:,:);
        fFriction(2,:,:) = -omegaT * Ffric(2,:,:);
        fFriction(3,:,:) = -omegaT * Ffric(3,:,:);
        
        Ftc = sum(pagemtimes(pagemtimes(JvT, fFriction),RF),3);

        for ii = 1:numel(I)
            kk = JvT(:,:,ii) * N(ii,:).';
            tt = JvT(:,:,ii) * T(:,:,ii);
            Knc = Knc + omegaN * kk * (kk).';
            Ktc = Ktc + omegaT * tt * (tt).';
        end
    
    end
end