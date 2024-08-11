/*
 * twa_parallel_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "twa_parallel.mdl".
 *
 * Model version              : 1.6959
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Sun Aug 11 16:49:43 2024
 *
 * Target selection: xpctargetert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&twa_parallel_B.EncoderInput_o1), 0, 0, 268 },

  { (char_T *)(&twa_parallel_B.NSampleEnable), 8, 0, 1 }
  ,

  { (char_T *)(&twa_parallel_DWork.DiscreteFIRFilter_states[0]), 0, 0, 60 },

  { (char_T *)(&twa_parallel_DWork.DiscreteFIRFilter_circBuf), 6, 0, 2 },

  { (char_T *)(&twa_parallel_DWork.NSampleEnable_Counter), 7, 0, 1 },

  { (char_T *)(&twa_parallel_DWork.SFunction_IWORK.AcquireOK), 10, 0, 5 },

  { (char_T *)(&twa_parallel_DWork.Homing_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&twa_parallel_DWork.is_active_c5_twa_parallel), 3, 0, 3 },

  { (char_T *)(&twa_parallel_DWork.isStable), 8, 0, 6 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&twa_parallel_P.eq_eps_Value), 0, 0, 235 },

  { (char_T *)(&twa_parallel_P.NSampleEnable_TARGETCNT), 7, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] twa_parallel_dt.h */
