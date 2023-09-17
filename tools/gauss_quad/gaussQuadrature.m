% https://pomax.github.io/bezierinfo/legendre-gauss.html
function [weight, point] = gaussQuadrature(precision)
if nargin<1, precision = 20; end

assert(2 <= precision && precision <= 66, 'precision must lie between 2 and 64');

weight = gaussWeights(precision);
point  = gaussPoints(precision);
end
