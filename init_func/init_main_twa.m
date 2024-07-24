%%%%%%       Initialization File for Control of the 3 Segment Snake %%%%%
% Elan Ahronovich 2024/05

% xPC Target Setting
dt = 0.002;  %control loop cycle

% Moving Average Filters
N_velocity = 2;
vel_filter_coeffs = ones(N_velocity,1);

N_pos = 1;
pos_filter_coeffs = ones(N_pos,1);

% PID Gains
K_p = [225 200 250 1 1 1]';
K_i = [18 18 18 0.25 0.25 0.25]';
K_d = ones(6,1);

% Macro Actuation Unit parameters
enc_res = 256*4; %[cnt/trn] * quadrature
gear_rat = 57/13; %[motor rotations/output rotation]

twa_enc_res = 256*4;
twa_gear_rat  = 3249/196;

% velmex pitch, screw is 20 turns/inch => 0.05 inch/turn => 1.27 mm/turn
velmex_pitch = 1.27; % [mm/turn]


% scope formatting
q_format = 'q1 [cnt] %12.4f,q2 [cnt] %12.4f,q3 [cnt] %12.4f,q4 [cnt] %12.4f,q5 [cnt] %12.4f,q6 [cnt] %12.4f';
qdes_format = 'q1_des [cnt] %12.4f,q2_des [cnt] %12.4f,q3_des [cnt] %12.4f,q4_des [cnt] %12.4f,q5_des [cnt] %12.4f,q6_des [cnt] %12.4f';
qd_format = 'q1d [cnt] %12.4f,q2d [cnt] %12.4f,q3d [cnt] %12.4f,q4d [cnt] %12.4f,q5d [cnt] %12.4f,q6d [cnt] %12.4f';
qcmd_format = 'q1_cmd [cnt] %12.4f,q2_cmd [cnt] %12.4f,q3_cmd [cnt] %12.4f,q4_cmd [cnt] %12.4f,q5_cmd [cnt] %12.4f,q6_cmd [cnt] %12.4f';