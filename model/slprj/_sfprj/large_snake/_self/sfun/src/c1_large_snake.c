/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c1_large_snake.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[20] = { "N", "dx", "i", "cur_t", "T",
  "TT", "TTT", "nargin", "nargout", "q_in", "q_prev", "status", "A_in", "tspan",
  "dt", "q_des", "dq_des", "ddq_des", "cur_status", "A_out" };

/* Function Declarations */
static void initialize_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance);
static void enable_c1_large_snake(SFc1_large_snakeInstanceStruct *chartInstance);
static void disable_c1_large_snake(SFc1_large_snakeInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_large_snake
  (SFc1_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_large_snake
  (SFc1_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance);
static void sf_c1_large_snake(SFc1_large_snakeInstanceStruct *chartInstance);
static void c1_c1_large_snake(SFc1_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_norm(SFc1_large_snakeInstanceStruct *chartInstance, real_T
                      c1_x[7]);
static real_T c1_ceval_xnrm2(SFc1_large_snakeInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[7], int32_T c1_ix0, int32_T c1_incx);
static real_T c1_mpower(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a);
static real_T c1_power(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a, real_T c1_b);
static void c1_eml_scalar_eg(SFc1_large_snakeInstanceStruct *chartInstance);
static void c1_eml_error(SFc1_large_snakeInstanceStruct *chartInstance);
static real_T c1_b_mpower(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a);
static real_T c1_c_mpower(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a);
static real_T c1_d_mpower(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a);
static void c1_b_eml_scalar_eg(SFc1_large_snakeInstanceStruct *chartInstance);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[58]);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_emlrt_marshallIn(SFc1_large_snakeInstanceStruct *chartInstance,
  const mxArray *c1_A_out, const char_T *c1_name, real_T c1_y[28]);
static real_T c1_b_emlrt_marshallIn(SFc1_large_snakeInstanceStruct
  *chartInstance, const mxArray *c1_cur_status, const char_T *c1_name);
static void c1_c_emlrt_marshallIn(SFc1_large_snakeInstanceStruct *chartInstance,
  const mxArray *c1_ddq_des, const char_T *c1_name, real_T c1_y[7]);
static uint8_T c1_d_emlrt_marshallIn(SFc1_large_snakeInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_large_snake, const char_T
  *c1_name);
static void init_dsm_address_info(SFc1_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c1_is_active_c1_large_snake;
  c1_is_active_c1_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_large_snake = 0U;
}

static void initialize_params_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c1_large_snake(SFc1_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_large_snake(SFc1_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_large_snake
  (SFc1_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance)
{
  c1_update_debugger_state_c1_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c1_large_snake
  (SFc1_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_hoistedGlobal[28];
  int32_T c1_i1;
  real_T c1_u[28];
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_i2;
  real_T c1_c_hoistedGlobal[7];
  int32_T c1_i3;
  real_T c1_c_u[7];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i4;
  real_T c1_d_hoistedGlobal[7];
  int32_T c1_i5;
  real_T c1_d_u[7];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i6;
  real_T c1_e_hoistedGlobal[7];
  int32_T c1_i7;
  real_T c1_e_u[7];
  const mxArray *c1_f_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  uint8_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T *c1_cur_status;
  uint8_T *c1_is_active_c1_large_snake;
  real_T (*c1_q_des)[7];
  real_T (*c1_dq_des)[7];
  real_T (*c1_ddq_des)[7];
  real_T (*c1_A_out)[28];
  c1_A_out = (real_T (*)[28])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_cur_status = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_ddq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_dq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_q_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(6));
  for (c1_i0 = 0; c1_i0 < 28; c1_i0 = c1_i0 + 1) {
    c1_hoistedGlobal[c1_i0] = (*c1_A_out)[c1_i0];
  }

  for (c1_i1 = 0; c1_i1 < 28; c1_i1 = c1_i1 + 1) {
    c1_u[c1_i1] = c1_hoistedGlobal[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 1U, 0U, 2, 7, 4));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_cur_status;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i2 = 0; c1_i2 < 7; c1_i2 = c1_i2 + 1) {
    c1_c_hoistedGlobal[c1_i2] = (*c1_ddq_des)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 7; c1_i3 = c1_i3 + 1) {
    c1_c_u[c1_i3] = c1_c_hoistedGlobal[c1_i3];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  for (c1_i4 = 0; c1_i4 < 7; c1_i4 = c1_i4 + 1) {
    c1_d_hoistedGlobal[c1_i4] = (*c1_dq_des)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 7; c1_i5 = c1_i5 + 1) {
    c1_d_u[c1_i5] = c1_d_hoistedGlobal[c1_i5];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c1_y, 3, c1_e_y);
  for (c1_i6 = 0; c1_i6 < 7; c1_i6 = c1_i6 + 1) {
    c1_e_hoistedGlobal[c1_i6] = (*c1_q_des)[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 7; c1_i7 = c1_i7 + 1) {
    c1_e_u[c1_i7] = c1_e_hoistedGlobal[c1_i7];
  }

  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_is_active_c1_large_snake;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 5, c1_g_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[28];
  int32_T c1_i8;
  real_T c1_dv1[7];
  int32_T c1_i9;
  real_T c1_dv2[7];
  int32_T c1_i10;
  real_T c1_dv3[7];
  int32_T c1_i11;
  boolean_T *c1_doneDoubleBufferReInit;
  real_T *c1_cur_status;
  uint8_T *c1_is_active_c1_large_snake;
  real_T (*c1_A_out)[28];
  real_T (*c1_ddq_des)[7];
  real_T (*c1_dq_des)[7];
  real_T (*c1_q_des)[7];
  c1_A_out = (real_T (*)[28])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_cur_status = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_ddq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_dq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_q_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "A_out", c1_dv0);
  for (c1_i8 = 0; c1_i8 < 28; c1_i8 = c1_i8 + 1) {
    (*c1_A_out)[c1_i8] = c1_dv0[c1_i8];
  }

  *c1_cur_status = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "cur_status");
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "ddq_des", c1_dv1);
  for (c1_i9 = 0; c1_i9 < 7; c1_i9 = c1_i9 + 1) {
    (*c1_ddq_des)[c1_i9] = c1_dv1[c1_i9];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
                        "dq_des", c1_dv2);
  for (c1_i10 = 0; c1_i10 < 7; c1_i10 = c1_i10 + 1) {
    (*c1_dq_des)[c1_i10] = c1_dv2[c1_i10];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
                        "q_des", c1_dv3);
  for (c1_i11 = 0; c1_i11 < 7; c1_i11 = c1_i11 + 1) {
    (*c1_q_des)[c1_i11] = c1_dv3[c1_i11];
  }

  *c1_is_active_c1_large_snake = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 5)), "is_active_c1_large_snake");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_large_snake(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_large_snake(SFc1_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c1_large_snake(SFc1_large_snakeInstanceStruct *chartInstance)
{
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_previousEvent;
  real_T *c1_cur_status;
  real_T *c1_status;
  real_T *c1_tspan;
  real_T *c1_dt;
  real_T (*c1_A_out)[28];
  real_T (*c1_A_in)[28];
  real_T (*c1_q_prev)[7];
  real_T (*c1_ddq_des)[7];
  real_T (*c1_dq_des)[7];
  real_T (*c1_q_des)[7];
  real_T (*c1_q_in)[7];
  c1_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_A_out = (real_T (*)[28])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_tspan = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_A_in = (real_T (*)[28])ssGetInputPortSignal(chartInstance->S, 3);
  c1_status = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_cur_status = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_q_prev = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 1);
  c1_ddq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_dq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_q_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_q_in = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c1_i12 = 0; c1_i12 < 7; c1_i12 = c1_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_q_in)[c1_i12], 0U);
  }

  for (c1_i13 = 0; c1_i13 < 7; c1_i13 = c1_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_q_des)[c1_i13], 1U);
  }

  for (c1_i14 = 0; c1_i14 < 7; c1_i14 = c1_i14 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_dq_des)[c1_i14], 2U);
  }

  for (c1_i15 = 0; c1_i15 < 7; c1_i15 = c1_i15 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_ddq_des)[c1_i15], 3U);
  }

  for (c1_i16 = 0; c1_i16 < 7; c1_i16 = c1_i16 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_q_prev)[c1_i16], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_cur_status, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_status, 6U);
  for (c1_i17 = 0; c1_i17 < 28; c1_i17 = c1_i17 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_A_in)[c1_i17], 7U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_tspan, 8U);
  for (c1_i18 = 0; c1_i18 < 28; c1_i18 = c1_i18 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_A_out)[c1_i18], 9U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_dt, 10U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_large_snake(chartInstance);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_large_snake(SFc1_large_snakeInstanceStruct *chartInstance)
{
  int32_T c1_i19;
  real_T c1_hoistedGlobal[7];
  int32_T c1_i20;
  real_T c1_b_hoistedGlobal[7];
  real_T c1_c_hoistedGlobal;
  int32_T c1_i21;
  real_T c1_d_hoistedGlobal[28];
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  int32_T c1_i22;
  real_T c1_q_in[7];
  int32_T c1_i23;
  real_T c1_q_prev[7];
  real_T c1_status;
  int32_T c1_i24;
  real_T c1_A_in[28];
  real_T c1_tspan;
  real_T c1_dt;
  uint32_T c1_debug_family_var_map[20];
  static const char *c1_sv0[20] = { "N", "dx", "i", "cur_t", "T", "TT", "TTT",
    "nargin", "nargout", "q_in", "q_prev", "status", "A_in"
    , "tspan", "dt", "q_des", "dq_des", "ddq_des", "cur_status", "A_out" };

  real_T c1_N;
  real_T c1_dx[7];
  real_T c1_i;
  real_T c1_cur_t;
  real_T c1_T[4];
  real_T c1_TT[4];
  real_T c1_TTT[4];
  real_T c1_nargin = 6.0;
  real_T c1_nargout = 5.0;
  real_T c1_q_des[7];
  real_T c1_dq_des[7];
  real_T c1_ddq_des[7];
  real_T c1_cur_status;
  real_T c1_A_out[28];
  int32_T c1_i25;
  real_T c1_b_q_in[7];
  int32_T c1_i26;
  int32_T c1_i27;
  real_T c1_b_i;
  real_T c1_b;
  real_T c1_y;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_c_b;
  real_T c1_c_y;
  int32_T c1_c_i;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_e_y;
  real_T c1_b_x;
  real_T c1_f_y;
  real_T c1_c_x;
  real_T c1_g_y;
  real_T c1_d0;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_e_b;
  real_T c1_h_y;
  real_T c1_f_b;
  real_T c1_i_y;
  real_T c1_g_b;
  real_T c1_j_y;
  real_T c1_h_b;
  real_T c1_k_y;
  real_T c1_i_b;
  real_T c1_l_y;
  real_T c1_j_b;
  real_T c1_m_y;
  int32_T c1_i28;
  real_T c1_a[28];
  int32_T c1_i29;
  real_T c1_k_b[4];
  int32_T c1_i30;
  real_T c1_b_A[28];
  int32_T c1_i31;
  real_T c1_b_B[4];
  int32_T c1_i32;
  int32_T c1_i33;
  real_T c1_c_A[28];
  int32_T c1_i34;
  real_T c1_c_B[4];
  int32_T c1_i35;
  real_T c1_d_A[28];
  int32_T c1_i36;
  real_T c1_d_B[4];
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  real_T c1_b_a[28];
  int32_T c1_i41;
  real_T c1_l_b[4];
  int32_T c1_i42;
  real_T c1_e_A[28];
  int32_T c1_i43;
  real_T c1_e_B[4];
  int32_T c1_i44;
  int32_T c1_i45;
  real_T c1_f_A[28];
  int32_T c1_i46;
  real_T c1_f_B[4];
  int32_T c1_i47;
  real_T c1_g_A[28];
  int32_T c1_i48;
  real_T c1_g_B[4];
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  real_T c1_c_a[28];
  int32_T c1_i53;
  real_T c1_m_b[4];
  int32_T c1_i54;
  real_T c1_h_A[28];
  int32_T c1_i55;
  real_T c1_h_B[4];
  int32_T c1_i56;
  int32_T c1_i57;
  real_T c1_i_A[28];
  int32_T c1_i58;
  real_T c1_i_B[4];
  int32_T c1_i59;
  real_T c1_j_A[28];
  int32_T c1_i60;
  real_T c1_j_B[4];
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  real_T c1_k_A;
  real_T c1_k_B;
  real_T c1_d_x;
  real_T c1_n_y;
  real_T c1_e_x;
  real_T c1_o_y;
  real_T c1_f_x;
  real_T c1_p_y;
  real_T c1_q_y;
  int32_T c1_i68;
  int32_T c1_i69;
  real_T c1_d_a[28];
  int32_T c1_i70;
  real_T c1_l_A[28];
  int32_T c1_i71;
  int32_T c1_i72;
  real_T c1_m_A[28];
  int32_T c1_i73;
  real_T c1_n_A[28];
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  real_T c1_e_a;
  real_T c1_n_b;
  real_T c1_r_y;
  real_T c1_o_A;
  real_T c1_l_B;
  real_T c1_g_x;
  real_T c1_s_y;
  real_T c1_h_x;
  real_T c1_t_y;
  real_T c1_i_x;
  real_T c1_u_y;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d5;
  real_T c1_o_b;
  real_T c1_v_y;
  real_T c1_p_b;
  real_T c1_w_y;
  real_T c1_q_b;
  real_T c1_x_y;
  real_T c1_r_b;
  real_T c1_y_y;
  real_T c1_s_b;
  real_T c1_ab_y;
  real_T c1_t_b;
  real_T c1_bb_y;
  int32_T c1_i83;
  real_T c1_f_a[28];
  int32_T c1_i84;
  real_T c1_u_b[4];
  int32_T c1_i85;
  real_T c1_p_A[28];
  int32_T c1_i86;
  real_T c1_m_B[4];
  int32_T c1_i87;
  int32_T c1_i88;
  real_T c1_q_A[28];
  int32_T c1_i89;
  real_T c1_n_B[4];
  int32_T c1_i90;
  real_T c1_r_A[28];
  int32_T c1_i91;
  real_T c1_o_B[4];
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  real_T c1_g_a[28];
  int32_T c1_i96;
  real_T c1_v_b[4];
  int32_T c1_i97;
  real_T c1_s_A[28];
  int32_T c1_i98;
  real_T c1_p_B[4];
  int32_T c1_i99;
  int32_T c1_i100;
  real_T c1_t_A[28];
  int32_T c1_i101;
  real_T c1_q_B[4];
  int32_T c1_i102;
  real_T c1_u_A[28];
  int32_T c1_i103;
  real_T c1_r_B[4];
  int32_T c1_i104;
  int32_T c1_i105;
  int32_T c1_i106;
  int32_T c1_i107;
  real_T c1_h_a[28];
  int32_T c1_i108;
  real_T c1_w_b[4];
  int32_T c1_i109;
  real_T c1_v_A[28];
  int32_T c1_i110;
  real_T c1_s_B[4];
  int32_T c1_i111;
  int32_T c1_i112;
  real_T c1_w_A[28];
  int32_T c1_i113;
  real_T c1_t_B[4];
  int32_T c1_i114;
  real_T c1_x_A[28];
  int32_T c1_i115;
  real_T c1_u_B[4];
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  int32_T c1_i119;
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  int32_T c1_i123;
  real_T *c1_b_status;
  real_T *c1_b_tspan;
  real_T *c1_b_dt;
  real_T *c1_b_cur_status;
  real_T (*c1_b_q_des)[7];
  real_T (*c1_b_dq_des)[7];
  real_T (*c1_b_ddq_des)[7];
  real_T (*c1_b_A_out)[28];
  real_T (*c1_b_A_in)[28];
  real_T (*c1_b_q_prev)[7];
  real_T (*c1_c_q_in)[7];
  c1_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_A_out = (real_T (*)[28])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_b_tspan = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_A_in = (real_T (*)[28])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_status = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_cur_status = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_q_prev = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_ddq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_dq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_q_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_c_q_in = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c1_i19 = 0; c1_i19 < 7; c1_i19 = c1_i19 + 1) {
    c1_hoistedGlobal[c1_i19] = (*c1_c_q_in)[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 7; c1_i20 = c1_i20 + 1) {
    c1_b_hoistedGlobal[c1_i20] = (*c1_b_q_prev)[c1_i20];
  }

  c1_c_hoistedGlobal = *c1_b_status;
  for (c1_i21 = 0; c1_i21 < 28; c1_i21 = c1_i21 + 1) {
    c1_d_hoistedGlobal[c1_i21] = (*c1_b_A_in)[c1_i21];
  }

  c1_e_hoistedGlobal = *c1_b_tspan;
  c1_f_hoistedGlobal = *c1_b_dt;
  for (c1_i22 = 0; c1_i22 < 7; c1_i22 = c1_i22 + 1) {
    c1_q_in[c1_i22] = c1_hoistedGlobal[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 7; c1_i23 = c1_i23 + 1) {
    c1_q_prev[c1_i23] = c1_b_hoistedGlobal[c1_i23];
  }

  c1_status = c1_c_hoistedGlobal;
  for (c1_i24 = 0; c1_i24 < 28; c1_i24 = c1_i24 + 1) {
    c1_A_in[c1_i24] = c1_d_hoistedGlobal[c1_i24];
  }

  c1_tspan = c1_e_hoistedGlobal;
  c1_dt = c1_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 20U, 20U, c1_sv0, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_N, c1_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_dx, c1_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_i, c1_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_cur_t, c1_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_T, c1_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_TT, c1_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_TTT, c1_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c1_q_in, c1_c_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c1_q_prev, c1_c_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c1_status, c1_b_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c1_A_in, c1_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c1_tspan, c1_b_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c1_dt, c1_b_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c1_q_des, c1_c_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c1_dq_des, c1_c_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c1_ddq_des, c1_c_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c1_cur_status, c1_b_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c1_A_out, c1_sf_marshall, 19U);
  CV_EML_FCN(0, 0);

  /*  5th Order Polynomial Planner */
  /*  Jason Pile */
  /*  Last Updated: 5/28/2011 */
  _SFD_EML_CALL(0,7);
  c1_N = 7.0;

  /*  Hard coded number of joints */
  /*  tspan=3;    % time to execute path plan (sec) */
  _SFD_EML_CALL(0,9);
  if (CV_EML_IF(0, 0, c1_status == 0.0)) {
    /*  no trajectory running */
    _SFD_EML_CALL(0,10);
    for (c1_i25 = 0; c1_i25 < 7; c1_i25 = c1_i25 + 1) {
      c1_b_q_in[c1_i25] = c1_q_in[c1_i25] - c1_q_prev[c1_i25];
    }

    if (CV_EML_IF(0, 1, c1_norm(chartInstance, c1_b_q_in) > 0.001)) {
      /*  must calculate new trajectory */
      _SFD_EML_CALL(0,11);
      for (c1_i26 = 0; c1_i26 < 7; c1_i26 = c1_i26 + 1) {
        c1_dx[c1_i26] = c1_q_in[c1_i26] - c1_q_prev[c1_i26];
      }

      /*  total displacement */
      _SFD_EML_CALL(0,12);
      for (c1_i27 = 0; c1_i27 < 28; c1_i27 = c1_i27 + 1) {
        c1_A_out[c1_i27] = 0.0;
      }

      /*  allocate memory for coefficients */
      /*  construct coefficients */
      c1_i = 1.0;
      c1_b_i = 1.0;
      while (c1_b_i <= 7.0) {
        c1_i = c1_b_i;
        CV_EML_FOR(0, 0, 1);
        _SFD_EML_CALL(0,15);
        c1_b = c1_dx[_SFD_EML_ARRAY_BOUNDS_CHECK("dx", (int32_T)
          _SFD_INTEGER_CHECK("i", c1_i), 1, 7, 1, 0) - 1];
        c1_y = 10.0 * c1_b;
        c1_b_b = c1_dx[_SFD_EML_ARRAY_BOUNDS_CHECK("dx", (int32_T)
          _SFD_INTEGER_CHECK("i", c1_i), 1, 7, 1, 0) - 1];
        c1_b_y = -15.0 * c1_b_b;
        c1_c_b = c1_dx[_SFD_EML_ARRAY_BOUNDS_CHECK("dx", (int32_T)
          _SFD_INTEGER_CHECK("i", c1_i), 1, 7, 1, 0) - 1];
        c1_c_y = 6.0 * c1_c_b;
        c1_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("A_out", (int32_T)
          _SFD_INTEGER_CHECK("i", c1_i), 1, 7, 1, 0) - 1;
        c1_A_out[c1_c_i] = c1_q_prev[_SFD_EML_ARRAY_BOUNDS_CHECK("q_prev",
          (int32_T)_SFD_INTEGER_CHECK("i", c1_i), 1, 7, 1, 0) - 1];
        c1_A_out[7 + c1_c_i] = c1_y;
        c1_A_out[c1_c_i + 14] = c1_b_y;
        c1_A_out[c1_c_i + 21] = c1_c_y;
        c1_b_i = c1_b_i + 1.0;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 0, 0);
      _SFD_EML_CALL(0,17);
      c1_cur_status = 1.0;
      _SFD_EML_CALL(0,18);
      c1_d_b = c1_dt;
      c1_d_y = c1_d_b;
      c1_A = c1_d_y;
      c1_B = c1_tspan;
      c1_x = c1_A;
      c1_e_y = c1_B;
      c1_b_x = c1_x;
      c1_f_y = c1_e_y;
      c1_c_x = c1_b_x;
      c1_g_y = c1_f_y;
      c1_cur_t = c1_c_x / c1_g_y;
      _SFD_EML_CALL(0,19);
      c1_d0 = c1_mpower(chartInstance, c1_cur_t);
      c1_d1 = c1_b_mpower(chartInstance, c1_cur_t);
      c1_d2 = c1_c_mpower(chartInstance, c1_cur_t);
      c1_T[0] = 1.0;
      c1_T[1] = c1_d0;
      c1_T[2] = c1_d1;
      c1_T[3] = c1_d2;

      /*  exponential time vector */
      _SFD_EML_CALL(0,20);
      c1_e_b = c1_d_mpower(chartInstance, c1_cur_t);
      c1_h_y = 3.0 * c1_e_b;
      c1_f_b = c1_mpower(chartInstance, c1_cur_t);
      c1_i_y = 4.0 * c1_f_b;
      c1_g_b = c1_b_mpower(chartInstance, c1_cur_t);
      c1_j_y = 5.0 * c1_g_b;
      c1_TT[0] = 0.0;
      c1_TT[1] = c1_h_y;
      c1_TT[2] = c1_i_y;
      c1_TT[3] = c1_j_y;

      /*  exponential time-velocity vector */
      _SFD_EML_CALL(0,21);
      c1_h_b = c1_cur_t;
      c1_k_y = 6.0 * c1_h_b;
      c1_i_b = c1_d_mpower(chartInstance, c1_cur_t);
      c1_l_y = 12.0 * c1_i_b;
      c1_j_b = c1_mpower(chartInstance, c1_cur_t);
      c1_m_y = 20.0 * c1_j_b;
      c1_TTT[0] = 0.0;
      c1_TTT[1] = c1_k_y;
      c1_TTT[2] = c1_l_y;
      c1_TTT[3] = c1_m_y;

      /*  exponential time-velocity vector */
      _SFD_EML_CALL(0,22);
      for (c1_i28 = 0; c1_i28 < 28; c1_i28 = c1_i28 + 1) {
        c1_a[c1_i28] = c1_A_out[c1_i28];
      }

      for (c1_i29 = 0; c1_i29 < 4; c1_i29 = c1_i29 + 1) {
        c1_k_b[c1_i29] = c1_T[c1_i29];
      }

      c1_b_eml_scalar_eg(chartInstance);
      c1_b_eml_scalar_eg(chartInstance);
      for (c1_i30 = 0; c1_i30 < 28; c1_i30 = c1_i30 + 1) {
        c1_b_A[c1_i30] = c1_a[c1_i30];
      }

      for (c1_i31 = 0; c1_i31 < 4; c1_i31 = c1_i31 + 1) {
        c1_b_B[c1_i31] = c1_k_b[c1_i31];
      }

      for (c1_i32 = 0; c1_i32 < 7; c1_i32 = c1_i32 + 1) {
        c1_q_des[c1_i32] = 0.0;
      }

      for (c1_i33 = 0; c1_i33 < 28; c1_i33 = c1_i33 + 1) {
        c1_c_A[c1_i33] = c1_b_A[c1_i33];
      }

      for (c1_i34 = 0; c1_i34 < 4; c1_i34 = c1_i34 + 1) {
        c1_c_B[c1_i34] = c1_b_B[c1_i34];
      }

      for (c1_i35 = 0; c1_i35 < 28; c1_i35 = c1_i35 + 1) {
        c1_d_A[c1_i35] = c1_c_A[c1_i35];
      }

      for (c1_i36 = 0; c1_i36 < 4; c1_i36 = c1_i36 + 1) {
        c1_d_B[c1_i36] = c1_c_B[c1_i36];
      }

      for (c1_i37 = 0; c1_i37 < 7; c1_i37 = c1_i37 + 1) {
        c1_q_des[c1_i37] = 0.0;
        c1_i38 = 0;
        for (c1_i39 = 0; c1_i39 < 4; c1_i39 = c1_i39 + 1) {
          c1_q_des[c1_i37] = c1_q_des[c1_i37] + c1_d_A[c1_i38 + c1_i37] *
            c1_d_B[c1_i39];
          c1_i38 = c1_i38 + 7;
        }
      }

      /*  current desired position  */
      _SFD_EML_CALL(0,23);
      for (c1_i40 = 0; c1_i40 < 28; c1_i40 = c1_i40 + 1) {
        c1_b_a[c1_i40] = c1_A_out[c1_i40];
      }

      for (c1_i41 = 0; c1_i41 < 4; c1_i41 = c1_i41 + 1) {
        c1_l_b[c1_i41] = c1_TT[c1_i41];
      }

      c1_b_eml_scalar_eg(chartInstance);
      c1_b_eml_scalar_eg(chartInstance);
      for (c1_i42 = 0; c1_i42 < 28; c1_i42 = c1_i42 + 1) {
        c1_e_A[c1_i42] = c1_b_a[c1_i42];
      }

      for (c1_i43 = 0; c1_i43 < 4; c1_i43 = c1_i43 + 1) {
        c1_e_B[c1_i43] = c1_l_b[c1_i43];
      }

      for (c1_i44 = 0; c1_i44 < 7; c1_i44 = c1_i44 + 1) {
        c1_dq_des[c1_i44] = 0.0;
      }

      for (c1_i45 = 0; c1_i45 < 28; c1_i45 = c1_i45 + 1) {
        c1_f_A[c1_i45] = c1_e_A[c1_i45];
      }

      for (c1_i46 = 0; c1_i46 < 4; c1_i46 = c1_i46 + 1) {
        c1_f_B[c1_i46] = c1_e_B[c1_i46];
      }

      for (c1_i47 = 0; c1_i47 < 28; c1_i47 = c1_i47 + 1) {
        c1_g_A[c1_i47] = c1_f_A[c1_i47];
      }

      for (c1_i48 = 0; c1_i48 < 4; c1_i48 = c1_i48 + 1) {
        c1_g_B[c1_i48] = c1_f_B[c1_i48];
      }

      for (c1_i49 = 0; c1_i49 < 7; c1_i49 = c1_i49 + 1) {
        c1_dq_des[c1_i49] = 0.0;
        c1_i50 = 0;
        for (c1_i51 = 0; c1_i51 < 4; c1_i51 = c1_i51 + 1) {
          c1_dq_des[c1_i49] = c1_dq_des[c1_i49] + c1_g_A[c1_i50 + c1_i49] *
            c1_g_B[c1_i51];
          c1_i50 = c1_i50 + 7;
        }
      }

      /*  current desired velocity */
      _SFD_EML_CALL(0,24);
      for (c1_i52 = 0; c1_i52 < 28; c1_i52 = c1_i52 + 1) {
        c1_c_a[c1_i52] = c1_A_out[c1_i52];
      }

      for (c1_i53 = 0; c1_i53 < 4; c1_i53 = c1_i53 + 1) {
        c1_m_b[c1_i53] = c1_TTT[c1_i53];
      }

      c1_b_eml_scalar_eg(chartInstance);
      c1_b_eml_scalar_eg(chartInstance);
      for (c1_i54 = 0; c1_i54 < 28; c1_i54 = c1_i54 + 1) {
        c1_h_A[c1_i54] = c1_c_a[c1_i54];
      }

      for (c1_i55 = 0; c1_i55 < 4; c1_i55 = c1_i55 + 1) {
        c1_h_B[c1_i55] = c1_m_b[c1_i55];
      }

      for (c1_i56 = 0; c1_i56 < 7; c1_i56 = c1_i56 + 1) {
        c1_ddq_des[c1_i56] = 0.0;
      }

      for (c1_i57 = 0; c1_i57 < 28; c1_i57 = c1_i57 + 1) {
        c1_i_A[c1_i57] = c1_h_A[c1_i57];
      }

      for (c1_i58 = 0; c1_i58 < 4; c1_i58 = c1_i58 + 1) {
        c1_i_B[c1_i58] = c1_h_B[c1_i58];
      }

      for (c1_i59 = 0; c1_i59 < 28; c1_i59 = c1_i59 + 1) {
        c1_j_A[c1_i59] = c1_i_A[c1_i59];
      }

      for (c1_i60 = 0; c1_i60 < 4; c1_i60 = c1_i60 + 1) {
        c1_j_B[c1_i60] = c1_i_B[c1_i60];
      }

      for (c1_i61 = 0; c1_i61 < 7; c1_i61 = c1_i61 + 1) {
        c1_ddq_des[c1_i61] = 0.0;
        c1_i62 = 0;
        for (c1_i63 = 0; c1_i63 < 4; c1_i63 = c1_i63 + 1) {
          c1_ddq_des[c1_i61] = c1_ddq_des[c1_i61] + c1_j_A[c1_i62 + c1_i61] *
            c1_j_B[c1_i63];
          c1_i62 = c1_i62 + 7;
        }
      }

      /* current desired acceleration */
    } else {
      /*  no new path needed */
      _SFD_EML_CALL(0,26);
      c1_cur_status = 0.0;
      _SFD_EML_CALL(0,27);
      for (c1_i64 = 0; c1_i64 < 28; c1_i64 = c1_i64 + 1) {
        c1_A_out[c1_i64] = c1_A_in[c1_i64];
      }

      _SFD_EML_CALL(0,28);
      for (c1_i65 = 0; c1_i65 < 7; c1_i65 = c1_i65 + 1) {
        c1_q_des[c1_i65] = c1_q_in[c1_i65];
      }

      /*  stay at commanded position   */
      _SFD_EML_CALL(0,29);
      for (c1_i66 = 0; c1_i66 < 7; c1_i66 = c1_i66 + 1) {
        c1_dq_des[c1_i66] = 0.0;
      }

      /*  zero velocity */
      _SFD_EML_CALL(0,30);
      for (c1_i67 = 0; c1_i67 < 7; c1_i67 = c1_i67 + 1) {
        c1_ddq_des[c1_i67] = 0.0;
      }

      /*  zero acceleration */
    }
  } else {
    /*  moving toward a goal position */
    _SFD_EML_CALL(0,33);
    c1_k_A = c1_tspan;
    c1_k_B = c1_dt;
    c1_d_x = c1_k_A;
    c1_n_y = c1_k_B;
    c1_e_x = c1_d_x;
    c1_o_y = c1_n_y;
    c1_f_x = c1_e_x;
    c1_p_y = c1_o_y;
    c1_q_y = c1_f_x / c1_p_y;
    if (CV_EML_IF(0, 2, c1_status >= c1_q_y)) {
      /*  reached position goal */
      _SFD_EML_CALL(0,34);
      for (c1_i68 = 0; c1_i68 < 4; c1_i68 = c1_i68 + 1) {
        c1_T[c1_i68] = 1.0;
      }

      _SFD_EML_CALL(0,35);
      for (c1_i69 = 0; c1_i69 < 28; c1_i69 = c1_i69 + 1) {
        c1_d_a[c1_i69] = c1_A_in[c1_i69];
      }

      c1_b_eml_scalar_eg(chartInstance);
      c1_b_eml_scalar_eg(chartInstance);
      for (c1_i70 = 0; c1_i70 < 28; c1_i70 = c1_i70 + 1) {
        c1_l_A[c1_i70] = c1_d_a[c1_i70];
      }

      for (c1_i71 = 0; c1_i71 < 7; c1_i71 = c1_i71 + 1) {
        c1_q_des[c1_i71] = 0.0;
      }

      for (c1_i72 = 0; c1_i72 < 28; c1_i72 = c1_i72 + 1) {
        c1_m_A[c1_i72] = c1_l_A[c1_i72];
      }

      for (c1_i73 = 0; c1_i73 < 28; c1_i73 = c1_i73 + 1) {
        c1_n_A[c1_i73] = c1_m_A[c1_i73];
      }

      for (c1_i74 = 0; c1_i74 < 7; c1_i74 = c1_i74 + 1) {
        c1_q_des[c1_i74] = 0.0;
        c1_i75 = 0;
        for (c1_i76 = 0; c1_i76 < 4; c1_i76 = c1_i76 + 1) {
          c1_q_des[c1_i74] = c1_q_des[c1_i74] + c1_n_A[c1_i75 + c1_i74];
          c1_i75 = c1_i75 + 7;
        }
      }

      _SFD_EML_CALL(0,36);
      for (c1_i77 = 0; c1_i77 < 7; c1_i77 = c1_i77 + 1) {
        c1_dq_des[c1_i77] = 0.0;
      }

      /*  zero velocity */
      _SFD_EML_CALL(0,37);
      for (c1_i78 = 0; c1_i78 < 7; c1_i78 = c1_i78 + 1) {
        c1_ddq_des[c1_i78] = 0.0;
      }

      /*  zero acceleration */
      _SFD_EML_CALL(0,38);
      c1_cur_status = 0.0;
      _SFD_EML_CALL(0,39);
      for (c1_i79 = 0; c1_i79 < 7; c1_i79 = c1_i79 + 1) {
        c1_A_out[c1_i79] = c1_q_des[c1_i79];
      }

      c1_i80 = 0;
      for (c1_i81 = 0; c1_i81 < 3; c1_i81 = c1_i81 + 1) {
        for (c1_i82 = 0; c1_i82 < 7; c1_i82 = c1_i82 + 1) {
          c1_A_out[(c1_i82 + c1_i80) + 7] = 0.0;
        }

        c1_i80 = c1_i80 + 7;
      }
    } else {
      /*  continue on the trajectory */
      _SFD_EML_CALL(0,41);
      c1_e_a = c1_status;
      c1_n_b = c1_dt;
      c1_r_y = c1_e_a * c1_n_b;
      c1_o_A = c1_r_y;
      c1_l_B = c1_tspan;
      c1_g_x = c1_o_A;
      c1_s_y = c1_l_B;
      c1_h_x = c1_g_x;
      c1_t_y = c1_s_y;
      c1_i_x = c1_h_x;
      c1_u_y = c1_t_y;
      c1_cur_t = c1_i_x / c1_u_y;

      /*  current normalized time [0 -> 1] */
      _SFD_EML_CALL(0,42);
      c1_d3 = c1_mpower(chartInstance, c1_cur_t);
      c1_d4 = c1_b_mpower(chartInstance, c1_cur_t);
      c1_d5 = c1_c_mpower(chartInstance, c1_cur_t);
      c1_T[0] = 1.0;
      c1_T[1] = c1_d3;
      c1_T[2] = c1_d4;
      c1_T[3] = c1_d5;

      /*  exponential time vector */
      _SFD_EML_CALL(0,43);
      c1_o_b = c1_d_mpower(chartInstance, c1_cur_t);
      c1_v_y = 3.0 * c1_o_b;
      c1_p_b = c1_mpower(chartInstance, c1_cur_t);
      c1_w_y = 4.0 * c1_p_b;
      c1_q_b = c1_b_mpower(chartInstance, c1_cur_t);
      c1_x_y = 5.0 * c1_q_b;
      c1_TT[0] = 0.0;
      c1_TT[1] = c1_v_y;
      c1_TT[2] = c1_w_y;
      c1_TT[3] = c1_x_y;

      /*  exponential time-velocity vector */
      _SFD_EML_CALL(0,44);
      c1_r_b = c1_cur_t;
      c1_y_y = 6.0 * c1_r_b;
      c1_s_b = c1_d_mpower(chartInstance, c1_cur_t);
      c1_ab_y = 12.0 * c1_s_b;
      c1_t_b = c1_mpower(chartInstance, c1_cur_t);
      c1_bb_y = 20.0 * c1_t_b;
      c1_TTT[0] = 0.0;
      c1_TTT[1] = c1_y_y;
      c1_TTT[2] = c1_ab_y;
      c1_TTT[3] = c1_bb_y;

      /*  exponential time-velocity vector */
      _SFD_EML_CALL(0,45);
      for (c1_i83 = 0; c1_i83 < 28; c1_i83 = c1_i83 + 1) {
        c1_f_a[c1_i83] = c1_A_in[c1_i83];
      }

      for (c1_i84 = 0; c1_i84 < 4; c1_i84 = c1_i84 + 1) {
        c1_u_b[c1_i84] = c1_T[c1_i84];
      }

      c1_b_eml_scalar_eg(chartInstance);
      c1_b_eml_scalar_eg(chartInstance);
      for (c1_i85 = 0; c1_i85 < 28; c1_i85 = c1_i85 + 1) {
        c1_p_A[c1_i85] = c1_f_a[c1_i85];
      }

      for (c1_i86 = 0; c1_i86 < 4; c1_i86 = c1_i86 + 1) {
        c1_m_B[c1_i86] = c1_u_b[c1_i86];
      }

      for (c1_i87 = 0; c1_i87 < 7; c1_i87 = c1_i87 + 1) {
        c1_q_des[c1_i87] = 0.0;
      }

      for (c1_i88 = 0; c1_i88 < 28; c1_i88 = c1_i88 + 1) {
        c1_q_A[c1_i88] = c1_p_A[c1_i88];
      }

      for (c1_i89 = 0; c1_i89 < 4; c1_i89 = c1_i89 + 1) {
        c1_n_B[c1_i89] = c1_m_B[c1_i89];
      }

      for (c1_i90 = 0; c1_i90 < 28; c1_i90 = c1_i90 + 1) {
        c1_r_A[c1_i90] = c1_q_A[c1_i90];
      }

      for (c1_i91 = 0; c1_i91 < 4; c1_i91 = c1_i91 + 1) {
        c1_o_B[c1_i91] = c1_n_B[c1_i91];
      }

      for (c1_i92 = 0; c1_i92 < 7; c1_i92 = c1_i92 + 1) {
        c1_q_des[c1_i92] = 0.0;
        c1_i93 = 0;
        for (c1_i94 = 0; c1_i94 < 4; c1_i94 = c1_i94 + 1) {
          c1_q_des[c1_i92] = c1_q_des[c1_i92] + c1_r_A[c1_i93 + c1_i92] *
            c1_o_B[c1_i94];
          c1_i93 = c1_i93 + 7;
        }
      }

      /*  current desired position */
      _SFD_EML_CALL(0,46);
      for (c1_i95 = 0; c1_i95 < 28; c1_i95 = c1_i95 + 1) {
        c1_g_a[c1_i95] = c1_A_in[c1_i95];
      }

      for (c1_i96 = 0; c1_i96 < 4; c1_i96 = c1_i96 + 1) {
        c1_v_b[c1_i96] = c1_TT[c1_i96];
      }

      c1_b_eml_scalar_eg(chartInstance);
      c1_b_eml_scalar_eg(chartInstance);
      for (c1_i97 = 0; c1_i97 < 28; c1_i97 = c1_i97 + 1) {
        c1_s_A[c1_i97] = c1_g_a[c1_i97];
      }

      for (c1_i98 = 0; c1_i98 < 4; c1_i98 = c1_i98 + 1) {
        c1_p_B[c1_i98] = c1_v_b[c1_i98];
      }

      for (c1_i99 = 0; c1_i99 < 7; c1_i99 = c1_i99 + 1) {
        c1_dq_des[c1_i99] = 0.0;
      }

      for (c1_i100 = 0; c1_i100 < 28; c1_i100 = c1_i100 + 1) {
        c1_t_A[c1_i100] = c1_s_A[c1_i100];
      }

      for (c1_i101 = 0; c1_i101 < 4; c1_i101 = c1_i101 + 1) {
        c1_q_B[c1_i101] = c1_p_B[c1_i101];
      }

      for (c1_i102 = 0; c1_i102 < 28; c1_i102 = c1_i102 + 1) {
        c1_u_A[c1_i102] = c1_t_A[c1_i102];
      }

      for (c1_i103 = 0; c1_i103 < 4; c1_i103 = c1_i103 + 1) {
        c1_r_B[c1_i103] = c1_q_B[c1_i103];
      }

      for (c1_i104 = 0; c1_i104 < 7; c1_i104 = c1_i104 + 1) {
        c1_dq_des[c1_i104] = 0.0;
        c1_i105 = 0;
        for (c1_i106 = 0; c1_i106 < 4; c1_i106 = c1_i106 + 1) {
          c1_dq_des[c1_i104] = c1_dq_des[c1_i104] + c1_u_A[c1_i105 + c1_i104] *
            c1_r_B[c1_i106];
          c1_i105 = c1_i105 + 7;
        }
      }

      /*  current desired velocity */
      _SFD_EML_CALL(0,47);
      for (c1_i107 = 0; c1_i107 < 28; c1_i107 = c1_i107 + 1) {
        c1_h_a[c1_i107] = c1_A_in[c1_i107];
      }

      for (c1_i108 = 0; c1_i108 < 4; c1_i108 = c1_i108 + 1) {
        c1_w_b[c1_i108] = c1_TTT[c1_i108];
      }

      c1_b_eml_scalar_eg(chartInstance);
      c1_b_eml_scalar_eg(chartInstance);
      for (c1_i109 = 0; c1_i109 < 28; c1_i109 = c1_i109 + 1) {
        c1_v_A[c1_i109] = c1_h_a[c1_i109];
      }

      for (c1_i110 = 0; c1_i110 < 4; c1_i110 = c1_i110 + 1) {
        c1_s_B[c1_i110] = c1_w_b[c1_i110];
      }

      for (c1_i111 = 0; c1_i111 < 7; c1_i111 = c1_i111 + 1) {
        c1_ddq_des[c1_i111] = 0.0;
      }

      for (c1_i112 = 0; c1_i112 < 28; c1_i112 = c1_i112 + 1) {
        c1_w_A[c1_i112] = c1_v_A[c1_i112];
      }

      for (c1_i113 = 0; c1_i113 < 4; c1_i113 = c1_i113 + 1) {
        c1_t_B[c1_i113] = c1_s_B[c1_i113];
      }

      for (c1_i114 = 0; c1_i114 < 28; c1_i114 = c1_i114 + 1) {
        c1_x_A[c1_i114] = c1_w_A[c1_i114];
      }

      for (c1_i115 = 0; c1_i115 < 4; c1_i115 = c1_i115 + 1) {
        c1_u_B[c1_i115] = c1_t_B[c1_i115];
      }

      for (c1_i116 = 0; c1_i116 < 7; c1_i116 = c1_i116 + 1) {
        c1_ddq_des[c1_i116] = 0.0;
        c1_i117 = 0;
        for (c1_i118 = 0; c1_i118 < 4; c1_i118 = c1_i118 + 1) {
          c1_ddq_des[c1_i116] = c1_ddq_des[c1_i116] + c1_x_A[c1_i117 + c1_i116] *
            c1_u_B[c1_i118];
          c1_i117 = c1_i117 + 7;
        }
      }

      /* current desired acceleration */
      _SFD_EML_CALL(0,48);
      c1_cur_status = c1_status + 1.0;

      /*  update status step */
      _SFD_EML_CALL(0,49);
      for (c1_i119 = 0; c1_i119 < 28; c1_i119 = c1_i119 + 1) {
        c1_A_out[c1_i119] = c1_A_in[c1_i119];
      }

      /*  maintain current coefficients         */
    }
  }

  _SFD_EML_CALL(0,-49);
  sf_debug_symbol_scope_pop();
  for (c1_i120 = 0; c1_i120 < 7; c1_i120 = c1_i120 + 1) {
    (*c1_b_q_des)[c1_i120] = c1_q_des[c1_i120];
  }

  for (c1_i121 = 0; c1_i121 < 7; c1_i121 = c1_i121 + 1) {
    (*c1_b_dq_des)[c1_i121] = c1_dq_des[c1_i121];
  }

  for (c1_i122 = 0; c1_i122 < 7; c1_i122 = c1_i122 + 1) {
    (*c1_b_ddq_des)[c1_i122] = c1_ddq_des[c1_i122];
  }

  *c1_b_cur_status = c1_cur_status;
  for (c1_i123 = 0; c1_i123 < 28; c1_i123 = c1_i123 + 1) {
    (*c1_b_A_out)[c1_i123] = c1_A_out[c1_i123];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static real_T c1_norm(SFc1_large_snakeInstanceStruct *chartInstance, real_T
                      c1_x[7])
{
  int32_T c1_i124;
  real_T c1_b_x[7];
  int32_T c1_i125;
  real_T c1_c_x[7];
  int32_T c1_i126;
  real_T c1_d_x[7];
  int32_T c1_i127;
  real_T c1_e_x[7];
  for (c1_i124 = 0; c1_i124 < 7; c1_i124 = c1_i124 + 1) {
    c1_b_x[c1_i124] = c1_x[c1_i124];
  }

  for (c1_i125 = 0; c1_i125 < 7; c1_i125 = c1_i125 + 1) {
    c1_c_x[c1_i125] = c1_b_x[c1_i125];
  }

  for (c1_i126 = 0; c1_i126 < 7; c1_i126 = c1_i126 + 1) {
    c1_d_x[c1_i126] = c1_c_x[c1_i126];
  }

  for (c1_i127 = 0; c1_i127 < 7; c1_i127 = c1_i127 + 1) {
    c1_e_x[c1_i127] = c1_d_x[c1_i127];
  }

  return c1_ceval_xnrm2(chartInstance, 7, c1_e_x, 1, 1);
}

static real_T c1_ceval_xnrm2(SFc1_large_snakeInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[7], int32_T c1_ix0, int32_T
  c1_incx)
{
  return dnrm232(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 7, 1, 0) - 1], &
                 c1_incx);
}

