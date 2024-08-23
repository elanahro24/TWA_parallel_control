% This function zeros the encoders. The first step is to turn off the PID
% controller and turn off torque to all the motors then, reset the
% encoders. Set q_des to zeros and reenable PID controller.
% elan ahronovich 07/2024
function resetencoders(tg,enc_vec)
% get quintic polynomial state, turn off if on
quintic_id = tg.getparamid('Quintic Poly/quintic_enable','Value');
quintic_enable = tg.getparam(quintic_id);

if quintic_enable; tg.setparam(quintic_id, 0); end

% turn off PID controller    
setpidmode(tg,0);

% reset encoder counts
for i = 1:length(enc_vec)
    str = ['Encoders/enc_reset',num2str(enc_vec(i))];
    enc_id = tg.getparamid(str,'Value');
    tg.setparam(enc_id,1);
end

% get current q_des
id = tg.getparamid('control_mode/q_des_usr','Value');
q_des = tg.getparam(id);

% set the specified joint values to zero 
for i = 1:length(enc_vec)
   q_des(enc_vec(i),1) = 0; 
end

% reset q_des
setqdes(tg,q_des);

% integrator reset is necessary to eliminate effect of steady state error 
reset_s_id = tg.getparamid('PID Controller/reset_integ','Value');
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
if quintic_enable; tg.setparam(quintic_id, 1); end
end