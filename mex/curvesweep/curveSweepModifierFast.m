function H = curveSweepModifierFast(Node0, List, Curve)

    H = zeros(4,4,length(Node0));

    for ii = 1:length(Node0)
        v = Node0(ii,:);

        a = List(ii);
        vy = v(2);
        vz = v(3);

        p1 = [0; vy; vz];
        
        if floor(a) == 0
            low = SE3(eye(3), [0;0;0]);
        else
            low = Curve(1:4,1:4,floor(a));
        end

        if ceil(a) == 0
            upp = SE3(eye(3), [0;0;0]);
        else
            upp = Curve(1:4,1:4,ceil(a));
        end

        G = lerpSE3(low, upp, a - floor(a));

        p0 = G(1:3,4);
        R = G(1:3,1:3);
    
        H0 = [R,p0;0,0,0,1];
        H1 = [eye(3),p1;0,0,0,1];
        
        H(:,:,ii) = H0*H1;
    end
end

function T_interp = lerpSE3(T1, T2, t)
    % Extract rotation matrices and translation vectors from SE3 transformations
    R1 = T1(1:3, 1:3);
    p1 = T1(1:3, 4);
    
    R2 = T2(1:3, 1:3);
    p2 = T2(1:3, 4);

    % [U1, S1, V1] = svd(R1);
    % [U2, S2, V2] = svd(R2);

    % % Combine the rotation matrices using the linear combination
    % R_interp = t * U1 * V1' + (1 - t) * U2 * V2';
    R_interp = (t * R1 + (1 - t) * R2);
    % q1 = rot2quat(R1);
    % q2 = rot2quat(R2);
    
    % q_interp = lerp(q1,q2,t);
    % R_interp = quat2rot(q_interp);
    p_interp = (1 - t) * p1 + t * p2;
    T_interp = [R_interp, p_interp; 0, 0, 0, 1];
end

function R = quat2rot(q)
    w = q(1); x = q(2); y = q(3); z = q(4);
    Rxx = 1 - 2*(y^2 + z^2); Rxy = 2*(x*y - z*w); Rxz = 2*(x*z + y*w); 
    Ryx = 2*(x*y + z*w); Ryy = 1 - 2*(x^2 + z^2); Ryz = 2*(y*z - x*w );
    Rzx = 2*(x*z - y*w ); Rzy = 2*(y*z + x*w ); Rzz = 1 - 2 *(x^2 + y^2);
    
    R = [Rxx, Rxy, Rxz; Ryx, Ryy, Ryz; Rzx, Rzy, Rzz];
end
    
function q = rot2quat(R)

    R = squeeze(R);
    T = 1.0 + R(1,1) + R(2,2) + R(3,3);
    
    if T > eps
        
        S  = 0.5 / sqrt(T);
        qw = 0.25 / S;
        qx = (R(3,2) - R(2,3)) * S;
        qy = (R(1,3) - R(3,1)) * S;
        qz = (R(2,1) - R(1,2)) * S;
    elseif R(1,1) > R(2,2) && R(1,1) > R(3,3)
        S = sqrt( 1.0 + R(1,1) - R(2,2) - R(3,3) ) * 2;
        qx = 0.25 * S;
        qy = (R(1,2) + R(2,1)) / S;
        qz = (R(1,3) + R(3,1)) / S;
        qw = (R(2,3) - R(3,2)) / S;
    elseif R(2,2) > R(3,3)
        S = sqrt( 1.0 + R(2,2) - R(1,1) - R(3,3) ) * 2;
        qx = (R(1,2) + R(2,1) ) / S;
        qy = 0.25 * S;
        qz = (R(2,3) + R(3,2) ) / S;
        qw = (R(1,3) - R(3,1) ) / S;
    else
        S = sqrt( 1.0 + R(3,3) - R(1,1) - R(2,2) ) * 2;
        qx = (R(1,3) + R(3,1)) / S;
        qy = (R(2,3) + R(3,2)) / S;
        qz = 0.25 * S;
        qw = (R(1,2) - R(2,1)) / S;
    end
    
    q = zeros(4,1);
    q(1) = qw;
    q(2) = qx;
    q(3) = qy;
    q(4) = qz;
end