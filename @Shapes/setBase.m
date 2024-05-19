function Shapes = setBase(Shapes,varargin)
% setBase - Set the base configuration of Shapes
%
%   Shapes = setBase(Shapes,varargin) sets the base configuration of Shapes
%   based on the input arguments.
%
% Example:
%       Shapes = setBase(Shapes, roty(pi/2));
%       Shapes = setBase(Shapes, [0 0 0]);
%       Shapes = setBase(Shapes, SE3(roty(pi/2),[0 0 0]) );
%       Shapes = setBase(Shapes, '+x');
%       Shapes = setBase(Shapes, '+y');
%       Shapes = setBase(Shapes, '+z');

    if numel(varargin{1}) == 9 || numel(varargin{1}) == 3
        Shapes.beamsolver.g0 = SE3(varargin{1});
        Shapes.solver.sol.g0 = SE3(varargin{1});
    elseif isa(varargin{1},'char')
        Shapes.beamsolver.g0 = dir2SE3(varargin{1});
        Shapes.solver.sol.g0 = dir2SE3(varargin{1});
    else
        Shapes.beamsolver.g0 = varargin{1};
        Shapes.solver.sol.g0 = varargin{1};
    end     
end

% Convert direction to SE3
function G = dir2SE3(dir)
    switch dir
        case {'+x', 'right', 'x'}
            G = SE3(roty(+1e-6));
        case {'+y', 'front', 'y'}
            G = SE3(rotz(pi/2+ 1e-6));
        case {'+z', 'up', 'z'}
            G = SE3(roty(-pi/2+ 1e-6));
        case {'-x', 'left'}
            G = SE3(roty(pi+ 1e-6));
        case {'-y', 'back'}
            G = SE3(rotz(-pi/2+ 1e-6));
        case {'-z', 'down'}
            G = SE3(roty(pi/2 + 1e-6));            
        otherwise
            error('Invalid direction');
    end
end