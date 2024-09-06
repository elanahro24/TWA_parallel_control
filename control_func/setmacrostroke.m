% set the amount to move the velmex slide 
% input is in mm relative to current position
% elan ahronovich 07/2024
function setmacrostroke(tg,macro_stroke)
q_des_usr = getqdesusr(tg);

q_des_macro = q_des_usr(1:3) + macro_stroke;

q_des = [q_des_macro;q_des_usr(4:6)];

setqdes(tg,q_des);

end