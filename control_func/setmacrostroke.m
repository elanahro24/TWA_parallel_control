% set the amount to move the velmex slide in mm

function setmacrostroke(tg,macro_stroke)

velmex_pitch = 1.27; % [mm/turn]

macro_qdes = macro_stroke / velmex_pitch;

id = tg.getparamid('q_des','Value');
qdes_cur = tg.getparam(id);

q_des = [macro_qdes;qdes_cur(4:6)];

tg.setparam(id,q_des);

end