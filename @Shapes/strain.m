function xi = strain(Shapes,q)
    
    q  = q(:);
    xi = zeros(Shapes.NNode,6);
    jj = 1;
    for ii = 1:2:Shapes.NNode*2
        xi(jj,:) = (Shapes.beamsolver.DofMap*Shapes.beamsolver.ThetaEval(:,:,ii)*q + ...
            Shapes.beamsolver.Xi0Eval(:,:,ii)).';
        jj = jj + 1;
    end
    
end