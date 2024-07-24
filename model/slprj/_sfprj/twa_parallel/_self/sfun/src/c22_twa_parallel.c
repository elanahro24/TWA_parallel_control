/* Include files */

#include "blascompat32.h"
#include "twa_parallel_sfun.h"
#include "c22_twa_parallel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "twa_parallel_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c22_debug_family_names[25] = { "n", "eta", "a0", "a4", "a3",
  "a5", "t", "tau", "nargin", "nargout", "q_des", "q_curr", "tf", "tc", "conf",
  "t0", "q0", "enable", "q_cmd", "q_dot", "q_dub_dot", "confn", "t0n", "q0n",
  "robot_mov" };

/* Function Declarations */
static void initialize_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance);
static void initialize_params_c22_twa_parallel(SFc22_twa_parallelInstanceStruct *
  chartInstance);
static void enable_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance);
static void disable_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance);
static void c22_update_debugger_state_c22_twa_parallel
  (SFc22_twa_parallelInstanceStruct *chartInstance);
static void ext_mode_exec_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c22_twa_parallel
  (SFc22_twa_parallelInstanceStruct *chartInstance);
static void set_sim_state_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c22_st);
static void finalize_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance);
static void sf_c22_twa_parallel(SFc22_twa_parallelInstanceStruct *chartInstance);
static void c22_c22_twa_parallel(SFc22_twa_parallelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber);
static void c22_eml_scalar_eg(SFc22_twa_parallelInstanceStruct *chartInstance);
static real_T c22_ceval_xdot(SFc22_twa_parallelInstanceStruct *chartInstance,
  int32_T c22_n, real_T c22_x[6], int32_T c22_ix0, int32_T c22_incx, real_T
  c22_y[6], int32_T c22_iy0, int32_T c22_incy);
static real_T c22_power(SFc22_twa_parallelInstanceStruct *chartInstance, real_T
  c22_a, real_T c22_b);
static void c22_eml_error(SFc22_twa_parallelInstanceStruct *chartInstance);
static const mxArray *c22_sf_marshall(void *chartInstanceVoid, void *c22_u);
static const mxArray *c22_b_sf_marshall(void *chartInstanceVoid, void *c22_u);
static void c22_info_helper(c22_ResolvedFunctionInfo c22_info[50]);
static const mxArray *c22_c_sf_marshall(void *chartInstanceVoid, void *c22_u);
static real_T c22_emlrt_marshallIn(SFc22_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c22_confn, const char_T *c22_name);
static void c22_b_emlrt_marshallIn(SFc22_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c22_q0n, const char_T *c22_name, real_T c22_y[6]);
static uint8_T c22_c_emlrt_marshallIn(SFc22_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c22_is_active_c22_twa_parallel, const char_T
  *c22_name);
static void init_dsm_address_info(SFc22_twa_parallelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance)
{
  uint8_T *c22_is_active_c22_twa_parallel;
  c22_is_active_c22_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c22_is_active_c22_twa_parallel = 0U;
}

static void initialize_params_c22_twa_parallel(SFc22_twa_parallelInstanceStruct *
  chartInstance)
{
}

static void enable_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c22_update_debugger_state_c22_twa_parallel
  (SFc22_twa_parallelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance)
{
  c22_update_debugger_state_c22_twa_parallel(chartInstance);
}

