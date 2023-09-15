classdef fluidicsoptions
    
    properties
        Type;
        isRegulated;
    end
    
    methods
        function obj = fluidicsoptions
            %FLUIDICSOTPIONS Construct an instance of this class
            %   Detailed explanation goes here
            obj.Type         = 'Pressure';
            obj.isRegulated  = true;
        end
    end
end

