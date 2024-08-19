% elan ahronovich 07/2024

function Kd = getkdmugain(tg)
    id = tg.getparamid('PID Controller/Kd_mu','Gain');
    Kd = tg.getparam(id);
end