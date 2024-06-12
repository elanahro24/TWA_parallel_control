/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c3_large_snake.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c3_debug_family_names[10] = { "STOP", "i", "nargin",
  "nargout", "stall", "dt", "stallTime", "prevCounter", "stop", "counter" };

/* Function Declarations */
static void initialize_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance);
static void enable_c3_large_snake(SFc3_large_snakeInstanceStruct *chartInstance);
static void disable_c3_large_snake(SFc3_large_snakeInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_large_snake
  (SFc3_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_large_snake
  (SFc3_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance);
static void sf_c3_large_snake(SFc3_large_snakeInstanceStruct *chartInstance);
static void c3_c3_large_snake(SFc3_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_c_sf_marshall(void *chartInstanceVoid, void *c3_u);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[33]);
static const mxArray *c3_d_sf_marshall(void *chartInstanceVoid, void *c3_u);
static void c3_emlrt_marshallIn(SFc3_large_snakeInstanceStruct *chartInstance,
  const mxArray *c3_counter, const char_T *c3_name, real_T c3_y[10]);
static real_T c3_b_emlrt_marshallIn(SFc3_large_snakeInstanceStruct
  *chartInstance, const mxArray *c3_stop, const char_T *c3_name);
static uint8_T c3_c_emlrt_marshallIn(SFc3_large_snakeInstanceStruct
  *chartInstance, const mxArray *c3_is_active_c3_large_snake, const char_T
  *c3_name);
static void init_dsm_address_info(SFc3_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c3_is_active_c3_large_snake;
  c3_is_active_c3_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c3_is_active_c3_large_snake = 0U;
}

static void initialize_params_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c3_large_snake(SFc3_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_large_snake(SFc3_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_large_snake
  (SFc3_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance)
{
  c3_update_debugger_state_c3_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c3_large_snake
  (SFc3_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c3_st = NULL;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_hoistedGlobal[10];
  int32_T c3_i1;
  real_T c3_u[10];
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_stop;
  uint8_T *c3_is_active_c3_large_snake;
  real_T (*c3_counter)[10];
  c3_counter = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3));
  for (c3_i0 = 0; c3_i0 < 10; c3_i0 = c3_i0 + 1) {
    c3_hoistedGlobal[c3_i0] = (*c3_counter)[c3_i0];
  }

  for (c3_i1 = 0; c3_i1 < 10; c3_i1 = c3_i1 + 1) {
    c3_u[c3_i1] = c3_hoistedGlobal[c3_i1];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 1U, 0U, 1, 10));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_stop;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_is_active_c3_large_snake;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[10];
  int32_T c3_i2;
  boolean_T *c3_doneDoubleBufferReInit;
  real_T *c3_stop;
  uint8_T *c3_is_active_c3_large_snake;
  real_T (*c3_counter)[10];
  c3_counter = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "counter", c3_dv0);
  for (c3_i2 = 0; c3_i2 < 10; c3_i2 = c3_i2 + 1) {
    (*c3_counter)[c3_i2] = c3_dv0[c3_i2];
  }

  *c3_stop = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    1)), "stop");
  *c3_is_active_c3_large_snake = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "is_active_c3_large_snake");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_large_snake(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_large_snake(SFc3_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c3_large_snake(SFc3_large_snakeInstanceStruct *chartInstance)
{
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_previousEvent;
  real_T *c3_dt;
  real_T *c3_stallTime;
  real_T *c3_stop;
  real_T (*c3_counter)[10];
  real_T (*c3_prevCounter)[10];
  boolean_T (*c3_stall)[10];
  c3_counter = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_prevCounter = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 3);
  c3_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_stallTime = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_stall = (boolean_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  for (c3_i3 = 0; c3_i3 < 10; c3_i3 = c3_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c3_stall)[c3_i3], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_dt, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_stallTime, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_stop, 3U);
  for (c3_i4 = 0; c3_i4 < 10; c3_i4 = c3_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_prevCounter)[c3_i4], 4U);
  }

  for (c3_i5 = 0; c3_i5 < 10; c3_i5 = c3_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_counter)[c3_i5], 5U);
  }

  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c3_c3_large_snake(chartInstance);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_c3_large_snake(SFc3_large_snakeInstanceStruct *chartInstance)
{
  int32_T c3_i6;
  boolean_T c3_hoistedGlobal[10];
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  int32_T c3_i7;
  real_T c3_d_hoistedGlobal[10];
  int32_T c3_i8;
  boolean_T c3_stall[10];
  real_T c3_dt;
  real_T c3_stallTime;
  int32_T c3_i9;
  real_T c3_prevCounter[10];
  uint32_T c3_debug_family_var_map[10];
  static const char *c3_sv0[10] = { "STOP", "i", "nargin", "nargout", "stall",
    "dt", "stallTime", "prevCounter", "stop", "counter" };

  real_T c3_STOP[10];
  real_T c3_i;
  real_T c3_nargin = 4.0;
  real_T c3_nargout = 2.0;
  real_T c3_stop;
  real_T c3_counter[10];
  int32_T c3_i10;
  boolean_T c3_x[10];
  real_T c3_y;
  int32_T c3_k;
  int32_T c3_b_k;
  int32_T c3_i11;
  int32_T c3_i12;
  real_T c3_b_i;
  real_T c3_A;
  real_T c3_B;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_e_y;
  int32_T c3_i13;
  real_T c3_e_x[10];
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_i14;
  int32_T c3_i15;
  real_T *c3_b_dt;
  real_T *c3_b_stallTime;
  real_T *c3_b_stop;
  real_T (*c3_b_counter)[10];
  real_T (*c3_b_prevCounter)[10];
  boolean_T (*c3_b_stall)[10];
  c3_b_counter = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_prevCounter = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_stallTime = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_stall = (boolean_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  for (c3_i6 = 0; c3_i6 < 10; c3_i6 = c3_i6 + 1) {
    c3_hoistedGlobal[c3_i6] = (*c3_b_stall)[c3_i6];
  }

  c3_b_hoistedGlobal = *c3_b_dt;
  c3_c_hoistedGlobal = *c3_b_stallTime;
  for (c3_i7 = 0; c3_i7 < 10; c3_i7 = c3_i7 + 1) {
    c3_d_hoistedGlobal[c3_i7] = (*c3_b_prevCounter)[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 10; c3_i8 = c3_i8 + 1) {
    c3_stall[c3_i8] = c3_hoistedGlobal[c3_i8];
  }

  c3_dt = c3_b_hoistedGlobal;
  c3_stallTime = c3_c_hoistedGlobal;
  for (c3_i9 = 0; c3_i9 < 10; c3_i9 = c3_i9 + 1) {
    c3_prevCounter[c3_i9] = c3_d_hoistedGlobal[c3_i9];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c3_sv0, c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_STOP, c3_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c3_i, c3_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c3_nargin, c3_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c3_nargout, c3_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c3_stall, c3_c_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c3_dt, c3_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c3_stallTime, c3_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c3_prevCounter, c3_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c3_stop, c3_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c3_counter, c3_sf_marshall, 9U);
  CV_EML_FCN(0, 0);

  /*  Description: */
  /*               if a motor is jammed for more than <stallTime> seconds --> stuck! -->stop model! */
  /*  Created by: */
  /*               Nima Sarli */
  /*  Date */
  /*              12/03/2015 */
  /*  */
  _SFD_EML_CALL(0,9);
  for (c3_i10 = 0; c3_i10 < 10; c3_i10 = c3_i10 + 1) {
    c3_x[c3_i10] = c3_stall[c3_i10];
  }

  c3_y = (real_T)c3_x[0];
  for (c3_k = 2; c3_k < 11; c3_k = c3_k + 1) {
    c3_b_k = c3_k;
    c3_y = c3_y + (real_T)c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 10, 1, 0) - 1];
  }

  if (CV_EML_IF(0, 0, c3_y > 0.0)) {
    /* if any motor is stalled */
    _SFD_EML_CALL(0,10);
    for (c3_i11 = 0; c3_i11 < 10; c3_i11 = c3_i11 + 1) {
      c3_counter[c3_i11] = c3_prevCounter[c3_i11] + (real_T)c3_stall[c3_i11];
    }

    /* start counting time */
    _SFD_EML_CALL(0,11);
    for (c3_i12 = 0; c3_i12 < 10; c3_i12 = c3_i12 + 1) {
      c3_STOP[c3_i12] = 0.0;
    }

    c3_i = 1.0;
    c3_b_i = 1.0;
    while (c3_b_i <= 10.0) {
      c3_i = c3_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0,13);
      c3_A = c3_stallTime;
      c3_B = c3_dt;
      c3_b_x = c3_A;
      c3_b_y = c3_B;
      c3_c_x = c3_b_x;
      c3_c_y = c3_b_y;
      c3_d_x = c3_c_x;
      c3_d_y = c3_c_y;
      c3_e_y = c3_d_x / c3_d_y;
      if (CV_EML_IF(0, 1, c3_counter[_SFD_EML_ARRAY_BOUNDS_CHECK("counter",
            (int32_T)_SFD_INTEGER_CHECK("i", c3_i), 1, 10, 1, 0) - 1] >
                    c3_e_y)) {
        /* stuck for more than <stallTime> seconds */
        _SFD_EML_CALL(0,14);
        c3_STOP[_SFD_EML_ARRAY_BOUNDS_CHECK("STOP", (int32_T)_SFD_INTEGER_CHECK(
          "i", c3_i), 1, 10, 1, 0) - 1] = 1.0;

        /* stuck! -->stop model */
      } else {
        /*  stuck for less than <stallTime> */
        _SFD_EML_CALL(0,16);
        if (CV_EML_IF(0, 2, c3_counter[_SFD_EML_ARRAY_BOUNDS_CHECK("counter",
              (int32_T)_SFD_INTEGER_CHECK("i", c3_i), 1, 10, 1, 0) - 1] ==
                      c3_prevCounter[_SFD_EML_ARRAY_BOUNDS_CHECK("prevCounter",
              (int32_T)_SFD_INTEGER_CHECK("i", c3_i), 1, 10, 1, 0) - 1])) {
          _SFD_EML_CALL(0,17);
          c3_counter[_SFD_EML_ARRAY_BOUNDS_CHECK("counter", (int32_T)
            _SFD_INTEGER_CHECK("i", c3_i), 1, 10, 1, 0) - 1] = 0.0;
        }

        _SFD_EML_CALL(0,19);
        c3_STOP[_SFD_EML_ARRAY_BOUNDS_CHECK("STOP", (int32_T)_SFD_INTEGER_CHECK(
          "i", c3_i), 1, 10, 1, 0) - 1] = 0.0;
      }

      c3_b_i = c3_b_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
    _SFD_EML_CALL(0,22);
    for (c3_i13 = 0; c3_i13 < 10; c3_i13 = c3_i13 + 1) {
      c3_e_x[c3_i13] = c3_STOP[c3_i13];
    }

    c3_stop = c3_e_x[0];
    for (c3_c_k = 2; c3_c_k < 11; c3_c_k = c3_c_k + 1) {
      c3_d_k = c3_c_k;
      c3_stop = c3_stop + c3_e_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c3_d_k), 1, 10, 1, 0) - 1];
    }
  } else {
    /* no motor stalled */
    _SFD_EML_CALL(0,24);
    c3_stop = 0.0;
    _SFD_EML_CALL(0,25);
    for (c3_i14 = 0; c3_i14 < 10; c3_i14 = c3_i14 + 1) {
      c3_counter[c3_i14] = 0.0;
    }
  }

  _SFD_EML_CALL(0,-25);
  sf_debug_symbol_scope_pop();
  *c3_b_stop = c3_stop;
  for (c3_i15 = 0; c3_i15 < 10; c3_i15 = c3_i15 + 1) {
    (*c3_b_counter)[c3_i15] = c3_counter[c3_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i16;
  real_T c3_b_u[10];
  const mxArray *c3_b_y = NULL;
  SFc3_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc3_large_snakeInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i16 = 0; c3_i16 < 10; c3_i16 = c3_i16 + 1) {
    c3_b_u[c3_i16] = (*((real_T (*)[10])c3_u))[c3_i16];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 1, 10));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc3_large_snakeInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_c_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i17;
  boolean_T c3_b_u[10];
  const mxArray *c3_b_y = NULL;
  SFc3_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc3_large_snakeInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i17 = 0; c3_i17 < 10; c3_i17 = c3_i17 + 1) {
    c3_b_u[c3_i17] = (*((boolean_T (*)[10])c3_u))[c3_i17];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 11, 0U, 1U, 0U, 2, 10, 1));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[33];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i18;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 33));
  for (c3_i18 = 0; c3_i18 < 33; c3_i18 = c3_i18 + 1) {
    c3_r0 = &c3_info[c3_i18];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
                    "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name",
                    "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c3_i18);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c3_i18
                    );
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c3_i18
                    );
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[33])
{
  c3_info[0].context = "";
  c3_info[0].name = "sum";
  c3_info[0].dominantType = "logical";
  c3_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[0].fileLength = 3457U;
  c3_info[0].fileTime1 = 1244760752U;
  c3_info[0].fileTime2 = 0U;
  c3_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[1].name = "nargin";
  c3_info[1].dominantType = "";
  c3_info[1].resolved = "[B]nargin";
  c3_info[1].fileLength = 0U;
  c3_info[1].fileTime1 = 0U;
  c3_info[1].fileTime2 = 0U;
  c3_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[2].name = "gt";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[B]gt";
  c3_info[2].fileLength = 0U;
  c3_info[2].fileTime1 = 0U;
  c3_info[2].fileTime2 = 0U;
  c3_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[3].name = "isa";
  c3_info[3].dominantType = "char";
  c3_info[3].resolved = "[B]isa";
  c3_info[3].fileLength = 0U;
  c3_info[3].fileTime1 = 0U;
  c3_info[3].fileTime2 = 0U;
  c3_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[4].name = "ischar";
  c3_info[4].dominantType = "logical";
  c3_info[4].resolved = "[B]ischar";
  c3_info[4].fileLength = 0U;
  c3_info[4].fileTime1 = 0U;
  c3_info[4].fileTime2 = 0U;
  c3_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[5].name = "islogical";
  c3_info[5].dominantType = "logical";
  c3_info[5].resolved = "[B]islogical";
  c3_info[5].fileLength = 0U;
  c3_info[5].fileTime1 = 0U;
  c3_info[5].fileTime2 = 0U;
  c3_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[6].name = "eq";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[B]eq";
  c3_info[6].fileLength = 0U;
  c3_info[6].fileTime1 = 0U;
  c3_info[6].fileTime2 = 0U;
  c3_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[7].name = "size";
  c3_info[7].dominantType = "logical";
  c3_info[7].resolved = "[B]size";
  c3_info[7].fileLength = 0U;
  c3_info[7].fileTime1 = 0U;
  c3_info[7].fileTime2 = 0U;
  c3_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[8].name = "isequal";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[8].fileLength = 180U;
  c3_info[8].fileTime1 = 1226602470U;
  c3_info[8].fileTime2 = 0U;
  c3_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[9].name = "false";
  c3_info[9].dominantType = "";
  c3_info[9].resolved = "[B]false";
  c3_info[9].fileLength = 0U;
  c3_info[9].fileTime1 = 0U;
  c3_info[9].fileTime2 = 0U;
  c3_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[10].name = "eml_isequal_core";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[10].fileLength = 4192U;
  c3_info[10].fileTime1 = 1257808582U;
  c3_info[10].fileTime2 = 0U;
  c3_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[11].name = "ge";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved = "[B]ge";
  c3_info[11].fileLength = 0U;
  c3_info[11].fileTime1 = 0U;
  c3_info[11].fileTime2 = 0U;
  c3_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[12].name = "isscalar";
  c3_info[12].dominantType = "logical";
  c3_info[12].resolved = "[B]isscalar";
  c3_info[12].fileLength = 0U;
  c3_info[12].fileTime1 = 0U;
  c3_info[12].fileTime2 = 0U;
  c3_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[13].name = "minus";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved = "[B]minus";
  c3_info[13].fileLength = 0U;
  c3_info[13].fileTime1 = 0U;
  c3_info[13].fileTime2 = 0U;
  c3_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[14].name = "isnumeric";
  c3_info[14].dominantType = "logical";
  c3_info[14].resolved = "[B]isnumeric";
  c3_info[14].fileLength = 0U;
  c3_info[14].fileTime1 = 0U;
  c3_info[14].fileTime2 = 0U;
  c3_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c3_info[15].name = "ndims";
  c3_info[15].dominantType = "logical";
  c3_info[15].resolved = "[B]ndims";
  c3_info[15].fileLength = 0U;
  c3_info[15].fileTime1 = 0U;
  c3_info[15].fileTime2 = 0U;
  c3_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c3_info[16].name = "ne";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved = "[B]ne";
  c3_info[16].fileLength = 0U;
  c3_info[16].fileTime1 = 0U;
  c3_info[16].fileTime2 = 0U;
  c3_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c3_info[17].name = "true";
  c3_info[17].dominantType = "";
  c3_info[17].resolved = "[B]true";
  c3_info[17].fileLength = 0U;
  c3_info[17].fileTime1 = 0U;
  c3_info[17].fileTime2 = 0U;
  c3_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[18].name = "not";
  c3_info[18].dominantType = "logical";
  c3_info[18].resolved = "[B]not";
  c3_info[18].fileLength = 0U;
  c3_info[18].fileTime1 = 0U;
  c3_info[18].fileTime2 = 0U;
  c3_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[19].name = "eml_const_nonsingleton_dim";
  c3_info[19].dominantType = "logical";
  c3_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c3_info[19].fileLength = 1473U;
  c3_info[19].fileTime1 = 1240287202U;
  c3_info[19].fileTime2 = 0U;
  c3_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[20].name = "cast";
  c3_info[20].dominantType = "char";
  c3_info[20].resolved = "[B]cast";
  c3_info[20].fileLength = 0U;
  c3_info[20].fileTime1 = 0U;
  c3_info[20].fileTime2 = 0U;
  c3_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[21].name = "eml_scalar_eg";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[21].fileLength = 3068U;
  c3_info[21].fileTime1 = 1240287210U;
  c3_info[21].fileTime2 = 0U;
  c3_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[22].name = "isstruct";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved = "[B]isstruct";
  c3_info[22].fileLength = 0U;
  c3_info[22].fileTime1 = 0U;
  c3_info[22].fileTime2 = 0U;
  c3_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c3_info[23].name = "class";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved = "[B]class";
  c3_info[23].fileLength = 0U;
  c3_info[23].fileTime1 = 0U;
  c3_info[23].fileTime2 = 0U;
  c3_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c3_info[24].name = "isreal";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved = "[B]isreal";
  c3_info[24].fileLength = 0U;
  c3_info[24].fileTime1 = 0U;
  c3_info[24].fileTime2 = 0U;
  c3_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[25].name = "isempty";
  c3_info[25].dominantType = "logical";
  c3_info[25].resolved = "[B]isempty";
  c3_info[25].fileLength = 0U;
  c3_info[25].fileTime1 = 0U;
  c3_info[25].fileTime2 = 0U;
  c3_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[26].name = "eml_index_class";
  c3_info[26].dominantType = "";
  c3_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[26].fileLength = 909U;
  c3_info[26].fileTime1 = 1192491982U;
  c3_info[26].fileTime2 = 0U;
  c3_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[27].name = "plus";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved = "[B]plus";
  c3_info[27].fileLength = 0U;
  c3_info[27].fileTime1 = 0U;
  c3_info[27].fileTime2 = 0U;
  c3_info[28].context = "";
  c3_info[28].name = "zeros";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved = "[B]zeros";
  c3_info[28].fileLength = 0U;
  c3_info[28].fileTime1 = 0U;
  c3_info[28].fileTime2 = 0U;
  c3_info[29].context = "";
  c3_info[29].name = "mrdivide";
  c3_info[29].dominantType = "double";
  c3_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[29].fileLength = 800U;
  c3_info[29].fileTime1 = 1238459490U;
  c3_info[29].fileTime2 = 0U;
  c3_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[30].name = "rdivide";
  c3_info[30].dominantType = "double";
  c3_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[30].fileLength = 403U;
  c3_info[30].fileTime1 = 1244760752U;
  c3_info[30].fileTime2 = 0U;
  c3_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[31].name = "eml_div";
  c3_info[31].dominantType = "double";
  c3_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[31].fileLength = 4269U;
  c3_info[31].fileTime1 = 1228119026U;
  c3_info[31].fileTime2 = 0U;
  c3_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[32].name = "isinteger";
  c3_info[32].dominantType = "double";
  c3_info[32].resolved = "[B]isinteger";
  c3_info[32].fileLength = 0U;
  c3_info[32].fileTime1 = 0U;
  c3_info[32].fileTime2 = 0U;
}

