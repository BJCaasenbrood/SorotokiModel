function [Fnc, Ftc, Knc, Ktc] = assembleContactShapes(Shapes)

omegaN = Shapes.Material.getContactReaction;
omegaT = Shapes.Material.getContactTangentReaction;
mu     = Shapes.Material.getContactFriction;

% get the minimal radius from the contact spheres
R = Shapes.system.ContactMesh.ContactDistance;

Knc = sparse(Shapes.NJoint,Shapes.NJoint);
Ktc = sparse(Shapes.NJoint,Shapes.NJoint);
Fnc = sparse(Shapes.NJoint,1);
Ftc = sparse(Shapes.NJoint,1);
SDF = Shapes.system.Contact{1};

g = Shapes.system.Backbone;

Y   = backbone(g);
J   = Shapes.system.Jacobian;
Eta = Shapes.system.Velocity;

% eps = Shapes.solver.TimeStep;
eps = 1.0;
d = SDF.eval(Y);
Intersect = find((d(:,end) - R) < eps );

if ~isempty(Intersect)
  I = Intersect;

  % compute normal, tangent, binormal
  [N,t,b] = SDF.gradient(Y(I,:));

  V0 = Eta(4:6,:,I); 
  T  = zeros(3,1,numel(I));
  Vt = zeros(numel(I),3);

  for ii = 1:numel(I)
     Vt(ii,:) = planeprojectVelocity(t(ii,:),b(ii,:),V0(:,:,ii).');
     T(1:3,:,ii) = Vt(ii,:)./(norm(Vt(ii,:) + 1e-6).');
  end

  % contact penalty function
  gn = clamp(d(I,end) - R(I), -Inf, 1e-3);

  Ux = gn .* N(:,1);
  Uy = gn .* N(:,2);
  Uz = gn .* N(:,3);

  % friction penalty function (i.e, expected distance traveled)
  gt = vecnorm(Vt.').' * Shapes.solver.TimeStep;

  % stick-slip boolean vector
  cType = ~abs(omegaT * squeeze(gt)) >= abs(mu * omegaN * gn);
  JvT = pagetranspose(J(4:6,:,I));

  GN = zeros(1,1,numel(I)); CT = GN; GT = GN;
  GN(1,1,:) = gn;
  GT(1,1,:) = gt;
  CT(1,1,:) = cType;

  Fcont = zeros(3,1,numel(I));
  Fcont(1,:,:) = -omegaN * Ux;
  Fcont(2,:,:) = -omegaN * Uy;
  Fcont(3,:,:) = -omegaN * Uz;

  FfricStick = zeros(3,1,numel(I));
  Fstick = pagemtimes(GT,T);
  FfricStick(1,:,:) = -omegaT * Fstick(1,:,:);
  FfricStick(2,:,:) = -omegaT * Fstick(2,:,:);
  FfricStick(3,:,:) = -omegaT * Fstick(3,:,:);

  FfricSlip = zeros(3,1,numel(I));
  Fslip = pagemtimes(sign(GT),pagemtimes(GN,T));
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
        (1 - CTT(ii)) * mu * omegaN * sign(gt(ii)) * tt * (kk).');
  end
end
end


function Y = planeprojectVelocity(n1, n2, v)
    
    % Calculate the normal vector of the plane
    Nv = cross(n1, n2);
    
    if all(Nv == 0)
        error('The plane defined by the input vectors is degenerate.');
    else
        N = Nv / norm(Nv);
    end
    
    % Project the vector onto the plane
    Y = v - dot(v, N) * N;
end
