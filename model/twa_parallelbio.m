function bio=twa_parallelbio
bio = [];
bio(1).blkName='Encoders/Encoder Input/p1';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&twa_parallel_B.EncoderInput_o1';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='Encoders/Encoder Input/p2';
bio(2).sigName='';
bio(2).portIdx=1;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&twa_parallel_B.EncoderInput_o2';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='Encoders/Encoder Input/p3';
bio(3).sigName='';
bio(3).portIdx=2;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&twa_parallel_B.EncoderInput_o3';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Encoders/Encoder Input/p4';
bio(4).sigName='';
bio(4).portIdx=3;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&twa_parallel_B.EncoderInput_o4';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Encoders/Encoder Input/p5';
bio(5).sigName='';
bio(5).portIdx=4;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&twa_parallel_B.EncoderInput_o5';
bio(5).ndims=2;
bio(5).size=[];


bio(6).blkName='Encoders/Encoder Input/p6';
bio(6).sigName='';
bio(6).portIdx=5;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&twa_parallel_B.EncoderInput_o6';
bio(6).ndims=2;
bio(6).size=[];


bio(7).blkName='PID Controller/Kd';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[3,1];
bio(7).sigWidth=3;
bio(7).sigAddress='&twa_parallel_B.Kd[0]';
bio(7).ndims=2;
bio(7).size=[];


bio(8).blkName='PID Controller/Kd_mu';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[3,1];
bio(8).sigWidth=3;
bio(8).sigAddress='&twa_parallel_B.Kd_mu[0]';
bio(8).ndims=2;
bio(8).size=[];


bio(9).blkName='PID Controller/Ki';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[3,1];
bio(9).sigWidth=3;
bio(9).sigAddress='&twa_parallel_B.Ki[0]';
bio(9).ndims=2;
bio(9).size=[];


bio(10).blkName='PID Controller/Ki_mu';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[3,1];
bio(10).sigWidth=3;
bio(10).sigAddress='&twa_parallel_B.Ki_mu[0]';
bio(10).ndims=2;
bio(10).size=[];


bio(11).blkName='PID Controller/Kp';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[3,1];
bio(11).sigWidth=3;
bio(11).sigAddress='&twa_parallel_B.Kp[0]';
bio(11).ndims=2;
bio(11).size=[];


bio(12).blkName='PID Controller/Kp_mu';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[3,1];
bio(12).sigWidth=3;
bio(12).sigAddress='&twa_parallel_B.Kp_mu[0]';
bio(12).ndims=2;
bio(12).size=[];


bio(13).blkName='PID Controller/Integrator';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[3,1];
bio(13).sigWidth=3;
bio(13).sigAddress='&twa_parallel_B.Integrator[0]';
bio(13).ndims=2;
bio(13).size=[];


bio(14).blkName='PID Controller/Integrator1';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[3,1];
bio(14).sigWidth=3;
bio(14).sigAddress='&twa_parallel_B.Integrator1[0]';
bio(14).ndims=2;
bio(14).size=[];


bio(15).blkName='PID Controller/Saturation';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[3,1];
bio(15).sigWidth=3;
bio(15).sigAddress='&twa_parallel_B.Saturation[0]';
bio(15).ndims=2;
bio(15).size=[];


bio(16).blkName='PID Controller/Saturation1';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[3,1];
bio(16).sigWidth=3;
bio(16).sigAddress='&twa_parallel_B.Saturation1[0]';
bio(16).ndims=2;
bio(16).size=[];


bio(17).blkName='PID Controller/saturate_int';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[3,1];
bio(17).sigWidth=3;
bio(17).sigAddress='&twa_parallel_B.saturate_int[0]';
bio(17).ndims=2;
bio(17).size=[];


bio(18).blkName='PID Controller/saturate_int1';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[3,1];
bio(18).sigWidth=3;
bio(18).sigAddress='&twa_parallel_B.saturate_int1[0]';
bio(18).ndims=2;
bio(18).size=[];


bio(19).blkName='PID Controller/Add';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[3,1];
bio(19).sigWidth=3;
bio(19).sigAddress='&twa_parallel_B.Add[0]';
bio(19).ndims=2;
bio(19).size=[];


bio(20).blkName='PID Controller/Add1';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[3,1];
bio(20).sigWidth=3;
bio(20).sigAddress='&twa_parallel_B.Add1[0]';
bio(20).ndims=2;
bio(20).size=[];


