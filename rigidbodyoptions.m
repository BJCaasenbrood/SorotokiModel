classdef rigidbodyoptions
    
    properties
        Type;
        isRegulated;
    end
    
    methods
        function obj = rigidbodyoptions
            obj.Type         = 'Pressure';
            obj.isRegulated  = true;
        end
    end
end

