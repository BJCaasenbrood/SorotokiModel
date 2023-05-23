clr;

R = 30;
T = readtable('Measurement_60mm_balloon_actuator_01.csv');
V = T.Var2(4:end) * (4/3) * pi * R^3;
P = T.Var3(4:end) * 0.1;

plot(P,V);


% fld = Fluidics();
% fld.system.Control = @Controller;
% %fld.solver.sol.x(1) = 120;
% fld.solver.TimeHorizon = 30;
% fld.solver.TimeStep    = 1/30;

% R = 30; % mm
% V = @(x) (4/3) * pi * R^3 * (1 + x/10);
% fld = fld.setPV(V);
% fld = fld.setRegulator('off');

% while fld.solver.Time < fld.solver.TimeHorizon
%     fld = updateStatesFlow(fld);
% end

% t = fld.solver.sol.tout;
% y = fld.solver.sol.yout;

% plot(t,y(:,1));

% function u = Controller(sys)
%     u(1) = 1e-2 * 10;
% end