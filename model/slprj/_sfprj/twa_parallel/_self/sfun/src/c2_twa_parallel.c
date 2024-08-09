/* Include files */

#include "blascompat32.h"
#include "twa_parallel_sfun.h"
#include "c2_twa_parallel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "twa_parallel_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[9] = { "theta_mu_rad", "nargin",
  "nargout", "q_cur", "des_micro_len", "meas_twa_len", "helix_rad", "wire_delta",
  "theta_mu" };

/* Function Declarations */
static void initialize_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance);
static void initialize_params_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance);
static void enable_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance);
static void disable_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_twa_parallel
  (SFc2_twa_parallelInstanceStruct *chartInstance);
static void ext_mode_exec_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_twa_parallel
  (SFc2_twa_parallelInstanceStruct *chartInstance);
static void set_sim_state_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance);
static void sf_c2_twa_parallel(SFc2_twa_parallelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_mpower(SFc2_twa_parallelInstanceStruct *chartInstance, real_T
  c2_a);
static void c2_eml_error(SFc2_twa_parallelInstanceStruct *chartInstance);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[34]);
static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_emlrt_marshallIn(SFc2_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c2_theta_mu, const char_T *c2_name, real_T c2_y[3]);
static uint8_T c2_b_emlrt_marshallIn(SFc2_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_twa_parallel, const char_T
  *c2_name);
static void init_dsm_address_info(SFc2_twa_parallelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance)
{
  uint8_T *c2_is_active_c2_twa_parallel;
  c2_is_active_c2_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_twa_parallel = 0U;
}

static void initialize_params_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void enable_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_twa_parallel
  (SFc2_twa_parallelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance)
{
  c2_update_debugger_state_c2_twa_parallel(chartInstance);
}