static real_T c1_mpower(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a)
{
  return c1_power(chartInstance, c1_a, 3.0);
}

static real_T c1_power(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a, real_T c1_b)
{
  real_T c1_ak;
  real_T c1_bk;
  real_T c1_x;
  real_T c1_b_x;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_a;
  c1_bk = c1_b;
  if (c1_ak < 0.0) {
    c1_x = c1_bk;
    c1_b_x = c1_x;
    c1_b_x = muDoubleScalarFloor(c1_b_x);
    if (c1_b_x != c1_bk) {
      c1_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c1_ak, c1_bk);
}

static void c1_eml_scalar_eg(SFc1_large_snakeInstanceStruct *chartInstance)
{
}

static void c1_eml_error(SFc1_large_snakeInstanceStruct *chartInstance)
{
  int32_T c1_i128;
  static char_T c1_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[32];
  const mxArray *c1_y = NULL;
  int32_T c1_i129;
  static char_T c1_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c1_b_u[102];
  const mxArray *c1_b_y = NULL;
  for (c1_i128 = 0; c1_i128 < 32; c1_i128 = c1_i128 + 1) {
    c1_u[c1_i128] = c1_cv0[c1_i128];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c1_i129 = 0; c1_i129 < 102; c1_i129 = c1_i129 + 1) {
    c1_b_u[c1_i129] = c1_cv1[c1_i129];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static real_T c1_b_mpower(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a)
{
  return c1_power(chartInstance, c1_a, 4.0);
}

static real_T c1_c_mpower(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a)
{
  return c1_power(chartInstance, c1_a, 5.0);
}

static real_T c1_d_mpower(SFc1_large_snakeInstanceStruct *chartInstance, real_T
  c1_a)
{
  return c1_power(chartInstance, c1_a, 2.0);
}

static void c1_b_eml_scalar_eg(SFc1_large_snakeInstanceStruct *chartInstance)
{
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i130;
  int32_T c1_i131;
  int32_T c1_i132;
  real_T c1_b_u[28];
  const mxArray *c1_b_y = NULL;
  SFc1_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc1_large_snakeInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i130 = 0;
  for (c1_i131 = 0; c1_i131 < 4; c1_i131 = c1_i131 + 1) {
    for (c1_i132 = 0; c1_i132 < 7; c1_i132 = c1_i132 + 1) {
      c1_b_u[c1_i132 + c1_i130] = (*((real_T (*)[28])c1_u))[c1_i132 + c1_i130];
    }

    c1_i130 = c1_i130 + 7;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 2, 7, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc1_large_snakeInstanceStruct *)chartInstanceVoid;
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
  int32_T c1_i133;
  real_T c1_b_u[7];
  const mxArray *c1_b_y = NULL;
  SFc1_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc1_large_snakeInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i133 = 0; c1_i133 < 7; c1_i133 = c1_i133 + 1) {
    c1_b_u[c1_i133] = (*((real_T (*)[7])c1_u))[c1_i133];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i134;
  real_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  SFc1_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc1_large_snakeInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i134 = 0; c1_i134 < 4; c1_i134 = c1_i134 + 1) {
    c1_b_u[c1_i134] = (*((real_T (*)[4])c1_u))[c1_i134];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[58];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i135;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 58));
  for (c1_i135 = 0; c1_i135 < 58; c1_i135 = c1_i135 + 1) {
    c1_r0 = &c1_info[c1_i135];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i135);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i135);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i135);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i135);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i135);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c1_i135);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c1_i135);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[58])
{
  c1_info[0].context = "";
  c1_info[0].name = "eq";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[B]eq";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "minus";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[B]minus";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "norm";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[2].fileLength = 5312U;
  c1_info[2].fileTime1 = 1262645476U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[3].name = "nargin";
  c1_info[3].dominantType = "";
  c1_info[3].resolved = "[B]nargin";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[4].name = "gt";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]gt";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[5].name = "isa";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]isa";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[6].name = "ndims";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]ndims";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[7].name = "le";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]le";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[8].name = "lt";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]lt";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[9].name = "size";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]size";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[10].name = "isempty";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]isempty";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[11].name = "isscalar";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[B]isscalar";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[12].name = "isvector";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]isvector";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[13].name = "eml_index_class";
  c1_info[13].dominantType = "";
  c1_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[13].fileLength = 909U;
  c1_info[13].fileTime1 = 1192491982U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[14].name = "ones";
  c1_info[14].dominantType = "char";
  c1_info[14].resolved = "[B]ones";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[15].name = "ischar";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[B]ischar";
  c1_info[15].fileLength = 0U;
  c1_info[15].fileTime1 = 0U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[16].name = "eml_xnrm2";
  c1_info[16].dominantType = "int32";
  c1_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[16].fileLength = 718U;
  c1_info[16].fileTime1 = 1209356056U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c1_info[17].name = "strcmp";
  c1_info[17].dominantType = "char";
  c1_info[17].resolved = "[B]strcmp";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[18].name = "cast";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]cast";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[19].name = "eml_refblas_xnrm2";
  c1_info[19].dominantType = "int32";
  c1_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[19].fileLength = 1433U;
  c1_info[19].fileTime1 = 1240287242U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[20].name = "class";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[B]class";
  c1_info[20].fileLength = 0U;
  c1_info[20].fileTime1 = 0U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[21].name = "zeros";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved = "[B]zeros";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[22].name = "true";
  c1_info[22].dominantType = "";
  c1_info[22].resolved = "[B]true";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[23].name = "eml_index_minus";
  c1_info[23].dominantType = "int32";
  c1_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[23].fileLength = 277U;
  c1_info[23].fileTime1 = 1192491984U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[24].name = "eml_index_times";
  c1_info[24].dominantType = "int32";
  c1_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[24].fileLength = 280U;
  c1_info[24].fileTime1 = 1192491986U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[25].name = "eml_index_plus";
  c1_info[25].dominantType = "int32";
  c1_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[25].fileLength = 272U;
  c1_info[25].fileTime1 = 1192491984U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[26].name = "real";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[B]real";
  c1_info[26].fileLength = 0U;
  c1_info[26].fileTime1 = 0U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[27].name = "ne";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[B]ne";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[28].name = "abs";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[28].fileLength = 566U;
  c1_info[28].fileTime1 = 1221292332U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[29].name = "islogical";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved = "[B]islogical";
  c1_info[29].fileLength = 0U;
  c1_info[29].fileTime1 = 0U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[30].name = "eml_scalar_abs";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[30].fileLength = 461U;
  c1_info[30].fileTime1 = 1203473160U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[31].name = "isinteger";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[B]isinteger";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[32].name = "isreal";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved = "[B]isreal";
  c1_info[32].fileLength = 0U;
  c1_info[32].fileTime1 = 0U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[33].name = "false";
  c1_info[33].dominantType = "";
  c1_info[33].resolved = "[B]false";
  c1_info[33].fileLength = 0U;
  c1_info[33].fileTime1 = 0U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[34].name = "times";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved = "[B]times";
  c1_info[34].fileLength = 0U;
  c1_info[34].fileTime1 = 0U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[35].name = "plus";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]plus";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[36].name = "imag";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]imag";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context = "";
  c1_info[37].name = "mtimes";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[37].fileLength = 3425U;
  c1_info[37].fileTime1 = 1250697966U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[38].name = "not";
  c1_info[38].dominantType = "logical";
  c1_info[38].resolved = "[B]not";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "";
  c1_info[39].name = "uminus";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved = "[B]uminus";
  c1_info[39].fileLength = 0U;
  c1_info[39].fileTime1 = 0U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "";
  c1_info[40].name = "mrdivide";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[40].fileLength = 800U;
  c1_info[40].fileTime1 = 1238459490U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[41].name = "ge";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved = "[B]ge";
  c1_info[41].fileLength = 0U;
  c1_info[41].fileTime1 = 0U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[42].name = "rdivide";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[42].fileLength = 403U;
  c1_info[42].fileTime1 = 1244760752U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[43].name = "eml_div";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[43].fileLength = 4269U;
  c1_info[43].fileTime1 = 1228119026U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context = "";
  c1_info[44].name = "mpower";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[44].fileLength = 3710U;
  c1_info[44].fileTime1 = 1238459488U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[45].name = "power";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[45].fileLength = 5380U;
  c1_info[45].fileTime1 = 1228119098U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[46].name = "eml_scalar_eg";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[46].fileLength = 3068U;
  c1_info[46].fileTime1 = 1240287210U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[47].name = "isstruct";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved = "[B]isstruct";
  c1_info[47].fileLength = 0U;
  c1_info[47].fileTime1 = 0U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[48].name = "eml_scalexp_alloc";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[48].fileLength = 808U;
  c1_info[48].fileTime1 = 1230519898U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[49].name = "eml_scalar_floor";
  c1_info[49].dominantType = "double";
  c1_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[49].fileLength = 260U;
  c1_info[49].fileTime1 = 1209355990U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[50].name = "eml_error";
  c1_info[50].dominantType = "char";
  c1_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[50].fileLength = 315U;
  c1_info[50].fileTime1 = 1213951944U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[51].name = "eml_xgemm";
  c1_info[51].dominantType = "int32";
  c1_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[51].fileLength = 3184U;
  c1_info[51].fileTime1 = 1209356052U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c1_info[52].name = "length";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[52].fileLength = 326U;
  c1_info[52].fileTime1 = 1226602474U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c1_info[53].name = "min";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[53].fileLength = 362U;
  c1_info[53].fileTime1 = 1244760752U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[54].name = "nargout";
  c1_info[54].dominantType = "";
  c1_info[54].resolved = "[B]nargout";
  c1_info[54].fileLength = 0U;
  c1_info[54].fileTime1 = 0U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[55].name = "eml_min_or_max";
  c1_info[55].dominantType = "char";
  c1_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[55].fileLength = 9969U;
  c1_info[55].fileTime1 = 1240287206U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[56].name = "isnumeric";
  c1_info[56].dominantType = "double";
  c1_info[56].resolved = "[B]isnumeric";
  c1_info[56].fileLength = 0U;
  c1_info[56].fileTime1 = 0U;
  c1_info[56].fileTime2 = 0U;
  c1_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[57].name = "eml_refblas_xgemm";
  c1_info[57].dominantType = "int32";
  c1_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[57].fileLength = 5748U;
  c1_info[57].fileTime1 = 1228119072U;
  c1_info[57].fileTime2 = 0U;
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc1_large_snakeInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static void c1_emlrt_marshallIn(SFc1_large_snakeInstanceStruct *chartInstance,
  const mxArray *c1_A_out, const char_T *c1_name,
  real_T c1_y[28])
{
  real_T c1_dv4[28];
  int32_T c1_i136;
  sf_mex_import(c1_name, sf_mex_dup(c1_A_out), &c1_dv4, 1, 0, 0U, 1, 0U, 2, 7, 4);
  for (c1_i136 = 0; c1_i136 < 28; c1_i136 = c1_i136 + 1) {
    c1_y[c1_i136] = c1_dv4[c1_i136];
  }

  sf_mex_destroy(&c1_A_out);
}

