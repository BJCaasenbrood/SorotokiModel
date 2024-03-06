function [Shapes,Kf,Gf] = reconstruct(Shapes,Fem,varargin)
    
    y = Fem.solver.sol.yout.';
    t = Fem.solver.sol.tout;
    
    set = 1:6;
    I6  = eye(6);
    Xa  = [];
    
    for ii = 1:6
        for jj = 1:Shapes.options.NModal(ii)
            Xa = [Xa,set(ii)];
        end
    end    
    
    Shapes.beamsolver.DofMap = I6(:,Xa);
    Shapes.NJoint = sum(Shapes.options.NModal);
    Shapes.NDim   = 2 * Shapes.NJoint;
    
    Shapes.system.pod.Gamma = [];
    Shapes.system.pod.Kappa = [];

    % compute zero-conf for Shapes;
    Shapes = Shapes.compute(0);
    p0 = backbone(Shapes.system.Backbone);

    if Fem.Dim == 2
        QueryFilter = Fem.Mesh.query([p0(:,1), p0(:,3)]);
    else
        error('Untested feature for 3D fem simulations');
    end
    
    for ii = 1:numel(t)

        % evaluate the system info at y(t)
        Fem.solver.sol.x = y(:,ii);
        Fem = Fem.compute();

        NodeFem = Fem.Mesh.Node + meshfield(Fem, y(:,ii) );
        RotFem  = Fem.system.Rotation;
        StrFem  = Fem.system.Stretch;
     
        [Kf, Gf] = ReconstructField(Shapes, Fem, QueryFilter,...
            NodeFem, RotFem, StrFem);
    
        Shapes.system.pod.Gamma = ...
            [Shapes.system.pod.Gamma, Gf-1];

        Shapes.system.pod.Kappa = ...
            [Shapes.system.pod.Kappa, Kf];
    end
    
    % % SVD decompostion of snapshot reconstructions
    [Ur, Sr, ~] = svd(full(Shapes.system.pod.Kappa * Shapes.system.pod.Kappa.'));
    [Uq, Sq, ~] = svd(full(Shapes.system.pod.Gamma * Shapes.system.pod.Gamma.'));
    
    % Er = (diag(Sr).^0.5);
    % Eq = (diag(Sq).^0.5);
    
    % Shapes.PODEnergy{2} = Eq/sum(Eq);
    % Shapes.PODEnergy{1} = Er/sum(Er);
    Shapes.system.pod.PODQ = [];
    Shapes.system.pod.PODR = [];
    
    for ii = 1:10
        PODr = Ur(:,ii);
        Shapes.system.pod.PODR = [Shapes.system.pod.PODR,PODr];
    end
    
    for ii = 1:10
        PODq = Uq(:,ii);
        Shapes.system.pod.PODQ = [Shapes.system.pod.PODQ, PODq];
    end

    if Shapes.options.isOrthonormal
        Shapes.system.pod.PODR = gsogpoly(Shapes.system.pod.PODR,Shapes.beamsolver.Space);
        Shapes.system.pod.PODQ = gsogpoly(Shapes.system.pod.PODQ,Shapes.beamsolver.Space);
    end
    
    k = 1;
    Shapes.system.pod.POD = [];
    for ii = 1:numel(Shapes.options.NModal)
    for jj = 1:Shapes.options.NModal(ii)
        if ii == 1
            Shapes.system.pod.POD(:,k) = ...
                Shapes.system.pod.PODQ(:,jj);
        else
            Shapes.system.pod.POD(:,k) = ...
                Shapes.system.pod.PODR(:,jj);
        end
        k = k + 1;
    end
    end
        
    % rebuild shape-function
    Shapes.system.pod.Theta = @(x) ShapeFunction(Shapes,x);
    Shapes = Shapes.rebuild(); 
end

function [Kappa, Gamma] = ReconstructField(Shapes,Fem,P,N,R,S)
    
    % P = full(Shapes.Filter);  
    h   = Shapes.beamsolver.SpaceStep;
    lst = 1:Fem.Mesh.NNode;

    % keyboard;
    
    Rot = {};
    Nod = P * N;

    o3 = zeros(1,3);
    Gamma = zeros(Shapes.NNode,1);
    Kappa = zeros(Shapes.NNode,1);
    
    % loop over each node in curve to find geometric strains
    for ii = 1:Shapes.NNode
        
        [RRe, UUe] = deal(0);
        
        for jj = lst(abs(P(ii,:))>0)
            UUe = UUe + P(ii,jj) * S{jj};
            RRe = RRe + P(ii,jj) * R{jj};
        end
        
        [Ur,~,Vr] = svd(RRe);        
        Rot{ii,1} = Ur * Vr.';
        % Tangent(ii,:) = Re(:,1).';
        % Gamma(ii,1)   = trace(UUe)/3;
    end
    
    for ii = 2:Shapes.NNode-1
        Ni  = Nod(ii,:);
        Nii = Nod(ii+1,:);
        Nip = Nod(ii-1,:);
        
        g  = [Rot{ii,1},    [Ni(1);  Ni(2);  0]; o3, 1];
        dg = ([Rot{ii+1,1}, [Nii(1); Nii(2); 0]; o3, 1] ...
            - [Rot{ii-1,1}, [Nip(1); Nip(2); 0]; o3, 1]) ...
            * (1/ 2 * h);
        
        % GSE3(:,:,ii) = g;

        XI = g \ dg;
        
        Kappa(ii,1) = XI(1,2);
        Gamma(ii,1) = XI(1,4);
    end
    
    
    % for ii = 1:Shapes.NNode
    %     if ii == 1
    %         Kappa(ii) = 0;
    %     elseif ii == Shapes.NNode
    %         Kappa(ii) = Kappa(ii-1);
    %     else
    %         t1 = (Tangent(ii,:) + Tangent(ii-1,:)); t1 = t1/norm(t1);
    %         t2 = (Tangent(ii,:) + Tangent(ii+1,:)); t2 = t2/norm(t2);
    %         dir = sign(dot(so3(t2)*t1(:),[0,0,1])); 
    %         angle = real(2*dir*acos(dot(t2,t1)));
    %         
    %         % differential geometric on discretized curve 
    %         % recover the approximate curvature
    %         Kappa(ii,1) = angle/(norm(Nod(ii+1,:) - Nod(ii,:)) + ...
    %             norm(Nod(ii,:) - Nod(ii-1,:)));
    %     end   
    % 
    % end
    
    Kappa(1,1) = Kappa(2,1);
    Gamma(1,1) = Gamma(2,1);
    Kappa(end,1) = Kappa(end-1,1);
    Gamma(end,1) = Gamma(end-1,1);
    
    % if ~isempty(Shapes.FilterRadius)
         Rf = 5;%Shapes.beamsolver.SpaceStep * 5;
    %     if numel(Rf) == 1
    %         Kappa = GaussianFilter(Kappa,round(Rf));
    %         Gamma = GaussianFilter(Gamma,round(Rf));
    %     else 
            %  Kappa = smoothdata(Kappa,'gaussian',round(Rf));
            %  Gamma = smoothdata(Gamma,'gaussian',round(Rf));
    %     end
    % end
    
    % subplot(2,1,1);
    % plot(Gamma); hold on
    % 
    % subplot(2,1,2);
    % plot(Kappa); hold on    
    
end

function P = ShapeFunction(Shapes,X)

    k  = 1;
    X0 = Shapes.beamsolver.Space;
    Pc = cell(Shapes.options.NDof,1); 
    X = zclamp(X/Shapes.Length,0,1);

    % construct shape-matrix 
    for jj = 1:6
        for ii = 1:Shapes.options.NModal(jj)
            
            if jj < 4
                THETA = Shapes.system.pod.PODR(:,ii);   % angular strains
            else
                THETA = Shapes.system.pod.PODQ(:,ii);  % linear strains
            end
            % not sure if interp1 is best/fastest option? 
            % maybe inverse lerp?
            Pc{k,1} = interp1(X0,THETA,X);
            k = k + 1;
        end
    end

    P = blkdiag(Pc{:});

end