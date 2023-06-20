function Shapes = assembleSelfContactEdge(Shapes)

    % build possible edge-contact cases
    Edge0 = nchoosek(1:Shapes.NNode-1,2);
    
    % remove neighbors 10% away
    radiusE = round(Shapes.NNode/10);
    I = abs(Edge0(:,1) - Edge0(:,2)) > radiusE; 

    Shapes.system.ContactEdge = Edge0(I,:);
end

