sc5 = tg.getscope(5);
sc6 = tg.getscope(6);
sc7 = tg.getscope(7);

sc5.start;
sc6.start;
sc7.start;

pause(1)

tg.setparam('pid_mode',1);
tg.setparam('do_quintic',0);

pause(1)

x = 0:0.001:10;

for i = 1:length(x)
    q1des = x(i);
    
    str = sprintf('Going to %2.3f mm',q1des);
    if i == 1
        f = waitbar(i/length(x),str);
    else
        waitbar(i/length(x),f,str);
    end 
    
    tg.setparam('q_des',q1des);
    pause(.002)    
end

for i = 1:length(x)
    q1des = x(end) - x(i);
    str = sprintf('Going to %2.3f mm',q1des);
    waitbar((length(x)-i)/length(x),f,str);
    tg.setparam('q_des',q1des);
    pause(.002)
end

close(f)

sc5.stop;
sc6.stop;
sc7.stop;

tg.setparam('pid_mode',0);
tg.stop;
