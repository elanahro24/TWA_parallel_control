% This function enables/disables quintic polynomial
function enablequintic(tg,tf)
    id = tg.getparamid('Quintic Poly/quintic_enable','Value');
    tg.setparam(id,tf);
    
end