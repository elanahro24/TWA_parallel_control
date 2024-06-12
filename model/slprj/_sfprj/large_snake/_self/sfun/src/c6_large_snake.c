/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c6_large_snake.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c6_debug_family_names[6] = { "orig_pos", "n_in_tb", "nargin",
  "nargout", "u", "sensor" };

static const char *c6_b_debug_family_names[5] = { "nargin", "nargout", "angle",
  "axis", "R" };

/* Function Declarations */
static void initialize_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance);
static void enable_c6_large_snake(SFc6_large_snakeInstanceStruct *chartInstance);
static void disable_c6_large_snake(SFc6_large_snakeInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_large_snake
  (SFc6_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_large_snake
  (SFc6_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance);
static void sf_c6_large_snake(SFc6_large_snakeInstanceStruct *chartInstance);
static void c6_c6_large_snake(SFc6_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static void c6_round(SFc6_large_snakeInstanceStruct *chartInstance, real_T c6_x
                     [6], real_T c6_b_x[6]);
static void c6_RotationMatrix(SFc6_large_snakeInstanceStruct *chartInstance,
  real_T c6_angle, real_T c6_axis[3], real_T c6_R[9]);
static void c6_eml_scalar_eg(SFc6_large_snakeInstanceStruct *chartInstance);
static void c6_b_eml_scalar_eg(SFc6_large_snakeInstanceStruct *chartInstance);
static const mxArray *c6_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_b_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_c_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_d_sf_marshall(void *chartInstanceVoid, void *c6_u);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[52]);
static const mxArray *c6_e_sf_marshall(void *chartInstanceVoid, void *c6_u);
static void c6_emlrt_marshallIn(SFc6_large_snakeInstanceStruct *chartInstance,
  const mxArray *c6_sensor, const char_T *c6_name, real_T c6_y[6]);
static uint8_T c6_b_emlrt_marshallIn(SFc6_large_snakeInstanceStruct
  *chartInstance, const mxArray *c6_is_active_c6_large_snake, const char_T
  *c6_name);
static void init_dsm_address_info(SFc6_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c6_is_active_c6_large_snake;
  c6_is_active_c6_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c6_is_active_c6_large_snake = 0U;
}

static void initialize_params_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c6_large_snake(SFc6_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_large_snake(SFc6_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_large_snake
  (SFc6_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance)
{
  c6_update_debugger_state_c6_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c6_large_snake
  (SFc6_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c6_st = NULL;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_hoistedGlobal[6];
  int32_T c6_i1;
  real_T c6_u[6];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  uint8_T *c6_is_active_c6_large_snake;
  real_T (*c6_sensor)[6];
  c6_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_is_active_c6_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  for (c6_i0 = 0; c6_i0 < 6; c6_i0 = c6_i0 + 1) {
    c6_hoistedGlobal[c6_i0] = (*c6_sensor)[c6_i0];
  }

  for (c6_i1 = 0; c6_i1 < 6; c6_i1 = c6_i1 + 1) {
    c6_u[c6_i1] = c6_hoistedGlobal[c6_i1];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = *c6_is_active_c6_large_snake;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[6];
  int32_T c6_i2;
  boolean_T *c6_doneDoubleBufferReInit;
  uint8_T *c6_is_active_c6_large_snake;
  real_T (*c6_sensor)[6];
  c6_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_is_active_c6_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c6_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                      "sensor", c6_dv0);
  for (c6_i2 = 0; c6_i2 < 6; c6_i2 = c6_i2 + 1) {
    (*c6_sensor)[c6_i2] = c6_dv0[c6_i2];
  }

  *c6_is_active_c6_large_snake = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 1)), "is_active_c6_large_snake");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_large_snake(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_large_snake(SFc6_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c6_large_snake(SFc6_large_snakeInstanceStruct *chartInstance)
{
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_previousEvent;
  real_T (*c6_sensor)[6];
  real_T (*c6_u)[6];
  c6_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,5);
  for (c6_i3 = 0; c6_i3 < 6; c6_i3 = c6_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c6_u)[c6_i3], 0U);
  }

  for (c6_i4 = 0; c6_i4 < 6; c6_i4 = c6_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c6_sensor)[c6_i4], 1U);
  }

  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c6_c6_large_snake(chartInstance);
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_c6_large_snake(SFc6_large_snakeInstanceStruct *chartInstance)
{
  int32_T c6_i5;
  real_T c6_hoistedGlobal[6];
  int32_T c6_i6;
  real_T c6_u[6];
  uint32_T c6_debug_family_var_map[6];
  static const char *c6_sv0[6] = { "orig_pos", "n_in_tb", "nargin", "nargout",
    "u", "sensor" };

  real_T c6_orig_pos[3];
  real_T c6_n_in_tb[3];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_sensor[6];
  int32_T c6_i7;
  real_T c6_a[6];
  int32_T c6_i8;
  real_T c6_y[6];
  int32_T c6_i9;
  real_T c6_b_y[6];
  real_T c6_A[6];
  int32_T c6_i10;
  real_T c6_x[6];
  int32_T c6_i11;
  real_T c6_b_x[6];
  int32_T c6_i12;
  real_T c6_c_x[6];
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  static real_T c6_dv1[3] = { 0.0, 0.0, 1.0 };

  real_T c6_dv2[3];
  real_T c6_b_a[9];
  int32_T c6_i16;
  static real_T c6_dv3[3] = { 0.0, 1.0, 0.0 };

  real_T c6_dv4[3];
  real_T c6_b[9];
  int32_T c6_i17;
  real_T c6_b_A[9];
  int32_T c6_i18;
  real_T c6_B[9];
  int32_T c6_i19;
  real_T c6_c_A[9];
  int32_T c6_i20;
  real_T c6_b_B[9];
  int32_T c6_i21;
  real_T c6_d_A[9];
  int32_T c6_i22;
  real_T c6_c_B[9];
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  real_T c6_c_y[9];
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  real_T c6_c_a[9];
  int32_T c6_i29;
  real_T c6_e_A[9];
  int32_T c6_i30;
  int32_T c6_i31;
  real_T c6_f_A[9];
  int32_T c6_i32;
  real_T c6_g_A[9];
  int32_T c6_i33;
  int32_T c6_i34;
  int32_T c6_i35;
  static real_T c6_dv5[3] = { 1.0, 0.0, 0.0 };

  int32_T c6_i36;
  int32_T c6_i37;
  int32_T c6_i38;
  real_T (*c6_b_sensor)[6];
  real_T (*c6_b_u)[6];
  c6_b_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,5);
  for (c6_i5 = 0; c6_i5 < 6; c6_i5 = c6_i5 + 1) {
    c6_hoistedGlobal[c6_i5] = (*c6_b_u)[c6_i5];
  }

  for (c6_i6 = 0; c6_i6 < 6; c6_i6 = c6_i6 + 1) {
    c6_u[c6_i6] = c6_hoistedGlobal[c6_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c6_sv0, c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_orig_pos, c6_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c6_n_in_tb, c6_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c6_nargin, c6_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c6_nargout, c6_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c6_u, c6_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c6_sensor, c6_sf_marshall, 5U);
  CV_EML_FCN(0, 0);

  /*    Frame definitions: */
  /*    tb: the base frame of trakstar */
  /*    n:  the norm (the X axis of trasmitter) */
  _SFD_EML_CALL(0,6);
  for (c6_i7 = 0; c6_i7 < 6; c6_i7 = c6_i7 + 1) {
    c6_a[c6_i7] = c6_u[c6_i7];
  }

  for (c6_i8 = 0; c6_i8 < 6; c6_i8 = c6_i8 + 1) {
    c6_y[c6_i8] = c6_a[c6_i8] * 100.0;
  }

  for (c6_i9 = 0; c6_i9 < 6; c6_i9 = c6_i9 + 1) {
    c6_b_y[c6_i9] = c6_y[c6_i9];
  }

  c6_round(chartInstance, c6_b_y, c6_A);
  for (c6_i10 = 0; c6_i10 < 6; c6_i10 = c6_i10 + 1) {
    c6_x[c6_i10] = c6_A[c6_i10];
  }

  for (c6_i11 = 0; c6_i11 < 6; c6_i11 = c6_i11 + 1) {
    c6_b_x[c6_i11] = c6_x[c6_i11];
  }

  for (c6_i12 = 0; c6_i12 < 6; c6_i12 = c6_i12 + 1) {
    c6_c_x[c6_i12] = c6_b_x[c6_i12];
  }

  for (c6_i13 = 0; c6_i13 < 6; c6_i13 = c6_i13 + 1) {
    c6_u[c6_i13] = c6_c_x[c6_i13] / 100.0;
  }

  _SFD_EML_CALL(0,7);
  for (c6_i14 = 0; c6_i14 < 3; c6_i14 = c6_i14 + 1) {
    c6_orig_pos[c6_i14] = c6_u[c6_i14];
  }

  _SFD_EML_CALL(0,8);
  for (c6_i15 = 0; c6_i15 < 3; c6_i15 = c6_i15 + 1) {
    c6_dv2[c6_i15] = c6_dv1[c6_i15];
  }

  c6_RotationMatrix(chartInstance, c6_u[3], c6_dv2, c6_b_a);
  for (c6_i16 = 0; c6_i16 < 3; c6_i16 = c6_i16 + 1) {
    c6_dv4[c6_i16] = c6_dv3[c6_i16];
  }

  c6_RotationMatrix(chartInstance, c6_u[4], c6_dv4, c6_b);
  c6_eml_scalar_eg(chartInstance);
  c6_eml_scalar_eg(chartInstance);
  for (c6_i17 = 0; c6_i17 < 9; c6_i17 = c6_i17 + 1) {
    c6_b_A[c6_i17] = c6_b_a[c6_i17];
  }

  for (c6_i18 = 0; c6_i18 < 9; c6_i18 = c6_i18 + 1) {
    c6_B[c6_i18] = c6_b[c6_i18];
  }

  for (c6_i19 = 0; c6_i19 < 9; c6_i19 = c6_i19 + 1) {
    c6_c_A[c6_i19] = c6_b_A[c6_i19];
  }

  for (c6_i20 = 0; c6_i20 < 9; c6_i20 = c6_i20 + 1) {
    c6_b_B[c6_i20] = c6_B[c6_i20];
  }

  for (c6_i21 = 0; c6_i21 < 9; c6_i21 = c6_i21 + 1) {
    c6_d_A[c6_i21] = c6_c_A[c6_i21];
  }

  for (c6_i22 = 0; c6_i22 < 9; c6_i22 = c6_i22 + 1) {
    c6_c_B[c6_i22] = c6_b_B[c6_i22];
  }

  for (c6_i23 = 0; c6_i23 < 3; c6_i23 = c6_i23 + 1) {
    c6_i24 = 0;
    for (c6_i25 = 0; c6_i25 < 3; c6_i25 = c6_i25 + 1) {
      c6_c_y[c6_i24 + c6_i23] = 0.0;
      c6_i26 = 0;
      for (c6_i27 = 0; c6_i27 < 3; c6_i27 = c6_i27 + 1) {
        c6_c_y[c6_i24 + c6_i23] = c6_c_y[c6_i24 + c6_i23] + c6_d_A[c6_i26 +
          c6_i23] * c6_c_B[c6_i27 + c6_i24];
        c6_i26 = c6_i26 + 3;
      }

      c6_i24 = c6_i24 + 3;
    }
  }

  for (c6_i28 = 0; c6_i28 < 9; c6_i28 = c6_i28 + 1) {
    c6_c_a[c6_i28] = c6_c_y[c6_i28];
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i29 = 0; c6_i29 < 9; c6_i29 = c6_i29 + 1) {
    c6_e_A[c6_i29] = c6_c_a[c6_i29];
  }

  for (c6_i30 = 0; c6_i30 < 3; c6_i30 = c6_i30 + 1) {
    c6_n_in_tb[c6_i30] = 0.0;
  }

  for (c6_i31 = 0; c6_i31 < 9; c6_i31 = c6_i31 + 1) {
    c6_f_A[c6_i31] = c6_e_A[c6_i31];
  }

  for (c6_i32 = 0; c6_i32 < 9; c6_i32 = c6_i32 + 1) {
    c6_g_A[c6_i32] = c6_f_A[c6_i32];
  }

  for (c6_i33 = 0; c6_i33 < 3; c6_i33 = c6_i33 + 1) {
    c6_n_in_tb[c6_i33] = 0.0;
    c6_i34 = 0;
    for (c6_i35 = 0; c6_i35 < 3; c6_i35 = c6_i35 + 1) {
      c6_n_in_tb[c6_i33] = c6_n_in_tb[c6_i33] + c6_g_A[c6_i34 + c6_i33] *
        c6_dv5[c6_i35];
      c6_i34 = c6_i34 + 3;
    }
  }

  _SFD_EML_CALL(0,9);
  for (c6_i36 = 0; c6_i36 < 3; c6_i36 = c6_i36 + 1) {
    c6_sensor[c6_i36] = c6_orig_pos[c6_i36];
  }

  for (c6_i37 = 0; c6_i37 < 3; c6_i37 = c6_i37 + 1) {
    c6_sensor[c6_i37 + 3] = c6_n_in_tb[c6_i37];
  }

  _SFD_EML_CALL(0,-9);
  sf_debug_symbol_scope_pop();
  for (c6_i38 = 0; c6_i38 < 6; c6_i38 = c6_i38 + 1) {
    (*c6_b_sensor)[c6_i38] = c6_sensor[c6_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m"));
}

static void c6_round(SFc6_large_snakeInstanceStruct *chartInstance, real_T c6_x
                     [6], real_T c6_b_x[6])
{
  int32_T c6_i39;
  real_T c6_k;
  real_T c6_b_k;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  for (c6_i39 = 0; c6_i39 < 6; c6_i39 = c6_i39 + 1) {
    c6_b_x[c6_i39] = c6_x[c6_i39];
  }

  for (c6_k = 1.0; c6_k <= 6.0; c6_k = c6_k + 1.0) {
    c6_b_k = c6_k;
    c6_c_x = c6_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c6_b_k), 1, 6, 1, 0) - 1];
    c6_d_x = c6_c_x;
    c6_e_x = c6_d_x;
    if (c6_e_x < 0.0) {
      c6_d_x = muDoubleScalarCeil(c6_e_x - 0.5);
    } else {
      c6_d_x = muDoubleScalarFloor(c6_e_x + 0.5);
    }

    c6_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_b_k), 1, 6, 1, 0) - 1] = c6_d_x;
  }
}

