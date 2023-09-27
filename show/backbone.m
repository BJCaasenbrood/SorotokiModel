function [p, ux, uy, uz] = backbone(g)
    p  = reshape(g(1:3,4,1:end),3,[]).';
    ux = reshape(g(1:3,1,1:end),3,[]).';
    uy = reshape(g(1:3,2,1:end),3,[]).';
    uz = reshape(g(1:3,3,1:end),3,[]).';
end