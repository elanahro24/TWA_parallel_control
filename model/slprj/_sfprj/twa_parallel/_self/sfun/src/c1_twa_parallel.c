/* Include files */

#include "blascompat32.h"
#include "twa_parallel_sfun.h"
#include "c1_twa_parallel.h"
#include <math.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "twa_parallel_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[50] = { "conv_rad", "x_delta",
  "init_twa_len", "p_rad", "b_rad", "rot_m2w", "vertex_locs", "p_in_m", "p_in_w",
  "b_in_w", "f_rad", "flexure_locs", "f_in_w", "m_rad", "motor_locs", "m_in_w",
  "vertex_dist", "i", "beta_cmd", "post_flex_angle", "beta", "rho_vec", "rho",
  "eta_vec", "eta", "flexure_frame_rot_angle", "n", "rot_f_2_w", "check",
  "lambda", "b_prime_in_f_dwn", "b_prime_in_f_up", "eta_prime_vec_dwn",
  "eta_prime_vec_up", "pre_flex_angle", "j", "a", "b", "c", "alpha", "nargin",
  "nargout", "x_des", "ee_rot", "macro_leg_len_prev", "micro_leg_len_prev",
  "x_prev", "macro_leg_len", "micro_leg_len", "x_cur" };

/* Function Declarations */
static void initialize_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance);
static void initialize_params_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance);
static void enable_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance);
static void disable_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_twa_parallel
  (SFc1_twa_parallelInstanceStruct *chartInstance);
static void ext_mode_exec_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_twa_parallel
  (SFc1_twa_parallelInstanceStruct *chartInstance);
static void set_sim_state_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance);
static void sf_c1_twa_parallel(SFc1_twa_parallelInstanceStruct *chartInstance);
static void c1_c1_twa_parallel(SFc1_twa_parallelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_abs(SFc1_twa_parallelInstanceStruct *chartInstance, real_T c1_x[3],
                   real_T c1_y[3]);
static void c1_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance);
static void c1_eml_xgemm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_A[9], real_T c1_B[9], real_T c1_C[9], real_T c1_b_C[9]);
static void c1_b_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance);
static void c1_c_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance);
static real_T c1_norm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                      c1_x[3]);
static real_T c1_b_abs(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_x);
static real_T c1_ceval_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[3], int32_T c1_ix0, int32_T c1_incx);
static real_T c1_b_norm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_x[9]);
static void c1_svd(SFc1_twa_parallelInstanceStruct *chartInstance, real_T c1_A[9],
                   real_T c1_Uout[3]);
static boolean_T c1_isfinite(SFc1_twa_parallelInstanceStruct *chartInstance,
  real_T c1_x);
static void c1_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance);
static real_T c1_eml_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[9], int32_T c1_ix0);
static real_T c1_b_ceval_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[9], int32_T c1_ix0, int32_T c1_incx);
static void c1_eml_xscal(SFc1_twa_parallelInstanceStruct *chartInstance, int32_T
  c1_n, real_T c1_a, real_T c1_x[9], int32_T c1_ix0, real_T c1_b_x[9]);
static void c1_ceval_xscal(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[9], int32_T c1_ix0, int32_T c1_incx,
  real_T c1_b_x[9]);
static real_T c1_eml_xdotc(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[9], int32_T c1_ix0, real_T c1_y[9], int32_T c1_iy0);
static real_T c1_ceval_xdot(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[9], int32_T c1_ix0, int32_T c1_incx, real_T c1_y[9],
  int32_T c1_iy0, int32_T c1_incy);
static void c1_eml_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance, int32_T
  c1_n, real_T c1_a, int32_T c1_ix0, real_T c1_y[9], int32_T c1_iy0, real_T
  c1_b_y[9]);
static void c1_ceval_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, int32_T c1_ix0, int32_T c1_incx, real_T c1_y[9],
  int32_T c1_iy0, int32_T c1_incy, real_T c1_b_y[9]);
static real_T c1_b_eml_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[3], int32_T c1_ix0);
static void c1_b_eml_xscal(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[3], int32_T c1_ix0, real_T c1_b_x[3]);
static void c1_b_ceval_xscal(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[3], int32_T c1_ix0, int32_T c1_incx,
  real_T c1_b_x[3]);
static void c1_b_eml_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[9], int32_T c1_ix0, real_T c1_y[3],
  int32_T c1_iy0, real_T c1_b_y[3]);
static void c1_b_ceval_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[9], int32_T c1_ix0, int32_T c1_incx,
  real_T c1_y[3], int32_T c1_iy0, int32_T c1_incy, real_T c1_b_y[3]);
static void c1_c_eml_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[3], int32_T c1_ix0, real_T c1_y[9],
  int32_T c1_iy0, real_T c1_b_y[9]);
static void c1_c_ceval_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[3], int32_T c1_ix0, int32_T c1_incx,
  real_T c1_y[9], int32_T c1_iy0, int32_T c1_incy, real_T c1_b_y[9]);
static real_T c1_power(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_a, real_T c1_b);
static void c1_b_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance);
static void c1_eps(SFc1_twa_parallelInstanceStruct *chartInstance);
static real_T c1_max(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                     c1_varargin_1, real_T c1_varargin_2);
static void c1_c_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance);
static real_T c1_b_max(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_varargin_1[5]);
static real_T c1_sqrt(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                      c1_x);
static void c1_d_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance);
static void c1_eml_xrotg(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_a, real_T c1_b, real_T *c1_b_a, real_T *c1_b_b, real_T *c1_c, real_T *c1_s);
static real_T c1_atan2(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_y, real_T c1_x);
static void c1_expm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T c1_A
                    [9], real_T c1_F[9]);
static void c1_PadeApproximantOfDegree(SFc1_twa_parallelInstanceStruct
  *chartInstance, real_T c1_A[9], real_T c1_m, real_T c1_F[9]);
static void c1_mldivide(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_A[9], real_T c1_B[9], real_T c1_Y[9]);
static void c1_eml_warning(SFc1_twa_parallelInstanceStruct *chartInstance);
static real_T c1_mpower(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_a);
static real_T c1_acos(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                      c1_x);
static void c1_e_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance);
static void c1_d_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[106]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[106]);
static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_emlrt_marshallIn(SFc1_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c1_macro_leg_len, const char_T *c1_name, real_T c1_y[3]);
static uint8_T c1_b_emlrt_marshallIn(SFc1_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_twa_parallel, const char_T
  *c1_name);
static void init_dsm_address_info(SFc1_twa_parallelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance)
{
  uint8_T *c1_is_active_c1_twa_parallel;
  c1_is_active_c1_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_twa_parallel = 0U;
}

static void initialize_params_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void enable_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_twa_parallel
  (SFc1_twa_parallelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance)
{
  c1_update_debugger_state_c1_twa_parallel(chartInstance);
}

