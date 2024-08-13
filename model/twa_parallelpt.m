function pt=twa_parallelpt
pt = [];
pt(1).blockname = 'cntrl_mode';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(getlenPT) = pt(1);

pt(2).blockname = 'do_homing';
pt(2).paramname = 'Value';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';

pt(3).blockname = 'q_des';
pt(3).paramname = 'Value';
pt(3).class     = 'vector';
pt(3).nrows     = 6;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';

pt(4).blockname = 'Analog Output';
pt(4).paramname = 'P1';
pt(4).class     = 'vector';
pt(4).nrows     = 1;
pt(4).ncols     = 6;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';

pt(5).blockname = 'Init';
pt(5).paramname = 'P1';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';

pt(6).blockname = 'Init';
pt(6).paramname = 'P2';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';

pt(7).blockname = 'Init';
pt(7).paramname = 'P3';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';

pt(8).blockname = 'Init';
pt(8).paramname = 'P4';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';

pt(9).blockname = 'Encoders/enc_reset1';
pt(9).paramname = 'Value';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';

pt(10).blockname = 'Encoders/enc_reset2';
pt(10).paramname = 'Value';
pt(10).class     = 'scalar';
pt(10).nrows     = 1;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';

pt(11).blockname = 'Encoders/enc_reset3';
pt(11).paramname = 'Value';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';

pt(12).blockname = 'Encoders/enc_reset4';
pt(12).paramname = 'Value';
pt(12).class     = 'scalar';
pt(12).nrows     = 1;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';

pt(13).blockname = 'Encoders/enc_reset5';
pt(13).paramname = 'Value';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';

pt(14).blockname = 'Encoders/enc_reset6';
pt(14).paramname = 'Value';
pt(14).class     = 'scalar';
pt(14).nrows     = 1;
pt(14).ncols     = 1;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';

pt(15).blockname = 'Encoders/Encoder Input';
pt(15).paramname = 'P1';
pt(15).class     = 'vector';
pt(15).nrows     = 1;
pt(15).ncols     = 6;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';

pt(16).blockname = 'Encoders/Encoder Input';
pt(16).paramname = 'P2';
pt(16).class     = 'scalar';
pt(16).nrows     = 1;
pt(16).ncols     = 1;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';

pt(17).blockname = 'Homing/b_in_w';
pt(17).paramname = 'Value';
pt(17).class     = 'col-mat';
pt(17).nrows     = 3;
pt(17).ncols     = 3;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';

pt(18).blockname = 'Homing/dt';
pt(18).paramname = 'Value';
pt(18).class     = 'scalar';
pt(18).nrows     = 1;
pt(18).ncols     = 1;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';

pt(19).blockname = 'Homing/eq_eps';
pt(19).paramname = 'Value';
pt(19).class     = 'scalar';
pt(19).nrows     = 1;
pt(19).ncols     = 1;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';

pt(20).blockname = 'Homing/f_in_w';
pt(20).paramname = 'Value';
pt(20).class     = 'col-mat';
pt(20).nrows     = 3;
pt(20).ncols     = 3;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';

pt(21).blockname = 'Homing/kp';
pt(21).paramname = 'Value';
pt(21).class     = 'scalar';
pt(21).nrows     = 1;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';

pt(22).blockname = 'Homing/m_in_w';
pt(22).paramname = 'Value';
pt(22).class     = 'col-mat';
pt(22).nrows     = 3;
pt(22).ncols     = 3;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';

pt(23).blockname = 'Homing/meas_macro_len';
pt(23).paramname = 'Value';
pt(23).class     = 'vector';
pt(23).nrows     = 3;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';
pt(23).ndims     = '2';
pt(23).size      = '[]';

pt(24).blockname = 'Homing/p_in_m';
pt(24).paramname = 'Value';
pt(24).class     = 'col-mat';
pt(24).nrows     = 3;
pt(24).ncols     = 3;
pt(24).subsource = 'SS_DOUBLE';
pt(24).ndims     = '2';
pt(24).size      = '[]';

