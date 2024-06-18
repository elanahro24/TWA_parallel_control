/* Include files */

#include "blascompat32.h"
#include "twa_parallel_sfun.h"
#include "c4_twa_parallel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "twa_parallel_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c4_debug_family_names[9] = { "velmex_limit", "initial_len",
  "velmex_stroke", "nargin", "nargout", "macro_leg_len", "velmex_pitch", "q_cur",
  "qmacro_des" };

/* Function Declarations */
static void initialize_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance);
static void initialize_params_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance);
static void enable_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance);
static void disable_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_twa_parallel
  (SFc4_twa_parallelInstanceStruct *chartInstance);
static void ext_mode_exec_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_twa_parallel
  (SFc4_twa_parallelInstanceStruct *chartInstance);
static void set_sim_state_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance);
static void sf_c4_twa_parallel(SFc4_twa_parallelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u);
static const mxArray *c4_c_sf_marshall(void *chartInstanceVoid, void *c4_u);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[33]);
static const mxArray *c4_d_sf_marshall(void *chartInstanceVoid, void *c4_u);
static void c4_emlrt_marshallIn(SFc4_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c4_qmacro_des, const char_T *c4_name, real_T c4_y[3]);
static uint8_T c4_b_emlrt_marshallIn(SFc4_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c4_is_active_c4_twa_parallel, const char_T
  *c4_name);
static void init_dsm_address_info(SFc4_twa_parallelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance)
{
  uint8_T *c4_is_active_c4_twa_parallel;
  c4_is_active_c4_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c4_is_active_c4_twa_parallel = 0U;
}

static void initialize_params_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void enable_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_twa_parallel
  (SFc4_twa_parallelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance)
{
  c4_update_debugger_state_c4_twa_parallel(chartInstance);
}

