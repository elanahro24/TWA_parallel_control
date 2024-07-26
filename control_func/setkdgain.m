function setkdgain(tg,k)
    id = tg.getparamid('PID Controller/Kd','Gain');
    tg.setparam(id,k);
end