static const mxArray *get_sim_state_c2_twa_parallel
  (SFc2_twa_parallelInstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_hoistedGlobal[3];
  int32_T c2_i1;
  real_T c2_u[3];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T *c2_is_active_c2_twa_parallel;
  real_T (*c2_theta_mu)[3];
  c2_theta_mu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i0 = 0; c2_i0 < 3; c2_i0 = c2_i0 + 1) {
    c2_hoistedGlobal[c2_i0] = (*c2_theta_mu)[c2_i0];
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1 = c2_i1 + 1) {
    c2_u[c2_i1] = c2_hoistedGlobal[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_is_active_c2_twa_parallel;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i2;
  boolean_T *c2_doneDoubleBufferReInit;
  uint8_T *c2_is_active_c2_twa_parallel;
  real_T (*c2_theta_mu)[3];
  c2_theta_mu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "theta_mu", c2_dv0);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2 = c2_i2 + 1) {
    (*c2_theta_mu)[c2_i2] = c2_dv0[c2_i2];
  }

  *c2_is_active_c2_twa_parallel = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_active_c2_twa_parallel");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_twa_parallel(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_twa_parallel(SFc2_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void sf_c2_twa_parallel(SFc2_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_previousEvent;
  int32_T c2_i7;
  real_T c2_hoistedGlobal[6];
  int32_T c2_i8;
  real_T c2_b_hoistedGlobal[3];
  int32_T c2_i9;
  real_T c2_c_hoistedGlobal[3];
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  int32_T c2_i10;
  real_T c2_q_cur[6];
  int32_T c2_i11;
  real_T c2_des_micro_len[3];
  int32_T c2_i12;
  real_T c2_meas_twa_len[3];
  real_T c2_helix_rad;
  real_T c2_wire_delta;
  uint32_T c2_debug_family_var_map[9];
  static const char *c2_sv0[9] = { "theta_mu_rad", "nargin", "nargout", "q_cur",
    "des_micro_len", "meas_twa_len", "helix_rad",
    "wire_delta", "theta_mu" };

  real_T c2_theta_mu_rad[3];
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 1.0;
  real_T c2_theta_mu[3];
  int32_T c2_i13;
  int32_T c2_i14;
  real_T c2_B;
  real_T c2_y;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_a;
  real_T c2_b;
  real_T c2_e_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_f_y;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b_B;
  real_T c2_g_y;
  real_T c2_h_y;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_k_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_l_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_c_B;
  real_T c2_m_y;
  real_T c2_n_y;
  real_T c2_o_y;
  real_T c2_p_y;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_q_y;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_r_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  int32_T c2_i15;
  real_T c2_A[3];
  int32_T c2_i16;
  real_T c2_j_x[3];
  int32_T c2_i17;
  real_T c2_k_x[3];
  int32_T c2_i18;
  real_T c2_l_x[3];
  int32_T c2_i19;
  int32_T c2_i20;
  real_T *c2_b_helix_rad;
  real_T *c2_b_wire_delta;
  real_T (*c2_b_theta_mu)[3];
  real_T (*c2_b_meas_twa_len)[3];
  real_T (*c2_b_des_micro_len)[3];
  real_T (*c2_b_q_cur)[6];
  c2_b_wire_delta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_helix_rad = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_meas_twa_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_theta_mu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_des_micro_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_q_cur = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  for (c2_i3 = 0; c2_i3 < 6; c2_i3 = c2_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_b_q_cur)[c2_i3], 0U);
  }

  for (c2_i4 = 0; c2_i4 < 3; c2_i4 = c2_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_b_des_micro_len)[c2_i4], 1U);
  }

  for (c2_i5 = 0; c2_i5 < 3; c2_i5 = c2_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_b_theta_mu)[c2_i5], 2U);
  }

  for (c2_i6 = 0; c2_i6 < 3; c2_i6 = c2_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_b_meas_twa_len)[c2_i6], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_helix_rad, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_wire_delta, 5U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for (c2_i7 = 0; c2_i7 < 6; c2_i7 = c2_i7 + 1) {
    c2_hoistedGlobal[c2_i7] = (*c2_b_q_cur)[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8 = c2_i8 + 1) {
    c2_b_hoistedGlobal[c2_i8] = (*c2_b_des_micro_len)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 3; c2_i9 = c2_i9 + 1) {
    c2_c_hoistedGlobal[c2_i9] = (*c2_b_meas_twa_len)[c2_i9];
  }

  c2_d_hoistedGlobal = *c2_b_helix_rad;
  c2_e_hoistedGlobal = *c2_b_wire_delta;
  for (c2_i10 = 0; c2_i10 < 6; c2_i10 = c2_i10 + 1) {
    c2_q_cur[c2_i10] = c2_hoistedGlobal[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 3; c2_i11 = c2_i11 + 1) {
    c2_des_micro_len[c2_i11] = c2_b_hoistedGlobal[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 3; c2_i12 = c2_i12 + 1) {
    c2_meas_twa_len[c2_i12] = c2_c_hoistedGlobal[c2_i12];
  }

  c2_helix_rad = c2_d_hoistedGlobal;
  c2_wire_delta = c2_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c2_sv0, c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_theta_mu_rad, c2_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_q_cur, c2_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_des_micro_len, c2_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_meas_twa_len, c2_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c2_helix_rad, c2_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c2_wire_delta, c2_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c2_theta_mu, c2_sf_marshall, 8U);
  CV_EML_FCN(0, 0);

  /*  This function solves for command signal for the twa's given a desired */
  /*  micro leg length */
  _SFD_EML_CALL(0,5);
  for (c2_i13 = 0; c2_i13 < 3; c2_i13 = c2_i13 + 1) {
    c2_theta_mu[c2_i13] = c2_q_cur[c2_i13 + 3];
  }

  _SFD_EML_CALL(0,6);
  for (c2_i14 = 0; c2_i14 < 3; c2_i14 = c2_i14 + 1) {
    c2_theta_mu_rad[c2_i14] = 0.0;
  }

  /*  qmu = zeros(3,1); */
  /*  qmu(1,1) = meas_twa_len(1,1) - des_micro_len(1,1); */
  /*  qmu(2,1) = meas_twa_len(2,1) - des_micro_len(2,1); */
  /*  qmu(3,1) = meas_twa_len(3,1) - des_micro_len(3,1); */
  /*  for i = 1:3 */
  /*      num = meas_twa_len(i,1)^2 * (1 + wire_delta)^2 - des_micro_len(i,1)^2; */
  /*      theta_mu(i,1) = sqrt(num/helix_rad^2); */
  /*  end */
  _SFD_EML_CALL(0,17);
  c2_B = c2_mpower(chartInstance, c2_helix_rad);
  c2_y = c2_B;
  c2_b_y = c2_y;
  c2_c_y = c2_b_y;
  c2_d_y = 1.0 / c2_c_y;
  c2_a = c2_mpower(chartInstance, c2_meas_twa_len[0]);
  c2_b = c2_mpower(chartInstance, 1.0 + c2_wire_delta);
  c2_e_y = c2_a * c2_b;
  c2_b_a = c2_d_y;
  c2_b_b = c2_e_y - c2_mpower(chartInstance, c2_des_micro_len[0]);
  c2_f_y = c2_b_a * c2_b_b;
  c2_x = c2_f_y;
  c2_b_x = c2_x;
  if (c2_b_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_c_x = c2_b_x;
  c2_b_x = c2_c_x;
  c2_b_x = muDoubleScalarSqrt(c2_b_x);
  c2_theta_mu_rad[0] = c2_b_x;

  /* [rad] */
  _SFD_EML_CALL(0,19);
  c2_b_B = c2_mpower(chartInstance, c2_helix_rad);
  c2_g_y = c2_b_B;
  c2_h_y = c2_g_y;
  c2_i_y = c2_h_y;
  c2_j_y = 1.0 / c2_i_y;
  c2_c_a = c2_mpower(chartInstance, c2_meas_twa_len[1]);
  c2_c_b = c2_mpower(chartInstance, 1.0 + c2_wire_delta);
  c2_k_y = c2_c_a * c2_c_b;
  c2_d_a = c2_j_y;
  c2_d_b = c2_k_y - c2_mpower(chartInstance, c2_des_micro_len[1]);
  c2_l_y = c2_d_a * c2_d_b;
  c2_d_x = c2_l_y;
  c2_e_x = c2_d_x;
  if (c2_e_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_f_x = c2_e_x;
  c2_e_x = c2_f_x;
  c2_e_x = muDoubleScalarSqrt(c2_e_x);
  c2_theta_mu_rad[1] = c2_e_x;

  /* [rad] */
  _SFD_EML_CALL(0,21);
  c2_c_B = c2_mpower(chartInstance, c2_helix_rad);
  c2_m_y = c2_c_B;
  c2_n_y = c2_m_y;
  c2_o_y = c2_n_y;
  c2_p_y = 1.0 / c2_o_y;
  c2_e_a = c2_mpower(chartInstance, c2_meas_twa_len[2]);
  c2_e_b = c2_mpower(chartInstance, 1.0 + c2_wire_delta);
  c2_q_y = c2_e_a * c2_e_b;
  c2_f_a = c2_p_y;
  c2_f_b = c2_q_y - c2_mpower(chartInstance, c2_des_micro_len[2]);
  c2_r_y = c2_f_a * c2_f_b;
  c2_g_x = c2_r_y;
  c2_h_x = c2_g_x;
  if (c2_h_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_i_x = c2_h_x;
  c2_h_x = c2_i_x;
  c2_h_x = muDoubleScalarSqrt(c2_h_x);
  c2_theta_mu_rad[2] = c2_h_x;

  /* [rad] */
  /* convert to rotations from radians */
  _SFD_EML_CALL(0,25);
  for (c2_i15 = 0; c2_i15 < 3; c2_i15 = c2_i15 + 1) {
    c2_A[c2_i15] = c2_theta_mu_rad[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 3; c2_i16 = c2_i16 + 1) {
    c2_j_x[c2_i16] = c2_A[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 3; c2_i17 = c2_i17 + 1) {
    c2_k_x[c2_i17] = c2_j_x[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 3; c2_i18 = c2_i18 + 1) {
    c2_l_x[c2_i18] = c2_k_x[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 3; c2_i19 = c2_i19 + 1) {
    c2_theta_mu[c2_i19] = c2_l_x[c2_i19] / 6.2831853071795862E+000;
  }

  _SFD_EML_CALL(0,-25);
  sf_debug_symbol_scope_pop();
  for (c2_i20 = 0; c2_i20 < 3; c2_i20 = c2_i20 + 1) {
    (*c2_b_theta_mu)[c2_i20] = c2_theta_mu[c2_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_twa_parallelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static real_T c2_mpower(SFc2_twa_parallelInstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static void c2_eml_error(SFc2_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c2_i21;
  static char_T c2_cv0[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  int32_T c2_i22;
  static char_T c2_cv1[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c2_b_u[77];
  const mxArray *c2_b_y = NULL;
  for (c2_i21 = 0; c2_i21 < 31; c2_i21 = c2_i21 + 1) {
    c2_u[c2_i21] = c2_cv0[c2_i21];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c2_i22 = 0; c2_i22 < 77; c2_i22 = c2_i22 + 1) {
    c2_b_u[c2_i22] = c2_cv1[c2_i22];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i23;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  SFc2_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc2_twa_parallelInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i23 = 0; c2_i23 < 3; c2_i23 = c2_i23 + 1) {
    c2_b_u[c2_i23] = (*((real_T (*)[3])c2_u))[c2_i23];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc2_twa_parallelInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i24;
  real_T c2_b_u[6];
  const mxArray *c2_b_y = NULL;
  SFc2_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc2_twa_parallelInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i24 = 0; c2_i24 < 6; c2_i24 = c2_i24 + 1) {
    c2_b_u[c2_i24] = (*((real_T (*)[6])c2_u))[c2_i24];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_twa_parallel_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[34];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i25;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 34));
  for (c2_i25 = 0; c2_i25 < 34; c2_i25 = c2_i25 + 1) {
    c2_r0 = &c2_info[c2_i25];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i25
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i25
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[34])
{
  c2_info[0].context = "";
  c2_info[0].name = "zeros";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]zeros";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "mpower";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[1].fileLength = 3710U;
  c2_info[1].fileTime1 = 1238459488U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[2].name = "nargin";
  c2_info[2].dominantType = "";
  c2_info[2].resolved = "[B]nargin";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[3].name = "gt";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]gt";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[4].name = "isa";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]isa";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[5].name = "isinteger";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isinteger";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[6].name = "isscalar";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]isscalar";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[7].name = "ndims";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]ndims";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[8].name = "eq";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]eq";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[9].name = "size";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]size";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[10].name = "power";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[10].fileLength = 5380U;
  c2_info[10].fileTime1 = 1228119098U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[11].name = "eml_scalar_eg";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[11].fileLength = 3068U;
  c2_info[11].fileTime1 = 1240287210U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c2_info[12].name = "false";
  c2_info[12].dominantType = "";
  c2_info[12].resolved = "[B]false";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[13].name = "isstruct";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]isstruct";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[14].name = "class";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]class";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[15].name = "cast";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]cast";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[16].name = "plus";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]plus";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c2_info[17].name = "isreal";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]isreal";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[18].name = "eml_scalexp_alloc";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[18].fileLength = 808U;
  c2_info[18].fileTime1 = 1230519898U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[19].name = "minus";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved = "[B]minus";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[20].name = "not";
  c2_info[20].dominantType = "logical";
  c2_info[20].resolved = "[B]not";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[21].name = "lt";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[B]lt";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[22].name = "eml_scalar_floor";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[22].fileLength = 260U;
  c2_info[22].fileTime1 = 1209355990U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[23].name = "ne";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]ne";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[24].name = "eml_error";
  c2_info[24].dominantType = "char";
  c2_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[24].fileLength = 315U;
  c2_info[24].fileTime1 = 1213951944U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[25].name = "strcmp";
  c2_info[25].dominantType = "char";
  c2_info[25].resolved = "[B]strcmp";
  c2_info[25].fileLength = 0U;
  c2_info[25].fileTime1 = 0U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context = "";
  c2_info[26].name = "mrdivide";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[26].fileLength = 800U;
  c2_info[26].fileTime1 = 1238459490U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[27].name = "ge";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[B]ge";
  c2_info[27].fileLength = 0U;
  c2_info[27].fileTime1 = 0U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[28].name = "rdivide";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[28].fileLength = 403U;
  c2_info[28].fileTime1 = 1244760752U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[29].name = "eml_div";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[29].fileLength = 4269U;
  c2_info[29].fileTime1 = 1228119026U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "";
  c2_info[30].name = "mtimes";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[30].fileLength = 3425U;
  c2_info[30].fileTime1 = 1250697966U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context = "";
  c2_info[31].name = "sqrt";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[31].fileLength = 572U;
  c2_info[31].fileTime1 = 1203473244U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[32].name = "eml_scalar_sqrt";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[32].fileLength = 664U;
  c2_info[32].fileTime1 = 1209355994U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context = "";
  c2_info[33].name = "pi";
  c2_info[33].dominantType = "";
  c2_info[33].resolved = "[B]pi";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
}

static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc2_twa_parallelInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static void c2_emlrt_marshallIn(SFc2_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c2_theta_mu, const char_T *c2_name,
  real_T c2_y[3])
{
  real_T c2_dv1[3];
  int32_T c2_i26;
  sf_mex_import(c2_name, sf_mex_dup(c2_theta_mu), &c2_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i26 = 0; c2_i26 < 3; c2_i26 = c2_i26 + 1) {
    c2_y[c2_i26] = c2_dv1[c2_i26];
  }

  sf_mex_destroy(&c2_theta_mu);
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_twa_parallel,
  const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_is_active_c2_twa_parallel), &c2_u0, 1, 3,
                0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_is_active_c2_twa_parallel);
  return c2_y;
}

static void init_dsm_address_info(SFc2_twa_parallelInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_twa_parallel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1144807342U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1865350670U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1126878230U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2220919259U);
}

mxArray *sf_c2_twa_parallel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3732553038U);
    pr[1] = (double)(3930744994U);
    pr[2] = (double)(1104902411U);
    pr[3] = (double)(1070040547U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_twa_parallel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[16],T\"theta_mu\",},{M[8],M[0],T\"is_active_c2_twa_parallel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_twa_parallel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_twa_parallelInstanceStruct *chartInstance;
    chartInstance = (SFc2_twa_parallelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_twa_parallelMachineNumber_,
           2,
           1,
           1,
           6,
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
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_cur",0,(MexFcnForType)c2_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"des_micro_len",0,(MexFcnForType)
                                c2_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"theta_mu",0,(MexFcnForType)c2_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"meas_twa_len",0,(MexFcnForType)
                                c2_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "helix_rad",0,(MexFcnForType)c2_b_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "wire_delta",0,(MexFcnForType)c2_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1007);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c2_q_cur)[6];
          real_T (*c2_des_micro_len)[3];
          real_T (*c2_theta_mu)[3];
          real_T (*c2_meas_twa_len)[3];
          real_T *c2_helix_rad;
          real_T *c2_wire_delta;
          c2_wire_delta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_helix_rad = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_meas_twa_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            2);
          c2_theta_mu = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_des_micro_len = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 1);
          c2_q_cur = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_q_cur);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_des_micro_len);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_theta_mu);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_meas_twa_len);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_helix_rad);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_wire_delta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_twa_parallelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_twa_parallel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_twa_parallelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*)
    chartInstanceVar);
  initialize_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_twa_parallel(void *chartInstanceVar)
{
  enable_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_twa_parallel(void *chartInstanceVar)
{
  disable_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_twa_parallel(void *chartInstanceVar)
{
  sf_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_twa_parallel(void *chartInstanceVar)
{
  ext_mode_exec_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_twa_parallel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_twa_parallel
    ((SFc2_twa_parallelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_twa_parallel();/* state var info */
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

static void sf_internal_set_sim_state_c2_twa_parallel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_twa_parallel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_twa_parallel(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_twa_parallel(S);
}

static void sf_opaque_set_sim_state_c2_twa_parallel(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c2_twa_parallel(S, st);
}

static void sf_opaque_terminate_c2_twa_parallel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_twa_parallelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_twa_parallel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_twa_parallel((SFc2_twa_parallelInstanceStruct*)
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

static void mdlSetWorkWidths_c2_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("twa_parallel","twa_parallel",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("twa_parallel","twa_parallel",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("twa_parallel",
      "twa_parallel",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"twa_parallel","twa_parallel",2,5);
      sf_mark_chart_reusable_outputs(S,"twa_parallel","twa_parallel",2,1);
    }

    sf_set_rtw_dwork_info(S,"twa_parallel","twa_parallel",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3751837139U));
  ssSetChecksum1(S,(2734298684U));
  ssSetChecksum2(S,(3761552896U));
  ssSetChecksum3(S,(2135264196U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "twa_parallel", "twa_parallel",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_twa_parallel(SimStruct *S)
{
  SFc2_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc2_twa_parallelInstanceStruct *)malloc(sizeof
    (SFc2_twa_parallelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_twa_parallelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_twa_parallel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_twa_parallel;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_twa_parallel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_twa_parallel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_twa_parallel;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_twa_parallel;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_twa_parallel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_twa_parallel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_twa_parallel;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_twa_parallel;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_twa_parallel;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c2_twa_parallel;
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

void c2_twa_parallel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_twa_parallel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_twa_parallel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_twa_parallel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_twa_parallel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
