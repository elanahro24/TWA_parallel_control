function pt=twa_parallelpt
pt = [];
pt(1).blockname = 'Analog Output';
pt(1).paramname = 'P1';
pt(1).class     = 'vector';
pt(1).nrows     = 1;
pt(1).ncols     = 6;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(getlenPT) = pt(1);

pt(2).blockname = 'Init';
pt(2).paramname = 'P1';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';

pt(3).blockname = 'Init';
pt(3).paramname = 'P2';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';

pt(4).blockname = 'Init';
pt(4).paramname = 'P3';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';

pt(5).blockname = 'Init';
pt(5).paramname = 'P4';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';

pt(6).blockname = 'Encoders/enc_reset1';
pt(6).paramname = 'Value';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';

pt(7).blockname = 'Encoders/enc_reset2';
pt(7).paramname = 'Value';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';

pt(8).blockname = 'Encoders/enc_reset3';
pt(8).paramname = 'Value';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';

pt(9).blockname = 'Encoders/enc_reset4';
pt(9).paramname = 'Value';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';

pt(10).blockname = 'Encoders/enc_reset5';
pt(10).paramname = 'Value';
pt(10).class     = 'scalar';
pt(10).nrows     = 1;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';

pt(11).blockname = 'Encoders/enc_reset6';
pt(11).paramname = 'Value';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';

pt(12).blockname = 'Encoders/Encoder Input';
pt(12).paramname = 'P1';
pt(12).class     = 'vector';
pt(12).nrows     = 1;
pt(12).ncols     = 6;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';

pt(13).blockname = 'Encoders/Encoder Input';
pt(13).paramname = 'P2';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';

pt(14).blockname = 'PID Controller/manual_current';
pt(14).paramname = 'Value';
pt(14).class     = 'vector';
pt(14).nrows     = 3;
pt(14).ncols     = 1;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';

pt(15).blockname = 'PID Controller/manual_current_mu';
pt(15).paramname = 'Value';
pt(15).class     = 'vector';
pt(15).nrows     = 3;
pt(15).ncols     = 1;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';

pt(16).blockname = 'PID Controller/pid_mode';
pt(16).paramname = 'Value';
pt(16).class     = 'scalar';
pt(16).nrows     = 1;
pt(16).ncols     = 1;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';

pt(17).blockname = 'PID Controller/reset_integ';
pt(17).paramname = 'Value';
pt(17).class     = 'scalar';
pt(17).nrows     = 1;
pt(17).ncols     = 1;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';

pt(18).blockname = 'PID Controller/Kd';
pt(18).paramname = 'Gain';
pt(18).class     = 'vector';
pt(18).nrows     = 3;
pt(18).ncols     = 1;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';

pt(19).blockname = 'PID Controller/Kd_mu';
pt(19).paramname = 'Gain';
pt(19).class     = 'vector';
pt(19).nrows     = 3;
pt(19).ncols     = 1;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';

pt(20).blockname = 'PID Controller/Ki';
pt(20).paramname = 'Gain';
pt(20).class     = 'vector';
pt(20).nrows     = 3;
pt(20).ncols     = 1;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';

pt(21).blockname = 'PID Controller/Ki_mu';
pt(21).paramname = 'Gain';
pt(21).class     = 'vector';
pt(21).nrows     = 3;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';

pt(22).blockname = 'PID Controller/Kp';
pt(22).paramname = 'Gain';
pt(22).class     = 'vector';
pt(22).nrows     = 3;
pt(22).ncols     = 1;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';

pt(23).blockname = 'PID Controller/Kp_mu';
pt(23).paramname = 'Gain';
pt(23).class     = 'vector';
pt(23).nrows     = 3;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';
pt(23).ndims     = '2';
pt(23).size      = '[]';

pt(24).blockname = 'PID Controller/Integrator';
pt(24).paramname = 'InitialCondition';
pt(24).class     = 'scalar';
pt(24).nrows     = 1;
pt(24).ncols     = 1;
pt(24).subsource = 'SS_DOUBLE';
pt(24).ndims     = '2';
pt(24).size      = '[]';

pt(25).blockname = 'PID Controller/Integrator1';
pt(25).paramname = 'InitialCondition';
pt(25).class     = 'scalar';
pt(25).nrows     = 1;
pt(25).ncols     = 1;
pt(25).subsource = 'SS_DOUBLE';
pt(25).ndims     = '2';
pt(25).size      = '[]';

