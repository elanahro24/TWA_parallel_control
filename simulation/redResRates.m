function [qeps,xcur,eerot,qdes,p_del] = redResRates(x_des,q_cur,qdes_cur,ee_rot_des,...
    dt,res_rate_param,full_jac,x_cur,ee_rot_cur,q_des)

qdes = qdes_cur;
xcur = x_cur;
eerot = ee_rot_cur;

% axis for jacobian definitions
z0 = [0 0 1]';

% positional error
p_del = norm(x_des - x_cur);

% positional error direction vector
if p_del ~= 0
    p_ep_hat = (x_des-x_cur)/p_del;
else
    p_ep_hat = zeros(3,1);
end

%* 
% This can probably be replaced with scalar angular difference that will 
% always bout about me = [0 0 1]'
%*

% desired orientation angle rotation matrix and error roation matrix
r_des = [cos(ee_rot_des) -sin(ee_rot_des) 0;sin(ee_rot_des) cos(ee_rot_des) 0;0 0 1];
r_cur = [cos(ee_rot_cur) -sin(ee_rot_cur) 0;sin(ee_rot_cur) cos(ee_rot_cur) 0;0 0 1];
r_del = r_des * r_cur';

% orientational error angle and axis
theta_e = acos((trace(r_del)-1)/2);

% orientational error axis
if theta_e ~= 0
    me = (1/(2*sin(theta_e)))*[r_del(3,2)-r_del(2,3);...
        r_del(1,3)-r_del(3,1);...
        r_del(2,1)-r_del(1,2)];
else
    me = z0;
end

% macro error thresholds
p_epsilon = res_rate_param(1,1);
w_epsilon = res_rate_param(2,1);

% macro linear velocity
vmax = res_rate_param(3,1);
vmin = res_rate_param(4,1);

% macro rotational velocity
wmax = res_rate_param(5,1);
wmin = res_rate_param(6,1);

% macro convergence radius multiplier
p_lambda = res_rate_param(7,1);
w_lambda = res_rate_param(8,1);

% measure joint error, proceed with looping resolved rates if the norm of
% each joint error is less than 100 microns 
qeps = zeros(6,1);
for jnum = 1:6
    qeps(jnum,1) = (norm(q_des(jnum,1) - q_cur(jnum,1)));
end

% if all(qeps(1:3) < 0.1)
    if theta_e > w_epsilon || p_del > p_epsilon        
        % linear velocity multiplier
        if p_del ~=0
            if p_del/p_epsilon <= p_lambda
                vdot = vmin + (((vmax-vmin)*(p_del-p_epsilon))/(p_epsilon*(p_lambda-1)));
            else
                vdot = vmax;
            end
        else
            vdot = 0;
        end
        
        % angular velocity multiplier
        if theta_e ~= 0
            if theta_e/w_epsilon <= w_lambda && theta_e ~= 0
                wdot = wmin + (((wmax-wmin)*(theta_e-w_epsilon))/(w_epsilon*(w_lambda-1)));
            else
                wdot = wmax;
            end
        else
            wdot = 0;
        end
        
        % xdot_des components
        v = vdot * p_ep_hat;
        w = wdot * me;
        
        % qdot des using inverse kinematics with redundancy
        qdot = full_jac * [v(1:2);w(3)];
        
        % new desired q values
        deltaq = qdot * dt;
        qdes = q_cur + deltaq;
        
        % integrate current position
        xcur = x_cur + v * dt;
        eerot = ee_rot_cur + w(3) * dt;        
    else
        qdes = qdes_cur;
        xcur = x_cur;
        eerot = ee_rot_cur;
    end
% end

end