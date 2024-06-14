function bio=twa_parallelbio
bio = [];
bio(1).blkName='GetMacroLegLen';
bio(1).sigName='macro_leg_len';
bio(1).portIdx=0;
bio(1).dim=[3,1];
bio(1).sigWidth=3;
bio(1).sigAddress='&twa_parallel_B.macro_leg_len[0]';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='GetMacroQDes';
bio(2).sigName='qmacro_des';
bio(2).portIdx=0;
bio(2).dim=[3,1];
bio(2).sigWidth=3;
bio(2).sigAddress='&twa_parallel_B.qmacro_des[0]';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='GetMicroQDes';
bio(3).sigName='qmicro_des';
bio(3).portIdx=0;
bio(3).dim=[3,1];
bio(3).sigWidth=3;
bio(3).sigAddress='&twa_parallel_B.qmicro_des[0]';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Switch';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[6,1];
bio(4).sigWidth=6;
bio(4).sigAddress='&twa_parallel_B.Switch[0]';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Encoders/Encoder Input/p1';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&twa_parallel_B.EncoderInput_o1';
bio(5).ndims=2;
bio(5).size=[];


bio(6).blkName='Encoders/Encoder Input/p2';
bio(6).sigName='';
bio(6).portIdx=1;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&twa_parallel_B.EncoderInput_o2';
bio(6).ndims=2;
bio(6).size=[];


bio(7).blkName='Encoders/Encoder Input/p3';
bio(7).sigName='';
bio(7).portIdx=2;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&twa_parallel_B.EncoderInput_o3';
bio(7).ndims=2;
bio(7).size=[];


bio(8).blkName='Encoders/Encoder Input/p4';
bio(8).sigName='';
bio(8).portIdx=3;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&twa_parallel_B.EncoderInput_o4';
bio(8).ndims=2;
bio(8).size=[];


bio(9).blkName='Encoders/Encoder Input/p5';
bio(9).sigName='';
bio(9).portIdx=4;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&twa_parallel_B.EncoderInput_o5';
bio(9).ndims=2;
bio(9).size=[];


bio(10).blkName='Encoders/Encoder Input/p6';
bio(10).sigName='';
bio(10).portIdx=5;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&twa_parallel_B.EncoderInput_o6';
bio(10).ndims=2;
bio(10).size=[];


bio(11).blkName='PID Controller/Kd';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[6,1];
bio(11).sigWidth=6;
bio(11).sigAddress='&twa_parallel_B.Kd[0]';
bio(11).ndims=2;
bio(11).size=[];


bio(12).blkName='PID Controller/Ki';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[6,1];
bio(12).sigWidth=6;
bio(12).sigAddress='&twa_parallel_B.Ki[0]';
bio(12).ndims=2;
bio(12).size=[];


bio(13).blkName='PID Controller/Kp';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[6,1];
bio(13).sigWidth=6;
bio(13).sigAddress='&twa_parallel_B.Kp[0]';
bio(13).ndims=2;
bio(13).size=[];


bio(14).blkName='PID Controller/Integrator';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[6,1];
bio(14).sigWidth=6;
bio(14).sigAddress='&twa_parallel_B.Integrator[0]';
bio(14).ndims=2;
bio(14).size=[];


bio(15).blkName='PID Controller/Saturation';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[6,1];
bio(15).sigWidth=6;
bio(15).sigAddress='&twa_parallel_B.Saturation[0]';
bio(15).ndims=2;
bio(15).size=[];


bio(16).blkName='PID Controller/saturate_int';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[6,1];
bio(16).sigWidth=6;
bio(16).sigAddress='&twa_parallel_B.saturate_int[0]';
bio(16).ndims=2;
bio(16).size=[];


bio(17).blkName='PID Controller/Add';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[6,1];
bio(17).sigWidth=6;
bio(17).sigAddress='&twa_parallel_B.Add[0]';
bio(17).ndims=2;
bio(17).size=[];


bio(18).blkName='PID Controller/Sum';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[6,1];
bio(18).sigWidth=6;
bio(18).sigAddress='&twa_parallel_B.Sum[0]';
bio(18).ndims=2;
bio(18).size=[];


bio(19).blkName='PID Controller/Switch';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[6,1];
bio(19).sigWidth=6;
bio(19).sigAddress='&twa_parallel_B.Switch_i[0]';
bio(19).ndims=2;
bio(19).size=[];