static const mxArray *get_sim_state_c22_twa_parallel
  (SFc22_twa_parallelInstanceStruct *chartInstance)
{
  const mxArray *c22_st = NULL;
  const mxArray *c22_y = NULL;
  real_T c22_hoistedGlobal;
  real_T c22_u;
  const mxArray *c22_b_y = NULL;
  int32_T c22_i0;
  real_T c22_b_hoistedGlobal[6];
  int32_T c22_i1;
  real_T c22_b_u[6];
  const mxArray *c22_c_y = NULL;
  int32_T c22_i2;
  real_T c22_c_hoistedGlobal[6];
  int32_T c22_i3;
  real_T c22_c_u[6];
  const mxArray *c22_d_y = NULL;
  int32_T c22_i4;
  real_T c22_d_hoistedGlobal[6];
  int32_T c22_i5;
  real_T c22_d_u[6];
  const mxArray *c22_e_y = NULL;
  int32_T c22_i6;
  real_T c22_e_hoistedGlobal[6];
  int32_T c22_i7;
  real_T c22_e_u[6];
  const mxArray *c22_f_y = NULL;
  real_T c22_f_hoistedGlobal;
  real_T c22_f_u;
  const mxArray *c22_g_y = NULL;
  real_T c22_g_hoistedGlobal;
  real_T c22_g_u;
  const mxArray *c22_h_y = NULL;
  uint8_T c22_h_hoistedGlobal;
  uint8_T c22_h_u;
  const mxArray *c22_i_y = NULL;
  real_T *c22_confn;
  real_T *c22_robot_mov;
  real_T *c22_t0n;
  uint8_T *c22_is_active_c22_twa_parallel;
  real_T (*c22_q_dub_dot)[6];
  real_T (*c22_q_dot)[6];
  real_T (*c22_q_cmd)[6];
  real_T (*c22_q0n)[6];
  c22_robot_mov = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c22_q0n = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 6);
  c22_t0n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c22_confn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c22_q_dub_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c22_q_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c22_q_cmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c22_is_active_c22_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellarray(8));
  c22_hoistedGlobal = *c22_confn;
  c22_u = c22_hoistedGlobal;
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c22_y, 0, c22_b_y);
  for (c22_i0 = 0; c22_i0 < 6; c22_i0 = c22_i0 + 1) {
    c22_b_hoistedGlobal[c22_i0] = (*c22_q0n)[c22_i0];
  }

  for (c22_i1 = 0; c22_i1 < 6; c22_i1 = c22_i1 + 1) {
    c22_b_u[c22_i1] = c22_b_hoistedGlobal[c22_i1];
  }

  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c22_y, 1, c22_c_y);
  for (c22_i2 = 0; c22_i2 < 6; c22_i2 = c22_i2 + 1) {
    c22_c_hoistedGlobal[c22_i2] = (*c22_q_cmd)[c22_i2];
  }

  for (c22_i3 = 0; c22_i3 < 6; c22_i3 = c22_i3 + 1) {
    c22_c_u[c22_i3] = c22_c_hoistedGlobal[c22_i3];
  }

  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", &c22_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c22_y, 2, c22_d_y);
  for (c22_i4 = 0; c22_i4 < 6; c22_i4 = c22_i4 + 1) {
    c22_d_hoistedGlobal[c22_i4] = (*c22_q_dot)[c22_i4];
  }

  for (c22_i5 = 0; c22_i5 < 6; c22_i5 = c22_i5 + 1) {
    c22_d_u[c22_i5] = c22_d_hoistedGlobal[c22_i5];
  }

  c22_e_y = NULL;
  sf_mex_assign(&c22_e_y, sf_mex_create("y", &c22_d_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c22_y, 3, c22_e_y);
  for (c22_i6 = 0; c22_i6 < 6; c22_i6 = c22_i6 + 1) {
    c22_e_hoistedGlobal[c22_i6] = (*c22_q_dub_dot)[c22_i6];
  }

  for (c22_i7 = 0; c22_i7 < 6; c22_i7 = c22_i7 + 1) {
    c22_e_u[c22_i7] = c22_e_hoistedGlobal[c22_i7];
  }

  c22_f_y = NULL;
  sf_mex_assign(&c22_f_y, sf_mex_create("y", &c22_e_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c22_y, 4, c22_f_y);
  c22_f_hoistedGlobal = *c22_robot_mov;
  c22_f_u = c22_f_hoistedGlobal;
  c22_g_y = NULL;
  sf_mex_assign(&c22_g_y, sf_mex_create("y", &c22_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c22_y, 5, c22_g_y);
  c22_g_hoistedGlobal = *c22_t0n;
  c22_g_u = c22_g_hoistedGlobal;
  c22_h_y = NULL;
  sf_mex_assign(&c22_h_y, sf_mex_create("y", &c22_g_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c22_y, 6, c22_h_y);
  c22_h_hoistedGlobal = *c22_is_active_c22_twa_parallel;
  c22_h_u = c22_h_hoistedGlobal;
  c22_i_y = NULL;
  sf_mex_assign(&c22_i_y, sf_mex_create("y", &c22_h_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c22_y, 7, c22_i_y);
  sf_mex_assign(&c22_st, c22_y);
  return c22_st;
}

static void set_sim_state_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c22_st)
{
  const mxArray *c22_u;
  real_T c22_dv0[6];
  int32_T c22_i8;
  real_T c22_dv1[6];
  int32_T c22_i9;
  real_T c22_dv2[6];
  int32_T c22_i10;
  real_T c22_dv3[6];
  int32_T c22_i11;
  boolean_T *c22_doneDoubleBufferReInit;
  real_T *c22_confn;
  real_T *c22_robot_mov;
  real_T *c22_t0n;
  uint8_T *c22_is_active_c22_twa_parallel;
  real_T (*c22_q0n)[6];
  real_T (*c22_q_cmd)[6];
  real_T (*c22_q_dot)[6];
  real_T (*c22_q_dub_dot)[6];
  c22_robot_mov = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c22_q0n = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 6);
  c22_t0n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c22_confn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c22_q_dub_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c22_q_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c22_q_cmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c22_is_active_c22_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c22_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c22_doneDoubleBufferReInit = TRUE;
  c22_u = sf_mex_dup(c22_st);
  *c22_confn = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c22_u, 0)), "confn");
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 1)),
    "q0n", c22_dv0);
  for (c22_i8 = 0; c22_i8 < 6; c22_i8 = c22_i8 + 1) {
    (*c22_q0n)[c22_i8] = c22_dv0[c22_i8];
  }

  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 2)),
    "q_cmd", c22_dv1);
  for (c22_i9 = 0; c22_i9 < 6; c22_i9 = c22_i9 + 1) {
    (*c22_q_cmd)[c22_i9] = c22_dv1[c22_i9];
  }

  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 3)),
    "q_dot", c22_dv2);
  for (c22_i10 = 0; c22_i10 < 6; c22_i10 = c22_i10 + 1) {
    (*c22_q_dot)[c22_i10] = c22_dv2[c22_i10];
  }

  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 4)),
    "q_dub_dot", c22_dv3);
  for (c22_i11 = 0; c22_i11 < 6; c22_i11 = c22_i11 + 1) {
    (*c22_q_dub_dot)[c22_i11] = c22_dv3[c22_i11];
  }

  *c22_robot_mov = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c22_u, 5)), "robot_mov");
  *c22_t0n = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u,
    6)), "t0n");
  *c22_is_active_c22_twa_parallel = c22_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 7)),
    "is_active_c22_twa_parallel");
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_twa_parallel(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_twa_parallel(SFc22_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void sf_c22_twa_parallel(SFc22_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c22_i12;
  int32_T c22_i13;
  int32_T c22_i14;
  int32_T c22_i15;
  int32_T c22_i16;
  int32_T c22_i17;
  int32_T c22_i18;
  int32_T c22_previousEvent;
  real_T *c22_tf;
  real_T *c22_tc;
  real_T *c22_conf;
  real_T *c22_confn;
  real_T *c22_t0;
  real_T *c22_t0n;
  real_T *c22_enable;
  real_T *c22_robot_mov;
  real_T (*c22_q0)[6];
  real_T (*c22_q0n)[6];
  real_T (*c22_q_dub_dot)[6];
  real_T (*c22_q_dot)[6];
  real_T (*c22_q_curr)[6];
  real_T (*c22_q_des)[6];
  real_T (*c22_q_cmd)[6];
  c22_robot_mov = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c22_enable = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c22_q0 = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 6);
  c22_q0n = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 6);
  c22_t0n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c22_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c22_confn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c22_conf = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c22_q_dub_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c22_q_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c22_tc = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c22_tf = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c22_q_curr = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c22_q_des = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c22_q_cmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,4);
  for (c22_i12 = 0; c22_i12 < 6; c22_i12 = c22_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_q_cmd)[c22_i12], 0U);
  }

  for (c22_i13 = 0; c22_i13 < 6; c22_i13 = c22_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_q_des)[c22_i13], 1U);
  }

  for (c22_i14 = 0; c22_i14 < 6; c22_i14 = c22_i14 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_q_curr)[c22_i14], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_tf, 3U);
  _SFD_DATA_RANGE_CHECK(*c22_tc, 4U);
  for (c22_i15 = 0; c22_i15 < 6; c22_i15 = c22_i15 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_q_dot)[c22_i15], 5U);
  }

  for (c22_i16 = 0; c22_i16 < 6; c22_i16 = c22_i16 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_q_dub_dot)[c22_i16], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_conf, 7U);
  _SFD_DATA_RANGE_CHECK(*c22_confn, 8U);
  _SFD_DATA_RANGE_CHECK(*c22_t0, 9U);
  _SFD_DATA_RANGE_CHECK(*c22_t0n, 10U);
  for (c22_i17 = 0; c22_i17 < 6; c22_i17 = c22_i17 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_q0n)[c22_i17], 11U);
  }

  for (c22_i18 = 0; c22_i18 < 6; c22_i18 = c22_i18 + 1) {
    _SFD_DATA_RANGE_CHECK((*c22_q0)[c22_i18], 12U);
  }

  _SFD_DATA_RANGE_CHECK(*c22_enable, 13U);
  _SFD_DATA_RANGE_CHECK(*c22_robot_mov, 14U);
  c22_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c22_c22_twa_parallel(chartInstance);
  _sfEvent_ = c22_previousEvent;
  sf_debug_check_for_state_inconsistency(_twa_parallelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c22_c22_twa_parallel(SFc22_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c22_i19;
  real_T c22_hoistedGlobal[6];
  int32_T c22_i20;
  real_T c22_b_hoistedGlobal[6];
  real_T c22_c_hoistedGlobal;
  real_T c22_d_hoistedGlobal;
  real_T c22_e_hoistedGlobal;
  real_T c22_f_hoistedGlobal;
  int32_T c22_i21;
  real_T c22_g_hoistedGlobal[6];
  real_T c22_h_hoistedGlobal;
  int32_T c22_i22;
  real_T c22_q_des[6];
  int32_T c22_i23;
  real_T c22_q_curr[6];
  real_T c22_tf;
  real_T c22_tc;
  real_T c22_conf;
  real_T c22_t0;
  int32_T c22_i24;
  real_T c22_q0[6];
  real_T c22_enable;
  uint32_T c22_debug_family_var_map[25];
  static const char *c22_sv0[25] = { "n", "eta", "a0", "a4", "a3", "a5", "t",
    "tau", "nargin", "nargout", "q_des", "q_curr", "tf",
    "tc", "conf", "t0", "q0", "enable", "q_cmd", "q_dot", "q_dub_dot", "confn",
    "t0n", "q0n",
    "robot_mov" };

  real_T c22_n;
  real_T c22_eta[6];
  real_T c22_a0[6];
  real_T c22_a4[6];
  real_T c22_a3[6];
  real_T c22_a5[6];
  real_T c22_t;
  real_T c22_tau;
  real_T c22_nargin = 8.0;
  real_T c22_nargout = 7.0;
  real_T c22_q_cmd[6];
  real_T c22_q_dot[6];
  real_T c22_q_dub_dot[6];
  real_T c22_confn;
  real_T c22_t0n;
  real_T c22_q0n[6];
  real_T c22_robot_mov;
  int32_T c22_i25;
  int32_T c22_i26;
  real_T c22_a[6];
  int32_T c22_i27;
  real_T c22_b[6];
  int32_T c22_i28;
  real_T c22_x[6];
  int32_T c22_i29;
  real_T c22_y[6];
  int32_T c22_i30;
  real_T c22_b_x[6];
  int32_T c22_i31;
  real_T c22_b_y[6];
  int32_T c22_i32;
  real_T c22_c_x[6];
  int32_T c22_i33;
  real_T c22_c_y[6];
  int32_T c22_i34;
  real_T c22_d_x[6];
  int32_T c22_i35;
  real_T c22_d_y[6];
  real_T c22_e_y;
  int32_T c22_i36;
  int32_T c22_i37;
  int32_T c22_i38;
  int32_T c22_i39;
  int32_T c22_i40;
  int32_T c22_i41;
  int32_T c22_i42;
  real_T c22_b_b[6];
  int32_T c22_i43;
  int32_T c22_i44;
  real_T c22_c_b[6];
  int32_T c22_i45;
  int32_T c22_i46;
  real_T c22_d_b[6];
  int32_T c22_i47;
  real_T c22_A;
  real_T c22_B;
  real_T c22_e_x;
  real_T c22_f_y;
  real_T c22_f_x;
  real_T c22_g_y;
  real_T c22_g_x;
  real_T c22_h_y;
  real_T c22_b_a;
  real_T c22_c;
  int32_T c22_i48;
  real_T c22_c_a[6];
  real_T c22_e_b;
  int32_T c22_i49;
  real_T c22_i_y[6];
  real_T c22_d_a;
  real_T c22_b_c;
  int32_T c22_i50;
  real_T c22_e_a[6];
  real_T c22_f_b;
  int32_T c22_i51;
  real_T c22_j_y[6];
  real_T c22_f_a;
  real_T c22_c_c;
  int32_T c22_i52;
  real_T c22_g_a[6];
  real_T c22_g_b;
  int32_T c22_i53;
  real_T c22_k_y[6];
  int32_T c22_i54;
  int32_T c22_i55;
  real_T c22_h_b[6];
  int32_T c22_i56;
  real_T c22_l_y[6];
  real_T c22_h_a;
  real_T c22_d_c;
  int32_T c22_i57;
  real_T c22_i_a[6];
  real_T c22_i_b;
  int32_T c22_i58;
  real_T c22_m_y[6];
  real_T c22_j_a;
  real_T c22_e_c;
  int32_T c22_i59;
  real_T c22_b_A[6];
  real_T c22_b_B;
  int32_T c22_i60;
  real_T c22_h_x[6];
  real_T c22_n_y;
  int32_T c22_i61;
  real_T c22_i_x[6];
  real_T c22_o_y;
  int32_T c22_i62;
  real_T c22_j_x[6];
  real_T c22_p_y;
  int32_T c22_i63;
  real_T c22_q_y[6];
  int32_T c22_i64;
  real_T c22_j_b[6];
  int32_T c22_i65;
  real_T c22_r_y[6];
  real_T c22_k_a;
  real_T c22_f_c;
  int32_T c22_i66;
  real_T c22_l_a[6];
  real_T c22_k_b;
  int32_T c22_i67;
  real_T c22_s_y[6];
  real_T c22_m_a;
  real_T c22_g_c;
  int32_T c22_i68;
  real_T c22_c_A[6];
  real_T c22_c_B;
  int32_T c22_i69;
  real_T c22_k_x[6];
  real_T c22_t_y;
  int32_T c22_i70;
  real_T c22_l_x[6];
  real_T c22_u_y;
  int32_T c22_i71;
  real_T c22_m_x[6];
  real_T c22_v_y;
  int32_T c22_i72;
  real_T c22_w_y[6];
  int32_T c22_i73;
  real_T c22_l_b[6];
  int32_T c22_i74;
  real_T c22_x_y[6];
  real_T c22_n_a;
  real_T c22_h_c;
  int32_T c22_i75;
  real_T c22_o_a[6];
  real_T c22_m_b;
  int32_T c22_i76;
  real_T c22_y_y[6];
  real_T c22_p_a;
  real_T c22_i_c;
  int32_T c22_i77;
  real_T c22_d_A[6];
  real_T c22_d_B;
  int32_T c22_i78;
  real_T c22_n_x[6];
  real_T c22_ab_y;
  int32_T c22_i79;
  real_T c22_o_x[6];
  real_T c22_bb_y;
  int32_T c22_i80;
  real_T c22_p_x[6];
  real_T c22_cb_y;
  int32_T c22_i81;
  real_T c22_db_y[6];
  int32_T c22_i82;
  int32_T c22_i83;
  real_T c22_n_b[6];
  int32_T c22_i84;
  real_T c22_eb_y[6];
  int32_T c22_i85;
  real_T c22_q_a[6];
  real_T c22_o_b;
  int32_T c22_i86;
  real_T c22_fb_y[6];
  real_T c22_r_a;
  real_T c22_j_c;
  int32_T c22_i87;
  real_T c22_e_A[6];
  real_T c22_e_B;
  int32_T c22_i88;
  real_T c22_q_x[6];
  real_T c22_gb_y;
  int32_T c22_i89;
  real_T c22_r_x[6];
  real_T c22_hb_y;
  int32_T c22_i90;
  real_T c22_s_x[6];
  real_T c22_ib_y;
  int32_T c22_i91;
  real_T c22_jb_y[6];
  int32_T c22_i92;
  real_T c22_p_b[6];
  int32_T c22_i93;
  real_T c22_kb_y[6];
  real_T c22_s_a;
  real_T c22_k_c;
  int32_T c22_i94;
  real_T c22_t_a[6];
  real_T c22_q_b;
  int32_T c22_i95;
  real_T c22_lb_y[6];
  real_T c22_u_a;
  real_T c22_l_c;
  int32_T c22_i96;
  real_T c22_f_A[6];
  real_T c22_f_B;
  int32_T c22_i97;
  real_T c22_t_x[6];
  real_T c22_mb_y;
  int32_T c22_i98;
  real_T c22_u_x[6];
  real_T c22_nb_y;
  int32_T c22_i99;
  real_T c22_v_x[6];
  real_T c22_ob_y;
  int32_T c22_i100;
  real_T c22_pb_y[6];
  int32_T c22_i101;
  real_T c22_r_b[6];
  int32_T c22_i102;
  real_T c22_qb_y[6];
  real_T c22_v_a;
  real_T c22_m_c;
  int32_T c22_i103;
  real_T c22_w_a[6];
  real_T c22_s_b;
  int32_T c22_i104;
  real_T c22_rb_y[6];
  real_T c22_x_a;
  real_T c22_n_c;
  int32_T c22_i105;
  real_T c22_g_A[6];
  real_T c22_g_B;
  int32_T c22_i106;
  real_T c22_w_x[6];
  real_T c22_sb_y;
  int32_T c22_i107;
  real_T c22_x_x[6];
  real_T c22_tb_y;
  int32_T c22_i108;
  real_T c22_y_x[6];
  real_T c22_ub_y;
  int32_T c22_i109;
  real_T c22_vb_y[6];
  int32_T c22_i110;
  int32_T c22_i111;
  int32_T c22_i112;
  int32_T c22_i113;
  int32_T c22_i114;
  int32_T c22_i115;
  int32_T c22_i116;
  int32_T c22_i117;
  int32_T c22_i118;
  int32_T c22_i119;
  int32_T c22_i120;
  int32_T c22_i121;
  int32_T c22_i122;
  int32_T c22_i123;
  int32_T c22_i124;
  int32_T c22_i125;
  int32_T c22_i126;
  real_T *c22_b_tf;
  real_T *c22_b_tc;
  real_T *c22_b_conf;
  real_T *c22_b_t0;
  real_T *c22_b_enable;
  real_T *c22_b_confn;
  real_T *c22_b_t0n;
  real_T *c22_b_robot_mov;
  real_T (*c22_b_q_cmd)[6];
  real_T (*c22_b_q_dot)[6];
  real_T (*c22_b_q_dub_dot)[6];
  real_T (*c22_b_q0n)[6];
  real_T (*c22_b_q0)[6];
  real_T (*c22_b_q_curr)[6];
  real_T (*c22_b_q_des)[6];
  c22_b_robot_mov = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c22_b_enable = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c22_b_q0 = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 6);
  c22_b_q0n = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 6);
  c22_b_t0n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c22_b_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c22_b_confn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c22_b_conf = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c22_b_q_dub_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c22_b_q_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c22_b_tc = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c22_b_tf = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c22_b_q_curr = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c22_b_q_des = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c22_b_q_cmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,4);
  for (c22_i19 = 0; c22_i19 < 6; c22_i19 = c22_i19 + 1) {
    c22_hoistedGlobal[c22_i19] = (*c22_b_q_des)[c22_i19];
  }

  for (c22_i20 = 0; c22_i20 < 6; c22_i20 = c22_i20 + 1) {
    c22_b_hoistedGlobal[c22_i20] = (*c22_b_q_curr)[c22_i20];
  }

  c22_c_hoistedGlobal = *c22_b_tf;
  c22_d_hoistedGlobal = *c22_b_tc;
  c22_e_hoistedGlobal = *c22_b_conf;
  c22_f_hoistedGlobal = *c22_b_t0;
  for (c22_i21 = 0; c22_i21 < 6; c22_i21 = c22_i21 + 1) {
    c22_g_hoistedGlobal[c22_i21] = (*c22_b_q0)[c22_i21];
  }

  c22_h_hoistedGlobal = *c22_b_enable;
  for (c22_i22 = 0; c22_i22 < 6; c22_i22 = c22_i22 + 1) {
    c22_q_des[c22_i22] = c22_hoistedGlobal[c22_i22];
  }

  for (c22_i23 = 0; c22_i23 < 6; c22_i23 = c22_i23 + 1) {
    c22_q_curr[c22_i23] = c22_b_hoistedGlobal[c22_i23];
  }

  c22_tf = c22_c_hoistedGlobal;
  c22_tc = c22_d_hoistedGlobal;
  c22_conf = c22_e_hoistedGlobal;
  c22_t0 = c22_f_hoistedGlobal;
  for (c22_i24 = 0; c22_i24 < 6; c22_i24 = c22_i24 + 1) {
    c22_q0[c22_i24] = c22_g_hoistedGlobal[c22_i24];
  }

  c22_enable = c22_h_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 25U, 25U, c22_sv0, c22_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c22_n, c22_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c22_eta, c22_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c22_a0, c22_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c22_a4, c22_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c22_a3, c22_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c22_a5, c22_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c22_t, c22_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c22_tau, c22_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c22_nargin, c22_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c22_nargout, c22_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c22_q_des, c22_b_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c22_q_curr, c22_b_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c22_tf, c22_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c22_tc, c22_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c22_conf, c22_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c22_t0, c22_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c22_q0, c22_b_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c22_enable, c22_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c22_q_cmd, c22_b_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c22_q_dot, c22_b_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c22_q_dub_dot, c22_b_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c22_confn, c22_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c22_t0n, c22_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c22_q0n, c22_b_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c22_robot_mov, c22_sf_marshall, 24U);
  CV_EML_FCN(0, 0);

  /*  number of actuators */
  _SFD_EML_CALL(0,3);
  c22_n = 6.0;
  _SFD_EML_CALL(0,5);
  c22_robot_mov = 0.0;
  _SFD_EML_CALL(0,6);
  for (c22_i25 = 0; c22_i25 < 6; c22_i25 = c22_i25 + 1) {
    c22_eta[c22_i25] = c22_q_des[c22_i25] - c22_q0[c22_i25];
  }

  _SFD_EML_CALL(0,8);
  if (CV_EML_IF(0, 0, c22_enable != 0.0) != 0.0) {
    _SFD_EML_CALL(0,9);
    for (c22_i26 = 0; c22_i26 < 6; c22_i26 = c22_i26 + 1) {
      c22_a[c22_i26] = c22_eta[c22_i26];
    }

    for (c22_i27 = 0; c22_i27 < 6; c22_i27 = c22_i27 + 1) {
      c22_b[c22_i27] = c22_eta[c22_i27];
    }

    c22_eml_scalar_eg(chartInstance);
    for (c22_i28 = 0; c22_i28 < 6; c22_i28 = c22_i28 + 1) {
      c22_x[c22_i28] = c22_a[c22_i28];
    }

    for (c22_i29 = 0; c22_i29 < 6; c22_i29 = c22_i29 + 1) {
      c22_y[c22_i29] = c22_b[c22_i29];
    }

    for (c22_i30 = 0; c22_i30 < 6; c22_i30 = c22_i30 + 1) {
      c22_b_x[c22_i30] = c22_x[c22_i30];
    }

    for (c22_i31 = 0; c22_i31 < 6; c22_i31 = c22_i31 + 1) {
      c22_b_y[c22_i31] = c22_y[c22_i31];
    }

    for (c22_i32 = 0; c22_i32 < 6; c22_i32 = c22_i32 + 1) {
      c22_c_x[c22_i32] = c22_b_x[c22_i32];
    }

    for (c22_i33 = 0; c22_i33 < 6; c22_i33 = c22_i33 + 1) {
      c22_c_y[c22_i33] = c22_b_y[c22_i33];
    }

    for (c22_i34 = 0; c22_i34 < 6; c22_i34 = c22_i34 + 1) {
      c22_d_x[c22_i34] = c22_c_x[c22_i34];
    }

    for (c22_i35 = 0; c22_i35 < 6; c22_i35 = c22_i35 + 1) {
      c22_d_y[c22_i35] = c22_c_y[c22_i35];
    }

    c22_e_y = c22_ceval_xdot(chartInstance, 6, c22_d_x, 1, 1, c22_d_y, 1, 1);
    if (CV_EML_IF(0, 1, c22_e_y > 0.0)) {
      /*  conf = 0 means that the 5th order poly */
      /*  is not configured for the desired trajectory. */
      /*  Therefore, the block is initialized. */
      _SFD_EML_CALL(0,13);
      if (CV_EML_IF(0, 2, c22_conf == 0.0)) {
        _SFD_EML_CALL(0,14);
        for (c22_i36 = 0; c22_i36 < 6; c22_i36 = c22_i36 + 1) {
          c22_q0n[c22_i36] = c22_q0[c22_i36];
        }

        _SFD_EML_CALL(0,15);
        c22_t0n = c22_tc;
        _SFD_EML_CALL(0,16);
        c22_confn = 1.0;
        _SFD_EML_CALL(0,17);
        for (c22_i37 = 0; c22_i37 < 6; c22_i37 = c22_i37 + 1) {
          c22_q_cmd[c22_i37] = c22_q0[c22_i37];
        }

        _SFD_EML_CALL(0,18);
        for (c22_i38 = 0; c22_i38 < 6; c22_i38 = c22_i38 + 1) {
          c22_q_dot[c22_i38] = 0.0;
        }

        _SFD_EML_CALL(0,19);
        for (c22_i39 = 0; c22_i39 < 6; c22_i39 = c22_i39 + 1) {
          c22_q_dub_dot[c22_i39] = 0.0;
        }
      } else {
        _SFD_EML_CALL(0,21);
        for (c22_i40 = 0; c22_i40 < 6; c22_i40 = c22_i40 + 1) {
          c22_q0n[c22_i40] = c22_q0[c22_i40];
        }

        _SFD_EML_CALL(0,22);
        c22_t0n = c22_t0;
        _SFD_EML_CALL(0,23);
        c22_confn = c22_conf;

        /*  5th order polynomial */
        _SFD_EML_CALL(0,26);
        for (c22_i41 = 0; c22_i41 < 6; c22_i41 = c22_i41 + 1) {
          c22_a0[c22_i41] = c22_q0[c22_i41];
        }

        _SFD_EML_CALL(0,27);
        for (c22_i42 = 0; c22_i42 < 6; c22_i42 = c22_i42 + 1) {
          c22_b_b[c22_i42] = c22_eta[c22_i42];
        }

        for (c22_i43 = 0; c22_i43 < 6; c22_i43 = c22_i43 + 1) {
          c22_a4[c22_i43] = -15.0 * c22_b_b[c22_i43];
        }

        _SFD_EML_CALL(0,28);
        for (c22_i44 = 0; c22_i44 < 6; c22_i44 = c22_i44 + 1) {
          c22_c_b[c22_i44] = c22_a4[c22_i44];
        }

        for (c22_i45 = 0; c22_i45 < 6; c22_i45 = c22_i45 + 1) {
          c22_a3[c22_i45] = -6.6666666666666663E-001 * c22_c_b[c22_i45];
        }

        _SFD_EML_CALL(0,29);
        for (c22_i46 = 0; c22_i46 < 6; c22_i46 = c22_i46 + 1) {
          c22_d_b[c22_i46] = c22_a4[c22_i46];
        }

        for (c22_i47 = 0; c22_i47 < 6; c22_i47 = c22_i47 + 1) {
          c22_a5[c22_i47] = -0.4 * c22_d_b[c22_i47];
        }

        _SFD_EML_CALL(0,30);
        c22_t = c22_tc - c22_t0;
        _SFD_EML_CALL(0,31);
        c22_A = c22_t;
        c22_B = c22_tf;
        c22_e_x = c22_A;
        c22_f_y = c22_B;
        c22_f_x = c22_e_x;
        c22_g_y = c22_f_y;
        c22_g_x = c22_f_x;
        c22_h_y = c22_g_y;
        c22_tau = c22_g_x / c22_h_y;
        _SFD_EML_CALL(0,33);
        if (CV_EML_IF(0, 3, c22_t < c22_tf)) {
          _SFD_EML_CALL(0,34);
          c22_robot_mov = 1.0;
          _SFD_EML_CALL(0,35);
          c22_b_a = c22_tau;
          c22_c = c22_power(chartInstance, c22_b_a, 3.0);
          for (c22_i48 = 0; c22_i48 < 6; c22_i48 = c22_i48 + 1) {
            c22_c_a[c22_i48] = c22_a3[c22_i48];
          }

          c22_e_b = c22_c;
          for (c22_i49 = 0; c22_i49 < 6; c22_i49 = c22_i49 + 1) {
            c22_i_y[c22_i49] = c22_c_a[c22_i49] * c22_e_b;
          }

          c22_d_a = c22_tau;
          c22_b_c = c22_power(chartInstance, c22_d_a, 4.0);
          for (c22_i50 = 0; c22_i50 < 6; c22_i50 = c22_i50 + 1) {
            c22_e_a[c22_i50] = c22_a4[c22_i50];
          }

          c22_f_b = c22_b_c;
          for (c22_i51 = 0; c22_i51 < 6; c22_i51 = c22_i51 + 1) {
            c22_j_y[c22_i51] = c22_e_a[c22_i51] * c22_f_b;
          }

          c22_f_a = c22_tau;
          c22_c_c = c22_power(chartInstance, c22_f_a, 5.0);
          for (c22_i52 = 0; c22_i52 < 6; c22_i52 = c22_i52 + 1) {
            c22_g_a[c22_i52] = c22_a5[c22_i52];
          }

          c22_g_b = c22_c_c;
          for (c22_i53 = 0; c22_i53 < 6; c22_i53 = c22_i53 + 1) {
            c22_k_y[c22_i53] = c22_g_a[c22_i53] * c22_g_b;
          }

          for (c22_i54 = 0; c22_i54 < 6; c22_i54 = c22_i54 + 1) {
            c22_q_cmd[c22_i54] = ((c22_a0[c22_i54] + c22_i_y[c22_i54]) +
                                  c22_j_y[c22_i54]) + c22_k_y[c22_i54];
          }

          _SFD_EML_CALL(0,36);
          for (c22_i55 = 0; c22_i55 < 6; c22_i55 = c22_i55 + 1) {
            c22_h_b[c22_i55] = c22_a3[c22_i55];
          }

          for (c22_i56 = 0; c22_i56 < 6; c22_i56 = c22_i56 + 1) {
            c22_l_y[c22_i56] = 3.0 * c22_h_b[c22_i56];
          }

          c22_h_a = c22_t;
          c22_d_c = c22_power(chartInstance, c22_h_a, 2.0);
          for (c22_i57 = 0; c22_i57 < 6; c22_i57 = c22_i57 + 1) {
            c22_i_a[c22_i57] = c22_l_y[c22_i57];
          }

          c22_i_b = c22_d_c;
          for (c22_i58 = 0; c22_i58 < 6; c22_i58 = c22_i58 + 1) {
            c22_m_y[c22_i58] = c22_i_a[c22_i58] * c22_i_b;
          }

          c22_j_a = c22_tf;
          c22_e_c = c22_power(chartInstance, c22_j_a, 3.0);
          for (c22_i59 = 0; c22_i59 < 6; c22_i59 = c22_i59 + 1) {
            c22_b_A[c22_i59] = c22_m_y[c22_i59];
          }

          c22_b_B = c22_e_c;
          for (c22_i60 = 0; c22_i60 < 6; c22_i60 = c22_i60 + 1) {
            c22_h_x[c22_i60] = c22_b_A[c22_i60];
          }

          c22_n_y = c22_b_B;
          for (c22_i61 = 0; c22_i61 < 6; c22_i61 = c22_i61 + 1) {
            c22_i_x[c22_i61] = c22_h_x[c22_i61];
          }

          c22_o_y = c22_n_y;
          for (c22_i62 = 0; c22_i62 < 6; c22_i62 = c22_i62 + 1) {
            c22_j_x[c22_i62] = c22_i_x[c22_i62];
          }

          c22_p_y = c22_o_y;
          for (c22_i63 = 0; c22_i63 < 6; c22_i63 = c22_i63 + 1) {
            c22_q_y[c22_i63] = c22_j_x[c22_i63] / c22_p_y;
          }

          for (c22_i64 = 0; c22_i64 < 6; c22_i64 = c22_i64 + 1) {
            c22_j_b[c22_i64] = c22_a4[c22_i64];
          }

          for (c22_i65 = 0; c22_i65 < 6; c22_i65 = c22_i65 + 1) {
            c22_r_y[c22_i65] = 4.0 * c22_j_b[c22_i65];
          }

          c22_k_a = c22_t;
          c22_f_c = c22_power(chartInstance, c22_k_a, 3.0);
          for (c22_i66 = 0; c22_i66 < 6; c22_i66 = c22_i66 + 1) {
            c22_l_a[c22_i66] = c22_r_y[c22_i66];
          }

          c22_k_b = c22_f_c;
          for (c22_i67 = 0; c22_i67 < 6; c22_i67 = c22_i67 + 1) {
            c22_s_y[c22_i67] = c22_l_a[c22_i67] * c22_k_b;
          }

          c22_m_a = c22_tf;
          c22_g_c = c22_power(chartInstance, c22_m_a, 4.0);
          for (c22_i68 = 0; c22_i68 < 6; c22_i68 = c22_i68 + 1) {
            c22_c_A[c22_i68] = c22_s_y[c22_i68];
          }

          c22_c_B = c22_g_c;
          for (c22_i69 = 0; c22_i69 < 6; c22_i69 = c22_i69 + 1) {
            c22_k_x[c22_i69] = c22_c_A[c22_i69];
          }

          c22_t_y = c22_c_B;
          for (c22_i70 = 0; c22_i70 < 6; c22_i70 = c22_i70 + 1) {
            c22_l_x[c22_i70] = c22_k_x[c22_i70];
          }

          c22_u_y = c22_t_y;
          for (c22_i71 = 0; c22_i71 < 6; c22_i71 = c22_i71 + 1) {
            c22_m_x[c22_i71] = c22_l_x[c22_i71];
          }

          c22_v_y = c22_u_y;
          for (c22_i72 = 0; c22_i72 < 6; c22_i72 = c22_i72 + 1) {
            c22_w_y[c22_i72] = c22_m_x[c22_i72] / c22_v_y;
          }

          for (c22_i73 = 0; c22_i73 < 6; c22_i73 = c22_i73 + 1) {
            c22_l_b[c22_i73] = c22_a5[c22_i73];
          }

          for (c22_i74 = 0; c22_i74 < 6; c22_i74 = c22_i74 + 1) {
            c22_x_y[c22_i74] = 5.0 * c22_l_b[c22_i74];
          }

          c22_n_a = c22_t;
          c22_h_c = c22_power(chartInstance, c22_n_a, 4.0);
          for (c22_i75 = 0; c22_i75 < 6; c22_i75 = c22_i75 + 1) {
            c22_o_a[c22_i75] = c22_x_y[c22_i75];
          }

          c22_m_b = c22_h_c;
          for (c22_i76 = 0; c22_i76 < 6; c22_i76 = c22_i76 + 1) {
            c22_y_y[c22_i76] = c22_o_a[c22_i76] * c22_m_b;
          }

          c22_p_a = c22_tf;
          c22_i_c = c22_power(chartInstance, c22_p_a, 5.0);
          for (c22_i77 = 0; c22_i77 < 6; c22_i77 = c22_i77 + 1) {
            c22_d_A[c22_i77] = c22_y_y[c22_i77];
          }

          c22_d_B = c22_i_c;
          for (c22_i78 = 0; c22_i78 < 6; c22_i78 = c22_i78 + 1) {
            c22_n_x[c22_i78] = c22_d_A[c22_i78];
          }

          c22_ab_y = c22_d_B;
          for (c22_i79 = 0; c22_i79 < 6; c22_i79 = c22_i79 + 1) {
            c22_o_x[c22_i79] = c22_n_x[c22_i79];
          }

          c22_bb_y = c22_ab_y;
          for (c22_i80 = 0; c22_i80 < 6; c22_i80 = c22_i80 + 1) {
            c22_p_x[c22_i80] = c22_o_x[c22_i80];
          }

          c22_cb_y = c22_bb_y;
          for (c22_i81 = 0; c22_i81 < 6; c22_i81 = c22_i81 + 1) {
            c22_db_y[c22_i81] = c22_p_x[c22_i81] / c22_cb_y;
          }

          for (c22_i82 = 0; c22_i82 < 6; c22_i82 = c22_i82 + 1) {
            c22_q_dot[c22_i82] = (c22_q_y[c22_i82] + c22_w_y[c22_i82]) +
              c22_db_y[c22_i82];
          }

          _SFD_EML_CALL(0,37);
          for (c22_i83 = 0; c22_i83 < 6; c22_i83 = c22_i83 + 1) {
            c22_n_b[c22_i83] = c22_a3[c22_i83];
          }

          for (c22_i84 = 0; c22_i84 < 6; c22_i84 = c22_i84 + 1) {
            c22_eb_y[c22_i84] = 6.0 * c22_n_b[c22_i84];
          }

          for (c22_i85 = 0; c22_i85 < 6; c22_i85 = c22_i85 + 1) {
            c22_q_a[c22_i85] = c22_eb_y[c22_i85];
          }

          c22_o_b = c22_t;
          for (c22_i86 = 0; c22_i86 < 6; c22_i86 = c22_i86 + 1) {
            c22_fb_y[c22_i86] = c22_q_a[c22_i86] * c22_o_b;
          }

          c22_r_a = c22_tf;
          c22_j_c = c22_power(chartInstance, c22_r_a, 3.0);
          for (c22_i87 = 0; c22_i87 < 6; c22_i87 = c22_i87 + 1) {
            c22_e_A[c22_i87] = c22_fb_y[c22_i87];
          }

          c22_e_B = c22_j_c;
          for (c22_i88 = 0; c22_i88 < 6; c22_i88 = c22_i88 + 1) {
            c22_q_x[c22_i88] = c22_e_A[c22_i88];
          }

          c22_gb_y = c22_e_B;
          for (c22_i89 = 0; c22_i89 < 6; c22_i89 = c22_i89 + 1) {
            c22_r_x[c22_i89] = c22_q_x[c22_i89];
          }

          c22_hb_y = c22_gb_y;
          for (c22_i90 = 0; c22_i90 < 6; c22_i90 = c22_i90 + 1) {
            c22_s_x[c22_i90] = c22_r_x[c22_i90];
          }

          c22_ib_y = c22_hb_y;
          for (c22_i91 = 0; c22_i91 < 6; c22_i91 = c22_i91 + 1) {
            c22_jb_y[c22_i91] = c22_s_x[c22_i91] / c22_ib_y;
          }

          for (c22_i92 = 0; c22_i92 < 6; c22_i92 = c22_i92 + 1) {
            c22_p_b[c22_i92] = c22_a4[c22_i92];
          }

          for (c22_i93 = 0; c22_i93 < 6; c22_i93 = c22_i93 + 1) {
            c22_kb_y[c22_i93] = 12.0 * c22_p_b[c22_i93];
          }

          c22_s_a = c22_t;
          c22_k_c = c22_power(chartInstance, c22_s_a, 2.0);
          for (c22_i94 = 0; c22_i94 < 6; c22_i94 = c22_i94 + 1) {
            c22_t_a[c22_i94] = c22_kb_y[c22_i94];
          }

          c22_q_b = c22_k_c;
          for (c22_i95 = 0; c22_i95 < 6; c22_i95 = c22_i95 + 1) {
            c22_lb_y[c22_i95] = c22_t_a[c22_i95] * c22_q_b;
          }

          c22_u_a = c22_tf;
          c22_l_c = c22_power(chartInstance, c22_u_a, 4.0);
          for (c22_i96 = 0; c22_i96 < 6; c22_i96 = c22_i96 + 1) {
            c22_f_A[c22_i96] = c22_lb_y[c22_i96];
          }

          c22_f_B = c22_l_c;
          for (c22_i97 = 0; c22_i97 < 6; c22_i97 = c22_i97 + 1) {
            c22_t_x[c22_i97] = c22_f_A[c22_i97];
          }

          c22_mb_y = c22_f_B;
          for (c22_i98 = 0; c22_i98 < 6; c22_i98 = c22_i98 + 1) {
            c22_u_x[c22_i98] = c22_t_x[c22_i98];
          }

          c22_nb_y = c22_mb_y;
          for (c22_i99 = 0; c22_i99 < 6; c22_i99 = c22_i99 + 1) {
            c22_v_x[c22_i99] = c22_u_x[c22_i99];
          }

          c22_ob_y = c22_nb_y;
          for (c22_i100 = 0; c22_i100 < 6; c22_i100 = c22_i100 + 1) {
            c22_pb_y[c22_i100] = c22_v_x[c22_i100] / c22_ob_y;
          }

          for (c22_i101 = 0; c22_i101 < 6; c22_i101 = c22_i101 + 1) {
            c22_r_b[c22_i101] = c22_a5[c22_i101];
          }

          for (c22_i102 = 0; c22_i102 < 6; c22_i102 = c22_i102 + 1) {
            c22_qb_y[c22_i102] = 20.0 * c22_r_b[c22_i102];
          }

          c22_v_a = c22_t;
          c22_m_c = c22_power(chartInstance, c22_v_a, 3.0);
          for (c22_i103 = 0; c22_i103 < 6; c22_i103 = c22_i103 + 1) {
            c22_w_a[c22_i103] = c22_qb_y[c22_i103];
          }

          c22_s_b = c22_m_c;
          for (c22_i104 = 0; c22_i104 < 6; c22_i104 = c22_i104 + 1) {
            c22_rb_y[c22_i104] = c22_w_a[c22_i104] * c22_s_b;
          }

          c22_x_a = c22_tf;
          c22_n_c = c22_power(chartInstance, c22_x_a, 5.0);
          for (c22_i105 = 0; c22_i105 < 6; c22_i105 = c22_i105 + 1) {
            c22_g_A[c22_i105] = c22_rb_y[c22_i105];
          }

          c22_g_B = c22_n_c;
          for (c22_i106 = 0; c22_i106 < 6; c22_i106 = c22_i106 + 1) {
            c22_w_x[c22_i106] = c22_g_A[c22_i106];
          }

          c22_sb_y = c22_g_B;
          for (c22_i107 = 0; c22_i107 < 6; c22_i107 = c22_i107 + 1) {
            c22_x_x[c22_i107] = c22_w_x[c22_i107];
          }

          c22_tb_y = c22_sb_y;
          for (c22_i108 = 0; c22_i108 < 6; c22_i108 = c22_i108 + 1) {
            c22_y_x[c22_i108] = c22_x_x[c22_i108];
          }

          c22_ub_y = c22_tb_y;
          for (c22_i109 = 0; c22_i109 < 6; c22_i109 = c22_i109 + 1) {
            c22_vb_y[c22_i109] = c22_y_x[c22_i109] / c22_ub_y;
          }

          for (c22_i110 = 0; c22_i110 < 6; c22_i110 = c22_i110 + 1) {
            c22_q_dub_dot[c22_i110] = (c22_jb_y[c22_i110] + c22_pb_y[c22_i110])
              + c22_vb_y[c22_i110];
          }
        } else {
          _SFD_EML_CALL(0,39);
          for (c22_i111 = 0; c22_i111 < 6; c22_i111 = c22_i111 + 1) {
            c22_q_cmd[c22_i111] = c22_q_des[c22_i111];
          }

          _SFD_EML_CALL(0,40);
          for (c22_i112 = 0; c22_i112 < 6; c22_i112 = c22_i112 + 1) {
            c22_q_dot[c22_i112] = 0.0;
          }

          _SFD_EML_CALL(0,41);
          for (c22_i113 = 0; c22_i113 < 6; c22_i113 = c22_i113 + 1) {
            c22_q_dub_dot[c22_i113] = 0.0;
          }

          _SFD_EML_CALL(0,42);
          for (c22_i114 = 0; c22_i114 < 6; c22_i114 = c22_i114 + 1) {
            c22_q0n[c22_i114] = c22_q_des[c22_i114];
          }
        }
      }
    } else {
      _SFD_EML_CALL(0,46);
      for (c22_i115 = 0; c22_i115 < 6; c22_i115 = c22_i115 + 1) {
        c22_q_cmd[c22_i115] = c22_q_des[c22_i115];
      }

      _SFD_EML_CALL(0,47);
      for (c22_i116 = 0; c22_i116 < 6; c22_i116 = c22_i116 + 1) {
        c22_q_dot[c22_i116] = 0.0;
      }

      _SFD_EML_CALL(0,48);
      for (c22_i117 = 0; c22_i117 < 6; c22_i117 = c22_i117 + 1) {
        c22_q_dub_dot[c22_i117] = 0.0;
      }

      _SFD_EML_CALL(0,49);
      c22_confn = 0.0;
      _SFD_EML_CALL(0,50);
      for (c22_i118 = 0; c22_i118 < 6; c22_i118 = c22_i118 + 1) {
        c22_q0n[c22_i118] = c22_q0[c22_i118];
      }

      _SFD_EML_CALL(0,51);
      c22_t0n = c22_t0;
    }
  } else {
    /*  Configuration space is not used (pdot = 0). */
    _SFD_EML_CALL(0,55);
    for (c22_i119 = 0; c22_i119 < 6; c22_i119 = c22_i119 + 1) {
      c22_q_cmd[c22_i119] = c22_q_des[c22_i119];
    }

    _SFD_EML_CALL(0,56);
    for (c22_i120 = 0; c22_i120 < 6; c22_i120 = c22_i120 + 1) {
      c22_q_dot[c22_i120] = 0.0;
    }

    _SFD_EML_CALL(0,57);
    for (c22_i121 = 0; c22_i121 < 6; c22_i121 = c22_i121 + 1) {
      c22_q_dub_dot[c22_i121] = 0.0;
    }

    /*  However we do want to record the current */
    _SFD_EML_CALL(0,58);
    c22_confn = 0.0;

    /*  position in order to be ready as soon */
    _SFD_EML_CALL(0,59);
    c22_t0n = c22_tc;

    /*  as the enable becomes 1. */
    _SFD_EML_CALL(0,60);
    for (c22_i122 = 0; c22_i122 < 6; c22_i122 = c22_i122 + 1) {
      c22_q0n[c22_i122] = c22_q_curr[c22_i122];
    }
  }

  /* ------------------------------------------------------------------------ */
  _SFD_EML_CALL(0,-60);
  sf_debug_symbol_scope_pop();
  for (c22_i123 = 0; c22_i123 < 6; c22_i123 = c22_i123 + 1) {
    (*c22_b_q_cmd)[c22_i123] = c22_q_cmd[c22_i123];
  }

  for (c22_i124 = 0; c22_i124 < 6; c22_i124 = c22_i124 + 1) {
    (*c22_b_q_dot)[c22_i124] = c22_q_dot[c22_i124];
  }

  for (c22_i125 = 0; c22_i125 < 6; c22_i125 = c22_i125 + 1) {
    (*c22_b_q_dub_dot)[c22_i125] = c22_q_dub_dot[c22_i125];
  }

  *c22_b_confn = c22_confn;
  *c22_b_t0n = c22_t0n;
  for (c22_i126 = 0; c22_i126 < 6; c22_i126 = c22_i126 + 1) {
    (*c22_b_q0n)[c22_i126] = c22_q0n[c22_i126];
  }

  *c22_b_robot_mov = c22_robot_mov;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber)
{
}

