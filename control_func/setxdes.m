function setxdes(tg,x_des)
    id = tg.getparamid('task_space/x_des','Value');
    tg.setparam(id,x_des);
end