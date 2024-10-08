qcur = zeros(6,1);
epeps = 0.01;%sqrt(3*0.01^2); %10 microns per actuator
kp = 0.5;
dt = 0.002;
velmex_pitch = 1.27;
twave = zeros(3,1);

% physically measured macro leg lengths at initial position
measured_len = [124.79;125.42;125.23];
macro_leg_len = measured_len;
ee_rot = pi/6;
rwave = [cos(ee_rot) -sin(ee_rot) 0;sin(ee_rot) cos(ee_rot) 0;0 0 1];
r_cur = rwave;
% locations of moving platform and base verteces
vertex_locs = [330 90 210]*pi/180;
p_rad = 45.00; %[mm]
p_in_m = p_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% base vertex locations
vertex_locs = [333.03 93.02 213.03]*pi/180;
b_rad = 162.32;% 158.04; %[mm]
b_in_w = b_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% flexure rotation center
f_rad = 80; %[mm]
flexure_locs = [-40 80 200]*pi/180;
f_in_w = f_rad*[cos(flexure_locs);sin(flexure_locs);zeros(1,3)];

% TWA motor position
m_rad = 11.915; %from CAD [mm]
motor_locs = [257.18 17.18 137.18]*pi/180;
m_in_w = m_rad*[cos(motor_locs);sin(motor_locs);zeros(1,3)];

% moving platform starts at the origin with 30 degree rotation
p_in_w = zeros(3,3) + rwave*p_in_m;

qnom = zeros(3,1);
qnom(1,1) = norm(p_in_w(:,1) - b_in_w(:,1));
qnom(2,1) = norm(p_in_w(:,2) - b_in_w(:,2));
qnom(3,1) = norm(p_in_w(:,3) - b_in_w(:,3));
eq = measured_len - qnom;

x_cur = zeros(3,1);
x_des = [5;3;0];
des_ee_rot = pi/3;
ep_p = 100;

loops = 0;
while norm(ep_p) > epeps

[deltaq,x_cur,ep_p] = res_rate_cmd(x_des,des_ee_rot,x_cur,r_cur,...
    dt,p_in_m,b_in_w,f_in_w,m_in_w);

loops = loops + 1;
disp(['Number of loops: ',num2str(loops)]);

end