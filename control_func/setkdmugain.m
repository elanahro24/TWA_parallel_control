function setkdmugain(tg,k)
    id = tg.getparamid('PID Controller/Kd_mu','Gain');
    tg.setparam(id,k);
end