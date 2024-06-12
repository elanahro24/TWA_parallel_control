/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c15_large_snake.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c15_debug_family_names[7] = { "nargin", "nargout", "pots",
  "pot_home", "q_home", "pot_gains", "q_est" };

/* Function Declarations */
static void initialize_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance);
static void enable_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance);
static void disable_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance);
static void c15_update_debugger_state_c15_large_snake
  (SFc15_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c15_large_snake
  (SFc15_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance, const mxArray *c15_st);
static void finalize_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance);
static void sf_c15_large_snake(SFc15_large_snakeInstanceStruct *chartInstance);
static void c15_c15_large_snake(SFc15_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber);
static void c15_eml_scalar_eg(SFc15_large_snakeInstanceStruct *chartInstance);
static const mxArray *c15_sf_marshall(void *chartInstanceVoid, void *c15_u);
static const mxArray *c15_b_sf_marshall(void *chartInstanceVoid, void *c15_u);
static const mxArray *c15_c_sf_marshall(void *chartInstanceVoid, void *c15_u);
static void c15_info_helper(c15_ResolvedFunctionInfo c15_info[38]);
static const mxArray *c15_d_sf_marshall(void *chartInstanceVoid, void *c15_u);
static void c15_emlrt_marshallIn(SFc15_large_snakeInstanceStruct *chartInstance,
  const mxArray *c15_q_est, const char_T *c15_name, real_T c15_y[9]);
static uint8_T c15_b_emlrt_marshallIn(SFc15_large_snakeInstanceStruct
  *chartInstance, const mxArray *c15_is_active_c15_large_snake, const char_T
  *c15_name);
static void init_dsm_address_info(SFc15_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c15_is_active_c15_large_snake;
  c15_is_active_c15_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c15_is_active_c15_large_snake = 0U;
}

static void initialize_params_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c15_update_debugger_state_c15_large_snake
  (SFc15_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance)
{
  c15_update_debugger_state_c15_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c15_large_snake
  (SFc15_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c15_st = NULL;
  const mxArray *c15_y = NULL;
  int32_T c15_i0;
  real_T c15_hoistedGlobal[9];
  int32_T c15_i1;
  real_T c15_u[9];
  const mxArray *c15_b_y = NULL;
  uint8_T c15_b_hoistedGlobal;
  uint8_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  uint8_T *c15_is_active_c15_large_snake;
  real_T (*c15_q_est)[9];
  c15_q_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_is_active_c15_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellarray(2));
  for (c15_i0 = 0; c15_i0 < 9; c15_i0 = c15_i0 + 1) {
    c15_hoistedGlobal[c15_i0] = (*c15_q_est)[c15_i0];
  }

  for (c15_i1 = 0; c15_i1 < 9; c15_i1 = c15_i1 + 1) {
    c15_u[c15_i1] = c15_hoistedGlobal[c15_i1];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_u, 0, 0U, 1U, 0U, 1, 9));
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_b_hoistedGlobal = *c15_is_active_c15_large_snake;
  c15_b_u = c15_b_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c15_y, 1, c15_c_y);
  sf_mex_assign(&c15_st, c15_y);
  return c15_st;
}