pt(26).blockname = 'PID Controller/Saturation';
pt(26).paramname = 'UpperLimit';
pt(26).class     = 'vector';
pt(26).nrows     = 1;
pt(26).ncols     = 3;
pt(26).subsource = 'SS_DOUBLE';
pt(26).ndims     = '2';
pt(26).size      = '[]';

pt(27).blockname = 'PID Controller/Saturation';
pt(27).paramname = 'LowerLimit';
pt(27).class     = 'vector';
pt(27).nrows     = 1;
pt(27).ncols     = 3;
pt(27).subsource = 'SS_DOUBLE';
pt(27).ndims     = '2';
pt(27).size      = '[]';

pt(28).blockname = 'PID Controller/Saturation1';
pt(28).paramname = 'UpperLimit';
pt(28).class     = 'vector';
pt(28).nrows     = 1;
pt(28).ncols     = 3;
pt(28).subsource = 'SS_DOUBLE';
pt(28).ndims     = '2';
pt(28).size      = '[]';

pt(29).blockname = 'PID Controller/Saturation1';
pt(29).paramname = 'LowerLimit';
pt(29).class     = 'vector';
pt(29).nrows     = 1;
pt(29).ncols     = 3;
pt(29).subsource = 'SS_DOUBLE';
pt(29).ndims     = '2';
pt(29).size      = '[]';

pt(30).blockname = 'PID Controller/saturate_int';
pt(30).paramname = 'UpperLimit';
pt(30).class     = 'vector';
pt(30).nrows     = 1;
pt(30).ncols     = 3;
pt(30).subsource = 'SS_DOUBLE';
pt(30).ndims     = '2';
pt(30).size      = '[]';

pt(31).blockname = 'PID Controller/saturate_int';
pt(31).paramname = 'LowerLimit';
pt(31).class     = 'vector';
pt(31).nrows     = 1;
pt(31).ncols     = 3;
pt(31).subsource = 'SS_DOUBLE';
pt(31).ndims     = '2';
pt(31).size      = '[]';

pt(32).blockname = 'PID Controller/saturate_int1';
pt(32).paramname = 'UpperLimit';
pt(32).class     = 'vector';
pt(32).nrows     = 3;
pt(32).ncols     = 1;
pt(32).subsource = 'SS_DOUBLE';
pt(32).ndims     = '2';
pt(32).size      = '[]';

pt(33).blockname = 'PID Controller/saturate_int1';
pt(33).paramname = 'LowerLimit';
pt(33).class     = 'vector';
pt(33).nrows     = 3;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';
pt(33).ndims     = '2';
pt(33).size      = '[]';

pt(34).blockname = 'Quintic Poly/quintic_enable';
pt(34).paramname = 'Value';
pt(34).class     = 'scalar';
pt(34).nrows     = 1;
pt(34).ncols     = 1;
pt(34).subsource = 'SS_DOUBLE';
pt(34).ndims     = '2';
pt(34).size      = '[]';

pt(35).blockname = 'Quintic Poly/tf';
pt(35).paramname = 'Value';
pt(35).class     = 'scalar';
pt(35).nrows     = 1;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';
pt(35).ndims     = '2';
pt(35).size      = '[]';

pt(36).blockname = 'Quintic Poly/Unit Delay';
pt(36).paramname = 'X0';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';
pt(36).ndims     = '2';
pt(36).size      = '[]';

pt(37).blockname = 'Quintic Poly/Unit Delay1';
pt(37).paramname = 'X0';
pt(37).class     = 'scalar';
pt(37).nrows     = 1;
pt(37).ncols     = 1;
pt(37).subsource = 'SS_DOUBLE';
pt(37).ndims     = '2';
pt(37).size      = '[]';

pt(38).blockname = 'Quintic Poly/Unit Delay2';
pt(38).paramname = 'X0';
pt(38).class     = 'vector';
pt(38).nrows     = 6;
pt(38).ncols     = 1;
pt(38).subsource = 'SS_DOUBLE';
pt(38).ndims     = '2';
pt(38).size      = '[]';

pt(39).blockname = 'control_mode/mode';
pt(39).paramname = 'Value';
pt(39).class     = 'scalar';
pt(39).nrows     = 1;
pt(39).ncols     = 1;
pt(39).subsource = 'SS_DOUBLE';
pt(39).ndims     = '2';
pt(39).size      = '[]';

