function StateList = findState(Model,Id,varargin)
    List = 1:Model.NDim;
    indexList = cumsum(vertcat(Model.NState{:}));
    index = indexList(Id);
    ind1 = index+varargin{1};
    StateList = List(ind1);
end
