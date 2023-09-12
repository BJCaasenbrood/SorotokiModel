% 09-May-2023 09:01:17
% Auto-generated test script

% Initialize the test suite
% Add test cases here
clr;

N = 300;
M = 6;
[Y,X] = pwlspace(N,M,false);

for ii = 1:M
    plot(X,Y(:,ii),'LineW',2); hold on;
end