classdef fluidicsoptions
    
    properties
        Type;
        isRegulated;
    end
    
    methods
        function obj = fluidicsoptions
            obj.Type         = 'Pressure';
            obj.isRegulated  = true;
        end
    end
end