static void c22_eml_scalar_eg(SFc22_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c22_ceval_xdot(SFc22_twa_parallelInstanceStruct *chartInstance,
  int32_T c22_n, real_T c22_x[6], int32_T c22_ix0,
  int32_T c22_incx, real_T c22_y[6], int32_T c22_iy0, int32_T c22_incy)
{
  real_T c22_d;
  c22_d = 0.0;
  if ((real_T)c22_n > 0.0) {
    return ddot32(&c22_n, &c22_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c22_ix0), 1, 6, 1, 0) - 1], &
                  c22_incx, &c22_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c22_iy0), 1, 6, 1, 0) - 1], &c22_incy);
  }

  return c22_d;
}

static real_T c22_power(SFc22_twa_parallelInstanceStruct *chartInstance, real_T
  c22_a, real_T c22_b)
{
  real_T c22_ak;
  real_T c22_bk;
  real_T c22_x;
  real_T c22_b_x;
  c22_ak = c22_a;
  c22_bk = c22_b;
  if (c22_ak < 0.0) {
    c22_x = c22_bk;
    c22_b_x = c22_x;
    c22_b_x = muDoubleScalarFloor(c22_b_x);
    if (c22_b_x != c22_bk) {
      c22_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c22_ak, c22_bk);
}

static void c22_eml_error(SFc22_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c22_i127;
  static char_T c22_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c22_u[32];
  const mxArray *c22_y = NULL;
  int32_T c22_i128;
  static char_T c22_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
    'r', 'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c22_b_u[102];
  const mxArray *c22_b_y = NULL;
  for (c22_i127 = 0; c22_i127 < 32; c22_i127 = c22_i127 + 1) {
    c22_u[c22_i127] = c22_cv0[c22_i127];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c22_i128 = 0; c22_i128 < 102; c22_i128 = c22_i128 + 1) {
    c22_b_u[c22_i128] = c22_cv1[c22_i128];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c22_y, 14, c22_b_y);
}

static const mxArray *c22_sf_marshall(void *chartInstanceVoid, void *c22_u)
{
  const mxArray *c22_y = NULL;
  real_T c22_b_u;
  const mxArray *c22_b_y = NULL;
  SFc22_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc22_twa_parallelInstanceStruct *)chartInstanceVoid;
  c22_y = NULL;
  c22_b_u = *((real_T *)c22_u);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

static const mxArray *c22_b_sf_marshall(void *chartInstanceVoid, void *c22_u)
{
  const mxArray *c22_y = NULL;
  int32_T c22_i129;
  real_T c22_b_u[6];
  const mxArray *c22_b_y = NULL;
  SFc22_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc22_twa_parallelInstanceStruct *)chartInstanceVoid;
  c22_y = NULL;
  for (c22_i129 = 0; c22_i129 < 6; c22_i129 = c22_i129 + 1) {
    c22_b_u[c22_i129] = (*((real_T (*)[6])c22_u))[c22_i129];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

const mxArray *sf_c22_twa_parallel_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_ResolvedFunctionInfo c22_info[50];
  const mxArray *c22_m0 = NULL;
  int32_T c22_i130;
  c22_ResolvedFunctionInfo *c22_r0;
  c22_nameCaptureInfo = NULL;
  c22_info_helper(c22_info);
  sf_mex_assign(&c22_m0, sf_mex_createstruct("nameCaptureInfo", 1, 50));
  for (c22_i130 = 0; c22_i130 < 50; c22_i130 = c22_i130 + 1) {
    c22_r0 = &c22_info[c22_i130];
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c22_r0->context)), "context"
                    , "nameCaptureInfo", c22_i130);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c22_r0->name)), "name",
                    "nameCaptureInfo", c22_i130);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo",
      c22_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c22_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c22_i130);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c22_r0->resolved)),
                    "resolved", "nameCaptureInfo", c22_i130);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", &c22_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c22_i130);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", &c22_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c22_i130);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", &c22_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c22_i130);
  }

  sf_mex_assign(&c22_nameCaptureInfo, c22_m0);
  return c22_nameCaptureInfo;
}

