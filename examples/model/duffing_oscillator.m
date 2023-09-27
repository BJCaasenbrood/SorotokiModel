clr;
% parameters
[amp, b, alpha, beta, w] = deal(0.45, 0.5, -1, 1, 2);

% flow and hessian function
f = @(x,u,t) [ x(2); -b*x(2)-alpha*x(1)-beta*x(1)^3+amp*sin(w*t)];
H = @(x,u,t) [ 0, 1; -alpha-3*beta*x(1)^2, -b];

% build nonlinear statespace model \lambda
sys = StateSpace({f,H},[0.5021; 0.17606]);
mdl = Model(sys);

mdl.set('MaxIteration',2,...
        'RelTolerance',1e-9,...
        'TimeStep',0.1,...
        'TimeHorizon',50);

tic; mdl = mdl.simulate; toc;

hold on;
plot(mdl.solver.sol.yout(:,1),mdl.solver.sol.yout(:,2));

tic;
duffing
toc;

function duffing
%This program in computed by S.Sabarathinam
[amp, b, alpha, beta, w] = deal(0.45, 0.5, -1, 1, 2);

tspan = 0:0.1:50;
x10 = 0.5021; x20 = 0.17606;
y0 = [x10; x20];
op=odeset('abstol',1e-9,'reltol',1e-9);
[t,y] = ode23t(@(t,x) f(t,x,b,alpha,beta,amp,w),tspan,y0,op);
x1=y(:,1); x2=y(:,2);
plot(x1,x2);  %plot the variable x and y

    function dy = f(t,y,b,alpha,beta,amp,w)
        x1 = y(1);    x2 = y(2);
        dx1=x2;
        dx2=-b*x2-alpha*x1-beta*x1^3+amp*sin(w*t);
        dy = [dx1; dx2];
    end
end