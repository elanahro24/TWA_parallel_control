% set the resolved rates parameters
% params is an 8x2 matrix, for macro and micro motion parameters
% elan ahronovich 07/2024

function res_rate_param = setratesparam(tg,params)
loc = 'control_mode/task_space/res_rate_param';
res_rate_param = tg.setparam(tg.getparamid(loc,'Value'),params);
end