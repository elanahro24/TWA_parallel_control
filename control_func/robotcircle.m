x = 0.5*cos(0:5*pi/180:2*pi);
y = 0.5*sin(0:5*pi/180:2*pi);

for i = 1:length(x)
    str = sprintf('Going to point %i/%i',i,2*length(x));
    if i == 1
    f = waitbar(i/(2*length(x)),str);
    else
        waitbar(i/(2*length(x)),f,str);
    end    
    xdes = [x(i);y(i);0];
    setxdes(tg,xdes);
    
    pause(2)    
end

for i = 1:length(x)
    str = sprintf('Going to point %i/%i',i+length(x),2*length(x));

    waitbar((i+length(x))/(2*length(x)),f,str);  
    xdes = [x(i);y(i);0];
    setxdes(tg,xdes);
    
    pause(2)    
end

close(f)