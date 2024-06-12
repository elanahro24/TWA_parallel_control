/*
 * twa_parallel.c
 *
 * Real-Time Workshop code generation for Simulink model "twa_parallel.mdl".
 *
 * Model version              : 1.6677
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Tue Jun 11 18:47:24 2024
 *
 * Target selection: xpctargetert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "twa_parallel_capi.h"
#include "twa_parallel.h"
#include "twa_parallel_private.h"
#include <stdio.h>
#include "twa_parallel_dt.h"

/* Block signals (auto storage) */
BlockIO_twa_parallel twa_parallel_B;

/* Block states (auto storage) */
D_Work_twa_parallel twa_parallel_DWork;

/* Real-time model */
rtModel_twa_parallel twa_parallel_rtM_;
rtModel_twa_parallel *twa_parallel_rtM = &twa_parallel_rtM_;

/* Forward declaration for local functions */
static real_T twa_parallel_norm(const real_T eml_x[3]);

/* Function for Embedded MATLAB: '<Root>/GetMacroLegLen' */
static real_T twa_parallel_norm(const real_T eml_x[3])
{
  real_T eml_y;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  real_T eml_xk;
  real_T eml_t;
  eml_y = 0.0;
  eml_scale = 0.0;
  eml_firstNonZero = TRUE;
  eml_xk = eml_x[0];
  if (eml_xk != 0.0) {
    eml_xk = fabs(eml_xk);
    eml_scale = eml_xk;
    eml_y = 1.0;
    eml_firstNonZero = FALSE;
  }

  eml_xk = eml_x[1];
  if (eml_xk != 0.0) {
    eml_xk = fabs(eml_xk);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
      eml_firstNonZero = FALSE;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  eml_xk = eml_x[2];
  if (eml_xk != 0.0) {
    eml_xk = fabs(eml_xk);
    if (eml_firstNonZero) {
      eml_scale = eml_xk;
      eml_y = 1.0;
    } else if (eml_scale < eml_xk) {
      eml_t = eml_scale / eml_xk;
      eml_y = eml_y * eml_t * eml_t + 1.0;
      eml_scale = eml_xk;
    } else {
      eml_t = eml_xk / eml_scale;
      eml_y += eml_t * eml_t;
    }
  }

  return eml_scale * sqrt(eml_y);
}

/* Model output function */
void twa_parallel_output(int_T tid)
{
  real_T eml_vertex_dist[9];
  boolean_T eml_y;
  boolean_T eml_x[3];
  int32_T eml_k;
  boolean_T eml_exitg;
  real_T eml_eta[6];
  real_T eml_a[6];
  real_T eml_b_c;
  real_T eml_g_c;
  real_T eml_h_c;
  real_T eml_i_c;
  int32_T uIdx;
  int32_T k;
  int32_T idxN;
  int32_T cff;
  int32_T j;
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T eml_velmex_stroke_idx;
  real_T eml_velmex_stroke_idx_0;
  real_T eml_velmex_stroke_idx_1;
  static real_T tmp_2[9] = { 3.8988463678375417E+001, -2.2510000000000023E+001,
    0.0, 2.7566799448806924E-015, 45.02, 0.0, -3.8988463678375432E+001,
    -2.2510000000000005E+001, 0.0 };

  static real_T tmp_3[9] = { 1.3856406460551014E+002, -8.0000000000000071E+001,
    0.0, 9.7971743931788261E-015, 160.0, 0.0, -1.3856406460551017E+002,
    -8.0000000000000014E+001, 0.0 };

  /* S-Function (initstgmodel2): '<Root>/Init' */
  {
    /* S-Function Block: <Root>/Init (initstgmodel2)*/
    {
      if (0==1) {
        extern struct ServoToGo StgController;
        short PARAMS[6];
        PARAMS[0] = StgController.wBaseAddress;
        PARAMS[1] = StgController.wIrq;
        PARAMS[2] = StgController.wModel;
        PARAMS[3] = StgController.wNoBoardFlag;
        PARAMS[4] = StgController.wAxesInSys;
        PARAMS[5] = StgController.wSaveDirs;
      }
    }
  }

  /* S-Function (dastgmodel2): '<Root>/Analog Output' */
  {
    /* S-Function Block: <Root>/Analog Output (dastgmodel2)*/
    {
      short i;

      {
        if ((twa_parallel_B.Switch_l[0] <= 10.) && (twa_parallel_B.Switch_l[0] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_l[0] * 409.6 + .5);
          RawDAC(0, i);
        } else {
          if (twa_parallel_B.Switch_l[0] > 10.)
            RawDAC(0, 4096.5);
          else
            RawDAC(0, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_l[1] <= 10.) && (twa_parallel_B.Switch_l[1] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_l[1] * 409.6 + .5);
          RawDAC(1, i);
        } else {
          if (twa_parallel_B.Switch_l[1] > 10.)
            RawDAC(1, 4096.5);
          else
            RawDAC(1, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_l[2] <= 10.) && (twa_parallel_B.Switch_l[2] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_l[2] * 409.6 + .5);
          RawDAC(2, i);
        } else {
          if (twa_parallel_B.Switch_l[2] > 10.)
            RawDAC(2, 4096.5);
          else
            RawDAC(2, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_l[3] <= 10.) && (twa_parallel_B.Switch_l[3] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_l[3] * 409.6 + .5);
          RawDAC(3, i);
        } else {
          if (twa_parallel_B.Switch_l[3] > 10.)
            RawDAC(3, 4096.5);
          else
            RawDAC(3, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_l[4] <= 10.) && (twa_parallel_B.Switch_l[4] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_l[4] * 409.6 + .5);
          RawDAC(4, i);
        } else {
          if (twa_parallel_B.Switch_l[4] > 10.)
            RawDAC(4, 4096.5);
          else
            RawDAC(4, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_l[5] <= 10.) && (twa_parallel_B.Switch_l[5] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_l[5] * 409.6 + .5);
          RawDAC(5, i);
        } else {
          if (twa_parallel_B.Switch_l[5] > 10.)
            RawDAC(5, 4096.5);
          else
            RawDAC(5, -4096.0 + .5);
        }
      }
    }
  }

  /* S-Function (encstgmodel2): '<S1>/Encoder Input' */
  {
    /* S-Function Block: <S1>/Encoder Input (encstgmodel2)*/
    {
      short i;
      LONGBYTE enc[8];
      EncoderLatch();
      EncReadAll(&enc);

      {
        if (twa_parallel_P.enc_reset_Value==1) {
          SetEncoderCounts(0, 0);
          twa_parallel_B.EncoderInput_o1 = 0;
        } else
          twa_parallel_B.EncoderInput_o1 = (double) enc[0].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset_Value==1) {
          SetEncoderCounts(1, 0);
          twa_parallel_B.EncoderInput_o2 = 0;
        } else
          twa_parallel_B.EncoderInput_o2 = (double) enc[1].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset_Value==1) {
          SetEncoderCounts(2, 0);
          twa_parallel_B.EncoderInput_o3 = 0;
        } else
          twa_parallel_B.EncoderInput_o3 = (double) enc[2].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset_Value==1) {
          SetEncoderCounts(3, 0);
          twa_parallel_B.EncoderInput_o4 = 0;
        } else
          twa_parallel_B.EncoderInput_o4 = (double) enc[3].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset_Value==1) {
          SetEncoderCounts(4, 0);
          twa_parallel_B.EncoderInput_o5 = 0;
        } else
          twa_parallel_B.EncoderInput_o5 = (double) enc[4].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset_Value==1) {
          SetEncoderCounts(5, 0);
          twa_parallel_B.EncoderInput_o6 = 0;
        } else
          twa_parallel_B.EncoderInput_o6 = (double) enc[5].Long/1;
      }
    }
  }

  /* Gain: '<S8>/enc_res' */
  twa_parallel_B.enc_res = twa_parallel_P.enc_res_Gain *
    twa_parallel_B.EncoderInput_o1;

  /* Gain: '<S8>/gear_ratio' */
  twa_parallel_B.gear_ratio = twa_parallel_P.gear_ratio_Gain *
    twa_parallel_B.enc_res;

  /* Gain: '<S9>/enc_res' */
  twa_parallel_B.enc_res_l = twa_parallel_P.enc_res_Gain_j *
    twa_parallel_B.EncoderInput_o2;

  /* Gain: '<S9>/gear_ratio' */
  twa_parallel_B.gear_ratio_p = twa_parallel_P.gear_ratio_Gain_i *
    twa_parallel_B.enc_res_l;

  /* Gain: '<S10>/enc_res' */
  twa_parallel_B.enc_res_f = twa_parallel_P.enc_res_Gain_jz *
    twa_parallel_B.EncoderInput_o3;

  /* Gain: '<S10>/gear_ratio' */
  twa_parallel_B.gear_ratio_c = twa_parallel_P.gear_ratio_Gain_d *
    twa_parallel_B.enc_res_f;

  /* Gain: '<S11>/enc_res' */
  twa_parallel_B.enc_res_c = twa_parallel_P.enc_res_Gain_i *
    twa_parallel_B.EncoderInput_o4;

  /* Gain: '<S11>/gear_ratio' */
  twa_parallel_B.gear_ratio_l = twa_parallel_P.gear_ratio_Gain_a *
    twa_parallel_B.enc_res_c;

  /* Gain: '<S12>/enc_res' */
  twa_parallel_B.enc_res_fa = twa_parallel_P.enc_res_Gain_g *
    twa_parallel_B.EncoderInput_o5;

  /* Gain: '<S12>/gear_ratio' */
  twa_parallel_B.gear_ratio_j = twa_parallel_P.gear_ratio_Gain_o *
    twa_parallel_B.enc_res_fa;

  /* Gain: '<S13>/enc_res' */
  twa_parallel_B.enc_res_b = twa_parallel_P.enc_res_Gain_ij *
    twa_parallel_B.EncoderInput_o6;

  /* Gain: '<S13>/gear_ratio' */
  twa_parallel_B.gear_ratio_n = twa_parallel_P.gear_ratio_Gain_da *
    twa_parallel_B.enc_res_b;

  /* SignalConversion: '<S16>/TmpSignal ConversionAtDiscrete FIR FilterInport1' */
  twa_parallel_B.TmpSignalConversionAtDiscreteFI[0] = twa_parallel_B.gear_ratio;
  twa_parallel_B.TmpSignalConversionAtDiscreteFI[1] =
    twa_parallel_B.gear_ratio_p;
  twa_parallel_B.TmpSignalConversionAtDiscreteFI[2] =
    twa_parallel_B.gear_ratio_c;
  twa_parallel_B.TmpSignalConversionAtDiscreteFI[3] =
    twa_parallel_B.gear_ratio_l;
  twa_parallel_B.TmpSignalConversionAtDiscreteFI[4] =
    twa_parallel_B.gear_ratio_j;
  twa_parallel_B.TmpSignalConversionAtDiscreteFI[5] =
    twa_parallel_B.gear_ratio_n;

  /* DiscreteFir: '<S16>/Discrete FIR Filter' incorporates:
   *  Constant: '<S16>/vel_filter_coeffs'
   */
  uIdx = 0;
  for (k = 0; k < 6; k++) {
    idxN = twa_parallel_DWork.DiscreteFIRFilter_circBuf;
    eml_velmex_stroke_idx = twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx]
      * twa_parallel_P.vel_filter_coeffs_Value[0];
    uIdx++;
    cff = 1;
    for (j = idxN; j < 1; j++) {
      eml_k = k + j;
      eml_velmex_stroke_idx += twa_parallel_DWork.DiscreteFIRFilter_states[eml_k]
        * twa_parallel_P.vel_filter_coeffs_Value[cff];
      cff++;
    }

    for (j = 0; j < idxN; j++) {
      eml_k = k + j;
      eml_velmex_stroke_idx += twa_parallel_DWork.DiscreteFIRFilter_states[eml_k]
        * twa_parallel_P.vel_filter_coeffs_Value[cff];
      cff++;
    }

    twa_parallel_B.DiscreteFIRFilter[k] = eml_velmex_stroke_idx;
  }

  for (uIdx = 0; uIdx < 6; uIdx++) {
    /* Gain: '<S16>/Gain' */
    twa_parallel_B.Gain[uIdx] = twa_parallel_P.Gain_Gain *
      twa_parallel_B.DiscreteFIRFilter[uIdx];

    /* SampleTimeMath: '<S15>/TSamp'
     *
     * About '<S15>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    twa_parallel_B.TSamp[uIdx] = twa_parallel_B.Gain[uIdx] *
      twa_parallel_P.TSamp_WtEt;

    /* UnitDelay: '<S15>/UD' */
    twa_parallel_B.Uk1[uIdx] = twa_parallel_DWork.UD_DSTATE[uIdx];

    /* Sum: '<S15>/Diff' */
    twa_parallel_B.Diff[uIdx] = twa_parallel_B.TSamp[uIdx] -
      twa_parallel_B.Uk1[uIdx];
  }

  /* ok to acquire for <S21>/S-Function */
  twa_parallel_DWork.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S22>/S-Function */
  twa_parallel_DWork.SFunction_IWORK_j.AcquireOK = 1;

  /* DiscreteFir: '<S20>/Discrete FIR Filter' incorporates:
   *  Constant: '<S20>/vel_filter_coeffs'
   */
  uIdx = 0;
  for (k = 0; k < 6; k++) {
    idxN = twa_parallel_DWork.DiscreteFIRFilter_circBuf_l;
    eml_velmex_stroke_idx = twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx]
      * twa_parallel_P.vel_filter_coeffs_Value_m[0];
    uIdx++;
    cff = 1;
    for (j = idxN; j < 1; j++) {
      eml_k = k + j;
      eml_velmex_stroke_idx +=
        twa_parallel_DWork.DiscreteFIRFilter_states_m[eml_k] *
        twa_parallel_P.vel_filter_coeffs_Value_m[cff];
      cff++;
    }

    for (j = 0; j < idxN; j++) {
      eml_k = k + j;
      eml_velmex_stroke_idx +=
        twa_parallel_DWork.DiscreteFIRFilter_states_m[eml_k] *
        twa_parallel_P.vel_filter_coeffs_Value_m[cff];
      cff++;
    }

    twa_parallel_B.DiscreteFIRFilter_h[k] = eml_velmex_stroke_idx;
  }

  /* Gain: '<S20>/Gain' */
  for (uIdx = 0; uIdx < 6; uIdx++) {
    twa_parallel_B.Gain_n[uIdx] = twa_parallel_P.Gain_Gain_d *
      twa_parallel_B.DiscreteFIRFilter_h[uIdx];
  }

  /* ok to acquire for <S23>/S-Function */
  twa_parallel_DWork.SFunction_IWORK_i.AcquireOK = 1;

  /* Embedded MATLAB: '<Root>/GetMacroLegLen' incorporates:
   *  Constant: '<Root>/ee_rot'
   *  Constant: '<Root>/x_des'
   */
  /* Embedded MATLAB Function 'GetMacroLegLen': '<S2>:1' */
  /*  This function solves for the vertex positions of the base and moving */
  /*  platform for a given desired end effector position. */
  /*  With vertex positions known, leg lengths can be solved for. */
  /*  moving platform radius */
  /* [mm] */
  /*  base radius */
  /* [mm] */
  /*  position of flexure centers */
  /*  radius of position of flexure center */
  /* [mm] */
  /*  position of twa pivot point, taken from CAD */
  /*  radius of position of twa pivot */
  /*  rotation matrix of moving frame about z-xis */
  /*  ee_rot = 0; */
  /* '<S2>:1:26' */
  /*  moving platform vertex locations */
  /*  x_des = zeros(3,1); */
  /* '<S2>:1:33' */
  /*  base vertex positions */
  /* '<S2>:1:36' */
  /* '<S2>:1:38' */
  tmp[0] = cos(twa_parallel_P.ee_rot_Value);
  tmp[3] = -sin(twa_parallel_P.ee_rot_Value);
  tmp[6] = 0.0;
  tmp[1] = sin(twa_parallel_P.ee_rot_Value);
  tmp[4] = cos(twa_parallel_P.ee_rot_Value);
  tmp[7] = 0.0;
  tmp[2] = 0.0;
  tmp[5] = 0.0;
  tmp[8] = 1.0;
  for (uIdx = 0; uIdx < 3; uIdx++) {
    tmp_0[uIdx] = 0.0;
    tmp_0[uIdx] += twa_parallel_P.x_des_Value[uIdx];
    tmp_0[uIdx + 3] = 0.0;
    tmp_0[uIdx + 3] += twa_parallel_P.x_des_Value[uIdx];
    tmp_0[uIdx + 6] = 0.0;
    tmp_0[uIdx + 6] += twa_parallel_P.x_des_Value[uIdx];
  }

  for (uIdx = 0; uIdx < 3; uIdx++) {
    for (k = 0; k < 3; k++) {
      tmp_1[uIdx + 3 * k] = 0.0;
      tmp_1[uIdx + 3 * k] = tmp_1[3 * k + uIdx] + tmp_2[3 * k] * tmp[uIdx];
      tmp_1[uIdx + 3 * k] = tmp_2[3 * k + 1] * tmp[uIdx + 3] + tmp_1[3 * k +
        uIdx];
      tmp_1[uIdx + 3 * k] = tmp_2[3 * k + 2] * tmp[uIdx + 6] + tmp_1[3 * k +
        uIdx];
    }
  }

  for (uIdx = 0; uIdx < 3; uIdx++) {
    eml_vertex_dist[3 * uIdx] = (tmp_0[3 * uIdx] + tmp_1[3 * uIdx]) - tmp_3[3 *
      uIdx];
    eml_vertex_dist[1 + 3 * uIdx] = (tmp_0[3 * uIdx + 1] + tmp_1[3 * uIdx + 1])
      - tmp_3[3 * uIdx + 1];
    eml_vertex_dist[2 + 3 * uIdx] = (tmp_0[3 * uIdx + 2] + tmp_1[3 * uIdx + 2])
      - tmp_3[3 * uIdx + 2];
  }

  /* '<S2>:1:40' */
  twa_parallel_B.macro_leg_len[0] = 0.0;
  twa_parallel_B.macro_leg_len[1] = 0.0;
  twa_parallel_B.macro_leg_len[2] = 0.0;

  /* '<S2>:1:41' */
  twa_parallel_B.macro_leg_len[0] = twa_parallel_norm(*((real_T (*)[3])&
    eml_vertex_dist[0]));

  /* '<S2>:1:42' */
  twa_parallel_B.macro_leg_len[1] = twa_parallel_norm(*((real_T (*)[3])&
    eml_vertex_dist[3]));

  /* '<S2>:1:43' */
  twa_parallel_B.macro_leg_len[2] = twa_parallel_norm(*((real_T (*)[3])&
    eml_vertex_dist[6]));

  /* SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport3' */
  twa_parallel_B.TmpSignalConversionAtSFunctio_i[0] = twa_parallel_B.gear_ratio;
  twa_parallel_B.TmpSignalConversionAtSFunctio_i[1] =
    twa_parallel_B.gear_ratio_p;
  twa_parallel_B.TmpSignalConversionAtSFunctio_i[2] =
    twa_parallel_B.gear_ratio_c;
  twa_parallel_B.TmpSignalConversionAtSFunctio_i[3] =
    twa_parallel_B.gear_ratio_l;
  twa_parallel_B.TmpSignalConversionAtSFunctio_i[4] =
    twa_parallel_B.gear_ratio_j;
  twa_parallel_B.TmpSignalConversionAtSFunctio_i[5] =
    twa_parallel_B.gear_ratio_n;

  /* Embedded MATLAB: '<Root>/GetMacroQDes' incorporates:
   *  Constant: '<Root>/ee_velmex_pitch'
   */
  /* Embedded MATLAB Function 'GetMacroQDes': '<S3>:1' */
  /*  This function solves for command signal for given desired macro leg */
  /*  lengths */
  /* '<S3>:1:5' */
  /* '<S3>:1:7' */
  /* '<S3>:1:11' */
  twa_parallel_B.qmacro_des[0] = twa_parallel_B.TmpSignalConversionAtSFunctio_i
    [0];
  twa_parallel_B.qmacro_des[1] = twa_parallel_B.TmpSignalConversionAtSFunctio_i
    [1];
  twa_parallel_B.qmacro_des[2] = twa_parallel_B.TmpSignalConversionAtSFunctio_i
    [2];

  /* '<S3>:1:12' */
  eml_velmex_stroke_idx = twa_parallel_B.macro_leg_len[0] - 120.0;

  /* '<S3>:1:13' */
  eml_velmex_stroke_idx_0 = twa_parallel_B.macro_leg_len[1] - 120.0;

  /* '<S3>:1:14' */
  eml_velmex_stroke_idx_1 = twa_parallel_B.macro_leg_len[2] - 120.0;
  eml_x[0] = (eml_velmex_stroke_idx < 196.0);
  eml_x[1] = (eml_velmex_stroke_idx_0 < 196.0);
  eml_x[2] = (eml_velmex_stroke_idx_1 < 196.0);
  eml_y = TRUE;
  eml_k = 1;
  eml_exitg = FALSE;
  while (((uint32_T)eml_exitg == 0U) && (eml_k <= 3)) {
    if ((int32_T)eml_x[eml_k - 1] == 0) {
      eml_y = FALSE;
      eml_exitg = TRUE;
    } else {
      eml_k++;
    }
  }

  if (eml_y) {
    /* '<S3>:1:17' */
    twa_parallel_B.qmacro_des[0] = eml_velmex_stroke_idx /
      twa_parallel_P.ee_velmex_pitch_Value;
    twa_parallel_B.qmacro_des[1] = eml_velmex_stroke_idx_0 /
      twa_parallel_P.ee_velmex_pitch_Value;
    twa_parallel_B.qmacro_des[2] = eml_velmex_stroke_idx_1 /
      twa_parallel_P.ee_velmex_pitch_Value;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport1' */
  twa_parallel_B.TmpSignalConversionAtSFunctio_e[0] = twa_parallel_B.gear_ratio;
  twa_parallel_B.TmpSignalConversionAtSFunctio_e[1] =
    twa_parallel_B.gear_ratio_p;
  twa_parallel_B.TmpSignalConversionAtSFunctio_e[2] =
    twa_parallel_B.gear_ratio_c;
  twa_parallel_B.TmpSignalConversionAtSFunctio_e[3] =
    twa_parallel_B.gear_ratio_l;
  twa_parallel_B.TmpSignalConversionAtSFunctio_e[4] =
    twa_parallel_B.gear_ratio_j;
  twa_parallel_B.TmpSignalConversionAtSFunctio_e[5] =
    twa_parallel_B.gear_ratio_n;

  /* Embedded MATLAB: '<Root>/GetMicroQDes' incorporates:
   *  Constant: '<Root>/micro_leg_len'
   */
  /* Embedded MATLAB Function 'GetMicroQDes': '<S4>:1' */
  /*  This function solves for command signal for the twa's given a desired */
  /*  micro leg length */
  /* '<S4>:1:5' */
  /* '<S4>:1:7' */
  /* [mm] */
  /* '<S4>:1:10' */
  twa_parallel_B.qmicro_des[0] = twa_parallel_B.TmpSignalConversionAtSFunctio_e
    [3];
  twa_parallel_B.qmicro_des[1] = twa_parallel_B.TmpSignalConversionAtSFunctio_e
    [4];
  twa_parallel_B.qmicro_des[2] = twa_parallel_B.TmpSignalConversionAtSFunctio_e
    [5];

  /* '<S4>:1:11' */
  eml_velmex_stroke_idx = 2.258E+002 - twa_parallel_P.micro_leg_len_Value[0];

  /* '<S4>:1:12' */
  eml_velmex_stroke_idx_0 = 2.263E+002 - twa_parallel_P.micro_leg_len_Value[1];

  /* '<S4>:1:13' */
  eml_velmex_stroke_idx_1 = 224.5 - twa_parallel_P.micro_leg_len_Value[2];

  /* '<S4>:1:15' */
  twa_parallel_B.qmicro_des[0] = sqrt((5.0985640000000007E+004 - rt_pow_snf
    (eml_velmex_stroke_idx, 2.0)) / 1.9516089999999996E-002);

  /* [rad] */
  /* '<S4>:1:16' */
  twa_parallel_B.qmicro_des[1] = sqrt((5.121169E+004 - rt_pow_snf
    (eml_velmex_stroke_idx_0, 2.0)) / 1.9516089999999996E-002);

  /* '<S4>:1:17' */
  twa_parallel_B.qmicro_des[2] = sqrt((50400.25 - rt_pow_snf
    (eml_velmex_stroke_idx_1, 2.0)) / 1.9516089999999996E-002);

  /* convert to rotations from radians */
  /* '<S4>:1:20' */
  twa_parallel_B.qmicro_des[0] = twa_parallel_B.qmicro_des[0] /
    6.2831853071795862E+000;
  twa_parallel_B.qmicro_des[1] = twa_parallel_B.qmicro_des[1] /
    6.2831853071795862E+000;
  twa_parallel_B.qmicro_des[2] = twa_parallel_B.qmicro_des[2] /
    6.2831853071795862E+000;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/cntrl_mode'
   *  Constant: '<Root>/q_des'
   */
  if (twa_parallel_P.cntrl_mode_Value != 0.0) {
    twa_parallel_B.Switch[0] = twa_parallel_B.qmacro_des[0];
    twa_parallel_B.Switch[1] = twa_parallel_B.qmacro_des[1];
    twa_parallel_B.Switch[2] = twa_parallel_B.qmacro_des[2];
    twa_parallel_B.Switch[3] = twa_parallel_B.qmicro_des[0];
    twa_parallel_B.Switch[4] = twa_parallel_B.qmicro_des[1];
    twa_parallel_B.Switch[5] = twa_parallel_B.qmicro_des[2];
  } else {
    for (uIdx = 0; uIdx < 6; uIdx++) {
      twa_parallel_B.Switch[uIdx] = twa_parallel_P.q_des_Value[uIdx];
    }
  }

  /* DigitalClock: '<S6>/Digital Clock' */
  twa_parallel_B.DigitalClock = twa_parallel_rtM->Timing.t[1];

  /* UnitDelay: '<S6>/Unit Delay' */
  twa_parallel_B.UnitDelay = twa_parallel_DWork.UnitDelay_DSTATE;

  /* UnitDelay: '<S6>/Unit Delay1' */
  twa_parallel_B.UnitDelay1 = twa_parallel_DWork.UnitDelay1_DSTATE;

  /* Signal Processing Blockset N-Sample Enable  (sdspnsamp2) - '<S19>/N-Sample Enable' */
  {
    {
      if (twa_parallel_DWork.NSampleEnable_Counter ==
          twa_parallel_P.NSampleEnable_TARGETCNT) {
        twa_parallel_B.NSampleEnable = (boolean_T)(2 -
          twa_parallel_P.NSampleEnable_ACTLEVEL);
      } else {
        twa_parallel_B.NSampleEnable = (boolean_T)
          (twa_parallel_P.NSampleEnable_ACTLEVEL - 1);
        (twa_parallel_DWork.NSampleEnable_Counter)++;
      }
    }
  }

  /* SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport2' */
  twa_parallel_B.TmpSignalConversionAtSFunctionI[0] = twa_parallel_B.gear_ratio;
  twa_parallel_B.TmpSignalConversionAtSFunctionI[1] =
    twa_parallel_B.gear_ratio_p;
  twa_parallel_B.TmpSignalConversionAtSFunctionI[2] =
    twa_parallel_B.gear_ratio_c;
  twa_parallel_B.TmpSignalConversionAtSFunctionI[3] =
    twa_parallel_B.gear_ratio_l;
  twa_parallel_B.TmpSignalConversionAtSFunctionI[4] =
    twa_parallel_B.gear_ratio_j;
  twa_parallel_B.TmpSignalConversionAtSFunctionI[5] =
    twa_parallel_B.gear_ratio_n;

  /* Embedded MATLAB: '<S6>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S6>/quintic_enable'
   *  Constant: '<S6>/tf'
   */
  /* Embedded MATLAB Function 'Quintic Poly/Embedded MATLAB Function': '<S18>:1' */
  /*  number of actuators */
  /* '<S18>:1:5' */
  twa_parallel_B.robot_mov = 0.0;

  /* '<S18>:1:6' */
  for (uIdx = 0; uIdx < 6; uIdx++) {
    /* UnitDelay: '<S6>/Unit Delay2' */
    twa_parallel_B.UnitDelay2[uIdx] = twa_parallel_DWork.UnitDelay2_DSTATE[uIdx];

    /* Switch: '<S19>/Switch' */
    if (twa_parallel_B.NSampleEnable) {
      twa_parallel_B.Switch_f[uIdx] =
        twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx];
    } else {
      twa_parallel_B.Switch_f[uIdx] = twa_parallel_B.UnitDelay2[uIdx];
    }

    eml_eta[uIdx] = twa_parallel_B.Switch[uIdx] - twa_parallel_B.Switch_f[uIdx];
  }

  if (twa_parallel_P.quintic_enable_Value != 0.0) {
    for (uIdx = 0; uIdx < 6; uIdx++) {
      eml_a[uIdx] = eml_eta[uIdx];
    }

    eml_velmex_stroke_idx = 0.0;
    eml_k = 1;
    uIdx = 1;
    for (k = 0; k < 6; k++) {
      eml_velmex_stroke_idx += eml_a[eml_k - 1] * eml_eta[uIdx - 1];
      eml_k++;
      uIdx++;
    }

    if (eml_velmex_stroke_idx > 0.0) {
      /* '<S18>:1:9' */
      /*  conf = 0 means that the 5th order poly */
      /*  is not configured for the desired trajectory. */
      /*  Therefore, the block is initialized. */
      if (twa_parallel_B.UnitDelay == 0.0) {
        /* '<S18>:1:13' */
        /* '<S18>:1:14' */
        /* '<S18>:1:15' */
        twa_parallel_B.t0n = twa_parallel_B.DigitalClock;

        /* '<S18>:1:16' */
        twa_parallel_B.confn = 1.0;

        /* '<S18>:1:17' */
        /* '<S18>:1:18' */
        /* '<S18>:1:19' */
        for (uIdx = 0; uIdx < 6; uIdx++) {
          twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch_f[uIdx];
          twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.Switch_f[uIdx];
          twa_parallel_B.q_dot[uIdx] = 0.0;
          twa_parallel_B.q_dub_dot[uIdx] = 0.0;
        }
      } else {
        /* '<S18>:1:21' */
        /* '<S18>:1:22' */
        twa_parallel_B.t0n = twa_parallel_B.UnitDelay1;

        /* '<S18>:1:23' */
        twa_parallel_B.confn = twa_parallel_B.UnitDelay;

        /*  5th order polynomial */
        /* '<S18>:1:27' */
        /* '<S18>:1:28' */
        /* '<S18>:1:29' */
        for (uIdx = 0; uIdx < 6; uIdx++) {
          eml_velmex_stroke_idx = eml_eta[uIdx];
          twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch_f[uIdx];
          eml_velmex_stroke_idx *= -15.0;
          twa_parallel_B.q_dub_dot[uIdx] = -6.6666666666666663E-001 *
            eml_velmex_stroke_idx;
          eml_a[uIdx] = -0.4 * eml_velmex_stroke_idx;
          eml_eta[uIdx] = eml_velmex_stroke_idx;
        }

        /* '<S18>:1:30' */
        eml_velmex_stroke_idx_0 = twa_parallel_B.DigitalClock -
          twa_parallel_B.UnitDelay1;

        /* '<S18>:1:31' */
        eml_velmex_stroke_idx = eml_velmex_stroke_idx_0 /
          twa_parallel_P.tf_Value;
        if (eml_velmex_stroke_idx_0 < twa_parallel_P.tf_Value) {
          /* '<S18>:1:33' */
          /* '<S18>:1:34' */
          twa_parallel_B.robot_mov = 1.0;

          /* '<S18>:1:35' */
          eml_velmex_stroke_idx_1 = rt_pow_snf(eml_velmex_stroke_idx, 3.0);
          eml_b_c = rt_pow_snf(eml_velmex_stroke_idx, 4.0);
          eml_velmex_stroke_idx = rt_pow_snf(eml_velmex_stroke_idx, 5.0);
          for (uIdx = 0; uIdx < 6; uIdx++) {
            twa_parallel_B.q_cmd[uIdx] = ((twa_parallel_B.q_dub_dot[uIdx] *
              eml_velmex_stroke_idx_1 + twa_parallel_B.Switch_f[uIdx]) +
              eml_eta[uIdx] * eml_b_c) + eml_a[uIdx] * eml_velmex_stroke_idx;
          }

          /* '<S18>:1:36' */
          eml_velmex_stroke_idx = rt_pow_snf(eml_velmex_stroke_idx_0, 2.0);
          eml_velmex_stroke_idx_1 = rt_pow_snf(twa_parallel_P.tf_Value, 3.0);
          eml_b_c = rt_pow_snf(eml_velmex_stroke_idx_0, 3.0);
          eml_g_c = rt_pow_snf(twa_parallel_P.tf_Value, 4.0);
          eml_h_c = rt_pow_snf(eml_velmex_stroke_idx_0, 4.0);
          eml_i_c = rt_pow_snf(twa_parallel_P.tf_Value, 5.0);
          for (uIdx = 0; uIdx < 6; uIdx++) {
            twa_parallel_B.q_dot[uIdx] = (3.0 * twa_parallel_B.q_dub_dot[uIdx] *
              eml_velmex_stroke_idx / eml_velmex_stroke_idx_1 + 4.0 *
              eml_eta[uIdx] * eml_b_c / eml_g_c) + 5.0 * eml_a[uIdx] * eml_h_c /
              eml_i_c;
          }

          /* '<S18>:1:37' */
          eml_velmex_stroke_idx = rt_pow_snf(twa_parallel_P.tf_Value, 3.0);
          eml_velmex_stroke_idx_1 = rt_pow_snf(eml_velmex_stroke_idx_0, 2.0);
          eml_b_c = rt_pow_snf(twa_parallel_P.tf_Value, 4.0);
          eml_g_c = rt_pow_snf(eml_velmex_stroke_idx_0, 3.0);
          eml_h_c = rt_pow_snf(twa_parallel_P.tf_Value, 5.0);
          for (uIdx = 0; uIdx < 6; uIdx++) {
            twa_parallel_B.q_dub_dot[uIdx] = (6.0 *
              twa_parallel_B.q_dub_dot[uIdx] * eml_velmex_stroke_idx_0 /
              eml_velmex_stroke_idx + 12.0 * eml_eta[uIdx] *
              eml_velmex_stroke_idx_1 / eml_b_c) + 20.0 * eml_a[uIdx] * eml_g_c /
              eml_h_c;
          }
        } else {
          /* '<S18>:1:39' */
          /* '<S18>:1:40' */
          /* '<S18>:1:41' */
          /* '<S18>:1:42' */
          for (uIdx = 0; uIdx < 6; uIdx++) {
            twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.Switch[uIdx];
            twa_parallel_B.q_dot[uIdx] = 0.0;
            twa_parallel_B.q_dub_dot[uIdx] = 0.0;
            twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch[uIdx];
          }
        }
      }
    } else {
      /* '<S18>:1:46' */
      /* '<S18>:1:47' */
      /* '<S18>:1:48' */
      /* '<S18>:1:49' */
      twa_parallel_B.confn = 0.0;

      /* '<S18>:1:50' */
      for (uIdx = 0; uIdx < 6; uIdx++) {
        twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.Switch[uIdx];
        twa_parallel_B.q_dot[uIdx] = 0.0;
        twa_parallel_B.q_dub_dot[uIdx] = 0.0;
        twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch_f[uIdx];
      }

      /* '<S18>:1:51' */
      twa_parallel_B.t0n = twa_parallel_B.UnitDelay1;
    }
  } else {
    /*  Configuration space is not used (pdot = 0). */
    /* '<S18>:1:55' */
    /* '<S18>:1:56' */
    /* '<S18>:1:57' */
    /*  However we do want to record the current */
    /* '<S18>:1:58' */
    twa_parallel_B.confn = 0.0;

    /*  position in order to be ready as soon */
    /* '<S18>:1:59' */
    twa_parallel_B.t0n = twa_parallel_B.DigitalClock;

    /*  as the enable becomes 1. */
    /* '<S18>:1:60' */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.Switch[uIdx];
      twa_parallel_B.q_dot[uIdx] = 0.0;
      twa_parallel_B.q_dub_dot[uIdx] = 0.0;
      twa_parallel_B.q0n[uIdx] =
        twa_parallel_B.TmpSignalConversionAtSFunctionI[uIdx];
    }
  }

  /* ------------------------------------------------------------------------ */
  for (uIdx = 0; uIdx < 6; uIdx++) {
    /* Saturate: '<S5>/Saturation' */

    /* Sum: '<S5>/Sum' */
    twa_parallel_B.Sum[uIdx] = twa_parallel_B.q_cmd[uIdx] -
      twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx];

    /* Gain: '<S5>/Kp' */
    twa_parallel_B.Kp[uIdx] = twa_parallel_P.Kp_Gain[uIdx] *
      twa_parallel_B.Sum[uIdx];

    /* SampleTimeMath: '<S17>/TSamp'
     *
     * About '<S17>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    twa_parallel_B.TSamp_a[uIdx] = twa_parallel_B.q_cmd[uIdx] *
      twa_parallel_P.TSamp_WtEt_a;

    /* UnitDelay: '<S17>/UD' */
    twa_parallel_B.Uk1_e[uIdx] = twa_parallel_DWork.UD_DSTATE_k[uIdx];

    /* Sum: '<S17>/Diff' */
    twa_parallel_B.Diff_j[uIdx] = twa_parallel_B.TSamp_a[uIdx] -
      twa_parallel_B.Uk1_e[uIdx];

    /* Sum: '<S5>/Sum1' */
    twa_parallel_B.Sum1[uIdx] = twa_parallel_B.Diff_j[uIdx] -
      twa_parallel_B.Diff[uIdx];

    /* Gain: '<S5>/Kd' */
    twa_parallel_B.Kd[uIdx] = twa_parallel_P.Kd_Gain[uIdx] *
      twa_parallel_B.Sum1[uIdx];

    /* Sum: '<S5>/Add' */
    twa_parallel_B.Add[uIdx] = twa_parallel_B.Kp[uIdx] + twa_parallel_B.Kd[uIdx];
    eml_velmex_stroke_idx = twa_parallel_B.Add[uIdx];
    twa_parallel_B.Saturation[uIdx] = rt_SATURATE(eml_velmex_stroke_idx,
      twa_parallel_P.Saturation_LowerSat[uIdx],
      twa_parallel_P.Saturation_UpperSat[uIdx]);

    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/manual_current'
     *  Constant: '<S5>/pd_mode'
     */
    if (twa_parallel_P.pd_mode_Value != 0.0) {
      twa_parallel_B.Switch_l[uIdx] = twa_parallel_B.Saturation[uIdx];
    } else {
      twa_parallel_B.Switch_l[uIdx] = twa_parallel_P.manual_current_Value[uIdx];
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void twa_parallel_update(int_T tid)
{
  int32_T k;

  /* Update for DiscreteFir: '<S16>/Discrete FIR Filter' */
  twa_parallel_DWork.DiscreteFIRFilter_circBuf =
    twa_parallel_DWork.DiscreteFIRFilter_circBuf - 1;
  if (twa_parallel_DWork.DiscreteFIRFilter_circBuf < 0) {
    twa_parallel_DWork.DiscreteFIRFilter_circBuf = 0;
  }

  for (k = 0; k < 6; k++) {
    twa_parallel_DWork.DiscreteFIRFilter_states[twa_parallel_DWork.DiscreteFIRFilter_circBuf
      + k] = twa_parallel_B.TmpSignalConversionAtDiscreteFI[k];
  }

  /* Update for UnitDelay: '<S15>/UD' */
  for (k = 0; k < 6; k++) {
    twa_parallel_DWork.UD_DSTATE[k] = twa_parallel_B.TSamp[k];
  }

  /* Update for DiscreteFir: '<S20>/Discrete FIR Filter' */
  twa_parallel_DWork.DiscreteFIRFilter_circBuf_l =
    twa_parallel_DWork.DiscreteFIRFilter_circBuf_l - 1;
  if (twa_parallel_DWork.DiscreteFIRFilter_circBuf_l < 0) {
    twa_parallel_DWork.DiscreteFIRFilter_circBuf_l = 0;
  }

  for (k = 0; k < 6; k++) {
    twa_parallel_DWork.DiscreteFIRFilter_states_m[twa_parallel_DWork.DiscreteFIRFilter_circBuf_l
      + k] = twa_parallel_B.TmpSignalConversionAtDiscreteFI[k];
  }

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  twa_parallel_DWork.UnitDelay_DSTATE = twa_parallel_B.confn;

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  twa_parallel_DWork.UnitDelay1_DSTATE = twa_parallel_B.t0n;
  for (k = 0; k < 6; k++) {
    /* Update for UnitDelay: '<S6>/Unit Delay2' */
    twa_parallel_DWork.UnitDelay2_DSTATE[k] = twa_parallel_B.q0n[k];

    /* Update for UnitDelay: '<S17>/UD' */
    twa_parallel_DWork.UD_DSTATE_k[k] = twa_parallel_B.TSamp_a[k];
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++twa_parallel_rtM->Timing.clockTick0)) {
    ++twa_parallel_rtM->Timing.clockTickH0;
  }

  twa_parallel_rtM->Timing.t[0] = twa_parallel_rtM->Timing.clockTick0 *
    twa_parallel_rtM->Timing.stepSize0 + twa_parallel_rtM->Timing.clockTickH0 *
    twa_parallel_rtM->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++twa_parallel_rtM->Timing.clockTick1)) {
      ++twa_parallel_rtM->Timing.clockTickH1;
    }

    twa_parallel_rtM->Timing.t[1] = twa_parallel_rtM->Timing.clockTick1 *
      twa_parallel_rtM->Timing.stepSize1 + twa_parallel_rtM->Timing.clockTickH1 *
      twa_parallel_rtM->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void twa_parallel_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)twa_parallel_rtM, 0,
                sizeof(rtModel_twa_parallel));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&twa_parallel_rtM->solverInfo,
                          &twa_parallel_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&twa_parallel_rtM->solverInfo, &rtmGetTPtr(twa_parallel_rtM));
    rtsiSetStepSizePtr(&twa_parallel_rtM->solverInfo,
                       &twa_parallel_rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&twa_parallel_rtM->solverInfo, (&rtmGetErrorStatus
      (twa_parallel_rtM)));
    rtsiSetRTModelPtr(&twa_parallel_rtM->solverInfo, twa_parallel_rtM);
  }

  rtsiSetSimTimeStep(&twa_parallel_rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&twa_parallel_rtM->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = twa_parallel_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    twa_parallel_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    twa_parallel_rtM->Timing.sampleTimes =
      (&twa_parallel_rtM->Timing.sampleTimesArray[0]);
    twa_parallel_rtM->Timing.offsetTimes =
      (&twa_parallel_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    twa_parallel_rtM->Timing.sampleTimes[0] = (0.0);
    twa_parallel_rtM->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    twa_parallel_rtM->Timing.offsetTimes[0] = (0.0);
    twa_parallel_rtM->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(twa_parallel_rtM, &twa_parallel_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = twa_parallel_rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    twa_parallel_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(twa_parallel_rtM, -1);
  twa_parallel_rtM->Timing.stepSize0 = 0.002;
  twa_parallel_rtM->Timing.stepSize1 = 0.002;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    twa_parallel_rtM->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(twa_parallel_rtM->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(twa_parallel_rtM->rtwLogInfo, (NULL));
    rtliSetLogT(twa_parallel_rtM->rtwLogInfo, "tout");
    rtliSetLogX(twa_parallel_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(twa_parallel_rtM->rtwLogInfo, "");
    rtliSetSigLog(twa_parallel_rtM->rtwLogInfo, "");
    rtliSetLogVarNameModifier(twa_parallel_rtM->rtwLogInfo, "rt_");
    rtliSetLogFormat(twa_parallel_rtM->rtwLogInfo, 2);
    rtliSetLogMaxRows(twa_parallel_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(twa_parallel_rtM->rtwLogInfo, 1);
    rtliSetLogY(twa_parallel_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(twa_parallel_rtM->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(twa_parallel_rtM->rtwLogInfo, (NULL));
  }

  /* external mode info */
  twa_parallel_rtM->Sizes.checksums[0] = (3230455310U);
  twa_parallel_rtM->Sizes.checksums[1] = (891657378U);
  twa_parallel_rtM->Sizes.checksums[2] = (2237461116U);
  twa_parallel_rtM->Sizes.checksums[3] = (3687892425U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    twa_parallel_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(twa_parallel_rtM->extModeInfo,
      &twa_parallel_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(twa_parallel_rtM->extModeInfo,
                        twa_parallel_rtM->Sizes.checksums);
    rteiSetTPtr(twa_parallel_rtM->extModeInfo, rtmGetTPtr(twa_parallel_rtM));
  }

  twa_parallel_rtM->solverInfoPtr = (&twa_parallel_rtM->solverInfo);
  twa_parallel_rtM->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&twa_parallel_rtM->solverInfo, 0.002);
  rtsiSetSolverMode(&twa_parallel_rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  twa_parallel_rtM->ModelData.blockIO = ((void *) &twa_parallel_B);
  (void) memset(((void *) &twa_parallel_B), 0,
                sizeof(BlockIO_twa_parallel));

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_B.TmpSignalConversionAtDiscreteFI[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.DiscreteFIRFilter[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Gain[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TSamp[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Uk1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Diff[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.DiscreteFIRFilter_h[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Gain_n[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.UnitDelay2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Switch_f[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Sum[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Kp[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TSamp_a[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Uk1_e[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Diff_j[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Sum1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Kd[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Add[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Saturation[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Switch_l[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TmpSignalConversionAtSFunctionI[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.q_cmd[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.q_dot[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.q_dub_dot[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.q0n[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TmpSignalConversionAtSFunctio_e[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TmpSignalConversionAtSFunctio_i[i] = 0.0;
    }

    twa_parallel_B.EncoderInput_o1 = 0.0;
    twa_parallel_B.EncoderInput_o2 = 0.0;
    twa_parallel_B.EncoderInput_o3 = 0.0;
    twa_parallel_B.EncoderInput_o4 = 0.0;
    twa_parallel_B.EncoderInput_o5 = 0.0;
    twa_parallel_B.EncoderInput_o6 = 0.0;
    twa_parallel_B.enc_res = 0.0;
    twa_parallel_B.gear_ratio = 0.0;
    twa_parallel_B.enc_res_l = 0.0;
    twa_parallel_B.gear_ratio_p = 0.0;
    twa_parallel_B.enc_res_f = 0.0;
    twa_parallel_B.gear_ratio_c = 0.0;
    twa_parallel_B.enc_res_c = 0.0;
    twa_parallel_B.gear_ratio_l = 0.0;
    twa_parallel_B.enc_res_fa = 0.0;
    twa_parallel_B.gear_ratio_j = 0.0;
    twa_parallel_B.enc_res_b = 0.0;
    twa_parallel_B.gear_ratio_n = 0.0;
    twa_parallel_B.DigitalClock = 0.0;
    twa_parallel_B.UnitDelay = 0.0;
    twa_parallel_B.UnitDelay1 = 0.0;
    twa_parallel_B.confn = 0.0;
    twa_parallel_B.t0n = 0.0;
    twa_parallel_B.robot_mov = 0.0;
    twa_parallel_B.qmicro_des[0] = 0.0;
    twa_parallel_B.qmicro_des[1] = 0.0;
    twa_parallel_B.qmicro_des[2] = 0.0;
    twa_parallel_B.qmacro_des[0] = 0.0;
    twa_parallel_B.qmacro_des[1] = 0.0;
    twa_parallel_B.qmacro_des[2] = 0.0;
    twa_parallel_B.macro_leg_len[0] = 0.0;
    twa_parallel_B.macro_leg_len[1] = 0.0;
    twa_parallel_B.macro_leg_len[2] = 0.0;
  }

  /* parameters */
  twa_parallel_rtM->ModelData.defaultParam = ((real_T *)&twa_parallel_P);

  /* states (dwork) */
  twa_parallel_rtM->Work.dwork = ((void *) &twa_parallel_DWork);
  (void) memset((void *)&twa_parallel_DWork, 0,
                sizeof(D_Work_twa_parallel));

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.DiscreteFIRFilter_states[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UD_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.DiscreteFIRFilter_states_m[i] = 0.0;
    }
  }

  twa_parallel_DWork.UnitDelay_DSTATE = 0.0;
  twa_parallel_DWork.UnitDelay1_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UnitDelay2_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UD_DSTATE_k[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    twa_parallel_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    twa_parallel_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  twa_parallel_InitializeDataMapInfo(twa_parallel_rtM);
}

/* Model terminate function */
void twa_parallel_terminate(void)
{
  /* Terminate for S-Function (dastgmodel2): '<Root>/Analog Output' */
  {
    /* S-Function Block: <Root>/Analog Output (dastgmodel2)*/
    {
      {
        RawDAC(0, 0);
      }

      {
        RawDAC(1, 0);
      }

      {
        RawDAC(2, 0);
      }

      {
        RawDAC(3, 0);
      }

      {
        RawDAC(4, 0);
      }

      {
        RawDAC(5, 0);
      }
    }
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  twa_parallel_output(tid);
}

void MdlUpdate(int_T tid)
{
  twa_parallel_update(tid);
}

void MdlInitializeSizes(void)
{
  twa_parallel_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  twa_parallel_rtM->Sizes.numY = (0);  /* Number of model outputs */
  twa_parallel_rtM->Sizes.numU = (0);  /* Number of model inputs */
  twa_parallel_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  twa_parallel_rtM->Sizes.numSampTimes = (2);/* Number of sample times */
  twa_parallel_rtM->Sizes.numBlocks = (69);/* Number of blocks */
  twa_parallel_rtM->Sizes.numBlockIO = (56);/* Number of block outputs */
  twa_parallel_rtM->Sizes.numBlockPrms = (100);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for DiscreteFir: '<S16>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf = 0;

    /* InitializeConditions for DiscreteFir: '<S20>/Discrete FIR Filter' */
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.DiscreteFIRFilter_states[i] =
        twa_parallel_P.DiscreteFIRFilter_IC;

      /* InitializeConditions for UnitDelay: '<S15>/UD' */
      twa_parallel_DWork.UD_DSTATE[i] = twa_parallel_P.UD_X0;
      twa_parallel_DWork.DiscreteFIRFilter_states_m[i] =
        twa_parallel_P.DiscreteFIRFilter_IC_b;
    }

    twa_parallel_DWork.DiscreteFIRFilter_circBuf_l = 0;

    /* InitializeConditions for Embedded MATLAB: '<Root>/GetMacroLegLen' */
    twa_parallel_DWork.is_active_c1_twa_parallel = 0U;

    /* InitializeConditions for Embedded MATLAB: '<Root>/GetMacroQDes' */
    twa_parallel_DWork.is_active_c4_twa_parallel = 0U;

    /* InitializeConditions for Embedded MATLAB: '<Root>/GetMicroQDes' */
    twa_parallel_DWork.is_active_c2_twa_parallel = 0U;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE = twa_parallel_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE = twa_parallel_P.UnitDelay1_X0;

    /* Signal Processing Blockset N-Sample Enable  (sdspnsamp2) - '<S19>/N-Sample Enable' */
    twa_parallel_DWork.NSampleEnable_Counter = (uint32_T) 0;

    /* InitializeConditions for Embedded MATLAB: '<S6>/Embedded MATLAB Function' */
    twa_parallel_DWork.is_active_c22_twa_parallel = 0U;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for UnitDelay: '<S6>/Unit Delay2' */
      twa_parallel_DWork.UnitDelay2_DSTATE[i] = twa_parallel_P.UnitDelay2_X0[i];

      /* InitializeConditions for UnitDelay: '<S17>/UD' */
      twa_parallel_DWork.UD_DSTATE_k[i] = twa_parallel_P.UD_X0_o;
    }
  }
}

void MdlStart(void)
{
  /* Start for S-Function (initstgmodel2): '<Root>/Init' */
  {
    extern struct IrqDataStruct IrqData;
    extern struct ServoToGo StgController;
    StgController.wBaseAddress = 768;
    StgController.wIrq = 5;
    IrqData.IRQ = 5;
    ServoToGo_Constructor2(IrqData.IRQ);
  }

  /* Start for S-Function (encstgmodel2): '<S1>/Encoder Input' */
  {
    int i;
    EncoderResetAddr();
    for (i = 0; i < 8; i++)
      SetEncoderCounts(i, 0);
  }

  /* S-Function Block: <S21>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s1"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s2"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s3"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s4"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s5"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s6"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s1"),"q1d [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s2"),"q2d [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s3"),"q3d [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s4"),"q4d [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s5"),"q5d [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s6"),"q6d [cnt] %12.4f");
        rl32eSetScope(2, 4, 25);
        rl32eSetScope(2, 40, 0);
        rl32eSetScope(2, 7, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 10, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, 0.0);
        rl32eSetTargetScope(2, 10, 0.0);
        xpceScopeAcqOK(2, &twa_parallel_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S22>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Scopes/Fir Filter/Gain/s1"));
        rl32eAddSignal(1, rl32eGetSignalNo("Scopes/Fir Filter/Gain/s2"));
        rl32eAddSignal(1, rl32eGetSignalNo("Scopes/Fir Filter/Gain/s3"));
        rl32eAddSignal(1, rl32eGetSignalNo("Scopes/Fir Filter/Gain/s4"));
        rl32eAddSignal(1, rl32eGetSignalNo("Scopes/Fir Filter/Gain/s5"));
        rl32eAddSignal(1, rl32eGetSignalNo("Scopes/Fir Filter/Gain/s6"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Scopes/Fir Filter/Gain/s1"),
          "q1 [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Scopes/Fir Filter/Gain/s2"),
          "q2 [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Scopes/Fir Filter/Gain/s3"),
          "q3 [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Scopes/Fir Filter/Gain/s4"),
          "q4 [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Scopes/Fir Filter/Gain/s5"),
          "q5 [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Scopes/Fir Filter/Gain/s6"),
          "q6 [cnt] %12.4f");
        rl32eSetScope(1, 4, 25);
        rl32eSetScope(1, 40, 0);
        rl32eSetScope(1, 7, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Scopes/Fir Filter/Gain/s1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 10, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 0.0);
        xpceScopeAcqOK(1, &twa_parallel_DWork.SFunction_IWORK_j.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S23>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Switch/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Switch/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Switch/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Switch/s4"));
        rl32eAddSignal(3, rl32eGetSignalNo("Switch/s5"));
        rl32eAddSignal(3, rl32eGetSignalNo("Switch/s6"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Switch/s1"),
          "q1_des [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Switch/s2"),
          "q2_des [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Switch/s3"),
          "q3_des [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Switch/s4"),
          "q4_des [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Switch/s5"),
          "q5_des [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Switch/s6"),
          "q6_des [cnt] %12.4f");
        rl32eSetScope(3, 4, 25);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Switch/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 10, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 0.0);
        xpceScopeAcqOK(3, &twa_parallel_DWork.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  twa_parallel_terminate();
}

rtModel_twa_parallel *twa_parallel(void)
{
  twa_parallel_initialize(1);
  return twa_parallel_rtM;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
