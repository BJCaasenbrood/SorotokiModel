function [Jn, Jtn, Etan] = computeFrameChangeFast(dx,...
    G,...       % evaluated backbone curve
    J,...       % evaluated Jacobian matrix
    Jt)         % evalatured time-Jacobian)

    Jn   = zeros(size(J));
    Jtn  = zeros(size(J));
    Etan = zeros(6,1,size(J,3));

    o3  = [0;0;0];
    NNode = size(J,3);

    for ii = 1:NNode

        % get rotation matrix
        Ad = Admap(G(1:3,1:3,ii), o3);

        % reorient Jacobian 
        J0 = Ad * J(:,:,ii);
        Jn(:,:,ii) = J0;

        % compute velocity twist
        V0 = J0 * dx;
        Etan(:,:,ii) = V0;

        adV = admap(V0); 
        V0(4:6) = 0;        % assume fixed frame
        adV_ = admap(V0);   % assume fixed frame
        dJdt = Ad*adV_*J0 + ... % world-frame dJacobian/dt
               Ad*(-adV*J0 + Jt(:,:,ii));

        Jtn(:,:,ii) = dJdt;
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

function y = skew(x)
    x1 = x(1); x2 = x(2); x3 = x(3);
    y = [0, -x3, x2; 
        x3, 0, -x1; 
        -x2, x1, 0];
end