static void set_sim_state_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_u;
  real_T c15_dv0[9];
  int32_T c15_i2;
  boolean_T *c15_doneDoubleBufferReInit;
  uint8_T *c15_is_active_c15_large_snake;
  real_T (*c15_q_est)[9];
  c15_q_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_is_active_c15_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c15_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c15_doneDoubleBufferReInit = TRUE;
  c15_u = sf_mex_dup(c15_st);
  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
                       "q_est", c15_dv0);
  for (c15_i2 = 0; c15_i2 < 9; c15_i2 = c15_i2 + 1) {
    (*c15_q_est)[c15_i2] = c15_dv0[c15_i2];
  }

  *c15_is_active_c15_large_snake = c15_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c15_u, 1)),
    "is_active_c15_large_snake");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_large_snake(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_large_snake(SFc15_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c15_large_snake(SFc15_large_snakeInstanceStruct *chartInstance)
{
  int32_T c15_i3;
  int32_T c15_i4;
  int32_T c15_i5;
  int32_T c15_i6;
  int32_T c15_i7;
  int32_T c15_previousEvent;
  real_T (*c15_pot_gains)[81];
  real_T (*c15_q_home)[9];
  real_T (*c15_pot_home)[9];
  real_T (*c15_pots)[9];
  real_T (*c15_q_est)[9];
  c15_pot_gains = (real_T (*)[81])ssGetInputPortSignal(chartInstance->S, 3);
  c15_q_home = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
  c15_pot_home = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c15_pots = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c15_q_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,12);
  for (c15_i3 = 0; c15_i3 < 9; c15_i3 = c15_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c15_q_est)[c15_i3], 0U);
  }

  for (c15_i4 = 0; c15_i4 < 9; c15_i4 = c15_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c15_pots)[c15_i4], 1U);
  }

  for (c15_i5 = 0; c15_i5 < 9; c15_i5 = c15_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c15_pot_home)[c15_i5], 2U);
  }

  for (c15_i6 = 0; c15_i6 < 9; c15_i6 = c15_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c15_q_home)[c15_i6], 3U);
  }

  for (c15_i7 = 0; c15_i7 < 81; c15_i7 = c15_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c15_pot_gains)[c15_i7], 4U);
  }

  c15_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c15_c15_large_snake(chartInstance);
  _sfEvent_ = c15_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c15_c15_large_snake(SFc15_large_snakeInstanceStruct *chartInstance)
{
  int32_T c15_i8;
  real_T c15_hoistedGlobal[9];
  int32_T c15_i9;
  real_T c15_b_hoistedGlobal[9];
  int32_T c15_i10;
  real_T c15_c_hoistedGlobal[9];
  int32_T c15_i11;
  real_T c15_d_hoistedGlobal[81];
  int32_T c15_i12;
  real_T c15_pots[9];
  int32_T c15_i13;
  real_T c15_pot_home[9];
  int32_T c15_i14;
  real_T c15_q_home[9];
  int32_T c15_i15;
  real_T c15_pot_gains[81];
  uint32_T c15_debug_family_var_map[7];
  real_T c15_nargin = 4.0;
  real_T c15_nargout = 1.0;
  real_T c15_q_est[9];
  int32_T c15_i16;
  real_T c15_a[81];
  int32_T c15_i17;
  real_T c15_b[9];
  int32_T c15_i18;
  real_T c15_A[81];
  int32_T c15_i19;
  real_T c15_B[9];
  int32_T c15_i20;
  real_T c15_b_A[81];
  int32_T c15_i21;
  real_T c15_b_B[9];
  int32_T c15_i22;
  real_T c15_c_A[81];
  int32_T c15_i23;
  real_T c15_c_B[9];
  int32_T c15_i24;
  real_T c15_y[9];
  int32_T c15_i25;
  int32_T c15_i26;
  int32_T c15_i27;
  int32_T c15_i28;
  real_T (*c15_b_q_est)[9];
  real_T (*c15_b_pot_gains)[81];
  real_T (*c15_b_q_home)[9];
  real_T (*c15_b_pot_home)[9];
  real_T (*c15_b_pots)[9];
  c15_b_pot_gains = (real_T (*)[81])ssGetInputPortSignal(chartInstance->S, 3);
  c15_b_q_home = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
  c15_b_pot_home = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c15_b_pots = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c15_b_q_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,12);
  for (c15_i8 = 0; c15_i8 < 9; c15_i8 = c15_i8 + 1) {
    c15_hoistedGlobal[c15_i8] = (*c15_b_pots)[c15_i8];
  }

  for (c15_i9 = 0; c15_i9 < 9; c15_i9 = c15_i9 + 1) {
    c15_b_hoistedGlobal[c15_i9] = (*c15_b_pot_home)[c15_i9];
  }

  for (c15_i10 = 0; c15_i10 < 9; c15_i10 = c15_i10 + 1) {
    c15_c_hoistedGlobal[c15_i10] = (*c15_b_q_home)[c15_i10];
  }

  for (c15_i11 = 0; c15_i11 < 81; c15_i11 = c15_i11 + 1) {
    c15_d_hoistedGlobal[c15_i11] = (*c15_b_pot_gains)[c15_i11];
  }

  for (c15_i12 = 0; c15_i12 < 9; c15_i12 = c15_i12 + 1) {
    c15_pots[c15_i12] = c15_hoistedGlobal[c15_i12];
  }

  for (c15_i13 = 0; c15_i13 < 9; c15_i13 = c15_i13 + 1) {
    c15_pot_home[c15_i13] = c15_b_hoistedGlobal[c15_i13];
  }

  for (c15_i14 = 0; c15_i14 < 9; c15_i14 = c15_i14 + 1) {
    c15_q_home[c15_i14] = c15_c_hoistedGlobal[c15_i14];
  }

  for (c15_i15 = 0; c15_i15 < 81; c15_i15 = c15_i15 + 1) {
    c15_pot_gains[c15_i15] = c15_d_hoistedGlobal[c15_i15];
  }

  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c15_debug_family_names,
    c15_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c15_nargin, c15_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c15_nargout, c15_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c15_pots, c15_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c15_pot_home, c15_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c15_q_home, c15_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c15_pot_gains, c15_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c15_q_est, c15_sf_marshall, 6U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  for (c15_i16 = 0; c15_i16 < 81; c15_i16 = c15_i16 + 1) {
    c15_a[c15_i16] = c15_pot_gains[c15_i16];
  }

  for (c15_i17 = 0; c15_i17 < 9; c15_i17 = c15_i17 + 1) {
    c15_b[c15_i17] = c15_pots[c15_i17] - c15_pot_home[c15_i17];
  }

  c15_eml_scalar_eg(chartInstance);
  c15_eml_scalar_eg(chartInstance);
  for (c15_i18 = 0; c15_i18 < 81; c15_i18 = c15_i18 + 1) {
    c15_A[c15_i18] = c15_a[c15_i18];
  }

  for (c15_i19 = 0; c15_i19 < 9; c15_i19 = c15_i19 + 1) {
    c15_B[c15_i19] = c15_b[c15_i19];
  }

  for (c15_i20 = 0; c15_i20 < 81; c15_i20 = c15_i20 + 1) {
    c15_b_A[c15_i20] = c15_A[c15_i20];
  }

  for (c15_i21 = 0; c15_i21 < 9; c15_i21 = c15_i21 + 1) {
    c15_b_B[c15_i21] = c15_B[c15_i21];
  }

  for (c15_i22 = 0; c15_i22 < 81; c15_i22 = c15_i22 + 1) {
    c15_c_A[c15_i22] = c15_b_A[c15_i22];
  }

  for (c15_i23 = 0; c15_i23 < 9; c15_i23 = c15_i23 + 1) {
    c15_c_B[c15_i23] = c15_b_B[c15_i23];
  }

  for (c15_i24 = 0; c15_i24 < 9; c15_i24 = c15_i24 + 1) {
    c15_y[c15_i24] = 0.0;
    c15_i25 = 0;
    for (c15_i26 = 0; c15_i26 < 9; c15_i26 = c15_i26 + 1) {
      c15_y[c15_i24] = c15_y[c15_i24] + c15_c_A[c15_i25 + c15_i24] *
        c15_c_B[c15_i26];
      c15_i25 = c15_i25 + 9;
    }
  }

  for (c15_i27 = 0; c15_i27 < 9; c15_i27 = c15_i27 + 1) {
    c15_q_est[c15_i27] = c15_q_home[c15_i27] + c15_y[c15_i27];
  }

  _SFD_EML_CALL(0,-3);
  sf_debug_symbol_scope_pop();
  for (c15_i28 = 0; c15_i28 < 9; c15_i28 = c15_i28 + 1) {
    (*c15_b_q_est)[c15_i28] = c15_q_est[c15_i28];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber)
{
}

