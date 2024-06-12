#include "twa_parallel.h"
#include "rtw_capi.h"
#include "twa_parallel_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 1, "GetMacroLegLen",
    "macro_leg_len", 0, 0, 0, 0, 0 },

  { 1, 2, "GetMacroQDes",
    "qmacro_des", 0, 0, 0, 0, 0 },

  { 2, 3, "GetMicroQDes",
    "qmicro_des", 0, 0, 0, 0, 0 },

  { 3, 0, "Switch",
    "", 0, 0, 1, 0, 0 },

  { 4, 0, "Encoders/Encoder Input/p1",
    "", 0, 0, 2, 0, 1 },

  { 5, 0, "Encoders/Encoder Input/p2",
    "", 1, 0, 2, 0, 1 },

  { 6, 0, "Encoders/Encoder Input/p3",
    "", 2, 0, 2, 0, 1 },

  { 7, 0, "Encoders/Encoder Input/p4",
    "", 3, 0, 2, 0, 1 },

  { 8, 0, "Encoders/Encoder Input/p5",
    "", 4, 0, 2, 0, 1 },

  { 9, 0, "Encoders/Encoder Input/p6",
    "", 5, 0, 2, 0, 1 },

  { 10, 0, "PD Controller/Kd",
    "", 0, 0, 1, 0, 0 },

  { 11, 0, "PD Controller/Kp",
    "", 0, 0, 1, 0, 0 },

  { 12, 0, "PD Controller/Saturation",
    "", 0, 0, 1, 0, 0 },

  { 13, 0, "PD Controller/Add",
    "", 0, 0, 1, 0, 0 },

  { 14, 0, "PD Controller/Sum",
    "", 0, 0, 1, 0, 0 },

  { 15, 0, "PD Controller/Sum1",
    "", 0, 0, 1, 0, 0 },

  { 16, 0, "PD Controller/Switch",
    "", 0, 0, 1, 0, 0 },

  { 17, 4, "Quintic Poly/Embedded MATLAB Function/p1",
    "q_cmd", 0, 0, 1, 0, 0 },

  { 18, 4, "Quintic Poly/Embedded MATLAB Function/p2",
    "q_dot", 1, 0, 1, 0, 0 },

  { 19, 4, "Quintic Poly/Embedded MATLAB Function/p3",
    "q_dub_dot", 2, 0, 1, 0, 0 },

  { 20, 4, "Quintic Poly/Embedded MATLAB Function/p4",
    "confn", 3, 0, 2, 0, 0 },

  { 21, 4, "Quintic Poly/Embedded MATLAB Function/p5",
    "t0n", 4, 0, 2, 0, 0 },

  { 22, 4, "Quintic Poly/Embedded MATLAB Function/p6",
    "q0n", 5, 0, 1, 0, 0 },

  { 23, 4, "Quintic Poly/Embedded MATLAB Function/p7",
    "robot_mov", 6, 0, 2, 0, 0 },

  { 24, 0, "Quintic Poly/Digital Clock",
    "", 0, 0, 2, 0, 0 },

  { 25, 0, "Quintic Poly/Unit Delay",
    "", 0, 0, 2, 0, 0 },

  { 26, 0, "Quintic Poly/Unit Delay1",
    "", 0, 0, 2, 0, 0 },

  { 27, 0, "Quintic Poly/Unit Delay2",
    "", 0, 0, 1, 0, 0 },

  { 28, 0, "Encoders/Counts To Turns/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 29, 0, "Encoders/Counts To Turns/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 30, 0, "Encoders/Counts To Turns1/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 31, 0, "Encoders/Counts To Turns1/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 32, 0, "Encoders/Counts To Turns2/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 33, 0, "Encoders/Counts To Turns2/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 34, 0, "Encoders/Counts To Turns3/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 35, 0, "Encoders/Counts To Turns3/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 36, 0, "Encoders/Counts To Turns4/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 37, 0, "Encoders/Counts To Turns4/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 38, 0, "Encoders/Counts To Turns5/enc_res",
    "", 0, 0, 2, 0, 0 },

  { 39, 0, "Encoders/Counts To Turns5/gear_ratio",
    "", 0, 0, 2, 0, 0 },

  { 40, 0, "PD Controller/Discrete Derivative/Diff",
    "", 0, 0, 1, 0, 0 },

  { 41, 0, "PD Controller/Discrete Derivative/UD",
    "U(k-1)", 0, 0, 1, 0, 0 },

  { 42, 0, "PD Controller/Discrete Derivative/TSamp",
    "", 0, 0, 1, 0, 0 },

  { 43, 0, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "", 0, 1, 2, 0, 0 },

  { 44, 0, "Quintic Poly/N-Sample Switch/Switch",
    "", 0, 0, 1, 0, 0 },

  { 45, 0, "Scopes/Fir Filter/Gain",
    "", 0, 0, 1, 0, 0 },

  { 46, 0, "Scopes/Fir Filter/Discrete FIR Filter",
    "", 0, 0, 1, 0, 0 },

  { 47, 0, "Encoders/Derivative/Discrete Derivative/Diff",
    "", 0, 0, 1, 0, 0 },

  { 48, 0, "Encoders/Derivative/Discrete Derivative/UD",
    "U(k-1)", 0, 0, 1, 0, 0 },

  { 49, 0, "Encoders/Derivative/Discrete Derivative/TSamp",
    "", 0, 0, 1, 0, 0 },

  { 50, 0, "Encoders/Derivative/Fir Filter/Gain",
    "", 0, 0, 1, 0, 0 },

  { 51, 0, "Encoders/Derivative/Fir Filter/Discrete FIR Filter",
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
  { 52, "cntrl_mode",
    "Value", 0, 2, 0 },

  { 53, "ee_rot",
    "Value", 0, 2, 0 },

  { 54, "ee_velmex_pitch",
    "Value", 0, 2, 0 },

  { 55, "micro_leg_len",
    "Value", 0, 0, 0 },

  { 56, "q_des",
    "Value", 0, 1, 0 },

  { 57, "x_des",
    "Value", 0, 0, 0 },

  { 58, "Analog Output",
    "P1", 0, 3, 0 },

  { 59, "Init",
    "P1", 0, 2, 0 },

  { 60, "Init",
    "P2", 0, 2, 0 },

  { 61, "Init",
    "P3", 0, 2, 0 },

  { 62, "Init",
    "P4", 0, 2, 0 },

  { 63, "Encoders/enc_reset",
    "Value", 0, 2, 0 },

  { 64, "Encoders/Encoder Input",
    "P1", 0, 3, 0 },

  { 65, "Encoders/Encoder Input",
    "P2", 0, 2, 0 },

  { 66, "PD Controller/manual_current",
    "Value", 0, 1, 0 },

  { 67, "PD Controller/pd_mode",
    "Value", 0, 2, 0 },

  { 68, "PD Controller/Kd",
    "Gain", 0, 1, 0 },

  { 69, "PD Controller/Kp",
    "Gain", 0, 1, 0 },

  { 70, "PD Controller/Saturation",
    "UpperLimit", 0, 3, 0 },

  { 71, "PD Controller/Saturation",
    "LowerLimit", 0, 3, 0 },

  { 72, "Quintic Poly/quintic_enable",
    "Value", 0, 2, 0 },

  { 73, "Quintic Poly/tf",
    "Value", 0, 2, 0 },

  { 74, "Quintic Poly/Unit Delay",
    "X0", 0, 2, 0 },

  { 75, "Quintic Poly/Unit Delay1",
    "X0", 0, 2, 0 },

  { 76, "Quintic Poly/Unit Delay2",
    "X0", 0, 1, 0 },

  { 77, "Encoders/Counts To Turns/enc_res",
    "Gain", 0, 2, 0 },

  { 78, "Encoders/Counts To Turns/gear_ratio",
    "Gain", 0, 2, 0 },

  { 79, "Encoders/Counts To Turns1/enc_res",
    "Gain", 0, 2, 0 },

  { 80, "Encoders/Counts To Turns1/gear_ratio",
    "Gain", 0, 2, 0 },

  { 81, "Encoders/Counts To Turns2/enc_res",
    "Gain", 0, 2, 0 },

  { 82, "Encoders/Counts To Turns2/gear_ratio",
    "Gain", 0, 2, 0 },

  { 83, "Encoders/Counts To Turns3/enc_res",
    "Gain", 0, 2, 0 },

  { 84, "Encoders/Counts To Turns3/gear_ratio",
    "Gain", 0, 2, 0 },

  { 85, "Encoders/Counts To Turns4/enc_res",
    "Gain", 0, 2, 0 },

  { 86, "Encoders/Counts To Turns4/gear_ratio",
    "Gain", 0, 2, 0 },

  { 87, "Encoders/Counts To Turns5/enc_res",
    "Gain", 0, 2, 0 },

  { 88, "Encoders/Counts To Turns5/gear_ratio",
    "Gain", 0, 2, 0 },

  { 89, "PD Controller/Discrete Derivative/UD",
    "X0", 0, 2, 0 },

  { 90, "PD Controller/Discrete Derivative/TSamp",
    "WtEt", 0, 2, 0 },

  { 91, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "TARGETCNT", 2, 2, 0 },

  { 92, "Quintic Poly/N-Sample Switch/N-Sample Enable",
    "ACTLEVEL", 2, 2, 0 },

  { 93, "Scopes/Fir Filter/vel_filter_coeffs",
    "Value", 0, 4, 0 },

  { 94, "Scopes/Fir Filter/Gain",
    "Gain", 0, 2, 0 },

  { 95, "Scopes/Fir Filter/Discrete FIR Filter",
    "IC", 0, 2, 0 },

  { 96, "Encoders/Derivative/Discrete Derivative/UD",
    "X0", 0, 2, 0 },

  { 97, "Encoders/Derivative/Discrete Derivative/TSamp",
    "WtEt", 0, 2, 0 },

  { 98, "Encoders/Derivative/Fir Filter/vel_filter_coeffs",
    "Value", 0, 4, 0 },

  { 99, "Encoders/Derivative/Fir Filter/Gain",
    "Gain", 0, 2, 0 },

  { 100, "Encoders/Derivative/Fir Filter/Discrete FIR Filter",
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
  &twa_parallel_B.qmacro_des[0],       /* 1: Signal */
  &twa_parallel_B.qmicro_des[0],       /* 2: Signal */
  &twa_parallel_B.Switch[0],           /* 3: Signal */
  &twa_parallel_B.EncoderInput_o1,     /* 4: Signal */
  &twa_parallel_B.EncoderInput_o2,     /* 5: Signal */
  &twa_parallel_B.EncoderInput_o3,     /* 6: Signal */
  &twa_parallel_B.EncoderInput_o4,     /* 7: Signal */
  &twa_parallel_B.EncoderInput_o5,     /* 8: Signal */
  &twa_parallel_B.EncoderInput_o6,     /* 9: Signal */
  &twa_parallel_B.Kd[0],               /* 10: Signal */
  &twa_parallel_B.Kp[0],               /* 11: Signal */
  &twa_parallel_B.Saturation[0],       /* 12: Signal */
  &twa_parallel_B.Add[0],              /* 13: Signal */
  &twa_parallel_B.Sum[0],              /* 14: Signal */
  &twa_parallel_B.Sum1[0],             /* 15: Signal */
  &twa_parallel_B.Switch_l[0],         /* 16: Signal */
  &twa_parallel_B.q_cmd[0],            /* 17: Signal */
  &twa_parallel_B.q_dot[0],            /* 18: Signal */
  &twa_parallel_B.q_dub_dot[0],        /* 19: Signal */
  &twa_parallel_B.confn,               /* 20: Signal */
  &twa_parallel_B.t0n,                 /* 21: Signal */
  &twa_parallel_B.q0n[0],              /* 22: Signal */
  &twa_parallel_B.robot_mov,           /* 23: Signal */
  &twa_parallel_B.DigitalClock,        /* 24: Signal */
  &twa_parallel_B.UnitDelay,           /* 25: Signal */
  &twa_parallel_B.UnitDelay1,          /* 26: Signal */
  &twa_parallel_B.UnitDelay2[0],       /* 27: Signal */
  &twa_parallel_B.enc_res,             /* 28: Signal */
  &twa_parallel_B.gear_ratio,          /* 29: Signal */
  &twa_parallel_B.enc_res_l,           /* 30: Signal */
  &twa_parallel_B.gear_ratio_p,        /* 31: Signal */
  &twa_parallel_B.enc_res_f,           /* 32: Signal */
  &twa_parallel_B.gear_ratio_c,        /* 33: Signal */
  &twa_parallel_B.enc_res_c,           /* 34: Signal */
  &twa_parallel_B.gear_ratio_l,        /* 35: Signal */
  &twa_parallel_B.enc_res_fa,          /* 36: Signal */
  &twa_parallel_B.gear_ratio_j,        /* 37: Signal */
  &twa_parallel_B.enc_res_b,           /* 38: Signal */
  &twa_parallel_B.gear_ratio_n,        /* 39: Signal */
  &twa_parallel_B.Diff_j[0],           /* 40: Signal */
  &twa_parallel_B.Uk1_e[0],            /* 41: Signal */
  &twa_parallel_B.TSamp_a[0],          /* 42: Signal */
  &twa_parallel_B.NSampleEnable,       /* 43: Signal */
  &twa_parallel_B.Switch_f[0],         /* 44: Signal */
  &twa_parallel_B.Gain_n[0],           /* 45: Signal */
  &twa_parallel_B.DiscreteFIRFilter_h[0],/* 46: Signal */
  &twa_parallel_B.Diff[0],             /* 47: Signal */
  &twa_parallel_B.Uk1[0],              /* 48: Signal */
  &twa_parallel_B.TSamp[0],            /* 49: Signal */
  &twa_parallel_B.Gain[0],             /* 50: Signal */
  &twa_parallel_B.DiscreteFIRFilter[0],/* 51: Signal */
  &twa_parallel_P.cntrl_mode_Value,    /* 52: Block Parameter */
  &twa_parallel_P.ee_rot_Value,        /* 53: Block Parameter */
  &twa_parallel_P.ee_velmex_pitch_Value,/* 54: Block Parameter */
  &twa_parallel_P.micro_leg_len_Value[0],/* 55: Block Parameter */
  &twa_parallel_P.q_des_Value[0],      /* 56: Block Parameter */
  &twa_parallel_P.x_des_Value[0],      /* 57: Block Parameter */
  &twa_parallel_P.AnalogOutput_P1[0],  /* 58: Block Parameter */
  &twa_parallel_P.Init_P1,             /* 59: Block Parameter */
  &twa_parallel_P.Init_P2,             /* 60: Block Parameter */
  &twa_parallel_P.Init_P3,             /* 61: Block Parameter */
  &twa_parallel_P.Init_P4,             /* 62: Block Parameter */
  &twa_parallel_P.enc_reset_Value,     /* 63: Block Parameter */
  &twa_parallel_P.EncoderInput_P1[0],  /* 64: Block Parameter */
  &twa_parallel_P.EncoderInput_P2,     /* 65: Block Parameter */
  &twa_parallel_P.manual_current_Value[0],/* 66: Block Parameter */
  &twa_parallel_P.pd_mode_Value,       /* 67: Block Parameter */
  &twa_parallel_P.Kd_Gain[0],          /* 68: Block Parameter */
  &twa_parallel_P.Kp_Gain[0],          /* 69: Block Parameter */
  &twa_parallel_P.Saturation_UpperSat[0],/* 70: Block Parameter */
  &twa_parallel_P.Saturation_LowerSat[0],/* 71: Block Parameter */
  &twa_parallel_P.quintic_enable_Value,/* 72: Block Parameter */
  &twa_parallel_P.tf_Value,            /* 73: Block Parameter */
  &twa_parallel_P.UnitDelay_X0,        /* 74: Block Parameter */
  &twa_parallel_P.UnitDelay1_X0,       /* 75: Block Parameter */
  &twa_parallel_P.UnitDelay2_X0[0],    /* 76: Block Parameter */
  &twa_parallel_P.enc_res_Gain,        /* 77: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain,     /* 78: Block Parameter */
  &twa_parallel_P.enc_res_Gain_j,      /* 79: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_i,   /* 80: Block Parameter */
  &twa_parallel_P.enc_res_Gain_jz,     /* 81: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_d,   /* 82: Block Parameter */
  &twa_parallel_P.enc_res_Gain_i,      /* 83: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_a,   /* 84: Block Parameter */
  &twa_parallel_P.enc_res_Gain_g,      /* 85: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_o,   /* 86: Block Parameter */
  &twa_parallel_P.enc_res_Gain_ij,     /* 87: Block Parameter */
  &twa_parallel_P.gear_ratio_Gain_da,  /* 88: Block Parameter */
  &twa_parallel_P.UD_X0_o,             /* 89: Block Parameter */
  &twa_parallel_P.TSamp_WtEt_a,        /* 90: Block Parameter */
  &twa_parallel_P.NSampleEnable_TARGETCNT,/* 91: Block Parameter */
  &twa_parallel_P.NSampleEnable_ACTLEVEL,/* 92: Block Parameter */
  &twa_parallel_P.vel_filter_coeffs_Value_m[0],/* 93: Block Parameter */
  &twa_parallel_P.Gain_Gain_d,         /* 94: Block Parameter */
  &twa_parallel_P.DiscreteFIRFilter_IC_b,/* 95: Block Parameter */
  &twa_parallel_P.UD_X0,               /* 96: Block Parameter */
  &twa_parallel_P.TSamp_WtEt,          /* 97: Block Parameter */
  &twa_parallel_P.vel_filter_coeffs_Value[0],/* 98: Block Parameter */
  &twa_parallel_P.Gain_Gain,           /* 99: Block Parameter */
  &twa_parallel_P.DiscreteFIRFilter_IC /* 100: Block Parameter */
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
  { rtBlockSignals, 52 },

  { rtBlockParameters, 49,
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
