% This function zeros the encoders. The first step is to turn off the PID
% controller and turn off torque to all the motors then, reset the
% encoders. Set q_des to zeros and reenable PID controller.
% elan ahronovich 07/2024
function resetencoders(tg,enc_vec)
% disable quintic polynomial
tg.enablequintic(0);

% turn off PID controller    
setpidmode(tg,0);

% reset encoder counts
for i = 1:length(enc_vec)
    str = ['Encoders/enc_reset',num2str(enc_vec(i))];
    enc_id = tg.getparamid(str,'Value');
    tg.setparam(enc_id,1);
end

% get current q_des
id = tg.getparamid('q_des','Value');
q_des = tg.getparam(id);

% set the specified joint values to zero 
for i = 1:length(enc_vec)
   q_des(enc_vec(i),1) = 0; 
end

% reset q_des
setqdes(tg,q_des);

% integrator reset is necessary to eliminate effect of steady state error 
reset_s_id = tg.getparamid('PID Controller/reset_integrator','Value');
tg.setparam(reset_s_id,1);

% turn off the encoder reset bit
for i = 1:length(enc_vec)
    str = ['Encoders/enc_reset',num2str(enc_vec(i))];
    enc_id = tg.getparamid(str,'Value');
    tg.setparam(enc_id,0);
end

% set integrator reset back to 0
tg.setparam(reset_s_id,0);

% turn PID Controller and quintic polynomial back on
setpidmode(tg,1);
tg.enablequintic(1);
end