static void c15_eml_scalar_eg(SFc15_large_snakeInstanceStruct *chartInstance)
{
}

static const mxArray *c15_sf_marshall(void *chartInstanceVoid, void *c15_u)
{
  const mxArray *c15_y = NULL;
  int32_T c15_i29;
  real_T c15_b_u[9];
  const mxArray *c15_b_y = NULL;
  SFc15_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc15_large_snakeInstanceStruct *)chartInstanceVoid;
  c15_y = NULL;
  for (c15_i29 = 0; c15_i29 < 9; c15_i29 = c15_i29 + 1) {
    c15_b_u[c15_i29] = (*((real_T (*)[9])c15_u))[c15_i29];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_b_u, 0, 0U, 1U, 0U, 1, 9));
  sf_mex_assign(&c15_y, c15_b_y);
  return c15_y;
}

static const mxArray *c15_b_sf_marshall(void *chartInstanceVoid, void *c15_u)
{
  const mxArray *c15_y = NULL;
  int32_T c15_i30;
  int32_T c15_i31;
  int32_T c15_i32;
  real_T c15_b_u[81];
  const mxArray *c15_b_y = NULL;
  SFc15_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc15_large_snakeInstanceStruct *)chartInstanceVoid;
  c15_y = NULL;
  c15_i30 = 0;
  for (c15_i31 = 0; c15_i31 < 9; c15_i31 = c15_i31 + 1) {
    for (c15_i32 = 0; c15_i32 < 9; c15_i32 = c15_i32 + 1) {
      c15_b_u[c15_i32 + c15_i30] = (*((real_T (*)[81])c15_u))[c15_i32 + c15_i30];
    }

    c15_i30 = c15_i30 + 9;
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_b_u, 0, 0U, 1U, 0U, 2, 9, 9));
  sf_mex_assign(&c15_y, c15_b_y);
  return c15_y;
}