static const mxArray *get_sim_state_c1_twa_parallel
  (SFc1_twa_parallelInstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_hoistedGlobal[3];
  int32_T c1_i1;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i2;
  real_T c1_b_hoistedGlobal[3];
  int32_T c1_i3;
  real_T c1_b_u[3];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i4;
  real_T c1_c_hoistedGlobal[3];
  int32_T c1_i5;
  real_T c1_c_u[3];
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T *c1_is_active_c1_twa_parallel;
  real_T (*c1_x_cur)[3];
  real_T (*c1_micro_leg_len)[3];
  real_T (*c1_macro_leg_len)[3];
  c1_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_micro_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_macro_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4));
  for (c1_i0 = 0; c1_i0 < 3; c1_i0 = c1_i0 + 1) {
    c1_hoistedGlobal[c1_i0] = (*c1_macro_leg_len)[c1_i0];
  }

  for (c1_i1 = 0; c1_i1 < 3; c1_i1 = c1_i1 + 1) {
    c1_u[c1_i1] = c1_hoistedGlobal[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    c1_b_hoistedGlobal[c1_i2] = (*c1_micro_leg_len)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3 = c1_i3 + 1) {
    c1_b_u[c1_i3] = c1_b_hoistedGlobal[c1_i3];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4 = c1_i4 + 1) {
    c1_c_hoistedGlobal[c1_i4] = (*c1_x_cur)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5 = c1_i5 + 1) {
    c1_c_u[c1_i5] = c1_c_hoistedGlobal[c1_i5];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_is_active_c1_twa_parallel;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i6;
  real_T c1_dv1[3];
  int32_T c1_i7;
  real_T c1_dv2[3];
  int32_T c1_i8;
  boolean_T *c1_doneDoubleBufferReInit;
  uint8_T *c1_is_active_c1_twa_parallel;
  real_T (*c1_macro_leg_len)[3];
  real_T (*c1_micro_leg_len)[3];
  real_T (*c1_x_cur)[3];
  c1_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_micro_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_macro_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "macro_leg_len", c1_dv0);
  for (c1_i6 = 0; c1_i6 < 3; c1_i6 = c1_i6 + 1) {
    (*c1_macro_leg_len)[c1_i6] = c1_dv0[c1_i6];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "micro_leg_len", c1_dv1);
  for (c1_i7 = 0; c1_i7 < 3; c1_i7 = c1_i7 + 1) {
    (*c1_micro_leg_len)[c1_i7] = c1_dv1[c1_i7];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                      "x_cur", c1_dv2);
  for (c1_i8 = 0; c1_i8 < 3; c1_i8 = c1_i8 + 1) {
    (*c1_x_cur)[c1_i8] = c1_dv2[c1_i8];
  }

  *c1_is_active_c1_twa_parallel = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "is_active_c1_twa_parallel");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_twa_parallel(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_twa_parallel(SFc1_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void sf_c1_twa_parallel(SFc1_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_previousEvent;
  real_T *c1_ee_rot;
  real_T (*c1_x_prev)[3];
  real_T (*c1_x_cur)[3];
  real_T (*c1_micro_leg_len)[3];
  real_T (*c1_micro_leg_len_prev)[3];
  real_T (*c1_macro_leg_len_prev)[3];
  real_T (*c1_macro_leg_len)[3];
  real_T (*c1_x_des)[3];
  c1_x_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c1_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_micro_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_micro_leg_len_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
    3);
  c1_macro_leg_len_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
    2);
  c1_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_macro_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_x_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9 = c1_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_x_des)[c1_i9], 0U);
  }

  for (c1_i10 = 0; c1_i10 < 3; c1_i10 = c1_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_macro_leg_len)[c1_i10], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_ee_rot, 2U);
  for (c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_macro_leg_len_prev)[c1_i11], 3U);
  }

  for (c1_i12 = 0; c1_i12 < 3; c1_i12 = c1_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_micro_leg_len_prev)[c1_i12], 4U);
  }

  for (c1_i13 = 0; c1_i13 < 3; c1_i13 = c1_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_micro_leg_len)[c1_i13], 5U);
  }

  for (c1_i14 = 0; c1_i14 < 3; c1_i14 = c1_i14 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_x_cur)[c1_i14], 6U);
  }

  for (c1_i15 = 0; c1_i15 < 3; c1_i15 = c1_i15 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_x_prev)[c1_i15], 7U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_twa_parallel(chartInstance);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_twa_parallelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_twa_parallel(SFc1_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c1_i16;
  real_T c1_hoistedGlobal[3];
  real_T c1_b_hoistedGlobal;
  int32_T c1_i17;
  real_T c1_c_hoistedGlobal[3];
  int32_T c1_i18;
  real_T c1_d_hoistedGlobal[3];
  int32_T c1_i19;
  real_T c1_e_hoistedGlobal[3];
  int32_T c1_i20;
  real_T c1_x_des[3];
  real_T c1_ee_rot;
  int32_T c1_i21;
  real_T c1_macro_leg_len_prev[3];
  int32_T c1_i22;
  real_T c1_micro_leg_len_prev[3];
  int32_T c1_i23;
  real_T c1_x_prev[3];
  uint32_T c1_debug_family_var_map[50];
  static const char *c1_sv0[50] = { "conv_rad", "x_delta", "init_twa_len",
    "p_rad", "b_rad", "rot_m2w", "vertex_locs", "p_in_m",
    "p_in_w", "b_in_w", "f_rad", "flexure_locs", "f_in_w", "m_rad", "motor_locs",
    "m_in_w",
    "vertex_dist", "i", "beta_cmd", "post_flex_angle", "beta", "rho_vec", "rho",
    "eta_vec", "eta",
    "flexure_frame_rot_angle", "n", "rot_f_2_w", "check", "lambda",
    "b_prime_in_f_dwn",
    "b_prime_in_f_up", "eta_prime_vec_dwn", "eta_prime_vec_up", "pre_flex_angle",
    "j", "a", "b", "c",
    "alpha", "nargin", "nargout", "x_des", "ee_rot", "macro_leg_len_prev",
    "micro_leg_len_prev",
    "x_prev", "macro_leg_len", "micro_leg_len", "x_cur" };

  real_T c1_conv_rad;
  real_T c1_x_delta[3];
  real_T c1_init_twa_len[3];
  real_T c1_p_rad;
  real_T c1_b_rad;
  real_T c1_rot_m2w[9];
  real_T c1_vertex_locs[3];
  real_T c1_p_in_m[9];
  real_T c1_p_in_w[9];
  real_T c1_b_in_w[9];
  real_T c1_f_rad;
  real_T c1_flexure_locs[3];
  real_T c1_f_in_w[9];
  real_T c1_m_rad;
  real_T c1_motor_locs[3];
  real_T c1_m_in_w[9];
  real_T c1_vertex_dist[9];
  real_T c1_i;
  real_T c1_beta_cmd;
  real_T c1_post_flex_angle[2];
  real_T c1_beta[2];
  real_T c1_rho_vec[9];
  real_T c1_rho;
  real_T c1_eta_vec[9];
  real_T c1_eta;
  real_T c1_flexure_frame_rot_angle;
  real_T c1_n[3];
  real_T c1_rot_f_2_w[9];
  real_T c1_check;
  real_T c1_lambda;
  real_T c1_b_prime_in_f_dwn[3];
  real_T c1_b_prime_in_f_up[3];
  real_T c1_eta_prime_vec_dwn[3];
  real_T c1_eta_prime_vec_up[3];
  real_T c1_pre_flex_angle;
  real_T c1_j;
  real_T c1_a;
  real_T c1_b;
  real_T c1_c;
  real_T c1_alpha;
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 3.0;
  real_T c1_macro_leg_len[3];
  real_T c1_micro_leg_len[3];
  real_T c1_x_cur[3];
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  real_T c1_b_x_des[3];
  real_T c1_dv3[3];
  int32_T c1_i28;
  int32_T c1_i29;
  static real_T c1_dv4[3] = { 2.258E+002, 2.263E+002, 224.5 };

  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  int32_T c1_i30;
  int32_T c1_i31;
  static real_T c1_dv5[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_i32;
  static real_T c1_dv6[3] = { 5.7595865315812871E+000, 1.5707963267948966E+000,
    3.6651914291880923E+000 };

  int32_T c1_i33;
  static real_T c1_dv7[9] = { 3.8971143170299726E+001, -2.2500000000000021E+001,
    0.0, 2.7554552980815448E-015, 45.0, 0.0,
    -3.8971143170299740E+001, -2.2500000000000004E+001, 0.0 };

  int32_T c1_i34;
  real_T c1_b_a[3];
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  real_T c1_y[9];
  int32_T c1_i38;
  real_T c1_c_a[9];
  int32_T c1_i39;
  real_T c1_d_a[9];
  int32_T c1_i40;
  real_T c1_dv8[9];
  int32_T c1_i41;
  real_T c1_dv9[9];
  real_T c1_b_y[9];
  int32_T c1_i42;
  int32_T c1_i43;
  static real_T c1_dv10[9] = { 1.4057324354229004E+002, -8.1160000000000068E+001,
    0.0, 9.9392334218799176E-015, 1.6232E+002, 0.0,
    -1.4057324354229007E+002, -8.1160000000000011E+001, 0.0 };

  int32_T c1_i44;
  static real_T c1_dv11[3] = { -6.9813170079773179E-001, 1.3962634015954636E+000,
    3.4906585039886591E+000 };

  int32_T c1_i45;
  static real_T c1_dv12[9] = { 6.1283555449518239E+001, -5.1423008774923140E+001,
    0.0, 1.3891854213354433E+001,
    7.8784620240976636E+001, 0.0, -7.5175409662872681E+001,
    -2.7361611466053493E+001, 0.0 };

  int32_T c1_i46;
  static real_T c1_dv13[3] = { 4.4886377702790163E+000, 2.9984756549262581E-001,
    2.3942426678858215E+000 };

  int32_T c1_i47;
  static real_T c1_dv14[9] = { -2.6438059510305436E+000,
    -1.1617982402004897E+001, 0.0, 1.1383370876372062E+001,
    3.5193880847335253E+000, 0.0, -8.7395649253415257E+000,
    8.0985943172713704E+000, 0.0 };

  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  real_T c1_b_vertex_dist[3];
  int32_T c1_i51;
  real_T c1_c_vertex_dist[3];
  int32_T c1_i52;
  real_T c1_d_vertex_dist[3];
  real_T c1_b_i;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  real_T c1_b_rho_vec[9];
  int32_T c1_i57;
  static real_T c1_dv15[9] = { 7.9289688092771797E+001, -2.9736991225076927E+001,
    0.0, -1.3891854213354422E+001,
    8.3535379759023357E+001, 0.0, -6.5397833879417391E+001,
    -5.3798388533946522E+001, 0.0 };

  int32_T c1_i58;
  real_T c1_dv16[9];
  int32_T c1_i59;
  real_T c1_dv17[3];
  real_T c1_c_y;
  real_T c1_d_y;
  real_T c1_e_y;
  int32_T c1_i60;
  real_T c1_e_a;
  real_T c1_b_b[9];
  int32_T c1_i61;
  real_T c1_f_y[9];
  int32_T c1_i62;
  real_T c1_g_y[9];
  real_T c1_dv18[9];
  int32_T c1_i63;
  real_T c1_c_b;
  real_T c1_h_y;
  real_T c1_f_a;
  real_T c1_d_b;
  real_T c1_i_y;
  real_T c1_A;
  real_T c1_B;
  real_T c1_m_x;
  real_T c1_j_y;
  real_T c1_n_x;
  real_T c1_k_y;
  real_T c1_o_x;
  real_T c1_l_y;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_g_a;
  real_T c1_e_b[3];
  int32_T c1_i64;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_bb_x;
  real_T c1_h_a;
  real_T c1_f_b[3];
  int32_T c1_i65;
  int32_T c1_i66;
  real_T c1_i_a[9];
  int32_T c1_i67;
  real_T c1_g_b[3];
  int32_T c1_i68;
  real_T c1_b_A[9];
  int32_T c1_i69;
  real_T c1_b_B[3];
  int32_T c1_i70;
  int32_T c1_i71;
  real_T c1_c_A[9];
  int32_T c1_i72;
  real_T c1_c_B[3];
  int32_T c1_i73;
  real_T c1_d_A[9];
  int32_T c1_i74;
  real_T c1_d_B[3];
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  real_T c1_j_a[9];
  int32_T c1_i79;
  real_T c1_h_b[3];
  int32_T c1_i80;
  real_T c1_e_A[9];
  int32_T c1_i81;
  real_T c1_e_B[3];
  int32_T c1_i82;
  int32_T c1_i83;
  real_T c1_f_A[9];
  int32_T c1_i84;
  real_T c1_f_B[3];
  int32_T c1_i85;
  real_T c1_g_A[9];
  int32_T c1_i86;
  real_T c1_g_B[3];
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  real_T c1_b_j;
  real_T c1_i_b;
  real_T c1_m_y;
  int32_T c1_c_i;
  int32_T c1_d_i;
  int32_T c1_i90;
  real_T c1_b_f_in_w[3];
  int32_T c1_e_i;
  int32_T c1_f_i;
  int32_T c1_i91;
  real_T c1_c_f_in_w[3];
  real_T c1_k_a;
  real_T c1_b_c;
  real_T c1_l_a;
  real_T c1_c_c;
  real_T c1_m_a;
  real_T c1_d_c;
  real_T c1_j_b;
  real_T c1_n_y;
  real_T c1_n_a;
  real_T c1_k_b;
  real_T c1_o_y;
  real_T c1_h_A;
  real_T c1_h_B;
  real_T c1_cb_x;
  real_T c1_p_y;
  real_T c1_db_x;
  real_T c1_q_y;
  real_T c1_eb_x;
  real_T c1_r_y;
  real_T c1_s_y;
  real_T c1_fb_x;
  real_T c1_gb_x;
  real_T c1_o_a;
  real_T c1_e_c;
  real_T c1_p_a;
  real_T c1_f_c;
  real_T c1_l_b;
  real_T c1_t_y;
  real_T c1_q_a;
  real_T c1_m_b;
  real_T c1_u_y;
  real_T c1_hb_x;
  real_T c1_ib_x;
  real_T c1_jb_x;
  real_T c1_r_a;
  real_T c1_n_b;
  real_T c1_v_y;
  real_T c1_kb_x;
  real_T c1_lb_x;
  real_T c1_mb_x;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  real_T *c1_b_ee_rot;
  real_T (*c1_b_macro_leg_len)[3];
  real_T (*c1_b_micro_leg_len)[3];
  real_T (*c1_b_x_cur)[3];
  real_T (*c1_b_x_prev)[3];
  real_T (*c1_b_micro_leg_len_prev)[3];
  real_T (*c1_b_macro_leg_len_prev)[3];
  real_T (*c1_c_x_des)[3];
  c1_b_x_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_micro_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_micro_leg_len_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
    3);
  c1_b_macro_leg_len_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
    2);
  c1_b_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_macro_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_c_x_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c1_i16 = 0; c1_i16 < 3; c1_i16 = c1_i16 + 1) {
    c1_hoistedGlobal[c1_i16] = (*c1_c_x_des)[c1_i16];
  }

  c1_b_hoistedGlobal = *c1_b_ee_rot;
  for (c1_i17 = 0; c1_i17 < 3; c1_i17 = c1_i17 + 1) {
    c1_c_hoistedGlobal[c1_i17] = (*c1_b_macro_leg_len_prev)[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 3; c1_i18 = c1_i18 + 1) {
    c1_d_hoistedGlobal[c1_i18] = (*c1_b_micro_leg_len_prev)[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 3; c1_i19 = c1_i19 + 1) {
    c1_e_hoistedGlobal[c1_i19] = (*c1_b_x_prev)[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 3; c1_i20 = c1_i20 + 1) {
    c1_x_des[c1_i20] = c1_hoistedGlobal[c1_i20];
  }

  c1_ee_rot = c1_b_hoistedGlobal;
  for (c1_i21 = 0; c1_i21 < 3; c1_i21 = c1_i21 + 1) {
    c1_macro_leg_len_prev[c1_i21] = c1_c_hoistedGlobal[c1_i21];
  }

  for (c1_i22 = 0; c1_i22 < 3; c1_i22 = c1_i22 + 1) {
    c1_micro_leg_len_prev[c1_i22] = c1_d_hoistedGlobal[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 3; c1_i23 = c1_i23 + 1) {
    c1_x_prev[c1_i23] = c1_e_hoistedGlobal[c1_i23];
  }

  sf_debug_symbol_scope_push_eml(0U, 50U, 50U, c1_sv0, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_conv_rad, c1_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_x_delta, c1_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_init_twa_len, c1_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_p_rad, c1_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_b_rad, c1_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_rot_m2w, c1_c_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_vertex_locs, c1_e_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_p_in_m, c1_c_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c1_p_in_w, c1_c_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c1_b_in_w, c1_c_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c1_f_rad, c1_b_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c1_flexure_locs, c1_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c1_f_in_w, c1_c_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c1_m_rad, c1_b_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c1_motor_locs, c1_e_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c1_m_in_w, c1_c_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c1_vertex_dist, c1_c_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c1_i, c1_b_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c1_beta_cmd, c1_b_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c1_post_flex_angle, c1_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c1_beta, c1_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c1_rho_vec, c1_c_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c1_rho, c1_b_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c1_eta_vec, c1_c_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c1_eta, c1_b_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c1_flexure_frame_rot_angle, c1_b_sf_marshall,
    25U);
  sf_debug_symbol_scope_add_eml(&c1_n, c1_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c1_rot_f_2_w, c1_c_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c1_check, c1_b_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c1_lambda, c1_b_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c1_b_prime_in_f_dwn, c1_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c1_b_prime_in_f_up, c1_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c1_eta_prime_vec_dwn, c1_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c1_eta_prime_vec_up, c1_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c1_pre_flex_angle, c1_b_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c1_j, c1_b_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c1_a, c1_b_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c1_b, c1_b_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c1_c, c1_b_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c1_alpha, c1_b_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_b_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_b_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c1_x_des, c1_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c1_ee_rot, c1_b_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c1_macro_leg_len_prev, c1_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c1_micro_leg_len_prev, c1_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c1_x_prev, c1_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c1_macro_leg_len, c1_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c1_micro_leg_len, c1_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c1_x_cur, c1_sf_marshall, 49U);
  CV_EML_FCN(0, 0);

  /*  This function solves for the vertex positions of the base and moving */
  /*  platform for a given desired end effector position. */
  /*  With vertex positions known, leg lengths can be solved for. */
  /*  initialization */
  _SFD_EML_CALL(0,7);
  c1_conv_rad = 0.5;

  /* [mm] */
  _SFD_EML_CALL(0,8);
  for (c1_i24 = 0; c1_i24 < 3; c1_i24 = c1_i24 + 1) {
    c1_x_cur[c1_i24] = c1_x_des[c1_i24];
  }

  _SFD_EML_CALL(0,9);
  for (c1_i25 = 0; c1_i25 < 3; c1_i25 = c1_i25 + 1) {
    c1_macro_leg_len[c1_i25] = c1_macro_leg_len_prev[c1_i25];
  }

  _SFD_EML_CALL(0,10);
  for (c1_i26 = 0; c1_i26 < 3; c1_i26 = c1_i26 + 1) {
    c1_micro_leg_len[c1_i26] = c1_micro_leg_len_prev[c1_i26];
  }

  _SFD_EML_CALL(0,11);
  for (c1_i27 = 0; c1_i27 < 3; c1_i27 = c1_i27 + 1) {
    c1_b_x_des[c1_i27] = c1_x_des[c1_i27] - c1_x_prev[c1_i27];
  }

  c1_abs(chartInstance, c1_b_x_des, c1_dv3);
  for (c1_i28 = 0; c1_i28 < 3; c1_i28 = c1_i28 + 1) {
    c1_x_delta[c1_i28] = c1_dv3[c1_i28];
  }

  _SFD_EML_CALL(0,13);
  for (c1_i29 = 0; c1_i29 < 3; c1_i29 = c1_i29 + 1) {
    c1_init_twa_len[c1_i29] = c1_dv4[c1_i29];
  }

  /* [mm] */
  /*  moving platform radius */
  _SFD_EML_CALL(0,16);
  c1_p_rad = 45.0;

  /* [mm] */
  /*  base radius */
  _SFD_EML_CALL(0,19);
  c1_b_rad = 1.6232E+002;

  /*  158.04; %[mm] */
  /*  rotation matrix of moving frame about z-xis */
  _SFD_EML_CALL(0,22);
  c1_x = c1_ee_rot;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_b_x = c1_c_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_d_x = c1_ee_rot;
  c1_e_x = c1_d_x;
  c1_f_x = c1_e_x;
  c1_e_x = c1_f_x;
  c1_e_x = muDoubleScalarSin(c1_e_x);
  c1_g_x = c1_ee_rot;
  c1_h_x = c1_g_x;
  c1_i_x = c1_h_x;
  c1_h_x = c1_i_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_j_x = c1_ee_rot;
  c1_k_x = c1_j_x;
  c1_l_x = c1_k_x;
  c1_k_x = c1_l_x;
  c1_k_x = muDoubleScalarCos(c1_k_x);
  c1_rot_m2w[0] = c1_b_x;
  c1_rot_m2w[3] = -c1_e_x;
  c1_rot_m2w[6] = 0.0;
  c1_rot_m2w[1] = c1_h_x;
  c1_rot_m2w[4] = c1_k_x;
  c1_rot_m2w[7] = 0.0;
  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 3; c1_i31 = c1_i31 + 1) {
    c1_rot_m2w[c1_i30 + 2] = c1_dv5[c1_i31];
    c1_i30 = c1_i30 + 3;
  }

  /*  moving platform vertex locations */
  _SFD_EML_CALL(0,25);
  for (c1_i32 = 0; c1_i32 < 3; c1_i32 = c1_i32 + 1) {
    c1_vertex_locs[c1_i32] = c1_dv6[c1_i32];
  }

  _SFD_EML_CALL(0,26);
  for (c1_i33 = 0; c1_i33 < 9; c1_i33 = c1_i33 + 1) {
    c1_p_in_m[c1_i33] = c1_dv7[c1_i33];
  }

  /*  x_des = zeros(3,1); */
  _SFD_EML_CALL(0,29);
  for (c1_i34 = 0; c1_i34 < 3; c1_i34 = c1_i34 + 1) {
    c1_b_a[c1_i34] = c1_x_des[c1_i34];
  }

  c1_i35 = 0;
  for (c1_i36 = 0; c1_i36 < 3; c1_i36 = c1_i36 + 1) {
    for (c1_i37 = 0; c1_i37 < 3; c1_i37 = c1_i37 + 1) {
      c1_y[c1_i37 + c1_i35] = c1_b_a[c1_i37];
    }

    c1_i35 = c1_i35 + 3;
  }

  for (c1_i38 = 0; c1_i38 < 9; c1_i38 = c1_i38 + 1) {
    c1_c_a[c1_i38] = c1_rot_m2w[c1_i38];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i39 = 0; c1_i39 < 9; c1_i39 = c1_i39 + 1) {
    c1_d_a[c1_i39] = c1_c_a[c1_i39];
  }

  for (c1_i40 = 0; c1_i40 < 9; c1_i40 = c1_i40 + 1) {
    c1_dv8[c1_i40] = c1_dv7[c1_i40];
  }

  for (c1_i41 = 0; c1_i41 < 9; c1_i41 = c1_i41 + 1) {
    c1_dv9[c1_i41] = 0.0;
  }

  c1_eml_xgemm(chartInstance, c1_d_a, c1_dv8, c1_dv9, c1_b_y);
  for (c1_i42 = 0; c1_i42 < 9; c1_i42 = c1_i42 + 1) {
    c1_p_in_w[c1_i42] = c1_y[c1_i42] + c1_b_y[c1_i42];
  }

  /*  base vertex positions */
  _SFD_EML_CALL(0,32);
  for (c1_i43 = 0; c1_i43 < 9; c1_i43 = c1_i43 + 1) {
    c1_b_in_w[c1_i43] = c1_dv10[c1_i43];
  }

  /*  position of flexure centers */
  /*  radius of position of flexure center */
  _SFD_EML_CALL(0,36);
  c1_f_rad = 80.0;

  /* [mm] */
  _SFD_EML_CALL(0,37);
  for (c1_i44 = 0; c1_i44 < 3; c1_i44 = c1_i44 + 1) {
    c1_flexure_locs[c1_i44] = c1_dv11[c1_i44];
  }

  _SFD_EML_CALL(0,38);
  for (c1_i45 = 0; c1_i45 < 9; c1_i45 = c1_i45 + 1) {
    c1_f_in_w[c1_i45] = c1_dv12[c1_i45];
  }

  /*  position of twa pivot point, taken from CAD */
  /*  radius of position of twa pivot */
  _SFD_EML_CALL(0,42);
  c1_m_rad = 11.915;
  _SFD_EML_CALL(0,43);
  for (c1_i46 = 0; c1_i46 < 3; c1_i46 = c1_i46 + 1) {
    c1_motor_locs[c1_i46] = c1_dv13[c1_i46];
  }

  _SFD_EML_CALL(0,44);
  for (c1_i47 = 0; c1_i47 < 9; c1_i47 = c1_i47 + 1) {
    c1_m_in_w[c1_i47] = c1_dv14[c1_i47];
  }

  _SFD_EML_CALL(0,46);
  if (CV_EML_COND(0, 0, c1_x_delta[0] > c1_conv_rad)) {
  } else if (CV_EML_COND(0, 1, c1_x_delta[1] > c1_conv_rad)) {
  } else {
    CV_EML_MCDC(0, 0, FALSE);
    CV_EML_IF(0, 0, FALSE);
    _SFD_EML_CALL(0,58);
    if (CV_EML_COND(0, 2, c1_x_delta[0] < c1_conv_rad)) {
    } else if (CV_EML_COND(0, 3, c1_x_delta[1] < c1_conv_rad)) {
    } else {
      CV_EML_MCDC(0, 1, FALSE);
      CV_EML_IF(0, 1, FALSE);
      goto label_1;
    }

    CV_EML_MCDC(0, 1, TRUE);
    CV_EML_IF(0, 1, TRUE);

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /*    Micro Actuator Leg Lengths % */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* * */
    /*  loop through each vertex */
    /* * */
    c1_i = 1.0;
    c1_b_i = 1.0;
    while (c1_b_i <= 3.0) {
      c1_i = c1_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0,67);
      c1_beta_cmd = 8.7266462599716474E-002;
      _SFD_EML_CALL(0,68);
      for (c1_i53 = 0; c1_i53 < 2; c1_i53 = c1_i53 + 1) {
        c1_post_flex_angle[c1_i53] = 0.0;
      }

      _SFD_EML_CALL(0,69);
      for (c1_i54 = 0; c1_i54 < 2; c1_i54 = c1_i54 + 1) {
        c1_beta[c1_i54] = rtNaN;
      }

      /*  vector from flexure center to moving platform vertex */
      _SFD_EML_CALL(0,72);
      for (c1_i55 = 0; c1_i55 < 9; c1_i55 = c1_i55 + 1) {
        c1_rho_vec[c1_i55] = c1_p_in_w[c1_i55] - c1_f_in_w[c1_i55];
      }

      /*  distance between flexure and moving platform verteces */
      _SFD_EML_CALL(0,75);
      for (c1_i56 = 0; c1_i56 < 9; c1_i56 = c1_i56 + 1) {
        c1_b_rho_vec[c1_i56] = c1_rho_vec[c1_i56];
      }

      c1_rho = c1_b_norm(chartInstance, c1_b_rho_vec);

      /*  vector from flexure center to base vertex pre flexure rotation */
      _SFD_EML_CALL(0,78);
      for (c1_i57 = 0; c1_i57 < 9; c1_i57 = c1_i57 + 1) {
        c1_eta_vec[c1_i57] = c1_dv15[c1_i57];
      }

      /*  magnitude of flexure swing-arm radius from flexure to base vertex */
      _SFD_EML_CALL(0,81);
      for (c1_i58 = 0; c1_i58 < 9; c1_i58 = c1_i58 + 1) {
        c1_dv16[c1_i58] = c1_dv15[c1_i58];
      }

      c1_eta = c1_b_norm(chartInstance, c1_dv16);

      /*  angle from world horizontal to vector from flexure to platform vertex */
      _SFD_EML_CALL(0,84);
      c1_flexure_frame_rot_angle = c1_atan2(chartInstance, c1_rho_vec[1],
        c1_rho_vec[0]);

      /*  rotation matrix to flexure frame */
      _SFD_EML_CALL(0,87);
      for (c1_i59 = 0; c1_i59 < 3; c1_i59 = c1_i59 + 1) {
        c1_dv17[c1_i59] = c1_dv5[c1_i59];
      }

      c1_c_y = c1_norm(chartInstance, c1_dv17);
      c1_d_y = c1_c_y;
      c1_e_y = c1_d_y;
      for (c1_i60 = 0; c1_i60 < 3; c1_i60 = c1_i60 + 1) {
        c1_n[c1_i60] = c1_dv5[c1_i60] / c1_e_y;
      }

      _SFD_EML_CALL(0,89);
      c1_e_a = c1_flexure_frame_rot_angle;
      c1_b_b[0] = 0.0;
      c1_b_b[3] = -c1_n[2];
      c1_b_b[6] = c1_n[1];
      c1_b_b[1] = c1_n[2];
      c1_b_b[4] = 0.0;
      c1_b_b[7] = -c1_n[0];
      c1_b_b[2] = c1_n[1];
      c1_b_b[5] = c1_n[0];
      c1_b_b[8] = 0.0;
      for (c1_i61 = 0; c1_i61 < 9; c1_i61 = c1_i61 + 1) {
        c1_f_y[c1_i61] = c1_e_a * c1_b_b[c1_i61];
      }

      for (c1_i62 = 0; c1_i62 < 9; c1_i62 = c1_i62 + 1) {
        c1_g_y[c1_i62] = c1_f_y[c1_i62];
      }

      c1_expm(chartInstance, c1_g_y, c1_dv18);
      for (c1_i63 = 0; c1_i63 < 9; c1_i63 = c1_i63 + 1) {
        c1_rot_f_2_w[c1_i63] = c1_dv18[c1_i63];
      }

      /*  condition for acos solvability */
      _SFD_EML_CALL(0,92);
      c1_c_b = c1_rho;
      c1_h_y = -2.0 * c1_c_b;
      c1_f_a = c1_h_y;
      c1_d_b = c1_eta;
      c1_i_y = c1_f_a * c1_d_b;
      c1_A = (c1_mpower(chartInstance,
                        c1_macro_leg_len[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "macro_leg_len", (int32_T)_SFD_INTEGER_CHECK("i", c1_i
                 ), 1, 3, 1, 0) - 1]) - c1_mpower(chartInstance, c1_rho)) -
        c1_mpower(chartInstance, c1_eta);
      c1_B = c1_i_y;
      c1_m_x = c1_A;
      c1_j_y = c1_B;
      c1_n_x = c1_m_x;
      c1_k_y = c1_j_y;
      c1_o_x = c1_n_x;
      c1_l_y = c1_k_y;
      c1_check = c1_o_x / c1_l_y;
      _SFD_EML_CALL(0,94);
      if (CV_EML_COND(0, 4, c1_check >= -1.0)) {
        if (CV_EML_COND(0, 5, c1_check <= 1.0)) {
          CV_EML_MCDC(0, 2, TRUE);
          CV_EML_IF(0, 2, TRUE);

          /*  calculate angle between mf and fb vectors, lambda, with */
          /*  law of cosines */
          _SFD_EML_CALL(0,97);
          c1_lambda = c1_acos(chartInstance, c1_check);

          /*  calculate flexed base vertex position for both elbow up */
          /*  and down configurations */
          _SFD_EML_CALL(0,101);
          c1_p_x = -c1_lambda;
          c1_q_x = c1_p_x;
          c1_r_x = c1_q_x;
          c1_q_x = c1_r_x;
          c1_q_x = muDoubleScalarCos(c1_q_x);
          c1_s_x = -c1_lambda;
          c1_t_x = c1_s_x;
          c1_u_x = c1_t_x;
          c1_t_x = c1_u_x;
          c1_t_x = muDoubleScalarSin(c1_t_x);
          c1_g_a = c1_eta;
          c1_e_b[0] = c1_q_x;
          c1_e_b[1] = c1_t_x;
          c1_e_b[2] = 0.0;
          for (c1_i64 = 0; c1_i64 < 3; c1_i64 = c1_i64 + 1) {
            c1_b_prime_in_f_dwn[c1_i64] = c1_g_a * c1_e_b[c1_i64];
          }

          _SFD_EML_CALL(0,102);
          c1_v_x = c1_lambda;
          c1_w_x = c1_v_x;
          c1_x_x = c1_w_x;
          c1_w_x = c1_x_x;
          c1_w_x = muDoubleScalarCos(c1_w_x);
          c1_y_x = c1_lambda;
          c1_ab_x = c1_y_x;
          c1_bb_x = c1_ab_x;
          c1_ab_x = c1_bb_x;
          c1_ab_x = muDoubleScalarSin(c1_ab_x);
          c1_h_a = c1_eta;
          c1_f_b[0] = c1_w_x;
          c1_f_b[1] = c1_ab_x;
          c1_f_b[2] = 0.0;
          for (c1_i65 = 0; c1_i65 < 3; c1_i65 = c1_i65 + 1) {
            c1_b_prime_in_f_up[c1_i65] = c1_h_a * c1_f_b[c1_i65];
          }

          _SFD_EML_CALL(0,104);
          for (c1_i66 = 0; c1_i66 < 9; c1_i66 = c1_i66 + 1) {
            c1_i_a[c1_i66] = c1_rot_f_2_w[c1_i66];
          }

          for (c1_i67 = 0; c1_i67 < 3; c1_i67 = c1_i67 + 1) {
            c1_g_b[c1_i67] = c1_b_prime_in_f_dwn[c1_i67];
          }

          c1_d_eml_scalar_eg(chartInstance);
          c1_d_eml_scalar_eg(chartInstance);
          for (c1_i68 = 0; c1_i68 < 9; c1_i68 = c1_i68 + 1) {
            c1_b_A[c1_i68] = c1_i_a[c1_i68];
          }

          for (c1_i69 = 0; c1_i69 < 3; c1_i69 = c1_i69 + 1) {
            c1_b_B[c1_i69] = c1_g_b[c1_i69];
          }

          for (c1_i70 = 0; c1_i70 < 3; c1_i70 = c1_i70 + 1) {
            c1_eta_prime_vec_dwn[c1_i70] = 0.0;
          }

          for (c1_i71 = 0; c1_i71 < 9; c1_i71 = c1_i71 + 1) {
            c1_c_A[c1_i71] = c1_b_A[c1_i71];
          }

          for (c1_i72 = 0; c1_i72 < 3; c1_i72 = c1_i72 + 1) {
            c1_c_B[c1_i72] = c1_b_B[c1_i72];
          }

          for (c1_i73 = 0; c1_i73 < 9; c1_i73 = c1_i73 + 1) {
            c1_d_A[c1_i73] = c1_c_A[c1_i73];
          }

          for (c1_i74 = 0; c1_i74 < 3; c1_i74 = c1_i74 + 1) {
            c1_d_B[c1_i74] = c1_c_B[c1_i74];
          }

          for (c1_i75 = 0; c1_i75 < 3; c1_i75 = c1_i75 + 1) {
            c1_eta_prime_vec_dwn[c1_i75] = 0.0;
            c1_i76 = 0;
            for (c1_i77 = 0; c1_i77 < 3; c1_i77 = c1_i77 + 1) {
              c1_eta_prime_vec_dwn[c1_i75] = c1_eta_prime_vec_dwn[c1_i75] +
                c1_d_A[c1_i76 + c1_i75] * c1_d_B[c1_i77];
              c1_i76 = c1_i76 + 3;
            }
          }

          _SFD_EML_CALL(0,105);
          for (c1_i78 = 0; c1_i78 < 9; c1_i78 = c1_i78 + 1) {
            c1_j_a[c1_i78] = c1_rot_f_2_w[c1_i78];
          }

          for (c1_i79 = 0; c1_i79 < 3; c1_i79 = c1_i79 + 1) {
            c1_h_b[c1_i79] = c1_b_prime_in_f_up[c1_i79];
          }

          c1_d_eml_scalar_eg(chartInstance);
          c1_d_eml_scalar_eg(chartInstance);
          for (c1_i80 = 0; c1_i80 < 9; c1_i80 = c1_i80 + 1) {
            c1_e_A[c1_i80] = c1_j_a[c1_i80];
          }

          for (c1_i81 = 0; c1_i81 < 3; c1_i81 = c1_i81 + 1) {
            c1_e_B[c1_i81] = c1_h_b[c1_i81];
          }

          for (c1_i82 = 0; c1_i82 < 3; c1_i82 = c1_i82 + 1) {
            c1_eta_prime_vec_up[c1_i82] = 0.0;
          }

          for (c1_i83 = 0; c1_i83 < 9; c1_i83 = c1_i83 + 1) {
            c1_f_A[c1_i83] = c1_e_A[c1_i83];
          }

          for (c1_i84 = 0; c1_i84 < 3; c1_i84 = c1_i84 + 1) {
            c1_f_B[c1_i84] = c1_e_B[c1_i84];
          }

          for (c1_i85 = 0; c1_i85 < 9; c1_i85 = c1_i85 + 1) {
            c1_g_A[c1_i85] = c1_f_A[c1_i85];
          }

          for (c1_i86 = 0; c1_i86 < 3; c1_i86 = c1_i86 + 1) {
            c1_g_B[c1_i86] = c1_f_B[c1_i86];
          }

          for (c1_i87 = 0; c1_i87 < 3; c1_i87 = c1_i87 + 1) {
            c1_eta_prime_vec_up[c1_i87] = 0.0;
            c1_i88 = 0;
            for (c1_i89 = 0; c1_i89 < 3; c1_i89 = c1_i89 + 1) {
              c1_eta_prime_vec_up[c1_i87] = c1_eta_prime_vec_up[c1_i87] +
                c1_g_A[c1_i88 + c1_i87] * c1_g_B[c1_i89];
              c1_i88 = c1_i88 + 3;
            }
          }

          /*  may not need these at all */
          /*                  b_prime_in_w(:,1) = f_in_w + eta_prime_vec_dwn; */
          /*                  b_prime_in_w(:,2) = f_in_w + eta_prime_vec_up; */
          _SFD_EML_CALL(0,111);
          c1_pre_flex_angle = -3.5880780152813718E-001;
          _SFD_EML_CALL(0,113);
          c1_post_flex_angle[0] = c1_atan2(chartInstance, c1_eta_prime_vec_dwn[1],
            c1_eta_prime_vec_dwn[0]);
          _SFD_EML_CALL(0,114);
          c1_post_flex_angle[1] = c1_atan2(chartInstance, c1_eta_prime_vec_up[1],
            c1_eta_prime_vec_up[0]);

          /* * */
          /*  determine if flex angle is within mechanical range */
          /* * */
          c1_j = 1.0;
          c1_b_j = 1.0;
          while (c1_b_j <= 2.0) {
            c1_j = c1_b_j;
            CV_EML_FOR(0, 1, 1);
            _SFD_EML_CALL(0,120);
            CV_EML_COND(0, 6, c1_pre_flex_angle < 0.0);
            if (CV_EML_COND(0, 7, c1_post_flex_angle[_SFD_EML_ARRAY_BOUNDS_CHECK
                            ("post_flex_angle", (int32_T)_SFD_INTEGER_CHECK("i",
                   c1_i), 1, 2
                             , 2, 0) - 1] < 0.0)) {
              CV_EML_MCDC(0, 3, TRUE);
              CV_EML_IF(0, 3, TRUE);
              _SFD_EML_CALL(0,121);
              c1_i_b = c1_post_flex_angle[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "post_flex_angle", (int32_T)_SFD_INTEGER_CHECK("j", c1_j), 1, 2,
                2, 0) - 1];
              c1_m_y = -1.0 * c1_i_b;
              c1_beta[_SFD_EML_ARRAY_BOUNDS_CHECK("beta", (int32_T)
                _SFD_INTEGER_CHECK("j", c1_j), 1, 2, 2, 0) - 1] =
                3.5880780152813718E-001 -
                c1_m_y;
            } else {
              CV_EML_MCDC(0, 3, FALSE);
              CV_EML_IF(0, 3, FALSE);
              _SFD_EML_CALL(0,123);
              c1_beta[_SFD_EML_ARRAY_BOUNDS_CHECK("beta", (int32_T)
                _SFD_INTEGER_CHECK("j", c1_j), 1, 2, 2, 0) - 1] =
                c1_pre_flex_angle -
                c1_post_flex_angle[_SFD_EML_ARRAY_BOUNDS_CHECK("post_flex_angle",
                (int32_T)_SFD_INTEGER_CHECK("j", c1_j), 1, 2, 2, 0) - 1];
            }

            _SFD_EML_CALL(0,126);
            if (CV_EML_COND(0, 8, c1_beta[_SFD_EML_ARRAY_BOUNDS_CHECK("beta",
                  (int32_T)_SFD_INTEGER_CHECK("j", c1_j), 1, 2, 2, 0) - 1] >=
                            -1.7453292519943295E-001)) {
              if (CV_EML_COND(0, 9, c1_beta[_SFD_EML_ARRAY_BOUNDS_CHECK("beta",
                    (int32_T)_SFD_INTEGER_CHECK("j", c1_j), 1, 2, 2, 0) - 1] <=
                              1.7453292519943295E-001)) {
                CV_EML_MCDC(0, 4, TRUE);
                CV_EML_IF(0, 4, TRUE);
                _SFD_EML_CALL(0,127);
                c1_beta_cmd = c1_beta[_SFD_EML_ARRAY_BOUNDS_CHECK("beta",
                  (int32_T)_SFD_INTEGER_CHECK("j", c1_j), 1, 2, 2, 0) - 1];
                goto label_2;
              }
            }

            CV_EML_MCDC(0, 4, FALSE);
            CV_EML_IF(0, 4, FALSE);
           label_2:
            ;
            c1_b_j = c1_b_j + 1.0;
            sf_mex_listen_for_ctrl_c(chartInstance->S);
          }

          CV_EML_FOR(0, 1, 0);
          goto label_3;
        }
      }

      CV_EML_MCDC(0, 2, FALSE);
      CV_EML_IF(0, 2, FALSE);
     label_3:
      ;

      /*  calculate initial angle prior to flexure bend */
      _SFD_EML_CALL(0,134);
      c1_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("f_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c1_i), 1, 3, 2, 0) - 1;
      c1_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("m_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c1_i), 1, 3, 2, 0) - 1;
      for (c1_i90 = 0; c1_i90 < 3; c1_i90 = c1_i90 + 1) {
        c1_b_f_in_w[c1_i90] = c1_f_in_w[c1_i90 + 3 * c1_c_i] - c1_m_in_w[c1_i90
          + 3 * c1_d_i];
      }

      c1_a = c1_norm(chartInstance, c1_b_f_in_w);
      _SFD_EML_CALL(0,135);
      c1_e_i = _SFD_EML_ARRAY_BOUNDS_CHECK("f_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c1_i), 1, 3, 2, 0) - 1;
      c1_f_i = _SFD_EML_ARRAY_BOUNDS_CHECK("b_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c1_i), 1, 3, 2, 0) - 1;
      for (c1_i91 = 0; c1_i91 < 3; c1_i91 = c1_i91 + 1) {
        c1_c_f_in_w[c1_i91] = c1_f_in_w[c1_i91 + 3 * c1_e_i] - c1_b_in_w[c1_i91
          + 3 * c1_f_i];
      }

      c1_b = c1_norm(chartInstance, c1_c_f_in_w);
      _SFD_EML_CALL(0,136);
      c1_c = c1_init_twa_len[_SFD_EML_ARRAY_BOUNDS_CHECK("init_twa_len",
        (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1];
      _SFD_EML_CALL(0,137);
      c1_k_a = c1_c;
      c1_b_c = c1_power(chartInstance, c1_k_a, 2.0);
      c1_l_a = c1_a;
      c1_c_c = c1_power(chartInstance, c1_l_a, 2.0);
      c1_m_a = c1_b;
      c1_d_c = c1_power(chartInstance, c1_m_a, 2.0);
      c1_j_b = c1_a;
      c1_n_y = -2.0 * c1_j_b;
      c1_n_a = c1_n_y;
      c1_k_b = c1_b;
      c1_o_y = c1_n_a * c1_k_b;
      c1_h_A = (c1_b_c - c1_c_c) - c1_d_c;
      c1_h_B = c1_o_y;
      c1_cb_x = c1_h_A;
      c1_p_y = c1_h_B;
      c1_db_x = c1_cb_x;
      c1_q_y = c1_p_y;
      c1_eb_x = c1_db_x;
      c1_r_y = c1_q_y;
      c1_s_y = c1_eb_x / c1_r_y;
      c1_fb_x = c1_s_y;
      c1_alpha = c1_fb_x;
      if (c1_alpha < -1.0) {
      } else if (1.0 < c1_alpha) {
      } else {
        goto label_4;
      }

      c1_e_eml_error(chartInstance);
     label_4:
      ;
      c1_gb_x = c1_alpha;
      c1_alpha = c1_gb_x;
      c1_alpha = muDoubleScalarAcos(c1_alpha);

      /*  calculate required twa length to facilitate flexure bend */
      _SFD_EML_CALL(0,140);
      c1_o_a = c1_a;
      c1_e_c = c1_power(chartInstance, c1_o_a, 2.0);
      c1_p_a = c1_b;
      c1_f_c = c1_power(chartInstance, c1_p_a, 2.0);
      c1_l_b = c1_a;
      c1_t_y = 2.0 * c1_l_b;
      c1_q_a = c1_t_y;
      c1_m_b = c1_b;
      c1_u_y = c1_q_a * c1_m_b;
      c1_hb_x = c1_alpha - c1_beta_cmd;
      c1_ib_x = c1_hb_x;
      c1_jb_x = c1_ib_x;
      c1_ib_x = c1_jb_x;
      c1_ib_x = muDoubleScalarCos(c1_ib_x);
      c1_r_a = c1_u_y;
      c1_n_b = c1_ib_x;
      c1_v_y = c1_r_a * c1_n_b;
      c1_kb_x = (c1_e_c - c1_f_c) - c1_v_y;
      c1_lb_x = c1_kb_x;
      if (c1_lb_x < 0.0) {
        c1_d_eml_error(chartInstance);
      }

      c1_mb_x = c1_lb_x;
      c1_lb_x = c1_mb_x;
      c1_lb_x = muDoubleScalarSqrt(c1_lb_x);
      c1_micro_leg_len[_SFD_EML_ARRAY_BOUNDS_CHECK("micro_leg_len", (int32_T)
        _SFD_INTEGER_CHECK("i", c1_i), 1, 3, 1, 0) - 1] = c1_lb_x;
      c1_b_i = c1_b_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
   label_1:
    ;
    goto label_5;
  }

  CV_EML_MCDC(0, 0, TRUE);
  CV_EML_IF(0, 0, TRUE);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*    Macro Actuator Leg Lengths % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  _SFD_EML_CALL(0,51);
  for (c1_i48 = 0; c1_i48 < 9; c1_i48 = c1_i48 + 1) {
    c1_vertex_dist[c1_i48] = c1_p_in_w[c1_i48] - c1_b_in_w[c1_i48];
  }

  _SFD_EML_CALL(0,53);
  for (c1_i49 = 0; c1_i49 < 3; c1_i49 = c1_i49 + 1) {
    c1_macro_leg_len[c1_i49] = 0.0;
  }

  _SFD_EML_CALL(0,54);
  for (c1_i50 = 0; c1_i50 < 3; c1_i50 = c1_i50 + 1) {
    c1_b_vertex_dist[c1_i50] = c1_vertex_dist[c1_i50];
  }

  c1_macro_leg_len[0] = c1_norm(chartInstance, c1_b_vertex_dist);
  _SFD_EML_CALL(0,55);
  for (c1_i51 = 0; c1_i51 < 3; c1_i51 = c1_i51 + 1) {
    c1_c_vertex_dist[c1_i51] = c1_vertex_dist[c1_i51 + 3];
  }

  c1_macro_leg_len[1] = c1_norm(chartInstance, c1_c_vertex_dist);
  _SFD_EML_CALL(0,56);
  for (c1_i52 = 0; c1_i52 < 3; c1_i52 = c1_i52 + 1) {
    c1_d_vertex_dist[c1_i52] = c1_vertex_dist[c1_i52 + 6];
  }

  c1_macro_leg_len[2] = c1_norm(chartInstance, c1_d_vertex_dist);
 label_5:
  ;
  _SFD_EML_CALL(0,-140);
  sf_debug_symbol_scope_pop();
  for (c1_i92 = 0; c1_i92 < 3; c1_i92 = c1_i92 + 1) {
    (*c1_b_macro_leg_len)[c1_i92] = c1_macro_leg_len[c1_i92];
  }

  for (c1_i93 = 0; c1_i93 < 3; c1_i93 = c1_i93 + 1) {
    (*c1_b_micro_leg_len)[c1_i93] = c1_micro_leg_len[c1_i93];
  }

  for (c1_i94 = 0; c1_i94 < 3; c1_i94 = c1_i94 + 1) {
    (*c1_b_x_cur)[c1_i94] = c1_x_cur[c1_i94];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static void c1_abs(SFc1_twa_parallelInstanceStruct *chartInstance, real_T c1_x[3],
                   real_T c1_y[3])
{
  real_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_b_y;
  for (c1_k = 1.0; c1_k <= 3.0; c1_k = c1_k + 1.0) {
    c1_b_k = c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 3, 1, 0) - 1];
    c1_b_y = muDoubleScalarAbs(c1_b_x);
    c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 3, 1, 0) - 1] = c1_b_y;
  }
}

static void c1_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance)
{
}

static void c1_eml_xgemm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_A[9], real_T c1_B[9], real_T c1_C[9], real_T
  c1_b_C[9])
{
  int32_T c1_i95;
  real_T c1_b_A[9];
  int32_T c1_i96;
  real_T c1_b_B[9];
  int32_T c1_i97;
  real_T c1_c_A[9];
  int32_T c1_i98;
  real_T c1_c_B[9];
  int32_T c1_i99;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  for (c1_i95 = 0; c1_i95 < 9; c1_i95 = c1_i95 + 1) {
    c1_b_A[c1_i95] = c1_A[c1_i95];
  }

  for (c1_i96 = 0; c1_i96 < 9; c1_i96 = c1_i96 + 1) {
    c1_b_B[c1_i96] = c1_B[c1_i96];
  }

  for (c1_i97 = 0; c1_i97 < 9; c1_i97 = c1_i97 + 1) {
    c1_c_A[c1_i97] = c1_b_A[c1_i97];
  }

  for (c1_i98 = 0; c1_i98 < 9; c1_i98 = c1_i98 + 1) {
    c1_c_B[c1_i98] = c1_b_B[c1_i98];
  }

  for (c1_i99 = 0; c1_i99 < 3; c1_i99 = c1_i99 + 1) {
    c1_i100 = 0;
    for (c1_i101 = 0; c1_i101 < 3; c1_i101 = c1_i101 + 1) {
      c1_b_C[c1_i100 + c1_i99] = 0.0;
      c1_i102 = 0;
      for (c1_i103 = 0; c1_i103 < 3; c1_i103 = c1_i103 + 1) {
        c1_b_C[c1_i100 + c1_i99] = c1_b_C[c1_i100 + c1_i99] + c1_c_A[c1_i102 +
          c1_i99] * c1_c_B[c1_i103 + c1_i100];
        c1_i102 = c1_i102 + 3;
      }

      c1_i100 = c1_i100 + 3;
    }
  }
}

static void c1_b_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance)
{
}

static void c1_c_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c1_norm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                      c1_x[3])
{
  int32_T c1_i104;
  real_T c1_b_x[3];
  int32_T c1_i105;
  real_T c1_c_x[3];
  int32_T c1_i106;
  real_T c1_d_x[3];
  int32_T c1_i107;
  real_T c1_e_x[3];
  for (c1_i104 = 0; c1_i104 < 3; c1_i104 = c1_i104 + 1) {
    c1_b_x[c1_i104] = c1_x[c1_i104];
  }

  for (c1_i105 = 0; c1_i105 < 3; c1_i105 = c1_i105 + 1) {
    c1_c_x[c1_i105] = c1_b_x[c1_i105];
  }

  for (c1_i106 = 0; c1_i106 < 3; c1_i106 = c1_i106 + 1) {
    c1_d_x[c1_i106] = c1_c_x[c1_i106];
  }

  for (c1_i107 = 0; c1_i107 < 3; c1_i107 = c1_i107 + 1) {
    c1_e_x[c1_i107] = c1_d_x[c1_i107];
  }

  return c1_ceval_xnrm2(chartInstance, 3, c1_e_x, 1, 1);
}

