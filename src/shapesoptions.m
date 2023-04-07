classdef shapesoptions
    
    properties
        Length;
        Table;
        NModal;
        NDof;

        Xi0;

        Dimension;
        Color;
        ColorMap;
        ColorAxis;
        Texture;
        Display;
        LineStyle;
        isAssembled;
    end
    
    methods
        function obj = shapesoptions
            %SDFOPTIONS Construct an instance of this class
            %   Detailed explanation goes here
            obj.Length              = 100;
            obj.Xi0                 = [0,0,0,1,0,0].';
            obj.Color               = [32, 129, 191]/255;
            obj.ColorMap            = cmap_turbo;
            obj.Display             = true;
            obj.ColorMap            = cmap_turbo;
            obj.ColorAxis           = [];
            obj.LineStyle           = '-';
            obj.isAssembled         = false;
            obj.Texture             = []; 
        end
    end
end

