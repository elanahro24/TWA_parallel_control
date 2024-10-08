%this script commands the robot to move in a spiral

figure();
spir = plot(0,0,'.');
hold on
grid on
set(gcf,'color','w')
spir2 = plot(0,0,'o','MarkerSize',5);

% theta = 0:10*pi/180:12*pi;
% x = theta/45.*cos(theta);
% y = theta/45.*sin(theta);

theta = 0:10*pi/180:12*pi;
x = theta/90.*cos(theta);
y = theta/90.*sin(theta);
spir.XData = x; spir.YData = y;

for i = 1:length(x)
    str = sprintf('Going to point %i/%i',i,length(x));
    
    if i == 1
        f = waitbar(i/(2*length(x)),str);
    else
        waitbar(i/(2*length(x)),f,str);
    end  
    
    xdes = [x(i);y(i);0];
    setxdes(tg,xdes);
    spir2.XData = [spir2.XData, x(i)];
    spir2.YData = [spir2.YData,y(i)];
    pause(4)    
end

close(f)