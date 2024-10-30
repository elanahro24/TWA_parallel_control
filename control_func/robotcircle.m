x = 0.25*cos(0:5*pi/180:2*pi);
y = 0.25*sin(0:5*pi/180:2*pi);
% x = 0.5*cos(2*pi:-5*pi/180:0);
% y = 0.5*sin(2*pi:-5*pi/180:0);

for i = 1:length(x)
    str = sprintf('Going to point %i/%i',i,2*length(x));
    if i == 1
    f = waitbar(i/(2*length(x)),str);
    else
        waitbar(i/(2*length(x)),f,str);
    end    
    xdes = [x(i);y(i);0];
    setxdes(tg,xdes);
    
    pause(6)    
end

for i = 1:length(x)
    str = sprintf('Going to point %i/%i',i+length(x),2*length(x));

    waitbar((i+length(x))/(2*length(x)),f,str);  
    xdes = [x(i);y(i);0];
    setxdes(tg,xdes);
    
    pause(6)    
end

close(f)