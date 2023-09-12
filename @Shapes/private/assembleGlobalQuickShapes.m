function Shapes = assembleGlobalQuickShapes(Shapes)

Q  = Shapes.solver.sol.x;
dQ = Shapes.solver.sol.dx;

Shapes.system.fElastic   = Shapes.system.Tangent * Q;
Shapes.system.fDamping   = Shapes.system.Damping * dQ;
Shapes.system.fCoriolis  = Shapes.system.Coriolis  * dQ;

end