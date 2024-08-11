/*
 * twa_parallel.c
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
static real_T twa_parallel_norm_b(const real_T eml_x[3]);
static real_T twa_parallel_eml_xdotu_b(const real_T eml_x[3], const real_T
  eml_y[3]);
static void twa_parallel_mldivide_b(const real_T eml_A[36], const real_T eml_B
  [18], real_T eml_Y[18]);
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

/* Function for Embedded MATLAB: '<S6>/ResolvedRates' */
static real_T twa_parallel_norm_b(const real_T eml_x[3])
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

/* Function for Embedded MATLAB: '<S6>/ResolvedRates' */
static real_T twa_parallel_eml_xdotu_b(const real_T eml_x[3], const real_T
  eml_y[3])
{
  real_T eml_d;
  eml_d = eml_x[0] * eml_y[0];
  eml_d += eml_x[1] * eml_y[1];
  eml_d += eml_x[2] * eml_y[2];
  return eml_d;
}

/* Function for Embedded MATLAB: '<S6>/ResolvedRates' */
static void twa_parallel_mldivide_b(const real_T eml_A[36], const real_T eml_B
  [18], real_T eml_Y[18])
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

/* Function for Embedded MATLAB: '<S2>/Homing' */
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

/* Function for Embedded MATLAB: '<S2>/Homing' */
static real_T twa_parallel_eml_xdotu(const real_T eml_x[3], const real_T eml_y[3])
{
  real_T eml_d;
  eml_d = eml_x[0] * eml_y[0];
  eml_d += eml_x[1] * eml_y[1];
  eml_d += eml_x[2] * eml_y[2];
  return eml_d;
}

