clear all
close all

fig1 = figure();
hold on;

qplt(1) = plot(0,0);
qplt(2) = plot(0,0);
qplt(3) = plot(0,0);
qplt(4) = plot(0,0);
qplt(5) = plot(0,0);
qplt(6) = plot(0,0);

ax1 = fig1.Children;
ax1.YLim = [-6, 6];
ax1.XLim = [0, 3000];
legend({'q1' 'q2' 'q3' 'q4' 'q5' 'q6'})


fig2 = figure();
hold on;
xplt(1) = plot(0,0);
xplt(2) = plot(0,0);
ax2 = fig2.Children;
ax2.YLim = [0, 7];
ax2.XLim = [0, 3000];

legend({'x' 'y'})


mode = 3;
q_cur = zeros(6,1);
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

for i = 1:6
    qplt(i).YData = [qplt(i).YData, q_des(i,1)];
    qplt(i).XData = 0:1:length(qplt(i).YData)-1;
    if i < 3
        xplt(i).YData = [xplt(i).YData, x_cur(i,1)];
        xplt(i).XData = 0:1:length(xplt(i).YData)-1;
    end
end

pause(0.002)
end