static real_T c1_b_emlrt_marshallIn(SFc1_large_snakeInstanceStruct
  *chartInstance, const mxArray *c1_cur_status, const char_T *
  c1_name)
{
  real_T c1_y;
  real_T c1_d6;
  sf_mex_import(c1_name, sf_mex_dup(c1_cur_status), &c1_d6, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d6;
  sf_mex_destroy(&c1_cur_status);
  return c1_y;
}

static void c1_c_emlrt_marshallIn(SFc1_large_snakeInstanceStruct *chartInstance,
  const mxArray *c1_ddq_des, const char_T *c1_name,
  real_T c1_y[7])
{
  real_T c1_dv5[7];
  int32_T c1_i137;
  sf_mex_import(c1_name, sf_mex_dup(c1_ddq_des), &c1_dv5, 1, 0, 0U, 1, 0U, 1, 7);
  for (c1_i137 = 0; c1_i137 < 7; c1_i137 = c1_i137 + 1) {
    c1_y[c1_i137] = c1_dv5[c1_i137];
  }

  sf_mex_destroy(&c1_ddq_des);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_large_snakeInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_large_snake,
  const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_is_active_c1_large_snake), &c1_u0, 1, 3,
                0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_is_active_c1_large_snake);
  return c1_y;
}

static void init_dsm_address_info(SFc1_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3715254461U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(381182150U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3437280188U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4190931502U);
}

