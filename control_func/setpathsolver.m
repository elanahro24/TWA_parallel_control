% set the solution type for robot control in task space, either using
% resolved rates (1) or inverse kinematics (2)
% elan ahronovich 08/2024
function setpathsolver(tg,n)
id = tg.getparamid('control_mode/task_space/mode','Value');
tg.setparam(id,n);
end