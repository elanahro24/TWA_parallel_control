% get the current value of the user specified q_des
% elan ahronovich 07/2024

function q_des_usr = getqdesusr(tg)
id = tg.getparamid('control_mode/q_des_usr','Value');
q_des_usr = tg.getparam(id);
end