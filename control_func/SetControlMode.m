% This function sets the switch for control mode between joint and task
% spaces.
% For joint space control set to 0, for task space set to 1.
% default is joint space control i.e. = 0
function SetControlMode(tg,n)
    id = tg.getparamid('cntrl_mode','Value');
    tg.setparam(id,n);
end