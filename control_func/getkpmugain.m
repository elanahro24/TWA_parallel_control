function Kp = getkpmugain(tg)
    id = tg.getparamid('PID Controller/Kp_mu','Gain');
    Kp = tg.getparam(id);
end