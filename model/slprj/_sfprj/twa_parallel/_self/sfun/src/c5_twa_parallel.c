/* Include files */

#include "blascompat32.h"
#include "twa_parallel_sfun.h"
#include "c5_twa_parallel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "twa_parallel_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c5_debug_family_names[10] = { "p_in_w", "qnom", "nargin",
  "nargout", "ee_rot", "p_in_m", "b_in_w", "meas_macro_len", "rm2w", "eq_start"
};

/* Function Declarations */
static void initialize_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance);
static void initialize_params_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance);
static void enable_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance);
static void disable_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_twa_parallel
  (SFc5_twa_parallelInstanceStruct *chartInstance);
static void ext_mode_exec_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_twa_parallel
  (SFc5_twa_parallelInstanceStruct *chartInstance);
static void set_sim_state_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance);
static void sf_c5_twa_parallel(SFc5_twa_parallelInstanceStruct *chartInstance);
static void c5_c5_twa_parallel(SFc5_twa_parallelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static void c5_eml_scalar_eg(SFc5_twa_parallelInstanceStruct *chartInstance);
static real_T c5_norm(SFc5_twa_parallelInstanceStruct *chartInstance, real_T
                      c5_x[3]);
static real_T c5_ceval_xnrm2(SFc5_twa_parallelInstanceStruct *chartInstance,
  int32_T c5_n, real_T c5_x[3], int32_T c5_ix0, int32_T c5_incx);
static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[54]);
static const mxArray *c5_d_sf_marshall(void *chartInstanceVoid, void *c5_u);
static void c5_emlrt_marshallIn(SFc5_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c5_eq_start, const char_T *c5_name, real_T c5_y[3]);
static void c5_b_emlrt_marshallIn(SFc5_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c5_rm2w, const char_T *c5_name, real_T c5_y[9]);
static uint8_T c5_c_emlrt_marshallIn(SFc5_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c5_is_active_c5_twa_parallel, const char_T
  *c5_name);
static void init_dsm_address_info(SFc5_twa_parallelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance)
{
  uint8_T *c5_is_active_c5_twa_parallel;
  c5_is_active_c5_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c5_is_active_c5_twa_parallel = 0U;
}

static void initialize_params_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void enable_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_twa_parallel
  (SFc5_twa_parallelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance)
{
  c5_update_debugger_state_c5_twa_parallel(chartInstance);
}

