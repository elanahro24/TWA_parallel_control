% elan ahronovich 07/2024
function Ki = getkigain(tg)
    id = tg.getparamid('PID Controller/Ki','Gain');
    Ki = tg.getparam(id);
end