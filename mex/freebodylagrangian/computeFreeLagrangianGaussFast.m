%#codegen
% [M,C,K,R,Dc,G,B,p,Phi,J,dJdt,Vg,Kin]
function [M, C, K, fg, D] = computeFreeLagrangianGaussFast(x, dx,...          % states
    G,...
    J,...       % evaluated Jacobian matrix
    Jt,...      % evalatured time-Jacobian
    Th,...      % evaluated shape function
    Ba,...      % strain mapping
    B0,...      % base velocity mapping
    Mtt,...     % geometric inertia tensor
    Ktt,...     % geometric stiffness tensor
    Dvec,...    % drag parameter vector
    Gvec,...    % gravity vector
    W,...       % gauss weights
    S)          % gauss pts)        

% compute total length
NNode  = size(W,2);
NGauss = size(W,1);
nx     = numel(x);
nq     = size(Ba,2);
L      = max(S(:));

% initialize 
M  = zeros(nx);
C  = zeros(nx);
K  = zeros(nx);
D  = zeros(nx);
fg = zeros(nx,1);

% drag coefficients
RhoD = Dvec(1);
Ct = Dvec(2);
Cp = Dvec(3);
R0 = Dvec(4);
alph = Dvec(5);

% construct gravity vector
grav = [0; 0; 0; Gvec];

for jj = 1:(NNode)

    % gauss-quadrature
    for ii = 1:NGauss
        t  = (S(ii+1,jj) - S(1,jj)) / (S(end,jj) - S(1,jj));
        Ji  = t * J(:,:,jj) + (1 - t) * J(:,:,jj+1);

        gi = interpolateSE3_inline(G(:,:,jj), G(:,:,jj+1), t);
        AdInv = Admapinv_inline(gi(1:3,1:3),gi(1:3,1));

        % compute inertia matrix
        M  = M + W(ii,jj) * (Ji.' * Mtt(:,:,jj) * Ji);

        % compute coriolis matrix
        eta  = Ji * dx;
        adV  = admap_inline(eta);
        Ceta = Mtt(:,:,jj) * adV - adV.' * Mtt(:,:,jj);
        CdJt = Mtt(:,:,jj) * Jt(:,:,jj);

        C  = C + W(ii,jj) * (Ji.' * ( Ceta * Ji + CdJt)) ;

        % compute gravity vector
        fg = fg  - W(ii,jj) * Ji.' * (Mtt(:,:,jj) * AdInv * grav);

        % compute stiffness matrix
        dBti = ( Ba * Th(:,:,ii+1,jj) );
        K(1:nq,1:nq) = K(1:nq,1:nq) + W(ii,jj) * dBti.' * Ktt(:,:,jj) * dBti;

        % compute viscous drag
        Rs = (1 - alph*(S(ii,jj) / L)) * R0;
        At = 2 * pi * Rs;
        Ap = 2 * Rs;

        % deriv of R*[(J dq) .* abs(J * dq)]
        etat  = eta(4:6);
        dV2dq = Ji(4:6,:) .* abs(etat) + etat .* sign(etat) .* Ji(4:6,:);

        D = D + 0.5 * W(ii,jj) * RhoD * Ji(4:6,:).' ...
            * ([Ct*At; Cp*Ap; Cp*Ap] .* dV2dq);
    end
end
end

function Z = interpolateSE3_inline(X,Y,t)

    tol = 1e-9;
    dH = Y / X;
    R = dH(1:3,1:3);
    T = dH(1:3,4);

    % get log of rotation matrix
    S  = logmapSO3_inline(R, tol);
    th = norm([S(3,2); S(1,3); S(2,1)]);

    if abs(th) >= tol
        tth = t*th;        
        Vi  = eye(3) - 0.5 * S + (1/(th^2)) * (1 - (th*sin(th))/(2*(1-cos(th))))*(S*S);
        Vt  = eye(3) + ((1-cos(tth))/(tth)^2)*(t*S) + ((tth - sin(tth))/((tth)^3)) * (t*S) * (t*S);
    else
        Vi = eye(3);
        Vt = Vi;
    end

    U  = Vi * T;
    Rt = expmapSO3_inline(t * S, tol);
    Tt = t * Vt * U;
    Z  = ([Rt,Tt;0,0,0,1]) * X;

end

function Y = logmapSO3_inline(X, tol)
    S = X;
    theta = acos(0.5*(trace(S) - 1));

    if sin(theta) >= tol
        alpha = 0.5*theta/sin(theta);
        Y = alpha*(S - S.'); 
    else
        Y = zeros(3); 
    end
end

function Y = expmapSO3_inline(X, tol)
    S = X;
    X = [S(3,2); S(1,3); S(2,1)];

    t = norm(X);
    if abs(t) >= tol
        a = sin(t)/t;
        b = (1-cos(t))/(t*t);
        
        Y = eye(3) + a*S + b*S*S;
    else
        Y = eye(3);
    end
end

function g = admap_inline(x)
    Wh = skew_inline(x(1:3));
    Uh = skew_inline(x(4:6));
    g = [Wh, zeros(3); Uh, Wh];
end

function Ad = Admap_inline(R,p)
    x1 = p(1); x2 = p(2); x3 = p(3);
    S  = [0, -x3, x2; x3, 0, -x1; -x2, x1, 0];    
    Ad = zeros(6);
    Ad(1:3,1:3) = R;
    Ad(4:6,4:6) = R;
    Ad(4:6,1:3) = S * R;
end

function Ad = Admapinv_inline(R,p)
    Rt = R.';
    x1 = p(1); x2 = p(2); x3 = p(3);
    S  = [0, -x3, x2; x3, 0, -x1; -x2, x1, 0];   
    Ad = zeros(6);
    Ad(1:3,1:3) = Rt;
    Ad(4:6,4:6) = Rt;
    Ad(4:6,1:3) = Rt*S.';
end

function y = skew_inline(x)
    x1 = x(1); x2 = x(2); x3 = x(3);
    y = [0, -x3, x2; x3, 0, -x1; -x2, x1, 0];
end