static const mxArray *get_sim_state_c5_twa_parallel
  (SFc5_twa_parallelInstanceStruct *chartInstance)
{
  const mxArray *c5_st = NULL;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_hoistedGlobal[3];
  int32_T c5_i1;
  real_T c5_u[3];
  const mxArray *c5_b_y = NULL;
  int32_T c5_i2;
  real_T c5_b_hoistedGlobal[9];
  int32_T c5_i3;
  real_T c5_b_u[9];
  const mxArray *c5_c_y = NULL;
  uint8_T c5_c_hoistedGlobal;
  uint8_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  uint8_T *c5_is_active_c5_twa_parallel;
  real_T (*c5_rm2w)[9];
  real_T (*c5_eq_start)[3];
  c5_eq_start = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_rm2w = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_is_active_c5_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(3));
  for (c5_i0 = 0; c5_i0 < 3; c5_i0 = c5_i0 + 1) {
    c5_hoistedGlobal[c5_i0] = (*c5_eq_start)[c5_i0];
  }

  for (c5_i1 = 0; c5_i1 < 3; c5_i1 = c5_i1 + 1) {
    c5_u[c5_i1] = c5_hoistedGlobal[c5_i1];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  for (c5_i2 = 0; c5_i2 < 9; c5_i2 = c5_i2 + 1) {
    c5_b_hoistedGlobal[c5_i2] = (*c5_rm2w)[c5_i2];
  }

  for (c5_i3 = 0; c5_i3 < 9; c5_i3 = c5_i3 + 1) {
    c5_b_u[c5_i3] = c5_b_hoistedGlobal[c5_i3];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_is_active_c5_twa_parallel;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 2, c5_d_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[3];
  int32_T c5_i4;
  real_T c5_dv1[9];
  int32_T c5_i5;
  boolean_T *c5_doneDoubleBufferReInit;
  uint8_T *c5_is_active_c5_twa_parallel;
  real_T (*c5_eq_start)[3];
  real_T (*c5_rm2w)[9];
  c5_eq_start = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_rm2w = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_is_active_c5_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c5_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                      "eq_start", c5_dv0);
  for (c5_i4 = 0; c5_i4 < 3; c5_i4 = c5_i4 + 1) {
    (*c5_eq_start)[c5_i4] = c5_dv0[c5_i4];
  }

  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
                        "rm2w", c5_dv1);
  for (c5_i5 = 0; c5_i5 < 9; c5_i5 = c5_i5 + 1) {
    (*c5_rm2w)[c5_i5] = c5_dv1[c5_i5];
  }

  *c5_is_active_c5_twa_parallel = c5_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 2)),
    "is_active_c5_twa_parallel");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_twa_parallel(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_twa_parallel(SFc5_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void sf_c5_twa_parallel(SFc5_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_previousEvent;
  real_T *c5_ee_rot;
  real_T (*c5_meas_macro_len)[3];
  real_T (*c5_b_in_w)[9];
  real_T (*c5_eq_start)[3];
  real_T (*c5_p_in_m)[9];
  real_T (*c5_rm2w)[9];
  c5_meas_macro_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
  c5_eq_start = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_p_in_m = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c5_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_rm2w = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,4);
  for (c5_i6 = 0; c5_i6 < 9; c5_i6 = c5_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_rm2w)[c5_i6], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_ee_rot, 1U);
  for (c5_i7 = 0; c5_i7 < 9; c5_i7 = c5_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_p_in_m)[c5_i7], 2U);
  }

  for (c5_i8 = 0; c5_i8 < 3; c5_i8 = c5_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_eq_start)[c5_i8], 3U);
  }

  for (c5_i9 = 0; c5_i9 < 9; c5_i9 = c5_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_in_w)[c5_i9], 4U);
  }

  for (c5_i10 = 0; c5_i10 < 3; c5_i10 = c5_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_meas_macro_len)[c5_i10], 5U);
  }

  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c5_c5_twa_parallel(chartInstance);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_twa_parallelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_c5_twa_parallel(SFc5_twa_parallelInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  int32_T c5_i11;
  real_T c5_b_hoistedGlobal[9];
  int32_T c5_i12;
  real_T c5_c_hoistedGlobal[9];
  int32_T c5_i13;
  real_T c5_d_hoistedGlobal[3];
  real_T c5_ee_rot;
  int32_T c5_i14;
  real_T c5_p_in_m[9];
  int32_T c5_i15;
  real_T c5_b_in_w[9];
  int32_T c5_i16;
  real_T c5_meas_macro_len[3];
  uint32_T c5_debug_family_var_map[10];
  static const char *c5_sv0[10] = { "p_in_w", "qnom", "nargin", "nargout",
    "ee_rot", "p_in_m", "b_in_w", "meas_macro_len", "rm2w",
    "eq_start" };

  real_T c5_p_in_w[9];
  real_T c5_qnom[3];
  real_T c5_nargin = 4.0;
  real_T c5_nargout = 2.0;
  real_T c5_rm2w[9];
  real_T c5_eq_start[3];
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  int32_T c5_i17;
  int32_T c5_i18;
  static real_T c5_dv2[3] = { 0.0, 0.0, 1.0 };

  int32_T c5_i19;
  real_T c5_a[9];
  int32_T c5_i20;
  real_T c5_b[9];
  int32_T c5_i21;
  real_T c5_A[9];
  int32_T c5_i22;
  real_T c5_B[9];
  int32_T c5_i23;
  real_T c5_b_A[9];
  int32_T c5_i24;
  real_T c5_b_B[9];
  int32_T c5_i25;
  real_T c5_c_A[9];
  int32_T c5_i26;
  real_T c5_c_B[9];
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  real_T c5_y[9];
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  real_T c5_b_p_in_w[3];
  int32_T c5_i35;
  real_T c5_c_p_in_w[3];
  int32_T c5_i36;
  real_T c5_d_p_in_w[3];
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  real_T *c5_b_ee_rot;
  real_T (*c5_b_rm2w)[9];
  real_T (*c5_b_eq_start)[3];
  real_T (*c5_b_meas_macro_len)[3];
  real_T (*c5_b_b_in_w)[9];
  real_T (*c5_b_p_in_m)[9];
  c5_b_meas_macro_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_b_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_eq_start = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_p_in_m = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_b_rm2w = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,4);
  c5_hoistedGlobal = *c5_b_ee_rot;
  for (c5_i11 = 0; c5_i11 < 9; c5_i11 = c5_i11 + 1) {
    c5_b_hoistedGlobal[c5_i11] = (*c5_b_p_in_m)[c5_i11];
  }

  for (c5_i12 = 0; c5_i12 < 9; c5_i12 = c5_i12 + 1) {
    c5_c_hoistedGlobal[c5_i12] = (*c5_b_b_in_w)[c5_i12];
  }

  for (c5_i13 = 0; c5_i13 < 3; c5_i13 = c5_i13 + 1) {
    c5_d_hoistedGlobal[c5_i13] = (*c5_b_meas_macro_len)[c5_i13];
  }

  c5_ee_rot = c5_hoistedGlobal;
  for (c5_i14 = 0; c5_i14 < 9; c5_i14 = c5_i14 + 1) {
    c5_p_in_m[c5_i14] = c5_b_hoistedGlobal[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 9; c5_i15 = c5_i15 + 1) {
    c5_b_in_w[c5_i15] = c5_c_hoistedGlobal[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 3; c5_i16 = c5_i16 + 1) {
    c5_meas_macro_len[c5_i16] = c5_d_hoistedGlobal[c5_i16];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c5_sv0, c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c5_p_in_w, c5_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c5_qnom, c5_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c5_nargin, c5_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c5_nargout, c5_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c5_ee_rot, c5_c_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c5_p_in_m, c5_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c5_b_in_w, c5_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c5_meas_macro_len, c5_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c5_rm2w, c5_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c5_eq_start, c5_sf_marshall, 9U);
  CV_EML_FCN(0, 0);

  /* this function calculates the error in leg lengths for the first iteration */
  /*  of the resolved rates initialization process */
  _SFD_EML_CALL(0,5);
  c5_x = c5_ee_rot;
  c5_b_x = c5_x;
  c5_c_x = c5_b_x;
  c5_b_x = c5_c_x;
  c5_b_x = muDoubleScalarCos(c5_b_x);
  c5_d_x = c5_ee_rot;
  c5_e_x = c5_d_x;
  c5_f_x = c5_e_x;
  c5_e_x = c5_f_x;
  c5_e_x = muDoubleScalarSin(c5_e_x);
  c5_g_x = c5_ee_rot;
  c5_h_x = c5_g_x;
  c5_i_x = c5_h_x;
  c5_h_x = c5_i_x;
  c5_h_x = muDoubleScalarSin(c5_h_x);
  c5_j_x = c5_ee_rot;
  c5_k_x = c5_j_x;
  c5_l_x = c5_k_x;
  c5_k_x = c5_l_x;
  c5_k_x = muDoubleScalarCos(c5_k_x);
  c5_rm2w[0] = c5_b_x;
  c5_rm2w[3] = -c5_e_x;
  c5_rm2w[6] = 0.0;
  c5_rm2w[1] = c5_h_x;
  c5_rm2w[4] = c5_k_x;
  c5_rm2w[7] = 0.0;
  c5_i17 = 0;
  for (c5_i18 = 0; c5_i18 < 3; c5_i18 = c5_i18 + 1) {
    c5_rm2w[c5_i17 + 2] = c5_dv2[c5_i18];
    c5_i17 = c5_i17 + 3;
  }

  /*  moving platform starts at the origin with 30 degree rotation */
  _SFD_EML_CALL(0,8);
  for (c5_i19 = 0; c5_i19 < 9; c5_i19 = c5_i19 + 1) {
    c5_a[c5_i19] = c5_rm2w[c5_i19];
  }

  for (c5_i20 = 0; c5_i20 < 9; c5_i20 = c5_i20 + 1) {
    c5_b[c5_i20] = c5_p_in_m[c5_i20];
  }

  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  for (c5_i21 = 0; c5_i21 < 9; c5_i21 = c5_i21 + 1) {
    c5_A[c5_i21] = c5_a[c5_i21];
  }

  for (c5_i22 = 0; c5_i22 < 9; c5_i22 = c5_i22 + 1) {
    c5_B[c5_i22] = c5_b[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 9; c5_i23 = c5_i23 + 1) {
    c5_b_A[c5_i23] = c5_A[c5_i23];
  }

  for (c5_i24 = 0; c5_i24 < 9; c5_i24 = c5_i24 + 1) {
    c5_b_B[c5_i24] = c5_B[c5_i24];
  }

  for (c5_i25 = 0; c5_i25 < 9; c5_i25 = c5_i25 + 1) {
    c5_c_A[c5_i25] = c5_b_A[c5_i25];
  }

  for (c5_i26 = 0; c5_i26 < 9; c5_i26 = c5_i26 + 1) {
    c5_c_B[c5_i26] = c5_b_B[c5_i26];
  }

  for (c5_i27 = 0; c5_i27 < 3; c5_i27 = c5_i27 + 1) {
    c5_i28 = 0;
    for (c5_i29 = 0; c5_i29 < 3; c5_i29 = c5_i29 + 1) {
      c5_y[c5_i28 + c5_i27] = 0.0;
      c5_i30 = 0;
      for (c5_i31 = 0; c5_i31 < 3; c5_i31 = c5_i31 + 1) {
        c5_y[c5_i28 + c5_i27] = c5_y[c5_i28 + c5_i27] + c5_c_A[c5_i30 + c5_i27] *
          c5_c_B[c5_i31 + c5_i28];
        c5_i30 = c5_i30 + 3;
      }

      c5_i28 = c5_i28 + 3;
    }
  }

  for (c5_i32 = 0; c5_i32 < 9; c5_i32 = c5_i32 + 1) {
    c5_p_in_w[c5_i32] = c5_y[c5_i32];
  }

  _SFD_EML_CALL(0,10);
  for (c5_i33 = 0; c5_i33 < 3; c5_i33 = c5_i33 + 1) {
    c5_qnom[c5_i33] = 0.0;
  }

  _SFD_EML_CALL(0,11);
  for (c5_i34 = 0; c5_i34 < 3; c5_i34 = c5_i34 + 1) {
    c5_b_p_in_w[c5_i34] = c5_p_in_w[c5_i34] - c5_b_in_w[c5_i34];
  }

  c5_qnom[0] = c5_norm(chartInstance, c5_b_p_in_w);
  _SFD_EML_CALL(0,12);
  for (c5_i35 = 0; c5_i35 < 3; c5_i35 = c5_i35 + 1) {
    c5_c_p_in_w[c5_i35] = c5_p_in_w[c5_i35 + 3] - c5_b_in_w[c5_i35 + 3];
  }

  c5_qnom[1] = c5_norm(chartInstance, c5_c_p_in_w);
  _SFD_EML_CALL(0,13);
  for (c5_i36 = 0; c5_i36 < 3; c5_i36 = c5_i36 + 1) {
    c5_d_p_in_w[c5_i36] = c5_p_in_w[c5_i36 + 6] - c5_b_in_w[c5_i36 + 6];
  }

  c5_qnom[2] = c5_norm(chartInstance, c5_d_p_in_w);
  _SFD_EML_CALL(0,14);
  for (c5_i37 = 0; c5_i37 < 3; c5_i37 = c5_i37 + 1) {
    c5_eq_start[c5_i37] = c5_meas_macro_len[c5_i37] - c5_qnom[c5_i37];
  }

  _SFD_EML_CALL(0,-14);
  sf_debug_symbol_scope_pop();
  for (c5_i38 = 0; c5_i38 < 9; c5_i38 = c5_i38 + 1) {
    (*c5_b_rm2w)[c5_i38] = c5_rm2w[c5_i38];
  }

  for (c5_i39 = 0; c5_i39 < 3; c5_i39 = c5_i39 + 1) {
    (*c5_b_eq_start)[c5_i39] = c5_eq_start[c5_i39];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static void c5_eml_scalar_eg(SFc5_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c5_norm(SFc5_twa_parallelInstanceStruct *chartInstance, real_T
                      c5_x[3])
{
  int32_T c5_i40;
  real_T c5_b_x[3];
  int32_T c5_i41;
  real_T c5_c_x[3];
  int32_T c5_i42;
  real_T c5_d_x[3];
  int32_T c5_i43;
  real_T c5_e_x[3];
  for (c5_i40 = 0; c5_i40 < 3; c5_i40 = c5_i40 + 1) {
    c5_b_x[c5_i40] = c5_x[c5_i40];
  }

  for (c5_i41 = 0; c5_i41 < 3; c5_i41 = c5_i41 + 1) {
    c5_c_x[c5_i41] = c5_b_x[c5_i41];
  }

  for (c5_i42 = 0; c5_i42 < 3; c5_i42 = c5_i42 + 1) {
    c5_d_x[c5_i42] = c5_c_x[c5_i42];
  }

  for (c5_i43 = 0; c5_i43 < 3; c5_i43 = c5_i43 + 1) {
    c5_e_x[c5_i43] = c5_d_x[c5_i43];
  }

  return c5_ceval_xnrm2(chartInstance, 3, c5_e_x, 1, 1);
}

static real_T c5_ceval_xnrm2(SFc5_twa_parallelInstanceStruct *chartInstance,
  int32_T c5_n, real_T c5_x[3], int32_T c5_ix0, int32_T
  c5_incx)
{
  return dnrm232(&c5_n, &c5_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c5_ix0), 1, 3, 1, 0) - 1], &
                 c5_incx);
}

static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i44;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  SFc5_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc5_twa_parallelInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i44 = 0; c5_i44 < 3; c5_i44 = c5_i44 + 1) {
    c5_b_u[c5_i44] = (*((real_T (*)[3])c5_u))[c5_i44];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  real_T c5_b_u[9];
  const mxArray *c5_b_y = NULL;
  SFc5_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc5_twa_parallelInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_i45 = 0;
  for (c5_i46 = 0; c5_i46 < 3; c5_i46 = c5_i46 + 1) {
    for (c5_i47 = 0; c5_i47 < 3; c5_i47 = c5_i47 + 1) {
      c5_b_u[c5_i47 + c5_i45] = (*((real_T (*)[9])c5_u))[c5_i47 + c5_i45];
    }

    c5_i45 = c5_i45 + 3;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc5_twa_parallelInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_twa_parallel_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[54];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i48;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 54));
  for (c5_i48 = 0; c5_i48 < 54; c5_i48 = c5_i48 + 1) {
    c5_r0 = &c5_info[c5_i48];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
                    "nameCaptureInfo", c5_i48);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name",
                    "nameCaptureInfo", c5_i48);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c5_i48);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c5_i48);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c5_i48);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i48
                    );
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i48
                    );
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[54])
{
  c5_info[0].context = "";
  c5_info[0].name = "cos";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[0].fileLength = 324U;
  c5_info[0].fileTime1 = 1203473150U;
  c5_info[0].fileTime2 = 0U;
  c5_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[1].name = "nargin";
  c5_info[1].dominantType = "";
  c5_info[1].resolved = "[B]nargin";
  c5_info[1].fileLength = 0U;
  c5_info[1].fileTime1 = 0U;
  c5_info[1].fileTime2 = 0U;
  c5_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[2].name = "gt";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved = "[B]gt";
  c5_info[2].fileLength = 0U;
  c5_info[2].fileTime1 = 0U;
  c5_info[2].fileTime2 = 0U;
  c5_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[3].name = "isa";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[B]isa";
  c5_info[3].fileLength = 0U;
  c5_info[3].fileTime1 = 0U;
  c5_info[3].fileTime2 = 0U;
  c5_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[4].name = "eml_scalar_cos";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c5_info[4].fileLength = 602U;
  c5_info[4].fileTime1 = 1209355986U;
  c5_info[4].fileTime2 = 0U;
  c5_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c5_info[5].name = "isreal";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved = "[B]isreal";
  c5_info[5].fileLength = 0U;
  c5_info[5].fileTime1 = 0U;
  c5_info[5].fileTime2 = 0U;
  c5_info[6].context = "";
  c5_info[6].name = "sin";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[6].fileLength = 324U;
  c5_info[6].fileTime1 = 1203473242U;
  c5_info[6].fileTime2 = 0U;
  c5_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[7].name = "eml_scalar_sin";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c5_info[7].fileLength = 601U;
  c5_info[7].fileTime1 = 1209355990U;
  c5_info[7].fileTime2 = 0U;
  c5_info[8].context = "";
  c5_info[8].name = "uminus";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[B]uminus";
  c5_info[8].fileLength = 0U;
  c5_info[8].fileTime1 = 0U;
  c5_info[8].fileTime2 = 0U;
  c5_info[9].context = "";
  c5_info[9].name = "zeros";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved = "[B]zeros";
  c5_info[9].fileLength = 0U;
  c5_info[9].fileTime1 = 0U;
  c5_info[9].fileTime2 = 0U;
  c5_info[10].context = "";
  c5_info[10].name = "mtimes";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[10].fileLength = 3425U;
  c5_info[10].fileTime1 = 1250697966U;
  c5_info[10].fileTime2 = 0U;
  c5_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[11].name = "isinteger";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved = "[B]isinteger";
  c5_info[11].fileLength = 0U;
  c5_info[11].fileTime1 = 0U;
  c5_info[11].fileTime2 = 0U;
  c5_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[12].name = "isscalar";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved = "[B]isscalar";
  c5_info[12].fileLength = 0U;
  c5_info[12].fileTime1 = 0U;
  c5_info[12].fileTime2 = 0U;
  c5_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[13].name = "ndims";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved = "[B]ndims";
  c5_info[13].fileLength = 0U;
  c5_info[13].fileTime1 = 0U;
  c5_info[13].fileTime2 = 0U;
  c5_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[14].name = "le";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved = "[B]le";
  c5_info[14].fileLength = 0U;
  c5_info[14].fileTime1 = 0U;
  c5_info[14].fileTime2 = 0U;
  c5_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[15].name = "size";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved = "[B]size";
  c5_info[15].fileLength = 0U;
  c5_info[15].fileTime1 = 0U;
  c5_info[15].fileTime2 = 0U;
  c5_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[16].name = "eq";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved = "[B]eq";
  c5_info[16].fileLength = 0U;
  c5_info[16].fileTime1 = 0U;
  c5_info[16].fileTime2 = 0U;
  c5_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[17].name = "not";
  c5_info[17].dominantType = "logical";
  c5_info[17].resolved = "[B]not";
  c5_info[17].fileLength = 0U;
  c5_info[17].fileTime1 = 0U;
  c5_info[17].fileTime2 = 0U;
  c5_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[18].name = "strcmp";
  c5_info[18].dominantType = "char";
  c5_info[18].resolved = "[B]strcmp";
  c5_info[18].fileLength = 0U;
  c5_info[18].fileTime1 = 0U;
  c5_info[18].fileTime2 = 0U;
  c5_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[19].name = "class";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved = "[B]class";
  c5_info[19].fileLength = 0U;
  c5_info[19].fileTime1 = 0U;
  c5_info[19].fileTime2 = 0U;
  c5_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[20].name = "ne";
  c5_info[20].dominantType = "logical";
  c5_info[20].resolved = "[B]ne";
  c5_info[20].fileLength = 0U;
  c5_info[20].fileTime1 = 0U;
  c5_info[20].fileTime2 = 0U;
  c5_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[21].name = "eml_index_class";
  c5_info[21].dominantType = "";
  c5_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[21].fileLength = 909U;
  c5_info[21].fileTime1 = 1192491982U;
  c5_info[21].fileTime2 = 0U;
  c5_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[22].name = "ones";
  c5_info[22].dominantType = "char";
  c5_info[22].resolved = "[B]ones";
  c5_info[22].fileLength = 0U;
  c5_info[22].fileTime1 = 0U;
  c5_info[22].fileTime2 = 0U;
  c5_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[23].name = "cast";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved = "[B]cast";
  c5_info[23].fileLength = 0U;
  c5_info[23].fileTime1 = 0U;
  c5_info[23].fileTime2 = 0U;
  c5_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[24].name = "eml_scalar_eg";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[24].fileLength = 3068U;
  c5_info[24].fileTime1 = 1240287210U;
  c5_info[24].fileTime2 = 0U;
  c5_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c5_info[25].name = "false";
  c5_info[25].dominantType = "";
  c5_info[25].resolved = "[B]false";
  c5_info[25].fileLength = 0U;
  c5_info[25].fileTime1 = 0U;
  c5_info[25].fileTime2 = 0U;
  c5_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[26].name = "isstruct";
  c5_info[26].dominantType = "double";
  c5_info[26].resolved = "[B]isstruct";
  c5_info[26].fileLength = 0U;
  c5_info[26].fileTime1 = 0U;
  c5_info[26].fileTime2 = 0U;
  c5_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c5_info[27].name = "plus";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved = "[B]plus";
  c5_info[27].fileLength = 0U;
  c5_info[27].fileTime1 = 0U;
  c5_info[27].fileTime2 = 0U;
  c5_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[28].name = "isempty";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved = "[B]isempty";
  c5_info[28].fileLength = 0U;
  c5_info[28].fileTime1 = 0U;
  c5_info[28].fileTime2 = 0U;
  c5_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[29].name = "eml_xgemm";
  c5_info[29].dominantType = "int32";
  c5_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[29].fileLength = 3184U;
  c5_info[29].fileTime1 = 1209356052U;
  c5_info[29].fileTime2 = 0U;
  c5_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[30].name = "lt";
  c5_info[30].dominantType = "int32";
  c5_info[30].resolved = "[B]lt";
  c5_info[30].fileLength = 0U;
  c5_info[30].fileTime1 = 0U;
  c5_info[30].fileTime2 = 0U;
  c5_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c5_info[31].name = "length";
  c5_info[31].dominantType = "double";
  c5_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c5_info[31].fileLength = 326U;
  c5_info[31].fileTime1 = 1226602474U;
  c5_info[31].fileTime2 = 0U;
  c5_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c5_info[32].name = "min";
  c5_info[32].dominantType = "double";
  c5_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[32].fileLength = 362U;
  c5_info[32].fileTime1 = 1244760752U;
  c5_info[32].fileTime2 = 0U;
  c5_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[33].name = "nargout";
  c5_info[33].dominantType = "";
  c5_info[33].resolved = "[B]nargout";
  c5_info[33].fileLength = 0U;
  c5_info[33].fileTime1 = 0U;
  c5_info[33].fileTime2 = 0U;
  c5_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[34].name = "eml_min_or_max";
  c5_info[34].dominantType = "char";
  c5_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[34].fileLength = 9969U;
  c5_info[34].fileTime1 = 1240287206U;
  c5_info[34].fileTime2 = 0U;
  c5_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[35].name = "ischar";
  c5_info[35].dominantType = "char";
  c5_info[35].resolved = "[B]ischar";
  c5_info[35].fileLength = 0U;
  c5_info[35].fileTime1 = 0U;
  c5_info[35].fileTime2 = 0U;
  c5_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[36].name = "isnumeric";
  c5_info[36].dominantType = "double";
  c5_info[36].resolved = "[B]isnumeric";
  c5_info[36].fileLength = 0U;
  c5_info[36].fileTime1 = 0U;
  c5_info[36].fileTime2 = 0U;
  c5_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c5_info[37].name = "islogical";
  c5_info[37].dominantType = "double";
  c5_info[37].resolved = "[B]islogical";
  c5_info[37].fileLength = 0U;
  c5_info[37].fileTime1 = 0U;
  c5_info[37].fileTime2 = 0U;
  c5_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c5_info[38].name = "eml_scalexp_alloc";
  c5_info[38].dominantType = "double";
  c5_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[38].fileLength = 808U;
  c5_info[38].fileTime1 = 1230519898U;
  c5_info[38].fileTime2 = 0U;
  c5_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[39].name = "minus";
  c5_info[39].dominantType = "double";
  c5_info[39].resolved = "[B]minus";
  c5_info[39].fileLength = 0U;
  c5_info[39].fileTime1 = 0U;
  c5_info[39].fileTime2 = 0U;
  c5_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[40].name = "eml_refblas_xgemm";
  c5_info[40].dominantType = "int32";
  c5_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c5_info[40].fileLength = 5748U;
  c5_info[40].fileTime1 = 1228119072U;
  c5_info[40].fileTime2 = 0U;
  c5_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c5_info[41].name = "eml_index_minus";
  c5_info[41].dominantType = "int32";
  c5_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c5_info[41].fileLength = 277U;
  c5_info[41].fileTime1 = 1192491984U;
  c5_info[41].fileTime2 = 0U;
  c5_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c5_info[42].name = "eml_index_times";
  c5_info[42].dominantType = "int32";
  c5_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c5_info[42].fileLength = 280U;
  c5_info[42].fileTime1 = 1192491986U;
  c5_info[42].fileTime2 = 0U;
  c5_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c5_info[43].name = "eml_index_plus";
  c5_info[43].dominantType = "int32";
  c5_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[43].fileLength = 272U;
  c5_info[43].fileTime1 = 1192491984U;
  c5_info[43].fileTime2 = 0U;
  c5_info[44].context = "";
  c5_info[44].name = "norm";
  c5_info[44].dominantType = "double";
  c5_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c5_info[44].fileLength = 5312U;
  c5_info[44].fileTime1 = 1262645476U;
  c5_info[44].fileTime2 = 0U;
  c5_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c5_info[45].name = "isvector";
  c5_info[45].dominantType = "double";
  c5_info[45].resolved = "[B]isvector";
  c5_info[45].fileLength = 0U;
  c5_info[45].fileTime1 = 0U;
  c5_info[45].fileTime2 = 0U;
  c5_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c5_info[46].name = "eml_xnrm2";
  c5_info[46].dominantType = "int32";
  c5_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c5_info[46].fileLength = 718U;
  c5_info[46].fileTime1 = 1209356056U;
  c5_info[46].fileTime2 = 0U;
  c5_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c5_info[47].name = "eml_refblas_xnrm2";
  c5_info[47].dominantType = "int32";
  c5_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c5_info[47].fileLength = 1433U;
  c5_info[47].fileTime1 = 1240287242U;
  c5_info[47].fileTime2 = 0U;
  c5_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c5_info[48].name = "true";
  c5_info[48].dominantType = "";
  c5_info[48].resolved = "[B]true";
  c5_info[48].fileLength = 0U;
  c5_info[48].fileTime1 = 0U;
  c5_info[48].fileTime2 = 0U;
  c5_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c5_info[49].name = "real";
  c5_info[49].dominantType = "double";
  c5_info[49].resolved = "[B]real";
  c5_info[49].fileLength = 0U;
  c5_info[49].fileTime1 = 0U;
  c5_info[49].fileTime2 = 0U;
  c5_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c5_info[50].name = "abs";
  c5_info[50].dominantType = "double";
  c5_info[50].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[50].fileLength = 566U;
  c5_info[50].fileTime1 = 1221292332U;
  c5_info[50].fileTime2 = 0U;
  c5_info[51].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[51].name = "eml_scalar_abs";
  c5_info[51].dominantType = "double";
  c5_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[51].fileLength = 461U;
  c5_info[51].fileTime1 = 1203473160U;
  c5_info[51].fileTime2 = 0U;
  c5_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c5_info[52].name = "times";
  c5_info[52].dominantType = "double";
  c5_info[52].resolved = "[B]times";
  c5_info[52].fileLength = 0U;
  c5_info[52].fileTime1 = 0U;
  c5_info[52].fileTime2 = 0U;
  c5_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c5_info[53].name = "imag";
  c5_info[53].dominantType = "double";
  c5_info[53].resolved = "[B]imag";
  c5_info[53].fileLength = 0U;
  c5_info[53].fileTime1 = 0U;
  c5_info[53].fileTime2 = 0U;
}

