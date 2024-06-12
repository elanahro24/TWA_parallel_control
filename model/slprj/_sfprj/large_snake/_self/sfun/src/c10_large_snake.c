/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c10_large_snake.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c10_debug_family_names[6] = { "orig_pos", "n_in_tb", "nargin",
  "nargout", "u", "sensor" };

static const char *c10_b_debug_family_names[5] = { "nargin", "nargout", "angle",
  "axis", "R" };

/* Function Declarations */
static void initialize_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance);
static void enable_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance);
static void disable_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance);
static void c10_update_debugger_state_c10_large_snake
  (SFc10_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c10_large_snake
  (SFc10_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance, const mxArray *c10_st);
static void finalize_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance);
static void sf_c10_large_snake(SFc10_large_snakeInstanceStruct *chartInstance);
static void c10_c10_large_snake(SFc10_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static void c10_round(SFc10_large_snakeInstanceStruct *chartInstance, real_T
                      c10_x[6], real_T c10_b_x[6]);
static void c10_RotationMatrix(SFc10_large_snakeInstanceStruct *chartInstance,
  real_T c10_angle, real_T c10_axis[3], real_T c10_R[9]);
static void c10_eml_scalar_eg(SFc10_large_snakeInstanceStruct *chartInstance);
static void c10_b_eml_scalar_eg(SFc10_large_snakeInstanceStruct *chartInstance);
static const mxArray *c10_sf_marshall(void *chartInstanceVoid, void *c10_u);
static const mxArray *c10_b_sf_marshall(void *chartInstanceVoid, void *c10_u);
static const mxArray *c10_c_sf_marshall(void *chartInstanceVoid, void *c10_u);
static const mxArray *c10_d_sf_marshall(void *chartInstanceVoid, void *c10_u);
static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[52]);
static const mxArray *c10_e_sf_marshall(void *chartInstanceVoid, void *c10_u);
static void c10_emlrt_marshallIn(SFc10_large_snakeInstanceStruct *chartInstance,
  const mxArray *c10_sensor, const char_T *c10_name, real_T c10_y[6]);
static uint8_T c10_b_emlrt_marshallIn(SFc10_large_snakeInstanceStruct
  *chartInstance, const mxArray *c10_is_active_c10_large_snake, const char_T
  *c10_name);
static void init_dsm_address_info(SFc10_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c10_is_active_c10_large_snake;
  c10_is_active_c10_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c10_is_active_c10_large_snake = 0U;
}

static void initialize_params_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_large_snake
  (SFc10_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance)
{
  c10_update_debugger_state_c10_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c10_large_snake
  (SFc10_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c10_st = NULL;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  real_T c10_hoistedGlobal[6];
  int32_T c10_i1;
  real_T c10_u[6];
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_hoistedGlobal;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  uint8_T *c10_is_active_c10_large_snake;
  real_T (*c10_sensor)[6];
  c10_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_is_active_c10_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(2));
  for (c10_i0 = 0; c10_i0 < 6; c10_i0 = c10_i0 + 1) {
    c10_hoistedGlobal[c10_i0] = (*c10_sensor)[c10_i0];
  }

  for (c10_i1 = 0; c10_i1 < 6; c10_i1 = c10_i1 + 1) {
    c10_u[c10_i1] = c10_hoistedGlobal[c10_i1];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = *c10_is_active_c10_large_snake;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y);
  return c10_st;
}

