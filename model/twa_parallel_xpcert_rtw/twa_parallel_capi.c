#include "twa_parallel.h"
#include "rtw_capi.h"
#include "twa_parallel_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 1, "GetLegLen/p1",
    "macro_leg_len", 0, 0, 0, 0, 0 },

  { 1, 1, "GetLegLen/p2",
    "micro_leg_len", 1, 0, 0, 0, 0 },

  { 2, 1, "GetLegLen/p3",
    "x_cur", 2, 0, 0, 0, 0 },

  { 3, 2, "GetMacroQDes",
    "qmacro_des", 0, 0, 0, 0, 0 },

  { 4, 3, "GetMicroQDes",
    "qmicro_des", 0, 0, 0, 0, 0 },

  { 5, 0, "Switch",
    "", 0, 0, 1, 0, 0 },

  { 6, 0, "Unit Delay",
    "", 0, 0, 0, 0, 0 },

  { 7, 0, "Unit Delay1",
    "", 0, 0, 0, 0, 0 },

  { 8, 0, "Unit Delay2",
    "", 0, 0, 0, 0, 0 },

  { 9, 0, "Encoders/Encoder Input/p1",
    "", 0, 0, 2, 0, 1 },

  { 10, 0, "Encoders/Encoder Input/p2",
    "", 1, 0, 2, 0, 1 },

  { 11, 0, "Encoders/Encoder Input/p3",
    "", 2, 0, 2, 0, 1 },

  { 12, 0, "Encoders/Encoder Input/p4",
    "", 3, 0, 2, 0, 1 },

  { 13, 0, "Encoders/Encoder Input/p5",
    "", 4, 0, 2, 0, 1 },

  { 14, 0, "Encoders/Encoder Input/p6",
    "", 5, 0, 2, 0, 1 },

  { 15, 0, "PID Controller/Kd",
    "", 0, 0, 1, 0, 0 },

  { 16, 0, "PID Controller/Ki",
    "", 0, 0, 1, 0, 0 },

  { 17, 0, "PID Controller/Kp",
    "", 0, 0, 1, 0, 0 },

  { 18, 0, "PID Controller/Integrator",
    "", 0, 0, 1, 0, 1 },

  { 19, 0, "PID Controller/Saturation",
    "", 0, 0, 1, 0, 0 },

  { 20, 0, "PID Controller/saturate_int",
    "", 0, 0, 1, 0, 0 },

  { 21, 0, "PID Controller/Add",
    "", 0, 0, 1, 0, 0 },

  { 22, 0, "PID Controller/Sum",
    "", 0, 0, 1, 0, 0 },

  { 23, 0, "PID Controller/Switch",
    "", 0, 0, 1, 0, 0 },

  { 24, 4, "Quintic Poly/Embedded MATLAB Function/p1",
    "q_cmd", 0, 0, 1, 0, 0 },

  { 25, 4, "Quintic Poly/Embedded MATLAB Function/p2",
    "q_dot", 1, 0, 1, 0, 0 },

  { 26, 4, "Quintic Poly/Embedded MATLAB Function/p3",
    "q_dub_dot", 2, 0, 1, 0, 0 },

  { 27, 4, "Quintic Poly/Embedded MATLAB Function/p4",
    "confn", 3, 0, 2, 0, 0 },

  { 28, 4, "Quintic Poly/Embedded MATLAB Function/p5",
    "t0n", 4, 0, 2, 0, 0 },

  { 29, 4, "Quintic Poly/Embedded MATLAB Function/p6",
    "q0n", 5, 0, 1, 0, 0 },

  { 30, 4, "Quintic Poly/Embedded MATLAB Function/p7",
    "robot_mov", 6, 0, 2, 0, 0 },

  { 31, 0, "Quintic Poly/Digital Clock",
    "", 0, 0, 2, 0, 0 },

  { 32, 0, "Quintic Poly/Unit Delay",
    "", 0, 0, 2, 0, 0 },

  { 33, 0, "Quintic Poly/Unit Delay1",
    "", 0, 0, 2, 0, 0 },

  { 34, 0, "Quintic Poly/Unit Delay2",
    "", 0, 0, 1, 0, 0 },

  { 35, 0, "Encoders/Counts To Turns/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 36, 0, "Encoders/Counts To Turns/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 37, 0, "Encoders/Counts To Turns1/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 38, 0, "Encoders/Counts To Turns1/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 39, 0, "Encoders/Counts To Turns2/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 40, 0, "Encoders/Counts To Turns2/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 41, 0, "Encoders/Counts To Turns3/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 42, 0, "Encoders/Counts To Turns3/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 43, 0, "Encoders/Counts To Turns4/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 44, 0, "Encoders/Counts To Turns4/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 45, 0, "Encoders/Counts To Turns5/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 46, 0, "Encoders/Counts To Turns5/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 47, 0, "PID Controller/Discrete Derivative/Diff",
    "", 0, 0, 1, 0, 0 },

  { 48, 0, "PID Controller/Discrete Derivative/UD",
    "U(k-1)", 0, 0, 1, 0, 0 },

  { 49, 0, "PID Controller/Discrete Derivative/TSamp",
    "", 0, 0, 1, 0, 0 },

  { 50, 0, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "", 0, 1, 2, 0, 0 },

  { 51, 0, "Quintic Poly/N-Sample Switch/Switch",
    "", 0, 0, 1, 0, 0 },

  { 52, 0, "Scopes/Fir Filter/Gain",
    "", 0, 0, 1, 0, 0 },

  { 53, 0, "Scopes/Fir Filter/Discrete FIR Filter",
    "", 0, 0, 1, 0, 0 },

  { 54, 0, "Encoders/Derivative/Discrete Derivative/Diff",
    "", 0, 0, 1, 0, 0 },

  { 55, 0, "Encoders/Derivative/Discrete Derivative/UD",
    "U(k-1)", 0, 0, 1, 0, 0 },

  { 56, 0, "Encoders/Derivative/Discrete Derivative/TSamp",
    "", 0, 0, 1, 0, 0 },

  { 57, 0, "Encoders/Derivative/Fir Filter/Gain",
    "", 0, 0, 1, 0, 0 },

  { 58, 0, "Encoders/Derivative/Fir Filter/Discrete FIR Filter",
    "", 0, 0, 1, 0, 0 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 59, "cntrl_mode",
    "Value", 0, 2, 0 },

  { 60, "ee_rot",
    "Value", 0, 2, 0 },

  { 61, "ee_velmex_pitch",
    "Value", 0, 2, 0 },

  { 62, "q_des",
    "Value", 0, 1, 0 },

  { 63, "twa_actuation",
    "Value", 0, 0, 0 },

  { 64, "x_des",
    "Value", 0, 0, 0 },

  { 65, "Analog Output",
    "P1", 0, 3, 0 },

  { 66, "Init",
    "P1", 0, 2, 0 },

  { 67, "Init",
    "P2", 0, 2, 0 },

  { 68, "Init",
    "P3", 0, 2, 0 },

  { 69, "Init",
    "P4", 0, 2, 0 },

  { 70, "Unit Delay",
    "X0", 0, 0, 0 },

  { 71, "Unit Delay1",
    "X0", 0, 0, 0 },

  { 72, "Unit Delay2",
    "X0", 0, 0, 0 },

  { 73, "Encoders/enc_reset",
    "Value", 0, 2, 0 },

  { 74, "Encoders/Encoder Input",
    "P1", 0, 3, 0 },

  { 75, "Encoders/Encoder Input",
    "P2", 0, 2, 0 },

  { 76, "PID Controller/manual_current",
    "Value", 0, 1, 0 },

  { 77, "PID Controller/pid_mode",
    "Value", 0, 2, 0 },

  { 78, "PID Controller/Kd",
    "Gain", 0, 1, 0 },

  { 79, "PID Controller/Ki",
    "Gain", 0, 1, 0 },

  { 80, "PID Controller/Kp",
    "Gain", 0, 1, 0 },

  { 81, "PID Controller/Integrator",
    "InitialCondition", 0, 2, 0 },

  { 82, "PID Controller/Saturation",
    "UpperLimit", 0, 3, 0 },

  { 83, "PID Controller/Saturation",
    "LowerLimit", 0, 3, 0 },

  { 84, "PID Controller/saturate_int",
    "UpperLimit", 0, 3, 0 },

  { 85, "PID Controller/saturate_int",
    "LowerLimit", 0, 3, 0 },

  { 86, "Quintic Poly/quintic_enable",
    "Value", 0, 2, 0 },

  { 87, "Quintic Poly/tf",
    "Value", 0, 2, 0 },

  { 88, "Quintic Poly/Unit Delay",
    "X0", 0, 2, 0 },

  { 89, "Quintic Poly/Unit Delay1",
    "X0", 0, 2, 0 },

  { 90, "Quintic Poly/Unit Delay2",
    "X0", 0, 1, 0 },

  { 91, "Encoders/Counts To Turns/enc_res",
    "Gain", 0, 2, 0 },

  { 92, "Encoders/Counts To Turns/gear_ratio",
    "Gain", 0, 2, 0 },

  { 93, "Encoders/Counts To Turns1/enc_res",
    "Gain", 0, 2, 0 },

  { 94, "Encoders/Counts To Turns1/gear_ratio",
    "Gain", 0, 2, 0 },

  { 95, "Encoders/Counts To Turns2/enc_res",
    "Gain", 0, 2, 0 },

  { 96, "Encoders/Counts To Turns2/gear_ratio",
    "Gain", 0, 2, 0 },

  { 97, "Encoders/Counts To Turns3/enc_res",
    "Gain", 0, 2, 0 },

  { 98, "Encoders/Counts To Turns3/gear_ratio",
    "Gain", 0, 2, 0 },

  { 99, "Encoders/Counts To Turns4/enc_res",
    "Gain", 0, 2, 0 },

  { 100, "Encoders/Counts To Turns4/gear_ratio",
    "Gain", 0, 2, 0 },

  { 101, "Encoders/Counts To Turns5/enc_res",
    "Gain", 0, 2, 0 },

  { 102, "Encoders/Counts To Turns5/gear_ratio",
    "Gain", 0, 2, 0 },

  { 103, "PID Controller/Discrete Derivative/UD",
    "X0", 0, 2, 0 },

  { 104, "PID Controller/Discrete Derivative/TSamp",
    "WtEt", 0, 2, 0 },

  { 105, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "TARGETCNT", 2, 2, 0 },

  { 106, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "ACTLEVEL", 2, 2, 0 },

  { 107, "Scopes/Fir Filter/vel_filter_coeffs",
    "Value", 0, 4, 0 },

  { 108, "Scopes/Fir Filter/Gain",
    "Gain", 0, 2, 0 },

  { 109, "Scopes/Fir Filter/Discrete FIR Filter",
    "IC", 0, 2, 0 },

  { 110, "Encoders/Derivative/Discrete Derivative/UD",
    "X0", 0, 2, 0 },

  { 111, "Encoders/Derivative/Discrete Derivative/TSamp",
    "WtEt", 0, 2, 0 },

  { 112, "Encoders/Derivative/Fir Filter/vel_filter_coeffs",
    "Value", 0, 4, 0 },

  { 113, "Encoders/Derivative/Fir Filter/Gain",
    "Gain", 0, 2, 0 },

  { 114, "Encoders/Derivative/Fir Filter/Discrete FIR Filter",
    "IC", 0, 2, 0 },

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
  &twa_parallel_B.macro_leg_len[0],    /* 0: Signal */
  &twa_parallel_B.micro_leg_len[0],    /* 1: Signal */
  &twa_parallel_B.x_cur[0],            /* 2: Signal */
  &twa_parallel_B.qmacro_des[0],       /* 3: Signal */
  &twa_parallel_B.qmicro_des[0],       /* 4: Signal */
  &twa_parallel_B.Switch[0],           /* 5: Signal */
  &twa_parallel_B.UnitDelay[0],        /* 6: Signal */
  &twa_parallel_B.UnitDelay1[0],       /* 7: Signal */
  &twa_parallel_B.UnitDelay2[0],       /* 8: Signal */
  &twa_parallel_B.EncoderInput_o1,     /* 9: Signal */
  &twa_parallel_B.EncoderInput_o2,     /* 10: Signal */
  &twa_parallel_B.EncoderInput_o3,     /* 11: Signal */
  &twa_parallel_B.EncoderInput_o4,     /* 12: Signal */
  &twa_parallel_B.EncoderInput_o5,     /* 13: Signal */
  &twa_parallel_B.EncoderInput_o6,     /* 14: Signal */
  &twa_parallel_B.Kd[0],               /* 15: Signal */
  &twa_parallel_B.Ki[0],               /* 16: Signal */
  &twa_parallel_B.Kp[0],               /* 17: Signal */
  &twa_parallel_B.Integrator[0],       /* 18: Signal */
  &twa_parallel_B.Saturation[0],       /* 19: Signal */
  &twa_parallel_B.saturate_int[0],     /* 20: Signal */
  &twa_parallel_B.Add[0],              /* 21: Signal */
  &twa_parallel_B.Sum[0],              /* 22: Signal */
  &twa_parallel_B.Switch_i[0],         /* 23: Signal */
  &twa_parallel_B.q_cmd[0],            /* 24: Signal */
  &twa_parallel_B.q_dot[0],            /* 25: Signal */
  &twa_parallel_B.q_dub_dot[0],        /* 26: Signal */
  &twa_parallel_B.confn,               /* 27: Signal */
  &twa_parallel_B.t0n,                 /* 28: Signal */
  &twa_parallel_B.q0n[0],              /* 29: Signal */
  &twa_parallel_B.robot_mov,           /* 30: Signal */
  &twa_parallel_B.DigitalClock,        /* 31: Signal */
  &twa_parallel_B.UnitDelay_k,         /* 32: Signal */
  &twa_parallel_B.UnitDelay1_b,        /* 33: Signal */
  &twa_parallel_B.UnitDelay2_n[0],     /* 34: Signal */
  &twa_parallel_B.enc_res,             /* 35: Signal */
  &twa_parallel_B.gear_ratio,          /* 36: Signal */
  &twa_parallel_B.enc_res_l,           /* 37: Signal */
  &twa_parallel_B.gear_ratio_p,        /* 38: Signal */
  &twa_parallel_B.enc_res_f,           /* 39: Signal */
  &twa_parallel_B.gear_ratio_c,        /* 40: Signal */
  &twa_parallel_B.enc_res_c,           /* 41: Signal */
  &twa_parallel_B.gear_ratio_l,        /* 42: Signal */
  &twa_parallel_B.enc_res_fa,          /* 43: Signal */
  &twa_parallel_B.gear_ratio_j,        /* 44: Signal */
  &twa_parallel_B.enc_res_b,           /* 45: Signal */
  &twa_parallel_B.gear_ratio_n,        /* 46: Signal */
  &twa_parallel_B.Diff_d[0],           /* 47: Signal */
  &twa_parallel_B.Uk1_j[0],            /* 48: Signal */
  &twa_parallel_B.TSamp_h[0],          /* 49: Signal */
  &twa_parallel_B.NSampleEnable,       /* 50: Signal */
  &twa_parallel_B.Switch_f[0],         /* 51: Signal */
  &twa_parallel_B.Gain_n[0],           /* 52: Signal */
  &twa_parallel_B.DiscreteFIRFilter_h[0],/* 53: Signal */
  &twa_parallel_B.Diff[0],             /* 54: Signal */
  &twa_parallel_B.Uk1[0],              /* 55: Signal */
  &twa_parallel_B.TSamp[0],            /* 56: Signal */
  &twa_parallel_B.Gain[0],             /* 57: Signal */
  &twa_parallel_B.DiscreteFIRFilter[0],/* 58: Signal */
  &twa_parallel_P.cntrl_mode_Value,    /* 59: Block Parameter */
  &twa_parallel_P.ee_rot_Value,        /* 60: Block Parameter */
  &twa_parallel_P.ee_velmex_pitch_Value,/* 61: Block Parameter */
  &twa_parallel_P.q_des_Value[0],      /* 62: Block Parameter */
  &twa_parallel_P.twa_actuation_Value[0],/* 63: Block Parameter */
  &twa_parallel_P.x_des_Value[0],      /* 64: Block Parameter */
  &twa_parallel_P.AnalogOutput_P1[0],  /* 65: Block Parameter */
  &twa_parallel_P.Init_P1,             /* 66: Block Parameter */
  &twa_parallel_P.Init_P2,             /* 67: Block Parameter */
  &twa_parallel_P.Init_P3,             /* 68: Block Parameter */
  &twa_parallel_P.Init_P4,             /* 69: Block Parameter */
  &twa_parallel_P.UnitDelay_X0[0],     /* 70: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0[0],    /* 71: Block Parameter */
  &twa_parallel_P.UnitDelay2_X0[0],    /* 72: Block Parameter */
  &twa_parallel_P.enc_reset_Value,     /* 73: Block Parameter */
  &twa_parallel_P.EncoderInput_P1[0],  /* 74: Block Parameter */
  &twa_parallel_P.EncoderInput_P2,     /* 75: Block Parameter */
  &twa_parallel_P.manual_current_Value[0],/* 76: Block Parameter */
  &twa_parallel_P.pid_mode_Value,      /* 77: Block Parameter */
  &twa_parallel_P.Kd_Gain[0],          /* 78: Block Parameter */
  &twa_parallel_P.Ki_Gain[0],          /* 79: Block Parameter */
  &twa_parallel_P.Kp_Gain[0],          /* 80: Block Parameter */
  &twa_parallel_P.Integrator_IC,       /* 81: Block Parameter */
  &twa_parallel_P.Saturation_UpperSat[0],/* 82: Block Parameter */
  &twa_parallel_P.Saturation_LowerSat[0],/* 83: Block Parameter */
  &twa_parallel_P.saturate_int_UpperSat[0],/* 84: Block Parameter */
  &twa_parallel_P.saturate_int_LowerSat[0],/* 85: Block Parameter */
  &twa_parallel_P.quintic_enable_Value,/* 86: Block Parameter */
  &twa_parallel_P.tf_Value,            /* 87: Block Parameter */
  &twa_parallel_P.UnitDelay_X0_p,      /* 88: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0_h,     /* 89: Block Parameter */
  &twa_parallel_P.UnitDelay2_X0_d[0],  /* 90: Block Parameter */
  &twa_parallel_P.enc_res_Gain,        /* 91: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain,     /* 92: Block Parameter */
  &twa_parallel_P.enc_res_Gain_j,      /* 93: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_i,   /* 94: Block Parameter */
  &twa_parallel_P.enc_res_Gain_jz,     /* 95: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_d,   /* 96: Block Parameter */
  &twa_parallel_P.enc_res_Gain_i,      /* 97: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_a,   /* 98: Block Parameter */
  &twa_parallel_P.enc_res_Gain_g,      /* 99: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_o,   /* 100: Block Parameter */
  &twa_parallel_P.enc_res_Gain_ij,     /* 101: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_da,  /* 102: Block Parameter */
  &twa_parallel_P.UD_X0_f,             /* 103: Block Parameter */
  &twa_parallel_P.TSamp_WtEt_p,        /* 104: Block Parameter */
  &twa_parallel_P.NSampleEnable_TARGETCNT,/* 105: Block Parameter */
  &twa_parallel_P.NSampleEnable_ACTLEVEL,/* 106: Block Parameter */
  &twa_parallel_P.vel_filter_coeffs_Value_m[0],/* 107: Block Parameter */
  &twa_parallel_P.Gain_Gain_d,         /* 108: Block Parameter */
  &twa_parallel_P.DiscreteFIRFilter_IC_b,/* 109: Block Parameter */
  &twa_parallel_P.UD_X0,               /* 110: Block Parameter */
  &twa_parallel_P.TSamp_WtEt,          /* 111: Block Parameter */
  &twa_parallel_P.vel_filter_coeffs_Value[0],/* 112: Block Parameter */
  &twa_parallel_P.Gain_Gain,           /* 113: Block Parameter */
  &twa_parallel_P.DiscreteFIRFilter_IC /* 114: Block Parameter */
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

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_SCALAR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  3,                                   /* 0 */
  1,                                   /* 1 */
  6,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  1,                                   /* 5 */
  1,                                   /* 6 */
  6,                                   /* 7 */
  2,                                   /* 8 */
  1                                    /* 9 */
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
  { rtBlockSignals, 59 },

  { rtBlockParameters, 56,
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
