function Shapes = setRadius(Shapes,varargin)
    if numel(varargin) == 1 && numel(varargin{1}) == 1
        Shapes.geometry.TubeRadiusA = varargin{1};
        Shapes.geometry.TubeRadiusB = varargin{1};
    elseif numel(varargin) == 1 && numel(varargin{1}) == 2
       R = varargin{1};
       Shapes.geometry.TubeRadiusA = R(1);
       Shapes.geometry.TubeRadiusB = R(2); 
    elseif numel(varargin) == 1 && numel(varargin{1}) == 3
       R = varargin{1};
       Shapes.geometry.TubeRadiusA = R(1);
       Shapes.geometry.TubeRadiusB = R(2);  
       Shapes.geometry.TubeRamp = R(3);
    elseif numel(varargin) == 1 && numel(varargin{1}) == 4
       R = varargin{1};
       Shapes.geometry.TubeRadiusA = R(1);
       Shapes.geometry.TubeRadiusB = R(2);  
       Shapes.geometry.TubeRamp = R(3);
       Shapes.geometry.TubeRadiusAlpha = R(4);
    end
 
    if Shapes.geometry.TubeRadiusAlpha > 0.5
         Rmean = mean([Shapes.geometry.TubeRadiusA,Shapes.geometry.TubeRadiusB]);
         Shapes.geometry.Sdf = sCircle(Rmean);
     else
         W = Shapes.geometry.TubeRadiusA/2;
         H = Shapes.geometry.TubeRadiusB/2;
         Shapes.geometry.Sdf = sRectangle(-W,W,-H,H);
     end
 
    Shapes = rebuild(Shapes);
 end