/*
 * File: twa_parallel_data.c
 *
 * Real-Time Workshop code generated for Simulink model twa_parallel.
 *
 * Model version                        : 1.6959
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Sun Aug 11 16:49:42 2024
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Sun Aug 11 16:49:43 2024
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
  { 1.4466350201102856E+002, -7.3609582987170469E+001, 0.0,
    -8.5839821766459057E+000, 1.6208705923555718E+002, 0.0,
    -1.3607951983438267E+002, -8.8477476248386822E+001, 0.0 },

  /*  Expression: m_in_w
   * Referenced by: '<S2>/m_in_w'
   */
  { -5.2888240882858959E+001, -2.3235668412239983E+002, 0.0,
    2.2767091163054408E+002, 7.0375781895173233E+001, 0.0,
    -1.7478267074768499E+002, 1.6198090222722661E+002, 0.0 },

  /*  Expression: f_in_w
   * Referenced by: '<S2>/f_in_w'
   */
  { 5.6568542494923804E+001, -5.6568542494923797E+001, 0.0,
    2.0705523608201659E+001, 7.7274066103125463E+001, 0.0,
    -7.6900935675065512E+001, -2.2050988465359922E+001, 0.0 },

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
  { 8.9010354868159425E-001, 1.5201035486815897E+000, 1.3301035486815920E+000 },

  /*  Expression: zeros(3,1)
   * Referenced by: '<S2>/Unit Delay3'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: rm2w_homing
   * Referenced by: '<S2>/Unit Delay2'
   */
  { 8.6602540378443871E-001, 4.9999999999999994E-001, 0.0,
    -4.9999999999999994E-001, 8.6602540378443871E-001, 0.0, 0.0, 0.0, 1.0 },
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
   * Referenced by: '<S21>/vel_filter_coeffs'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Discrete FIR Filter'
                                        */
  0.5,                                 /* Expression: 1/N_velocity
                                        * Referenced by: '<S21>/Gain'
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
                                        * Referenced by: '<S6>/ee_rot_des'
                                        */
  0.002,                               /* Expression: dt
                                        * Referenced by: '<S6>/dt'
                                        */

  /*  Expression: p_in_m
   * Referenced by: '<S6>/p_in_m'
   */
  { 3.8971143170299726E+001, -2.2500000000000021E+001, 0.0,
    2.7554552980815448E-015, 45.0, 0.0, -3.8971143170299740E+001,
    -2.2500000000000004E+001, 0.0 },

  /*  Expression: b_in_w
   * Referenced by: '<S6>/b_in_w'
   */
  { 1.4466350201102856E+002, -7.3609582987170469E+001, 0.0,
    -8.5839821766459057E+000, 1.6208705923555718E+002, 0.0,
    -1.3607951983438267E+002, -8.8477476248386822E+001, 0.0 },

  /*  Expression: m_in_w
   * Referenced by: '<S6>/m_in_w'
   */
  { -5.2888240882858959E+001, -2.3235668412239983E+002, 0.0,
    2.2767091163054408E+002, 7.0375781895173233E+001, 0.0,
    -1.7478267074768499E+002, 1.6198090222722661E+002, 0.0 },

  /*  Expression: f_in_w
   * Referenced by: '<S6>/f_in_w'
   */
  { 5.6568542494923804E+001, -5.6568542494923797E+001, 0.0,
    2.0705523608201659E+001, 7.7274066103125463E+001, 0.0,
    -7.6900935675065512E+001, -2.2050988465359922E+001, 0.0 },

  /*  Expression: zeros(6,1)
   * Referenced by: '<S6>/Unit Delay1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: zeros(3,1)
   * Referenced by: '<S6>/Unit Delay4'
   */
  { 0.0, 0.0, 0.0 },
  5.2359877559829882E-001,             /* Expression: pi/6
                                        * Referenced by: '<S6>/Unit Delay3'
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
                                        * Referenced by: '<S17>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S17>/UD'
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

  /*  Expression: t_in_w
   * Referenced by: '<S6>/t_in_w'
   */
  { 1.4243556993353818E+002, -9.2235651485464956E+001, 0.0,
    8.6606323542513639E+000, 1.6947064770769154E+002, 0.0,
    -1.5109620228778959E+002, -7.7234996222226684E+001, 0.0 },
  2.0261003687626575E-001,             /* Expression: twa_gamma
                                        * Referenced by: '<S6>/twa_gamma'
                                        */
  0.0,                                 /* Expression: use_twa
                                        * Referenced by: '<S6>/use_twa'
                                        */
  16.7,                                /* Expression: twa_flange_offset
                                        * Referenced by: '<S6>/twa_flange_offset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/do_homing'
                                        */
  1U,                                  /* Computed Parameter: NSampleEnable_TARGETCNT
                                        * Referenced by: '<S20>/N-Sample Enable'
                                        */
  2U                                   /* Computed Parameter: NSampleEnable_ACTLEVEL
                                        * Referenced by: '<S20>/N-Sample Enable'
                                        */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
