x = 1*cos(0:pi/10:2*pi);
y = 1*sin(0:pi/10:2*pi);
f = waitbar(0,'Going to point 1...');

for i = 1:length(x)
    xdes = [x(i);y(i);0];
    setxdes(tg,xdes);
    pause(5)
    str = sprintf('Goint to point %i',i);
    waitbar(i/length(x),f,str);
end