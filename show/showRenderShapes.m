function Shapes = showRenderShapes(Shapes,varargin)

    if nargin < 2
        q = Shapes.solver.sol.x;
    else
        q = varargin{1};
    end
    
    o3 = [0;0;0];
    p0 = Shapes.beamsolver.g0(1:3,4);
    R0 = Shapes.beamsolver.g0(1:3,1:3);
    
    if isempty(Shapes.Gmodel)       

        g = string(Shapes, 0 * q);

        TubeRadiusA = Shapes.geometry.TubeRadiusA;
        TubeRadiusB = Shapes.geometry.TubeRadiusB;
        TubeAlpha   = Shapes.geometry.TubeRadiusAlpha;
        TubeRamp    = Shapes.geometry.TubeRamp;

        Node = backbone(pagemtimes(inv(SE3(R0,p0)), g));
        % Node = interp1(linspace(0,1,Shapes.NNode),Node,linspace(0,1,Shapes.NNode));
        
        [x,y,z] = rtubeplot(Node.',...
            TubeRadiusA,...
            TubeRadiusB,...
            TubeAlpha,...
            16,1e-6,...
            TubeRamp);
        
        fv = surf2patch(x,y,z,'triangles');
        v = fv.vertices;
        f = fv.faces;
        
        Shapes.Gmodel = Gmodel(v,f,'Texture',Shapes.options.Texture,'Alpha',Shapes.options.Alpha);
        Shapes.Gmodel.render();

        [~,~,t] = distance2curve(Node, v);
        Shapes.geometry.IKList = clamp(t * Shapes.NNode, 0, Shapes.NNode);
    end

    g = string(Shapes, q);
    G0 = pagemtimes(inv(SE3(R0,p0)), g);
    %G = CurveSweepModifier(Shapes, Shapes.geometry.IKList, G0, p0);
    G = curveSweepModifierFast_mex(Shapes.Gmodel.Node0, Shapes.geometry.IKList, G0);
    Shapes.Gmodel.Node = backbone(pagemtimes(SE3(R0,p0), G));
    Shapes.Gmodel.update();
end