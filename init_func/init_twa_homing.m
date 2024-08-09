% for initialization resolved rates.
% physically measured macro leg lengths at initial position
meas_macro_len = [124.79;125.42;125.23];

ee_rot = pi/6;
rm2w_homing = [cos(ee_rot) -sin(ee_rot) 0;sin(ee_rot) cos(ee_rot) 0;0 0 1];

% locations of moving platform verteces
platform_vertex_locs = [330 90 210]*pi/180;
p_rad = 45.00; %[mm]
p_in_m = p_rad*[cos(platform_vertex_locs);sin(platform_vertex_locs);zeros(1,3)];

% base vertex locations 
% angular offset for base verteces is different than moving platform due to
% a miscommunication during the designing process
base_vertex_locations = [333.0315 93.0315 213.0315]*pi/180;
b_rad = 162.3142;% 158.04; %[mm]
b_in_w = b_rad*[cos(base_vertex_locations);sin(base_vertex_locations);zeros(1,3)];

% flexure rotation center
f_rad = 80; %[mm]
flexure_locs = [-45 75 196]*pi/180;
f_in_w = f_rad*[cos(flexure_locs);sin(flexure_locs);zeros(1,3)];

% TWA motor position
m_rad = 238.2998; %from CAD [mm] (old number, not sure where it came from 11.915)
motor_locs = [257.177 17.177 137.177]*pi/180;
m_in_w = m_rad*[cos(motor_locs);sin(motor_locs);zeros(1,3)];

% TWA attachment point position 
t_rad = 169.6918;
t_locs = [327.0745 87.0745 207.0745]*pi/180;
t_in_w = t_rad*[cos(t_locs);sin(t_locs);zeros(1,3)];

% angle between base vertex and twa attachment point, in flexure frame
twa_gamma = 11.6087 * pi/180;

% moving platform starts at the origin with 30 degree rotation
p_in_w = zeros(3,3) + rm2w_homing*p_in_m;

qmacro_nom = zeros(3,1);
qmacro_nom(1,1) = norm(p_in_w(:,1) - b_in_w(:,1));  
qmacro_nom(2,1) = norm(p_in_w(:,2) - b_in_w(:,2));
qmacro_nom(3,1) = norm(p_in_w(:,3) - b_in_w(:,3));
eq_homing = meas_macro_len - qmacro_nom;
