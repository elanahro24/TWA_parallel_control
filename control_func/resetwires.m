function  resetwires(tg)
% this function returns the twas back to their untwisted lengths

qcur = zeros(6,1);

% grab the current q values of macro actuators to keep those
for i = 1:3
    str = ['Encoders/Counts To Turns',num2str(i),'/gear_ratio'];
    qcur(i,1) = tg.getsignal(tg.getsignalid(str));
end

qdes = qcur;
id = tg.getparamid('q_des','Value');
tg.setparam(id,qdes);

end

