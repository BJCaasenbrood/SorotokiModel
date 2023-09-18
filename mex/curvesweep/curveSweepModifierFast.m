function H = curveSweepModifierFast(Node0, List, Curve)

    H = zeros(4,4,length(Node0));

    for ii = 1:length(Node0)
        v = Node0(ii,:);

        vy = v(2);
        vz = v(3);
        % dvx = 
   
        p1 = [0; vy; vz];
        a = List(ii);
        
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

function Z = lerpSE3(X,Y,t)

    dH = Y / X;
    R = dH(1:3,1:3);
    T = dH(1:3,4);

    % get log of rotation matrix
    S = logmapSO3(R);
    th = norm([S(3,2); S(1,3); S(2,1)]);
    if abs(th) < 1e-9
        Vi = eye(3);
    else
        Vi = eye(3) - 0.5 * S + (1/(th^2)) * (1 - (th*sin(th))/(2*(1-cos(th))))*(S*S);
    end
    U  = Vi * T;

    Rt = expmapSO3(t * S);
    tth = t*th;
    
    if abs(tth) < 1e-9
        Vt = eye(3);
    else
        Vt = eye(3) + ((1-cos(tth))/(tth)^2)*(t*S) + ((tth - sin(tth))/((tth)^3)) * (t*S) * (t*S);
    end
    
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


% function T_interp = lerpSE3(T1, T2, t)
%     % Extract rotation matrices and translation vectors from SE3 transformations
%     R1 = T1(1:3, 1:3);
%     p1 = T1(1:3, 4);
% 
%     R2 = T2(1:3, 1:3);
%     p2 = T2(1:3, 4);
% 
%     % [U1, S1, V1] = svd(R1);
%     % [U2, S2, V2] = svd(R2);
% 
%     % % Combine the rotation matrices using the linear combination
%     % R_interp = t * U1 * V1' + (1 - t) * U2 * V2';
%     R_interp = (t * R1 + (1 - t) * R2);
%     % q1 = rot2quat(R1);
%     % q2 = rot2quat(R2);
% 
%     % q_interp = lerp(q1,q2,t);
%     % R_interp = quat2rot(q_interp);
%     p_interp = (1 - t) * p1 + t * p2;
%     T_interp = [R_interp, p_interp; 0, 0, 0, 1];
% end
