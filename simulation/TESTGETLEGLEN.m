clear
close all
init_twa_homing()

ee_rot = pi/6;
micro_len = 223.6857*ones(3,1);
x_prev = zeros(3,1);
meas_macro_len = [124.79;125.42;125.23];
velmex_pitch = 1.27;
q_cur = zeros(6,1);

% points for a circle
x = 0.5*cos(0:pi/90:2*pi);
y = 0.5*sin(0:pi/90:2*pi);

for i = 1:length(x)
    xdes = [10+x(i);y(i);0];

    [des_macro_len,micro_len_out, x_cur,p_in_w, b_in_w]  = getleglen(xdes,...
    ee_rot,p_in_m,b_in_w,m_in_w,f_in_w,t_in_w,twa_gamma,micro_len,x_prev);

    

    qmacro_des  = getmacroqdes(des_macro_len,meas_macro_len,velmex_pitch,q_cur);
    meas_macro_len = des_macro_len;
    cla
    draw_robot(b_in_w,p_in_w,qmacro_des)
    pause(0.01)
end