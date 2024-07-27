/* Include files */

#include "blascompat32.h"
#include "twa_parallel_sfun.h"
#include "c1_twa_parallel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "twa_parallel_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[26] = { "conv_rad", "x_delta",
  "init_twa_len", "p_rad", "b_rad", "rot_m2w", "vertex_locs", "p_in_m", "p_in_w",
  "b_in_w", "f_rad", "flexure_locs", "f_in_w", "m_rad", "motor_locs", "m_in_w",
  "vertex_dist", "nargin", "nargout", "x_des", "ee_rot", "micro_len", "x_prev",
  "des_macro_len", "micro_len_out", "x_cur" };

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
static void c1_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance);
static real_T c1_norm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                      c1_x[3]);
static real_T c1_ceval_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[3], int32_T c1_ix0, int32_T c1_incx);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[59]);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_emlrt_marshallIn(SFc1_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c1_des_macro_len, const char_T *c1_name, real_T c1_y[3]);
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
  real_T (*c1_micro_len_out)[3];
  real_T (*c1_des_macro_len)[3];
  c1_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_micro_len_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_des_macro_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4));
  for (c1_i0 = 0; c1_i0 < 3; c1_i0 = c1_i0 + 1) {
    c1_hoistedGlobal[c1_i0] = (*c1_des_macro_len)[c1_i0];
  }

  for (c1_i1 = 0; c1_i1 < 3; c1_i1 = c1_i1 + 1) {
    c1_u[c1_i1] = c1_hoistedGlobal[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    c1_b_hoistedGlobal[c1_i2] = (*c1_micro_len_out)[c1_i2];
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
  real_T (*c1_des_macro_len)[3];
  real_T (*c1_micro_len_out)[3];
  real_T (*c1_x_cur)[3];
  c1_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_micro_len_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_des_macro_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "des_macro_len", c1_dv0);
  for (c1_i6 = 0; c1_i6 < 3; c1_i6 = c1_i6 + 1) {
    (*c1_des_macro_len)[c1_i6] = c1_dv0[c1_i6];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "micro_len_out", c1_dv1);
  for (c1_i7 = 0; c1_i7 < 3; c1_i7 = c1_i7 + 1) {
    (*c1_micro_len_out)[c1_i7] = c1_dv1[c1_i7];
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
  int32_T c1_previousEvent;
  real_T *c1_ee_rot;
  real_T (*c1_x_prev)[3];
  real_T (*c1_x_cur)[3];
  real_T (*c1_micro_len_out)[3];
  real_T (*c1_micro_len)[3];
  real_T (*c1_des_macro_len)[3];
  real_T (*c1_x_des)[3];
  c1_x_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c1_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_micro_len_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_micro_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c1_des_macro_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_x_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9 = c1_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_x_des)[c1_i9], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_ee_rot, 1U);
  for (c1_i10 = 0; c1_i10 < 3; c1_i10 = c1_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_des_macro_len)[c1_i10], 2U);
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_micro_len)[c1_i11], 3U);
  }

  for (c1_i12 = 0; c1_i12 < 3; c1_i12 = c1_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_micro_len_out)[c1_i12], 4U);
  }

  for (c1_i13 = 0; c1_i13 < 3; c1_i13 = c1_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_x_cur)[c1_i13], 5U);
  }

  for (c1_i14 = 0; c1_i14 < 3; c1_i14 = c1_i14 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_x_prev)[c1_i14], 6U);
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
  int32_T c1_i15;
  real_T c1_hoistedGlobal[3];
  real_T c1_b_hoistedGlobal;
  int32_T c1_i16;
  real_T c1_c_hoistedGlobal[3];
  int32_T c1_i17;
  real_T c1_d_hoistedGlobal[3];
  int32_T c1_i18;
  real_T c1_x_des[3];
  real_T c1_ee_rot;
  int32_T c1_i19;
  real_T c1_micro_len[3];
  int32_T c1_i20;
  real_T c1_x_prev[3];
  uint32_T c1_debug_family_var_map[26];
  static const char *c1_sv0[26] = { "conv_rad", "x_delta", "init_twa_len",
    "p_rad", "b_rad", "rot_m2w", "vertex_locs", "p_in_m",
    "p_in_w", "b_in_w", "f_rad", "flexure_locs", "f_in_w", "m_rad", "motor_locs",
    "m_in_w",
    "vertex_dist", "nargin", "nargout", "x_des", "ee_rot", "micro_len", "x_prev",
    "des_macro_len",
    "micro_len_out", "x_cur" };

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
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 3.0;
  real_T c1_des_macro_len[3];
  real_T c1_micro_len_out[3];
  real_T c1_x_cur[3];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T c1_x[3];
  real_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_y;
  int32_T c1_i24;
  static real_T c1_dv3[3] = { 2.258E+002, 2.263E+002, 224.5 };

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
  real_T c1_m_x;
  real_T c1_n_x;
  int32_T c1_i25;
  int32_T c1_i26;
  static real_T c1_dv4[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_i27;
  static real_T c1_dv5[3] = { 5.7595865315812871E+000, 1.5707963267948966E+000,
    3.6651914291880923E+000 };

  int32_T c1_i28;
  static real_T c1_dv6[9] = { 3.8971143170299726E+001, -2.2500000000000021E+001,
    0.0, 2.7554552980815448E-015, 45.0, 0.0,
    -3.8971143170299740E+001, -2.2500000000000004E+001, 0.0 };

  int32_T c1_i29;
  real_T c1_a[3];
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_b_y[9];
  int32_T c1_i33;
  real_T c1_b_a[9];
  int32_T c1_i34;
  real_T c1_A[9];
  int32_T c1_i35;
  real_T c1_b_A[9];
  int32_T c1_i36;
  real_T c1_c_A[9];
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  real_T c1_c_y[9];
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  static real_T c1_dv7[9] = { 1.4057324354229004E+002, -8.1160000000000068E+001,
    0.0, 9.9392334218799176E-015, 1.6232E+002, 0.0,
    -1.4057324354229007E+002, -8.1160000000000011E+001, 0.0 };

  int32_T c1_i44;
  static real_T c1_dv8[3] = { -6.9813170079773179E-001, 1.3962634015954636E+000,
    3.4906585039886591E+000 };

  int32_T c1_i45;
  static real_T c1_dv9[9] = { 6.1283555449518239E+001, -5.1423008774923140E+001,
    0.0, 1.3891854213354433E+001, 7.8784620240976636E+001
    , 0.0, -7.5175409662872681E+001, -2.7361611466053493E+001, 0.0 };

  int32_T c1_i46;
  static real_T c1_dv10[3] = { 4.4886377702790163E+000, 2.9984756549262581E-001,
    2.3942426678858215E+000 };

  int32_T c1_i47;
  static real_T c1_dv11[9] = { -2.6438059510305436E+000,
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
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  real_T *c1_b_ee_rot;
  real_T (*c1_b_des_macro_len)[3];
  real_T (*c1_b_micro_len_out)[3];
  real_T (*c1_b_x_cur)[3];
  real_T (*c1_b_x_prev)[3];
  real_T (*c1_b_micro_len)[3];
  real_T (*c1_b_x_des)[3];
  c1_b_x_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_micro_len_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_micro_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_des_macro_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_x_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c1_i15 = 0; c1_i15 < 3; c1_i15 = c1_i15 + 1) {
    c1_hoistedGlobal[c1_i15] = (*c1_b_x_des)[c1_i15];
  }

  c1_b_hoistedGlobal = *c1_b_ee_rot;
  for (c1_i16 = 0; c1_i16 < 3; c1_i16 = c1_i16 + 1) {
    c1_c_hoistedGlobal[c1_i16] = (*c1_b_micro_len)[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 3; c1_i17 = c1_i17 + 1) {
    c1_d_hoistedGlobal[c1_i17] = (*c1_b_x_prev)[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 3; c1_i18 = c1_i18 + 1) {
    c1_x_des[c1_i18] = c1_hoistedGlobal[c1_i18];
  }

  c1_ee_rot = c1_b_hoistedGlobal;
  for (c1_i19 = 0; c1_i19 < 3; c1_i19 = c1_i19 + 1) {
    c1_micro_len[c1_i19] = c1_c_hoistedGlobal[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 3; c1_i20 = c1_i20 + 1) {
    c1_x_prev[c1_i20] = c1_d_hoistedGlobal[c1_i20];
  }

  sf_debug_symbol_scope_push_eml(0U, 26U, 26U, c1_sv0, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_conv_rad, c1_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_x_delta, c1_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_init_twa_len, c1_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_p_rad, c1_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_b_rad, c1_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_rot_m2w, c1_c_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_vertex_locs, c1_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_p_in_m, c1_c_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c1_p_in_w, c1_c_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c1_b_in_w, c1_c_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c1_f_rad, c1_b_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c1_flexure_locs, c1_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c1_f_in_w, c1_c_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c1_m_rad, c1_b_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c1_motor_locs, c1_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c1_m_in_w, c1_c_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c1_vertex_dist, c1_c_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_b_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_b_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c1_x_des, c1_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c1_ee_rot, c1_b_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c1_micro_len, c1_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c1_x_prev, c1_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c1_des_macro_len, c1_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c1_micro_len_out, c1_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c1_x_cur, c1_sf_marshall, 25U);
  CV_EML_FCN(0, 0);

  /*  This function solves for the vertex positions of the base and moving */
  /*  platform for a given desired end effector position. */
  /*  With vertex positions known, leg lengths can be solved for. */
  /*  initialization */
  _SFD_EML_CALL(0,7);
  c1_conv_rad = 0.5;

  /* [mm] */
  _SFD_EML_CALL(0,8);
  for (c1_i21 = 0; c1_i21 < 3; c1_i21 = c1_i21 + 1) {
    c1_x_cur[c1_i21] = c1_x_des[c1_i21];
  }

  _SFD_EML_CALL(0,10);
  for (c1_i22 = 0; c1_i22 < 3; c1_i22 = c1_i22 + 1) {
    c1_micro_len_out[c1_i22] = c1_micro_len[c1_i22];
  }

  _SFD_EML_CALL(0,11);
  for (c1_i23 = 0; c1_i23 < 3; c1_i23 = c1_i23 + 1) {
    c1_x[c1_i23] = c1_x_des[c1_i23] - c1_x_prev[c1_i23];
  }

  for (c1_k = 1.0; c1_k <= 3.0; c1_k = c1_k + 1.0) {
    c1_b_k = c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 3, 1, 0) - 1];
    c1_y = muDoubleScalarAbs(c1_b_x);
    c1_x_delta[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 3, 1, 0) - 1] = c1_y;
  }

  /*  initial twa wire length */
  _SFD_EML_CALL(0,14);
  for (c1_i24 = 0; c1_i24 < 3; c1_i24 = c1_i24 + 1) {
    c1_init_twa_len[c1_i24] = c1_dv3[c1_i24];
  }

  /* [mm] */
  /*  moving platform radius */
  _SFD_EML_CALL(0,17);
  c1_p_rad = 45.0;

  /* [mm] */
  /*  base radius */
  _SFD_EML_CALL(0,20);
  c1_b_rad = 1.6232E+002;

  /*  158.04; %[mm] */
  /*  rotation matrix of moving frame about z-xis */
  _SFD_EML_CALL(0,23);
  c1_c_x = c1_ee_rot;
  c1_d_x = c1_c_x;
  c1_e_x = c1_d_x;
  c1_d_x = c1_e_x;
  c1_d_x = muDoubleScalarCos(c1_d_x);
  c1_f_x = c1_ee_rot;
  c1_g_x = c1_f_x;
  c1_h_x = c1_g_x;
  c1_g_x = c1_h_x;
  c1_g_x = muDoubleScalarSin(c1_g_x);
  c1_i_x = c1_ee_rot;
  c1_j_x = c1_i_x;
  c1_k_x = c1_j_x;
  c1_j_x = c1_k_x;
  c1_j_x = muDoubleScalarSin(c1_j_x);
  c1_l_x = c1_ee_rot;
  c1_m_x = c1_l_x;
  c1_n_x = c1_m_x;
  c1_m_x = c1_n_x;
  c1_m_x = muDoubleScalarCos(c1_m_x);
  c1_rot_m2w[0] = c1_d_x;
  c1_rot_m2w[3] = -c1_g_x;
  c1_rot_m2w[6] = 0.0;
  c1_rot_m2w[1] = c1_j_x;
  c1_rot_m2w[4] = c1_m_x;
  c1_rot_m2w[7] = 0.0;
  c1_i25 = 0;
  for (c1_i26 = 0; c1_i26 < 3; c1_i26 = c1_i26 + 1) {
    c1_rot_m2w[c1_i25 + 2] = c1_dv4[c1_i26];
    c1_i25 = c1_i25 + 3;
  }

  /*  moving platform vertex locations */
  _SFD_EML_CALL(0,26);
  for (c1_i27 = 0; c1_i27 < 3; c1_i27 = c1_i27 + 1) {
    c1_vertex_locs[c1_i27] = c1_dv5[c1_i27];
  }

  _SFD_EML_CALL(0,27);
  for (c1_i28 = 0; c1_i28 < 9; c1_i28 = c1_i28 + 1) {
    c1_p_in_m[c1_i28] = c1_dv6[c1_i28];
  }

  /*  x_des = zeros(3,1); */
  _SFD_EML_CALL(0,30);
  for (c1_i29 = 0; c1_i29 < 3; c1_i29 = c1_i29 + 1) {
    c1_a[c1_i29] = c1_x_des[c1_i29];
  }

  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 3; c1_i31 = c1_i31 + 1) {
    for (c1_i32 = 0; c1_i32 < 3; c1_i32 = c1_i32 + 1) {
      c1_b_y[c1_i32 + c1_i30] = c1_a[c1_i32];
    }

    c1_i30 = c1_i30 + 3;
  }

  for (c1_i33 = 0; c1_i33 < 9; c1_i33 = c1_i33 + 1) {
    c1_b_a[c1_i33] = c1_rot_m2w[c1_i33];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i34 = 0; c1_i34 < 9; c1_i34 = c1_i34 + 1) {
    c1_A[c1_i34] = c1_b_a[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 9; c1_i35 = c1_i35 + 1) {
    c1_b_A[c1_i35] = c1_A[c1_i35];
  }

  for (c1_i36 = 0; c1_i36 < 9; c1_i36 = c1_i36 + 1) {
    c1_c_A[c1_i36] = c1_b_A[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 3; c1_i37 = c1_i37 + 1) {
    c1_i38 = 0;
    for (c1_i39 = 0; c1_i39 < 3; c1_i39 = c1_i39 + 1) {
      c1_c_y[c1_i38 + c1_i37] = 0.0;
      c1_i40 = 0;
      for (c1_i41 = 0; c1_i41 < 3; c1_i41 = c1_i41 + 1) {
        c1_c_y[c1_i38 + c1_i37] = c1_c_y[c1_i38 + c1_i37] + c1_c_A[c1_i40 +
          c1_i37] * c1_dv6[c1_i41 + c1_i38];
        c1_i40 = c1_i40 + 3;
      }

      c1_i38 = c1_i38 + 3;
    }
  }

  for (c1_i42 = 0; c1_i42 < 9; c1_i42 = c1_i42 + 1) {
    c1_p_in_w[c1_i42] = c1_b_y[c1_i42] + c1_c_y[c1_i42];
  }

  /*  base vertex positions */
  _SFD_EML_CALL(0,33);
  for (c1_i43 = 0; c1_i43 < 9; c1_i43 = c1_i43 + 1) {
    c1_b_in_w[c1_i43] = c1_dv7[c1_i43];
  }

  /*  position of flexure centers */
  /*  radius of position of flexure center */
  _SFD_EML_CALL(0,37);
  c1_f_rad = 80.0;

  /* [mm] */
  _SFD_EML_CALL(0,38);
  for (c1_i44 = 0; c1_i44 < 3; c1_i44 = c1_i44 + 1) {
    c1_flexure_locs[c1_i44] = c1_dv8[c1_i44];
  }

  _SFD_EML_CALL(0,39);
  for (c1_i45 = 0; c1_i45 < 9; c1_i45 = c1_i45 + 1) {
    c1_f_in_w[c1_i45] = c1_dv9[c1_i45];
  }

  /*  position of twa pivot point, taken from CAD */
  /*  radius of position of twa pivot */
  _SFD_EML_CALL(0,43);
  c1_m_rad = 11.915;
  _SFD_EML_CALL(0,44);
  for (c1_i46 = 0; c1_i46 < 3; c1_i46 = c1_i46 + 1) {
    c1_motor_locs[c1_i46] = c1_dv10[c1_i46];
  }

  _SFD_EML_CALL(0,45);
  for (c1_i47 = 0; c1_i47 < 9; c1_i47 = c1_i47 + 1) {
    c1_m_in_w[c1_i47] = c1_dv11[c1_i47];
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*         Macro Actuator        % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  _SFD_EML_CALL(0,52);
  for (c1_i48 = 0; c1_i48 < 9; c1_i48 = c1_i48 + 1) {
    c1_vertex_dist[c1_i48] = c1_p_in_w[c1_i48] - c1_b_in_w[c1_i48];
  }

  _SFD_EML_CALL(0,54);
  for (c1_i49 = 0; c1_i49 < 3; c1_i49 = c1_i49 + 1) {
    c1_des_macro_len[c1_i49] = 0.0;
  }

  _SFD_EML_CALL(0,55);
  for (c1_i50 = 0; c1_i50 < 3; c1_i50 = c1_i50 + 1) {
    c1_b_vertex_dist[c1_i50] = c1_vertex_dist[c1_i50];
  }

  c1_des_macro_len[0] = c1_norm(chartInstance, c1_b_vertex_dist);
  _SFD_EML_CALL(0,56);
  for (c1_i51 = 0; c1_i51 < 3; c1_i51 = c1_i51 + 1) {
    c1_c_vertex_dist[c1_i51] = c1_vertex_dist[c1_i51 + 3];
  }

  c1_des_macro_len[1] = c1_norm(chartInstance, c1_c_vertex_dist);
  _SFD_EML_CALL(0,57);
  for (c1_i52 = 0; c1_i52 < 3; c1_i52 = c1_i52 + 1) {
    c1_d_vertex_dist[c1_i52] = c1_vertex_dist[c1_i52 + 6];
  }

  c1_des_macro_len[2] = c1_norm(chartInstance, c1_d_vertex_dist);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*        Micro Actuator         % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  if x_delta(1,1) < conv_rad || x_delta(2,1) < conv_rad */
  /*      % initial flexure bend */
  /*      beta_cmd = 5*pi/180; */
  /*       */
  /*      % loop through each vertex */
  /*      for i = 1:3 */
  /*          post_flex_angle = zeros(1,2); */
  /*          beta = NaN(1,2); */
  /*           */
  /*          % vector from flexure center to moving platform vertex */
  /*          rho_vec = p_in_w(:,i) - f_in_w(:,i); */
  /*           */
  /*          % distance between flexure and moving platform verteces */
  /*          rho = norm(rho_vec); */
  /*           */
  /*          % vector from flexure center to base vertex pre flexure rotation */
  /*          eta_vec = b_in_w(:,i) - f_in_w(:,i); */
  /*           */
  /*          % flexure angle at the start (e.g. 5 deg preload) in world frame */
  /*          pre_flex_angle = atan2(eta_vec(2,1),eta_vec(1,1)); */
  /*           */
  /*          % magnitude of flexure swing-arm radius from flexure to base vertex */
  /*          eta = norm(eta_vec); */
  /*           */
  /*          % angle from world horizontal to the vector from the flexure */
  /*          % center to the platform vertex */
  /*          flexure_frame_rot_angle = atan2(rho_vec(2,1),rho_vec(1,1)); */
  /*           */
  /*          % rotation matrix from flexure frame to world */
  /*          n = [0;0;1] ./ norm([0;0;1]); */
  /*          rot_f_2_w = expm(flexure_frame_rot_angle*[0 -n(3) n(2);n(3) 0 -n(1);n(2) n(1) 0]); */
  /*           */
  /*          % condition for acos solvability */
  /*          check = (macro_len(i,1)^2-rho^2-eta^2)/(-2*rho*eta); */
  /*           */
  /*          if check >= -1 && check <= 1 */
  /*              % calculate angle between mf and fb vectors, lambda, with */
  /*              % law of cosines */
  /*              lambda = acos(check); */
  /*               */
  /*              % calculate flexed base vertex position for both elbow up */
  /*              % and down configurations in the flexure frame */
  /*              b_prime_in_f_dwn = eta*[cos(-lambda);sin(-lambda);0]; */
  /*              b_prime_in_f_up = eta*[cos(lambda);sin(lambda);0]; */
  /*               */
  /*              % vector from flexure center point to new base vertex location */
  /*              % rotated to world frame */
  /*              eta_prime_vec_dwn = rot_f_2_w*b_prime_in_f_dwn; */
  /*              eta_prime_vec_up = rot_f_2_w*b_prime_in_f_up; */
  /*               */
  /*              post_flex_angle(1,1) = atan2(eta_prime_vec_dwn(2,1),eta_prime_vec_dwn(1,1)); */
  /*              post_flex_angle(1,2) = atan2(eta_prime_vec_up(2,1),eta_prime_vec_up(1,1)); */
  /*               */
  /*              % determine if flex angle is within mechanical range */
  /*              for j = 1:2 */
  /*                  if pre_flex_angle < 0 && post_flex_angle(1,i) < 0 */
  /*                      beta(1,j) = (-1*pre_flex_angle)-(-1*post_flex_angle(1,j)); */
  /*                  else */
  /*                      beta(1,j) = pre_flex_angle - post_flex_angle(1,j); */
  /*                  end */
  /*                   */
  /*                  if beta(1,j) >= -pi/18 && beta(1,j) <= pi/18 */
  /*                      beta_cmd = beta(1,j); */
  /*                  end */
  /*              end */
  /*          end */
  /*           */
  /*          % initial angle prior to flexure bend */
  /*          a = norm(f_in_w(:,i) - m_in_w(:,i)); */
  /*          b = norm(f_in_w(:,i) - b_in_w(:,i)); */
  /*          c = init_twa_len(i,1); */
  /*          alpha =  acos((c^2 - a^2 - b^2)/(-2*a*b)); */
  /*           */
  /*          % calculate required twa length to facilitate flexure bend */
  /*          micro_len_out(i,1) = sqrt(a^2 - b^2 - 2*a*b*cos(alpha - beta_cmd)); */
  /*      end */
  /*  end */
  _SFD_EML_CALL(0,-57);
  sf_debug_symbol_scope_pop();
  for (c1_i53 = 0; c1_i53 < 3; c1_i53 = c1_i53 + 1) {
    (*c1_b_des_macro_len)[c1_i53] = c1_des_macro_len[c1_i53];
  }

  for (c1_i54 = 0; c1_i54 < 3; c1_i54 = c1_i54 + 1) {
    (*c1_b_micro_len_out)[c1_i54] = c1_micro_len_out[c1_i54];
  }

  for (c1_i55 = 0; c1_i55 < 3; c1_i55 = c1_i55 + 1) {
    (*c1_b_x_cur)[c1_i55] = c1_x_cur[c1_i55];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static void c1_eml_scalar_eg(SFc1_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c1_norm(SFc1_twa_parallelInstanceStruct *chartInstance, real_T
                      c1_x[3])
{
  int32_T c1_i56;
  real_T c1_b_x[3];
  int32_T c1_i57;
  real_T c1_c_x[3];
  int32_T c1_i58;
  real_T c1_d_x[3];
  int32_T c1_i59;
  real_T c1_e_x[3];
  for (c1_i56 = 0; c1_i56 < 3; c1_i56 = c1_i56 + 1) {
    c1_b_x[c1_i56] = c1_x[c1_i56];
  }

  for (c1_i57 = 0; c1_i57 < 3; c1_i57 = c1_i57 + 1) {
    c1_c_x[c1_i57] = c1_b_x[c1_i57];
  }

  for (c1_i58 = 0; c1_i58 < 3; c1_i58 = c1_i58 + 1) {
    c1_d_x[c1_i58] = c1_c_x[c1_i58];
  }

  for (c1_i59 = 0; c1_i59 < 3; c1_i59 = c1_i59 + 1) {
    c1_e_x[c1_i59] = c1_d_x[c1_i59];
  }

  return c1_ceval_xnrm2(chartInstance, 3, c1_e_x, 1, 1);
}

static real_T c1_ceval_xnrm2(SFc1_twa_parallelInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[3], int32_T c1_ix0, int32_T
  c1_incx)
{
  return dnrm232(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 3, 1, 0) - 1], &
                 c1_incx);
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i60;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i60 = 0; c1_i60 < 3; c1_i60 = c1_i60 + 1) {
    c1_b_u[c1_i60] = (*((real_T (*)[3])c1_u))[c1_i60];
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
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  real_T c1_b_u[9];
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i61 = 0;
  for (c1_i62 = 0; c1_i62 < 3; c1_i62 = c1_i62 + 1) {
    for (c1_i63 = 0; c1_i63 < 3; c1_i63 = c1_i63 + 1) {
      c1_b_u[c1_i63 + c1_i61] = (*((real_T (*)[9])c1_u))[c1_i63 + c1_i61];
    }

    c1_i61 = c1_i61 + 3;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i64;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  SFc1_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc1_twa_parallelInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i64 = 0; c1_i64 < 3; c1_i64 = c1_i64 + 1) {
    c1_b_u[c1_i64] = (*((real_T (*)[3])c1_u))[c1_i64];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_twa_parallel_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[59];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i65;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 59));
  for (c1_i65 = 0; c1_i65 < 59; c1_i65 = c1_i65 + 1) {
    c1_r0 = &c1_info[c1_i65];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i65
                    );
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i65
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[59])
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
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
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
  const mxArray *c1_des_macro_len, const char_T *
  c1_name, real_T c1_y[3])
{
  real_T c1_dv12[3];
  int32_T c1_i66;
  sf_mex_import(c1_name, sf_mex_dup(c1_des_macro_len), &c1_dv12, 1, 0, 0U, 1, 0U,
                1, 3);
  for (c1_i66 = 0; c1_i66 < 3; c1_i66 = c1_i66 + 1) {
    c1_y[c1_i66] = c1_dv12[c1_i66];
  }

  sf_mex_destroy(&c1_des_macro_len);
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(42746754U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3844078725U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2159014961U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2264070729U);
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
    pr[0] = (double)(830336455U);
    pr[1] = (double)(4189736456U);
    pr[2] = (double)(1542586048U);
    pr[3] = (double)(3906239735U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[19],T\"des_macro_len\",},{M[1],M[16],T\"micro_len_out\",},{M[1],M[17],T\"x_cur\",},{M[8],M[0],T\"is_active_c1_twa_parallel\",}}"
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
           7,
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

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"ee_rot",
                              0,(MexFcnForType)c1_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"des_macro_len",0,(MexFcnForType)
                                c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"micro_len",0,(MexFcnForType)
                                c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"micro_len_out",0,(MexFcnForType)
                                c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"x_cur",0,(MexFcnForType)c1_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,5003);
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
          real_T *c1_ee_rot;
          real_T (*c1_des_macro_len)[3];
          real_T (*c1_micro_len)[3];
          real_T (*c1_micro_len_out)[3];
          real_T (*c1_x_cur)[3];
          real_T (*c1_x_prev)[3];
          c1_x_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c1_x_cur = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c1_micro_len_out = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c1_micro_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c1_des_macro_len = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c1_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_x_des = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_x_des);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_ee_rot);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_des_macro_len);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_micro_len);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_micro_len_out);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_x_cur);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_x_prev);
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
      sf_mark_chart_expressionable_inputs(S,"twa_parallel","twa_parallel",1,4);
      sf_mark_chart_reusable_outputs(S,"twa_parallel","twa_parallel",1,3);
    }

    sf_set_rtw_dwork_info(S,"twa_parallel","twa_parallel",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(212575414U));
  ssSetChecksum1(S,(60731626U));
  ssSetChecksum2(S,(3927504262U));
  ssSetChecksum3(S,(2933916499U));
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
