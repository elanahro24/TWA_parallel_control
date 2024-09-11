% This function sets the switch for control mode between joint and task
% spaces.
% For joint space control set to 1, for task space set to 2.
% default is joint space control i.e. = 1
function setcontrolmode(tg,n)
%get the current control mode
id = tg.getparamid('control_mode/mode','Value');
cur_mode = tg.getparam(id);

% if switching from task space to joint space control,
% preemptively change the q_des_usr value to the q_des value
% currently being sent to the actuators. This will limit the
% actuators from jumping positions
if cur_mode == 2
    q_des_cur = zeros(6,1);
    for i = 1:6
        str = ['control_mode/control_switch/s',num2str(i)];
        q_des_cur(i,1) = tg.getsignal(str);
    end
    setqdes(tg,q_des_cur);
end

%change control mode
tg.setparam(id,n);

end