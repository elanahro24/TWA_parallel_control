% This function sets the switch for control mode between joint and task
% spaces.
% For joint space control set to 1, for task space set to 2.
% default is joint space control i.e. = 1
function SetControlMode(tg,n)
    id = tg.getparamid('cntrl_mode','Value');
    tg.setparam(id,n);
end