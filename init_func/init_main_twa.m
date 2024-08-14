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
K_p = [30 30 30 1 1 1]';
K_i = [18 18 18 0.25 0.25 0.25]';
K_d = 0.3*ones(6,1);

% Macro Actuation Unit parameters
enc_res = 256*4; %[cnt/trn] * quadrature
gear_rat = 57/13; %[motor rotations/output rotation]

twa_enc_res = 256*4;
twa_gear_rat  = 3249/196;

% velmex pitch, screw is 20 turns/inch => 0.05 inch/turn => 1.27 mm/turn
velmex_pitch = 1.27; % [mm/turn]

% resolved rates parameters struct
% elements = v, w, epsilon, lambda v: 
% [p_epsilon; w_epsilon; vmax; vmin; wmax; wmin; p_lambda; w_lambda]
res_rate_param = [1, 0.001, 500, 1, 0.001, 0.05, 3, 3]';


% switch for using twa in task space when manually choosing macro/micro
% motion. 0 = no; 1 = yes
use_twa = 0;

% scope formatting
q_format = 'q1 [mm] %12.4f,q2 [mm] %12.4f,q3 [mm] %12.4f,q4 [cnt] %12.4f,q5 [cnt] %12.4f,q6 [cnt] %12.4f';
qdes_format = 'q1_des [cnt] %8.4f,q2_des [cnt] %8.4f,q3_des [cnt] %8.4f,q4_des [cnt] %8.4f,q5_des [cnt] %8.4f,q6_des [cnt] %8.4f';
qd_format = 'q1d [mm/s] %8.6f,q2d [mm/s] %8.6f,q3d [mm/s] %8.6f,q4d [cnt] %8.6f,q5d [cnt] %8.6f,q6d [cnt] %8.6f, qdnorm %5i';
qcmd_format = 'q1_cmd [A] %12.4f,q2_cmd [A] %12.4f,q3_cmd [A] %12.4f,q4_cmd [A] %12.4f,q5_cmd [A] %12.4f,q6_cmd [A] %12.4f';
deltaq_format = 'q1 delta [mm] %12.4f,q2 delta [mm] %12.4f,q3 delta [mm] %12.4f,q4 delta [mm] %12.4f,q5 delta [mm] %12.4f,q6 delta [mm] %12.4f';
xcur_format = 'xcur [mm] %12.4f,Ycur [mm] %12.4f,Zcur [mm] %12.4f';