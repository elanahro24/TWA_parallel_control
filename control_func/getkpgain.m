function Kp = getkpgain(tg)
%     id = tg.getparamid('PID Controller/Kp','Gain'); % for r2010a
    Kp = tg.getparam('Kp');
end