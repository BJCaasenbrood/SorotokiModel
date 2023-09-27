function Shapes = addChild(Shapes, obj, S)
    assert(isa(obj, 'Shapes') || isa(obj, 'Gmodel'), 'added child must be a Gmodel or Shapes object');

    S = clamp(S,0,1);
    n = length(Shapes.childern);

    Shapes.childern{n+1,1} = obj;
    Shapes.childern{n+1,2} = S;
end