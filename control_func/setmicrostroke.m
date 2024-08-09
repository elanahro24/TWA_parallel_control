% this functions sets the actuated length of twa's based on a desired
% amount of stroke
function setmicrostroke(tg,des_micro_len)
% wire properties
init_len = [229.37;228.33;227.27]; %from hook to flange %[mm]
wire_rad = 0.011 * 25.4 / 2; %[mm]
E = 60e9;
A = pi * wire_rad^2;
Ks = E*A;
wire_delta = 20/Ks;

% a matrix for allowing negative stroke direction i.e. unwinding
dir = eye(3);

% helix radius is diameter of wire strand when using only two wires
helix_rad = wire_rad * 2;

% get current set point
id = tg.getparamid('q_des','Value');
q_cur = tg.getparam(id);

qmudes = q_cur(4:6,1);
for i=1:3
%     if micro_stroke(i,1) < 0; dir(i,i) = -1; end
%     rho = init_len(i,1) - (dir(i,i)*micro_stroke(i,1));
%     qmudes(i,1) = sqrt((init_len(i,1)^2 - rho^2)/wire_rad^2);
%     qmudes(i,1) = sqrt(((init_len(i,1)^2*(1+20/Ks)^2)-rho^2)/helix_rad^2); %[rad]
    qmudes(i,1) = sqrt((1/helix_rad^2) * ...
        ((init_len(i,1)^2 * (1+wire_delta)^2) - des_micro_len(1,1)^2));
end

q_cur(4:6) = (dir*qmudes)/(2*pi);
tg.setparam(id,q_cur);
end