static void c22_info_helper(c22_ResolvedFunctionInfo c22_info[50])
{
  c22_info[0].context = "";
  c22_info[0].name = "size";
  c22_info[0].dominantType = "double";
  c22_info[0].resolved = "[B]size";
  c22_info[0].fileLength = 0U;
  c22_info[0].fileTime1 = 0U;
  c22_info[0].fileTime2 = 0U;
  c22_info[1].context = "";
  c22_info[1].name = "minus";
  c22_info[1].dominantType = "double";
  c22_info[1].resolved = "[B]minus";
  c22_info[1].fileLength = 0U;
  c22_info[1].fileTime1 = 0U;
  c22_info[1].fileTime2 = 0U;
  c22_info[2].context = "";
  c22_info[2].name = "ctranspose";
  c22_info[2].dominantType = "double";
  c22_info[2].resolved = "[B]ctranspose";
  c22_info[2].fileLength = 0U;
  c22_info[2].fileTime1 = 0U;
  c22_info[2].fileTime2 = 0U;
  c22_info[3].context = "";
  c22_info[3].name = "mtimes";
  c22_info[3].dominantType = "double";
  c22_info[3].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[3].fileLength = 3425U;
  c22_info[3].fileTime1 = 1250697966U;
  c22_info[3].fileTime2 = 0U;
  c22_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[4].name = "nargin";
  c22_info[4].dominantType = "";
  c22_info[4].resolved = "[B]nargin";
  c22_info[4].fileLength = 0U;
  c22_info[4].fileTime1 = 0U;
  c22_info[4].fileTime2 = 0U;
  c22_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[5].name = "gt";
  c22_info[5].dominantType = "double";
  c22_info[5].resolved = "[B]gt";
  c22_info[5].fileLength = 0U;
  c22_info[5].fileTime1 = 0U;
  c22_info[5].fileTime2 = 0U;
  c22_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[6].name = "isa";
  c22_info[6].dominantType = "double";
  c22_info[6].resolved = "[B]isa";
  c22_info[6].fileLength = 0U;
  c22_info[6].fileTime1 = 0U;
  c22_info[6].fileTime2 = 0U;
  c22_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[7].name = "isinteger";
  c22_info[7].dominantType = "double";
  c22_info[7].resolved = "[B]isinteger";
  c22_info[7].fileLength = 0U;
  c22_info[7].fileTime1 = 0U;
  c22_info[7].fileTime2 = 0U;
  c22_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[8].name = "isscalar";
  c22_info[8].dominantType = "double";
  c22_info[8].resolved = "[B]isscalar";
  c22_info[8].fileLength = 0U;
  c22_info[8].fileTime1 = 0U;
  c22_info[8].fileTime2 = 0U;
  c22_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[9].name = "ndims";
  c22_info[9].dominantType = "double";
  c22_info[9].resolved = "[B]ndims";
  c22_info[9].fileLength = 0U;
  c22_info[9].fileTime1 = 0U;
  c22_info[9].fileTime2 = 0U;
  c22_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[10].name = "le";
  c22_info[10].dominantType = "double";
  c22_info[10].resolved = "[B]le";
  c22_info[10].fileLength = 0U;
  c22_info[10].fileTime1 = 0U;
  c22_info[10].fileTime2 = 0U;
  c22_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[11].name = "eq";
  c22_info[11].dominantType = "double";
  c22_info[11].resolved = "[B]eq";
  c22_info[11].fileLength = 0U;
  c22_info[11].fileTime1 = 0U;
  c22_info[11].fileTime2 = 0U;
  c22_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[12].name = "not";
  c22_info[12].dominantType = "logical";
  c22_info[12].resolved = "[B]not";
  c22_info[12].fileLength = 0U;
  c22_info[12].fileTime1 = 0U;
  c22_info[12].fileTime2 = 0U;
  c22_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[13].name = "strcmp";
  c22_info[13].dominantType = "char";
  c22_info[13].resolved = "[B]strcmp";
  c22_info[13].fileLength = 0U;
  c22_info[13].fileTime1 = 0U;
  c22_info[13].fileTime2 = 0U;
  c22_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[14].name = "class";
  c22_info[14].dominantType = "double";
  c22_info[14].resolved = "[B]class";
  c22_info[14].fileLength = 0U;
  c22_info[14].fileTime1 = 0U;
  c22_info[14].fileTime2 = 0U;
  c22_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[15].name = "isreal";
  c22_info[15].dominantType = "double";
  c22_info[15].resolved = "[B]isreal";
  c22_info[15].fileLength = 0U;
  c22_info[15].fileTime1 = 0U;
  c22_info[15].fileTime2 = 0U;
  c22_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[16].name = "ne";
  c22_info[16].dominantType = "logical";
  c22_info[16].resolved = "[B]ne";
  c22_info[16].fileLength = 0U;
  c22_info[16].fileTime1 = 0U;
  c22_info[16].fileTime2 = 0U;
  c22_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[17].name = "eml_index_class";
  c22_info[17].dominantType = "";
  c22_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c22_info[17].fileLength = 909U;
  c22_info[17].fileTime1 = 1192491982U;
  c22_info[17].fileTime2 = 0U;
  c22_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[18].name = "ones";
  c22_info[18].dominantType = "char";
  c22_info[18].resolved = "[B]ones";
  c22_info[18].fileLength = 0U;
  c22_info[18].fileTime1 = 0U;
  c22_info[18].fileTime2 = 0U;
  c22_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[19].name = "cast";
  c22_info[19].dominantType = "double";
  c22_info[19].resolved = "[B]cast";
  c22_info[19].fileLength = 0U;
  c22_info[19].fileTime1 = 0U;
  c22_info[19].fileTime2 = 0U;
  c22_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[20].name = "eml_scalar_eg";
  c22_info[20].dominantType = "double";
  c22_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c22_info[20].fileLength = 3068U;
  c22_info[20].fileTime1 = 1240287210U;
  c22_info[20].fileTime2 = 0U;
  c22_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c22_info[21].name = "false";
  c22_info[21].dominantType = "";
  c22_info[21].resolved = "[B]false";
  c22_info[21].fileLength = 0U;
  c22_info[21].fileTime1 = 0U;
  c22_info[21].fileTime2 = 0U;
  c22_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c22_info[22].name = "isstruct";
  c22_info[22].dominantType = "double";
  c22_info[22].resolved = "[B]isstruct";
  c22_info[22].fileLength = 0U;
  c22_info[22].fileTime1 = 0U;
  c22_info[22].fileTime2 = 0U;
  c22_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c22_info[23].name = "plus";
  c22_info[23].dominantType = "double";
  c22_info[23].resolved = "[B]plus";
  c22_info[23].fileLength = 0U;
  c22_info[23].fileTime1 = 0U;
  c22_info[23].fileTime2 = 0U;
  c22_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[24].name = "isempty";
  c22_info[24].dominantType = "double";
  c22_info[24].resolved = "[B]isempty";
  c22_info[24].fileLength = 0U;
  c22_info[24].fileTime1 = 0U;
  c22_info[24].fileTime2 = 0U;
  c22_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c22_info[25].name = "eml_xdotu";
  c22_info[25].dominantType = "int32";
  c22_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c22_info[25].fileLength = 1453U;
  c22_info[25].fileTime1 = 1209356050U;
  c22_info[25].fileTime2 = 0U;
  c22_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c22_info[26].name = "eml_xdot";
  c22_info[26].dominantType = "int32";
  c22_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c22_info[26].fileLength = 1330U;
  c22_info[26].fileTime1 = 1209356048U;
  c22_info[26].fileTime2 = 0U;
  c22_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c22_info[27].name = "eml_refblas_xdot";
  c22_info[27].dominantType = "int32";
  c22_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c22_info[27].fileLength = 343U;
  c22_info[27].fileTime1 = 1211241242U;
  c22_info[27].fileTime2 = 0U;
  c22_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c22_info[28].name = "eml_refblas_xdotx";
  c22_info[28].dominantType = "int32";
  c22_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c22_info[28].fileLength = 1605U;
  c22_info[28].fileTime1 = 1236282478U;
  c22_info[28].fileTime2 = 0U;
  c22_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c22_info[29].name = "ischar";
  c22_info[29].dominantType = "char";
  c22_info[29].resolved = "[B]ischar";
  c22_info[29].fileLength = 0U;
  c22_info[29].fileTime1 = 0U;
  c22_info[29].fileTime2 = 0U;
  c22_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c22_info[30].name = "isequal";
  c22_info[30].dominantType = "char";
  c22_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c22_info[30].fileLength = 180U;
  c22_info[30].fileTime1 = 1226602470U;
  c22_info[30].fileTime2 = 0U;
  c22_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c22_info[31].name = "eml_isequal_core";
  c22_info[31].dominantType = "char";
  c22_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c22_info[31].fileLength = 4192U;
  c22_info[31].fileTime1 = 1257808582U;
  c22_info[31].fileTime2 = 0U;
  c22_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c22_info[32].name = "ge";
  c22_info[32].dominantType = "double";
  c22_info[32].resolved = "[B]ge";
  c22_info[32].fileLength = 0U;
  c22_info[32].fileTime1 = 0U;
  c22_info[32].fileTime2 = 0U;
  c22_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c22_info[33].name = "islogical";
  c22_info[33].dominantType = "logical";
  c22_info[33].resolved = "[B]islogical";
  c22_info[33].fileLength = 0U;
  c22_info[33].fileTime1 = 0U;
  c22_info[33].fileTime2 = 0U;
  c22_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c22_info[34].name = "isnumeric";
  c22_info[34].dominantType = "char";
  c22_info[34].resolved = "[B]isnumeric";
  c22_info[34].fileLength = 0U;
  c22_info[34].fileTime1 = 0U;
  c22_info[34].fileTime2 = 0U;
  c22_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c22_info[35].name = "true";
  c22_info[35].dominantType = "";
  c22_info[35].resolved = "[B]true";
  c22_info[35].fileLength = 0U;
  c22_info[35].fileTime1 = 0U;
  c22_info[35].fileTime2 = 0U;
  c22_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c22_info[36].name = "lt";
  c22_info[36].dominantType = "int32";
  c22_info[36].resolved = "[B]lt";
  c22_info[36].fileLength = 0U;
  c22_info[36].fileTime1 = 0U;
  c22_info[36].fileTime2 = 0U;
  c22_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c22_info[37].name = "times";
  c22_info[37].dominantType = "double";
  c22_info[37].resolved = "[B]times";
  c22_info[37].fileLength = 0U;
  c22_info[37].fileTime1 = 0U;
  c22_info[37].fileTime2 = 0U;
  c22_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c22_info[38].name = "uminus";
  c22_info[38].dominantType = "int32";
  c22_info[38].resolved = "[B]uminus";
  c22_info[38].fileLength = 0U;
  c22_info[38].fileTime1 = 0U;
  c22_info[38].fileTime2 = 0U;
  c22_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c22_info[39].name = "eml_index_minus";
  c22_info[39].dominantType = "int32";
  c22_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c22_info[39].fileLength = 277U;
  c22_info[39].fileTime1 = 1192491984U;
  c22_info[39].fileTime2 = 0U;
  c22_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c22_info[40].name = "eml_index_plus";
  c22_info[40].dominantType = "int32";
  c22_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c22_info[40].fileLength = 272U;
  c22_info[40].fileTime1 = 1192491984U;
  c22_info[40].fileTime2 = 0U;
  c22_info[41].context = "";
  c22_info[41].name = "zeros";
  c22_info[41].dominantType = "double";
  c22_info[41].resolved = "[B]zeros";
  c22_info[41].fileLength = 0U;
  c22_info[41].fileTime1 = 0U;
  c22_info[41].fileTime2 = 0U;
  c22_info[42].context = "";
  c22_info[42].name = "mrdivide";
  c22_info[42].dominantType = "double";
  c22_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c22_info[42].fileLength = 800U;
  c22_info[42].fileTime1 = 1238459490U;
  c22_info[42].fileTime2 = 0U;
  c22_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c22_info[43].name = "rdivide";
  c22_info[43].dominantType = "double";
  c22_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c22_info[43].fileLength = 403U;
  c22_info[43].fileTime1 = 1244760752U;
  c22_info[43].fileTime2 = 0U;
  c22_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c22_info[44].name = "eml_div";
  c22_info[44].dominantType = "double";
  c22_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c22_info[44].fileLength = 4269U;
  c22_info[44].fileTime1 = 1228119026U;
  c22_info[44].fileTime2 = 0U;
  c22_info[45].context = "";
  c22_info[45].name = "mpower";
  c22_info[45].dominantType = "double";
  c22_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c22_info[45].fileLength = 3710U;
  c22_info[45].fileTime1 = 1238459488U;
  c22_info[45].fileTime2 = 0U;
  c22_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c22_info[46].name = "power";
  c22_info[46].dominantType = "double";
  c22_info[46].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c22_info[46].fileLength = 5380U;
  c22_info[46].fileTime1 = 1228119098U;
  c22_info[46].fileTime2 = 0U;
  c22_info[47].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c22_info[47].name = "eml_scalexp_alloc";
  c22_info[47].dominantType = "double";
  c22_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c22_info[47].fileLength = 808U;
  c22_info[47].fileTime1 = 1230519898U;
  c22_info[47].fileTime2 = 0U;
  c22_info[48].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c22_info[48].name = "eml_scalar_floor";
  c22_info[48].dominantType = "double";
  c22_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c22_info[48].fileLength = 260U;
  c22_info[48].fileTime1 = 1209355990U;
  c22_info[48].fileTime2 = 0U;
  c22_info[49].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c22_info[49].name = "eml_error";
  c22_info[49].dominantType = "char";
  c22_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c22_info[49].fileLength = 315U;
  c22_info[49].fileTime1 = 1213951944U;
  c22_info[49].fileTime2 = 0U;
}

