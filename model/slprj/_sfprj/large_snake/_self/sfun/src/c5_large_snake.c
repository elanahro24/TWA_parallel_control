/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c5_large_snake.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c5_debug_family_names[10] = { "k1", "q_seg1", "q_seg2_alone",
  "q_seg2", "q_insertion", "nargin", "nargout", "psi", "r", "q_des" };

/* Function Declarations */
static void initialize_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance);
static void enable_c5_large_snake(SFc5_large_snakeInstanceStruct *chartInstance);
static void disable_c5_large_snake(SFc5_large_snakeInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_large_snake
  (SFc5_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_large_snake
  (SFc5_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance);
static void sf_c5_large_snake(SFc5_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_d_sf_marshall(void *chartInstanceVoid, void *c5_u);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[21]);
static const mxArray *c5_e_sf_marshall(void *chartInstanceVoid, void *c5_u);
static void c5_emlrt_marshallIn(SFc5_large_snakeInstanceStruct *chartInstance,
  const mxArray *c5_q_des, const char_T *c5_name, real_T c5_y[9]);
static uint8_T c5_b_emlrt_marshallIn(SFc5_large_snakeInstanceStruct
  *chartInstance, const mxArray *c5_is_active_c5_large_snake, const char_T
  *c5_name);
static void init_dsm_address_info(SFc5_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c5_is_active_c5_large_snake;
  c5_is_active_c5_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c5_is_active_c5_large_snake = 0U;
}

static void initialize_params_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c5_large_snake(SFc5_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_large_snake(SFc5_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_large_snake
  (SFc5_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance)
{
  c5_update_debugger_state_c5_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c5_large_snake
  (SFc5_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c5_st = NULL;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_hoistedGlobal[9];
  int32_T c5_i1;
  real_T c5_u[9];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  uint8_T *c5_is_active_c5_large_snake;
  real_T (*c5_q_des)[9];
  c5_q_des = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_is_active_c5_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2));
  for (c5_i0 = 0; c5_i0 < 9; c5_i0 = c5_i0 + 1) {
    c5_hoistedGlobal[c5_i0] = (*c5_q_des)[c5_i0];
  }

  for (c5_i1 = 0; c5_i1 < 9; c5_i1 = c5_i1 + 1) {
    c5_u[c5_i1] = c5_hoistedGlobal[c5_i1];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 1U, 0U, 1, 9));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_is_active_c5_large_snake;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[9];
  int32_T c5_i2;
  boolean_T *c5_doneDoubleBufferReInit;
  uint8_T *c5_is_active_c5_large_snake;
  real_T (*c5_q_des)[9];
  c5_q_des = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_is_active_c5_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c5_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                      "q_des", c5_dv0);
  for (c5_i2 = 0; c5_i2 < 9; c5_i2 = c5_i2 + 1) {
    (*c5_q_des)[c5_i2] = c5_dv0[c5_i2];
  }

  *c5_is_active_c5_large_snake = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 1)), "is_active_c5_large_snake");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_large_snake(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_large_snake(SFc5_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c5_large_snake(SFc5_large_snakeInstanceStruct *chartInstance)
{
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_previousEvent;
  int32_T c5_i5;
  real_T c5_hoistedGlobal[7];
  real_T c5_b_hoistedGlobal;
  int32_T c5_i6;
  real_T c5_psi[7];
  real_T c5_r;
  uint32_T c5_debug_family_var_map[10];
  static const char *c5_sv0[10] = { "k1", "q_seg1", "q_seg2_alone", "q_seg2",
    "q_insertion", "nargin", "nargout", "psi", "r", "q_des"
  };

  real_T c5_k1;
  real_T c5_q_seg1[3];
  real_T c5_q_seg2_alone[3];
  real_T c5_q_seg2[3];
  real_T c5_q_insertion[3];
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  real_T c5_q_des[9];
  real_T c5_b;
  real_T c5_y;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_a;
  real_T c5_b_b;
  real_T c5_b_y;
  real_T c5_b_a;
  real_T c5_c_b;
  real_T c5_c_y;
  real_T c5_d_b;
  real_T c5_d_y;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_c_a;
  real_T c5_e_b;
  real_T c5_e_y;
  real_T c5_d_a;
  real_T c5_f_b;
  real_T c5_f_y;
  real_T c5_g_b;
  real_T c5_g_y;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_e_a;
  real_T c5_h_b;
  real_T c5_h_y;
  real_T c5_f_a;
  real_T c5_i_b;
  real_T c5_i_y;
  real_T c5_j_b;
  real_T c5_j_y;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_g_a;
  real_T c5_k_b;
  real_T c5_k_y;
  real_T c5_h_a;
  real_T c5_l_b;
  real_T c5_l_y;
  real_T c5_m_b;
  real_T c5_m_y;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_i_a;
  real_T c5_n_b;
  real_T c5_n_y;
  real_T c5_j_a;
  real_T c5_o_b;
  real_T c5_o_y;
  real_T c5_p_b;
  real_T c5_p_y;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_k_a;
  real_T c5_q_b;
  real_T c5_q_y;
  real_T c5_l_a;
  real_T c5_r_b;
  real_T c5_r_y;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  real_T *c5_b_r;
  real_T (*c5_b_q_des)[9];
  real_T (*c5_b_psi)[7];
  c5_b_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_q_des = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_psi = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,4);
  for (c5_i3 = 0; c5_i3 < 7; c5_i3 = c5_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_psi)[c5_i3], 0U);
  }

  for (c5_i4 = 0; c5_i4 < 9; c5_i4 = c5_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_q_des)[c5_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_b_r, 2U);
  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,4);
  for (c5_i5 = 0; c5_i5 < 7; c5_i5 = c5_i5 + 1) {
    c5_hoistedGlobal[c5_i5] = (*c5_b_psi)[c5_i5];
  }

  c5_b_hoistedGlobal = *c5_b_r;
  for (c5_i6 = 0; c5_i6 < 7; c5_i6 = c5_i6 + 1) {
    c5_psi[c5_i6] = c5_hoistedGlobal[c5_i6];
  }

  c5_r = c5_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c5_sv0, c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c5_k1, c5_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c5_q_seg1, c5_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c5_q_seg2_alone, c5_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c5_q_seg2, c5_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c5_q_insertion, c5_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c5_nargin, c5_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c5_nargout, c5_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c5_psi, c5_c_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c5_r, c5_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c5_q_des, c5_sf_marshall, 9U);
  CV_EML_FCN(0, 0);

  /*    1st segment */
  _SFD_EML_CALL(0,4);
  c5_k1 = 1.0;
  _SFD_EML_CALL(0,5);
  c5_b = c5_r;
  c5_y = c5_b;
  c5_x = c5_psi[1];
  c5_b_x = c5_x;
  c5_c_x = c5_b_x;
  c5_b_x = c5_c_x;
  c5_b_x = muDoubleScalarCos(c5_b_x);
  c5_a = c5_y;
  c5_b_b = c5_b_x;
  c5_b_y = c5_a * c5_b_b;
  c5_b_a = c5_b_y;
  c5_c_b = c5_psi[0] - 1.5707963267948966E+000;
  c5_c_y = c5_b_a * c5_c_b;
  c5_d_b = c5_r;
  c5_d_y = c5_d_b;
  c5_d_x = c5_psi[1] + 2.0943951023931953E+000;
  c5_e_x = c5_d_x;
  c5_f_x = c5_e_x;
  c5_e_x = c5_f_x;
  c5_e_x = muDoubleScalarCos(c5_e_x);
  c5_c_a = c5_d_y;
  c5_e_b = c5_e_x;
  c5_e_y = c5_c_a * c5_e_b;
  c5_d_a = c5_e_y;
  c5_f_b = c5_psi[0] - 1.5707963267948966E+000;
  c5_f_y = c5_d_a * c5_f_b;
  c5_g_b = c5_r;
  c5_g_y = c5_g_b;
  c5_g_x = c5_psi[1] + 4.1887902047863905E+000;
  c5_h_x = c5_g_x;
  c5_i_x = c5_h_x;
  c5_h_x = c5_i_x;
  c5_h_x = muDoubleScalarCos(c5_h_x);
  c5_e_a = c5_g_y;
  c5_h_b = c5_h_x;
  c5_h_y = c5_e_a * c5_h_b;
  c5_f_a = c5_h_y;
  c5_i_b = c5_psi[0] - 1.5707963267948966E+000;
  c5_i_y = c5_f_a * c5_i_b;
  c5_q_seg1[0] = c5_c_y;
  c5_q_seg1[1] = c5_f_y;
  c5_q_seg1[2] = c5_i_y;

  /*    2nd segment */
  _SFD_EML_CALL(0,10);
  c5_j_b = c5_r;
  c5_j_y = c5_j_b;
  c5_j_x = c5_psi[3];
  c5_k_x = c5_j_x;
  c5_l_x = c5_k_x;
  c5_k_x = c5_l_x;
  c5_k_x = muDoubleScalarCos(c5_k_x);
  c5_g_a = c5_j_y;
  c5_k_b = c5_k_x;
  c5_k_y = c5_g_a * c5_k_b;
  c5_h_a = c5_k_y;
  c5_l_b = c5_psi[2] - 1.5707963267948966E+000;
  c5_l_y = c5_h_a * c5_l_b;
  c5_m_b = c5_r;
  c5_m_y = c5_m_b;
  c5_m_x = c5_psi[3] + 2.0943951023931953E+000;
  c5_n_x = c5_m_x;
  c5_o_x = c5_n_x;
  c5_n_x = c5_o_x;
  c5_n_x = muDoubleScalarCos(c5_n_x);
  c5_i_a = c5_m_y;
  c5_n_b = c5_n_x;
  c5_n_y = c5_i_a * c5_n_b;
  c5_j_a = c5_n_y;
  c5_o_b = c5_psi[2] - 1.5707963267948966E+000;
  c5_o_y = c5_j_a * c5_o_b;
  c5_p_b = c5_r;
  c5_p_y = c5_p_b;
  c5_p_x = c5_psi[3] + 4.1887902047863905E+000;
  c5_q_x = c5_p_x;
  c5_r_x = c5_q_x;
  c5_q_x = c5_r_x;
  c5_q_x = muDoubleScalarCos(c5_q_x);
  c5_k_a = c5_p_y;
  c5_q_b = c5_q_x;
  c5_q_y = c5_k_a * c5_q_b;
  c5_l_a = c5_q_y;
  c5_r_b = c5_psi[2] - 1.5707963267948966E+000;
  c5_r_y = c5_l_a * c5_r_b;
  c5_q_seg2_alone[0] = c5_l_y;
  c5_q_seg2_alone[1] = c5_o_y;
  c5_q_seg2_alone[2] = c5_r_y;
  _SFD_EML_CALL(0,14);
  for (c5_i7 = 0; c5_i7 < 3; c5_i7 = c5_i7 + 1) {
    c5_q_seg2[c5_i7] = c5_q_seg2_alone[c5_i7] + c5_q_seg1[c5_i7];
  }

  _SFD_EML_CALL(0,15);
  for (c5_i8 = 0; c5_i8 < 3; c5_i8 = c5_i8 + 1) {
    c5_q_insertion[c5_i8] = c5_psi[c5_i8 + 4];
  }

  _SFD_EML_CALL(0,17);
  for (c5_i9 = 0; c5_i9 < 3; c5_i9 = c5_i9 + 1) {
    c5_q_des[c5_i9] = c5_q_seg1[c5_i9];
  }

  for (c5_i10 = 0; c5_i10 < 3; c5_i10 = c5_i10 + 1) {
    c5_q_des[c5_i10 + 3] = c5_q_seg2[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 3; c5_i11 = c5_i11 + 1) {
    c5_q_des[c5_i11 + 6] = c5_q_insertion[c5_i11];
  }

  _SFD_EML_CALL(0,-17);
  sf_debug_symbol_scope_pop();
  for (c5_i12 = 0; c5_i12 < 9; c5_i12 = c5_i12 + 1) {
    (*c5_b_q_des)[c5_i12] = c5_q_des[c5_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i13;
  real_T c5_b_u[9];
  const mxArray *c5_b_y = NULL;
  SFc5_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc5_large_snakeInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i13 = 0; c5_i13 < 9; c5_i13 = c5_i13 + 1) {
    c5_b_u[c5_i13] = (*((real_T (*)[9])c5_u))[c5_i13];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 1U, 0U, 1, 9));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc5_large_snakeInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i14;
  real_T c5_b_u[7];
  const mxArray *c5_b_y = NULL;
  SFc5_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc5_large_snakeInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i14 = 0; c5_i14 < 7; c5_i14 = c5_i14 + 1) {
    c5_b_u[c5_i14] = (*((real_T (*)[7])c5_u))[c5_i14];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_d_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i15;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  SFc5_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc5_large_snakeInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i15 = 0; c5_i15 < 3; c5_i15 = c5_i15 + 1) {
    c5_b_u[c5_i15] = (*((real_T (*)[3])c5_u))[c5_i15];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[21];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i16;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 21));
  for (c5_i16 = 0; c5_i16 < 21; c5_i16 = c5_i16 + 1) {
    c5_r0 = &c5_info[c5_i16];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
                    "nameCaptureInfo", c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name",
                    "nameCaptureInfo", c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i16
                    );
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i16
                    );
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[21])
{
  c5_info[0].context = "";
  c5_info[0].name = "mtimes";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[0].fileLength = 3425U;
  c5_info[0].fileTime1 = 1250697966U;
  c5_info[0].fileTime2 = 0U;
  c5_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[1].name = "nargin";
  c5_info[1].dominantType = "";
  c5_info[1].resolved = "[B]nargin";
  c5_info[1].fileLength = 0U;
  c5_info[1].fileTime1 = 0U;
  c5_info[1].fileTime2 = 0U;
  c5_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[2].name = "gt";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved = "[B]gt";
  c5_info[2].fileLength = 0U;
  c5_info[2].fileTime1 = 0U;
  c5_info[2].fileTime2 = 0U;
  c5_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[3].name = "isa";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[B]isa";
  c5_info[3].fileLength = 0U;
  c5_info[3].fileTime1 = 0U;
  c5_info[3].fileTime2 = 0U;
  c5_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[4].name = "isinteger";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved = "[B]isinteger";
  c5_info[4].fileLength = 0U;
  c5_info[4].fileTime1 = 0U;
  c5_info[4].fileTime2 = 0U;
  c5_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[5].name = "isscalar";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved = "[B]isscalar";
  c5_info[5].fileLength = 0U;
  c5_info[5].fileTime1 = 0U;
  c5_info[5].fileTime2 = 0U;
  c5_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[6].name = "strcmp";
  c5_info[6].dominantType = "char";
  c5_info[6].resolved = "[B]strcmp";
  c5_info[6].fileLength = 0U;
  c5_info[6].fileTime1 = 0U;
  c5_info[6].fileTime2 = 0U;
  c5_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[7].name = "size";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved = "[B]size";
  c5_info[7].fileLength = 0U;
  c5_info[7].fileTime1 = 0U;
  c5_info[7].fileTime2 = 0U;
  c5_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[8].name = "eq";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[B]eq";
  c5_info[8].fileLength = 0U;
  c5_info[8].fileTime1 = 0U;
  c5_info[8].fileTime2 = 0U;
  c5_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[9].name = "class";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved = "[B]class";
  c5_info[9].fileLength = 0U;
  c5_info[9].fileTime1 = 0U;
  c5_info[9].fileTime2 = 0U;
  c5_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[10].name = "not";
  c5_info[10].dominantType = "logical";
  c5_info[10].resolved = "[B]not";
  c5_info[10].fileLength = 0U;
  c5_info[10].fileTime1 = 0U;
  c5_info[10].fileTime2 = 0U;
  c5_info[11].context = "";
  c5_info[11].name = "cos";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[11].fileLength = 324U;
  c5_info[11].fileTime1 = 1203473150U;
  c5_info[11].fileTime2 = 0U;
  c5_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[12].name = "eml_scalar_cos";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c5_info[12].fileLength = 602U;
  c5_info[12].fileTime1 = 1209355986U;
  c5_info[12].fileTime2 = 0U;
  c5_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c5_info[13].name = "isreal";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved = "[B]isreal";
  c5_info[13].fileLength = 0U;
  c5_info[13].fileTime1 = 0U;
  c5_info[13].fileTime2 = 0U;
  c5_info[14].context = "";
  c5_info[14].name = "pi";
  c5_info[14].dominantType = "";
  c5_info[14].resolved = "[B]pi";
  c5_info[14].fileLength = 0U;
  c5_info[14].fileTime1 = 0U;
  c5_info[14].fileTime2 = 0U;
  c5_info[15].context = "";
  c5_info[15].name = "mrdivide";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[15].fileLength = 800U;
  c5_info[15].fileTime1 = 1238459490U;
  c5_info[15].fileTime2 = 0U;
  c5_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[16].name = "ge";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved = "[B]ge";
  c5_info[16].fileLength = 0U;
  c5_info[16].fileTime1 = 0U;
  c5_info[16].fileTime2 = 0U;
  c5_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[17].name = "rdivide";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[17].fileLength = 403U;
  c5_info[17].fileTime1 = 1244760752U;
  c5_info[17].fileTime2 = 0U;
  c5_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[18].name = "eml_div";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[18].fileLength = 4269U;
  c5_info[18].fileTime1 = 1228119026U;
  c5_info[18].fileTime2 = 0U;
  c5_info[19].context = "";
  c5_info[19].name = "minus";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved = "[B]minus";
  c5_info[19].fileLength = 0U;
  c5_info[19].fileTime1 = 0U;
  c5_info[19].fileTime2 = 0U;
  c5_info[20].context = "";
  c5_info[20].name = "plus";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved = "[B]plus";
  c5_info[20].fileLength = 0U;
  c5_info[20].fileTime1 = 0U;
  c5_info[20].fileTime2 = 0U;
}