pt(40).blockname = 'control_mode/q_des_usr';
pt(40).paramname = 'Value';
pt(40).class     = 'vector';
pt(40).nrows     = 6;
pt(40).ncols     = 1;
pt(40).subsource = 'SS_DOUBLE';
pt(40).ndims     = '2';
pt(40).size      = '[]';

pt(41).blockname = 'control_mode/Unit Delay1';
pt(41).paramname = 'X0';
pt(41).class     = 'vector';
pt(41).nrows     = 6;
pt(41).ncols     = 1;
pt(41).subsource = 'SS_DOUBLE';
pt(41).ndims     = '2';
pt(41).size      = '[]';

pt(42).blockname = 'Encoders/Counts To Turns1/enc_res';
pt(42).paramname = 'Gain';
pt(42).class     = 'scalar';
pt(42).nrows     = 1;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';
pt(42).ndims     = '2';
pt(42).size      = '[]';

pt(43).blockname = 'Encoders/Counts To Turns1/gear_ratio';
pt(43).paramname = 'Gain';
pt(43).class     = 'scalar';
pt(43).nrows     = 1;
pt(43).ncols     = 1;
pt(43).subsource = 'SS_DOUBLE';
pt(43).ndims     = '2';
pt(43).size      = '[]';

pt(44).blockname = 'Encoders/Counts To Turns1/velmex_pitch';
pt(44).paramname = 'Gain';
pt(44).class     = 'scalar';
pt(44).nrows     = 1;
pt(44).ncols     = 1;
pt(44).subsource = 'SS_DOUBLE';
pt(44).ndims     = '2';
pt(44).size      = '[]';

pt(45).blockname = 'Encoders/Counts To Turns2/enc_res';
pt(45).paramname = 'Gain';
pt(45).class     = 'scalar';
pt(45).nrows     = 1;
pt(45).ncols     = 1;
pt(45).subsource = 'SS_DOUBLE';
pt(45).ndims     = '2';
pt(45).size      = '[]';

pt(46).blockname = 'Encoders/Counts To Turns2/gear_ratio';
pt(46).paramname = 'Gain';
pt(46).class     = 'scalar';
pt(46).nrows     = 1;
pt(46).ncols     = 1;
pt(46).subsource = 'SS_DOUBLE';
pt(46).ndims     = '2';
pt(46).size      = '[]';

pt(47).blockname = 'Encoders/Counts To Turns2/velmex_pitch';
pt(47).paramname = 'Gain';
pt(47).class     = 'scalar';
pt(47).nrows     = 1;
pt(47).ncols     = 1;
pt(47).subsource = 'SS_DOUBLE';
pt(47).ndims     = '2';
pt(47).size      = '[]';

pt(48).blockname = 'Encoders/Counts To Turns3/enc_res';
pt(48).paramname = 'Gain';
pt(48).class     = 'scalar';
pt(48).nrows     = 1;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';
pt(48).ndims     = '2';
pt(48).size      = '[]';

pt(49).blockname = 'Encoders/Counts To Turns3/gear_ratio';
pt(49).paramname = 'Gain';
pt(49).class     = 'scalar';
pt(49).nrows     = 1;
pt(49).ncols     = 1;
pt(49).subsource = 'SS_DOUBLE';
pt(49).ndims     = '2';
pt(49).size      = '[]';

pt(50).blockname = 'Encoders/Counts To Turns3/velmex_pitch';
pt(50).paramname = 'Gain';
pt(50).class     = 'scalar';
pt(50).nrows     = 1;
pt(50).ncols     = 1;
pt(50).subsource = 'SS_DOUBLE';
pt(50).ndims     = '2';
pt(50).size      = '[]';

pt(51).blockname = 'Encoders/Counts To Turns4/helix_rad';
pt(51).paramname = 'Value';
pt(51).class     = 'scalar';
pt(51).nrows     = 1;
pt(51).ncols     = 1;
pt(51).subsource = 'SS_DOUBLE';
pt(51).ndims     = '2';
pt(51).size      = '[]';

