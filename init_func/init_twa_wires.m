% physically measured UNTWISTED twa lengths
hook = 4 + 2.5; %thickness and height of hook from cad
init_twa_len = [230.6; 232.98; 229.8] - hook; %[mm]

% experimentally calibrated wire radii
wire_rad = [0.17756944; 0.18128001; 0.17811843]; %[mm]

% physically measured starting distance of flexure with wire on hook
meas_flex_pos = [224.5; 226.7; 222.8];

% distance from rotation axis to start of TWA measured from CAD
twa_offset = 16.7; %[mm]

% starting between hook and twa flange, measured from CAD 
% needed in order to properly position each base vertex at their respective
% initial positions
start_len = (238.231 - twa_offset) * ones(3,1);

% difference between measured flexure distance and required started
% difference is the required compensatory stroke from the twa
start_stroke = meas_flex_pos - start_len;

% number of strands in a helix
num_strands = 2;

% helix radius is diameter of wire strand when using only two wires
helix_rad = wire_rad * num_strands;

% wire properties, relatively insignificant contribution to control command
E = 117e9;
A = pi * wire_rad.^2;

% helix stiffness modeled as springs in parallel
Ks = E.*A*num_strands;
F = 20; %[N]

wire_delta = F./Ks;

% qmicro_nom = zeros(3,1);
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;
% qmicro_nom(1,1) = norm(m_in_w(:,1) - b_in_w(:,1)) - twa_flange_offset;
