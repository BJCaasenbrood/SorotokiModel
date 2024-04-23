function Shapes = compute(Shapes,varargin)

    noBuild = false;
    for ii = 1:2:numel(varargin)
        if strcmpi(varargin{ii},'nobuild')
            noBuild = varargin{ii+1};
        end
    end
    
    if ~noBuild
        Shapes = assembleGlobalShapes(Shapes);
    else
        Shapes = assembleGlobalQuickShapes(Shapes);
    end
    
    Shapes = assembleBoundaryShapes(Shapes);
    
    Shapes.system.fResidual = Shapes.system.fElastic + Shapes.system.fDamping ... 
        + Shapes.system.fCoriolis - Shapes.system.fInput + Shapes.system.fBody ...
        + Shapes.system.fDrag;
    
end