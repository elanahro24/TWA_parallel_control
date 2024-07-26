% This function zeros the encoders. The first step is to turn off the PID
% controller and turn off torque to all the motors then, reset the
% encoders. Set q_des to zeros and reenable PID controller.
function resetencoders(tg)
% disable quintic polynomial
tg.EnableQuintic(0);

% turn off PID controller    
SetPidMode(tg,0);

% reset enocder counts
enc_id = tg.getparamid('Encoders/enc_reset','Value');
tg.setparam(enc_id,1);

% reset q_des to zeros
setqdes(tg,zeros(6,1));

% integrator reset is necessary to eliminate effect of steady state error 
reset_s_id = tg.getparamid('PID Controller/reset_integrator','Value');
tg.setparam(reset_s_id,1);

% turn off the encoder reset bit
tg.setparam(enc_id,0);

% set integrator reset back to 0
tg.setparam(reset_s_id,0);

% turn PID Controller and quintic polynomial back on
SetPidMode(tg,1);
tg.EnableQuintic(1);
end