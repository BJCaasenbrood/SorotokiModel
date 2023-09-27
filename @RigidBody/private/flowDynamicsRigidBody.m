function [dx, RigidBody] = flowDynamicsRigidBody(RigidBody, x, u, t)
    q = x(1:4);
    w = x(8:10);
    v = x(11:13);
    
    ag = RigidBody.system.Gravity(:);
    Mt = RigidBody.Mtt;
    I = Mt(4:6,4:6);
    J = Mt(1:3,1:3);
    
    Uw = u(1:3);
    Uv = u(4:6);
    
    Q = (q)/norm(q + 1e-6); % ensure normalize
    % Q = q;
    R = quat2rot(Q);
    
    % [Ur,~,Vr] = svd(R);
    % R = (Ur*Vr.');
    
    Sw = [0 -w(3) w(2); w(3) 0 -w(1); -w(2) w(1) 0];
    
    A = zeros(4);
    A(1,2:4)   = -w.';
    A(2:4,1)   = +w;
    A(2:4,2:4) = Sw;
    
    ds = v;               % position update
    dv = I\(R*Uv) + ag;   % velocity update
    dq = 0.5*A*Q;         % quaternion update
    dw = J\(Uw-Sw*(J*w)); % angular velocity update
    
    dx = [dq;ds;dw;dv];
    
    % write log
    RigidBody.system.Quaternion    = Q;
    RigidBody.system.Velocity      = [w(:); v(:)];
    RigidBody.system.Configuration = [R,x(5:7);0,0,0,1];
end

function R = quat2rot(q)
    w = q(1); x = q(2); y = q(3); z = q(4);
    Rxx = 1 - 2*(y^2 + z^2); Rxy = 2*(x*y - z*w); Rxz = 2*(x*z + y*w); 
    Ryx = 2*(x*y + z*w); Ryy = 1 - 2*(x^2 + z^2); Ryz = 2*(y*z - x*w );
    Rzx = 2*(x*z - y*w ); Rzy = 2*(y*z + x*w ); Rzz = 1 - 2 *(x^2 + y^2);
    
    R = [Rxx, Rxy, Rxz; Ryx, Ryy, Ryz; Rzx, Rzy, Rzz];
end
    
    