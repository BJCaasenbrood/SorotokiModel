function [Y, X] = chebyspace(N,M,varargin)
% loop over functional space
X = linspace(0,1,N).';
Y = zeros(N,M);

for ii = 1:M
   Y(:,ii) = chebyshev(X,ii-1); % chebyshev
end

% ensure its orthonormal (gram–schmidt)
% if isempty(varargin)
%     Y = gsogpoly(Y,X);
% end
end

