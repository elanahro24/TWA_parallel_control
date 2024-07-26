function setkpgain(tg,k)
    id = tg.getparamid('PID Controller/Kp','Gain');
    tg.setparam(id,k);
end