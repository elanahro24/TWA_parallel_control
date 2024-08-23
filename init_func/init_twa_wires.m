% physically measured UNTWISTED twa lengths
meas_twa_len = [229.37, 228.33, 227.27]'; %from hook to flange %[mm]

% starting length of TWAs, measured from CAD for each base vertex to be in
% their respective starting positions
start_len = 223.6858 * ones(3,1);

start_stroke = meas_twa_len - start_len;

wire_rad = 0.011 * 25.4 / 2; %[mm]

% number of strands in a helix
num_strands = 2;

% helix radius is diameter of wire strand when using only two wires
helix_rad = wire_rad * num_strands;

% wire properties, relatively insignificant contribution to control command
E = 60e9;
A = pi * wire_rad^2;

% helix stiffness modeled as springs in parallel
Ks = E*A*num_strands;
F = 20; %[N]

wire_delta = F/Ks;

% distance from rotation axis to start of TWA measured from CAD
twa_flange_offset = 16.7; %[mm]

% qmicro_nom = zeros(3,1);
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;
