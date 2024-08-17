% get the resolved rates parameters
% elan ahronovich 07/2024

function res_rate_param = getratesparam(tg)
loc = 'control_mode/task_space/res_rate_param';
res_rate_param = tg.getparam(tg.getparamid(loc,'Value'));
end