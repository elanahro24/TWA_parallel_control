% elan ahronovich 07/2024

function Kd = getkdgain(tg)
    id = tg.getparamid('PID Controller/Kd','Gain');
    Kd = tg.getparam(id);
end