bio(21).blkName='PID Controller/Sum';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[3,1];
bio(21).sigWidth=3;
bio(21).sigAddress='&twa_parallel_B.Sum[0]';
bio(21).ndims=2;
bio(21).size=[];


bio(22).blkName='PID Controller/Sum1';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[3,1];
bio(22).sigWidth=3;
bio(22).sigAddress='&twa_parallel_B.Sum1[0]';
bio(22).ndims=2;
bio(22).size=[];


bio(23).blkName='PID Controller/Switch';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[3,1];
bio(23).sigWidth=3;
bio(23).sigAddress='&twa_parallel_B.Switch_i[0]';
bio(23).ndims=2;
bio(23).size=[];


bio(24).blkName='PID Controller/Switch1';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[3,1];
bio(24).sigWidth=3;
bio(24).sigAddress='&twa_parallel_B.Switch1[0]';
bio(24).ndims=2;
bio(24).size=[];


bio(25).blkName='Quintic Poly/Embedded MATLAB Function/p1';
bio(25).sigName='q_cmd';
bio(25).portIdx=0;
bio(25).dim=[6,1];
bio(25).sigWidth=6;
bio(25).sigAddress='&twa_parallel_B.q_cmd[0]';
bio(25).ndims=2;
bio(25).size=[];


bio(26).blkName='Quintic Poly/Embedded MATLAB Function/p2';
bio(26).sigName='q_dot';
bio(26).portIdx=1;
bio(26).dim=[6,1];
bio(26).sigWidth=6;
bio(26).sigAddress='&twa_parallel_B.q_dot[0]';
bio(26).ndims=2;
bio(26).size=[];


bio(27).blkName='Quintic Poly/Embedded MATLAB Function/p3';
bio(27).sigName='q_dub_dot';
bio(27).portIdx=2;
bio(27).dim=[6,1];
bio(27).sigWidth=6;
bio(27).sigAddress='&twa_parallel_B.q_dub_dot[0]';
bio(27).ndims=2;
bio(27).size=[];


bio(28).blkName='Quintic Poly/Embedded MATLAB Function/p4';
bio(28).sigName='confn';
bio(28).portIdx=3;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&twa_parallel_B.confn';
bio(28).ndims=2;
bio(28).size=[];


bio(29).blkName='Quintic Poly/Embedded MATLAB Function/p5';
bio(29).sigName='t0n';
bio(29).portIdx=4;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&twa_parallel_B.t0n';
bio(29).ndims=2;
bio(29).size=[];


bio(30).blkName='Quintic Poly/Embedded MATLAB Function/p6';
bio(30).sigName='q0n';
bio(30).portIdx=5;
bio(30).dim=[6,1];
bio(30).sigWidth=6;
bio(30).sigAddress='&twa_parallel_B.q0n[0]';
bio(30).ndims=2;
bio(30).size=[];


bio(31).blkName='Quintic Poly/Embedded MATLAB Function/p7';
bio(31).sigName='robot_mov';
bio(31).portIdx=6;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&twa_parallel_B.robot_mov';
bio(31).ndims=2;
bio(31).size=[];


bio(32).blkName='Quintic Poly/Digital Clock';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&twa_parallel_B.DigitalClock_j';
bio(32).ndims=2;
bio(32).size=[];


bio(33).blkName='Quintic Poly/Unit Delay';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&twa_parallel_B.UnitDelay';
bio(33).ndims=2;
bio(33).size=[];


bio(34).blkName='Quintic Poly/Unit Delay1';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&twa_parallel_B.UnitDelay1_b';
bio(34).ndims=2;
bio(34).size=[];


bio(35).blkName='Quintic Poly/Unit Delay2';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[6,1];
bio(35).sigWidth=6;
bio(35).sigAddress='&twa_parallel_B.UnitDelay2[0]';
bio(35).ndims=2;
bio(35).size=[];


bio(36).blkName='control_mode/control_switch';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[6,1];
bio(36).sigWidth=6;
bio(36).sigAddress='&twa_parallel_B.control_switch[0]';
bio(36).ndims=2;
bio(36).size=[];


bio(37).blkName='control_mode/Unit Delay1';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[6,1];
bio(37).sigWidth=6;
bio(37).sigAddress='&twa_parallel_B.UnitDelay1[0]';
bio(37).ndims=2;
bio(37).size=[];


