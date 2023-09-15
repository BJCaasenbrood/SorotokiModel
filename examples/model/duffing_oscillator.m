clf;
amp=0.45;  % control parameter
b=0.5;
alpha=-1.0d0;
beta=1.0d0;
w=2.0;

f = @(x,u,t) [ x(2); -b*x(2)-alpha*x(1)-beta*x(1)^3+amp*sin(w*t)];
H = @(x,u,t) [ 0, 1; -alpha-3*beta*x(1)^2, -b];

sys = StateSpace({f,H},[0.5021; 0.17606]);

mdl = Model(sys);
% mdl.solver.MaxIteration = 2;
mdl.solver.RelTolerance = 1e-9;
mdl.solver.TimeStep    = 0.1;
mdl.solver.TimeHorizon = 50;

tic;
mdl = mdl.simulate;
toc;

hold on;
plot(mdl.solver.sol.yout(:,1),mdl.solver.sol.yout(:,2));

tic;
duffing
toc;

function duffing
%This program in computed by S.Sabarathinam
%%Based on: Nonlinear Dynamics: Integrability, Chaos and Patterns,by M Lakshmanan, S Rajaseekar
% to see the double scroll chaotic attractor in this program
%to change the 'amp' value you can see the period doubling scenario
% figure(1)
% fid = fopen('double.dat','w'); %save the data as dat format in your folder

amp=0.45;  % control parameter
b=0.5;
alpha=-1.0d0;
beta=1.0d0;
w=2.0;
%time step and initial condition
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