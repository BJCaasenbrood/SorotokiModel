function [Y, X] = pccspace(N,M,varargin)
% loop over functional space
X = linspace(0,1,N).';
Y = zeros(N,M);

for ii = 1:M
   Y(:,ii) = pcc(X,ii,M); %chebyshev(X/L,ii-1); % chebyshev
end

% ensure its orthonormal (gram–schmidt)
if isempty(varargin)
    Y = gsogpoly(Y,X);
end
end

function y = pcc(x,n,c)
% n = index
% c = number of cuts
if n > c || n < 1 
    error('Index number cannot be large that number of piece-wise segments') 
end
    
s1 = (x >= (n-1)/c) & (x < (n)/c);
s2 = (x == (n)/c);
s = s1 | s2;

y = double(s);
end

    

