clear
close all
init_twa_homing()
init_twa_wires()
load('temp')
path = 1000 * temp;

ee_rot = pi/6;
micro_len = 223.6857*ones(3,1);
x_prev = [2.5;-2.5;0];
meas_macro_len = [124.79;125.42;125.23];
macro_len_prev = meas_macro_len;
use_twa = 1;
velmex_pitch = 1.27;
q_cur = zeros(6,1);

% points for a circle
x = 1.5*cos(0:pi/60:2*pi);
y = 1.5*sin(0:pi/60:2*pi);

for i = 1:length(x)
    xdes = [path(1,i);path(2,i);0];
%     xdes = [0;0;0];

    [des_macro_len,micro_len_out,p_in_w, b_in_w]  = getleglen(xdes,...
    ee_rot,p_in_m,b_in_w,m_in_w,f_in_w,t_in_w,twa_gamma,use_twa,macro_len_prev,micro_len);
    
%     disp(['qmicro1 = : ',num2str(micro_len_out(1)),' qmicro2 = : ',num2str(micro_len_out(2)),' qmicro3 = : ',num2str(micro_len_out(3))])
    
    qmacro_des  = getmacroqdes(des_macro_len,macro_len_prev,velmex_pitch,q_cur);
%     disp(['qmacro1 = : ',num2str(qmacro_des(1)),' qmacro2 = : ',num2str(qmacro_des(2)),' qmacro3 = : ',num2str(qmacro_des(3))])

    macro_len_prev = des_macro_len;
    micro_len = micro_len_out;

    cla
    draw_robot(b_in_w,p_in_w,qmacro_des)
    pause(1)
end