function Kd = GetKdGain(tg)
    id = tg.getparamid('PID Controller/Kd','Gain');
    Kd = tg.getparam(id);
end