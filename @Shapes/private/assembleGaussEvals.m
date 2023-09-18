function Shapes = assembleGaussEvals(Shapes)


Pl   = Shapes.beamsolver.evalLocal.points;

[nx,ny] = size(Shapes.system.pod.Theta(0));
[nu,nw] = size(Pl);

Shapes.beamsolver.evalLocal.Theta = zeros(nx,ny,nu,nw);
Shapes.beamsolver.evalLocal.Xi0   = zeros(6,1,nu,nw);

for ii = 1:nu
    for jj = 1:nw
        Shapes.beamsolver.evalLocal.Theta(:,:,ii,jj) = ...
            Shapes.system.pod.Theta(Pl(ii,jj));
        Shapes.beamsolver.evalLocal.Xi0(:,:,ii,jj) = ...
             Shapes.beamsolver.Xi0(Pl(ii,jj));          
    end
end

for ii = 1:nw
    if Shapes.options.isRampCompensation
        TubeRamp = 0.8;
        alpha = lerp(1,1-TubeRamp,ii/numel(s));
        Shapes.beamsolver.evalLocal.KttEval(:,:,ii) = (alpha)^2 * Shapes.beamsolver.Ktt;
        Shapes.beamsolver.evalLocal.MttEval(:,:,ii) = (alpha)^2 * Shapes.beamsolver.Mtt;
        Shapes.beamsolver.evalLocal.DttEval(:,:,ii) = (alpha)^2 * Shapes.beamsolver.Dtt;
    else
        Shapes.beamsolver.evalLocal.KttEval(:,:,ii) = Shapes.beamsolver.Ktt;
        Shapes.beamsolver.evalLocal.MttEval(:,:,ii) = Shapes.beamsolver.Mtt;
        Shapes.beamsolver.evalLocal.DttEval(:,:,ii) = Shapes.beamsolver.Dtt;
    end   
end

end
