% elan ahronovich 07/2024
function Ki = getkimugain(tg)
    id = tg.getparamid('PID Controller/Ki_mu','Gain');
    Ki = tg.getparam(id);
end