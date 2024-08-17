/*
 * twa_parallel.c
 *
 * Real-Time Workshop code generation for Simulink model "twa_parallel.mdl".
 *
 * Model version              : 1.7084
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Fri Aug 16 19:57:38 2024
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

/* Continuous states */
ContinuousStates_twa_parallel twa_parallel_X;

/* Block states (auto storage) */
D_Work_twa_parallel twa_parallel_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_twa_parallel twa_parallel_PrevZCSigState;

/* Real-time model */
rtModel_twa_parallel twa_parallel_rtM_;
rtModel_twa_parallel *twa_parallel_rtM = &twa_parallel_rtM_;

/* Forward declaration for local functions */
static real_T twa_parallel_norm(const real_T eml_x[3]);
static real_T twa_parallel_eml_xdotu(const real_T eml_x[3], const real_T eml_y[3]);
static void twa_parallel_mldivide(const real_T eml_A[36], const real_T eml_B[18],
  real_T eml_Y[18]);

/* This function updates continuous states using the ODE8 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
#define twa_parallel_NSTAGES           13

  static real_T rt_ODE8_B[13] = {
    4.174749114153025E-2, 0.0, 0.0, 0.0,
    0.0, -5.54523286112393E-2, 2.393128072011801E-1, 7.03510669403443E-1,
    -7.597596138144609E-1, 6.605630309222863E-1, 1.581874825101233E-1,
    -2.381095387528628E-1, 2.5E-1
  };

  static real_T rt_ODE8_C[13] = {
    0.0, 5.555555555555556E-2, 8.333333333333333E-2, 1.25E-1,
    3.125E-1, 3.75E-1, 1.475E-1, 4.65E-1,
    5.648654513822596E-1, 6.5E-1, 9.246562776405044E-1, 1.0, 1.0
  };

  static real_T rt_ODE8_A[13][13] = {
    /* rt_ODE8_A[0][] */
    { 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[1][] */
    { 5.555555555555556E-2, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[2][] */
    { 2.083333333333333E-2, 6.25E-2, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[3][] */
    { 3.125E-2, 0.0, 9.375E-2, 0.0,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[4][] */
    { 3.125E-1, 0.0, -1.171875, 1.171875,
      0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[5][] */
    { 3.75E-2, 0.0, 0.0, 1.875E-1,
      1.5E-1, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[6][] */
    { 4.791013711111111E-2, 0.0, 0.0, 1.122487127777778E-1,
      -2.550567377777778E-2, 1.284682388888889E-2, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[7][] */
    { 1.691798978729228E-2, 0.0, 0.0, 3.878482784860432E-1,
      3.597736985150033E-2, 1.969702142156661E-1, -1.727138523405018E-1, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[8][] */
    { 6.90957533591923E-2, 0.0, 0.0, -6.342479767288542E-1,
      -1.611975752246041E-1, 1.386503094588253E-1, 9.409286140357563E-1,
      2.11636326481944E-1,
      0.0, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[9][] */
    { 1.835569968390454E-1, 0.0, 0.0, -2.468768084315592,
      -2.912868878163005E-1, -2.647302023311738E-2, 2.8478387641928,
      2.813873314698498E-1,
      1.237448998633147E-1, 0.0, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[10][] */
    { -1.215424817395888, 0.0, 0.0, 1.667260866594577E1,
      9.157418284168179E-1, -6.056605804357471, -1.600357359415618E1,
      1.484930308629766E1,
      -1.337157573528985E1, 5.134182648179638, 0.0, 0.0, 0.0 },

    /* rt_ODE8_A[11][] */
    { 2.588609164382643E-1, 0.0, 0.0, -4.774485785489205,
      -4.350930137770325E-1, -3.049483332072241, 5.577920039936099,
      6.155831589861039,
      -5.062104586736938, 2.193926173180679, 1.346279986593349E-1, 0.0, 0.0 },

    /* rt_ODE8_A[12][] */
    { 8.224275996265075E-1, 0.0, 0.0, -1.165867325727766E1,
      -7.576221166909362E-1, 7.139735881595818E-1, 1.207577498689006E1,
      -2.127659113920403,
      1.990166207048956, -2.342864715440405E-1, 1.758985777079423E-1, 0.0, 0.0 },
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE8_IntgData *intgData = (ODE8_IntgData *) rtsiGetSolverData(si);
  real_T *deltaY = intgData->deltaY;
  real_T *x0 = intgData->x0;
  real_T* f[twa_parallel_NSTAGES];
  int idx,stagesIdx,statesIdx;
  double deltaX;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  f[0] = intgData->f[0];
  f[1] = intgData->f[1];
  f[2] = intgData->f[2];
  f[3] = intgData->f[3];
  f[4] = intgData->f[4];
  f[5] = intgData->f[5];
  f[6] = intgData->f[6];
  f[7] = intgData->f[7];
  f[8] = intgData->f[8];
  f[9] = intgData->f[9];
  f[10] = intgData->f[10];
  f[11] = intgData->f[11];
  f[12] = intgData->f[12];

  /* Save the state values at time t in y and x0*/
  (void) memset(deltaY, 0,
                nXc*sizeof(real_T));
  (void) memcpy(x0, x,
                nXc*sizeof(real_T));
  for (stagesIdx=0;stagesIdx<twa_parallel_NSTAGES;stagesIdx++) {
    (void) memcpy(x, x0,
                  nXc*sizeof(real_T));
    for (statesIdx=0;statesIdx<nXc;statesIdx++) {
      deltaX = 0;
      for (idx=0;idx<stagesIdx;idx++) {
        deltaX = deltaX + h*rt_ODE8_A[stagesIdx][idx]*f[idx][statesIdx];
      }

      x[statesIdx] = x0[statesIdx] + deltaX;
    }

    if (stagesIdx==0) {
      rtsiSetdX(si, f[stagesIdx]);
      twa_parallel_derivatives();
    } else {
      (stagesIdx==twa_parallel_NSTAGES-1)? rtsiSetT(si, tnew) : rtsiSetT(si, t +
        h*rt_ODE8_C[stagesIdx]);
      rtsiSetdX(si, f[stagesIdx]);
      twa_parallel_output(0);
      twa_parallel_derivatives();
    }

    for (statesIdx=0;statesIdx<nXc;statesIdx++) {
      deltaY[statesIdx] = deltaY[statesIdx] + h*rt_ODE8_B[stagesIdx]*f[stagesIdx]
        [statesIdx];
    }
  }

  for (statesIdx=0;statesIdx<nXc;statesIdx++) {
    x[statesIdx] = x0[statesIdx] + deltaY[statesIdx];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for Embedded MATLAB: '<S25>/get_jacobian' */
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

/* Function for Embedded MATLAB: '<S25>/get_jacobian' */
static real_T twa_parallel_eml_xdotu(const real_T eml_x[3], const real_T eml_y[3])
{
  real_T eml_d;
  eml_d = eml_x[0] * eml_y[0];
  eml_d += eml_x[1] * eml_y[1];
  eml_d += eml_x[2] * eml_y[2];
  return eml_d;
}

/* Function for Embedded MATLAB: '<S25>/get_jacobian' */
static void twa_parallel_mldivide(const real_T eml_A[36], const real_T eml_B[18],
  real_T eml_Y[18])
{
  real_T eml_temp;
  real_T eml_b_A[36];
  int8_T eml_ipiv[6];
  int32_T eml_i;
  int32_T eml_mmj;
  int32_T eml_jp1j;
  int32_T eml_b_j;
  real_T eml_smax;
  int32_T eml_jA;
  int32_T eml_d_k;
  int32_T eml_d_i;
  int32_T eml_c_loop_ub;
  int32_T eml_e_c;
  int32_T eml_f_c;
  memcpy((void *)&eml_b_A[0], (void *)&eml_A[0], 36U * sizeof(real_T));
  for (eml_b_j = 0; eml_b_j < 6; eml_b_j++) {
    eml_ipiv[eml_b_j] = (int8_T)(1 + eml_b_j);
  }

  for (eml_b_j = 0; eml_b_j < 5; eml_b_j++) {
    eml_mmj = 5 - eml_b_j;
    eml_c_loop_ub = eml_b_j * 7 + 1;
    eml_jp1j = eml_c_loop_ub + 1;
    eml_i = eml_mmj + 1;
    eml_e_c = 1;
    eml_d_k = eml_c_loop_ub;
    eml_temp = eml_b_A[eml_c_loop_ub - 1];
    eml_smax = fabs(eml_temp);
    for (eml_f_c = 2; eml_f_c <= eml_i; eml_f_c++) {
      eml_d_k++;
      eml_temp = eml_b_A[eml_d_k - 1];
      eml_temp = fabs(eml_temp);
      if (eml_temp > eml_smax) {
        eml_e_c = eml_f_c;
        eml_smax = eml_temp;
      }
    }

    eml_i = eml_e_c - 1;
    if (eml_b_A[(eml_c_loop_ub + eml_i) - 1] != 0.0) {
      if (eml_i != 0) {
        eml_ipiv[eml_b_j] = (int8_T)((eml_b_j + 1) + eml_i);
        eml_d_k = 1 + eml_b_j;
        eml_i += eml_d_k;
        for (eml_e_c = 0; eml_e_c < 6; eml_e_c++) {
          eml_temp = eml_b_A[eml_d_k - 1];
          eml_b_A[eml_d_k - 1] = eml_b_A[eml_i - 1];
          eml_b_A[eml_i - 1] = eml_temp;
          eml_d_k += 6;
          eml_i += 6;
        }
      }

      eml_i = (eml_mmj - 1) + eml_jp1j;
      for (eml_e_c = eml_jp1j; eml_e_c <= eml_i; eml_e_c++) {
        eml_b_A[eml_e_c - 1] /= eml_b_A[eml_c_loop_ub - 1];
      }
    }

    eml_d_i = 5 - eml_b_j;
    eml_jA = eml_c_loop_ub + 6;
    eml_i = eml_c_loop_ub + 6;
    for (eml_e_c = 1; eml_e_c <= eml_d_i; eml_e_c++) {
      eml_temp = eml_b_A[eml_i - 1];
      if (eml_temp != 0.0) {
        eml_temp = -eml_temp;
        eml_d_k = eml_jp1j;
        eml_f_c = eml_mmj + eml_jA;
        for (eml_c_loop_ub = 1 + eml_jA; eml_c_loop_ub <= eml_f_c; eml_c_loop_ub
             ++) {
          eml_b_A[eml_c_loop_ub - 1] += eml_b_A[eml_d_k - 1] * eml_temp;
          eml_d_k++;
        }
      }

      eml_i += 6;
      eml_jA += 6;
    }
  }

  memcpy((void *)&eml_Y[0], (void *)&eml_B[0], 18U * sizeof(real_T));
  for (eml_i = 0; eml_i < 6; eml_i++) {
    if (eml_i + 1 != eml_ipiv[eml_i]) {
      eml_e_c = eml_ipiv[eml_i];
      eml_temp = eml_Y[eml_i];
      eml_Y[eml_i] = eml_Y[eml_e_c - 1];
      eml_Y[eml_e_c - 1] = eml_temp;
      eml_temp = eml_Y[eml_i + 6];
      eml_Y[eml_i + 6] = eml_Y[eml_e_c + 5];
      eml_Y[eml_e_c + 5] = eml_temp;
      eml_temp = eml_Y[eml_i + 12];
      eml_Y[eml_i + 12] = eml_Y[eml_e_c + 11];
      eml_Y[eml_e_c + 11] = eml_temp;
    }
  }

  for (eml_i = 0; eml_i < 3; eml_i++) {
    eml_e_c = 6 * eml_i;
    for (eml_d_k = 0; eml_d_k < 6; eml_d_k++) {
      eml_f_c = 6 * eml_d_k;
      if (eml_Y[((eml_d_k + 1) + eml_e_c) - 1] != 0.0) {
        for (eml_c_loop_ub = eml_d_k + 2; eml_c_loop_ub <= 6; eml_c_loop_ub++) {
          eml_Y[(eml_c_loop_ub + eml_e_c) - 1] -= eml_Y[((eml_d_k + 1) + eml_e_c)
            - 1] * eml_b_A[(eml_c_loop_ub + eml_f_c) - 1];
        }
      }
    }
  }

  for (eml_i = 0; eml_i < 3; eml_i++) {
    eml_e_c = 6 * eml_i;
    for (eml_d_k = 6; eml_d_k > 0; eml_d_k += -1) {
      eml_f_c = (eml_d_k - 1) * 6;
      if (eml_Y[(eml_d_k + eml_e_c) - 1] != 0.0) {
        eml_Y[(eml_d_k + eml_e_c) - 1] /= eml_b_A[(eml_d_k + eml_f_c) - 1];
        eml_c_loop_ub = eml_d_k - 1;
        for (eml_d_i = 1; eml_d_i <= eml_c_loop_ub; eml_d_i++) {
          eml_Y[(eml_d_i + eml_e_c) - 1] -= eml_Y[(eml_d_k + eml_e_c) - 1] *
            eml_b_A[(eml_d_i + eml_f_c) - 1];
        }
      }
    }
  }
}

/* Model output function */
void twa_parallel_output(int_T tid)
{
  real_T eml_r_cur[9];
  real_T eml_p_in_w[9];
  real_T eml_n1hat[3];
  real_T eml_n2hat[3];
  real_T eml_n3hat[3];
  real_T eml_q1_mu;
  real_T eml_q2_mu;
  real_T eml_q3_mu;
  real_T eml_l1_hat[3];
  real_T eml_l2_hat[3];
  real_T eml_l3_hat[3];
  real_T eml_a;
  real_T eml_a_0;
  real_T eml_c;
  real_T eml_c_0;
  real_T eml_c_1;
  real_T eml_iik_jac[18];
  real_T eml_y;
  real_T eml_d_y[3];
  real_T eml_e_y[3];
  real_T eml_f_y[3];
  real_T eml_Y[18];
  int32_T eml_rtemp;
  real_T eml_p_del;
  boolean_T eml_b_x[3];
  boolean_T eml_firstNonZero;
  boolean_T eml_exitg;
  real_T eml_eta[6];
  real_T eml_a_1[6];
  int32_T uIdx;
  int32_T k;
  int32_T uIdx_0;
  int32_T k_0;
  int32_T j;
  real_T eml_d_y_0[3];
  real_T eml_e_y_0[3];
  real_T eml_f_y_0[3];
  real_T eml_iik_jac_0[18];
  real_T eml_iik_jac_1[18];
  real_T eml_q1_mu_0[3];
  real_T tmp[3];
  real_T eml_a_2[3];
  real_T tmp_0[3];
  real_T eml_y_0[3];
  real_T tmp_1[3];
  real_T tmp_2[3];
  real_T tmp_3[3];
  real_T tmp_4[3];
  real_T tmp_5[3];
  real_T tmp_6[3];
  real_T tmp_7[3];
  real_T tmp_8[3];
  real_T tmp_9[3];
  real_T tmp_a[3];
  real_T eml_r_cur_0[9];
  real_T eml_n1hat_0[9];
  static real_T tmp_b[3] = { 0.0, 0.0, 1.0 };

  static real_T tmp_c[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E+010, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0E+010, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E+010 };

  static int8_T tmp_d[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    /* set solver stop time */
    if (!(twa_parallel_rtM->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&twa_parallel_rtM->solverInfo,
                            ((twa_parallel_rtM->Timing.clockTickH0 + 1) *
        twa_parallel_rtM->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&twa_parallel_rtM->solverInfo,
                            ((twa_parallel_rtM->Timing.clockTick0 + 1) *
        twa_parallel_rtM->Timing.stepSize0 +
        twa_parallel_rtM->Timing.clockTickH0 *
        twa_parallel_rtM->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(twa_parallel_rtM)) {
    twa_parallel_rtM->Timing.t[0] = rtsiGetT(&twa_parallel_rtM->solverInfo);
  }

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
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
  }

  /* S-Function (dastgmodel2): '<Root>/Analog Output' */
  {
    /* S-Function Block: <Root>/Analog Output (dastgmodel2)*/
    {
      short i;

      {
        if ((twa_parallel_B.Switch_i[0] <= 10.) && (twa_parallel_B.Switch_i[0] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_i[0] * 409.6 + .5);
          RawDAC(0, i);
        } else {
          if (twa_parallel_B.Switch_i[0] > 10.)
            RawDAC(0, 4096.5);
          else
            RawDAC(0, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_i[1] <= 10.) && (twa_parallel_B.Switch_i[1] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_i[1] * 409.6 + .5);
          RawDAC(1, i);
        } else {
          if (twa_parallel_B.Switch_i[1] > 10.)
            RawDAC(1, 4096.5);
          else
            RawDAC(1, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_i[2] <= 10.) && (twa_parallel_B.Switch_i[2] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_i[2] * 409.6 + .5);
          RawDAC(2, i);
        } else {
          if (twa_parallel_B.Switch_i[2] > 10.)
            RawDAC(2, 4096.5);
          else
            RawDAC(2, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_i[3] <= 10.) && (twa_parallel_B.Switch_i[3] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_i[3] * 409.6 + .5);
          RawDAC(3, i);
        } else {
          if (twa_parallel_B.Switch_i[3] > 10.)
            RawDAC(3, 4096.5);
          else
            RawDAC(3, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_i[4] <= 10.) && (twa_parallel_B.Switch_i[4] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_i[4] * 409.6 + .5);
          RawDAC(4, i);
        } else {
          if (twa_parallel_B.Switch_i[4] > 10.)
            RawDAC(4, 4096.5);
          else
            RawDAC(4, -4096.0 + .5);
        }
      }

      {
        if ((twa_parallel_B.Switch_i[5] <= 10.) && (twa_parallel_B.Switch_i[5] >=
             -10.)) {
          i = (short)(twa_parallel_B.Switch_i[5] * 409.6 + .5);
          RawDAC(5, i);
        } else {
          if (twa_parallel_B.Switch_i[5] > 10.)
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
        if (twa_parallel_P.enc_reset1_Value==1) {
          SetEncoderCounts(0, 0);
          twa_parallel_B.EncoderInput_o1 = 0;
        } else
          twa_parallel_B.EncoderInput_o1 = (double) enc[0].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset2_Value==1) {
          SetEncoderCounts(1, 0);
          twa_parallel_B.EncoderInput_o2 = 0;
        } else
          twa_parallel_B.EncoderInput_o2 = (double) enc[1].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset3_Value==1) {
          SetEncoderCounts(2, 0);
          twa_parallel_B.EncoderInput_o3 = 0;
        } else
          twa_parallel_B.EncoderInput_o3 = (double) enc[2].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset4_Value==1) {
          SetEncoderCounts(3, 0);
          twa_parallel_B.EncoderInput_o4 = 0;
        } else
          twa_parallel_B.EncoderInput_o4 = (double) enc[3].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset5_Value==1) {
          SetEncoderCounts(4, 0);
          twa_parallel_B.EncoderInput_o5 = 0;
        } else
          twa_parallel_B.EncoderInput_o5 = (double) enc[4].Long/1;
      }

      {
        if (twa_parallel_P.enc_reset6_Value==1) {
          SetEncoderCounts(5, 0);
          twa_parallel_B.EncoderInput_o6 = 0;
        } else
          twa_parallel_B.EncoderInput_o6 = (double) enc[5].Long/1;
      }
    }
  }

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    /* Gain: '<S6>/enc_res' */
    twa_parallel_B.enc_res = twa_parallel_P.enc_res_Gain *
      twa_parallel_B.EncoderInput_o1;

    /* Gain: '<S6>/gear_ratio' */
    twa_parallel_B.gear_ratio = twa_parallel_P.gear_ratio_Gain *
      twa_parallel_B.enc_res;

    /* Gain: '<S6>/velmex_pitch' */
    twa_parallel_B.velmex_pitch = twa_parallel_P.velmex_pitch_Gain *
      twa_parallel_B.gear_ratio;

    /* Gain: '<S7>/enc_res' */
    twa_parallel_B.enc_res_f = twa_parallel_P.enc_res_Gain_j *
      twa_parallel_B.EncoderInput_o2;

    /* Gain: '<S7>/gear_ratio' */
    twa_parallel_B.gear_ratio_c = twa_parallel_P.gear_ratio_Gain_d *
      twa_parallel_B.enc_res_f;

    /* Gain: '<S7>/velmex_pitch' */
    twa_parallel_B.velmex_pitch_e = twa_parallel_P.velmex_pitch_Gain_j *
      twa_parallel_B.gear_ratio_c;

    /* Gain: '<S8>/enc_res' */
    twa_parallel_B.enc_res_c = twa_parallel_P.enc_res_Gain_i *
      twa_parallel_B.EncoderInput_o3;

    /* Gain: '<S8>/gear_ratio' */
    twa_parallel_B.gear_ratio_l = twa_parallel_P.gear_ratio_Gain_a *
      twa_parallel_B.enc_res_c;

    /* Gain: '<S8>/velmex_pitch' */
    twa_parallel_B.velmex_pitch_k = twa_parallel_P.velmex_pitch_Gain_je *
      twa_parallel_B.gear_ratio_l;

    /* Gain: '<S9>/enc_res' */
    twa_parallel_B.enc_res_fa = twa_parallel_P.enc_res_Gain_g *
      twa_parallel_B.EncoderInput_o4;

    /* Gain: '<S9>/gear_ratio' */
    twa_parallel_B.gear_ratio_j = twa_parallel_P.gear_ratio_Gain_o *
      twa_parallel_B.enc_res_fa;

    /* Gain: '<S10>/enc_res' */
    twa_parallel_B.enc_res_b = twa_parallel_P.enc_res_Gain_ij *
      twa_parallel_B.EncoderInput_o5;

    /* Gain: '<S10>/gear_ratio' */
    twa_parallel_B.gear_ratio_n = twa_parallel_P.gear_ratio_Gain_da *
      twa_parallel_B.enc_res_b;

    /* Gain: '<S11>/enc_res' */
    twa_parallel_B.enc_res_e = twa_parallel_P.enc_res_Gain_m *
      twa_parallel_B.EncoderInput_o6;

    /* Gain: '<S11>/gear_ratio' */
    twa_parallel_B.gear_ratio_f = twa_parallel_P.gear_ratio_Gain_c *
      twa_parallel_B.enc_res_e;

    /* SignalConversion: '<S14>/TmpSignal ConversionAtDiscrete FIR FilterInport1' */
    twa_parallel_B.TmpSignalConversionAtDiscreteFI[0] =
      twa_parallel_B.velmex_pitch;
    twa_parallel_B.TmpSignalConversionAtDiscreteFI[1] =
      twa_parallel_B.velmex_pitch_e;
    twa_parallel_B.TmpSignalConversionAtDiscreteFI[2] =
      twa_parallel_B.velmex_pitch_k;
    twa_parallel_B.TmpSignalConversionAtDiscreteFI[3] =
      twa_parallel_B.gear_ratio_j;
    twa_parallel_B.TmpSignalConversionAtDiscreteFI[4] =
      twa_parallel_B.gear_ratio_n;
    twa_parallel_B.TmpSignalConversionAtDiscreteFI[5] =
      twa_parallel_B.gear_ratio_f;

    /* DiscreteFir: '<S14>/Discrete FIR Filter' incorporates:
     *  Constant: '<S14>/vel_filter_coeffs'
     */
    uIdx = 0;
    for (k = 0; k < 6; k++) {
      uIdx_0 = twa_parallel_DWork.DiscreteFIRFilter_circBuf;
      eml_y = twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx] *
        twa_parallel_P.vel_filter_coeffs_Value[0];
      uIdx++;
      k_0 = 1;
      for (j = uIdx_0; j < 1; j++) {
        eml_rtemp = k + j;
        eml_y += twa_parallel_DWork.DiscreteFIRFilter_states[eml_rtemp] *
          twa_parallel_P.vel_filter_coeffs_Value[k_0];
        k_0++;
      }

      for (j = 0; j < uIdx_0; j++) {
        eml_rtemp = k + j;
        eml_y += twa_parallel_DWork.DiscreteFIRFilter_states[eml_rtemp] *
          twa_parallel_P.vel_filter_coeffs_Value[k_0];
        k_0++;
      }

      twa_parallel_B.DiscreteFIRFilter[k] = eml_y;
    }

    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* Gain: '<S14>/Gain' */
      twa_parallel_B.Gain[uIdx] = twa_parallel_P.Gain_Gain *
        twa_parallel_B.DiscreteFIRFilter[uIdx];

      /* SampleTimeMath: '<S13>/TSamp'
       *
       * About '<S13>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      twa_parallel_B.TSamp[uIdx] = twa_parallel_B.Gain[uIdx] *
        twa_parallel_P.TSamp_WtEt;

      /* UnitDelay: '<S13>/UD' */
      twa_parallel_B.Uk1[uIdx] = twa_parallel_DWork.UD_DSTATE[uIdx];

      /* Sum: '<S13>/Diff' */
      twa_parallel_B.Diff[uIdx] = twa_parallel_B.TSamp[uIdx] -
        twa_parallel_B.Uk1[uIdx];
    }

    /* ok to acquire for <S20>/S-Function */
    twa_parallel_DWork.SFunction_IWORK.AcquireOK = 1;

    /* DiscreteFir: '<S18>/Discrete FIR Filter' incorporates:
     *  Constant: '<S18>/vel_filter_coeffs'
     */
    uIdx_0 = 0;
    for (k_0 = 0; k_0 < 6; k_0++) {
      uIdx = twa_parallel_DWork.DiscreteFIRFilter_circBuf_l;
      eml_y = twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx_0] *
        twa_parallel_P.vel_filter_coeffs_Value_m[0];
      uIdx_0++;
      k = 1;
      for (j = uIdx; j < 1; j++) {
        eml_rtemp = k_0 + j;
        eml_y += twa_parallel_DWork.DiscreteFIRFilter_states_m[eml_rtemp] *
          twa_parallel_P.vel_filter_coeffs_Value_m[k];
        k++;
      }

      for (j = 0; j < uIdx; j++) {
        eml_rtemp = k_0 + j;
        eml_y += twa_parallel_DWork.DiscreteFIRFilter_states_m[eml_rtemp] *
          twa_parallel_P.vel_filter_coeffs_Value_m[k];
        k++;
      }

      twa_parallel_B.DiscreteFIRFilter_h[k_0] = eml_y;
    }

    /* Gain: '<S18>/Gain' */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      twa_parallel_B.Gain_n[uIdx] = twa_parallel_P.Gain_Gain_d *
        twa_parallel_B.DiscreteFIRFilter_h[uIdx];
    }

    /* ok to acquire for <S19>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_j.AcquireOK = 1;

    /* ok to acquire for <S21>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_i.AcquireOK = 1;

    /* ok to acquire for <S22>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_ih.AcquireOK = 1;

    /* ok to acquire for <S23>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_m.AcquireOK = 1;
    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* UnitDelay: '<S26>/Delay Input1' */
      twa_parallel_B.Uk1_j[uIdx] = twa_parallel_DWork.DelayInput1_DSTATE[uIdx];

      /* RelationalOperator: '<S26>/FixPt Relational Operator' incorporates:
       *  Constant: '<S5>/q_des_usr'
       */
      twa_parallel_B.FixPtRelationalOperator[uIdx] =
        (twa_parallel_P.q_des_usr_Value[uIdx] != twa_parallel_B.Uk1_j[uIdx]);

      /* UnitDelay: '<S5>/Unit Delay1' */
      twa_parallel_B.UnitDelay1[uIdx] =
        twa_parallel_DWork.UnitDelay1_DSTATE[uIdx];

      /* Switch: '<S24>/Switch' incorporates:
       *  Constant: '<S5>/q_des_usr'
       */
      if (twa_parallel_B.FixPtRelationalOperator[uIdx] != 0) {
        twa_parallel_B.Switch[uIdx] = twa_parallel_P.q_des_usr_Value[uIdx];
      } else {
        twa_parallel_B.Switch[uIdx] = twa_parallel_B.UnitDelay1[uIdx];
      }
    }

    /* UnitDelay: '<S25>/Unit Delay3' */
    twa_parallel_B.UnitDelay3 = twa_parallel_DWork.UnitDelay3_DSTATE;

    /* Embedded MATLAB: '<S25>/get_jacobian' incorporates:
     *  Constant: '<S25>/b_in_w'
     *  Constant: '<S25>/f_in_w'
     *  Constant: '<S25>/m_in_w'
     *  Constant: '<S25>/p_in_m'
     */
    /* Embedded MATLAB Function 'control_mode/task_space/get_jacobian': '<S28>:1' */
    /* '<S28>:1:3' */

    /* UnitDelay: '<S25>/Unit Delay6' */
    twa_parallel_B.UnitDelay6[0] = twa_parallel_DWork.UnitDelay6_DSTATE[0];
    twa_parallel_B.xcur[0] = twa_parallel_B.UnitDelay6[0];

    /* UnitDelay: '<S25>/Unit Delay6' */
    twa_parallel_B.UnitDelay6[1] = twa_parallel_DWork.UnitDelay6_DSTATE[1];
    twa_parallel_B.xcur[1] = twa_parallel_B.UnitDelay6[1];

    /* UnitDelay: '<S25>/Unit Delay6' */
    twa_parallel_B.UnitDelay6[2] = twa_parallel_DWork.UnitDelay6_DSTATE[2];
    twa_parallel_B.xcur[2] = twa_parallel_B.UnitDelay6[2];

    /* '<S28>:1:4' */
    twa_parallel_B.eerotcur = twa_parallel_B.UnitDelay3;

    /*  axis for jacobian definitions */
    /*  rotation matrix */
    /* '<S28>:1:10' */
    eml_r_cur[0] = cos(twa_parallel_B.UnitDelay3);
    eml_r_cur[3] = -sin(twa_parallel_B.UnitDelay3);
    eml_r_cur[6] = 0.0;
    eml_r_cur[1] = sin(twa_parallel_B.UnitDelay3);
    eml_r_cur[4] = cos(twa_parallel_B.UnitDelay3);
    eml_r_cur[7] = 0.0;
    eml_r_cur[2] = 0.0;
    eml_r_cur[5] = 0.0;
    eml_r_cur[8] = 1.0;

    /*  moving platform vertex locations */
    /* '<S28>:1:13' */
    for (uIdx = 0; uIdx < 3; uIdx++) {
      eml_n1hat_0[uIdx] = 0.0;
      eml_n1hat_0[uIdx] += twa_parallel_B.UnitDelay6[uIdx];
      eml_n1hat_0[uIdx + 3] = 0.0;
      eml_n1hat_0[uIdx + 3] += twa_parallel_B.UnitDelay6[uIdx];
      eml_n1hat_0[uIdx + 6] = 0.0;
      eml_n1hat_0[uIdx + 6] += twa_parallel_B.UnitDelay6[uIdx];
    }

    for (uIdx = 0; uIdx < 3; uIdx++) {
      for (k = 0; k < 3; k++) {
        eml_r_cur_0[uIdx + 3 * k] = 0.0;
        eml_r_cur_0[uIdx + 3 * k] = eml_r_cur_0[3 * k + uIdx] +
          twa_parallel_P.p_in_m_Value[3 * k] * eml_r_cur[uIdx];
        eml_r_cur_0[uIdx + 3 * k] = twa_parallel_P.p_in_m_Value[3 * k + 1] *
          eml_r_cur[uIdx + 3] + eml_r_cur_0[3 * k + uIdx];
        eml_r_cur_0[uIdx + 3 * k] = twa_parallel_P.p_in_m_Value[3 * k + 2] *
          eml_r_cur[uIdx + 6] + eml_r_cur_0[3 * k + uIdx];
      }
    }

    for (uIdx = 0; uIdx < 3; uIdx++) {
      eml_p_in_w[3 * uIdx] = eml_n1hat_0[3 * uIdx] + eml_r_cur_0[3 * uIdx];
      eml_p_in_w[1 + 3 * uIdx] = eml_n1hat_0[3 * uIdx + 1] + eml_r_cur_0[3 *
        uIdx + 1];
      eml_p_in_w[2 + 3 * uIdx] = eml_n1hat_0[3 * uIdx + 2] + eml_r_cur_0[3 *
        uIdx + 2];
    }

    /* % instantaneous direct kinematics jacobian */
    /*  vector from base vertex to moving platform vertex */
    /* '<S28>:1:17' */
    eml_q1_mu_0[0] = twa_parallel_P.b_in_w_Value[0] - eml_p_in_w[0];
    eml_q1_mu_0[1] = twa_parallel_P.b_in_w_Value[1] - eml_p_in_w[1];
    eml_q1_mu_0[2] = twa_parallel_P.b_in_w_Value[2] - eml_p_in_w[2];
    eml_y = twa_parallel_norm(eml_q1_mu_0);

    /* '<S28>:1:18' */
    eml_n1hat[0] = (eml_p_in_w[0] - twa_parallel_P.b_in_w_Value[0]) / eml_y;
    eml_a_2[0] = twa_parallel_P.b_in_w_Value[3] - eml_p_in_w[3];
    eml_n1hat[1] = (eml_p_in_w[1] - twa_parallel_P.b_in_w_Value[1]) / eml_y;
    eml_a_2[1] = twa_parallel_P.b_in_w_Value[4] - eml_p_in_w[4];
    eml_n1hat[2] = (eml_p_in_w[2] - twa_parallel_P.b_in_w_Value[2]) / eml_y;
    eml_a_2[2] = twa_parallel_P.b_in_w_Value[5] - eml_p_in_w[5];
    eml_y = twa_parallel_norm(eml_a_2);

    /* '<S28>:1:19' */
    eml_n2hat[0] = (eml_p_in_w[3] - twa_parallel_P.b_in_w_Value[3]) / eml_y;
    eml_y_0[0] = twa_parallel_P.b_in_w_Value[6] - eml_p_in_w[6];
    eml_n2hat[1] = (eml_p_in_w[4] - twa_parallel_P.b_in_w_Value[4]) / eml_y;
    eml_y_0[1] = twa_parallel_P.b_in_w_Value[7] - eml_p_in_w[7];
    eml_n2hat[2] = (eml_p_in_w[5] - twa_parallel_P.b_in_w_Value[5]) / eml_y;
    eml_y_0[2] = twa_parallel_P.b_in_w_Value[8] - eml_p_in_w[8];
    eml_y = twa_parallel_norm(eml_y_0);

    /* '<S28>:1:21' */
    /* '<S28>:1:22' */
    /* '<S28>:1:23' */
    /* '<S28>:1:25' */
    /* % instantaneous inverse kinematics jacobian */
    /*  micro actuator (TWA) lengths */
    /* '<S28>:1:31' */
    for (uIdx = 0; uIdx < 3; uIdx++) {
      eml_n3hat[uIdx] = (eml_p_in_w[6 + uIdx] - twa_parallel_P.b_in_w_Value[6 +
                         uIdx]) / eml_y;
      eml_q2_mu = eml_r_cur[uIdx] * twa_parallel_P.p_in_m_Value[0];
      eml_q2_mu += eml_r_cur[uIdx + 3] * twa_parallel_P.p_in_m_Value[1];
      eml_q2_mu += eml_r_cur[uIdx + 6] * twa_parallel_P.p_in_m_Value[2];
      eml_a_0 = eml_r_cur[uIdx] * twa_parallel_P.p_in_m_Value[3];
      eml_a_0 += eml_r_cur[uIdx + 3] * twa_parallel_P.p_in_m_Value[4];
      eml_a_0 += eml_r_cur[uIdx + 6] * twa_parallel_P.p_in_m_Value[5];
      eml_c_0 = eml_r_cur[uIdx] * twa_parallel_P.p_in_m_Value[6];
      eml_c_0 += eml_r_cur[uIdx + 3] * twa_parallel_P.p_in_m_Value[7];
      eml_c_0 += eml_r_cur[uIdx + 6] * twa_parallel_P.p_in_m_Value[8];
      eml_q1_mu_0[uIdx] = twa_parallel_P.b_in_w_Value[uIdx] -
        twa_parallel_P.m_in_w_Value[uIdx];
      eml_a_2[uIdx] = twa_parallel_P.b_in_w_Value[3 + uIdx] -
        twa_parallel_P.m_in_w_Value[3 + uIdx];
      eml_y_0[uIdx] = twa_parallel_P.b_in_w_Value[6 + uIdx] -
        twa_parallel_P.m_in_w_Value[6 + uIdx];
      tmp_a[uIdx] = twa_parallel_P.m_in_w_Value[uIdx] -
        twa_parallel_P.b_in_w_Value[uIdx];
      eml_f_y[uIdx] = eml_c_0;
      eml_e_y[uIdx] = eml_a_0;
      eml_d_y[uIdx] = eml_q2_mu;
    }

    eml_q1_mu = twa_parallel_norm(eml_q1_mu_0);

    /* '<S28>:1:32' */
    eml_q2_mu = twa_parallel_norm(eml_a_2);

    /* '<S28>:1:33' */
    eml_q3_mu = twa_parallel_norm(eml_y_0);

    /*  vector from base vertex to twa motor attachment point */
    /* '<S28>:1:36' */
    eml_y = twa_parallel_norm(tmp_a);

    /* '<S28>:1:37' */
    eml_l1_hat[0] = (twa_parallel_P.m_in_w_Value[0] -
                     twa_parallel_P.b_in_w_Value[0]) / eml_y;
    tmp_9[0] = twa_parallel_P.m_in_w_Value[3] - twa_parallel_P.b_in_w_Value[3];
    eml_l1_hat[1] = (twa_parallel_P.m_in_w_Value[1] -
                     twa_parallel_P.b_in_w_Value[1]) / eml_y;
    tmp_9[1] = twa_parallel_P.m_in_w_Value[4] - twa_parallel_P.b_in_w_Value[4];
    eml_l1_hat[2] = (twa_parallel_P.m_in_w_Value[2] -
                     twa_parallel_P.b_in_w_Value[2]) / eml_y;
    tmp_9[2] = twa_parallel_P.m_in_w_Value[5] - twa_parallel_P.b_in_w_Value[5];
    eml_y = twa_parallel_norm(tmp_9);

    /* '<S28>:1:38' */
    eml_l2_hat[0] = (twa_parallel_P.m_in_w_Value[3] -
                     twa_parallel_P.b_in_w_Value[3]) / eml_y;
    tmp_8[0] = twa_parallel_P.m_in_w_Value[6] - twa_parallel_P.b_in_w_Value[6];
    eml_l2_hat[1] = (twa_parallel_P.m_in_w_Value[4] -
                     twa_parallel_P.b_in_w_Value[4]) / eml_y;
    tmp_8[1] = twa_parallel_P.m_in_w_Value[7] - twa_parallel_P.b_in_w_Value[7];
    eml_l2_hat[2] = (twa_parallel_P.m_in_w_Value[5] -
                     twa_parallel_P.b_in_w_Value[5]) / eml_y;
    tmp_8[2] = twa_parallel_P.m_in_w_Value[8] - twa_parallel_P.b_in_w_Value[8];
    eml_y = twa_parallel_norm(tmp_8);

    /*  distance from micro actuator attachmnet point (m_i) to flexure rotation */
    /* center (f_i) */
    /* '<S28>:1:42' */
    eml_l3_hat[0] = (twa_parallel_P.m_in_w_Value[6] -
                     twa_parallel_P.b_in_w_Value[6]) / eml_y;
    tmp_7[0] = twa_parallel_P.m_in_w_Value[0] - twa_parallel_P.f_in_w_Value[0];
    tmp_6[0] = twa_parallel_P.m_in_w_Value[3] - twa_parallel_P.f_in_w_Value[3];
    tmp_5[0] = twa_parallel_P.m_in_w_Value[6] - twa_parallel_P.f_in_w_Value[6];
    tmp_4[0] = twa_parallel_P.b_in_w_Value[0] - twa_parallel_P.f_in_w_Value[0];
    tmp_3[0] = twa_parallel_P.b_in_w_Value[3] - twa_parallel_P.f_in_w_Value[3];
    tmp_2[0] = twa_parallel_P.b_in_w_Value[6] - twa_parallel_P.f_in_w_Value[6];
    eml_l3_hat[1] = (twa_parallel_P.m_in_w_Value[7] -
                     twa_parallel_P.b_in_w_Value[7]) / eml_y;
    tmp_7[1] = twa_parallel_P.m_in_w_Value[1] - twa_parallel_P.f_in_w_Value[1];
    tmp_6[1] = twa_parallel_P.m_in_w_Value[4] - twa_parallel_P.f_in_w_Value[4];
    tmp_5[1] = twa_parallel_P.m_in_w_Value[7] - twa_parallel_P.f_in_w_Value[7];
    tmp_4[1] = twa_parallel_P.b_in_w_Value[1] - twa_parallel_P.f_in_w_Value[1];
    tmp_3[1] = twa_parallel_P.b_in_w_Value[4] - twa_parallel_P.f_in_w_Value[4];
    tmp_2[1] = twa_parallel_P.b_in_w_Value[7] - twa_parallel_P.f_in_w_Value[7];
    eml_l3_hat[2] = (twa_parallel_P.m_in_w_Value[8] -
                     twa_parallel_P.b_in_w_Value[8]) / eml_y;
    tmp_7[2] = twa_parallel_P.m_in_w_Value[2] - twa_parallel_P.f_in_w_Value[2];
    tmp_6[2] = twa_parallel_P.m_in_w_Value[5] - twa_parallel_P.f_in_w_Value[5];
    tmp_5[2] = twa_parallel_P.m_in_w_Value[8] - twa_parallel_P.f_in_w_Value[8];
    tmp_4[2] = twa_parallel_P.b_in_w_Value[2] - twa_parallel_P.f_in_w_Value[2];
    tmp_3[2] = twa_parallel_P.b_in_w_Value[5] - twa_parallel_P.f_in_w_Value[5];
    tmp_2[2] = twa_parallel_P.b_in_w_Value[8] - twa_parallel_P.f_in_w_Value[8];
    eml_y = twa_parallel_norm(tmp_7);

    /* '<S28>:1:43' */
    eml_a = twa_parallel_norm(tmp_6);

    /* '<S28>:1:44' */
    eml_a_0 = twa_parallel_norm(tmp_5);

    /*  distance from flexure rotation center (f_i) to base vertex */
    /* '<S28>:1:47' */
    eml_c = twa_parallel_norm(tmp_4);

    /* '<S28>:1:48' */
    eml_c_0 = twa_parallel_norm(tmp_3);

    /* '<S28>:1:49' */
    eml_c_1 = twa_parallel_norm(tmp_2);

    /*  term to paramterize angle between a_i and qimu, delta */
    /* '<S28>:1:52' */
    /* '<S28>:1:53' */
    /* '<S28>:1:54' */
    /*  time derivatives */
    /* '<S28>:1:57' */
    /* '<S28>:1:58' */
    /* '<S28>:1:59' */
    /* '<S28>:1:61' */
    eml_q1_mu = (((rt_pow_snf(eml_c, 2.0) - rt_pow_snf(eml_y, 2.0)) - rt_pow_snf
                  (eml_q1_mu, 2.0)) * 2.0 * eml_y + 4.0 * eml_y * rt_pow_snf
                 (eml_q1_mu, 2.0)) / (4.0 * rt_pow_snf(eml_y, 2.0) * rt_pow_snf
      (eml_q1_mu, 2.0)) * eml_q1_mu / sqrt(1.0 - rt_pow_snf(((rt_pow_snf(eml_c,
      2.0) - rt_pow_snf(eml_y, 2.0)) - rt_pow_snf(eml_q1_mu, 2.0)) / (-2.0 *
      eml_y * eml_q1_mu), 2.0));

    /* '<S28>:1:62' */
    eml_a = (((rt_pow_snf(eml_c_0, 2.0) - rt_pow_snf(eml_a, 2.0)) - rt_pow_snf
              (eml_q2_mu, 2.0)) * 2.0 * eml_a + 4.0 * eml_a * rt_pow_snf
             (eml_q2_mu, 2.0)) / (4.0 * rt_pow_snf(eml_a, 2.0) * rt_pow_snf
      (eml_q2_mu, 2.0)) * eml_q2_mu / sqrt(1.0 - rt_pow_snf(((rt_pow_snf(eml_c_0,
      2.0) - rt_pow_snf(eml_a, 2.0)) - rt_pow_snf(eml_q2_mu, 2.0)) / (-2.0 *
      eml_a * eml_q2_mu), 2.0));

    /* '<S28>:1:63' */
    eml_y = (((rt_pow_snf(eml_c_1, 2.0) - rt_pow_snf(eml_a_0, 2.0)) - rt_pow_snf
              (eml_q3_mu, 2.0)) * 2.0 * eml_a_0 + 4.0 * eml_a_0 * rt_pow_snf
             (eml_q3_mu, 2.0)) / (4.0 * rt_pow_snf(eml_a_0, 2.0) * rt_pow_snf
      (eml_q3_mu, 2.0)) * eml_q3_mu / sqrt(1.0 - rt_pow_snf(((rt_pow_snf(eml_c_1,
      2.0) - rt_pow_snf(eml_a_0, 2.0)) - rt_pow_snf(eml_q3_mu, 2.0)) / (-2.0 *
      eml_a_0 * eml_q3_mu), 2.0));

    /*  micro motion instantaneous inverse kinematics jacobian */
    /* '<S28>:1:66' */
    /*  macro motion instantaneous inverse kinematics jacobian */
    /* '<S28>:1:71' */
    /*  combined macro-micro motion IIK jacobian */
    /* '<S28>:1:74' */
    tmp[0] = 0.0 * eml_l1_hat[2] - eml_l1_hat[1];
    tmp[1] = eml_l1_hat[0] - 0.0 * eml_l1_hat[2];
    tmp[2] = 0.0 * eml_l1_hat[1] - 0.0 * eml_l1_hat[0];
    tmp_0[0] = 0.0 * eml_l2_hat[2] - eml_l2_hat[1];
    tmp_0[1] = eml_l2_hat[0] - 0.0 * eml_l2_hat[2];
    tmp_0[2] = 0.0 * eml_l2_hat[1] - 0.0 * eml_l2_hat[0];
    eml_q1_mu_0[0] = eml_q1_mu * eml_n1hat[0];
    eml_a_2[0] = eml_a * eml_n2hat[0];
    eml_y_0[0] = eml_y * eml_n3hat[0];
    eml_q1_mu_0[1] = eml_q1_mu * eml_n1hat[1];
    eml_a_2[1] = eml_a * eml_n2hat[1];
    eml_y_0[1] = eml_y * eml_n3hat[1];
    eml_q1_mu_0[2] = eml_q1_mu * eml_n1hat[2];
    eml_a_2[2] = eml_a * eml_n2hat[2];
    eml_y_0[2] = eml_y * eml_n3hat[2];
    tmp_1[0] = 0.0 * eml_l3_hat[2] - eml_l3_hat[1];
    tmp_1[1] = eml_l3_hat[0] - 0.0 * eml_l3_hat[2];
    tmp_1[2] = 0.0 * eml_l3_hat[1] - 0.0 * eml_l3_hat[0];
    eml_q2_mu = twa_parallel_eml_xdotu(eml_n1hat, eml_l1_hat) +
      twa_parallel_eml_xdotu(eml_q1_mu_0, tmp);
    eml_a_0 = twa_parallel_eml_xdotu(eml_n2hat, eml_l2_hat) +
      twa_parallel_eml_xdotu(eml_a_2, tmp_0);
    eml_c_0 = twa_parallel_eml_xdotu(eml_n3hat, eml_l3_hat) +
      twa_parallel_eml_xdotu(eml_y_0, tmp_1);
    for (uIdx = 0; uIdx < 3; uIdx++) {
      eml_iik_jac[3 * uIdx] = (real_T)tmp_d[3 * uIdx];
      eml_iik_jac[1 + 3 * uIdx] = (real_T)tmp_d[3 * uIdx + 1];
      eml_iik_jac[2 + 3 * uIdx] = (real_T)tmp_d[3 * uIdx + 2];
    }

    eml_iik_jac[9] = eml_q2_mu;
    eml_iik_jac[12] = 0.0;
    eml_iik_jac[15] = 0.0;
    eml_iik_jac[10] = 0.0;
    eml_iik_jac[13] = eml_a_0;
    eml_iik_jac[16] = 0.0;
    eml_iik_jac[11] = 0.0;
    eml_iik_jac[14] = 0.0;
    eml_iik_jac[17] = eml_c_0;

    /*  the full manipulator jacobian with redundancy resolution weighting */
    /* '<S28>:1:78' */
    for (uIdx = 0; uIdx < 3; uIdx++) {
      for (k = 0; k < 6; k++) {
        eml_iik_jac_1[k + 6 * uIdx] = eml_iik_jac[3 * k + uIdx];
      }
    }

    twa_parallel_mldivide(tmp_c, eml_iik_jac_1, eml_Y);
    for (uIdx = 0; uIdx < 3; uIdx++) {
      for (k = 0; k < 3; k++) {
        eml_r_cur[uIdx + 3 * k] = 0.0;
        for (uIdx_0 = 0; uIdx_0 < 6; uIdx_0++) {
          eml_r_cur[uIdx + 3 * k] = eml_Y[6 * k + uIdx_0] * eml_iik_jac[3 *
            uIdx_0 + uIdx] + eml_r_cur[3 * k + uIdx];
        }
      }
    }

    for (uIdx = 0; uIdx < 3; uIdx++) {
      for (k = 0; k < 6; k++) {
        eml_iik_jac_0[k + 6 * uIdx] = eml_iik_jac[3 * k + uIdx];
      }
    }

    twa_parallel_mldivide(tmp_c, eml_iik_jac_0, eml_Y);
    for (uIdx = 0; uIdx < 6; uIdx++) {
      eml_iik_jac[3 * uIdx] = eml_Y[uIdx];
      eml_iik_jac[1 + 3 * uIdx] = eml_Y[uIdx + 6];
      eml_iik_jac[2 + 3 * uIdx] = eml_Y[uIdx + 12];
    }

    k = 1;
    uIdx_0 = 2;
    k_0 = 3;
    eml_y = eml_r_cur[0];
    eml_a = fabs(eml_y);
    eml_y = eml_r_cur[1];
    eml_y = fabs(eml_y);
    if (eml_y > eml_a) {
      eml_a = eml_y;
      k = 2;
      uIdx_0 = 1;
    }

    eml_y = eml_r_cur[2];
    if (fabs(eml_y) > eml_a) {
      k = 3;
      uIdx_0 = 2;
      k_0 = 1;
    }

    eml_r_cur[uIdx_0 - 1] /= eml_r_cur[k - 1];
    eml_r_cur[k_0 - 1] /= eml_r_cur[k - 1];
    eml_r_cur[uIdx_0 + 2] -= eml_r_cur[uIdx_0 - 1] * eml_r_cur[k + 2];
    eml_r_cur[k_0 + 2] -= eml_r_cur[k_0 - 1] * eml_r_cur[k + 2];
    eml_r_cur[uIdx_0 + 5] -= eml_r_cur[uIdx_0 - 1] * eml_r_cur[k + 5];
    eml_r_cur[k_0 + 5] -= eml_r_cur[k_0 - 1] * eml_r_cur[k + 5];
    eml_y = eml_r_cur[k_0 + 2];
    eml_a = eml_r_cur[uIdx_0 + 2];
    if (fabs(eml_y) > fabs(eml_a)) {
      eml_rtemp = uIdx_0;
      uIdx_0 = k_0;
      k_0 = eml_rtemp;
    }

    eml_r_cur[k_0 + 2] /= eml_r_cur[uIdx_0 + 2];
    eml_r_cur[k_0 + 5] -= eml_r_cur[k_0 + 2] * eml_r_cur[uIdx_0 + 5];
    for (uIdx = 0; uIdx < 6; uIdx++) {
      eml_Y[3 * uIdx] = eml_iik_jac[(k - 1) + 3 * uIdx];
      eml_Y[1 + 3 * uIdx] = eml_iik_jac[(uIdx_0 - 1) + 3 * uIdx] - eml_Y[3 *
        uIdx] * eml_r_cur[uIdx_0 - 1];
      eml_Y[2 + 3 * uIdx] = (eml_iik_jac[(k_0 - 1) + 3 * uIdx] - eml_Y[3 * uIdx]
        * eml_r_cur[k_0 - 1]) - eml_Y[3 * uIdx + 1] * eml_r_cur[k_0 + 2];
      eml_Y[2 + 3 * uIdx] = eml_Y[3 * uIdx + 2] / eml_r_cur[k_0 + 5];
      eml_Y[3 * uIdx] -= eml_Y[3 * uIdx + 2] * eml_r_cur[k + 5];
      eml_Y[1 + 3 * uIdx] = eml_Y[3 * uIdx + 1] - eml_Y[3 * uIdx + 2] *
        eml_r_cur[uIdx_0 + 5];
      eml_Y[1 + 3 * uIdx] = eml_Y[3 * uIdx + 1] / eml_r_cur[uIdx_0 + 2];
      eml_Y[3 * uIdx] -= eml_Y[3 * uIdx + 1] * eml_r_cur[k + 2];
      eml_Y[3 * uIdx] /= eml_r_cur[k - 1];
    }

    eml_d_y_0[0] = eml_d_y[1] * eml_n1hat[2] - eml_d_y[2] * eml_n1hat[1];
    eml_d_y_0[1] = eml_d_y[2] * eml_n1hat[0] - eml_d_y[0] * eml_n1hat[2];
    eml_d_y_0[2] = eml_d_y[0] * eml_n1hat[1] - eml_d_y[1] * eml_n1hat[0];
    eml_e_y_0[0] = eml_e_y[1] * eml_n2hat[2] - eml_e_y[2] * eml_n2hat[1];
    eml_e_y_0[1] = eml_e_y[2] * eml_n2hat[0] - eml_e_y[0] * eml_n2hat[2];
    eml_e_y_0[2] = eml_e_y[0] * eml_n2hat[1] - eml_e_y[1] * eml_n2hat[0];
    eml_f_y_0[0] = eml_f_y[1] * eml_n3hat[2] - eml_f_y[2] * eml_n3hat[1];
    eml_f_y_0[1] = eml_f_y[2] * eml_n3hat[0] - eml_f_y[0] * eml_n3hat[2];
    eml_f_y_0[2] = eml_f_y[0] * eml_n3hat[1] - eml_f_y[1] * eml_n3hat[0];
    eml_q2_mu = twa_parallel_eml_xdotu(tmp_b, eml_d_y_0);
    eml_a_0 = twa_parallel_eml_xdotu(tmp_b, eml_e_y_0);
    eml_c_0 = twa_parallel_eml_xdotu(tmp_b, eml_f_y_0);
    eml_n1hat_0[0] = eml_n1hat[0];
    eml_n1hat_0[3] = eml_n1hat[1];
    eml_n1hat_0[6] = eml_q2_mu;
    eml_n1hat_0[1] = eml_n2hat[0];
    eml_n1hat_0[4] = eml_n2hat[1];
    eml_n1hat_0[7] = eml_a_0;
    eml_n1hat_0[2] = eml_n3hat[0];
    eml_n1hat_0[5] = eml_n3hat[1];
    eml_n1hat_0[8] = eml_c_0;
    for (uIdx = 0; uIdx < 6; uIdx++) {
      for (k = 0; k < 3; k++) {
        twa_parallel_B.full_jac[uIdx + 6 * k] = 0.0;
        twa_parallel_B.full_jac[uIdx + 6 * k] = twa_parallel_B.full_jac[6 * k +
          uIdx] + eml_Y[3 * uIdx] * eml_n1hat_0[3 * k];
        twa_parallel_B.full_jac[uIdx + 6 * k] = eml_Y[3 * uIdx + 1] *
          eml_n1hat_0[3 * k + 1] + twa_parallel_B.full_jac[6 * k + uIdx];
        twa_parallel_B.full_jac[uIdx + 6 * k] = eml_Y[3 * uIdx + 2] *
          eml_n1hat_0[3 * k + 2] + twa_parallel_B.full_jac[6 * k + uIdx];
      }
    }

    /* SignalConversion: '<S27>/TmpSignal ConversionAt SFunction Inport2' */
    twa_parallel_B.TmpSignalConversionAtSFunctionI[0] =
      twa_parallel_B.velmex_pitch;
    twa_parallel_B.TmpSignalConversionAtSFunctionI[1] =
      twa_parallel_B.velmex_pitch_e;
    twa_parallel_B.TmpSignalConversionAtSFunctionI[2] =
      twa_parallel_B.velmex_pitch_k;
    twa_parallel_B.TmpSignalConversionAtSFunctionI[3] =
      twa_parallel_B.gear_ratio_j;
    twa_parallel_B.TmpSignalConversionAtSFunctionI[4] =
      twa_parallel_B.gear_ratio_n;
    twa_parallel_B.TmpSignalConversionAtSFunctionI[5] =
      twa_parallel_B.gear_ratio_f;

    /* Embedded MATLAB: '<S25>/ResolvedRates' incorporates:
     *  Constant: '<S25>/dt'
     *  Constant: '<S25>/ee_rot_des'
     *  Constant: '<S25>/res_rate_param'
     *  Constant: '<S25>/x_des'
     */
    /* Embedded MATLAB Function 'control_mode/task_space/ResolvedRates': '<S27>:1' */
    /* '<S27>:1:4' */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* UnitDelay: '<S25>/Unit Delay1' */
      twa_parallel_B.UnitDelay1_a[uIdx] =
        twa_parallel_DWork.UnitDelay1_DSTATE_b[uIdx];
      twa_parallel_B.qdes[uIdx] = twa_parallel_B.UnitDelay1[uIdx];
    }

    /* '<S27>:1:5' */
    /* '<S27>:1:6' */
    twa_parallel_B.eerot = twa_parallel_B.eerotcur;

    /*  axis for jacobian definitions */
    /* '<S27>:1:9' */
    /*  positional error */
    /* '<S27>:1:12' */
    twa_parallel_B.xcur_e[0] = twa_parallel_B.xcur[0];
    eml_n1hat[0] = twa_parallel_P.x_des_Value[0] - twa_parallel_B.xcur[0];
    twa_parallel_B.xcur_e[1] = twa_parallel_B.xcur[1];
    eml_n1hat[1] = twa_parallel_P.x_des_Value[1] - twa_parallel_B.xcur[1];
    twa_parallel_B.xcur_e[2] = twa_parallel_B.xcur[2];
    eml_n1hat[2] = twa_parallel_P.x_des_Value[2] - twa_parallel_B.xcur[2];
    eml_p_del = 0.0;
    eml_c = 0.0;
    eml_firstNonZero = TRUE;
    eml_y = eml_n1hat[0];
    if (eml_y != 0.0) {
      eml_y = fabs(eml_y);
      eml_c = eml_y;
      eml_p_del = 1.0;
      eml_firstNonZero = FALSE;
    }

    eml_y = eml_n1hat[1];
    if (eml_y != 0.0) {
      eml_y = fabs(eml_y);
      if (eml_firstNonZero) {
        eml_c = eml_y;
        eml_p_del = 1.0;
        eml_firstNonZero = FALSE;
      } else if (eml_c < eml_y) {
        eml_a = eml_c / eml_y;
        eml_p_del = eml_p_del * eml_a * eml_a + 1.0;
        eml_c = eml_y;
      } else {
        eml_a = eml_y / eml_c;
        eml_p_del += eml_a * eml_a;
      }
    }

    eml_y = eml_n1hat[2];
    if (eml_y != 0.0) {
      eml_y = fabs(eml_y);
      if (eml_firstNonZero) {
        eml_c = eml_y;
        eml_p_del = 1.0;
      } else if (eml_c < eml_y) {
        eml_a = eml_c / eml_y;
        eml_p_del = eml_p_del * eml_a * eml_a + 1.0;
        eml_c = eml_y;
      } else {
        eml_a = eml_y / eml_c;
        eml_p_del += eml_a * eml_a;
      }
    }

    eml_p_del = eml_c * sqrt(eml_p_del);

    /*  positional error direction vector */
    if (eml_p_del != 0.0) {
      /* '<S27>:1:15' */
      /* '<S27>:1:16' */
      eml_n1hat[0] = (twa_parallel_P.x_des_Value[0] - twa_parallel_B.xcur[0]) /
        eml_p_del;
      eml_n1hat[1] = (twa_parallel_P.x_des_Value[1] - twa_parallel_B.xcur[1]) /
        eml_p_del;
      eml_n1hat[2] = (twa_parallel_P.x_des_Value[2] - twa_parallel_B.xcur[2]) /
        eml_p_del;
    } else {
      /* '<S27>:1:18' */
      eml_n1hat[0] = 0.0;
      eml_n1hat[1] = 0.0;
      eml_n1hat[2] = 0.0;
    }

    /* *  */
    /*  This can probably be replaced with scalar angular difference that will  */
    /*  always bout about me = [0 0 1]' */
    /* * */
    /*  desired orientation angle rotation matrix and error roation matrix */
    /* '<S27>:1:27' */
    /* '<S27>:1:28' */
    /* '<S27>:1:29' */
    eml_n1hat_0[0] = cos(twa_parallel_P.ee_rot_des_Value);
    eml_n1hat_0[3] = -sin(twa_parallel_P.ee_rot_des_Value);
    eml_n1hat_0[6] = 0.0;
    eml_n1hat_0[1] = sin(twa_parallel_P.ee_rot_des_Value);
    eml_n1hat_0[4] = cos(twa_parallel_P.ee_rot_des_Value);
    eml_n1hat_0[7] = 0.0;
    eml_n1hat_0[2] = 0.0;
    eml_n1hat_0[5] = 0.0;
    eml_n1hat_0[8] = 1.0;
    eml_r_cur_0[0] = cos(twa_parallel_B.eerotcur);
    eml_r_cur_0[1] = -sin(twa_parallel_B.eerotcur);
    eml_r_cur_0[2] = 0.0;
    eml_r_cur_0[3] = sin(twa_parallel_B.eerotcur);
    eml_r_cur_0[4] = cos(twa_parallel_B.eerotcur);
    eml_r_cur_0[5] = 0.0;
    eml_r_cur_0[6] = 0.0;
    eml_r_cur_0[7] = 0.0;
    eml_r_cur_0[8] = 1.0;
    for (uIdx = 0; uIdx < 3; uIdx++) {
      for (k = 0; k < 3; k++) {
        eml_r_cur[uIdx + 3 * k] = 0.0;
        eml_r_cur[uIdx + 3 * k] = eml_r_cur[3 * k + uIdx] + eml_r_cur_0[3 * k] *
          eml_n1hat_0[uIdx];
        eml_r_cur[uIdx + 3 * k] = eml_r_cur_0[3 * k + 1] * eml_n1hat_0[uIdx + 3]
          + eml_r_cur[3 * k + uIdx];
        eml_r_cur[uIdx + 3 * k] = eml_r_cur_0[3 * k + 2] * eml_n1hat_0[uIdx + 6]
          + eml_r_cur[3 * k + uIdx];
      }
    }

    /*  orientational error angle and axis */
    /* '<S27>:1:32' */
    eml_y = eml_r_cur[0];
    eml_y += eml_r_cur[4];
    eml_y += eml_r_cur[8];
    eml_q3_mu = acos((eml_y - 1.0) / 2.0);

    /*  orientational error axis */
    if (eml_q3_mu != 0.0) {
      /* '<S27>:1:35' */
      /* '<S27>:1:36' */
      eml_y = 1.0 / (2.0 * sin(eml_q3_mu));
      eml_q2_mu = eml_r_cur[5] - eml_r_cur[7];
      eml_a_0 = eml_r_cur[6] - eml_r_cur[2];
      eml_c_0 = eml_r_cur[1] - eml_r_cur[3];
      eml_n2hat[0] = eml_y * eml_q2_mu;
      eml_n2hat[1] = eml_y * eml_a_0;
      eml_n2hat[2] = eml_y * eml_c_0;
    } else {
      /* '<S27>:1:40' */
      eml_n2hat[0] = 0.0;
      eml_n2hat[1] = 0.0;
      eml_n2hat[2] = 1.0;
    }

    /*  macro error thresholds */
    /* '<S27>:1:44' */
    eml_y = twa_parallel_P.res_rate_param_Value[0];

    /* '<S27>:1:45' */
    eml_a_0 = twa_parallel_P.res_rate_param_Value[1];

    /*  macro linear velocity */
    /* '<S27>:1:48' */
    eml_c = twa_parallel_P.res_rate_param_Value[2];

    /* '<S27>:1:49' */
    eml_q1_mu = twa_parallel_P.res_rate_param_Value[3];

    /*  macro rotational velocity */
    /* '<S27>:1:52' */
    eml_a = twa_parallel_P.res_rate_param_Value[4];

    /* '<S27>:1:53' */
    eml_c_0 = twa_parallel_P.res_rate_param_Value[5];

    /*  macro convergence radius multiplier */
    /* '<S27>:1:56' */
    eml_c_1 = twa_parallel_P.res_rate_param_Value[6];

    /* '<S27>:1:57' */
    eml_q2_mu = twa_parallel_P.res_rate_param_Value[7];

    /*  measure joint error, proceed with looping resolved rates if the norm of */
    /*  each joint error is less than 100 microns  */
    /* '<S27>:1:61' */
    /* '<S27>:1:62' */
    for (eml_rtemp = 0; eml_rtemp < 6; eml_rtemp++) {
      /* '<S27>:1:62' */
      /* '<S27>:1:63' */
      twa_parallel_B.qeps[eml_rtemp] = fabs
        (twa_parallel_B.UnitDelay1_a[eml_rtemp] -
         twa_parallel_B.TmpSignalConversionAtSFunctionI[eml_rtemp]);
    }

    eml_b_x[0] = (twa_parallel_B.qeps[0] < 0.1);
    eml_b_x[1] = (twa_parallel_B.qeps[1] < 0.1);
    eml_b_x[2] = (twa_parallel_B.qeps[2] < 0.1);
    eml_firstNonZero = TRUE;
    eml_rtemp = 1;
    eml_exitg = FALSE;
    while (((uint32_T)eml_exitg == 0U) && (eml_rtemp <= 3)) {
      if ((int32_T)eml_b_x[eml_rtemp - 1] == 0) {
        eml_firstNonZero = FALSE;
        eml_exitg = TRUE;
      } else {
        eml_rtemp++;
      }
    }

    if (eml_firstNonZero && ((eml_q3_mu > eml_a_0) || (eml_p_del > eml_y))) {
      /* '<S27>:1:67' */
      /*  linear velocity multiplier */
      if (eml_p_del != 0.0) {
        /* '<S27>:1:69' */
        if (eml_p_del / eml_y <= eml_c_1) {
          /* '<S27>:1:70' */
          /* '<S27>:1:71' */
          eml_c = (eml_c - eml_q1_mu) * (eml_p_del - eml_y) / ((eml_c_1 - 1.0) *
            eml_y) + eml_q1_mu;
        } else {
          /* '<S27>:1:73' */
        }
      } else {
        /* '<S27>:1:76' */
        eml_c = 0.0;
      }

      /*  angular velocity multiplier */
      if (eml_q3_mu != 0.0) {
        /* '<S27>:1:80' */
        if ((eml_q3_mu / eml_a_0 <= eml_q2_mu) && (eml_q3_mu != 0.0)) {
          /* '<S27>:1:81' */
          /* '<S27>:1:82' */
          eml_a = (eml_a - eml_c_0) * (eml_q3_mu - eml_a_0) / ((eml_q2_mu - 1.0)
            * eml_a_0) + eml_c_0;
        } else {
          /* '<S27>:1:84' */
        }
      } else {
        /* '<S27>:1:87' */
        eml_a = 0.0;
      }

      /*  xdot_des components */
      /* '<S27>:1:91' */
      /* '<S27>:1:92' */
      eml_q2_mu = eml_n1hat[0];
      eml_a_0 = eml_n2hat[0];
      eml_q2_mu *= eml_c;
      eml_a_0 *= eml_a;
      eml_n2hat[0] = eml_a_0;
      eml_n1hat[0] = eml_q2_mu;
      eml_q2_mu = eml_n1hat[1];
      eml_a_0 = eml_n2hat[1];
      eml_q2_mu *= eml_c;
      eml_a_0 *= eml_a;
      eml_n2hat[1] = eml_a_0;
      eml_n1hat[1] = eml_q2_mu;
      eml_q2_mu = eml_n1hat[2];
      eml_a_0 = eml_n2hat[2];
      eml_q2_mu *= eml_c;
      eml_a_0 *= eml_a;
      eml_n2hat[2] = eml_a_0;
      eml_n1hat[2] = eml_q2_mu;

      /*  qdot des using inverse kinematics with redundancy */
      /* '<S27>:1:95' */
      /*  new desired q values */
      /* '<S27>:1:98' */
      /* '<S27>:1:99' */
      eml_c_0 = eml_n1hat[0];
      eml_q2_mu = eml_n1hat[1];
      eml_a_0 = eml_n2hat[2];
      for (uIdx = 0; uIdx < 6; uIdx++) {
        eml_q1_mu = twa_parallel_B.full_jac[uIdx] * eml_c_0;
        eml_q1_mu += twa_parallel_B.full_jac[uIdx + 6] * eml_q2_mu;
        eml_q1_mu += twa_parallel_B.full_jac[uIdx + 12] * eml_a_0;
        twa_parallel_B.qdes[uIdx] = eml_q1_mu * twa_parallel_P.dt_Value +
          twa_parallel_B.TmpSignalConversionAtSFunctionI[uIdx];
      }

      /*  integrate current position */
      /* '<S27>:1:102' */
      twa_parallel_B.xcur_e[0] = eml_n1hat[0] * twa_parallel_P.dt_Value +
        twa_parallel_B.xcur[0];
      twa_parallel_B.xcur_e[1] = eml_n1hat[1] * twa_parallel_P.dt_Value +
        twa_parallel_B.xcur[1];
      twa_parallel_B.xcur_e[2] = eml_n1hat[2] * twa_parallel_P.dt_Value +
        twa_parallel_B.xcur[2];

      /* '<S27>:1:103' */
      twa_parallel_B.eerot = eml_n2hat[2] * twa_parallel_P.dt_Value +
        twa_parallel_B.eerotcur;
    } else {
      /* '<S27>:1:105' */
      /* '<S27>:1:106' */
      /* '<S27>:1:107' */
    }

    /* MultiPortSwitch: '<S5>/cntrl_switch' incorporates:
     *  Constant: '<S5>/cntrl_mode'
     */
    if ((int32_T)twa_parallel_P.cntrl_mode_Value == 1) {
      for (uIdx = 0; uIdx < 6; uIdx++) {
        twa_parallel_B.cntrl_switch[uIdx] = twa_parallel_B.Switch[uIdx];
      }
    } else {
      for (uIdx = 0; uIdx < 6; uIdx++) {
        twa_parallel_B.cntrl_switch[uIdx] = twa_parallel_B.qdes[uIdx];
      }
    }

    /* DigitalClock: '<S3>/Digital Clock' */
    twa_parallel_B.DigitalClock = twa_parallel_rtM->Timing.t[1];

    /* UnitDelay: '<S3>/Unit Delay' */
    twa_parallel_B.UnitDelay = twa_parallel_DWork.UnitDelay_DSTATE;

    /* UnitDelay: '<S3>/Unit Delay1' */
    twa_parallel_B.UnitDelay1_b = twa_parallel_DWork.UnitDelay1_DSTATE_h;

    /* Signal Processing Blockset N-Sample Enable  (sdspnsamp2) - '<S17>/N-Sample Enable' */
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

    /* SignalConversion: '<S16>/TmpSignal ConversionAt SFunction Inport2' */
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[0] =
      twa_parallel_B.velmex_pitch;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[1] =
      twa_parallel_B.velmex_pitch_e;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[2] =
      twa_parallel_B.velmex_pitch_k;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[3] =
      twa_parallel_B.gear_ratio_j;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[4] =
      twa_parallel_B.gear_ratio_n;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[5] =
      twa_parallel_B.gear_ratio_f;

    /* Embedded MATLAB: '<S3>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S3>/quintic_enable'
     *  Constant: '<S3>/tf'
     */
    /* Embedded MATLAB Function 'Quintic Poly/Embedded MATLAB Function': '<S16>:1' */
    /*  number of actuators */
    /* '<S16>:1:5' */
    twa_parallel_B.robot_mov = 0.0;

    /* '<S16>:1:6' */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* UnitDelay: '<S3>/Unit Delay2' */
      twa_parallel_B.UnitDelay2[uIdx] =
        twa_parallel_DWork.UnitDelay2_DSTATE[uIdx];

      /* Switch: '<S17>/Switch' */
      if (twa_parallel_B.NSampleEnable) {
        twa_parallel_B.Switch_f[uIdx] =
          twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx];
      } else {
        twa_parallel_B.Switch_f[uIdx] = twa_parallel_B.UnitDelay2[uIdx];
      }

      eml_eta[uIdx] = twa_parallel_B.cntrl_switch[uIdx] -
        twa_parallel_B.Switch_f[uIdx];
    }

    if (twa_parallel_P.quintic_enable_Value != 0.0) {
      for (uIdx = 0; uIdx < 6; uIdx++) {
        eml_a_1[uIdx] = eml_eta[uIdx];
      }

      eml_y = 0.0;
      eml_rtemp = 1;
      uIdx = 1;
      for (k = 0; k < 6; k++) {
        eml_y += eml_a_1[eml_rtemp - 1] * eml_eta[uIdx - 1];
        eml_rtemp++;
        uIdx++;
      }

      if (eml_y > 0.0) {
        /* '<S16>:1:9' */
        /*  conf = 0 means that the 5th order poly */
        /*  is not configured for the desired trajectory. */
        /*  Therefore, the block is initialized. */
        if (twa_parallel_B.UnitDelay == 0.0) {
          /* '<S16>:1:13' */
          /* '<S16>:1:14' */
          /* '<S16>:1:15' */
          twa_parallel_B.t0n = twa_parallel_B.DigitalClock;

          /* '<S16>:1:16' */
          twa_parallel_B.confn = 1.0;

          /* '<S16>:1:17' */
          /* '<S16>:1:18' */
          /* '<S16>:1:19' */
          for (uIdx = 0; uIdx < 6; uIdx++) {
            twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch_f[uIdx];
            twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.Switch_f[uIdx];
            twa_parallel_B.q_dot[uIdx] = 0.0;
            twa_parallel_B.q_dub_dot[uIdx] = 0.0;
          }
        } else {
          /* '<S16>:1:21' */
          /* '<S16>:1:22' */
          twa_parallel_B.t0n = twa_parallel_B.UnitDelay1_b;

          /* '<S16>:1:23' */
          twa_parallel_B.confn = twa_parallel_B.UnitDelay;

          /*  5th order polynomial */
          /* '<S16>:1:27' */
          /* '<S16>:1:28' */
          /* '<S16>:1:29' */
          for (uIdx = 0; uIdx < 6; uIdx++) {
            eml_q2_mu = eml_eta[uIdx];
            twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch_f[uIdx];
            eml_q2_mu *= -15.0;
            twa_parallel_B.q_dub_dot[uIdx] = -6.6666666666666663E-001 *
              eml_q2_mu;
            eml_a_1[uIdx] = -0.4 * eml_q2_mu;
            eml_eta[uIdx] = eml_q2_mu;
          }

          /* '<S16>:1:30' */
          eml_c_1 = twa_parallel_B.DigitalClock - twa_parallel_B.UnitDelay1_b;

          /* '<S16>:1:31' */
          eml_y = eml_c_1 / twa_parallel_P.tf_Value;
          if (eml_c_1 < twa_parallel_P.tf_Value) {
            /* '<S16>:1:33' */
            /* '<S16>:1:34' */
            twa_parallel_B.robot_mov = 1.0;

            /* '<S16>:1:35' */
            eml_a = rt_pow_snf(eml_y, 3.0);
            eml_c = rt_pow_snf(eml_y, 4.0);
            eml_y = rt_pow_snf(eml_y, 5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_cmd[uIdx] = ((twa_parallel_B.q_dub_dot[uIdx] *
                eml_a + twa_parallel_B.Switch_f[uIdx]) + eml_eta[uIdx] * eml_c)
                + eml_a_1[uIdx] * eml_y;
            }

            /* '<S16>:1:36' */
            eml_y = rt_pow_snf(eml_c_1, 2.0);
            eml_c = rt_pow_snf(twa_parallel_P.tf_Value, 3.0);
            eml_a = rt_pow_snf(eml_c_1, 3.0);
            eml_q1_mu = rt_pow_snf(twa_parallel_P.tf_Value, 4.0);
            eml_c_0 = rt_pow_snf(eml_c_1, 4.0);
            eml_a_0 = rt_pow_snf(twa_parallel_P.tf_Value, 5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_dot[uIdx] = (3.0 * twa_parallel_B.q_dub_dot[uIdx]
                * eml_y / eml_c + 4.0 * eml_eta[uIdx] * eml_a / eml_q1_mu) + 5.0
                * eml_a_1[uIdx] * eml_c_0 / eml_a_0;
            }

            /* '<S16>:1:37' */
            eml_y = rt_pow_snf(twa_parallel_P.tf_Value, 3.0);
            eml_c = rt_pow_snf(eml_c_1, 2.0);
            eml_a = rt_pow_snf(twa_parallel_P.tf_Value, 4.0);
            eml_q1_mu = rt_pow_snf(eml_c_1, 3.0);
            eml_c_0 = rt_pow_snf(twa_parallel_P.tf_Value, 5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_dub_dot[uIdx] = (6.0 *
                twa_parallel_B.q_dub_dot[uIdx] * eml_c_1 / eml_y + 12.0 *
                eml_eta[uIdx] * eml_c / eml_a) + 20.0 * eml_a_1[uIdx] *
                eml_q1_mu / eml_c_0;
            }
          } else {
            /* '<S16>:1:39' */
            /* '<S16>:1:40' */
            /* '<S16>:1:41' */
            /* '<S16>:1:42' */
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.cntrl_switch[uIdx];
              twa_parallel_B.q_dot[uIdx] = 0.0;
              twa_parallel_B.q_dub_dot[uIdx] = 0.0;
              twa_parallel_B.q0n[uIdx] = twa_parallel_B.cntrl_switch[uIdx];
            }
          }
        }
      } else {
        /* '<S16>:1:46' */
        /* '<S16>:1:47' */
        /* '<S16>:1:48' */
        /* '<S16>:1:49' */
        twa_parallel_B.confn = 0.0;

        /* '<S16>:1:50' */
        for (uIdx = 0; uIdx < 6; uIdx++) {
          twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.cntrl_switch[uIdx];
          twa_parallel_B.q_dot[uIdx] = 0.0;
          twa_parallel_B.q_dub_dot[uIdx] = 0.0;
          twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch_f[uIdx];
        }

        /* '<S16>:1:51' */
        twa_parallel_B.t0n = twa_parallel_B.UnitDelay1_b;
      }
    } else {
      /*  Configuration space is not used (pdot = 0). */
      /* '<S16>:1:55' */
      /* '<S16>:1:56' */
      /* '<S16>:1:57' */
      /*  However we do want to record the current */
      /* '<S16>:1:58' */
      twa_parallel_B.confn = 0.0;

      /*  position in order to be ready as soon */
      /* '<S16>:1:59' */
      twa_parallel_B.t0n = twa_parallel_B.DigitalClock;

      /*  as the enable becomes 1. */
      /* '<S16>:1:60' */
      for (uIdx = 0; uIdx < 6; uIdx++) {
        twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.cntrl_switch[uIdx];
        twa_parallel_B.q_dot[uIdx] = 0.0;
        twa_parallel_B.q_dub_dot[uIdx] = 0.0;
        twa_parallel_B.q0n[uIdx] =
          twa_parallel_B.TmpSignalConversionAtSFunctio_c[uIdx];
      }
    }

    /* ------------------------------------------------------------------------ */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* Sum: '<S2>/Sum' */
      twa_parallel_B.Sum[uIdx] = twa_parallel_B.q_cmd[uIdx] -
        twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx];

      /* Gain: '<S2>/Kp' */
      twa_parallel_B.Kp[uIdx] = twa_parallel_P.Kp_Gain[uIdx] *
        twa_parallel_B.Sum[uIdx];
    }
  }

  /* Integrator: '<S2>/Integrator' */
  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &twa_parallel_PrevZCSigState.Integrator_Reset_ZCE,
                       twa_parallel_P.reset_integrator_Value);

    /* evaluate zero-crossings */
    if (zcEvent) {
      {
        int_T i1;
        real_T *xc = &twa_parallel_X.Integrator_CSTATE[0];
        for (i1=0; i1 < 6; i1++) {
          xc[i1] = twa_parallel_P.Integrator_IC;
        }
      }
    }
  }

  {
    int_T i1;
    real_T *y0 = twa_parallel_B.Integrator;
    real_T *xc = &twa_parallel_X.Integrator_CSTATE[0];
    for (i1=0; i1 < 6; i1++) {
      y0[i1] = xc[i1];
    }
  }

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* Saturate: '<S2>/Saturation' incorporates:
       *  Saturate: '<S2>/saturate_int'
       */

      /* Gain: '<S2>/Ki' */
      twa_parallel_B.Ki[uIdx] = twa_parallel_P.Ki_Gain[uIdx] *
        twa_parallel_B.Integrator[uIdx];
      eml_q2_mu = twa_parallel_B.Ki[uIdx];
      twa_parallel_B.saturate_int[uIdx] = rt_SATURATE(eml_q2_mu,
        twa_parallel_P.saturate_int_LowerSat[uIdx],
        twa_parallel_P.saturate_int_UpperSat[uIdx]);

      /* SampleTimeMath: '<S15>/TSamp'
       *
       * About '<S15>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      twa_parallel_B.TSamp_h[uIdx] = twa_parallel_B.Sum[uIdx] *
        twa_parallel_P.TSamp_WtEt_p;

      /* UnitDelay: '<S15>/UD' */
      twa_parallel_B.Uk1_jb[uIdx] = twa_parallel_DWork.UD_DSTATE_o[uIdx];

      /* Sum: '<S15>/Diff' */
      twa_parallel_B.Diff_d[uIdx] = twa_parallel_B.TSamp_h[uIdx] -
        twa_parallel_B.Uk1_jb[uIdx];

      /* Gain: '<S2>/Kd' */
      twa_parallel_B.Kd[uIdx] = twa_parallel_P.Kd_Gain[uIdx] *
        twa_parallel_B.Diff_d[uIdx];

      /* Sum: '<S2>/Add' */
      twa_parallel_B.Add[uIdx] = (twa_parallel_B.Kp[uIdx] +
        twa_parallel_B.saturate_int[uIdx]) + twa_parallel_B.Kd[uIdx];
      eml_q2_mu = twa_parallel_B.Add[uIdx];
      twa_parallel_B.Saturation[uIdx] = rt_SATURATE(eml_q2_mu,
        twa_parallel_P.Saturation_LowerSat[uIdx],
        twa_parallel_P.Saturation_UpperSat[uIdx]);

      /* Switch: '<S2>/Switch' incorporates:
       *  Constant: '<S2>/manual_current'
       *  Constant: '<S2>/pid_mode'
       */
      if (twa_parallel_P.pid_mode_Value != 0.0) {
        twa_parallel_B.Switch_i[uIdx] = twa_parallel_B.Saturation[uIdx];
      } else {
        twa_parallel_B.Switch_i[uIdx] = twa_parallel_P.manual_current_Value[uIdx];
      }
    }

    /* ok to acquire for <S29>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_l.AcquireOK = 1;

    /* Constant: '<S25>/t_in_w' */
    memcpy((void *)(&twa_parallel_B.t_in_w[0]), (void *)
           (&twa_parallel_P.t_in_w_Value[0]), 9U * sizeof(real_T));

    /* Constant: '<S25>/twa_flange_offset' */
    twa_parallel_B.twa_flange_offset = twa_parallel_P.twa_flange_offset_Value;

    /* Constant: '<S25>/twa_gamma' */
    twa_parallel_B.twa_gamma = twa_parallel_P.twa_gamma_Value;

    /* Constant: '<S25>/use_twa' */
    twa_parallel_B.use_twa = twa_parallel_P.use_twa_Value;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void twa_parallel_update(int_T tid)
{
  int32_T k;
  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    /* Update for DiscreteFir: '<S14>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf =
      twa_parallel_DWork.DiscreteFIRFilter_circBuf - 1;
    if (twa_parallel_DWork.DiscreteFIRFilter_circBuf < 0) {
      twa_parallel_DWork.DiscreteFIRFilter_circBuf = 0;
    }

    for (k = 0; k < 6; k++) {
      twa_parallel_DWork.DiscreteFIRFilter_states[twa_parallel_DWork.DiscreteFIRFilter_circBuf
        + k] = twa_parallel_B.TmpSignalConversionAtDiscreteFI[k];
    }

    /* Update for UnitDelay: '<S13>/UD' */
    for (k = 0; k < 6; k++) {
      twa_parallel_DWork.UD_DSTATE[k] = twa_parallel_B.TSamp[k];
    }

    /* Update for DiscreteFir: '<S18>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf_l =
      twa_parallel_DWork.DiscreteFIRFilter_circBuf_l - 1;
    if (twa_parallel_DWork.DiscreteFIRFilter_circBuf_l < 0) {
      twa_parallel_DWork.DiscreteFIRFilter_circBuf_l = 0;
    }

    for (k = 0; k < 6; k++) {
      twa_parallel_DWork.DiscreteFIRFilter_states_m[twa_parallel_DWork.DiscreteFIRFilter_circBuf_l
        + k] = twa_parallel_B.TmpSignalConversionAtDiscreteFI[k];
    }

    /* Update for UnitDelay: '<S25>/Unit Delay6' */
    twa_parallel_DWork.UnitDelay6_DSTATE[0] = twa_parallel_B.xcur_e[0];
    twa_parallel_DWork.UnitDelay6_DSTATE[1] = twa_parallel_B.xcur_e[1];
    twa_parallel_DWork.UnitDelay6_DSTATE[2] = twa_parallel_B.xcur_e[2];

    /* Update for UnitDelay: '<S25>/Unit Delay3' */
    twa_parallel_DWork.UnitDelay3_DSTATE = twa_parallel_B.eerot;

    /* Update for UnitDelay: '<S3>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE = twa_parallel_B.confn;

    /* Update for UnitDelay: '<S3>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE_h = twa_parallel_B.t0n;
    for (k = 0; k < 6; k++) {
      /* Update for UnitDelay: '<S26>/Delay Input1' incorporates:
       *  Constant: '<S5>/q_des_usr'
       */
      twa_parallel_DWork.DelayInput1_DSTATE[k] =
        twa_parallel_P.q_des_usr_Value[k];

      /* Update for UnitDelay: '<S5>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE[k] = twa_parallel_B.cntrl_switch[k];

      /* Update for UnitDelay: '<S25>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE_b[k] = twa_parallel_B.qdes[k];

      /* Update for UnitDelay: '<S3>/Unit Delay2' */
      twa_parallel_DWork.UnitDelay2_DSTATE[k] = twa_parallel_B.q0n[k];
    }
  }

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    /* Update for UnitDelay: '<S15>/UD' */
    for (k = 0; k < 6; k++) {
      twa_parallel_DWork.UD_DSTATE_o[k] = twa_parallel_B.TSamp_h[k];
    }
  }

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    rt_ertODEUpdateContinuousStates(&twa_parallel_rtM->solverInfo);
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

  twa_parallel_rtM->Timing.t[0] = rtsiGetSolverStopTime
    (&twa_parallel_rtM->solverInfo);
  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
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

