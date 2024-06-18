function SetQdes(tg,q_des)
    id = tg.getparamid('q_des','Value');
    tg.setparam(id,q_des);
end