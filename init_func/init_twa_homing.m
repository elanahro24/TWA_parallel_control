% for initialization resolved rates.
% physically measured macro leg lengths at initial position
meas_macro_len = [124.79;125.42;125.23];

% physically measured UNTWISTED twa lengths
meas_twa_len = [229.37 228.33 227.27];
ee_rot = pi/6;
rm2w_homing = [cos(ee_rot) -sin(ee_rot) 0;sin(ee_rot) cos(ee_rot) 0;0 0 1];

% locations of moving platform verteces
platform_vertex_locs = [330 90 210]*pi/180;
p_rad = 45.00; %[mm]
p_in_m = p_rad*[cos(platform_vertex_locs);sin(platform_vertex_locs);zeros(1,3)];

% base vertex locations 
% angular offset for base verteces is different than moving platform due to
% a miscommunication during the designing process
base_vertex_locations = [333.03 93.03 213.03]*pi/180;
b_rad = 162.31;% 158.04; %[mm]
b_in_w = b_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% flexure rotation center
f_rad = 80; %[mm]
flexure_locs = [-40 80 200]*pi/180;
f_in_w = f_rad*[cos(flexure_locs);sin(flexure_locs);zeros(1,3)];

% TWA motor position
m_rad = 238.30; %from CAD [mm] (old number, not sure where it came from 11.915)
motor_locs = [257.18 17.18 137.18]*pi/180;
m_in_w = m_rad*[cos(motor_locs);sin(motor_locs);zeros(1,3)];

% distance from rotation axis to start of TWA measured from CAD
axis_offset = 16.7;

% moving platform starts at the origin with 30 degree rotation
p_in_w = zeros(3,3) + rm2w_homing*p_in_m;

qmacro_nom = zeros(3,1);
qmacro_nom(1,1) = norm(p_in_w(:,1) - b_in_w(:,1));  
qmacro_nom(2,1) = norm(p_in_w(:,2) - b_in_w(:,2));
qmacro_nom(3,1) = norm(p_in_w(:,3) - b_in_w(:,3));
eq_homing = meas_macro_len - qmacro_nom;

qmicro_nom = zeros(3,1);
qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - axis_offset;
qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - axis_offset;
qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - axis_offset;