static real_T c1_b_abs(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  return muDoubleScalarAbs(c1_b_x);
}

static real_T c1_ceval_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[3], int32_T c1_ix0, int32_T
  c1_incx)
{
  return dnrm232(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 3, 1, 0) - 1], &
                 c1_incx);
}

static real_T c1_b_norm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_x[9])
{
  int32_T c1_i108;
  real_T c1_b_x[9];
  real_T c1_s[3];
  for (c1_i108 = 0; c1_i108 < 9; c1_i108 = c1_i108 + 1) {
    c1_b_x[c1_i108] = c1_x[c1_i108];
  }

  c1_svd(chartInstance, c1_b_x, c1_s);
  return c1_s[0];
}

static void c1_svd(SFc1_twa_parallelInstanceStruct *chartInstance, real_T c1_A[9],
                   real_T c1_Uout[3])
{
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i109;
  real_T c1_s[3];
  int32_T c1_i110;
  real_T c1_e[3];
  int32_T c1_i111;
  real_T c1_work[3];
  int32_T c1_q;
  int32_T c1_b_q;
  int32_T c1_a;
  int32_T c1_qp1;
  int32_T c1_b_a;
  int32_T c1_qm1;
  int32_T c1_b;
  int32_T c1_c;
  int32_T c1_c_a;
  int32_T c1_b_b;
  int32_T c1_qq;
  int32_T c1_c_b;
  int32_T c1_nmq;
  int32_T c1_d_a;
  int32_T c1_nmqp1;
  int32_T c1_i112;
  real_T c1_b_A[9];
  real_T c1_nrm;
  real_T c1_absx;
  real_T c1_d;
  real_T c1_y;
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_z;
  int32_T c1_i113;
  real_T c1_c_A[9];
  int32_T c1_b_qp1;
  int32_T c1_jj;
  int32_T c1_b_jj;
  int32_T c1_e_a;
  int32_T c1_b_c;
  int32_T c1_d_b;
  int32_T c1_c_c;
  int32_T c1_f_a;
  int32_T c1_e_b;
  int32_T c1_qjj;
  int32_T c1_i114;
  real_T c1_d_A[9];
  int32_T c1_i115;
  real_T c1_e_A[9];
  real_T c1_t;
  real_T c1_x;
  real_T c1_d_y;
  real_T c1_b_x;
  real_T c1_e_y;
  real_T c1_b_z;
  int32_T c1_i116;
  real_T c1_f_A[9];
  int32_T c1_f_b;
  int32_T c1_pmq;
  int32_T c1_i117;
  real_T c1_b_e[3];
  real_T c1_b_absx;
  real_T c1_b_d;
  real_T c1_f_y;
  real_T c1_g_y;
  real_T c1_h_y;
  real_T c1_c_z;
  int32_T c1_i118;
  real_T c1_c_e[3];
  int32_T c1_c_qp1;
  int32_T c1_ii;
  int32_T c1_b_ii;
  int32_T c1_d_qp1;
  int32_T c1_c_jj;
  int32_T c1_g_a;
  int32_T c1_d_c;
  int32_T c1_g_b;
  int32_T c1_e_c;
  int32_T c1_h_a;
  int32_T c1_h_b;
  int32_T c1_qp1jj;
  int32_T c1_i119;
  real_T c1_g_A[9];
  int32_T c1_i120;
  real_T c1_b_work[3];
  int32_T c1_e_qp1;
  int32_T c1_d_jj;
  real_T c1_c_x;
  real_T c1_i_y;
  real_T c1_d_x;
  real_T c1_j_y;
  int32_T c1_i_a;
  int32_T c1_f_c;
  int32_T c1_i_b;
  int32_T c1_g_c;
  int32_T c1_j_a;
  int32_T c1_j_b;
  int32_T c1_i121;
  real_T c1_c_work[3];
  int32_T c1_i122;
  real_T c1_h_A[9];
  int32_T c1_m;
  int32_T c1_c_q;
  real_T c1_rt;
  real_T c1_e_x;
  real_T c1_k_y;
  real_T c1_f_x;
  real_T c1_l_y;
  real_T c1_r;
  real_T c1_g_x;
  real_T c1_m_y;
  real_T c1_h_x;
  real_T c1_n_y;
  real_T c1_d_z;
  real_T c1_i_x;
  real_T c1_o_y;
  real_T c1_j_x;
  real_T c1_p_y;
  int32_T c1_k_a;
  int32_T c1_h_c;
  int32_T c1_l_a;
  int32_T c1_i_c;
  real_T c1_m_a;
  real_T c1_k_b;
  real_T c1_q_y;
  real_T c1_iter;
  real_T c1_snorm;
  int32_T c1_c_ii;
  int32_T c1_n_a;
  int32_T c1_o_a;
  int32_T c1_i123;
  int32_T c1_d_ii;
  int32_T c1_p_a;
  int32_T c1_j_c;
  real_T c1_test0;
  real_T c1_ztest0;
  real_T c1_l_b;
  real_T c1_r_y;
  real_T c1_m_b;
  real_T c1_s_y;
  int32_T c1_q_a;
  int32_T c1_k_c;
  real_T c1_kase;
  int32_T c1_qs;
  int32_T c1_b_m;
  int32_T c1_e_ii;
  real_T c1_test;
  int32_T c1_r_a;
  int32_T c1_l_c;
  int32_T c1_s_a;
  int32_T c1_m_c;
  real_T c1_ztest;
  real_T c1_n_b;
  real_T c1_t_y;
  int32_T c1_t_a;
  int32_T c1_u_a;
  int32_T c1_n_c;
  real_T c1_f;
  int32_T c1_v_a;
  int32_T c1_o_c;
  int32_T c1_w_a;
  int32_T c1_i124;
  int32_T c1_c_k;
  real_T c1_t1;
  real_T c1_sn;
  real_T c1_cs;
  real_T c1_b_f;
  real_T c1_b_t1;
  real_T c1_b_cs;
  real_T c1_b_sn;
  int32_T c1_x_a;
  int32_T c1_km1;
  real_T c1_y_a;
  real_T c1_o_b;
  real_T c1_ab_a;
  real_T c1_p_b;
  real_T c1_u_y;
  int32_T c1_bb_a;
  int32_T c1_d_q;
  int32_T c1_d_k;
  real_T c1_c_sn;
  real_T c1_c_cs;
  real_T c1_c_f;
  real_T c1_c_t1;
  real_T c1_cb_a;
  real_T c1_q_b;
  real_T c1_db_a;
  real_T c1_r_b;
  real_T c1_v_y;
  int32_T c1_eb_a;
  int32_T c1_mm1;
  real_T c1_d0;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_dv19[5];
  real_T c1_scale;
  real_T c1_k_x;
  real_T c1_w_y;
  real_T c1_l_x;
  real_T c1_x_y;
  real_T c1_sm;
  real_T c1_m_x;
  real_T c1_y_y;
  real_T c1_n_x;
  real_T c1_ab_y;
  real_T c1_smm1;
  real_T c1_o_x;
  real_T c1_bb_y;
  real_T c1_p_x;
  real_T c1_cb_y;
  real_T c1_emm1;
  real_T c1_q_x;
  real_T c1_db_y;
  real_T c1_r_x;
  real_T c1_eb_y;
  real_T c1_sqds;
  real_T c1_s_x;
  real_T c1_fb_y;
  real_T c1_t_x;
  real_T c1_gb_y;
  real_T c1_eqds;
  real_T c1_fb_a;
  real_T c1_s_b;
  real_T c1_hb_y;
  real_T c1_gb_a;
  real_T c1_t_b;
  real_T c1_ib_y;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_u_b;
  real_T c1_hb_a;
  real_T c1_v_b;
  real_T c1_p_c;
  real_T c1_ib_a;
  real_T c1_w_b;
  real_T c1_shift;
  real_T c1_jb_a;
  real_T c1_x_b;
  real_T c1_jb_y;
  real_T c1_w_x;
  real_T c1_kb_y;
  real_T c1_x_x;
  real_T c1_lb_y;
  real_T c1_kb_a;
  real_T c1_y_b;
  real_T c1_mb_y;
  real_T c1_lb_a;
  real_T c1_ab_b;
  real_T c1_g;
  int32_T c1_e_q;
  int32_T c1_e_k;
  int32_T c1_mb_a;
  int32_T c1_nb_a;
  int32_T c1_kp1;
  real_T c1_d_sn;
  real_T c1_d_cs;
  real_T c1_b_g;
  real_T c1_d_f;
  real_T c1_ob_a;
  real_T c1_bb_b;
  real_T c1_nb_y;
  real_T c1_pb_a;
  real_T c1_cb_b;
  real_T c1_ob_y;
  real_T c1_qb_a;
  real_T c1_db_b;
  real_T c1_pb_y;
  real_T c1_rb_a;
  real_T c1_eb_b;
  real_T c1_qb_y;
  real_T c1_sb_a;
  real_T c1_fb_b;
  real_T c1_tb_a;
  real_T c1_gb_b;
  real_T c1_rb_y;
  real_T c1_e_sn;
  real_T c1_e_cs;
  real_T c1_c_g;
  real_T c1_e_f;
  real_T c1_ub_a;
  real_T c1_hb_b;
  real_T c1_sb_y;
  real_T c1_vb_a;
  real_T c1_ib_b;
  real_T c1_tb_y;
  real_T c1_wb_a;
  real_T c1_jb_b;
  real_T c1_ub_y;
  real_T c1_xb_a;
  real_T c1_kb_b;
  real_T c1_vb_y;
  real_T c1_yb_a;
  real_T c1_lb_b;
  real_T c1_ac_a;
  real_T c1_mb_b;
  real_T c1_wb_y;
  int32_T c1_bc_a;
  int32_T c1_q_c;
  int32_T c1_i125;
  int32_T c1_f_k;
  int32_T c1_cc_a;
  int32_T c1_dc_a;
  int32_T c1_ec_a;
  c1_c_eml_scalar_eg(chartInstance);
  for (c1_k = 1; c1_k < 10; c1_k = c1_k + 1) {
    c1_b_k = c1_k;
    if (!c1_isfinite(chartInstance, c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 9, 1, 0) - 1
                     ])) {
      c1_eml_error(chartInstance);
    }
  }

  for (c1_i109 = 0; c1_i109 < 3; c1_i109 = c1_i109 + 1) {
    c1_s[c1_i109] = 0.0;
  }

  for (c1_i110 = 0; c1_i110 < 3; c1_i110 = c1_i110 + 1) {
    c1_e[c1_i110] = 0.0;
  }

  for (c1_i111 = 0; c1_i111 < 3; c1_i111 = c1_i111 + 1) {
    c1_work[c1_i111] = 0.0;
  }

  for (c1_q = 1; c1_q < 3; c1_q = c1_q + 1) {
    c1_b_q = c1_q;
    c1_a = c1_b_q;
    c1_qp1 = c1_a + 1;
    c1_b_a = c1_b_q;
    c1_qm1 = c1_b_a - 1;
    c1_b = c1_qm1;
    c1_c = 3 * c1_b;
    c1_c_a = c1_b_q;
    c1_b_b = c1_c;
    c1_qq = c1_c_a + c1_b_b;
    c1_c_b = c1_b_q;
    c1_nmq = 3 - c1_c_b;
    c1_d_a = c1_nmq;
    c1_nmqp1 = c1_d_a + 1;
    if (c1_b_q <= 2) {
      for (c1_i112 = 0; c1_i112 < 9; c1_i112 = c1_i112 + 1) {
        c1_b_A[c1_i112] = c1_A[c1_i112];
      }

      c1_nrm = c1_eml_xnrm2(chartInstance, c1_nmqp1, c1_b_A, c1_qq);
      if (c1_nrm == 0.0) {
        c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1] = 0.0;
      } else {
        c1_absx = c1_nrm;
        c1_d = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c1_qq), 1, 9, 1, 0) - 1];
        if (c1_d < 0.0) {
          c1_y = -c1_absx;
        } else {
          c1_y = c1_absx;
        }

        c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1] = c1_y;
        c1_b_y = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) - 1];
        c1_c_y = c1_b_y;
        c1_z = 1.0 / c1_c_y;
        for (c1_i113 = 0; c1_i113 < 9; c1_i113 = c1_i113 + 1) {
          c1_c_A[c1_i113] = c1_A[c1_i113];
        }

        c1_eml_xscal(chartInstance, c1_nmqp1, c1_z, c1_c_A, c1_qq, c1_A);
        c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_qq), 1, 9, 1, 0) - 1] = c1_A[
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_qq), 1, 9, 1, 0) - 1] + 1.0;
        c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1] = -c1_s[
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1];
      }
    }

    c1_b_qp1 = c1_qp1;
    for (c1_jj = c1_b_qp1; c1_jj < 4; c1_jj = c1_jj + 1) {
      c1_b_jj = c1_jj;
      c1_e_a = c1_b_jj;
      c1_b_c = c1_e_a - 1;
      c1_d_b = c1_b_c;
      c1_c_c = 3 * c1_d_b;
      c1_f_a = c1_b_q;
      c1_e_b = c1_c_c;
      c1_qjj = c1_f_a + c1_e_b;
      if (c1_b_q <= 2) {
        if (c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_b_q), 1, 3, 1, 0) - 1] != 0.0) {
          for (c1_i114 = 0; c1_i114 < 9; c1_i114 = c1_i114 + 1) {
            c1_d_A[c1_i114] = c1_A[c1_i114];
          }

          for (c1_i115 = 0; c1_i115 < 9; c1_i115 = c1_i115 + 1) {
            c1_e_A[c1_i115] = c1_A[c1_i115];
          }

          c1_t = c1_eml_xdotc(chartInstance, c1_nmqp1, c1_d_A, c1_qq, c1_e_A,
                              c1_qjj);
          c1_x = c1_t;
          c1_d_y = c1_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) - 1) + 3 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_q), 1, 3, 2, 0) - 1)];
          c1_b_x = c1_x;
          c1_e_y = c1_d_y;
          c1_b_z = c1_b_x / c1_e_y;
          c1_t = -c1_b_z;
          for (c1_i116 = 0; c1_i116 < 9; c1_i116 = c1_i116 + 1) {
            c1_f_A[c1_i116] = c1_A[c1_i116];
          }

          c1_eml_xaxpy(chartInstance, c1_nmqp1, c1_t, c1_qq, c1_f_A, c1_qjj,
                       c1_A);
          goto label_1;
        }
      }

     label_1:
      ;
      c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_jj), 1, 3, 1, 0) - 1] = c1_A[
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c1_qjj), 1, 9, 1, 0) - 1];
    }

    if (c1_b_q <= 1) {
      c1_f_b = c1_b_q;
      c1_pmq = 3 - c1_f_b;
      for (c1_i117 = 0; c1_i117 < 3; c1_i117 = c1_i117 + 1) {
        c1_b_e[c1_i117] = c1_e[c1_i117];
      }

      c1_nrm = c1_b_eml_xnrm2(chartInstance, c1_pmq, c1_b_e, c1_qp1);
      if (c1_nrm == 0.0) {
        c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1] = 0.0;
      } else {
        c1_b_absx = c1_nrm;
        c1_b_d = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_qp1), 1, 3, 1, 0) - 1];
        if (c1_b_d < 0.0) {
          c1_f_y = -c1_b_absx;
        } else {
          c1_f_y = c1_b_absx;
        }

        c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1] = c1_f_y;
        c1_g_y = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) - 1];
        c1_h_y = c1_g_y;
        c1_c_z = 1.0 / c1_h_y;
        for (c1_i118 = 0; c1_i118 < 3; c1_i118 = c1_i118 + 1) {
          c1_c_e[c1_i118] = c1_e[c1_i118];
        }

        c1_b_eml_xscal(chartInstance, c1_pmq, c1_c_z, c1_c_e, c1_qp1, c1_e);
        c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_qp1), 1, 3, 1, 0) - 1] = c1_e[
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_qp1), 1, 3, 1, 0) - 1] + 1.0;
      }

      c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_q), 1, 3, 1, 0) - 1] = -c1_e[
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c1_b_q), 1, 3, 1, 0) - 1];
      if (c1_qp1 <= 3) {
        if (c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_b_q), 1, 3, 1, 0) - 1] != 0.0) {
          c1_c_qp1 = c1_qp1;
          for (c1_ii = c1_c_qp1; c1_ii < 4; c1_ii = c1_ii + 1) {
            c1_b_ii = c1_ii;
            c1_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c1_b_ii), 1, 3, 1, 0) - 1] = 0.0;
          }

          c1_d_qp1 = c1_qp1;
          for (c1_c_jj = c1_d_qp1; c1_c_jj < 4; c1_c_jj = c1_c_jj + 1) {
            c1_b_jj = c1_c_jj;
            c1_g_a = c1_b_jj;
            c1_d_c = c1_g_a - 1;
            c1_g_b = c1_d_c;
            c1_e_c = 3 * c1_g_b;
            c1_h_a = c1_qp1;
            c1_h_b = c1_e_c;
            c1_qp1jj = c1_h_a + c1_h_b;
            for (c1_i119 = 0; c1_i119 < 9; c1_i119 = c1_i119 + 1) {
              c1_g_A[c1_i119] = c1_A[c1_i119];
            }

            for (c1_i120 = 0; c1_i120 < 3; c1_i120 = c1_i120 + 1) {
              c1_b_work[c1_i120] = c1_work[c1_i120];
            }

            c1_b_eml_xaxpy(chartInstance, c1_nmq,
                           c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c1_b_jj), 1, 3, 1
              , 0) - 1], c1_g_A, c1_qp1jj, c1_b_work, c1_qp1, c1_work);
          }

          c1_e_qp1 = c1_qp1;
          for (c1_d_jj = c1_e_qp1; c1_d_jj < 4; c1_d_jj = c1_d_jj + 1) {
            c1_b_jj = c1_d_jj;
            c1_c_x = -c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c1_b_jj), 1, 3, 1, 0) - 1];
            c1_i_y = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c1_qp1), 1, 3, 1, 0) - 1];
            c1_d_x = c1_c_x;
            c1_j_y = c1_i_y;
            c1_t = c1_d_x / c1_j_y;
            c1_i_a = c1_b_jj;
            c1_f_c = c1_i_a - 1;
            c1_i_b = c1_f_c;
            c1_g_c = 3 * c1_i_b;
            c1_j_a = c1_qp1;
            c1_j_b = c1_g_c;
            c1_qp1jj = c1_j_a + c1_j_b;
            for (c1_i121 = 0; c1_i121 < 3; c1_i121 = c1_i121 + 1) {
              c1_c_work[c1_i121] = c1_work[c1_i121];
            }

            for (c1_i122 = 0; c1_i122 < 9; c1_i122 = c1_i122 + 1) {
              c1_h_A[c1_i122] = c1_A[c1_i122];
            }

            c1_c_eml_xaxpy(chartInstance, c1_nmq, c1_t, c1_c_work, c1_qp1,
                           c1_h_A, c1_qp1jj, c1_A);
          }

          goto label_2;
        }
      }

     label_2:
      ;
    }
  }

  c1_m = 3;
  c1_s[2] = c1_A[8];
  c1_e[1] = c1_A[7];
  c1_e[2] = 0.0;
  for (c1_c_q = 1; c1_c_q < 4; c1_c_q = c1_c_q + 1) {
    c1_b_q = c1_c_q;
    if (c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1] != 0.0) {
      c1_rt = c1_b_abs(chartInstance, c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) -
                       1]);
      c1_e_x = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c1_b_q), 1, 3, 1, 0) - 1];
      c1_k_y = c1_rt;
      c1_f_x = c1_e_x;
      c1_l_y = c1_k_y;
      c1_r = c1_f_x / c1_l_y;
      c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_q), 1, 3, 1, 0) - 1] = c1_rt;
      if (c1_b_q < 3) {
        c1_g_x = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) - 1];
        c1_m_y = c1_r;
        c1_h_x = c1_g_x;
        c1_n_y = c1_m_y;
        c1_d_z = c1_h_x / c1_n_y;
        c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1] = c1_d_z;
      }
    }

    if (c1_b_q < 3) {
      if (c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_q), 1, 3, 1, 0) - 1] != 0.0) {
        c1_rt = c1_b_abs(chartInstance, c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) -
                         1]);
        c1_i_x = c1_rt;
        c1_o_y = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) - 1];
        c1_j_x = c1_i_x;
        c1_p_y = c1_o_y;
        c1_r = c1_j_x / c1_p_y;
        c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_q), 1, 3, 1, 0) - 1] = c1_rt;
        c1_k_a = c1_b_q;
        c1_h_c = c1_k_a + 1;
        c1_l_a = c1_b_q;
        c1_i_c = c1_l_a + 1;
        c1_m_a = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_i_c), 1, 3, 1, 0) - 1];
        c1_k_b = c1_r;
        c1_q_y = c1_m_a * c1_k_b;
        c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_h_c), 1, 3, 1, 0) - 1] = c1_q_y;
      }
    }
  }

  c1_iter = 0.0;
  c1_eps(chartInstance);
  c1_snorm = 0.0;
  for (c1_c_ii = 1; c1_c_ii < 4; c1_c_ii = c1_c_ii + 1) {
    c1_b_ii = c1_c_ii;
    c1_snorm = c1_max(chartInstance, c1_snorm, c1_max(chartInstance, c1_b_abs
      (chartInstance, c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (
      int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_ii), 1, 3, 1, 0) - 1]),
      c1_b_abs(chartInstance, c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (
      int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_ii), 1, 3, 1, 0) - 1])));
  }

 label_11:
  ;
  if ((real_T)c1_m > 0.0) {
    if (c1_iter >= 75.0) {
      c1_c_eml_error(chartInstance);
    } else {
      c1_n_a = c1_m;
      c1_b_q = c1_n_a - 1;
      c1_o_a = c1_m;
      c1_i123 = c1_o_a - 1;
      c1_d_ii = c1_i123;
     label_6:
      ;
      if (c1_d_ii > -1) {
        c1_b_ii = c1_d_ii;
        c1_b_q = c1_b_ii;
        if ((real_T)c1_b_ii == 0.0) {
          goto label_3;
        } else {
          c1_p_a = c1_b_ii;
          c1_j_c = c1_p_a + 1;
          c1_test0 = c1_b_abs(chartInstance, c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_ii),
            1, 3, 1, 0
            ) - 1]) + c1_b_abs(chartInstance, c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_j_c), 1, 3, 1, 0)
                               - 1]);
          c1_ztest0 = c1_b_abs(chartInstance, c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_ii), 1, 3, 1,
            0) - 1]);
          c1_eps(chartInstance);
          c1_l_b = c1_test0;
          c1_r_y = 2.2204460492503131E-016 * c1_l_b;
          if (c1_ztest0 <= c1_r_y) {
            goto label_4;
          } else if (c1_ztest0 <= 1.0020841800044864E-292) {
            goto label_4;
          } else {
            if (c1_iter > 20.0) {
              c1_eps(chartInstance);
              c1_m_b = c1_snorm;
              c1_s_y = 2.2204460492503131E-016 * c1_m_b;
              if (c1_ztest0 <= c1_s_y) {
                goto label_5;
              }
            }
          }
        }
      } else {
        goto label_3;
      }

      c1_d_ii = c1_d_ii + -1;
      goto label_6;
     label_4:
      ;
     label_5:
      ;
      c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_ii), 1, 3, 1, 0) - 1] = 0.0;
     label_3:
      ;
      c1_q_a = c1_m;
      c1_k_c = c1_q_a - 1;
      if (c1_b_q == c1_k_c) {
        c1_kase = 4.0;
      } else {
        c1_qs = c1_m;
        c1_b_m = c1_m;
        c1_e_ii = c1_b_m;
       label_8:
        ;
        if (c1_e_ii >= c1_b_q) {
          c1_b_ii = c1_e_ii;
          c1_qs = c1_b_ii;
          if (c1_b_ii == c1_b_q) {
            goto label_7;
          } else {
            c1_test = 0.0;
            if (c1_b_ii < c1_m) {
              c1_test = c1_b_abs(chartInstance, c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK
                                 ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                c1_b_ii), 1, 3, 1, 0)
                                 - 1]);
            }

            c1_r_a = c1_b_q;
            c1_l_c = c1_r_a + 1;
            if (c1_b_ii > c1_l_c) {
              c1_s_a = c1_b_ii;
              c1_m_c = c1_s_a - 1;
              c1_test = c1_test + c1_b_abs(chartInstance,
                c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c1_m_c), 1
                , 3, 1, 0) - 1]);
            }

            c1_ztest = c1_b_abs(chartInstance, c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_ii), 1, 3, 1, 0
              ) - 1]);
            c1_eps(chartInstance);
            c1_n_b = c1_test;
            c1_t_y = 2.2204460492503131E-016 * c1_n_b;
            if (c1_ztest <= c1_t_y) {
            } else if (c1_ztest <= 1.0020841800044864E-292) {
            } else {
              c1_e_ii = c1_e_ii + -1;
              goto label_8;
            }
          }
        } else {
          goto label_7;
        }

        c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_ii), 1, 3, 1, 0) - 1] = 0.0;
       label_7:
        ;
        if (c1_qs == c1_b_q) {
          c1_kase = 3.0;
        } else if (c1_qs == c1_m) {
          c1_kase = 1.0;
        } else {
          c1_kase = 2.0;
          c1_b_q = c1_qs;
        }
      }

      c1_t_a = c1_b_q;
      c1_b_q = c1_t_a + 1;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c1_kase)) {
       case 1:
        c1_u_a = c1_m;
        c1_n_c = c1_u_a - 1;
        c1_f = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c1_n_c), 1, 3, 1, 0) - 1];
        c1_v_a = c1_m;
        c1_o_c = c1_v_a - 1;
        c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_o_c), 1, 3, 1, 0) - 1] = 0.0;
        c1_w_a = c1_m;
        c1_i124 = c1_w_a - 1;
        for (c1_c_k = c1_i124; c1_c_k >= c1_b_q; c1_c_k = c1_c_k + -1) {
          c1_b_k = c1_c_k;
          c1_t1 = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_eml_xrotg(chartInstance, c1_t1, c1_f, &c1_b_t1, &c1_b_f, &c1_cs,
                       &c1_sn);
          c1_t1 = c1_b_t1;
          c1_f = c1_b_f;
          c1_b_cs = c1_cs;
          c1_b_sn = c1_sn;
          c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_k), 1, 3, 1, 0) - 1] = c1_t1;
          if (c1_b_k > c1_b_q) {
            c1_x_a = c1_b_k;
            c1_km1 = c1_x_a - 1;
            c1_y_a = -c1_b_sn;
            c1_o_b = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c1_km1), 1, 3, 1, 0) - 1];
            c1_f = c1_y_a * c1_o_b;
            c1_ab_a = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c1_km1), 1, 3, 1, 0) - 1];
            c1_p_b = c1_b_cs;
            c1_u_y = c1_ab_a * c1_p_b;
            c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_km1), 1, 3, 1, 0) - 1] = c1_u_y;
          }
        }
        break;

       case 2:
        c1_bb_a = c1_b_q;
        c1_qm1 = c1_bb_a - 1;
        c1_f = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c1_qm1), 1, 3, 1, 0) - 1];
        c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_qm1), 1, 3, 1, 0) - 1] = 0.0;
        c1_d_q = c1_b_q;
        for (c1_d_k = c1_d_q; c1_d_k <= c1_m; c1_d_k = c1_d_k + 1) {
          c1_b_k = c1_d_k;
          c1_t1 = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_eml_xrotg(chartInstance, c1_t1, c1_f, &c1_c_t1, &c1_c_f, &c1_c_cs,
                       &c1_c_sn);
          c1_t1 = c1_c_t1;
          c1_b_cs = c1_c_cs;
          c1_b_sn = c1_c_sn;
          c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_k), 1, 3, 1, 0) - 1] = c1_t1;
          c1_cb_a = -c1_b_sn;
          c1_q_b = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_f = c1_cb_a * c1_q_b;
          c1_db_a = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_r_b = c1_b_cs;
          c1_v_y = c1_db_a * c1_r_b;
          c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_k), 1, 3, 1, 0) - 1] = c1_v_y;
        }
        break;

       case 3:
        c1_eb_a = c1_m;
        c1_mm1 = c1_eb_a - 1;
        c1_d0 = c1_b_abs(chartInstance, c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_m), 1, 3, 1, 0) - 1]
                         );
        c1_d1 = c1_b_abs(chartInstance, c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_mm1), 1, 3, 1, 0) -
                         1]);
        c1_d2 = c1_b_abs(chartInstance, c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_mm1), 1, 3, 1, 0) -
                         1]);
        c1_d3 = c1_b_abs(chartInstance, c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) -
                         1]);
        c1_d4 = c1_b_abs(chartInstance, c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) -
                         1]);
        c1_dv19[0] = c1_d0;
        c1_dv19[1] = c1_d1;
        c1_dv19[2] = c1_d2;
        c1_dv19[3] = c1_d3;
        c1_dv19[4] = c1_d4;
        c1_scale = c1_b_max(chartInstance, c1_dv19);
        c1_k_x = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_m), 1, 3, 1, 0) - 1];
        c1_w_y = c1_scale;
        c1_l_x = c1_k_x;
        c1_x_y = c1_w_y;
        c1_sm = c1_l_x / c1_x_y;
        c1_m_x = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_mm1), 1, 3, 1, 0) - 1];
        c1_y_y = c1_scale;
        c1_n_x = c1_m_x;
        c1_ab_y = c1_y_y;
        c1_smm1 = c1_n_x / c1_ab_y;
        c1_o_x = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_mm1), 1, 3, 1, 0) - 1];
        c1_bb_y = c1_scale;
        c1_p_x = c1_o_x;
        c1_cb_y = c1_bb_y;
        c1_emm1 = c1_p_x / c1_cb_y;
        c1_q_x = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) - 1];
        c1_db_y = c1_scale;
        c1_r_x = c1_q_x;
        c1_eb_y = c1_db_y;
        c1_sqds = c1_r_x / c1_eb_y;
        c1_s_x = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) - 1];
        c1_fb_y = c1_scale;
        c1_t_x = c1_s_x;
        c1_gb_y = c1_fb_y;
        c1_eqds = c1_t_x / c1_gb_y;
        c1_fb_a = c1_smm1 + c1_sm;
        c1_s_b = c1_smm1 - c1_sm;
        c1_hb_y = c1_fb_a * c1_s_b;
        c1_gb_a = c1_emm1;
        c1_t_b = c1_emm1;
        c1_ib_y = c1_gb_a * c1_t_b;
        c1_u_x = c1_hb_y + c1_ib_y;
        c1_v_x = c1_u_x;
        c1_u_b = c1_v_x / 2.0;
        c1_hb_a = c1_sm;
        c1_v_b = c1_emm1;
        c1_p_c = c1_hb_a * c1_v_b;
        c1_ib_a = c1_p_c;
        c1_w_b = c1_p_c;
        c1_p_c = c1_ib_a * c1_w_b;
        c1_shift = 0.0;
        if (c1_u_b != 0.0) {
        } else if (c1_p_c != 0.0) {
        } else {
          goto label_9;
        }

        c1_jb_a = c1_u_b;
        c1_x_b = c1_u_b;
        c1_jb_y = c1_jb_a * c1_x_b;
        c1_shift = c1_sqrt(chartInstance, c1_jb_y + c1_p_c);
        if (c1_u_b < 0.0) {
          c1_shift = -c1_shift;
        }

        c1_w_x = c1_p_c;
        c1_kb_y = c1_u_b + c1_shift;
        c1_x_x = c1_w_x;
        c1_lb_y = c1_kb_y;
        c1_shift = c1_x_x / c1_lb_y;
       label_9:
        ;
        c1_kb_a = c1_sqds + c1_sm;
        c1_y_b = c1_sqds - c1_sm;
        c1_mb_y = c1_kb_a * c1_y_b;
        c1_f = c1_mb_y + c1_shift;
        c1_lb_a = c1_sqds;
        c1_ab_b = c1_eqds;
        c1_g = c1_lb_a * c1_ab_b;
        c1_e_q = c1_b_q;
        for (c1_e_k = c1_e_q; c1_e_k <= c1_mm1; c1_e_k = c1_e_k + 1) {
          c1_b_k = c1_e_k;
          c1_mb_a = c1_b_k;
          c1_km1 = c1_mb_a - 1;
          c1_nb_a = c1_b_k;
          c1_kp1 = c1_nb_a + 1;
          c1_eml_xrotg(chartInstance, c1_f, c1_g, &c1_d_f, &c1_b_g, &c1_d_cs,
                       &c1_d_sn);
          c1_f = c1_d_f;
          c1_b_cs = c1_d_cs;
          c1_b_sn = c1_d_sn;
          if (c1_b_k > c1_b_q) {
            c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_km1), 1, 3, 1, 0) - 1] = c1_f;
          }

          c1_ob_a = c1_b_cs;
          c1_bb_b = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_nb_y = c1_ob_a * c1_bb_b;
          c1_pb_a = c1_b_sn;
          c1_cb_b = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_ob_y = c1_pb_a * c1_cb_b;
          c1_f = c1_nb_y + c1_ob_y;
          c1_qb_a = c1_b_cs;
          c1_db_b = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_pb_y = c1_qb_a * c1_db_b;
          c1_rb_a = c1_b_sn;
          c1_eb_b = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_qb_y = c1_rb_a * c1_eb_b;
          c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_k), 1, 3, 1, 0) - 1] = c1_pb_y - c1_qb_y;
          c1_sb_a = c1_b_sn;
          c1_fb_b = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_kp1), 1, 3, 1, 0) - 1];
          c1_g = c1_sb_a * c1_fb_b;
          c1_tb_a = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_kp1), 1, 3, 1, 0) - 1];
          c1_gb_b = c1_b_cs;
          c1_rb_y = c1_tb_a * c1_gb_b;
          c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_kp1), 1, 3, 1, 0) - 1] = c1_rb_y;
          c1_eml_xrotg(chartInstance, c1_f, c1_g, &c1_e_f, &c1_c_g, &c1_e_cs,
                       &c1_e_sn);
          c1_f = c1_e_f;
          c1_b_cs = c1_e_cs;
          c1_b_sn = c1_e_sn;
          c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_k), 1, 3, 1, 0) - 1] = c1_f;
          c1_ub_a = c1_b_cs;
          c1_hb_b = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_sb_y = c1_ub_a * c1_hb_b;
          c1_vb_a = c1_b_sn;
          c1_ib_b = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_kp1), 1, 3, 1, 0) - 1];
          c1_tb_y = c1_vb_a * c1_ib_b;
          c1_f = c1_sb_y + c1_tb_y;
          c1_wb_a = -c1_b_sn;
          c1_jb_b = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
          c1_ub_y = c1_wb_a * c1_jb_b;
          c1_xb_a = c1_b_cs;
          c1_kb_b = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_kp1), 1, 3, 1, 0) - 1];
          c1_vb_y = c1_xb_a * c1_kb_b;
          c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_kp1), 1, 3, 1, 0) - 1] = c1_ub_y + c1_vb_y;
          c1_yb_a = c1_b_sn;
          c1_lb_b = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_kp1), 1, 3, 1, 0) - 1];
          c1_g = c1_yb_a * c1_lb_b;
          c1_ac_a = c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_kp1), 1, 3, 1, 0) - 1];
          c1_mb_b = c1_b_cs;
          c1_wb_y = c1_ac_a * c1_mb_b;
          c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_kp1), 1, 3, 1, 0) - 1] = c1_wb_y;
        }

        c1_bc_a = c1_m;
        c1_q_c = c1_bc_a - 1;
        c1_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_q_c), 1, 3, 1, 0) - 1] = c1_f;
        c1_iter = c1_iter + 1.0;
        break;

       default:
        if (c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_b_q), 1, 3, 1, 0) - 1] < 0.0) {
          c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_q), 1, 3, 1, 0) - 1] = -c1_s[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_q), 1, 3, 1, 0) - 1];
        }

        c1_cc_a = c1_b_q;
        c1_qp1 = c1_cc_a + 1;
       label_10:
        ;
        if (c1_b_q < 3) {
          if (c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c1_b_q), 1, 3, 1, 0) - 1] < c1_s[
              _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_qp1), 1, 3, 1, 0) - 1]) {
            c1_rt = c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c1_b_q), 1, 3, 1, 0) - 1];
            c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_b_q), 1, 3, 1, 0) - 1] = c1_s[
              _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_qp1), 1, 3, 1, 0) - 1];
            c1_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_qp1), 1, 3, 1, 0) - 1] = c1_rt;
            c1_b_q = c1_qp1;
            c1_ec_a = c1_b_q;
            c1_qp1 = c1_ec_a + 1;
            goto label_10;
          }
        }

        c1_iter = 0.0;
        c1_dc_a = c1_m;
        c1_m = c1_dc_a - 1;
        break;
      }

      goto label_11;
    }
  }

  for (c1_i125 = 0; c1_i125 < 3; c1_i125 = c1_i125 + 1) {
    c1_Uout[c1_i125] = 0.0;
  }

  for (c1_f_k = 1; c1_f_k < 4; c1_f_k = c1_f_k + 1) {
    c1_b_k = c1_f_k;
    c1_Uout[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 3, 1, 0) - 1] = c1_s[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_b_k), 1, 3, 1, 0) - 1];
  }
}

