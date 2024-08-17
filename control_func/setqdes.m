% elan ahronovich 07/2024
function setqdes(tg,q_des)
    id = tg.getparamid('control_mode/q_des_usr','Value');
    tg.setparam(id,q_des);
end