function Shapes = show(Shapes,varargin)

    q = Shapes.solver.sol.x;

    if nargin >= 2
        q = varargin{1};
    end
    
    p0 = Shapes.beamsolver.g0(1:3,4);
    R0 = Shapes.beamsolver.g0(1:3,1:3);
    
    if isempty(Shapes.Gmodel)       

        g = string(Shapes, 0 * q);

        TubeRadiusA = Shapes.geometry.TubeRadiusA;
        TubeRadiusB = Shapes.geometry.TubeRadiusB;
        TubeAlpha = Shapes.geometry.TubeRadiusAlpha;
        TubeRamp = Shapes.geometry.TubeRamp;

        Node_ = backbone(pagemtimes(inv(SE3(R0,p0)), g));
        Node  = interp1(linspace(0,1,Shapes.NNode), Node_, ...
                linspace(0,1,Shapes.options.Quality));

        Shapes.geometry.Node0 = Node;
        
        [x,y,z] = rtubeplot(Node.', TubeRadiusA,...
            TubeRadiusB, TubeAlpha, 16, 1e-6, TubeRamp);    
        
        fv = surf2patch(x,y,z,'triangles');
        v = fv.vertices;
        f = fv.faces;
        
        Shapes.Gmodel = Gmodel(v,f,'Texture',Shapes.options.Texture,...
            'Alpha',Shapes.options.Alpha);
        Shapes.Gmodel.render();

        [~,~,t] = distance2curve(Node_, v);
        Shapes.geometry.IKList = clamp(t * Shapes.NNode, 0, Shapes.NNode);
    end

    g  = string(Shapes, q);
    G0 = pagemtimes(inv(SE3(R0,p0)), g);

    if ~isempty(Shapes.childern)
        for ii = 1:size(Shapes.childern,1)
            obj = Shapes.childern{ii,1};
            id = clamp(round(Shapes.childern{ii,2})*Shapes.NNode, 1,Shapes.NNode);

            if isa(obj,'Shapes')
                g0 = obj.beamsolver.g0;
                obj.beamsolver.g0 = g(:,:,id) * g0;
                obj = obj.show();
                obj.beamsolver.g0 = g0;
            elseif isa(obj,'Gmodel')
                Node0 = obj.Node0;
                obj.Node = (g(1:3,1:3,id)*Node0.' + g(1:3,4,id)).';
                obj = obj.update();
            end

            Shapes.childern{ii,1} = obj;
        end    
    end

    G = curveSweepModifierFast_mex(Shapes.Gmodel.Node0, ...
        Shapes.geometry.Node0,Shapes.geometry.IKList,G0);
    
    Shapes.Gmodel.Node = backbone(pagemtimes(SE3(R0,p0), G));
    % Shapes.Gmodel.updateNode();
    Shapes.Gmodel.update();
end