static void c6_RotationMatrix(SFc6_large_snakeInstanceStruct *chartInstance,
  real_T c6_angle, real_T c6_axis[3], real_T c6_R[9])
{
  uint32_T c6_debug_family_var_map[5];
  static const char *c6_sv1[5] = { "nargin", "nargout", "angle", "axis", "R" };

  real_T c6_nargin = 2.0;
  real_T c6_nargout = 1.0;
  real_T c6_b;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_k_x;
  real_T c6_l_x;
  int32_T c6_i40;
  int32_T c6_i41;
  static real_T c6_dv6[3] = { 1.0, 0.0, 0.0 };

  real_T c6_m_x;
  real_T c6_n_x;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_s_x;
  real_T c6_t_x;
  real_T c6_u_x;
  real_T c6_v_x;
  real_T c6_w_x;
  real_T c6_x_x;
  int32_T c6_i42;
  int32_T c6_i43;
  static real_T c6_dv7[3] = { 0.0, 1.0, 0.0 };

  real_T c6_y_x;
  real_T c6_ab_x;
  real_T c6_bb_x;
  real_T c6_cb_x;
  real_T c6_db_x;
  real_T c6_eb_x;
  real_T c6_fb_x;
  real_T c6_gb_x;
  real_T c6_hb_x;
  real_T c6_ib_x;
  real_T c6_jb_x;
  real_T c6_kb_x;
  int32_T c6_i44;
  int32_T c6_i45;
  static real_T c6_dv8[3] = { 0.0, 0.0, 1.0 };

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c6_sv1, c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_nargin, c6_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c6_nargout, c6_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c6_angle, c6_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c6_axis, c6_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c6_R, c6_d_sf_marshall, 4U);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0,4);
  c6_b = c6_angle;
  c6_angle = 1.7453292519943295E-002 * c6_b;
  _SFD_SCRIPT_CALL(0,5);
  if (CV_SCRIPT_IF(0, 0, c6_axis[0] == 1.0)) {
    _SFD_SCRIPT_CALL(0,6);
    c6_x = c6_angle;
    c6_b_x = c6_x;
    c6_c_x = c6_b_x;
    c6_b_x = c6_c_x;
    c6_b_x = muDoubleScalarCos(c6_b_x);
    c6_d_x = c6_angle;
    c6_e_x = c6_d_x;
    c6_f_x = c6_e_x;
    c6_e_x = c6_f_x;
    c6_e_x = muDoubleScalarSin(c6_e_x);
    c6_g_x = c6_angle;
    c6_h_x = c6_g_x;
    c6_i_x = c6_h_x;
    c6_h_x = c6_i_x;
    c6_h_x = muDoubleScalarSin(c6_h_x);
    c6_j_x = c6_angle;
    c6_k_x = c6_j_x;
    c6_l_x = c6_k_x;
    c6_k_x = c6_l_x;
    c6_k_x = muDoubleScalarCos(c6_k_x);
    c6_i40 = 0;
    for (c6_i41 = 0; c6_i41 < 3; c6_i41 = c6_i41 + 1) {
      c6_R[c6_i40] = c6_dv6[c6_i41];
      c6_i40 = c6_i40 + 3;
    }

    c6_R[1] = 0.0;
    c6_R[4] = c6_b_x;
    c6_R[7] = -c6_e_x;
    c6_R[2] = 0.0;
    c6_R[5] = c6_h_x;
    c6_R[8] = c6_k_x;
  } else {
    _SFD_SCRIPT_CALL(0,9);
    if (CV_SCRIPT_IF(0, 1, c6_axis[1] == 1.0)) {
      _SFD_SCRIPT_CALL(0,10);
      c6_m_x = c6_angle;
      c6_n_x = c6_m_x;
      c6_o_x = c6_n_x;
      c6_n_x = c6_o_x;
      c6_n_x = muDoubleScalarCos(c6_n_x);
      c6_p_x = c6_angle;
      c6_q_x = c6_p_x;
      c6_r_x = c6_q_x;
      c6_q_x = c6_r_x;
      c6_q_x = muDoubleScalarSin(c6_q_x);
      c6_s_x = c6_angle;
      c6_t_x = c6_s_x;
      c6_u_x = c6_t_x;
      c6_t_x = c6_u_x;
      c6_t_x = muDoubleScalarSin(c6_t_x);
      c6_v_x = c6_angle;
      c6_w_x = c6_v_x;
      c6_x_x = c6_w_x;
      c6_w_x = c6_x_x;
      c6_w_x = muDoubleScalarCos(c6_w_x);
      c6_R[0] = c6_n_x;
      c6_R[3] = 0.0;
      c6_R[6] = c6_q_x;
      c6_i42 = 0;
      for (c6_i43 = 0; c6_i43 < 3; c6_i43 = c6_i43 + 1) {
        c6_R[c6_i42 + 1] = c6_dv7[c6_i43];
        c6_i42 = c6_i42 + 3;
      }

      c6_R[2] = -c6_t_x;
      c6_R[5] = 0.0;
      c6_R[8] = c6_w_x;
    } else {
      _SFD_SCRIPT_CALL(0,14);
      c6_y_x = c6_angle;
      c6_ab_x = c6_y_x;
      c6_bb_x = c6_ab_x;
      c6_ab_x = c6_bb_x;
      c6_ab_x = muDoubleScalarCos(c6_ab_x);
      c6_cb_x = c6_angle;
      c6_db_x = c6_cb_x;
      c6_eb_x = c6_db_x;
      c6_db_x = c6_eb_x;
      c6_db_x = muDoubleScalarSin(c6_db_x);
      c6_fb_x = c6_angle;
      c6_gb_x = c6_fb_x;
      c6_hb_x = c6_gb_x;
      c6_gb_x = c6_hb_x;
      c6_gb_x = muDoubleScalarSin(c6_gb_x);
      c6_ib_x = c6_angle;
      c6_jb_x = c6_ib_x;
      c6_kb_x = c6_jb_x;
      c6_jb_x = c6_kb_x;
      c6_jb_x = muDoubleScalarCos(c6_jb_x);
      c6_R[0] = c6_ab_x;
      c6_R[3] = -c6_db_x;
      c6_R[6] = 0.0;
      c6_R[1] = c6_gb_x;
      c6_R[4] = c6_jb_x;
      c6_R[7] = 0.0;
      c6_i44 = 0;
      for (c6_i45 = 0; c6_i45 < 3; c6_i45 = c6_i45 + 1) {
        c6_R[c6_i44 + 2] = c6_dv8[c6_i45];
        c6_i44 = c6_i44 + 3;
      }
    }
  }

  _SFD_SCRIPT_CALL(0,-14);
  sf_debug_symbol_scope_pop();
}

