  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (twa_parallel_P)
    ;%
      section.nData     = 79;
      section.data(79)  = dumData; %prealloc
      
	  ;% twa_parallel_P.eq_eps_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_P.kp_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_P.dt_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% twa_parallel_P.p_in_m_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% twa_parallel_P.b_in_w_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 12;
	
	  ;% twa_parallel_P.m_in_w_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% twa_parallel_P.f_in_w_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% twa_parallel_P.meas_macro_len_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 39;
	
	  ;% twa_parallel_P.velmex_pitch_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 42;
	
	  ;% twa_parallel_P.UnitDelay1_X0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 43;
	
	  ;% twa_parallel_P.UnitDelay4_X0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 46;
	
	  ;% twa_parallel_P.UnitDelay3_X0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 49;
	
	  ;% twa_parallel_P.UnitDelay2_X0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 52;
	
	  ;% twa_parallel_P.Init_P1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 61;
	
	  ;% twa_parallel_P.Init_P2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 62;
	
	  ;% twa_parallel_P.Init_P3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 63;
	
	  ;% twa_parallel_P.Init_P4
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 64;
	
	  ;% twa_parallel_P.AnalogOutput_P1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 65;
	
	  ;% twa_parallel_P.EncoderInput_P1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 71;
	
	  ;% twa_parallel_P.EncoderInput_P2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 77;
	
	  ;% twa_parallel_P.enc_res_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 78;
	
	  ;% twa_parallel_P.gear_ratio_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 79;
	
	  ;% twa_parallel_P.enc_res_Gain_j
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 80;
	
	  ;% twa_parallel_P.gear_ratio_Gain_i
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 81;
	
	  ;% twa_parallel_P.enc_res_Gain_jz
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 82;
	
	  ;% twa_parallel_P.gear_ratio_Gain_d
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 83;
	
	  ;% twa_parallel_P.enc_res_Gain_i
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 84;
	
	  ;% twa_parallel_P.gear_ratio_Gain_a
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 85;
	
	  ;% twa_parallel_P.enc_res_Gain_g
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 86;
	
	  ;% twa_parallel_P.gear_ratio_Gain_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 87;
	
	  ;% twa_parallel_P.enc_res_Gain_ij
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 88;
	
	  ;% twa_parallel_P.gear_ratio_Gain_da
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 89;
	
	  ;% twa_parallel_P.vel_filter_coeffs_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 90;
	
	  ;% twa_parallel_P.DiscreteFIRFilter_IC
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 92;
	
	  ;% twa_parallel_P.Gain_Gain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 93;
	
	  ;% twa_parallel_P.TSamp_WtEt
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 94;
	
	  ;% twa_parallel_P.UD_X0
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 95;
	
	  ;% twa_parallel_P.enc_reset_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 96;
	
	  ;% twa_parallel_P.vel_filter_coeffs_Value_m
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 97;
	
	  ;% twa_parallel_P.DiscreteFIRFilter_IC_b
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 99;
	
	  ;% twa_parallel_P.Gain_Gain_d
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 100;
	
	  ;% twa_parallel_P.do_homing_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 101;
	
	  ;% twa_parallel_P.cntrl_mode_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 102;
	
	  ;% twa_parallel_P.q_des_Value
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 103;
	
	  ;% twa_parallel_P.x_des_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 109;
	
	  ;% twa_parallel_P.ee_rot_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 112;
	
	  ;% twa_parallel_P.p_in_m_Value_m
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 113;
	
	  ;% twa_parallel_P.b_in_w_Value_i
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 122;
	
	  ;% twa_parallel_P.m_in_w_Value_n
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 131;
	
	  ;% twa_parallel_P.f_in_w_Value_b
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 140;
	
	  ;% twa_parallel_P.t_in_w_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 149;
	
	  ;% twa_parallel_P.twa_gamma_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 158;
	
	  ;% twa_parallel_P.twa_flange_offset_Value
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 159;
	
	  ;% twa_parallel_P.use_twa_Value
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 160;
	
	  ;% twa_parallel_P.UnitDelay1_X0_g
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 161;
	
	  ;% twa_parallel_P.UnitDelay2_X0_p
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 164;
	
	  ;% twa_parallel_P.meas_macro_len_Value_d
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 167;
	
	  ;% twa_parallel_P.velmex_pitch_Value_e
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 170;
	
	  ;% twa_parallel_P.meas_twa_len_Value
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 171;
	
	  ;% twa_parallel_P.helix_rad_Value
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 174;
	
	  ;% twa_parallel_P.wire_delta_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 175;
	
	  ;% twa_parallel_P.tf_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 176;
	
	  ;% twa_parallel_P.UnitDelay_X0
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 177;
	
	  ;% twa_parallel_P.UnitDelay1_X0_h
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 178;
	
	  ;% twa_parallel_P.UnitDelay2_X0_d
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 179;
	
	  ;% twa_parallel_P.quintic_enable_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 185;
	
	  ;% twa_parallel_P.Kp_Gain
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 186;
	
	  ;% twa_parallel_P.reset_integrator_Value
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 192;
	
	  ;% twa_parallel_P.Integrator_IC
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 193;
	
	  ;% twa_parallel_P.Ki_Gain
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 194;
	
	  ;% twa_parallel_P.saturate_int_UpperSat
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 200;
	
	  ;% twa_parallel_P.saturate_int_LowerSat
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 206;
	
	  ;% twa_parallel_P.TSamp_WtEt_p
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 212;
	
	  ;% twa_parallel_P.UD_X0_f
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 213;
	
	  ;% twa_parallel_P.Kd_Gain
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 214;
	
	  ;% twa_parallel_P.Saturation_UpperSat
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 220;
	
	  ;% twa_parallel_P.Saturation_LowerSat
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 226;
	
	  ;% twa_parallel_P.pid_mode_Value
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 232;
	
	  ;% twa_parallel_P.manual_current_Value
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 233;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% twa_parallel_P.NSampleEnable_TARGETCNT
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_P.NSampleEnable_ACTLEVEL
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (twa_parallel_B)
    ;%
      section.nData     = 71;
      section.data(71)  = dumData; %prealloc
      
	  ;% twa_parallel_B.EncoderInput_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_B.EncoderInput_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_B.EncoderInput_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% twa_parallel_B.EncoderInput_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% twa_parallel_B.EncoderInput_o5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% twa_parallel_B.EncoderInput_o6
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% twa_parallel_B.enc_res
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% twa_parallel_B.gear_ratio
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% twa_parallel_B.enc_res_l
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% twa_parallel_B.gear_ratio_p
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% twa_parallel_B.enc_res_f
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% twa_parallel_B.gear_ratio_c
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% twa_parallel_B.enc_res_c
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% twa_parallel_B.gear_ratio_l
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% twa_parallel_B.enc_res_fa
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% twa_parallel_B.gear_ratio_j
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% twa_parallel_B.enc_res_b
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% twa_parallel_B.gear_ratio_n
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% twa_parallel_B.TmpSignalConversionAtDiscreteFI
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% twa_parallel_B.DiscreteFIRFilter
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 24;
	
	  ;% twa_parallel_B.Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% twa_parallel_B.TSamp
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 36;
	
	  ;% twa_parallel_B.Uk1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 42;
	
	  ;% twa_parallel_B.Diff
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 48;
	
	  ;% twa_parallel_B.DiscreteFIRFilter_h
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 54;
	
	  ;% twa_parallel_B.Gain_n
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 60;
	
	  ;% twa_parallel_B.HiddenBuf_InsertedFor_Homing_at
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 66;
	
	  ;% twa_parallel_B.UnitDelay1
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 67;
	
	  ;% twa_parallel_B.UnitDelay2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 70;
	
	  ;% twa_parallel_B.cntrl_switch
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 73;
	
	  ;% twa_parallel_B.DigitalClock
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 79;
	
	  ;% twa_parallel_B.UnitDelay
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 80;
	
	  ;% twa_parallel_B.UnitDelay1_b
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 81;
	
	  ;% twa_parallel_B.UnitDelay2_n
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 82;
	
	  ;% twa_parallel_B.Switch
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 88;
	
	  ;% twa_parallel_B.Sum
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 94;
	
	  ;% twa_parallel_B.Kp
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 100;
	
	  ;% twa_parallel_B.Integrator
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 106;
	
	  ;% twa_parallel_B.Ki
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 112;
	
	  ;% twa_parallel_B.saturate_int
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 118;
	
	  ;% twa_parallel_B.TSamp_h
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 124;
	
	  ;% twa_parallel_B.Uk1_j
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 130;
	
	  ;% twa_parallel_B.Diff_d
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 136;
	
	  ;% twa_parallel_B.Kd
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 142;
	
	  ;% twa_parallel_B.Add
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 148;
	
	  ;% twa_parallel_B.Saturation
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 154;
	
	  ;% twa_parallel_B.Switch_i
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 160;
	
	  ;% twa_parallel_B.TmpSignalConversionAtSFunctionI
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 166;
	
	  ;% twa_parallel_B.theta_mu
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 172;
	
	  ;% twa_parallel_B.TmpSignalConversionAtSFunctio_d
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 175;
	
	  ;% twa_parallel_B.qmacro_des
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 181;
	
	  ;% twa_parallel_B.des_macro_len
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 184;
	
	  ;% twa_parallel_B.micro_len_out
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 187;
	
	  ;% twa_parallel_B.TmpSignalConversionAtSFunctio_c
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 190;
	
	  ;% twa_parallel_B.q_cmd
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 196;
	
	  ;% twa_parallel_B.q_dot
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 202;
	
	  ;% twa_parallel_B.q_dub_dot
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 208;
	
	  ;% twa_parallel_B.confn
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 214;
	
	  ;% twa_parallel_B.t0n
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 215;
	
	  ;% twa_parallel_B.q0n
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 216;
	
	  ;% twa_parallel_B.robot_mov
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 222;
	
	  ;% twa_parallel_B.UnitDelay1_p
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 223;
	
	  ;% twa_parallel_B.UnitDelay4
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 226;
	
	  ;% twa_parallel_B.UnitDelay3
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 229;
	
	  ;% twa_parallel_B.UnitDelay2_j
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 232;
	
	  ;% twa_parallel_B.TmpSignalConversionAtSFunctio_n
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 241;
	
	  ;% twa_parallel_B.qcmd
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 247;
	
	  ;% twa_parallel_B.des_leg_len
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 253;
	
	  ;% twa_parallel_B.eq_out
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 256;
	
	  ;% twa_parallel_B.twave_out
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 259;
	
	  ;% twa_parallel_B.rwave_out
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 262;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% twa_parallel_B.NSampleEnable
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (twa_parallel_DWork)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.DiscreteFIRFilter_states
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.UD_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% twa_parallel_DWork.DiscreteFIRFilter_states_m
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 12;
	
	  ;% twa_parallel_DWork.UnitDelay1_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 18;
	
	  ;% twa_parallel_DWork.UnitDelay2_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 21;
	
	  ;% twa_parallel_DWork.UnitDelay_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 24;
	
	  ;% twa_parallel_DWork.UnitDelay1_DSTATE_h
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 25;
	
	  ;% twa_parallel_DWork.UnitDelay2_DSTATE_k
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 26;
	
	  ;% twa_parallel_DWork.UD_DSTATE_o
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 32;
	
	  ;% twa_parallel_DWork.UnitDelay1_DSTATE_f
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 38;
	
	  ;% twa_parallel_DWork.UnitDelay4_DSTATE
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 41;
	
	  ;% twa_parallel_DWork.UnitDelay3_DSTATE
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 44;
	
	  ;% twa_parallel_DWork.UnitDelay2_DSTATE_l
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.DiscreteFIRFilter_circBuf
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.DiscreteFIRFilter_circBuf_l
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.NSampleEnable_Counter
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.SFunction_IWORK.AcquireOK
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.SFunction_IWORK_j.AcquireOK
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_DWork.SFunction_IWORK_i.AcquireOK
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% twa_parallel_DWork.SFunction_IWORK_m.AcquireOK
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
	  ;% twa_parallel_DWork.SFunction_IWORK_a.AcquireOK
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.Homing_SubsysRanBC
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.is_active_c2_twa_parallel
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.is_active_c4_twa_parallel
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_DWork.is_active_c1_twa_parallel
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
	  ;% twa_parallel_DWork.is_active_c22_twa_parallel
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 3;
	
	  ;% twa_parallel_DWork.is_active_c3_twa_parallel
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.isStable
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_DWork.isStable_m
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit_k
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% twa_parallel_DWork.isStable_o
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit_p
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 5;
	
	  ;% twa_parallel_DWork.isStable_n
	  section.data(7).logicalSrcIdx = 33;
	  section.data(7).dtTransOffset = 6;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit_b
	  section.data(8).logicalSrcIdx = 34;
	  section.data(8).dtTransOffset = 7;
	
	  ;% twa_parallel_DWork.isStable_j
	  section.data(9).logicalSrcIdx = 35;
	  section.data(9).dtTransOffset = 8;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit_h
	  section.data(10).logicalSrcIdx = 36;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4278547763;
  targMap.checksum1 = 142775865;
  targMap.checksum2 = 3159325380;
  targMap.checksum3 = 3516417542;

