% This function enables/disables quintic polynomial
function EnableQuintic(tg,tf)
    id = tg.getparamid('Quintic Poly/quintic_enable','Value');
    tg.setparam(id,tf);
end