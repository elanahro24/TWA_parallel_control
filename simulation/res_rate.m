function [qcmd,des_leg_len,eq_out,twave_out,rwave_out] = res_rate(qcur,eqeps,kp,dt,p_in_m,b_in_w,measured_len,velmex_pitch,macro_leg_len,eq,twave,rwave)

qcmd = qcur;
z0 = [0 0 1]';

% moving platform vertex locations
p_in_w = twave*ones(1,3) + rwave*p_in_m;

if norm(eq) > eqeps
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
    
    des_leg_len = zeros(3,1);
    for i = 1:3
        p_in_w(:,i) = twave + rwave*p_in_m(:,i);
        des_leg_len(i,1) = norm(p_in_w(:,i) - b_in_w(:,i));
    end
    
    eq_out = macro_leg_len - des_leg_len
    normeq = norm(eq_out)
    
    % the amount each velmex slides need to move is the difference between 
    % the last leg length and the new leg length
%     qcmd(1:3,1) = (measured_len - des_leg_len)/velmex_pitch
    qcmd(1:3,1) = (des_leg_len - measured_len)/velmex_pitch
    
    twave_out = twave;
    rwave_out = rwave;
end