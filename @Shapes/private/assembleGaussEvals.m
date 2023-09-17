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

end
