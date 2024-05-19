function [G, J, Jt] = computeFreeForwardKinematicsGaussFast(x,dx,... % states
    p0,...      % position zero
    Phi0,...    % phi zero
    xia0,...    % evaluated intrinsic strain vector
    Th,...      % evaluated Theta matrix
    Ba,...      % state to strain mapping
    B0,...      % state to base vel mapping
    W,...       % gauss weights
    S)          % gauss pts

nx = numel(x);
nq = size(Ba,2);
nq0 = size(B0,2);
NNode = size(W,2);
NGauss = size(W,1);

dB  = zeros(6,nq);
dBt = zeros(6,nq);
G   = zeros(4,4,NNode+1);
gi  = zeros(4,4,NGauss,NNode+1);
J   = zeros(6,nx,NNode+1);
Jt  = zeros(6,nx,NNode+1);

q  = x(1:nq);
a  = B0 * x((nq+1):end);
da = B0 * dx((nq+1):end);
w  = da(1:3);

phi = a(1:3);
% p0  = a(4:6);

G(:,:,1) = SE3_inline(Phi0, p0);
% G(:,:,1) = expmapSE3_inline(hat(Twist));

t = norm(phi);
if abs(t) < 1e-9
    Jl = eye(3);
else
    a = (1-cos(t)) / (t*t);
    b = (t-sin(t)) / (t*t*t);
    Jl = eye(3) + a * skew_inline(phi) + b*skew_inline(phi)*skew_inline(phi);
end

% RR  = [eye(3)   zeros(3); 
%        zeros(3), Phi0.'];

% dRR = [zeros(3), zeros(3); 
%        zeros(3), -skew_inline(w)*Phi0.'];

RR  = [Phi0.' * Jl,  zeros(3); 
       zeros(3), Phi0.'];

dRR = [-skew_inline(w)*Phi0.', zeros(3); 
       zeros(3), -skew_inline(w)*Phi0.'];

J(:,:,1) = [dB, RR * B0];

for jj = 1:NNode

    % % gauss quad integration for strain
    Y1 = zeros(6,1);

    for ii = 1:NGauss
        dXI = ( Ba * Th(:,:,ii+1,jj) ) * q + xia0(:,:,ii+1,jj);
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
    
    Ad0 = Admap_inline( G(1:3,1:3,1), G(1:3,4,1)  );
    Ad  = Admapinv_inline( G(1:3,1:3,jj+1), G(1:3,4,jj+1) );

    J(:,:,jj+1) = Ad * [dB, Ad0 * RR * B0];

    % solve for Jt(s,t)
    % gauss quad integration for strain
    for ii = 1:NGauss
        t    = (S(ii+1,jj) - S(1,jj)) / (S(end,jj) - S(1,jj));
        Ji   = t * J(:,:,jj) + (1-t) * J(:,:,jj+1);
        Adg  = Admap_inline(gi(1:3,1:3,ii,jj), gi(1:3,4,ii,jj));
        dBti = ( Ba * Th(:,:,ii+1,jj) );
        deta = Ji * dx;
        dBt  = dBt + W(ii,jj) * Adg * admap_inline(deta) * dBti;
    end

    eta = J(:,:,jj+1) * dx;
    ad  = admap_inline(eta);
    ad0 = admap_inline(RR * da);
    
    Jt(:,:,jj+1) = -ad * Ad * [dB, Ad0 * RR * B0] + Ad * [dBt, Ad0 * ad0 * RR * B0] + ...
                    Ad * [dB * 0, Ad0 * dRR * B0];
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
    [S, th]  = logmapSO3_inline(R);
    % th = norm([S(3,2); S(1,3); S(2,1)]);

    if abs(th) >= tol
        tth = t*th;        
        Vi  = eye(3) - 0.5 * S + (1/(th^2)) * (1 - (th*sin(th))/(2*(1-cos(th))))*(S*S);
        Vt  = eye(3) + ((1-cos(tth))/(tth)^2)*(t*S) + ((tth - sin(tth))/((tth)^3)) * (t*S) * (t*S);
    else
        Vi = eye(3);
        Vt = Vi;
    end

    U  = Vi * T;
    Rt = expmapSO3_inline(t * S);
    Tt = t * Vt * U;
    Z  = ([Rt,Tt;0,0,0,1]) * X;

end

% function Y = expmapSE3_inline(X)

%     tol = 1e-9;

%     S = X(1:3,1:3);
%     U = X(1:3,4);

%     Y = zeros(4);
%     Y(4,4)     = 1;
%     Y(1:3,1:3) = expmapSO3_inline(S, tol);
%     Y(1:3,4)   = (tmapSO3_inline(S,Y(1:3,1:3), tol)) * U;
% end

% function Y = logmapSO3_inline(X, tol)
%     S = X;
%     theta = acos(0.5*(trace(S) - 1));

%     if sin(theta) >= tol
%         alpha = 0.5*theta/sin(theta);
%         Y = alpha*(S - S.'); 
%     else
%         Y = zeros(3); 
%     end
% end

% function Y = expmapSO3_inline(X, tol)
%     S = X;
%     X = [S(3,2); S(1,3); S(2,1)];

%     t = norm(X);
%     if abs(t) >= tol
%         a = sin(t)/t;
%         b = (1-cos(t))/(t*t);
        
%         Y = eye(3) + a*S + b*S*S;
%     else
%         Y = eye(3);
%     end
% end

% function Y = tmapSO3_inline(X,R,tol)
%     S = X;
%     X = [S(3,2); S(1,3); S(2,1)];

%     t = norm(X);
%     if abs(t) >= tol
%         I = eye(3);
%         a = 1 / (t*t);
%         Y = a * (I-R)*S + a * X * X.';
%     else
%         Y = eye(3);
%     end
% end

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