static boolean_T c1_isfinite(SFc1_twa_parallelInstanceStruct *chartInstance,
  real_T c1_x)
{
  real_T c1_b_x;
  boolean_T c1_b_b;
  boolean_T c1_b0;
  real_T c1_c_x;
  boolean_T c1_c_b;
  boolean_T c1_b1;
  c1_b_x = c1_x;
  c1_b_b = muDoubleScalarIsInf(c1_b_x);
  c1_b0 = !c1_b_b;
  c1_c_x = c1_x;
  c1_c_b = muDoubleScalarIsNaN(c1_c_x);
  c1_b1 = !c1_c_b;
  return c1_b0 && c1_b1;
}

static void c1_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c1_i126;
  static char_T c1_cv0[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'v', 'd',
    ':', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i', 't', 'h'
    , 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c1_u[27];
  const mxArray *c1_y = NULL;
  int32_T c1_i127;
  static char_T c1_cv1[41] = { 'I', 'n', 'p', 'u', 't', ' ', 't', 'o', ' ', 'S',
    'V', 'D', ' ', 'm', 'u', 's', 't', ' ', 'n', 'o', 't'
    , ' ', 'c', 'o', 'n', 't', 'a', 'i', 'n', ' ', 'N', 'a', 'N', ' ', 'o', 'r',
    ' ', 'I', 'n', 'f', '.' };

  char_T c1_b_u[41];
  const mxArray *c1_b_y = NULL;
  for (c1_i126 = 0; c1_i126 < 27; c1_i126 = c1_i126 + 1) {
    c1_u[c1_i126] = c1_cv0[c1_i126];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 27));
  for (c1_i127 = 0; c1_i127 < 41; c1_i127 = c1_i127 + 1) {
    c1_b_u[c1_i127] = c1_cv1[c1_i127];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 41));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static real_T c1_eml_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[9], int32_T c1_ix0)
{
  int32_T c1_b_n;
  int32_T c1_i128;
  real_T c1_b_x[9];
  int32_T c1_b_ix0;
  int32_T c1_i129;
  real_T c1_c_x[9];
  c1_b_n = c1_n;
  for (c1_i128 = 0; c1_i128 < 9; c1_i128 = c1_i128 + 1) {
    c1_b_x[c1_i128] = c1_x[c1_i128];
  }

  c1_b_ix0 = c1_ix0;
  if ((real_T)c1_b_n < 1.0) {
    return 0.0;
  } else {
    for (c1_i129 = 0; c1_i129 < 9; c1_i129 = c1_i129 + 1) {
      c1_c_x[c1_i129] = c1_b_x[c1_i129];
    }

    return c1_b_ceval_xnrm2(chartInstance, c1_b_n, c1_c_x, c1_b_ix0, 1);
  }
}

static real_T c1_b_ceval_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[9], int32_T c1_ix0, int32_T
  c1_incx)
{
  return dnrm232(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 9, 1, 0) - 1], &
                 c1_incx);
}

static void c1_eml_xscal(SFc1_twa_parallelInstanceStruct *chartInstance, int32_T
  c1_n, real_T c1_a, real_T c1_x[9], int32_T c1_ix0,
  real_T c1_b_x[9])
{
  int32_T c1_i130;
  int32_T c1_b_n;
  real_T c1_b_a;
  int32_T c1_i131;
  real_T c1_c_x[9];
  int32_T c1_b_ix0;
  int32_T c1_i132;
  int32_T c1_i133;
  real_T c1_d_x[9];
  for (c1_i130 = 0; c1_i130 < 9; c1_i130 = c1_i130 + 1) {
    c1_b_x[c1_i130] = c1_x[c1_i130];
  }

  c1_b_n = c1_n;
  c1_b_a = c1_a;
  for (c1_i131 = 0; c1_i131 < 9; c1_i131 = c1_i131 + 1) {
    c1_c_x[c1_i131] = c1_b_x[c1_i131];
  }

  c1_b_ix0 = c1_ix0;
  for (c1_i132 = 0; c1_i132 < 9; c1_i132 = c1_i132 + 1) {
    c1_b_x[c1_i132] = c1_c_x[c1_i132];
  }

  for (c1_i133 = 0; c1_i133 < 9; c1_i133 = c1_i133 + 1) {
    c1_d_x[c1_i133] = c1_b_x[c1_i133];
  }

  c1_ceval_xscal(chartInstance, c1_b_n, c1_b_a, c1_d_x, c1_b_ix0, 1, c1_b_x);
}

static void c1_ceval_xscal(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[9], int32_T c1_ix0
  , int32_T c1_incx, real_T c1_b_x[9])
{
  int32_T c1_i134;
  for (c1_i134 = 0; c1_i134 < 9; c1_i134 = c1_i134 + 1) {
    c1_b_x[c1_i134] = c1_x[c1_i134];
  }

  dscal32(&c1_n, &c1_a, &c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 9, 1, 0) - 1], &
          c1_incx);
}

static real_T c1_eml_xdotc(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[9], int32_T c1_ix0, real_T c1_y
  [9], int32_T c1_iy0)
{
  int32_T c1_b_n;
  int32_T c1_i135;
  real_T c1_b_x[9];
  int32_T c1_b_ix0;
  int32_T c1_i136;
  real_T c1_b_y[9];
  int32_T c1_b_iy0;
  int32_T c1_c_n;
  int32_T c1_i137;
  real_T c1_c_x[9];
  int32_T c1_c_ix0;
  int32_T c1_i138;
  real_T c1_c_y[9];
  int32_T c1_c_iy0;
  int32_T c1_i139;
  real_T c1_d_x[9];
  int32_T c1_i140;
  real_T c1_d_y[9];
  c1_b_n = c1_n;
  for (c1_i135 = 0; c1_i135 < 9; c1_i135 = c1_i135 + 1) {
    c1_b_x[c1_i135] = c1_x[c1_i135];
  }

  c1_b_ix0 = c1_ix0;
  for (c1_i136 = 0; c1_i136 < 9; c1_i136 = c1_i136 + 1) {
    c1_b_y[c1_i136] = c1_y[c1_i136];
  }

  c1_b_iy0 = c1_iy0;
  c1_c_n = c1_b_n;
  for (c1_i137 = 0; c1_i137 < 9; c1_i137 = c1_i137 + 1) {
    c1_c_x[c1_i137] = c1_b_x[c1_i137];
  }

  c1_c_ix0 = c1_b_ix0;
  for (c1_i138 = 0; c1_i138 < 9; c1_i138 = c1_i138 + 1) {
    c1_c_y[c1_i138] = c1_b_y[c1_i138];
  }

  c1_c_iy0 = c1_b_iy0;
  for (c1_i139 = 0; c1_i139 < 9; c1_i139 = c1_i139 + 1) {
    c1_d_x[c1_i139] = c1_c_x[c1_i139];
  }

  for (c1_i140 = 0; c1_i140 < 9; c1_i140 = c1_i140 + 1) {
    c1_d_y[c1_i140] = c1_c_y[c1_i140];
  }

  return c1_ceval_xdot(chartInstance, c1_c_n, c1_d_x, c1_c_ix0, 1, c1_d_y,
                       c1_c_iy0, 1);
}