static const mxArray *c5_e_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  boolean_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc5_large_snakeInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((boolean_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static void c5_emlrt_marshallIn(SFc5_large_snakeInstanceStruct *chartInstance,
  const mxArray *c5_q_des, const char_T *c5_name,
  real_T c5_y[9])
{
  real_T c5_dv1[9];
  int32_T c5_i17;
  sf_mex_import(c5_name, sf_mex_dup(c5_q_des), &c5_dv1, 1, 0, 0U, 1, 0U, 1, 9);
  for (c5_i17 = 0; c5_i17 < 9; c5_i17 = c5_i17 + 1) {
    c5_y[c5_i17] = c5_dv1[c5_i17];
  }

  sf_mex_destroy(&c5_q_des);
}

static uint8_T c5_b_emlrt_marshallIn(SFc5_large_snakeInstanceStruct
  *chartInstance, const mxArray *c5_is_active_c5_large_snake,
  const char_T *c5_name)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_name, sf_mex_dup(c5_is_active_c5_large_snake), &c5_u0, 1, 3,
                0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_is_active_c5_large_snake);
  return c5_y;
}

static void init_dsm_address_info(SFc5_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(76463973U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(679197803U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3542272663U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(691038258U);
}

mxArray *sf_c5_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1189080628U);
    pr[1] = (double)(2855955685U);
    pr[2] = (double)(2509027765U);
    pr[3] = (double)(296605995U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

static mxArray *sf_get_sim_state_info_c5_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"q_des\",},{M[8],M[0],T\"is_active_c5_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc5_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           5,
           1,
           1,
           3,
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
                                1.0,0,"psi",0,(MexFcnForType)c5_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 9;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_des",0,(MexFcnForType)c5_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"r",0,
                              (MexFcnForType)c5_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,447);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c5_psi)[7];
          real_T (*c5_q_des)[9];
          real_T *c5_r;
          c5_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_q_des = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_psi = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_psi);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_q_des);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_r);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_large_snakeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c5_large_snake((SFc5_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c5_large_snake((SFc5_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_large_snake(void *chartInstanceVar)
{
  enable_c5_large_snake((SFc5_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_large_snake(void *chartInstanceVar)
{
  disable_c5_large_snake((SFc5_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_large_snake(void *chartInstanceVar)
{
  sf_c5_large_snake((SFc5_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c5_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c5_large_snake((SFc5_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c5_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_large_snake
    ((SFc5_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c5_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c5_large_snake(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_large_snake((SFc5_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c5_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_large_snake(S);
}

static void sf_opaque_set_sim_state_c5_large_snake(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_large_snake(S, st);
}

static void sf_opaque_terminate_c5_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_large_snake((SFc5_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_large_snake((SFc5_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c5_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",5,2);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",5,1);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(689231500U));
  ssSetChecksum1(S,(2384493603U));
  ssSetChecksum2(S,(3016132071U));
  ssSetChecksum3(S,(3080817415U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_large_snake(SimStruct *S)
{
  SFc5_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc5_large_snakeInstanceStruct *)malloc(sizeof
    (SFc5_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_large_snake;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c5_large_snake;
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

void c5_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
