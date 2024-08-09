function [deltaq] = res_rate_cmd(x_des,des_ee_rot,x_cur,r_cur,eqeps,...
                        dt,p_in_m,b_in_w,f_in_w,m_in_w,ep_p)

deltaq = zeros(6,1);
z0 = [0 0 1]';

% moving platform vertex locations
p_in_w = x_cur*ones(1,3) + r_cur*p_in_m;

if norm(ep_p) > eqeps
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
    
    % the full manipulator jacobian with redundancy resolution weighting
    w_mat = diag([1,1,1,1e10,1e10,1e10]);
    full_jac = (w_mat\iik_jac') / (iik_jac/w_mat*iik_jac') * idk_jac;
    
    % positional error and direction
    ep_p = norm(x_des - x_cur);
    nhat = (x_des-x_cur)/ep_p;
    
    % orientational error and direction
    % this is always about the z-axis, shouldnt need to calculate me.
    r_des = [cos(des_ee_rot) -sin(des_ee_rot) 0;sin(des_ee_rot) cos(des_ee_rot) 0;0 0 1];
    r_ep = r_des * r_cur';

    theta_e = acos((trace(r_ep)-1)/2);

    me = (1/(2*sin(theta_e)))*[r_ep(3,2)-r_ep(2,3);r_ep(1,3)-r_ep(3,1);r_ep(2,1)-r_ep(1,2)];
    vmax = 1;
    wmax = 1;
    v = vmax * nhat;
    w = wmax * me;
    qdot = full_jac * [v(1:2);w(3)];

    deltaq = qdot * dt;

end