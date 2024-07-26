/* Include files */

#include "blascompat32.h"
#include "twa_parallel_sfun.h"
#include "c3_twa_parallel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "twa_parallel_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c3_debug_family_names[34] = { "z0", "p_in_w", "n1hat",
  "n2hat", "n3hat", "a13", "a23", "a33", "jac", "qdot", "tdot", "v", "w",
  "del_r", "i", "nargin", "nargout", "qcur", "eqeps", "kp", "dt", "p_in_m",
  "b_in_w", "measured_len", "velmex_pitch", "macro_leg_len", "eq", "twave",
  "rwave", "qcmd", "des_leg_len", "eq_out", "twave_out", "rwave_out" };

/* Function Declarations */
static void initialize_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance);
static void initialize_params_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance);
static void enable_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance);
static void disable_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_twa_parallel
  (SFc3_twa_parallelInstanceStruct *chartInstance);
static void ext_mode_exec_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_twa_parallel
  (SFc3_twa_parallelInstanceStruct *chartInstance);
static void set_sim_state_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance);
static void sf_c3_twa_parallel(SFc3_twa_parallelInstanceStruct *chartInstance);
static void c3_c3_twa_parallel(SFc3_twa_parallelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static void c3_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static real_T c3_norm(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                      c3_x[3]);
static real_T c3_ceval_xnrm2(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T c3_incx);
static void c3_b_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static void c3_cross(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                     c3_a[3], real_T c3_b[3], real_T c3_c[3]);
static void c3_c_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static real_T c3_ceval_xdot(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T c3_incx, real_T c3_y[3],
  int32_T c3_iy0, int32_T c3_incy);
static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_c_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_d_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_e_sf_marshall(void *chartInstanceVoid, void *c3_u);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[66]);
static const mxArray *c3_f_sf_marshall(void *chartInstanceVoid, void *c3_u);
static void c3_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c3_des_leg_len, const char_T *c3_name, real_T c3_y[3]);
static void c3_b_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c3_qcmd, const char_T *c3_name, real_T c3_y[6]);
static void c3_c_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c3_rwave_out, const char_T *c3_name, real_T c3_y[9]);
static uint8_T c3_d_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c3_is_active_c3_twa_parallel, const char_T
  *c3_name);
static void init_dsm_address_info(SFc3_twa_parallelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance)
{
  uint8_T *c3_is_active_c3_twa_parallel;
  c3_is_active_c3_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c3_is_active_c3_twa_parallel = 0U;
}

static void initialize_params_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void enable_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_twa_parallel
  (SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance)
{
  c3_update_debugger_state_c3_twa_parallel(chartInstance);
}

