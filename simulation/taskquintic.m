function [qdes,deltax,tinit,xinit,robotmoving] = taskquintic(mode,q_cur,...
    p_in_m,b_in_w,m_in_w,f_in_w,x_des,...
    tc,tf,q_des,x_cur,t_init,x_init,robot_moving)

% initialize
qdes = q_des;
deltax = x_cur;
tinit = t_init;
xinit = x_init;
robotmoving = robot_moving;

if mode == 3; do_quintic = 1; else; do_quintic =0; end

% axis for jacobian definitions
z0 = [0 0 1]';

% rotation matrix
ee_rot_cur = pi/6;
r_cur = [cos(ee_rot_cur) -sin(ee_rot_cur) 0;sin(ee_rot_cur) cos(ee_rot_cur) 0;0 0 1];

% moving platform vertex locations
p_in_w = x_cur*ones(1,3) + r_cur*p_in_m;

%% instantaneous direct kinematics jacobian
% vector from base vertex to moving platform vertex
n1hat = (p_in_w(:,1)-b_in_w(:,1))./norm(b_in_w(:,1) - p_in_w(:,1));
n2hat = (p_in_w(:,2)-b_in_w(:,2))./norm(b_in_w(:,2) - p_in_w(:,2));
n3hat = (p_in_w(:,3)-b_in_w(:,3))./norm(b_in_w(:,3) - p_in_w(:,3));

a13 = z0'*(cross(r_cur*p_in_m(:,1),n1hat));
a23 = z0'*(cross(r_cur*p_in_m(:,2),n2hat));
a33 = z0'*(cross(r_cur*p_in_m(:,3),n3hat));

idk_jac = [n1hat(1,1) n1hat(2,1) a13; ...
    n2hat(1,1) n2hat(2,1) a23; ...
    n3hat(1,1) n3hat(2,1) a33];

%% instantaneous inverse kinematics jacobian
% micro actuator (TWA) lengths
q1_mu = norm(b_in_w(:,1) - m_in_w(:,1));
q2_mu = norm(b_in_w(:,2) - m_in_w(:,2));
q3_mu = norm(b_in_w(:,3) - m_in_w(:,3));

% vector from base vertex to twa motor attachment point
l1_hat = (m_in_w(:,1) - b_in_w(:,1)) ./ norm(m_in_w(:,1) - b_in_w(:,1));
l2_hat = (m_in_w(:,2) - b_in_w(:,2)) ./ norm(m_in_w(:,2) - b_in_w(:,2));
l3_hat = (m_in_w(:,3) - b_in_w(:,3)) ./ norm(m_in_w(:,3) - b_in_w(:,3));

% distance from micro actuator attachmnet point (m_i) to flexure rotation
%center (f_i)
a1 = norm(m_in_w(:,1) - f_in_w(:,1));
a2 = norm(m_in_w(:,2) - f_in_w(:,2));
a3 = norm(m_in_w(:,3) - f_in_w(:,3));

% distance from flexure rotation center (f_i) to base vertex
c1 = norm(b_in_w(:,1)-f_in_w(:,1));
c2 = norm(b_in_w(:,2)-f_in_w(:,2));
c3 = norm(b_in_w(:,3)-f_in_w(:,3));

% term to paramterize angle between a_i and qimu, delta
h1 = (c1^2 - a1^2 - q1_mu^2)/(-2*a1*q1_mu);
h2 = (c2^2 - a2^2 - q2_mu^2)/(-2*a2*q2_mu);
h3 = (c3^2 - a3^2 - q3_mu^2)/(-2*a3*q3_mu);

% time derivatives
h1dot = (4*a1*q1_mu^2 + (c1^2 - a1^2 - q1_mu^2)*2*a1) / (4*a1^2*q1_mu^2);
h2dot = (4*a2*q2_mu^2 + (c2^2 - a2^2 - q2_mu^2)*2*a2) / (4*a2^2*q2_mu^2);
h3dot = (4*a3*q3_mu^2 + (c3^2 - a3^2 - q3_mu^2)*2*a3) / (4*a3^2*q3_mu^2);

e1 = n1hat' * l1_hat + q1_mu*h1dot/sqrt(1-h1^2) * n1hat' * cross(z0,l1_hat);
e2 = n2hat' * l2_hat + q2_mu*h2dot/sqrt(1-h2^2) * n2hat' * cross(z0,l2_hat);
e3 = n3hat' * l3_hat + q3_mu*h3dot/sqrt(1-h3^2) * n3hat' * cross(z0,l3_hat);

% micro motion instantaneous inverse kinematics jacobian
b_mu = [e1 0 0;...
    0 e2 0;...
    0 0 e3];

% macro motion instantaneous inverse kinematics jacobian
b_m = eye(3);

% combined macro-micro motion IIK jacobian
iik_jac = [b_m,b_mu];

% positional error
p_del = x_des - x_init;
w_del = norm(x_des(3,1) - x_init(3,1));

%
if do_quintic && norm(p_del) > 0
    if robot_moving
        t = tc - t_init;
        if t < tf
            eta = t/tf;
            a3 = 10*eta^3;
            a4 = -15*eta^4;
            a5 = 6*eta^5;
            
            % apply quintic polynomial on task space
            deltax = x_init + p_del*(a3+a4+a5);
            
            % redundancy weight matrix favoring velmex up to 50 microns
            % from destination
            if norm(x_cur - x_des) > 0.050
                w_mat = diag([ones(1,3),1e10*ones(1,3)]);
                macro_motion = 1;
            else
                w_mat = diag([1e10*ones(1,3),ones(1,3)]);
                macro_motion = 0;
            end
            
            % construct jacobian
            full_jac = (w_mat\iik_jac') / (iik_jac/w_mat*iik_jac') * idk_jac;
            
            % deltaq ~ J * deltax
            deltaq = full_jac * deltax;
            switch macro_motion
                case 1
                    % new desired q values
                    qdes(1:3,1) = deltaq(1:3,1);
                    qdes(4:6,1) = q_cur(4:6,1);
                case 0
                    qdes(4:6,1) = deltaq(4:6,1);
                    qdes(1:3,1) = q_cur(1:3,1);
            end
                    
        else
            robotmoving = 0;
        end
    else
        qdes = q_cur;
        tinit = tc;
        xinit = x_cur;
        robotmoving = 1;
    end
end

end