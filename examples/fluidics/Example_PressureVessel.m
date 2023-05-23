clr;

fld = Fluidics();
fld.system.Control = @Controller;
fld.solver.TimeHorizon = 30;
fld.solver.TimeStep  = 1/30;

fld = fld.setRegulator('on','pressure');

while fld.solver.Time < fld.solver.TimeHorizon
    fld = updateStatesFlow(fld);
end

t = fld.solver.sol.tout;
y = fld.solver.sol.yout;

plot(t,y(:,1));

function u = Controller(sys)
    t = sys.solver.Time;
    u(1) = 10 * waveform(t,[0,10;5,-10;10,10]);
end