static const mxArray *get_sim_state_c3_twa_parallel
  (SFc3_twa_parallelInstanceStruct *chartInstance)
{
  const mxArray *c3_st = NULL;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_hoistedGlobal[3];
  int32_T c3_i1;
  real_T c3_u[3];
  const mxArray *c3_b_y = NULL;
  int32_T c3_i2;
  real_T c3_b_hoistedGlobal[3];
  int32_T c3_i3;
  real_T c3_b_u[3];
  const mxArray *c3_c_y = NULL;
  int32_T c3_i4;
  real_T c3_c_hoistedGlobal[6];
  int32_T c3_i5;
  real_T c3_c_u[6];
  const mxArray *c3_d_y = NULL;
  int32_T c3_i6;
  real_T c3_d_hoistedGlobal[9];
  int32_T c3_i7;
  real_T c3_d_u[9];
  const mxArray *c3_e_y = NULL;
  int32_T c3_i8;
  real_T c3_e_hoistedGlobal[3];
  int32_T c3_i9;
  real_T c3_e_u[3];
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T *c3_is_active_c3_twa_parallel;
  real_T (*c3_twave_out)[3];
  real_T (*c3_rwave_out)[9];
  real_T (*c3_qcmd)[6];
  real_T (*c3_eq_out)[3];
  real_T (*c3_des_leg_len)[3];
  c3_rwave_out = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_twave_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c3_eq_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_des_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_qcmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(6));
  for (c3_i0 = 0; c3_i0 < 3; c3_i0 = c3_i0 + 1) {
    c3_hoistedGlobal[c3_i0] = (*c3_des_leg_len)[c3_i0];
  }

  for (c3_i1 = 0; c3_i1 < 3; c3_i1 = c3_i1 + 1) {
    c3_u[c3_i1] = c3_hoistedGlobal[c3_i1];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i2 = 0; c3_i2 < 3; c3_i2 = c3_i2 + 1) {
    c3_b_hoistedGlobal[c3_i2] = (*c3_eq_out)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 3; c3_i3 = c3_i3 + 1) {
    c3_b_u[c3_i3] = c3_b_hoistedGlobal[c3_i3];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  for (c3_i4 = 0; c3_i4 < 6; c3_i4 = c3_i4 + 1) {
    c3_c_hoistedGlobal[c3_i4] = (*c3_qcmd)[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 6; c3_i5 = c3_i5 + 1) {
    c3_c_u[c3_i5] = c3_c_hoistedGlobal[c3_i5];
  }

  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c3_y, 2, c3_d_y);
  for (c3_i6 = 0; c3_i6 < 9; c3_i6 = c3_i6 + 1) {
    c3_d_hoistedGlobal[c3_i6] = (*c3_rwave_out)[c3_i6];
  }

  for (c3_i7 = 0; c3_i7 < 9; c3_i7 = c3_i7 + 1) {
    c3_d_u[c3_i7] = c3_d_hoistedGlobal[c3_i7];
  }

  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_setcell(c3_y, 3, c3_e_y);
  for (c3_i8 = 0; c3_i8 < 3; c3_i8 = c3_i8 + 1) {
    c3_e_hoistedGlobal[c3_i8] = (*c3_twave_out)[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 3; c3_i9 = c3_i9 + 1) {
    c3_e_u[c3_i9] = c3_e_hoistedGlobal[c3_i9];
  }

  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_is_active_c3_twa_parallel;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 5, c3_g_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[3];
  int32_T c3_i10;
  real_T c3_dv1[3];
  int32_T c3_i11;
  real_T c3_dv2[6];
  int32_T c3_i12;
  real_T c3_dv3[9];
  int32_T c3_i13;
  real_T c3_dv4[3];
  int32_T c3_i14;
  boolean_T *c3_doneDoubleBufferReInit;
  uint8_T *c3_is_active_c3_twa_parallel;
  real_T (*c3_des_leg_len)[3];
  real_T (*c3_eq_out)[3];
  real_T (*c3_qcmd)[6];
  real_T (*c3_rwave_out)[9];
  real_T (*c3_twave_out)[3];
  c3_rwave_out = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_twave_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c3_eq_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_des_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_qcmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "des_leg_len", c3_dv0);
  for (c3_i10 = 0; c3_i10 < 3; c3_i10 = c3_i10 + 1) {
    (*c3_des_leg_len)[c3_i10] = c3_dv0[c3_i10];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                      "eq_out", c3_dv1);
  for (c3_i11 = 0; c3_i11 < 3; c3_i11 = c3_i11 + 1) {
    (*c3_eq_out)[c3_i11] = c3_dv1[c3_i11];
  }

  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
                        "qcmd", c3_dv2);
  for (c3_i12 = 0; c3_i12 < 6; c3_i12 = c3_i12 + 1) {
    (*c3_qcmd)[c3_i12] = c3_dv2[c3_i12];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
                        "rwave_out", c3_dv3);
  for (c3_i13 = 0; c3_i13 < 9; c3_i13 = c3_i13 + 1) {
    (*c3_rwave_out)[c3_i13] = c3_dv3[c3_i13];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
                      "twave_out", c3_dv4);
  for (c3_i14 = 0; c3_i14 < 3; c3_i14 = c3_i14 + 1) {
    (*c3_twave_out)[c3_i14] = c3_dv4[c3_i14];
  }

  *c3_is_active_c3_twa_parallel = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 5)),
    "is_active_c3_twa_parallel");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_twa_parallel(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_twa_parallel(SFc3_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void sf_c3_twa_parallel(SFc3_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_previousEvent;
  real_T *c3_eqeps;
  real_T *c3_kp;
  real_T *c3_dt;
  real_T *c3_velmex_pitch;
  real_T (*c3_rwave)[9];
  real_T (*c3_twave)[3];
  real_T (*c3_rwave_out)[9];
  real_T (*c3_twave_out)[3];
  real_T (*c3_eq_out)[3];
  real_T (*c3_eq)[3];
  real_T (*c3_macro_leg_len)[3];
  real_T (*c3_measured_len)[3];
  real_T (*c3_b_in_w)[9];
  real_T (*c3_p_in_m)[9];
  real_T (*c3_des_leg_len)[3];
  real_T (*c3_qcmd)[6];
  real_T (*c3_qcur)[6];
  c3_rwave = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 11);
  c3_twave = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 10);
  c3_rwave_out = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_twave_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c3_eq_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_eq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c3_macro_leg_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 8);
  c3_velmex_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_measured_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c3_p_in_m = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c3_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_kp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_des_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_qcmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_eqeps = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_qcur = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  for (c3_i15 = 0; c3_i15 < 6; c3_i15 = c3_i15 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_qcur)[c3_i15], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_eqeps, 1U);
  for (c3_i16 = 0; c3_i16 < 6; c3_i16 = c3_i16 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_qcmd)[c3_i16], 2U);
  }

  for (c3_i17 = 0; c3_i17 < 3; c3_i17 = c3_i17 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_des_leg_len)[c3_i17], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_kp, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_dt, 5U);
  for (c3_i18 = 0; c3_i18 < 9; c3_i18 = c3_i18 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_p_in_m)[c3_i18], 6U);
  }

  for (c3_i19 = 0; c3_i19 < 9; c3_i19 = c3_i19 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_in_w)[c3_i19], 7U);
  }

  for (c3_i20 = 0; c3_i20 < 3; c3_i20 = c3_i20 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_measured_len)[c3_i20], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_velmex_pitch, 9U);
  for (c3_i21 = 0; c3_i21 < 3; c3_i21 = c3_i21 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_macro_leg_len)[c3_i21], 10U);
  }

  for (c3_i22 = 0; c3_i22 < 3; c3_i22 = c3_i22 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_eq)[c3_i22], 11U);
  }

  for (c3_i23 = 0; c3_i23 < 3; c3_i23 = c3_i23 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_eq_out)[c3_i23], 12U);
  }

  for (c3_i24 = 0; c3_i24 < 3; c3_i24 = c3_i24 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_twave_out)[c3_i24], 13U);
  }

  for (c3_i25 = 0; c3_i25 < 9; c3_i25 = c3_i25 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_rwave_out)[c3_i25], 14U);
  }

  for (c3_i26 = 0; c3_i26 < 3; c3_i26 = c3_i26 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_twave)[c3_i26], 15U);
  }

  for (c3_i27 = 0; c3_i27 < 9; c3_i27 = c3_i27 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_rwave)[c3_i27], 16U);
  }

  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c3_c3_twa_parallel(chartInstance);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_twa_parallelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_c3_twa_parallel(SFc3_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c3_i28;
  real_T c3_hoistedGlobal[6];
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  int32_T c3_i29;
  real_T c3_e_hoistedGlobal[9];
  int32_T c3_i30;
  real_T c3_f_hoistedGlobal[9];
  int32_T c3_i31;
  real_T c3_g_hoistedGlobal[3];
  real_T c3_h_hoistedGlobal;
  int32_T c3_i32;
  real_T c3_i_hoistedGlobal[3];
  int32_T c3_i33;
  real_T c3_j_hoistedGlobal[3];
  int32_T c3_i34;
  real_T c3_k_hoistedGlobal[3];
  int32_T c3_i35;
  real_T c3_l_hoistedGlobal[9];
  int32_T c3_i36;
  real_T c3_qcur[6];
  real_T c3_eqeps;
  real_T c3_kp;
  real_T c3_dt;
  int32_T c3_i37;
  real_T c3_p_in_m[9];
  int32_T c3_i38;
  real_T c3_b_in_w[9];
  int32_T c3_i39;
  real_T c3_measured_len[3];
  real_T c3_velmex_pitch;
  int32_T c3_i40;
  real_T c3_macro_leg_len[3];
  int32_T c3_i41;
  real_T c3_eq[3];
  int32_T c3_i42;
  real_T c3_twave[3];
  int32_T c3_i43;
  real_T c3_rwave[9];
  uint32_T c3_debug_family_var_map[34];
  static const char *c3_sv0[34] = { "z0", "p_in_w", "n1hat", "n2hat", "n3hat",
    "a13", "a23", "a33", "jac", "qdot", "tdot", "v", "w",
    "del_r", "i", "nargin", "nargout", "qcur", "eqeps", "kp", "dt", "p_in_m",
    "b_in_w", "measured_len"
    , "velmex_pitch", "macro_leg_len", "eq", "twave", "rwave", "qcmd",
    "des_leg_len", "eq_out",
    "twave_out", "rwave_out" };

  real_T c3_z0[3];
  real_T c3_p_in_w[9];
  real_T c3_n1hat[3];
  real_T c3_n2hat[3];
  real_T c3_n3hat[3];
  real_T c3_a13;
  real_T c3_a23;
  real_T c3_a33;
  real_T c3_jac[9];
  real_T c3_qdot[3];
  real_T c3_tdot[3];
  real_T c3_v[2];
  real_T c3_w;
  real_T c3_del_r[9];
  real_T c3_i;
  real_T c3_nargin = 12.0;
  real_T c3_nargout = 5.0;
  real_T c3_qcmd[6];
  real_T c3_des_leg_len[3];
  real_T c3_eq_out[3];
  real_T c3_twave_out[3];
  real_T c3_rwave_out[9];
  int32_T c3_i44;
  int32_T c3_i45;
  static real_T c3_dv5[3] = { 0.0, 0.0, 1.0 };

  int32_T c3_i46;
  real_T c3_a[3];
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  real_T c3_y[9];
  int32_T c3_i50;
  real_T c3_b_a[9];
  int32_T c3_i51;
  real_T c3_b[9];
  int32_T c3_i52;
  real_T c3_A[9];
  int32_T c3_i53;
  real_T c3_B[9];
  int32_T c3_i54;
  real_T c3_b_A[9];
  int32_T c3_i55;
  real_T c3_b_B[9];
  int32_T c3_i56;
  real_T c3_c_A[9];
  int32_T c3_i57;
  real_T c3_c_B[9];
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i60;
  real_T c3_b_y[9];
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  real_T c3_b_eq[3];
  int32_T c3_i65;
  real_T c3_x[3];
  int32_T c3_i66;
  real_T c3_b_b_in_w[3];
  real_T c3_c_y;
  int32_T c3_i67;
  real_T c3_b_x[3];
  real_T c3_d_y;
  int32_T c3_i68;
  real_T c3_c_x[3];
  real_T c3_e_y;
  int32_T c3_i69;
  int32_T c3_i70;
  real_T c3_d_x[3];
  int32_T c3_i71;
  real_T c3_c_b_in_w[3];
  real_T c3_f_y;
  int32_T c3_i72;
  real_T c3_e_x[3];
  real_T c3_g_y;
  int32_T c3_i73;
  real_T c3_f_x[3];
  real_T c3_h_y;
  int32_T c3_i74;
  int32_T c3_i75;
  real_T c3_g_x[3];
  int32_T c3_i76;
  real_T c3_d_b_in_w[3];
  real_T c3_i_y;
  int32_T c3_i77;
  real_T c3_h_x[3];
  real_T c3_j_y;
  int32_T c3_i78;
  real_T c3_i_x[3];
  real_T c3_k_y;
  int32_T c3_i79;
  int32_T c3_i80;
  real_T c3_c_a[9];
  int32_T c3_i81;
  real_T c3_b_b[3];
  int32_T c3_i82;
  real_T c3_d_A[9];
  int32_T c3_i83;
  real_T c3_d_B[3];
  int32_T c3_i84;
  real_T c3_e_A[9];
  int32_T c3_i85;
  real_T c3_e_B[3];
  int32_T c3_i86;
  real_T c3_f_A[9];
  int32_T c3_i87;
  real_T c3_f_B[3];
  int32_T c3_i88;
  real_T c3_l_y[3];
  int32_T c3_i89;
  int32_T c3_i90;
  int32_T c3_i91;
  real_T c3_m_y[3];
  int32_T c3_i92;
  real_T c3_b_n1hat[3];
  real_T c3_c_b[3];
  int32_T c3_i93;
  real_T c3_n_y[3];
  int32_T c3_i94;
  real_T c3_o_y[3];
  int32_T c3_i95;
  real_T c3_p_y[3];
  int32_T c3_i96;
  real_T c3_dv6[3];
  int32_T c3_i97;
  real_T c3_q_y[3];
  int32_T c3_i98;
  real_T c3_d_a[9];
  int32_T c3_i99;
  real_T c3_d_b[3];
  int32_T c3_i100;
  real_T c3_g_A[9];
  int32_T c3_i101;
  real_T c3_g_B[3];
  int32_T c3_i102;
  real_T c3_h_A[9];
  int32_T c3_i103;
  real_T c3_h_B[3];
  int32_T c3_i104;
  real_T c3_i_A[9];
  int32_T c3_i105;
  real_T c3_i_B[3];
  int32_T c3_i106;
  real_T c3_r_y[3];
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  real_T c3_s_y[3];
  int32_T c3_i110;
  real_T c3_b_n2hat[3];
  real_T c3_e_b[3];
  int32_T c3_i111;
  real_T c3_t_y[3];
  int32_T c3_i112;
  real_T c3_u_y[3];
  int32_T c3_i113;
  real_T c3_v_y[3];
  int32_T c3_i114;
  real_T c3_dv7[3];
  int32_T c3_i115;
  real_T c3_w_y[3];
  int32_T c3_i116;
  real_T c3_e_a[9];
  int32_T c3_i117;
  real_T c3_f_b[3];
  int32_T c3_i118;
  real_T c3_j_A[9];
  int32_T c3_i119;
  real_T c3_j_B[3];
  int32_T c3_i120;
  real_T c3_k_A[9];
  int32_T c3_i121;
  real_T c3_k_B[3];
  int32_T c3_i122;
  real_T c3_l_A[9];
  int32_T c3_i123;
  real_T c3_l_B[3];
  int32_T c3_i124;
  real_T c3_x_y[3];
  int32_T c3_i125;
  int32_T c3_i126;
  int32_T c3_i127;
  real_T c3_y_y[3];
  int32_T c3_i128;
  real_T c3_b_n3hat[3];
  real_T c3_g_b[3];
  int32_T c3_i129;
  real_T c3_ab_y[3];
  int32_T c3_i130;
  real_T c3_bb_y[3];
  int32_T c3_i131;
  real_T c3_cb_y[3];
  int32_T c3_i132;
  real_T c3_dv8[3];
  int32_T c3_i133;
  real_T c3_db_y[3];
  real_T c3_f_a;
  int32_T c3_i134;
  real_T c3_h_b[3];
  int32_T c3_i135;
  int32_T c3_i136;
  real_T c3_g_a[9];
  int32_T c3_i137;
  real_T c3_i_b[3];
  int32_T c3_i138;
  real_T c3_m_A[9];
  int32_T c3_i139;
  real_T c3_m_B[3];
  int32_T c3_i140;
  int32_T c3_i141;
  real_T c3_n_A[9];
  int32_T c3_i142;
  real_T c3_n_B[3];
  int32_T c3_i143;
  real_T c3_o_A[9];
  int32_T c3_i144;
  real_T c3_o_B[3];
  int32_T c3_i145;
  int32_T c3_i146;
  int32_T c3_i147;
  int32_T c3_i148;
  int32_T c3_i149;
  real_T c3_h_a[2];
  real_T c3_j_b;
  int32_T c3_i150;
  real_T c3_eb_y[2];
  int32_T c3_i151;
  real_T c3_b_twave[2];
  int32_T c3_i152;
  real_T c3_i_a;
  real_T c3_k_b;
  real_T c3_fb_y;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_j_a;
  real_T c3_l_b;
  real_T c3_gb_y;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_k_a;
  real_T c3_m_b;
  real_T c3_hb_y;
  real_T c3_p_x;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_l_a;
  real_T c3_n_b;
  real_T c3_ib_y;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_u_x;
  int32_T c3_i153;
  int32_T c3_i154;
  int32_T c3_i155;
  real_T c3_m_a[9];
  int32_T c3_i156;
  real_T c3_o_b[9];
  int32_T c3_i157;
  real_T c3_p_A[9];
  int32_T c3_i158;
  real_T c3_p_B[9];
  int32_T c3_i159;
  int32_T c3_i160;
  real_T c3_q_A[9];
  int32_T c3_i161;
  real_T c3_q_B[9];
  int32_T c3_i162;
  real_T c3_r_A[9];
  int32_T c3_i163;
  real_T c3_r_B[9];
  int32_T c3_i164;
  int32_T c3_i165;
  int32_T c3_i166;
  int32_T c3_i167;
  int32_T c3_i168;
  int32_T c3_i169;
  real_T c3_b_i;
  int32_T c3_i170;
  real_T c3_n_a[9];
  int32_T c3_c_i;
  int32_T c3_i171;
  real_T c3_p_b[3];
  int32_T c3_i172;
  real_T c3_s_A[9];
  int32_T c3_i173;
  real_T c3_s_B[3];
  int32_T c3_i174;
  real_T c3_t_A[9];
  int32_T c3_i175;
  real_T c3_t_B[3];
  int32_T c3_i176;
  real_T c3_u_A[9];
  int32_T c3_i177;
  real_T c3_u_B[3];
  int32_T c3_i178;
  real_T c3_jb_y[3];
  int32_T c3_i179;
  int32_T c3_i180;
  int32_T c3_d_i;
  int32_T c3_i181;
  int32_T c3_e_i;
  int32_T c3_f_i;
  int32_T c3_i182;
  real_T c3_b_p_in_w[3];
  int32_T c3_i183;
  int32_T c3_i184;
  real_T c3_v_A[3];
  real_T c3_v_B;
  int32_T c3_i185;
  real_T c3_v_x[3];
  real_T c3_kb_y;
  int32_T c3_i186;
  real_T c3_w_x[3];
  real_T c3_lb_y;
  int32_T c3_i187;
  real_T c3_x_x[3];
  real_T c3_mb_y;
  int32_T c3_i188;
  real_T c3_nb_y[3];
  int32_T c3_i189;
  int32_T c3_i190;
  int32_T c3_i191;
  int32_T c3_i192;
  int32_T c3_i193;
  int32_T c3_i194;
  int32_T c3_i195;
  int32_T c3_i196;
  int32_T c3_i197;
  int32_T c3_i198;
  int32_T c3_i199;
  int32_T c3_i200;
  real_T *c3_b_eqeps;
  real_T *c3_b_kp;
  real_T *c3_b_dt;
  real_T *c3_b_velmex_pitch;
  real_T (*c3_b_qcmd)[6];
  real_T (*c3_b_des_leg_len)[3];
  real_T (*c3_b_eq_out)[3];
  real_T (*c3_b_twave_out)[3];
  real_T (*c3_b_rwave_out)[9];
  real_T (*c3_b_rwave)[9];
  real_T (*c3_c_twave)[3];
  real_T (*c3_c_eq)[3];
  real_T (*c3_b_macro_leg_len)[3];
  real_T (*c3_b_measured_len)[3];
  real_T (*c3_e_b_in_w)[9];
  real_T (*c3_b_p_in_m)[9];
  real_T (*c3_b_qcur)[6];
  c3_b_rwave = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 11);
  c3_c_twave = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 10);
  c3_b_rwave_out = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_b_twave_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_eq_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_c_eq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c3_b_macro_leg_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 8);
  c3_b_velmex_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_measured_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c3_e_b_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_p_in_m = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_kp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_des_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_qcmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_eqeps = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_qcur = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  for (c3_i28 = 0; c3_i28 < 6; c3_i28 = c3_i28 + 1) {
    c3_hoistedGlobal[c3_i28] = (*c3_b_qcur)[c3_i28];
  }

  c3_b_hoistedGlobal = *c3_b_eqeps;
  c3_c_hoistedGlobal = *c3_b_kp;
  c3_d_hoistedGlobal = *c3_b_dt;
  for (c3_i29 = 0; c3_i29 < 9; c3_i29 = c3_i29 + 1) {
    c3_e_hoistedGlobal[c3_i29] = (*c3_b_p_in_m)[c3_i29];
  }

  for (c3_i30 = 0; c3_i30 < 9; c3_i30 = c3_i30 + 1) {
    c3_f_hoistedGlobal[c3_i30] = (*c3_e_b_in_w)[c3_i30];
  }

  for (c3_i31 = 0; c3_i31 < 3; c3_i31 = c3_i31 + 1) {
    c3_g_hoistedGlobal[c3_i31] = (*c3_b_measured_len)[c3_i31];
  }

  c3_h_hoistedGlobal = *c3_b_velmex_pitch;
  for (c3_i32 = 0; c3_i32 < 3; c3_i32 = c3_i32 + 1) {
    c3_i_hoistedGlobal[c3_i32] = (*c3_b_macro_leg_len)[c3_i32];
  }

  for (c3_i33 = 0; c3_i33 < 3; c3_i33 = c3_i33 + 1) {
    c3_j_hoistedGlobal[c3_i33] = (*c3_c_eq)[c3_i33];
  }

  for (c3_i34 = 0; c3_i34 < 3; c3_i34 = c3_i34 + 1) {
    c3_k_hoistedGlobal[c3_i34] = (*c3_c_twave)[c3_i34];
  }

  for (c3_i35 = 0; c3_i35 < 9; c3_i35 = c3_i35 + 1) {
    c3_l_hoistedGlobal[c3_i35] = (*c3_b_rwave)[c3_i35];
  }

  for (c3_i36 = 0; c3_i36 < 6; c3_i36 = c3_i36 + 1) {
    c3_qcur[c3_i36] = c3_hoistedGlobal[c3_i36];
  }

  c3_eqeps = c3_b_hoistedGlobal;
  c3_kp = c3_c_hoistedGlobal;
  c3_dt = c3_d_hoistedGlobal;
  for (c3_i37 = 0; c3_i37 < 9; c3_i37 = c3_i37 + 1) {
    c3_p_in_m[c3_i37] = c3_e_hoistedGlobal[c3_i37];
  }

  for (c3_i38 = 0; c3_i38 < 9; c3_i38 = c3_i38 + 1) {
    c3_b_in_w[c3_i38] = c3_f_hoistedGlobal[c3_i38];
  }

  for (c3_i39 = 0; c3_i39 < 3; c3_i39 = c3_i39 + 1) {
    c3_measured_len[c3_i39] = c3_g_hoistedGlobal[c3_i39];
  }

  c3_velmex_pitch = c3_h_hoistedGlobal;
  for (c3_i40 = 0; c3_i40 < 3; c3_i40 = c3_i40 + 1) {
    c3_macro_leg_len[c3_i40] = c3_i_hoistedGlobal[c3_i40];
  }

  for (c3_i41 = 0; c3_i41 < 3; c3_i41 = c3_i41 + 1) {
    c3_eq[c3_i41] = c3_j_hoistedGlobal[c3_i41];
  }

  for (c3_i42 = 0; c3_i42 < 3; c3_i42 = c3_i42 + 1) {
    c3_twave[c3_i42] = c3_k_hoistedGlobal[c3_i42];
  }

  for (c3_i43 = 0; c3_i43 < 9; c3_i43 = c3_i43 + 1) {
    c3_rwave[c3_i43] = c3_l_hoistedGlobal[c3_i43];
  }

  sf_debug_symbol_scope_push_eml(0U, 34U, 34U, c3_sv0, c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_z0, c3_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c3_p_in_w, c3_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c3_n1hat, c3_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c3_n2hat, c3_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c3_n3hat, c3_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c3_a13, c3_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c3_a23, c3_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c3_a33, c3_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c3_jac, c3_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c3_qdot, c3_b_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c3_tdot, c3_b_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c3_v, c3_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c3_w, c3_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c3_del_r, c3_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c3_i, c3_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c3_nargin, c3_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c3_nargout, c3_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c3_qcur, c3_c_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c3_eqeps, c3_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c3_kp, c3_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c3_dt, c3_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c3_p_in_m, c3_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c3_b_in_w, c3_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c3_measured_len, c3_b_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c3_velmex_pitch, c3_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c3_macro_leg_len, c3_b_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c3_eq, c3_b_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c3_twave, c3_b_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c3_rwave, c3_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c3_qcmd, c3_c_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c3_des_leg_len, c3_b_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c3_eq_out, c3_b_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c3_twave_out, c3_b_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c3_rwave_out, c3_sf_marshall, 33U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  for (c3_i44 = 0; c3_i44 < 6; c3_i44 = c3_i44 + 1) {
    c3_qcmd[c3_i44] = c3_qcur[c3_i44];
  }

  _SFD_EML_CALL(0,5);
  for (c3_i45 = 0; c3_i45 < 3; c3_i45 = c3_i45 + 1) {
    c3_z0[c3_i45] = c3_dv5[c3_i45];
  }

  /*  moving platform vertex locations */
  _SFD_EML_CALL(0,8);
  for (c3_i46 = 0; c3_i46 < 3; c3_i46 = c3_i46 + 1) {
    c3_a[c3_i46] = c3_twave[c3_i46];
  }

  c3_i47 = 0;
  for (c3_i48 = 0; c3_i48 < 3; c3_i48 = c3_i48 + 1) {
    for (c3_i49 = 0; c3_i49 < 3; c3_i49 = c3_i49 + 1) {
      c3_y[c3_i49 + c3_i47] = c3_a[c3_i49];
    }

    c3_i47 = c3_i47 + 3;
  }

  for (c3_i50 = 0; c3_i50 < 9; c3_i50 = c3_i50 + 1) {
    c3_b_a[c3_i50] = c3_rwave[c3_i50];
  }

  for (c3_i51 = 0; c3_i51 < 9; c3_i51 = c3_i51 + 1) {
    c3_b[c3_i51] = c3_p_in_m[c3_i51];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i52 = 0; c3_i52 < 9; c3_i52 = c3_i52 + 1) {
    c3_A[c3_i52] = c3_b_a[c3_i52];
  }

  for (c3_i53 = 0; c3_i53 < 9; c3_i53 = c3_i53 + 1) {
    c3_B[c3_i53] = c3_b[c3_i53];
  }

  for (c3_i54 = 0; c3_i54 < 9; c3_i54 = c3_i54 + 1) {
    c3_b_A[c3_i54] = c3_A[c3_i54];
  }

  for (c3_i55 = 0; c3_i55 < 9; c3_i55 = c3_i55 + 1) {
    c3_b_B[c3_i55] = c3_B[c3_i55];
  }

  for (c3_i56 = 0; c3_i56 < 9; c3_i56 = c3_i56 + 1) {
    c3_c_A[c3_i56] = c3_b_A[c3_i56];
  }

  for (c3_i57 = 0; c3_i57 < 9; c3_i57 = c3_i57 + 1) {
    c3_c_B[c3_i57] = c3_b_B[c3_i57];
  }

  for (c3_i58 = 0; c3_i58 < 3; c3_i58 = c3_i58 + 1) {
    c3_i59 = 0;
    for (c3_i60 = 0; c3_i60 < 3; c3_i60 = c3_i60 + 1) {
      c3_b_y[c3_i59 + c3_i58] = 0.0;
      c3_i61 = 0;
      for (c3_i62 = 0; c3_i62 < 3; c3_i62 = c3_i62 + 1) {
        c3_b_y[c3_i59 + c3_i58] = c3_b_y[c3_i59 + c3_i58] + c3_c_A[c3_i61 +
          c3_i58] * c3_c_B[c3_i62 + c3_i59];
        c3_i61 = c3_i61 + 3;
      }

      c3_i59 = c3_i59 + 3;
    }
  }

  for (c3_i63 = 0; c3_i63 < 9; c3_i63 = c3_i63 + 1) {
    c3_p_in_w[c3_i63] = c3_y[c3_i63] + c3_b_y[c3_i63];
  }

  _SFD_EML_CALL(0,10);
  for (c3_i64 = 0; c3_i64 < 3; c3_i64 = c3_i64 + 1) {
    c3_b_eq[c3_i64] = c3_eq[c3_i64];
  }

  if (CV_EML_IF(0, 0, c3_norm(chartInstance, c3_b_eq) > c3_eqeps)) {
    /*  get parallel (macro) jacobian */
    _SFD_EML_CALL(0,12);
    for (c3_i65 = 0; c3_i65 < 3; c3_i65 = c3_i65 + 1) {
      c3_x[c3_i65] = c3_p_in_w[c3_i65] - c3_b_in_w[c3_i65];
    }

    for (c3_i66 = 0; c3_i66 < 3; c3_i66 = c3_i66 + 1) {
      c3_b_b_in_w[c3_i66] = c3_b_in_w[c3_i66] - c3_p_in_w[c3_i66];
    }

    c3_c_y = c3_norm(chartInstance, c3_b_b_in_w);
    for (c3_i67 = 0; c3_i67 < 3; c3_i67 = c3_i67 + 1) {
      c3_b_x[c3_i67] = c3_x[c3_i67];
    }

    c3_d_y = c3_c_y;
    for (c3_i68 = 0; c3_i68 < 3; c3_i68 = c3_i68 + 1) {
      c3_c_x[c3_i68] = c3_b_x[c3_i68];
    }

    c3_e_y = c3_d_y;
    for (c3_i69 = 0; c3_i69 < 3; c3_i69 = c3_i69 + 1) {
      c3_n1hat[c3_i69] = c3_c_x[c3_i69] / c3_e_y;
    }

    _SFD_EML_CALL(0,13);
    for (c3_i70 = 0; c3_i70 < 3; c3_i70 = c3_i70 + 1) {
      c3_d_x[c3_i70] = c3_p_in_w[c3_i70 + 3] - c3_b_in_w[c3_i70 + 3];
    }

    for (c3_i71 = 0; c3_i71 < 3; c3_i71 = c3_i71 + 1) {
      c3_c_b_in_w[c3_i71] = c3_b_in_w[c3_i71 + 3] - c3_p_in_w[c3_i71 + 3];
    }

    c3_f_y = c3_norm(chartInstance, c3_c_b_in_w);
    for (c3_i72 = 0; c3_i72 < 3; c3_i72 = c3_i72 + 1) {
      c3_e_x[c3_i72] = c3_d_x[c3_i72];
    }

    c3_g_y = c3_f_y;
    for (c3_i73 = 0; c3_i73 < 3; c3_i73 = c3_i73 + 1) {
      c3_f_x[c3_i73] = c3_e_x[c3_i73];
    }

    c3_h_y = c3_g_y;
    for (c3_i74 = 0; c3_i74 < 3; c3_i74 = c3_i74 + 1) {
      c3_n2hat[c3_i74] = c3_f_x[c3_i74] / c3_h_y;
    }

    _SFD_EML_CALL(0,14);
    for (c3_i75 = 0; c3_i75 < 3; c3_i75 = c3_i75 + 1) {
      c3_g_x[c3_i75] = c3_p_in_w[c3_i75 + 6] - c3_b_in_w[c3_i75 + 6];
    }

    for (c3_i76 = 0; c3_i76 < 3; c3_i76 = c3_i76 + 1) {
      c3_d_b_in_w[c3_i76] = c3_b_in_w[c3_i76 + 6] - c3_p_in_w[c3_i76 + 6];
    }

    c3_i_y = c3_norm(chartInstance, c3_d_b_in_w);
    for (c3_i77 = 0; c3_i77 < 3; c3_i77 = c3_i77 + 1) {
      c3_h_x[c3_i77] = c3_g_x[c3_i77];
    }

    c3_j_y = c3_i_y;
    for (c3_i78 = 0; c3_i78 < 3; c3_i78 = c3_i78 + 1) {
      c3_i_x[c3_i78] = c3_h_x[c3_i78];
    }

    c3_k_y = c3_j_y;
    for (c3_i79 = 0; c3_i79 < 3; c3_i79 = c3_i79 + 1) {
      c3_n3hat[c3_i79] = c3_i_x[c3_i79] / c3_k_y;
    }

    /*  Inverse kinematics jacobian components */
    _SFD_EML_CALL(0,17);
    for (c3_i80 = 0; c3_i80 < 9; c3_i80 = c3_i80 + 1) {
      c3_c_a[c3_i80] = c3_rwave[c3_i80];
    }

    for (c3_i81 = 0; c3_i81 < 3; c3_i81 = c3_i81 + 1) {
      c3_b_b[c3_i81] = c3_p_in_m[c3_i81];
    }

    c3_b_eml_scalar_eg(chartInstance);
    c3_b_eml_scalar_eg(chartInstance);
    for (c3_i82 = 0; c3_i82 < 9; c3_i82 = c3_i82 + 1) {
      c3_d_A[c3_i82] = c3_c_a[c3_i82];
    }

    for (c3_i83 = 0; c3_i83 < 3; c3_i83 = c3_i83 + 1) {
      c3_d_B[c3_i83] = c3_b_b[c3_i83];
    }

    for (c3_i84 = 0; c3_i84 < 9; c3_i84 = c3_i84 + 1) {
      c3_e_A[c3_i84] = c3_d_A[c3_i84];
    }

    for (c3_i85 = 0; c3_i85 < 3; c3_i85 = c3_i85 + 1) {
      c3_e_B[c3_i85] = c3_d_B[c3_i85];
    }

    for (c3_i86 = 0; c3_i86 < 9; c3_i86 = c3_i86 + 1) {
      c3_f_A[c3_i86] = c3_e_A[c3_i86];
    }

    for (c3_i87 = 0; c3_i87 < 3; c3_i87 = c3_i87 + 1) {
      c3_f_B[c3_i87] = c3_e_B[c3_i87];
    }

    for (c3_i88 = 0; c3_i88 < 3; c3_i88 = c3_i88 + 1) {
      c3_l_y[c3_i88] = 0.0;
      c3_i89 = 0;
      for (c3_i90 = 0; c3_i90 < 3; c3_i90 = c3_i90 + 1) {
        c3_l_y[c3_i88] = c3_l_y[c3_i88] + c3_f_A[c3_i89 + c3_i88] *
          c3_f_B[c3_i90];
        c3_i89 = c3_i89 + 3;
      }
    }

    for (c3_i91 = 0; c3_i91 < 3; c3_i91 = c3_i91 + 1) {
      c3_m_y[c3_i91] = c3_l_y[c3_i91];
    }

    for (c3_i92 = 0; c3_i92 < 3; c3_i92 = c3_i92 + 1) {
      c3_b_n1hat[c3_i92] = c3_n1hat[c3_i92];
    }

    c3_cross(chartInstance, c3_m_y, c3_b_n1hat, c3_c_b);
    c3_c_eml_scalar_eg(chartInstance);
    for (c3_i93 = 0; c3_i93 < 3; c3_i93 = c3_i93 + 1) {
      c3_n_y[c3_i93] = c3_c_b[c3_i93];
    }

    for (c3_i94 = 0; c3_i94 < 3; c3_i94 = c3_i94 + 1) {
      c3_o_y[c3_i94] = c3_n_y[c3_i94];
    }

    for (c3_i95 = 0; c3_i95 < 3; c3_i95 = c3_i95 + 1) {
      c3_p_y[c3_i95] = c3_o_y[c3_i95];
    }

    for (c3_i96 = 0; c3_i96 < 3; c3_i96 = c3_i96 + 1) {
      c3_dv6[c3_i96] = c3_dv5[c3_i96];
    }

    for (c3_i97 = 0; c3_i97 < 3; c3_i97 = c3_i97 + 1) {
      c3_q_y[c3_i97] = c3_p_y[c3_i97];
    }

    c3_a13 = c3_ceval_xdot(chartInstance, 3, c3_dv6, 1, 1, c3_q_y, 1, 1);
    _SFD_EML_CALL(0,18);
    for (c3_i98 = 0; c3_i98 < 9; c3_i98 = c3_i98 + 1) {
      c3_d_a[c3_i98] = c3_rwave[c3_i98];
    }

    for (c3_i99 = 0; c3_i99 < 3; c3_i99 = c3_i99 + 1) {
      c3_d_b[c3_i99] = c3_p_in_m[c3_i99 + 3];
    }

    c3_b_eml_scalar_eg(chartInstance);
    c3_b_eml_scalar_eg(chartInstance);
    for (c3_i100 = 0; c3_i100 < 9; c3_i100 = c3_i100 + 1) {
      c3_g_A[c3_i100] = c3_d_a[c3_i100];
    }

    for (c3_i101 = 0; c3_i101 < 3; c3_i101 = c3_i101 + 1) {
      c3_g_B[c3_i101] = c3_d_b[c3_i101];
    }

    for (c3_i102 = 0; c3_i102 < 9; c3_i102 = c3_i102 + 1) {
      c3_h_A[c3_i102] = c3_g_A[c3_i102];
    }

    for (c3_i103 = 0; c3_i103 < 3; c3_i103 = c3_i103 + 1) {
      c3_h_B[c3_i103] = c3_g_B[c3_i103];
    }

    for (c3_i104 = 0; c3_i104 < 9; c3_i104 = c3_i104 + 1) {
      c3_i_A[c3_i104] = c3_h_A[c3_i104];
    }

    for (c3_i105 = 0; c3_i105 < 3; c3_i105 = c3_i105 + 1) {
      c3_i_B[c3_i105] = c3_h_B[c3_i105];
    }

    for (c3_i106 = 0; c3_i106 < 3; c3_i106 = c3_i106 + 1) {
      c3_r_y[c3_i106] = 0.0;
      c3_i107 = 0;
      for (c3_i108 = 0; c3_i108 < 3; c3_i108 = c3_i108 + 1) {
        c3_r_y[c3_i106] = c3_r_y[c3_i106] + c3_i_A[c3_i107 + c3_i106] *
          c3_i_B[c3_i108];
        c3_i107 = c3_i107 + 3;
      }
    }

    for (c3_i109 = 0; c3_i109 < 3; c3_i109 = c3_i109 + 1) {
      c3_s_y[c3_i109] = c3_r_y[c3_i109];
    }

    for (c3_i110 = 0; c3_i110 < 3; c3_i110 = c3_i110 + 1) {
      c3_b_n2hat[c3_i110] = c3_n2hat[c3_i110];
    }

    c3_cross(chartInstance, c3_s_y, c3_b_n2hat, c3_e_b);
    c3_c_eml_scalar_eg(chartInstance);
    for (c3_i111 = 0; c3_i111 < 3; c3_i111 = c3_i111 + 1) {
      c3_t_y[c3_i111] = c3_e_b[c3_i111];
    }

    for (c3_i112 = 0; c3_i112 < 3; c3_i112 = c3_i112 + 1) {
      c3_u_y[c3_i112] = c3_t_y[c3_i112];
    }

    for (c3_i113 = 0; c3_i113 < 3; c3_i113 = c3_i113 + 1) {
      c3_v_y[c3_i113] = c3_u_y[c3_i113];
    }

    for (c3_i114 = 0; c3_i114 < 3; c3_i114 = c3_i114 + 1) {
      c3_dv7[c3_i114] = c3_dv5[c3_i114];
    }

    for (c3_i115 = 0; c3_i115 < 3; c3_i115 = c3_i115 + 1) {
      c3_w_y[c3_i115] = c3_v_y[c3_i115];
    }

    c3_a23 = c3_ceval_xdot(chartInstance, 3, c3_dv7, 1, 1, c3_w_y, 1, 1);
    _SFD_EML_CALL(0,19);
    for (c3_i116 = 0; c3_i116 < 9; c3_i116 = c3_i116 + 1) {
      c3_e_a[c3_i116] = c3_rwave[c3_i116];
    }

    for (c3_i117 = 0; c3_i117 < 3; c3_i117 = c3_i117 + 1) {
      c3_f_b[c3_i117] = c3_p_in_m[c3_i117 + 6];
    }

    c3_b_eml_scalar_eg(chartInstance);
    c3_b_eml_scalar_eg(chartInstance);
    for (c3_i118 = 0; c3_i118 < 9; c3_i118 = c3_i118 + 1) {
      c3_j_A[c3_i118] = c3_e_a[c3_i118];
    }

    for (c3_i119 = 0; c3_i119 < 3; c3_i119 = c3_i119 + 1) {
      c3_j_B[c3_i119] = c3_f_b[c3_i119];
    }

    for (c3_i120 = 0; c3_i120 < 9; c3_i120 = c3_i120 + 1) {
      c3_k_A[c3_i120] = c3_j_A[c3_i120];
    }

    for (c3_i121 = 0; c3_i121 < 3; c3_i121 = c3_i121 + 1) {
      c3_k_B[c3_i121] = c3_j_B[c3_i121];
    }

    for (c3_i122 = 0; c3_i122 < 9; c3_i122 = c3_i122 + 1) {
      c3_l_A[c3_i122] = c3_k_A[c3_i122];
    }

    for (c3_i123 = 0; c3_i123 < 3; c3_i123 = c3_i123 + 1) {
      c3_l_B[c3_i123] = c3_k_B[c3_i123];
    }

    for (c3_i124 = 0; c3_i124 < 3; c3_i124 = c3_i124 + 1) {
      c3_x_y[c3_i124] = 0.0;
      c3_i125 = 0;
      for (c3_i126 = 0; c3_i126 < 3; c3_i126 = c3_i126 + 1) {
        c3_x_y[c3_i124] = c3_x_y[c3_i124] + c3_l_A[c3_i125 + c3_i124] *
          c3_l_B[c3_i126];
        c3_i125 = c3_i125 + 3;
      }
    }

    for (c3_i127 = 0; c3_i127 < 3; c3_i127 = c3_i127 + 1) {
      c3_y_y[c3_i127] = c3_x_y[c3_i127];
    }

    for (c3_i128 = 0; c3_i128 < 3; c3_i128 = c3_i128 + 1) {
      c3_b_n3hat[c3_i128] = c3_n3hat[c3_i128];
    }

    c3_cross(chartInstance, c3_y_y, c3_b_n3hat, c3_g_b);
    c3_c_eml_scalar_eg(chartInstance);
    for (c3_i129 = 0; c3_i129 < 3; c3_i129 = c3_i129 + 1) {
      c3_ab_y[c3_i129] = c3_g_b[c3_i129];
    }

    for (c3_i130 = 0; c3_i130 < 3; c3_i130 = c3_i130 + 1) {
      c3_bb_y[c3_i130] = c3_ab_y[c3_i130];
    }

    for (c3_i131 = 0; c3_i131 < 3; c3_i131 = c3_i131 + 1) {
      c3_cb_y[c3_i131] = c3_bb_y[c3_i131];
    }

    for (c3_i132 = 0; c3_i132 < 3; c3_i132 = c3_i132 + 1) {
      c3_dv8[c3_i132] = c3_dv5[c3_i132];
    }

    for (c3_i133 = 0; c3_i133 < 3; c3_i133 = c3_i133 + 1) {
      c3_db_y[c3_i133] = c3_cb_y[c3_i133];
    }

    c3_a33 = c3_ceval_xdot(chartInstance, 3, c3_dv8, 1, 1, c3_db_y, 1, 1);
    _SFD_EML_CALL(0,21);
    c3_jac[0] = c3_n1hat[0];
    c3_jac[3] = c3_n1hat[1];
    c3_jac[6] = c3_a13;
    c3_jac[1] = c3_n2hat[0];
    c3_jac[4] = c3_n2hat[1];
    c3_jac[7] = c3_a23;
    c3_jac[2] = c3_n3hat[0];
    c3_jac[5] = c3_n3hat[1];
    c3_jac[8] = c3_a33;

    /*  joint velocities and ee velocity proportional to joint error */
    _SFD_EML_CALL(0,26);
    c3_f_a = c3_kp;
    for (c3_i134 = 0; c3_i134 < 3; c3_i134 = c3_i134 + 1) {
      c3_h_b[c3_i134] = c3_eq[c3_i134];
    }

    for (c3_i135 = 0; c3_i135 < 3; c3_i135 = c3_i135 + 1) {
      c3_qdot[c3_i135] = c3_f_a * c3_h_b[c3_i135];
    }

    _SFD_EML_CALL(0,27);
    for (c3_i136 = 0; c3_i136 < 9; c3_i136 = c3_i136 + 1) {
      c3_g_a[c3_i136] = c3_jac[c3_i136];
    }

    for (c3_i137 = 0; c3_i137 < 3; c3_i137 = c3_i137 + 1) {
      c3_i_b[c3_i137] = c3_qdot[c3_i137];
    }

    c3_b_eml_scalar_eg(chartInstance);
    c3_b_eml_scalar_eg(chartInstance);
    for (c3_i138 = 0; c3_i138 < 9; c3_i138 = c3_i138 + 1) {
      c3_m_A[c3_i138] = c3_g_a[c3_i138];
    }

    for (c3_i139 = 0; c3_i139 < 3; c3_i139 = c3_i139 + 1) {
      c3_m_B[c3_i139] = c3_i_b[c3_i139];
    }

    for (c3_i140 = 0; c3_i140 < 3; c3_i140 = c3_i140 + 1) {
      c3_tdot[c3_i140] = 0.0;
    }

    for (c3_i141 = 0; c3_i141 < 9; c3_i141 = c3_i141 + 1) {
      c3_n_A[c3_i141] = c3_m_A[c3_i141];
    }

    for (c3_i142 = 0; c3_i142 < 3; c3_i142 = c3_i142 + 1) {
      c3_n_B[c3_i142] = c3_m_B[c3_i142];
    }

    for (c3_i143 = 0; c3_i143 < 9; c3_i143 = c3_i143 + 1) {
      c3_o_A[c3_i143] = c3_n_A[c3_i143];
    }

    for (c3_i144 = 0; c3_i144 < 3; c3_i144 = c3_i144 + 1) {
      c3_o_B[c3_i144] = c3_n_B[c3_i144];
    }

    for (c3_i145 = 0; c3_i145 < 3; c3_i145 = c3_i145 + 1) {
      c3_tdot[c3_i145] = 0.0;
      c3_i146 = 0;
      for (c3_i147 = 0; c3_i147 < 3; c3_i147 = c3_i147 + 1) {
        c3_tdot[c3_i145] = c3_tdot[c3_i145] + c3_o_A[c3_i146 + c3_i145] *
          c3_o_B[c3_i147];
        c3_i146 = c3_i146 + 3;
      }
    }

    /*  separate translational and rotational components of twist */
    _SFD_EML_CALL(0,30);
    for (c3_i148 = 0; c3_i148 < 2; c3_i148 = c3_i148 + 1) {
      c3_v[c3_i148] = c3_tdot[c3_i148];
    }

    _SFD_EML_CALL(0,31);
    c3_w = c3_tdot[2];

    /*  new end effector position */
    _SFD_EML_CALL(0,34);
    for (c3_i149 = 0; c3_i149 < 2; c3_i149 = c3_i149 + 1) {
      c3_h_a[c3_i149] = c3_v[c3_i149];
    }

    c3_j_b = c3_dt;
    for (c3_i150 = 0; c3_i150 < 2; c3_i150 = c3_i150 + 1) {
      c3_eb_y[c3_i150] = c3_h_a[c3_i150] * c3_j_b;
    }

    for (c3_i151 = 0; c3_i151 < 2; c3_i151 = c3_i151 + 1) {
      c3_b_twave[c3_i151] = c3_twave[c3_i151] + c3_eb_y[c3_i151];
    }

    for (c3_i152 = 0; c3_i152 < 2; c3_i152 = c3_i152 + 1) {
      c3_twave[c3_i152] = c3_b_twave[c3_i152];
    }

    /*  change in end effector orientation */
    _SFD_EML_CALL(0,37);
    c3_i_a = c3_w;
    c3_k_b = c3_dt;
    c3_fb_y = c3_i_a * c3_k_b;
    c3_j_x = c3_fb_y;
    c3_k_x = c3_j_x;
    c3_l_x = c3_k_x;
    c3_k_x = c3_l_x;
    c3_k_x = muDoubleScalarCos(c3_k_x);
    c3_j_a = c3_w;
    c3_l_b = c3_dt;
    c3_gb_y = c3_j_a * c3_l_b;
    c3_m_x = c3_gb_y;
    c3_n_x = c3_m_x;
    c3_o_x = c3_n_x;
    c3_n_x = c3_o_x;
    c3_n_x = muDoubleScalarSin(c3_n_x);
    c3_k_a = c3_w;
    c3_m_b = c3_dt;
    c3_hb_y = c3_k_a * c3_m_b;
    c3_p_x = c3_hb_y;
    c3_q_x = c3_p_x;
    c3_r_x = c3_q_x;
    c3_q_x = c3_r_x;
    c3_q_x = muDoubleScalarSin(c3_q_x);
    c3_l_a = c3_w;
    c3_n_b = c3_dt;
    c3_ib_y = c3_l_a * c3_n_b;
    c3_s_x = c3_ib_y;
    c3_t_x = c3_s_x;
    c3_u_x = c3_t_x;
    c3_t_x = c3_u_x;
    c3_t_x = muDoubleScalarCos(c3_t_x);
    c3_del_r[0] = c3_k_x;
    c3_del_r[3] = -c3_n_x;
    c3_del_r[6] = 0.0;
    c3_del_r[1] = c3_q_x;
    c3_del_r[4] = c3_t_x;
    c3_del_r[7] = 0.0;
    c3_i153 = 0;
    for (c3_i154 = 0; c3_i154 < 3; c3_i154 = c3_i154 + 1) {
      c3_del_r[c3_i153 + 2] = c3_dv5[c3_i154];
      c3_i153 = c3_i153 + 3;
    }

    /*  new end effector orientation */
    _SFD_EML_CALL(0,40);
    for (c3_i155 = 0; c3_i155 < 9; c3_i155 = c3_i155 + 1) {
      c3_m_a[c3_i155] = c3_del_r[c3_i155];
    }

    for (c3_i156 = 0; c3_i156 < 9; c3_i156 = c3_i156 + 1) {
      c3_o_b[c3_i156] = c3_rwave[c3_i156];
    }

    c3_eml_scalar_eg(chartInstance);
    c3_eml_scalar_eg(chartInstance);
    for (c3_i157 = 0; c3_i157 < 9; c3_i157 = c3_i157 + 1) {
      c3_p_A[c3_i157] = c3_m_a[c3_i157];
    }

    for (c3_i158 = 0; c3_i158 < 9; c3_i158 = c3_i158 + 1) {
      c3_p_B[c3_i158] = c3_o_b[c3_i158];
    }

    for (c3_i159 = 0; c3_i159 < 9; c3_i159 = c3_i159 + 1) {
      c3_rwave[c3_i159] = 0.0;
    }

    for (c3_i160 = 0; c3_i160 < 9; c3_i160 = c3_i160 + 1) {
      c3_q_A[c3_i160] = c3_p_A[c3_i160];
    }

    for (c3_i161 = 0; c3_i161 < 9; c3_i161 = c3_i161 + 1) {
      c3_q_B[c3_i161] = c3_p_B[c3_i161];
    }

    for (c3_i162 = 0; c3_i162 < 9; c3_i162 = c3_i162 + 1) {
      c3_r_A[c3_i162] = c3_q_A[c3_i162];
    }

    for (c3_i163 = 0; c3_i163 < 9; c3_i163 = c3_i163 + 1) {
      c3_r_B[c3_i163] = c3_q_B[c3_i163];
    }

    for (c3_i164 = 0; c3_i164 < 3; c3_i164 = c3_i164 + 1) {
      c3_i165 = 0;
      for (c3_i166 = 0; c3_i166 < 3; c3_i166 = c3_i166 + 1) {
        c3_rwave[c3_i165 + c3_i164] = 0.0;
        c3_i167 = 0;
        for (c3_i168 = 0; c3_i168 < 3; c3_i168 = c3_i168 + 1) {
          c3_rwave[c3_i165 + c3_i164] = c3_rwave[c3_i165 + c3_i164] +
            c3_r_A[c3_i167 + c3_i164] * c3_r_B[c3_i168 + c3_i165];
          c3_i167 = c3_i167 + 3;
        }

        c3_i165 = c3_i165 + 3;
      }
    }

    _SFD_EML_CALL(0,42);
    for (c3_i169 = 0; c3_i169 < 3; c3_i169 = c3_i169 + 1) {
      c3_des_leg_len[c3_i169] = 0.0;
    }

    c3_i = 1.0;
    c3_b_i = 1.0;
    while (c3_b_i <= 3.0) {
      c3_i = c3_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0,44);
      for (c3_i170 = 0; c3_i170 < 9; c3_i170 = c3_i170 + 1) {
        c3_n_a[c3_i170] = c3_rwave[c3_i170];
      }

      c3_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("p_in_m", (int32_T)_SFD_INTEGER_CHECK
        ("i", c3_i), 1, 3, 2, 0) - 1;
      for (c3_i171 = 0; c3_i171 < 3; c3_i171 = c3_i171 + 1) {
        c3_p_b[c3_i171] = c3_p_in_m[c3_i171 + 3 * c3_c_i];
      }

      c3_b_eml_scalar_eg(chartInstance);
      c3_b_eml_scalar_eg(chartInstance);
      for (c3_i172 = 0; c3_i172 < 9; c3_i172 = c3_i172 + 1) {
        c3_s_A[c3_i172] = c3_n_a[c3_i172];
      }

      for (c3_i173 = 0; c3_i173 < 3; c3_i173 = c3_i173 + 1) {
        c3_s_B[c3_i173] = c3_p_b[c3_i173];
      }

      for (c3_i174 = 0; c3_i174 < 9; c3_i174 = c3_i174 + 1) {
        c3_t_A[c3_i174] = c3_s_A[c3_i174];
      }

      for (c3_i175 = 0; c3_i175 < 3; c3_i175 = c3_i175 + 1) {
        c3_t_B[c3_i175] = c3_s_B[c3_i175];
      }

      for (c3_i176 = 0; c3_i176 < 9; c3_i176 = c3_i176 + 1) {
        c3_u_A[c3_i176] = c3_t_A[c3_i176];
      }

      for (c3_i177 = 0; c3_i177 < 3; c3_i177 = c3_i177 + 1) {
        c3_u_B[c3_i177] = c3_t_B[c3_i177];
      }

      for (c3_i178 = 0; c3_i178 < 3; c3_i178 = c3_i178 + 1) {
        c3_jb_y[c3_i178] = 0.0;
        c3_i179 = 0;
        for (c3_i180 = 0; c3_i180 < 3; c3_i180 = c3_i180 + 1) {
          c3_jb_y[c3_i178] = c3_jb_y[c3_i178] + c3_u_A[c3_i179 + c3_i178] *
            c3_u_B[c3_i180];
          c3_i179 = c3_i179 + 3;
        }
      }

      c3_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("p_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c3_i), 1, 3, 2, 0) - 1;
      for (c3_i181 = 0; c3_i181 < 3; c3_i181 = c3_i181 + 1) {
        c3_p_in_w[c3_i181 + 3 * c3_d_i] = c3_twave[c3_i181] + c3_jb_y[c3_i181];
      }

      _SFD_EML_CALL(0,45);
      c3_e_i = _SFD_EML_ARRAY_BOUNDS_CHECK("p_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c3_i), 1, 3, 2, 0) - 1;
      c3_f_i = _SFD_EML_ARRAY_BOUNDS_CHECK("b_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c3_i), 1, 3, 2, 0) - 1;
      for (c3_i182 = 0; c3_i182 < 3; c3_i182 = c3_i182 + 1) {
        c3_b_p_in_w[c3_i182] = c3_p_in_w[c3_i182 + 3 * c3_e_i] -
          c3_b_in_w[c3_i182 + 3 * c3_f_i];
      }

      c3_des_leg_len[_SFD_EML_ARRAY_BOUNDS_CHECK("des_leg_len", (int32_T)
        _SFD_INTEGER_CHECK("i", c3_i), 1, 3, 1, 0) - 1] = c3_norm(
        chartInstance, c3_b_p_in_w);
      c3_b_i = c3_b_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
    _SFD_EML_CALL(0,48);
    for (c3_i183 = 0; c3_i183 < 3; c3_i183 = c3_i183 + 1) {
      c3_eq_out[c3_i183] = c3_macro_leg_len[c3_i183] - c3_des_leg_len[c3_i183];
    }

    /*  the amount each velmex slides need to move is the difference between  */
    /*  the last leg length and the new leg length */
    _SFD_EML_CALL(0,52);
    for (c3_i184 = 0; c3_i184 < 3; c3_i184 = c3_i184 + 1) {
      c3_v_A[c3_i184] = c3_measured_len[c3_i184] - c3_des_leg_len[c3_i184];
    }

    c3_v_B = c3_velmex_pitch;
    for (c3_i185 = 0; c3_i185 < 3; c3_i185 = c3_i185 + 1) {
      c3_v_x[c3_i185] = c3_v_A[c3_i185];
    }

    c3_kb_y = c3_v_B;
    for (c3_i186 = 0; c3_i186 < 3; c3_i186 = c3_i186 + 1) {
      c3_w_x[c3_i186] = c3_v_x[c3_i186];
    }

    c3_lb_y = c3_kb_y;
    for (c3_i187 = 0; c3_i187 < 3; c3_i187 = c3_i187 + 1) {
      c3_x_x[c3_i187] = c3_w_x[c3_i187];
    }

    c3_mb_y = c3_lb_y;
    for (c3_i188 = 0; c3_i188 < 3; c3_i188 = c3_i188 + 1) {
      c3_nb_y[c3_i188] = c3_x_x[c3_i188] / c3_mb_y;
    }

    for (c3_i189 = 0; c3_i189 < 3; c3_i189 = c3_i189 + 1) {
      c3_qcmd[c3_i189] = c3_nb_y[c3_i189];
    }

    _SFD_EML_CALL(0,54);
    for (c3_i190 = 0; c3_i190 < 3; c3_i190 = c3_i190 + 1) {
      c3_twave_out[c3_i190] = c3_twave[c3_i190];
    }

    _SFD_EML_CALL(0,55);
    for (c3_i191 = 0; c3_i191 < 9; c3_i191 = c3_i191 + 1) {
      c3_rwave_out[c3_i191] = c3_rwave[c3_i191];
    }
  } else {
    _SFD_EML_CALL(0,57);
    for (c3_i192 = 0; c3_i192 < 3; c3_i192 = c3_i192 + 1) {
      c3_des_leg_len[c3_i192] = c3_macro_leg_len[c3_i192];
    }

    _SFD_EML_CALL(0,58);
    for (c3_i193 = 0; c3_i193 < 3; c3_i193 = c3_i193 + 1) {
      c3_eq_out[c3_i193] = c3_eq[c3_i193];
    }

    _SFD_EML_CALL(0,59);
    for (c3_i194 = 0; c3_i194 < 3; c3_i194 = c3_i194 + 1) {
      c3_twave_out[c3_i194] = c3_twave[c3_i194];
    }

    _SFD_EML_CALL(0,60);
    for (c3_i195 = 0; c3_i195 < 9; c3_i195 = c3_i195 + 1) {
      c3_rwave_out[c3_i195] = c3_rwave[c3_i195];
    }
  }

  _SFD_EML_CALL(0,-60);
  sf_debug_symbol_scope_pop();
  for (c3_i196 = 0; c3_i196 < 6; c3_i196 = c3_i196 + 1) {
    (*c3_b_qcmd)[c3_i196] = c3_qcmd[c3_i196];
  }

  for (c3_i197 = 0; c3_i197 < 3; c3_i197 = c3_i197 + 1) {
    (*c3_b_des_leg_len)[c3_i197] = c3_des_leg_len[c3_i197];
  }

  for (c3_i198 = 0; c3_i198 < 3; c3_i198 = c3_i198 + 1) {
    (*c3_b_eq_out)[c3_i198] = c3_eq_out[c3_i198];
  }

  for (c3_i199 = 0; c3_i199 < 3; c3_i199 = c3_i199 + 1) {
    (*c3_b_twave_out)[c3_i199] = c3_twave_out[c3_i199];
  }

  for (c3_i200 = 0; c3_i200 < 9; c3_i200 = c3_i200 + 1) {
    (*c3_b_rwave_out)[c3_i200] = c3_rwave_out[c3_i200];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static void c3_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c3_norm(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                      c3_x[3])
{
  int32_T c3_i201;
  real_T c3_b_x[3];
  int32_T c3_i202;
  real_T c3_c_x[3];
  int32_T c3_i203;
  real_T c3_d_x[3];
  int32_T c3_i204;
  real_T c3_e_x[3];
  for (c3_i201 = 0; c3_i201 < 3; c3_i201 = c3_i201 + 1) {
    c3_b_x[c3_i201] = c3_x[c3_i201];
  }

  for (c3_i202 = 0; c3_i202 < 3; c3_i202 = c3_i202 + 1) {
    c3_c_x[c3_i202] = c3_b_x[c3_i202];
  }

  for (c3_i203 = 0; c3_i203 < 3; c3_i203 = c3_i203 + 1) {
    c3_d_x[c3_i203] = c3_c_x[c3_i203];
  }

  for (c3_i204 = 0; c3_i204 < 3; c3_i204 = c3_i204 + 1) {
    c3_e_x[c3_i204] = c3_d_x[c3_i204];
  }

  return c3_ceval_xnrm2(chartInstance, 3, c3_e_x, 1, 1);
}

static real_T c3_ceval_xnrm2(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T
  c3_incx)
{
  return dnrm232(&c3_n, &c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 3, 1, 0) - 1], &
                 c3_incx);
}

static void c3_b_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static void c3_cross(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                     c3_a[3], real_T c3_b[3], real_T c3_c[3])
{
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_y;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_b_y;
  real_T c3_c1;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_c_y;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_d_y;
  real_T c3_c2;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_e_y;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_f_y;
  real_T c3_c3;
  c3_b_a = c3_a[1];
  c3_b_b = c3_b[2];
  c3_y = c3_b_a * c3_b_b;
  c3_c_a = c3_a[2];
  c3_c_b = c3_b[1];
  c3_b_y = c3_c_a * c3_c_b;
  c3_c1 = c3_y - c3_b_y;
  c3_d_a = c3_a[2];
  c3_d_b = c3_b[0];
  c3_c_y = c3_d_a * c3_d_b;
  c3_e_a = c3_a[0];
  c3_e_b = c3_b[2];
  c3_d_y = c3_e_a * c3_e_b;
  c3_c2 = c3_c_y - c3_d_y;
  c3_f_a = c3_a[0];
  c3_f_b = c3_b[1];
  c3_e_y = c3_f_a * c3_f_b;
  c3_g_a = c3_a[1];
  c3_g_b = c3_b[0];
  c3_f_y = c3_g_a * c3_g_b;
  c3_c3 = c3_e_y - c3_f_y;
  c3_c[0] = c3_c1;
  c3_c[1] = c3_c2;
  c3_c[2] = c3_c3;
}

static void c3_c_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c3_ceval_xdot(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T
  c3_incx, real_T c3_y[3], int32_T c3_iy0, int32_T c3_incy)
{
  real_T c3_d;
  c3_d = 0.0;
  if ((real_T)c3_n > 0.0) {
    return ddot32(&c3_n, &c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 3, 1, 0) - 1], &
                  c3_incx, &c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_iy0), 1, 3, 1, 0) - 1], &c3_incy);
  }

  return c3_d;
}