pt(25).blockname = 'Homing/velmex_pitch';
pt(25).paramname = 'Value';
pt(25).class     = 'scalar';
pt(25).nrows     = 1;
pt(25).ncols     = 1;
pt(25).subsource = 'SS_DOUBLE';
pt(25).ndims     = '2';
pt(25).size      = '[]';

pt(26).blockname = 'Homing/Unit Delay1';
pt(26).paramname = 'X0';
pt(26).class     = 'vector';
pt(26).nrows     = 3;
pt(26).ncols     = 1;
pt(26).subsource = 'SS_DOUBLE';
pt(26).ndims     = '2';
pt(26).size      = '[]';

pt(27).blockname = 'Homing/Unit Delay2';
pt(27).paramname = 'X0';
pt(27).class     = 'col-mat';
pt(27).nrows     = 3;
pt(27).ncols     = 3;
pt(27).subsource = 'SS_DOUBLE';
pt(27).ndims     = '2';
pt(27).size      = '[]';

pt(28).blockname = 'Homing/Unit Delay3';
pt(28).paramname = 'X0';
pt(28).class     = 'vector';
pt(28).nrows     = 3;
pt(28).ncols     = 1;
pt(28).subsource = 'SS_DOUBLE';
pt(28).ndims     = '2';
pt(28).size      = '[]';

pt(29).blockname = 'Homing/Unit Delay4';
pt(29).paramname = 'X0';
pt(29).class     = 'vector';
pt(29).nrows     = 3;
pt(29).ncols     = 1;
pt(29).subsource = 'SS_DOUBLE';
pt(29).ndims     = '2';
pt(29).size      = '[]';

pt(30).blockname = 'PID Controller/manual_current';
pt(30).paramname = 'Value';
pt(30).class     = 'vector';
pt(30).nrows     = 6;
pt(30).ncols     = 1;
pt(30).subsource = 'SS_DOUBLE';
pt(30).ndims     = '2';
pt(30).size      = '[]';

pt(31).blockname = 'PID Controller/pid_mode';
pt(31).paramname = 'Value';
pt(31).class     = 'scalar';
pt(31).nrows     = 1;
pt(31).ncols     = 1;
pt(31).subsource = 'SS_DOUBLE';
pt(31).ndims     = '2';
pt(31).size      = '[]';

pt(32).blockname = 'PID Controller/reset_integrator';
pt(32).paramname = 'Value';
pt(32).class     = 'scalar';
pt(32).nrows     = 1;
pt(32).ncols     = 1;
pt(32).subsource = 'SS_DOUBLE';
pt(32).ndims     = '2';
pt(32).size      = '[]';

pt(33).blockname = 'PID Controller/Kd';
pt(33).paramname = 'Gain';
pt(33).class     = 'vector';
pt(33).nrows     = 6;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';
pt(33).ndims     = '2';
pt(33).size      = '[]';

pt(34).blockname = 'PID Controller/Ki';
pt(34).paramname = 'Gain';
pt(34).class     = 'vector';
pt(34).nrows     = 6;
pt(34).ncols     = 1;
pt(34).subsource = 'SS_DOUBLE';
pt(34).ndims     = '2';
pt(34).size      = '[]';

pt(35).blockname = 'PID Controller/Kp';
pt(35).paramname = 'Gain';
pt(35).class     = 'vector';
pt(35).nrows     = 6;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';
pt(35).ndims     = '2';
pt(35).size      = '[]';

pt(36).blockname = 'PID Controller/Integrator';
pt(36).paramname = 'InitialCondition';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';
pt(36).ndims     = '2';
pt(36).size      = '[]';

pt(37).blockname = 'PID Controller/Saturation';
pt(37).paramname = 'UpperLimit';
pt(37).class     = 'vector';
pt(37).nrows     = 1;
pt(37).ncols     = 6;
pt(37).subsource = 'SS_DOUBLE';
pt(37).ndims     = '2';
pt(37).size      = '[]';

pt(38).blockname = 'PID Controller/Saturation';
pt(38).paramname = 'LowerLimit';
pt(38).class     = 'vector';
pt(38).nrows     = 1;
pt(38).ncols     = 6;
pt(38).subsource = 'SS_DOUBLE';
pt(38).ndims     = '2';
pt(38).size      = '[]';