static void c6_eml_scalar_eg(SFc6_large_snakeInstanceStruct *chartInstance)
{
}

static void c6_b_eml_scalar_eg(SFc6_large_snakeInstanceStruct *chartInstance)
{
}

static const mxArray *c6_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i46;
  real_T c6_b_u[6];
  const mxArray *c6_b_y = NULL;
  SFc6_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc6_large_snakeInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  for (c6_i46 = 0; c6_i46 < 6; c6_i46 = c6_i46 + 1) {
    c6_b_u[c6_i46] = (*((real_T (*)[6])c6_u))[c6_i46];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_b_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  SFc6_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc6_large_snakeInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_b_u = *((real_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_c_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i47;
  real_T c6_b_u[3];
  const mxArray *c6_b_y = NULL;
  SFc6_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc6_large_snakeInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  for (c6_i47 = 0; c6_i47 < 3; c6_i47 = c6_i47 + 1) {
    c6_b_u[c6_i47] = (*((real_T (*)[3])c6_u))[c6_i47];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_d_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i48;
  int32_T c6_i49;
  int32_T c6_i50;
  real_T c6_b_u[9];
  const mxArray *c6_b_y = NULL;
  SFc6_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc6_large_snakeInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_i48 = 0;
  for (c6_i49 = 0; c6_i49 < 3; c6_i49 = c6_i49 + 1) {
    for (c6_i50 = 0; c6_i50 < 3; c6_i50 = c6_i50 + 1) {
      c6_b_u[c6_i50 + c6_i48] = (*((real_T (*)[9])c6_u))[c6_i50 + c6_i48];
    }

    c6_i48 = c6_i48 + 3;
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

const mxArray *sf_c6_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_ResolvedFunctionInfo c6_info[52];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i51;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 52));
  for (c6_i51 = 0; c6_i51 < 52; c6_i51 = c6_i51 + 1) {
    c6_r0 = &c6_info[c6_i51];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context",
                    "nameCaptureInfo", c6_i51);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name",
                    "nameCaptureInfo", c6_i51);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c6_i51);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c6_i51);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c6_i51);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c6_i51
                    );
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c6_i51
                    );
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[52])
{
  c6_info[0].context = "";
  c6_info[0].name = "mtimes";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[0].fileLength = 3425U;
  c6_info[0].fileTime1 = 1250697966U;
  c6_info[0].fileTime2 = 0U;
  c6_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[1].name = "nargin";
  c6_info[1].dominantType = "";
  c6_info[1].resolved = "[B]nargin";
  c6_info[1].fileLength = 0U;
  c6_info[1].fileTime1 = 0U;
  c6_info[1].fileTime2 = 0U;
  c6_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[2].name = "gt";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved = "[B]gt";
  c6_info[2].fileLength = 0U;
  c6_info[2].fileTime1 = 0U;
  c6_info[2].fileTime2 = 0U;
  c6_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[3].name = "isa";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved = "[B]isa";
  c6_info[3].fileLength = 0U;
  c6_info[3].fileTime1 = 0U;
  c6_info[3].fileTime2 = 0U;
  c6_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[4].name = "isinteger";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved = "[B]isinteger";
  c6_info[4].fileLength = 0U;
  c6_info[4].fileTime1 = 0U;
  c6_info[4].fileTime2 = 0U;
  c6_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[5].name = "isscalar";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[B]isscalar";
  c6_info[5].fileLength = 0U;
  c6_info[5].fileTime1 = 0U;
  c6_info[5].fileTime2 = 0U;
  c6_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[6].name = "strcmp";
  c6_info[6].dominantType = "char";
  c6_info[6].resolved = "[B]strcmp";
  c6_info[6].fileLength = 0U;
  c6_info[6].fileTime1 = 0U;
  c6_info[6].fileTime2 = 0U;
  c6_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[7].name = "size";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved = "[B]size";
  c6_info[7].fileLength = 0U;
  c6_info[7].fileTime1 = 0U;
  c6_info[7].fileTime2 = 0U;
  c6_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[8].name = "eq";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved = "[B]eq";
  c6_info[8].fileLength = 0U;
  c6_info[8].fileTime1 = 0U;
  c6_info[8].fileTime2 = 0U;
  c6_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[9].name = "class";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved = "[B]class";
  c6_info[9].fileLength = 0U;
  c6_info[9].fileTime1 = 0U;
  c6_info[9].fileTime2 = 0U;
  c6_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[10].name = "not";
  c6_info[10].dominantType = "logical";
  c6_info[10].resolved = "[B]not";
  c6_info[10].fileLength = 0U;
  c6_info[10].fileTime1 = 0U;
  c6_info[10].fileTime2 = 0U;
  c6_info[11].context = "";
  c6_info[11].name = "round";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c6_info[11].fileLength = 331U;
  c6_info[11].fileTime1 = 1203473236U;
  c6_info[11].fileTime2 = 0U;
  c6_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c6_info[12].name = "eml_scalar_round";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c6_info[12].fileLength = 523U;
  c6_info[12].fileTime1 = 1203473208U;
  c6_info[12].fileTime2 = 0U;
  c6_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c6_info[13].name = "isfloat";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved = "[B]isfloat";
  c6_info[13].fileLength = 0U;
  c6_info[13].fileTime1 = 0U;
  c6_info[13].fileTime2 = 0U;
  c6_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c6_info[14].name = "isreal";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved = "[B]isreal";
  c6_info[14].fileLength = 0U;
  c6_info[14].fileTime1 = 0U;
  c6_info[14].fileTime2 = 0U;
  c6_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c6_info[15].name = "lt";
  c6_info[15].dominantType = "double";
  c6_info[15].resolved = "[B]lt";
  c6_info[15].fileLength = 0U;
  c6_info[15].fileTime1 = 0U;
  c6_info[15].fileTime2 = 0U;
  c6_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c6_info[16].name = "minus";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved = "[B]minus";
  c6_info[16].fileLength = 0U;
  c6_info[16].fileTime1 = 0U;
  c6_info[16].fileTime2 = 0U;
  c6_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c6_info[17].name = "plus";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved = "[B]plus";
  c6_info[17].fileLength = 0U;
  c6_info[17].fileTime1 = 0U;
  c6_info[17].fileTime2 = 0U;
  c6_info[18].context = "";
  c6_info[18].name = "mrdivide";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[18].fileLength = 800U;
  c6_info[18].fileTime1 = 1238459490U;
  c6_info[18].fileTime2 = 0U;
  c6_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[19].name = "ge";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved = "[B]ge";
  c6_info[19].fileLength = 0U;
  c6_info[19].fileTime1 = 0U;
  c6_info[19].fileTime2 = 0U;
  c6_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[20].name = "rdivide";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[20].fileLength = 403U;
  c6_info[20].fileTime1 = 1244760752U;
  c6_info[20].fileTime2 = 0U;
  c6_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[21].name = "eml_div";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[21].fileLength = 4269U;
  c6_info[21].fileTime1 = 1228119026U;
  c6_info[21].fileTime2 = 0U;
  c6_info[22].context = "";
  c6_info[22].name = "RotationMatrix";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c6_info[22].fileLength = 433U;
  c6_info[22].fileTime1 = 1468274189U;
  c6_info[22].fileTime2 = 0U;
  c6_info[23].context = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c6_info[23].name = "pi";
  c6_info[23].dominantType = "";
  c6_info[23].resolved = "[B]pi";
  c6_info[23].fileLength = 0U;
  c6_info[23].fileTime1 = 0U;
  c6_info[23].fileTime2 = 0U;
  c6_info[24].context = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c6_info[24].name = "cos";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[24].fileLength = 324U;
  c6_info[24].fileTime1 = 1203473150U;
  c6_info[24].fileTime2 = 0U;
  c6_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[25].name = "eml_scalar_cos";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[25].fileLength = 602U;
  c6_info[25].fileTime1 = 1209355986U;
  c6_info[25].fileTime2 = 0U;
  c6_info[26].context = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c6_info[26].name = "sin";
  c6_info[26].dominantType = "double";
  c6_info[26].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[26].fileLength = 324U;
  c6_info[26].fileTime1 = 1203473242U;
  c6_info[26].fileTime2 = 0U;
  c6_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[27].name = "eml_scalar_sin";
  c6_info[27].dominantType = "double";
  c6_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c6_info[27].fileLength = 601U;
  c6_info[27].fileTime1 = 1209355990U;
  c6_info[27].fileTime2 = 0U;
  c6_info[28].context = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c6_info[28].name = "uminus";
  c6_info[28].dominantType = "double";
  c6_info[28].resolved = "[B]uminus";
  c6_info[28].fileLength = 0U;
  c6_info[28].fileTime1 = 0U;
  c6_info[28].fileTime2 = 0U;
  c6_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[29].name = "ndims";
  c6_info[29].dominantType = "double";
  c6_info[29].resolved = "[B]ndims";
  c6_info[29].fileLength = 0U;
  c6_info[29].fileTime1 = 0U;
  c6_info[29].fileTime2 = 0U;
  c6_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[30].name = "le";
  c6_info[30].dominantType = "double";
  c6_info[30].resolved = "[B]le";
  c6_info[30].fileLength = 0U;
  c6_info[30].fileTime1 = 0U;
  c6_info[30].fileTime2 = 0U;
  c6_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[31].name = "ne";
  c6_info[31].dominantType = "logical";
  c6_info[31].resolved = "[B]ne";
  c6_info[31].fileLength = 0U;
  c6_info[31].fileTime1 = 0U;
  c6_info[31].fileTime2 = 0U;
  c6_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[32].name = "eml_index_class";
  c6_info[32].dominantType = "";
  c6_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[32].fileLength = 909U;
  c6_info[32].fileTime1 = 1192491982U;
  c6_info[32].fileTime2 = 0U;
  c6_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[33].name = "ones";
  c6_info[33].dominantType = "char";
  c6_info[33].resolved = "[B]ones";
  c6_info[33].fileLength = 0U;
  c6_info[33].fileTime1 = 0U;
  c6_info[33].fileTime2 = 0U;
  c6_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[34].name = "cast";
  c6_info[34].dominantType = "double";
  c6_info[34].resolved = "[B]cast";
  c6_info[34].fileLength = 0U;
  c6_info[34].fileTime1 = 0U;
  c6_info[34].fileTime2 = 0U;
  c6_info[35].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[35].name = "eml_scalar_eg";
  c6_info[35].dominantType = "double";
  c6_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[35].fileLength = 3068U;
  c6_info[35].fileTime1 = 1240287210U;
  c6_info[35].fileTime2 = 0U;
  c6_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c6_info[36].name = "false";
  c6_info[36].dominantType = "";
  c6_info[36].resolved = "[B]false";
  c6_info[36].fileLength = 0U;
  c6_info[36].fileTime1 = 0U;
  c6_info[36].fileTime2 = 0U;
  c6_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[37].name = "isstruct";
  c6_info[37].dominantType = "double";
  c6_info[37].resolved = "[B]isstruct";
  c6_info[37].fileLength = 0U;
  c6_info[37].fileTime1 = 0U;
  c6_info[37].fileTime2 = 0U;
  c6_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[38].name = "isempty";
  c6_info[38].dominantType = "double";
  c6_info[38].resolved = "[B]isempty";
  c6_info[38].fileLength = 0U;
  c6_info[38].fileTime1 = 0U;
  c6_info[38].fileTime2 = 0U;
  c6_info[39].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[39].name = "eml_xgemm";
  c6_info[39].dominantType = "int32";
  c6_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[39].fileLength = 3184U;
  c6_info[39].fileTime1 = 1209356052U;
  c6_info[39].fileTime2 = 0U;
  c6_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c6_info[40].name = "length";
  c6_info[40].dominantType = "double";
  c6_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[40].fileLength = 326U;
  c6_info[40].fileTime1 = 1226602474U;
  c6_info[40].fileTime2 = 0U;
  c6_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c6_info[41].name = "min";
  c6_info[41].dominantType = "double";
  c6_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[41].fileLength = 362U;
  c6_info[41].fileTime1 = 1244760752U;
  c6_info[41].fileTime2 = 0U;
  c6_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[42].name = "nargout";
  c6_info[42].dominantType = "";
  c6_info[42].resolved = "[B]nargout";
  c6_info[42].fileLength = 0U;
  c6_info[42].fileTime1 = 0U;
  c6_info[42].fileTime2 = 0U;
  c6_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[43].name = "eml_min_or_max";
  c6_info[43].dominantType = "char";
  c6_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[43].fileLength = 9969U;
  c6_info[43].fileTime1 = 1240287206U;
  c6_info[43].fileTime2 = 0U;
  c6_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[44].name = "ischar";
  c6_info[44].dominantType = "char";
  c6_info[44].resolved = "[B]ischar";
  c6_info[44].fileLength = 0U;
  c6_info[44].fileTime1 = 0U;
  c6_info[44].fileTime2 = 0U;
  c6_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[45].name = "isnumeric";
  c6_info[45].dominantType = "double";
  c6_info[45].resolved = "[B]isnumeric";
  c6_info[45].fileLength = 0U;
  c6_info[45].fileTime1 = 0U;
  c6_info[45].fileTime2 = 0U;
  c6_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c6_info[46].name = "islogical";
  c6_info[46].dominantType = "double";
  c6_info[46].resolved = "[B]islogical";
  c6_info[46].fileLength = 0U;
  c6_info[46].fileTime1 = 0U;
  c6_info[46].fileTime2 = 0U;
  c6_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c6_info[47].name = "eml_scalexp_alloc";
  c6_info[47].dominantType = "double";
  c6_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[47].fileLength = 808U;
  c6_info[47].fileTime1 = 1230519898U;
  c6_info[47].fileTime2 = 0U;
  c6_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[48].name = "eml_refblas_xgemm";
  c6_info[48].dominantType = "int32";
  c6_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[48].fileLength = 5748U;
  c6_info[48].fileTime1 = 1228119072U;
  c6_info[48].fileTime2 = 0U;
  c6_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[49].name = "eml_index_minus";
  c6_info[49].dominantType = "int32";
  c6_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[49].fileLength = 277U;
  c6_info[49].fileTime1 = 1192491984U;
  c6_info[49].fileTime2 = 0U;
  c6_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[50].name = "eml_index_times";
  c6_info[50].dominantType = "int32";
  c6_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[50].fileLength = 280U;
  c6_info[50].fileTime1 = 1192491986U;
  c6_info[50].fileTime2 = 0U;
  c6_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[51].name = "eml_index_plus";
  c6_info[51].dominantType = "int32";
  c6_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[51].fileLength = 272U;
  c6_info[51].fileTime1 = 1192491984U;
  c6_info[51].fileTime2 = 0U;
}