pt(52).blockname = 'Encoders/Counts To Turns4/twa_len';
pt(52).paramname = 'Value';
pt(52).class     = 'vector';
pt(52).nrows     = 3;
pt(52).ncols     = 1;
pt(52).subsource = 'SS_DOUBLE';
pt(52).ndims     = '2';
pt(52).size      = '[]';

pt(53).blockname = 'Encoders/Counts To Turns4/wire_delta';
pt(53).paramname = 'Value';
pt(53).class     = 'scalar';
pt(53).nrows     = 1;
pt(53).ncols     = 1;
pt(53).subsource = 'SS_DOUBLE';
pt(53).ndims     = '2';
pt(53).size      = '[]';

pt(54).blockname = 'Encoders/Counts To Turns4/enc_res';
pt(54).paramname = 'Gain';
pt(54).class     = 'scalar';
pt(54).nrows     = 1;
pt(54).ncols     = 1;
pt(54).subsource = 'SS_DOUBLE';
pt(54).ndims     = '2';
pt(54).size      = '[]';

pt(55).blockname = 'Encoders/Counts To Turns4/gear_ratio';
pt(55).paramname = 'Gain';
pt(55).class     = 'scalar';
pt(55).nrows     = 1;
pt(55).ncols     = 1;
pt(55).subsource = 'SS_DOUBLE';
pt(55).ndims     = '2';
pt(55).size      = '[]';

pt(56).blockname = 'Encoders/Counts To Turns5/helix_rad';
pt(56).paramname = 'Value';
pt(56).class     = 'scalar';
pt(56).nrows     = 1;
pt(56).ncols     = 1;
pt(56).subsource = 'SS_DOUBLE';
pt(56).ndims     = '2';
pt(56).size      = '[]';

pt(57).blockname = 'Encoders/Counts To Turns5/twa_len';
pt(57).paramname = 'Value';
pt(57).class     = 'vector';
pt(57).nrows     = 3;
pt(57).ncols     = 1;
pt(57).subsource = 'SS_DOUBLE';
pt(57).ndims     = '2';
pt(57).size      = '[]';

pt(58).blockname = 'Encoders/Counts To Turns5/wire_delta';
pt(58).paramname = 'Value';
pt(58).class     = 'scalar';
pt(58).nrows     = 1;
pt(58).ncols     = 1;
pt(58).subsource = 'SS_DOUBLE';
pt(58).ndims     = '2';
pt(58).size      = '[]';

pt(59).blockname = 'Encoders/Counts To Turns5/enc_res';
pt(59).paramname = 'Gain';
pt(59).class     = 'scalar';
pt(59).nrows     = 1;
pt(59).ncols     = 1;
pt(59).subsource = 'SS_DOUBLE';
pt(59).ndims     = '2';
pt(59).size      = '[]';

pt(60).blockname = 'Encoders/Counts To Turns5/gear_ratio';
pt(60).paramname = 'Gain';
pt(60).class     = 'scalar';
pt(60).nrows     = 1;
pt(60).ncols     = 1;
pt(60).subsource = 'SS_DOUBLE';
pt(60).ndims     = '2';
pt(60).size      = '[]';

pt(61).blockname = 'Encoders/Counts To Turns6/helix_rad';
pt(61).paramname = 'Value';
pt(61).class     = 'scalar';
pt(61).nrows     = 1;
pt(61).ncols     = 1;
pt(61).subsource = 'SS_DOUBLE';
pt(61).ndims     = '2';
pt(61).size      = '[]';

pt(62).blockname = 'Encoders/Counts To Turns6/twa_len';
pt(62).paramname = 'Value';
pt(62).class     = 'vector';
pt(62).nrows     = 3;
pt(62).ncols     = 1;
pt(62).subsource = 'SS_DOUBLE';
pt(62).ndims     = '2';
pt(62).size      = '[]';

pt(63).blockname = 'Encoders/Counts To Turns6/wire_delta';
pt(63).paramname = 'Value';
pt(63).class     = 'scalar';
pt(63).nrows     = 1;
pt(63).ncols     = 1;
pt(63).subsource = 'SS_DOUBLE';
pt(63).ndims     = '2';
pt(63).size      = '[]';

pt(64).blockname = 'Encoders/Counts To Turns6/enc_res';
pt(64).paramname = 'Gain';
pt(64).class     = 'scalar';
pt(64).nrows     = 1;
pt(64).ncols     = 1;
pt(64).subsource = 'SS_DOUBLE';
pt(64).ndims     = '2';
pt(64).size      = '[]';

