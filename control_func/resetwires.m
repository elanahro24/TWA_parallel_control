function  resetwires(tg)
% this function returns the twas back to their untwisted lengths
% elan ahronovich

qcur = zeros(6,1);

% grab the current q values of macro actuators to keep those in place
for i = 1:3
    str = ['Encoders/Counts To Turns',num2str(i),'/gear_ratio'];
    qcur(i,1) = tg.getsignal(tg.getsignalid(str));
end

qdes = qcur;

tg.setqdes(qdes);
end