bio(20).blkName='Quintic Poly/Embedded MATLAB Function/p1';
bio(20).sigName='q_cmd';
bio(20).portIdx=0;
bio(20).dim=[6,1];
bio(20).sigWidth=6;
bio(20).sigAddress='&twa_parallel_B.q_cmd[0]';
bio(20).ndims=2;
bio(20).size=[];


bio(21).blkName='Quintic Poly/Embedded MATLAB Function/p2';
bio(21).sigName='q_dot';
bio(21).portIdx=1;
bio(21).dim=[6,1];
bio(21).sigWidth=6;
bio(21).sigAddress='&twa_parallel_B.q_dot[0]';
bio(21).ndims=2;
bio(21).size=[];


bio(22).blkName='Quintic Poly/Embedded MATLAB Function/p3';
bio(22).sigName='q_dub_dot';
bio(22).portIdx=2;
bio(22).dim=[6,1];
bio(22).sigWidth=6;
bio(22).sigAddress='&twa_parallel_B.q_dub_dot[0]';
bio(22).ndims=2;
bio(22).size=[];


bio(23).blkName='Quintic Poly/Embedded MATLAB Function/p4';
bio(23).sigName='confn';
bio(23).portIdx=3;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&twa_parallel_B.confn';
bio(23).ndims=2;
bio(23).size=[];


bio(24).blkName='Quintic Poly/Embedded MATLAB Function/p5';
bio(24).sigName='t0n';
bio(24).portIdx=4;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&twa_parallel_B.t0n';
bio(24).ndims=2;
bio(24).size=[];


bio(25).blkName='Quintic Poly/Embedded MATLAB Function/p6';
bio(25).sigName='q0n';
bio(25).portIdx=5;
bio(25).dim=[6,1];
bio(25).sigWidth=6;
bio(25).sigAddress='&twa_parallel_B.q0n[0]';
bio(25).ndims=2;
bio(25).size=[];


bio(26).blkName='Quintic Poly/Embedded MATLAB Function/p7';
bio(26).sigName='robot_mov';
bio(26).portIdx=6;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&twa_parallel_B.robot_mov';
bio(26).ndims=2;
bio(26).size=[];


bio(27).blkName='Quintic Poly/Digital Clock';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&twa_parallel_B.DigitalClock';
bio(27).ndims=2;
bio(27).size=[];


bio(28).blkName='Quintic Poly/Unit Delay';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&twa_parallel_B.UnitDelay';
bio(28).ndims=2;
bio(28).size=[];


bio(29).blkName='Quintic Poly/Unit Delay1';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&twa_parallel_B.UnitDelay1';
bio(29).ndims=2;
bio(29).size=[];


bio(30).blkName='Quintic Poly/Unit Delay2';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[6,1];
bio(30).sigWidth=6;
bio(30).sigAddress='&twa_parallel_B.UnitDelay2[0]';
bio(30).ndims=2;
bio(30).size=[];


bio(31).blkName='Encoders/Counts To Turns/enc_res';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&twa_parallel_B.enc_res';
bio(31).ndims=2;
bio(31).size=[];


bio(32).blkName='Encoders/Counts To Turns/gear_ratio';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&twa_parallel_B.gear_ratio';
bio(32).ndims=2;
bio(32).size=[];


bio(33).blkName='Encoders/Counts To Turns1/enc_res';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&twa_parallel_B.enc_res_l';
bio(33).ndims=2;
bio(33).size=[];


bio(34).blkName='Encoders/Counts To Turns1/gear_ratio';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&twa_parallel_B.gear_ratio_p';
bio(34).ndims=2;
bio(34).size=[];


bio(35).blkName='Encoders/Counts To Turns2/enc_res';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&twa_parallel_B.enc_res_f';
bio(35).ndims=2;
bio(35).size=[];


bio(36).blkName='Encoders/Counts To Turns2/gear_ratio';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&twa_parallel_B.gear_ratio_c';
bio(36).ndims=2;
bio(36).size=[];


bio(37).blkName='Encoders/Counts To Turns3/enc_res';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&twa_parallel_B.enc_res_c';
bio(37).ndims=2;
bio(37).size=[];


bio(38).blkName='Encoders/Counts To Turns3/gear_ratio';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&twa_parallel_B.gear_ratio_l';
bio(38).ndims=2;
bio(38).size=[];


bio(39).blkName='Encoders/Counts To Turns4/enc_res';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&twa_parallel_B.enc_res_fa';
bio(39).ndims=2;
bio(39).size=[];