static void set_sim_state_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv0[6];
  int32_T c10_i2;
  boolean_T *c10_doneDoubleBufferReInit;
  uint8_T *c10_is_active_c10_large_snake;
  real_T (*c10_sensor)[6];
  c10_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_is_active_c10_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c10_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
                       "sensor", c10_dv0);
  for (c10_i2 = 0; c10_i2 < 6; c10_i2 = c10_i2 + 1) {
    (*c10_sensor)[c10_i2] = c10_dv0[c10_i2];
  }

  *c10_is_active_c10_large_snake = c10_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "is_active_c10_large_snake");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_large_snake(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_large_snake(SFc10_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c10_large_snake(SFc10_large_snakeInstanceStruct *chartInstance)
{
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_previousEvent;
  real_T (*c10_sensor)[6];
  real_T (*c10_u)[6];
  c10_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,9);
  for (c10_i3 = 0; c10_i3 < 6; c10_i3 = c10_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_u)[c10_i3], 0U);
  }

  for (c10_i4 = 0; c10_i4 < 6; c10_i4 = c10_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_sensor)[c10_i4], 1U);
  }

  c10_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c10_c10_large_snake(chartInstance);
  _sfEvent_ = c10_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c10_c10_large_snake(SFc10_large_snakeInstanceStruct *chartInstance)
{
  int32_T c10_i5;
  real_T c10_hoistedGlobal[6];
  int32_T c10_i6;
  real_T c10_u[6];
  uint32_T c10_debug_family_var_map[6];
  static const char *c10_sv0[6] = { "orig_pos", "n_in_tb", "nargin", "nargout",
    "u", "sensor" };

  real_T c10_orig_pos[3];
  real_T c10_n_in_tb[3];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  real_T c10_sensor[6];
  int32_T c10_i7;
  real_T c10_a[6];
  int32_T c10_i8;
  real_T c10_y[6];
  int32_T c10_i9;
  real_T c10_b_y[6];
  real_T c10_A[6];
  int32_T c10_i10;
  real_T c10_x[6];
  int32_T c10_i11;
  real_T c10_b_x[6];
  int32_T c10_i12;
  real_T c10_c_x[6];
  int32_T c10_i13;
  int32_T c10_i14;
  int32_T c10_i15;
  static real_T c10_dv1[3] = { 0.0, 0.0, 1.0 };

  real_T c10_dv2[3];
  real_T c10_b_a[9];
  int32_T c10_i16;
  static real_T c10_dv3[3] = { 0.0, 1.0, 0.0 };

  real_T c10_dv4[3];
  real_T c10_b[9];
  int32_T c10_i17;
  real_T c10_b_A[9];
  int32_T c10_i18;
  real_T c10_B[9];
  int32_T c10_i19;
  real_T c10_c_A[9];
  int32_T c10_i20;
  real_T c10_b_B[9];
  int32_T c10_i21;
  real_T c10_d_A[9];
  int32_T c10_i22;
  real_T c10_c_B[9];
  int32_T c10_i23;
  int32_T c10_i24;
  int32_T c10_i25;
  real_T c10_c_y[9];
  int32_T c10_i26;
  int32_T c10_i27;
  int32_T c10_i28;
  real_T c10_c_a[9];
  int32_T c10_i29;
  real_T c10_e_A[9];
  int32_T c10_i30;
  int32_T c10_i31;
  real_T c10_f_A[9];
  int32_T c10_i32;
  real_T c10_g_A[9];
  int32_T c10_i33;
  int32_T c10_i34;
  int32_T c10_i35;
  static real_T c10_dv5[3] = { 1.0, 0.0, 0.0 };

  int32_T c10_i36;
  int32_T c10_i37;
  int32_T c10_i38;
  real_T (*c10_b_sensor)[6];
  real_T (*c10_b_u)[6];
  c10_b_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,9);
  for (c10_i5 = 0; c10_i5 < 6; c10_i5 = c10_i5 + 1) {
    c10_hoistedGlobal[c10_i5] = (*c10_b_u)[c10_i5];
  }

  for (c10_i6 = 0; c10_i6 < 6; c10_i6 = c10_i6 + 1) {
    c10_u[c10_i6] = c10_hoistedGlobal[c10_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c10_sv0, c10_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c10_orig_pos, c10_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c10_n_in_tb, c10_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c10_nargin, c10_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c10_nargout, c10_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c10_u, c10_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c10_sensor, c10_sf_marshall, 5U);
  CV_EML_FCN(0, 0);

  /*    Frame definitions: */
  /*    tb: the base frame of trakstar */
  /*    n:  the norm (the X axis of trasmitter) */
  _SFD_EML_CALL(0,6);
  for (c10_i7 = 0; c10_i7 < 6; c10_i7 = c10_i7 + 1) {
    c10_a[c10_i7] = c10_u[c10_i7];
  }

  for (c10_i8 = 0; c10_i8 < 6; c10_i8 = c10_i8 + 1) {
    c10_y[c10_i8] = c10_a[c10_i8] * 100.0;
  }

  for (c10_i9 = 0; c10_i9 < 6; c10_i9 = c10_i9 + 1) {
    c10_b_y[c10_i9] = c10_y[c10_i9];
  }

  c10_round(chartInstance, c10_b_y, c10_A);
  for (c10_i10 = 0; c10_i10 < 6; c10_i10 = c10_i10 + 1) {
    c10_x[c10_i10] = c10_A[c10_i10];
  }

  for (c10_i11 = 0; c10_i11 < 6; c10_i11 = c10_i11 + 1) {
    c10_b_x[c10_i11] = c10_x[c10_i11];
  }

  for (c10_i12 = 0; c10_i12 < 6; c10_i12 = c10_i12 + 1) {
    c10_c_x[c10_i12] = c10_b_x[c10_i12];
  }

  for (c10_i13 = 0; c10_i13 < 6; c10_i13 = c10_i13 + 1) {
    c10_u[c10_i13] = c10_c_x[c10_i13] / 100.0;
  }

  _SFD_EML_CALL(0,7);
  for (c10_i14 = 0; c10_i14 < 3; c10_i14 = c10_i14 + 1) {
    c10_orig_pos[c10_i14] = c10_u[c10_i14];
  }

  _SFD_EML_CALL(0,8);
  for (c10_i15 = 0; c10_i15 < 3; c10_i15 = c10_i15 + 1) {
    c10_dv2[c10_i15] = c10_dv1[c10_i15];
  }

  c10_RotationMatrix(chartInstance, c10_u[3], c10_dv2, c10_b_a);
  for (c10_i16 = 0; c10_i16 < 3; c10_i16 = c10_i16 + 1) {
    c10_dv4[c10_i16] = c10_dv3[c10_i16];
  }

  c10_RotationMatrix(chartInstance, c10_u[4], c10_dv4, c10_b);
  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i17 = 0; c10_i17 < 9; c10_i17 = c10_i17 + 1) {
    c10_b_A[c10_i17] = c10_b_a[c10_i17];
  }

  for (c10_i18 = 0; c10_i18 < 9; c10_i18 = c10_i18 + 1) {
    c10_B[c10_i18] = c10_b[c10_i18];
  }

  for (c10_i19 = 0; c10_i19 < 9; c10_i19 = c10_i19 + 1) {
    c10_c_A[c10_i19] = c10_b_A[c10_i19];
  }

  for (c10_i20 = 0; c10_i20 < 9; c10_i20 = c10_i20 + 1) {
    c10_b_B[c10_i20] = c10_B[c10_i20];
  }

  for (c10_i21 = 0; c10_i21 < 9; c10_i21 = c10_i21 + 1) {
    c10_d_A[c10_i21] = c10_c_A[c10_i21];
  }

  for (c10_i22 = 0; c10_i22 < 9; c10_i22 = c10_i22 + 1) {
    c10_c_B[c10_i22] = c10_b_B[c10_i22];
  }

  for (c10_i23 = 0; c10_i23 < 3; c10_i23 = c10_i23 + 1) {
    c10_i24 = 0;
    for (c10_i25 = 0; c10_i25 < 3; c10_i25 = c10_i25 + 1) {
      c10_c_y[c10_i24 + c10_i23] = 0.0;
      c10_i26 = 0;
      for (c10_i27 = 0; c10_i27 < 3; c10_i27 = c10_i27 + 1) {
        c10_c_y[c10_i24 + c10_i23] = c10_c_y[c10_i24 + c10_i23] +
          c10_d_A[c10_i26 + c10_i23] * c10_c_B[c10_i27 + c10_i24];
        c10_i26 = c10_i26 + 3;
      }

      c10_i24 = c10_i24 + 3;
    }
  }

  for (c10_i28 = 0; c10_i28 < 9; c10_i28 = c10_i28 + 1) {
    c10_c_a[c10_i28] = c10_c_y[c10_i28];
  }

  c10_b_eml_scalar_eg(chartInstance);
  c10_b_eml_scalar_eg(chartInstance);
  for (c10_i29 = 0; c10_i29 < 9; c10_i29 = c10_i29 + 1) {
    c10_e_A[c10_i29] = c10_c_a[c10_i29];
  }

  for (c10_i30 = 0; c10_i30 < 3; c10_i30 = c10_i30 + 1) {
    c10_n_in_tb[c10_i30] = 0.0;
  }

  for (c10_i31 = 0; c10_i31 < 9; c10_i31 = c10_i31 + 1) {
    c10_f_A[c10_i31] = c10_e_A[c10_i31];
  }

  for (c10_i32 = 0; c10_i32 < 9; c10_i32 = c10_i32 + 1) {
    c10_g_A[c10_i32] = c10_f_A[c10_i32];
  }

  for (c10_i33 = 0; c10_i33 < 3; c10_i33 = c10_i33 + 1) {
    c10_n_in_tb[c10_i33] = 0.0;
    c10_i34 = 0;
    for (c10_i35 = 0; c10_i35 < 3; c10_i35 = c10_i35 + 1) {
      c10_n_in_tb[c10_i33] = c10_n_in_tb[c10_i33] + c10_g_A[c10_i34 + c10_i33] *
        c10_dv5[c10_i35];
      c10_i34 = c10_i34 + 3;
    }
  }

  _SFD_EML_CALL(0,9);
  for (c10_i36 = 0; c10_i36 < 3; c10_i36 = c10_i36 + 1) {
    c10_sensor[c10_i36] = c10_orig_pos[c10_i36];
  }

  for (c10_i37 = 0; c10_i37 < 3; c10_i37 = c10_i37 + 1) {
    c10_sensor[c10_i37 + 3] = c10_n_in_tb[c10_i37];
  }

  _SFD_EML_CALL(0,-9);
  sf_debug_symbol_scope_pop();
  for (c10_i38 = 0; c10_i38 < 6; c10_i38 = c10_i38 + 1) {
    (*c10_b_sensor)[c10_i38] = c10_sensor[c10_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c10_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m"));
}

static void c10_round(SFc10_large_snakeInstanceStruct *chartInstance, real_T
                      c10_x[6], real_T c10_b_x[6])
{
  int32_T c10_i39;
  real_T c10_k;
  real_T c10_b_k;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_e_x;
  for (c10_i39 = 0; c10_i39 < 6; c10_i39 = c10_i39 + 1) {
    c10_b_x[c10_i39] = c10_x[c10_i39];
  }

  for (c10_k = 1.0; c10_k <= 6.0; c10_k = c10_k + 1.0) {
    c10_b_k = c10_k;
    c10_c_x = c10_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_k), 1, 6, 1, 0) - 1];
    c10_d_x = c10_c_x;
    c10_e_x = c10_d_x;
    if (c10_e_x < 0.0) {
      c10_d_x = muDoubleScalarCeil(c10_e_x - 0.5);
    } else {
      c10_d_x = muDoubleScalarFloor(c10_e_x + 0.5);
    }

    c10_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c10_b_k), 1, 6, 1, 0) - 1] = c10_d_x;
  }
}