/* Derivatives for root system: '<Root>' */
void twa_parallel_derivatives(void)
{
  /* Derivatives for Integrator: '<S2>/Integrator' */
  {
    {
      int_T i1;
      const real_T *u0 = twa_parallel_B.Sum;
      real_T *xdot = &((StateDerivatives_twa_parallel *)
                       twa_parallel_rtM->ModelData.derivs)->Integrator_CSTATE[0];
      for (i1=0; i1 < 6; i1++) {
        xdot[i1] = u0[i1];
      }
    }
  }
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
    rtsiSetdXPtr(&twa_parallel_rtM->solverInfo,
                 &twa_parallel_rtM->ModelData.derivs);
    rtsiSetContStatesPtr(&twa_parallel_rtM->solverInfo,
                         &twa_parallel_rtM->ModelData.contStates);
    rtsiSetNumContStatesPtr(&twa_parallel_rtM->solverInfo,
      &twa_parallel_rtM->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&twa_parallel_rtM->solverInfo, (&rtmGetErrorStatus
      (twa_parallel_rtM)));
    rtsiSetRTModelPtr(&twa_parallel_rtM->solverInfo, twa_parallel_rtM);
  }

  rtsiSetSimTimeStep(&twa_parallel_rtM->solverInfo, MAJOR_TIME_STEP);
  twa_parallel_rtM->ModelData.intgData.deltaY=
    twa_parallel_rtM->ModelData.OdeDeltaY;
  twa_parallel_rtM->ModelData.intgData.f[0] = twa_parallel_rtM->ModelData.odeF[0];
  twa_parallel_rtM->ModelData.intgData.f[1] = twa_parallel_rtM->ModelData.odeF[1];
  twa_parallel_rtM->ModelData.intgData.f[2] = twa_parallel_rtM->ModelData.odeF[2];
  twa_parallel_rtM->ModelData.intgData.f[3] = twa_parallel_rtM->ModelData.odeF[3];
  twa_parallel_rtM->ModelData.intgData.f[4] = twa_parallel_rtM->ModelData.odeF[4];
  twa_parallel_rtM->ModelData.intgData.f[5] = twa_parallel_rtM->ModelData.odeF[5];
  twa_parallel_rtM->ModelData.intgData.f[6] = twa_parallel_rtM->ModelData.odeF[6];
  twa_parallel_rtM->ModelData.intgData.f[7] = twa_parallel_rtM->ModelData.odeF[7];
  twa_parallel_rtM->ModelData.intgData.f[8] = twa_parallel_rtM->ModelData.odeF[8];
  twa_parallel_rtM->ModelData.intgData.f[9] = twa_parallel_rtM->ModelData.odeF[9];
  twa_parallel_rtM->ModelData.intgData.f[10] = twa_parallel_rtM->ModelData.odeF
    [10];
  twa_parallel_rtM->ModelData.intgData.f[11] = twa_parallel_rtM->ModelData.odeF
    [11];
  twa_parallel_rtM->ModelData.intgData.f[12] = twa_parallel_rtM->ModelData.odeF
    [12];
  twa_parallel_rtM->ModelData.intgData.x0 = twa_parallel_rtM->ModelData.odeX0;
  twa_parallel_rtM->ModelData.contStates = ((real_T *) &twa_parallel_X);
  rtsiSetSolverData(&twa_parallel_rtM->solverInfo, (void *)
                    &twa_parallel_rtM->ModelData.intgData);
  rtsiSetSolverName(&twa_parallel_rtM->solverInfo,"ode8");

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
  twa_parallel_rtM->Sizes.checksums[0] = (651560163U);
  twa_parallel_rtM->Sizes.checksums[1] = (91343873U);
  twa_parallel_rtM->Sizes.checksums[2] = (1462715790U);
  twa_parallel_rtM->Sizes.checksums[3] = (26570083U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    twa_parallel_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
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
      twa_parallel_B.Uk1_j[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.UnitDelay1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.UnitDelay1_a[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.cntrl_switch[i] = 0.0;
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
      twa_parallel_B.Integrator[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Ki[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.saturate_int[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TSamp_h[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Uk1_jb[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Diff_d[i] = 0.0;
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
      twa_parallel_B.Switch_i[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      twa_parallel_B.t_in_w[i] = 0.0;
    }

    for (i = 0; i < 18; i++) {
      twa_parallel_B.full_jac[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TmpSignalConversionAtSFunctionI[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.qeps[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.qdes[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TmpSignalConversionAtSFunctio_c[i] = 0.0;
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

    twa_parallel_B.EncoderInput_o1 = 0.0;
    twa_parallel_B.EncoderInput_o2 = 0.0;
    twa_parallel_B.EncoderInput_o3 = 0.0;
    twa_parallel_B.EncoderInput_o4 = 0.0;
    twa_parallel_B.EncoderInput_o5 = 0.0;
    twa_parallel_B.EncoderInput_o6 = 0.0;
    twa_parallel_B.enc_res = 0.0;
    twa_parallel_B.gear_ratio = 0.0;
    twa_parallel_B.velmex_pitch = 0.0;
    twa_parallel_B.enc_res_f = 0.0;
    twa_parallel_B.gear_ratio_c = 0.0;
    twa_parallel_B.velmex_pitch_e = 0.0;
    twa_parallel_B.enc_res_c = 0.0;
    twa_parallel_B.gear_ratio_l = 0.0;
    twa_parallel_B.velmex_pitch_k = 0.0;
    twa_parallel_B.enc_res_fa = 0.0;
    twa_parallel_B.gear_ratio_j = 0.0;
    twa_parallel_B.enc_res_b = 0.0;
    twa_parallel_B.gear_ratio_n = 0.0;
    twa_parallel_B.enc_res_e = 0.0;
    twa_parallel_B.gear_ratio_f = 0.0;
    twa_parallel_B.UnitDelay6[0] = 0.0;
    twa_parallel_B.UnitDelay6[1] = 0.0;
    twa_parallel_B.UnitDelay6[2] = 0.0;
    twa_parallel_B.UnitDelay3 = 0.0;
    twa_parallel_B.DigitalClock = 0.0;
    twa_parallel_B.UnitDelay = 0.0;
    twa_parallel_B.UnitDelay1_b = 0.0;
    twa_parallel_B.twa_flange_offset = 0.0;
    twa_parallel_B.twa_gamma = 0.0;
    twa_parallel_B.use_twa = 0.0;
    twa_parallel_B.xcur[0] = 0.0;
    twa_parallel_B.xcur[1] = 0.0;
    twa_parallel_B.xcur[2] = 0.0;
    twa_parallel_B.eerotcur = 0.0;
    twa_parallel_B.xcur_e[0] = 0.0;
    twa_parallel_B.xcur_e[1] = 0.0;
    twa_parallel_B.xcur_e[2] = 0.0;
    twa_parallel_B.eerot = 0.0;
    twa_parallel_B.confn = 0.0;
    twa_parallel_B.t0n = 0.0;
    twa_parallel_B.robot_mov = 0.0;
  }

  /* parameters */
  twa_parallel_rtM->ModelData.defaultParam = ((real_T *)&twa_parallel_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &twa_parallel_X;
    twa_parallel_rtM->ModelData.contStates = (x);
    (void) memset((void *)&twa_parallel_X, 0,
                  sizeof(ContinuousStates_twa_parallel));
  }

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

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.DelayInput1_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  twa_parallel_DWork.UnitDelay6_DSTATE[0] = 0.0;
  twa_parallel_DWork.UnitDelay6_DSTATE[1] = 0.0;
  twa_parallel_DWork.UnitDelay6_DSTATE[2] = 0.0;
  twa_parallel_DWork.UnitDelay3_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UnitDelay1_DSTATE_b[i] = 0.0;
    }
  }

  twa_parallel_DWork.UnitDelay_DSTATE = 0.0;
  twa_parallel_DWork.UnitDelay1_DSTATE_h = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UnitDelay2_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UD_DSTATE_o[i] = 0.0;
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
  twa_parallel_PrevZCSigState.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
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

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

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
  twa_parallel_rtM->Sizes.numContStates = (6);/* Number of continuous states */
  twa_parallel_rtM->Sizes.numY = (0);  /* Number of model outputs */
  twa_parallel_rtM->Sizes.numU = (0);  /* Number of model inputs */
  twa_parallel_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  twa_parallel_rtM->Sizes.numSampTimes = (2);/* Number of sample times */
  twa_parallel_rtM->Sizes.numBlocks = (95);/* Number of blocks */
  twa_parallel_rtM->Sizes.numBlockIO = (75);/* Number of block outputs */
  twa_parallel_rtM->Sizes.numBlockPrms = (211);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for DiscreteFir: '<S14>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf = 0;

    /* InitializeConditions for DiscreteFir: '<S18>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf_l = 0;

    /* InitializeConditions for UnitDelay: '<S25>/Unit Delay6' */
    twa_parallel_DWork.UnitDelay6_DSTATE[0] = twa_parallel_P.UnitDelay6_X0[0];
    twa_parallel_DWork.UnitDelay6_DSTATE[1] = twa_parallel_P.UnitDelay6_X0[1];
    twa_parallel_DWork.UnitDelay6_DSTATE[2] = twa_parallel_P.UnitDelay6_X0[2];

    /* InitializeConditions for UnitDelay: '<S25>/Unit Delay3' */
    twa_parallel_DWork.UnitDelay3_DSTATE = twa_parallel_P.UnitDelay3_X0;

    /* InitializeConditions for Embedded MATLAB: '<S25>/get_jacobian' */
    twa_parallel_DWork.is_active_c1_twa_parallel = 0U;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.DiscreteFIRFilter_states[i] =
        twa_parallel_P.DiscreteFIRFilter_IC;

      /* InitializeConditions for UnitDelay: '<S13>/UD' */
      twa_parallel_DWork.UD_DSTATE[i] = twa_parallel_P.UD_X0;
      twa_parallel_DWork.DiscreteFIRFilter_states_m[i] =
        twa_parallel_P.DiscreteFIRFilter_IC_b;

      /* InitializeConditions for UnitDelay: '<S26>/Delay Input1' */
      twa_parallel_DWork.DelayInput1_DSTATE[i] = twa_parallel_P.DelayInput1_X0[i];

      /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE[i] = twa_parallel_P.UnitDelay1_X0[i];

      /* InitializeConditions for UnitDelay: '<S25>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE_b[i] =
        twa_parallel_P.UnitDelay1_X0_e[i];
    }

    /* InitializeConditions for Embedded MATLAB: '<S25>/ResolvedRates' */
    twa_parallel_DWork.is_active_c5_twa_parallel = 0U;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE = twa_parallel_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE_h = twa_parallel_P.UnitDelay1_X0_h;

    /* Signal Processing Blockset N-Sample Enable  (sdspnsamp2) - '<S17>/N-Sample Enable' */
    twa_parallel_DWork.NSampleEnable_Counter = (uint32_T) 0;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UnitDelay2_DSTATE[i] = twa_parallel_P.UnitDelay2_X0[i];
    }

    /* InitializeConditions for Embedded MATLAB: '<S3>/Embedded MATLAB Function' */
    twa_parallel_DWork.is_active_c22_twa_parallel = 0U;

    /* InitializeConditions for Integrator: '<S2>/Integrator' */
    {
      int_T i1;
      real_T *xc = &twa_parallel_X.Integrator_CSTATE[0];
      for (i1=0; i1 < 6; i1++) {
        xc[i1] = twa_parallel_P.Integrator_IC;
      }
    }

    /* InitializeConditions for UnitDelay: '<S15>/UD' */
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UD_DSTATE_o[i] = twa_parallel_P.UD_X0_f;
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

  /* S-Function Block: <S20>/S-Function (scblock) */
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
          "q1 [mm] %12.4f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Scopes/Fir Filter/Gain/s2"),
          "q2 [mm] %12.4f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Scopes/Fir Filter/Gain/s3"),
          "q3 [mm] %12.4f");
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
        xpceScopeAcqOK(1, &twa_parallel_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S19>/S-Function (scblock) */
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
          "Encoders/Derivative/Discrete Derivative/Diff/s1"),"q1d [mm/s] %8.6f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s2"),"q2d [mm/s] %8.6f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s3"),"q3d [mm/s] %8.6f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s4"),"q4d [cnt] %8.6f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s5"),"q5d [cnt] %8.6f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Encoders/Derivative/Discrete Derivative/Diff/s6"),"q6d [cnt] %8.6f");
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
        xpceScopeAcqOK(2, &twa_parallel_DWork.SFunction_IWORK_j.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S21>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("control_mode/cntrl_switch/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("control_mode/cntrl_switch/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("control_mode/cntrl_switch/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("control_mode/cntrl_switch/s4"));
        rl32eAddSignal(3, rl32eGetSignalNo("control_mode/cntrl_switch/s5"));
        rl32eAddSignal(3, rl32eGetSignalNo("control_mode/cntrl_switch/s6"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo(
          "control_mode/cntrl_switch/s1"),"q1_des [cnt] %8.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo(
          "control_mode/cntrl_switch/s2"),"q2_des [cnt] %8.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo(
          "control_mode/cntrl_switch/s3"),"q3_des [cnt] %8.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo(
          "control_mode/cntrl_switch/s4"),"q4_des [cnt] %8.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo(
          "control_mode/cntrl_switch/s5"),"q5_des [cnt] %8.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo(
          "control_mode/cntrl_switch/s6"),"q6_des [cnt] %8.4f");
        rl32eSetScope(3, 4, 25);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("control_mode/cntrl_switch/s1"));
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

  /* S-Function Block: <S22>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("PID Controller/Switch/s1"));
        rl32eAddSignal(4, rl32eGetSignalNo("PID Controller/Switch/s2"));
        rl32eAddSignal(4, rl32eGetSignalNo("PID Controller/Switch/s3"));
        rl32eAddSignal(4, rl32eGetSignalNo("PID Controller/Switch/s4"));
        rl32eAddSignal(4, rl32eGetSignalNo("PID Controller/Switch/s5"));
        rl32eAddSignal(4, rl32eGetSignalNo("PID Controller/Switch/s6"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("PID Controller/Switch/s1"),
          "q1_cmd [A] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("PID Controller/Switch/s2"),
          "q2_cmd [A] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("PID Controller/Switch/s3"),
          "q3_cmd [A] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("PID Controller/Switch/s4"),
          "q4_cmd [A] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("PID Controller/Switch/s5"),
          "q5_cmd [A] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("PID Controller/Switch/s6"),
          "q6_cmd [A] %12.4f");
        rl32eSetScope(4, 4, 25);
        rl32eSetScope(4, 40, 0);
        rl32eSetScope(4, 7, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("PID Controller/Switch/s1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 10, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, 0.0);
        rl32eSetTargetScope(4, 10, 0.0);
        xpceScopeAcqOK(4, &twa_parallel_DWork.SFunction_IWORK_ih.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* S-Function Block: <S23>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p2/s1"));
        rl32eAddSignal(5, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p2/s2"));
        rl32eAddSignal(5, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p2/s3"));
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p2/s1"),"xcur [mm] %12.4f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p2/s2"),"Ycur [mm] %12.4f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p2/s3"),"Zcur [mm] %12.4f");
        rl32eSetScope(5, 4, 25);
        rl32eSetScope(5, 40, 0);
        rl32eSetScope(5, 7, 1);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p2/s1"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 10, 0);
        rl32eSetTargetScope(5, 1, 0.0);
        rl32eSetTargetScope(5, 11, 0.0);
        rl32eSetTargetScope(5, 10, 0.0);
        xpceScopeAcqOK(5, &twa_parallel_DWork.SFunction_IWORK_m.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* S-Function Block: <S29>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s2"));
        rl32eAddSignal(7, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s3"));
        rl32eAddSignal(7, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s4"));
        rl32eAddSignal(7, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s5"));
        rl32eAddSignal(7, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s6"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s1"),"qeps1 %10.6f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s2"),"qeps2 %10.6f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s3"),"qeps3 %10.6f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s4"),"qeps4 %10.6f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s5"),"qeps5 %10.6f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s6"),"qeps6 %10.6f");
        rl32eSetScope(7, 4, 25);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 1);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo(
          "control_mode/task_space/ResolvedRates/p1/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, 0.0);
        rl32eSetTargetScope(7, 10, 0.0);
        xpceScopeAcqOK(7, &twa_parallel_DWork.SFunction_IWORK_l.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
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
