/*
 * File: twa_parallel_data.c
 *
 * Real-Time Workshop code generated for Simulink model twa_parallel.
 *
 * Model version                        : 1.6855
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Thu Jul 25 18:36:06 2024
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Thu Jul 25 18:36:06 2024
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
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S2>/eq_eps'
                                        */
  0.25,                                /* Expression: 0.25
                                        * Referenced by: '<S2>/kp'
                                        */
  0.002,                               /* Expression: dt
                                        * Referenced by: '<S2>/dt'
                                        */

  /*  Expression: p_in_m
   * Referenced by: '<S2>/p_in_m'
   */
  { 3.8971143170299726E+001, -2.2500000000000021E+001, 0.0,
    2.7554552980815448E-015, 45.0, 0.0, -3.8971143170299740E+001,
    -2.2500000000000004E+001, 0.0 },

  /*  Expression: b_in_w
   * Referenced by: '<S2>/b_in_w'
   */
  { 1.4057324354229004E+002, -8.1160000000000068E+001, 0.0,
    9.9392334218799176E-015, 1.6232E+002, 0.0, -1.4057324354229007E+002,
    -8.1160000000000011E+001, 0.0 },

  /*  Expression: meas_macro_len
   * Referenced by: '<S2>/meas_macro_len'
   */
  { 1.2479E+002, 125.42, 125.23 },
  1.27,                                /* Expression: velmex_pitch
                                        * Referenced by: '<S2>/velmex_pitch'
                                        */

  /*  Expression: meas_macro_len
   * Referenced by: '<S2>/Unit Delay1'
   */
  { 1.2479E+002, 125.42, 125.23 },

  /*  Expression: eq_homing
   * Referenced by: '<S2>/Unit Delay4'
   */
  { -5.9417157358376471E-001, 3.5828426416230741E-002, -1.5417157358376699E-001
  },

  /*  Expression: zeros(3,1)
   * Referenced by: '<S2>/Unit Delay3'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: rm2w_homing
   * Referenced by: '<S2>/Unit Delay2'
   */
  { 8.6602540378443871E-001, 4.9999999999999994E-001, 0.0,
    -4.9999999999999994E-001, 8.6602540378443871E-001, 0.0, 0.0, 0.0, 1.0 },
  5.2359877559829882E-001,             /* Expression: pi/6
                                        * Referenced by: '<S2>/ee_rot'
                                        */
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
                                        * Referenced by: '<S7>/enc_res'
                                        */
  2.2807017543859648E-001,             /* Expression: 1/gear_rat
                                        * Referenced by: '<S7>/gear_ratio'
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
  0.0009765625,                        /* Expression: 1/twa_enc_res
                                        * Referenced by: '<S10>/enc_res'
                                        */
  6.0326254232071407E-002,             /* Expression: 1/twa_gear_rat
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

  /*  Expression: vel_filter_coeffs
   * Referenced by: '<S15>/vel_filter_coeffs'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Discrete FIR Filter'
                                        */
  0.5,                                 /* Expression: 1/N_velocity
                                        * Referenced by: '<S15>/Gain'
                                        */
  500.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S14>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S14>/UD'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset'
                                        */

  /*  Expression: vel_filter_coeffs
   * Referenced by: '<S22>/vel_filter_coeffs'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Discrete FIR Filter'
                                        */
  0.5,                                 /* Expression: 1/N_velocity
                                        * Referenced by: '<S22>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/do_homing'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/cntrl_mode'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<Root>/q_des'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: zeros(3,1)
   * Referenced by: '<S6>/x_des'
   */
  { 0.0, 0.0, 0.0 },
  5.2359877559829882E-001,             /* Expression: pi/6
                                        * Referenced by: '<S6>/ee_rot'
                                        */

  /*  Expression: zeros(3,1)
   * Referenced by: '<S6>/Unit Delay1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: zeros(3,1)
   * Referenced by: '<S6>/Unit Delay2'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: zeros(3,1)
   * Referenced by: '<S6>/Unit Delay'
   */
  { 0.0, 0.0, 0.0 },
  1.27,                                /* Expression: velmex_pitch
                                        * Referenced by: '<S27>/ee_velmex_pitch'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S4>/tf'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay1'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<S4>/Unit Delay2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/quintic_enable'
                                        */

  /*  Expression: K_p
   * Referenced by: '<S3>/Kp'
   */
  { 225.0, 200.0, 250.0, 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/reset_integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */

  /*  Expression: K_i
   * Referenced by: '<S3>/Ki'
   */
  { 18.0, 18.0, 18.0, 0.25, 0.25, 0.25 },

  /*  Expression: [5,5,5,.25,0.25,0.25]
   * Referenced by: '<S3>/saturate_int'
   */
  { 5.0, 5.0, 5.0, 0.25, 0.25, 0.25 },

  /*  Expression: -1*[5,5,5,.25,0.25,0.25]
   * Referenced by: '<S3>/saturate_int'
   */
  { -5.0, -5.0, -5.0, -0.25, -0.25, -0.25 },
  500.0,                               /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S18>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S18>/UD'
                                        */

  /*  Expression: K_d
   * Referenced by: '<S3>/Kd'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  Expression: [10,10,10,2,2,2]
   * Referenced by: '<S3>/Saturation'
   */
  { 10.0, 10.0, 10.0, 2.0, 2.0, 2.0 },

  /*  Expression: -1*[10,10,10,2,2,2]
   * Referenced by: '<S3>/Saturation'
   */
  { -10.0, -10.0, -10.0, -2.0, -2.0, -2.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/pid_mode'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<S3>/manual_current'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1U,                                  /* Computed Parameter: NSampleEnable_TARGETCNT
                                        * Referenced by: '<S21>/N-Sample Enable'
                                        */
  2U                                   /* Computed Parameter: NSampleEnable_ACTLEVEL
                                        * Referenced by: '<S21>/N-Sample Enable'
                                        */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
