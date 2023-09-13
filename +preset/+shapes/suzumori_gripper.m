function [SHAPES, GRIPPER] = suzumori_gripper(varargin)

    p = inputParser;
    addOptional(p,'n',30);
    addOptional(p,'dt',1/120);
    addOptional(p,'contact',1);
    parse(p,varargin{:});

    currentDir = fileparts(mfilename('fullpath'));
    stlPath1 = fullfile(currentDir, 'assets/', 'suzumori_gripper_beam.stl');
    stlPath2 = fullfile(currentDir, 'assets/', 'suzumori_gripper_base.stl');
    
    % try
        obj  = Gmodel(stlPath1,'Texture', matcap_polishedaluminium,'Shading','Face');
        obj2 = Gmodel(stlPath2,'Texture', matcap_metalclean * 0.65,'Shading','Face');
        figure(101); view(30,10);
        obj = obj.bake.render();
        obj2 = obj2.bake.render();

        GRIPPER = {obj; obj2}; 
        clearvars obj obj2

        Y = chebyspace(p.Results.n,2);
        SHAPES = cell(4,1); 

        for ii = 1:4
            phi = ii * (2*pi)/4;
            shp = Shapes(Y,[0,2,2,0,0,0],'Length',85,'Texture',matcap_egg);
            shp = shp.setBase(SE3(rotz(phi)*roty(pi/2),[37 * cos(phi), 37 * sin(phi),10]));
            shp = shp.setRadius([9,9,0.0]);

            if p.Results.contact
                sdf = sSphere(35,[0,0,-60]);
                shp = shp.addContact(sdf);

                obj = Gmodel(sdf);
                obj.render;
                % GRIPPER = vertcat(GRIPPER(:),obj);
            end

            shp.Material = NeoHookean(0.1,0.3);

            shp.Material.params.Zeta = 0.5;
            shp.Material.params.Rho  = 250e-12;
            shp.Material.contact.ContactFriction = 0.35;
            shp.Material.contact.NormalReaction  = 0.05;
            shp.Material.contact.TangentReaction = 0.05;

            shp = shp.rebuild();

            shp.solver.TimeStep = p.Results.dt;
            shp.solver.TimeHorizon = Inf;
            shp.solver.MaxIteration = 5;
            shp.solver.sol.x(1) = -4e-2;

            SHAPES{ii} = showRenderShapes(shp);
        end
    % end
end