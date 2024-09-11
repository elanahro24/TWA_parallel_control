%%%%%%       Initialization File for Control of the 3 Segment Snake %%%%%
% Elan Ahronovich 2024/05

% xPC Target Setting
dt = 0.001;  %control loop cycle

% Moving Average Filters
N_velocity = 2;
vel_filter_coeffs = ones(N_velocity,1);

N_pos = 1;
pos_filter_coeffs = ones(N_pos,1);

% PID Gains
pid_mode = 0; %start off for safety
reset_integ = 0; %reset integrator
Kp = [1500;25;25];%25*ones(3,1);
Ki = [9;9;9];%9*ones(3,1);
Kd = [5;0.15;0.15];%0.15*ones(3,1);

Kp_mu = 150*ones(3,1);
Ki_mu = 5*ones(3,1); %[100;100;100]
Kd_mu = 2*ones(3,1);

% Motor parameters
enc_res = [512; 256; 256]*4; %[cnt/trn] * quadrature
gear_rat = [729/25; 57/13; 57/13]; %[motor rotations/output rotation]

twa_enc_res = 256*4;
twa_gear_rat  = 3249/196;

enc_res_vec = [enc_res;twa_enc_res*ones(3,1)];
gear_rat_vec = [gear_rat;twa_gear_rat*ones(3,1)];

% initialize encoder counts to enable zeroing
init_cnt = 20;

% velmex pitch, screw is 20 turns/inch => 0.05 inch/turn => 1.27 mm/turn
velmex_pitch = 1.27; % [mm/turn]

% resolved rates parameters struct
% elements = v, w, epsilon, lambda v: 
% [p_epsilon; w_epsilon; vmax; vmin; wmax; wmin; p_lambda; w_lambda; qeps]

% 1/3 rule for macro motion with w_eps = 0.035 (~2 deg) give wmax = 11.667
res_rate_param = [0.5, 0.035, 2, 0.1, 2, 0.05, 3, 3, 0.005]';

% a second column for micro actuator resolved rates
res_rate_param = [res_rate_param,...
                       [0.001, 0.0087, 0.01, 0.0005, 1.45, 0.001, 20, 1.5, 0.0003]'];


% switch for using twa in task space when manually choosing macro/micro
% motion. 0 = no; 1 = yes
use_twa = 0;

% scope formatting
q_format = 'q1 [mm] %12.6f,q2 [mm] %12.6f,q3 [mm] %12.6f,q4 [cnt] %12.6f,q5 [cnt] %12.6f,q6 [cnt] %12.6f';
qdes_format = 'q1_ref [cnt] %8.4f,q2_ref [cnt] %8.4f,q3_ref [cnt] %8.4f,q4_ref [cnt] %8.4f,q5_ref [cnt] %8.4f,q6_ref [cnt] %8.4f';
qd_format = 'q1d [mm/s] %8.6f,q2d [mm/s] %8.6f,q3d [mm/s] %8.6f,q4d [cnt] %8.6f,q5d [cnt] %8.6f,q6d [cnt] %8.6f, qdnorm %5i';
qcmd_format = 'q1_cmd [A] %12.4f,q2_cmd [A] %12.4f,q3_cmd [A] %12.4f,q4_cmd [A] %12.4f,q5_cmd [A] %12.4f,q6_cmd [A] %12.4f';
deltaq_format = 'q1 delta [mm] %12.4f,q2 delta [mm] %12.4f,q3 delta [mm] %12.4f,q4 delta [mm] %12.4f,q5 delta [mm] %12.4f,q6 delta [mm] %12.4f';
xcur_format = 'x [mm] %12.4f,y [mm] %12.4f,omega [rad] %12.4f';