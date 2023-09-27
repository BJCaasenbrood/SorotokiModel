function RigidBody = render(RigidBody)

    G = RigidBody.system.Configuration;

    if ~isempty(RigidBody.Gmodel)
        Node0 = RigidBody.Gmodel.Node0;
        RigidBody.Gmodel.Node = (G(1:3,1:3) * (Node0.') + G(1:3,4)).';

        RigidBody.Gmodel.update();
    end

end