% This function changes tf in the quintic polynomial
function setQuinticTf(tg,tf)
    id = tg.getparamid('Quintic Poly/tf','Value');
    tg.setparam(id,tf);
end