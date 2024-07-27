
% B= 3x3 matrix containing vertices of base platfrom in columns
% P = 3x3 matrix containing vertices of moving platform in columns
% E = 3x3 matrix constaining coordinates of elbows

function []=draw_robot(B,P,qmacro_des)

LineWidth=4;

% center of triangle 
t=sum(P,2)/3; %the center of the equilateral triangular moving platfrom

% base triangle 
h=patch(B(1,:),B(2,:),B(3,:)); % create a red patch with handle h
set(h,'edgecolor','k','linewidth',LineWidth,'FaceColor','w','facealpha',0); % set the edge color for the patch

% moving platform
h=patch(P(1,:),P(2,:),P(3,:)); % create a red patch with handle h
%set(h,'edgecolor',[0, 0.4470, 0.7410],'linewidth',LineWidth,'FaceColor',[0.8500, 0.3250, 0.0980]); % set the edge color for the patch
set(h,'edgecolor',[0, 0.4470, 0.7410],'linewidth',LineWidth,'FaceColor','none'); % set the edge color for the patch

% legs
X=[B(1,:); P(1,:)];
Y=[B(2,:); P(2,:)];
Z=[B(3,:); P(3,:)];

h=line(X,Y,Z);

for i = 1:3
    if qmacro_des(i,1) > 0
        set(h(i),'Color','green','linewidth',LineWidth);
    else
        set(h(i),'Color','red','linewidth',LineWidth);
    end
end

% set(h(1),'Color',[0.6350, 0.0780, 0.1840],'linewidth',LineWidth); 
% set(h(2),'Color',[0.6350, 0.0780, 0.1840],'linewidth',LineWidth); 
% set(h(3),'Color',[0.6350, 0.0780, 0.1840],'linewidth',LineWidth); 

% draw coordinate systems
% base_width=norm(B(:,2)-B(:,1));
% Draw_Coordinate_System(base_width*0.2,RotD([0,0,1],0),[0,0,0]','rgb','w');
platfrom_width=norm(P(:,2)-P(:,1));
theta=atan2( P(2,1)-P(2,3),P(1,1)-P(1,3) )*180/pi; %angle of moving platform 
draw_coordinate_system(platfrom_width*0.1,RotD([0,0,1],theta),t,'rgb','m');

% draw base joint circles
draw_circle(platfrom_width*0.08,B(:,1),20,[0.6350, 0.0780, 0.1840]);
draw_circle(platfrom_width*0.08,B(:,2),20,[0.6350, 0.0780, 0.1840]);
draw_circle(platfrom_width*0.08,B(:,3),20,[0.6350, 0.0780, 0.1840]);

% draw platfrom joint circles
draw_circle(platfrom_width*0.08,P(:,1),20,[0, 0.4470, 0.7410]);
draw_circle(platfrom_width*0.08,P(:,2),20,[0, 0.4470, 0.7410]);
draw_circle(platfrom_width*0.08,P(:,3),20,[0, 0.4470, 0.7410]);
