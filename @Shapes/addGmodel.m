function Shapes = addGmodel(Shapes,obj)

    % assign gmodel to shape class
    Shapes.Gmodel = obj;
    obj = obj.render; % render Gmodel

    % get initial rotation and pos
    p0 = Shapes.beamsolver.g0(1:3,4);
    R0 = Shapes.beamsolver.g0(1:3,1:3);

    % compute zero-strain configuration
    g = string(Shapes, zeros(Shapes.NJoint,1) );

    % transform to conf along x-axis
    Node = backbone(pagemtimes(inv(SE3(R0,p0)), g));

    % get mapping t \in [0,1] to assign mesh nodes to backbone
    [~,~,t] = distance2curve(Node, obj.Node);
    Shapes.geometry.Node0  = Node;
    Shapes.geometry.IKList = clamp(t * Shapes.NNode, 0, Shapes.NNode);
end