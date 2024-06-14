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
      section.nData     = 51;
      section.data(51)  = dumData; %prealloc
      
	  ;% twa_parallel_P.Init_P1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_P.Init_P2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_P.Init_P3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% twa_parallel_P.Init_P4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% twa_parallel_P.AnalogOutput_P1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% twa_parallel_P.EncoderInput_P1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% twa_parallel_P.EncoderInput_P2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 16;
	
	  ;% twa_parallel_P.enc_res_Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 17;
	
	  ;% twa_parallel_P.gear_ratio_Gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 18;
	
	  ;% twa_parallel_P.enc_res_Gain_j
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 19;
	
	  ;% twa_parallel_P.gear_ratio_Gain_i
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 20;
	
	  ;% twa_parallel_P.enc_res_Gain_jz
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 21;
	
	  ;% twa_parallel_P.gear_ratio_Gain_d
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 22;
	
	  ;% twa_parallel_P.enc_res_Gain_i
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 23;
	
	  ;% twa_parallel_P.gear_ratio_Gain_a
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 24;
	
	  ;% twa_parallel_P.enc_res_Gain_g
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 25;
	
	  ;% twa_parallel_P.gear_ratio_Gain_o
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 26;
	
	  ;% twa_parallel_P.enc_res_Gain_ij
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 27;
	
	  ;% twa_parallel_P.gear_ratio_Gain_da
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 28;
	
	  ;% twa_parallel_P.vel_filter_coeffs_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 29;
	
	  ;% twa_parallel_P.DiscreteFIRFilter_IC
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 31;
	
	  ;% twa_parallel_P.Gain_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 32;
	
	  ;% twa_parallel_P.TSamp_WtEt
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 33;
	
	  ;% twa_parallel_P.UD_X0
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 34;
	
	  ;% twa_parallel_P.enc_reset_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 35;
	
	  ;% twa_parallel_P.vel_filter_coeffs_Value_m
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 36;
	
	  ;% twa_parallel_P.DiscreteFIRFilter_IC_b
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 38;
	
	  ;% twa_parallel_P.Gain_Gain_d
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 39;
	
	  ;% twa_parallel_P.x_des_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 40;
	
	  ;% twa_parallel_P.ee_rot_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 43;
	
	  ;% twa_parallel_P.ee_velmex_pitch_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 44;
	
	  ;% twa_parallel_P.micro_leg_len_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 45;
	
	  ;% twa_parallel_P.cntrl_mode_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 48;
	
	  ;% twa_parallel_P.q_des_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 49;
	
	  ;% twa_parallel_P.tf_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 55;
	
	  ;% twa_parallel_P.UnitDelay_X0
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 56;
	
	  ;% twa_parallel_P.UnitDelay1_X0
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 57;
	
	  ;% twa_parallel_P.UnitDelay2_X0
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 58;
	
	  ;% twa_parallel_P.quintic_enable_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 64;
	
	  ;% twa_parallel_P.Kp_Gain
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 65;
	
	  ;% twa_parallel_P.Integrator_IC
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 71;
	
	  ;% twa_parallel_P.Ki_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 72;
	
	  ;% twa_parallel_P.saturate_int_UpperSat
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 78;
	
	  ;% twa_parallel_P.saturate_int_LowerSat
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 84;
	
	  ;% twa_parallel_P.TSamp_WtEt_p
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 90;
	
	  ;% twa_parallel_P.UD_X0_f
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 91;
	
	  ;% twa_parallel_P.Kd_Gain
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 92;
	
	  ;% twa_parallel_P.Saturation_UpperSat
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 98;
	
	  ;% twa_parallel_P.Saturation_LowerSat
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 104;
	
	  ;% twa_parallel_P.pid_mode_Value
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 110;
	
	  ;% twa_parallel_P.manual_current_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 111;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% twa_parallel_P.NSampleEnable_TARGETCNT
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_P.NSampleEnable_ACTLEVEL
	  section.data(2).logicalSrcIdx = 52;
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
      section.nData     = 57;
      section.data(57)  = dumData; %prealloc
      
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
	
	  ;% twa_parallel_B.Switch
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 66;
	
	  ;% twa_parallel_B.DigitalClock
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 72;
	
	  ;% twa_parallel_B.UnitDelay
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 73;
	
	  ;% twa_parallel_B.UnitDelay1
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 74;
	
	  ;% twa_parallel_B.UnitDelay2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 75;
	
	  ;% twa_parallel_B.Switch_f
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 81;
	
	  ;% twa_parallel_B.Sum
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 87;
	
	  ;% twa_parallel_B.Kp
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 93;
	
	  ;% twa_parallel_B.Integrator
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 99;
	
	  ;% twa_parallel_B.Ki
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 105;
	
	  ;% twa_parallel_B.saturate_int
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 111;
	
	  ;% twa_parallel_B.TSamp_h
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 117;
	
	  ;% twa_parallel_B.Uk1_j
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 123;
	
	  ;% twa_parallel_B.Diff_d
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 129;
	
	  ;% twa_parallel_B.Kd
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 135;
	
	  ;% twa_parallel_B.Add
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 141;
	
	  ;% twa_parallel_B.Saturation
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 147;
	
	  ;% twa_parallel_B.Switch_i
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 153;
	
	  ;% twa_parallel_B.TmpSignalConversionAtSFunctionI
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 159;
	
	  ;% twa_parallel_B.q_cmd
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 165;
	
	  ;% twa_parallel_B.q_dot
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 171;
	
	  ;% twa_parallel_B.q_dub_dot
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 177;
	
	  ;% twa_parallel_B.confn
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 183;
	
	  ;% twa_parallel_B.t0n
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 184;
	
	  ;% twa_parallel_B.q0n
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 185;
	
	  ;% twa_parallel_B.robot_mov
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 191;
	
	  ;% twa_parallel_B.TmpSignalConversionAtSFunctio_e
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 192;
	
	  ;% twa_parallel_B.qmicro_des
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 198;
	
	  ;% twa_parallel_B.TmpSignalConversionAtSFunctio_i
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 201;
	
	  ;% twa_parallel_B.qmacro_des
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 207;
	
	  ;% twa_parallel_B.macro_leg_len
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 210;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% twa_parallel_B.NSampleEnable
	  section.data(1).logicalSrcIdx = 57;
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
    nTotSects     = 6;
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
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.DiscreteFIRFilter_states
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.UD_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% twa_parallel_DWork.DiscreteFIRFilter_states_m
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 12;
	
	  ;% twa_parallel_DWork.UnitDelay_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 18;
	
	  ;% twa_parallel_DWork.UnitDelay1_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 19;
	
	  ;% twa_parallel_DWork.UnitDelay2_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 20;
	
	  ;% twa_parallel_DWork.UD_DSTATE_o
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.DiscreteFIRFilter_circBuf
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.DiscreteFIRFilter_circBuf_l
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.NSampleEnable_Counter
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.SFunction_IWORK.AcquireOK
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.SFunction_IWORK_j.AcquireOK
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_DWork.SFunction_IWORK_i.AcquireOK
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.is_active_c22_twa_parallel
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.is_active_c2_twa_parallel
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_DWork.is_active_c4_twa_parallel
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% twa_parallel_DWork.is_active_c1_twa_parallel
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% twa_parallel_DWork.isStable
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% twa_parallel_DWork.isStable_b
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit_m
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% twa_parallel_DWork.isStable_l
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit_n
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% twa_parallel_DWork.isStable_k
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
	  ;% twa_parallel_DWork.doneDoubleBufferReInit_f
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
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


  targMap.checksum0 = 2130740451;
  targMap.checksum1 = 1199217746;
  targMap.checksum2 = 4135643746;
  targMap.checksum3 = 3337905401;