bio(38).blkName='Encoders/Counts To Turns1/enc_res';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&twa_parallel_B.enc_res';
bio(38).ndims=2;
bio(38).size=[];


bio(39).blkName='Encoders/Counts To Turns1/gear_ratio';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&twa_parallel_B.gear_ratio';
bio(39).ndims=2;
bio(39).size=[];


bio(40).blkName='Encoders/Counts To Turns1/velmex_pitch';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&twa_parallel_B.velmex_pitch';
bio(40).ndims=2;
bio(40).size=[];


bio(41).blkName='Encoders/Counts To Turns2/enc_res';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&twa_parallel_B.enc_res_f';
bio(41).ndims=2;
bio(41).size=[];


bio(42).blkName='Encoders/Counts To Turns2/gear_ratio';
bio(42).sigName='';
bio(42).portIdx=0;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&twa_parallel_B.gear_ratio_c';
bio(42).ndims=2;
bio(42).size=[];


bio(43).blkName='Encoders/Counts To Turns2/velmex_pitch';
bio(43).sigName='';
bio(43).portIdx=0;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&twa_parallel_B.velmex_pitch_e';
bio(43).ndims=2;
bio(43).size=[];


bio(44).blkName='Encoders/Counts To Turns3/enc_res';
bio(44).sigName='';
bio(44).portIdx=0;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&twa_parallel_B.enc_res_c';
bio(44).ndims=2;
bio(44).size=[];


bio(45).blkName='Encoders/Counts To Turns3/gear_ratio';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&twa_parallel_B.gear_ratio_l';
bio(45).ndims=2;
bio(45).size=[];


bio(46).blkName='Encoders/Counts To Turns3/velmex_pitch';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&twa_parallel_B.velmex_pitch_k';
bio(46).ndims=2;
bio(46).size=[];


bio(47).blkName='Encoders/Counts To Turns4/gettwalen';
bio(47).sigName='twa_len';
bio(47).portIdx=0;
bio(47).dim=[1,1];
bio(47).sigWidth=1;
bio(47).sigAddress='&twa_parallel_B.twa_len_o';
bio(47).ndims=2;
bio(47).size=[];


bio(48).blkName='Encoders/Counts To Turns4/enc_res';
bio(48).sigName='';
bio(48).portIdx=0;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&twa_parallel_B.enc_res_fa';
bio(48).ndims=2;
bio(48).size=[];


bio(49).blkName='Encoders/Counts To Turns4/gear_ratio';
bio(49).sigName='';
bio(49).portIdx=0;
bio(49).dim=[1,1];
bio(49).sigWidth=1;
bio(49).sigAddress='&twa_parallel_B.gear_ratio_j';
bio(49).ndims=2;
bio(49).size=[];


bio(50).blkName='Encoders/Counts To Turns5/gettwalen';
bio(50).sigName='twa_len';
bio(50).portIdx=0;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&twa_parallel_B.twa_len_i';
bio(50).ndims=2;
bio(50).size=[];


bio(51).blkName='Encoders/Counts To Turns5/enc_res';
bio(51).sigName='';
bio(51).portIdx=0;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&twa_parallel_B.enc_res_b';
bio(51).ndims=2;
bio(51).size=[];


bio(52).blkName='Encoders/Counts To Turns5/gear_ratio';
bio(52).sigName='';
bio(52).portIdx=0;
bio(52).dim=[1,1];
bio(52).sigWidth=1;
bio(52).sigAddress='&twa_parallel_B.gear_ratio_n';
bio(52).ndims=2;
bio(52).size=[];


bio(53).blkName='Encoders/Counts To Turns6/gettwalen';
bio(53).sigName='twa_len';
bio(53).portIdx=0;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&twa_parallel_B.twa_len';
bio(53).ndims=2;
bio(53).size=[];


bio(54).blkName='Encoders/Counts To Turns6/enc_res';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&twa_parallel_B.enc_res_e';
bio(54).ndims=2;
bio(54).size=[];


bio(55).blkName='Encoders/Counts To Turns6/gear_ratio';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&twa_parallel_B.gear_ratio_f';
bio(55).ndims=2;
bio(55).size=[];


bio(56).blkName='PID Controller/Discrete Derivative/Diff';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[3,1];
bio(56).sigWidth=3;
bio(56).sigAddress='&twa_parallel_B.Diff_d[0]';
bio(56).ndims=2;
bio(56).size=[];


