function qmacro_des  = getmacroqdes(des_macro_len,meas_macro_len,velmex_pitch,q_cur)
% This function solves for command signal for given desired macro leg
% lengths

% if required velmex motion is less than 0.5 mm, do not move velmex
converg_rad = 0.5;

qmacro_des = (q_cur(1:3,1));

velmex_limit = 30; %+-30 mm stroke from starting point at the velmex pivot 

velmex_stroke = zeros(3,1);
velmex_stroke(1,1) = des_macro_len(1,1) - meas_macro_len(1,1);
velmex_stroke(2,1) = des_macro_len(2,1) - meas_macro_len(2,1);
velmex_stroke(3,1) = des_macro_len(3,1) - meas_macro_len(3,1);

for i = 1:3
    if abs(velmex_stroke(i,1)) < velmex_limit && abs(velmex_stroke(i,1)) > converg_rad
        qmacro_des(i,1) = velmex_stroke(i,1) / velmex_pitch;
    end
end
