
L = 100; % length of robot
N = 120;  % number of discrete points on curve
M = 3;   % number of modes
X = linspace(0,L,N)';
Y = zeros(N,M);

for ii = 1:M
   Y(:,ii) = chebyshev(X/L,ii-1); 
end

Modes = [0,M,0,M,0,0];   % curvature-elongation

shp = Shapes(Y,Modes,'Length',L);

% shp.E    = 5.00;    % Young's modulus in Mpa
% shp.Nu   = 0.49;     % Poisson ratio
% shp.Rho  = 1000e-12; % Density in kg/mm^3
% shp.Zeta = 1;     % Damping coefficient
shp.Material = NeoHookean();
shp = shp.rebuild();

%% eval theta
Fnc = @(x) shp.Theta(x);
s   = sort([shp.Sigma*shp.Length,...
            shp.Sigma*shp.Length+(2/3)*shp.get('ds')]);

[nx,ny] = size(Fnc(0));
Theta   = zeros(nx,ny,numel(s));
Xi0     = zeros(6,1,numel(s));

for ii = 1:numel(s)
    Theta(:,:,ii) = Fnc(s(ii));
    Xi0(:,1,ii) = [0;0;0;1;0;0];
end


%% entries
x  = 0.01*rand(shp.NDim/2,1);
dx = 0.01*rand(shp.NDim/2,1);
%Ba   = shp.Ba;
ds   = shp.get('ds');
p0   = zeros(3,1);
Phi0 = eye(3);
xia0 = Xi0;
Th   = Theta;
Ba   = shp.get('Ba');
Ktt  = shp.get('Ktt');
Mtt  = shp.get('Mtt');
Zeta = shp.Material.Damping;
Gvec = [0;0;9e3];
rArea = ones(240,1);

[M,C,K,R,G,p,Phi,J,Vg,Kin] = computeLagrangianFast(x,dx,... % states
    ds,...      % spatial steps
    p0,...      % position zero
    Phi0,...    % phi zero
    xia0,...    % intrinsic strain vector
    Th,...      % evaluated Theta matrix
    Ba,...      % state to strain matrix
    Ktt,...     % geometric stiffness
    Mtt,...     % geometric inertia
    Zeta,...
    Gvec,...
    rArea);      

%clearvars -except M C K R G p Phi J Vg Kin