% This function enables/disables quintic polynomial
% elan ahronovich 07/2024
function dohoming(tg,tf)
    id = tg.getparamid('do_homing','Value');
    tg.setparam(id,tf);
end