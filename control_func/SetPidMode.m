% This function sets the switch for the pid control mode between manual
% current control and PID control.
% Default is manual current control.
function SetPidMode(tg,n)
    id = tg.getparamid('PID Controller/pid_mode','Value');
    tg.setparam(id,n);
end