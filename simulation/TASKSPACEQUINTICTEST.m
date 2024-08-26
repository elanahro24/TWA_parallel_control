clear all
close all

fig1 = figure();
hold on;

qplt(1) = plot(0,0,'linewidth',2.5);
qplt(2) = plot(0,0,'linewidth',2.5);
qplt(3) = plot(0,0,'linewidth',2.5);
ax1 = fig1.Children;
ax1.YLim = [-6, 6];
ax1.XLim = [0, 3000];
legend({'q1' 'q2' 'q3'});


fig3 = figure();
hold on
qplt(4) = plot(0,5.6842,'linewidth',2.5);
qplt(5) = plot(0,4.66442,'linewidth',2.5);
qplt(6) = plot(0,3.584,'linewidth',2.5);
ax3 = fig3.Children;
ax3.YLim = [-6, 6];
ax3.XLim = [0, 3000];
legend({'twa1' 'twa2' 'twa3'});


fig2 = figure();
hold on;
xplt(1) = plot(0,0,'linewidth',2.5);
xplt(2) = plot(0,0,'linewidth',2.5);
ax2 = fig2.Children;
ax2.YLim = [-0.5, 5.5];
ax2.XLim = [0, 3000];

legend({'x' 'y'})


mode = 3;
q_cur = [zeros(3,1);5.6842;4.66442;3.584];
init_twa_homing();
x_des = [5;0;0];
dt = 0.002;
tc = 0;
tf = 5;
q_des = zeros(6,1);
x_cur = zeros(3,1);
t_init = 0;
x_init = zeros(3,1);
robot_moving = 0;

robotmoving = 1;


while robotmoving

[qdes,deltax,tinit,xinit,robotmoving] = taskquintic(mode,q_cur,...
    p_in_m,b_in_w,m_in_w,f_in_w,x_des,...
    tc,tf,q_des,x_cur,t_init,x_init,robot_moving);
q_des = qdes;
q_cur = qdes;   
x_cur = deltax;
t_init = tinit;
x_init = xinit;
robot_moving = robotmoving;
tc = tc + dt;

qplt(1).YData = [qplt(1).YData, q_des(1,1)];
qplt(1).XData = [qplt(1).XData, qplt(1).XData(end)+1];

qplt(2).YData = [qplt(2).YData, q_des(2,1)];
qplt(2).XData = [qplt(2).XData, qplt(2).XData(end)+1];

qplt(3).YData = [qplt(3).YData, q_des(3,1)];
qplt(3).XData = [qplt(3).XData, qplt(3).XData(end)+1];

qplt(4).YData = [qplt(4).YData, q_des(4,1)];
qplt(4).XData = [qplt(4).XData, qplt(4).XData(end)+1];

qplt(5).YData = [qplt(5).YData, q_des(5,1)];
qplt(5).XData = [qplt(5).XData, qplt(5).XData(end)+1];

qplt(6).YData = [qplt(6).YData, q_des(6,1)];
qplt(6).XData = [qplt(6).XData, qplt(6).XData(end)+1];

xplt(1).YData = [xplt(1).YData, x_cur(1,1)];
xplt(1).XData = [xplt(1).XData, xplt(1).XData(end)+1];

xplt(2).YData = [xplt(2).YData, x_cur(2,1)];
xplt(2).XData = [xplt(2).XData, xplt(2).XData(end)+1];


pause(0.001)
end