pt(65).blockname = 'Encoders/Counts To Turns6/gear_ratio';
pt(65).paramname = 'Gain';
pt(65).class     = 'scalar';
pt(65).nrows     = 1;
pt(65).ncols     = 1;
pt(65).subsource = 'SS_DOUBLE';
pt(65).ndims     = '2';
pt(65).size      = '[]';

pt(66).blockname = 'PID Controller/Discrete Derivative/UD';
pt(66).paramname = 'X0';
pt(66).class     = 'scalar';
pt(66).nrows     = 1;
pt(66).ncols     = 1;
pt(66).subsource = 'SS_DOUBLE';
pt(66).ndims     = '2';
pt(66).size      = '[]';

pt(67).blockname = 'PID Controller/Discrete Derivative/TSamp';
pt(67).paramname = 'WtEt';
pt(67).class     = 'scalar';
pt(67).nrows     = 1;
pt(67).ncols     = 1;
pt(67).subsource = 'SS_DOUBLE';
pt(67).ndims     = '2';
pt(67).size      = '[]';

pt(68).blockname = 'PID Controller/Discrete Derivative1/UD';
pt(68).paramname = 'X0';
pt(68).class     = 'scalar';
pt(68).nrows     = 1;
pt(68).ncols     = 1;
pt(68).subsource = 'SS_DOUBLE';
pt(68).ndims     = '2';
pt(68).size      = '[]';

pt(69).blockname = 'PID Controller/Discrete Derivative1/TSamp';
pt(69).paramname = 'WtEt';
pt(69).class     = 'scalar';
pt(69).nrows     = 1;
pt(69).ncols     = 1;
pt(69).subsource = 'SS_DOUBLE';
pt(69).ndims     = '2';
pt(69).size      = '[]';

pt(70).blockname = 'Quintic Poly/N-Sample Switch/N-Sample Enable';
pt(70).paramname = 'TARGETCNT';
pt(70).class     = 'scalar';
pt(70).nrows     = 1;
pt(70).ncols     = 1;
pt(70).subsource = 'SS_UINT32';
pt(70).ndims     = '2';
pt(70).size      = '[]';

pt(71).blockname = 'Quintic Poly/N-Sample Switch/N-Sample Enable';
pt(71).paramname = 'ACTLEVEL';
pt(71).class     = 'scalar';
pt(71).nrows     = 1;
pt(71).ncols     = 1;
pt(71).subsource = 'SS_UINT32';
pt(71).ndims     = '2';
pt(71).size      = '[]';

pt(72).blockname = 'Scopes/Fir Filter/vel_filter_coeffs';
pt(72).paramname = 'Value';
pt(72).class     = 'vector';
pt(72).nrows     = 2;
pt(72).ncols     = 1;
pt(72).subsource = 'SS_DOUBLE';
pt(72).ndims     = '2';
pt(72).size      = '[]';

pt(73).blockname = 'Scopes/Fir Filter/Gain';
pt(73).paramname = 'Gain';
pt(73).class     = 'scalar';
pt(73).nrows     = 1;
pt(73).ncols     = 1;
pt(73).subsource = 'SS_DOUBLE';
pt(73).ndims     = '2';
pt(73).size      = '[]';

pt(74).blockname = 'Scopes/Fir Filter/Discrete FIR Filter';
pt(74).paramname = 'IC';
pt(74).class     = 'scalar';
pt(74).nrows     = 1;
pt(74).ncols     = 1;
pt(74).subsource = 'SS_DOUBLE';
pt(74).ndims     = '2';
pt(74).size      = '[]';

pt(75).blockname = 'control_mode/task_space/b_in_w';
pt(75).paramname = 'Value';
pt(75).class     = 'col-mat';
pt(75).nrows     = 3;
pt(75).ncols     = 3;
pt(75).subsource = 'SS_DOUBLE';
pt(75).ndims     = '2';
pt(75).size      = '[]';

pt(76).blockname = 'control_mode/task_space/dt';
pt(76).paramname = 'Value';
pt(76).class     = 'scalar';
pt(76).nrows     = 1;
pt(76).ncols     = 1;
pt(76).subsource = 'SS_DOUBLE';
pt(76).ndims     = '2';
pt(76).size      = '[]';