static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i205;
  int32_T c3_i206;
  int32_T c3_i207;
  real_T c3_b_u[9];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_i205 = 0;
  for (c3_i206 = 0; c3_i206 < 3; c3_i206 = c3_i206 + 1) {
    for (c3_i207 = 0; c3_i207 < 3; c3_i207 = c3_i207 + 1) {
      c3_b_u[c3_i207 + c3_i205] = (*((real_T (*)[9])c3_u))[c3_i207 + c3_i205];
    }

    c3_i205 = c3_i205 + 3;
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i208;
  real_T c3_b_u[3];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i208 = 0; c3_i208 < 3; c3_i208 = c3_i208 + 1) {
    c3_b_u[c3_i208] = (*((real_T (*)[3])c3_u))[c3_i208];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_c_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i209;
  real_T c3_b_u[6];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i209 = 0; c3_i209 < 6; c3_i209 = c3_i209 + 1) {
    c3_b_u[c3_i209] = (*((real_T (*)[6])c3_u))[c3_i209];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_d_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_e_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i210;
  real_T c3_b_u[2];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i210 = 0; c3_i210 < 2; c3_i210 = c3_i210 + 1) {
    c3_b_u[c3_i210] = (*((real_T (*)[2])c3_u))[c3_i210];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_twa_parallel_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[66];
  c3_ResolvedFunctionInfo (*c3_b_info)[66];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i211;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  c3_b_info = (c3_ResolvedFunctionInfo (*)[66])c3_info;
  (*c3_b_info)[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c3_b_info)[64].name = "eml_scalar_sin";
  (*c3_b_info)[64].dominantType = "double";
  (*c3_b_info)[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c3_b_info)[64].fileLength = 601U;
  (*c3_b_info)[64].fileTime1 = 1209355990U;
  (*c3_b_info)[64].fileTime2 = 0U;
  (*c3_b_info)[65].context = "";
  (*c3_b_info)[65].name = "mrdivide";
  (*c3_b_info)[65].dominantType = "double";
  (*c3_b_info)[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  (*c3_b_info)[65].fileLength = 800U;
  (*c3_b_info)[65].fileTime1 = 1238459490U;
  (*c3_b_info)[65].fileTime2 = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 66));
  for (c3_i211 = 0; c3_i211 < 66; c3_i211 = c3_i211 + 1) {
    c3_r0 = &c3_info[c3_i211];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
                    "nameCaptureInfo", c3_i211);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name",
                    "nameCaptureInfo", c3_i211);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c3_i211);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c3_i211);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c3_i211);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c3_i211);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c3_i211);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[66])
{
  c3_info[0].context = "";
  c3_info[0].name = "ctranspose";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[B]ctranspose";
  c3_info[0].fileLength = 0U;
  c3_info[0].fileTime1 = 0U;
  c3_info[0].fileTime2 = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "ones";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved = "[B]ones";
  c3_info[1].fileLength = 0U;
  c3_info[1].fileTime1 = 0U;
  c3_info[1].fileTime2 = 0U;
  c3_info[2].context = "";
  c3_info[2].name = "mtimes";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[2].fileLength = 3425U;
  c3_info[2].fileTime1 = 1250697966U;
  c3_info[2].fileTime2 = 0U;
  c3_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[3].name = "nargin";
  c3_info[3].dominantType = "";
  c3_info[3].resolved = "[B]nargin";
  c3_info[3].fileLength = 0U;
  c3_info[3].fileTime1 = 0U;
  c3_info[3].fileTime2 = 0U;
  c3_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[4].name = "gt";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved = "[B]gt";
  c3_info[4].fileLength = 0U;
  c3_info[4].fileTime1 = 0U;
  c3_info[4].fileTime2 = 0U;
  c3_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[5].name = "isa";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[B]isa";
  c3_info[5].fileLength = 0U;
  c3_info[5].fileTime1 = 0U;
  c3_info[5].fileTime2 = 0U;
  c3_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[6].name = "isinteger";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[B]isinteger";
  c3_info[6].fileLength = 0U;
  c3_info[6].fileTime1 = 0U;
  c3_info[6].fileTime2 = 0U;
  c3_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[7].name = "isscalar";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[B]isscalar";
  c3_info[7].fileLength = 0U;
  c3_info[7].fileTime1 = 0U;
  c3_info[7].fileTime2 = 0U;
  c3_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[8].name = "ndims";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved = "[B]ndims";
  c3_info[8].fileLength = 0U;
  c3_info[8].fileTime1 = 0U;
  c3_info[8].fileTime2 = 0U;
  c3_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[9].name = "le";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[B]le";
  c3_info[9].fileLength = 0U;
  c3_info[9].fileTime1 = 0U;
  c3_info[9].fileTime2 = 0U;
  c3_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[10].name = "size";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved = "[B]size";
  c3_info[10].fileLength = 0U;
  c3_info[10].fileTime1 = 0U;
  c3_info[10].fileTime2 = 0U;
  c3_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[11].name = "eq";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved = "[B]eq";
  c3_info[11].fileLength = 0U;
  c3_info[11].fileTime1 = 0U;
  c3_info[11].fileTime2 = 0U;
  c3_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[12].name = "not";
  c3_info[12].dominantType = "logical";
  c3_info[12].resolved = "[B]not";
  c3_info[12].fileLength = 0U;
  c3_info[12].fileTime1 = 0U;
  c3_info[12].fileTime2 = 0U;
  c3_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[13].name = "strcmp";
  c3_info[13].dominantType = "char";
  c3_info[13].resolved = "[B]strcmp";
  c3_info[13].fileLength = 0U;
  c3_info[13].fileTime1 = 0U;
  c3_info[13].fileTime2 = 0U;
  c3_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[14].name = "class";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved = "[B]class";
  c3_info[14].fileLength = 0U;
  c3_info[14].fileTime1 = 0U;
  c3_info[14].fileTime2 = 0U;
  c3_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[15].name = "isreal";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved = "[B]isreal";
  c3_info[15].fileLength = 0U;
  c3_info[15].fileTime1 = 0U;
  c3_info[15].fileTime2 = 0U;
  c3_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[16].name = "ne";
  c3_info[16].dominantType = "logical";
  c3_info[16].resolved = "[B]ne";
  c3_info[16].fileLength = 0U;
  c3_info[16].fileTime1 = 0U;
  c3_info[16].fileTime2 = 0U;
  c3_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[17].name = "eml_index_class";
  c3_info[17].dominantType = "";
  c3_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[17].fileLength = 909U;
  c3_info[17].fileTime1 = 1192491982U;
  c3_info[17].fileTime2 = 0U;
  c3_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[18].name = "cast";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved = "[B]cast";
  c3_info[18].fileLength = 0U;
  c3_info[18].fileTime1 = 0U;
  c3_info[18].fileTime2 = 0U;
  c3_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[19].name = "eml_scalar_eg";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[19].fileLength = 3068U;
  c3_info[19].fileTime1 = 1240287210U;
  c3_info[19].fileTime2 = 0U;
  c3_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c3_info[20].name = "false";
  c3_info[20].dominantType = "";
  c3_info[20].resolved = "[B]false";
  c3_info[20].fileLength = 0U;
  c3_info[20].fileTime1 = 0U;
  c3_info[20].fileTime2 = 0U;
  c3_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[21].name = "isstruct";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved = "[B]isstruct";
  c3_info[21].fileLength = 0U;
  c3_info[21].fileTime1 = 0U;
  c3_info[21].fileTime2 = 0U;
  c3_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c3_info[22].name = "plus";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved = "[B]plus";
  c3_info[22].fileLength = 0U;
  c3_info[22].fileTime1 = 0U;
  c3_info[22].fileTime2 = 0U;
  c3_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[23].name = "isempty";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved = "[B]isempty";
  c3_info[23].fileLength = 0U;
  c3_info[23].fileTime1 = 0U;
  c3_info[23].fileTime2 = 0U;
  c3_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[24].name = "eml_xgemm";
  c3_info[24].dominantType = "int32";
  c3_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[24].fileLength = 3184U;
  c3_info[24].fileTime1 = 1209356052U;
  c3_info[24].fileTime2 = 0U;
  c3_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[25].name = "lt";
  c3_info[25].dominantType = "int32";
  c3_info[25].resolved = "[B]lt";
  c3_info[25].fileLength = 0U;
  c3_info[25].fileTime1 = 0U;
  c3_info[25].fileTime2 = 0U;
  c3_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c3_info[26].name = "length";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[26].fileLength = 326U;
  c3_info[26].fileTime1 = 1226602474U;
  c3_info[26].fileTime2 = 0U;
  c3_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c3_info[27].name = "min";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[27].fileLength = 362U;
  c3_info[27].fileTime1 = 1244760752U;
  c3_info[27].fileTime2 = 0U;
  c3_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[28].name = "nargout";
  c3_info[28].dominantType = "";
  c3_info[28].resolved = "[B]nargout";
  c3_info[28].fileLength = 0U;
  c3_info[28].fileTime1 = 0U;
  c3_info[28].fileTime2 = 0U;
  c3_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[29].name = "eml_min_or_max";
  c3_info[29].dominantType = "char";
  c3_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[29].fileLength = 9969U;
  c3_info[29].fileTime1 = 1240287206U;
  c3_info[29].fileTime2 = 0U;
  c3_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[30].name = "ischar";
  c3_info[30].dominantType = "char";
  c3_info[30].resolved = "[B]ischar";
  c3_info[30].fileLength = 0U;
  c3_info[30].fileTime1 = 0U;
  c3_info[30].fileTime2 = 0U;
  c3_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[31].name = "isnumeric";
  c3_info[31].dominantType = "double";
  c3_info[31].resolved = "[B]isnumeric";
  c3_info[31].fileLength = 0U;
  c3_info[31].fileTime1 = 0U;
  c3_info[31].fileTime2 = 0U;
  c3_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c3_info[32].name = "islogical";
  c3_info[32].dominantType = "double";
  c3_info[32].resolved = "[B]islogical";
  c3_info[32].fileLength = 0U;
  c3_info[32].fileTime1 = 0U;
  c3_info[32].fileTime2 = 0U;
  c3_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c3_info[33].name = "eml_scalexp_alloc";
  c3_info[33].dominantType = "double";
  c3_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[33].fileLength = 808U;
  c3_info[33].fileTime1 = 1230519898U;
  c3_info[33].fileTime2 = 0U;
  c3_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[34].name = "minus";
  c3_info[34].dominantType = "double";
  c3_info[34].resolved = "[B]minus";
  c3_info[34].fileLength = 0U;
  c3_info[34].fileTime1 = 0U;
  c3_info[34].fileTime2 = 0U;
  c3_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[35].name = "eml_refblas_xgemm";
  c3_info[35].dominantType = "int32";
  c3_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[35].fileLength = 5748U;
  c3_info[35].fileTime1 = 1228119072U;
  c3_info[35].fileTime2 = 0U;
  c3_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[36].name = "eml_index_minus";
  c3_info[36].dominantType = "int32";
  c3_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[36].fileLength = 277U;
  c3_info[36].fileTime1 = 1192491984U;
  c3_info[36].fileTime2 = 0U;
  c3_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[37].name = "eml_index_times";
  c3_info[37].dominantType = "int32";
  c3_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[37].fileLength = 280U;
  c3_info[37].fileTime1 = 1192491986U;
  c3_info[37].fileTime2 = 0U;
  c3_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[38].name = "eml_index_plus";
  c3_info[38].dominantType = "int32";
  c3_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[38].fileLength = 272U;
  c3_info[38].fileTime1 = 1192491984U;
  c3_info[38].fileTime2 = 0U;
  c3_info[39].context = "";
  c3_info[39].name = "norm";
  c3_info[39].dominantType = "double";
  c3_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c3_info[39].fileLength = 5312U;
  c3_info[39].fileTime1 = 1262645476U;
  c3_info[39].fileTime2 = 0U;
  c3_info[40].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c3_info[40].name = "isvector";
  c3_info[40].dominantType = "double";
  c3_info[40].resolved = "[B]isvector";
  c3_info[40].fileLength = 0U;
  c3_info[40].fileTime1 = 0U;
  c3_info[40].fileTime2 = 0U;
  c3_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c3_info[41].name = "eml_xnrm2";
  c3_info[41].dominantType = "int32";
  c3_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c3_info[41].fileLength = 718U;
  c3_info[41].fileTime1 = 1209356056U;
  c3_info[41].fileTime2 = 0U;
  c3_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c3_info[42].name = "eml_refblas_xnrm2";
  c3_info[42].dominantType = "int32";
  c3_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[42].fileLength = 1433U;
  c3_info[42].fileTime1 = 1240287242U;
  c3_info[42].fileTime2 = 0U;
  c3_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[43].name = "zeros";
  c3_info[43].dominantType = "char";
  c3_info[43].resolved = "[B]zeros";
  c3_info[43].fileLength = 0U;
  c3_info[43].fileTime1 = 0U;
  c3_info[43].fileTime2 = 0U;
  c3_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[44].name = "true";
  c3_info[44].dominantType = "";
  c3_info[44].resolved = "[B]true";
  c3_info[44].fileLength = 0U;
  c3_info[44].fileTime1 = 0U;
  c3_info[44].fileTime2 = 0U;
  c3_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[45].name = "real";
  c3_info[45].dominantType = "double";
  c3_info[45].resolved = "[B]real";
  c3_info[45].fileLength = 0U;
  c3_info[45].fileTime1 = 0U;
  c3_info[45].fileTime2 = 0U;
  c3_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[46].name = "abs";
  c3_info[46].dominantType = "double";
  c3_info[46].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[46].fileLength = 566U;
  c3_info[46].fileTime1 = 1221292332U;
  c3_info[46].fileTime2 = 0U;
  c3_info[47].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[47].name = "eml_scalar_abs";
  c3_info[47].dominantType = "double";
  c3_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[47].fileLength = 461U;
  c3_info[47].fileTime1 = 1203473160U;
  c3_info[47].fileTime2 = 0U;
  c3_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[48].name = "times";
  c3_info[48].dominantType = "double";
  c3_info[48].resolved = "[B]times";
  c3_info[48].fileLength = 0U;
  c3_info[48].fileTime1 = 0U;
  c3_info[48].fileTime2 = 0U;
  c3_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c3_info[49].name = "imag";
  c3_info[49].dominantType = "double";
  c3_info[49].resolved = "[B]imag";
  c3_info[49].fileLength = 0U;
  c3_info[49].fileTime1 = 0U;
  c3_info[49].fileTime2 = 0U;
  c3_info[50].context = "";
  c3_info[50].name = "rdivide";
  c3_info[50].dominantType = "double";
  c3_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[50].fileLength = 403U;
  c3_info[50].fileTime1 = 1244760752U;
  c3_info[50].fileTime2 = 0U;
  c3_info[51].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[51].name = "eml_div";
  c3_info[51].dominantType = "double";
  c3_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[51].fileLength = 4269U;
  c3_info[51].fileTime1 = 1228119026U;
  c3_info[51].fileTime2 = 0U;
  c3_info[52].context = "";
  c3_info[52].name = "cross";
  c3_info[52].dominantType = "double";
  c3_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c3_info[52].fileLength = 3157U;
  c3_info[52].fileTime1 = 1240287262U;
  c3_info[52].fileTime2 = 0U;
  c3_info[53].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[53].name = "eml_xdotu";
  c3_info[53].dominantType = "int32";
  c3_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[53].fileLength = 1453U;
  c3_info[53].fileTime1 = 1209356050U;
  c3_info[53].fileTime2 = 0U;
  c3_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[54].name = "eml_xdot";
  c3_info[54].dominantType = "int32";
  c3_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[54].fileLength = 1330U;
  c3_info[54].fileTime1 = 1209356048U;
  c3_info[54].fileTime2 = 0U;
  c3_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[55].name = "eml_refblas_xdot";
  c3_info[55].dominantType = "int32";
  c3_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[55].fileLength = 343U;
  c3_info[55].fileTime1 = 1211241242U;
  c3_info[55].fileTime2 = 0U;
  c3_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[56].name = "eml_refblas_xdotx";
  c3_info[56].dominantType = "int32";
  c3_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[56].fileLength = 1605U;
  c3_info[56].fileTime1 = 1236282478U;
  c3_info[56].fileTime2 = 0U;
  c3_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[57].name = "isequal";
  c3_info[57].dominantType = "char";
  c3_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[57].fileLength = 180U;
  c3_info[57].fileTime1 = 1226602470U;
  c3_info[57].fileTime2 = 0U;
  c3_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[58].name = "eml_isequal_core";
  c3_info[58].dominantType = "char";
  c3_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[58].fileLength = 4192U;
  c3_info[58].fileTime1 = 1257808582U;
  c3_info[58].fileTime2 = 0U;
  c3_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[59].name = "ge";
  c3_info[59].dominantType = "double";
  c3_info[59].resolved = "[B]ge";
  c3_info[59].fileLength = 0U;
  c3_info[59].fileTime1 = 0U;
  c3_info[59].fileTime2 = 0U;
  c3_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[60].name = "uminus";
  c3_info[60].dominantType = "int32";
  c3_info[60].resolved = "[B]uminus";
  c3_info[60].fileLength = 0U;
  c3_info[60].fileTime1 = 0U;
  c3_info[60].fileTime2 = 0U;
  c3_info[61].context = "";
  c3_info[61].name = "cos";
  c3_info[61].dominantType = "double";
  c3_info[61].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[61].fileLength = 324U;
  c3_info[61].fileTime1 = 1203473150U;
  c3_info[61].fileTime2 = 0U;
  c3_info[62].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[62].name = "eml_scalar_cos";
  c3_info[62].dominantType = "double";
  c3_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[62].fileLength = 602U;
  c3_info[62].fileTime1 = 1209355986U;
  c3_info[62].fileTime2 = 0U;
  c3_info[63].context = "";
  c3_info[63].name = "sin";
  c3_info[63].dominantType = "double";
  c3_info[63].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[63].fileLength = 324U;
  c3_info[63].fileTime1 = 1203473242U;
  c3_info[63].fileTime2 = 0U;
}