pt(39).blockname = 'PID Controller/saturate_int';
pt(39).paramname = 'UpperLimit';
pt(39).class     = 'vector';
pt(39).nrows     = 1;
pt(39).ncols     = 6;
pt(39).subsource = 'SS_DOUBLE';
pt(39).ndims     = '2';
pt(39).size      = '[]';

pt(40).blockname = 'PID Controller/saturate_int';
pt(40).paramname = 'LowerLimit';
pt(40).class     = 'vector';
pt(40).nrows     = 1;
pt(40).ncols     = 6;
pt(40).subsource = 'SS_DOUBLE';
pt(40).ndims     = '2';
pt(40).size      = '[]';

pt(41).blockname = 'Quintic Poly/quintic_enable';
pt(41).paramname = 'Value';
pt(41).class     = 'scalar';
pt(41).nrows     = 1;
pt(41).ncols     = 1;
pt(41).subsource = 'SS_DOUBLE';
pt(41).ndims     = '2';
pt(41).size      = '[]';

pt(42).blockname = 'Quintic Poly/tf';
pt(42).paramname = 'Value';
pt(42).class     = 'scalar';
pt(42).nrows     = 1;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';
pt(42).ndims     = '2';
pt(42).size      = '[]';

pt(43).blockname = 'Quintic Poly/Unit Delay';
pt(43).paramname = 'X0';
pt(43).class     = 'scalar';
pt(43).nrows     = 1;
pt(43).ncols     = 1;
pt(43).subsource = 'SS_DOUBLE';
pt(43).ndims     = '2';
pt(43).size      = '[]';

pt(44).blockname = 'Quintic Poly/Unit Delay1';
pt(44).paramname = 'X0';
pt(44).class     = 'scalar';
pt(44).nrows     = 1;
pt(44).ncols     = 1;
pt(44).subsource = 'SS_DOUBLE';
pt(44).ndims     = '2';
pt(44).size      = '[]';

pt(45).blockname = 'Quintic Poly/Unit Delay2';
pt(45).paramname = 'X0';
pt(45).class     = 'vector';
pt(45).nrows     = 6;
pt(45).ncols     = 1;
pt(45).subsource = 'SS_DOUBLE';
pt(45).ndims     = '2';
pt(45).size      = '[]';

pt(46).blockname = 'task_space/b_in_w';
pt(46).paramname = 'Value';
pt(46).class     = 'col-mat';
pt(46).nrows     = 3;
pt(46).ncols     = 3;
pt(46).subsource = 'SS_DOUBLE';
pt(46).ndims     = '2';
pt(46).size      = '[]';

pt(47).blockname = 'task_space/dt';
pt(47).paramname = 'Value';
pt(47).class     = 'scalar';
pt(47).nrows     = 1;
pt(47).ncols     = 1;
pt(47).subsource = 'SS_DOUBLE';
pt(47).ndims     = '2';
pt(47).size      = '[]';

pt(48).blockname = 'task_space/ee_rot_des';
pt(48).paramname = 'Value';
pt(48).class     = 'scalar';
pt(48).nrows     = 1;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';
pt(48).ndims     = '2';
pt(48).size      = '[]';

pt(49).blockname = 'task_space/f_in_w';
pt(49).paramname = 'Value';
pt(49).class     = 'col-mat';
pt(49).nrows     = 3;
pt(49).ncols     = 3;
pt(49).subsource = 'SS_DOUBLE';
pt(49).ndims     = '2';
pt(49).size      = '[]';

pt(50).blockname = 'task_space/m_in_w';
pt(50).paramname = 'Value';
pt(50).class     = 'col-mat';
pt(50).nrows     = 3;
pt(50).ncols     = 3;
pt(50).subsource = 'SS_DOUBLE';
pt(50).ndims     = '2';
pt(50).size      = '[]';

pt(51).blockname = 'task_space/p_in_m';
pt(51).paramname = 'Value';
pt(51).class     = 'col-mat';
pt(51).nrows     = 3;
pt(51).ncols     = 3;
pt(51).subsource = 'SS_DOUBLE';
pt(51).ndims     = '2';
pt(51).size      = '[]';