static real_T c1_ceval_xdot(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[9], int32_T c1_ix0, int32_T
  c1_incx, real_T c1_y[9], int32_T c1_iy0, int32_T c1_incy)
{
  real_T c1_d;
  c1_d = 0.0;
  if ((real_T)c1_n > 0.0) {
    return ddot32(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 9, 1, 0) - 1], &
                  c1_incx, &c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_iy0), 1, 9, 1, 0) - 1], &c1_incy);
  }

  return c1_d;
}

static void c1_eml_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance, int32_T
  c1_n, real_T c1_a, int32_T c1_ix0, real_T c1_y[9],
  int32_T c1_iy0, real_T c1_b_y[9])
{
  int32_T c1_i141;
  int32_T c1_b_n;
  real_T c1_b_a;
  int32_T c1_b_ix0;
  int32_T c1_i142;
  real_T c1_c_y[9];
  int32_T c1_b_iy0;
  int32_T c1_i143;
  int32_T c1_i144;
  real_T c1_d_y[9];
  for (c1_i141 = 0; c1_i141 < 9; c1_i141 = c1_i141 + 1) {
    c1_b_y[c1_i141] = c1_y[c1_i141];
  }

  c1_b_n = c1_n;
  c1_b_a = c1_a;
  c1_b_ix0 = c1_ix0;
  for (c1_i142 = 0; c1_i142 < 9; c1_i142 = c1_i142 + 1) {
    c1_c_y[c1_i142] = c1_b_y[c1_i142];
  }

  c1_b_iy0 = c1_iy0;
  for (c1_i143 = 0; c1_i143 < 9; c1_i143 = c1_i143 + 1) {
    c1_b_y[c1_i143] = c1_c_y[c1_i143];
  }

  for (c1_i144 = 0; c1_i144 < 9; c1_i144 = c1_i144 + 1) {
    c1_d_y[c1_i144] = c1_b_y[c1_i144];
  }

  c1_ceval_xaxpy(chartInstance, c1_b_n, c1_b_a, c1_b_ix0, 1, c1_d_y, c1_b_iy0, 1,
                 c1_b_y);
}

static void c1_ceval_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, int32_T c1_ix0, int32_T
  c1_incx, real_T c1_y[9], int32_T c1_iy0, int32_T c1_incy, real_T c1_b_y[9])
{
  int32_T c1_i145;
  for (c1_i145 = 0; c1_i145 < 9; c1_i145 = c1_i145 + 1) {
    c1_b_y[c1_i145] = c1_y[c1_i145];
  }

  daxpy32(&c1_n, &c1_a, &c1_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 9, 1, 0) - 1], &
          c1_incx, &c1_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_iy0), 1, 9, 1, 0) - 1], &c1_incy);
}

static real_T c1_b_eml_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[3], int32_T c1_ix0)
{
  int32_T c1_b_n;
  int32_T c1_i146;
  real_T c1_b_x[3];
  int32_T c1_b_ix0;
  int32_T c1_i147;
  real_T c1_c_x[3];
  c1_b_n = c1_n;
  for (c1_i146 = 0; c1_i146 < 3; c1_i146 = c1_i146 + 1) {
    c1_b_x[c1_i146] = c1_x[c1_i146];
  }

  c1_b_ix0 = c1_ix0;
  if ((real_T)c1_b_n < 1.0) {
    return 0.0;
  } else {
    for (c1_i147 = 0; c1_i147 < 3; c1_i147 = c1_i147 + 1) {
      c1_c_x[c1_i147] = c1_b_x[c1_i147];
    }

    return c1_ceval_xnrm2(chartInstance, c1_b_n, c1_c_x, c1_b_ix0, 1);
  }
}

static void c1_b_eml_xscal(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[3], int32_T c1_ix0
  , real_T c1_b_x[3])
{
  int32_T c1_i148;
  int32_T c1_b_n;
  real_T c1_b_a;
  int32_T c1_i149;
  real_T c1_c_x[3];
  int32_T c1_b_ix0;
  int32_T c1_i150;
  int32_T c1_i151;
  real_T c1_d_x[3];
  for (c1_i148 = 0; c1_i148 < 3; c1_i148 = c1_i148 + 1) {
    c1_b_x[c1_i148] = c1_x[c1_i148];
  }

  c1_b_n = c1_n;
  c1_b_a = c1_a;
  for (c1_i149 = 0; c1_i149 < 3; c1_i149 = c1_i149 + 1) {
    c1_c_x[c1_i149] = c1_b_x[c1_i149];
  }

  c1_b_ix0 = c1_ix0;
  for (c1_i150 = 0; c1_i150 < 3; c1_i150 = c1_i150 + 1) {
    c1_b_x[c1_i150] = c1_c_x[c1_i150];
  }

  for (c1_i151 = 0; c1_i151 < 3; c1_i151 = c1_i151 + 1) {
    c1_d_x[c1_i151] = c1_b_x[c1_i151];
  }

  c1_b_ceval_xscal(chartInstance, c1_b_n, c1_b_a, c1_d_x, c1_b_ix0, 1, c1_b_x);
}

static void c1_b_ceval_xscal(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[3], int32_T
  c1_ix0, int32_T c1_incx, real_T c1_b_x[3])
{
  int32_T c1_i152;
  for (c1_i152 = 0; c1_i152 < 3; c1_i152 = c1_i152 + 1) {
    c1_b_x[c1_i152] = c1_x[c1_i152];
  }

  dscal32(&c1_n, &c1_a, &c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 3, 1, 0) - 1], &
          c1_incx);
}

static void c1_b_eml_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[9], int32_T c1_ix0
  , real_T c1_y[3], int32_T c1_iy0, real_T c1_b_y[3])
{
  int32_T c1_i153;
  int32_T c1_b_n;
  real_T c1_b_a;
  int32_T c1_i154;
  real_T c1_b_x[9];
  int32_T c1_b_ix0;
  int32_T c1_i155;
  real_T c1_c_y[3];
  int32_T c1_b_iy0;
  int32_T c1_i156;
  int32_T c1_i157;
  real_T c1_c_x[9];
  int32_T c1_i158;
  real_T c1_d_y[3];
  for (c1_i153 = 0; c1_i153 < 3; c1_i153 = c1_i153 + 1) {
    c1_b_y[c1_i153] = c1_y[c1_i153];
  }

  c1_b_n = c1_n;
  c1_b_a = c1_a;
  for (c1_i154 = 0; c1_i154 < 9; c1_i154 = c1_i154 + 1) {
    c1_b_x[c1_i154] = c1_x[c1_i154];
  }

  c1_b_ix0 = c1_ix0;
  for (c1_i155 = 0; c1_i155 < 3; c1_i155 = c1_i155 + 1) {
    c1_c_y[c1_i155] = c1_b_y[c1_i155];
  }

  c1_b_iy0 = c1_iy0;
  for (c1_i156 = 0; c1_i156 < 3; c1_i156 = c1_i156 + 1) {
    c1_b_y[c1_i156] = c1_c_y[c1_i156];
  }

  for (c1_i157 = 0; c1_i157 < 9; c1_i157 = c1_i157 + 1) {
    c1_c_x[c1_i157] = c1_b_x[c1_i157];
  }

  for (c1_i158 = 0; c1_i158 < 3; c1_i158 = c1_i158 + 1) {
    c1_d_y[c1_i158] = c1_b_y[c1_i158];
  }

  c1_b_ceval_xaxpy(chartInstance, c1_b_n, c1_b_a, c1_c_x, c1_b_ix0, 1, c1_d_y,
                   c1_b_iy0, 1, c1_b_y);
}

static void c1_b_ceval_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[9], int32_T
  c1_ix0, int32_T c1_incx, real_T c1_y[3], int32_T c1_iy0, int32_T c1_incy,
  real_T c1_b_y[3])
{
  int32_T c1_i159;
  for (c1_i159 = 0; c1_i159 < 3; c1_i159 = c1_i159 + 1) {
    c1_b_y[c1_i159] = c1_y[c1_i159];
  }

  daxpy32(&c1_n, &c1_a, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 9, 1, 0) - 1], &
          c1_incx, &c1_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_iy0), 1, 3, 1, 0) - 1], &c1_incy);
}

static void c1_c_eml_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[3], int32_T c1_ix0
  , real_T c1_y[9], int32_T c1_iy0, real_T c1_b_y[9])
{
  int32_T c1_i160;
  int32_T c1_b_n;
  real_T c1_b_a;
  int32_T c1_i161;
  real_T c1_b_x[3];
  int32_T c1_b_ix0;
  int32_T c1_i162;
  real_T c1_c_y[9];
  int32_T c1_b_iy0;
  int32_T c1_i163;
  int32_T c1_i164;
  real_T c1_c_x[3];
  int32_T c1_i165;
  real_T c1_d_y[9];
  for (c1_i160 = 0; c1_i160 < 9; c1_i160 = c1_i160 + 1) {
    c1_b_y[c1_i160] = c1_y[c1_i160];
  }

  c1_b_n = c1_n;
  c1_b_a = c1_a;
  for (c1_i161 = 0; c1_i161 < 3; c1_i161 = c1_i161 + 1) {
    c1_b_x[c1_i161] = c1_x[c1_i161];
  }

  c1_b_ix0 = c1_ix0;
  for (c1_i162 = 0; c1_i162 < 9; c1_i162 = c1_i162 + 1) {
    c1_c_y[c1_i162] = c1_b_y[c1_i162];
  }

  c1_b_iy0 = c1_iy0;
  for (c1_i163 = 0; c1_i163 < 9; c1_i163 = c1_i163 + 1) {
    c1_b_y[c1_i163] = c1_c_y[c1_i163];
  }

  for (c1_i164 = 0; c1_i164 < 3; c1_i164 = c1_i164 + 1) {
    c1_c_x[c1_i164] = c1_b_x[c1_i164];
  }

  for (c1_i165 = 0; c1_i165 < 9; c1_i165 = c1_i165 + 1) {
    c1_d_y[c1_i165] = c1_b_y[c1_i165];
  }

  c1_c_ceval_xaxpy(chartInstance, c1_b_n, c1_b_a, c1_c_x, c1_b_ix0, 1, c1_d_y,
                   c1_b_iy0, 1, c1_b_y);
}

static void c1_c_ceval_xaxpy(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_a, real_T c1_x[3], int32_T
  c1_ix0, int32_T c1_incx, real_T c1_y[9], int32_T c1_iy0, int32_T c1_incy,
  real_T c1_b_y[9])
{
  int32_T c1_i166;
  for (c1_i166 = 0; c1_i166 < 9; c1_i166 = c1_i166 + 1) {
    c1_b_y[c1_i166] = c1_y[c1_i166];
  }

  daxpy32(&c1_n, &c1_a, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 3, 1, 0) - 1], &
          c1_incx, &c1_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_iy0), 1, 9, 1, 0) - 1], &c1_incy);
}

static real_T c1_power(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_a, real_T c1_b)
{
  real_T c1_ak;
  real_T c1_bk;
  real_T c1_x;
  real_T c1_b_x;
  c1_b_eml_scalar_eg(chartInstance);
  c1_ak = c1_a;
  c1_bk = c1_b;
  if (c1_ak < 0.0) {
    c1_x = c1_bk;
    c1_b_x = c1_x;
    c1_b_x = muDoubleScalarFloor(c1_b_x);
    if (c1_b_x != c1_bk) {
      c1_b_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c1_ak, c1_bk);
}

static void c1_b_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c1_i167;
  static char_T c1_cv2[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[32];
  const mxArray *c1_y = NULL;
  int32_T c1_i168;
  static char_T c1_cv3[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c1_b_u[102];
  const mxArray *c1_b_y = NULL;
  for (c1_i167 = 0; c1_i167 < 32; c1_i167 = c1_i167 + 1) {
    c1_u[c1_i167] = c1_cv2[c1_i167];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c1_i168 = 0; c1_i168 < 102; c1_i168 = c1_i168 + 1) {
    c1_b_u[c1_i168] = c1_cv3[c1_i168];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static void c1_eps(SFc1_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c1_max(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                     c1_varargin_1, real_T c1_varargin_2)
{
  real_T c1_x;
  real_T c1_y;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_xk;
  real_T c1_yk;
  real_T c1_c_x;
  real_T c1_c_y;
  c1_x = c1_varargin_1;
  c1_y = c1_varargin_2;
  c1_b_x = c1_x;
  c1_b_y = c1_y;
  c1_b_eml_scalar_eg(chartInstance);
  c1_xk = c1_b_x;
  c1_yk = c1_b_y;
  c1_c_x = c1_xk;
  c1_c_y = c1_yk;
  c1_b_eml_scalar_eg(chartInstance);
  return muDoubleScalarMax(c1_c_x, c1_c_y);
}

static void c1_c_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c1_i169;
  static char_T c1_cv4[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'v', 'd',
    ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e'
    , 'n', 'c', 'e' };

  char_T c1_u[24];
  const mxArray *c1_y = NULL;
  int32_T c1_i170;
  static char_T c1_cv5[21] = { 'S', 'V', 'D', ' ', 'f', 'a', 'i', 'l', 's', ' ',
    't', 'o', ' ', 'c', 'o', 'n', 'v', 'e', 'r', 'g', 'e'
  };

  char_T c1_b_u[21];
  const mxArray *c1_b_y = NULL;
  for (c1_i169 = 0; c1_i169 < 24; c1_i169 = c1_i169 + 1) {
    c1_u[c1_i169] = c1_cv4[c1_i169];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 24));
  for (c1_i170 = 0; c1_i170 < 21; c1_i170 = c1_i170 + 1) {
    c1_b_u[c1_i170] = c1_cv5[c1_i170];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 21));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static real_T c1_b_max(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_varargin_1[5])
{
  int32_T c1_i171;
  real_T c1_x[5];
  int32_T c1_i172;
  real_T c1_b_x[5];
  real_T c1_mtmp;
  int32_T c1_itmp;
  int32_T c1_ix;
  real_T c1_c_x;
  boolean_T c1_b;
  boolean_T c1_searchingForNonNaN;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_a;
  real_T c1_d_x;
  boolean_T c1_b_b;
  int32_T c1_b_a;
  int32_T c1_i173;
  int32_T c1_c_k;
  int32_T c1_c_a;
  real_T c1_b_mtmp;
  for (c1_i171 = 0; c1_i171 < 5; c1_i171 = c1_i171 + 1) {
    c1_x[c1_i171] = c1_varargin_1[c1_i171];
  }

  for (c1_i172 = 0; c1_i172 < 5; c1_i172 = c1_i172 + 1) {
    c1_b_x[c1_i172] = c1_x[c1_i172];
  }

  c1_mtmp = c1_b_x[0];
  c1_itmp = 1;
  c1_ix = 1;
  c1_c_x = c1_mtmp;
  c1_b = muDoubleScalarIsNaN(c1_c_x);
  if (c1_b) {
    c1_searchingForNonNaN = TRUE;
    c1_k = 2;
   label_1:
    ;
    if (c1_k < 6) {
      c1_b_k = c1_k;
      c1_a = c1_ix;
      c1_ix = c1_a + 1;
      c1_d_x = c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 5, 1, 0) - 1];
      c1_b_b = muDoubleScalarIsNaN(c1_d_x);
      if (!c1_b_b) {
        c1_mtmp = c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 5, 1, 0) - 1];
        c1_itmp = c1_b_k;
        c1_searchingForNonNaN = FALSE;
      } else {
        c1_k = c1_k + 1;
        goto label_1;
      }
    }

    if (c1_searchingForNonNaN) {
      goto label_2;
    }
  }

  c1_b_a = c1_itmp;
  c1_i173 = c1_b_a + 1;
  for (c1_c_k = c1_i173; c1_c_k < 6; c1_c_k = c1_c_k + 1) {
    c1_c_a = c1_ix;
    c1_ix = c1_c_a + 1;
    if (c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_ix), 1, 5, 1, 0) - 1] > c1_mtmp) {
      c1_mtmp = c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 5, 1, 0) - 1];
    }
  }

 label_2:
  ;
  c1_b_mtmp = c1_mtmp;
  return c1_b_mtmp;
}

static real_T c1_sqrt(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                      c1_x)
{
  real_T c1_b_x;
  real_T c1_c_x;
  c1_b_x = c1_x;
  if (c1_b_x < 0.0) {
    c1_d_eml_error(chartInstance);
  }

  c1_c_x = c1_b_x;
  c1_b_x = c1_c_x;
  return muDoubleScalarSqrt(c1_b_x);
}

static void c1_d_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c1_i174;
  static char_T c1_cv6[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[31];
  const mxArray *c1_y = NULL;
  int32_T c1_i175;
  static char_T c1_cv7[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c1_b_u[77];
  const mxArray *c1_b_y = NULL;
  for (c1_i174 = 0; c1_i174 < 31; c1_i174 = c1_i174 + 1) {
    c1_u[c1_i174] = c1_cv6[c1_i174];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c1_i175 = 0; c1_i175 < 77; c1_i175 = c1_i175 + 1) {
    c1_b_u[c1_i175] = c1_cv7[c1_i175];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static void c1_eml_xrotg(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_a, real_T c1_b, real_T *c1_b_a, real_T *c1_b_b,
  real_T *c1_c, real_T *c1_s)
{
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_d_b;
  real_T c1_d_a;
  real_T c1_b_c;
  real_T c1_b_s;
  *c1_b_b = c1_b;
  *c1_b_a = c1_a;
  c1_c_a = *c1_b_a;
  c1_c_b = *c1_b_b;
  c1_d_b = c1_c_b;
  c1_d_a = c1_c_a;
  c1_b_c = 0.0;
  c1_b_s = 0.0;
  drotg32(&c1_d_a, &c1_d_b, &c1_b_c, &c1_b_s);
  *c1_b_a = c1_d_a;
  *c1_b_b = c1_d_b;
  *c1_c = c1_b_c;
  *c1_s = c1_b_s;
}

static real_T c1_atan2(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_y, real_T c1_x)
{
  real_T c1_b_y;
  real_T c1_b_x;
  c1_b_eml_scalar_eg(chartInstance);
  c1_b_y = c1_y;
  c1_b_x = c1_x;
  return muDoubleScalarAtan2(c1_b_y, c1_b_x);
}

static void c1_expm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T c1_A
                    [9], real_T c1_F[9])
{
  int32_T c1_i176;
  real_T c1_x[9];
  int32_T c1_i177;
  real_T c1_b_x[9];
  real_T c1_normA;
  real_T c1_j;
  real_T c1_b_j;
  real_T c1_s;
  real_T c1_i;
  real_T c1_b_i;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_y;
  real_T c1_e_x;
  boolean_T c1_b;
  real_T c1_c_i;
  real_T c1_d_i;
  static real_T c1_dv20[5] = { 1.4955852179582920E-002, 2.5393983300632300E-001,
    9.5041789961629319E-001, 2.0978479612570680E+000,
    5.3719203511481517E+000 };

  int32_T c1_i178;
  real_T c1_b_A[9];
  static real_T c1_dv21[5] = { 3.0, 5.0, 7.0, 9.0, 13.0 };

  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  boolean_T c1_b_b;
  boolean_T c1_b2;
  real_T c1_k_x;
  boolean_T c1_c_b;
  boolean_T c1_b3;
  boolean_T c1_d_b;
  int32_T c1_eint;
  real_T c1_fdbl;
  int32_T c1_b_eint;
  real_T c1_b_fdbl;
  int32_T c1_c_eint;
  real_T c1_f;
  real_T c1_e;
  real_T c1_d5;
  real_T c1_d6;
  real_T c1_t;
  real_T c1_b_s;
  real_T c1_b_t;
  real_T c1_c_s;
  real_T c1_a;
  real_T c1_b_a;
  real_T c1_b_y;
  int32_T c1_i179;
  real_T c1_l_x[9];
  real_T c1_c_y;
  int32_T c1_i180;
  real_T c1_m_x[9];
  real_T c1_d_y;
  int32_T c1_i181;
  int32_T c1_i182;
  real_T c1_c_A[9];
  real_T c1_c_j;
  int32_T c1_i183;
  real_T c1_c_a[9];
  int32_T c1_i184;
  real_T c1_e_b[9];
  int32_T c1_i185;
  real_T c1_d_a[9];
  int32_T c1_i186;
  real_T c1_f_b[9];
  int32_T c1_i187;
  real_T c1_dv22[9];
  for (c1_i176 = 0; c1_i176 < 9; c1_i176 = c1_i176 + 1) {
    c1_x[c1_i176] = c1_A[c1_i176];
  }

  for (c1_i177 = 0; c1_i177 < 9; c1_i177 = c1_i177 + 1) {
    c1_b_x[c1_i177] = c1_x[c1_i177];
  }

  c1_normA = 0.0;
  c1_j = 1.0;
 label_1:
  ;
  if (c1_j <= 3.0) {
    c1_b_j = c1_j;
    c1_s = 0.0;
    for (c1_i = 1.0; c1_i <= 3.0; c1_i = c1_i + 1.0) {
      c1_b_i = c1_i;
      c1_c_x = c1_b_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_b_i), 1, 3, 1, 0) - 1) + 3 * (
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_j),
        1, 3, 2, 0) - 1)];
      c1_d_x = c1_c_x;
      c1_y = muDoubleScalarAbs(c1_d_x);
      c1_s = c1_s + c1_y;
    }

    c1_e_x = c1_s;
    c1_b = muDoubleScalarIsNaN(c1_e_x);
    if (c1_b) {
      c1_normA = rtNaN;
    } else {
      if (c1_s > c1_normA) {
        c1_normA = c1_s;
      }

      c1_j = c1_j + 1.0;
      goto label_1;
    }
  }

  if (c1_normA <= 5.3719203511481517E+000) {
    c1_c_i = 1.0;
   label_2:
    ;
    if (c1_c_i <= 5.0) {
      c1_d_i = c1_c_i;
      if (c1_normA <= c1_dv20[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", c1_d_i), 1, 5, 1, 0) - 1]) {
        for (c1_i178 = 0; c1_i178 < 9; c1_i178 = c1_i178 + 1) {
          c1_b_A[c1_i178] = c1_A[c1_i178];
        }

        c1_PadeApproximantOfDegree(chartInstance, c1_b_A,
          c1_dv21[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c1_d_i), 1
          , 5, 1, 0) - 1], c1_F);
      } else {
        c1_c_i = c1_c_i + 1.0;
        goto label_2;
      }
    }
  } else {
    c1_f_x = c1_normA / 5.3719203511481517E+000;
    c1_g_x = c1_f_x;
    c1_h_x = c1_g_x;
    c1_i_x = c1_h_x;
    c1_j_x = c1_i_x;
    c1_b_b = muDoubleScalarIsInf(c1_j_x);
    c1_b2 = !c1_b_b;
    c1_k_x = c1_i_x;
    c1_c_b = muDoubleScalarIsNaN(c1_k_x);
    c1_b3 = !c1_c_b;
    c1_d_b = (c1_b2 && c1_b3);
    if (c1_d_b) {
      c1_fdbl = frexp(c1_h_x, &c1_eint);
      c1_b_eint = c1_eint;
      c1_b_fdbl = c1_fdbl;
      c1_c_eint = c1_b_eint;
      c1_f = c1_b_fdbl;
      c1_e = (real_T)c1_c_eint;
    } else {
      c1_f = c1_h_x;
      c1_e = 0.0;
    }

    c1_d5 = c1_f;
    c1_d6 = c1_e;
    c1_t = c1_d5;
    c1_b_s = c1_d6;
    c1_b_t = c1_t;
    c1_c_s = c1_b_s;
    if (c1_b_t == 0.5) {
      c1_c_s = c1_c_s - 1.0;
    }

    c1_a = c1_c_s;
    c1_b_a = c1_a;
    c1_b_y = c1_power(chartInstance, 2.0, c1_b_a);
    for (c1_i179 = 0; c1_i179 < 9; c1_i179 = c1_i179 + 1) {
      c1_l_x[c1_i179] = c1_A[c1_i179];
    }

    c1_c_y = c1_b_y;
    for (c1_i180 = 0; c1_i180 < 9; c1_i180 = c1_i180 + 1) {
      c1_m_x[c1_i180] = c1_l_x[c1_i180];
    }

    c1_d_y = c1_c_y;
    for (c1_i181 = 0; c1_i181 < 9; c1_i181 = c1_i181 + 1) {
      c1_A[c1_i181] = c1_m_x[c1_i181] / c1_d_y;
    }

    for (c1_i182 = 0; c1_i182 < 9; c1_i182 = c1_i182 + 1) {
      c1_c_A[c1_i182] = c1_A[c1_i182];
    }

    c1_PadeApproximantOfDegree(chartInstance, c1_c_A, 13.0, c1_F);
    for (c1_c_j = 1.0; c1_c_j <= c1_c_s; c1_c_j = c1_c_j + 1.0) {
      for (c1_i183 = 0; c1_i183 < 9; c1_i183 = c1_i183 + 1) {
        c1_c_a[c1_i183] = c1_F[c1_i183];
      }

      for (c1_i184 = 0; c1_i184 < 9; c1_i184 = c1_i184 + 1) {
        c1_e_b[c1_i184] = c1_F[c1_i184];
      }

      c1_eml_scalar_eg(chartInstance);
      c1_eml_scalar_eg(chartInstance);
      for (c1_i185 = 0; c1_i185 < 9; c1_i185 = c1_i185 + 1) {
        c1_d_a[c1_i185] = c1_c_a[c1_i185];
      }

      for (c1_i186 = 0; c1_i186 < 9; c1_i186 = c1_i186 + 1) {
        c1_f_b[c1_i186] = c1_e_b[c1_i186];
      }

      for (c1_i187 = 0; c1_i187 < 9; c1_i187 = c1_i187 + 1) {
        c1_dv22[c1_i187] = 0.0;
      }

      c1_eml_xgemm(chartInstance, c1_d_a, c1_f_b, c1_dv22, c1_F);
    }
  }
}

