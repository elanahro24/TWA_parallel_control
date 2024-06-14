function Kp = getKpGain(tg)
    id = tg.getparamid('PID Controller/Kp','Gain');
    Kp = tg.getparam(id);
end