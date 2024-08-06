ee_rot = pi/6;
micro_len = zeros(3,1);
x_prev = zeros(3,1);
meas_macro_len = [124.79;125.42;125.23];
velmex_pitch = 1.27;
q_cur = zeros(6,1);

for i = 1:1:20
    xdes = [i;0;0];

    [des_macro_len,micro_len_out, x_cur,p_in_w, b_in_w]  = getleglen(xdes,ee_rot,micro_len,x_prev)

    qmacro_des  = getmacroqdes(des_macro_len,meas_macro_len,velmex_pitch,q_cur)
    meas_macro_len = des_macro_len;
    cla
    draw_robot(b_in_w,p_in_w,qmacro_des)
    pause(0.25)

end