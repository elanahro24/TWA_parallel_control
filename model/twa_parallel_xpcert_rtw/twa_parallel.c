/*
 * twa_parallel.c
 *
 * Real-Time Workshop code generation for Simulink model "twa_parallel.mdl".
 *
 * Model version              : 1.6743
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Fri Jun 21 16:16:36 2024
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

/* Real-time model */
rtModel_twa_parallel twa_parallel_rtM_;
rtModel_twa_parallel *twa_parallel_rtM = &twa_parallel_rtM_;

/* Forward declaration for local functions */
static real_T twa_parallel_eml_xnrm2(int32_T eml_n, const real_T eml_x[9],
  int32_T eml_ix0);
static void twa_parallel_refp3_eml_xscal(int32_T eml_n, real_T eml_a, real_T
  eml_x[9], int32_T eml_ix0);
static real_T twa_parallel_eml_xnrm2_c(int32_T eml_n, const real_T eml_x[3],
  int32_T eml_ix0);
static void twa_parallel_refp3_eml_xscal_c(int32_T eml_n, real_T eml_a, real_T
  eml_x[3], int32_T eml_ix0);
static void twa_parallel_refp7_eml_xrotg(real_T *eml_a, real_T *eml_b, real_T
  *eml_c, real_T *eml_s);
static real_T twa_parallel_max(const real_T eml_varargin_1[5]);
static real_T twa_parallel_eml_xdotc(int32_T eml_n, const real_T eml_x[9],
  int32_T eml_ix0, const real_T eml_y[9], int32_T eml_iy0);
static void twa_parallel_refp4_eml_xaxpy(int32_T eml_n, real_T eml_a, int32_T
  eml_ix0, real_T eml_y[9], int32_T eml_iy0);
static void twa_parallel_refp5_eml_xaxpy_c(int32_T eml_n, real_T eml_a, const
  real_T eml_x[3], int32_T eml_ix0, real_T eml_y[9], int32_T eml_iy0);
static void twa_parallel_refp5_eml_xaxpy(int32_T eml_n, real_T eml_a, const
  real_T eml_x[9], int32_T eml_ix0, real_T eml_y[3], int32_T eml_iy0);
static void twa_parallel_svd(real_T eml_A[9], real_T eml_Uout[3]);
static void twa_par_PadeApproximantOfDegree(const real_T eml_A[9], real_T eml_m,
  real_T eml_F[9]);
