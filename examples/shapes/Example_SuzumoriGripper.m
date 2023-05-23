clr;
sdf  = sCylinder(0,0,0,30,28).translate([0,0,-65]);
obj  = Gmodel('Suzumori_Beam.stl','Texture',matcap_polishedaluminium,'Shading','Face');
obj2 = Gmodel('Suzumori_Holder_Grippers.stl','Texture',matcap_metalclean * 0.65,'Shading','Face');
figure(101); view(30,10);
obj = obj.bake.render();
obj2 = obj2.bake.render();

gripper = {obj;obj2}; 
clearvars obj obj2

Y = chebyspace(50,2);

for ii = 1:4
    phi = ii * (2*pi)/4;
    shp = Shapes(Y,[0,2,2,0,0,0],'Length',85,'Texture',matcap_egg);
    shp = shp.setBase(SE3(rotz(phi)*roty(pi/2),[37 * cos(phi), 37 * sin(phi),10]));
    shp = shp.setRadius([9,9,0.0]);
    shp = shp.addContact(sdf);
    shp.system.Controller = @(x) Controller(x);
    shp.solver.sol.x = [-1e-2;0;0;0];
    shp.solver.TimeStep = 1/30;
    shp.solver.TimeHorizon = 5;
    shp.Material = NeoHookean(0.01,0.3,'Zeta',0.5,'NormalReaction',0.3);
    SHP{ii} = showRenderShapes(shp);
end

while SHP{ii}.solver.Time < SHP{ii}.solver.TimeHorizon
   
    for ii = 1:4
        SHP{ii} = updateDynamicStepShapes(SHP{ii});
        SHP{ii} = showRenderShapes(SHP{ii});
    end

    background();
    view(30,10);
    axis([-80,80,-80,80,-80,90]);
end


function tau = Controller(shp)
    t = shp.solver.Time;
    W = 3*pi;
    y1 = -80 * clamp(sin(-W*t),-1,0);
    y2 = -80 * clamp(sin(-W*t-pi/2),-2,1);
    tau = [y1; 0; y2; 0];
end
