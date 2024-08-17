#include "twa_parallel.h"
#include "rtw_capi.h"
#include "twa_parallel_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Encoders/Encoder Input/p1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Encoders/Encoder Input/p2",
    "", 1, 0, 0, 0, 0 },

  { 2, 0, "Encoders/Encoder Input/p3",
    "", 2, 0, 0, 0, 0 },

  { 3, 0, "Encoders/Encoder Input/p4",
    "", 3, 0, 0, 0, 0 },

  { 4, 0, "Encoders/Encoder Input/p5",
    "", 4, 0, 0, 0, 0 },

  { 5, 0, "Encoders/Encoder Input/p6",
    "", 5, 0, 0, 0, 0 },

  { 6, 0, "PID Controller/Kd",
    "", 0, 0, 1, 0, 1 },

  { 7, 0, "PID Controller/Ki",
    "", 0, 0, 1, 0, 1 },

  { 8, 0, "PID Controller/Kp",
    "", 0, 0, 1, 0, 1 },

  { 9, 0, "PID Controller/Integrator",
    "", 0, 0, 1, 0, 0 },

  { 10, 0, "PID Controller/Saturation",
    "", 0, 0, 1, 0, 1 },

  { 11, 0, "PID Controller/saturate_int",
    "", 0, 0, 1, 0, 1 },

  { 12, 0, "PID Controller/Add",
    "", 0, 0, 1, 0, 1 },

  { 13, 0, "PID Controller/Sum",
    "", 0, 0, 1, 0, 1 },

  { 14, 0, "PID Controller/Switch",
    "", 0, 0, 1, 0, 1 },

  { 15, 1, "Quintic Poly/Embedded MATLAB Function/p1",
    "q_cmd", 0, 0, 1, 0, 1 },

  { 16, 1, "Quintic Poly/Embedded MATLAB Function/p2",
    "q_dot", 1, 0, 1, 0, 1 },

  { 17, 1, "Quintic Poly/Embedded MATLAB Function/p3",
    "q_dub_dot", 2, 0, 1, 0, 1 },

  { 18, 1, "Quintic Poly/Embedded MATLAB Function/p4",
    "confn", 3, 0, 0, 0, 1 },

  { 19, 1, "Quintic Poly/Embedded MATLAB Function/p5",
    "t0n", 4, 0, 0, 0, 1 },

  { 20, 1, "Quintic Poly/Embedded MATLAB Function/p6",
    "q0n", 5, 0, 1, 0, 1 },

  { 21, 1, "Quintic Poly/Embedded MATLAB Function/p7",
    "robot_mov", 6, 0, 0, 0, 1 },

  { 22, 0, "Quintic Poly/Digital Clock",
    "", 0, 0, 0, 0, 1 },

  { 23, 0, "Quintic Poly/Unit Delay",
    "", 0, 0, 0, 0, 1 },

  { 24, 0, "Quintic Poly/Unit Delay1",
    "", 0, 0, 0, 0, 1 },

  { 25, 0, "Quintic Poly/Unit Delay2",
    "", 0, 0, 1, 0, 1 },

  { 26, 0, "control_mode/control_switch",
    "", 0, 0, 1, 0, 1 },

  { 27, 0, "control_mode/Unit Delay1",
    "", 0, 0, 1, 0, 1 },

  { 28, 0, "Encoders/Counts To Turns1/enc_res",
    "", 0, 0, 0, 0, 1 },

  { 29, 0, "Encoders/Counts To Turns1/gear_ratio",
    "", 0, 0, 0, 0, 1 },

  { 30, 0, "Encoders/Counts To Turns1/velmex_pitch",
    "", 0, 0, 0, 0, 1 },

  { 31, 0, "Encoders/Counts To Turns2/enc_res",
    "", 0, 0, 0, 0, 1 },

  { 32, 0, "Encoders/Counts To Turns2/gear_ratio",
    "", 0, 0, 0, 0, 1 },

  { 33, 0, "Encoders/Counts To Turns2/velmex_pitch",
    "", 0, 0, 0, 0, 1 },

  { 34, 0, "Encoders/Counts To Turns3/enc_res",
    "", 0, 0, 0, 0, 1 },

  { 35, 0, "Encoders/Counts To Turns3/gear_ratio",
    "", 0, 0, 0, 0, 1 },

  { 36, 0, "Encoders/Counts To Turns3/velmex_pitch",
    "", 0, 0, 0, 0, 1 },

  { 37, 0, "Encoders/Counts To Turns4/enc_res",
    "", 0, 0, 0, 0, 1 },

  { 38, 0, "Encoders/Counts To Turns4/gear_ratio",
    "", 0, 0, 0, 0, 1 },

  { 39, 0, "Encoders/Counts To Turns5/enc_res",
    "", 0, 0, 0, 0, 1 },

  { 40, 0, "Encoders/Counts To Turns5/gear_ratio",
    "", 0, 0, 0, 0, 1 },

  { 41, 0, "Encoders/Counts To Turns6/enc_res",
    "", 0, 0, 0, 0, 1 },

  { 42, 0, "Encoders/Counts To Turns6/gear_ratio",
    "", 0, 0, 0, 0, 1 },

  { 43, 0, "PID Controller/Discrete Derivative/Diff",
    "", 0, 0, 1, 0, 1 },

  { 44, 0, "PID Controller/Discrete Derivative/UD",
    "U(k-1)", 0, 0, 1, 0, 1 },

  { 45, 0, "PID Controller/Discrete Derivative/TSamp",
    "", 0, 0, 1, 0, 1 },

  { 46, 0, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "", 0, 1, 0, 0, 1 },

  { 47, 0, "Quintic Poly/N-Sample Switch/Switch",
    "", 0, 0, 1, 0, 1 },

  { 48, 0, "Scopes/Fir Filter/Gain",
    "", 0, 0, 1, 0, 1 },

  { 49, 0, "Scopes/Fir Filter/Discrete FIR Filter",
    "", 0, 0, 1, 0, 1 },

  { 50, 0, "control_mode/detect change/Switch",
    "", 0, 0, 1, 0, 1 },

  { 51, 2, "control_mode/task_space/ResolvedRates/p1",
    "qeps", 0, 0, 1, 0, 1 },

  { 52, 2, "control_mode/task_space/ResolvedRates/p2",
    "xcur", 1, 0, 2, 0, 1 },

  { 53, 2, "control_mode/task_space/ResolvedRates/p3",
    "eerot", 2, 0, 0, 0, 1 },

  { 54, 2, "control_mode/task_space/ResolvedRates/p4",
    "qdes", 3, 0, 1, 0, 1 },

  { 55, 3, "control_mode/task_space/get_jacobian/p1",
    "full_jac", 0, 0, 3, 0, 1 },

  { 56, 3, "control_mode/task_space/get_jacobian/p2",
    "xcur", 1, 0, 2, 0, 1 },

  { 57, 3, "control_mode/task_space/get_jacobian/p3",
    "eerotcur", 2, 0, 0, 0, 1 },

  { 58, 0, "control_mode/task_space/t_in_w",
    "", 0, 0, 4, 0, 1 },

  { 59, 0, "control_mode/task_space/twa_flange_offset",
    "", 0, 0, 0, 0, 1 },

  { 60, 0, "control_mode/task_space/twa_gamma",
    "", 0, 0, 0, 0, 1 },

  { 61, 0, "control_mode/task_space/use_twa",
    "", 0, 0, 0, 0, 1 },

  { 62, 0, "control_mode/task_space/Unit Delay1",
    "", 0, 0, 1, 0, 1 },

  { 63, 0, "control_mode/task_space/Unit Delay3",
    "", 0, 0, 0, 0, 1 },

  { 64, 0, "control_mode/task_space/Unit Delay6",
    "", 0, 0, 2, 0, 1 },

  { 65, 0, "Encoders/Derivative/Discrete Derivative/Diff",
    "", 0, 0, 1, 0, 1 },

  { 66, 0, "Encoders/Derivative/Discrete Derivative/UD",
    "U(k-1)", 0, 0, 1, 0, 1 },

  { 67, 0, "Encoders/Derivative/Discrete Derivative/TSamp",
    "", 0, 0, 1, 0, 1 },

  { 68, 0, "Encoders/Derivative/Fir Filter/Gain",
    "", 0, 0, 1, 0, 1 },

  { 69, 0, "Encoders/Derivative/Fir Filter/Discrete FIR Filter",
    "", 0, 0, 1, 0, 1 },

  { 70, 0, "control_mode/detect change/Detect Change/FixPt Relational Operator",
    "", 0, 2, 1, 0, 1 },

  { 71, 0, "control_mode/detect change/Detect Change/Delay Input1",
    "U(k-1)", 0, 0, 1, 0, 1 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 72, "Analog Output",
    "P1", 0, 5, 0 },

  { 73, "Init",
    "P1", 0, 0, 0 },

  { 74, "Init",
    "P2", 0, 0, 0 },

  { 75, "Init",
    "P3", 0, 0, 0 },

  { 76, "Init",
    "P4", 0, 0, 0 },

  { 77, "Encoders/enc_reset1",
    "Value", 0, 0, 0 },

  { 78, "Encoders/enc_reset2",
    "Value", 0, 0, 0 },

  { 79, "Encoders/enc_reset3",
    "Value", 0, 0, 0 },

  { 80, "Encoders/enc_reset4",
    "Value", 0, 0, 0 },

  { 81, "Encoders/enc_reset5",
    "Value", 0, 0, 0 },

  { 82, "Encoders/enc_reset6",
    "Value", 0, 0, 0 },

  { 83, "Encoders/Encoder Input",
    "P1", 0, 5, 0 },

  { 84, "Encoders/Encoder Input",
    "P2", 0, 0, 0 },

  { 85, "PID Controller/manual_current",
    "Value", 0, 1, 0 },

  { 86, "PID Controller/pid_mode",
    "Value", 0, 0, 0 },

  { 87, "PID Controller/reset_integrator",
    "Value", 0, 0, 0 },

  { 88, "PID Controller/Kd",
    "Gain", 0, 1, 0 },

  { 89, "PID Controller/Ki",
    "Gain", 0, 1, 0 },

  { 90, "PID Controller/Kp",
    "Gain", 0, 1, 0 },

  { 91, "PID Controller/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 92, "PID Controller/Saturation",
    "UpperLimit", 0, 5, 0 },

  { 93, "PID Controller/Saturation",
    "LowerLimit", 0, 5, 0 },

  { 94, "PID Controller/saturate_int",
    "UpperLimit", 0, 5, 0 },

  { 95, "PID Controller/saturate_int",
    "LowerLimit", 0, 5, 0 },

  { 96, "Quintic Poly/quintic_enable",
    "Value", 0, 0, 0 },

  { 97, "Quintic Poly/tf",
    "Value", 0, 0, 0 },

  { 98, "Quintic Poly/Unit Delay",
    "X0", 0, 0, 0 },

  { 99, "Quintic Poly/Unit Delay1",
    "X0", 0, 0, 0 },

  { 100, "Quintic Poly/Unit Delay2",
    "X0", 0, 1, 0 },

  { 101, "control_mode/mode",
    "Value", 0, 0, 0 },

  { 102, "control_mode/q_des_usr",
    "Value", 0, 1, 0 },

  { 103, "control_mode/Unit Delay1",
    "X0", 0, 1, 0 },

  { 104, "Encoders/Counts To Turns1/enc_res",
    "Gain", 0, 0, 0 },

  { 105, "Encoders/Counts To Turns1/gear_ratio",
    "Gain", 0, 0, 0 },

  { 106, "Encoders/Counts To Turns1/velmex_pitch",
    "Gain", 0, 0, 0 },

  { 107, "Encoders/Counts To Turns2/enc_res",
    "Gain", 0, 0, 0 },

  { 108, "Encoders/Counts To Turns2/gear_ratio",
    "Gain", 0, 0, 0 },

  { 109, "Encoders/Counts To Turns2/velmex_pitch",
    "Gain", 0, 0, 0 },

  { 110, "Encoders/Counts To Turns3/enc_res",
    "Gain", 0, 0, 0 },

  { 111, "Encoders/Counts To Turns3/gear_ratio",
    "Gain", 0, 0, 0 },

  { 112, "Encoders/Counts To Turns3/velmex_pitch",
    "Gain", 0, 0, 0 },

  { 113, "Encoders/Counts To Turns4/enc_res",
    "Gain", 0, 0, 0 },

  { 114, "Encoders/Counts To Turns4/gear_ratio",
    "Gain", 0, 0, 0 },

  { 115, "Encoders/Counts To Turns5/enc_res",
    "Gain", 0, 0, 0 },

  { 116, "Encoders/Counts To Turns5/gear_ratio",
    "Gain", 0, 0, 0 },

  { 117, "Encoders/Counts To Turns6/enc_res",
    "Gain", 0, 0, 0 },

  { 118, "Encoders/Counts To Turns6/gear_ratio",
    "Gain", 0, 0, 0 },

  { 119, "PID Controller/Discrete Derivative/UD",
    "X0", 0, 0, 0 },

  { 120, "PID Controller/Discrete Derivative/TSamp",
    "WtEt", 0, 0, 0 },

  { 121, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "TARGETCNT", 3, 0, 0 },

  { 122, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "ACTLEVEL", 3, 0, 0 },

  { 123, "Scopes/Fir Filter/vel_filter_coeffs",
    "Value", 0, 6, 0 },

  { 124, "Scopes/Fir Filter/Gain",
    "Gain", 0, 0, 0 },

  { 125, "Scopes/Fir Filter/Discrete FIR Filter",
    "IC", 0, 0, 0 },

  { 126, "control_mode/task_space/b_in_w",
    "Value", 0, 4, 0 },

  { 127, "control_mode/task_space/dt",
    "Value", 0, 0, 0 },

  { 128, "control_mode/task_space/ee_rot_des",
    "Value", 0, 0, 0 },

  { 129, "control_mode/task_space/f_in_w",
    "Value", 0, 4, 0 },

  { 130, "control_mode/task_space/m_in_w",
    "Value", 0, 4, 0 },

  { 131, "control_mode/task_space/p_in_m",
    "Value", 0, 4, 0 },

  { 132, "control_mode/task_space/res_rate_param",
    "Value", 0, 7, 0 },

  { 133, "control_mode/task_space/t_in_w",
    "Value", 0, 4, 0 },

  { 134, "control_mode/task_space/twa_flange_offset",
    "Value", 0, 0, 0 },

  { 135, "control_mode/task_space/twa_gamma",
    "Value", 0, 0, 0 },

  { 136, "control_mode/task_space/use_twa",
    "Value", 0, 0, 0 },

  { 137, "control_mode/task_space/x_des",
    "Value", 0, 2, 0 },

  { 138, "control_mode/task_space/Unit Delay1",
    "X0", 0, 1, 0 },

  { 139, "control_mode/task_space/Unit Delay3",
    "X0", 0, 0, 0 },

  { 140, "control_mode/task_space/Unit Delay6",
    "X0", 0, 2, 0 },

  { 141, "Encoders/Derivative/Discrete Derivative/UD",
    "X0", 0, 0, 0 },

  { 142, "Encoders/Derivative/Discrete Derivative/TSamp",
    "WtEt", 0, 0, 0 },

  { 143, "Encoders/Derivative/Fir Filter/vel_filter_coeffs",
    "Value", 0, 6, 0 },

  { 144, "Encoders/Derivative/Fir Filter/Gain",
    "Gain", 0, 0, 0 },

  { 145, "Encoders/Derivative/Fir Filter/Discrete FIR Filter",
    "IC", 0, 0, 0 },

  { 146, "control_mode/detect change/Detect Change/Delay Input1",
    "X0", 0, 1, 0 },

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
  &twa_parallel_B.EncoderInput_o1,     /* 0: Signal */
  &twa_parallel_B.EncoderInput_o2,     /* 1: Signal */
  &twa_parallel_B.EncoderInput_o3,     /* 2: Signal */
  &twa_parallel_B.EncoderInput_o4,     /* 3: Signal */
  &twa_parallel_B.EncoderInput_o5,     /* 4: Signal */
  &twa_parallel_B.EncoderInput_o6,     /* 5: Signal */
  &twa_parallel_B.Kd[0],               /* 6: Signal */
  &twa_parallel_B.Ki[0],               /* 7: Signal */
  &twa_parallel_B.Kp[0],               /* 8: Signal */
  &twa_parallel_B.Integrator[0],       /* 9: Signal */
  &twa_parallel_B.Saturation[0],       /* 10: Signal */
  &twa_parallel_B.saturate_int[0],     /* 11: Signal */
  &twa_parallel_B.Add[0],              /* 12: Signal */
  &twa_parallel_B.Sum[0],              /* 13: Signal */
  &twa_parallel_B.Switch_i[0],         /* 14: Signal */
  &twa_parallel_B.q_cmd[0],            /* 15: Signal */
  &twa_parallel_B.q_dot[0],            /* 16: Signal */
  &twa_parallel_B.q_dub_dot[0],        /* 17: Signal */
  &twa_parallel_B.confn,               /* 18: Signal */
  &twa_parallel_B.t0n,                 /* 19: Signal */
  &twa_parallel_B.q0n[0],              /* 20: Signal */
  &twa_parallel_B.robot_mov,           /* 21: Signal */
  &twa_parallel_B.DigitalClock,        /* 22: Signal */
  &twa_parallel_B.UnitDelay,           /* 23: Signal */
  &twa_parallel_B.UnitDelay1_b,        /* 24: Signal */
  &twa_parallel_B.UnitDelay2[0],       /* 25: Signal */
  &twa_parallel_B.control_switch[0],   /* 26: Signal */
  &twa_parallel_B.UnitDelay1[0],       /* 27: Signal */
  &twa_parallel_B.enc_res,             /* 28: Signal */
  &twa_parallel_B.gear_ratio,          /* 29: Signal */
  &twa_parallel_B.velmex_pitch,        /* 30: Signal */
  &twa_parallel_B.enc_res_f,           /* 31: Signal */
  &twa_parallel_B.gear_ratio_c,        /* 32: Signal */
  &twa_parallel_B.velmex_pitch_e,      /* 33: Signal */
  &twa_parallel_B.enc_res_c,           /* 34: Signal */
  &twa_parallel_B.gear_ratio_l,        /* 35: Signal */
  &twa_parallel_B.velmex_pitch_k,      /* 36: Signal */
  &twa_parallel_B.enc_res_fa,          /* 37: Signal */
  &twa_parallel_B.gear_ratio_j,        /* 38: Signal */
  &twa_parallel_B.enc_res_b,           /* 39: Signal */
  &twa_parallel_B.gear_ratio_n,        /* 40: Signal */
  &twa_parallel_B.enc_res_e,           /* 41: Signal */
  &twa_parallel_B.gear_ratio_f,        /* 42: Signal */
  &twa_parallel_B.Diff_d[0],           /* 43: Signal */
  &twa_parallel_B.Uk1_jb[0],           /* 44: Signal */
  &twa_parallel_B.TSamp_h[0],          /* 45: Signal */
  &twa_parallel_B.NSampleEnable,       /* 46: Signal */
  &twa_parallel_B.Switch_f[0],         /* 47: Signal */
  &twa_parallel_B.Gain_n[0],           /* 48: Signal */
  &twa_parallel_B.DiscreteFIRFilter_h[0],/* 49: Signal */
  &twa_parallel_B.Switch[0],           /* 50: Signal */
  &twa_parallel_B.qeps[0],             /* 51: Signal */
  &twa_parallel_B.xcur_e[0],           /* 52: Signal */
  &twa_parallel_B.eerot,               /* 53: Signal */
  &twa_parallel_B.qdes[0],             /* 54: Signal */
  &twa_parallel_B.full_jac[0],         /* 55: Signal */
  &twa_parallel_B.xcur[0],             /* 56: Signal */
  &twa_parallel_B.eerotcur,            /* 57: Signal */
  &twa_parallel_B.t_in_w[0],           /* 58: Signal */
  &twa_parallel_B.twa_flange_offset,   /* 59: Signal */
  &twa_parallel_B.twa_gamma,           /* 60: Signal */
  &twa_parallel_B.use_twa,             /* 61: Signal */
  &twa_parallel_B.UnitDelay1_a[0],     /* 62: Signal */
  &twa_parallel_B.UnitDelay3,          /* 63: Signal */
  &twa_parallel_B.UnitDelay6[0],       /* 64: Signal */
  &twa_parallel_B.Diff[0],             /* 65: Signal */
  &twa_parallel_B.Uk1[0],              /* 66: Signal */
  &twa_parallel_B.TSamp[0],            /* 67: Signal */
  &twa_parallel_B.Gain[0],             /* 68: Signal */
  &twa_parallel_B.DiscreteFIRFilter[0],/* 69: Signal */
  &twa_parallel_B.FixPtRelationalOperator[0],/* 70: Signal */
  &twa_parallel_B.Uk1_j[0],            /* 71: Signal */
  &twa_parallel_P.AnalogOutput_P1[0],  /* 72: Block Parameter */
  &twa_parallel_P.Init_P1,             /* 73: Block Parameter */
  &twa_parallel_P.Init_P2,             /* 74: Block Parameter */
  &twa_parallel_P.Init_P3,             /* 75: Block Parameter */
  &twa_parallel_P.Init_P4,             /* 76: Block Parameter */
  &twa_parallel_P.enc_reset1_Value,    /* 77: Block Parameter */
  &twa_parallel_P.enc_reset2_Value,    /* 78: Block Parameter */
  &twa_parallel_P.enc_reset3_Value,    /* 79: Block Parameter */
  &twa_parallel_P.enc_reset4_Value,    /* 80: Block Parameter */
  &twa_parallel_P.enc_reset5_Value,    /* 81: Block Parameter */
  &twa_parallel_P.enc_reset6_Value,    /* 82: Block Parameter */
  &twa_parallel_P.EncoderInput_P1[0],  /* 83: Block Parameter */
  &twa_parallel_P.EncoderInput_P2,     /* 84: Block Parameter */
  &twa_parallel_P.manual_current_Value[0],/* 85: Block Parameter */
  &twa_parallel_P.pid_mode_Value,      /* 86: Block Parameter */
  &twa_parallel_P.reset_integrator_Value,/* 87: Block Parameter */
  &twa_parallel_P.Kd_Gain[0],          /* 88: Block Parameter */
  &twa_parallel_P.Ki_Gain[0],          /* 89: Block Parameter */
  &twa_parallel_P.Kp_Gain[0],          /* 90: Block Parameter */
  &twa_parallel_P.Integrator_IC,       /* 91: Block Parameter */
  &twa_parallel_P.Saturation_UpperSat[0],/* 92: Block Parameter */
  &twa_parallel_P.Saturation_LowerSat[0],/* 93: Block Parameter */
  &twa_parallel_P.saturate_int_UpperSat[0],/* 94: Block Parameter */
  &twa_parallel_P.saturate_int_LowerSat[0],/* 95: Block Parameter */
  &twa_parallel_P.quintic_enable_Value,/* 96: Block Parameter */
  &twa_parallel_P.tf_Value,            /* 97: Block Parameter */
  &twa_parallel_P.UnitDelay_X0,        /* 98: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0_h,     /* 99: Block Parameter */
  &twa_parallel_P.UnitDelay2_X0[0],    /* 100: Block Parameter */
  &twa_parallel_P.mode_Value,          /* 101: Block Parameter */
  &twa_parallel_P.q_des_usr_Value[0],  /* 102: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0[0],    /* 103: Block Parameter */
  &twa_parallel_P.enc_res_Gain,        /* 104: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain,     /* 105: Block Parameter */
  &twa_parallel_P.velmex_pitch_Gain,   /* 106: Block Parameter */
  &twa_parallel_P.enc_res_Gain_j,      /* 107: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_d,   /* 108: Block Parameter */
  &twa_parallel_P.velmex_pitch_Gain_j, /* 109: Block Parameter */
  &twa_parallel_P.enc_res_Gain_i,      /* 110: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_a,   /* 111: Block Parameter */
  &twa_parallel_P.velmex_pitch_Gain_je,/* 112: Block Parameter */
  &twa_parallel_P.enc_res_Gain_g,      /* 113: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_o,   /* 114: Block Parameter */
  &twa_parallel_P.enc_res_Gain_ij,     /* 115: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_da,  /* 116: Block Parameter */
  &twa_parallel_P.enc_res_Gain_m,      /* 117: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_c,   /* 118: Block Parameter */
  &twa_parallel_P.UD_X0_f,             /* 119: Block Parameter */
  &twa_parallel_P.TSamp_WtEt_p,        /* 120: Block Parameter */
  &twa_parallel_P.NSampleEnable_TARGETCNT,/* 121: Block Parameter */
  &twa_parallel_P.NSampleEnable_ACTLEVEL,/* 122: Block Parameter */
  &twa_parallel_P.vel_filter_coeffs_Value_m[0],/* 123: Block Parameter */
  &twa_parallel_P.Gain_Gain_d,         /* 124: Block Parameter */
  &twa_parallel_P.DiscreteFIRFilter_IC_b,/* 125: Block Parameter */
  &twa_parallel_P.b_in_w_Value[0],     /* 126: Block Parameter */
  &twa_parallel_P.dt_Value,            /* 127: Block Parameter */
  &twa_parallel_P.ee_rot_des_Value,    /* 128: Block Parameter */
  &twa_parallel_P.f_in_w_Value[0],     /* 129: Block Parameter */
  &twa_parallel_P.m_in_w_Value[0],     /* 130: Block Parameter */
  &twa_parallel_P.p_in_m_Value[0],     /* 131: Block Parameter */
  &twa_parallel_P.res_rate_param_Value[0],/* 132: Block Parameter */
  &twa_parallel_P.t_in_w_Value[0],     /* 133: Block Parameter */
  &twa_parallel_P.twa_flange_offset_Value,/* 134: Block Parameter */
  &twa_parallel_P.twa_gamma_Value,     /* 135: Block Parameter */
  &twa_parallel_P.use_twa_Value,       /* 136: Block Parameter */
  &twa_parallel_P.x_des_Value[0],      /* 137: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0_e[0],  /* 138: Block Parameter */
  &twa_parallel_P.UnitDelay3_X0,       /* 139: Block Parameter */
  &twa_parallel_P.UnitDelay6_X0[0],    /* 140: Block Parameter */
  &twa_parallel_P.UD_X0,               /* 141: Block Parameter */
  &twa_parallel_P.TSamp_WtEt,          /* 142: Block Parameter */
  &twa_parallel_P.vel_filter_coeffs_Value[0],/* 143: Block Parameter */
  &twa_parallel_P.Gain_Gain,           /* 144: Block Parameter */
  &twa_parallel_P.DiscreteFIRFilter_IC,/* 145: Block Parameter */
  &twa_parallel_P.DelayInput1_X0[0]    /* 146: Block Parameter */
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

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

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
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 14, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  6,                                   /* 2 */
  1,                                   /* 3 */
  3,                                   /* 4 */
  1,                                   /* 5 */
  6,                                   /* 6 */
  3,                                   /* 7 */
  3,                                   /* 8 */
  3,                                   /* 9 */
  1,                                   /* 10 */
  6,                                   /* 11 */
  2,                                   /* 12 */
  1,                                   /* 13 */
  8,                                   /* 14 */
  2                                    /* 15 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.002
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 }
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
  { rtBlockSignals, 72 },

  { rtBlockParameters, 75,
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