static real_T twa_parallel_norm(const real_T eml_x[3]);

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

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static real_T twa_parallel_eml_xnrm2(int32_T eml_n, const real_T eml_x[9],
  int32_T eml_ix0)
{
  real_T eml_y;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  int32_T eml_kend;
  real_T eml_xk;
  real_T eml_t;
  int32_T eml_k;
  eml_y = 0.0;
  if (!(eml_n < 1)) {
    if (eml_n == 1) {
      return fabs(eml_x[eml_ix0 - 1]);
    } else {
      eml_scale = 0.0;
      eml_firstNonZero = TRUE;
      eml_kend = (eml_n - 1) + eml_ix0;
      for (eml_k = eml_ix0; eml_k <= eml_kend; eml_k++) {
        eml_xk = eml_x[eml_k - 1];
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
      }

      return eml_scale * sqrt(eml_y);
    }
  }

  return eml_y;
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static void twa_parallel_refp3_eml_xscal(int32_T eml_n, real_T eml_a, real_T
  eml_x[9], int32_T eml_ix0)
{
  int32_T eml_k;
  int32_T eml_loop_ub;
  eml_loop_ub = (eml_n - 1) + eml_ix0;
  for (eml_k = eml_ix0; eml_k <= eml_loop_ub; eml_k++) {
    eml_x[eml_k - 1] *= eml_a;
  }
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static real_T twa_parallel_eml_xnrm2_c(int32_T eml_n, const real_T eml_x[3],
  int32_T eml_ix0)
{
  real_T eml_y;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  int32_T eml_kend;
  real_T eml_xk;
  real_T eml_t;
  int32_T eml_k;
  eml_y = 0.0;
  if (!(eml_n < 1)) {
    if (eml_n == 1) {
      return fabs(eml_x[eml_ix0 - 1]);
    } else {
      eml_scale = 0.0;
      eml_firstNonZero = TRUE;
      eml_kend = (eml_n - 1) + eml_ix0;
      for (eml_k = eml_ix0; eml_k <= eml_kend; eml_k++) {
        eml_xk = eml_x[eml_k - 1];
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
      }

      return eml_scale * sqrt(eml_y);
    }
  }

  return eml_y;
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static void twa_parallel_refp3_eml_xscal_c(int32_T eml_n, real_T eml_a, real_T
  eml_x[3], int32_T eml_ix0)
{
  int32_T eml_k;
  int32_T eml_loop_ub;
  eml_loop_ub = (eml_n - 1) + eml_ix0;
  for (eml_k = eml_ix0; eml_k <= eml_loop_ub; eml_k++) {
    eml_x[eml_k - 1] *= eml_a;
  }
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static void twa_parallel_refp7_eml_xrotg(real_T *eml_a, real_T *eml_b, real_T
  *eml_c, real_T *eml_s)
{
  real_T eml_roe;
  real_T eml_absa;
  real_T eml_absb;
  real_T eml_scale;
  real_T eml_ads;
  real_T eml_bds;
  real_T eml_r;
  eml_roe = *eml_b;
  eml_absa = fabs(*eml_a);
  eml_absb = fabs(*eml_b);
  if (eml_absa > eml_absb) {
    eml_roe = *eml_a;
  }

  eml_scale = eml_absa + eml_absb;
  if (eml_scale == 0.0) {
    eml_bds = 0.0;
    eml_ads = 1.0;
    eml_r = 0.0;
    eml_scale = 0.0;
  } else {
    eml_ads = eml_absa / eml_scale;
    eml_bds = eml_absb / eml_scale;
    eml_r = sqrt(eml_ads * eml_ads + eml_bds * eml_bds) * eml_scale;
    if (eml_roe < 0.0) {
      eml_r = -eml_r;
    }

    eml_ads = *eml_a / eml_r;
    eml_bds = *eml_b / eml_r;
    if (eml_absa > eml_absb) {
      eml_scale = eml_bds;
    } else if (eml_ads != 0.0) {
      eml_scale = 1.0 / eml_ads;
    } else {
      eml_scale = 1.0;
    }
  }

  *eml_a = eml_r;
  *eml_b = eml_scale;
  *eml_c = eml_ads;
  *eml_s = eml_bds;
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static real_T twa_parallel_max(const real_T eml_varargin_1[5])
{
  real_T eml_mtmp;
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  boolean_T eml_exitg;
  eml_mtmp = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = FALSE;
  if (rtIsNaN(eml_mtmp)) {
    eml_searchingForNonNaN = TRUE;
    eml_k = 2;
    eml_exitg = FALSE;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 6)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = FALSE;
        eml_exitg = TRUE;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = TRUE;
    }
  } else {
    eml_guard = TRUE;
  }

  if (eml_guard) {
    for (eml_itmp++; eml_itmp < 6; eml_itmp++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > eml_mtmp) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
      }
    }
  }

  return eml_mtmp;
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static real_T twa_parallel_eml_xdotc(int32_T eml_n, const real_T eml_x[9],
  int32_T eml_ix0, const real_T eml_y[9], int32_T eml_iy0)
{
  real_T eml_d;
  int32_T eml_ix;
  int32_T eml_iy;
  int32_T eml_k;
  eml_d = 0.0;
  if (!(eml_n < 1)) {
    eml_ix = eml_ix0;
    eml_iy = eml_iy0;
    for (eml_k = 1; eml_k <= eml_n; eml_k++) {
      eml_d += eml_x[eml_ix - 1] * eml_y[eml_iy - 1];
      eml_ix++;
      eml_iy++;
    }
  }

  return eml_d;
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static void twa_parallel_refp4_eml_xaxpy(int32_T eml_n, real_T eml_a, int32_T
  eml_ix0, real_T eml_y[9], int32_T eml_iy0)
{
  int32_T eml_ix;
  int32_T eml_iy;
  int32_T eml_k;
  if (!((eml_n < 1) || (eml_a == 0.0))) {
    eml_ix = eml_ix0;
    eml_iy = eml_iy0;
    for (eml_k = 1; eml_k <= eml_n; eml_k++) {
      eml_y[eml_iy - 1] += eml_y[eml_ix - 1] * eml_a;
      eml_iy++;
      eml_ix++;
    }
  }
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static void twa_parallel_refp5_eml_xaxpy_c(int32_T eml_n, real_T eml_a, const
  real_T eml_x[3], int32_T eml_ix0, real_T eml_y[9], int32_T eml_iy0)
{
  int32_T eml_ix;
  int32_T eml_iy;
  int32_T eml_k;
  if (!((eml_n < 1) || (eml_a == 0.0))) {
    eml_ix = eml_ix0;
    eml_iy = eml_iy0;
    for (eml_k = 1; eml_k <= eml_n; eml_k++) {
      eml_y[eml_iy - 1] += eml_x[eml_ix - 1] * eml_a;
      eml_iy++;
      eml_ix++;
    }
  }
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static void twa_parallel_refp5_eml_xaxpy(int32_T eml_n, real_T eml_a, const
  real_T eml_x[9], int32_T eml_ix0, real_T eml_y[3], int32_T eml_iy0)
{
  int32_T eml_ix;
  int32_T eml_iy;
  int32_T eml_k;
  if (!((eml_n < 1) || (eml_a == 0.0))) {
    eml_ix = eml_ix0;
    eml_iy = eml_iy0;
    for (eml_k = 1; eml_k <= eml_n; eml_k++) {
      eml_y[eml_iy - 1] += eml_x[eml_ix - 1] * eml_a;
      eml_iy++;
      eml_ix++;
    }
  }
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static void twa_parallel_svd(real_T eml_A[9], real_T eml_Uout[3])
{
  real_T eml_s[3];
  real_T eml_e[3];
  real_T eml_work[3];
  int32_T eml_m;
  int32_T eml_iter;
  real_T eml_ztest;
  int32_T eml_qs;
  real_T eml_ztest_0;
  real_T eml_f;
  real_T eml_scale;
  real_T eml_sm;
  real_T eml_sqds;
  real_T eml_sn;
  int32_T eml_b_q;
  int32_T eml_c_q;
  int32_T eml_c_ii;
  boolean_T eml_exitg;
  real_T tmp[5];
  real_T eml_e_0;
  eml_s[0] = 0.0;
  eml_e[0] = 0.0;
  eml_work[0] = 0.0;
  eml_s[1] = 0.0;
  eml_e[1] = 0.0;
  eml_work[1] = 0.0;
  eml_s[2] = 0.0;
  eml_e[2] = 0.0;
  eml_work[2] = 0.0;
  eml_ztest = twa_parallel_eml_xnrm2(3, eml_A, 1);
  if (eml_ztest == 0.0) {
    eml_s[0] = 0.0;
  } else {
    if (eml_A[0] < 0.0) {
      eml_ztest = -eml_ztest;
    }

    eml_s[0] = eml_ztest;
    twa_parallel_refp3_eml_xscal(3, 1.0 / eml_s[0], eml_A, 1);
    eml_A[0]++;
    eml_s[0] = -eml_s[0];
  }

  for (eml_qs = 2; eml_qs < 4; eml_qs++) {
    eml_iter = (eml_qs - 1) * 3 + 1;
    if (eml_s[0] != 0.0) {
      twa_parallel_refp4_eml_xaxpy(3, -(twa_parallel_eml_xdotc(3, eml_A, 1,
        eml_A, eml_iter) / eml_A[0]), 1, eml_A, eml_iter);
    }

    eml_e[eml_qs - 1] = eml_A[eml_iter - 1];
  }

  eml_ztest = twa_parallel_eml_xnrm2_c(2, eml_e, 2);
  if (eml_ztest == 0.0) {
    eml_e[0] = 0.0;
  } else {
    if (eml_e[1] < 0.0) {
      eml_ztest = -eml_ztest;
    }

    eml_e[0] = eml_ztest;
    twa_parallel_refp3_eml_xscal_c(2, 1.0 / eml_e[0], eml_e, 2);
    eml_e[1]++;
  }

  eml_e[0] = -eml_e[0];
  if (eml_e[0] != 0.0) {
    for (eml_c_q = 2; eml_c_q < 4; eml_c_q++) {
      eml_work[eml_c_q - 1] = 0.0;
    }

    for (eml_c_q = 2; eml_c_q < 4; eml_c_q++) {
      twa_parallel_refp5_eml_xaxpy(2, eml_e[eml_c_q - 1], eml_A, 2 + 3 *
        (eml_c_q - 1), eml_work, 2);
    }

    for (eml_c_q = 2; eml_c_q < 4; eml_c_q++) {
      twa_parallel_refp5_eml_xaxpy_c(2, (-eml_e[eml_c_q - 1]) / eml_e[1],
        eml_work, 2, eml_A, 2 + 3 * (eml_c_q - 1));
    }
  }

  eml_ztest = twa_parallel_eml_xnrm2(2, eml_A, 5);
  if (eml_ztest == 0.0) {
    eml_s[1] = 0.0;
  } else {
    if (eml_A[4] < 0.0) {
      eml_ztest = -eml_ztest;
    }

    eml_s[1] = eml_ztest;
    twa_parallel_refp3_eml_xscal(2, 1.0 / eml_s[1], eml_A, 5);
    eml_A[4]++;
    eml_s[1] = -eml_s[1];
  }

  for (eml_qs = 3; eml_qs < 4; eml_qs = 4) {
    if (eml_s[1] != 0.0) {
      twa_parallel_refp4_eml_xaxpy(2, -(twa_parallel_eml_xdotc(2, eml_A, 5,
        eml_A, 8) / eml_A[4]), 5, eml_A, 8);
    }

    eml_e[2] = eml_A[7];
  }

  eml_m = 3;
  eml_s[2] = eml_A[8];
  eml_e[1] = eml_A[7];
  eml_e[2] = 0.0;
  eml_e_0 = eml_e[0];
  if (eml_s[0] != 0.0) {
    eml_ztest_0 = fabs(eml_s[0]);
    eml_ztest = eml_s[0];
    eml_s[0] = eml_ztest_0;
    eml_e_0 /= eml_ztest / eml_ztest_0;
  }

  if (eml_e_0 != 0.0) {
    eml_ztest_0 = fabs(eml_e_0);
    eml_ztest = eml_e_0;
    eml_e_0 = eml_ztest_0;
    eml_s[1] *= eml_ztest_0 / eml_ztest;
  }

  eml_e[0] = eml_e_0;
  eml_e_0 = eml_e[1];
  if (eml_s[1] != 0.0) {
    eml_ztest_0 = fabs(eml_s[1]);
    eml_ztest = eml_s[1];
    eml_s[1] = eml_ztest_0;
    eml_e_0 /= eml_ztest / eml_ztest_0;
  }

  if (eml_e_0 != 0.0) {
    eml_ztest_0 = fabs(eml_e_0);
    eml_ztest = eml_e_0;
    eml_e_0 = eml_ztest_0;
    eml_s[2] *= eml_ztest_0 / eml_ztest;
  }

  eml_e[1] = eml_e_0;
  if (eml_s[2] != 0.0) {
    eml_ztest_0 = fabs(eml_s[2]);
    eml_s[2] = eml_ztest_0;
  }

  eml_e[2] = 0.0;
  eml_iter = 0;
  eml_ztest = eml_s[0];
  eml_ztest_0 = eml_e[0];
  eml_ztest = rt_MAXd_snf(eml_ztest, eml_ztest_0);
  eml_e_0 = rt_MAXd_snf(0.0, eml_ztest);
  eml_ztest = eml_s[1];
  eml_ztest_0 = eml_e[1];
  eml_ztest = rt_MAXd_snf(eml_ztest, eml_ztest_0);
  eml_e_0 = rt_MAXd_snf(eml_e_0, eml_ztest);
  eml_ztest = eml_s[2];
  eml_e_0 = rt_MAXd_snf(eml_e_0, eml_ztest);
  while ((eml_m > 0) && (!(eml_iter >= 75))) {
    eml_c_ii = eml_m - 1;
    do {
      eml_c_q = 0;
      eml_b_q = eml_c_ii;
      if (eml_c_ii == 0) {
        eml_c_q = 1;
      } else {
        eml_ztest = fabs(eml_e[eml_c_ii - 1]);
        if ((eml_ztest <= (fabs(eml_s[eml_c_ii - 1]) + fabs(eml_s[eml_c_ii])) *
             2.2204460492503131E-016) || (eml_ztest <= 1.0020841800044864E-292) ||
            ((eml_iter > 20) && (eml_ztest <= 2.2204460492503131E-016 * eml_e_0)))
        {
          eml_e[eml_c_ii - 1] = 0.0;
          eml_c_q = 1;
        } else {
          eml_c_ii += -1;
        }
      }
    } while ((uint32_T)eml_c_q == 0U);

    if (eml_m - 1 == eml_c_ii) {
      eml_c_q = 4;
    } else {
      eml_qs = eml_m;
      eml_c_q = eml_m;
      eml_exitg = FALSE;
      while (((uint32_T)eml_exitg == 0U) && (eml_c_q >= eml_c_ii)) {
        eml_qs = eml_c_q;
        if (eml_c_q == eml_c_ii) {
          eml_exitg = TRUE;
        } else {
          eml_ztest = 0.0;
          if (eml_c_q < eml_m) {
            eml_ztest = fabs(eml_e[eml_c_q - 1]);
          }

          if (eml_c_q > eml_c_ii + 1) {
            eml_ztest += fabs(eml_e[eml_c_q - 2]);
          }

          eml_ztest_0 = fabs(eml_s[eml_c_q - 1]);
          if ((eml_ztest_0 <= 2.2204460492503131E-016 * eml_ztest) ||
              (eml_ztest_0 <= 1.0020841800044864E-292)) {
            eml_s[eml_c_q - 1] = 0.0;
            eml_exitg = TRUE;
          } else {
            eml_c_q += -1;
          }
        }
      }

      if (eml_qs == eml_c_ii) {
        eml_c_q = 3;
      } else if (eml_qs == eml_m) {
        eml_c_q = 1;
      } else {
        eml_c_q = 2;
        eml_b_q = eml_qs;
      }
    }

    eml_b_q++;
    switch (eml_c_q) {
     case 1:
      eml_f = eml_e[eml_m - 2];
      eml_e[eml_m - 2] = 0.0;
      for (eml_c_q = eml_m - 1; eml_c_q >= eml_b_q; eml_c_q += -1) {
        eml_ztest = eml_s[eml_c_q - 1];
        twa_parallel_refp7_eml_xrotg(&eml_ztest, &eml_f, &eml_ztest_0, &eml_sn);
        eml_s[eml_c_q - 1] = eml_ztest;
        if (eml_c_q > eml_b_q) {
          eml_f = (-eml_sn) * eml_e[0];
          eml_e[0] *= eml_ztest_0;
        }
      }
      break;

     case 2:
      eml_c_q = eml_b_q - 1;
      eml_f = eml_e[eml_c_q - 1];
      eml_e[eml_c_q - 1] = 0.0;
      while (eml_b_q <= eml_m) {
        eml_ztest = eml_s[eml_b_q - 1];
        twa_parallel_refp7_eml_xrotg(&eml_ztest, &eml_f, &eml_ztest_0, &eml_sn);
        eml_s[eml_b_q - 1] = eml_ztest;
        eml_f = eml_e[eml_b_q - 1] * (-eml_sn);
        eml_e[eml_b_q - 1] *= eml_ztest_0;
        eml_b_q++;
      }
      break;

     case 3:
      eml_c_q = eml_m - 1;
      tmp[0] = fabs(eml_s[eml_m - 1]);
      tmp[1] = fabs(eml_s[eml_c_q - 1]);
      tmp[2] = fabs(eml_e[eml_c_q - 1]);
      tmp[3] = fabs(eml_s[eml_b_q - 1]);
      tmp[4] = fabs(eml_e[eml_b_q - 1]);
      eml_scale = twa_parallel_max(tmp);
      eml_sm = eml_s[eml_m - 1] / eml_scale;
      eml_ztest = eml_s[eml_c_q - 1] / eml_scale;
      eml_ztest_0 = eml_e[eml_c_q - 1] / eml_scale;
      eml_sqds = eml_s[eml_b_q - 1] / eml_scale;
      eml_sn = ((eml_ztest + eml_sm) * (eml_ztest - eml_sm) + eml_ztest_0 *
                eml_ztest_0) / 2.0;
      eml_ztest = eml_sm * eml_ztest_0;
      eml_ztest *= eml_ztest;
      eml_ztest_0 = 0.0;
      if ((eml_sn != 0.0) || (eml_ztest != 0.0)) {
        eml_ztest_0 = sqrt(eml_sn * eml_sn + eml_ztest);
        if (eml_sn < 0.0) {
          eml_ztest_0 = -eml_ztest_0;
        }

        eml_ztest_0 = eml_ztest / (eml_sn + eml_ztest_0);
      }

      eml_f = (eml_sqds + eml_sm) * (eml_sqds - eml_sm) + eml_ztest_0;
      eml_ztest = eml_e[eml_b_q - 1] / eml_scale * eml_sqds;
      for (eml_c_ii = eml_b_q; eml_c_ii <= eml_c_q; eml_c_ii++) {
        eml_qs = eml_c_ii + 1;
        twa_parallel_refp7_eml_xrotg(&eml_f, &eml_ztest, &eml_sm, &eml_scale);
        if (eml_c_ii > eml_b_q) {
          eml_e[0] = eml_f;
        }

        eml_ztest = eml_s[eml_c_ii - 1] * eml_sm;
        eml_ztest_0 = eml_e[eml_c_ii - 1] * eml_scale;
        eml_e[eml_c_ii - 1] = eml_e[eml_c_ii - 1] * eml_sm - eml_s[eml_c_ii - 1]
          * eml_scale;
        eml_sn = eml_s[eml_qs - 1];
        eml_s[eml_qs - 1] *= eml_sm;
        eml_sm = eml_ztest + eml_ztest_0;
        eml_ztest = eml_scale * eml_sn;
        twa_parallel_refp7_eml_xrotg(&eml_sm, &eml_ztest, &eml_sn, &eml_ztest_0);
        eml_s[eml_c_ii - 1] = eml_sm;
        eml_f = eml_e[eml_c_ii - 1] * eml_sn + eml_s[eml_qs - 1] * eml_ztest_0;
        eml_s[eml_qs - 1] = eml_e[eml_c_ii - 1] * (-eml_ztest_0) + eml_s[eml_qs
          - 1] * eml_sn;
        eml_ztest = eml_e[eml_qs - 1] * eml_ztest_0;
        eml_e[eml_qs - 1] *= eml_sn;
      }

      eml_e[eml_m - 2] = eml_f;
      eml_iter++;
      break;

     default:
      if (eml_s[eml_b_q - 1] < 0.0) {
        eml_s[eml_b_q - 1] = -eml_s[eml_b_q - 1];
      }

      for (eml_qs = eml_b_q + 1; (eml_b_q < 3) && (eml_s[eml_b_q - 1] <
            eml_s[eml_qs - 1]); eml_qs++) {
        eml_ztest_0 = eml_s[eml_b_q - 1];
        eml_s[eml_b_q - 1] = eml_s[eml_qs - 1];
        eml_s[eml_qs - 1] = eml_ztest_0;
        eml_b_q = eml_qs;
      }

      eml_iter = 0;
      eml_m--;
      break;
    }
  }

  eml_Uout[0] = eml_s[0];
  eml_Uout[1] = eml_s[1];
  eml_Uout[2] = eml_s[2];
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
static void twa_par_PadeApproximantOfDegree(const real_T eml_A[9], real_T eml_m,
  real_T eml_F[9])
{
  real_T eml_A_0[9];
  real_T eml_U[9];
  real_T eml_V[9];
  real_T eml_d;
  real_T eml_A_1[9];
  real_T eml_A_2[9];
  int32_T eml_e_k;
  int32_T eml_r;
  int32_T eml_r_0;
  int32_T eml_r_1;
  real_T eml_A_3[9];
  real_T eml_A_4[9];
  real_T eml_U_0;
  real_T eml_V_0;
  for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
    for (eml_r = 0; eml_r < 3; eml_r++) {
      eml_A_0[eml_e_k + 3 * eml_r] = 0.0;
      eml_A_0[eml_e_k + 3 * eml_r] = eml_A_0[3 * eml_r + eml_e_k] + eml_A[3 *
        eml_r] * eml_A[eml_e_k];
      eml_A_0[eml_e_k + 3 * eml_r] = eml_A[3 * eml_r + 1] * eml_A[eml_e_k + 3] +
        eml_A_0[3 * eml_r + eml_e_k];
      eml_A_0[eml_e_k + 3 * eml_r] = eml_A[3 * eml_r + 2] * eml_A[eml_e_k + 6] +
        eml_A_0[3 * eml_r + eml_e_k];
    }
  }

  if (eml_m == 3.0) {
    memcpy((void *)&eml_U[0], (void *)&eml_A_0[0], 9U * sizeof(real_T));
    eml_U[0] += 60.0;
    eml_U[4] += 60.0;
    eml_U[8] += 60.0;
    for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
      for (eml_r = 0; eml_r < 3; eml_r++) {
        eml_A_3[eml_e_k + 3 * eml_r] = 0.0;
        eml_A_3[eml_e_k + 3 * eml_r] = eml_A_3[3 * eml_r + eml_e_k] + eml_U[3 *
          eml_r] * eml_A[eml_e_k];
        eml_A_3[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + 1] * eml_A[eml_e_k + 3]
          + eml_A_3[3 * eml_r + eml_e_k];
        eml_A_3[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + 2] * eml_A[eml_e_k + 6]
          + eml_A_3[3 * eml_r + eml_e_k];
      }
    }

    for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
      eml_U[3 * eml_e_k] = eml_A_3[3 * eml_e_k];
      eml_U[1 + 3 * eml_e_k] = eml_A_3[3 * eml_e_k + 1];
      eml_U[2 + 3 * eml_e_k] = eml_A_3[3 * eml_e_k + 2];
    }

    for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
      eml_V[eml_e_k] = 12.0 * eml_A_0[eml_e_k];
    }

    eml_d = 120.0;
  } else {
    for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
      for (eml_r = 0; eml_r < 3; eml_r++) {
        eml_A_1[eml_e_k + 3 * eml_r] = 0.0;
        eml_A_1[eml_e_k + 3 * eml_r] = eml_A_1[3 * eml_r + eml_e_k] + eml_A_0[3 *
          eml_r] * eml_A_0[eml_e_k];
        eml_A_1[eml_e_k + 3 * eml_r] = eml_A_0[3 * eml_r + 1] * eml_A_0[eml_e_k
          + 3] + eml_A_1[3 * eml_r + eml_e_k];
        eml_A_1[eml_e_k + 3 * eml_r] = eml_A_0[3 * eml_r + 2] * eml_A_0[eml_e_k
          + 6] + eml_A_1[3 * eml_r + eml_e_k];
      }
    }

    if (eml_m == 5.0) {
      for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
        eml_U[eml_e_k] = 420.0 * eml_A_0[eml_e_k] + eml_A_1[eml_e_k];
      }

      eml_U[0] += 15120.0;
      eml_U[4] += 15120.0;
      eml_U[8] += 15120.0;
      for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
        for (eml_r = 0; eml_r < 3; eml_r++) {
          eml_A_3[eml_e_k + 3 * eml_r] = 0.0;
          eml_A_3[eml_e_k + 3 * eml_r] = eml_A_3[3 * eml_r + eml_e_k] + eml_U[3 *
            eml_r] * eml_A[eml_e_k];
          eml_A_3[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + 1] * eml_A[eml_e_k +
            3] + eml_A_3[3 * eml_r + eml_e_k];
          eml_A_3[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + 2] * eml_A[eml_e_k +
            6] + eml_A_3[3 * eml_r + eml_e_k];
        }
      }

      for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
        eml_U[3 * eml_e_k] = eml_A_3[3 * eml_e_k];
        eml_U[1 + 3 * eml_e_k] = eml_A_3[3 * eml_e_k + 1];
        eml_U[2 + 3 * eml_e_k] = eml_A_3[3 * eml_e_k + 2];
      }

      for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
        eml_V[eml_e_k] = 30.0 * eml_A_1[eml_e_k] + 3360.0 * eml_A_0[eml_e_k];
      }

      eml_d = 30240.0;
    } else {
      for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
        for (eml_r = 0; eml_r < 3; eml_r++) {
          eml_A_2[eml_e_k + 3 * eml_r] = 0.0;
          eml_A_2[eml_e_k + 3 * eml_r] = eml_A_2[3 * eml_r + eml_e_k] + eml_A_0
            [3 * eml_r] * eml_A_1[eml_e_k];
          eml_A_2[eml_e_k + 3 * eml_r] = eml_A_0[3 * eml_r + 1] *
            eml_A_1[eml_e_k + 3] + eml_A_2[3 * eml_r + eml_e_k];
          eml_A_2[eml_e_k + 3 * eml_r] = eml_A_0[3 * eml_r + 2] *
            eml_A_1[eml_e_k + 6] + eml_A_2[3 * eml_r + eml_e_k];
        }
      }

      if (eml_m == 7.0) {
        for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
          eml_U[eml_e_k] = (1512.0 * eml_A_1[eml_e_k] + eml_A_2[eml_e_k]) +
            277200.0 * eml_A_0[eml_e_k];
        }

        eml_U[0] += 8.64864E+006;
        eml_U[4] += 8.64864E+006;
        eml_U[8] += 8.64864E+006;
        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          for (eml_r = 0; eml_r < 3; eml_r++) {
            eml_A_3[eml_e_k + 3 * eml_r] = 0.0;
            eml_A_3[eml_e_k + 3 * eml_r] = eml_A_3[3 * eml_r + eml_e_k] + eml_U
              [3 * eml_r] * eml_A[eml_e_k];
            eml_A_3[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + 1] * eml_A[eml_e_k
              + 3] + eml_A_3[3 * eml_r + eml_e_k];
            eml_A_3[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + 2] * eml_A[eml_e_k
              + 6] + eml_A_3[3 * eml_r + eml_e_k];
          }
        }

        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          eml_U[3 * eml_e_k] = eml_A_3[3 * eml_e_k];
          eml_U[1 + 3 * eml_e_k] = eml_A_3[3 * eml_e_k + 1];
          eml_U[2 + 3 * eml_e_k] = eml_A_3[3 * eml_e_k + 2];
        }

        for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
          eml_V[eml_e_k] = (56.0 * eml_A_2[eml_e_k] + 25200.0 * eml_A_1[eml_e_k])
            + 1.99584E+006 * eml_A_0[eml_e_k];
        }

        eml_d = 1.729728E+007;
      } else if (eml_m == 9.0) {
        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          for (eml_r = 0; eml_r < 3; eml_r++) {
            eml_V[eml_e_k + 3 * eml_r] = 0.0;
            eml_V[eml_e_k + 3 * eml_r] = eml_V[3 * eml_r + eml_e_k] + eml_A_0[3 *
              eml_r] * eml_A_2[eml_e_k];
            eml_V[eml_e_k + 3 * eml_r] = eml_A_0[3 * eml_r + 1] *
              eml_A_2[eml_e_k + 3] + eml_V[3 * eml_r + eml_e_k];
            eml_V[eml_e_k + 3 * eml_r] = eml_A_0[3 * eml_r + 2] *
              eml_A_2[eml_e_k + 6] + eml_V[3 * eml_r + eml_e_k];
          }
        }

        for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
          eml_U[eml_e_k] = ((3960.0 * eml_A_2[eml_e_k] + eml_V[eml_e_k]) +
                            2.16216E+006 * eml_A_1[eml_e_k]) + 3.027024E+008 *
            eml_A_0[eml_e_k];
        }

        eml_U[0] += 8.8216128E+009;
        eml_U[4] += 8.8216128E+009;
        eml_U[8] += 8.8216128E+009;
        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          for (eml_r = 0; eml_r < 3; eml_r++) {
            eml_A_3[eml_e_k + 3 * eml_r] = 0.0;
            eml_A_3[eml_e_k + 3 * eml_r] = eml_A_3[3 * eml_r + eml_e_k] + eml_U
              [3 * eml_r] * eml_A[eml_e_k];
            eml_A_3[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + 1] * eml_A[eml_e_k
              + 3] + eml_A_3[3 * eml_r + eml_e_k];
            eml_A_3[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + 2] * eml_A[eml_e_k
              + 6] + eml_A_3[3 * eml_r + eml_e_k];
          }
        }

        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          eml_U[3 * eml_e_k] = eml_A_3[3 * eml_e_k];
          eml_U[1 + 3 * eml_e_k] = eml_A_3[3 * eml_e_k + 1];
          eml_U[2 + 3 * eml_e_k] = eml_A_3[3 * eml_e_k + 2];
        }

        for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
          eml_V_0 = eml_V[eml_e_k];
          eml_V_0 = ((90.0 * eml_V_0 + 110880.0 * eml_A_2[eml_e_k]) +
                     3.027024E+007 * eml_A_1[eml_e_k]) + 2.0756736E+009 *
            eml_A_0[eml_e_k];
          eml_V[eml_e_k] = eml_V_0;
        }

        eml_d = 1.76432256E+010;
      } else {
        for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
          eml_U[eml_e_k] = (3.352212864E+010 * eml_A_2[eml_e_k] +
                            1.0559470521600000E+013 * eml_A_1[eml_e_k]) +
            1.1873537964288000E+015 * eml_A_0[eml_e_k];
        }

        eml_U[0] += 3.2382376266240000E+016;
        eml_U[4] += 3.2382376266240000E+016;
        eml_U[8] += 3.2382376266240000E+016;
        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          eml_A_3[3 * eml_e_k] = (eml_A_1[3 * eml_e_k] * 16380.0 + eml_A_2[3 *
            eml_e_k]) + eml_A_0[3 * eml_e_k] * 4.08408E+007;
          eml_A_3[1 + 3 * eml_e_k] = (eml_A_1[3 * eml_e_k + 1] * 16380.0 +
            eml_A_2[3 * eml_e_k + 1]) + eml_A_0[3 * eml_e_k + 1] * 4.08408E+007;
          eml_A_3[2 + 3 * eml_e_k] = (eml_A_1[3 * eml_e_k + 2] * 16380.0 +
            eml_A_2[3 * eml_e_k + 2]) + eml_A_0[3 * eml_e_k + 2] * 4.08408E+007;
        }

        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          for (eml_r = 0; eml_r < 3; eml_r++) {
            eml_V_0 = eml_A_3[3 * eml_r] * eml_A_2[eml_e_k];
            eml_V_0 += eml_A_3[3 * eml_r + 1] * eml_A_2[eml_e_k + 3];
            eml_V_0 += eml_A_3[3 * eml_r + 2] * eml_A_2[eml_e_k + 6];
            eml_A_4[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + eml_e_k] + eml_V_0;
          }
        }

        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          for (eml_r = 0; eml_r < 3; eml_r++) {
            eml_U[eml_e_k + 3 * eml_r] = 0.0;
            eml_U[eml_e_k + 3 * eml_r] = eml_U[3 * eml_r + eml_e_k] + eml_A_4[3 *
              eml_r] * eml_A[eml_e_k];
            eml_U[eml_e_k + 3 * eml_r] = eml_A_4[3 * eml_r + 1] * eml_A[eml_e_k
              + 3] + eml_U[3 * eml_r + eml_e_k];
            eml_U[eml_e_k + 3 * eml_r] = eml_A_4[3 * eml_r + 2] * eml_A[eml_e_k
              + 6] + eml_U[3 * eml_r + eml_e_k];
          }
        }

        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          eml_A_3[3 * eml_e_k] = (eml_A_2[3 * eml_e_k] * 182.0 + eml_A_1[3 *
            eml_e_k] * 960960.0) + eml_A_0[3 * eml_e_k] * 1.32324192E+009;
          eml_A_3[1 + 3 * eml_e_k] = (eml_A_2[3 * eml_e_k + 1] * 182.0 +
            eml_A_1[3 * eml_e_k + 1] * 960960.0) + eml_A_0[3 * eml_e_k + 1] *
            1.32324192E+009;
          eml_A_3[2 + 3 * eml_e_k] = (eml_A_2[3 * eml_e_k + 2] * 182.0 +
            eml_A_1[3 * eml_e_k + 2] * 960960.0) + eml_A_0[3 * eml_e_k + 2] *
            1.32324192E+009;
        }

        for (eml_e_k = 0; eml_e_k < 3; eml_e_k++) {
          for (eml_r = 0; eml_r < 3; eml_r++) {
            eml_V_0 = eml_A_3[3 * eml_r] * eml_A_2[eml_e_k];
            eml_V_0 += eml_A_3[3 * eml_r + 1] * eml_A_2[eml_e_k + 3];
            eml_V_0 += eml_A_3[3 * eml_r + 2] * eml_A_2[eml_e_k + 6];
            eml_V[eml_e_k + 3 * eml_r] = ((eml_A_2[3 * eml_r + eml_e_k] *
              6.704425728E+011 + eml_V_0) + eml_A_1[3 * eml_r + eml_e_k] *
              1.2906019526400000E+014) + eml_A_0[3 * eml_r + eml_e_k] *
              7.7717703038976000E+015;
          }
        }

        eml_d = 6.4764752532480000E+016;
      }
    }
  }

  eml_V[0] += eml_d;
  eml_V[4] += eml_d;
  eml_V[8] += eml_d;
  for (eml_e_k = 0; eml_e_k < 9; eml_e_k++) {
    eml_V_0 = eml_V[eml_e_k];
    eml_U_0 = eml_U[eml_e_k];
    eml_d = eml_U_0;
    eml_U_0 = eml_V_0 - eml_d;
    eml_V_0 += eml_d;
    eml_U[eml_e_k] = eml_U_0;
    eml_V[eml_e_k] = eml_V_0;
  }

  eml_r = 1;
  eml_r_0 = 2;
  eml_r_1 = 3;
  eml_d = eml_U[0];
  eml_V_0 = fabs(eml_d);
  eml_d = eml_U[1];
  eml_d = fabs(eml_d);
  if (eml_d > eml_V_0) {
    eml_V_0 = eml_d;
    eml_r = 2;
    eml_r_0 = 1;
  }

  eml_d = eml_U[2];
  if (fabs(eml_d) > eml_V_0) {
    eml_r = 3;
    eml_r_0 = 2;
    eml_r_1 = 1;
  }

  eml_U[eml_r_0 - 1] /= eml_U[eml_r - 1];
  eml_U[eml_r_1 - 1] /= eml_U[eml_r - 1];
  eml_U[eml_r_0 + 2] -= eml_U[eml_r_0 - 1] * eml_U[eml_r + 2];
  eml_U[eml_r_1 + 2] -= eml_U[eml_r_1 - 1] * eml_U[eml_r + 2];
  eml_U[eml_r_0 + 5] -= eml_U[eml_r_0 - 1] * eml_U[eml_r + 5];
  eml_U[eml_r_1 + 5] -= eml_U[eml_r_1 - 1] * eml_U[eml_r + 5];
  eml_d = eml_U[eml_r_1 + 2];
  eml_V_0 = eml_U[eml_r_0 + 2];
  if (fabs(eml_d) > fabs(eml_V_0)) {
    eml_e_k = eml_r_0;
    eml_r_0 = eml_r_1;
    eml_r_1 = eml_e_k;
  }

  eml_U[eml_r_1 + 2] /= eml_U[eml_r_0 + 2];
  eml_U[eml_r_1 + 5] -= eml_U[eml_r_1 + 2] * eml_U[eml_r_0 + 5];
  eml_F[0] = eml_V[eml_r - 1];
  eml_F[1] = eml_V[eml_r_0 - 1] - eml_U[eml_r_0 - 1] * eml_F[0];
  eml_F[2] = (eml_V[eml_r_1 - 1] - eml_U[eml_r_1 - 1] * eml_F[0]) -
    eml_U[eml_r_1 + 2] * eml_F[1];
  eml_F[2] /= eml_U[eml_r_1 + 5];
  eml_F[0] -= eml_U[eml_r + 5] * eml_F[2];
  eml_F[1] -= eml_U[eml_r_0 + 5] * eml_F[2];
  eml_F[1] /= eml_U[eml_r_0 + 2];
  eml_F[0] -= eml_U[eml_r + 2] * eml_F[1];
  eml_F[0] /= eml_U[eml_r - 1];
  eml_F[3] = eml_V[eml_r + 2];
  eml_F[4] = eml_V[eml_r_0 + 2] - eml_U[eml_r_0 - 1] * eml_F[3];
  eml_F[5] = (eml_V[eml_r_1 + 2] - eml_U[eml_r_1 - 1] * eml_F[3]) -
    eml_U[eml_r_1 + 2] * eml_F[4];
  eml_F[5] /= eml_U[eml_r_1 + 5];
  eml_F[3] -= eml_U[eml_r + 5] * eml_F[5];
  eml_F[4] -= eml_U[eml_r_0 + 5] * eml_F[5];
  eml_F[4] /= eml_U[eml_r_0 + 2];
  eml_F[3] -= eml_U[eml_r + 2] * eml_F[4];
  eml_F[3] /= eml_U[eml_r - 1];
  eml_F[6] = eml_V[eml_r + 5];
  eml_F[7] = eml_V[eml_r_0 + 5] - eml_U[eml_r_0 - 1] * eml_F[6];
  eml_F[8] = (eml_V[eml_r_1 + 5] - eml_U[eml_r_1 - 1] * eml_F[6]) -
    eml_U[eml_r_1 + 2] * eml_F[7];
  eml_F[8] /= eml_U[eml_r_1 + 5];
  eml_F[6] -= eml_U[eml_r + 5] * eml_F[8];
  eml_F[7] -= eml_U[eml_r_0 + 5] * eml_F[8];
  eml_F[7] /= eml_U[eml_r_0 + 2];
  eml_F[6] -= eml_U[eml_r + 2] * eml_F[7];
  eml_F[6] /= eml_U[eml_r - 1];
}

