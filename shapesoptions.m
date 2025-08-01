classdef shapesoptions
    
    properties
        Length;
        Table;
        NModal;
        NDof;
        BaseTable;
        NBase;
        NBaseDof;

        Dimension;
        Color;
        ColorMap;
        ColorAxis;
        Texture;
        Alpha;
        Display;
        LineStyle;
        isAssembled;
        isOrthonormal;
        isSelfContact;
        loadingFactor;

        FilterRadius;
        isVolumetricContact;
        ContactDistance;
        isRampCompensation;
        Quality;
    end
    
    methods
        function obj = shapesoptions
            %SDFOPTIONS Construct an instance of this class
            %   Detailed explanation goes here
            obj.Length              = 100;
            obj.Color               = [32, 129, 191]/255;
            obj.ColorMap            = cmap_turbo;
            obj.Display             = true;
            obj.Texture             = matcap_bluebase;
            obj.Alpha               = 1.0;
            obj.ColorAxis           = [];
            obj.LineStyle           = '-';
            obj.isAssembled         = false;
            obj.Texture             = []; 
            obj.loadingFactor       = []; 
            obj.FilterRadius        = 10;
            obj.isVolumetricContact = false;
            obj.ContactDistance     = [];
            obj.isRampCompensation  = true;
            obj.isOrthonormal       = true;
            obj.isSelfContact       = false;
            obj.Quality             = 60;
            obj.Display             = @(x) x.show();
        end
    end
end