static void c1_PadeApproximantOfDegree(SFc1_twa_parallelInstanceStruct
  *chartInstance, real_T c1_A[9], real_T c1_m, real_T c1_F[9])
{
  int32_T c1_i188;
  real_T c1_a[9];
  int32_T c1_i189;
  real_T c1_b[9];
  int32_T c1_i190;
  real_T c1_b_a[9];
  int32_T c1_i191;
  real_T c1_b_b[9];
  int32_T c1_i192;
  real_T c1_dv23[9];
  real_T c1_A2[9];
  int32_T c1_i193;
  real_T c1_U[9];
  real_T c1_k;
  real_T c1_b_k;
  int32_T c1_i194;
  real_T c1_c_a[9];
  int32_T c1_i195;
  real_T c1_c_b[9];
  int32_T c1_i196;
  real_T c1_d_a[9];
  int32_T c1_i197;
  real_T c1_d_b[9];
  int32_T c1_i198;
  real_T c1_dv24[9];
  int32_T c1_i199;
  real_T c1_e_b[9];
  int32_T c1_i200;
  real_T c1_V[9];
  real_T c1_d;
  int32_T c1_i201;
  real_T c1_e_a[9];
  int32_T c1_i202;
  real_T c1_f_b[9];
  int32_T c1_i203;
  real_T c1_f_a[9];
  int32_T c1_i204;
  real_T c1_g_b[9];
  int32_T c1_i205;
  real_T c1_dv25[9];
  real_T c1_A3[9];
  int32_T c1_i206;
  real_T c1_h_b[9];
  int32_T c1_i207;
  real_T c1_y[9];
  int32_T c1_i208;
  real_T c1_c_k;
  int32_T c1_i209;
  real_T c1_g_a[9];
  int32_T c1_i210;
  real_T c1_i_b[9];
  int32_T c1_i211;
  real_T c1_h_a[9];
  int32_T c1_i212;
  real_T c1_j_b[9];
  int32_T c1_i213;
  real_T c1_dv26[9];
  int32_T c1_i214;
  real_T c1_k_b[9];
  int32_T c1_i215;
  real_T c1_b_y[9];
  int32_T c1_i216;
  real_T c1_l_b[9];
  int32_T c1_i217;
  real_T c1_c_y[9];
  int32_T c1_i218;
  int32_T c1_i219;
  real_T c1_i_a[9];
  int32_T c1_i220;
  real_T c1_m_b[9];
  int32_T c1_i221;
  real_T c1_j_a[9];
  int32_T c1_i222;
  real_T c1_n_b[9];
  int32_T c1_i223;
  real_T c1_dv27[9];
  real_T c1_A4[9];
  int32_T c1_i224;
  real_T c1_o_b[9];
  int32_T c1_i225;
  real_T c1_d_y[9];
  int32_T c1_i226;
  real_T c1_p_b[9];
  int32_T c1_i227;
  real_T c1_e_y[9];
  int32_T c1_i228;
  real_T c1_d_k;
  int32_T c1_i229;
  real_T c1_k_a[9];
  int32_T c1_i230;
  real_T c1_q_b[9];
  int32_T c1_i231;
  real_T c1_l_a[9];
  int32_T c1_i232;
  real_T c1_r_b[9];
  int32_T c1_i233;
  real_T c1_dv28[9];
  int32_T c1_i234;
  real_T c1_s_b[9];
  int32_T c1_i235;
  real_T c1_f_y[9];
  int32_T c1_i236;
  real_T c1_t_b[9];
  int32_T c1_i237;
  real_T c1_g_y[9];
  int32_T c1_i238;
  real_T c1_u_b[9];
  int32_T c1_i239;
  real_T c1_h_y[9];
  int32_T c1_i240;
  int32_T c1_i241;
  real_T c1_m_a[9];
  int32_T c1_i242;
  real_T c1_v_b[9];
  int32_T c1_i243;
  real_T c1_n_a[9];
  int32_T c1_i244;
  real_T c1_w_b[9];
  int32_T c1_i245;
  real_T c1_dv29[9];
  int32_T c1_i246;
  real_T c1_x_b[9];
  int32_T c1_i247;
  real_T c1_i_y[9];
  int32_T c1_i248;
  real_T c1_y_b[9];
  int32_T c1_i249;
  real_T c1_j_y[9];
  int32_T c1_i250;
  real_T c1_ab_b[9];
  int32_T c1_i251;
  real_T c1_k_y[9];
  int32_T c1_i252;
  real_T c1_e_k;
  int32_T c1_i253;
  real_T c1_o_a[9];
  int32_T c1_i254;
  real_T c1_bb_b[9];
  int32_T c1_i255;
  real_T c1_p_a[9];
  int32_T c1_i256;
  real_T c1_cb_b[9];
  int32_T c1_i257;
  real_T c1_dv30[9];
  int32_T c1_i258;
  real_T c1_db_b[9];
  int32_T c1_i259;
  real_T c1_l_y[9];
  int32_T c1_i260;
  real_T c1_eb_b[9];
  int32_T c1_i261;
  real_T c1_m_y[9];
  int32_T c1_i262;
  real_T c1_fb_b[9];
  int32_T c1_i263;
  real_T c1_n_y[9];
  int32_T c1_i264;
  real_T c1_gb_b[9];
  int32_T c1_i265;
  real_T c1_o_y[9];
  int32_T c1_i266;
  int32_T c1_i267;
  real_T c1_hb_b[9];
  int32_T c1_i268;
  real_T c1_p_y[9];
  int32_T c1_i269;
  real_T c1_ib_b[9];
  int32_T c1_i270;
  real_T c1_q_y[9];
  int32_T c1_i271;
  real_T c1_jb_b[9];
  int32_T c1_i272;
  real_T c1_r_y[9];
  int32_T c1_i273;
  real_T c1_f_k;
  int32_T c1_i274;
  real_T c1_kb_b[9];
  int32_T c1_i275;
  real_T c1_s_y[9];
  int32_T c1_i276;
  real_T c1_lb_b[9];
  int32_T c1_i277;
  real_T c1_t_y[9];
  int32_T c1_i278;
  real_T c1_q_a[9];
  int32_T c1_i279;
  real_T c1_mb_b[9];
  int32_T c1_i280;
  real_T c1_r_a[9];
  int32_T c1_i281;
  real_T c1_nb_b[9];
  int32_T c1_i282;
  real_T c1_dv31[9];
  real_T c1_u_y[9];
  int32_T c1_i283;
  real_T c1_s_a[9];
  int32_T c1_i284;
  real_T c1_ob_b[9];
  int32_T c1_i285;
  real_T c1_t_a[9];
  int32_T c1_i286;
  real_T c1_pb_b[9];
  int32_T c1_i287;
  real_T c1_dv32[9];
  int32_T c1_i288;
  real_T c1_qb_b[9];
  int32_T c1_i289;
  real_T c1_v_y[9];
  int32_T c1_i290;
  real_T c1_rb_b[9];
  int32_T c1_i291;
  real_T c1_w_y[9];
  int32_T c1_i292;
  real_T c1_sb_b[9];
  int32_T c1_i293;
  real_T c1_x_y[9];
  int32_T c1_i294;
  real_T c1_u_a[9];
  int32_T c1_i295;
  real_T c1_tb_b[9];
  int32_T c1_i296;
  real_T c1_v_a[9];
  int32_T c1_i297;
  real_T c1_ub_b[9];
  int32_T c1_i298;
  real_T c1_dv33[9];
  real_T c1_y_y[9];
  int32_T c1_i299;
  real_T c1_vb_b[9];
  int32_T c1_i300;
  real_T c1_ab_y[9];
  int32_T c1_i301;
  real_T c1_wb_b[9];
  int32_T c1_i302;
  real_T c1_bb_y[9];
  int32_T c1_i303;
  real_T c1_xb_b[9];
  int32_T c1_i304;
  real_T c1_cb_y[9];
  int32_T c1_i305;
  real_T c1_g_k;
  real_T c1_h_k;
  real_T c1_uk;
  int32_T c1_i306;
  real_T c1_b_U[9];
  int32_T c1_i307;
  real_T c1_b_V[9];
  for (c1_i188 = 0; c1_i188 < 9; c1_i188 = c1_i188 + 1) {
    c1_a[c1_i188] = c1_A[c1_i188];
  }

  for (c1_i189 = 0; c1_i189 < 9; c1_i189 = c1_i189 + 1) {
    c1_b[c1_i189] = c1_A[c1_i189];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i190 = 0; c1_i190 < 9; c1_i190 = c1_i190 + 1) {
    c1_b_a[c1_i190] = c1_a[c1_i190];
  }

  for (c1_i191 = 0; c1_i191 < 9; c1_i191 = c1_i191 + 1) {
    c1_b_b[c1_i191] = c1_b[c1_i191];
  }

  for (c1_i192 = 0; c1_i192 < 9; c1_i192 = c1_i192 + 1) {
    c1_dv23[c1_i192] = 0.0;
  }

  c1_eml_xgemm(chartInstance, c1_b_a, c1_b_b, c1_dv23, c1_A2);
  if (c1_m == 3.0) {
    for (c1_i193 = 0; c1_i193 < 9; c1_i193 = c1_i193 + 1) {
      c1_U[c1_i193] = c1_A2[c1_i193];
    }

    for (c1_k = 1.0; c1_k <= 3.0; c1_k = c1_k + 1.0) {
      c1_b_k = c1_k;
      c1_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c1_b_k), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] = c1_U
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", c1_b_k), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] +
        60.0;
    }

    for (c1_i194 = 0; c1_i194 < 9; c1_i194 = c1_i194 + 1) {
      c1_c_a[c1_i194] = c1_A[c1_i194];
    }

    for (c1_i195 = 0; c1_i195 < 9; c1_i195 = c1_i195 + 1) {
      c1_c_b[c1_i195] = c1_U[c1_i195];
    }

    c1_eml_scalar_eg(chartInstance);
    c1_eml_scalar_eg(chartInstance);
    for (c1_i196 = 0; c1_i196 < 9; c1_i196 = c1_i196 + 1) {
      c1_d_a[c1_i196] = c1_c_a[c1_i196];
    }

    for (c1_i197 = 0; c1_i197 < 9; c1_i197 = c1_i197 + 1) {
      c1_d_b[c1_i197] = c1_c_b[c1_i197];
    }

    for (c1_i198 = 0; c1_i198 < 9; c1_i198 = c1_i198 + 1) {
      c1_dv24[c1_i198] = 0.0;
    }

    c1_eml_xgemm(chartInstance, c1_d_a, c1_d_b, c1_dv24, c1_U);
    for (c1_i199 = 0; c1_i199 < 9; c1_i199 = c1_i199 + 1) {
      c1_e_b[c1_i199] = c1_A2[c1_i199];
    }

    for (c1_i200 = 0; c1_i200 < 9; c1_i200 = c1_i200 + 1) {
      c1_V[c1_i200] = 12.0 * c1_e_b[c1_i200];
    }

    c1_d = 120.0;
  } else {
    for (c1_i201 = 0; c1_i201 < 9; c1_i201 = c1_i201 + 1) {
      c1_e_a[c1_i201] = c1_A2[c1_i201];
    }

    for (c1_i202 = 0; c1_i202 < 9; c1_i202 = c1_i202 + 1) {
      c1_f_b[c1_i202] = c1_A2[c1_i202];
    }

    c1_eml_scalar_eg(chartInstance);
    c1_eml_scalar_eg(chartInstance);
    for (c1_i203 = 0; c1_i203 < 9; c1_i203 = c1_i203 + 1) {
      c1_f_a[c1_i203] = c1_e_a[c1_i203];
    }

    for (c1_i204 = 0; c1_i204 < 9; c1_i204 = c1_i204 + 1) {
      c1_g_b[c1_i204] = c1_f_b[c1_i204];
    }

    for (c1_i205 = 0; c1_i205 < 9; c1_i205 = c1_i205 + 1) {
      c1_dv25[c1_i205] = 0.0;
    }

    c1_eml_xgemm(chartInstance, c1_f_a, c1_g_b, c1_dv25, c1_A3);
    if (c1_m == 5.0) {
      for (c1_i206 = 0; c1_i206 < 9; c1_i206 = c1_i206 + 1) {
        c1_h_b[c1_i206] = c1_A2[c1_i206];
      }

      for (c1_i207 = 0; c1_i207 < 9; c1_i207 = c1_i207 + 1) {
        c1_y[c1_i207] = 420.0 * c1_h_b[c1_i207];
      }

      for (c1_i208 = 0; c1_i208 < 9; c1_i208 = c1_i208 + 1) {
        c1_U[c1_i208] = c1_A3[c1_i208] + c1_y[c1_i208];
      }

      for (c1_c_k = 1.0; c1_c_k <= 3.0; c1_c_k = c1_c_k + 1.0) {
        c1_b_k = c1_c_k;
        c1_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c1_b_k), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] = c1_U
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", c1_b_k), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] +
          15120.0;
      }

      for (c1_i209 = 0; c1_i209 < 9; c1_i209 = c1_i209 + 1) {
        c1_g_a[c1_i209] = c1_A[c1_i209];
      }

      for (c1_i210 = 0; c1_i210 < 9; c1_i210 = c1_i210 + 1) {
        c1_i_b[c1_i210] = c1_U[c1_i210];
      }

      c1_eml_scalar_eg(chartInstance);
      c1_eml_scalar_eg(chartInstance);
      for (c1_i211 = 0; c1_i211 < 9; c1_i211 = c1_i211 + 1) {
        c1_h_a[c1_i211] = c1_g_a[c1_i211];
      }

      for (c1_i212 = 0; c1_i212 < 9; c1_i212 = c1_i212 + 1) {
        c1_j_b[c1_i212] = c1_i_b[c1_i212];
      }

      for (c1_i213 = 0; c1_i213 < 9; c1_i213 = c1_i213 + 1) {
        c1_dv26[c1_i213] = 0.0;
      }

      c1_eml_xgemm(chartInstance, c1_h_a, c1_j_b, c1_dv26, c1_U);
      for (c1_i214 = 0; c1_i214 < 9; c1_i214 = c1_i214 + 1) {
        c1_k_b[c1_i214] = c1_A3[c1_i214];
      }

      for (c1_i215 = 0; c1_i215 < 9; c1_i215 = c1_i215 + 1) {
        c1_b_y[c1_i215] = 30.0 * c1_k_b[c1_i215];
      }

      for (c1_i216 = 0; c1_i216 < 9; c1_i216 = c1_i216 + 1) {
        c1_l_b[c1_i216] = c1_A2[c1_i216];
      }

      for (c1_i217 = 0; c1_i217 < 9; c1_i217 = c1_i217 + 1) {
        c1_c_y[c1_i217] = 3360.0 * c1_l_b[c1_i217];
      }

      for (c1_i218 = 0; c1_i218 < 9; c1_i218 = c1_i218 + 1) {
        c1_V[c1_i218] = c1_b_y[c1_i218] + c1_c_y[c1_i218];
      }

      c1_d = 30240.0;
    } else {
      for (c1_i219 = 0; c1_i219 < 9; c1_i219 = c1_i219 + 1) {
        c1_i_a[c1_i219] = c1_A3[c1_i219];
      }

      for (c1_i220 = 0; c1_i220 < 9; c1_i220 = c1_i220 + 1) {
        c1_m_b[c1_i220] = c1_A2[c1_i220];
      }

      c1_eml_scalar_eg(chartInstance);
      c1_eml_scalar_eg(chartInstance);
      for (c1_i221 = 0; c1_i221 < 9; c1_i221 = c1_i221 + 1) {
        c1_j_a[c1_i221] = c1_i_a[c1_i221];
      }

      for (c1_i222 = 0; c1_i222 < 9; c1_i222 = c1_i222 + 1) {
        c1_n_b[c1_i222] = c1_m_b[c1_i222];
      }

      for (c1_i223 = 0; c1_i223 < 9; c1_i223 = c1_i223 + 1) {
        c1_dv27[c1_i223] = 0.0;
      }

      c1_eml_xgemm(chartInstance, c1_j_a, c1_n_b, c1_dv27, c1_A4);
      if (c1_m == 7.0) {
        for (c1_i224 = 0; c1_i224 < 9; c1_i224 = c1_i224 + 1) {
          c1_o_b[c1_i224] = c1_A3[c1_i224];
        }

        for (c1_i225 = 0; c1_i225 < 9; c1_i225 = c1_i225 + 1) {
          c1_d_y[c1_i225] = 1512.0 * c1_o_b[c1_i225];
        }

        for (c1_i226 = 0; c1_i226 < 9; c1_i226 = c1_i226 + 1) {
          c1_p_b[c1_i226] = c1_A2[c1_i226];
        }

        for (c1_i227 = 0; c1_i227 < 9; c1_i227 = c1_i227 + 1) {
          c1_e_y[c1_i227] = 277200.0 * c1_p_b[c1_i227];
        }

        for (c1_i228 = 0; c1_i228 < 9; c1_i228 = c1_i228 + 1) {
          c1_U[c1_i228] = (c1_A4[c1_i228] + c1_d_y[c1_i228]) + c1_e_y[c1_i228];
        }

        for (c1_d_k = 1.0; c1_d_k <= 3.0; c1_d_k = c1_d_k + 1.0) {
          c1_b_k = c1_d_k;
          c1_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c1_b_k), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] =
            c1_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                    "", c1_b_k), 1, 3, 1, 0) - 1) + 3 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               c1_b_k), 1, 3, 2, 0) - 1)] +
            8.64864E+006;
        }

        for (c1_i229 = 0; c1_i229 < 9; c1_i229 = c1_i229 + 1) {
          c1_k_a[c1_i229] = c1_A[c1_i229];
        }

        for (c1_i230 = 0; c1_i230 < 9; c1_i230 = c1_i230 + 1) {
          c1_q_b[c1_i230] = c1_U[c1_i230];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        for (c1_i231 = 0; c1_i231 < 9; c1_i231 = c1_i231 + 1) {
          c1_l_a[c1_i231] = c1_k_a[c1_i231];
        }

        for (c1_i232 = 0; c1_i232 < 9; c1_i232 = c1_i232 + 1) {
          c1_r_b[c1_i232] = c1_q_b[c1_i232];
        }

        for (c1_i233 = 0; c1_i233 < 9; c1_i233 = c1_i233 + 1) {
          c1_dv28[c1_i233] = 0.0;
        }

        c1_eml_xgemm(chartInstance, c1_l_a, c1_r_b, c1_dv28, c1_U);
        for (c1_i234 = 0; c1_i234 < 9; c1_i234 = c1_i234 + 1) {
          c1_s_b[c1_i234] = c1_A4[c1_i234];
        }

        for (c1_i235 = 0; c1_i235 < 9; c1_i235 = c1_i235 + 1) {
          c1_f_y[c1_i235] = 56.0 * c1_s_b[c1_i235];
        }

        for (c1_i236 = 0; c1_i236 < 9; c1_i236 = c1_i236 + 1) {
          c1_t_b[c1_i236] = c1_A3[c1_i236];
        }

        for (c1_i237 = 0; c1_i237 < 9; c1_i237 = c1_i237 + 1) {
          c1_g_y[c1_i237] = 25200.0 * c1_t_b[c1_i237];
        }

        for (c1_i238 = 0; c1_i238 < 9; c1_i238 = c1_i238 + 1) {
          c1_u_b[c1_i238] = c1_A2[c1_i238];
        }

        for (c1_i239 = 0; c1_i239 < 9; c1_i239 = c1_i239 + 1) {
          c1_h_y[c1_i239] = 1.99584E+006 * c1_u_b[c1_i239];
        }

        for (c1_i240 = 0; c1_i240 < 9; c1_i240 = c1_i240 + 1) {
          c1_V[c1_i240] = (c1_f_y[c1_i240] + c1_g_y[c1_i240]) + c1_h_y[c1_i240];
        }

        c1_d = 1.729728E+007;
      } else if (c1_m == 9.0) {
        for (c1_i241 = 0; c1_i241 < 9; c1_i241 = c1_i241 + 1) {
          c1_m_a[c1_i241] = c1_A4[c1_i241];
        }

        for (c1_i242 = 0; c1_i242 < 9; c1_i242 = c1_i242 + 1) {
          c1_v_b[c1_i242] = c1_A2[c1_i242];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        for (c1_i243 = 0; c1_i243 < 9; c1_i243 = c1_i243 + 1) {
          c1_n_a[c1_i243] = c1_m_a[c1_i243];
        }

        for (c1_i244 = 0; c1_i244 < 9; c1_i244 = c1_i244 + 1) {
          c1_w_b[c1_i244] = c1_v_b[c1_i244];
        }

        for (c1_i245 = 0; c1_i245 < 9; c1_i245 = c1_i245 + 1) {
          c1_dv29[c1_i245] = 0.0;
        }

        c1_eml_xgemm(chartInstance, c1_n_a, c1_w_b, c1_dv29, c1_V);
        for (c1_i246 = 0; c1_i246 < 9; c1_i246 = c1_i246 + 1) {
          c1_x_b[c1_i246] = c1_A4[c1_i246];
        }

        for (c1_i247 = 0; c1_i247 < 9; c1_i247 = c1_i247 + 1) {
          c1_i_y[c1_i247] = 3960.0 * c1_x_b[c1_i247];
        }

        for (c1_i248 = 0; c1_i248 < 9; c1_i248 = c1_i248 + 1) {
          c1_y_b[c1_i248] = c1_A3[c1_i248];
        }

        for (c1_i249 = 0; c1_i249 < 9; c1_i249 = c1_i249 + 1) {
          c1_j_y[c1_i249] = 2.16216E+006 * c1_y_b[c1_i249];
        }

        for (c1_i250 = 0; c1_i250 < 9; c1_i250 = c1_i250 + 1) {
          c1_ab_b[c1_i250] = c1_A2[c1_i250];
        }

        for (c1_i251 = 0; c1_i251 < 9; c1_i251 = c1_i251 + 1) {
          c1_k_y[c1_i251] = 3.027024E+008 * c1_ab_b[c1_i251];
        }

        for (c1_i252 = 0; c1_i252 < 9; c1_i252 = c1_i252 + 1) {
          c1_U[c1_i252] = ((c1_V[c1_i252] + c1_i_y[c1_i252]) + c1_j_y[c1_i252])
            + c1_k_y[c1_i252];
        }

        for (c1_e_k = 1.0; c1_e_k <= 3.0; c1_e_k = c1_e_k + 1.0) {
          c1_b_k = c1_e_k;
          c1_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c1_b_k), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] =
            c1_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                    "", c1_b_k), 1, 3, 1, 0) - 1) + 3 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               c1_b_k), 1, 3, 2, 0) - 1)] +
            8.8216128E+009;
        }

        for (c1_i253 = 0; c1_i253 < 9; c1_i253 = c1_i253 + 1) {
          c1_o_a[c1_i253] = c1_A[c1_i253];
        }

        for (c1_i254 = 0; c1_i254 < 9; c1_i254 = c1_i254 + 1) {
          c1_bb_b[c1_i254] = c1_U[c1_i254];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        for (c1_i255 = 0; c1_i255 < 9; c1_i255 = c1_i255 + 1) {
          c1_p_a[c1_i255] = c1_o_a[c1_i255];
        }

        for (c1_i256 = 0; c1_i256 < 9; c1_i256 = c1_i256 + 1) {
          c1_cb_b[c1_i256] = c1_bb_b[c1_i256];
        }

        for (c1_i257 = 0; c1_i257 < 9; c1_i257 = c1_i257 + 1) {
          c1_dv30[c1_i257] = 0.0;
        }

        c1_eml_xgemm(chartInstance, c1_p_a, c1_cb_b, c1_dv30, c1_U);
        for (c1_i258 = 0; c1_i258 < 9; c1_i258 = c1_i258 + 1) {
          c1_db_b[c1_i258] = c1_V[c1_i258];
        }

        for (c1_i259 = 0; c1_i259 < 9; c1_i259 = c1_i259 + 1) {
          c1_l_y[c1_i259] = 90.0 * c1_db_b[c1_i259];
        }

        for (c1_i260 = 0; c1_i260 < 9; c1_i260 = c1_i260 + 1) {
          c1_eb_b[c1_i260] = c1_A4[c1_i260];
        }

        for (c1_i261 = 0; c1_i261 < 9; c1_i261 = c1_i261 + 1) {
          c1_m_y[c1_i261] = 110880.0 * c1_eb_b[c1_i261];
        }

        for (c1_i262 = 0; c1_i262 < 9; c1_i262 = c1_i262 + 1) {
          c1_fb_b[c1_i262] = c1_A3[c1_i262];
        }

        for (c1_i263 = 0; c1_i263 < 9; c1_i263 = c1_i263 + 1) {
          c1_n_y[c1_i263] = 3.027024E+007 * c1_fb_b[c1_i263];
        }

        for (c1_i264 = 0; c1_i264 < 9; c1_i264 = c1_i264 + 1) {
          c1_gb_b[c1_i264] = c1_A2[c1_i264];
        }

        for (c1_i265 = 0; c1_i265 < 9; c1_i265 = c1_i265 + 1) {
          c1_o_y[c1_i265] = 2.0756736E+009 * c1_gb_b[c1_i265];
        }

        for (c1_i266 = 0; c1_i266 < 9; c1_i266 = c1_i266 + 1) {
          c1_V[c1_i266] = ((c1_l_y[c1_i266] + c1_m_y[c1_i266]) + c1_n_y[c1_i266])
            + c1_o_y[c1_i266];
        }

        c1_d = 1.76432256E+010;
      } else {
        for (c1_i267 = 0; c1_i267 < 9; c1_i267 = c1_i267 + 1) {
          c1_hb_b[c1_i267] = c1_A4[c1_i267];
        }

        for (c1_i268 = 0; c1_i268 < 9; c1_i268 = c1_i268 + 1) {
          c1_p_y[c1_i268] = 3.352212864E+010 * c1_hb_b[c1_i268];
        }

        for (c1_i269 = 0; c1_i269 < 9; c1_i269 = c1_i269 + 1) {
          c1_ib_b[c1_i269] = c1_A3[c1_i269];
        }

        for (c1_i270 = 0; c1_i270 < 9; c1_i270 = c1_i270 + 1) {
          c1_q_y[c1_i270] = 1.0559470521600000E+013 * c1_ib_b[c1_i270];
        }

        for (c1_i271 = 0; c1_i271 < 9; c1_i271 = c1_i271 + 1) {
          c1_jb_b[c1_i271] = c1_A2[c1_i271];
        }

        for (c1_i272 = 0; c1_i272 < 9; c1_i272 = c1_i272 + 1) {
          c1_r_y[c1_i272] = 1.1873537964288000E+015 * c1_jb_b[c1_i272];
        }

        for (c1_i273 = 0; c1_i273 < 9; c1_i273 = c1_i273 + 1) {
          c1_U[c1_i273] = (c1_p_y[c1_i273] + c1_q_y[c1_i273]) + c1_r_y[c1_i273];
        }

        for (c1_f_k = 1.0; c1_f_k <= 3.0; c1_f_k = c1_f_k + 1.0) {
          c1_b_k = c1_f_k;
          c1_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c1_b_k), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] =
            c1_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                    "", c1_b_k), 1, 3, 1, 0) - 1) + 3 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               c1_b_k), 1, 3, 2, 0) - 1)] +
            3.2382376266240000E+016;
        }

        for (c1_i274 = 0; c1_i274 < 9; c1_i274 = c1_i274 + 1) {
          c1_kb_b[c1_i274] = c1_A3[c1_i274];
        }

        for (c1_i275 = 0; c1_i275 < 9; c1_i275 = c1_i275 + 1) {
          c1_s_y[c1_i275] = 16380.0 * c1_kb_b[c1_i275];
        }

        for (c1_i276 = 0; c1_i276 < 9; c1_i276 = c1_i276 + 1) {
          c1_lb_b[c1_i276] = c1_A2[c1_i276];
        }

        for (c1_i277 = 0; c1_i277 < 9; c1_i277 = c1_i277 + 1) {
          c1_t_y[c1_i277] = 4.08408E+007 * c1_lb_b[c1_i277];
        }

        for (c1_i278 = 0; c1_i278 < 9; c1_i278 = c1_i278 + 1) {
          c1_q_a[c1_i278] = c1_A4[c1_i278];
        }

        for (c1_i279 = 0; c1_i279 < 9; c1_i279 = c1_i279 + 1) {
          c1_mb_b[c1_i279] = (c1_A4[c1_i279] + c1_s_y[c1_i279]) + c1_t_y[c1_i279];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        for (c1_i280 = 0; c1_i280 < 9; c1_i280 = c1_i280 + 1) {
          c1_r_a[c1_i280] = c1_q_a[c1_i280];
        }

        for (c1_i281 = 0; c1_i281 < 9; c1_i281 = c1_i281 + 1) {
          c1_nb_b[c1_i281] = c1_mb_b[c1_i281];
        }

        for (c1_i282 = 0; c1_i282 < 9; c1_i282 = c1_i282 + 1) {
          c1_dv31[c1_i282] = 0.0;
        }

        c1_eml_xgemm(chartInstance, c1_r_a, c1_nb_b, c1_dv31, c1_u_y);
        for (c1_i283 = 0; c1_i283 < 9; c1_i283 = c1_i283 + 1) {
          c1_s_a[c1_i283] = c1_A[c1_i283];
        }

        for (c1_i284 = 0; c1_i284 < 9; c1_i284 = c1_i284 + 1) {
          c1_ob_b[c1_i284] = c1_u_y[c1_i284] + c1_U[c1_i284];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        for (c1_i285 = 0; c1_i285 < 9; c1_i285 = c1_i285 + 1) {
          c1_t_a[c1_i285] = c1_s_a[c1_i285];
        }

        for (c1_i286 = 0; c1_i286 < 9; c1_i286 = c1_i286 + 1) {
          c1_pb_b[c1_i286] = c1_ob_b[c1_i286];
        }

        for (c1_i287 = 0; c1_i287 < 9; c1_i287 = c1_i287 + 1) {
          c1_dv32[c1_i287] = 0.0;
        }

        c1_eml_xgemm(chartInstance, c1_t_a, c1_pb_b, c1_dv32, c1_U);
        for (c1_i288 = 0; c1_i288 < 9; c1_i288 = c1_i288 + 1) {
          c1_qb_b[c1_i288] = c1_A4[c1_i288];
        }

        for (c1_i289 = 0; c1_i289 < 9; c1_i289 = c1_i289 + 1) {
          c1_v_y[c1_i289] = 182.0 * c1_qb_b[c1_i289];
        }

        for (c1_i290 = 0; c1_i290 < 9; c1_i290 = c1_i290 + 1) {
          c1_rb_b[c1_i290] = c1_A3[c1_i290];
        }

        for (c1_i291 = 0; c1_i291 < 9; c1_i291 = c1_i291 + 1) {
          c1_w_y[c1_i291] = 960960.0 * c1_rb_b[c1_i291];
        }

        for (c1_i292 = 0; c1_i292 < 9; c1_i292 = c1_i292 + 1) {
          c1_sb_b[c1_i292] = c1_A2[c1_i292];
        }

        for (c1_i293 = 0; c1_i293 < 9; c1_i293 = c1_i293 + 1) {
          c1_x_y[c1_i293] = 1.32324192E+009 * c1_sb_b[c1_i293];
        }

        for (c1_i294 = 0; c1_i294 < 9; c1_i294 = c1_i294 + 1) {
          c1_u_a[c1_i294] = c1_A4[c1_i294];
        }

        for (c1_i295 = 0; c1_i295 < 9; c1_i295 = c1_i295 + 1) {
          c1_tb_b[c1_i295] = (c1_v_y[c1_i295] + c1_w_y[c1_i295]) +
            c1_x_y[c1_i295];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        for (c1_i296 = 0; c1_i296 < 9; c1_i296 = c1_i296 + 1) {
          c1_v_a[c1_i296] = c1_u_a[c1_i296];
        }

        for (c1_i297 = 0; c1_i297 < 9; c1_i297 = c1_i297 + 1) {
          c1_ub_b[c1_i297] = c1_tb_b[c1_i297];
        }

        for (c1_i298 = 0; c1_i298 < 9; c1_i298 = c1_i298 + 1) {
          c1_dv33[c1_i298] = 0.0;
        }

        c1_eml_xgemm(chartInstance, c1_v_a, c1_ub_b, c1_dv33, c1_y_y);
        for (c1_i299 = 0; c1_i299 < 9; c1_i299 = c1_i299 + 1) {
          c1_vb_b[c1_i299] = c1_A4[c1_i299];
        }

        for (c1_i300 = 0; c1_i300 < 9; c1_i300 = c1_i300 + 1) {
          c1_ab_y[c1_i300] = 6.704425728E+011 * c1_vb_b[c1_i300];
        }

        for (c1_i301 = 0; c1_i301 < 9; c1_i301 = c1_i301 + 1) {
          c1_wb_b[c1_i301] = c1_A3[c1_i301];
        }

        for (c1_i302 = 0; c1_i302 < 9; c1_i302 = c1_i302 + 1) {
          c1_bb_y[c1_i302] = 1.2906019526400000E+014 * c1_wb_b[c1_i302];
        }

        for (c1_i303 = 0; c1_i303 < 9; c1_i303 = c1_i303 + 1) {
          c1_xb_b[c1_i303] = c1_A2[c1_i303];
        }

        for (c1_i304 = 0; c1_i304 < 9; c1_i304 = c1_i304 + 1) {
          c1_cb_y[c1_i304] = 7.7717703038976000E+015 * c1_xb_b[c1_i304];
        }

        for (c1_i305 = 0; c1_i305 < 9; c1_i305 = c1_i305 + 1) {
          c1_V[c1_i305] = ((c1_y_y[c1_i305] + c1_ab_y[c1_i305]) +
                           c1_bb_y[c1_i305]) + c1_cb_y[c1_i305];
        }

        c1_d = 6.4764752532480000E+016;
      }
    }
  }

  for (c1_g_k = 1.0; c1_g_k <= 3.0; c1_g_k = c1_g_k + 1.0) {
    c1_b_k = c1_g_k;
    c1_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
           1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] = c1_V
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", c1_b_k), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 2, 0) - 1)] +
      c1_d;
  }

  for (c1_h_k = 1.0; c1_h_k <= 9.0; c1_h_k = c1_h_k + 1.0) {
    c1_b_k = c1_h_k;
    c1_uk = c1_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 9, 1, 0) - 1];
    c1_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 9, 1, 0) - 1] = c1_V[_SFD_EML_ARRAY_BOUNDS_CHECK(""
      , (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 9, 1, 0) - 1] - c1_uk;
    c1_V[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 9, 1, 0) - 1] = c1_V[_SFD_EML_ARRAY_BOUNDS_CHECK(""
      , (int32_T)_SFD_INTEGER_CHECK("", c1_b_k), 1, 9, 1, 0) - 1] + c1_uk;
  }

  for (c1_i306 = 0; c1_i306 < 9; c1_i306 = c1_i306 + 1) {
    c1_b_U[c1_i306] = c1_U[c1_i306];
  }

  for (c1_i307 = 0; c1_i307 < 9; c1_i307 = c1_i307 + 1) {
    c1_b_V[c1_i307] = c1_V[c1_i307];
  }

  c1_mldivide(chartInstance, c1_b_U, c1_b_V, c1_F);
}

