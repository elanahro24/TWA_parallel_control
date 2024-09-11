x = 0.25*cos(0:pi/10:2*pi);
y = 0.25*sin(0:pi/10:2*pi);
f = waitbar(0,'Going to point 1...');

for i = 1:length(x)
    xdes = [x(i);y(i);0];
    setxdes(tg,xdes);
    
    if i == 1
        pause(3)
    else
        pause(1)
    end
    
    str = sprintf('Going to point %i',i);
    waitbar(i/length(x),f,str);
end