static void c10_RotationMatrix(SFc10_large_snakeInstanceStruct *chartInstance,
  real_T c10_angle, real_T c10_axis[3], real_T c10_R[9]
  )
{
  uint32_T c10_debug_family_var_map[5];
  static const char *c10_sv1[5] = { "nargin", "nargout", "angle", "axis", "R" };

  real_T c10_nargin = 2.0;
  real_T c10_nargout = 1.0;
  real_T c10_b;
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_e_x;
  real_T c10_f_x;
  real_T c10_g_x;
  real_T c10_h_x;
  real_T c10_i_x;
  real_T c10_j_x;
  real_T c10_k_x;
  real_T c10_l_x;
  int32_T c10_i40;
  int32_T c10_i41;
  static real_T c10_dv6[3] = { 1.0, 0.0, 0.0 };

  real_T c10_m_x;
  real_T c10_n_x;
  real_T c10_o_x;
  real_T c10_p_x;
  real_T c10_q_x;
  real_T c10_r_x;
  real_T c10_s_x;
  real_T c10_t_x;
  real_T c10_u_x;
  real_T c10_v_x;
  real_T c10_w_x;
  real_T c10_x_x;
  int32_T c10_i42;
  int32_T c10_i43;
  static real_T c10_dv7[3] = { 0.0, 1.0, 0.0 };

  real_T c10_y_x;
  real_T c10_ab_x;
  real_T c10_bb_x;
  real_T c10_cb_x;
  real_T c10_db_x;
  real_T c10_eb_x;
  real_T c10_fb_x;
  real_T c10_gb_x;
  real_T c10_hb_x;
  real_T c10_ib_x;
  real_T c10_jb_x;
  real_T c10_kb_x;
  int32_T c10_i44;
  int32_T c10_i45;
  static real_T c10_dv8[3] = { 0.0, 0.0, 1.0 };

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c10_sv1, c10_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c10_nargin, c10_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c10_nargout, c10_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c10_angle, c10_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c10_axis, c10_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c10_R, c10_d_sf_marshall, 4U);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0,4);
  c10_b = c10_angle;
  c10_angle = 1.7453292519943295E-002 * c10_b;
  _SFD_SCRIPT_CALL(0,5);
  if (CV_SCRIPT_IF(0, 0, c10_axis[0] == 1.0)) {
    _SFD_SCRIPT_CALL(0,6);
    c10_x = c10_angle;
    c10_b_x = c10_x;
    c10_c_x = c10_b_x;
    c10_b_x = c10_c_x;
    c10_b_x = muDoubleScalarCos(c10_b_x);
    c10_d_x = c10_angle;
    c10_e_x = c10_d_x;
    c10_f_x = c10_e_x;
    c10_e_x = c10_f_x;
    c10_e_x = muDoubleScalarSin(c10_e_x);
    c10_g_x = c10_angle;
    c10_h_x = c10_g_x;
    c10_i_x = c10_h_x;
    c10_h_x = c10_i_x;
    c10_h_x = muDoubleScalarSin(c10_h_x);
    c10_j_x = c10_angle;
    c10_k_x = c10_j_x;
    c10_l_x = c10_k_x;
    c10_k_x = c10_l_x;
    c10_k_x = muDoubleScalarCos(c10_k_x);
    c10_i40 = 0;
    for (c10_i41 = 0; c10_i41 < 3; c10_i41 = c10_i41 + 1) {
      c10_R[c10_i40] = c10_dv6[c10_i41];
      c10_i40 = c10_i40 + 3;
    }

    c10_R[1] = 0.0;
    c10_R[4] = c10_b_x;
    c10_R[7] = -c10_e_x;
    c10_R[2] = 0.0;
    c10_R[5] = c10_h_x;
    c10_R[8] = c10_k_x;
  } else {
    _SFD_SCRIPT_CALL(0,9);
    if (CV_SCRIPT_IF(0, 1, c10_axis[1] == 1.0)) {
      _SFD_SCRIPT_CALL(0,10);
      c10_m_x = c10_angle;
      c10_n_x = c10_m_x;
      c10_o_x = c10_n_x;
      c10_n_x = c10_o_x;
      c10_n_x = muDoubleScalarCos(c10_n_x);
      c10_p_x = c10_angle;
      c10_q_x = c10_p_x;
      c10_r_x = c10_q_x;
      c10_q_x = c10_r_x;
      c10_q_x = muDoubleScalarSin(c10_q_x);
      c10_s_x = c10_angle;
      c10_t_x = c10_s_x;
      c10_u_x = c10_t_x;
      c10_t_x = c10_u_x;
      c10_t_x = muDoubleScalarSin(c10_t_x);
      c10_v_x = c10_angle;
      c10_w_x = c10_v_x;
      c10_x_x = c10_w_x;
      c10_w_x = c10_x_x;
      c10_w_x = muDoubleScalarCos(c10_w_x);
      c10_R[0] = c10_n_x;
      c10_R[3] = 0.0;
      c10_R[6] = c10_q_x;
      c10_i42 = 0;
      for (c10_i43 = 0; c10_i43 < 3; c10_i43 = c10_i43 + 1) {
        c10_R[c10_i42 + 1] = c10_dv7[c10_i43];
        c10_i42 = c10_i42 + 3;
      }

      c10_R[2] = -c10_t_x;
      c10_R[5] = 0.0;
      c10_R[8] = c10_w_x;
    } else {
      _SFD_SCRIPT_CALL(0,14);
      c10_y_x = c10_angle;
      c10_ab_x = c10_y_x;
      c10_bb_x = c10_ab_x;
      c10_ab_x = c10_bb_x;
      c10_ab_x = muDoubleScalarCos(c10_ab_x);
      c10_cb_x = c10_angle;
      c10_db_x = c10_cb_x;
      c10_eb_x = c10_db_x;
      c10_db_x = c10_eb_x;
      c10_db_x = muDoubleScalarSin(c10_db_x);
      c10_fb_x = c10_angle;
      c10_gb_x = c10_fb_x;
      c10_hb_x = c10_gb_x;
      c10_gb_x = c10_hb_x;
      c10_gb_x = muDoubleScalarSin(c10_gb_x);
      c10_ib_x = c10_angle;
      c10_jb_x = c10_ib_x;
      c10_kb_x = c10_jb_x;
      c10_jb_x = c10_kb_x;
      c10_jb_x = muDoubleScalarCos(c10_jb_x);
      c10_R[0] = c10_ab_x;
      c10_R[3] = -c10_db_x;
      c10_R[6] = 0.0;
      c10_R[1] = c10_gb_x;
      c10_R[4] = c10_jb_x;
      c10_R[7] = 0.0;
      c10_i44 = 0;
      for (c10_i45 = 0; c10_i45 < 3; c10_i45 = c10_i45 + 1) {
        c10_R[c10_i44 + 2] = c10_dv8[c10_i45];
        c10_i44 = c10_i44 + 3;
      }
    }
  }

  _SFD_SCRIPT_CALL(0,-14);
  sf_debug_symbol_scope_pop();
}

