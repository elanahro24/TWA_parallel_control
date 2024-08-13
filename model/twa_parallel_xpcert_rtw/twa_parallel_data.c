/*
 * File: twa_parallel_data.c
 *
 * Real-Time Workshop code generated for Simulink model twa_parallel.
 *
 * Model version                        : 1.7020
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Mon Aug 12 20:20:22 2024
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Mon Aug 12 20:20:22 2024
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
                                        * Referenced by: '<S6>/enc_res'
                                        */
  2.2807017543859648E-001,             /* Expression: 1/gear_rat
                                        * Referenced by: '<S6>/gear_ratio'
                                        */
  1.27,                                /* Expression: velmex_pitch
                                        * Referenced by: '<S6>/velmex_pitch'
                                        */
  0.0009765625,                        /* Expression: 1/enc_res
                                        * Referenced by: '<S7>/enc_res'
                                        */
  2.2807017543859648E-001,             /* Expression: 1/gear_rat
                                        * Referenced by: '<S7>/gear_ratio'
                                        */
  1.27,                                /* Expression: velmex_pitch
                                        * Referenced by: '<S7>/velmex_pitch'
                                        */
  0.0009765625,                        /* Expression: 1/enc_res
                                        * Referenced by: '<S8>/enc_res'
                                        */
  2.2807017543859648E-001,             /* Expression: 1/gear_rat
                                        * Referenced by: '<S8>/gear_ratio'
                                        */
  1.27,                                /* Expression: velmex_pitch
                                        * Referenced by: '<S8>/velmex_pitch'
                                        */
  0.0009765625,                        /* Expression: 1/twa_enc_res
                                        * Referenced by: '<S9>/enc_res'
                                        */
  6.0326254232071407E-002,             /* Expression: 1/twa_gear_rat
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

  /*  Expression: vel_filter_coeffs
   * Referenced by: '<S14>/vel_filter_coeffs'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Discrete FIR Filter'
                                        */
  0.5,                                 /* Expression: 1/N_velocity
                                        * Referenced by: '<S14>/Gain'
                                        */
  500.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S13>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S13>/UD'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset6'
                                        */

  /*  Expression: vel_filter_coeffs
   * Referenced by: '<S18>/vel_filter_coeffs'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Discrete FIR Filter'
                                        */
  0.5,                                 /* Expression: 1/N_velocity
                                        * Referenced by: '<S18>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/cntrl_mode'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<Root>/q_des'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: zeros(3,1)
   * Referenced by: '<S5>/x_des'
   */
  { 0.0, 0.0, 0.0 },
  5.2359877559829882E-001,             /* Expression: pi/6
                                        * Referenced by: '<S5>/ee_rot_des'
                                        */
  0.002,                               /* Expression: dt
                                        * Referenced by: '<S5>/dt'
                                        */

  /*  Expression: p_in_m
   * Referenced by: '<S5>/p_in_m'
   */
  { 3.8971143170299726E+001, -2.2500000000000021E+001, 0.0,
    2.7554552980815448E-015, 45.0, 0.0, -3.8971143170299740E+001,
    -2.2500000000000004E+001, 0.0 },

  /*  Expression: b_in_w
   * Referenced by: '<S5>/b_in_w'
   */
  { 1.4466350201102856E+002, -7.3609582987170469E+001, 0.0,
    -8.5839821766459057E+000, 1.6208705923555718E+002, 0.0,
    -1.3607951983438267E+002, -8.8477476248386822E+001, 0.0 },

  /*  Expression: m_in_w
   * Referenced by: '<S5>/m_in_w'
   */
  { -5.2888240882858959E+001, -2.3235668412239983E+002, 0.0,
    2.2767091163054408E+002, 7.0375781895173233E+001, 0.0,
    -1.7478267074768499E+002, 1.6198090222722661E+002, 0.0 },

  /*  Expression: f_in_w
   * Referenced by: '<S5>/f_in_w'
   */
  { 5.6568542494923804E+001, -5.6568542494923797E+001, 0.0,
    2.0705523608201659E+001, 7.7274066103125463E+001, 0.0,
    -7.6900935675065512E+001, -2.2050988465359922E+001, 0.0 },

  /*  Expression: zeros(6,1)
   * Referenced by: '<S5>/Unit Delay1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: zeros(3,1)
   * Referenced by: '<S5>/Unit Delay4'
   */
  { 0.0, 0.0, 0.0 },
  5.2359877559829882E-001,             /* Expression: pi/6
                                        * Referenced by: '<S5>/Unit Delay3'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/tf'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay1'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<S3>/Unit Delay2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/quintic_enable'
                                        */

  /*  Expression: K_p
   * Referenced by: '<S2>/Kp'
   */
  { 50.0, 50.0, 50.0, 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/reset_integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */

  /*  Expression: K_i
   * Referenced by: '<S2>/Ki'
   */
  { 18.0, 18.0, 18.0, 0.25, 0.25, 0.25 },

  /*  Expression: [5,5,5,.25,0.25,0.25]
   * Referenced by: '<S2>/saturate_int'
   */
  { 5.0, 5.0, 5.0, 0.25, 0.25, 0.25 },

  /*  Expression: -1*[5,5,5,.25,0.25,0.25]
   * Referenced by: '<S2>/saturate_int'
   */
  { -5.0, -5.0, -5.0, -0.25, -0.25, -0.25 },
  500.0,                               /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S15>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S15>/UD'
                                        */

  /*  Expression: K_d
   * Referenced by: '<S2>/Kd'
   */
  { 0.1, 0.1, 0.1, 0.1, 0.1, 0.1 },

  /*  Expression: [10,10,10,2,2,2]
   * Referenced by: '<S2>/Saturation'
   */
  { 10.0, 10.0, 10.0, 2.0, 2.0, 2.0 },

  /*  Expression: -1*[10,10,10,2,2,2]
   * Referenced by: '<S2>/Saturation'
   */
  { -10.0, -10.0, -10.0, -2.0, -2.0, -2.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/pid_mode'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<S2>/manual_current'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: t_in_w
   * Referenced by: '<S5>/t_in_w'
   */
  { 1.4243556993353818E+002, -9.2235651485464956E+001, 0.0,
    8.6606323542513639E+000, 1.6947064770769154E+002, 0.0,
    -1.5109620228778959E+002, -7.7234996222226684E+001, 0.0 },
  2.0261003687626575E-001,             /* Expression: twa_gamma
                                        * Referenced by: '<S5>/twa_gamma'
                                        */
  0.0,                                 /* Expression: use_twa
                                        * Referenced by: '<S5>/use_twa'
                                        */
  16.7,                                /* Expression: twa_flange_offset
                                        * Referenced by: '<S5>/twa_flange_offset'
                                        */
  1U,                                  /* Computed Parameter: NSampleEnable_TARGETCNT
                                        * Referenced by: '<S17>/N-Sample Enable'
                                        */
  2U                                   /* Computed Parameter: NSampleEnable_ACTLEVEL
                                        * Referenced by: '<S17>/N-Sample Enable'
                                        */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