pt(52).blockname = 'task_space/t_in_w';
pt(52).paramname = 'Value';
pt(52).class     = 'col-mat';
pt(52).nrows     = 3;
pt(52).ncols     = 3;
pt(52).subsource = 'SS_DOUBLE';
pt(52).ndims     = '2';
pt(52).size      = '[]';

pt(53).blockname = 'task_space/twa_flange_offset';
pt(53).paramname = 'Value';
pt(53).class     = 'scalar';
pt(53).nrows     = 1;
pt(53).ncols     = 1;
pt(53).subsource = 'SS_DOUBLE';
pt(53).ndims     = '2';
pt(53).size      = '[]';

pt(54).blockname = 'task_space/twa_gamma';
pt(54).paramname = 'Value';
pt(54).class     = 'scalar';
pt(54).nrows     = 1;
pt(54).ncols     = 1;
pt(54).subsource = 'SS_DOUBLE';
pt(54).ndims     = '2';
pt(54).size      = '[]';

pt(55).blockname = 'task_space/use_twa';
pt(55).paramname = 'Value';
pt(55).class     = 'scalar';
pt(55).nrows     = 1;
pt(55).ncols     = 1;
pt(55).subsource = 'SS_DOUBLE';
pt(55).ndims     = '2';
pt(55).size      = '[]';

pt(56).blockname = 'task_space/x_des';
pt(56).paramname = 'Value';
pt(56).class     = 'vector';
pt(56).nrows     = 3;
pt(56).ncols     = 1;
pt(56).subsource = 'SS_DOUBLE';
pt(56).ndims     = '2';
pt(56).size      = '[]';

pt(57).blockname = 'task_space/Unit Delay1';
pt(57).paramname = 'X0';
pt(57).class     = 'vector';
pt(57).nrows     = 6;
pt(57).ncols     = 1;
pt(57).subsource = 'SS_DOUBLE';
pt(57).ndims     = '2';
pt(57).size      = '[]';

pt(58).blockname = 'task_space/Unit Delay3';
pt(58).paramname = 'X0';
pt(58).class     = 'scalar';
pt(58).nrows     = 1;
pt(58).ncols     = 1;
pt(58).subsource = 'SS_DOUBLE';
pt(58).ndims     = '2';
pt(58).size      = '[]';

pt(59).blockname = 'task_space/Unit Delay4';
pt(59).paramname = 'X0';
pt(59).class     = 'vector';
pt(59).nrows     = 3;
pt(59).ncols     = 1;
pt(59).subsource = 'SS_DOUBLE';
pt(59).ndims     = '2';
pt(59).size      = '[]';

pt(60).blockname = 'Encoders/Counts To Turns1/enc_res';
pt(60).paramname = 'Gain';
pt(60).class     = 'scalar';
pt(60).nrows     = 1;
pt(60).ncols     = 1;
pt(60).subsource = 'SS_DOUBLE';
pt(60).ndims     = '2';
pt(60).size      = '[]';

pt(61).blockname = 'Encoders/Counts To Turns1/gear_ratio';
pt(61).paramname = 'Gain';
pt(61).class     = 'scalar';
pt(61).nrows     = 1;
pt(61).ncols     = 1;
pt(61).subsource = 'SS_DOUBLE';
pt(61).ndims     = '2';
pt(61).size      = '[]';

pt(62).blockname = 'Encoders/Counts To Turns1/velmex_pitch';
pt(62).paramname = 'Gain';
pt(62).class     = 'scalar';
pt(62).nrows     = 1;
pt(62).ncols     = 1;
pt(62).subsource = 'SS_DOUBLE';
pt(62).ndims     = '2';
pt(62).size      = '[]';

pt(63).blockname = 'Encoders/Counts To Turns2/enc_res';
pt(63).paramname = 'Gain';
pt(63).class     = 'scalar';
pt(63).nrows     = 1;
pt(63).ncols     = 1;
pt(63).subsource = 'SS_DOUBLE';
pt(63).ndims     = '2';
pt(63).size      = '[]';

