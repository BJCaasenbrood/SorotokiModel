function [x,I] = getState(Model,System,varargin)   

% get current states  
if numel(varargin) == 1
    X_ = Model.X;
else
    X_ = Model.Log.x(varargin{2},:);
end

Xi = [0;cumsum(vertcat(Model.NState{:}))];
Xn = Model.NState;

x = [];
I = [];

for ii = System
    if isempty(varargin)
        idLocal = 1:Xn{ii};
    elseif isempty(varargin{1})
        idLocal = 1:Xn{ii};
    else
        idLocal = varargin{1};
        idLocal = idLocal(:);
    end
    
    idGlobal = Xi(ii) + idLocal;
    x = [x; X_(idGlobal)];
    I = [I; idGlobal(:)];
end    
    
end
