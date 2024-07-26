function Kp = getkpgain(tg)
    id = tg.getparamid('PID Controller/Kp','Gain');
    Kp = tg.getparam(id);
end