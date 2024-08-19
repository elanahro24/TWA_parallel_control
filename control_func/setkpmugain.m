function setkpmugain(tg,k)
    id = tg.getparamid('PID Controller/Kp_mu','Gain');
    tg.setparam(id,k);
end