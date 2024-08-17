counter_out = 0;
num_loops = 0;
eq_out = 0.2;
do_homing = 1;
eq_eps = 0.1;
kp = 1;
dt = 0.002;
velmex_pitch = 1.27;

qdes = zeros(3,1);
qhome = [124.79;125.42;125.23];

twave = zeros(3,1); %twave_in;
twave_out = twave;
rwave = [cos(pi/6) -sin(pi/6) 0;sin(pi/6) cos(pi/6) 0;0 0 1];%rwave_in;
rwave_out = rwave;
z0 = [0 0 1]';

% moving platform radius
p_rad = 45.00; %[mm]

% base radius
b_rad = 162.32;% 158.04; %[mm]

% moving platform vertex locations
vertex_locs = [330 90 210]*pi/180;
p_in_m = p_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

p_in_w = twave + rwave*p_in_m;

% base vertex positions
b_in_w = b_rad*[cos(vertex_locs);sin(vertex_locs);zeros(1,3)];

while norm(eq_out) > eq_eps
    counter_in = counter_out;
    eq_in = eq_out;
    % get joint-level error
    if counter_in == 0
        qnom = zeros(3,1);
        qnom(1,1) = norm(p_in_w(:,1) - b_in_w(:,1));
        qnom(2,1) = norm(p_in_w(:,2) - b_in_w(:,2));
        qnom(3,1) = norm(p_in_w(:,3) - b_in_w(:,3));
        eq = qhome - qnom;
        eq_out = eq;
        counter_out = 1;
    else
        eq = eq_in;
        eq_out = eq;
        counter_out = 1;
    end

    if do_homing && norm(eq) > eq_eps
        % get parallel (macro) jacobian
        n1hat = (p_in_w(:,1)-b_in_w(:,1))./norm(b_in_w(:,1) - p_in_w(:,1));
        n2hat = (p_in_w(:,2)-b_in_w(:,2))./norm(b_in_w(:,2) - p_in_w(:,2));
        n3hat = (p_in_w(:,3)-b_in_w(:,3))./norm(b_in_w(:,3) - p_in_w(:,3));

        % Inverse kinematics jacobian components
        a13 = z0'*(cross(rwave*p_in_m(:,1),n1hat));
        a23 = z0'*(cross(rwave*p_in_m(:,2),n2hat));
        a33 = z0'*(cross(rwave*p_in_m(:,3),n3hat));

        jac = [n1hat(1,1) n1hat(2,1) a13; ...
            n2hat(1,1) n2hat(2,1) a23; ...
            n3hat(1,1) n3hat(2,1) a33];

        % joint velocities and ee velocity proportional to joint error
        qdot = kp * eq;
        tdot = jac*qdot;

        % separate translational and rotational components of twist
        v = tdot(1:2,1);
        w = tdot(3,1);

        % new end effector position
        twave(1:2,1) = twave(1:2,1) + v*dt;

        % change in end effector orientation
        del_r = [cos(w*dt) -sin(w*dt) 0;sin(w*dt) cos(w*dt) 0;0 0 1];

        % new end effector orientation
        rwave = del_r*rwave;

        for i = 1:3
            p_in_w(:,i) = twave + rwave*p_in_m(:,i);
            qdes(i,1) = norm(p_in_w(:,i) - b_in_w(:,i));
        end

        eq_out = qhome - qdes(1:3,1);
        normeq = norm(eq_out)

        q_cmd = (qhome - qdes(1:3,1))/velmex_pitch

        qhome = qdes(1:3,1);

        %     qdes(1:3,1) = qdes(1:3,1)/velmex_pitch;
        twave_out = twave;
        rwave_out = rwave;
    end
    num_loops = num_loops + 1
end