pt(77).blockname = 'control_mode/task_space/ee_rot_des';
pt(77).paramname = 'Value';
pt(77).class     = 'scalar';
pt(77).nrows     = 1;
pt(77).ncols     = 1;
pt(77).subsource = 'SS_DOUBLE';
pt(77).ndims     = '2';
pt(77).size      = '[]';

pt(78).blockname = 'control_mode/task_space/f_in_w';
pt(78).paramname = 'Value';
pt(78).class     = 'col-mat';
pt(78).nrows     = 3;
pt(78).ncols     = 3;
pt(78).subsource = 'SS_DOUBLE';
pt(78).ndims     = '2';
pt(78).size      = '[]';

pt(79).blockname = 'control_mode/task_space/m_in_w';
pt(79).paramname = 'Value';
pt(79).class     = 'col-mat';
pt(79).nrows     = 3;
pt(79).ncols     = 3;
pt(79).subsource = 'SS_DOUBLE';
pt(79).ndims     = '2';
pt(79).size      = '[]';

pt(80).blockname = 'control_mode/task_space/mode';
pt(80).paramname = 'Value';
pt(80).class     = 'scalar';
pt(80).nrows     = 1;
pt(80).ncols     = 1;
pt(80).subsource = 'SS_DOUBLE';
pt(80).ndims     = '2';
pt(80).size      = '[]';

pt(81).blockname = 'control_mode/task_space/p_in_m';
pt(81).paramname = 'Value';
pt(81).class     = 'col-mat';
pt(81).nrows     = 3;
pt(81).ncols     = 3;
pt(81).subsource = 'SS_DOUBLE';
pt(81).ndims     = '2';
pt(81).size      = '[]';

pt(82).blockname = 'control_mode/task_space/qmacro_nom';
pt(82).paramname = 'Value';
pt(82).class     = 'col-mat';
pt(82).nrows     = 3;
pt(82).ncols     = 3;
pt(82).subsource = 'SS_DOUBLE';
pt(82).ndims     = '2';
pt(82).size      = '[]';

pt(83).blockname = 'control_mode/task_space/qmacro_nom1';
pt(83).paramname = 'Value';
pt(83).class     = 'vector';
pt(83).nrows     = 3;
pt(83).ncols     = 1;
pt(83).subsource = 'SS_DOUBLE';
pt(83).ndims     = '2';
pt(83).size      = '[]';

pt(84).blockname = 'control_mode/task_space/res_rate_param';
pt(84).paramname = 'Value';
pt(84).class     = 'col-mat';
pt(84).nrows     = 9;
pt(84).ncols     = 2;
pt(84).subsource = 'SS_DOUBLE';
pt(84).ndims     = '2';
pt(84).size      = '[]';

pt(85).blockname = 'control_mode/task_space/t_in_w';
pt(85).paramname = 'Value';
pt(85).class     = 'col-mat';
pt(85).nrows     = 3;
pt(85).ncols     = 3;
pt(85).subsource = 'SS_DOUBLE';
pt(85).ndims     = '2';
pt(85).size      = '[]';

pt(86).blockname = 'control_mode/task_space/twa_flange_offset';
pt(86).paramname = 'Value';
pt(86).class     = 'scalar';
pt(86).nrows     = 1;
pt(86).ncols     = 1;
pt(86).subsource = 'SS_DOUBLE';
pt(86).ndims     = '2';
pt(86).size      = '[]';

pt(87).blockname = 'control_mode/task_space/twa_gamma';
pt(87).paramname = 'Value';
pt(87).class     = 'scalar';
pt(87).nrows     = 1;
pt(87).ncols     = 1;
pt(87).subsource = 'SS_DOUBLE';
pt(87).ndims     = '2';
pt(87).size      = '[]';

pt(88).blockname = 'control_mode/task_space/use_twa';
pt(88).paramname = 'Value';
pt(88).class     = 'scalar';
pt(88).nrows     = 1;
pt(88).ncols     = 1;
pt(88).subsource = 'SS_DOUBLE';
pt(88).ndims     = '2';
pt(88).size      = '[]';

pt(89).blockname = 'control_mode/task_space/x_des';
pt(89).paramname = 'Value';
pt(89).class     = 'vector';
pt(89).nrows     = 3;
pt(89).ncols     = 1;
pt(89).subsource = 'SS_DOUBLE';
pt(89).ndims     = '2';
pt(89).size      = '[]';