static const mxArray *c3_f_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  boolean_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((boolean_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static void c3_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c3_des_leg_len, const char_T *c3_name
  , real_T c3_y[3])
{
  real_T c3_dv9[3];
  int32_T c3_i212;
  sf_mex_import(c3_name, sf_mex_dup(c3_des_leg_len), &c3_dv9, 1, 0, 0U, 1, 0U, 1,
                3);
  for (c3_i212 = 0; c3_i212 < 3; c3_i212 = c3_i212 + 1) {
    c3_y[c3_i212] = c3_dv9[c3_i212];
  }

  sf_mex_destroy(&c3_des_leg_len);
}

static void c3_b_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c3_qcmd, const char_T *c3_name,
  real_T c3_y[6])
{
  real_T c3_dv10[6];
  int32_T c3_i213;
  sf_mex_import(c3_name, sf_mex_dup(c3_qcmd), &c3_dv10, 1, 0, 0U, 1, 0U, 1, 6);
  for (c3_i213 = 0; c3_i213 < 6; c3_i213 = c3_i213 + 1) {
    c3_y[c3_i213] = c3_dv10[c3_i213];
  }

  sf_mex_destroy(&c3_qcmd);
}

static void c3_c_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c3_rwave_out, const char_T *c3_name
  , real_T c3_y[9])
{
  real_T c3_dv11[9];
  int32_T c3_i214;
  sf_mex_import(c3_name, sf_mex_dup(c3_rwave_out), &c3_dv11, 1, 0, 0U, 1, 0U, 2,
                3, 3);
  for (c3_i214 = 0; c3_i214 < 9; c3_i214 = c3_i214 + 1) {
    c3_y[c3_i214] = c3_dv11[c3_i214];
  }

  sf_mex_destroy(&c3_rwave_out);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c3_is_active_c3_twa_parallel,
  const char_T *c3_name)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_name, sf_mex_dup(c3_is_active_c3_twa_parallel), &c3_u0, 1, 3,
                0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_is_active_c3_twa_parallel);
  return c3_y;
}