bio(57).blkName='PID Controller/Discrete Derivative/UD';
bio(57).sigName='U(k-1)';
bio(57).portIdx=0;
bio(57).dim=[3,1];
bio(57).sigWidth=3;
bio(57).sigAddress='&twa_parallel_B.Uk1_jb[0]';
bio(57).ndims=2;
bio(57).size=[];


bio(58).blkName='PID Controller/Discrete Derivative/TSamp';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[3,1];
bio(58).sigWidth=3;
bio(58).sigAddress='&twa_parallel_B.TSamp_h[0]';
bio(58).ndims=2;
bio(58).size=[];


bio(59).blkName='PID Controller/Discrete Derivative1/Diff';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[3,1];
bio(59).sigWidth=3;
bio(59).sigAddress='&twa_parallel_B.Diff_a[0]';
bio(59).ndims=2;
bio(59).size=[];


bio(60).blkName='PID Controller/Discrete Derivative1/UD';
bio(60).sigName='U(k-1)';
bio(60).portIdx=0;
bio(60).dim=[3,1];
bio(60).sigWidth=3;
bio(60).sigAddress='&twa_parallel_B.Uk1_f[0]';
bio(60).ndims=2;
bio(60).size=[];


bio(61).blkName='PID Controller/Discrete Derivative1/TSamp';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[3,1];
bio(61).sigWidth=3;
bio(61).sigAddress='&twa_parallel_B.TSamp_p[0]';
bio(61).ndims=2;
bio(61).size=[];


bio(62).blkName='Quintic Poly/N-Sample Switch/N-Sample Enable';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&twa_parallel_B.NSampleEnable';
bio(62).ndims=2;
bio(62).size=[];


bio(63).blkName='Quintic Poly/N-Sample Switch/Switch';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[6,1];
bio(63).sigWidth=6;
bio(63).sigAddress='&twa_parallel_B.Switch_f[0]';
bio(63).ndims=2;
bio(63).size=[];


bio(64).blkName='Scopes/Fir Filter/Gain';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[6,1];
bio(64).sigWidth=6;
bio(64).sigAddress='&twa_parallel_B.Gain_n[0]';
bio(64).ndims=2;
bio(64).size=[];


bio(65).blkName='Scopes/Fir Filter/Discrete FIR Filter';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[6,1];
bio(65).sigWidth=6;
bio(65).sigAddress='&twa_parallel_B.DiscreteFIRFilter_h[0]';
bio(65).ndims=2;
bio(65).size=[];


bio(66).blkName='control_mode/detect change/Switch';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[6,1];
bio(66).sigWidth=6;
bio(66).sigAddress='&twa_parallel_B.Switch[0]';
bio(66).ndims=2;
bio(66).size=[];


bio(67).blkName='control_mode/task_space/ResolvedRates/p1';
bio(67).sigName='xcur';
bio(67).portIdx=0;
bio(67).dim=[3,1];
bio(67).sigWidth=3;
bio(67).sigAddress='&twa_parallel_B.xcur[0]';
bio(67).ndims=2;
bio(67).size=[];


bio(68).blkName='control_mode/task_space/ResolvedRates/p2';
bio(68).sigName='eerot';
bio(68).portIdx=1;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&twa_parallel_B.eerot';
bio(68).ndims=2;
bio(68).size=[];


bio(69).blkName='control_mode/task_space/ResolvedRates/p3';
bio(69).sigName='qref';
bio(69).portIdx=2;
bio(69).dim=[6,1];
bio(69).sigWidth=6;
bio(69).sigAddress='&twa_parallel_B.qref[0]';
bio(69).ndims=2;
bio(69).size=[];


bio(70).blkName='control_mode/task_space/ResolvedRates/p4';
bio(70).sigName='deltaq';
bio(70).portIdx=3;
bio(70).dim=[6,1];
bio(70).sigWidth=6;
bio(70).sigAddress='&twa_parallel_B.deltaq[0]';
bio(70).ndims=2;
bio(70).size=[];


bio(71).blkName='control_mode/task_space/inv_kin/p1';
bio(71).sigName='qdes';
bio(71).portIdx=0;
bio(71).dim=[6,1];
bio(71).sigWidth=6;
bio(71).sigAddress='&twa_parallel_B.qdes_f[0]';
bio(71).ndims=2;
bio(71).size=[];


