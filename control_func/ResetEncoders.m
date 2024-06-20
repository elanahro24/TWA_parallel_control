% This function zeros the encoders. The first step is to turn off the PID
% controller and turn off torque to all the motors then, reset the
% encoders. Set q_des to zeros and reenable PID controller.
function ResetEncoders(tg)
% turn off PID controller    
SetPidMode(tg,0);

% reset encoders
id = tg.getparamid('Encoders/enc_reset','Value');
tg.setparam(id,1);
pause(1);
tg.setparam(id,0);

% reset q_des to zeros
SetQdes(tg,zeros(6,1));

% turn on PID Controller
SetPidMode(tg,1);
end