% set the amount to move the velmex slide 
% input is in mm relative to current position
% elan ahronovich 07/2024
function setmacrostroke(tg,macro_stroke)
q_des_usr = tg.getqdesusr;

q_des = q_des_usr + [macro_stroke;zeros(3,1)];

tg.setqdes(q_des);

end