static const mxArray *c15_c_sf_marshall(void *chartInstanceVoid, void *c15_u)
{
  const mxArray *c15_y = NULL;
  real_T c15_b_u;
  const mxArray *c15_b_y = NULL;
  SFc15_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc15_large_snakeInstanceStruct *)chartInstanceVoid;
  c15_y = NULL;
  c15_b_u = *((real_T *)c15_u);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c15_y, c15_b_y);
  return c15_y;
}

const mxArray *sf_c15_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_ResolvedFunctionInfo c15_info[38];
  const mxArray *c15_m0 = NULL;
  int32_T c15_i33;
  c15_ResolvedFunctionInfo *c15_r0;
  c15_nameCaptureInfo = NULL;
  c15_info_helper(c15_info);
  sf_mex_assign(&c15_m0, sf_mex_createstruct("nameCaptureInfo", 1, 38));
  for (c15_i33 = 0; c15_i33 < 38; c15_i33 = c15_i33 + 1) {
    c15_r0 = &c15_info[c15_i33];
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->context)), "context"
                    , "nameCaptureInfo", c15_i33);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->name)), "name",
                    "nameCaptureInfo", c15_i33);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      c15_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c15_i33);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->resolved)),
                    "resolved", "nameCaptureInfo", c15_i33);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c15_i33);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c15_i33);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c15_i33);
  }

  sf_mex_assign(&c15_nameCaptureInfo, c15_m0);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(c15_ResolvedFunctionInfo c15_info[38])
{
  c15_info[0].context = "";
  c15_info[0].name = "minus";
  c15_info[0].dominantType = "double";
  c15_info[0].resolved = "[B]minus";
  c15_info[0].fileLength = 0U;
  c15_info[0].fileTime1 = 0U;
  c15_info[0].fileTime2 = 0U;
  c15_info[1].context = "";
  c15_info[1].name = "mtimes";
  c15_info[1].dominantType = "double";
  c15_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[1].fileLength = 3425U;
  c15_info[1].fileTime1 = 1250697966U;
  c15_info[1].fileTime2 = 0U;
  c15_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[2].name = "nargin";
  c15_info[2].dominantType = "";
  c15_info[2].resolved = "[B]nargin";
  c15_info[2].fileLength = 0U;
  c15_info[2].fileTime1 = 0U;
  c15_info[2].fileTime2 = 0U;
  c15_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[3].name = "gt";
  c15_info[3].dominantType = "double";
  c15_info[3].resolved = "[B]gt";
  c15_info[3].fileLength = 0U;
  c15_info[3].fileTime1 = 0U;
  c15_info[3].fileTime2 = 0U;
  c15_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[4].name = "isa";
  c15_info[4].dominantType = "double";
  c15_info[4].resolved = "[B]isa";
  c15_info[4].fileLength = 0U;
  c15_info[4].fileTime1 = 0U;
  c15_info[4].fileTime2 = 0U;
  c15_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[5].name = "isinteger";
  c15_info[5].dominantType = "double";
  c15_info[5].resolved = "[B]isinteger";
  c15_info[5].fileLength = 0U;
  c15_info[5].fileTime1 = 0U;
  c15_info[5].fileTime2 = 0U;
  c15_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[6].name = "isscalar";
  c15_info[6].dominantType = "double";
  c15_info[6].resolved = "[B]isscalar";
  c15_info[6].fileLength = 0U;
  c15_info[6].fileTime1 = 0U;
  c15_info[6].fileTime2 = 0U;
  c15_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[7].name = "ndims";
  c15_info[7].dominantType = "double";
  c15_info[7].resolved = "[B]ndims";
  c15_info[7].fileLength = 0U;
  c15_info[7].fileTime1 = 0U;
  c15_info[7].fileTime2 = 0U;
  c15_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[8].name = "le";
  c15_info[8].dominantType = "double";
  c15_info[8].resolved = "[B]le";
  c15_info[8].fileLength = 0U;
  c15_info[8].fileTime1 = 0U;
  c15_info[8].fileTime2 = 0U;
  c15_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[9].name = "size";
  c15_info[9].dominantType = "double";
  c15_info[9].resolved = "[B]size";
  c15_info[9].fileLength = 0U;
  c15_info[9].fileTime1 = 0U;
  c15_info[9].fileTime2 = 0U;
  c15_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[10].name = "eq";
  c15_info[10].dominantType = "double";
  c15_info[10].resolved = "[B]eq";
  c15_info[10].fileLength = 0U;
  c15_info[10].fileTime1 = 0U;
  c15_info[10].fileTime2 = 0U;
  c15_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[11].name = "not";
  c15_info[11].dominantType = "logical";
  c15_info[11].resolved = "[B]not";
  c15_info[11].fileLength = 0U;
  c15_info[11].fileTime1 = 0U;
  c15_info[11].fileTime2 = 0U;
  c15_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[12].name = "strcmp";
  c15_info[12].dominantType = "char";
  c15_info[12].resolved = "[B]strcmp";
  c15_info[12].fileLength = 0U;
  c15_info[12].fileTime1 = 0U;
  c15_info[12].fileTime2 = 0U;
  c15_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[13].name = "class";
  c15_info[13].dominantType = "double";
  c15_info[13].resolved = "[B]class";
  c15_info[13].fileLength = 0U;
  c15_info[13].fileTime1 = 0U;
  c15_info[13].fileTime2 = 0U;
  c15_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[14].name = "isreal";
  c15_info[14].dominantType = "double";
  c15_info[14].resolved = "[B]isreal";
  c15_info[14].fileLength = 0U;
  c15_info[14].fileTime1 = 0U;
  c15_info[14].fileTime2 = 0U;
  c15_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[15].name = "ne";
  c15_info[15].dominantType = "logical";
  c15_info[15].resolved = "[B]ne";
  c15_info[15].fileLength = 0U;
  c15_info[15].fileTime1 = 0U;
  c15_info[15].fileTime2 = 0U;
  c15_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[16].name = "eml_index_class";
  c15_info[16].dominantType = "";
  c15_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c15_info[16].fileLength = 909U;
  c15_info[16].fileTime1 = 1192491982U;
  c15_info[16].fileTime2 = 0U;
  c15_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[17].name = "ones";
  c15_info[17].dominantType = "char";
  c15_info[17].resolved = "[B]ones";
  c15_info[17].fileLength = 0U;
  c15_info[17].fileTime1 = 0U;
  c15_info[17].fileTime2 = 0U;
  c15_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[18].name = "cast";
  c15_info[18].dominantType = "double";
  c15_info[18].resolved = "[B]cast";
  c15_info[18].fileLength = 0U;
  c15_info[18].fileTime1 = 0U;
  c15_info[18].fileTime2 = 0U;
  c15_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[19].name = "eml_scalar_eg";
  c15_info[19].dominantType = "double";
  c15_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c15_info[19].fileLength = 3068U;
  c15_info[19].fileTime1 = 1240287210U;
  c15_info[19].fileTime2 = 0U;
  c15_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c15_info[20].name = "false";
  c15_info[20].dominantType = "";
  c15_info[20].resolved = "[B]false";
  c15_info[20].fileLength = 0U;
  c15_info[20].fileTime1 = 0U;
  c15_info[20].fileTime2 = 0U;
  c15_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c15_info[21].name = "isstruct";
  c15_info[21].dominantType = "double";
  c15_info[21].resolved = "[B]isstruct";
  c15_info[21].fileLength = 0U;
  c15_info[21].fileTime1 = 0U;
  c15_info[21].fileTime2 = 0U;
  c15_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c15_info[22].name = "plus";
  c15_info[22].dominantType = "double";
  c15_info[22].resolved = "[B]plus";
  c15_info[22].fileLength = 0U;
  c15_info[22].fileTime1 = 0U;
  c15_info[22].fileTime2 = 0U;
  c15_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[23].name = "isempty";
  c15_info[23].dominantType = "double";
  c15_info[23].resolved = "[B]isempty";
  c15_info[23].fileLength = 0U;
  c15_info[23].fileTime1 = 0U;
  c15_info[23].fileTime2 = 0U;
  c15_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c15_info[24].name = "eml_xgemm";
  c15_info[24].dominantType = "int32";
  c15_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c15_info[24].fileLength = 3184U;
  c15_info[24].fileTime1 = 1209356052U;
  c15_info[24].fileTime2 = 0U;
  c15_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c15_info[25].name = "lt";
  c15_info[25].dominantType = "int32";
  c15_info[25].resolved = "[B]lt";
  c15_info[25].fileLength = 0U;
  c15_info[25].fileTime1 = 0U;
  c15_info[25].fileTime2 = 0U;
  c15_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c15_info[26].name = "length";
  c15_info[26].dominantType = "double";
  c15_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c15_info[26].fileLength = 326U;
  c15_info[26].fileTime1 = 1226602474U;
  c15_info[26].fileTime2 = 0U;
  c15_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c15_info[27].name = "min";
  c15_info[27].dominantType = "double";
  c15_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c15_info[27].fileLength = 362U;
  c15_info[27].fileTime1 = 1244760752U;
  c15_info[27].fileTime2 = 0U;
  c15_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c15_info[28].name = "nargout";
  c15_info[28].dominantType = "";
  c15_info[28].resolved = "[B]nargout";
  c15_info[28].fileLength = 0U;
  c15_info[28].fileTime1 = 0U;
  c15_info[28].fileTime2 = 0U;
  c15_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c15_info[29].name = "eml_min_or_max";
  c15_info[29].dominantType = "char";
  c15_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c15_info[29].fileLength = 9969U;
  c15_info[29].fileTime1 = 1240287206U;
  c15_info[29].fileTime2 = 0U;
  c15_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c15_info[30].name = "ischar";
  c15_info[30].dominantType = "char";
  c15_info[30].resolved = "[B]ischar";
  c15_info[30].fileLength = 0U;
  c15_info[30].fileTime1 = 0U;
  c15_info[30].fileTime2 = 0U;
  c15_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c15_info[31].name = "isnumeric";
  c15_info[31].dominantType = "double";
  c15_info[31].resolved = "[B]isnumeric";
  c15_info[31].fileLength = 0U;
  c15_info[31].fileTime1 = 0U;
  c15_info[31].fileTime2 = 0U;
  c15_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c15_info[32].name = "islogical";
  c15_info[32].dominantType = "double";
  c15_info[32].resolved = "[B]islogical";
  c15_info[32].fileLength = 0U;
  c15_info[32].fileTime1 = 0U;
  c15_info[32].fileTime2 = 0U;
  c15_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c15_info[33].name = "eml_scalexp_alloc";
  c15_info[33].dominantType = "double";
  c15_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c15_info[33].fileLength = 808U;
  c15_info[33].fileTime1 = 1230519898U;
  c15_info[33].fileTime2 = 0U;
  c15_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c15_info[34].name = "eml_refblas_xgemm";
  c15_info[34].dominantType = "int32";
  c15_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c15_info[34].fileLength = 5748U;
  c15_info[34].fileTime1 = 1228119072U;
  c15_info[34].fileTime2 = 0U;
  c15_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c15_info[35].name = "eml_index_minus";
  c15_info[35].dominantType = "int32";
  c15_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c15_info[35].fileLength = 277U;
  c15_info[35].fileTime1 = 1192491984U;
  c15_info[35].fileTime2 = 0U;
  c15_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c15_info[36].name = "eml_index_times";
  c15_info[36].dominantType = "int32";
  c15_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c15_info[36].fileLength = 280U;
  c15_info[36].fileTime1 = 1192491986U;
  c15_info[36].fileTime2 = 0U;
  c15_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c15_info[37].name = "eml_index_plus";
  c15_info[37].dominantType = "int32";
  c15_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c15_info[37].fileLength = 272U;
  c15_info[37].fileTime1 = 1192491984U;
  c15_info[37].fileTime2 = 0U;
}