pt(90).blockname = 'control_mode/task_space/Unit Delay1';
pt(90).paramname = 'X0';
pt(90).class     = 'vector';
pt(90).nrows     = 6;
pt(90).ncols     = 1;
pt(90).subsource = 'SS_DOUBLE';
pt(90).ndims     = '2';
pt(90).size      = '[]';

pt(91).blockname = 'control_mode/task_space/Unit Delay2';
pt(91).paramname = 'X0';
pt(91).class     = 'vector';
pt(91).nrows     = 6;
pt(91).ncols     = 1;
pt(91).subsource = 'SS_DOUBLE';
pt(91).ndims     = '2';
pt(91).size      = '[]';

pt(92).blockname = 'control_mode/task_space/Unit Delay3';
pt(92).paramname = 'X0';
pt(92).class     = 'scalar';
pt(92).nrows     = 1;
pt(92).ncols     = 1;
pt(92).subsource = 'SS_DOUBLE';
pt(92).ndims     = '2';
pt(92).size      = '[]';

pt(93).blockname = 'control_mode/task_space/Unit Delay4';
pt(93).paramname = 'X0';
pt(93).class     = 'vector';
pt(93).nrows     = 3;
pt(93).ncols     = 1;
pt(93).subsource = 'SS_DOUBLE';
pt(93).ndims     = '2';
pt(93).size      = '[]';

pt(94).blockname = 'control_mode/task_space/Unit Delay5';
pt(94).paramname = 'X0';
pt(94).class     = 'col-mat';
pt(94).nrows     = 3;
pt(94).ncols     = 3;
pt(94).subsource = 'SS_DOUBLE';
pt(94).ndims     = '2';
pt(94).size      = '[]';

pt(95).blockname = 'control_mode/task_space/Unit Delay7';
pt(95).paramname = 'X0';
pt(95).class     = 'vector';
pt(95).nrows     = 6;
pt(95).ncols     = 1;
pt(95).subsource = 'SS_DOUBLE';
pt(95).ndims     = '2';
pt(95).size      = '[]';

pt(96).blockname = 'Encoders/Derivative/Discrete Derivative/UD';
pt(96).paramname = 'X0';
pt(96).class     = 'scalar';
pt(96).nrows     = 1;
pt(96).ncols     = 1;
pt(96).subsource = 'SS_DOUBLE';
pt(96).ndims     = '2';
pt(96).size      = '[]';

pt(97).blockname = 'Encoders/Derivative/Discrete Derivative/TSamp';
pt(97).paramname = 'WtEt';
pt(97).class     = 'scalar';
pt(97).nrows     = 1;
pt(97).ncols     = 1;
pt(97).subsource = 'SS_DOUBLE';
pt(97).ndims     = '2';
pt(97).size      = '[]';

pt(98).blockname = 'Encoders/Derivative/Fir Filter/vel_filter_coeffs';
pt(98).paramname = 'Value';
pt(98).class     = 'vector';
pt(98).nrows     = 2;
pt(98).ncols     = 1;
pt(98).subsource = 'SS_DOUBLE';
pt(98).ndims     = '2';
pt(98).size      = '[]';

pt(99).blockname = 'Encoders/Derivative/Fir Filter/Gain';
pt(99).paramname = 'Gain';
pt(99).class     = 'scalar';
pt(99).nrows     = 1;
pt(99).ncols     = 1;
pt(99).subsource = 'SS_DOUBLE';
pt(99).ndims     = '2';
pt(99).size      = '[]';

pt(100).blockname = 'Encoders/Derivative/Fir Filter/Discrete FIR Filter';
pt(100).paramname = 'IC';
pt(100).class     = 'scalar';
pt(100).nrows     = 1;
pt(100).ncols     = 1;
pt(100).subsource = 'SS_DOUBLE';
pt(100).ndims     = '2';
pt(100).size      = '[]';

pt(101).blockname = 'control_mode/detect change/Detect Change/Delay Input1';
pt(101).paramname = 'X0';
pt(101).class     = 'vector';
pt(101).nrows     = 6;
pt(101).ncols     = 1;
pt(101).subsource = 'SS_DOUBLE';
pt(101).ndims     = '2';
pt(101).size      = '[]';

function len = getlenPT
len = 101;

