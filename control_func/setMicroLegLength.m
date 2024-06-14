function setMicroLegLength(tg,leg_len)
    id = tg.getparamid('micro_leg_len','Value');
    tg.setparam(id,leg_len);
end