pt(64).blockname = 'Encoders/Counts To Turns2/gear_ratio';
pt(64).paramname = 'Gain';
pt(64).class     = 'scalar';
pt(64).nrows     = 1;
pt(64).ncols     = 1;
pt(64).subsource = 'SS_DOUBLE';
pt(64).ndims     = '2';
pt(64).size      = '[]';

pt(65).blockname = 'Encoders/Counts To Turns2/velmex_pitch';
pt(65).paramname = 'Gain';
pt(65).class     = 'scalar';
pt(65).nrows     = 1;
pt(65).ncols     = 1;
pt(65).subsource = 'SS_DOUBLE';
pt(65).ndims     = '2';
pt(65).size      = '[]';

pt(66).blockname = 'Encoders/Counts To Turns3/enc_res';
pt(66).paramname = 'Gain';
pt(66).class     = 'scalar';
pt(66).nrows     = 1;
pt(66).ncols     = 1;
pt(66).subsource = 'SS_DOUBLE';
pt(66).ndims     = '2';
pt(66).size      = '[]';

pt(67).blockname = 'Encoders/Counts To Turns3/gear_ratio';
pt(67).paramname = 'Gain';
pt(67).class     = 'scalar';
pt(67).nrows     = 1;
pt(67).ncols     = 1;
pt(67).subsource = 'SS_DOUBLE';
pt(67).ndims     = '2';
pt(67).size      = '[]';

pt(68).blockname = 'Encoders/Counts To Turns3/velmex_pitch';
pt(68).paramname = 'Gain';
pt(68).class     = 'scalar';
pt(68).nrows     = 1;
pt(68).ncols     = 1;
pt(68).subsource = 'SS_DOUBLE';
pt(68).ndims     = '2';
pt(68).size      = '[]';

pt(69).blockname = 'Encoders/Counts To Turns4/enc_res';
pt(69).paramname = 'Gain';
pt(69).class     = 'scalar';
pt(69).nrows     = 1;
pt(69).ncols     = 1;
pt(69).subsource = 'SS_DOUBLE';
pt(69).ndims     = '2';
pt(69).size      = '[]';

pt(70).blockname = 'Encoders/Counts To Turns4/gear_ratio';
pt(70).paramname = 'Gain';
pt(70).class     = 'scalar';
pt(70).nrows     = 1;
pt(70).ncols     = 1;
pt(70).subsource = 'SS_DOUBLE';
pt(70).ndims     = '2';
pt(70).size      = '[]';

pt(71).blockname = 'Encoders/Counts To Turns5/enc_res';
pt(71).paramname = 'Gain';
pt(71).class     = 'scalar';
pt(71).nrows     = 1;
pt(71).ncols     = 1;
pt(71).subsource = 'SS_DOUBLE';
pt(71).ndims     = '2';
pt(71).size      = '[]';

pt(72).blockname = 'Encoders/Counts To Turns5/gear_ratio';
pt(72).paramname = 'Gain';
pt(72).class     = 'scalar';
pt(72).nrows     = 1;
pt(72).ncols     = 1;
pt(72).subsource = 'SS_DOUBLE';
pt(72).ndims     = '2';
pt(72).size      = '[]';

pt(73).blockname = 'Encoders/Counts To Turns6/enc_res';
pt(73).paramname = 'Gain';
pt(73).class     = 'scalar';
pt(73).nrows     = 1;
pt(73).ncols     = 1;
pt(73).subsource = 'SS_DOUBLE';
pt(73).ndims     = '2';
pt(73).size      = '[]';

pt(74).blockname = 'Encoders/Counts To Turns6/gear_ratio';
pt(74).paramname = 'Gain';
pt(74).class     = 'scalar';
pt(74).nrows     = 1;
pt(74).ncols     = 1;
pt(74).subsource = 'SS_DOUBLE';
pt(74).ndims     = '2';
pt(74).size      = '[]';

pt(75).blockname = 'PID Controller/Discrete Derivative/UD';
pt(75).paramname = 'X0';
pt(75).class     = 'scalar';
pt(75).nrows     = 1;
pt(75).ncols     = 1;
pt(75).subsource = 'SS_DOUBLE';
pt(75).ndims     = '2';
pt(75).size      = '[]';

