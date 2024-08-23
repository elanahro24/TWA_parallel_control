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
Kp = 50*ones(3,1);
Ki = 18*ones(3,1);
Kd = 0.3*ones(3,1);

Kp_mu = 150*ones(3,1);
Ki_mu = [50;50;50]; %[100;100;100]
Kd_mu = [2;5;5];

% Macro Actuation Unit parameters
enc_res = 256*4; %[cnt/trn] * quadrature
gear_rat = 57/13; %[motor rotations/output rotation]

twa_enc_res = 256*4;
twa_gear_rat  = 3249/196;

% velmex pitch, screw is 20 turns/inch => 0.05 inch/turn => 1.27 mm/turn
velmex_pitch = 1.27; % [mm/turn]

% resolved rates parameters struct
% elements = v, w, epsilon, lambda v: 
% [p_epsilon; w_epsilon; vmax; vmin; wmax; wmin; p_lambda; w_lambda; qeps]

% 1/3 rule for macro motion with w_eps = 0.035 (~2 deg) give wmax = 11.667
res_rate_param = [0.5, 0.035, 15, 0.1, 2, 0.05, 3, 3, 0.005]';

% a second column for micro actuator resolved rates
res_rate_param = [res_rate_param,...
                       [0.001, 0.0087, 20, 0.0005, 1.45, 0.001, 15, 1.5, 0.0003]'];


% switch for using twa in task space when manually choosing macro/micro
% motion. 0 = no; 1 = yes
use_twa = 1;

% scope formatting
q_format = 'q1 [mm] %12.6f,q2 [mm] %12.6f,q3 [mm] %12.6f,q4 [cnt] %12.6f,q5 [cnt] %12.6f,q6 [cnt] %12.6f';
qdes_format = 'q1_des [cnt] %8.4f,q2_des [cnt] %8.4f,q3_des [cnt] %8.4f,q4_des [cnt] %8.4f,q5_des [cnt] %8.4f,q6_des [cnt] %8.4f';
qd_format = 'q1d [mm/s] %8.6f,q2d [mm/s] %8.6f,q3d [mm/s] %8.6f,q4d [cnt] %8.6f,q5d [cnt] %8.6f,q6d [cnt] %8.6f, qdnorm %5i';
qcmd_format = 'q1_cmd [A] %12.4f,q2_cmd [A] %12.4f,q3_cmd [A] %12.4f,q4_cmd [A] %12.4f,q5_cmd [A] %12.4f,q6_cmd [A] %12.4f';
deltaq_format = 'q1 delta [mm] %12.4f,q2 delta [mm] %12.4f,q3 delta [mm] %12.4f,q4 delta [mm] %12.4f,q5 delta [mm] %12.4f,q6 delta [mm] %12.4f';
xcur_format = 'xcur [mm] %12.4f,Ycur [mm] %12.4f,Zcur [mm] %12.4f';