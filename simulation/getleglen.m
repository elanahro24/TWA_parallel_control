function [des_macro_len,micro_len_out, x_cur,p_in_w, b_in_w]  = getleglen(x_des,ee_rot,micro_len,x_prev)
% This function solves for the vertex positions of the base and moving
% platform for a given desired end effector position.
% With vertex positions known, leg lengths can be solved for.

% initialization
conv_rad = 0.5; %[mm]
x_cur = x_des;

micro_len_out = micro_len;
x_delta = abs(x_des - x_prev);

% initial twa wire length
init_twa_len = [225.8;226.3;224.5]; %[mm]

% moving platform radius
p_rad = 45.00; %[mm]

% base radius
b_rad = 162.32;% 158.04; %[mm]

% rotation matrix of moving frame about z-xis
rot_m2w = [cos(ee_rot) -sin(ee_rot) 0; sin(ee_rot) cos(ee_rot) 0; 0 0 1];

% moving platform vertex locations
vertex_locs = [330 90 210]*pi/180;
p_in_m = p_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% x_des = zeros(3,1);
p_in_w = x_des*ones(1,3) + rot_m2w*p_in_m;

% base vertex positions
b_in_w = b_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

% position of flexure centers
% radius of position of flexure center
f_rad = 80; %[mm]
flexure_locs = [-40 80 200]*pi/180;
f_in_w = f_rad*[cos(flexure_locs);sin(flexure_locs);zeros(1,3)];

% position of twa pivot point, taken from CAD
% radius of position of twa pivot
m_rad = 11.915;
motor_locs = [257.18 17.18 137.18]*pi/180;
m_in_w = m_rad*[cos(motor_locs);sin(motor_locs);zeros(1,3)];


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%        Macro Actuator        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

vertex_dist = p_in_w - b_in_w;

des_macro_len = zeros(3,1);
des_macro_len(1,1) = norm(vertex_dist(:,1));
des_macro_len(2,1) = norm(vertex_dist(:,2));
des_macro_len(3,1) = norm(vertex_dist(:,3));