mxArray *sf_c1_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1305230247U);
    pr[1] = (double)(1702080564U);
    pr[2] = (double)(3131875663U);
    pr[3] = (double)(1041968765U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
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
      pr[0] = (double)(7);
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
      pr[0] = (double)(7);
      pr[1] = (double)(4);
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
      pr[0] = (double)(7);
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
      pr[0] = (double)(7);
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
      pr[0] = (double)(7);
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
      pr[0] = (double)(7);
      pr[1] = (double)(4);
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

static mxArray *sf_get_sim_state_info_c1_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[10],T\"A_out\",},{M[1],M[7],T\"cur_status\",},{M[1],M[15],T\"ddq_des\",},{M[1],M[14],T\"dq_des\",},{M[1],M[5],T\"q_des\",},{M[8],M[0],T\"is_active_c1_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc1_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           1,
           1,
           1,
           11,
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
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_in",0,(MexFcnForType)c1_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_des",0,(MexFcnForType)c1_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"dq_des",0,(MexFcnForType)c1_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"ddq_des",0,(MexFcnForType)
                                c1_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_prev",0,(MexFcnForType)c1_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "cur_status",0,(MexFcnForType)c1_b_sf_marshall);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"status",
                              0,(MexFcnForType)c1_b_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 7;
            dimVector[1]= 4;
            _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"A_in",0,(MexFcnForType)c1_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tspan",0,
                              (MexFcnForType)c1_b_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 7;
            dimVector[1]= 4;
            _SFD_SET_DATA_PROPS(9,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"A_out",0,(MexFcnForType)c1_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dt",0,
                              (MexFcnForType)c1_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",71,-1,2383);
        _SFD_CV_INIT_EML_IF(0,0,276,290,1395,2379);
        _SFD_CV_INIT_EML_IF(0,1,323,351,1146,1390);
        _SFD_CV_INIT_EML_IF(0,2,1443,1464,1713,2371);
        _SFD_CV_INIT_EML_FOR(0,0,552,562,646);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c1_q_in)[7];
          real_T (*c1_q_des)[7];
          real_T (*c1_dq_des)[7];
          real_T (*c1_ddq_des)[7];
          real_T (*c1_q_prev)[7];
          real_T *c1_cur_status;
          real_T *c1_status;
          real_T (*c1_A_in)[28];
          real_T *c1_tspan;
          real_T (*c1_A_out)[28];
          real_T *c1_dt;
          c1_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_A_out = (real_T (*)[28])ssGetOutputPortSignal(chartInstance->S, 5);
          c1_tspan = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_A_in = (real_T (*)[28])ssGetInputPortSignal(chartInstance->S, 3);
          c1_status = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_cur_status = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_q_prev = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 1);
          c1_ddq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 3);
          c1_dq_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_q_des = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_q_in = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_q_in);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_q_des);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_dq_des);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_ddq_des);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_q_prev);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_cur_status);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_status);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_A_in);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_tspan);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_A_out);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_dt);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_large_snakeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_large_snake((SFc1_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c1_large_snake((SFc1_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_large_snake(void *chartInstanceVar)
{
  enable_c1_large_snake((SFc1_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_large_snake(void *chartInstanceVar)
{
  disable_c1_large_snake((SFc1_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_large_snake(void *chartInstanceVar)
{
  sf_c1_large_snake((SFc1_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c1_large_snake((SFc1_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_large_snake
    ((SFc1_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c1_large_snake(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_large_snake((SFc1_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_large_snake(S);
}

static void sf_opaque_set_sim_state_c1_large_snake(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_large_snake(S, st);
}

static void sf_opaque_terminate_c1_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_large_snake((SFc1_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_large_snake((SFc1_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c1_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",1,6);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",1,5);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1094191084U));
  ssSetChecksum1(S,(1519772706U));
  ssSetChecksum2(S,(2125257229U));
  ssSetChecksum3(S,(106995819U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_large_snake(SimStruct *S)
{
  SFc1_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc1_large_snakeInstanceStruct *)malloc(sizeof
    (SFc1_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_large_snake;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c1_large_snake;
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

void c1_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
