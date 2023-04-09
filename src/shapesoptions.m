classdef shapesoptions
    
    properties
        Length;
        Table;
        NModal;
        NDof;

        Dimension;
        Color;
        ColorMap;
        ColorAxis;
        Texture;
        Display;
        LineStyle;
        isAssembled;
        isOrthonormal;

        FilterRadius;
        isVolumetricContact;
        ContactDistance;
        isRampCompensation;
    end
    
    methods
        function obj = shapesoptions
            %SDFOPTIONS Construct an instance of this class
            %   Detailed explanation goes here
            obj.Length              = 100;
            obj.Color               = [32, 129, 191]/255;
            obj.ColorMap            = cmap_turbo;
            obj.Display             = true;
            obj.ColorMap            = cmap_turbo;
            obj.ColorAxis           = [];
            obj.LineStyle           = '-';
            obj.isAssembled         = false;
            obj.Texture             = []; 
            obj.FilterRadius        = 10;
            obj.isVolumetricContact = true;
            obj.ContactDistance     = 1e-3;
            obj.isRampCompensation  = false;
            obj.isOrthonormal       = true;
        end
    end
end

