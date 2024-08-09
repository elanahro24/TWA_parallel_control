% physically measured UNTWISTED twa lengths
meas_twa_len = [229.37 228.33 227.27]; %from hook to flange %[mm]

wire_rad = 0.011 * 25.4 / 2; %[mm]

% helix radius is diameter of wire strand when using only two wires
helix_rad = wire_rad * 2;

% wire properties, relatively insignificant contribution to control command
E = 60e9;
A = pi * wire_rad^2;
Ks = E*A;
F = 20; %[N]

wire_delta = F/Ks;

% distance from rotation axis to start of TWA measured from CAD
twa_flange_offset = 16.7; %[mm]

% qmicro_nom = zeros(3,1);
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;