static const mxArray *c5_d_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  boolean_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc5_twa_parallelInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((boolean_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static void c5_emlrt_marshallIn(SFc5_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c5_eq_start, const char_T *c5_name,
  real_T c5_y[3])
{
  real_T c5_dv3[3];
  int32_T c5_i49;
  sf_mex_import(c5_name, sf_mex_dup(c5_eq_start), &c5_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c5_i49 = 0; c5_i49 < 3; c5_i49 = c5_i49 + 1) {
    c5_y[c5_i49] = c5_dv3[c5_i49];
  }

  sf_mex_destroy(&c5_eq_start);
}

static void c5_b_emlrt_marshallIn(SFc5_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c5_rm2w, const char_T *c5_name,
  real_T c5_y[9])
{
  real_T c5_dv4[9];
  int32_T c5_i50;
  sf_mex_import(c5_name, sf_mex_dup(c5_rm2w), &c5_dv4, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c5_i50 = 0; c5_i50 < 9; c5_i50 = c5_i50 + 1) {
    c5_y[c5_i50] = c5_dv4[c5_i50];
  }

  sf_mex_destroy(&c5_rm2w);
}

static uint8_T c5_c_emlrt_marshallIn(SFc5_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c5_is_active_c5_twa_parallel,
  const char_T *c5_name)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_name, sf_mex_dup(c5_is_active_c5_twa_parallel), &c5_u0, 1, 3,
                0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_is_active_c5_twa_parallel);
  return c5_y;
}

