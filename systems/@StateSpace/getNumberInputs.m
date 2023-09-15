function n = getNumberInputs(StateSpace)
    n = numel(StateSpace.solver.sol.x);
end