static void c10_eml_scalar_eg(SFc10_large_snakeInstanceStruct *chartInstance)
{
}

static void c10_b_eml_scalar_eg(SFc10_large_snakeInstanceStruct *chartInstance)
{
}

static const mxArray *c10_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i46;
  real_T c10_b_u[6];
  const mxArray *c10_b_y = NULL;
  SFc10_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc10_large_snakeInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  for (c10_i46 = 0; c10_i46 < 6; c10_i46 = c10_i46 + 1) {
    c10_b_u[c10_i46] = (*((real_T (*)[6])c10_u))[c10_i46];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_b_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  SFc10_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc10_large_snakeInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  c10_b_u = *((real_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_c_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i47;
  real_T c10_b_u[3];
  const mxArray *c10_b_y = NULL;
  SFc10_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc10_large_snakeInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  for (c10_i47 = 0; c10_i47 < 3; c10_i47 = c10_i47 + 1) {
    c10_b_u[c10_i47] = (*((real_T (*)[3])c10_u))[c10_i47];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_d_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i48;
  int32_T c10_i49;
  int32_T c10_i50;
  real_T c10_b_u[9];
  const mxArray *c10_b_y = NULL;
  SFc10_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc10_large_snakeInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  c10_i48 = 0;
  for (c10_i49 = 0; c10_i49 < 3; c10_i49 = c10_i49 + 1) {
    for (c10_i50 = 0; c10_i50 < 3; c10_i50 = c10_i50 + 1) {
      c10_b_u[c10_i50 + c10_i48] = (*((real_T (*)[9])c10_u))[c10_i50 + c10_i48];
    }

    c10_i48 = c10_i48 + 3;
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

const mxArray *sf_c10_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_ResolvedFunctionInfo c10_info[52];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i51;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_info_helper(c10_info);
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 52));
  for (c10_i51 = 0; c10_i51 < 52; c10_i51 = c10_i51 + 1) {
    c10_r0 = &c10_info[c10_i51];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context"
                    , "nameCaptureInfo", c10_i51);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name",
                    "nameCaptureInfo", c10_i51);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i51);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)),
                    "resolved", "nameCaptureInfo", c10_i51);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c10_i51);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c10_i51);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c10_i51);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[52])
{
  c10_info[0].context = "";
  c10_info[0].name = "mtimes";
  c10_info[0].dominantType = "double";
  c10_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[0].fileLength = 3425U;
  c10_info[0].fileTime1 = 1250697966U;
  c10_info[0].fileTime2 = 0U;
  c10_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[1].name = "nargin";
  c10_info[1].dominantType = "";
  c10_info[1].resolved = "[B]nargin";
  c10_info[1].fileLength = 0U;
  c10_info[1].fileTime1 = 0U;
  c10_info[1].fileTime2 = 0U;
  c10_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[2].name = "gt";
  c10_info[2].dominantType = "double";
  c10_info[2].resolved = "[B]gt";
  c10_info[2].fileLength = 0U;
  c10_info[2].fileTime1 = 0U;
  c10_info[2].fileTime2 = 0U;
  c10_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[3].name = "isa";
  c10_info[3].dominantType = "double";
  c10_info[3].resolved = "[B]isa";
  c10_info[3].fileLength = 0U;
  c10_info[3].fileTime1 = 0U;
  c10_info[3].fileTime2 = 0U;
  c10_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[4].name = "isinteger";
  c10_info[4].dominantType = "double";
  c10_info[4].resolved = "[B]isinteger";
  c10_info[4].fileLength = 0U;
  c10_info[4].fileTime1 = 0U;
  c10_info[4].fileTime2 = 0U;
  c10_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[5].name = "isscalar";
  c10_info[5].dominantType = "double";
  c10_info[5].resolved = "[B]isscalar";
  c10_info[5].fileLength = 0U;
  c10_info[5].fileTime1 = 0U;
  c10_info[5].fileTime2 = 0U;
  c10_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[6].name = "strcmp";
  c10_info[6].dominantType = "char";
  c10_info[6].resolved = "[B]strcmp";
  c10_info[6].fileLength = 0U;
  c10_info[6].fileTime1 = 0U;
  c10_info[6].fileTime2 = 0U;
  c10_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[7].name = "size";
  c10_info[7].dominantType = "double";
  c10_info[7].resolved = "[B]size";
  c10_info[7].fileLength = 0U;
  c10_info[7].fileTime1 = 0U;
  c10_info[7].fileTime2 = 0U;
  c10_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[8].name = "eq";
  c10_info[8].dominantType = "double";
  c10_info[8].resolved = "[B]eq";
  c10_info[8].fileLength = 0U;
  c10_info[8].fileTime1 = 0U;
  c10_info[8].fileTime2 = 0U;
  c10_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[9].name = "class";
  c10_info[9].dominantType = "double";
  c10_info[9].resolved = "[B]class";
  c10_info[9].fileLength = 0U;
  c10_info[9].fileTime1 = 0U;
  c10_info[9].fileTime2 = 0U;
  c10_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[10].name = "not";
  c10_info[10].dominantType = "logical";
  c10_info[10].resolved = "[B]not";
  c10_info[10].fileLength = 0U;
  c10_info[10].fileTime1 = 0U;
  c10_info[10].fileTime2 = 0U;
  c10_info[11].context = "";
  c10_info[11].name = "round";
  c10_info[11].dominantType = "double";
  c10_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c10_info[11].fileLength = 331U;
  c10_info[11].fileTime1 = 1203473236U;
  c10_info[11].fileTime2 = 0U;
  c10_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c10_info[12].name = "eml_scalar_round";
  c10_info[12].dominantType = "double";
  c10_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c10_info[12].fileLength = 523U;
  c10_info[12].fileTime1 = 1203473208U;
  c10_info[12].fileTime2 = 0U;
  c10_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c10_info[13].name = "isfloat";
  c10_info[13].dominantType = "double";
  c10_info[13].resolved = "[B]isfloat";
  c10_info[13].fileLength = 0U;
  c10_info[13].fileTime1 = 0U;
  c10_info[13].fileTime2 = 0U;
  c10_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c10_info[14].name = "isreal";
  c10_info[14].dominantType = "double";
  c10_info[14].resolved = "[B]isreal";
  c10_info[14].fileLength = 0U;
  c10_info[14].fileTime1 = 0U;
  c10_info[14].fileTime2 = 0U;
  c10_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c10_info[15].name = "lt";
  c10_info[15].dominantType = "double";
  c10_info[15].resolved = "[B]lt";
  c10_info[15].fileLength = 0U;
  c10_info[15].fileTime1 = 0U;
  c10_info[15].fileTime2 = 0U;
  c10_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c10_info[16].name = "minus";
  c10_info[16].dominantType = "double";
  c10_info[16].resolved = "[B]minus";
  c10_info[16].fileLength = 0U;
  c10_info[16].fileTime1 = 0U;
  c10_info[16].fileTime2 = 0U;
  c10_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  c10_info[17].name = "plus";
  c10_info[17].dominantType = "double";
  c10_info[17].resolved = "[B]plus";
  c10_info[17].fileLength = 0U;
  c10_info[17].fileTime1 = 0U;
  c10_info[17].fileTime2 = 0U;
  c10_info[18].context = "";
  c10_info[18].name = "mrdivide";
  c10_info[18].dominantType = "double";
  c10_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[18].fileLength = 800U;
  c10_info[18].fileTime1 = 1238459490U;
  c10_info[18].fileTime2 = 0U;
  c10_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[19].name = "ge";
  c10_info[19].dominantType = "double";
  c10_info[19].resolved = "[B]ge";
  c10_info[19].fileLength = 0U;
  c10_info[19].fileTime1 = 0U;
  c10_info[19].fileTime2 = 0U;
  c10_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[20].name = "rdivide";
  c10_info[20].dominantType = "double";
  c10_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[20].fileLength = 403U;
  c10_info[20].fileTime1 = 1244760752U;
  c10_info[20].fileTime2 = 0U;
  c10_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[21].name = "eml_div";
  c10_info[21].dominantType = "double";
  c10_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[21].fileLength = 4269U;
  c10_info[21].fileTime1 = 1228119026U;
  c10_info[21].fileTime2 = 0U;
  c10_info[22].context = "";
  c10_info[22].name = "RotationMatrix";
  c10_info[22].dominantType = "double";
  c10_info[22].resolved = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c10_info[22].fileLength = 433U;
  c10_info[22].fileTime1 = 1468274189U;
  c10_info[22].fileTime2 = 0U;
  c10_info[23].context = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c10_info[23].name = "pi";
  c10_info[23].dominantType = "";
  c10_info[23].resolved = "[B]pi";
  c10_info[23].fileLength = 0U;
  c10_info[23].fileTime1 = 0U;
  c10_info[23].fileTime2 = 0U;
  c10_info[24].context = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c10_info[24].name = "cos";
  c10_info[24].dominantType = "double";
  c10_info[24].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[24].fileLength = 324U;
  c10_info[24].fileTime1 = 1203473150U;
  c10_info[24].fileTime2 = 0U;
  c10_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[25].name = "eml_scalar_cos";
  c10_info[25].dominantType = "double";
  c10_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c10_info[25].fileLength = 602U;
  c10_info[25].fileTime1 = 1209355986U;
  c10_info[25].fileTime2 = 0U;
  c10_info[26].context = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c10_info[26].name = "sin";
  c10_info[26].dominantType = "double";
  c10_info[26].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c10_info[26].fileLength = 324U;
  c10_info[26].fileTime1 = 1203473242U;
  c10_info[26].fileTime2 = 0U;
  c10_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c10_info[27].name = "eml_scalar_sin";
  c10_info[27].dominantType = "double";
  c10_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c10_info[27].fileLength = 601U;
  c10_info[27].fileTime1 = 1209355990U;
  c10_info[27].fileTime2 = 0U;
  c10_info[28].context = "[]C:/Users/arma/Desktop/Dev/ECL2010/RotationMatrix.m";
  c10_info[28].name = "uminus";
  c10_info[28].dominantType = "double";
  c10_info[28].resolved = "[B]uminus";
  c10_info[28].fileLength = 0U;
  c10_info[28].fileTime1 = 0U;
  c10_info[28].fileTime2 = 0U;
  c10_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[29].name = "ndims";
  c10_info[29].dominantType = "double";
  c10_info[29].resolved = "[B]ndims";
  c10_info[29].fileLength = 0U;
  c10_info[29].fileTime1 = 0U;
  c10_info[29].fileTime2 = 0U;
  c10_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[30].name = "le";
  c10_info[30].dominantType = "double";
  c10_info[30].resolved = "[B]le";
  c10_info[30].fileLength = 0U;
  c10_info[30].fileTime1 = 0U;
  c10_info[30].fileTime2 = 0U;
  c10_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[31].name = "ne";
  c10_info[31].dominantType = "logical";
  c10_info[31].resolved = "[B]ne";
  c10_info[31].fileLength = 0U;
  c10_info[31].fileTime1 = 0U;
  c10_info[31].fileTime2 = 0U;
  c10_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[32].name = "eml_index_class";
  c10_info[32].dominantType = "";
  c10_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[32].fileLength = 909U;
  c10_info[32].fileTime1 = 1192491982U;
  c10_info[32].fileTime2 = 0U;
  c10_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[33].name = "ones";
  c10_info[33].dominantType = "char";
  c10_info[33].resolved = "[B]ones";
  c10_info[33].fileLength = 0U;
  c10_info[33].fileTime1 = 0U;
  c10_info[33].fileTime2 = 0U;
  c10_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[34].name = "cast";
  c10_info[34].dominantType = "double";
  c10_info[34].resolved = "[B]cast";
  c10_info[34].fileLength = 0U;
  c10_info[34].fileTime1 = 0U;
  c10_info[34].fileTime2 = 0U;
  c10_info[35].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[35].name = "eml_scalar_eg";
  c10_info[35].dominantType = "double";
  c10_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[35].fileLength = 3068U;
  c10_info[35].fileTime1 = 1240287210U;
  c10_info[35].fileTime2 = 0U;
  c10_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c10_info[36].name = "false";
  c10_info[36].dominantType = "";
  c10_info[36].resolved = "[B]false";
  c10_info[36].fileLength = 0U;
  c10_info[36].fileTime1 = 0U;
  c10_info[36].fileTime2 = 0U;
  c10_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[37].name = "isstruct";
  c10_info[37].dominantType = "double";
  c10_info[37].resolved = "[B]isstruct";
  c10_info[37].fileLength = 0U;
  c10_info[37].fileTime1 = 0U;
  c10_info[37].fileTime2 = 0U;
  c10_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[38].name = "isempty";
  c10_info[38].dominantType = "double";
  c10_info[38].resolved = "[B]isempty";
  c10_info[38].fileLength = 0U;
  c10_info[38].fileTime1 = 0U;
  c10_info[38].fileTime2 = 0U;
  c10_info[39].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[39].name = "eml_xgemm";
  c10_info[39].dominantType = "int32";
  c10_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c10_info[39].fileLength = 3184U;
  c10_info[39].fileTime1 = 1209356052U;
  c10_info[39].fileTime2 = 0U;
  c10_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c10_info[40].name = "length";
  c10_info[40].dominantType = "double";
  c10_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c10_info[40].fileLength = 326U;
  c10_info[40].fileTime1 = 1226602474U;
  c10_info[40].fileTime2 = 0U;
  c10_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c10_info[41].name = "min";
  c10_info[41].dominantType = "double";
  c10_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[41].fileLength = 362U;
  c10_info[41].fileTime1 = 1244760752U;
  c10_info[41].fileTime2 = 0U;
  c10_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[42].name = "nargout";
  c10_info[42].dominantType = "";
  c10_info[42].resolved = "[B]nargout";
  c10_info[42].fileLength = 0U;
  c10_info[42].fileTime1 = 0U;
  c10_info[42].fileTime2 = 0U;
  c10_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[43].name = "eml_min_or_max";
  c10_info[43].dominantType = "char";
  c10_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[43].fileLength = 9969U;
  c10_info[43].fileTime1 = 1240287206U;
  c10_info[43].fileTime2 = 0U;
  c10_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[44].name = "ischar";
  c10_info[44].dominantType = "char";
  c10_info[44].resolved = "[B]ischar";
  c10_info[44].fileLength = 0U;
  c10_info[44].fileTime1 = 0U;
  c10_info[44].fileTime2 = 0U;
  c10_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[45].name = "isnumeric";
  c10_info[45].dominantType = "double";
  c10_info[45].resolved = "[B]isnumeric";
  c10_info[45].fileLength = 0U;
  c10_info[45].fileTime1 = 0U;
  c10_info[45].fileTime2 = 0U;
  c10_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c10_info[46].name = "islogical";
  c10_info[46].dominantType = "double";
  c10_info[46].resolved = "[B]islogical";
  c10_info[46].fileLength = 0U;
  c10_info[46].fileTime1 = 0U;
  c10_info[46].fileTime2 = 0U;
  c10_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c10_info[47].name = "eml_scalexp_alloc";
  c10_info[47].dominantType = "double";
  c10_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c10_info[47].fileLength = 808U;
  c10_info[47].fileTime1 = 1230519898U;
  c10_info[47].fileTime2 = 0U;
  c10_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c10_info[48].name = "eml_refblas_xgemm";
  c10_info[48].dominantType = "int32";
  c10_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c10_info[48].fileLength = 5748U;
  c10_info[48].fileTime1 = 1228119072U;
  c10_info[48].fileTime2 = 0U;
  c10_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c10_info[49].name = "eml_index_minus";
  c10_info[49].dominantType = "int32";
  c10_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c10_info[49].fileLength = 277U;
  c10_info[49].fileTime1 = 1192491984U;
  c10_info[49].fileTime2 = 0U;
  c10_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c10_info[50].name = "eml_index_times";
  c10_info[50].dominantType = "int32";
  c10_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c10_info[50].fileLength = 280U;
  c10_info[50].fileTime1 = 1192491986U;
  c10_info[50].fileTime2 = 0U;
  c10_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c10_info[51].name = "eml_index_plus";
  c10_info[51].dominantType = "int32";
  c10_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c10_info[51].fileLength = 272U;
  c10_info[51].fileTime1 = 1192491984U;
  c10_info[51].fileTime2 = 0U;
}

