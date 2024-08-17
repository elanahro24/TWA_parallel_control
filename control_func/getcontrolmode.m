% This function sets the switch for control mode between joint and task
% spaces.
% elan ahronovich 07/2024
% For joint space control set to 1, for task space set to 2.
% default is joint space control i.e. = 1
function getcontrolmode(tg)
    id = tg.getparamid('cntrl_mode','Value');
    mode = tg.getparam(id);
    
    switch mode
        case 1
            disp('Control mode is in joint space (i.e. commanding qdes');
        case 2
            disp('Control mode is in task space');
    end
end