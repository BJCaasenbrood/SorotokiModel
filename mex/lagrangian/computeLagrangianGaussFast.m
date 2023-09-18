%#codegen
% [M,C,K,R,Dc,G,B,p,Phi,J,dJdt,Vg,Kin]
function [M, C, K, fg] = computeLagrangianGaussFast(x,dx,...          % states
    G,...
    J,...       % evaluated Jacobian matrix
    Jt,...      % evalatured time-Jacobian
    Th,...      % evaluated shape function
    Ba,...      % strain mapping
    Mtt,...     % geometric inertia tensor
    Ktt,...     % geometric stiffness tensor
    Dctt,...    % drag tensor
    Gvec,...    % gravity vector
    W,...       % gauss weights
    S)          % gauss pts)        

% compute total length
NNode  = size(W,2);
NGauss = size(W,1);
nq     = numel(x);

% initialize 
M  = zeros(nq);
C  = zeros(nq);
K  = zeros(nq);
fg = zeros(nq,1);

% construct gravity vector
grav = [0; 0; 0; Gvec];

for jj = 1:(NNode)

    % gauss-quadrature
    for ii = 1:NGauss
        t  = (S(ii+1,jj) - S(1,jj)) / (S(end,jj) - S(1,jj));
        Ji  = t * J(:,:,jj) + (1 - t) * J(:,:,jj+1);

        % compute inertia matrix
        M = M + W(ii,jj) * (Ji.' * Mtt(:,:,jj) * Ji);

        % compute coriolis matrix
        adV  = admap( Ji * dx );
        Ceta = Mtt(:,:,jj) * adV - adV.' * Mtt(:,:,jj);
        CdJt = Mtt(:,:,jj) * Jt(:,:,jj);

        C = C + W(ii,jj) * (Ji.' * ( Ceta * Ji + CdJt));

        % compute gravity vector
        gi = interpolateSE3(G(:,:,jj), G(:,:,jj+1), t);
        AdInv = Admapinv(gi(1:3,1:3),gi(1:3,1));
        fg = fg - W(ii,jj) * Ji.' * (Mtt(:,:,jj) * AdInv * grav);

        % compute stiffness matrix
        dBti = ( Ba * Th(:,:,ii+1,jj) );
        K = K + W(ii,jj) * dBti.' * Ktt(:,:,jj) * dBti;
    end
end

% % recover the kinematics entities
% p    = Z1(1:3,4);
% Phi  = Z1(1:3,1:3);

% B1   = Z1(1:6,5:5+n-1);
% B2   = Z1(1:6,6+n-1:6+2*(n-1));
% J0   = Admapinv(Phi,p)*B1;
% dJ0  = Admapinv(Phi,p)*B2;

% V    = J0*dx; 
% adV  = admap(V);

% % set linear velocity zero -- dJ worldframe 
% V(4:6) = 0;
% adV_ = admap(V);
% J    = Admap(Phi,[0;0;0])*J0;           % world-frame Jacobian
% dJdt = Admap(Phi,[0;0;0])*adV_*J0 + ... % world-frame dJacobian/dt
%        Admap(Phi,[0;0;0])*(-adV*J0 + dJ0);

% % recover the dynamics entities
% M  = Z2(1:n,1:n);           % mass
% C  = Z2(1:n,n+1:2*n);       % coriolis
% K  = Z2(1:n,2*n+1:3*n);     % stiffness
% Dc  = Z2(1:n,3*n+1:4*n);     % gravity vector
% G = Z2(1:n,4*n+1);         % drag

% Vg  = Z1(5,4);
% Kin = Z1(6,4);

% R = Zeta*K;
% B = Z3;
end

% function [dZ1,dZ2,dZ3] = LagrangianODEX(x,dx,Z1,...
%     Theta,xia0,Mscl,Ba,Mtt,Ktt,Dtt,Gvec)

% n     = numel(x);
% m     = size(Mscl,3);
% p_    = Z1(1:3,4);
% Phi_  = Z1(1:3,1:3);
% J_    = Z1(1:6,5:5+n-1);
% Jt_   = Z1(1:6,6+n-1:6+2*(n-1));

% for ii = 1:2
%     Phi_(:,ii) = Phi_(:,ii) ./ norm(Phi_(:,ii));
% end

% Phi_(:,3) = isomSO3(Phi_(:,1)) * Phi_(:,2);

% %build geometric strain
% XI = Ba*Theta*x + xia0;

% Gamma = XI(1:3);
% U     = XI(4:6);

% % build forward kin - position
% dp   = Phi_*U;
% dPhi = Phi_*isomSO3(Gamma);

% A   = Admap(Phi_,p_);
% Ai  = Admapinv(Phi_,p_);

% % build jacobian
% Jg   = Ai*J_;
% Jgt  = Ai*Jt_;
% V    = Jg*dx;
% adV  = admap(V);

% BTh = Ba*Theta;

% dJ  = A*BTh;
% dJt = A*adV*BTh;

% % Precompute commonly used variables
% Mtt_adV = Mtt * adV;
% adVt_Mtt = adV.' * Mtt;
% Jg_transpose = Jg.';

% % Compute dM, dC, and dG
% dM = Jg_transpose * Mtt * Jg;
% dC = Jg_transpose * ((Mtt_adV - adVt_Mtt) * Jg + Mtt * Jgt);
% dG = -Jg_transpose * (Mtt * Ai * [0; 0; 0; Gvec]);
% dD = -Jg_transpose * Dtt * Jg * norm(V(4:6));

% % compute (nonlinear stiffness)
% dK = (((BTh).'*Ktt*(BTh)));

% % compute grav. potential energy
% dKe = 0.5*V.'*Mtt*V;
% dVg = Mtt(4,4)*p_.'*Gvec;

% dZ1                      = zeros(6,6+2*(n-1));
% dZ1(1:3,1:3)             = dPhi;
% dZ1(1:3,4)               = dp;

% dZ1(1:6,5:5+n-1)         = dJ;
% dZ1(1:6,6+n-1:6+2*(n-1)) = dJt;

% dZ1(5,4)                 = dVg;
% dZ1(6,4)                 = dKe;

% dZ2 = zeros(n,4*n+1);
% dZ2(1:n,1:n)             = dM;
% dZ2(1:n,n+1:2*n)         = dC;
% dZ2(1:n,2*n+1:3*n)       = dK;
% dZ2(1:n,3*n+1:4*n)       = dD;
% dZ2(1:n,4*n+1)           = dG;

% dZ3 = zeros(n,m);

% for ii = 1:m
%     di  = [Mscl(:,1:3,ii).';1]; % lifted position vector
%     ddi = [Mscl(:,4:6,ii).';1]; % lifted position vector deriv.
    
%     XiHat      = hat(XI);
%     tangentRaw = XiHat*di + ddi;
%     ti         = tangentRaw(1:3)/(norm(tangentRaw(1:3)) + 1e-6);

%     Fu        = [hat(di(1:3))*ti;ti];
%     dZ3(:,ii) = ((BTh.')*Fu);
% end

% end
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
