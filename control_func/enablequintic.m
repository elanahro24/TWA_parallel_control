% This function enables/disables quintic polynomial
% elan ahronovich 07/2024
function enablequintic(tg,tf)
    id = tg.getparamid('Quintic Poly/quintic_enable','Value');
    tg.setparam(id,tf);
end