static const mxArray *c3_d_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  boolean_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc3_large_snakeInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_b_u = *((boolean_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static void c3_emlrt_marshallIn(SFc3_large_snakeInstanceStruct *chartInstance,
  const mxArray *c3_counter, const char_T *c3_name,
  real_T c3_y[10])
{
  real_T c3_dv1[10];
  int32_T c3_i19;
  sf_mex_import(c3_name, sf_mex_dup(c3_counter), &c3_dv1, 1, 0, 0U, 1, 0U, 1, 10);
  for (c3_i19 = 0; c3_i19 < 10; c3_i19 = c3_i19 + 1) {
    c3_y[c3_i19] = c3_dv1[c3_i19];
  }

  sf_mex_destroy(&c3_counter);
}

static real_T c3_b_emlrt_marshallIn(SFc3_large_snakeInstanceStruct
  *chartInstance, const mxArray *c3_stop, const char_T *c3_name)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_name, sf_mex_dup(c3_stop), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_stop);
  return c3_y;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_large_snakeInstanceStruct
  *chartInstance, const mxArray *c3_is_active_c3_large_snake,
  const char_T *c3_name)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_name, sf_mex_dup(c3_is_active_c3_large_snake), &c3_u0, 1, 3,
                0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_is_active_c3_large_snake);
  return c3_y;
}