static const mxArray *c15_d_sf_marshall(void *chartInstanceVoid, void *c15_u)
{
  const mxArray *c15_y = NULL;
  boolean_T c15_b_u;
  const mxArray *c15_b_y = NULL;
  SFc15_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc15_large_snakeInstanceStruct *)chartInstanceVoid;
  c15_y = NULL;
  c15_b_u = *((boolean_T *)c15_u);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c15_y, c15_b_y);
  return c15_y;
}

static void c15_emlrt_marshallIn(SFc15_large_snakeInstanceStruct *chartInstance,
  const mxArray *c15_q_est, const char_T *c15_name,
  real_T c15_y[9])
{
  real_T c15_dv1[9];
  int32_T c15_i34;
  sf_mex_import(c15_name, sf_mex_dup(c15_q_est), &c15_dv1, 1, 0, 0U, 1, 0U, 1, 9);
  for (c15_i34 = 0; c15_i34 < 9; c15_i34 = c15_i34 + 1) {
    c15_y[c15_i34] = c15_dv1[c15_i34];
  }

  sf_mex_destroy(&c15_q_est);
}

static uint8_T c15_b_emlrt_marshallIn(SFc15_large_snakeInstanceStruct
  *chartInstance, const mxArray *c15_is_active_c15_large_snake,
  const char_T *c15_name)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  sf_mex_import(c15_name, sf_mex_dup(c15_is_active_c15_large_snake), &c15_u0, 1,
                3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_is_active_c15_large_snake);
  return c15_y;
}