static const mxArray *c10_e_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  boolean_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  SFc10_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc10_large_snakeInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  c10_b_u = *((boolean_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static void c10_emlrt_marshallIn(SFc10_large_snakeInstanceStruct *chartInstance,
  const mxArray *c10_sensor, const char_T *c10_name,
  real_T c10_y[6])
{
  real_T c10_dv9[6];
  int32_T c10_i52;
  sf_mex_import(c10_name, sf_mex_dup(c10_sensor), &c10_dv9, 1, 0, 0U, 1, 0U, 1,
                6);
  for (c10_i52 = 0; c10_i52 < 6; c10_i52 = c10_i52 + 1) {
    c10_y[c10_i52] = c10_dv9[c10_i52];
  }

  sf_mex_destroy(&c10_sensor);
}

static uint8_T c10_b_emlrt_marshallIn(SFc10_large_snakeInstanceStruct
  *chartInstance, const mxArray *c10_is_active_c10_large_snake,
  const char_T *c10_name)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_name, sf_mex_dup(c10_is_active_c10_large_snake), &c10_u0, 1,
                3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_is_active_c10_large_snake);
  return c10_y;
}

static void init_dsm_address_info(SFc10_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c10_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2298000191U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1975510851U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3391658010U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(782053085U);
}

mxArray *sf_c10_large_snake_get_autoinheritance_info(void)
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