static void init_dsm_address_info(SFc3_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2096998728U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2615605428U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3075324693U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2289167521U);
}

mxArray *sf_c3_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1424600982U);
    pr[1] = (double)(486649017U);
    pr[2] = (double)(4143299678U);
    pr[3] = (double)(3524427746U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      pr[0] = (double)(10);
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
      pr[0] = (double)(10);
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

static mxArray *sf_get_sim_state_info_c3_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"counter\",},{M[1],M[5],T\"stop\",},{M[8],M[0],T\"is_active_c3_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc3_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           3,
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
            unsigned int dimVector[2];
            dimVector[0]= 10;
            dimVector[1]= 1;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"stall",0,(MexFcnForType)c3_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dt",0,
                              (MexFcnForType)c3_b_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "stallTime",0,(MexFcnForType)c3_b_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"stop",0,
                              (MexFcnForType)c3_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 10;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"prevCounter",0,(MexFcnForType)
                                c3_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 10;
            _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"counter",0,(MexFcnForType)c3_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,3,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",185,-1,787);
        _SFD_CV_INIT_EML_IF(0,0,249,264,717,784);
        _SFD_CV_INIT_EML_IF(0,1,395,426,523,686);
        _SFD_CV_INIT_EML_IF(0,2,574,603,-1,649);
        _SFD_CV_INIT_EML_FOR(0,0,374,387,694);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          boolean_T (*c3_stall)[10];
          real_T *c3_dt;
          real_T *c3_stallTime;
          real_T *c3_stop;
          real_T (*c3_prevCounter)[10];
          real_T (*c3_counter)[10];
          c3_counter = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
          c3_prevCounter = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S,
            3);
          c3_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_stallTime = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_stall = (boolean_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_stall);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_dt);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_stallTime);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_stop);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_prevCounter);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_counter);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_large_snakeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_large_snake((SFc3_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c3_large_snake((SFc3_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_large_snake(void *chartInstanceVar)
{
  enable_c3_large_snake((SFc3_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_large_snake(void *chartInstanceVar)
{
  disable_c3_large_snake((SFc3_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_large_snake(void *chartInstanceVar)
{
  sf_c3_large_snake((SFc3_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c3_large_snake((SFc3_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c3_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_large_snake
    ((SFc3_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c3_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c3_large_snake(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_large_snake((SFc3_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c3_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_large_snake(S);
}

static void sf_opaque_set_sim_state_c3_large_snake(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_large_snake(S, st);
}

static void sf_opaque_terminate_c3_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_large_snake((SFc3_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_large_snake((SFc3_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c3_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",3,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",3,4);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",3,2);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(4183765403U));
  ssSetChecksum1(S,(60049106U));
  ssSetChecksum2(S,(3153344886U));
  ssSetChecksum3(S,(3710433906U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_large_snake(SimStruct *S)
{
  SFc3_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc3_large_snakeInstanceStruct *)malloc(sizeof
    (SFc3_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_large_snake;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c3_large_snake;
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

void c3_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
