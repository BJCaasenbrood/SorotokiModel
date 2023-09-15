function StateSpace = set(StateSpace,varargin)
for ii = 1:2:length(varargin)
    StateSpace.(varargin{ii}) = varargin{ii+1};
end
end