pt(76).blockname = 'PID Controller/Discrete Derivative/TSamp';
pt(76).paramname = 'WtEt';
pt(76).class     = 'scalar';
pt(76).nrows     = 1;
pt(76).ncols     = 1;
pt(76).subsource = 'SS_DOUBLE';
pt(76).ndims     = '2';
pt(76).size      = '[]';

pt(77).blockname = 'Quintic Poly/N-Sample Switch/N-Sample Enable';
pt(77).paramname = 'TARGETCNT';
pt(77).class     = 'scalar';
pt(77).nrows     = 1;
pt(77).ncols     = 1;
pt(77).subsource = 'SS_UINT32';
pt(77).ndims     = '2';
pt(77).size      = '[]';

pt(78).blockname = 'Quintic Poly/N-Sample Switch/N-Sample Enable';
pt(78).paramname = 'ACTLEVEL';
pt(78).class     = 'scalar';
pt(78).nrows     = 1;
pt(78).ncols     = 1;
pt(78).subsource = 'SS_UINT32';
pt(78).ndims     = '2';
pt(78).size      = '[]';

pt(79).blockname = 'Scopes/Fir Filter/vel_filter_coeffs';
pt(79).paramname = 'Value';
pt(79).class     = 'vector';
pt(79).nrows     = 2;
pt(79).ncols     = 1;
pt(79).subsource = 'SS_DOUBLE';
pt(79).ndims     = '2';
pt(79).size      = '[]';

pt(80).blockname = 'Scopes/Fir Filter/Gain';
pt(80).paramname = 'Gain';
pt(80).class     = 'scalar';
pt(80).nrows     = 1;
pt(80).ncols     = 1;
pt(80).subsource = 'SS_DOUBLE';
pt(80).ndims     = '2';
pt(80).size      = '[]';

pt(81).blockname = 'Scopes/Fir Filter/Discrete FIR Filter';
pt(81).paramname = 'IC';
pt(81).class     = 'scalar';
pt(81).nrows     = 1;
pt(81).ncols     = 1;
pt(81).subsource = 'SS_DOUBLE';
pt(81).ndims     = '2';
pt(81).size      = '[]';

pt(82).blockname = 'Encoders/Derivative/Discrete Derivative/UD';
pt(82).paramname = 'X0';
pt(82).class     = 'scalar';
pt(82).nrows     = 1;
pt(82).ncols     = 1;
pt(82).subsource = 'SS_DOUBLE';
pt(82).ndims     = '2';
pt(82).size      = '[]';

pt(83).blockname = 'Encoders/Derivative/Discrete Derivative/TSamp';
pt(83).paramname = 'WtEt';
pt(83).class     = 'scalar';
pt(83).nrows     = 1;
pt(83).ncols     = 1;
pt(83).subsource = 'SS_DOUBLE';
pt(83).ndims     = '2';
pt(83).size      = '[]';

pt(84).blockname = 'Encoders/Derivative/Fir Filter/vel_filter_coeffs';
pt(84).paramname = 'Value';
pt(84).class     = 'vector';
pt(84).nrows     = 2;
pt(84).ncols     = 1;
pt(84).subsource = 'SS_DOUBLE';
pt(84).ndims     = '2';
pt(84).size      = '[]';

pt(85).blockname = 'Encoders/Derivative/Fir Filter/Gain';
pt(85).paramname = 'Gain';
pt(85).class     = 'scalar';
pt(85).nrows     = 1;
pt(85).ncols     = 1;
pt(85).subsource = 'SS_DOUBLE';
pt(85).ndims     = '2';
pt(85).size      = '[]';

pt(86).blockname = 'Encoders/Derivative/Fir Filter/Discrete FIR Filter';
pt(86).paramname = 'IC';
pt(86).class     = 'scalar';
pt(86).nrows     = 1;
pt(86).ncols     = 1;
pt(86).subsource = 'SS_DOUBLE';
pt(86).ndims     = '2';
pt(86).size      = '[]';

function len = getlenPT
len = 86;