static const mxArray *c6_e_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  boolean_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  SFc6_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc6_large_snakeInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_b_u = *((boolean_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static void c6_emlrt_marshallIn(SFc6_large_snakeInstanceStruct *chartInstance,
  const mxArray *c6_sensor, const char_T *c6_name,
  real_T c6_y[6])
{
  real_T c6_dv9[6];
  int32_T c6_i52;
  sf_mex_import(c6_name, sf_mex_dup(c6_sensor), &c6_dv9, 1, 0, 0U, 1, 0U, 1, 6);
  for (c6_i52 = 0; c6_i52 < 6; c6_i52 = c6_i52 + 1) {
    c6_y[c6_i52] = c6_dv9[c6_i52];
  }

  sf_mex_destroy(&c6_sensor);
}

static uint8_T c6_b_emlrt_marshallIn(SFc6_large_snakeInstanceStruct
  *chartInstance, const mxArray *c6_is_active_c6_large_snake,
  const char_T *c6_name)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_name, sf_mex_dup(c6_is_active_c6_large_snake), &c6_u0, 1, 3,
                0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_is_active_c6_large_snake);
  return c6_y;
}

static void init_dsm_address_info(SFc6_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2298000191U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1975510851U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3391658010U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(782053085U);
}

mxArray *sf_c6_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4256605512U);
    pr[1] = (double)(4073782623U);
    pr[2] = (double)(609263258U);
    pr[3] = (double)(3054467638U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c6_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[11],T\"sensor\",},{M[8],M[0],T\"is_active_c6_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc6_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           6,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           1,
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
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"u",0,(MexFcnForType)c6_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"sensor",0,(MexFcnForType)c6_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,294);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"RotationMatrix",6,-1,433);
        _SFD_CV_INIT_SCRIPT_IF(0,0,79,94,195,424);
        _SFD_CV_INIT_SCRIPT_IF(0,1,195,214,315,424);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c6_u)[6];
          real_T (*c6_sensor)[6];
          c6_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_sensor);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_large_snakeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c6_large_snake((SFc6_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c6_large_snake((SFc6_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_large_snake(void *chartInstanceVar)
{
  enable_c6_large_snake((SFc6_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_large_snake(void *chartInstanceVar)
{
  disable_c6_large_snake((SFc6_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_large_snake(void *chartInstanceVar)
{
  sf_c6_large_snake((SFc6_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c6_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c6_large_snake((SFc6_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c6_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_large_snake
    ((SFc6_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c6_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c6_large_snake(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_large_snake((SFc6_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c6_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_large_snake(S);
}

static void sf_opaque_set_sim_state_c6_large_snake(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c6_large_snake(S, st);
}

static void sf_opaque_terminate_c6_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_large_snake((SFc6_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_large_snake((SFc6_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c6_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",6,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",6,1);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",6,1);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2295182288U));
  ssSetChecksum1(S,(1316392496U));
  ssSetChecksum2(S,(183595624U));
  ssSetChecksum3(S,(3047754736U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_large_snake(SimStruct *S)
{
  SFc6_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc6_large_snakeInstanceStruct *)malloc(sizeof
    (SFc6_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_large_snake;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c6_large_snake;
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

void c6_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
