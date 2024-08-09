x = 5*cos(0:pi/10:2*pi);
y = 5*sin(0:pi/10:2*pi);

for i = 1:length(x)
    xdes = [x(i);y(i);0];
    tg.setxdes(xdes);
    pause(4)
end