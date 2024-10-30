% Wire properties for the wires used in twisted wires

% The initial length of the twisted wires. There are two values that follow
% the first is the wire measured using calipers and the second is the
% distance between the outer surface of the flexure hook and the flange on
% the twa motor shaft. Since there is thickness to the hook and slight
% stressing of the wires when they are attached to the flexure hook, we
% physically measure the distance instead of estimating. We use the
% physically measured distance between the twa motor flange and flexure
% hook as the initial length of the TWA. 
% The difference between the
% estimated length and measured length is small though.
% physically measured UNTWISTED twa lengths
hook = 4 + 2.5; %thickness and height of hook from cad
init_twa_len = [230.6; 232.98; 229.8] - hook; %[mm]

% physically measured starting distance of flexure with wire on hook
meas_flex_pos = [224.5; 226.7; 222.8]; % to be explicit and clear
L0 = meas_flex_pos; % for simplicity throughout

% experimentally calibrated wire radii
wire_rad = [0.17756944; 0.18128001; 0.17811843]; %[mm]

% distance from rotation axis to start of TWA measured from CAD
twa_offset = 16.7; %[mm]

% starting between hook and twa flange, measured from CAD 
% needed in order to properly position each base vertex at their respective
% initial positions
start_len = (238.231 - twa_offset) * ones(3,1);

% difference between measured flexure distance and required started
% difference is the required compensatory stroke from the twa
start_stroke = L0 - start_len;

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

% monomial constants for wire radius, two monomial bases describe twa
% behavior, one for contraction and one for extension. The first two
% entries of each vector are the constants for the contraction polynomial
% and the second two are for the extension polynomial
% r1c = [0.191945366814433; -1.98640114374183e-07];
% r2c = [0.191945366814433; -1.98640114374183e-07];
% r3c = [0.207008490755032; -3.52424846618225e-07];

r1c = [0.191978042483586; -1.99247143439634e-07; 0.185823702595638; -1.22273736550038e-07];
r2c = [0.189872168129352; -1.57355736875015e-07; 0.189875454692156; -1.49503235873576e-07];
r3c = [0.206683669242695; -3.46329242382291e-07; 0.188590200865444; -1.27782286957162e-07];
rad_coeff = [r1c, r2c, r3c];

%chebyshev polynomial constants and theta max from 1mm diameter circle
c1 = [1.306704518015341, -0.601528549357469, 0.322874731862283, -0.103497450387190, 237.943749551229];
c2 = [1.107327277987840, -0.097518276153950, -0.004008059978344, -0.001627727399626, 290.733357027217];
c3 = [-0.644776678459277, 2.372841624831809, -1.056732366794198, 0.244700522877303, 179.720233498613];
constants = [c1',c2',c3'];
