/*
 * File: twa_parallel_data.c
 *
 * Real-Time Workshop code generated for Simulink model twa_parallel.
 *
 * Model version                        : 1.6680
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Wed Jun 12 15:41:39 2024
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Wed Jun 12 15:41:39 2024
 *
 * Target selection: xpctargetert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "twa_parallel.h"
#include "twa_parallel_private.h"

/* Block parameters (auto storage) */
Parameters_twa_parallel twa_parallel_P = {
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<Root>/Init'
                                        */
  768.0,                               /* Expression: baseaddressD
                                        * Referenced by: '<Root>/Init'
                                        */
  5.0,                                 /* Expression: irq_num
                                        * Referenced by: '<Root>/Init'
                                        */
  0.0,                                 /* Expression: debug_flag
                                        * Referenced by: '<Root>/Init'
                                        */

  /*  Expression: channels
   * Referenced by: '<Root>/Analog Output'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0 },

  /*  Expression: channels
   * Referenced by: '<S1>/Encoder Input'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0 },
  360.0,                               /* Expression: countrev
                                        * Referenced by: '<S1>/Encoder Input'
                                        */
  0.0009765625,                        /* Expression: 1/enc_res
                                        * Referenced by: '<S8>/enc_res'
                                        */
  2.2807017543859648E-001,             /* Expression: 1/gear_rat
                                        * Referenced by: '<S8>/gear_ratio'
                                        */
  0.0009765625,                        /* Expression: 1/enc_res
                                        * Referenced by: '<S9>/enc_res'
                                        */
  2.2807017543859648E-001,             /* Expression: 1/gear_rat
                                        * Referenced by: '<S9>/gear_ratio'
                                        */
  0.0009765625,                        /* Expression: 1/enc_res
                                        * Referenced by: '<S10>/enc_res'
                                        */
  2.2807017543859648E-001,             /* Expression: 1/gear_rat
                                        * Referenced by: '<S10>/gear_ratio'
                                        */
  0.0009765625,                        /* Expression: 1/twa_enc_res
                                        * Referenced by: '<S11>/enc_res'
                                        */
  6.0326254232071407E-002,             /* Expression: 1/twa_gear_rat
                                        * Referenced by: '<S11>/gear_ratio'
                                        */
  0.0009765625,                        /* Expression: 1/twa_enc_res
                                        * Referenced by: '<S12>/enc_res'
                                        */
  6.0326254232071407E-002,             /* Expression: 1/twa_gear_rat
                                        * Referenced by: '<S12>/gear_ratio'
                                        */
  0.0009765625,                        /* Expression: 1/twa_enc_res
                                        * Referenced by: '<S13>/enc_res'
                                        */
  6.0326254232071407E-002,             /* Expression: 1/twa_gear_rat
                                        * Referenced by: '<S13>/gear_ratio'
                                        */

  /*  Expression: vel_filter_coeffs
   * Referenced by: '<S16>/vel_filter_coeffs'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Discrete FIR Filter'
                                        */
  0.5,                                 /* Expression: 1/N_velocity
                                        * Referenced by: '<S16>/Gain'
                                        */
  500.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S15>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S15>/UD'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset'
                                        */

  /*  Expression: vel_filter_coeffs
   * Referenced by: '<S20>/vel_filter_coeffs'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Discrete FIR Filter'
                                        */
  0.5,                                 /* Expression: 1/N_velocity
                                        * Referenced by: '<S20>/Gain'
                                        */

  /*  Expression: zeros(3,1)
   * Referenced by: '<Root>/x_des'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/ee_rot'
                                        */
  1.27,                                /* Expression: velmex_pitch
                                        * Referenced by: '<Root>/ee_velmex_pitch'
                                        */

  /*  Expression: zeros(3,1)
   * Referenced by: '<Root>/micro_leg_len'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/cntrl_mode'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<Root>/q_des'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S6>/tf'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay1'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<S6>/Unit Delay2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/quintic_enable'
                                        */

  /*  Expression: K_p
   * Referenced by: '<S5>/Kp'
   */
  { 35.0, 45.0, 20.0, 1.0, 1.0, 1.0 },
  500.0,                               /* Computed Parameter: TSamp_WtEt_a
                                        * Referenced by: '<S17>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S17>/UD'
                                        */

  /*  Expression: K_d
   * Referenced by: '<S5>/Kd'
   */
  { 0.25, 0.25, 0.25, 0.25, 0.25, 0.25 },

  /*  Expression: [10,10,10,2,2,2]
   * Referenced by: '<S5>/Saturation'
   */
  { 10.0, 10.0, 10.0, 2.0, 2.0, 2.0 },

  /*  Expression: -1*[10,10,10,2,2,2]
   * Referenced by: '<S5>/Saturation'
   */
  { -10.0, -10.0, -10.0, -2.0, -2.0, -2.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/pd_mode'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<S5>/manual_current'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1U,                                  /* Computed Parameter: NSampleEnable_TARGETCNT
                                        * Referenced by: '<S19>/N-Sample Enable'
                                        */
  2U                                   /* Computed Parameter: NSampleEnable_ACTLEVEL
                                        * Referenced by: '<S19>/N-Sample Enable'
                                        */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
