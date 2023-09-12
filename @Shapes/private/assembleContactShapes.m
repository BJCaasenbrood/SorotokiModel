function [Fnc, Ftc, Knc, Ktc] = assembleContactShapes(Shapes)

omegaN = Shapes.Material.getContactReaction;
omegaT = Shapes.Material.getContactTangentReaction;
mu     = Shapes.Material.getContactFriction;

if isempty(Shapes.options.ContactDistance)
    R = adaptiveDistanceMeasure(Shapes);
else
    R = Shapes.options.ContactDistance * ones(Shapes.NNode,1);
end

Knc = sparse(Shapes.NJoint,Shapes.NJoint);
Ktc = sparse(Shapes.NJoint,Shapes.NJoint);
Fnc = sparse(Shapes.NJoint,1);
Ftc = sparse(Shapes.NJoint,1);
SDF = Shapes.system.Contact{1};

g = Shapes.system.Backbone;

Y   = backbone(g);
J   = Shapes.system.Jacobian;
Eta = Shapes.system.Velocity;

eps = Shapes.solver.TimeStep * 10;
d   = SDF(Y);
Intersect = find((d(:,end) - R) < eps );

if ~isempty(Intersect)
  I = Intersect;

  n1 = (SDF(Y(I,:)+repmat([eps,0,0],size(Y(I,:),1),1))-d(I,end))/eps;
  n2 = (SDF(Y(I,:)+repmat([0,eps,0],size(Y(I,:),1),1))-d(I,end))/eps;
  n3 = (SDF(Y(I,:)+repmat([0,0,eps],size(Y(I,:),1),1))-d(I,end))/eps;

  % normal vector, tangent vector
  N(:,1) = n1(:,end);
  N(:,2) = n2(:,end);
  N(:,3) = n3(:,end);

  T = zeros(3,1,numel(I));
  T(2,:,:) = n1(:,end);
  T(1,:,:) = -n2(:,end);
  T(3,:,:) = n3(:,end);

  % contact penalty function
  gn = clamp(d(I,end) - R(I), -Inf, Shapes.solver.TimeStep * 10);

  Ux = gn.*n1(:,end);
  Uy = gn.*n2(:,end);
  Uz = gn.*n3(:,end);

  V0 = Eta(4:6,:,I);
  Vn = V0./(vecnorm(squeeze(V0).' + 1e-6).');

  % friction penalty function (i.e, expected distance traveled)
  gt = pagemtimes(pagetranspose(Vn),T) * Shapes.solver.TimeStep;

  % stick-slip boolean vector
  cType = abs(omegaT * squeeze(gt)) >= abs(mu * omegaN * gn);
  JvT = pagetranspose(J(4:6,:,I));

  Fcont = zeros(3,1,numel(I));
  Fcont(1,:,:) = -omegaN * Ux;
  Fcont(2,:,:) = -omegaN * Uy;
  Fcont(3,:,:) = -omegaN * Uz;

  FfricStick = zeros(3,1,numel(I));
  Fstick = pagemtimes(gt,T);
  FfricStick(1,:,:) = -omegaT * Fstick(1,:,:);
  FfricStick(2,:,:) = -omegaT * Fstick(2,:,:);
  FfricStick(3,:,:) = -omegaT * Fstick(3,:,:);

  GN = zeros(1,1,numel(I)); CT = GN;
  GN(1,1,:) = gn;
  CT(1,1,:) = cType;

  FfricSlip = zeros(3,1,numel(I));
  Fslip = pagemtimes(sign(gt),pagemtimes(GN,T));
  FfricSlip(1,:,:) = mu * omegaN * Fslip(1,:,:);
  FfricSlip(2,:,:) = mu * omegaN * Fslip(2,:,:);
  FfricSlip(3,:,:) = mu * omegaN * Fslip(3,:,:);

  Fnc = sum(pagemtimes(JvT, Fcont), 3);
  Ftc = sum(pagemtimes(pagemtimes(JvT, FfricStick),CT),3) + ...
        sum(pagemtimes(pagemtimes(JvT, FfricSlip), 1 - CT),3);

  CTT = squeeze(CT);

  for ii = 1:numel(I)
    kk = JvT(:,:,ii) * N(ii,:).';
    tt = JvT(:,:,ii) * T(:,:,ii);
    Knc = Knc + omegaN * kk * (kk).';
    Ktc = Ktc + (CTT(ii) * omegaT * tt * (tt).' + ...
        (1 - CTT(ii)) * mu * omegaN * sign(gt(1,1,ii)) * tt * (kk).');
  end
end
end

function R = adaptiveDistanceMeasure(Shapes)

TubeRadiusA = Shapes.geometry.TubeRadiusA;
TubeRadiusB = Shapes.geometry.TubeRadiusB;
TubeRamp  = Shapes.geometry.TubeRamp;

ramp = min(max(TubeRamp,1e-6),1-1e-6);
rmax = max(TubeRadiusA,TubeRadiusB);

if numel(ramp) == 1
  R = rmax * linspace(1,1-ramp,Shapes.NNode);
else
  x = linspace(0,1,numel(ramp));
  y = linspace(0,1,Shapes.NNode);
  R = rmax * interp1(x,ramp(:),y);
end

R = R(:);
end