bio(72).blkName='control_mode/task_space/inv_kin/p2';
bio(72).sigName='vertex_dist';
bio(72).portIdx=1;
bio(72).dim=[3,3];
bio(72).sigWidth=9;
bio(72).sigAddress='&twa_parallel_B.vertex_dist[0]';
bio(72).ndims=2;
bio(72).size=[];


bio(73).blkName='control_mode/task_space/quintic/p1';
bio(73).sigName='qdes';
bio(73).portIdx=0;
bio(73).dim=[6,1];
bio(73).sigWidth=6;
bio(73).sigAddress='&twa_parallel_B.qdes[0]';
bio(73).ndims=2;
bio(73).size=[];


bio(74).blkName='control_mode/task_space/quintic/p2';
bio(74).sigName='deltax';
bio(74).portIdx=1;
bio(74).dim=[3,1];
bio(74).sigWidth=3;
bio(74).sigAddress='&twa_parallel_B.deltax[0]';
bio(74).ndims=2;
bio(74).size=[];


bio(75).blkName='control_mode/task_space/quintic/p3';
bio(75).sigName='tinit';
bio(75).portIdx=2;
bio(75).dim=[1,1];
bio(75).sigWidth=1;
bio(75).sigAddress='&twa_parallel_B.tinit';
bio(75).ndims=2;
bio(75).size=[];


bio(76).blkName='control_mode/task_space/quintic/p4';
bio(76).sigName='xinit';
bio(76).portIdx=3;
bio(76).dim=[3,1];
bio(76).sigWidth=3;
bio(76).sigAddress='&twa_parallel_B.xinit[0]';
bio(76).ndims=2;
bio(76).size=[];


bio(77).blkName='control_mode/task_space/quintic/p5';
bio(77).sigName='robotmoving';
bio(77).portIdx=4;
bio(77).dim=[1,1];
bio(77).sigWidth=1;
bio(77).sigAddress='&twa_parallel_B.robotmoving';
bio(77).ndims=2;
bio(77).size=[];


bio(78).blkName='control_mode/task_space/Digital Clock';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[1,1];
bio(78).sigWidth=1;
bio(78).sigAddress='&twa_parallel_B.DigitalClock';
bio(78).ndims=2;
bio(78).size=[];


bio(79).blkName='control_mode/task_space/Multiport Switch';
bio(79).sigName='';
bio(79).portIdx=0;
bio(79).dim=[6,1];
bio(79).sigWidth=6;
bio(79).sigAddress='&twa_parallel_B.MultiportSwitch[0]';
bio(79).ndims=2;
bio(79).size=[];


bio(80).blkName='control_mode/task_space/Unit Delay1';
bio(80).sigName='';
bio(80).portIdx=0;
bio(80).dim=[6,1];
bio(80).sigWidth=6;
bio(80).sigAddress='&twa_parallel_B.UnitDelay1_a[0]';
bio(80).ndims=2;
bio(80).size=[];


bio(81).blkName='control_mode/task_space/Unit Delay10';
bio(81).sigName='';
bio(81).portIdx=0;
bio(81).dim=[1,1];
bio(81).sigWidth=1;
bio(81).sigAddress='&twa_parallel_B.UnitDelay10';
bio(81).ndims=2;
bio(81).size=[];


bio(82).blkName='control_mode/task_space/Unit Delay11';
bio(82).sigName='';
bio(82).portIdx=0;
bio(82).dim=[3,1];
bio(82).sigWidth=3;
bio(82).sigAddress='&twa_parallel_B.UnitDelay11[0]';
bio(82).ndims=2;
bio(82).size=[];


bio(83).blkName='control_mode/task_space/Unit Delay2';
bio(83).sigName='';
bio(83).portIdx=0;
bio(83).dim=[6,1];
bio(83).sigWidth=6;
bio(83).sigAddress='&twa_parallel_B.UnitDelay2_k[0]';
bio(83).ndims=2;
bio(83).size=[];


bio(84).blkName='control_mode/task_space/Unit Delay3';
bio(84).sigName='';
bio(84).portIdx=0;
bio(84).dim=[1,1];
bio(84).sigWidth=1;
bio(84).sigAddress='&twa_parallel_B.UnitDelay3';
bio(84).ndims=2;
bio(84).size=[];


