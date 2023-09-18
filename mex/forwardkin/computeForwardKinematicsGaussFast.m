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

G(:,:,1) = SE3(Phi0, p0);

for jj = 1:NNode

    % % gauss quad integration for strain
    Y1 = zeros(6,1);

    for ii = 1:NGauss
        dXI = ( Ba * Th(:,:,ii+1,jj) ) * x + xia0(:,:,ii+1,jj);
        Y1  = Y1 + W(ii,jj) * dXI;
    end

    PSI = (Y1);
    
    % compute new G from strain integration
    G(:,:,jj+1) = G(:,:,jj) * expmapSE3( hat( PSI ) );

    % solve for J(s,t)
    % gauss quad integration for strain
    for ii = 1:NGauss
        t  = (S(ii+1,jj) - S(1,jj)) / (S(end,jj) - S(1,jj));
        gi(:,:,ii,jj) = interpolateSE3(G(:,:,jj), G(:,:,jj+1), t);
        dBi = Admap(gi(1:3,1:3,ii,jj), gi(1:3,4,ii,jj)) * Ba * Th(:,:,ii+1,jj) ;
        dB  = dB + W(ii,jj) * dBi;
    end
    
    % Ad = Admap(G(1:3,1:3,jj+1),[0;0;0]) * ...
    Ad = Admapinv( G(1:3,1:3,jj+1), G(1:3,4,jj+1) );
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
        dBt  = dBt + W(ii,jj) * Admap(gi(1:3,1:3,ii,jj), gi(1:3,4,ii,jj)) * admap(deta) * dBti;
    end

    Jt(:,:,jj+1) = Ad * dBt;
end

end

function Y = SE3(R,p)
    Y          = zeros(4);
    Y(4,4)     = 1;
    Y(1:3,1:3) = R;
    Y(1:3,4)   = p;
end

function Z = interpolateSE3(X,Y,t)

    dH = Y / X;
    R = dH(1:3,1:3);
    T = dH(1:3,4);

    % get log of rotation matrix
    S = logmapSO3(R);
    th = norm([S(3,2); S(1,3); S(2,1)]) + 1e-12;
    Vi = eye(3) - 0.5 * S + (1/(th^2)) * (1 - (th*sin(th))/(2*(1-cos(th))))*(S*S);
    U  = Vi * T;

    Rt = expmapSO3(t * S);
    tth = t*th + 1e-12;
    Vt = eye(3) + ((1-cos(tth))/(tth)^2)*(t*S) + ((tth - sin(tth))/((tth)^3)) * (t*S) * (t*S);
    Tt = t * Vt * U;

    Z = ([Rt,Tt;0,0,0,1]) * X;
end


function Y = logmapSO3(X)
    S = X;
    theta = acos(0.5*((S(1,1) + S(2,2) + S(3,3)) - 1));
    alpha = 0.5*theta/ ( sin(theta) + 1e-12);
    Y = alpha*(S - S.'); 
end

function Y = expmapSE3(X)
    S = X(1:3,1:3);
    U = X(1:3,4);

    Y = zeros(4);
    Y(4,4)     = 1;
    Y(1:3,1:3) = expmapSO3(S);
    Y(1:3,4)   = (tmapSO3(S)).' * U;
end

function Y = expmapSO3(X)
    S = X;
    X = [S(3,2); S(1,3); S(2,1)];

    t = norm(X);
    if abs(t) >= 1e-12
        a = sin(t)/t;
        b = (1-cos(t))/(t*t);
        
        Y = eye(3) + a*S + b*S*S;
    else
        Y = eye(3);
    end
end

function Y = tmapSO3(X)
    S = X;
    X = [S(3,2); S(1,3); S(2,1)];

    t = norm(X);
    if abs(t) >= 1e-6
        a = sin(t)/t;
        b = (1-cos(t))/(t*t);
        
        Y = eye(3) + b*S + (1/(t*t))*(1-a)*S*S;
    else
        Y = eye(3);
    end
end

function g = admap(x)
    Wh = skew(x(1:3));
    Uh = skew(x(4:6));
    g = [Wh, zeros(3); Uh, Wh];
end

function Ad = Admap(R,p)
    x1 = p(1); x2 = p(2); x3 = p(3);
    S  = [0, -x3, x2; x3, 0, -x1; -x2, x1, 0];    
    Ad = zeros(6);
    Ad(1:3,1:3) = R;
    Ad(4:6,4:6) = R;
    Ad(4:6,1:3) = S * R;
end

function Ad = Admapinv(R,p)
    Rt = R.';
    x1 = p(1); x2 = p(2); x3 = p(3);
    S  = [0, -x3, x2; x3, 0, -x1; -x2, x1, 0];   
    Ad = zeros(6);
    Ad(1:3,1:3) = Rt;
    Ad(4:6,4:6) = Rt;
    Ad(4:6,1:3) = Rt*S.';
end

function Y = hat(X)
    if numel(X) == 6
        S = skew(X(1:3));
        U = X(4:6);
        
        Y = zeros(4,4);
        Y(1:3,1:3) = S;
        Y(1:3,4)   = U;
        
    elseif numel(X) == 3
        Y = skew(X);
    end
end

function y = skew(x)
    x1 = x(1); x2 = x(2); x3 = x(3);
    y = [0, -x3, x2; 
        x3, 0, -x1; 
        -x2, x1, 0];
end

function Y = commutator(x,y)
    Y = [x(2)*y(3) - x(3)*y(2);
        x(3)*y(1) - x(1)*y(3);
        x(1)*y(2) - x(2)*y(1);
        x(2)*y(6) - x(3)*y(5) + x(5)*y(3) - x(6)*y(2);
        x(3)*y(4) - x(1)*y(6) - x(4)*y(3) + x(6)*y(1);
        x(1)*y(5) - x(2)*y(4) + x(4)*y(2) - x(5)*y(1)];
end
