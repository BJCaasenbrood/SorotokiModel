classdef geometryoptions
    
    properties
        Sdf;
        TubeRadiusA;   
        TubeRadiusB;   
        TubeRadiusAlpha; 
        TubeRamp;        
        IKList;
    end
    
    methods
        function obj = geometryoptions
            %SDFOPTIONS Construct an instance of this class
            %   Detailed explanation goes here
            obj.Sdf = sCircle(5);
            obj.TubeRadiusA     = 5;
            obj.TubeRadiusB     = 5;
            obj.TubeRadiusAlpha = 1e-6;
            obj.TubeRamp        = 0;
            obj.IKList          = [];
        end
    end
end