bio(40).blkName='Encoders/Counts To Turns4/gear_ratio';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&twa_parallel_B.gear_ratio_j';
bio(40).ndims=2;
bio(40).size=[];


bio(41).blkName='Encoders/Counts To Turns5/enc_res';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&twa_parallel_B.enc_res_b';
bio(41).ndims=2;
bio(41).size=[];


bio(42).blkName='Encoders/Counts To Turns5/gear_ratio';
bio(42).sigName='';
bio(42).portIdx=0;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&twa_parallel_B.gear_ratio_n';
bio(42).ndims=2;
bio(42).size=[];


bio(43).blkName='PID Controller/Discrete Derivative/Diff';
bio(43).sigName='';
bio(43).portIdx=0;
bio(43).dim=[6,1];
bio(43).sigWidth=6;
bio(43).sigAddress='&twa_parallel_B.Diff_d[0]';
bio(43).ndims=2;
bio(43).size=[];


bio(44).blkName='PID Controller/Discrete Derivative/UD';
bio(44).sigName='U(k-1)';
bio(44).portIdx=0;
bio(44).dim=[6,1];
bio(44).sigWidth=6;
bio(44).sigAddress='&twa_parallel_B.Uk1_j[0]';
bio(44).ndims=2;
bio(44).size=[];


bio(45).blkName='PID Controller/Discrete Derivative/TSamp';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[6,1];
bio(45).sigWidth=6;
bio(45).sigAddress='&twa_parallel_B.TSamp_h[0]';
bio(45).ndims=2;
bio(45).size=[];


bio(46).blkName='Quintic Poly/N-Sample Switch/N-Sample Enable';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&twa_parallel_B.NSampleEnable';
bio(46).ndims=2;
bio(46).size=[];


bio(47).blkName='Quintic Poly/N-Sample Switch/Switch';
bio(47).sigName='';
bio(47).portIdx=0;
bio(47).dim=[6,1];
bio(47).sigWidth=6;
bio(47).sigAddress='&twa_parallel_B.Switch_f[0]';
bio(47).ndims=2;
bio(47).size=[];


bio(48).blkName='Scopes/Fir Filter/Gain';
bio(48).sigName='';
bio(48).portIdx=0;
bio(48).dim=[6,1];
bio(48).sigWidth=6;
bio(48).sigAddress='&twa_parallel_B.Gain_n[0]';
bio(48).ndims=2;
bio(48).size=[];


bio(49).blkName='Scopes/Fir Filter/Discrete FIR Filter';
bio(49).sigName='';
bio(49).portIdx=0;
bio(49).dim=[6,1];
bio(49).sigWidth=6;
bio(49).sigAddress='&twa_parallel_B.DiscreteFIRFilter_h[0]';
bio(49).ndims=2;
bio(49).size=[];


bio(50).blkName='Encoders/Derivative/Discrete Derivative/Diff';
bio(50).sigName='';
bio(50).portIdx=0;
bio(50).dim=[6,1];
bio(50).sigWidth=6;
bio(50).sigAddress='&twa_parallel_B.Diff[0]';
bio(50).ndims=2;
bio(50).size=[];


bio(51).blkName='Encoders/Derivative/Discrete Derivative/UD';
bio(51).sigName='U(k-1)';
bio(51).portIdx=0;
bio(51).dim=[6,1];
bio(51).sigWidth=6;
bio(51).sigAddress='&twa_parallel_B.Uk1[0]';
bio(51).ndims=2;
bio(51).size=[];


bio(52).blkName='Encoders/Derivative/Discrete Derivative/TSamp';
bio(52).sigName='';
bio(52).portIdx=0;
bio(52).dim=[6,1];
bio(52).sigWidth=6;
bio(52).sigAddress='&twa_parallel_B.TSamp[0]';
bio(52).ndims=2;
bio(52).size=[];


bio(53).blkName='Encoders/Derivative/Fir Filter/Gain';
bio(53).sigName='';
bio(53).portIdx=0;
bio(53).dim=[6,1];
bio(53).sigWidth=6;
bio(53).sigAddress='&twa_parallel_B.Gain[0]';
bio(53).ndims=2;
bio(53).size=[];


bio(54).blkName='Encoders/Derivative/Fir Filter/Discrete FIR Filter';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[6,1];
bio(54).sigWidth=6;
bio(54).sigAddress='&twa_parallel_B.DiscreteFIRFilter[0]';
bio(54).ndims=2;
bio(54).size=[];


function len = getlenBIO
len = 54;

