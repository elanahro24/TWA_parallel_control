%%       Initialization File for Control of the 3 Segment Snake
%%                          xPC Target Setting
dt = 0.001;  %control loop cycle
% dt_trakstar = 0.008;
%%                  PID CONTROLLER GAINS
% The original gains
% for 3 segment big snake
% K_p = diag([180,180,180,180,180,180,200,200,200,180]); 
% K_d = diag([4.5,4.5,4.5,4.5,4.5,4.5,3.5,3.5,3.5,4.5]);
K_p = diag([180,180,180,180,180,180,30,30,30,180]);
K_d = diag([4.5,4.5,4.5,4.5,4.5,4.5,1,0.5,1,4.5]);
disp('Proportional Gain Matrix');
disp(K_p);
disp('Derivative Gain Matrix');
disp(K_d);
% K_i = 0.4*eye(10);
%%                 Enable Hardware/Control
enc_res = 0;
Enable_control = 0;               %set to 1 to enable motors
% Enable_motors = zeros(8,1);        %set for ones(8,1) to enable motors
% Enable_Motors =  ones(8,1); %since we are missing a relay for the 9th motor
% joint_treashold = [5;5;5;10;10;10;15;15;15]; % mm
max_joint_vel = [3;3;3;3;3;3;10;10;10;10]; % mm/sec
%%                Snake geometry constants 
[r,L1,L2,L3,theta_0,beta] = BS_robot_kin_param();
%% Actuation Unit
% PITCH: The axial distance between threads. Pitch is equal to the lead in
%        a single start screw.
% LEAD: The axial distance the nut advances in one revolution of the screw.
%       The lead is equal to the pitch times the number of starts.
% LEAD = PITCH x STARTS
LEAD_big = 5.08; %mm/turn
LEAD_small = 0.6091;%mm/turn
LEAD_velmex = 1.27; % mm/turn
%   velmex is 20 turns/inch => 0.05 inch/turn => 1.27 mm/turn
%----------Motor Encoder and Gear Parameters--------------------------------
GEAR_RATIO_big   = 41553/325;
GEAR_RATIO_small = 64;
GEAR_RATIO_rotary = 185193/2197;
GEAR_RATIO_RE16 = 729/25; % maxon RE16 29:1
ENCODER_COUNTS_big   = 100;     % Counts per revolution axes 1-6
ENCODER_COUNTS_small = 12;      % Counts per revolution axes 7-9
ENCODER_COUNTS_rotary = 100;
ENCODER_COUNTS_RE16 = 512;      % Counts per revolution
K_motors_1to6=diag([1/(ENCODER_COUNTS_big*4),1/(ENCODER_COUNTS_big*4),1/(ENCODER_COUNTS_big*4),1/(ENCODER_COUNTS_big*4),1/(ENCODER_COUNTS_big*4),1/(ENCODER_COUNTS_big*4)]);
K_motors_7to9=diag([1/(ENCODER_COUNTS_small*4),1/(ENCODER_COUNTS_small*4),1/(ENCODER_COUNTS_small*4)]);
K_motor_10 = 1/(ENCODER_COUNTS_rotary*4);
K_motors_Velmex_7to9 = (1/(ENCODER_COUNTS_RE16*4))*diag([1,1,1]);
Gear_ratio_matrix_1to6=diag([1/GEAR_RATIO_big,1/GEAR_RATIO_big,1/GEAR_RATIO_big,1/GEAR_RATIO_big,1/GEAR_RATIO_big,1/GEAR_RATIO_big]);
Gear_ratio_matrix_7to9 = diag([1/GEAR_RATIO_small,1/GEAR_RATIO_small,1/GEAR_RATIO_small]);
Gear_ratio_matrix_Velmex_7to9 = (1/GEAR_RATIO_RE16)*diag([1,1,1]);
Gear_ratio_10 = 1/GEAR_RATIO_rotary;
Lead_matrix_1to6 = diag([LEAD_big,LEAD_big,LEAD_big,LEAD_big,LEAD_big,LEAD_big]);
Lead_matrix_7to9 = diag([LEAD_small,LEAD_small,LEAD_small]);
Lead_matrix_velmex_7to9 = diag([LEAD_velmex,LEAD_velmex,LEAD_velmex]);

%% Actuation Compensation
% k_comp = [1.1908;1.0914;1.0918];             %vector of compensation factors for each segment
% K_compensator = 1.5 * eye(6); %diag([1.63,2.2,2.2,2.8,2,3.2]); % ONLINE COMPENSATOR
% Kd_compensator = 0.1 * eye(6); %diag([0.13,0.1,0.12,0.16,0.2,0.25]);
% disp('Online PSI Compensator Gain Matrix');
% disp(K_compensator);
%% Moving Average Filters
N_velocity = 2;
vel_filter_coeffs = ones(N_velocity,1); %weights of position data point
% N_vel_coeff = 200;
% trakstar_vel_filter_coeffs = ones(N_vel_coeff,1);
%% Elliptic Filter
% [b_IIR_Filter_Coeffs,a_IIR_Filter_Coeffs] = ellip(3,0.5,40,10/500); % 3th order Elliptical Filter, passband edge frequency 10/500
%% Phantom Omni
% R_omni_rob = RotationMatrix(-90,[0;0;1])*RotationMatrix(-90,[1;0;0]);
%% Magnetic Tracker
N_trakstar = 1;
trakstar_filter_coeffs = ones(N_trakstar,1); %weights of position data point
dt_trakstar = 0.008; % magnetic tracker time step
dt_configuration_space = dt_trakstar;
%%  Joint limits
theta_max = pi/2;
theta_min = pi/10;
psi_max = [theta_max;inf;theta_max;inf];
psi_min = [theta_min;-inf;theta_min;-inf];
ins_ctr_limits = [0,L1]; 
% ins_ctr_limits - central backbone insertion distance
% this is used only in config-ins-coordination mode
ins_joints_max = [30;30;30];
ins_joints_min = [-80;-80;-80];
q_max_seg_1 = r * (pi/2-theta_min);
q_max = [q_max_seg_1;q_max_seg_1;q_max_seg_1];
q_min = -q_max;
%%  Potentiometers
%   Pot gains
pot_gain_mean = mean([4.4271;4.4591;4.5181]);
pot_gains = diag([4.4271;4.4591;4.5181;...
                    pot_gain_mean*ones(3,1);...
                    ones(3,1)]); % need to calibrate
q_home = [  0;0;0;...
            0;0;0;...
            0;0;0];
pot_home = [2.5;2.5;2.5;...
            2.5;2.5;2.5;...
            0;0;0];
q_epsilon = 0.2;
%   Pot filter
N_pot_voltage = 5;
pot_voltage_filter_coeffs = ones(N_pot_voltage,1);
%%  Motor Stalling Safety
STALL_VOLTAGE = 9.5;
STALL_JOINT_SPEED = 0.05;
STALL_TIME = 3;