static void init_dsm_address_info(SFc5_twa_parallelInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_twa_parallel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2906016210U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2342936829U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3685695991U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3268194822U);
}

mxArray *sf_c5_twa_parallel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3300087892U);
    pr[1] = (double)(2548106810U);
    pr[2] = (double)(3862367799U);
    pr[3] = (double)(3342054405U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[1] = (double)(3);
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
      pr[1] = (double)(3);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c5_twa_parallel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"eq_start\",},{M[1],M[9],T\"rm2w\",},{M[8],M[0],T\"is_active_c5_twa_parallel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_twa_parallel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_twa_parallelInstanceStruct *chartInstance;
    chartInstance = (SFc5_twa_parallelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_twa_parallelMachineNumber_,
           5,
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
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"rm2w",0,(MexFcnForType)c5_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"ee_rot",
                              0,(MexFcnForType)c5_c_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"p_in_m",0,(MexFcnForType)c5_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"eq_start",0,(MexFcnForType)c5_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"b_in_w",0,(MexFcnForType)c5_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"meas_macro_len",0,(MexFcnForType)
                                c5_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",122,-1,553);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c5_rm2w)[9];
          real_T *c5_ee_rot;
          real_T (*c5_p_in_m)[9];
          real_T (*c5_eq_start)[3];
          real_T (*c5_b_in_w)[9];
          real_T (*c5_meas_macro_len)[3];
          c5_meas_macro_len = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 3);
          c5_b_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
          c5_eq_start = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c5_p_in_m = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c5_ee_rot = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c5_rm2w = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_rm2w);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_ee_rot);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_p_in_m);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_eq_start);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_b_in_w);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_meas_macro_len);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_twa_parallelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_twa_parallel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_twa_parallelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*)
    chartInstanceVar);
  initialize_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_twa_parallel(void *chartInstanceVar)
{
  enable_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_twa_parallel(void *chartInstanceVar)
{
  disable_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_twa_parallel(void *chartInstanceVar)
{
  sf_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c5_twa_parallel(void *chartInstanceVar)
{
  ext_mode_exec_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c5_twa_parallel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_twa_parallel
    ((SFc5_twa_parallelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c5_twa_parallel();/* state var info */
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

static void sf_internal_set_sim_state_c5_twa_parallel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_twa_parallel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c5_twa_parallel(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_twa_parallel(S);
}

static void sf_opaque_set_sim_state_c5_twa_parallel(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c5_twa_parallel(S, st);
}

static void sf_opaque_terminate_c5_twa_parallel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_twa_parallelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_twa_parallel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_twa_parallel((SFc5_twa_parallelInstanceStruct*)
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

static void mdlSetWorkWidths_c5_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("twa_parallel","twa_parallel",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("twa_parallel","twa_parallel",5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("twa_parallel",
      "twa_parallel",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"twa_parallel","twa_parallel",5,4);
      sf_mark_chart_reusable_outputs(S,"twa_parallel","twa_parallel",5,2);
    }

    sf_set_rtw_dwork_info(S,"twa_parallel","twa_parallel",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3740365419U));
  ssSetChecksum1(S,(3588126277U));
  ssSetChecksum2(S,(123565448U));
  ssSetChecksum3(S,(2295459585U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "twa_parallel", "twa_parallel",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_twa_parallel(SimStruct *S)
{
  SFc5_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc5_twa_parallelInstanceStruct *)malloc(sizeof
    (SFc5_twa_parallelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_twa_parallelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_twa_parallel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_twa_parallel;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_twa_parallel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_twa_parallel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_twa_parallel;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_twa_parallel;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_twa_parallel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_twa_parallel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_twa_parallel;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_twa_parallel;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_twa_parallel;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c5_twa_parallel;
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

void c5_twa_parallel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_twa_parallel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_twa_parallel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_twa_parallel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_twa_parallel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
