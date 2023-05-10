function [Fnc, Ftc, Knc, Ktc] = assembleContactShapes(Shapes)

    omegaN = Shapes.Material.getContactReaction;
    omegaT = Shapes.Material.getContactFriction;
    
    Knc = sparse(Shapes.NJoint,Shapes.NJoint);
    Ktc = sparse(Shapes.NJoint,Shapes.NJoint);
    Fnc = sparse(Shapes.NJoint,1); 
    Ftc = sparse(Shapes.NJoint,1); 
    SDF = Shapes.system.Contact{1};
    
    g = Shapes.system.Backbone;
    J = Shapes.system.Jacobian;
    Y = backbone(g);
    
    eps = 1e-6;
    d   = SDF(Y);
    Intersect = find((d(:,end))<eps);
    
    if ~isempty(Intersect)

        I = Intersect;
        
        n1 = (SDF(Y(I,:)+repmat([eps,0,0],size(Y(I,:),1),1))-d(I,end))/eps;
        n2 = (SDF(Y(I,:)+repmat([0,eps,0],size(Y(I,:),1),1))-d(I,end))/eps;
        n3 = (SDF(Y(I,:)+repmat([0,0,eps],size(Y(I,:),1),1))-d(I,end))/eps;
    
        Ux = (d(I,end)).*n1(:,end);
        Uy = (d(I,end)).*n2(:,end);
        Uz = (d(I,end)).*n3(:,end);
    
        % normal vector, tangent vector
        N(:,1) =  n1(:,end);
        N(:,2) =  n2(:,end);
        N(:,3) =  n3(:,end);
        T(:,2) =  n1(:,end);
        T(:,1) = -n2(:,end);
        T(:,3) =  n3(:,end);

        JvT = pagetranspose(J(4:6,:,I));

        fContact = zeros(3,1,numel(I));
        fContact(1,:,:) = -omegaN * Ux;
        fContact(2,:,:) = -omegaN * Uy;
        fContact(3,:,:) = -omegaN * Uz;

        Fnc = sum(pagemtimes(JvT, fContact),3);
    
        % V0 = dU(I,:);
        % Vn = V0./sqrt(sum((V0.^2),2) + 1e-2);
        % Ffric = (dot(Vn.',T.').').*T;

        RF = omegaN * [-Ux, -Uy, -Uz];
        RF = sqrt(sum((RF.^2),2));
        % 
        % % modify forcing
        % Ix = 2*I(1:size(Y(I,:),1),1)-1;
        % Iy = 2*I(1:size(Y(I,:),1),1);
        % 
        % Fnc(Ix,1) = -omegaN*Ux;
        % Fnc(Iy,1) = -omegaN*Uy;
        % Ftc(Ix,1) = -omegaT*(RF).*Ffric(:,1);
        % Ftc(Iy,1) = -omegaT*(RF).*Ffric(:,2);
        
        %index = 0;
        % NDof  = Fem.Dim;
        % I = zeros(numel(Ix)*NDof^2,1);
        % J = zeros(numel(Ix)*NDof^2,1);
        % K = zeros(numel(Ix)*NDof^2,1);
        % T = zeros(numel(Ix)*NDof^2,1);

        for ii = 1:numel(I)
            kk = JvT(:,:,ii) * N(ii,:).';
            Knc = Knc + omegaN * kk * (kk).';
        end
    
        % for ii = 1:numel(Ix)
        %     KK = N(ii,:) .' * N(ii,:);
        %     TT = sign(RF(ii)) * T(ii,:) .' * T(ii,:);
        %     eDof = [Ix(ii);Iy(ii)];
        %     II = repmat(eDof,1,Fem.Dim);
        %     JJ = II';
    
        %     ind = index+1:index+NDof^2;
        %     I(ind) = II(:);
        %     J(ind) = JJ(:);
        %     K(ind) = KK(:);
        %     T(ind) = TT(:);
    
        %     index = index + NDof^2;
        % end

    
    end
end