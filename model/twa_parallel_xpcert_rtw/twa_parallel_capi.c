#include "twa_parallel.h"
#include "rtw_capi.h"
#include "twa_parallel_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "cntrl_switch",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Encoders/Encoder Input/p1",
    "", 0, 0, 1, 0, 1 },

  { 2, 0, "Encoders/Encoder Input/p2",
    "", 1, 0, 1, 0, 1 },

  { 3, 0, "Encoders/Encoder Input/p3",
    "", 2, 0, 1, 0, 1 },

  { 4, 0, "Encoders/Encoder Input/p4",
    "", 3, 0, 1, 0, 1 },

  { 5, 0, "Encoders/Encoder Input/p5",
    "", 4, 0, 1, 0, 1 },

  { 6, 0, "Encoders/Encoder Input/p6",
    "", 5, 0, 1, 0, 1 },

  { 7, 1, "Homing/Homing/p1",
    "qcmd", 0, 0, 1, 0, 0 },

  { 8, 1, "Homing/Homing/p2",
    "des_leg_len", 1, 0, 2, 0, 0 },

  { 9, 1, "Homing/Homing/p3",
    "eq_out", 2, 0, 2, 0, 0 },

  { 10, 1, "Homing/Homing/p4",
    "twave_out", 3, 0, 2, 0, 0 },

  { 11, 1, "Homing/Homing/p5",
    "rwave_out", 4, 0, 3, 0, 0 },

  { 12, 2, "Homing/Unit Delay1",
    "", 0, 0, 2, 0, 0 },

  { 13, 2, "Homing/Unit Delay2",
    "", 0, 0, 3, 0, 0 },

  { 14, 2, "Homing/Unit Delay3",
    "", 0, 0, 2, 0, 0 },

  { 15, 2, "Homing/Unit Delay4",
    "", 0, 0, 2, 0, 0 },

  { 16, 0, "PID Controller/Kd",
    "", 0, 0, 0, 0, 0 },

  { 17, 0, "PID Controller/Ki",
    "", 0, 0, 0, 0, 0 },

  { 18, 0, "PID Controller/Kp",
    "", 0, 0, 0, 0, 0 },

  { 19, 0, "PID Controller/Integrator",
    "", 0, 0, 0, 0, 1 },

  { 20, 0, "PID Controller/Saturation",
    "", 0, 0, 0, 0, 0 },

  { 21, 0, "PID Controller/saturate_int",
    "", 0, 0, 0, 0, 0 },

  { 22, 0, "PID Controller/Add",
    "", 0, 0, 0, 0, 0 },

  { 23, 0, "PID Controller/Sum",
    "", 0, 0, 0, 0, 0 },

  { 24, 0, "PID Controller/Switch",
    "", 0, 0, 0, 0, 0 },

  { 25, 3, "Quintic Poly/Embedded MATLAB Function/p1",
    "q_cmd", 0, 0, 0, 0, 0 },

  { 26, 3, "Quintic Poly/Embedded MATLAB Function/p2",
    "q_dot", 1, 0, 0, 0, 0 },

  { 27, 3, "Quintic Poly/Embedded MATLAB Function/p3",
    "q_dub_dot", 2, 0, 0, 0, 0 },

  { 28, 3, "Quintic Poly/Embedded MATLAB Function/p4",
    "confn", 3, 0, 1, 0, 0 },

  { 29, 3, "Quintic Poly/Embedded MATLAB Function/p5",
    "t0n", 4, 0, 1, 0, 0 },

  { 30, 3, "Quintic Poly/Embedded MATLAB Function/p6",
    "q0n", 5, 0, 0, 0, 0 },

  { 31, 3, "Quintic Poly/Embedded MATLAB Function/p7",
    "robot_mov", 6, 0, 1, 0, 0 },

  { 32, 0, "Quintic Poly/Digital Clock",
    "", 0, 0, 1, 0, 0 },

  { 33, 0, "Quintic Poly/Unit Delay",
    "", 0, 0, 1, 0, 0 },

  { 34, 0, "Quintic Poly/Unit Delay1",
    "", 0, 0, 1, 0, 0 },

  { 35, 0, "Quintic Poly/Unit Delay2",
    "", 0, 0, 0, 0, 0 },

  { 36, 5, "task_space/ResolvedRates/p1",
    "qdes", 0, 0, 0, 0, 0 },

  { 37, 5, "task_space/ResolvedRates/p2",
    "xcur", 1, 0, 2, 0, 0 },

  { 38, 5, "task_space/ResolvedRates/p3",
    "eerot", 2, 0, 1, 0, 0 },

  { 39, 0, "task_space/t_in_w",
    "", 0, 0, 3, 0, 0 },

  { 40, 0, "task_space/twa_flange_offset",
    "", 0, 0, 1, 0, 0 },

  { 41, 0, "task_space/twa_gamma",
    "", 0, 0, 1, 0, 0 },

  { 42, 0, "task_space/use_twa",
    "", 0, 0, 1, 0, 0 },

  { 43, 0, "task_space/Unit Delay1",
    "", 0, 0, 0, 0, 0 },

  { 44, 0, "task_space/Unit Delay3",
    "", 0, 0, 1, 0, 0 },

  { 45, 0, "task_space/Unit Delay4",
    "", 0, 0, 2, 0, 0 },

  { 46, 0, "Encoders/Counts To Turns1/enc_res",
    "", 0, 0, 1, 0, 0 },

  { 47, 0, "Encoders/Counts To Turns1/gear_ratio",
    "", 0, 0, 1, 0, 0 },

  { 48, 0, "Encoders/Counts To Turns2/enc_res",
    "", 0, 0, 1, 0, 0 },

  { 49, 0, "Encoders/Counts To Turns2/gear_ratio",
    "", 0, 0, 1, 0, 0 },

  { 50, 0, "Encoders/Counts To Turns3/enc_res",
    "", 0, 0, 1, 0, 0 },

  { 51, 0, "Encoders/Counts To Turns3/gear_ratio",
    "", 0, 0, 1, 0, 0 },

  { 52, 0, "Encoders/Counts To Turns4/enc_res",
    "", 0, 0, 1, 0, 0 },

  { 53, 0, "Encoders/Counts To Turns4/gear_ratio",
    "", 0, 0, 1, 0, 0 },

  { 54, 0, "Encoders/Counts To Turns5/enc_res",
    "", 0, 0, 1, 0, 0 },

  { 55, 0, "Encoders/Counts To Turns5/gear_ratio",
    "", 0, 0, 1, 0, 0 },

  { 56, 0, "Encoders/Counts To Turns6/enc_res",
    "", 0, 0, 1, 0, 0 },

  { 57, 0, "Encoders/Counts To Turns6/gear_ratio",
    "", 0, 0, 1, 0, 0 },

  { 58, 0, "PID Controller/Discrete Derivative/Diff",
    "", 0, 0, 0, 0, 0 },

  { 59, 0, "PID Controller/Discrete Derivative/UD",
    "U(k-1)", 0, 0, 0, 0, 0 },

  { 60, 0, "PID Controller/Discrete Derivative/TSamp",
    "", 0, 0, 0, 0, 0 },

  { 61, 0, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "", 0, 1, 1, 0, 0 },

  { 62, 0, "Quintic Poly/N-Sample Switch/Switch",
    "", 0, 0, 0, 0, 0 },

  { 63, 0, "Scopes/Fir Filter/Gain",
    "", 0, 0, 0, 0, 0 },

  { 64, 0, "Scopes/Fir Filter/Discrete FIR Filter",
    "", 0, 0, 0, 0, 0 },

  { 65, 4, "Scopes/norm/Embedded MATLAB Function",
    "y", 0, 0, 1, 0, 0 },

  { 66, 0, "Encoders/Derivative/Discrete Derivative/Diff",
    "", 0, 0, 0, 0, 0 },

  { 67, 0, "Encoders/Derivative/Discrete Derivative/UD",
    "U(k-1)", 0, 0, 0, 0, 0 },

  { 68, 0, "Encoders/Derivative/Discrete Derivative/TSamp",
    "", 0, 0, 0, 0, 0 },

  { 69, 0, "Encoders/Derivative/Fir Filter/Gain",
    "", 0, 0, 0, 0, 0 },

  { 70, 0, "Encoders/Derivative/Fir Filter/Discrete FIR Filter",
    "", 0, 0, 0, 0, 0 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 71, "cntrl_mode",
    "Value", 0, 1, 0 },

  { 72, "do_homing",
    "Value", 0, 1, 0 },

  { 73, "q_des",
    "Value", 0, 0, 0 },

  { 74, "Analog Output",
    "P1", 0, 4, 0 },

  { 75, "Init",
    "P1", 0, 1, 0 },

  { 76, "Init",
    "P2", 0, 1, 0 },

  { 77, "Init",
    "P3", 0, 1, 0 },

  { 78, "Init",
    "P4", 0, 1, 0 },

  { 79, "Encoders/enc_reset",
    "Value", 0, 1, 0 },

  { 80, "Encoders/Encoder Input",
    "P1", 0, 4, 0 },

  { 81, "Encoders/Encoder Input",
    "P2", 0, 1, 0 },

  { 82, "Homing/b_in_w",
    "Value", 0, 3, 0 },

  { 83, "Homing/dt",
    "Value", 0, 1, 0 },

  { 84, "Homing/eq_eps",
    "Value", 0, 1, 0 },

  { 85, "Homing/f_in_w",
    "Value", 0, 3, 0 },

  { 86, "Homing/kp",
    "Value", 0, 1, 0 },

  { 87, "Homing/m_in_w",
    "Value", 0, 3, 0 },

  { 88, "Homing/meas_macro_len",
    "Value", 0, 2, 0 },

  { 89, "Homing/p_in_m",
    "Value", 0, 3, 0 },

  { 90, "Homing/velmex_pitch",
    "Value", 0, 1, 0 },

  { 91, "Homing/Unit Delay1",
    "X0", 0, 2, 0 },

  { 92, "Homing/Unit Delay2",
    "X0", 0, 3, 0 },

  { 93, "Homing/Unit Delay3",
    "X0", 0, 2, 0 },

  { 94, "Homing/Unit Delay4",
    "X0", 0, 2, 0 },

  { 95, "PID Controller/manual_current",
    "Value", 0, 0, 0 },

  { 96, "PID Controller/pid_mode",
    "Value", 0, 1, 0 },

  { 97, "PID Controller/reset_integrator",
    "Value", 0, 1, 0 },

  { 98, "PID Controller/Kd",
    "Gain", 0, 0, 0 },

  { 99, "PID Controller/Ki",
    "Gain", 0, 0, 0 },

  { 100, "PID Controller/Kp",
    "Gain", 0, 0, 0 },

  { 101, "PID Controller/Integrator",
    "InitialCondition", 0, 1, 0 },

  { 102, "PID Controller/Saturation",
    "UpperLimit", 0, 4, 0 },

  { 103, "PID Controller/Saturation",
    "LowerLimit", 0, 4, 0 },

  { 104, "PID Controller/saturate_int",
    "UpperLimit", 0, 4, 0 },

  { 105, "PID Controller/saturate_int",
    "LowerLimit", 0, 4, 0 },

  { 106, "Quintic Poly/quintic_enable",
    "Value", 0, 1, 0 },

  { 107, "Quintic Poly/tf",
    "Value", 0, 1, 0 },

  { 108, "Quintic Poly/Unit Delay",
    "X0", 0, 1, 0 },

  { 109, "Quintic Poly/Unit Delay1",
    "X0", 0, 1, 0 },

  { 110, "Quintic Poly/Unit Delay2",
    "X0", 0, 0, 0 },

  { 111, "task_space/b_in_w",
    "Value", 0, 3, 0 },

  { 112, "task_space/dt",
    "Value", 0, 1, 0 },

  { 113, "task_space/ee_rot_des",
    "Value", 0, 1, 0 },

  { 114, "task_space/f_in_w",
    "Value", 0, 3, 0 },

  { 115, "task_space/m_in_w",
    "Value", 0, 3, 0 },

  { 116, "task_space/p_in_m",
    "Value", 0, 3, 0 },

  { 117, "task_space/t_in_w",
    "Value", 0, 3, 0 },

  { 118, "task_space/twa_flange_offset",
    "Value", 0, 1, 0 },

  { 119, "task_space/twa_gamma",
    "Value", 0, 1, 0 },

  { 120, "task_space/use_twa",
    "Value", 0, 1, 0 },

  { 121, "task_space/x_des",
    "Value", 0, 2, 0 },

  { 122, "task_space/Unit Delay1",
    "X0", 0, 0, 0 },

  { 123, "task_space/Unit Delay3",
    "X0", 0, 1, 0 },

  { 124, "task_space/Unit Delay4",
    "X0", 0, 2, 0 },

  { 125, "Encoders/Counts To Turns1/enc_res",
    "Gain", 0, 1, 0 },

  { 126, "Encoders/Counts To Turns1/gear_ratio",
    "Gain", 0, 1, 0 },

  { 127, "Encoders/Counts To Turns2/enc_res",
    "Gain", 0, 1, 0 },

  { 128, "Encoders/Counts To Turns2/gear_ratio",
    "Gain", 0, 1, 0 },

  { 129, "Encoders/Counts To Turns3/enc_res",
    "Gain", 0, 1, 0 },

  { 130, "Encoders/Counts To Turns3/gear_ratio",
    "Gain", 0, 1, 0 },

  { 131, "Encoders/Counts To Turns4/enc_res",
    "Gain", 0, 1, 0 },

  { 132, "Encoders/Counts To Turns4/gear_ratio",
    "Gain", 0, 1, 0 },

  { 133, "Encoders/Counts To Turns5/enc_res",
    "Gain", 0, 1, 0 },

  { 134, "Encoders/Counts To Turns5/gear_ratio",
    "Gain", 0, 1, 0 },

  { 135, "Encoders/Counts To Turns6/enc_res",
    "Gain", 0, 1, 0 },

  { 136, "Encoders/Counts To Turns6/gear_ratio",
    "Gain", 0, 1, 0 },

  { 137, "PID Controller/Discrete Derivative/UD",
    "X0", 0, 1, 0 },

  { 138, "PID Controller/Discrete Derivative/TSamp",
    "WtEt", 0, 1, 0 },

  { 139, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "TARGETCNT", 2, 1, 0 },

  { 140, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "ACTLEVEL", 2, 1, 0 },

  { 141, "Scopes/Fir Filter/vel_filter_coeffs",
    "Value", 0, 5, 0 },

  { 142, "Scopes/Fir Filter/Gain",
    "Gain", 0, 1, 0 },

  { 143, "Scopes/Fir Filter/Discrete FIR Filter",
    "IC", 0, 1, 0 },

  { 144, "Encoders/Derivative/Discrete Derivative/UD",
    "X0", 0, 1, 0 },

  { 145, "Encoders/Derivative/Discrete Derivative/TSamp",
    "WtEt", 0, 1, 0 },

  { 146, "Encoders/Derivative/Fir Filter/vel_filter_coeffs",
    "Value", 0, 5, 0 },

  { 147, "Encoders/Derivative/Fir Filter/Gain",
    "Gain", 0, 1, 0 },

  { 148, "Encoders/Derivative/Fir Filter/Discrete FIR Filter",
    "IC", 0, 1, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &twa_parallel_B.cntrl_switch[0],     /* 0: Signal */
  &twa_parallel_B.EncoderInput_o1,     /* 1: Signal */
  &twa_parallel_B.EncoderInput_o2,     /* 2: Signal */
  &twa_parallel_B.EncoderInput_o3,     /* 3: Signal */
  &twa_parallel_B.EncoderInput_o4,     /* 4: Signal */
  &twa_parallel_B.EncoderInput_o5,     /* 5: Signal */
  &twa_parallel_B.EncoderInput_o6,     /* 6: Signal */
  &twa_parallel_B.qcmd,                /* 7: Signal */
  &twa_parallel_B.des_leg_len[0],      /* 8: Signal */
  &twa_parallel_B.eq_out[0],           /* 9: Signal */
  &twa_parallel_B.twave_out[0],        /* 10: Signal */
  &twa_parallel_B.rwave_out[0],        /* 11: Signal */
  &twa_parallel_B.UnitDelay1_p[0],     /* 12: Signal */
  &twa_parallel_B.UnitDelay2_j[0],     /* 13: Signal */
  &twa_parallel_B.UnitDelay3_b[0],     /* 14: Signal */
  &twa_parallel_B.UnitDelay4_e[0],     /* 15: Signal */
  &twa_parallel_B.Kd[0],               /* 16: Signal */
  &twa_parallel_B.Ki[0],               /* 17: Signal */
  &twa_parallel_B.Kp[0],               /* 18: Signal */
  &twa_parallel_B.Integrator[0],       /* 19: Signal */
  &twa_parallel_B.Saturation[0],       /* 20: Signal */
  &twa_parallel_B.saturate_int[0],     /* 21: Signal */
  &twa_parallel_B.Add[0],              /* 22: Signal */
  &twa_parallel_B.Sum[0],              /* 23: Signal */
  &twa_parallel_B.Switch_i[0],         /* 24: Signal */
  &twa_parallel_B.q_cmd[0],            /* 25: Signal */
  &twa_parallel_B.q_dot[0],            /* 26: Signal */
  &twa_parallel_B.q_dub_dot[0],        /* 27: Signal */
  &twa_parallel_B.confn,               /* 28: Signal */
  &twa_parallel_B.t0n,                 /* 29: Signal */
  &twa_parallel_B.q0n[0],              /* 30: Signal */
  &twa_parallel_B.robot_mov,           /* 31: Signal */
  &twa_parallel_B.DigitalClock,        /* 32: Signal */
  &twa_parallel_B.UnitDelay,           /* 33: Signal */
  &twa_parallel_B.UnitDelay1_b,        /* 34: Signal */
  &twa_parallel_B.UnitDelay2[0],       /* 35: Signal */
  &twa_parallel_B.qdes[0],             /* 36: Signal */
  &twa_parallel_B.xcur[0],             /* 37: Signal */
  &twa_parallel_B.eerot,               /* 38: Signal */
  &twa_parallel_B.t_in_w[0],           /* 39: Signal */
  &twa_parallel_B.twa_flange_offset,   /* 40: Signal */
  &twa_parallel_B.twa_gamma,           /* 41: Signal */
  &twa_parallel_B.use_twa,             /* 42: Signal */
  &twa_parallel_B.UnitDelay1[0],       /* 43: Signal */
  &twa_parallel_B.UnitDelay3,          /* 44: Signal */
  &twa_parallel_B.UnitDelay4[0],       /* 45: Signal */
  &twa_parallel_B.enc_res,             /* 46: Signal */
  &twa_parallel_B.gear_ratio,          /* 47: Signal */
  &twa_parallel_B.enc_res_f,           /* 48: Signal */
  &twa_parallel_B.gear_ratio_c,        /* 49: Signal */
  &twa_parallel_B.enc_res_c,           /* 50: Signal */
  &twa_parallel_B.gear_ratio_l,        /* 51: Signal */
  &twa_parallel_B.enc_res_fa,          /* 52: Signal */
  &twa_parallel_B.gear_ratio_j,        /* 53: Signal */
  &twa_parallel_B.enc_res_b,           /* 54: Signal */
  &twa_parallel_B.gear_ratio_n,        /* 55: Signal */
  &twa_parallel_B.enc_res_e,           /* 56: Signal */
  &twa_parallel_B.gear_ratio_f,        /* 57: Signal */
  &twa_parallel_B.Diff_d[0],           /* 58: Signal */
  &twa_parallel_B.Uk1_j[0],            /* 59: Signal */
  &twa_parallel_B.TSamp_h[0],          /* 60: Signal */
  &twa_parallel_B.NSampleEnable,       /* 61: Signal */
  &twa_parallel_B.Switch[0],           /* 62: Signal */
  &twa_parallel_B.Gain_n[0],           /* 63: Signal */
  &twa_parallel_B.DiscreteFIRFilter_h[0],/* 64: Signal */
  &twa_parallel_B.y,                   /* 65: Signal */
  &twa_parallel_B.Diff[0],             /* 66: Signal */
  &twa_parallel_B.Uk1[0],              /* 67: Signal */
  &twa_parallel_B.TSamp[0],            /* 68: Signal */
  &twa_parallel_B.Gain[0],             /* 69: Signal */
  &twa_parallel_B.DiscreteFIRFilter[0],/* 70: Signal */
  &twa_parallel_P.cntrl_mode_Value,    /* 71: Block Parameter */
  &twa_parallel_P.do_homing_Value,     /* 72: Block Parameter */
  &twa_parallel_P.q_des_Value[0],      /* 73: Block Parameter */
  &twa_parallel_P.AnalogOutput_P1[0],  /* 74: Block Parameter */
  &twa_parallel_P.Init_P1,             /* 75: Block Parameter */
  &twa_parallel_P.Init_P2,             /* 76: Block Parameter */
  &twa_parallel_P.Init_P3,             /* 77: Block Parameter */
  &twa_parallel_P.Init_P4,             /* 78: Block Parameter */
  &twa_parallel_P.enc_reset_Value,     /* 79: Block Parameter */
  &twa_parallel_P.EncoderInput_P1[0],  /* 80: Block Parameter */
  &twa_parallel_P.EncoderInput_P2,     /* 81: Block Parameter */
  &twa_parallel_P.b_in_w_Value[0],     /* 82: Block Parameter */
  &twa_parallel_P.dt_Value,            /* 83: Block Parameter */
  &twa_parallel_P.eq_eps_Value,        /* 84: Block Parameter */
  &twa_parallel_P.f_in_w_Value[0],     /* 85: Block Parameter */
  &twa_parallel_P.kp_Value,            /* 86: Block Parameter */
  &twa_parallel_P.m_in_w_Value[0],     /* 87: Block Parameter */
  &twa_parallel_P.meas_macro_len_Value[0],/* 88: Block Parameter */
  &twa_parallel_P.p_in_m_Value[0],     /* 89: Block Parameter */
  &twa_parallel_P.velmex_pitch_Value,  /* 90: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0[0],    /* 91: Block Parameter */
  &twa_parallel_P.UnitDelay2_X0[0],    /* 92: Block Parameter */
  &twa_parallel_P.UnitDelay3_X0[0],    /* 93: Block Parameter */
  &twa_parallel_P.UnitDelay4_X0[0],    /* 94: Block Parameter */
  &twa_parallel_P.manual_current_Value[0],/* 95: Block Parameter */
  &twa_parallel_P.pid_mode_Value,      /* 96: Block Parameter */
  &twa_parallel_P.reset_integrator_Value,/* 97: Block Parameter */
  &twa_parallel_P.Kd_Gain[0],          /* 98: Block Parameter */
  &twa_parallel_P.Ki_Gain[0],          /* 99: Block Parameter */
  &twa_parallel_P.Kp_Gain[0],          /* 100: Block Parameter */
  &twa_parallel_P.Integrator_IC,       /* 101: Block Parameter */
  &twa_parallel_P.Saturation_UpperSat[0],/* 102: Block Parameter */
  &twa_parallel_P.Saturation_LowerSat[0],/* 103: Block Parameter */
  &twa_parallel_P.saturate_int_UpperSat[0],/* 104: Block Parameter */
  &twa_parallel_P.saturate_int_LowerSat[0],/* 105: Block Parameter */
  &twa_parallel_P.quintic_enable_Value,/* 106: Block Parameter */
  &twa_parallel_P.tf_Value,            /* 107: Block Parameter */
  &twa_parallel_P.UnitDelay_X0,        /* 108: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0_h,     /* 109: Block Parameter */
  &twa_parallel_P.UnitDelay2_X0_d[0],  /* 110: Block Parameter */
  &twa_parallel_P.b_in_w_Value_i[0],   /* 111: Block Parameter */
  &twa_parallel_P.dt_Value_n,          /* 112: Block Parameter */
  &twa_parallel_P.ee_rot_des_Value,    /* 113: Block Parameter */
  &twa_parallel_P.f_in_w_Value_b[0],   /* 114: Block Parameter */
  &twa_parallel_P.m_in_w_Value_n[0],   /* 115: Block Parameter */
  &twa_parallel_P.p_in_m_Value_m[0],   /* 116: Block Parameter */
  &twa_parallel_P.t_in_w_Value[0],     /* 117: Block Parameter */
  &twa_parallel_P.twa_flange_offset_Value,/* 118: Block Parameter */
  &twa_parallel_P.twa_gamma_Value,     /* 119: Block Parameter */
  &twa_parallel_P.use_twa_Value,       /* 120: Block Parameter */
  &twa_parallel_P.x_des_Value[0],      /* 121: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0_g[0],  /* 122: Block Parameter */
  &twa_parallel_P.UnitDelay3_X0_b,     /* 123: Block Parameter */
  &twa_parallel_P.UnitDelay4_X0_l[0],  /* 124: Block Parameter */
  &twa_parallel_P.enc_res_Gain,        /* 125: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain,     /* 126: Block Parameter */
  &twa_parallel_P.enc_res_Gain_j,      /* 127: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_d,   /* 128: Block Parameter */
  &twa_parallel_P.enc_res_Gain_i,      /* 129: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_a,   /* 130: Block Parameter */
  &twa_parallel_P.enc_res_Gain_g,      /* 131: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_o,   /* 132: Block Parameter */
  &twa_parallel_P.enc_res_Gain_ij,     /* 133: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_da,  /* 134: Block Parameter */
  &twa_parallel_P.enc_res_Gain_m,      /* 135: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_c,   /* 136: Block Parameter */
  &twa_parallel_P.UD_X0_f,             /* 137: Block Parameter */
  &twa_parallel_P.TSamp_WtEt_p,        /* 138: Block Parameter */
  &twa_parallel_P.NSampleEnable_TARGETCNT,/* 139: Block Parameter */
  &twa_parallel_P.NSampleEnable_ACTLEVEL,/* 140: Block Parameter */
  &twa_parallel_P.vel_filter_coeffs_Value_m[0],/* 141: Block Parameter */
  &twa_parallel_P.Gain_Gain_d,         /* 142: Block Parameter */
  &twa_parallel_P.DiscreteFIRFilter_IC_b,/* 143: Block Parameter */
  &twa_parallel_P.UD_X0,               /* 144: Block Parameter */
  &twa_parallel_P.TSamp_WtEt,          /* 145: Block Parameter */
  &twa_parallel_P.vel_filter_coeffs_Value[0],/* 146: Block Parameter */
  &twa_parallel_P.Gain_Gain,           /* 147: Block Parameter */
  &twa_parallel_P.DiscreteFIRFilter_IC /* 148: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_VECTOR, 0, 2, 0 },

  { rtwCAPI_SCALAR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  6,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  1,                                   /* 3 */
  3,                                   /* 4 */
  1,                                   /* 5 */
  3,                                   /* 6 */
  3,                                   /* 7 */
  1,                                   /* 8 */
  6,                                   /* 9 */
  2,                                   /* 10 */
  1                                    /* 11 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.002, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 71 },

  { rtBlockParameters, 78,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void twa_parallel_InitializeDataMapInfo(rtModel_twa_parallel *twa_parallel_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(twa_parallel_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(twa_parallel_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(twa_parallel_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(twa_parallel_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(twa_parallel_rtM->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(twa_parallel_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(twa_parallel_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(twa_parallel_rtM->DataMapInfo.mmi, 0);
}
