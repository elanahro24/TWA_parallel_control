% This function enables/disables quintic polynomial
function dohoming(tg,tf)
    id = tg.getparamid('do_homing','Value');
    tg.setparam(id,tf);
end