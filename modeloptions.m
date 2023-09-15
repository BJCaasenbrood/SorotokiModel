classdef modeloptions
    
    properties
        Color;
        ColorMap;
        ColorAxis;
        Display;
        LineStyle;
        isNonlinear;
        isAssembled;
    end
    
    methods
        function obj = modeloptions
            %SDFOPTIONS Construct an instance of this class
            %   Detailed explanation goes here
            obj.Color           = [0.8329 0.8329 0.8329];
            obj.ColorMap        = cmap_turbo;
            obj.Display         = [];
            obj.ColorAxis       = [];
            obj.LineStyle       = '-';
            obj.isAssembled     = false;
        end
    end
end