static const mxArray *get_sim_state_c4_twa_parallel
  (SFc4_twa_parallelInstanceStruct *chartInstance)
{
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_hoistedGlobal[3];
  int32_T c4_i1;
  real_T c4_u[3];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T *c4_is_active_c4_twa_parallel;
  real_T (*c4_qmacro_des)[3];
  c4_qmacro_des = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_is_active_c4_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2));
  for (c4_i0 = 0; c4_i0 < 3; c4_i0 = c4_i0 + 1) {
    c4_hoistedGlobal[c4_i0] = (*c4_qmacro_des)[c4_i0];
  }

  for (c4_i1 = 0; c4_i1 < 3; c4_i1 = c4_i1 + 1) {
    c4_u[c4_i1] = c4_hoistedGlobal[c4_i1];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_is_active_c4_twa_parallel;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[3];
  int32_T c4_i2;
  boolean_T *c4_doneDoubleBufferReInit;
  uint8_T *c4_is_active_c4_twa_parallel;
  real_T (*c4_qmacro_des)[3];
  c4_qmacro_des = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_is_active_c4_twa_parallel = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c4_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                      "qmacro_des", c4_dv0);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2 = c4_i2 + 1) {
    (*c4_qmacro_des)[c4_i2] = c4_dv0[c4_i2];
  }

  *c4_is_active_c4_twa_parallel = c4_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "is_active_c4_twa_parallel");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_twa_parallel(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_twa_parallel(SFc4_twa_parallelInstanceStruct
  *chartInstance)
{
}

static void sf_c4_twa_parallel(SFc4_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_previousEvent;
  int32_T c4_i6;
  real_T c4_hoistedGlobal[3];
  real_T c4_b_hoistedGlobal;
  int32_T c4_i7;
  real_T c4_c_hoistedGlobal[6];
  int32_T c4_i8;
  real_T c4_macro_leg_len[3];
  real_T c4_velmex_pitch;
  int32_T c4_i9;
  real_T c4_q_cur[6];
  uint32_T c4_debug_family_var_map[9];
  static const char *c4_sv0[9] = { "velmex_limit", "initial_len",
    "velmex_stroke", "nargin", "nargout", "macro_leg_len",
    "velmex_pitch", "q_cur", "qmacro_des" };

  real_T c4_velmex_limit;
  real_T c4_initial_len[3];
  real_T c4_velmex_stroke[3];
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 1.0;
  real_T c4_qmacro_des[3];
  int32_T c4_i10;
  int32_T c4_i11;
  static real_T c4_dv1[3] = { 1.30115E+002, 1.2905E+002, 130.495 };

  int32_T c4_i12;
  int32_T c4_i13;
  real_T c4_x[3];
  real_T c4_k;
  real_T c4_b_k;
  real_T c4_b_x;
  real_T c4_y;
  real_T c4_b_y[3];
  int32_T c4_i14;
  boolean_T c4_c_x[3];
  int32_T c4_i15;
  boolean_T c4_d_x[3];
  boolean_T c4_c_y;
  real_T c4_c_k;
  real_T c4_d_k;
  int32_T c4_i16;
  real_T c4_A[3];
  real_T c4_B;
  int32_T c4_i17;
  real_T c4_e_x[3];
  real_T c4_d_y;
  int32_T c4_i18;
  real_T c4_f_x[3];
  real_T c4_e_y;
  int32_T c4_i19;
  real_T c4_g_x[3];
  real_T c4_f_y;
  int32_T c4_i20;
  int32_T c4_i21;
  real_T *c4_b_velmex_pitch;
  real_T (*c4_b_qmacro_des)[3];
  real_T (*c4_b_q_cur)[6];
  real_T (*c4_b_macro_leg_len)[3];
  c4_b_q_cur = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_velmex_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_qmacro_des = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_macro_leg_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  for (c4_i3 = 0; c4_i3 < 3; c4_i3 = c4_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_macro_leg_len)[c4_i3], 0U);
  }

  for (c4_i4 = 0; c4_i4 < 3; c4_i4 = c4_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_qmacro_des)[c4_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_b_velmex_pitch, 2U);
  for (c4_i5 = 0; c4_i5 < 6; c4_i5 = c4_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_q_cur)[c4_i5], 3U);
  }

  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  for (c4_i6 = 0; c4_i6 < 3; c4_i6 = c4_i6 + 1) {
    c4_hoistedGlobal[c4_i6] = (*c4_b_macro_leg_len)[c4_i6];
  }

  c4_b_hoistedGlobal = *c4_b_velmex_pitch;
  for (c4_i7 = 0; c4_i7 < 6; c4_i7 = c4_i7 + 1) {
    c4_c_hoistedGlobal[c4_i7] = (*c4_b_q_cur)[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 3; c4_i8 = c4_i8 + 1) {
    c4_macro_leg_len[c4_i8] = c4_hoistedGlobal[c4_i8];
  }

  c4_velmex_pitch = c4_b_hoistedGlobal;
  for (c4_i9 = 0; c4_i9 < 6; c4_i9 = c4_i9 + 1) {
    c4_q_cur[c4_i9] = c4_c_hoistedGlobal[c4_i9];
  }

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c4_sv0, c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c4_velmex_limit, c4_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c4_initial_len, c4_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c4_velmex_stroke, c4_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c4_nargin, c4_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c4_nargout, c4_c_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c4_macro_leg_len, c4_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c4_velmex_pitch, c4_c_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c4_q_cur, c4_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c4_qmacro_des, c4_sf_marshall, 8U);
  CV_EML_FCN(0, 0);

  /*  This function solves for command signal for given desired macro leg */
  /*  lengths */
  _SFD_EML_CALL(0,5);
  for (c4_i10 = 0; c4_i10 < 3; c4_i10 = c4_i10 + 1) {
    c4_qmacro_des[c4_i10] = c4_q_cur[c4_i10];
  }

  _SFD_EML_CALL(0,7);
  c4_velmex_limit = 30.0;

  /* +-30 mm stroke from starting point at the velmex pivot  */
  _SFD_EML_CALL(0,9);
  for (c4_i11 = 0; c4_i11 < 3; c4_i11 = c4_i11 + 1) {
    c4_initial_len[c4_i11] = c4_dv1[c4_i11];
  }

  _SFD_EML_CALL(0,11);
  for (c4_i12 = 0; c4_i12 < 3; c4_i12 = c4_i12 + 1) {
    c4_velmex_stroke[c4_i12] = 0.0;
  }

  _SFD_EML_CALL(0,12);
  c4_velmex_stroke[0] = c4_macro_leg_len[0] - c4_initial_len[0];
  _SFD_EML_CALL(0,13);
  c4_velmex_stroke[1] = c4_macro_leg_len[1] - c4_initial_len[1];
  _SFD_EML_CALL(0,14);
  c4_velmex_stroke[2] = c4_macro_leg_len[2] - c4_initial_len[2];
  _SFD_EML_CALL(0,16);
  for (c4_i13 = 0; c4_i13 < 3; c4_i13 = c4_i13 + 1) {
    c4_x[c4_i13] = c4_velmex_stroke[c4_i13];
  }

  for (c4_k = 1.0; c4_k <= 3.0; c4_k = c4_k + 1.0) {
    c4_b_k = c4_k;
    c4_b_x = c4_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c4_b_k), 1, 3, 1, 0) - 1];
    c4_y = muDoubleScalarAbs(c4_b_x);
    c4_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c4_b_k), 1, 3, 1, 0) - 1] = c4_y;
  }

  for (c4_i14 = 0; c4_i14 < 3; c4_i14 = c4_i14 + 1) {
    c4_c_x[c4_i14] = (c4_b_y[c4_i14] < c4_velmex_limit);
  }

  for (c4_i15 = 0; c4_i15 < 3; c4_i15 = c4_i15 + 1) {
    c4_d_x[c4_i15] = c4_c_x[c4_i15];
  }

  c4_c_y = TRUE;
  c4_c_k = 1.0;
 label_1:
  ;
  if (c4_c_k <= 3.0) {
    c4_d_k = c4_c_k;
    if ((real_T)c4_d_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c4_d_k), 1, 3, 1, 0) - 1] == 0.0) {
      c4_c_y = FALSE;
    } else {
      c4_c_k = c4_c_k + 1.0;
      goto label_1;
    }
  }

  if (CV_EML_IF(0, 0, c4_c_y)) {
    _SFD_EML_CALL(0,17);
    for (c4_i16 = 0; c4_i16 < 3; c4_i16 = c4_i16 + 1) {
      c4_A[c4_i16] = c4_velmex_stroke[c4_i16];
    }

    c4_B = c4_velmex_pitch;
    for (c4_i17 = 0; c4_i17 < 3; c4_i17 = c4_i17 + 1) {
      c4_e_x[c4_i17] = c4_A[c4_i17];
    }

    c4_d_y = c4_B;
    for (c4_i18 = 0; c4_i18 < 3; c4_i18 = c4_i18 + 1) {
      c4_f_x[c4_i18] = c4_e_x[c4_i18];
    }

    c4_e_y = c4_d_y;
    for (c4_i19 = 0; c4_i19 < 3; c4_i19 = c4_i19 + 1) {
      c4_g_x[c4_i19] = c4_f_x[c4_i19];
    }

    c4_f_y = c4_e_y;
    for (c4_i20 = 0; c4_i20 < 3; c4_i20 = c4_i20 + 1) {
      c4_qmacro_des[c4_i20] = c4_g_x[c4_i20] / c4_f_y;
    }
  }

  _SFD_EML_CALL(0,-17);
  sf_debug_symbol_scope_pop();
  for (c4_i21 = 0; c4_i21 < 3; c4_i21 = c4_i21 + 1) {
    (*c4_b_qmacro_des)[c4_i21] = c4_qmacro_des[c4_i21];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_twa_parallelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i22;
  real_T c4_b_u[3];
  const mxArray *c4_b_y = NULL;
  SFc4_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc4_twa_parallelInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  for (c4_i22 = 0; c4_i22 < 3; c4_i22 = c4_i22 + 1) {
    c4_b_u[c4_i22] = (*((real_T (*)[3])c4_u))[c4_i22];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i23;
  real_T c4_b_u[6];
  const mxArray *c4_b_y = NULL;
  SFc4_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc4_twa_parallelInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  for (c4_i23 = 0; c4_i23 < 6; c4_i23 = c4_i23 + 1) {
    c4_b_u[c4_i23] = (*((real_T (*)[6])c4_u))[c4_i23];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_c_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc4_twa_parallelInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_twa_parallel_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[33];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i24;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 33));
  for (c4_i24 = 0; c4_i24 < 33; c4_i24 = c4_i24 + 1) {
    c4_r0 = &c4_info[c4_i24];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i24);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i24);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i24);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i24);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i24);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i24
                    );
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i24
                    );
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[33])
{
  c4_info[0].context = "";
  c4_info[0].name = "zeros";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved = "[B]zeros";
  c4_info[0].fileLength = 0U;
  c4_info[0].fileTime1 = 0U;
  c4_info[0].fileTime2 = 0U;
  c4_info[1].context = "";
  c4_info[1].name = "minus";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved = "[B]minus";
  c4_info[1].fileLength = 0U;
  c4_info[1].fileTime1 = 0U;
  c4_info[1].fileTime2 = 0U;
  c4_info[2].context = "";
  c4_info[2].name = "abs";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[2].fileLength = 566U;
  c4_info[2].fileTime1 = 1221292332U;
  c4_info[2].fileTime2 = 0U;
  c4_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[3].name = "nargin";
  c4_info[3].dominantType = "";
  c4_info[3].resolved = "[B]nargin";
  c4_info[3].fileLength = 0U;
  c4_info[3].fileTime1 = 0U;
  c4_info[3].fileTime2 = 0U;
  c4_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[4].name = "gt";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved = "[B]gt";
  c4_info[4].fileLength = 0U;
  c4_info[4].fileTime1 = 0U;
  c4_info[4].fileTime2 = 0U;
  c4_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[5].name = "isa";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved = "[B]isa";
  c4_info[5].fileLength = 0U;
  c4_info[5].fileTime1 = 0U;
  c4_info[5].fileTime2 = 0U;
  c4_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[6].name = "ischar";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved = "[B]ischar";
  c4_info[6].fileLength = 0U;
  c4_info[6].fileTime1 = 0U;
  c4_info[6].fileTime2 = 0U;
  c4_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[7].name = "islogical";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved = "[B]islogical";
  c4_info[7].fileLength = 0U;
  c4_info[7].fileTime1 = 0U;
  c4_info[7].fileTime2 = 0U;
  c4_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[8].name = "size";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved = "[B]size";
  c4_info[8].fileLength = 0U;
  c4_info[8].fileTime1 = 0U;
  c4_info[8].fileTime2 = 0U;
  c4_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[9].name = "class";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved = "[B]class";
  c4_info[9].fileLength = 0U;
  c4_info[9].fileTime1 = 0U;
  c4_info[9].fileTime2 = 0U;
  c4_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[10].name = "eml_scalar_abs";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c4_info[10].fileLength = 461U;
  c4_info[10].fileTime1 = 1203473160U;
  c4_info[10].fileTime2 = 0U;
  c4_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c4_info[11].name = "isinteger";
  c4_info[11].dominantType = "double";
  c4_info[11].resolved = "[B]isinteger";
  c4_info[11].fileLength = 0U;
  c4_info[11].fileTime1 = 0U;
  c4_info[11].fileTime2 = 0U;
  c4_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c4_info[12].name = "isreal";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved = "[B]isreal";
  c4_info[12].fileLength = 0U;
  c4_info[12].fileTime1 = 0U;
  c4_info[12].fileTime2 = 0U;
  c4_info[13].context = "";
  c4_info[13].name = "lt";
  c4_info[13].dominantType = "double";
  c4_info[13].resolved = "[B]lt";
  c4_info[13].fileLength = 0U;
  c4_info[13].fileTime1 = 0U;
  c4_info[13].fileTime2 = 0U;
  c4_info[14].context = "";
  c4_info[14].name = "all";
  c4_info[14].dominantType = "logical";
  c4_info[14].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c4_info[14].fileLength = 427U;
  c4_info[14].fileTime1 = 1221292338U;
  c4_info[14].fileTime2 = 0U;
  c4_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c4_info[15].name = "eml_all_or_any";
  c4_info[15].dominantType = "char";
  c4_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[15].fileLength = 3729U;
  c4_info[15].fileTime1 = 1240287200U;
  c4_info[15].fileTime2 = 0U;
  c4_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[16].name = "strcmp";
  c4_info[16].dominantType = "char";
  c4_info[16].resolved = "[B]strcmp";
  c4_info[16].fileLength = 0U;
  c4_info[16].fileTime1 = 0U;
  c4_info[16].fileTime2 = 0U;
  c4_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[17].name = "isequal";
  c4_info[17].dominantType = "double";
  c4_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[17].fileLength = 180U;
  c4_info[17].fileTime1 = 1226602470U;
  c4_info[17].fileTime2 = 0U;
  c4_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[18].name = "false";
  c4_info[18].dominantType = "";
  c4_info[18].resolved = "[B]false";
  c4_info[18].fileLength = 0U;
  c4_info[18].fileTime1 = 0U;
  c4_info[18].fileTime2 = 0U;
  c4_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c4_info[19].name = "eml_isequal_core";
  c4_info[19].dominantType = "double";
  c4_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[19].fileLength = 4192U;
  c4_info[19].fileTime1 = 1257808582U;
  c4_info[19].fileTime2 = 0U;
  c4_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[20].name = "ge";
  c4_info[20].dominantType = "double";
  c4_info[20].resolved = "[B]ge";
  c4_info[20].fileLength = 0U;
  c4_info[20].fileTime1 = 0U;
  c4_info[20].fileTime2 = 0U;
  c4_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[21].name = "isscalar";
  c4_info[21].dominantType = "logical";
  c4_info[21].resolved = "[B]isscalar";
  c4_info[21].fileLength = 0U;
  c4_info[21].fileTime1 = 0U;
  c4_info[21].fileTime2 = 0U;
  c4_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[22].name = "isnumeric";
  c4_info[22].dominantType = "logical";
  c4_info[22].resolved = "[B]isnumeric";
  c4_info[22].fileLength = 0U;
  c4_info[22].fileTime1 = 0U;
  c4_info[22].fileTime2 = 0U;
  c4_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c4_info[23].name = "ndims";
  c4_info[23].dominantType = "logical";
  c4_info[23].resolved = "[B]ndims";
  c4_info[23].fileLength = 0U;
  c4_info[23].fileTime1 = 0U;
  c4_info[23].fileTime2 = 0U;
  c4_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c4_info[24].name = "ne";
  c4_info[24].dominantType = "double";
  c4_info[24].resolved = "[B]ne";
  c4_info[24].fileLength = 0U;
  c4_info[24].fileTime1 = 0U;
  c4_info[24].fileTime2 = 0U;
  c4_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c4_info[25].name = "true";
  c4_info[25].dominantType = "";
  c4_info[25].resolved = "[B]true";
  c4_info[25].fileLength = 0U;
  c4_info[25].fileTime1 = 0U;
  c4_info[25].fileTime2 = 0U;
  c4_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c4_info[26].name = "not";
  c4_info[26].dominantType = "logical";
  c4_info[26].resolved = "[B]not";
  c4_info[26].fileLength = 0U;
  c4_info[26].fileTime1 = 0U;
  c4_info[26].fileTime2 = 0U;
  c4_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[27].name = "eml_const_nonsingleton_dim";
  c4_info[27].dominantType = "logical";
  c4_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c4_info[27].fileLength = 1473U;
  c4_info[27].fileTime1 = 1240287202U;
  c4_info[27].fileTime2 = 0U;
  c4_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[28].name = "isempty";
  c4_info[28].dominantType = "logical";
  c4_info[28].resolved = "[B]isempty";
  c4_info[28].fileLength = 0U;
  c4_info[28].fileTime1 = 0U;
  c4_info[28].fileTime2 = 0U;
  c4_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c4_info[29].name = "eq";
  c4_info[29].dominantType = "double";
  c4_info[29].resolved = "[B]eq";
  c4_info[29].fileLength = 0U;
  c4_info[29].fileTime1 = 0U;
  c4_info[29].fileTime2 = 0U;
  c4_info[30].context = "";
  c4_info[30].name = "mrdivide";
  c4_info[30].dominantType = "double";
  c4_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c4_info[30].fileLength = 800U;
  c4_info[30].fileTime1 = 1238459490U;
  c4_info[30].fileTime2 = 0U;
  c4_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c4_info[31].name = "rdivide";
  c4_info[31].dominantType = "double";
  c4_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[31].fileLength = 403U;
  c4_info[31].fileTime1 = 1244760752U;
  c4_info[31].fileTime2 = 0U;
  c4_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[32].name = "eml_div";
  c4_info[32].dominantType = "double";
  c4_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[32].fileLength = 4269U;
  c4_info[32].fileTime1 = 1228119026U;
  c4_info[32].fileTime2 = 0U;
}

