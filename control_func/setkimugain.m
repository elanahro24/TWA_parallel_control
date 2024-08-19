function setkimugain(tg,k)
    id = tg.getparamid('PID Controller/Ki_mu','Gain');
    tg.setparam(id,k);
end