/* Function for Embedded MATLAB: '<Root>/GetLegLen' */
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
  real_T eml_x_delta[3];
  real_T eml_p_in_w[9];
  real_T eml_beta_cmd;
  real_T eml_post_flex_angle[2];
  real_T eml_rho_vec[9];
  real_T eml_flexure_frame_rot_angle;
  real_T eml_x[3];
  int32_T eml_k;
  real_T eml_s;
  uint32_T eml_b_j;
  int32_T eml_eint;
  boolean_T eml_exitg;
  boolean_T eml_x_0[3];
  int8_T eml_c_y[3];
  boolean_T eml_exitg_0;
  real_T eml_eta[6];
  real_T eml_a[6];
  real_T eml_h_c;
  real_T eml_i_c;
  int32_T uIdx;
  int32_T k;
  int32_T idxN;
  int32_T cff;
  int32_T j;
  real_T tmp[3];
  real_T tmp_0[3];
  real_T eml_rho_vec_0[9];
  real_T tmp_1[9];
  real_T tmp_2[9];
  real_T tmp_3[3];
  real_T tmp_4[3];
  real_T eml_x_1;
  real_T unnamed_idx;
  static real_T tmp_5[5] = { 1.4955852179582920E-002, 2.5393983300632300E-001,
    9.5041789961629319E-001, 2.0978479612570680E+000, 5.3719203511481517E+000 };

  static real_T tmp_6[9] = { 6.1283555449518239E+001, -5.1423008774923140E+001,
    0.0, 1.3891854213354433E+001, 7.8784620240976636E+001, 0.0,
    -7.5175409662872681E+001, -2.7361611466053493E+001, 0.0 };

  static int8_T tmp_7[9] = { 0, 1, 0, -1, 0, 0, 0, 0, 0 };

  static real_T tmp_8[9] = { 1.4057324354229004E+002, -8.1160000000000068E+001,
    0.0, 9.9392334218799176E-015, 1.6232E+002, 0.0, -1.4057324354229007E+002,
    -8.1160000000000011E+001, 0.0 };

  static real_T tmp_9[9] = { 3.8971143170299726E+001, -2.2500000000000021E+001,
    0.0, 2.7554552980815448E-015, 45.0, 0.0, -3.8971143170299740E+001,
    -2.2500000000000004E+001, 0.0 };

  static real_T tmp_a[9] = { -2.6438059510305436E+000, -1.1617982402004897E+001,
    0.0, 1.1383370876372062E+001, 3.5193880847335253E+000, 0.0,
    -8.7395649253415257E+000, 8.0985943172713704E+000, 0.0 };

  static int8_T tmp_b[5] = { 3, 5, 7, 9, 13 };

  static real_T tmp_c[3] = { 2.258E+002, 2.263E+002, 224.5 };

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

    /* DiscreteFir: '<S16>/Discrete FIR Filter' incorporates:
     *  Constant: '<S16>/vel_filter_coeffs'
     */
    uIdx = 0;
    for (k = 0; k < 6; k++) {
      idxN = twa_parallel_DWork.DiscreteFIRFilter_circBuf;
      eml_flexure_frame_rot_angle =
        twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx] *
        twa_parallel_P.vel_filter_coeffs_Value[0];
      uIdx++;
      cff = 1;
      for (j = idxN; j < 1; j++) {
        eml_k = k + j;
        eml_flexure_frame_rot_angle +=
          twa_parallel_DWork.DiscreteFIRFilter_states[eml_k] *
          twa_parallel_P.vel_filter_coeffs_Value[cff];
        cff++;
      }

      for (j = 0; j < idxN; j++) {
        eml_k = k + j;
        eml_flexure_frame_rot_angle +=
          twa_parallel_DWork.DiscreteFIRFilter_states[eml_k] *
          twa_parallel_P.vel_filter_coeffs_Value[cff];
        cff++;
      }

      twa_parallel_B.DiscreteFIRFilter[k] = eml_flexure_frame_rot_angle;
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

    /* ok to acquire for <S22>/S-Function */
    twa_parallel_DWork.SFunction_IWORK.AcquireOK = 1;

    /* DiscreteFir: '<S20>/Discrete FIR Filter' incorporates:
     *  Constant: '<S20>/vel_filter_coeffs'
     */
    uIdx = 0;
    for (k = 0; k < 6; k++) {
      idxN = twa_parallel_DWork.DiscreteFIRFilter_circBuf_l;
      eml_flexure_frame_rot_angle =
        twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx] *
        twa_parallel_P.vel_filter_coeffs_Value_m[0];
      uIdx++;
      cff = 1;
      for (j = idxN; j < 1; j++) {
        eml_k = k + j;
        eml_flexure_frame_rot_angle +=
          twa_parallel_DWork.DiscreteFIRFilter_states_m[eml_k] *
          twa_parallel_P.vel_filter_coeffs_Value_m[cff];
        cff++;
      }

      for (j = 0; j < idxN; j++) {
        eml_k = k + j;
        eml_flexure_frame_rot_angle +=
          twa_parallel_DWork.DiscreteFIRFilter_states_m[eml_k] *
          twa_parallel_P.vel_filter_coeffs_Value_m[cff];
        cff++;
      }

      twa_parallel_B.DiscreteFIRFilter_h[k] = eml_flexure_frame_rot_angle;
    }

    /* Gain: '<S20>/Gain' */
    for (uIdx = 0; uIdx < 6; uIdx++) {
      twa_parallel_B.Gain_n[uIdx] = twa_parallel_P.Gain_Gain_d *
        twa_parallel_B.DiscreteFIRFilter_h[uIdx];
    }

    /* ok to acquire for <S21>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_j.AcquireOK = 1;

    /* ok to acquire for <S23>/S-Function */
    twa_parallel_DWork.SFunction_IWORK_i.AcquireOK = 1;

    /* Embedded MATLAB: '<Root>/GetLegLen' incorporates:
     *  Constant: '<Root>/ee_rot'
     *  Constant: '<Root>/x_des'
     */
    /* Embedded MATLAB Function 'GetLegLen': '<S2>:1' */
    /*  This function solves for the vertex positions of the base and moving */
    /*  platform for a given desired end effector position. */
    /*  With vertex positions known, leg lengths can be solved for. */
    /*  initialization */
    /* '<S2>:1:7' */
    /* [mm] */
    /* '<S2>:1:8' */
    /* '<S2>:1:9' */
    /* '<S2>:1:10' */
    /* '<S2>:1:11' */

    /* UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_B.UnitDelay1[0] = twa_parallel_DWork.UnitDelay1_DSTATE[0];

    /* UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_B.UnitDelay2[0] = twa_parallel_DWork.UnitDelay2_DSTATE[0];

    /* UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_B.UnitDelay[0] = twa_parallel_DWork.UnitDelay_DSTATE[0];
    twa_parallel_B.macro_leg_len[0] = twa_parallel_B.UnitDelay1[0];
    twa_parallel_B.micro_leg_len[0] = twa_parallel_B.UnitDelay2[0];
    eml_x_1 = twa_parallel_P.x_des_Value[0] - twa_parallel_B.UnitDelay[0];
    eml_x_delta[0] = fabs(eml_x_1);
    eml_x[0] = eml_x_1;

    /* UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_B.UnitDelay1[1] = twa_parallel_DWork.UnitDelay1_DSTATE[1];

    /* UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_B.UnitDelay2[1] = twa_parallel_DWork.UnitDelay2_DSTATE[1];

    /* UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_B.UnitDelay[1] = twa_parallel_DWork.UnitDelay_DSTATE[1];
    twa_parallel_B.macro_leg_len[1] = twa_parallel_B.UnitDelay1[1];
    twa_parallel_B.micro_leg_len[1] = twa_parallel_B.UnitDelay2[1];
    eml_x_1 = twa_parallel_P.x_des_Value[1] - twa_parallel_B.UnitDelay[1];
    eml_x_delta[1] = fabs(eml_x_1);
    eml_x[1] = eml_x_1;

    /* UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_B.UnitDelay1[2] = twa_parallel_DWork.UnitDelay1_DSTATE[2];

    /* UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_B.UnitDelay2[2] = twa_parallel_DWork.UnitDelay2_DSTATE[2];

    /* UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_B.UnitDelay[2] = twa_parallel_DWork.UnitDelay_DSTATE[2];
    twa_parallel_B.macro_leg_len[2] = twa_parallel_B.UnitDelay1[2];
    twa_parallel_B.micro_leg_len[2] = twa_parallel_B.UnitDelay2[2];
    eml_x_1 = twa_parallel_P.x_des_Value[2] - twa_parallel_B.UnitDelay[2];
    eml_x_delta[2] = fabs(eml_x_1);
    eml_x[2] = eml_x_1;

    /* '<S2>:1:13' */
    /* [mm] */
    /*  moving platform radius */
    /* [mm] */
    /*  base radius */
    /*  158.04; %[mm] */
    /*  rotation matrix of moving frame about z-xis */
    /* '<S2>:1:22' */
    /*  moving platform vertex locations */
    /*  x_des = zeros(3,1); */
    /* '<S2>:1:29' */
    eml_rho_vec_0[0] = cos(twa_parallel_P.ee_rot_Value);
    eml_rho_vec_0[3] = -sin(twa_parallel_P.ee_rot_Value);
    eml_rho_vec_0[6] = 0.0;
    eml_rho_vec_0[1] = sin(twa_parallel_P.ee_rot_Value);
    eml_rho_vec_0[4] = cos(twa_parallel_P.ee_rot_Value);
    eml_rho_vec_0[7] = 0.0;
    eml_rho_vec_0[2] = 0.0;
    eml_rho_vec_0[5] = 0.0;
    eml_rho_vec_0[8] = 1.0;
    for (uIdx = 0; uIdx < 3; uIdx++) {
      tmp_1[uIdx] = 0.0;
      tmp_1[uIdx] += twa_parallel_P.x_des_Value[uIdx];
      tmp_1[uIdx + 3] = 0.0;
      tmp_1[uIdx + 3] += twa_parallel_P.x_des_Value[uIdx];
      tmp_1[uIdx + 6] = 0.0;
      tmp_1[uIdx + 6] += twa_parallel_P.x_des_Value[uIdx];
    }

    for (uIdx = 0; uIdx < 3; uIdx++) {
      for (idxN = 0; idxN < 3; idxN++) {
        tmp_2[uIdx + 3 * idxN] = 0.0;
        tmp_2[uIdx + 3 * idxN] = tmp_2[3 * idxN + uIdx] + tmp_9[3 * idxN] *
          eml_rho_vec_0[uIdx];
        tmp_2[uIdx + 3 * idxN] = tmp_9[3 * idxN + 1] * eml_rho_vec_0[uIdx + 3] +
          tmp_2[3 * idxN + uIdx];
        tmp_2[uIdx + 3 * idxN] = tmp_9[3 * idxN + 2] * eml_rho_vec_0[uIdx + 6] +
          tmp_2[3 * idxN + uIdx];
      }
    }

    for (uIdx = 0; uIdx < 3; uIdx++) {
      eml_p_in_w[3 * uIdx] = tmp_1[3 * uIdx] + tmp_2[3 * uIdx];
      eml_p_in_w[1 + 3 * uIdx] = tmp_1[3 * uIdx + 1] + tmp_2[3 * uIdx + 1];
      eml_p_in_w[2 + 3 * uIdx] = tmp_1[3 * uIdx + 2] + tmp_2[3 * uIdx + 2];
    }

    /*  base vertex positions */
    /* '<S2>:1:32' */
    /*  position of flexure centers */
    /*  radius of position of flexure center */
    /* [mm] */
    /* '<S2>:1:38' */
    /*  position of twa pivot point, taken from CAD */
    /*  radius of position of twa pivot */
    /* '<S2>:1:44' */
    if ((eml_x_delta[0] > 0.5) || (eml_x_delta[1] > 0.5)) {
      /* '<S2>:1:46' */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /*    Macro Actuator Leg Lengths % */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
      /* '<S2>:1:51' */
      for (uIdx = 0; uIdx < 9; uIdx++) {
        eml_rho_vec[uIdx] = eml_p_in_w[uIdx] - tmp_8[uIdx];
      }

      /* '<S2>:1:53' */
      twa_parallel_B.macro_leg_len[0] = 0.0;
      twa_parallel_B.macro_leg_len[1] = 0.0;
      twa_parallel_B.macro_leg_len[2] = 0.0;

      /* '<S2>:1:54' */
      twa_parallel_B.macro_leg_len[0] = twa_parallel_norm(*((real_T (*)[3])&
        eml_rho_vec[0]));

      /* '<S2>:1:55' */
      twa_parallel_B.macro_leg_len[1] = twa_parallel_norm(*((real_T (*)[3])&
        eml_rho_vec[3]));

      /* '<S2>:1:56' */
      twa_parallel_B.macro_leg_len[2] = twa_parallel_norm(*((real_T (*)[3])&
        eml_rho_vec[6]));
    } else {
      if ((eml_x_delta[0] < 0.5) || (eml_x_delta[1] < 0.5)) {
        /* '<S2>:1:58' */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*    Micro Actuator Leg Lengths % */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /* * */
        /*  loop through each vertex */
        /* * */
        /* '<S2>:1:66' */
        for (k = 0; k < 3; k++) {
          /* '<S2>:1:66' */
          /* '<S2>:1:67' */
          eml_beta_cmd = 8.7266462599716474E-002;

          /* '<S2>:1:68' */
          /* '<S2>:1:69' */
          eml_post_flex_angle[0] = 0.0;
          eml_post_flex_angle[1] = 0.0;

          /*  vector from flexure center to moving platform vertex */
          /* '<S2>:1:72' */
          /*  distance between flexure and moving platform verteces */
          /* '<S2>:1:75' */
          for (uIdx = 0; uIdx < 9; uIdx++) {
            eml_x_1 = eml_p_in_w[uIdx] - tmp_6[uIdx];
            eml_rho_vec_0[uIdx] = eml_x_1;
            eml_rho_vec[uIdx] = eml_x_1;
          }

          twa_parallel_svd(eml_rho_vec_0, eml_x);
          eml_x_1 = eml_x[0];

          /*  vector from flexure center to base vertex pre flexure rotation */
          /*  magnitude of flexure swing-arm radius from flexure to base vertex */
          /*  angle from world horizontal to vector from flexure to platform vertex */
          /* '<S2>:1:84' */
          eml_flexure_frame_rot_angle = rt_atan2_snf(eml_rho_vec[1],
            eml_rho_vec[0]);

          /*  rotation matrix to flexure frame */
          /* '<S2>:1:89' */
          for (uIdx = 0; uIdx < 9; uIdx++) {
            eml_rho_vec[uIdx] = eml_flexure_frame_rot_angle * (real_T)tmp_7[uIdx];
          }

          eml_flexure_frame_rot_angle = 0.0;
          eml_k = 1;
          eml_exitg = FALSE;
          while (((uint32_T)eml_exitg == 0U) && (eml_k <= 3)) {
            eml_s = fabs(eml_rho_vec[(eml_k - 1) * 3]);
            eml_s += fabs(eml_rho_vec[(eml_k - 1) * 3 + 1]);
            eml_s += fabs(eml_rho_vec[(eml_k - 1) * 3 + 2]);
            if (rtIsNaN(eml_s)) {
              eml_flexure_frame_rot_angle = (rtNaN);
              eml_exitg = TRUE;
            } else {
              if (eml_s > eml_flexure_frame_rot_angle) {
                eml_flexure_frame_rot_angle = eml_s;
              }

              eml_k++;
            }
          }

          if (eml_flexure_frame_rot_angle <= 5.3719203511481517E+000) {
            eml_k = 1;
            eml_exitg = FALSE;
            while (((uint32_T)eml_exitg == 0U) && (eml_k <= 5)) {
              if (eml_flexure_frame_rot_angle <= tmp_5[eml_k - 1]) {
                memcpy((void *)&eml_rho_vec_0[0], (void *)&eml_rho_vec[0], 9U *
                       sizeof(real_T));
                twa_par_PadeApproximantOfDegree(eml_rho_vec_0, (real_T)
                  tmp_b[eml_k - 1], eml_rho_vec);
                eml_exitg = TRUE;
              } else {
                eml_k++;
              }
            }
          } else {
            eml_flexure_frame_rot_angle /= 5.3719203511481517E+000;
            if ((!rtIsInf(eml_flexure_frame_rot_angle)) && (!rtIsNaN
                 (eml_flexure_frame_rot_angle))) {
              frexp(eml_flexure_frame_rot_angle, &eml_eint);
              eml_flexure_frame_rot_angle = frexp(eml_flexure_frame_rot_angle,
                &eml_eint);
              eml_k = eml_eint;
            } else {
              eml_k = 0;
            }

            eml_s = (real_T)eml_k;
            if (eml_flexure_frame_rot_angle == 0.5) {
              eml_s = (real_T)eml_k - 1.0;
            }

            eml_flexure_frame_rot_angle = rt_pow_snf(2.0, eml_s);
            for (uIdx = 0; uIdx < 9; uIdx++) {
              eml_rho_vec_0[uIdx] = eml_rho_vec[uIdx] /
                eml_flexure_frame_rot_angle;
            }

            twa_par_PadeApproximantOfDegree(eml_rho_vec_0, 13.0, eml_rho_vec);
            for (eml_b_j = 1U; (real_T)eml_b_j <= eml_s; eml_b_j++) {
              for (uIdx = 0; uIdx < 3; uIdx++) {
                for (idxN = 0; idxN < 3; idxN++) {
                  eml_rho_vec_0[uIdx + 3 * idxN] = 0.0;
                  eml_rho_vec_0[uIdx + 3 * idxN] = eml_rho_vec_0[3 * idxN + uIdx]
                    + eml_rho_vec[3 * idxN] * eml_rho_vec[uIdx];
                  eml_rho_vec_0[uIdx + 3 * idxN] = eml_rho_vec[3 * idxN + 1] *
                    eml_rho_vec[uIdx + 3] + eml_rho_vec_0[3 * idxN + uIdx];
                  eml_rho_vec_0[uIdx + 3 * idxN] = eml_rho_vec[3 * idxN + 2] *
                    eml_rho_vec[uIdx + 6] + eml_rho_vec_0[3 * idxN + uIdx];
                }
              }

              for (uIdx = 0; uIdx < 3; uIdx++) {
                eml_rho_vec[3 * uIdx] = eml_rho_vec_0[3 * uIdx];
                eml_rho_vec[1 + 3 * uIdx] = eml_rho_vec_0[3 * uIdx + 1];
                eml_rho_vec[2 + 3 * uIdx] = eml_rho_vec_0[3 * uIdx + 2];
              }
            }
          }

          /*  condition for acos solvability */
          /* '<S2>:1:92' */
          eml_flexure_frame_rot_angle = ((rt_pow_snf(twa_parallel_B.UnitDelay1[k],
            2.0) - rt_pow_snf(eml_x_1, 2.0)) - 1.0756714927454021E+004) / (-2.0 *
            eml_x_1 * 1.0371458396702954E+002);
          if ((eml_flexure_frame_rot_angle >= -1.0) &&
              (eml_flexure_frame_rot_angle <= 1.0)) {
            /* '<S2>:1:94' */
            /*  calculate angle between mf and fb vectors, lambda, with */
            /*  law of cosines */
            /* '<S2>:1:97' */
            eml_flexure_frame_rot_angle = acos(eml_flexure_frame_rot_angle);

            /*  calculate flexed base vertex position for both elbow up */
            /*  and down configurations */
            /* '<S2>:1:101' */
            /* '<S2>:1:102' */
            /* '<S2>:1:104' */
            eml_x_1 = cos(-eml_flexure_frame_rot_angle);
            eml_s = sin(-eml_flexure_frame_rot_angle);
            unnamed_idx = 1.0371458396702954E+002 * eml_x_1;
            eml_s *= 1.0371458396702954E+002;

            /* '<S2>:1:105' */
            tmp_3[0] = cos(eml_flexure_frame_rot_angle);
            tmp_3[1] = sin(eml_flexure_frame_rot_angle);
            tmp_3[2] = 0.0;
            for (uIdx = 0; uIdx < 3; uIdx++) {
              eml_x_1 = eml_rho_vec[uIdx] * unnamed_idx;
              eml_x_1 += eml_rho_vec[uIdx + 3] * eml_s;
              eml_x_1 += eml_rho_vec[uIdx + 6] * 0.0;
              tmp_4[uIdx] = 1.0371458396702954E+002 * tmp_3[uIdx];
              eml_x[uIdx] = eml_x_1;
            }

            for (uIdx = 0; uIdx < 3; uIdx++) {
              eml_x_1 = eml_rho_vec[uIdx] * tmp_4[0];
              eml_x_1 += eml_rho_vec[uIdx + 3] * tmp_4[1];
              eml_x_1 += eml_rho_vec[uIdx + 6] * tmp_4[2];
              eml_x_delta[uIdx] = eml_x_1;
            }

            /*  may not need these at all */
            /*                  b_prime_in_w(:,1) = f_in_w + eta_prime_vec_dwn; */
            /*                  b_prime_in_w(:,2) = f_in_w + eta_prime_vec_up; */
            /* '<S2>:1:111' */
            /* '<S2>:1:113' */
            eml_post_flex_angle[0] = rt_atan2_snf(eml_x[1], eml_x[0]);

            /* '<S2>:1:114' */
            eml_post_flex_angle[1] = rt_atan2_snf(eml_x_delta[1], eml_x_delta[0]);

            /* * */
            /*  determine if flex angle is within mechanical range */
            /* * */
            /* '<S2>:1:119' */
            if (eml_post_flex_angle[k] < 0.0) {
              /* '<S2>:1:120' */
              /* '<S2>:1:121' */
              eml_x_1 = 3.5880780152813718E-001 - -1.0 * eml_post_flex_angle[0];
            } else {
              /* '<S2>:1:123' */
              eml_x_1 = -3.5880780152813718E-001 - eml_post_flex_angle[0];
            }

            if ((eml_x_1 >= -1.7453292519943295E-001) && (eml_x_1 <=
                 1.7453292519943295E-001)) {
              /* '<S2>:1:126' */
              /* '<S2>:1:127' */
              eml_beta_cmd = eml_x_1;
            }

            /* '<S2>:1:119' */
            if (eml_post_flex_angle[k] < 0.0) {
              /* '<S2>:1:120' */
              /* '<S2>:1:121' */
              eml_x_1 = 3.5880780152813718E-001 - -1.0 * eml_post_flex_angle[1];
            } else {
              /* '<S2>:1:123' */
              eml_x_1 = -3.5880780152813718E-001 - eml_post_flex_angle[1];
            }

            if ((eml_x_1 >= -1.7453292519943295E-001) && (eml_x_1 <=
                 1.7453292519943295E-001)) {
              /* '<S2>:1:126' */
              /* '<S2>:1:127' */
              eml_beta_cmd = eml_x_1;
            }
          }

          /*  calculate initial angle prior to flexure bend */
          /* '<S2>:1:134' */
          tmp_0[0] = tmp_6[3 * k] - tmp_a[3 * k];
          tmp[0] = tmp_6[3 * k] - tmp_8[3 * k];
          tmp_0[1] = tmp_6[3 * k + 1] - tmp_a[3 * k + 1];
          tmp[1] = tmp_6[3 * k + 1] - tmp_8[3 * k + 1];
          tmp_0[2] = tmp_6[3 * k + 2] - tmp_a[3 * k + 2];
          tmp[2] = tmp_6[3 * k + 2] - tmp_8[3 * k + 2];
          eml_flexure_frame_rot_angle = twa_parallel_norm(tmp_0);

          /* '<S2>:1:135' */
          eml_s = twa_parallel_norm(tmp);

          /* '<S2>:1:136' */
          /* '<S2>:1:137' */
          /*  calculate required twa length to facilitate flexure bend */
          /* '<S2>:1:140' */
          twa_parallel_B.micro_leg_len[k] = sqrt((rt_pow_snf
            (eml_flexure_frame_rot_angle, 2.0) - rt_pow_snf(eml_s, 2.0)) - cos
            (acos(((rt_pow_snf(tmp_c[k], 2.0) - rt_pow_snf
                    (eml_flexure_frame_rot_angle, 2.0)) - rt_pow_snf(eml_s, 2.0))
                  / (-2.0 * eml_flexure_frame_rot_angle * eml_s)) - eml_beta_cmd)
            * (2.0 * eml_flexure_frame_rot_angle * eml_s));
        }
      }
    }

    /* SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport3' */
    twa_parallel_B.TmpSignalConversionAtSFunctio_i[0] =
      twa_parallel_B.gear_ratio;
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
    /*  if required velmex motion is less than 0.5 mm, do not move velmex */
    /* '<S3>:1:6' */
    /* '<S3>:1:8' */
    /* '<S3>:1:10' */
    /* +-30 mm stroke from starting point at the velmex pivot  */
    /* '<S3>:1:12' */
    /* '<S3>:1:14' */
    twa_parallel_B.x_cur[0] = twa_parallel_P.x_des_Value[0];
    twa_parallel_B.qmacro_des[0] =
      twa_parallel_B.TmpSignalConversionAtSFunctio_i[0];
    eml_x[0] = 0.0;
    twa_parallel_B.x_cur[1] = twa_parallel_P.x_des_Value[1];
    twa_parallel_B.qmacro_des[1] =
      twa_parallel_B.TmpSignalConversionAtSFunctio_i[1];
    eml_x[1] = 0.0;
    twa_parallel_B.x_cur[2] = twa_parallel_P.x_des_Value[2];
    twa_parallel_B.qmacro_des[2] =
      twa_parallel_B.TmpSignalConversionAtSFunctio_i[2];
    eml_x[2] = 0.0;

    /* '<S3>:1:15' */
    eml_x[0] = 1.30115E+002 - twa_parallel_B.macro_leg_len[0];

    /* '<S3>:1:16' */
    eml_x[1] = 1.2905E+002 - twa_parallel_B.macro_leg_len[1];

    /* '<S3>:1:17' */
    eml_x[2] = 130.495 - twa_parallel_B.macro_leg_len[2];
    eml_x_1 = fabs(eml_x[0]);
    eml_x_0[0] = (eml_x_1 < 30.0);
    eml_x_1 = fabs(eml_x[1]);
    eml_x_0[1] = (eml_x_1 < 30.0);
    eml_x_1 = fabs(eml_x[2]);
    eml_x_0[2] = (eml_x_1 < 30.0);
    eml_exitg = TRUE;
    eml_k = 1;
    eml_exitg_0 = FALSE;
    while (((uint32_T)eml_exitg_0 == 0U) && (eml_k <= 3)) {
      if ((int32_T)eml_x_0[eml_k - 1] == 0) {
        eml_exitg = FALSE;
        eml_exitg_0 = TRUE;
      } else {
        eml_k++;
      }
    }

    if (eml_exitg) {
      eml_exitg = (eml_x[0] < 0.5);
      eml_c_y[0] = eml_exitg;
      eml_exitg = (eml_x[1] < 0.5);
      eml_c_y[1] = eml_exitg;
      eml_exitg = (eml_x[2] < 0.5);
      eml_c_y[2] = eml_exitg;
      eml_exitg = TRUE;
      eml_k = 1;
      eml_exitg_0 = FALSE;
      while (((uint32_T)eml_exitg_0 == 0U) && (eml_k <= 3)) {
        if (eml_c_y[eml_k - 1] == 0) {
          eml_exitg = FALSE;
          eml_exitg_0 = TRUE;
        } else {
          eml_k++;
        }
      }

      if (eml_exitg) {
        /* '<S3>:1:21' */
        twa_parallel_B.qmacro_des[0] = eml_x[0] /
          twa_parallel_P.ee_velmex_pitch_Value;
        twa_parallel_B.qmacro_des[1] = eml_x[1] /
          twa_parallel_P.ee_velmex_pitch_Value;
        twa_parallel_B.qmacro_des[2] = eml_x[2] /
          twa_parallel_P.ee_velmex_pitch_Value;
      }
    }

    /* SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport1' */
    twa_parallel_B.TmpSignalConversionAtSFunctio_e[0] =
      twa_parallel_B.gear_ratio;
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
     *  Constant: '<Root>/twa_actuation'
     */
    /* Embedded MATLAB Function 'GetMicroQDes': '<S4>:1' */
    /*  This function solves for command signal for the twa's given a desired */
    /*  micro leg length */
    /* '<S4>:1:5' */
    /* '<S4>:1:7' */
    /* [mm] */
    /* '<S4>:1:10' */
    twa_parallel_B.qmicro_des[0] =
      twa_parallel_B.TmpSignalConversionAtSFunctio_e[3];
    eml_x[0] = 0.0;
    twa_parallel_B.qmicro_des[1] =
      twa_parallel_B.TmpSignalConversionAtSFunctio_e[4];
    eml_x[1] = 0.0;
    twa_parallel_B.qmicro_des[2] =
      twa_parallel_B.TmpSignalConversionAtSFunctio_e[5];
    eml_x[2] = 0.0;

    /* '<S4>:1:11' */
    eml_x[0] = 2.258E+002 - twa_parallel_P.twa_actuation_Value[0];

    /* '<S4>:1:12' */
    eml_x[1] = 2.263E+002 - twa_parallel_P.twa_actuation_Value[1];

    /* '<S4>:1:13' */
    eml_x[2] = 224.5 - twa_parallel_P.twa_actuation_Value[2];

    /* '<S4>:1:15' */
    twa_parallel_B.qmicro_des[0] = sqrt((5.0985640000000007E+004 - rt_pow_snf
      (eml_x[0], 2.0)) / 1.9516089999999996E-002);

    /* [rad] */
    /* '<S4>:1:16' */
    twa_parallel_B.qmicro_des[1] = sqrt((5.121169E+004 - rt_pow_snf(eml_x[1],
      2.0)) / 1.9516089999999996E-002);

    /* '<S4>:1:17' */
    twa_parallel_B.qmicro_des[2] = sqrt((50400.25 - rt_pow_snf(eml_x[2], 2.0)) /
      1.9516089999999996E-002);

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
      twa_parallel_B.Switch[3] = twa_parallel_B.micro_leg_len[0];
      twa_parallel_B.Switch[4] = twa_parallel_B.micro_leg_len[1];
      twa_parallel_B.Switch[5] = twa_parallel_B.micro_leg_len[2];
    } else {
      for (uIdx = 0; uIdx < 6; uIdx++) {
        twa_parallel_B.Switch[uIdx] = twa_parallel_P.q_des_Value[uIdx];
      }
    }

    /* DigitalClock: '<S6>/Digital Clock' */
    twa_parallel_B.DigitalClock = twa_parallel_rtM->Timing.t[1];

    /* UnitDelay: '<S6>/Unit Delay' */
    twa_parallel_B.UnitDelay_k = twa_parallel_DWork.UnitDelay_DSTATE_e;

    /* UnitDelay: '<S6>/Unit Delay1' */
    twa_parallel_B.UnitDelay1_b = twa_parallel_DWork.UnitDelay1_DSTATE_h;

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
      twa_parallel_B.UnitDelay2_n[uIdx] =
        twa_parallel_DWork.UnitDelay2_DSTATE_k[uIdx];

      /* Switch: '<S19>/Switch' */
      if (twa_parallel_B.NSampleEnable) {
        twa_parallel_B.Switch_f[uIdx] =
          twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx];
      } else {
        twa_parallel_B.Switch_f[uIdx] = twa_parallel_B.UnitDelay2_n[uIdx];
      }

      eml_eta[uIdx] = twa_parallel_B.Switch[uIdx] - twa_parallel_B.Switch_f[uIdx];
    }

    if (twa_parallel_P.quintic_enable_Value != 0.0) {
      for (uIdx = 0; uIdx < 6; uIdx++) {
        eml_a[uIdx] = eml_eta[uIdx];
      }

      eml_flexure_frame_rot_angle = 0.0;
      eml_k = 1;
      uIdx = 1;
      for (k = 0; k < 6; k++) {
        eml_flexure_frame_rot_angle += eml_a[eml_k - 1] * eml_eta[uIdx - 1];
        eml_k++;
        uIdx++;
      }

      if (eml_flexure_frame_rot_angle > 0.0) {
        /* '<S18>:1:9' */
        /*  conf = 0 means that the 5th order poly */
        /*  is not configured for the desired trajectory. */
        /*  Therefore, the block is initialized. */
        if (twa_parallel_B.UnitDelay_k == 0.0) {
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
          twa_parallel_B.t0n = twa_parallel_B.UnitDelay1_b;

          /* '<S18>:1:23' */
          twa_parallel_B.confn = twa_parallel_B.UnitDelay_k;

          /*  5th order polynomial */
          /* '<S18>:1:27' */
          /* '<S18>:1:28' */
          /* '<S18>:1:29' */
          for (uIdx = 0; uIdx < 6; uIdx++) {
            eml_x_1 = eml_eta[uIdx];
            twa_parallel_B.q0n[uIdx] = twa_parallel_B.Switch_f[uIdx];
            eml_x_1 *= -15.0;
            twa_parallel_B.q_dub_dot[uIdx] = -6.6666666666666663E-001 * eml_x_1;
            eml_a[uIdx] = -0.4 * eml_x_1;
            eml_eta[uIdx] = eml_x_1;
          }

          /* '<S18>:1:30' */
          unnamed_idx = twa_parallel_B.DigitalClock -
            twa_parallel_B.UnitDelay1_b;

          /* '<S18>:1:31' */
          eml_flexure_frame_rot_angle = unnamed_idx / twa_parallel_P.tf_Value;
          if (unnamed_idx < twa_parallel_P.tf_Value) {
            /* '<S18>:1:33' */
            /* '<S18>:1:34' */
            twa_parallel_B.robot_mov = 1.0;

            /* '<S18>:1:35' */
            eml_s = rt_pow_snf(eml_flexure_frame_rot_angle, 3.0);
            eml_x_1 = rt_pow_snf(eml_flexure_frame_rot_angle, 4.0);
            eml_flexure_frame_rot_angle = rt_pow_snf(eml_flexure_frame_rot_angle,
              5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_cmd[uIdx] = ((twa_parallel_B.q_dub_dot[uIdx] *
                eml_s + twa_parallel_B.Switch_f[uIdx]) + eml_eta[uIdx] * eml_x_1)
                + eml_a[uIdx] * eml_flexure_frame_rot_angle;
            }

            /* '<S18>:1:36' */
            eml_flexure_frame_rot_angle = rt_pow_snf(unnamed_idx, 2.0);
            eml_s = rt_pow_snf(twa_parallel_P.tf_Value, 3.0);
            eml_x_1 = rt_pow_snf(unnamed_idx, 3.0);
            eml_beta_cmd = rt_pow_snf(twa_parallel_P.tf_Value, 4.0);
            eml_h_c = rt_pow_snf(unnamed_idx, 4.0);
            eml_i_c = rt_pow_snf(twa_parallel_P.tf_Value, 5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_dot[uIdx] = (3.0 * twa_parallel_B.q_dub_dot[uIdx]
                * eml_flexure_frame_rot_angle / eml_s + 4.0 * eml_eta[uIdx] *
                eml_x_1 / eml_beta_cmd) + 5.0 * eml_a[uIdx] * eml_h_c / eml_i_c;
            }

            /* '<S18>:1:37' */
            eml_flexure_frame_rot_angle = rt_pow_snf(twa_parallel_P.tf_Value,
              3.0);
            eml_s = rt_pow_snf(unnamed_idx, 2.0);
            eml_x_1 = rt_pow_snf(twa_parallel_P.tf_Value, 4.0);
            eml_beta_cmd = rt_pow_snf(unnamed_idx, 3.0);
            eml_h_c = rt_pow_snf(twa_parallel_P.tf_Value, 5.0);
            for (uIdx = 0; uIdx < 6; uIdx++) {
              twa_parallel_B.q_dub_dot[uIdx] = (6.0 *
                twa_parallel_B.q_dub_dot[uIdx] * unnamed_idx /
                eml_flexure_frame_rot_angle + 12.0 * eml_eta[uIdx] * eml_s /
                eml_x_1) + 20.0 * eml_a[uIdx] * eml_beta_cmd / eml_h_c;
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
        twa_parallel_B.t0n = twa_parallel_B.UnitDelay1_b;
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
      /* Sum: '<S5>/Sum' */
      twa_parallel_B.Sum[uIdx] = twa_parallel_B.q_cmd[uIdx] -
        twa_parallel_B.TmpSignalConversionAtDiscreteFI[uIdx];

      /* Gain: '<S5>/Kp' */
      twa_parallel_B.Kp[uIdx] = twa_parallel_P.Kp_Gain[uIdx] *
        twa_parallel_B.Sum[uIdx];
    }
  }

  /* Integrator: '<S5>/Integrator' */
  for (uIdx = 0; uIdx < 6; uIdx++) {
    twa_parallel_B.Integrator[uIdx] = twa_parallel_X.Integrator_CSTATE[uIdx];
  }

  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
    for (uIdx = 0; uIdx < 6; uIdx++) {
      /* Saturate: '<S5>/Saturation' incorporates:
       *  Saturate: '<S5>/saturate_int'
       */

      /* Gain: '<S5>/Ki' */
      twa_parallel_B.Ki[uIdx] = twa_parallel_P.Ki_Gain[uIdx] *
        twa_parallel_B.Integrator[uIdx];
      eml_x_1 = twa_parallel_B.Ki[uIdx];
      twa_parallel_B.saturate_int[uIdx] = rt_SATURATE(eml_x_1,
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

      /* Gain: '<S5>/Kd' */
      twa_parallel_B.Kd[uIdx] = twa_parallel_P.Kd_Gain[uIdx] *
        twa_parallel_B.Diff_d[uIdx];

      /* Sum: '<S5>/Add' */
      twa_parallel_B.Add[uIdx] = (twa_parallel_B.Kp[uIdx] +
        twa_parallel_B.saturate_int[uIdx]) + twa_parallel_B.Kd[uIdx];
      eml_x_1 = twa_parallel_B.Add[uIdx];
      twa_parallel_B.Saturation[uIdx] = rt_SATURATE(eml_x_1,
        twa_parallel_P.Saturation_LowerSat[uIdx],
        twa_parallel_P.Saturation_UpperSat[uIdx]);

      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S5>/manual_current'
       *  Constant: '<S5>/pid_mode'
       */
      if (twa_parallel_P.pid_mode_Value != 0.0) {
        twa_parallel_B.Switch_i[uIdx] = twa_parallel_B.Saturation[uIdx];
      } else {
        twa_parallel_B.Switch_i[uIdx] = twa_parallel_P.manual_current_Value[uIdx];
      }
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
  if (rtmIsMajorTimeStep(twa_parallel_rtM)) {
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

    /* Update for UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE[0] = twa_parallel_B.macro_leg_len[0];

    /* Update for UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_DWork.UnitDelay2_DSTATE[0] = twa_parallel_B.micro_leg_len[0];

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE[0] = twa_parallel_B.x_cur[0];

    /* Update for UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE[1] = twa_parallel_B.macro_leg_len[1];

    /* Update for UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_DWork.UnitDelay2_DSTATE[1] = twa_parallel_B.micro_leg_len[1];

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE[1] = twa_parallel_B.x_cur[1];

    /* Update for UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE[2] = twa_parallel_B.macro_leg_len[2];

    /* Update for UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_DWork.UnitDelay2_DSTATE[2] = twa_parallel_B.micro_leg_len[2];

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE[2] = twa_parallel_B.x_cur[2];

    /* Update for UnitDelay: '<S6>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE_e = twa_parallel_B.confn;

    /* Update for UnitDelay: '<S6>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE_h = twa_parallel_B.t0n;
    for (k = 0; k < 6; k++) {
      /* Update for UnitDelay: '<S6>/Unit Delay2' */
      twa_parallel_DWork.UnitDelay2_DSTATE_k[k] = twa_parallel_B.q0n[k];

      /* Update for UnitDelay: '<S17>/UD' */
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
  int32_T i;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  for (i = 0; i < 6; i++) {
    ((StateDerivatives_twa_parallel *) twa_parallel_rtM->ModelData.derivs)
      ->Integrator_CSTATE[i] = twa_parallel_B.Sum[i];
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
  twa_parallel_rtM->Sizes.checksums[0] = (578991209U);
  twa_parallel_rtM->Sizes.checksums[1] = (2496754609U);
  twa_parallel_rtM->Sizes.checksums[2] = (1142300911U);
  twa_parallel_rtM->Sizes.checksums[3] = (4244654368U);

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
      twa_parallel_B.UnitDelay2_n[i] = 0.0;
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
    twa_parallel_B.UnitDelay1[0] = 0.0;
    twa_parallel_B.UnitDelay1[1] = 0.0;
    twa_parallel_B.UnitDelay1[2] = 0.0;
    twa_parallel_B.UnitDelay2[0] = 0.0;
    twa_parallel_B.UnitDelay2[1] = 0.0;
    twa_parallel_B.UnitDelay2[2] = 0.0;
    twa_parallel_B.UnitDelay[0] = 0.0;
    twa_parallel_B.UnitDelay[1] = 0.0;
    twa_parallel_B.UnitDelay[2] = 0.0;
    twa_parallel_B.DigitalClock = 0.0;
    twa_parallel_B.UnitDelay_k = 0.0;
    twa_parallel_B.UnitDelay1_b = 0.0;
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
    twa_parallel_B.micro_leg_len[0] = 0.0;
    twa_parallel_B.micro_leg_len[1] = 0.0;
    twa_parallel_B.micro_leg_len[2] = 0.0;
    twa_parallel_B.x_cur[0] = 0.0;
    twa_parallel_B.x_cur[1] = 0.0;
    twa_parallel_B.x_cur[2] = 0.0;
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

  twa_parallel_DWork.UnitDelay1_DSTATE[0] = 0.0;
  twa_parallel_DWork.UnitDelay1_DSTATE[1] = 0.0;
  twa_parallel_DWork.UnitDelay1_DSTATE[2] = 0.0;
  twa_parallel_DWork.UnitDelay2_DSTATE[0] = 0.0;
  twa_parallel_DWork.UnitDelay2_DSTATE[1] = 0.0;
  twa_parallel_DWork.UnitDelay2_DSTATE[2] = 0.0;
  twa_parallel_DWork.UnitDelay_DSTATE[0] = 0.0;
  twa_parallel_DWork.UnitDelay_DSTATE[1] = 0.0;
  twa_parallel_DWork.UnitDelay_DSTATE[2] = 0.0;
  twa_parallel_DWork.UnitDelay_DSTATE_e = 0.0;
  twa_parallel_DWork.UnitDelay1_DSTATE_h = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      twa_parallel_DWork.UnitDelay2_DSTATE_k[i] = 0.0;
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
  twa_parallel_rtM->Sizes.numBlocks = (74);/* Number of blocks */
  twa_parallel_rtM->Sizes.numBlockIO = (63);/* Number of block outputs */
  twa_parallel_rtM->Sizes.numBlockPrms = (128);/* Sum of parameter "widths" */
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

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE[0] = twa_parallel_P.UnitDelay1_X0[0];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_DWork.UnitDelay2_DSTATE[0] = twa_parallel_P.UnitDelay2_X0[0];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE[0] = twa_parallel_P.UnitDelay_X0[0];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE[1] = twa_parallel_P.UnitDelay1_X0[1];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_DWork.UnitDelay2_DSTATE[1] = twa_parallel_P.UnitDelay2_X0[1];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE[1] = twa_parallel_P.UnitDelay_X0[1];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE[2] = twa_parallel_P.UnitDelay1_X0[2];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    twa_parallel_DWork.UnitDelay2_DSTATE[2] = twa_parallel_P.UnitDelay2_X0[2];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE[2] = twa_parallel_P.UnitDelay_X0[2];

    /* InitializeConditions for Embedded MATLAB: '<Root>/GetLegLen' */
    twa_parallel_DWork.is_active_c1_twa_parallel = 0U;

    /* InitializeConditions for Embedded MATLAB: '<Root>/GetMacroQDes' */
    twa_parallel_DWork.is_active_c4_twa_parallel = 0U;

    /* InitializeConditions for Embedded MATLAB: '<Root>/GetMicroQDes' */
    twa_parallel_DWork.is_active_c2_twa_parallel = 0U;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    twa_parallel_DWork.UnitDelay_DSTATE_e = twa_parallel_P.UnitDelay_X0_p;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
    twa_parallel_DWork.UnitDelay1_DSTATE_h = twa_parallel_P.UnitDelay1_X0_h;

    /* Signal Processing Blockset N-Sample Enable  (sdspnsamp2) - '<S19>/N-Sample Enable' */
    twa_parallel_DWork.NSampleEnable_Counter = (uint32_T) 0;

    /* InitializeConditions for Embedded MATLAB: '<S6>/Embedded MATLAB Function' */
    twa_parallel_DWork.is_active_c22_twa_parallel = 0U;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for UnitDelay: '<S6>/Unit Delay2' */
      twa_parallel_DWork.UnitDelay2_DSTATE_k[i] =
        twa_parallel_P.UnitDelay2_X0_d[i];

      /* InitializeConditions for Integrator: '<S5>/Integrator' */
      twa_parallel_X.Integrator_CSTATE[i] = twa_parallel_P.Integrator_IC;

      /* InitializeConditions for UnitDelay: '<S17>/UD' */
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
        xpceScopeAcqOK(1, &twa_parallel_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
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
        xpceScopeAcqOK(2, &twa_parallel_DWork.SFunction_IWORK_j.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
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