static const mxArray *c22_c_sf_marshall(void *chartInstanceVoid, void *c22_u)
{
  const mxArray *c22_y = NULL;
  boolean_T c22_b_u;
  const mxArray *c22_b_y = NULL;
  SFc22_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc22_twa_parallelInstanceStruct *)chartInstanceVoid;
  c22_y = NULL;
  c22_b_u = *((boolean_T *)c22_u);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c22_y, c22_b_y);
  return c22_y;
}

static real_T c22_emlrt_marshallIn(SFc22_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c22_confn, const char_T *c22_name
  )
{
  real_T c22_y;
  real_T c22_d0;
  sf_mex_import(c22_name, sf_mex_dup(c22_confn), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_confn);
  return c22_y;
}

static void c22_b_emlrt_marshallIn(SFc22_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c22_q0n, const char_T *c22_name,
  real_T c22_y[6])
{
  real_T c22_dv4[6];
  int32_T c22_i131;
  sf_mex_import(c22_name, sf_mex_dup(c22_q0n), &c22_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c22_i131 = 0; c22_i131 < 6; c22_i131 = c22_i131 + 1) {
    c22_y[c22_i131] = c22_dv4[c22_i131];
  }

  sf_mex_destroy(&c22_q0n);
}

static uint8_T c22_c_emlrt_marshallIn(SFc22_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c22_is_active_c22_twa_parallel
  , const char_T *c22_name)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  sf_mex_import(c22_name, sf_mex_dup(c22_is_active_c22_twa_parallel), &c22_u0, 1,
                3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_is_active_c22_twa_parallel);
  return c22_y;
}

