
clr;
%%

k = 1;
c = 0.1;
m = 0.01;

A = [0, 1; -k/m, -c/m];
B = [0;0];

sys = StateSpace({A,B},[1;-1]);
mdl = Model(sys);

mdl.solver.isLog = 0;

tic;
mdl = mdl.simulate;
toc;

plot(mdl.solver.sol.tout,mdl.solver.sol.yout);