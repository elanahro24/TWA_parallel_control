% for initialization resolved rates.
% locations of moving platform and base verteces
vertex_locs = [330 90 210]*pi/180;

% moving platform radius
p_rad = 45.00; %[mm]

% base radius
b_rad = 162.32;% 158.04; %[mm]

% moving platform vertex locations
p_in_m = p_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% base vertex positions
b_in_w = b_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% physically measured macro leg lengths at initial position
meas_macro_len = [124.79;125.42;125.23];

% end effector rotation during initialization
ee_rot = pi/6;

% rotation matrix
rm2w_homing = [cos(ee_rot) -sin(ee_rot) 0;sin(ee_rot) cos(ee_rot) 0;0 0 1];

% moving platform starts at the origin with 30 degree rotation
p_in_w = zeros(3,3) + rm2w_homing*p_in_m;

qnom = zeros(3,1);
qnom(1,1) = norm(p_in_w(:,1) - b_in_w(:,1));
qnom(2,1) = norm(p_in_w(:,2) - b_in_w(:,2));
qnom(3,1) = norm(p_in_w(:,3) - b_in_w(:,3));
eq_homing = meas_macro_len - qnom;