static void init_dsm_address_info(SFc22_twa_parallelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c22_twa_parallel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2321536860U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3036903951U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3400964159U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2352847355U);
}

mxArray *sf_c22_twa_parallel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1174409115U);
    pr[1] = (double)(3722762805U);
    pr[2] = (double)(3393023580U);
    pr[3] = (double)(3517638942U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c22_twa_parallel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[12],T\"confn\",},{M[1],M[15],T\"q0n\",},{M[1],M[31],T\"q_cmd\",},{M[1],M[25],T\"q_dot\",},{M[1],M[32],T\"q_dub_dot\",},{M[1],M[33],T\"robot_mov\",},{M[1],M[14],T\"t0n\",},{M[8],M[0],T\"is_active_c22_twa_parallel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_twa_parallel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_twa_parallelInstanceStruct *chartInstance;
    chartInstance = (SFc22_twa_parallelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_twa_parallelMachineNumber_,
           22,
           1,
           1,
           15,
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
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_cmd",0,(MexFcnForType)c22_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_des",0,(MexFcnForType)c22_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_curr",0,(MexFcnForType)
                                c22_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tf",0,
                              (MexFcnForType)c22_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tc",0,
                              (MexFcnForType)c22_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_dot",0,(MexFcnForType)c22_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_dub_dot",0,(MexFcnForType)
                                c22_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"conf",0,
                              (MexFcnForType)c22_sf_marshall);
          _SFD_SET_DATA_PROPS(8,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"confn",0,
                              (MexFcnForType)c22_sf_marshall);
          _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t0",0,
                              (MexFcnForType)c22_sf_marshall);
          _SFD_SET_DATA_PROPS(10,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t0n",0,
                              (MexFcnForType)c22_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(11,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q0n",0,(MexFcnForType)c22_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(12,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q0",0,(MexFcnForType)c22_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(13,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"enable",
                              0,(MexFcnForType)c22_sf_marshall);
          _SFD_SET_DATA_PROPS(14,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "robot_mov",0,(MexFcnForType)c22_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,4,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1824);
        _SFD_CV_INIT_EML_IF(0,0,187,196,1496,1823);
        _SFD_CV_INIT_EML_IF(0,1,201,220,1345,1495);
        _SFD_CV_INIT_EML_IF(0,2,381,393,606,1340);
        _SFD_CV_INIT_EML_IF(0,3,906,915,1172,1328);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c22_q_cmd)[6];
          real_T (*c22_q_des)[6];
          real_T (*c22_q_curr)[6];
          real_T *c22_tf;
          real_T *c22_tc;
          real_T (*c22_q_dot)[6];
          real_T (*c22_q_dub_dot)[6];
          real_T *c22_conf;
          real_T *c22_confn;
          real_T *c22_t0;
          real_T *c22_t0n;
          real_T (*c22_q0n)[6];
          real_T (*c22_q0)[6];
          real_T *c22_enable;
          real_T *c22_robot_mov;
          c22_robot_mov = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c22_enable = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c22_q0 = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 6);
          c22_q0n = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 6);
          c22_t0n = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c22_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c22_confn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c22_conf = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c22_q_dub_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
            3);
          c22_q_dot = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
          c22_tc = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c22_tf = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c22_q_curr = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c22_q_des = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          c22_q_cmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c22_q_cmd);
          _SFD_SET_DATA_VALUE_PTR(1U, c22_q_des);
          _SFD_SET_DATA_VALUE_PTR(2U, c22_q_curr);
          _SFD_SET_DATA_VALUE_PTR(3U, c22_tf);
          _SFD_SET_DATA_VALUE_PTR(4U, c22_tc);
          _SFD_SET_DATA_VALUE_PTR(5U, c22_q_dot);
          _SFD_SET_DATA_VALUE_PTR(6U, c22_q_dub_dot);
          _SFD_SET_DATA_VALUE_PTR(7U, c22_conf);
          _SFD_SET_DATA_VALUE_PTR(8U, c22_confn);
          _SFD_SET_DATA_VALUE_PTR(9U, c22_t0);
          _SFD_SET_DATA_VALUE_PTR(10U, c22_t0n);
          _SFD_SET_DATA_VALUE_PTR(11U, c22_q0n);
          _SFD_SET_DATA_VALUE_PTR(12U, c22_q0);
          _SFD_SET_DATA_VALUE_PTR(13U, c22_enable);
          _SFD_SET_DATA_VALUE_PTR(14U, c22_robot_mov);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_twa_parallelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c22_twa_parallel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_twa_parallelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*)
    chartInstanceVar);
  initialize_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c22_twa_parallel(void *chartInstanceVar)
{
  enable_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c22_twa_parallel(void *chartInstanceVar)
{
  disable_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c22_twa_parallel(void *chartInstanceVar)
{
  sf_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c22_twa_parallel(void *chartInstanceVar)
{
  ext_mode_exec_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c22_twa_parallel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c22_twa_parallel
    ((SFc22_twa_parallelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c22_twa_parallel();/* state var info */
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

static void sf_internal_set_sim_state_c22_twa_parallel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_twa_parallel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c22_twa_parallel(SimStruct* S)
{
  return sf_internal_get_sim_state_c22_twa_parallel(S);
}

static void sf_opaque_set_sim_state_c22_twa_parallel(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c22_twa_parallel(S, st);
}

static void sf_opaque_terminate_c22_twa_parallel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_twa_parallelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_twa_parallel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c22_twa_parallel((SFc22_twa_parallelInstanceStruct*)
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

static void mdlSetWorkWidths_c22_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("twa_parallel","twa_parallel",22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("twa_parallel","twa_parallel",22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("twa_parallel",
      "twa_parallel",22,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"twa_parallel","twa_parallel",22,8);
      sf_mark_chart_reusable_outputs(S,"twa_parallel","twa_parallel",22,7);
    }

    sf_set_rtw_dwork_info(S,"twa_parallel","twa_parallel",22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(702151414U));
  ssSetChecksum1(S,(2035425184U));
  ssSetChecksum2(S,(2113390951U));
  ssSetChecksum3(S,(3722334792U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c22_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "twa_parallel", "twa_parallel",22);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_twa_parallel(SimStruct *S)
{
  SFc22_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc22_twa_parallelInstanceStruct *)malloc(sizeof
    (SFc22_twa_parallelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_twa_parallelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c22_twa_parallel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c22_twa_parallel;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c22_twa_parallel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_twa_parallel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c22_twa_parallel;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c22_twa_parallel;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c22_twa_parallel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c22_twa_parallel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_twa_parallel;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_twa_parallel;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c22_twa_parallel;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c22_twa_parallel;
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

void c22_twa_parallel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_twa_parallel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_twa_parallel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_twa_parallel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_twa_parallel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
