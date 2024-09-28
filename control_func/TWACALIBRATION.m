savedat = 1;
plotdat = 1;

experiment = 'twa2cal';
twacaldata.expname = experiment;
twacaldata.wirelength = 232.98;

expstr = sprintf([experiment,'.dat']);

sc3 = tg.getscope(3);%qcur, qref, potv, potmm
sc3.FileName = expstr;
tg.start;

pause

sc3.start;

tg.setparam('pid_mode',1);
tg.setparam('quintic_tf',0.05)

pause(0.5)

x = 0:5*pi/180:50*2*pi; %[radians]

for i = 1:length(x)
    q1des = x(i);
    
    str = sprintf('Going to %2.3f mm',q1des);
    if i == 1
        f = waitbar(i/length(x),str);
    else
        waitbar(i/length(x),f,str);
    end 
    
    tg.setparam('q_des',q1des);
    pause(.075)
end

for i = 1:length(x)
    q1des = x(end) - x(i);
    str = sprintf('Going to %2.3f mm',q1des);
    waitbar((length(x)-i)/length(x),f,str);
    tg.setparam('q_des',q1des);
    pause(.075)
end
pause(5);
close(f)
sc3.stop;

tg.setparam('pid_mode',0);
tg.stop;


%get and save data
if plotdat
    SimulinkRealTime.copyFileToHost(expstr)
    twacal = SimulinkRealTime.utils.getFileScopeData(expstr);
    
    twacaldata.qcur = twacal.data(:,1);
    twacaldata.qref = twacal.data(:,2);
    twacaldata.potv = twacal.data(:,3);
    twacaldata.potmm = twacal.data(:,4);
    twacaldata.t = twacal.data(:,5);
    
    fig = figure();
    plot(twacaldata.t,twacaldata.potv,'.')
    hold on
    legend('Pot [V]');
    set(gcf,'Color','w')
end

if savedat
   save(experiment,'twacaldata');
end

grid on