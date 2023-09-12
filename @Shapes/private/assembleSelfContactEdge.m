function Shapes = assembleSelfContactEdge(Shapes)

    % build possible edge-contact cases
    dE = round(Shapes.NNode/15);
    Edge0 = nchoosek(1:dE:Shapes.NNode-1,2);
    
    % remove neighbors 10% away
    I = abs(Edge0(:,1) - Edge0(:,2)) > dE; 

    Shapes.system.ContactEdge = Edge0(I,:);
end