static mxArray *sf_get_sim_state_info_c10_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[11],T\"sensor\",},{M[8],M[0],T\"is_active_c10_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc10_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           10,
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
                                1.0,0,"u",0,(MexFcnForType)c10_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"sensor",0,(MexFcnForType)c10_sf_marshall);
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
          real_T (*c10_u)[6];
          real_T (*c10_sensor)[6];
          c10_sensor = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c10_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_sensor);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c10_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_large_snakeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_large_snake((SFc10_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c10_large_snake((SFc10_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_large_snake(void *chartInstanceVar)
{
  enable_c10_large_snake((SFc10_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_large_snake(void *chartInstanceVar)
{
  disable_c10_large_snake((SFc10_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_large_snake(void *chartInstanceVar)
{
  sf_c10_large_snake((SFc10_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c10_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c10_large_snake((SFc10_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c10_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_large_snake
    ((SFc10_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c10_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c10_large_snake(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_large_snake((SFc10_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c10_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c10_large_snake(S);
}

static void sf_opaque_set_sim_state_c10_large_snake(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c10_large_snake(S, st);
}

static void sf_opaque_terminate_c10_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c10_large_snake((SFc10_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_large_snake((SFc10_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c10_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",10,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",10,1);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",10,1);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",10);
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

static void mdlRTW_c10_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",10);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_large_snake(SimStruct *S)
{
  SFc10_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc10_large_snakeInstanceStruct *)malloc(sizeof
    (SFc10_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c10_large_snake;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c10_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c10_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c10_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c10_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c10_large_snake;
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

void c10_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
