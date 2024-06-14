function Ki = getKiGain(tg)
    id = tg.getparamid('PID Controller/Ki','Gain');
    Ki = tg.getparam(id);
end