static const mxArray *c4_d_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  boolean_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc4_twa_parallelInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((boolean_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static void c4_emlrt_marshallIn(SFc4_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c4_qmacro_des, const char_T *c4_name
  , real_T c4_y[3])
{
  real_T c4_dv2[3];
  int32_T c4_i25;
  sf_mex_import(c4_name, sf_mex_dup(c4_qmacro_des), &c4_dv2, 1, 0, 0U, 1, 0U, 1,
                3);
  for (c4_i25 = 0; c4_i25 < 3; c4_i25 = c4_i25 + 1) {
    c4_y[c4_i25] = c4_dv2[c4_i25];
  }

  sf_mex_destroy(&c4_qmacro_des);
}

static uint8_T c4_b_emlrt_marshallIn(SFc4_twa_parallelInstanceStruct
  *chartInstance, const mxArray *c4_is_active_c4_twa_parallel,
  const char_T *c4_name)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_name, sf_mex_dup(c4_is_active_c4_twa_parallel), &c4_u0, 1, 3,
                0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_is_active_c4_twa_parallel);
  return c4_y;
}

static void init_dsm_address_info(SFc4_twa_parallelInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_twa_parallel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(36356975U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(556757150U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1159059255U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1826523230U);
}

mxArray *sf_c4_twa_parallel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2124761394U);
    pr[1] = (double)(1022661362U);
    pr[2] = (double)(3665958403U);
    pr[3] = (double)(156517112U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static mxArray *sf_get_sim_state_info_c4_twa_parallel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[16],T\"qmacro_des\",},{M[8],M[0],T\"is_active_c4_twa_parallel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_twa_parallel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_twa_parallelInstanceStruct *chartInstance;
    chartInstance = (SFc4_twa_parallelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_twa_parallelMachineNumber_,
           4,
           1,
           1,
           4,
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
                                1.0,0,"macro_leg_len",0,(MexFcnForType)
                                c4_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"qmacro_des",0,(MexFcnForType)
                                c4_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "velmex_pitch",0,(MexFcnForType)c4_c_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_cur",0,(MexFcnForType)c4_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,607);
        _SFD_CV_INIT_EML_IF(0,0,514,555,-1,607);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c4_macro_leg_len)[3];
          real_T (*c4_qmacro_des)[3];
          real_T *c4_velmex_pitch;
          real_T (*c4_q_cur)[6];
          c4_q_cur = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c4_velmex_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_qmacro_des = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            1);
          c4_macro_leg_len = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_macro_leg_len);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_qmacro_des);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_velmex_pitch);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_q_cur);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_twa_parallelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_twa_parallel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_twa_parallelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*)
    chartInstanceVar);
  initialize_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_twa_parallel(void *chartInstanceVar)
{
  enable_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_twa_parallel(void *chartInstanceVar)
{
  disable_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_twa_parallel(void *chartInstanceVar)
{
  sf_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c4_twa_parallel(void *chartInstanceVar)
{
  ext_mode_exec_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c4_twa_parallel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_twa_parallel
    ((SFc4_twa_parallelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c4_twa_parallel();/* state var info */
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

static void sf_internal_set_sim_state_c4_twa_parallel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_twa_parallel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c4_twa_parallel(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_twa_parallel(S);
}

static void sf_opaque_set_sim_state_c4_twa_parallel(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c4_twa_parallel(S, st);
}

static void sf_opaque_terminate_c4_twa_parallel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_twa_parallelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_twa_parallel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_twa_parallel((SFc4_twa_parallelInstanceStruct*)
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

static void mdlSetWorkWidths_c4_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("twa_parallel","twa_parallel",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("twa_parallel","twa_parallel",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("twa_parallel",
      "twa_parallel",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"twa_parallel","twa_parallel",4,3);
      sf_mark_chart_reusable_outputs(S,"twa_parallel","twa_parallel",4,1);
    }

    sf_set_rtw_dwork_info(S,"twa_parallel","twa_parallel",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2672925757U));
  ssSetChecksum1(S,(2650836524U));
  ssSetChecksum2(S,(125582482U));
  ssSetChecksum3(S,(1670621621U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_twa_parallel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "twa_parallel", "twa_parallel",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_twa_parallel(SimStruct *S)
{
  SFc4_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc4_twa_parallelInstanceStruct *)malloc(sizeof
    (SFc4_twa_parallelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_twa_parallelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_twa_parallel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_twa_parallel;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_twa_parallel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_twa_parallel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_twa_parallel;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_twa_parallel;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_twa_parallel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_twa_parallel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_twa_parallel;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_twa_parallel;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_twa_parallel;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c4_twa_parallel;
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

void c4_twa_parallel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_twa_parallel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_twa_parallel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_twa_parallel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_twa_parallel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