/* Function for Embedded MATLAB: '<S2>/Homing' */
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
  real_T eml_p_del;
  real_T eml_r_cur[9];
  real_T eml_r_del[9];
  real_T eml_theta_e;
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
  real_T eml_c;
  real_T eml_c_0;
  real_T eml_iik_jac[18];
  real_T eml_t;
  real_T eml_y;
  real_T eml_e_y[3];
  real_T eml_f_y[3];
  real_T eml_g_y[3];
  int32_T eml_k;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  real_T eml_eta[6];
  real_T eml_a_0[6];
  real_T eml_tdot[6];
  real_T eml_d_y[3];
  real_T eml_e_y_0[3];
  real_T eml_f_y_0[3];
  int32_T uIdx;
  int32_T k;
  int32_T uIdx_0;
  int32_T cff;
  int32_T j;
  real_T eml_d_y_0[3];
  real_T eml_e_y_1[3];
  real_T eml_f_y_1[3];
  real_T eml_iik_jac_0[18];
  real_T eml_iik_jac_1[18];
  real_T tmp[3];
  real_T tmp_0[3];
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
  real_T tmp_b[3];
  real_T tmp_c[3];
  real_T eml_e_y_2[3];
  real_T eml_f_y_2[3];
  real_T eml_g_y_0[3];
  real_T eml_iik_jac_2[18];
  real_T eml_iik_jac_3[18];
  real_T eml_y_0[3];
  real_T tmp_d[3];
  real_T eml_q1_mu_0[3];
  real_T tmp_e[3];
  real_T eml_t_0[3];
  real_T tmp_f[3];
  real_T tmp_g[3];
  real_T tmp_h[3];
  real_T tmp_i[3];
  real_T tmp_j[3];
  real_T tmp_k[3];
  real_T tmp_l[3];
  real_T tmp_m[3];
  real_T tmp_n[3];
  real_T tmp_o[3];
  real_T eml_r_cur_0[3];
  real_T eml_r_cur_1[9];
  real_T eml_n1hat_0[9];
  real_T eml_Y[18];
  static real_T tmp_p[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E+010, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0E+010, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E+010 };

  static real_T tmp_q[3] = { 0.0, 0.0, 1.0 };

  static int8_T tmp_r[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

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

  /* Reset subsysRan breadcrumbs */
  srClearBC(twa_parallel_DWork.Homing_SubsysRanBC);
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

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    /* Gain: '<S7>/enc_res' */
    twa_parallel_B.enc_res = twa_parallel_P.enc_res_Gain *
      twa_parallel_B.EncoderInput_o1;

    /* Gain: '<S7>/gear_ratio' */
    twa_parallel_B.gear_ratio = twa_parallel_P.gear_ratio_Gain *
      twa_parallel_B.enc_res;

    /* Gain: '<S8>/enc_res' */
    twa_parallel_B.enc_res_l = twa_parallel_P.enc_res_Gain_j *
      twa_parallel_B.EncoderInput_o2;

    /* Gain: '<S8>/gear_ratio' */
    twa_parallel_B.gear_ratio_p = twa_parallel_P.gear_ratio_Gain_i *
      twa_parallel_B.enc_res_l;

    /* Gain: '<S9>/enc_res' */
    twa_parallel_B.enc_res_f = twa_parallel_P.enc_res_Gain_jz *
      twa_parallel_B.EncoderInput_o3;

    /* Gain: '<S9>/gear_ratio' */
    twa_parallel_B.gear_ratio_c = twa_parallel_P.gear_ratio_Gain_d *
      twa_parallel_B.enc_res_f;

    /* Gain: '<S10>/enc_res' */
    twa_parallel_B.enc_res_c = twa_parallel_P.enc_res_Gain_i *
      twa_parallel_B.EncoderInput_o4;

    /* Gain: '<S10>/gear_ratio' */
    twa_parallel_B.gear_ratio_l = twa_parallel_P.gear_ratio_Gain_a *
      twa_parallel_B.enc_res_c;

    /* Gain: '<S11>/enc_res' */
    twa_parallel_B.enc_res_fa = twa_parallel_P.enc_res_Gain_g *
      twa_parallel_B.EncoderInput_o5;

    /* Gain: '<S11>/gear_ratio' */
    twa_parallel_B.gear_ratio_j = twa_parallel_P.gear_ratio_Gain_o *
      twa_parallel_B.enc_res_fa;

    /* Gain: '<S12>/enc_res' */
    twa_parallel_B.enc_res_b = twa_parallel_P.enc_res_Gain_ij *
      twa_parallel_B.EncoderInput_o6;

    /* Gain: '<S12>/gear_ratio' */
    twa_parallel_B.gear_ratio_n = twa_parallel_P.gear_ratio_Gain_da *
      twa_parallel_B.enc_res_b;

    /* SignalConversion: '<S15>/TmpSignal ConversionAtDiscrete FIR FilterInport1' */
    twa_parallel_B.TmpSignalConversionAtDiscreteFI[0] =
      twa_parallel_B.gear_ratio;
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

    /* DiscreteFir: '<S15>/Discrete FIR Filter' incorporates:
     *  Constant: '<S15>/vel_filter_coeffs'
     */
    uIdx = 0;
    for (k = 0; k < 6; k++) {
      uIdx_0 = twa_parallel_DWork.DiscreteFIRFilter_circBuf;
      eml_t = twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx] *
        twa_parallel_P.vel_filter_coeffs_Value[0];
      uIdx++;
      cff = 1;
      for (j = uIdx_0; j < 1; j++) {
        eml_k = k + j;
        eml_t += twa_parallel_DWork.DiscreteFIRFilter_states[eml_k] *
          twa_parallel_P.vel_filter_coeffs_Value[cff];
        cff++;
      }

      for (j = 0; j < uIdx_0; j++) {
        eml_k = k + j;
        eml_t += twa_parallel_DWork.DiscreteFIRFilter_states[eml_k] *
          twa_parallel_P.vel_filter_coeffs_Value[cff];
        cff++;
      }

      twa_parallel_B.DiscreteFIRFilter[k] = eml_t;
    }

    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* Gain: '<S15>/Gain' */
      twa_parallel_B.Gain[uIdx] = twa_parallel_P.Gain_Gain *
        twa_parallel_B.DiscreteFIRFilter[uIdx];

      /* SampleTimeMath: '<S14>/TSamp'
       *
       * About '<S14>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      twa_parallel_B.TSamp[uIdx] = twa_parallel_B.Gain[uIdx] *
        twa_parallel_P.TSamp_WtEt;

      /* UnitDelay: '<S14>/UD' */
      twa_parallel_B.Uk1[uIdx] = twa_parallel_DWork.UD_DSTATE[uIdx];

      /* Sum: '<S14>/Diff' */
      twa_parallel_B.Diff[uIdx] = twa_parallel_B.TSamp[uIdx] -
        twa_parallel_B.Uk1[uIdx];
    }

    /* ok to acquire for <S23>/S-Function */
    twa_parallel_DWork.SFunction_IWORK.AcquireOK = 1;

    /* DiscreteFir: '<S21>/Discrete FIR Filter' incorporates:
     *  Constant: '<S21>/vel_filter_coeffs'
     */
    uIdx_0 = 0;
    for (uIdx = 0; uIdx < 6; uIdx++) {
      k = twa_parallel_DWork.DiscreteFIRFilter_circBuf_l;
      eml_t = twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx_0] *
        twa_parallel_P.vel_filter_coeffs_Value_m[0];
      uIdx_0++;
      cff = 1;
      for (j = k; j < 1; j++) {
        eml_k = uIdx + j;
        eml_t += twa_parallel_DWork.DiscreteFIRFilter_states_m[eml_k] *
          twa_parallel_P.vel_filter_coeffs_Value_m[cff];
        cff++;
      }

      for (j = 0; j < k; j++) {
        eml_k = uIdx + j;
        eml_t += twa_parallel_DWork.DiscreteFIRFilter_states_m[eml_k] *
          twa_parallel_P.vel_filter_coeffs_Value_m[cff];
        cff++;
      }

      twa_parallel_B.DiscreteFIRFilter_h[uIdx] = eml_t;
    }

    /* Gain: '<S21>/Gain' */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      twa_parallel_B.Gain_n[uIdx] = twa_parallel_P.Gain_Gain_d *
        twa_parallel_B.DiscreteFIRFilter_h[uIdx];
    }

    /* ok to acquire for <S22>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_j.AcquireOK = 1;

    /* ok to acquire for <S24>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_i.AcquireOK = 1;

    /* ok to acquire for <S18>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_m.AcquireOK = 1;

    /* UnitDelay: '<S6>/Unit Delay4' */
    twa_parallel_B.UnitDelay4[0] = twa_parallel_DWork.UnitDelay4_DSTATE[0];
    twa_parallel_B.UnitDelay4[1] = twa_parallel_DWork.UnitDelay4_DSTATE[1];
    twa_parallel_B.UnitDelay4[2] = twa_parallel_DWork.UnitDelay4_DSTATE[2];

    /* UnitDelay: '<S6>/Unit Delay3' */
    twa_parallel_B.UnitDelay3 = twa_parallel_DWork.UnitDelay3_DSTATE;

    /* SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport2' */
    twa_parallel_B.TmpSignalConversionAtSFunctionI[0] =
      twa_parallel_B.gear_ratio;
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

    /* Embedded MATLAB: '<S6>/ResolvedRates' incorporates:
     *  Constant: '<S6>/b_in_w'
     *  Constant: '<S6>/dt'
     *  Constant: '<S6>/ee_rot_des'
     *  Constant: '<S6>/f_in_w'
     *  Constant: '<S6>/m_in_w'
     *  Constant: '<S6>/p_in_m'
     *  Constant: '<S6>/x_des'
     */
    /* Embedded MATLAB Function 'task_space/ResolvedRates': '<S25>:1' */
    /* '<S25>:1:4' */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* UnitDelay: '<S6>/Unit Delay1' */
      twa_parallel_B.UnitDelay1[uIdx] =
        twa_parallel_DWork.UnitDelay1_DSTATE[uIdx];
      twa_parallel_B.qdes[uIdx] = twa_parallel_B.UnitDelay1[uIdx];
    }

    /* '<S25>:1:5' */
    /* '<S25>:1:6' */
    twa_parallel_B.eerot = twa_parallel_B.UnitDelay3;

    /*  axis for jacobian definitions */
    /* '<S25>:1:9' */
    /*  positional error */
    /* '<S25>:1:12' */
    twa_parallel_B.xcur[0] = twa_parallel_B.UnitDelay4[0];
    tmp_o[0] = twa_parallel_P.x_des_Value[0] - twa_parallel_B.UnitDelay4[0];
    twa_parallel_B.xcur[1] = twa_parallel_B.UnitDelay4[1];
    tmp_o[1] = twa_parallel_P.x_des_Value[1] - twa_parallel_B.UnitDelay4[1];
    twa_parallel_B.xcur[2] = twa_parallel_B.UnitDelay4[2];
    tmp_o[2] = twa_parallel_P.x_des_Value[2] - twa_parallel_B.UnitDelay4[2];
    eml_p_del = twa_parallel_norm_b(tmp_o);

    /*  desired orientation angle rotation matrix and error roation matrix */
    /* '<S25>:1:15' */
    /* '<S25>:1:16' */
    eml_r_cur[0] = cos(twa_parallel_B.UnitDelay3);
    eml_r_cur[3] = -sin(twa_parallel_B.UnitDelay3);
    eml_r_cur[6] = 0.0;
    eml_r_cur[1] = sin(twa_parallel_B.UnitDelay3);
    eml_r_cur[4] = cos(twa_parallel_B.UnitDelay3);
    eml_r_cur[7] = 0.0;
    eml_r_cur[2] = 0.0;
    eml_r_cur[5] = 0.0;
    eml_r_cur[8] = 1.0;

    /* '<S25>:1:17' */
    eml_n1hat_0[0] = cos(twa_parallel_P.ee_rot_des_Value);
    eml_n1hat_0[3] = -sin(twa_parallel_P.ee_rot_des_Value);
    eml_n1hat_0[6] = 0.0;
    eml_n1hat_0[1] = sin(twa_parallel_P.ee_rot_des_Value);
    eml_n1hat_0[4] = cos(twa_parallel_P.ee_rot_des_Value);
    eml_n1hat_0[7] = 0.0;
    eml_n1hat_0[2] = 0.0;
    eml_n1hat_0[5] = 0.0;
    eml_n1hat_0[8] = 1.0;
    for (uIdx = 0; uIdx < 3; uIdx++) {
      for (k = 0; k < 3; k++) {
        eml_r_del[uIdx + 3 * k] = 0.0;
        eml_r_del[uIdx + 3 * k] = eml_r_del[3 * k + uIdx] + eml_n1hat_0[uIdx] *
          eml_r_cur[k];
        eml_r_del[uIdx + 3 * k] = eml_r_del[3 * k + uIdx] + eml_n1hat_0[uIdx + 3]
          * eml_r_cur[k + 3];
        eml_r_del[uIdx + 3 * k] = eml_r_del[3 * k + uIdx] + eml_n1hat_0[uIdx + 6]
          * eml_r_cur[k + 6];
      }
    }

    /*  orientational error angle and axis */
    /* '<S25>:1:20' */
    eml_t = eml_r_del[0];
    eml_t += eml_r_del[4];
    eml_t += eml_r_del[8];
    eml_theta_e = acos((eml_t - 1.0) / 2.0);

    /*  error thresholds */
    /* '<S25>:1:23' */
    /* '<S25>:1:24' */
    eml_y = 0.0;
    eml_scale = 0.0;
    eml_firstNonZero = TRUE;
    for (eml_k = 0; eml_k < 6; eml_k++) {
      eml_t = twa_parallel_B.Diff[eml_k];
      if (eml_t != 0.0) {
        eml_t = fabs(eml_t);
        if (eml_firstNonZero) {
          eml_scale = eml_t;
          eml_y = 1.0;
          eml_firstNonZero = FALSE;
        } else if (eml_scale < eml_t) {
          eml_q1_mu = eml_scale / eml_t;
          eml_y = eml_y * eml_q1_mu * eml_q1_mu + 1.0;
          eml_scale = eml_t;
        } else {
          eml_q1_mu = eml_t / eml_scale;
          eml_y += eml_q1_mu * eml_q1_mu;
        }
      }
    }

    eml_y = eml_scale * sqrt(eml_y);
    if (eml_y > 0.001) {
      /* '<S25>:1:27' */
      if ((eml_theta_e > 0.001) || (eml_p_del > 0.01)) {
        /* '<S25>:1:28' */
        /*  moving platform vertex locations */
        /* '<S25>:1:30' */
        for (uIdx = 0; uIdx < 3; uIdx++) {
          eml_n1hat_0[uIdx] = 0.0;
          eml_n1hat_0[uIdx] += twa_parallel_B.UnitDelay4[uIdx];
          eml_n1hat_0[uIdx + 3] = 0.0;
          eml_n1hat_0[uIdx + 3] += twa_parallel_B.UnitDelay4[uIdx];
          eml_n1hat_0[uIdx + 6] = 0.0;
          eml_n1hat_0[uIdx + 6] += twa_parallel_B.UnitDelay4[uIdx];
        }

        for (uIdx = 0; uIdx < 3; uIdx++) {
          for (k = 0; k < 3; k++) {
            eml_r_cur_1[uIdx + 3 * k] = 0.0;
            eml_r_cur_1[uIdx + 3 * k] = eml_r_cur_1[3 * k + uIdx] +
              twa_parallel_P.p_in_m_Value_m[3 * k] * eml_r_cur[uIdx];
            eml_r_cur_1[uIdx + 3 * k] = twa_parallel_P.p_in_m_Value_m[3 * k + 1]
              * eml_r_cur[uIdx + 3] + eml_r_cur_1[3 * k + uIdx];
            eml_r_cur_1[uIdx + 3 * k] = twa_parallel_P.p_in_m_Value_m[3 * k + 2]
              * eml_r_cur[uIdx + 6] + eml_r_cur_1[3 * k + uIdx];
          }
        }

        for (uIdx = 0; uIdx < 3; uIdx++) {
          eml_p_in_w[3 * uIdx] = eml_n1hat_0[3 * uIdx] + eml_r_cur_1[3 * uIdx];
          eml_p_in_w[1 + 3 * uIdx] = eml_n1hat_0[3 * uIdx + 1] + eml_r_cur_1[3 *
            uIdx + 1];
          eml_p_in_w[2 + 3 * uIdx] = eml_n1hat_0[3 * uIdx + 2] + eml_r_cur_1[3 *
            uIdx + 2];
        }

        /*         %% instantaneous direct kinematics jacobian */
        /*  vector from base vertex to moving platform vertex */
        /* '<S25>:1:34' */
        eml_y_0[0] = twa_parallel_P.b_in_w_Value_i[0] - eml_p_in_w[0];
        eml_y_0[1] = twa_parallel_P.b_in_w_Value_i[1] - eml_p_in_w[1];
        eml_y_0[2] = twa_parallel_P.b_in_w_Value_i[2] - eml_p_in_w[2];
        eml_t = twa_parallel_norm_b(eml_y_0);

        /* '<S25>:1:35' */
        eml_n1hat[0] = (eml_p_in_w[0] - twa_parallel_P.b_in_w_Value_i[0]) /
          eml_t;
        eml_q1_mu_0[0] = twa_parallel_P.b_in_w_Value_i[3] - eml_p_in_w[3];
        eml_n1hat[1] = (eml_p_in_w[1] - twa_parallel_P.b_in_w_Value_i[1]) /
          eml_t;
        eml_q1_mu_0[1] = twa_parallel_P.b_in_w_Value_i[4] - eml_p_in_w[4];
        eml_n1hat[2] = (eml_p_in_w[2] - twa_parallel_P.b_in_w_Value_i[2]) /
          eml_t;
        eml_q1_mu_0[2] = twa_parallel_P.b_in_w_Value_i[5] - eml_p_in_w[5];
        eml_t = twa_parallel_norm_b(eml_q1_mu_0);

        /* '<S25>:1:36' */
        eml_n2hat[0] = (eml_p_in_w[3] - twa_parallel_P.b_in_w_Value_i[3]) /
          eml_t;
        eml_t_0[0] = twa_parallel_P.b_in_w_Value_i[6] - eml_p_in_w[6];
        eml_n2hat[1] = (eml_p_in_w[4] - twa_parallel_P.b_in_w_Value_i[4]) /
          eml_t;
        eml_t_0[1] = twa_parallel_P.b_in_w_Value_i[7] - eml_p_in_w[7];
        eml_n2hat[2] = (eml_p_in_w[5] - twa_parallel_P.b_in_w_Value_i[5]) /
          eml_t;
        eml_t_0[2] = twa_parallel_P.b_in_w_Value_i[8] - eml_p_in_w[8];
        eml_t = twa_parallel_norm_b(eml_t_0);

        /* '<S25>:1:38' */
        /* '<S25>:1:39' */
        /* '<S25>:1:40' */
        /* '<S25>:1:42' */
        /*         %% instantaneous inverse kinematics jacobian */
        /*  micro actuator (TWA) lengths */
        /* '<S25>:1:48' */
        for (uIdx = 0; uIdx < 3; uIdx++) {
          eml_n3hat[uIdx] = (eml_p_in_w[6 + uIdx] -
                             twa_parallel_P.b_in_w_Value_i[6 + uIdx]) / eml_t;
          eml_scale = eml_r_cur[uIdx] * twa_parallel_P.p_in_m_Value_m[0];
          eml_scale += eml_r_cur[uIdx + 3] * twa_parallel_P.p_in_m_Value_m[1];
          eml_scale += eml_r_cur[uIdx + 6] * twa_parallel_P.p_in_m_Value_m[2];
          eml_q1_mu = eml_r_cur[uIdx] * twa_parallel_P.p_in_m_Value_m[3];
          eml_q1_mu += eml_r_cur[uIdx + 3] * twa_parallel_P.p_in_m_Value_m[4];
          eml_q1_mu += eml_r_cur[uIdx + 6] * twa_parallel_P.p_in_m_Value_m[5];
          eml_q2_mu = eml_r_cur[uIdx] * twa_parallel_P.p_in_m_Value_m[6];
          eml_q2_mu += eml_r_cur[uIdx + 3] * twa_parallel_P.p_in_m_Value_m[7];
          eml_q2_mu += eml_r_cur[uIdx + 6] * twa_parallel_P.p_in_m_Value_m[8];
          eml_y_0[uIdx] = twa_parallel_P.b_in_w_Value_i[uIdx] -
            twa_parallel_P.m_in_w_Value_n[uIdx];
          eml_q1_mu_0[uIdx] = twa_parallel_P.b_in_w_Value_i[3 + uIdx] -
            twa_parallel_P.m_in_w_Value_n[3 + uIdx];
          eml_t_0[uIdx] = twa_parallel_P.b_in_w_Value_i[6 + uIdx] -
            twa_parallel_P.m_in_w_Value_n[6 + uIdx];
          tmp_o[uIdx] = twa_parallel_P.m_in_w_Value_n[uIdx] -
            twa_parallel_P.b_in_w_Value_i[uIdx];
          eml_g_y[uIdx] = eml_q2_mu;
          eml_f_y[uIdx] = eml_q1_mu;
          eml_e_y[uIdx] = eml_scale;
        }

        eml_q1_mu = twa_parallel_norm_b(eml_y_0);

        /* '<S25>:1:49' */
        eml_q2_mu = twa_parallel_norm_b(eml_q1_mu_0);

        /* '<S25>:1:50' */
        eml_q3_mu = twa_parallel_norm_b(eml_t_0);

        /*  vector from base vertex to twa motor attachment point */
        /* '<S25>:1:53' */
        eml_t = twa_parallel_norm_b(tmp_o);

        /* '<S25>:1:54' */
        eml_l1_hat[0] = (twa_parallel_P.m_in_w_Value_n[0] -
                         twa_parallel_P.b_in_w_Value_i[0]) / eml_t;
        tmp_n[0] = twa_parallel_P.m_in_w_Value_n[3] -
          twa_parallel_P.b_in_w_Value_i[3];
        eml_l1_hat[1] = (twa_parallel_P.m_in_w_Value_n[1] -
                         twa_parallel_P.b_in_w_Value_i[1]) / eml_t;
        tmp_n[1] = twa_parallel_P.m_in_w_Value_n[4] -
          twa_parallel_P.b_in_w_Value_i[4];
        eml_l1_hat[2] = (twa_parallel_P.m_in_w_Value_n[2] -
                         twa_parallel_P.b_in_w_Value_i[2]) / eml_t;
        tmp_n[2] = twa_parallel_P.m_in_w_Value_n[5] -
          twa_parallel_P.b_in_w_Value_i[5];
        eml_t = twa_parallel_norm_b(tmp_n);

        /* '<S25>:1:55' */
        eml_l2_hat[0] = (twa_parallel_P.m_in_w_Value_n[3] -
                         twa_parallel_P.b_in_w_Value_i[3]) / eml_t;
        tmp_m[0] = twa_parallel_P.m_in_w_Value_n[6] -
          twa_parallel_P.b_in_w_Value_i[6];
        eml_l2_hat[1] = (twa_parallel_P.m_in_w_Value_n[4] -
                         twa_parallel_P.b_in_w_Value_i[4]) / eml_t;
        tmp_m[1] = twa_parallel_P.m_in_w_Value_n[7] -
          twa_parallel_P.b_in_w_Value_i[7];
        eml_l2_hat[2] = (twa_parallel_P.m_in_w_Value_n[5] -
                         twa_parallel_P.b_in_w_Value_i[5]) / eml_t;
        tmp_m[2] = twa_parallel_P.m_in_w_Value_n[8] -
          twa_parallel_P.b_in_w_Value_i[8];
        eml_t = twa_parallel_norm_b(tmp_m);

        /*  distance from micro actuator attachmnet point (m_i) to flexure rotation */
        /* center (f_i) */
        /* '<S25>:1:59' */
        eml_l3_hat[0] = (twa_parallel_P.m_in_w_Value_n[6] -
                         twa_parallel_P.b_in_w_Value_i[6]) / eml_t;
        tmp_l[0] = twa_parallel_P.m_in_w_Value_n[0] -
          twa_parallel_P.f_in_w_Value_b[0];
        tmp_k[0] = twa_parallel_P.m_in_w_Value_n[3] -
          twa_parallel_P.f_in_w_Value_b[3];
        tmp_j[0] = twa_parallel_P.m_in_w_Value_n[6] -
          twa_parallel_P.f_in_w_Value_b[6];
        tmp_i[0] = twa_parallel_P.b_in_w_Value_i[0] -
          twa_parallel_P.f_in_w_Value_b[0];
        tmp_h[0] = twa_parallel_P.b_in_w_Value_i[3] -
          twa_parallel_P.f_in_w_Value_b[3];
        tmp_g[0] = twa_parallel_P.b_in_w_Value_i[6] -
          twa_parallel_P.f_in_w_Value_b[6];
        eml_l3_hat[1] = (twa_parallel_P.m_in_w_Value_n[7] -
                         twa_parallel_P.b_in_w_Value_i[7]) / eml_t;
        tmp_l[1] = twa_parallel_P.m_in_w_Value_n[1] -
          twa_parallel_P.f_in_w_Value_b[1];
        tmp_k[1] = twa_parallel_P.m_in_w_Value_n[4] -
          twa_parallel_P.f_in_w_Value_b[4];
        tmp_j[1] = twa_parallel_P.m_in_w_Value_n[7] -
          twa_parallel_P.f_in_w_Value_b[7];
        tmp_i[1] = twa_parallel_P.b_in_w_Value_i[1] -
          twa_parallel_P.f_in_w_Value_b[1];
        tmp_h[1] = twa_parallel_P.b_in_w_Value_i[4] -
          twa_parallel_P.f_in_w_Value_b[4];
        tmp_g[1] = twa_parallel_P.b_in_w_Value_i[7] -
          twa_parallel_P.f_in_w_Value_b[7];
        eml_l3_hat[2] = (twa_parallel_P.m_in_w_Value_n[8] -
                         twa_parallel_P.b_in_w_Value_i[8]) / eml_t;
        tmp_l[2] = twa_parallel_P.m_in_w_Value_n[2] -
          twa_parallel_P.f_in_w_Value_b[2];
        tmp_k[2] = twa_parallel_P.m_in_w_Value_n[5] -
          twa_parallel_P.f_in_w_Value_b[5];
        tmp_j[2] = twa_parallel_P.m_in_w_Value_n[8] -
          twa_parallel_P.f_in_w_Value_b[8];
        tmp_i[2] = twa_parallel_P.b_in_w_Value_i[2] -
          twa_parallel_P.f_in_w_Value_b[2];
        tmp_h[2] = twa_parallel_P.b_in_w_Value_i[5] -
          twa_parallel_P.f_in_w_Value_b[5];
        tmp_g[2] = twa_parallel_P.b_in_w_Value_i[8] -
          twa_parallel_P.f_in_w_Value_b[8];
        eml_t = twa_parallel_norm_b(tmp_l);

        /* '<S25>:1:60' */
        eml_scale = twa_parallel_norm_b(tmp_k);

        /* '<S25>:1:61' */
        eml_a = twa_parallel_norm_b(tmp_j);

        /*  distance from flexure rotation center (f_i) to base vertex */
        /* '<S25>:1:64' */
        eml_y = twa_parallel_norm_b(tmp_i);

        /* '<S25>:1:65' */
        eml_c = twa_parallel_norm_b(tmp_h);

        /* '<S25>:1:66' */
        eml_c_0 = twa_parallel_norm_b(tmp_g);

        /*  term to paramterize angle between a_i and qimu, delta */
        /* '<S25>:1:69' */
        /* '<S25>:1:70' */
        /* '<S25>:1:71' */
        /*  time derivatives */
        /* '<S25>:1:74' */
        /* '<S25>:1:75' */
        /* '<S25>:1:76' */
        /* '<S25>:1:78' */
        eml_y = (((rt_pow_snf(eml_y, 2.0) - rt_pow_snf(eml_t, 2.0)) - rt_pow_snf
                  (eml_q1_mu, 2.0)) * 2.0 * eml_t + 4.0 * eml_t * rt_pow_snf
                 (eml_q1_mu, 2.0)) / (4.0 * rt_pow_snf(eml_t, 2.0) * rt_pow_snf
          (eml_q1_mu, 2.0)) * eml_q1_mu / sqrt(1.0 - rt_pow_snf(((rt_pow_snf
          (eml_y, 2.0) - rt_pow_snf(eml_t, 2.0)) - rt_pow_snf(eml_q1_mu, 2.0)) /
          (-2.0 * eml_t * eml_q1_mu), 2.0));

        /* '<S25>:1:79' */
        eml_q1_mu = (((rt_pow_snf(eml_c, 2.0) - rt_pow_snf(eml_scale, 2.0)) -
                      rt_pow_snf(eml_q2_mu, 2.0)) * 2.0 * eml_scale + 4.0 *
                     eml_scale * rt_pow_snf(eml_q2_mu, 2.0)) / (4.0 * rt_pow_snf
          (eml_scale, 2.0) * rt_pow_snf(eml_q2_mu, 2.0)) * eml_q2_mu / sqrt(1.0
          - rt_pow_snf(((rt_pow_snf(eml_c, 2.0) - rt_pow_snf(eml_scale, 2.0)) -
                        rt_pow_snf(eml_q2_mu, 2.0)) / (-2.0 * eml_scale *
          eml_q2_mu), 2.0));

        /* '<S25>:1:80' */
        eml_t = (((rt_pow_snf(eml_c_0, 2.0) - rt_pow_snf(eml_a, 2.0)) -
                  rt_pow_snf(eml_q3_mu, 2.0)) * 2.0 * eml_a + 4.0 * eml_a *
                 rt_pow_snf(eml_q3_mu, 2.0)) / (4.0 * rt_pow_snf(eml_a, 2.0) *
          rt_pow_snf(eml_q3_mu, 2.0)) * eml_q3_mu / sqrt(1.0 - rt_pow_snf
          (((rt_pow_snf(eml_c_0, 2.0) - rt_pow_snf(eml_a, 2.0)) - rt_pow_snf
            (eml_q3_mu, 2.0)) / (-2.0 * eml_a * eml_q3_mu), 2.0));

        /*  micro motion instantaneous inverse kinematics jacobian */
        /* '<S25>:1:83' */
        /*  macro motion instantaneous inverse kinematics jacobian */
        /* '<S25>:1:88' */
        /*  combined macro-micro motion IIK jacobian */
        /* '<S25>:1:91' */
        tmp_d[0] = 0.0 * eml_l1_hat[2] - eml_l1_hat[1];
        tmp_d[1] = eml_l1_hat[0] - 0.0 * eml_l1_hat[2];
        tmp_d[2] = 0.0 * eml_l1_hat[1] - 0.0 * eml_l1_hat[0];
        tmp_e[0] = 0.0 * eml_l2_hat[2] - eml_l2_hat[1];
        tmp_e[1] = eml_l2_hat[0] - 0.0 * eml_l2_hat[2];
        tmp_e[2] = 0.0 * eml_l2_hat[1] - 0.0 * eml_l2_hat[0];
        eml_y_0[0] = eml_y * eml_n1hat[0];
        eml_q1_mu_0[0] = eml_q1_mu * eml_n2hat[0];
        eml_t_0[0] = eml_t * eml_n3hat[0];
        eml_y_0[1] = eml_y * eml_n1hat[1];
        eml_q1_mu_0[1] = eml_q1_mu * eml_n2hat[1];
        eml_t_0[1] = eml_t * eml_n3hat[1];
        eml_y_0[2] = eml_y * eml_n1hat[2];
        eml_q1_mu_0[2] = eml_q1_mu * eml_n2hat[2];
        eml_t_0[2] = eml_t * eml_n3hat[2];
        tmp_f[0] = 0.0 * eml_l3_hat[2] - eml_l3_hat[1];
        tmp_f[1] = eml_l3_hat[0] - 0.0 * eml_l3_hat[2];
        tmp_f[2] = 0.0 * eml_l3_hat[1] - 0.0 * eml_l3_hat[0];
        eml_q1_mu = twa_parallel_eml_xdotu_b(eml_n1hat, eml_l1_hat) +
          twa_parallel_eml_xdotu_b(eml_y_0, tmp_d);
        eml_q2_mu = twa_parallel_eml_xdotu_b(eml_n2hat, eml_l2_hat) +
          twa_parallel_eml_xdotu_b(eml_q1_mu_0, tmp_e);
        eml_q3_mu = twa_parallel_eml_xdotu_b(eml_n3hat, eml_l3_hat) +
          twa_parallel_eml_xdotu_b(eml_t_0, tmp_f);
        for (uIdx = 0; uIdx < 3; uIdx++) {
          eml_iik_jac[3 * uIdx] = (real_T)tmp_r[3 * uIdx];
          eml_iik_jac[1 + 3 * uIdx] = (real_T)tmp_r[3 * uIdx + 1];
          eml_iik_jac[2 + 3 * uIdx] = (real_T)tmp_r[3 * uIdx + 2];
        }

        eml_iik_jac[9] = eml_q1_mu;
        eml_iik_jac[12] = 0.0;
        eml_iik_jac[15] = 0.0;
        eml_iik_jac[10] = 0.0;
        eml_iik_jac[13] = eml_q2_mu;
        eml_iik_jac[16] = 0.0;
        eml_iik_jac[11] = 0.0;
        eml_iik_jac[14] = 0.0;
        eml_iik_jac[17] = eml_q3_mu;

        /*  the full manipulator jacobian with redundancy resolution weighting */
        /* '<S25>:1:95' */
        for (uIdx = 0; uIdx < 3; uIdx++) {
          for (k = 0; k < 6; k++) {
            eml_iik_jac_3[k + 6 * uIdx] = eml_iik_jac[3 * k + uIdx];
          }
        }

        twa_parallel_mldivide_b(tmp_p, eml_iik_jac_3, eml_Y);
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
            eml_iik_jac_2[k + 6 * uIdx] = eml_iik_jac[3 * k + uIdx];
          }
        }

        twa_parallel_mldivide_b(tmp_p, eml_iik_jac_2, eml_Y);
        for (uIdx = 0; uIdx < 6; uIdx++) {
          eml_iik_jac[3 * uIdx] = eml_Y[uIdx];
          eml_iik_jac[1 + 3 * uIdx] = eml_Y[uIdx + 6];
          eml_iik_jac[2 + 3 * uIdx] = eml_Y[uIdx + 12];
        }

        uIdx = 1;
        k = 2;
        uIdx_0 = 3;
        eml_t = eml_r_cur[0];
        eml_y = fabs(eml_t);
        eml_t = eml_r_cur[1];
        eml_t = fabs(eml_t);
        if (eml_t > eml_y) {
          eml_y = eml_t;
          uIdx = 2;
          k = 1;
        }

        eml_t = eml_r_cur[2];
        if (fabs(eml_t) > eml_y) {
          uIdx = 3;
          k = 2;
          uIdx_0 = 1;
        }

        eml_r_cur[k - 1] /= eml_r_cur[uIdx - 1];
        eml_r_cur[uIdx_0 - 1] /= eml_r_cur[uIdx - 1];
        eml_r_cur[k + 2] -= eml_r_cur[k - 1] * eml_r_cur[uIdx + 2];
        eml_r_cur[uIdx_0 + 2] -= eml_r_cur[uIdx_0 - 1] * eml_r_cur[uIdx + 2];
        eml_r_cur[k + 5] -= eml_r_cur[k - 1] * eml_r_cur[uIdx + 5];
        eml_r_cur[uIdx_0 + 5] -= eml_r_cur[uIdx_0 - 1] * eml_r_cur[uIdx + 5];
        eml_t = eml_r_cur[uIdx_0 + 2];
        eml_y = eml_r_cur[k + 2];
        if (fabs(eml_t) > fabs(eml_y)) {
          eml_k = k;
          k = uIdx_0;
          uIdx_0 = eml_k;
        }

        eml_r_cur[uIdx_0 + 2] /= eml_r_cur[k + 2];
        eml_r_cur[uIdx_0 + 5] -= eml_r_cur[uIdx_0 + 2] * eml_r_cur[k + 5];
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_iik_jac_3[3 * eml_k] = eml_iik_jac[(uIdx - 1) + 3 * eml_k];
          eml_iik_jac_3[1 + 3 * eml_k] = eml_iik_jac[(k - 1) + 3 * eml_k] -
            eml_iik_jac_3[3 * eml_k] * eml_r_cur[k - 1];
          eml_iik_jac_3[2 + 3 * eml_k] = (eml_iik_jac[(uIdx_0 - 1) + 3 * eml_k]
            - eml_iik_jac_3[3 * eml_k] * eml_r_cur[uIdx_0 - 1]) - eml_iik_jac_3
            [3 * eml_k + 1] * eml_r_cur[uIdx_0 + 2];
          eml_iik_jac_3[2 + 3 * eml_k] = eml_iik_jac_3[3 * eml_k + 2] /
            eml_r_cur[uIdx_0 + 5];
          eml_iik_jac_3[3 * eml_k] -= eml_iik_jac_3[3 * eml_k + 2] *
            eml_r_cur[uIdx + 5];
          eml_iik_jac_3[1 + 3 * eml_k] = eml_iik_jac_3[3 * eml_k + 1] -
            eml_iik_jac_3[3 * eml_k + 2] * eml_r_cur[k + 5];
          eml_iik_jac_3[1 + 3 * eml_k] = eml_iik_jac_3[3 * eml_k + 1] /
            eml_r_cur[k + 2];
          eml_iik_jac_3[3 * eml_k] -= eml_iik_jac_3[3 * eml_k + 1] *
            eml_r_cur[uIdx + 2];
          eml_iik_jac_3[3 * eml_k] /= eml_r_cur[uIdx - 1];
        }

        /*  positional error direction */
        /* '<S25>:1:98' */
        /*  orientational error axis */
        if (eml_theta_e != 0.0) {
          /* '<S25>:1:101' */
          /* '<S25>:1:102' */
          eml_t = 1.0 / (2.0 * sin(eml_theta_e));
          eml_q1_mu = eml_r_del[5] - eml_r_del[7];
          eml_q2_mu = eml_r_del[6] - eml_r_del[2];
          eml_q3_mu = eml_r_del[1] - eml_r_del[3];
          eml_l1_hat[0] = eml_t * eml_q1_mu;
          eml_l1_hat[1] = eml_t * eml_q2_mu;
          eml_l1_hat[2] = eml_t * eml_q3_mu;
        } else {
          /* '<S25>:1:106' */
          eml_l1_hat[0] = 0.0;
          eml_l1_hat[1] = 0.0;
          eml_l1_hat[2] = 1.0;
        }

        /*  inverse kinematics based on pose error */
        /* '<S25>:1:110' */
        /* '<S25>:1:111' */
        /* '<S25>:1:112' */
        /* '<S25>:1:113' */
        /* '<S25>:1:114' */
        /* '<S25>:1:115' */
        /* '<S25>:1:116' */
        eml_t = 0.0;

        /* '<S25>:1:117' */
        eml_y = 0.0;
        if (eml_p_del != 0.0) {
          /* '<S25>:1:119' */
          if (eml_p_del / 0.01 <= 5.0) {
            /* '<S25>:1:120' */
            /* '<S25>:1:121' */
            eml_t = (eml_p_del - 0.01) * 4.9 / 0.04 + 0.1;
          } else {
            /* '<S25>:1:123' */
            eml_t = 5.0;
          }
        }

        if (eml_theta_e != 0.0) {
          /* '<S25>:1:127' */
          if ((eml_theta_e / 0.001 <= 2.0) && (eml_theta_e != 0.0)) {
            /* '<S25>:1:128' */
            /* '<S25>:1:129' */
            eml_y = (eml_theta_e - 0.001) * 0.49 / 0.001 + 0.01;
          } else {
            /* '<S25>:1:131' */
            eml_y = 0.5;
          }
        }

        /* '<S25>:1:135' */
        /* '<S25>:1:136' */
        eml_q1_mu = eml_l1_hat[0];
        twa_parallel_B.xcur[0] = (twa_parallel_P.x_des_Value[0] -
          twa_parallel_B.UnitDelay4[0]) / eml_p_del * eml_t;
        eml_q1_mu *= eml_y;
        eml_l1_hat[0] = eml_q1_mu;
        eml_q1_mu = eml_l1_hat[1];
        twa_parallel_B.xcur[1] = (twa_parallel_P.x_des_Value[1] -
          twa_parallel_B.UnitDelay4[1]) / eml_p_del * eml_t;
        eml_q1_mu *= eml_y;
        eml_l1_hat[1] = eml_q1_mu;
        eml_q1_mu = eml_l1_hat[2];
        twa_parallel_B.xcur[2] = (twa_parallel_P.x_des_Value[2] -
          twa_parallel_B.UnitDelay4[2]) / eml_p_del * eml_t;
        eml_q1_mu *= eml_y;
        eml_l1_hat[2] = eml_q1_mu;

        /* '<S25>:1:138' */
        /* '<S25>:1:139' */
        /* '<S25>:1:140' */
        eml_e_y_2[0] = eml_e_y[1] * eml_n1hat[2] - eml_e_y[2] * eml_n1hat[1];
        eml_e_y_2[1] = eml_e_y[2] * eml_n1hat[0] - eml_e_y[0] * eml_n1hat[2];
        eml_e_y_2[2] = eml_e_y[0] * eml_n1hat[1] - eml_e_y[1] * eml_n1hat[0];
        eml_f_y_2[0] = eml_f_y[1] * eml_n2hat[2] - eml_f_y[2] * eml_n2hat[1];
        eml_f_y_2[1] = eml_f_y[2] * eml_n2hat[0] - eml_f_y[0] * eml_n2hat[2];
        eml_f_y_2[2] = eml_f_y[0] * eml_n2hat[1] - eml_f_y[1] * eml_n2hat[0];
        eml_g_y_0[0] = eml_g_y[1] * eml_n3hat[2] - eml_g_y[2] * eml_n3hat[1];
        eml_g_y_0[1] = eml_g_y[2] * eml_n3hat[0] - eml_g_y[0] * eml_n3hat[2];
        eml_g_y_0[2] = eml_g_y[0] * eml_n3hat[1] - eml_g_y[1] * eml_n3hat[0];
        eml_q1_mu = twa_parallel_eml_xdotu_b(tmp_q, eml_e_y_2);
        eml_q2_mu = twa_parallel_eml_xdotu_b(tmp_q, eml_f_y_2);
        eml_q3_mu = twa_parallel_eml_xdotu_b(tmp_q, eml_g_y_0);
        eml_n1hat_0[0] = eml_n1hat[0];
        eml_n1hat_0[3] = eml_n1hat[1];
        eml_n1hat_0[6] = eml_q1_mu;
        eml_n1hat_0[1] = eml_n2hat[0];
        eml_n1hat_0[4] = eml_n2hat[1];
        eml_n1hat_0[7] = eml_q2_mu;
        eml_n1hat_0[2] = eml_n3hat[0];
        eml_n1hat_0[5] = eml_n3hat[1];
        eml_n1hat_0[8] = eml_q3_mu;
        eml_q2_mu = twa_parallel_B.xcur[0];
        eml_q3_mu = twa_parallel_B.xcur[1];
        eml_q1_mu = eml_l1_hat[2];
        for (uIdx = 0; uIdx < 6; uIdx++) {
          for (k = 0; k < 3; k++) {
            eml_Y[uIdx + 6 * k] = 0.0;
            eml_Y[uIdx + 6 * k] = eml_Y[6 * k + uIdx] + eml_iik_jac_3[3 * uIdx] *
              eml_n1hat_0[3 * k];
            eml_Y[uIdx + 6 * k] = eml_iik_jac_3[3 * uIdx + 1] * eml_n1hat_0[3 *
              k + 1] + eml_Y[6 * k + uIdx];
            eml_Y[uIdx + 6 * k] = eml_iik_jac_3[3 * uIdx + 2] * eml_n1hat_0[3 *
              k + 2] + eml_Y[6 * k + uIdx];
          }
        }

        for (uIdx = 0; uIdx < 6; uIdx++) {
          eml_scale = eml_Y[uIdx] * eml_q2_mu;
          eml_scale += eml_Y[uIdx + 6] * eml_q3_mu;
          eml_scale += eml_Y[uIdx + 12] * eml_q1_mu;
          twa_parallel_B.qdes[uIdx] = eml_scale * twa_parallel_P.dt_Value_n +
            twa_parallel_B.TmpSignalConversionAtSFunctionI[uIdx];
        }

        /* '<S25>:1:142' */
        twa_parallel_B.xcur[0] = twa_parallel_B.xcur[0] *
          twa_parallel_P.dt_Value_n + twa_parallel_B.UnitDelay4[0];
        twa_parallel_B.xcur[1] = twa_parallel_B.xcur[1] *
          twa_parallel_P.dt_Value_n + twa_parallel_B.UnitDelay4[1];
        twa_parallel_B.xcur[2] = twa_parallel_B.xcur[2] *
          twa_parallel_P.dt_Value_n + twa_parallel_B.UnitDelay4[2];

        /* '<S25>:1:143' */
        twa_parallel_B.eerot = eml_l1_hat[2] * twa_parallel_P.dt_Value_n +
          twa_parallel_B.UnitDelay3;
      } else {
        /* '<S25>:1:145' */
        for (uIdx = 0; uIdx < 6; uIdx++) {
          twa_parallel_B.qdes[uIdx] =
            twa_parallel_B.TmpSignalConversionAtSFunctionI[uIdx];
        }

        /* '<S25>:1:146' */
        /*  check this for angle or rotation matrix */
        /* '<S25>:1:148' */
      }
    }

    /* MultiPortSwitch: '<Root>/cntrl_switch' incorporates:
     *  Constant: '<Root>/cntrl_mode'
     *  Constant: '<Root>/q_des'
     */
    if ((int32_T)twa_parallel_P.cntrl_mode_Value == 1) {
      for (uIdx = 0; uIdx < 6; uIdx++) {
        twa_parallel_B.cntrl_switch[uIdx] = twa_parallel_P.q_des_Value[uIdx];
      }
    } else {
      for (uIdx = 0; uIdx < 6; uIdx++) {
        twa_parallel_B.cntrl_switch[uIdx] = twa_parallel_B.qdes[uIdx];
      }
    }

    /* DigitalClock: '<S4>/Digital Clock' */
    twa_parallel_B.DigitalClock = twa_parallel_rtM->Timing.t[1];

    /* UnitDelay: '<S4>/Unit Delay' */
    twa_parallel_B.UnitDelay = twa_parallel_DWork.UnitDelay_DSTATE;

    /* UnitDelay: '<S4>/Unit Delay1' */
    twa_parallel_B.UnitDelay1_b = twa_parallel_DWork.UnitDelay1_DSTATE_h;

    /* Signal Processing Blockset N-Sample Enable  (sdspnsamp2) - '<S20>/N-Sample Enable' */
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

    /* SignalConversion: '<S19>/TmpSignal ConversionAt SFunction Inport2' */
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[0] =
      twa_parallel_B.gear_ratio;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[1] =
      twa_parallel_B.gear_ratio_p;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[2] =
      twa_parallel_B.gear_ratio_c;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[3] =
      twa_parallel_B.gear_ratio_l;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[4] =
      twa_parallel_B.gear_ratio_j;
    twa_parallel_B.TmpSignalConversionAtSFunctio_c[5] =
      twa_parallel_B.gear_ratio_n;

    /* Embedded MATLAB: '<S4>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S4>/quintic_enable'
     *  Constant: '<S4>/tf'
     */
    /* Embedded MATLAB Function 'Quintic Poly/Embedded MATLAB Function': '<S19>:1' */
    /*  number of actuators */
    /* '<S19>:1:5' */
    twa_parallel_B.robot_mov = 0.0;

    /* '<S19>:1:6' */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* UnitDelay: '<S4>/Unit Delay2' */
      twa_parallel_B.UnitDelay2[uIdx] =
        twa_parallel_DWork.UnitDelay2_DSTATE[uIdx];

      /* Switch: '<S20>/Switch' */
      if (twa_parallel_B.NSampleEnable) {
        twa_parallel_B.Switch[uIdx] =
          twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx];
      } else {
        twa_parallel_B.Switch[uIdx] = twa_parallel_B.UnitDelay2[uIdx];
      }

      eml_eta[uIdx] = twa_parallel_B.cntrl_switch[uIdx] -
        twa_parallel_B.Switch[uIdx];
    }

    if (twa_parallel_P.quintic_enable_Value != 0.0) {
      for (uIdx = 0; uIdx < 6; uIdx++) {
        eml_a_0[uIdx] = eml_eta[uIdx];
      }

      eml_t = 0.0;
      eml_k = 1;
      uIdx = 1;
      for (k = 0; k < 6; k++) {
        eml_t += eml_a_0[eml_k - 1] * eml_eta[uIdx - 1];
        eml_k++;
        uIdx++;
      }

      if (eml_t > 0.0) {
        /* '<S19>:1:9' */
        /*  conf = 0 means that the 5th order poly */
        /*  is not configured for the desired trajectory. */
        /*  Therefore, the block is initialized. */
        if (twa_parallel_B.UnitDelay == 0.0) {
          /* '<S19>:1:13' */
          /* '<S19>:1:14' */
          /* '<S19>:1:15' */
          twa_parallel_B.t0n = twa_parallel_B.DigitalClock;

          /* '<S19>:1:16' */
          twa_parallel_B.confn = 1.0;

          /* '<S19>:1:17' */
          /* '<S19>:1:18' */
          /* '<S19>:1:19' */
          for (uIdx = 0; uIdx < 6; uIdx++) {
            twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch[uIdx];
            twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.Switch[uIdx];
            twa_parallel_B.q_dot[uIdx] = 0.0;
            twa_parallel_B.q_dub_dot[uIdx] = 0.0;
          }
        } else {
          /* '<S19>:1:21' */
          /* '<S19>:1:22' */
          twa_parallel_B.t0n = twa_parallel_B.UnitDelay1_b;

          /* '<S19>:1:23' */
          twa_parallel_B.confn = twa_parallel_B.UnitDelay;

          /*  5th order polynomial */
          /* '<S19>:1:27' */
          /* '<S19>:1:28' */
          /* '<S19>:1:29' */
          for (uIdx = 0; uIdx < 6; uIdx++) {
            eml_q1_mu = eml_eta[uIdx];
            twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch[uIdx];
            eml_q1_mu *= -15.0;
            twa_parallel_B.q_dub_dot[uIdx] = -6.6666666666666663E-001 *
              eml_q1_mu;
            eml_a_0[uIdx] = -0.4 * eml_q1_mu;
            eml_eta[uIdx] = eml_q1_mu;
          }

          /* '<S19>:1:30' */
          eml_c_0 = twa_parallel_B.DigitalClock - twa_parallel_B.UnitDelay1_b;

          /* '<S19>:1:31' */
          eml_t = eml_c_0 / twa_parallel_P.tf_Value;
          if (eml_c_0 < twa_parallel_P.tf_Value) {
            /* '<S19>:1:33' */
            /* '<S19>:1:34' */
            twa_parallel_B.robot_mov = 1.0;

            /* '<S19>:1:35' */
            eml_y = rt_pow_snf(eml_t, 3.0);
            eml_q1_mu = rt_pow_snf(eml_t, 4.0);
            eml_t = rt_pow_snf(eml_t, 5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_cmd[uIdx] = ((twa_parallel_B.q_dub_dot[uIdx] *
                eml_y + twa_parallel_B.Switch[uIdx]) + eml_eta[uIdx] * eml_q1_mu)
                + eml_a_0[uIdx] * eml_t;
            }

            /* '<S19>:1:36' */
            eml_t = rt_pow_snf(eml_c_0, 2.0);
            eml_q1_mu = rt_pow_snf(twa_parallel_P.tf_Value, 3.0);
            eml_c = rt_pow_snf(eml_c_0, 3.0);
            eml_y = rt_pow_snf(twa_parallel_P.tf_Value, 4.0);
            eml_scale = rt_pow_snf(eml_c_0, 4.0);
            eml_a = rt_pow_snf(twa_parallel_P.tf_Value, 5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_dot[uIdx] = (3.0 * twa_parallel_B.q_dub_dot[uIdx]
                * eml_t / eml_q1_mu + 4.0 * eml_eta[uIdx] * eml_c / eml_y) + 5.0
                * eml_a_0[uIdx] * eml_scale / eml_a;
            }

            /* '<S19>:1:37' */
            eml_t = rt_pow_snf(twa_parallel_P.tf_Value, 3.0);
            eml_q1_mu = rt_pow_snf(eml_c_0, 2.0);
            eml_y = rt_pow_snf(twa_parallel_P.tf_Value, 4.0);
            eml_scale = rt_pow_snf(eml_c_0, 3.0);
            eml_c = rt_pow_snf(twa_parallel_P.tf_Value, 5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_dub_dot[uIdx] = (6.0 *
                twa_parallel_B.q_dub_dot[uIdx] * eml_c_0 / eml_t + 12.0 *
                eml_eta[uIdx] * eml_q1_mu / eml_y) + 20.0 * eml_a_0[uIdx] *
                eml_scale / eml_c;
            }
          } else {
            /* '<S19>:1:39' */
            /* '<S19>:1:40' */
            /* '<S19>:1:41' */
            /* '<S19>:1:42' */
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.cntrl_switch[uIdx];
              twa_parallel_B.q_dot[uIdx] = 0.0;
              twa_parallel_B.q_dub_dot[uIdx] = 0.0;
              twa_parallel_B.q0n[uIdx] = twa_parallel_B.cntrl_switch[uIdx];
            }
          }
        }
      } else {
        /* '<S19>:1:46' */
        /* '<S19>:1:47' */
        /* '<S19>:1:48' */
        /* '<S19>:1:49' */
        twa_parallel_B.confn = 0.0;

        /* '<S19>:1:50' */
        for (uIdx = 0; uIdx < 6; uIdx++) {
          twa_parallel_B.q_cmd[uIdx] = twa_parallel_B.cntrl_switch[uIdx];
          twa_parallel_B.q_dot[uIdx] = 0.0;
          twa_parallel_B.q_dub_dot[uIdx] = 0.0;
          twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch[uIdx];
        }

        /* '<S19>:1:51' */
        twa_parallel_B.t0n = twa_parallel_B.UnitDelay1_b;
      }
    } else {
      /*  Configuration space is not used (pdot = 0). */
      /* '<S19>:1:55' */
      /* '<S19>:1:56' */
      /* '<S19>:1:57' */
      /*  However we do want to record the current */
      /* '<S19>:1:58' */
      twa_parallel_B.confn = 0.0;

      /*  position in order to be ready as soon */
      /* '<S19>:1:59' */
      twa_parallel_B.t0n = twa_parallel_B.DigitalClock;

      /*  as the enable becomes 1. */
      /* '<S19>:1:60' */
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
      /* Sum: '<S3>/Sum' */
      twa_parallel_B.Sum[uIdx] = twa_parallel_B.q_cmd[uIdx] -
        twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx];

      /* Gain: '<S3>/Kp' */
      twa_parallel_B.Kp[uIdx] = twa_parallel_P.Kp_Gain[uIdx] *
        twa_parallel_B.Sum[uIdx];
    }
  }

  /* Integrator: '<S3>/Integrator' */
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
      /* Saturate: '<S3>/Saturation' incorporates:
       *  Saturate: '<S3>/saturate_int'
       */

      /* Gain: '<S3>/Ki' */
      twa_parallel_B.Ki[uIdx] = twa_parallel_P.Ki_Gain[uIdx] *
        twa_parallel_B.Integrator[uIdx];
      eml_q1_mu = twa_parallel_B.Ki[uIdx];
      twa_parallel_B.saturate_int[uIdx] = rt_SATURATE(eml_q1_mu,
        twa_parallel_P.saturate_int_LowerSat[uIdx],
        twa_parallel_P.saturate_int_UpperSat[uIdx]);

      /* SampleTimeMath: '<S17>/TSamp'
       *
       * About '<S17>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      twa_parallel_B.TSamp_h[uIdx] = twa_parallel_B.Sum[uIdx] *
        twa_parallel_P.TSamp_WtEt_p;

      /* UnitDelay: '<S17>/UD' */
      twa_parallel_B.Uk1_j[uIdx] = twa_parallel_DWork.UD_DSTATE_o[uIdx];

      /* Sum: '<S17>/Diff' */
      twa_parallel_B.Diff_d[uIdx] = twa_parallel_B.TSamp_h[uIdx] -
        twa_parallel_B.Uk1_j[uIdx];

      /* Gain: '<S3>/Kd' */
      twa_parallel_B.Kd[uIdx] = twa_parallel_P.Kd_Gain[uIdx] *
        twa_parallel_B.Diff_d[uIdx];

      /* Sum: '<S3>/Add' */
      twa_parallel_B.Add[uIdx] = (twa_parallel_B.Kp[uIdx] +
        twa_parallel_B.saturate_int[uIdx]) + twa_parallel_B.Kd[uIdx];
      eml_q1_mu = twa_parallel_B.Add[uIdx];
      twa_parallel_B.Saturation[uIdx] = rt_SATURATE(eml_q1_mu,
        twa_parallel_P.Saturation_LowerSat[uIdx],
        twa_parallel_P.Saturation_UpperSat[uIdx]);

      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/manual_current'
       *  Constant: '<S3>/pid_mode'
       */
      if (twa_parallel_P.pid_mode_Value != 0.0) {
        twa_parallel_B.Switch_i[uIdx] = twa_parallel_B.Saturation[uIdx];
      } else {
        twa_parallel_B.Switch_i[uIdx] = twa_parallel_P.manual_current_Value[uIdx];
      }
    }

    /* ok to acquire for <S26>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_a.AcquireOK = 1;

    /* Constant: '<S6>/t_in_w' */
    memcpy((void *)(&twa_parallel_B.t_in_w[0]), (void *)
           (&twa_parallel_P.t_in_w_Value[0]), 9U * sizeof(real_T));

    /* Constant: '<S6>/twa_gamma' */
    twa_parallel_B.twa_gamma = twa_parallel_P.twa_gamma_Value;

    /* Constant: '<S6>/use_twa' */
    twa_parallel_B.use_twa = twa_parallel_P.use_twa_Value;

    /* Constant: '<S6>/twa_flange_offset' */
    twa_parallel_B.twa_flange_offset = twa_parallel_P.twa_flange_offset_Value;

    /* SignalConversion: '<Root>/HiddenBuf_InsertedFor_Homing_at_inport_1' incorporates:
     *  Constant: '<Root>/do_homing'
     */
    twa_parallel_B.HiddenBuf_InsertedFor_Homing_at =
      twa_parallel_P.do_homing_Value;

    /* Outputs for enable SubSystem: '<Root>/Homing' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    if (twa_parallel_B.HiddenBuf_InsertedFor_Homing_at > 0.0) {
      /* UnitDelay: '<S2>/Unit Delay1' */
      twa_parallel_B.UnitDelay1_p[0] = twa_parallel_DWork.UnitDelay1_DSTATE_f[0];

      /* UnitDelay: '<S2>/Unit Delay4' */
      twa_parallel_B.UnitDelay4_e[0] = twa_parallel_DWork.UnitDelay4_DSTATE_g[0];

      /* UnitDelay: '<S2>/Unit Delay3' */
      twa_parallel_B.UnitDelay3_b[0] = twa_parallel_DWork.UnitDelay3_DSTATE_e[0];

      /* UnitDelay: '<S2>/Unit Delay1' */
      twa_parallel_B.UnitDelay1_p[1] = twa_parallel_DWork.UnitDelay1_DSTATE_f[1];

      /* UnitDelay: '<S2>/Unit Delay4' */
      twa_parallel_B.UnitDelay4_e[1] = twa_parallel_DWork.UnitDelay4_DSTATE_g[1];

      /* UnitDelay: '<S2>/Unit Delay3' */
      twa_parallel_B.UnitDelay3_b[1] = twa_parallel_DWork.UnitDelay3_DSTATE_e[1];

      /* UnitDelay: '<S2>/Unit Delay1' */
      twa_parallel_B.UnitDelay1_p[2] = twa_parallel_DWork.UnitDelay1_DSTATE_f[2];

      /* UnitDelay: '<S2>/Unit Delay4' */
      twa_parallel_B.UnitDelay4_e[2] = twa_parallel_DWork.UnitDelay4_DSTATE_g[2];

      /* UnitDelay: '<S2>/Unit Delay3' */
      twa_parallel_B.UnitDelay3_b[2] = twa_parallel_DWork.UnitDelay3_DSTATE_e[2];

      /* UnitDelay: '<S2>/Unit Delay2' */
      memcpy((void *)(&twa_parallel_B.UnitDelay2_j[0]), (void *)
             (&twa_parallel_DWork.UnitDelay2_DSTATE_l[0]), 9U * sizeof(real_T));

      /* Embedded MATLAB: '<S2>/Homing' incorporates:
       *  Constant: '<S2>/b_in_w'
       *  Constant: '<S2>/dt'
       *  Constant: '<S2>/eq_eps'
       *  Constant: '<S2>/f_in_w'
       *  Constant: '<S2>/kp'
       *  Constant: '<S2>/m_in_w'
       *  Constant: '<S2>/meas_macro_len'
       *  Constant: '<S2>/p_in_m'
       *  Constant: '<S2>/velmex_pitch'
       */
      twa_parallel_B.twave_out[0] = twa_parallel_B.UnitDelay3_b[0];
      twa_parallel_B.twave_out[1] = twa_parallel_B.UnitDelay3_b[1];
      twa_parallel_B.twave_out[2] = twa_parallel_B.UnitDelay3_b[2];

      /* Embedded MATLAB Function 'Homing/Homing': '<S16>:1' */
      /* '<S16>:1:5' */
      twa_parallel_B.qcmd = 0.0;

      /*  moving platform vertex locations */
      /* '<S16>:1:10' */
      for (uIdx = 0; uIdx < 3; uIdx++) {
        eml_n1hat_0[uIdx] = 0.0;
        eml_n1hat_0[uIdx] += twa_parallel_B.UnitDelay3_b[uIdx];
        eml_n1hat_0[uIdx + 3] = 0.0;
        eml_n1hat_0[uIdx + 3] += twa_parallel_B.UnitDelay3_b[uIdx];
        eml_n1hat_0[uIdx + 6] = 0.0;
        eml_n1hat_0[uIdx + 6] += twa_parallel_B.UnitDelay3_b[uIdx];
      }

      for (uIdx = 0; uIdx < 3; uIdx++) {
        for (k = 0; k < 3; k++) {
          eml_r_cur_1[uIdx + 3 * k] = 0.0;
          eml_r_cur_1[uIdx + 3 * k] = eml_r_cur_1[3 * k + uIdx] +
            twa_parallel_P.p_in_m_Value[3 * k] *
            twa_parallel_B.UnitDelay2_j[uIdx];
          eml_r_cur_1[uIdx + 3 * k] = twa_parallel_P.p_in_m_Value[3 * k + 1] *
            twa_parallel_B.UnitDelay2_j[uIdx + 3] + eml_r_cur_1[3 * k + uIdx];
          eml_r_cur_1[uIdx + 3 * k] = twa_parallel_P.p_in_m_Value[3 * k + 2] *
            twa_parallel_B.UnitDelay2_j[uIdx + 6] + eml_r_cur_1[3 * k + uIdx];
        }
      }

      for (uIdx = 0; uIdx < 3; uIdx++) {
        eml_r_cur[3 * uIdx] = eml_n1hat_0[3 * uIdx] + eml_r_cur_1[3 * uIdx];
        eml_r_cur[1 + 3 * uIdx] = eml_n1hat_0[3 * uIdx + 1] + eml_r_cur_1[3 *
          uIdx + 1];
        eml_r_cur[2 + 3 * uIdx] = eml_n1hat_0[3 * uIdx + 2] + eml_r_cur_1[3 *
          uIdx + 2];
      }

      if (twa_parallel_norm(&twa_parallel_B.UnitDelay4_e[0]) >
          twa_parallel_P.eq_eps_Value) {
        /* '<S16>:1:12' */
        /*     %% instantaneous direct kinematics jacobian */
        /*  vector from base vertex to moving platform vertex */
        /* '<S16>:1:15' */
        tmp_c[0] = twa_parallel_P.b_in_w_Value[0] - eml_r_cur[0];
        tmp_c[1] = twa_parallel_P.b_in_w_Value[1] - eml_r_cur[1];
        tmp_c[2] = twa_parallel_P.b_in_w_Value[2] - eml_r_cur[2];
        eml_t = twa_parallel_norm(tmp_c);

        /* '<S16>:1:16' */
        eml_n1hat[0] = (eml_r_cur[0] - twa_parallel_P.b_in_w_Value[0]) / eml_t;
        tmp_b[0] = twa_parallel_P.b_in_w_Value[3] - eml_r_cur[3];
        eml_n1hat[1] = (eml_r_cur[1] - twa_parallel_P.b_in_w_Value[1]) / eml_t;
        tmp_b[1] = twa_parallel_P.b_in_w_Value[4] - eml_r_cur[4];
        eml_n1hat[2] = (eml_r_cur[2] - twa_parallel_P.b_in_w_Value[2]) / eml_t;
        tmp_b[2] = twa_parallel_P.b_in_w_Value[5] - eml_r_cur[5];
        eml_t = twa_parallel_norm(tmp_b);

        /* '<S16>:1:17' */
        eml_n2hat[0] = (eml_r_cur[3] - twa_parallel_P.b_in_w_Value[3]) / eml_t;
        tmp_a[0] = twa_parallel_P.b_in_w_Value[6] - eml_r_cur[6];
        eml_n2hat[1] = (eml_r_cur[4] - twa_parallel_P.b_in_w_Value[4]) / eml_t;
        tmp_a[1] = twa_parallel_P.b_in_w_Value[7] - eml_r_cur[7];
        eml_n2hat[2] = (eml_r_cur[5] - twa_parallel_P.b_in_w_Value[5]) / eml_t;
        tmp_a[2] = twa_parallel_P.b_in_w_Value[8] - eml_r_cur[8];
        eml_t = twa_parallel_norm(tmp_a);

        /* '<S16>:1:19' */
        /* '<S16>:1:20' */
        /* '<S16>:1:21' */
        /* '<S16>:1:23' */
        /*     %% instantaneous inverse kinematics jacobian */
        /*  micro actuator (TWA) lengths */
        /* '<S16>:1:29' */
        for (uIdx = 0; uIdx < 3; uIdx++) {
          eml_n3hat[uIdx] = (eml_r_cur[6 + uIdx] - twa_parallel_P.b_in_w_Value[6
                             + uIdx]) / eml_t;
          eml_q1_mu = twa_parallel_B.UnitDelay2_j[uIdx] *
            twa_parallel_P.p_in_m_Value[0];
          eml_q1_mu += twa_parallel_B.UnitDelay2_j[uIdx + 3] *
            twa_parallel_P.p_in_m_Value[1];
          eml_q1_mu += twa_parallel_B.UnitDelay2_j[uIdx + 6] *
            twa_parallel_P.p_in_m_Value[2];
          eml_q2_mu = twa_parallel_B.UnitDelay2_j[uIdx] *
            twa_parallel_P.p_in_m_Value[3];
          eml_q2_mu += twa_parallel_B.UnitDelay2_j[uIdx + 3] *
            twa_parallel_P.p_in_m_Value[4];
          eml_q2_mu += twa_parallel_B.UnitDelay2_j[uIdx + 6] *
            twa_parallel_P.p_in_m_Value[5];
          eml_q3_mu = twa_parallel_B.UnitDelay2_j[uIdx] *
            twa_parallel_P.p_in_m_Value[6];
          eml_q3_mu += twa_parallel_B.UnitDelay2_j[uIdx + 3] *
            twa_parallel_P.p_in_m_Value[7];
          eml_q3_mu += twa_parallel_B.UnitDelay2_j[uIdx + 6] *
            twa_parallel_P.p_in_m_Value[8];
          eml_y_0[uIdx] = twa_parallel_P.b_in_w_Value[uIdx] -
            twa_parallel_P.m_in_w_Value[uIdx];
          eml_q1_mu_0[uIdx] = twa_parallel_P.b_in_w_Value[3 + uIdx] -
            twa_parallel_P.m_in_w_Value[3 + uIdx];
          eml_t_0[uIdx] = twa_parallel_P.b_in_w_Value[6 + uIdx] -
            twa_parallel_P.m_in_w_Value[6 + uIdx];
          tmp_o[uIdx] = twa_parallel_P.m_in_w_Value[uIdx] -
            twa_parallel_P.b_in_w_Value[uIdx];
          eml_f_y_0[uIdx] = eml_q3_mu;
          eml_e_y_0[uIdx] = eml_q2_mu;
          eml_d_y[uIdx] = eml_q1_mu;
        }

        eml_q1_mu = twa_parallel_norm(eml_y_0);

        /* '<S16>:1:30' */
        eml_q2_mu = twa_parallel_norm(eml_q1_mu_0);

        /* '<S16>:1:31' */
        eml_q3_mu = twa_parallel_norm(eml_t_0);

        /*  vector from base vertex to twa motor attachment point */
        /* '<S16>:1:34' */
        eml_t = twa_parallel_norm(tmp_o);

        /* '<S16>:1:35' */
        eml_e_y[0] = (twa_parallel_P.m_in_w_Value[0] -
                      twa_parallel_P.b_in_w_Value[0]) / eml_t;
        tmp_9[0] = twa_parallel_P.m_in_w_Value[3] - twa_parallel_P.b_in_w_Value
          [3];
        eml_e_y[1] = (twa_parallel_P.m_in_w_Value[1] -
                      twa_parallel_P.b_in_w_Value[1]) / eml_t;
        tmp_9[1] = twa_parallel_P.m_in_w_Value[4] - twa_parallel_P.b_in_w_Value
          [4];
        eml_e_y[2] = (twa_parallel_P.m_in_w_Value[2] -
                      twa_parallel_P.b_in_w_Value[2]) / eml_t;
        tmp_9[2] = twa_parallel_P.m_in_w_Value[5] - twa_parallel_P.b_in_w_Value
          [5];
        eml_t = twa_parallel_norm(tmp_9);

        /* '<S16>:1:36' */
        eml_f_y[0] = (twa_parallel_P.m_in_w_Value[3] -
                      twa_parallel_P.b_in_w_Value[3]) / eml_t;
        tmp_8[0] = twa_parallel_P.m_in_w_Value[6] - twa_parallel_P.b_in_w_Value
          [6];
        eml_f_y[1] = (twa_parallel_P.m_in_w_Value[4] -
                      twa_parallel_P.b_in_w_Value[4]) / eml_t;
        tmp_8[1] = twa_parallel_P.m_in_w_Value[7] - twa_parallel_P.b_in_w_Value
          [7];
        eml_f_y[2] = (twa_parallel_P.m_in_w_Value[5] -
                      twa_parallel_P.b_in_w_Value[5]) / eml_t;
        tmp_8[2] = twa_parallel_P.m_in_w_Value[8] - twa_parallel_P.b_in_w_Value
          [8];
        eml_t = twa_parallel_norm(tmp_8);

        /*  distance from micro actuator attachmnet point (m_i) to flexure rotation */
        /* center (f_i) */
        /* '<S16>:1:40' */
        eml_g_y[0] = (twa_parallel_P.m_in_w_Value[6] -
                      twa_parallel_P.b_in_w_Value[6]) / eml_t;
        tmp_7[0] = twa_parallel_P.m_in_w_Value[0] - twa_parallel_P.f_in_w_Value
          [0];
        tmp_6[0] = twa_parallel_P.m_in_w_Value[3] - twa_parallel_P.f_in_w_Value
          [3];
        tmp_5[0] = twa_parallel_P.m_in_w_Value[6] - twa_parallel_P.f_in_w_Value
          [6];
        tmp_4[0] = twa_parallel_P.b_in_w_Value[0] - twa_parallel_P.f_in_w_Value
          [0];
        tmp_3[0] = twa_parallel_P.b_in_w_Value[3] - twa_parallel_P.f_in_w_Value
          [3];
        tmp_2[0] = twa_parallel_P.b_in_w_Value[6] - twa_parallel_P.f_in_w_Value
          [6];
        eml_g_y[1] = (twa_parallel_P.m_in_w_Value[7] -
                      twa_parallel_P.b_in_w_Value[7]) / eml_t;
        tmp_7[1] = twa_parallel_P.m_in_w_Value[1] - twa_parallel_P.f_in_w_Value
          [1];
        tmp_6[1] = twa_parallel_P.m_in_w_Value[4] - twa_parallel_P.f_in_w_Value
          [4];
        tmp_5[1] = twa_parallel_P.m_in_w_Value[7] - twa_parallel_P.f_in_w_Value
          [7];
        tmp_4[1] = twa_parallel_P.b_in_w_Value[1] - twa_parallel_P.f_in_w_Value
          [1];
        tmp_3[1] = twa_parallel_P.b_in_w_Value[4] - twa_parallel_P.f_in_w_Value
          [4];
        tmp_2[1] = twa_parallel_P.b_in_w_Value[7] - twa_parallel_P.f_in_w_Value
          [7];
        eml_g_y[2] = (twa_parallel_P.m_in_w_Value[8] -
                      twa_parallel_P.b_in_w_Value[8]) / eml_t;
        tmp_7[2] = twa_parallel_P.m_in_w_Value[2] - twa_parallel_P.f_in_w_Value
          [2];
        tmp_6[2] = twa_parallel_P.m_in_w_Value[5] - twa_parallel_P.f_in_w_Value
          [5];
        tmp_5[2] = twa_parallel_P.m_in_w_Value[8] - twa_parallel_P.f_in_w_Value
          [8];
        tmp_4[2] = twa_parallel_P.b_in_w_Value[2] - twa_parallel_P.f_in_w_Value
          [2];
        tmp_3[2] = twa_parallel_P.b_in_w_Value[5] - twa_parallel_P.f_in_w_Value
          [5];
        tmp_2[2] = twa_parallel_P.b_in_w_Value[8] - twa_parallel_P.f_in_w_Value
          [8];
        eml_t = twa_parallel_norm(tmp_7);

        /* '<S16>:1:41' */
        eml_scale = twa_parallel_norm(tmp_6);

        /* '<S16>:1:42' */
        eml_a = twa_parallel_norm(tmp_5);

        /*  distance from flexure rotation center (f_i) to base vertex */
        /* '<S16>:1:45' */
        eml_y = twa_parallel_norm(tmp_4);

        /* '<S16>:1:46' */
        eml_c = twa_parallel_norm(tmp_3);

        /* '<S16>:1:47' */
        eml_c_0 = twa_parallel_norm(tmp_2);

        /*  term to paramterize angle between a_i and qimu, delta */
        /* '<S16>:1:50' */
        /* '<S16>:1:51' */
        /* '<S16>:1:52' */
        /*  time derivatives */
        /* '<S16>:1:55' */
        /* '<S16>:1:56' */
        /* '<S16>:1:57' */
        /* '<S16>:1:59' */
        eml_y = (((rt_pow_snf(eml_y, 2.0) - rt_pow_snf(eml_t, 2.0)) - rt_pow_snf
                  (eml_q1_mu, 2.0)) * 2.0 * eml_t + 4.0 * eml_t * rt_pow_snf
                 (eml_q1_mu, 2.0)) / (4.0 * rt_pow_snf(eml_t, 2.0) * rt_pow_snf
          (eml_q1_mu, 2.0)) * eml_q1_mu / sqrt(1.0 - rt_pow_snf(((rt_pow_snf
          (eml_y, 2.0) - rt_pow_snf(eml_t, 2.0)) - rt_pow_snf(eml_q1_mu, 2.0)) /
          (-2.0 * eml_t * eml_q1_mu), 2.0));

        /* '<S16>:1:60' */
        eml_q1_mu = (((rt_pow_snf(eml_c, 2.0) - rt_pow_snf(eml_scale, 2.0)) -
                      rt_pow_snf(eml_q2_mu, 2.0)) * 2.0 * eml_scale + 4.0 *
                     eml_scale * rt_pow_snf(eml_q2_mu, 2.0)) / (4.0 * rt_pow_snf
          (eml_scale, 2.0) * rt_pow_snf(eml_q2_mu, 2.0)) * eml_q2_mu / sqrt(1.0
          - rt_pow_snf(((rt_pow_snf(eml_c, 2.0) - rt_pow_snf(eml_scale, 2.0)) -
                        rt_pow_snf(eml_q2_mu, 2.0)) / (-2.0 * eml_scale *
          eml_q2_mu), 2.0));

        /* '<S16>:1:61' */
        eml_t = (((rt_pow_snf(eml_c_0, 2.0) - rt_pow_snf(eml_a, 2.0)) -
                  rt_pow_snf(eml_q3_mu, 2.0)) * 2.0 * eml_a + 4.0 * eml_a *
                 rt_pow_snf(eml_q3_mu, 2.0)) / (4.0 * rt_pow_snf(eml_a, 2.0) *
          rt_pow_snf(eml_q3_mu, 2.0)) * eml_q3_mu / sqrt(1.0 - rt_pow_snf
          (((rt_pow_snf(eml_c_0, 2.0) - rt_pow_snf(eml_a, 2.0)) - rt_pow_snf
            (eml_q3_mu, 2.0)) / (-2.0 * eml_a * eml_q3_mu), 2.0));

        /*  micro motion instantaneous inverse kinematics jacobian */
        /* '<S16>:1:64' */
        /*  macro motion instantaneous inverse kinematics jacobian */
        /* '<S16>:1:69' */
        /*  combined macro-micro motion IIK jacobian */
        /* '<S16>:1:72' */
        tmp[0] = 0.0 * eml_e_y[2] - eml_e_y[1];
        tmp[1] = eml_e_y[0] - 0.0 * eml_e_y[2];
        tmp[2] = 0.0 * eml_e_y[1] - 0.0 * eml_e_y[0];
        tmp_0[0] = 0.0 * eml_f_y[2] - eml_f_y[1];
        tmp_0[1] = eml_f_y[0] - 0.0 * eml_f_y[2];
        tmp_0[2] = 0.0 * eml_f_y[1] - 0.0 * eml_f_y[0];
        eml_y_0[0] = eml_y * eml_n1hat[0];
        eml_q1_mu_0[0] = eml_q1_mu * eml_n2hat[0];
        eml_t_0[0] = eml_t * eml_n3hat[0];
        eml_y_0[1] = eml_y * eml_n1hat[1];
        eml_q1_mu_0[1] = eml_q1_mu * eml_n2hat[1];
        eml_t_0[1] = eml_t * eml_n3hat[1];
        eml_y_0[2] = eml_y * eml_n1hat[2];
        eml_q1_mu_0[2] = eml_q1_mu * eml_n2hat[2];
        eml_t_0[2] = eml_t * eml_n3hat[2];
        tmp_1[0] = 0.0 * eml_g_y[2] - eml_g_y[1];
        tmp_1[1] = eml_g_y[0] - 0.0 * eml_g_y[2];
        tmp_1[2] = 0.0 * eml_g_y[1] - 0.0 * eml_g_y[0];
        eml_q1_mu = twa_parallel_eml_xdotu(eml_n1hat, eml_e_y) +
          twa_parallel_eml_xdotu(eml_y_0, tmp);
        eml_q2_mu = twa_parallel_eml_xdotu(eml_n2hat, eml_f_y) +
          twa_parallel_eml_xdotu(eml_q1_mu_0, tmp_0);
        eml_q3_mu = twa_parallel_eml_xdotu(eml_n3hat, eml_g_y) +
          twa_parallel_eml_xdotu(eml_t_0, tmp_1);
        for (uIdx = 0; uIdx < 3; uIdx++) {
          eml_iik_jac[3 * uIdx] = (real_T)tmp_r[3 * uIdx];
          eml_iik_jac[1 + 3 * uIdx] = (real_T)tmp_r[3 * uIdx + 1];
          eml_iik_jac[2 + 3 * uIdx] = (real_T)tmp_r[3 * uIdx + 2];
        }

        eml_iik_jac[9] = eml_q1_mu;
        eml_iik_jac[12] = 0.0;
        eml_iik_jac[15] = 0.0;
        eml_iik_jac[10] = 0.0;
        eml_iik_jac[13] = eml_q2_mu;
        eml_iik_jac[16] = 0.0;
        eml_iik_jac[11] = 0.0;
        eml_iik_jac[14] = 0.0;
        eml_iik_jac[17] = eml_q3_mu;

        /*  the full manipulator jacobian with redundancy resolution weighting */
        /* '<S16>:1:76' */
        for (uIdx = 0; uIdx < 3; uIdx++) {
          for (k = 0; k < 6; k++) {
            eml_iik_jac_1[k + 6 * uIdx] = eml_iik_jac[3 * k + uIdx];
          }
        }

        twa_parallel_mldivide(tmp_p, eml_iik_jac_1, eml_Y);
        for (uIdx = 0; uIdx < 3; uIdx++) {
          for (k = 0; k < 3; k++) {
            eml_r_del[uIdx + 3 * k] = 0.0;
            for (uIdx_0 = 0; uIdx_0 < 6; uIdx_0++) {
              eml_r_del[uIdx + 3 * k] = eml_Y[6 * k + uIdx_0] * eml_iik_jac[3 *
                uIdx_0 + uIdx] + eml_r_del[3 * k + uIdx];
            }
          }
        }

        for (uIdx = 0; uIdx < 3; uIdx++) {
          for (k = 0; k < 6; k++) {
            eml_iik_jac_0[k + 6 * uIdx] = eml_iik_jac[3 * k + uIdx];
          }
        }

        twa_parallel_mldivide(tmp_p, eml_iik_jac_0, eml_Y);
        for (uIdx = 0; uIdx < 6; uIdx++) {
          eml_iik_jac[3 * uIdx] = eml_Y[uIdx];
          eml_iik_jac[1 + 3 * uIdx] = eml_Y[uIdx + 6];
          eml_iik_jac[2 + 3 * uIdx] = eml_Y[uIdx + 12];
        }

        uIdx = 1;
        k = 2;
        uIdx_0 = 3;
        eml_t = eml_r_del[0];
        eml_y = fabs(eml_t);
        eml_t = eml_r_del[1];
        eml_t = fabs(eml_t);
        if (eml_t > eml_y) {
          eml_y = eml_t;
          uIdx = 2;
          k = 1;
        }

        eml_t = eml_r_del[2];
        if (fabs(eml_t) > eml_y) {
          uIdx = 3;
          k = 2;
          uIdx_0 = 1;
        }

        eml_r_del[k - 1] /= eml_r_del[uIdx - 1];
        eml_r_del[uIdx_0 - 1] /= eml_r_del[uIdx - 1];
        eml_r_del[k + 2] -= eml_r_del[k - 1] * eml_r_del[uIdx + 2];
        eml_r_del[uIdx_0 + 2] -= eml_r_del[uIdx_0 - 1] * eml_r_del[uIdx + 2];
        eml_r_del[k + 5] -= eml_r_del[k - 1] * eml_r_del[uIdx + 5];
        eml_r_del[uIdx_0 + 5] -= eml_r_del[uIdx_0 - 1] * eml_r_del[uIdx + 5];
        eml_t = eml_r_del[uIdx_0 + 2];
        eml_y = eml_r_del[k + 2];
        if (fabs(eml_t) > fabs(eml_y)) {
          eml_k = k;
          k = uIdx_0;
          uIdx_0 = eml_k;
        }

        eml_r_del[uIdx_0 + 2] /= eml_r_del[k + 2];
        eml_r_del[uIdx_0 + 5] -= eml_r_del[uIdx_0 + 2] * eml_r_del[k + 5];
        for (eml_k = 0; eml_k < 6; eml_k++) {
          eml_iik_jac_3[3 * eml_k] = eml_iik_jac[(uIdx - 1) + 3 * eml_k];
          eml_iik_jac_3[1 + 3 * eml_k] = eml_iik_jac[(k - 1) + 3 * eml_k] -
            eml_iik_jac_3[3 * eml_k] * eml_r_del[k - 1];
          eml_iik_jac_3[2 + 3 * eml_k] = (eml_iik_jac[(uIdx_0 - 1) + 3 * eml_k]
            - eml_iik_jac_3[3 * eml_k] * eml_r_del[uIdx_0 - 1]) - eml_iik_jac_3
            [3 * eml_k + 1] * eml_r_del[uIdx_0 + 2];
          eml_iik_jac_3[2 + 3 * eml_k] = eml_iik_jac_3[3 * eml_k + 2] /
            eml_r_del[uIdx_0 + 5];
          eml_iik_jac_3[3 * eml_k] -= eml_iik_jac_3[3 * eml_k + 2] *
            eml_r_del[uIdx + 5];
          eml_iik_jac_3[1 + 3 * eml_k] = eml_iik_jac_3[3 * eml_k + 1] -
            eml_iik_jac_3[3 * eml_k + 2] * eml_r_del[k + 5];
          eml_iik_jac_3[1 + 3 * eml_k] = eml_iik_jac_3[3 * eml_k + 1] /
            eml_r_del[k + 2];
          eml_iik_jac_3[3 * eml_k] -= eml_iik_jac_3[3 * eml_k + 1] *
            eml_r_del[uIdx + 2];
          eml_iik_jac_3[3 * eml_k] /= eml_r_del[uIdx - 1];
        }

        /*     %% */
        /*  joint velocities and ee velocity proportional to joint error */
        /* '<S16>:1:80' */
        /* '<S16>:1:81' */
        eml_d_y_0[0] = eml_d_y[1] * eml_n1hat[2] - eml_d_y[2] * eml_n1hat[1];
        eml_d_y_0[1] = eml_d_y[2] * eml_n1hat[0] - eml_d_y[0] * eml_n1hat[2];
        eml_d_y_0[2] = eml_d_y[0] * eml_n1hat[1] - eml_d_y[1] * eml_n1hat[0];
        eml_e_y_1[0] = eml_e_y_0[1] * eml_n2hat[2] - eml_e_y_0[2] * eml_n2hat[1];
        eml_e_y_1[1] = eml_e_y_0[2] * eml_n2hat[0] - eml_e_y_0[0] * eml_n2hat[2];
        eml_e_y_1[2] = eml_e_y_0[0] * eml_n2hat[1] - eml_e_y_0[1] * eml_n2hat[0];
        eml_f_y_1[0] = eml_f_y_0[1] * eml_n3hat[2] - eml_f_y_0[2] * eml_n3hat[1];
        eml_f_y_1[1] = eml_f_y_0[2] * eml_n3hat[0] - eml_f_y_0[0] * eml_n3hat[2];
        eml_f_y_1[2] = eml_f_y_0[0] * eml_n3hat[1] - eml_f_y_0[1] * eml_n3hat[0];
        eml_q1_mu = twa_parallel_eml_xdotu(tmp_q, eml_d_y_0);
        eml_q2_mu = twa_parallel_eml_xdotu(tmp_q, eml_e_y_1);
        eml_q3_mu = twa_parallel_eml_xdotu(tmp_q, eml_f_y_1);
        eml_n1hat_0[0] = eml_n1hat[0];
        eml_n1hat_0[3] = eml_n1hat[1];
        eml_n1hat_0[6] = eml_q1_mu;
        eml_n1hat_0[1] = eml_n2hat[0];
        eml_n1hat_0[4] = eml_n2hat[1];
        eml_n1hat_0[7] = eml_q2_mu;
        eml_n1hat_0[2] = eml_n3hat[0];
        eml_n1hat_0[5] = eml_n3hat[1];
        eml_n1hat_0[8] = eml_q3_mu;
        for (uIdx = 0; uIdx < 6; uIdx++) {
          for (k = 0; k < 3; k++) {
            eml_Y[uIdx + 6 * k] = 0.0;
            eml_Y[uIdx + 6 * k] = eml_Y[6 * k + uIdx] + eml_iik_jac_3[3 * uIdx] *
              eml_n1hat_0[3 * k];
            eml_Y[uIdx + 6 * k] = eml_iik_jac_3[3 * uIdx + 1] * eml_n1hat_0[3 *
              k + 1] + eml_Y[6 * k + uIdx];
            eml_Y[uIdx + 6 * k] = eml_iik_jac_3[3 * uIdx + 2] * eml_n1hat_0[3 *
              k + 2] + eml_Y[6 * k + uIdx];
          }
        }

        for (uIdx = 0; uIdx < 6; uIdx++) {
          eml_q1_mu = twa_parallel_P.kp_Value * twa_parallel_B.UnitDelay4_e[0] *
            eml_Y[uIdx];
          eml_q1_mu += eml_Y[uIdx + 6] * (twa_parallel_P.kp_Value *
            twa_parallel_B.UnitDelay4_e[1]);
          eml_q1_mu += eml_Y[uIdx + 12] * (twa_parallel_P.kp_Value *
            twa_parallel_B.UnitDelay4_e[2]);
          eml_tdot[uIdx] = eml_q1_mu;
        }

        /*  separate translational and rotational components of twist */
        /* '<S16>:1:84' */
        /* '<S16>:1:85' */
        eml_t = eml_tdot[2];

        /*  new end effector position */
        /* '<S16>:1:88' */
        twa_parallel_B.twave_out[0] = eml_tdot[0] * twa_parallel_P.dt_Value +
          twa_parallel_B.UnitDelay3_b[0];
        twa_parallel_B.twave_out[1] = eml_tdot[1] * twa_parallel_P.dt_Value +
          twa_parallel_B.UnitDelay3_b[1];

        /*  change in end effector orientation */
        /* '<S16>:1:91' */
        /*  new end effector orientation */
        /* '<S16>:1:94' */
        eml_n1hat_0[0] = cos(eml_t * twa_parallel_P.dt_Value);
        eml_n1hat_0[3] = -sin(eml_t * twa_parallel_P.dt_Value);
        eml_n1hat_0[6] = 0.0;
        eml_n1hat_0[1] = sin(eml_t * twa_parallel_P.dt_Value);
        eml_n1hat_0[4] = cos(eml_t * twa_parallel_P.dt_Value);
        eml_n1hat_0[7] = 0.0;
        eml_n1hat_0[2] = 0.0;
        eml_n1hat_0[5] = 0.0;
        eml_n1hat_0[8] = 1.0;
        for (uIdx = 0; uIdx < 3; uIdx++) {
          for (k = 0; k < 3; k++) {
            twa_parallel_B.rwave_out[uIdx + 3 * k] = 0.0;
            twa_parallel_B.rwave_out[uIdx + 3 * k] = twa_parallel_B.rwave_out[3 *
              k + uIdx] + twa_parallel_B.UnitDelay2_j[3 * k] * eml_n1hat_0[uIdx];
            twa_parallel_B.rwave_out[uIdx + 3 * k] =
              twa_parallel_B.UnitDelay2_j[3 * k + 1] * eml_n1hat_0[uIdx + 3] +
              twa_parallel_B.rwave_out[3 * k + uIdx];
            twa_parallel_B.rwave_out[uIdx + 3 * k] =
              twa_parallel_B.UnitDelay2_j[3 * k + 2] * eml_n1hat_0[uIdx + 6] +
              twa_parallel_B.rwave_out[3 * k + uIdx];
          }
        }

        /* '<S16>:1:96' */
        /* '<S16>:1:97' */
        for (eml_k = 0; eml_k < 3; eml_k++) {
          /* '<S16>:1:97' */
          /* '<S16>:1:98' */
          for (uIdx = 0; uIdx < 3; uIdx++) {
            eml_q1_mu = twa_parallel_P.p_in_m_Value[3 * eml_k] *
              twa_parallel_B.rwave_out[uIdx];
            eml_q1_mu += twa_parallel_P.p_in_m_Value[3 * eml_k + 1] *
              twa_parallel_B.rwave_out[uIdx + 3];
            eml_q1_mu += twa_parallel_P.p_in_m_Value[3 * eml_k + 2] *
              twa_parallel_B.rwave_out[uIdx + 6];
            eml_y_0[uIdx] = twa_parallel_B.twave_out[uIdx] + eml_q1_mu;
          }

          eml_r_cur[3 * eml_k] = eml_y_0[0];
          eml_r_cur[1 + 3 * eml_k] = eml_y_0[1];
          eml_r_cur[2 + 3 * eml_k] = eml_y_0[2];

          /* '<S16>:1:99' */
          eml_r_cur_0[0] = eml_r_cur[3 * eml_k] - twa_parallel_P.b_in_w_Value[3 *
            eml_k];
          eml_r_cur_0[1] = eml_r_cur[3 * eml_k + 1] -
            twa_parallel_P.b_in_w_Value[3 * eml_k + 1];
          eml_r_cur_0[2] = eml_r_cur[3 * eml_k + 2] -
            twa_parallel_P.b_in_w_Value[3 * eml_k + 2];
          twa_parallel_B.des_leg_len[eml_k] = twa_parallel_norm(eml_r_cur_0);
        }

        /* '<S16>:1:102' */
        twa_parallel_B.eq_out[0] = twa_parallel_B.UnitDelay1_p[0] -
          twa_parallel_B.des_leg_len[0];
        twa_parallel_B.eq_out[1] = twa_parallel_B.UnitDelay1_p[1] -
          twa_parallel_B.des_leg_len[1];
        twa_parallel_B.eq_out[2] = twa_parallel_B.UnitDelay1_p[2] -
          twa_parallel_B.des_leg_len[2];

        /*  the amount each velmex slides need to move is the difference between */
        /*  the last leg length and the new leg length */
        /*      qcmd(1:3,1) = (measured_len - des_leg_len)/velmex_pitch */
        /* '<S16>:1:107' */
        twa_parallel_B.qcmd = (twa_parallel_B.des_leg_len[2] -
          twa_parallel_P.meas_macro_len_Value[2]) /
          twa_parallel_P.velmex_pitch_Value;

        /* '<S16>:1:109' */
        /* '<S16>:1:110' */
      } else {
        /* '<S16>:1:112' */
        /* '<S16>:1:113' */
        twa_parallel_B.des_leg_len[0] = twa_parallel_B.UnitDelay1_p[0];
        twa_parallel_B.eq_out[0] = twa_parallel_B.UnitDelay4_e[0];
        twa_parallel_B.des_leg_len[1] = twa_parallel_B.UnitDelay1_p[1];
        twa_parallel_B.eq_out[1] = twa_parallel_B.UnitDelay4_e[1];
        twa_parallel_B.des_leg_len[2] = twa_parallel_B.UnitDelay1_p[2];
        twa_parallel_B.eq_out[2] = twa_parallel_B.UnitDelay4_e[2];

        /* '<S16>:1:114' */
        /* '<S16>:1:115' */
        memcpy((void *)(&twa_parallel_B.rwave_out[0]), (void *)
               (&twa_parallel_B.UnitDelay2_j[0]), 9U * sizeof(real_T));
      }

      if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
        srUpdateBC(twa_parallel_DWork.Homing_SubsysRanBC);
      }
    }

    /* end of Outputs for SubSystem: '<Root>/Homing' */
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
    /* Update for DiscreteFir: '<S15>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf =
      twa_parallel_DWork.DiscreteFIRFilter_circBuf - 1;
    if (twa_parallel_DWork.DiscreteFIRFilter_circBuf < 0) {
      twa_parallel_DWork.DiscreteFIRFilter_circBuf = 0;
    }

    for (k = 0; k < 6; k++) {
      twa_parallel_DWork.DiscreteFIRFilter_states[twa_parallel_DWork.DiscreteFIRFilter_circBuf
        + k] = twa_parallel_B.TmpSignalConversionAtDiscreteFI[k];
    }

    /* Update for UnitDelay: '<S14>/UD' */
    for (k = 0; k < 6; k++) {
      twa_parallel_DWork.UD_DSTATE[k] = twa_parallel_B.TSamp[k];
    }

    /* Update for DiscreteFir: '<S21>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf_l =
      twa_parallel_DWork.DiscreteFIRFilter_circBuf_l - 1;
    if (twa_parallel_DWork.DiscreteFIRFilter_circBuf_l < 0) {
      twa_parallel_DWork.DiscreteFIRFilter_circBuf_l = 0;
    }

    for (k = 0; k < 6; k++) {
      twa_parallel_DWork.DiscreteFIRFilter_states_m[twa_parallel_DWork.DiscreteFIRFilter_circBuf_l
        + k] = twa_parallel_B.TmpSignalConversionAtDiscreteFI[k];
    }

    /* Update for UnitDelay: '<S6>/Unit Delay4' */
    twa_parallel_DWork.UnitDelay4_DSTATE[0] = twa_parallel_B.xcur[0];
    twa_parallel_DWork.UnitDelay4_DSTATE[1] = twa_parallel_B.xcur[1];
    twa_parallel_DWork.UnitDelay4_DSTATE[2] = twa_parallel_B.xcur[2];

    /* Update for UnitDelay: '<S6>/Unit Delay3' */
    twa_parallel_DWork.UnitDelay3_DSTATE = twa_parallel_B.eerot;

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE = twa_parallel_B.confn;

    /* Update for UnitDelay: '<S4>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE_h = twa_parallel_B.t0n;
    for (k = 0; k < 6; k++) {
      /* Update for UnitDelay: '<S6>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE[k] = twa_parallel_B.qdes[k];

      /* Update for UnitDelay: '<S4>/Unit Delay2' */
      twa_parallel_DWork.UnitDelay2_DSTATE[k] = twa_parallel_B.q0n[k];
    }
  }

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    /* Update for UnitDelay: '<S17>/UD' */
    for (k = 0; k < 6; k++) {
      twa_parallel_DWork.UD_DSTATE_o[k] = twa_parallel_B.TSamp_h[k];
    }

    /* Update for enable SubSystem: '<Root>/Homing' incorporates:
     *  Update for EnablePort: '<S2>/Enable'
     */
    if (twa_parallel_B.HiddenBuf_InsertedFor_Homing_at > 0.0) {
      /* Update for UnitDelay: '<S2>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE_f[0] = twa_parallel_B.des_leg_len[0];

      /* Update for UnitDelay: '<S2>/Unit Delay4' */
      twa_parallel_DWork.UnitDelay4_DSTATE_g[0] = twa_parallel_B.eq_out[0];

      /* Update for UnitDelay: '<S2>/Unit Delay3' */
      twa_parallel_DWork.UnitDelay3_DSTATE_e[0] = twa_parallel_B.twave_out[0];

      /* Update for UnitDelay: '<S2>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE_f[1] = twa_parallel_B.des_leg_len[1];

      /* Update for UnitDelay: '<S2>/Unit Delay4' */
      twa_parallel_DWork.UnitDelay4_DSTATE_g[1] = twa_parallel_B.eq_out[1];

      /* Update for UnitDelay: '<S2>/Unit Delay3' */
      twa_parallel_DWork.UnitDelay3_DSTATE_e[1] = twa_parallel_B.twave_out[1];

      /* Update for UnitDelay: '<S2>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE_f[2] = twa_parallel_B.des_leg_len[2];

      /* Update for UnitDelay: '<S2>/Unit Delay4' */
      twa_parallel_DWork.UnitDelay4_DSTATE_g[2] = twa_parallel_B.eq_out[2];

      /* Update for UnitDelay: '<S2>/Unit Delay3' */
      twa_parallel_DWork.UnitDelay3_DSTATE_e[2] = twa_parallel_B.twave_out[2];

      /* Update for UnitDelay: '<S2>/Unit Delay2' */
      memcpy((void *)(&twa_parallel_DWork.UnitDelay2_DSTATE_l[0]), (void *)
             (&twa_parallel_B.rwave_out[0]), 9U * sizeof(real_T));
    }

    /* end of Update for SubSystem: '<Root>/Homing' */
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
  /* Derivatives for Integrator: '<S3>/Integrator' */
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
  twa_parallel_rtM->Sizes.checksums[0] = (196772679U);
  twa_parallel_rtM->Sizes.checksums[1] = (3755560381U);
  twa_parallel_rtM->Sizes.checksums[2] = (1664469325U);
  twa_parallel_rtM->Sizes.checksums[3] = (3201855251U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    twa_parallel_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&twa_parallel_DWork.Homing_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&twa_parallel_DWork.Homing_SubsysRanBC;
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
      twa_parallel_B.UnitDelay1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.cntrl_switch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.UnitDelay2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      twa_parallel_B.Switch[i] = 0.0;
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
      twa_parallel_B.Uk1_j[i] = 0.0;
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

    for (i = 0; i < 6; i++) {
      twa_parallel_B.TmpSignalConversionAtSFunctionI[i] = 0.0;
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

    for (i = 0; i < 9; i++) {
      twa_parallel_B.UnitDelay2_j[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      twa_parallel_B.rwave_out[i] = 0.0;
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
    twa_parallel_B.UnitDelay4[0] = 0.0;
    twa_parallel_B.UnitDelay4[1] = 0.0;
    twa_parallel_B.UnitDelay4[2] = 0.0;
    twa_parallel_B.UnitDelay3 = 0.0;
    twa_parallel_B.DigitalClock = 0.0;
    twa_parallel_B.UnitDelay = 0.0;
    twa_parallel_B.UnitDelay1_b = 0.0;
    twa_parallel_B.twa_gamma = 0.0;
    twa_parallel_B.use_twa = 0.0;
    twa_parallel_B.twa_flange_offset = 0.0;
    twa_parallel_B.HiddenBuf_InsertedFor_Homing_at = 0.0;
    twa_parallel_B.xcur[0] = 0.0;
    twa_parallel_B.xcur[1] = 0.0;
    twa_parallel_B.xcur[2] = 0.0;
    twa_parallel_B.eerot = 0.0;
    twa_parallel_B.confn = 0.0;
    twa_parallel_B.t0n = 0.0;
    twa_parallel_B.robot_mov = 0.0;
    twa_parallel_B.UnitDelay1_p[0] = 0.0;
    twa_parallel_B.UnitDelay1_p[1] = 0.0;
    twa_parallel_B.UnitDelay1_p[2] = 0.0;
    twa_parallel_B.UnitDelay4_e[0] = 0.0;
    twa_parallel_B.UnitDelay4_e[1] = 0.0;
    twa_parallel_B.UnitDelay4_e[2] = 0.0;
    twa_parallel_B.UnitDelay3_b[0] = 0.0;
    twa_parallel_B.UnitDelay3_b[1] = 0.0;
    twa_parallel_B.UnitDelay3_b[2] = 0.0;
    twa_parallel_B.qcmd = 0.0;
    twa_parallel_B.des_leg_len[0] = 0.0;
    twa_parallel_B.des_leg_len[1] = 0.0;
    twa_parallel_B.des_leg_len[2] = 0.0;
    twa_parallel_B.eq_out[0] = 0.0;
    twa_parallel_B.eq_out[1] = 0.0;
    twa_parallel_B.eq_out[2] = 0.0;
    twa_parallel_B.twave_out[0] = 0.0;
    twa_parallel_B.twave_out[1] = 0.0;
    twa_parallel_B.twave_out[2] = 0.0;
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
      twa_parallel_DWork.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  twa_parallel_DWork.UnitDelay4_DSTATE[0] = 0.0;
  twa_parallel_DWork.UnitDelay4_DSTATE[1] = 0.0;
  twa_parallel_DWork.UnitDelay4_DSTATE[2] = 0.0;
  twa_parallel_DWork.UnitDelay3_DSTATE = 0.0;
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

  twa_parallel_DWork.UnitDelay1_DSTATE_f[0] = 0.0;
  twa_parallel_DWork.UnitDelay1_DSTATE_f[1] = 0.0;
  twa_parallel_DWork.UnitDelay1_DSTATE_f[2] = 0.0;
  twa_parallel_DWork.UnitDelay4_DSTATE_g[0] = 0.0;
  twa_parallel_DWork.UnitDelay4_DSTATE_g[1] = 0.0;
  twa_parallel_DWork.UnitDelay4_DSTATE_g[2] = 0.0;
  twa_parallel_DWork.UnitDelay3_DSTATE_e[0] = 0.0;
  twa_parallel_DWork.UnitDelay3_DSTATE_e[1] = 0.0;
  twa_parallel_DWork.UnitDelay3_DSTATE_e[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      twa_parallel_DWork.UnitDelay2_DSTATE_l[i] = 0.0;
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
  twa_parallel_rtM->Sizes.numBlocks = (97);/* Number of blocks */
  twa_parallel_rtM->Sizes.numBlockIO = (74);/* Number of block outputs */
  twa_parallel_rtM->Sizes.numBlockPrms = (237);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for DiscreteFir: '<S15>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf = 0;

    /* InitializeConditions for DiscreteFir: '<S21>/Discrete FIR Filter' */
    twa_parallel_DWork.DiscreteFIRFilter_circBuf_l = 0;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.DiscreteFIRFilter_states[i] =
        twa_parallel_P.DiscreteFIRFilter_IC;

      /* InitializeConditions for UnitDelay: '<S14>/UD' */
      twa_parallel_DWork.UD_DSTATE[i] = twa_parallel_P.UD_X0;
      twa_parallel_DWork.DiscreteFIRFilter_states_m[i] =
        twa_parallel_P.DiscreteFIRFilter_IC_b;

      /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
      twa_parallel_DWork.UnitDelay1_DSTATE[i] = twa_parallel_P.UnitDelay1_X0_g[i];
    }

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay4' */
    twa_parallel_DWork.UnitDelay4_DSTATE[0] = twa_parallel_P.UnitDelay4_X0_l[0];
    twa_parallel_DWork.UnitDelay4_DSTATE[1] = twa_parallel_P.UnitDelay4_X0_l[1];
    twa_parallel_DWork.UnitDelay4_DSTATE[2] = twa_parallel_P.UnitDelay4_X0_l[2];

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay3' */
    twa_parallel_DWork.UnitDelay3_DSTATE = twa_parallel_P.UnitDelay3_X0_b;

    /* InitializeConditions for Embedded MATLAB: '<S6>/ResolvedRates' */
    twa_parallel_DWork.is_active_c5_twa_parallel = 0U;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE = twa_parallel_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE_h = twa_parallel_P.UnitDelay1_X0_h;

    /* Signal Processing Blockset N-Sample Enable  (sdspnsamp2) - '<S20>/N-Sample Enable' */
    twa_parallel_DWork.NSampleEnable_Counter = (uint32_T) 0;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay2' */
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UnitDelay2_DSTATE[i] = twa_parallel_P.UnitDelay2_X0_d[i];
    }

    /* InitializeConditions for Embedded MATLAB: '<S4>/Embedded MATLAB Function' */
    twa_parallel_DWork.is_active_c22_twa_parallel = 0U;

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    {
      int_T i1;
      real_T *xc = &twa_parallel_X.Integrator_CSTATE[0];
      for (i1=0; i1 < 6; i1++) {
        xc[i1] = twa_parallel_P.Integrator_IC;
      }
    }

    /* InitializeConditions for UnitDelay: '<S17>/UD' */
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

  /* S-Function Block: <S23>/S-Function (scblock) */
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
        xpceScopeAcqOK(1, &twa_parallel_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S22>/S-Function (scblock) */
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
        xpceScopeAcqOK(2, &twa_parallel_DWork.SFunction_IWORK_j.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S24>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("cntrl_switch/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("cntrl_switch/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("cntrl_switch/s3"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("cntrl_switch/s1"),
          "q1_des [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("cntrl_switch/s2"),
          "q2_des [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("cntrl_switch/s3"),
          "q3_des [cnt] %12.4f");
        rl32eSetScope(3, 4, 25);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("cntrl_switch/s1"));
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

  /* S-Function Block: <S18>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("PID Controller/saturate_int/s1"));
        rl32eAddSignal(5, rl32eGetSignalNo("PID Controller/saturate_int/s2"));
        rl32eAddSignal(5, rl32eGetSignalNo("PID Controller/saturate_int/s3"));
        rl32eAddSignal(5, rl32eGetSignalNo("PID Controller/saturate_int/s4"));
        rl32eAddSignal(5, rl32eGetSignalNo("PID Controller/saturate_int/s5"));
        rl32eAddSignal(5, rl32eGetSignalNo("PID Controller/saturate_int/s6"));
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "PID Controller/saturate_int/s1"),"q1_cmd [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "PID Controller/saturate_int/s2"),"q2_cmd [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "PID Controller/saturate_int/s3"),"q3_cmd [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "PID Controller/saturate_int/s4"),"q4_cmd [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "PID Controller/saturate_int/s5"),"q5_cmd [cnt] %12.4f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "PID Controller/saturate_int/s6"),"q6_cmd [cnt] %12.4f");
        rl32eSetScope(5, 4, 25);
        rl32eSetScope(5, 40, 0);
        rl32eSetScope(5, 7, 1);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("PID Controller/saturate_int/s1"));
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

  /* S-Function Block: <S26>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("task_space/ResolvedRates/p1/s1"));
        rl32eAddSignal(4, rl32eGetSignalNo("task_space/ResolvedRates/p1/s2"));
        rl32eAddSignal(4, rl32eGetSignalNo("task_space/ResolvedRates/p1/s3"));
        rl32eAddSignal(4, rl32eGetSignalNo("task_space/ResolvedRates/p1/s4"));
        rl32eAddSignal(4, rl32eGetSignalNo("task_space/ResolvedRates/p1/s5"));
        rl32eAddSignal(4, rl32eGetSignalNo("task_space/ResolvedRates/p1/s6"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "task_space/ResolvedRates/p1/s1"),"q1 delta [mm] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "task_space/ResolvedRates/p1/s2"),"q2 delta [mm] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "task_space/ResolvedRates/p1/s3"),"q3 delta [mm] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "task_space/ResolvedRates/p1/s4"),"q4 delta [mm] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "task_space/ResolvedRates/p1/s5"),"q5 delta [mm] %12.4f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "task_space/ResolvedRates/p1/s6"),"q6 delta [mm] %12.4f");
        rl32eSetScope(4, 4, 25);
        rl32eSetScope(4, 40, 0);
        rl32eSetScope(4, 7, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("task_space/ResolvedRates/p1/s1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 10, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, 0.0);
        rl32eSetTargetScope(4, 10, 0.0);
        xpceScopeAcqOK(4, &twa_parallel_DWork.SFunction_IWORK_a.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* Start for enable SubSystem: '<Root>/Homing' */

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  twa_parallel_DWork.UnitDelay1_DSTATE_f[0] = twa_parallel_P.UnitDelay1_X0[0];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay4' */
  twa_parallel_DWork.UnitDelay4_DSTATE_g[0] = twa_parallel_P.UnitDelay4_X0[0];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay3' */
  twa_parallel_DWork.UnitDelay3_DSTATE_e[0] = twa_parallel_P.UnitDelay3_X0[0];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  twa_parallel_DWork.UnitDelay1_DSTATE_f[1] = twa_parallel_P.UnitDelay1_X0[1];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay4' */
  twa_parallel_DWork.UnitDelay4_DSTATE_g[1] = twa_parallel_P.UnitDelay4_X0[1];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay3' */
  twa_parallel_DWork.UnitDelay3_DSTATE_e[1] = twa_parallel_P.UnitDelay3_X0[1];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  twa_parallel_DWork.UnitDelay1_DSTATE_f[2] = twa_parallel_P.UnitDelay1_X0[2];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay4' */
  twa_parallel_DWork.UnitDelay4_DSTATE_g[2] = twa_parallel_P.UnitDelay4_X0[2];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay3' */
  twa_parallel_DWork.UnitDelay3_DSTATE_e[2] = twa_parallel_P.UnitDelay3_X0[2];

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay2' */
  memcpy((void *)(&twa_parallel_DWork.UnitDelay2_DSTATE_l[0]), (void *)
         (&twa_parallel_P.UnitDelay2_X0[0]), 9U * sizeof(real_T));

  /* InitializeConditions for Embedded MATLAB: '<S2>/Homing' */
  twa_parallel_DWork.is_active_c3_twa_parallel = 0U;

  /* end of Start for SubSystem: '<Root>/Homing' */
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
