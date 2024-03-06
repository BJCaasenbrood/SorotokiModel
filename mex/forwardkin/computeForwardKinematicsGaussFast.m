function [G, J, Jt] = computeForwardKinematicsGaussFast(x,dx,... % states
    p0,...      % position zero
    Phi0,...    % phi zero
    xia0,...    % evaluated intrinsic strain vector
    Th,...      % evaluated Theta matrix
    Ba,...      % state to strain mapping
    W,...       % gauss weights
    S)          % gauss pts

nq  = numel(x);
NNode = size(W,2);
NGauss = size(W,1);

dB  = zeros(6,nq);
dBt = zeros(6,nq);
G   = zeros(4,4,NNode+1);
gi  = zeros(4,4,NGauss,NNode+1);
J   = zeros(6,nq,NNode+1);
Jt  = zeros(6,nq,NNode+1);

G(:,:,1) = SE3_inline(Phi0, p0);

for jj = 1:NNode

    % % gauss quad integration for strain
    Y1 = zeros(6,1);

    for ii = 1:NGauss
        dXI = ( Ba * Th(:,:,ii+1,jj) ) * x + xia0(:,:,ii+1,jj);
        Y1  = Y1 + W(ii,jj) * dXI;
    end

    PSI = (Y1);
    
    % compute new G from strain integration
    G(:,:,jj+1) = G(:,:,jj) * expmapSE3_inline( hat( PSI ) );

    % solve for J(s,t)
    % gauss quad integration for strain
    for ii = 1:NGauss
        t  = (S(ii+1,jj) - S(1,jj)) / (S(end,jj) - S(1,jj));
        gi(:,:,ii,jj) = interpolateSE3_inline(G(:,:,jj), G(:,:,jj+1), t);
        dBi = Admap_inline(gi(1:3,1:3,ii,jj), gi(1:3,4,ii,jj)) * Ba * Th(:,:,ii+1,jj) ;
        dB  = dB + W(ii,jj) * dBi;
    end
    
    % Ad = Admap(G(1:3,1:3,jj+1),[0;0;0]) * ...
    Ad = Admapinv_inline( G(1:3,1:3,jj+1), G(1:3,4,jj+1) );
    J(:,:,jj+1) = Ad * dB;

    % solve for Jt(s,t)
    % gauss quad integration for strain
    for ii = 1:NGauss
        t  = (S(ii+1,jj) - S(1,jj)) / (S(end,jj) - S(1,jj));
        % gi = interpolateSE3(G(:,:,jj), G(:,:,jj+1), t);
        % gi  = t * G(:,:,jj) + (1-t) * G(:,:,jj+1);
        Ji  = t * J(:,:,jj) + (1-t) * J(:,:,jj+1);
        dBti = ( Ba * Th(:,:,ii+1,jj) );
        deta = Ji * dx;
        dBt  = dBt + W(ii,jj) * Admap_inline(gi(1:3,1:3,ii,jj), gi(1:3,4,ii,jj)) * admap_inline(deta) * dBti;
    end

    Jt(:,:,jj+1) = Ad * dBt;
end

end

function Y = SE3_inline(R,p)
    Y          = zeros(4);
    Y(4,4)     = 1;
    Y(1:3,1:3) = R;
    Y(1:3,4)   = p;
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

function Y = expmapSE3_inline(X)

    tol = 1e-9;

    S = X(1:3,1:3);
    U = X(1:3,4);

    Y = zeros(4);
    Y(4,4)     = 1;
    Y(1:3,1:3) = expmapSO3_inline(S, tol);
    Y(1:3,4)   = (tmapSO3_line(S, tol)) * U;
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

function Y = tmapSO3_line(X, tol)
    S = X;
    X = [S(3,2); S(1,3); S(2,1)];

    t = norm(X);
    if abs(t) >= tol
        a = sin(t)/t;
        b = (1-cos(t))/(t*t);
        Y = eye(3) + b*S + (1/(t*t))*(1-a)*S*S;
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
    Ad(4:6,1:3) = Rt * S.';
end

function Y = hat_inline(X)
    if numel(X) == 6
        S = skew_inline(X(1:3));
        U = X(4:6);
        
        Y = zeros(4,4);
        Y(1:3,1:3) = S;
        Y(1:3,4)   = U;
        
    elseif numel(X) == 3
        Y = skew_inline(X);
    end
end

function y = skew_inline(x)
    x1 = x(1); x2 = x(2); x3 = x(3);
    y = [0, -x3, x2; 
        x3, 0, -x1; 
        -x2, x1, 0];
end

function Y = commutator_inline(x,y)
    Y = [x(2)*y(3) - x(3)*y(2);
        x(3)*y(1) - x(1)*y(3);
        x(1)*y(2) - x(2)*y(1);
        x(2)*y(6) - x(3)*y(5) + x(5)*y(3) - x(6)*y(2);
        x(3)*y(4) - x(1)*y(6) - x(4)*y(3) + x(6)*y(1);
        x(1)*y(5) - x(2)*y(4) + x(4)*y(2) - x(5)*y(1)];
end
