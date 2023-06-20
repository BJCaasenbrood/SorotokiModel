function [dist,Pc,Qc,Wc] = sdLines(L1,L2)

if (nargin ~= 2)
    error('Not enough input arguments');
end

sL=[size(L1) size(L2)];

if ~isequal(sL(1:2:3),[2 2])
    error('L1,L2 must be 2*n matrix sized');
elseif ~isequal(sL(1:2),sL(3:4))
    error('Matrix L1,L2 dimensions must agree');
end

% Calculation process
P0=L1(1,:);
P1=L1(2,:);
Q0=L2(1,:);
Q1=L2(2,:);
u=P1-P0; v=Q1-Q0; w0=P0-Q0;
a=u*u'; b=u*v'; c=v*v'; d=u*w0'; e=v*w0';
sc=clamp((b*e-c*d)/(a*c-b^2),0,1);
tc=clamp((a*e-b*d)/(a*c-b^2),0,1);

dist = norm(w0+(sc*u-tc*v));

Pc=P0+sc*u;
Qc=Q0+tc*v;
Wc=[sc;tc];

%% plotting section
% 
% par=5;
% [s t]=deal([0 par]);
% difP=P1-P0; difQ=Q1-Q0;
% 
% P=reshape(difP(:)*s, [size(difP) length(s)]);
% Q=reshape(difQ(:)*t, [size(difQ) length(s)]);
% 
% plot3(P0(1)+[P(1,1,1) P(1,1,2)],P0(2)+[P(1,2,1)...
%     P(1,2,2)],P0(3)+[P(1,3,1) P(1,3,2)],'r');
% hold on
% plot3(Q0(1)+[Q(1,1,1) Q(1,1,2)],Q0(2)+[Q(1,2,1)...
%     Q(1,2,2)],Q0(3)+[Q(1,3,1) Q(1,3,2)],'g');
% plot3([Pc(1) Qc(1)],[Pc(2) Qc(2)],[Pc(3) Qc(3)],'g',...
%     'lineWidth',2, 'marker', 'p', 'MarkerFaceColor', 'r',...
%     'markerSize',10,'markerEdgeColor','none');
% 
% fplot(L1,'ko');
% fplot(L2,'ko');
% 
% hold off

end