static void init_dsm_address_info(SFc15_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c15_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4217106216U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1214395440U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(546664757U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2732778083U);
}

mxArray *sf_c15_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2183361502U);
    pr[1] = (double)(2466196733U);
    pr[2] = (double)(4118108106U);
    pr[3] = (double)(2824540425U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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
      pr[0] = (double)(9);
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
      pr[0] = (double)(9);
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
      pr[0] = (double)(9);
      pr[1] = (double)(9);
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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

static mxArray *sf_get_sim_state_info_c15_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"q_est\",},{M[8],M[0],T\"is_active_c15_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc15_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           15,
           1,
           1,
           5,
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
          init_script_number_translation(_large_snakeMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_large_snakeMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_large_snakeMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 9;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_est",0,(MexFcnForType)c15_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 9;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"pots",0,(MexFcnForType)c15_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 9;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"pot_home",0,(MexFcnForType)
                                c15_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 9;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_home",0,(MexFcnForType)c15_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 9;
            dimVector[1]= 9;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"pot_gains",0,(MexFcnForType)
                                c15_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,112);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c15_q_est)[9];
          real_T (*c15_pots)[9];
          real_T (*c15_pot_home)[9];
          real_T (*c15_q_home)[9];
          real_T (*c15_pot_gains)[81];
          c15_pot_gains = (real_T (*)[81])ssGetInputPortSignal(chartInstance->S,
            3);
          c15_q_home = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
          c15_pot_home = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c15_pots = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          c15_q_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c15_q_est);
          _SFD_SET_DATA_VALUE_PTR(1U, c15_pots);
          _SFD_SET_DATA_VALUE_PTR(2U, c15_pot_home);
          _SFD_SET_DATA_VALUE_PTR(3U, c15_q_home);
          _SFD_SET_DATA_VALUE_PTR(4U, c15_pot_gains);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c15_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_large_snakeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_large_snake((SFc15_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c15_large_snake((SFc15_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c15_large_snake(void *chartInstanceVar)
{
  enable_c15_large_snake((SFc15_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_large_snake(void *chartInstanceVar)
{
  disable_c15_large_snake((SFc15_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c15_large_snake(void *chartInstanceVar)
{
  sf_c15_large_snake((SFc15_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c15_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c15_large_snake((SFc15_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c15_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_large_snake
    ((SFc15_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c15_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c15_large_snake(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_large_snake((SFc15_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c15_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c15_large_snake(S);
}

static void sf_opaque_set_sim_state_c15_large_snake(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c15_large_snake(S, st);
}

static void sf_opaque_terminate_c15_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c15_large_snake((SFc15_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_large_snake((SFc15_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c15_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",15,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",15,4);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",15,1);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2838700514U));
  ssSetChecksum1(S,(2861592823U));
  ssSetChecksum2(S,(3883125893U));
  ssSetChecksum3(S,(3554543106U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c15_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",15);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_large_snake(SimStruct *S)
{
  SFc15_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc15_large_snakeInstanceStruct *)malloc(sizeof
    (SFc15_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c15_large_snake;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c15_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c15_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c15_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c15_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c15_large_snake;
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

void c15_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
