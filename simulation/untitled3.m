% locations of moving platform and base verteces
vertex_locs = [330 90 210]*pi/180;
p_rad = 45.00; %[mm]
p_in_m = p_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% base vertex locations
vertex_locs = [333.03 93.02 213.03]*pi/180;
b_rad = 162.32;% 158.04; %[mm]
b_in_w = b_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% TWA motor position
m_rad = 11.915; %from CAD [mm]
motor_locs = [257.18 17.18 137.18]*pi/180;
m_in_w = m_rad*[cos(motor_locs);sin(motor_locs);zeros(1,3)];

% flexure rotation center
f_rad = 80; %[mm]
flexure_locs = [-40 80 200]*pi/180;
f_in_w = f_rad*[cos(flexure_locs);sin(flexure_locs);zeros(1,3)];

x_cur = zeros(3,1);
ee_rot_cur = pi/6;
q_cur = zeros(6,1);

x_des = [10;10;0];
ee_rot_des = ee_rot_cur;

res_rate_param = [1, 0.001, 500, 1, 2, 0.05, 3, 3]';

p_epsilon = res_rate_param(1,1);
p_del = 100;

while p_del > p_epsilon

    [full_jac,xcur,eerotcur]  = getJacobian(p_in_m,b_in_w,m_in_w,f_in_w,x_cur,ee_rot_cur);

    x_cur = xcur;
    ee_rot_cur = eerotcur;

    [qeps,xcur,eerot,qdes,p_del] = redResRate(x_des,q_cur,qdes_cur,ee_rot_des,...
        dt,res_rate_param,full_jac,x_cur,ee_rot_cur,q_des);
    qdes_cur = qdes;
end