static void init_dsm_address_info(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_twa_parallel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4174660877U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1339959007U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3004039193U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1415700140U);
}

mxArray *sf_c3_twa_parallel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3043451842U);
    pr[1] = (double)(3633874054U);
    pr[2] = (double)(224265917U);
    pr[3] = (double)(1760102700U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c3_twa_parallel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[21],T\"des_leg_len\",},{M[1],M[10],T\"eq_out\",},{M[1],M[5],T\"qcmd\",},{M[1],M[14],T\"rwave_out\",},{M[1],M[13],T\"twave_out\",},{M[8],M[0],T\"is_active_c3_twa_parallel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_twa_parallel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_twa_parallelInstanceStruct *chartInstance;
    chartInstance = (SFc3_twa_parallelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_twa_parallelMachineNumber_,
           3,
           1,
           1,
           17,
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
                                1.0,0,"qcur",0,(MexFcnForType)c3_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"eqeps",0,
                              (MexFcnForType)c3_d_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"qcmd",0,(MexFcnForType)c3_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"des_leg_len",0,(MexFcnForType)
                                c3_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"kp",0,
                              (MexFcnForType)c3_d_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dt",0,
                              (MexFcnForType)c3_d_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"p_in_m",0,(MexFcnForType)c3_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"b_in_w",0,(MexFcnForType)c3_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"measured_len",0,(MexFcnForType)
                                c3_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "velmex_pitch",0,(MexFcnForType)c3_d_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"macro_leg_len",0,(MexFcnForType)
                                c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"eq",0,(MexFcnForType)c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(12,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"eq_out",0,(MexFcnForType)c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(13,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"twave_out",0,(MexFcnForType)
                                c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(14,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"rwave_out",0,(MexFcnForType)
                                c3_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(15,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"twave",0,(MexFcnForType)c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(16,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"rwave",0,(MexFcnForType)c3_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1886);
        _SFD_CV_INIT_EML_IF(0,0,261,280,1782,1886);
        _SFD_CV_INIT_EML_FOR(0,0,1364,1376,1492);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c3_qcur)[6];
          real_T *c3_eqeps;
          real_T (*c3_qcmd)[6];
          real_T (*c3_des_leg_len)[3];
          real_T *c3_kp;
          real_T *c3_dt;
          real_T (*c3_p_in_m)[9];
          real_T (*c3_b_in_w)[9];
          real_T (*c3_measured_len)[3];
          real_T *c3_velmex_pitch;
          real_T (*c3_macro_leg_len)[3];
          real_T (*c3_eq)[3];
          real_T (*c3_eq_out)[3];
          real_T (*c3_twave_out)[3];
          real_T (*c3_rwave_out)[9];
          real_T (*c3_twave)[3];
          real_T (*c3_rwave)[9];
          c3_rwave = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 11);
          c3_twave = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 10);
          c3_rwave_out = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S,
            5);
          c3_twave_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            4);
          c3_eq_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c3_eq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
          c3_macro_leg_len = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 8);
          c3_velmex_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_measured_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            6);
          c3_b_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
          c3_p_in_m = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
          c3_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_kp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_des_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            2);
          c3_qcmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_eqeps = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_qcur = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_qcur);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_eqeps);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_qcmd);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_des_leg_len);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_kp);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_dt);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_p_in_m);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_b_in_w);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_measured_len);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_velmex_pitch);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_macro_leg_len);
          _SFD_SET_DATA_VALUE_PTR(11U, c3_eq);
          _SFD_SET_DATA_VALUE_PTR(12U, c3_eq_out);
          _SFD_SET_DATA_VALUE_PTR(13U, c3_twave_out);
          _SFD_SET_DATA_VALUE_PTR(14U, c3_rwave_out);
          _SFD_SET_DATA_VALUE_PTR(15U, c3_twave);
          _SFD_SET_DATA_VALUE_PTR(16U, c3_rwave);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_twa_parallelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_twa_parallel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_twa_parallelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*)
    chartInstanceVar);
  initialize_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_twa_parallel(void *chartInstanceVar)
{
  enable_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_twa_parallel(void *chartInstanceVar)
{
  disable_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_twa_parallel(void *chartInstanceVar)
{
  sf_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_twa_parallel(void *chartInstanceVar)
{
  ext_mode_exec_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c3_twa_parallel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_twa_parallel
    ((SFc3_twa_parallelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c3_twa_parallel();/* state var info */
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

static void sf_internal_set_sim_state_c3_twa_parallel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_twa_parallel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c3_twa_parallel(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_twa_parallel(S);
}

static void sf_opaque_set_sim_state_c3_twa_parallel(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c3_twa_parallel(S, st);
}

static void sf_opaque_terminate_c3_twa_parallel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_twa_parallelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_twa_parallel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_twa_parallel((SFc3_twa_parallelInstanceStruct*)
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

static void mdlSetWorkWidths_c3_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("twa_parallel","twa_parallel",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("twa_parallel","twa_parallel",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("twa_parallel",
      "twa_parallel",3,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"twa_parallel","twa_parallel",3,12);
      sf_mark_chart_reusable_outputs(S,"twa_parallel","twa_parallel",3,5);
    }

    sf_set_rtw_dwork_info(S,"twa_parallel","twa_parallel",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2346785156U));
  ssSetChecksum1(S,(211032420U));
  ssSetChecksum2(S,(3594839285U));
  ssSetChecksum3(S,(3781380574U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "twa_parallel", "twa_parallel",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_twa_parallel(SimStruct *S)
{
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)malloc(sizeof
    (SFc3_twa_parallelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_twa_parallelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_twa_parallel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_twa_parallel;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_twa_parallel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_twa_parallel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_twa_parallel;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_twa_parallel;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_twa_parallel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_twa_parallel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_twa_parallel;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_twa_parallel;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_twa_parallel;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c3_twa_parallel;
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

void c3_twa_parallel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_twa_parallel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_twa_parallel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_twa_parallel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_twa_parallel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
