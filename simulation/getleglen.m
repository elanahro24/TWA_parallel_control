function [des_macro_len,micro_len_out, x_cur,p_in_w, b_in_w]  = getleglen(x_des,...
    ee_rot,p_in_m,b_in_w,m_in_w,f_in_w,t_in_w,twa_gamma,micro_len,x_prev)
% This function solves for the vertex positions of the base and moving
% platform for a given desired end effector position.
% With vertex positions known, leg lengths can be solved for.

% initialization
conv_rad = 0.5; %[mm]
x_cur = x_des;

micro_len_out = micro_len;
x_delta = abs(x_des - x_prev);

% initial twa wire length
init_twa_len = [225.8;226.3;224.5]; %[mm]

% rotation matrix of moving frame about z-xis
rot_m2w = [cos(ee_rot) -sin(ee_rot) 0; sin(ee_rot) cos(ee_rot) 0; 0 0 1];

p_in_w = x_des*ones(1,3) + rot_m2w*p_in_m;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%        Macro Actuator        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

vertex_dist = p_in_w - b_in_w;

des_macro_len = zeros(3,1);
des_macro_len(1,1) = norm(vertex_dist(:,1));
des_macro_len(2,1) = norm(vertex_dist(:,2));
des_macro_len(3,1) = norm(vertex_dist(:,3));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       Micro Actuator         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if x_delta(1,1) < conv_rad || x_delta(2,1) < conv_rad
    % initial flexure bend
    beta_cmd = 0;
    
    % loop through each vertex
    for i = 1:3
        post_flex_angle = zeros(1,2);
        beta = zeros(1,2);
        
        % vector from flexure center to moving platform vertex
        rho_vec = p_in_w(:,i) - f_in_w(:,i);
        
        % distance between flexure and moving platform verteces
        rho = norm(rho_vec);
        
        % vector from flexure center to base vertex pre flexure rotation
        eta_vec = b_in_w(:,i) - f_in_w(:,i);
        
        % flexure angle at the start (e.g. 5 deg preload) in world frame
        pre_flex_angle = atan2(eta_vec(2,1),eta_vec(1,1));
        
        % magnitude of flexure swing-arm radius from flexure to base vertex
        eta = norm(eta_vec);
        
        % angle from world horizontal to the vector from the flexure
        % center to the platform vertex
        flexure_frame_rot_angle = atan2(rho_vec(2,1),rho_vec(1,1));
        
        % rotation matrix from flexure frame to world
        n = [0;0;1] ./ norm([0;0;1]);
        rot_f_2_w = expm(flexure_frame_rot_angle*[0 -n(3) n(2);n(3) 0 -n(1);n(2) n(1) 0]);
        
        % condition for acos solvability
        check = (des_macro_len(i,1)^2-rho^2-eta^2)/(-2*rho*eta);
        
        if check >= -1 && check <= 1
            % calculate angle between mf and fb vectors, lambda, with
            % law of cosines
            lambda = acos(check);
            
            % calculate flexed base vertex position for both elbow up
            % and down configurations in the flexure frame
            b_prime_in_f_dwn = eta*[cos(-lambda);sin(-lambda);0];
            b_prime_in_f_up = eta*[cos(lambda);sin(lambda);0];
            
            % vector from flexure center point to new base vertex location
            % rotated to world frame
            eta_prime_vec_dwn = rot_f_2_w*b_prime_in_f_dwn;
            eta_prime_vec_up = rot_f_2_w*b_prime_in_f_up;
            
            post_flex_angle(1,1) = atan2(eta_prime_vec_dwn(2,1),eta_prime_vec_dwn(1,1));
            post_flex_angle(1,2) = atan2(eta_prime_vec_up(2,1),eta_prime_vec_up(1,1));
            
            % determine if flex angle is within mechanical range
            for j = 1:2
                if pre_flex_angle < 0 && post_flex_angle(1,j) < 0
                    beta(1,j) = (-1*pre_flex_angle)-(-1*post_flex_angle(1,j));
                else
                    beta(1,j) = pre_flex_angle - post_flex_angle(1,j);
                end
                
                if beta(1,j) >= -pi/18 && beta(1,j) <= pi/18
                    beta_cmd = beta(1,j);
                end
            end
        end
        
        % initial angle prior to flexure bend
        a = norm(f_in_w(:,i) - m_in_w(:,i));
        b = norm(f_in_w(:,i) - b_in_w(:,i));
        c = norm(m_in_w(:,i) - b_in_w(:,i));
        %c = init_twa_len(i,1);
        
        alpha =  acos((c^2 - a^2 - b^2)/(-2*a*b));
        
        
        delta = alpha - beta_cmd;
        % distance between base vertex and twa motor position after flex
        c_prime = sqrt(a^2 + b^2 - 2*a*b*cos(delta));
        
        % required twa length to facilitate flexure bend
        d = norm(f_in_w(:,i) - t_in_w(:,i));
        
        micro_len_out(i,1) = sqrt(a^2 + d^2 - 2*a*d*cos(delta - twa_gamma));
        disp(['Vertex Num: ',num2str(i),' twa length = ',num2str(micro_len_out(i)),' Beta = ',num2str(beta_cmd*180/pi)])
    end
end