static void c1_mldivide(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_A[9], real_T c1_B[9], real_T c1_Y[9])
{
  int32_T c1_i308;
  real_T c1_b_A[9];
  int32_T c1_i309;
  real_T c1_b_B[9];
  int32_T c1_i310;
  real_T c1_c_A[9];
  int32_T c1_i311;
  real_T c1_c_B[9];
  int32_T c1_r1;
  int32_T c1_r2;
  int32_T c1_r3;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_b_y;
  real_T c1_maxval;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_c_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_d_y;
  real_T c1_a21;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_e_y;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_f_y;
  real_T c1_d;
  real_T c1_p_x;
  real_T c1_g_y;
  real_T c1_q_x;
  real_T c1_h_y;
  real_T c1_z;
  real_T c1_r_x;
  real_T c1_i_y;
  real_T c1_s_x;
  real_T c1_j_y;
  real_T c1_b_z;
  real_T c1_a;
  real_T c1_b;
  real_T c1_k_y;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_l_y;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_m_y;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_n_y;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_o_y;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_p_y;
  real_T c1_b_d;
  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_bb_x;
  real_T c1_q_y;
  real_T c1_cb_x;
  real_T c1_db_x;
  real_T c1_r_y;
  real_T c1_c_d;
  int32_T c1_rtemp;
  real_T c1_eb_x;
  real_T c1_s_y;
  real_T c1_fb_x;
  real_T c1_t_y;
  real_T c1_c_z;
  real_T c1_e_a;
  real_T c1_e_b;
  real_T c1_u_y;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_f_a;
  real_T c1_f_b;
  real_T c1_v_y;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_w_y;
  real_T c1_h_a;
  real_T c1_h_b;
  real_T c1_x_y;
  real_T c1_gb_x;
  real_T c1_y_y;
  real_T c1_hb_x;
  real_T c1_ab_y;
  real_T c1_d_z;
  real_T c1_i_a;
  real_T c1_i_b;
  real_T c1_bb_y;
  real_T c1_j_a;
  real_T c1_j_b;
  real_T c1_cb_y;
  real_T c1_ib_x;
  real_T c1_db_y;
  real_T c1_jb_x;
  real_T c1_eb_y;
  real_T c1_e_z;
  real_T c1_k_a;
  real_T c1_k_b;
  real_T c1_fb_y;
  real_T c1_kb_x;
  real_T c1_gb_y;
  real_T c1_lb_x;
  real_T c1_hb_y;
  real_T c1_f_z;
  for (c1_i308 = 0; c1_i308 < 9; c1_i308 = c1_i308 + 1) {
    c1_b_A[c1_i308] = c1_A[c1_i308];
  }

  for (c1_i309 = 0; c1_i309 < 9; c1_i309 = c1_i309 + 1) {
    c1_b_B[c1_i309] = c1_B[c1_i309];
  }

  for (c1_i310 = 0; c1_i310 < 9; c1_i310 = c1_i310 + 1) {
    c1_c_A[c1_i310] = c1_b_A[c1_i310];
  }

  for (c1_i311 = 0; c1_i311 < 9; c1_i311 = c1_i311 + 1) {
    c1_c_B[c1_i311] = c1_b_B[c1_i311];
  }

  c1_r1 = 1;
  c1_r2 = 2;
  c1_r3 = 3;
  c1_x = c1_c_A[0];
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_y = muDoubleScalarAbs(c1_c_x);
  c1_d_x = 0.0;
  c1_e_x = c1_d_x;
  c1_b_y = muDoubleScalarAbs(c1_e_x);
  c1_maxval = c1_y + c1_b_y;
  c1_f_x = c1_c_A[1];
  c1_g_x = c1_f_x;
  c1_h_x = c1_g_x;
  c1_c_y = muDoubleScalarAbs(c1_h_x);
  c1_i_x = 0.0;
  c1_j_x = c1_i_x;
  c1_d_y = muDoubleScalarAbs(c1_j_x);
  c1_a21 = c1_c_y + c1_d_y;
  if (c1_a21 > c1_maxval) {
    c1_maxval = c1_a21;
    c1_r1 = 2;
    c1_r2 = 1;
  }

  c1_k_x = c1_c_A[2];
  c1_l_x = c1_k_x;
  c1_m_x = c1_l_x;
  c1_e_y = muDoubleScalarAbs(c1_m_x);
  c1_n_x = 0.0;
  c1_o_x = c1_n_x;
  c1_f_y = muDoubleScalarAbs(c1_o_x);
  c1_d = c1_e_y + c1_f_y;
  if (c1_d > c1_maxval) {
    c1_r1 = 3;
    c1_r2 = 2;
    c1_r3 = 1;
  }

  c1_p_x = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r2), 1, 3, 1, 0) - 1];
  c1_g_y = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r1), 1, 3, 1, 0) - 1];
  c1_q_x = c1_p_x;
  c1_h_y = c1_g_y;
  c1_z = c1_q_x / c1_h_y;
  c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r2), 1, 3, 1, 0) - 1] = c1_z;
  c1_r_x = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r3), 1, 3, 1, 0) - 1];
  c1_i_y = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r1), 1, 3, 1, 0) - 1];
  c1_s_x = c1_r_x;
  c1_j_y = c1_i_y;
  c1_b_z = c1_s_x / c1_j_y;
  c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r3), 1, 3, 1, 0) - 1] = c1_b_z;
  c1_a = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r2), 1, 3, 1, 0) - 1];
  c1_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r1), 1, 3, 1, 0) + 2];
  c1_k_y = c1_a * c1_b;
  c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r2), 1, 3, 1, 0) + 2] = c1_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r2), 1, 3, 1, 0) + 2] - c1_k_y;
  c1_b_a = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r3), 1, 3, 1, 0) - 1];
  c1_b_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r1), 1, 3, 1, 0) + 2];
  c1_l_y = c1_b_a * c1_b_b;
  c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r3), 1, 3, 1, 0) + 2] = c1_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r3), 1, 3, 1, 0) + 2] - c1_l_y;
  c1_c_a = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r2), 1, 3, 1, 0) - 1];
  c1_c_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r1), 1, 3, 1, 0) + 5];
  c1_m_y = c1_c_a * c1_c_b;
  c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r2), 1, 3, 1, 0) + 5] = c1_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r2), 1, 3, 1, 0) + 5] - c1_m_y;
  c1_d_a = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r3), 1, 3, 1, 0) - 1];
  c1_d_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r1), 1, 3, 1, 0) + 5];
  c1_n_y = c1_d_a * c1_d_b;
  c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r3), 1, 3, 1, 0) + 5] = c1_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r3), 1, 3, 1, 0) + 5] - c1_n_y;
  c1_t_x = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r3), 1, 3, 1, 0) + 2];
  c1_u_x = c1_t_x;
  c1_v_x = c1_u_x;
  c1_o_y = muDoubleScalarAbs(c1_v_x);
  c1_w_x = 0.0;
  c1_x_x = c1_w_x;
  c1_p_y = muDoubleScalarAbs(c1_x_x);
  c1_b_d = c1_o_y + c1_p_y;
  c1_y_x = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r2), 1, 3, 1, 0) + 2];
  c1_ab_x = c1_y_x;
  c1_bb_x = c1_ab_x;
  c1_q_y = muDoubleScalarAbs(c1_bb_x);
  c1_cb_x = 0.0;
  c1_db_x = c1_cb_x;
  c1_r_y = muDoubleScalarAbs(c1_db_x);
  c1_c_d = c1_q_y + c1_r_y;
  if (c1_b_d > c1_c_d) {
    c1_rtemp = c1_r2;
    c1_r2 = c1_r3;
    c1_r3 = c1_rtemp;
  }

  c1_eb_x = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c1_r3), 1, 3, 1, 0) + 2];
  c1_s_y = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r2), 1, 3, 1, 0) + 2];
  c1_fb_x = c1_eb_x;
  c1_t_y = c1_s_y;
  c1_c_z = c1_fb_x / c1_t_y;
  c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r3), 1, 3, 1, 0) + 2] = c1_c_z;
  c1_e_a = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r3), 1, 3, 1, 0) + 2];
  c1_e_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_r2), 1, 3, 1, 0) + 5];
  c1_u_y = c1_e_a * c1_e_b;
  c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r3), 1, 3, 1, 0) + 5] = c1_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_r3), 1, 3, 1, 0) + 5] - c1_u_y;
  if (c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_r1), 1, 3, 1, 0) - 1] == 0.0) {
  } else if (c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
               "", (real_T)c1_r2), 1, 3, 1, 0) + 2] == 0.0) {
  } else if (c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
               "", (real_T)c1_r3), 1, 3, 1, 0) + 5] == 0.0) {
    goto label_1;
  } else {
    goto label_2;
  }

 label_1:
  ;
  c1_eml_warning(chartInstance);
 label_2:
  ;
  c1_eml_scalar_eg(chartInstance);
  for (c1_k = 1; c1_k < 4; c1_k = c1_k + 1) {
    c1_b_k = c1_k;
    c1_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = c1_c_B[(
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_r1), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_f_a = c1_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_f_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_r2), 1, 3, 1, 0) - 1];
    c1_v_y = c1_f_a * c1_f_b;
    c1_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = c1_c_B[(
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_r2), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)] -
      c1_v_y;
    c1_g_a = c1_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_g_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_r3), 1, 3, 1, 0) - 1];
    c1_w_y = c1_g_a * c1_g_b;
    c1_h_a = c1_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_h_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_r3), 1, 3, 1, 0) + 2];
    c1_x_y = c1_h_a * c1_h_b;
    c1_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = (c1_c_B[(
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_r3), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)] -
      c1_w_y) - c1_x_y;
    c1_gb_x = c1_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_y_y = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_r3), 1, 3, 1, 0) + 5];
    c1_hb_x = c1_gb_x;
    c1_ab_y = c1_y_y;
    c1_d_z = c1_hb_x / c1_ab_y;
    c1_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = c1_d_z;
    c1_i_a = c1_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_i_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_r1), 1, 3, 1, 0) + 5];
    c1_bb_y = c1_i_a * c1_i_b;
    c1_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = c1_Y[3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_b_k), 1, 3, 2, 0) - 1)] - c1_bb_y;
    c1_j_a = c1_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_j_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_r2), 1, 3, 1, 0) + 5];
    c1_cb_y = c1_j_a * c1_j_b;
    c1_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = c1_Y[1 + 3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_b_k), 1, 3, 2, 0) - 1)] - c1_cb_y;
    c1_ib_x = c1_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_db_y = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c1_r2), 1, 3, 1, 0) + 2];
    c1_jb_x = c1_ib_x;
    c1_eb_y = c1_db_y;
    c1_e_z = c1_jb_x / c1_eb_y;
    c1_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = c1_e_z;
    c1_k_a = c1_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_k_b = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_r1), 1, 3, 1, 0) + 2];
    c1_fb_y = c1_k_a * c1_k_b;
    c1_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = c1_Y[3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_b_k), 1, 3, 2, 0) - 1)] - c1_fb_y;
    c1_kb_x = c1_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 2, 0) - 1)];
    c1_gb_y = c1_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c1_r1), 1, 3, 1, 0) - 1];
    c1_lb_x = c1_kb_x;
    c1_hb_y = c1_gb_y;
    c1_f_z = c1_lb_x / c1_hb_y;
    c1_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_b_k), 1, 3, 2, 0) - 1)] = c1_f_z;
  }
}

