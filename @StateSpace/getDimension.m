function n = getDimension(StateSpace)
    n = numel(StateSpace.solver.sol.x);
end