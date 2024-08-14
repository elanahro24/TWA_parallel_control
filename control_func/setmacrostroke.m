% set the amount to move the velmex slide in mm

function setmacrostroke(tg,macro_stroke)

id = tg.getparamid('q_des','Value');
qdes_cur = tg.getparam(id);

q_des = [macro_stroke;qdes_cur(4:6)];

tg.setparam(id,q_des);

end