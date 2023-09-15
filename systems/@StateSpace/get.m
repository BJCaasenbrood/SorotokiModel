function varargout = get(StateSpace,varargin)
if nargin > 1
    varargout{nargin-1,1} = [];
    for ii = 1:length(varargin)
        varargout{ii,1} = StateSpace.(varargin{ii});
    end
else
    varargout = StateSpace.(varargin);
end
end