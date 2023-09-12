%#codegen
function Kg = computeGradientGvecFast(x,... % states
    ds,...      % spatial steps
    p0,...      % position zero
    Phi0,...    % phi zero
    xia0,...    % intrinsic strain vector
    Th,...      % evaluated Theta matrix
    Ba,...      % state to strain matrix
    Mtt,...     % geometric inertia
    Gvec)       % gravitional vector  

% compute total length
eps = 1e-5;
dX  = eps * eye(numel(x));

Kg  = zeros(numel(x),numel(x));
[~,Z0] = compute(x,ds,p0,Phi0,xia0,Th,Ba,Mtt,Gvec);

for ii = 1:numel(x)
    [~,Z_] = compute(x + dX(:,ii), ds,p0,Phi0,xia0,Th,Ba,Mtt,Gvec);
    Kg(:,ii) = (Z_ - Z0) / eps;
end

end

function [Z1,Z2] = compute(x,ds,p0,Phi0,xia0,Th,Ba,Mtt,Gvec)
    n = numel(x);
    s = 0;
    
    Z1 = zeros(6,5+n-1);
    Z2 = zeros(n,1);
    
    Z1(1:3,1:3) = Phi0;
    Z1(1:3,4)   = p0;
    
    for ii = 1:(size(Th,3)/2)
        
        % first EL-diff eval
        [K1Z1,K1Z2] = LagrangianODEX(x, Z1,...
            Th(:,:,2*ii-1), xia0(:,1,2*ii-1), ...
            Ba, Mtt(:,:,2*ii-1), Gvec);
        
        % second EL-diff eval
        [K2Z1,K2Z2] = LagrangianODEX(x, Z1 + (2/3)*ds*K1Z1,...
            Th(:,:,2*ii), xia0(:,1,2*ii), ...
            Ba, Mtt(:,:,2*ii), Gvec);
        
        % update integrands
        s  = s  + ds;
        Z1 = Z1 + 0.25*ds*(K1Z1 + 3*K2Z1);
        Z2 = Z2 + 0.25*ds*(K1Z2 + 3*K2Z2);
    end
end

function [dZ1,dZ2] = LagrangianODEX(x,Z1,...
    Theta,xia0,Ba,Mtt,Gvec)

n     = numel(x);
p_    = Z1(1:3,4);
Phi_  = Z1(1:3,1:3);
J_    = Z1(1:6,5:5+n-1);

%build geometric strain
XI = Ba*Theta*x + xia0;

Gamma = XI(1:3);
U     = XI(4:6);

% ensure that Phi is in SO(3)
for ii = 1:2
    Phi_(:,ii) = Phi_(:,ii) ./ norm(Phi_(:,ii));
end
Phi_(:,3) = isomSO3(Phi_(:,1)) * Phi_(:,2);

% build forward kin - position
dp   = Phi_*U;
dPhi = Phi_*isomSO3(Gamma);

A   = Admap(Phi_,p_);
Ai  = Admapinv(Phi_,p_);

% build jacobian
Jg  = Ai*J_;
BTh = Ba*Theta;
dJ  = A*BTh;

Jg_transpose = Jg.';
dG = -Jg_transpose * (Ai * Mtt * [0; 0; 0; Gvec]);

dZ1                    = zeros(6,5+n-1);
dZ2                    = zeros(n,1);
dZ1(1:3,1:3)           = dPhi;
dZ1(1:3,4)             = dp;
dZ1(1:6,5:5+n-1)       = dJ;
dZ2(1:n,1)             = dG;

end
%--------------------------------------------------------------------------
function y = isomSO3(x)
    y = [ 0, -x(3), x(2);
          x(3), 0, -x(1);
         -x(2), x(1), 0];
end
%--------------------------------------------------------------------------
function Y = hat(X)

if numel(X) == 6
    S = isomSO3(X(1:3));
    U = X(4:6);
    
    Y = zeros(4,4);
    Y(1:3,1:3) = S;
    Y(1:3,4)   = U;
    
elseif numel(X) == 3
    Y = isomSO3(X);
end
    
end

%--------------------------------------------------------------------------
function g = admap(x)
    Wh = isomSO3(x(1:3));
    Uh = isomSO3(x(4:6));
    g = [Wh, zeros(3); Uh, Wh];
end

%--------------------------------------------------------------------------
function Ad = Admap(R,p)
    S = isomSO3(p);
    Ad = zeros(6);
    Ad(1:3,1:3) = R;
    Ad(4:6,4:6) = R;
    Ad(4:6,1:3) = S*R;
end
%--------------------------------------------------------------------------
function Ad = Admapinv(R,p)
    Rt = R.';   
    S = isomSO3(p);
    Ad = zeros(6);
    Ad(1:3,1:3) = Rt;
    Ad(4:6,4:6) = Rt;
    Ad(4:6,1:3) = Rt*S.';
end