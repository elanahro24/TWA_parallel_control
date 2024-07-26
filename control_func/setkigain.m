function SetKiGain(tg,k)
    id = tg.getparamid('PID Controller/Ki','Gain');
    tg.setparam(id,k);
end