static void c1_eml_warning(SFc1_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c1_i312;
  static char_T c1_cv8[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x'
  };

  char_T c1_u[21];
  const mxArray *c1_y = NULL;
  int32_T c1_i313;
  static char_T c1_cv9[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o'
    , ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char_T c1_b_u[40];
  const mxArray *c1_b_y = NULL;
  for (c1_i312 = 0; c1_i312 < 21; c1_i312 = c1_i312 + 1) {
    c1_u[c1_i312] = c1_cv8[c1_i312];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c1_i313 = 0; c1_i313 < 40; c1_i313 = c1_i313 + 1) {
    c1_b_u[c1_i313] = c1_cv9[c1_i313];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static real_T c1_mpower(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
  c1_a)
{
  return c1_power(chartInstance, c1_a, 2.0);
}

static real_T c1_acos(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                      c1_x)
{
  real_T c1_b_x;
  real_T c1_c_x;
  c1_b_x = c1_x;
  if (c1_b_x < -1.0) {
  } else if (1.0 < c1_b_x) {
  } else {
    goto label_1;
  }

  c1_e_eml_error(chartInstance);
 label_1:
  ;
  c1_c_x = c1_b_x;
  c1_b_x = c1_c_x;
  return muDoubleScalarAcos(c1_b_x);
}

static void c1_e_eml_error(SFc1_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c1_i314;
  static char_T c1_cv10[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 'c', 'o', 's', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[31];
  const mxArray *c1_y = NULL;
  int32_T c1_i315;
  static char_T c1_cv11[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 'a',
    'c', 'o', 's', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c1_b_u[77];
  const mxArray *c1_b_y = NULL;
  for (c1_i314 = 0; c1_i314 < 31; c1_i314 = c1_i314 + 1) {
    c1_u[c1_i314] = c1_cv10[c1_i314];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c1_i315 = 0; c1_i315 < 77; c1_i315 = c1_i315 + 1) {
    c1_b_u[c1_i315] = c1_cv11[c1_i315];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static void c1_d_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance)
{
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i316;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i316 = 0; c1_i316 < 3; c1_i316 = c1_i316 + 1) {
    c1_b_u[c1_i316] = (*((real_T (*)[3])c1_u))[c1_i316];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i317;
  int32_T c1_i318;
  int32_T c1_i319;
  real_T c1_b_u[9];
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i317 = 0;
  for (c1_i318 = 0; c1_i318 < 3; c1_i318 = c1_i318 + 1) {
    for (c1_i319 = 0; c1_i319 < 3; c1_i319 = c1_i319 + 1) {
      c1_b_u[c1_i319 + c1_i317] = (*((real_T (*)[9])c1_u))[c1_i319 + c1_i317];
    }

    c1_i317 = c1_i317 + 3;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i320;
  real_T c1_b_u[2];
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i320 = 0; c1_i320 < 2; c1_i320 = c1_i320 + 1) {
    c1_b_u[c1_i320] = (*((real_T (*)[2])c1_u))[c1_i320];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i321;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i321 = 0; c1_i321 < 3; c1_i321 = c1_i321 + 1) {
    c1_b_u[c1_i321] = (*((real_T (*)[3])c1_u))[c1_i321];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_twa_parallel_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[106];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i322;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 106));
  for (c1_i322 = 0; c1_i322 < 106; c1_i322 = c1_i322 + 1) {
    c1_r0 = &c1_info[c1_i322];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i322);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i322);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i322);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i322);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i322);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c1_i322);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c1_i322);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[106])
{
  c1_info[0].context = "";
  c1_info[0].name = "minus";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[B]minus";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "abs";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[1].fileLength = 566U;
  c1_info[1].fileTime1 = 1221292332U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[2].name = "nargin";
  c1_info[2].dominantType = "";
  c1_info[2].resolved = "[B]nargin";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[3].name = "gt";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]gt";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[4].name = "isa";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]isa";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[5].name = "ischar";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]ischar";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[6].name = "islogical";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]islogical";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[7].name = "size";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]size";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[8].name = "class";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]class";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[9].name = "zeros";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]zeros";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[10].name = "eml_scalar_abs";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[10].fileLength = 461U;
  c1_info[10].fileTime1 = 1203473160U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[11].name = "isinteger";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[B]isinteger";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[12].name = "isreal";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]isreal";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "";
  c1_info[13].name = "cos";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[13].fileLength = 324U;
  c1_info[13].fileTime1 = 1203473150U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[14].name = "eml_scalar_cos";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[14].fileLength = 602U;
  c1_info[14].fileTime1 = 1209355986U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context = "";
  c1_info[15].name = "sin";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[15].fileLength = 324U;
  c1_info[15].fileTime1 = 1203473242U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[16].name = "eml_scalar_sin";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[16].fileLength = 601U;
  c1_info[16].fileTime1 = 1209355990U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context = "";
  c1_info[17].name = "uminus";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[B]uminus";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context = "";
  c1_info[18].name = "pi";
  c1_info[18].dominantType = "";
  c1_info[18].resolved = "[B]pi";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context = "";
  c1_info[19].name = "mtimes";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[19].fileLength = 3425U;
  c1_info[19].fileTime1 = 1250697966U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[20].name = "isscalar";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[B]isscalar";
  c1_info[20].fileLength = 0U;
  c1_info[20].fileTime1 = 0U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[21].name = "strcmp";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved = "[B]strcmp";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[22].name = "eq";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[B]eq";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[23].name = "not";
  c1_info[23].dominantType = "logical";
  c1_info[23].resolved = "[B]not";
  c1_info[23].fileLength = 0U;
  c1_info[23].fileTime1 = 0U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "";
  c1_info[24].name = "mrdivide";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[24].fileLength = 800U;
  c1_info[24].fileTime1 = 1238459490U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[25].name = "ge";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved = "[B]ge";
  c1_info[25].fileLength = 0U;
  c1_info[25].fileTime1 = 0U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[26].name = "rdivide";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[26].fileLength = 403U;
  c1_info[26].fileTime1 = 1244760752U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[27].name = "eml_div";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[27].fileLength = 4269U;
  c1_info[27].fileTime1 = 1228119026U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context = "";
  c1_info[28].name = "ones";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved = "[B]ones";
  c1_info[28].fileLength = 0U;
  c1_info[28].fileTime1 = 0U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[29].name = "ndims";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved = "[B]ndims";
  c1_info[29].fileLength = 0U;
  c1_info[29].fileTime1 = 0U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[30].name = "le";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved = "[B]le";
  c1_info[30].fileLength = 0U;
  c1_info[30].fileTime1 = 0U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[31].name = "ne";
  c1_info[31].dominantType = "logical";
  c1_info[31].resolved = "[B]ne";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[32].name = "eml_index_class";
  c1_info[32].dominantType = "";
  c1_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[32].fileLength = 909U;
  c1_info[32].fileTime1 = 1192491982U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[33].name = "cast";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved = "[B]cast";
  c1_info[33].fileLength = 0U;
  c1_info[33].fileTime1 = 0U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[34].name = "eml_scalar_eg";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[34].fileLength = 3068U;
  c1_info[34].fileTime1 = 1240287210U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c1_info[35].name = "false";
  c1_info[35].dominantType = "";
  c1_info[35].resolved = "[B]false";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[36].name = "isstruct";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]isstruct";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c1_info[37].name = "plus";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved = "[B]plus";
  c1_info[37].fileLength = 0U;
  c1_info[37].fileTime1 = 0U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[38].name = "isempty";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]isempty";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[39].name = "eml_xgemm";
  c1_info[39].dominantType = "int32";
  c1_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[39].fileLength = 3184U;
  c1_info[39].fileTime1 = 1209356052U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[40].name = "lt";
  c1_info[40].dominantType = "int32";
  c1_info[40].resolved = "[B]lt";
  c1_info[40].fileLength = 0U;
  c1_info[40].fileTime1 = 0U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c1_info[41].name = "length";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[41].fileLength = 326U;
  c1_info[41].fileTime1 = 1226602474U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c1_info[42].name = "min";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[42].fileLength = 362U;
  c1_info[42].fileTime1 = 1244760752U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[43].name = "nargout";
  c1_info[43].dominantType = "";
  c1_info[43].resolved = "[B]nargout";
  c1_info[43].fileLength = 0U;
  c1_info[43].fileTime1 = 0U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[44].name = "eml_min_or_max";
  c1_info[44].dominantType = "char";
  c1_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[44].fileLength = 9969U;
  c1_info[44].fileTime1 = 1240287206U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[45].name = "isnumeric";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved = "[B]isnumeric";
  c1_info[45].fileLength = 0U;
  c1_info[45].fileTime1 = 0U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c1_info[46].name = "eml_scalexp_alloc";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[46].fileLength = 808U;
  c1_info[46].fileTime1 = 1230519898U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[47].name = "eml_refblas_xgemm";
  c1_info[47].dominantType = "int32";
  c1_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[47].fileLength = 5748U;
  c1_info[47].fileTime1 = 1228119072U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[48].name = "eml_index_minus";
  c1_info[48].dominantType = "int32";
  c1_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[48].fileLength = 277U;
  c1_info[48].fileTime1 = 1192491984U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[49].name = "eml_index_times";
  c1_info[49].dominantType = "int32";
  c1_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[49].fileLength = 280U;
  c1_info[49].fileTime1 = 1192491986U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[50].name = "eml_index_plus";
  c1_info[50].dominantType = "int32";
  c1_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[50].fileLength = 272U;
  c1_info[50].fileTime1 = 1192491984U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context = "";
  c1_info[51].name = "norm";
  c1_info[51].dominantType = "double";
  c1_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[51].fileLength = 5312U;
  c1_info[51].fileTime1 = 1262645476U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[52].name = "isvector";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved = "[B]isvector";
  c1_info[52].fileLength = 0U;
  c1_info[52].fileTime1 = 0U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[53].name = "eml_xnrm2";
  c1_info[53].dominantType = "int32";
  c1_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[53].fileLength = 718U;
  c1_info[53].fileTime1 = 1209356056U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[54].name = "eml_refblas_xnrm2";
  c1_info[54].dominantType = "int32";
  c1_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[54].fileLength = 1433U;
  c1_info[54].fileTime1 = 1240287242U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[55].name = "true";
  c1_info[55].dominantType = "";
  c1_info[55].resolved = "[B]true";
  c1_info[55].fileLength = 0U;
  c1_info[55].fileTime1 = 0U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[56].name = "real";
  c1_info[56].dominantType = "double";
  c1_info[56].resolved = "[B]real";
  c1_info[56].fileLength = 0U;
  c1_info[56].fileTime1 = 0U;
  c1_info[56].fileTime2 = 0U;
  c1_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[57].name = "times";
  c1_info[57].dominantType = "double";
  c1_info[57].resolved = "[B]times";
  c1_info[57].fileLength = 0U;
  c1_info[57].fileTime1 = 0U;
  c1_info[57].fileTime2 = 0U;
  c1_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[58].name = "imag";
  c1_info[58].dominantType = "double";
  c1_info[58].resolved = "[B]imag";
  c1_info[58].fileLength = 0U;
  c1_info[58].fileTime1 = 0U;
  c1_info[58].fileTime2 = 0U;
  c1_info[59].context = "";
  c1_info[59].name = "NaN";
  c1_info[59].dominantType = "double";
  c1_info[59].resolved = "[B]NaN";
  c1_info[59].fileLength = 0U;
  c1_info[59].fileTime1 = 0U;
  c1_info[59].fileTime2 = 0U;
  c1_info[60].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[60].name = "inf";
  c1_info[60].dominantType = "";
  c1_info[60].resolved = "[B]inf";
  c1_info[60].fileLength = 0U;
  c1_info[60].fileTime1 = 0U;
  c1_info[60].fileTime2 = 0U;
  c1_info[61].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[61].name = "svd";
  c1_info[61].dominantType = "double";
  c1_info[61].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[61].fileLength = 18191U;
  c1_info[61].fileTime1 = 1238459482U;
  c1_info[61].fileTime2 = 0U;
  c1_info[62].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[62].name = "isfinite";
  c1_info[62].dominantType = "double";
  c1_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[62].fileLength = 364U;
  c1_info[62].fileTime1 = 1226602472U;
  c1_info[62].fileTime2 = 0U;
  c1_info[63].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[63].name = "isinf";
  c1_info[63].dominantType = "double";
  c1_info[63].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[63].fileLength = 506U;
  c1_info[63].fileTime1 = 1228119008U;
  c1_info[63].fileTime2 = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[106])
{
  c1_info[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[64].name = "isnan";
  c1_info[64].dominantType = "double";
  c1_info[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[64].fileLength = 506U;
  c1_info[64].fileTime1 = 1228119010U;
  c1_info[64].fileTime2 = 0U;
  c1_info[65].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[65].name = "and";
  c1_info[65].dominantType = "logical";
  c1_info[65].resolved = "[B]and";
  c1_info[65].fileLength = 0U;
  c1_info[65].fileTime1 = 0U;
  c1_info[65].fileTime2 = 0U;
  c1_info[66].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[66].name = "eml_error";
  c1_info[66].dominantType = "char";
  c1_info[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[66].fileLength = 315U;
  c1_info[66].fileTime1 = 1213951944U;
  c1_info[66].fileTime2 = 0U;
  c1_info[67].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[67].name = "max";
  c1_info[67].dominantType = "int32";
  c1_info[67].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[67].fileLength = 362U;
  c1_info[67].fileTime1 = 1244760752U;
  c1_info[67].fileTime2 = 0U;
  c1_info[68].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[68].name = "eml_xscal";
  c1_info[68].dominantType = "int32";
  c1_info[68].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c1_info[68].fileLength = 1205U;
  c1_info[68].fileTime1 = 1209356060U;
  c1_info[68].fileTime2 = 0U;
  c1_info[69].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c1_info[69].name = "eml_refblas_xscal";
  c1_info[69].dominantType = "int32";
  c1_info[69].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[69].fileLength = 464U;
  c1_info[69].fileTime1 = 1195339604U;
  c1_info[69].fileTime2 = 0U;
  c1_info[70].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[70].name = "eml_xdotc";
  c1_info[70].dominantType = "int32";
  c1_info[70].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c1_info[70].fileLength = 1453U;
  c1_info[70].fileTime1 = 1209356050U;
  c1_info[70].fileTime2 = 0U;
  c1_info[71].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c1_info[71].name = "eml_xdot";
  c1_info[71].dominantType = "int32";
  c1_info[71].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[71].fileLength = 1330U;
  c1_info[71].fileTime1 = 1209356048U;
  c1_info[71].fileTime2 = 0U;
  c1_info[72].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[72].name = "eml_refblas_xdot";
  c1_info[72].dominantType = "int32";
  c1_info[72].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[72].fileLength = 343U;
  c1_info[72].fileTime1 = 1211241242U;
  c1_info[72].fileTime2 = 0U;
  c1_info[73].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[73].name = "eml_refblas_xdotx";
  c1_info[73].dominantType = "int32";
  c1_info[73].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[73].fileLength = 1605U;
  c1_info[73].fileTime1 = 1236282478U;
  c1_info[73].fileTime2 = 0U;
  c1_info[74].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[74].name = "isequal";
  c1_info[74].dominantType = "char";
  c1_info[74].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[74].fileLength = 180U;
  c1_info[74].fileTime1 = 1226602470U;
  c1_info[74].fileTime2 = 0U;
  c1_info[75].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[75].name = "eml_isequal_core";
  c1_info[75].dominantType = "char";
  c1_info[75].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[75].fileLength = 4192U;
  c1_info[75].fileTime1 = 1257808582U;
  c1_info[75].fileTime2 = 0U;
  c1_info[76].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[76].name = "eml_xaxpy";
  c1_info[76].dominantType = "int32";
  c1_info[76].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c1_info[76].fileLength = 1880U;
  c1_info[76].fileTime1 = 1209356046U;
  c1_info[76].fileTime2 = 0U;
  c1_info[77].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c1_info[77].name = "eml_refblas_xaxpy";
  c1_info[77].dominantType = "int32";
  c1_info[77].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c1_info[77].fileLength = 1497U;
  c1_info[77].fileTime1 = 1238459464U;
  c1_info[77].fileTime2 = 0U;
  c1_info[78].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[78].name = "conj";
  c1_info[78].dominantType = "double";
  c1_info[78].resolved = "[B]conj";
  c1_info[78].fileLength = 0U;
  c1_info[78].fileTime1 = 0U;
  c1_info[78].fileTime2 = 0U;
  c1_info[79].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[79].name = "realmin";
  c1_info[79].dominantType = "char";
  c1_info[79].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[79].fileLength = 749U;
  c1_info[79].fileTime1 = 1226602478U;
  c1_info[79].fileTime2 = 0U;
  c1_info[80].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[80].name = "mpower";
  c1_info[80].dominantType = "double";
  c1_info[80].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[80].fileLength = 3710U;
  c1_info[80].fileTime1 = 1238459488U;
  c1_info[80].fileTime2 = 0U;
  c1_info[81].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[81].name = "power";
  c1_info[81].dominantType = "double";
  c1_info[81].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[81].fileLength = 5380U;
  c1_info[81].fileTime1 = 1228119098U;
  c1_info[81].fileTime2 = 0U;
  c1_info[82].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[82].name = "eml_scalar_floor";
  c1_info[82].dominantType = "double";
  c1_info[82].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[82].fileLength = 260U;
  c1_info[82].fileTime1 = 1209355990U;
  c1_info[82].fileTime2 = 0U;
  c1_info[83].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[83].name = "eps";
  c1_info[83].dominantType = "char";
  c1_info[83].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[83].fileLength = 1331U;
  c1_info[83].fileTime1 = 1246308586U;
  c1_info[83].fileTime2 = 0U;
  c1_info[84].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[84].name = "eml_is_float_class";
  c1_info[84].dominantType = "char";
  c1_info[84].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[84].fileLength = 226U;
  c1_info[84].fileTime1 = 1197875640U;
  c1_info[84].fileTime2 = 0U;
  c1_info[85].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[85].name = "eml_const_nonsingleton_dim";
  c1_info[85].dominantType = "double";
  c1_info[85].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[85].fileLength = 1473U;
  c1_info[85].fileTime1 = 1240287202U;
  c1_info[85].fileTime2 = 0U;
  c1_info[86].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[86].name = "sqrt";
  c1_info[86].dominantType = "double";
  c1_info[86].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[86].fileLength = 572U;
  c1_info[86].fileTime1 = 1203473244U;
  c1_info[86].fileTime2 = 0U;
  c1_info[87].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[87].name = "eml_scalar_sqrt";
  c1_info[87].dominantType = "double";
  c1_info[87].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[87].fileLength = 664U;
  c1_info[87].fileTime1 = 1209355994U;
  c1_info[87].fileTime2 = 0U;
  c1_info[88].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c1_info[88].name = "eml_xrotg";
  c1_info[88].dominantType = "double";
  c1_info[88].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c1_info[88].fileLength = 597U;
  c1_info[88].fileTime1 = 1209356058U;
  c1_info[88].fileTime2 = 0U;
  c1_info[89].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m";
  c1_info[89].name = "eml_refblas_xrotg";
  c1_info[89].dominantType = "double";
  c1_info[89].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c1_info[89].fileLength = 1282U;
  c1_info[89].fileTime1 = 1195339604U;
  c1_info[89].fileTime2 = 0U;
  c1_info[90].context = "";
  c1_info[90].name = "atan2";
  c1_info[90].dominantType = "double";
  c1_info[90].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[90].fileLength = 605U;
  c1_info[90].fileTime1 = 1236282454U;
  c1_info[90].fileTime2 = 0U;
  c1_info[91].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[91].name = "eml_scalar_atan2";
  c1_info[91].dominantType = "double";
  c1_info[91].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c1_info[91].fileLength = 964U;
  c1_info[91].fileTime1 = 1209355986U;
  c1_info[91].fileTime2 = 0U;
  c1_info[92].context = "";
  c1_info[92].name = "expm";
  c1_info[92].dominantType = "double";
  c1_info[92].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m";
  c1_info[92].fileLength = 4447U;
  c1_info[92].fileTime1 = 1228119078U;
  c1_info[92].fileTime2 = 0U;
  c1_info[93].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/mat1norm";
  c1_info[93].name = "eml_guarded_nan";
  c1_info[93].dominantType = "char";
  c1_info[93].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[93].fileLength = 485U;
  c1_info[93].fileTime1 = 1192491980U;
  c1_info[93].fileTime2 = 0U;
  c1_info[94].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[94].name = "nan";
  c1_info[94].dominantType = "char";
  c1_info[94].resolved = "[B]nan";
  c1_info[94].fileLength = 0U;
  c1_info[94].fileTime1 = 0U;
  c1_info[94].fileTime2 = 0U;
  c1_info[95].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m/PadeApproximantOfDegree";
  c1_info[95].name = "numel";
  c1_info[95].dominantType = "double";
  c1_info[95].resolved = "[B]numel";
  c1_info[95].fileLength = 0U;
  c1_info[95].fileTime1 = 0U;
  c1_info[95].fileTime2 = 0U;
  c1_info[96].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m/PadeApproximantOfDegree";
  c1_info[96].name = "mldivide";
  c1_info[96].dominantType = "double";
  c1_info[96].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c1_info[96].fileLength = 998U;
  c1_info[96].fileTime1 = 1238459488U;
  c1_info[96].fileTime2 = 0U;
  c1_info[97].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c1_info[97].name = "eml_lusolve";
  c1_info[97].dominantType = "double";
  c1_info[97].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c1_info[97].fileLength = 4120U;
  c1_info[97].fileTime1 = 1228119032U;
  c1_info[97].fileTime2 = 0U;
  c1_info[98].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolve3x3";
  c1_info[98].name = "eml_xcabs1";
  c1_info[98].dominantType = "double";
  c1_info[98].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[98].fileLength = 419U;
  c1_info[98].fileTime1 = 1209356046U;
  c1_info[98].fileTime2 = 0U;
  c1_info[99].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/warn_singular";
  c1_info[99].name = "eml_warning";
  c1_info[99].dominantType = "char";
  c1_info[99].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[99].fileLength = 262U;
  c1_info[99].fileTime1 = 1236282478U;
  c1_info[99].fileTime2 = 0U;
  c1_info[100].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m";
  c1_info[100].name = "log2";
  c1_info[100].dominantType = "double";
  c1_info[100].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/log2.m";
  c1_info[100].fileLength = 927U;
  c1_info[100].fileTime1 = 1228118988U;
  c1_info[100].fileTime2 = 0U;
  c1_info[101].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/log2.m";
  c1_info[101].name = "eml_scalar_log2";
  c1_info[101].dominantType = "double";
  c1_info[101].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log2.m";
  c1_info[101].fileLength = 1570U;
  c1_info[101].fileTime1 = 1203473198U;
  c1_info[101].fileTime2 = 0U;
  c1_info[102].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m";
  c1_info[102].name = "pow2";
  c1_info[102].dominantType = "double";
  c1_info[102].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/pow2.m";
  c1_info[102].fileLength = 1917U;
  c1_info[102].fileTime1 = 1228118990U;
  c1_info[102].fileTime2 = 0U;
  c1_info[103].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/pow2.m";
  c1_info[103].name = "eml_scalar_pow2";
  c1_info[103].dominantType = "double";
  c1_info[103].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_pow2.m";
  c1_info[103].fileLength = 189U;
  c1_info[103].fileTime1 = 1203473202U;
  c1_info[103].fileTime2 = 0U;
  c1_info[104].context = "";
  c1_info[104].name = "acos";
  c1_info[104].dominantType = "double";
  c1_info[104].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c1_info[104].fileLength = 585U;
  c1_info[104].fileTime1 = 1203473130U;
  c1_info[104].fileTime2 = 0U;
  c1_info[105].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c1_info[105].name = "eml_scalar_acos";
  c1_info[105].dominantType = "double";
  c1_info[105].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  c1_info[105].fileLength = 553U;
  c1_info[105].fileTime1 = 1203473160U;
  c1_info[105].fileTime2 = 0U;
}

static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static void c1_emlrt_marshallIn(SFc1_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c1_macro_leg_len, const char_T *
  c1_name, real_T c1_y[3])
{
  real_T c1_dv34[3];
  int32_T c1_i323;
  sf_mex_import(c1_name, sf_mex_dup(c1_macro_leg_len), &c1_dv34, 1, 0, 0U, 1, 0U,
                1, 3);
  for (c1_i323 = 0; c1_i323 < 3; c1_i323 = c1_i323 + 1) {
    c1_y[c1_i323] = c1_dv34[c1_i323];
  }

  sf_mex_destroy(&c1_macro_leg_len);
}

static uint8_T c1_b_emlrt_marshallIn(SFc1_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_twa_parallel,
  const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_is_active_c1_twa_parallel), &c1_u0, 1, 3,
                0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_is_active_c1_twa_parallel);
  return c1_y;
}

static void init_dsm_address_info(SFc1_twa_parallelInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_twa_parallel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2506857988U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2830719202U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1009946661U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(609105381U);
}

mxArray *sf_c1_twa_parallel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2714726105U);
    pr[1] = (double)(944377689U);
    pr[2] = (double)(767930267U);
    pr[3] = (double)(2007506603U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_twa_parallel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"macro_leg_len\",},{M[1],M[16],T\"micro_leg_len\",},{M[1],M[17],T\"x_cur\",},{M[8],M[0],T\"is_active_c1_twa_parallel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_twa_parallel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_twa_parallelInstanceStruct *chartInstance;
    chartInstance = (SFc1_twa_parallelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_twa_parallelMachineNumber_,
           1,
           1,
           1,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_twa_parallelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_twa_parallelMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_twa_parallelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x_des",0,(MexFcnForType)c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"macro_leg_len",0,(MexFcnForType)
                                c1_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"ee_rot",
                              0,(MexFcnForType)c1_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"macro_leg_len_prev",0,(MexFcnForType)
                                c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"micro_leg_len_prev",0,(MexFcnForType)
                                c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"micro_leg_len",0,(MexFcnForType)
                                c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x_cur",0,(MexFcnForType)c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x_prev",0,(MexFcnForType)c1_sf_marshall);
          }

          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,5,0,0,2,0,10,5);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,5028);
        _SFD_CV_INIT_EML_IF(0,0,1394,1447,1788,1845);
        _SFD_CV_INIT_EML_IF(0,1,1788,1845,-1,1845);
        _SFD_CV_INIT_EML_IF(0,2,3034,3062,-1,4619);
        _SFD_CV_INIT_EML_IF(0,3,4198,4247,4343,4438);
        _SFD_CV_INIT_EML_IF(0,4,4472,4516,-1,4578);
        _SFD_CV_INIT_EML_FOR(0,0,2011,2023,5016);
        _SFD_CV_INIT_EML_FOR(0,1,4170,4182,4594);

        {
          static int condStart[] = { 1397, 1424 };

          static int condEnd[] = { 1420, 1447 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,0,1397,1447,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1795, 1822 };

          static int condEnd[] = { 1818, 1845 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1795,1845,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3037, 3052 };

          static int condEnd[] = { 3048, 3062 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,2,3037,3062,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4201, 4223 };

          static int condEnd[] = { 4219, 4247 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,3,4201,4247,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4475, 4498 };

          static int condEnd[] = { 4494, 4516 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,4,4475,4516,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c1_x_des)[3];
          real_T (*c1_macro_leg_len)[3];
          real_T *c1_ee_rot;
          real_T (*c1_macro_leg_len_prev)[3];
          real_T (*c1_micro_leg_len_prev)[3];
          real_T (*c1_micro_leg_len)[3];
          real_T (*c1_x_cur)[3];
          real_T (*c1_x_prev)[3];
          c1_x_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c1_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c1_micro_leg_len = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c1_micro_leg_len_prev = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 3);
          c1_macro_leg_len_prev = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 2);
          c1_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_macro_leg_len = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c1_x_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_x_des);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_macro_leg_len);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_ee_rot);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_macro_leg_len_prev);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_micro_leg_len_prev);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_micro_leg_len);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_x_cur);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_x_prev);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_twa_parallelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_twa_parallel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_twa_parallelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*)
    chartInstanceVar);
  initialize_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_twa_parallel(void *chartInstanceVar)
{
  enable_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_twa_parallel(void *chartInstanceVar)
{
  disable_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_twa_parallel(void *chartInstanceVar)
{
  sf_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_twa_parallel(void *chartInstanceVar)
{
  ext_mode_exec_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_twa_parallel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_twa_parallel
    ((SFc1_twa_parallelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_twa_parallel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

static void sf_internal_set_sim_state_c1_twa_parallel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_twa_parallel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_twa_parallel(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_twa_parallel(S);
}

static void sf_opaque_set_sim_state_c1_twa_parallel(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c1_twa_parallel(S, st);
}

static void sf_opaque_terminate_c1_twa_parallel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_twa_parallelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_twa_parallel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_twa_parallel((SFc1_twa_parallelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c1_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("twa_parallel","twa_parallel",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("twa_parallel","twa_parallel",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("twa_parallel",
      "twa_parallel",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"twa_parallel","twa_parallel",1,5);
      sf_mark_chart_reusable_outputs(S,"twa_parallel","twa_parallel",1,3);
    }

    sf_set_rtw_dwork_info(S,"twa_parallel","twa_parallel",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(817181578U));
  ssSetChecksum1(S,(627249847U));
  ssSetChecksum2(S,(2414760911U));
  ssSetChecksum3(S,(3661386715U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "twa_parallel", "twa_parallel",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_twa_parallel(SimStruct *S)
{
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)malloc(sizeof
    (SFc1_twa_parallelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_twa_parallelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_twa_parallel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_twa_parallel;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_twa_parallel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_twa_parallel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_twa_parallel;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_twa_parallel;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_twa_parallel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_twa_parallel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_twa_parallel;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_twa_parallel;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_twa_parallel;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c1_twa_parallel;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }

  chart_debug_initialization(S,1);
}

void c1_twa_parallel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_twa_parallel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_twa_parallel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_twa_parallel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_twa_parallel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