bio(85).blkName='control_mode/task_space/Unit Delay4';
bio(85).sigName='';
bio(85).portIdx=0;
bio(85).dim=[3,1];
bio(85).sigWidth=3;
bio(85).sigAddress='&twa_parallel_B.UnitDelay4[0]';
bio(85).ndims=2;
bio(85).size=[];


bio(86).blkName='control_mode/task_space/Unit Delay5';
bio(86).sigName='';
bio(86).portIdx=0;
bio(86).dim=[3,3];
bio(86).sigWidth=9;
bio(86).sigAddress='&twa_parallel_B.UnitDelay5[0]';
bio(86).ndims=2;
bio(86).size=[];


bio(87).blkName='control_mode/task_space/Unit Delay6';
bio(87).sigName='';
bio(87).portIdx=0;
bio(87).dim=[3,1];
bio(87).sigWidth=3;
bio(87).sigAddress='&twa_parallel_B.UnitDelay6[0]';
bio(87).ndims=2;
bio(87).size=[];


bio(88).blkName='control_mode/task_space/Unit Delay7';
bio(88).sigName='';
bio(88).portIdx=0;
bio(88).dim=[6,1];
bio(88).sigWidth=6;
bio(88).sigAddress='&twa_parallel_B.UnitDelay7[0]';
bio(88).ndims=2;
bio(88).size=[];


bio(89).blkName='control_mode/task_space/Unit Delay8';
bio(89).sigName='';
bio(89).portIdx=0;
bio(89).dim=[6,1];
bio(89).sigWidth=6;
bio(89).sigAddress='&twa_parallel_B.UnitDelay8[0]';
bio(89).ndims=2;
bio(89).size=[];


bio(90).blkName='control_mode/task_space/Unit Delay9';
bio(90).sigName='';
bio(90).portIdx=0;
bio(90).dim=[1,1];
bio(90).sigWidth=1;
bio(90).sigAddress='&twa_parallel_B.UnitDelay9';
bio(90).ndims=2;
bio(90).size=[];


bio(91).blkName='Encoders/Derivative/Discrete Derivative/Diff';
bio(91).sigName='';
bio(91).portIdx=0;
bio(91).dim=[6,1];
bio(91).sigWidth=6;
bio(91).sigAddress='&twa_parallel_B.Diff[0]';
bio(91).ndims=2;
bio(91).size=[];


bio(92).blkName='Encoders/Derivative/Discrete Derivative/UD';
bio(92).sigName='U(k-1)';
bio(92).portIdx=0;
bio(92).dim=[6,1];
bio(92).sigWidth=6;
bio(92).sigAddress='&twa_parallel_B.Uk1[0]';
bio(92).ndims=2;
bio(92).size=[];


bio(93).blkName='Encoders/Derivative/Discrete Derivative/TSamp';
bio(93).sigName='';
bio(93).portIdx=0;
bio(93).dim=[6,1];
bio(93).sigWidth=6;
bio(93).sigAddress='&twa_parallel_B.TSamp[0]';
bio(93).ndims=2;
bio(93).size=[];


bio(94).blkName='Encoders/Derivative/Fir Filter/Gain';
bio(94).sigName='';
bio(94).portIdx=0;
bio(94).dim=[6,1];
bio(94).sigWidth=6;
bio(94).sigAddress='&twa_parallel_B.Gain[0]';
bio(94).ndims=2;
bio(94).size=[];


bio(95).blkName='Encoders/Derivative/Fir Filter/Discrete FIR Filter';
bio(95).sigName='';
bio(95).portIdx=0;
bio(95).dim=[6,1];
bio(95).sigWidth=6;
bio(95).sigAddress='&twa_parallel_B.DiscreteFIRFilter[0]';
bio(95).ndims=2;
bio(95).size=[];


bio(96).blkName='control_mode/detect change/Detect Change/FixPt Relational Operator';
bio(96).sigName='';
bio(96).portIdx=0;
bio(96).dim=[6,1];
bio(96).sigWidth=6;
bio(96).sigAddress='&twa_parallel_B.FixPtRelationalOperator[0]';
bio(96).ndims=2;
bio(96).size=[];


bio(97).blkName='control_mode/detect change/Detect Change/Delay Input1';
bio(97).sigName='U(k-1)';
bio(97).portIdx=0;
bio(97).dim=[6,1];
bio(97).sigWidth=6;
bio(97).sigAddress='&twa_parallel_B.Uk1_j[0]';
bio(97).ndims=2;
bio(97).size=[];


function len = getlenBIO
len = 97;

