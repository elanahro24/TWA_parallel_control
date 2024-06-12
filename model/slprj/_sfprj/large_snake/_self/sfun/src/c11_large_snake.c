/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c11_large_snake.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c11_debug_family_names[8] = { "unusedU0", "nargin", "nargout",
  "psi", "qs", "r", "L", "q_wire_pos" };

static const char *c11_b_debug_family_names[6] = { "k1", "nargin", "nargout",
  "psi", "r", "q" };

static const char *c11_c_debug_family_names[11] = { "rho", "theta_s", "dq_wires",
  "nargin", "nargout", "psi", "qs", "r", "L", "q_wire_position", "l_wires" };

/* Function Declarations */
static void initialize_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance);
static void enable_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance);
static void disable_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance);
static void c11_update_debugger_state_c11_large_snake
  (SFc11_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c11_large_snake
  (SFc11_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance, const mxArray *c11_st);
static void finalize_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance);
static void sf_c11_large_snake(SFc11_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_b_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_c_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_d_sf_marshall(void *chartInstanceVoid, void *c11_u);
static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[24]);
static const mxArray *c11_e_sf_marshall(void *chartInstanceVoid, void *c11_u);
static void c11_emlrt_marshallIn(SFc11_large_snakeInstanceStruct *chartInstance,
  const mxArray *c11_q_wire_pos, const char_T *c11_name, real_T c11_y[3]);
static uint8_T c11_b_emlrt_marshallIn(SFc11_large_snakeInstanceStruct
  *chartInstance, const mxArray *c11_is_active_c11_large_snake, const char_T
  *c11_name);
static void init_dsm_address_info(SFc11_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c11_is_active_c11_large_snake;
  c11_is_active_c11_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c11_is_active_c11_large_snake = 0U;
}

static void initialize_params_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_large_snake
  (SFc11_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance)
{
  c11_update_debugger_state_c11_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c11_large_snake
  (SFc11_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c11_st = NULL;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_hoistedGlobal[3];
  int32_T c11_i1;
  real_T c11_u[3];
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  uint8_T *c11_is_active_c11_large_snake;
  real_T (*c11_q_wire_pos)[3];
  c11_q_wire_pos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_is_active_c11_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2));
  for (c11_i0 = 0; c11_i0 < 3; c11_i0 = c11_i0 + 1) {
    c11_hoistedGlobal[c11_i0] = (*c11_q_wire_pos)[c11_i0];
  }

  for (c11_i1 = 0; c11_i1 < 3; c11_i1 = c11_i1 + 1) {
    c11_u[c11_i1] = c11_hoistedGlobal[c11_i1];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = *c11_is_active_c11_large_snake;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y);
  return c11_st;
}

static void set_sim_state_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[3];
  int32_T c11_i2;
  boolean_T *c11_doneDoubleBufferReInit;
  uint8_T *c11_is_active_c11_large_snake;
  real_T (*c11_q_wire_pos)[3];
  c11_q_wire_pos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_is_active_c11_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c11_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
                       "q_wire_pos", c11_dv0);
  for (c11_i2 = 0; c11_i2 < 3; c11_i2 = c11_i2 + 1) {
    (*c11_q_wire_pos)[c11_i2] = c11_dv0[c11_i2];
  }

  *c11_is_active_c11_large_snake = c11_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "is_active_c11_large_snake");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_large_snake(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_large_snake(SFc11_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c11_large_snake(SFc11_large_snakeInstanceStruct *chartInstance)
{
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_previousEvent;
  int32_T c11_i5;
  real_T c11_hoistedGlobal[2];
  real_T c11_b_hoistedGlobal;
  real_T c11_c_hoistedGlobal;
  real_T c11_d_hoistedGlobal;
  int32_T c11_i6;
  real_T c11_psi[2];
  real_T c11_qs;
  real_T c11_r;
  real_T c11_L;
  uint32_T c11_debug_family_var_map[8];
  static const char *c11_sv0[8] = { "unusedU0", "nargin", "nargout", "psi", "qs",
    "r", "L", "q_wire_pos" };

  real_T c11_unusedU0[3];
  real_T c11_b_unusedU0;
  real_T c11_nargin = 4.0;
  real_T c11_nargout = 1.0;
  real_T c11_q_wire_pos[3];
  int32_T c11_i7;
  real_T c11_b_psi[2];
  real_T c11_b_qs;
  real_T c11_b_r;
  real_T c11_b_L;
  uint32_T c11_b_debug_family_var_map[11];
  static const char *c11_sv1[11] = { "rho", "theta_s", "dq_wires", "nargin",
    "nargout", "psi", "qs", "r", "L", "q_wire_position",
    "l_wires" };

  real_T c11_rho;
  real_T c11_theta_s;
  real_T c11_dq_wires[3];
  real_T c11_b_nargin = 4.0;
  real_T c11_b_nargout = 2.0;
  real_T c11_b_q_wire_pos[3];
  real_T c11_c_unusedU0[3];
  real_T c11_A;
  real_T c11_B;
  real_T c11_x;
  real_T c11_y;
  real_T c11_b_x;
  real_T c11_b_y;
  real_T c11_c_x;
  real_T c11_c_y;
  real_T c11_b_A;
  real_T c11_b_B;
  real_T c11_d_x;
  real_T c11_d_y;
  real_T c11_e_x;
  real_T c11_e_y;
  real_T c11_f_x;
  real_T c11_f_y;
  real_T c11_g_y;
  real_T c11_c_psi[2];
  real_T c11_c_r;
  uint32_T c11_c_debug_family_var_map[6];
  static const char *c11_sv2[6] = { "k1", "nargin", "nargout", "psi", "r", "q" };

  real_T c11_k1;
  real_T c11_c_nargin = 2.0;
  real_T c11_c_nargout = 1.0;
  real_T c11_b;
  real_T c11_h_y;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_a;
  real_T c11_b_b;
  real_T c11_i_y;
  real_T c11_b_a;
  real_T c11_c_b;
  real_T c11_j_y;
  real_T c11_d_b;
  real_T c11_k_y;
  real_T c11_j_x;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_c_a;
  real_T c11_e_b;
  real_T c11_l_y;
  real_T c11_d_a;
  real_T c11_f_b;
  real_T c11_m_y;
  real_T c11_g_b;
  real_T c11_n_y;
  real_T c11_m_x;
  real_T c11_n_x;
  real_T c11_o_x;
  real_T c11_e_a;
  real_T c11_h_b;
  real_T c11_o_y;
  real_T c11_f_a;
  real_T c11_i_b;
  real_T c11_p_y;
  int32_T c11_i8;
  real_T c11_j_b;
  int32_T c11_i9;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  real_T *c11_c_qs;
  real_T *c11_d_r;
  real_T *c11_c_L;
  real_T (*c11_c_q_wire_pos)[3];
  real_T (*c11_d_psi)[2];
  c11_c_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c11_d_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_c_qs = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_c_q_wire_pos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_d_psi = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,10);
  for (c11_i3 = 0; c11_i3 < 2; c11_i3 = c11_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_d_psi)[c11_i3], 0U);
  }

  for (c11_i4 = 0; c11_i4 < 3; c11_i4 = c11_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_c_q_wire_pos)[c11_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c11_c_qs, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_d_r, 3U);
  _SFD_DATA_RANGE_CHECK(*c11_c_L, 4U);
  c11_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,10);
  for (c11_i5 = 0; c11_i5 < 2; c11_i5 = c11_i5 + 1) {
    c11_hoistedGlobal[c11_i5] = (*c11_d_psi)[c11_i5];
  }

  c11_b_hoistedGlobal = *c11_c_qs;
  c11_c_hoistedGlobal = *c11_d_r;
  c11_d_hoistedGlobal = *c11_c_L;
  for (c11_i6 = 0; c11_i6 < 2; c11_i6 = c11_i6 + 1) {
    c11_psi[c11_i6] = c11_hoistedGlobal[c11_i6];
  }

  c11_qs = c11_b_hoistedGlobal;
  c11_r = c11_c_hoistedGlobal;
  c11_L = c11_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 9U, c11_sv0, c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c11_unusedU0, c11_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(&c11_b_unusedU0, c11_b_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c11_psi, c11_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c11_qs, c11_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c11_r, c11_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c11_L, c11_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c11_q_wire_pos, c11_sf_marshall, 7U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  for (c11_i7 = 0; c11_i7 < 2; c11_i7 = c11_i7 + 1) {
    c11_b_psi[c11_i7] = c11_psi[c11_i7];
  }

  c11_b_qs = c11_qs;
  c11_b_r = c11_r;
  c11_b_L = c11_L;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c11_sv1,
    c11_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c11_rho, c11_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c11_theta_s, c11_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c11_dq_wires, c11_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c11_b_nargin, c11_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c11_b_nargout, c11_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c11_b_psi, c11_c_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c11_b_qs, c11_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c11_b_r, c11_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c11_b_L, c11_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c11_b_q_wire_pos, c11_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c11_c_unusedU0, c11_sf_marshall, 10U);
  CV_SCRIPT_FCN(0, 0);

  /* %  Wire insertion coordination */
  /*    By Long Wang, 2017/2/9 */
  /*    This func calcuates the wire insertion coordination */
  /* %  Inputs */
  /*    psi - [theta, delta] for one segment */
  /*    qs - imaginary insertion distance on the central backbone */
  /*    r - the constant apart distance secondary backbones and central */
  /*    L - the length of the snake segment */
  /* %  Outputs */
  /*    l_wires - the length(s) of inserted wires */
  /*    q_wire_position - the joint position(s) of the inserted wires */
  /*    Note that l_wires is differnet from q_wire_position because: */
  /*    The home positions of wires are defined such that: */
  /*        1) all wires are fully inserted in the 1st segment. */
  /*        2) the snake segment is straight. */
  /*    i.e. q_wire_position = l_wires - [L,L,L] */
  /*    i.e. when fully inserted, q_wire_position = [0;0;0]; */
  /*    i.e. when not inserted, q_wire_position = [-L,-L,-L]; */
  _SFD_SCRIPT_CALL(0,21);
  if (CV_SCRIPT_IF(0, 0, 1.5707963267948966E+000 - c11_b_psi[0] > 1.0E-006)) {
    _SFD_SCRIPT_CALL(0,22);
    c11_A = c11_b_L;
    c11_B = 1.5707963267948966E+000 - c11_b_psi[0];
    c11_x = c11_A;
    c11_y = c11_B;
    c11_b_x = c11_x;
    c11_b_y = c11_y;
    c11_c_x = c11_b_x;
    c11_c_y = c11_b_y;
    c11_rho = c11_c_x / c11_c_y;
    _SFD_SCRIPT_CALL(0,23);
    c11_b_A = c11_b_qs;
    c11_b_B = c11_rho;
    c11_d_x = c11_b_A;
    c11_d_y = c11_b_B;
    c11_e_x = c11_d_x;
    c11_e_y = c11_d_y;
    c11_f_x = c11_e_x;
    c11_f_y = c11_e_y;
    c11_g_y = c11_f_x / c11_f_y;
    c11_theta_s = 1.5707963267948966E+000 - c11_g_y;
    _SFD_SCRIPT_CALL(0,24);
    c11_c_psi[0] = c11_theta_s;
    c11_c_psi[1] = c11_b_psi[1];
    c11_c_r = c11_b_r;
    sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c11_sv2,
      c11_c_debug_family_var_map);
    sf_debug_symbol_scope_add_eml(&c11_k1, c11_b_sf_marshall, 0U);
    sf_debug_symbol_scope_add_eml(&c11_c_nargin, c11_b_sf_marshall, 1U);
    sf_debug_symbol_scope_add_eml(&c11_c_nargout, c11_b_sf_marshall, 2U);
    sf_debug_symbol_scope_add_eml(&c11_c_psi, c11_d_sf_marshall, 3U);
    sf_debug_symbol_scope_add_eml(&c11_c_r, c11_b_sf_marshall, 4U);
    sf_debug_symbol_scope_add_eml(&c11_dq_wires, c11_sf_marshall, 5U);
    CV_SCRIPT_FCN(1, 0);

    /* %  By Long Wang, kinematic func */
    /*    for now only first segment, 3 backbones */
    /*    note that this has to be consistent with large_snake/Trajectory */
    /*    Planner/Inverse Kinematics */
    _SFD_SCRIPT_CALL(1,7);
    c11_k1 = 1.0;
    _SFD_SCRIPT_CALL(1,8);
    c11_b = c11_c_r;
    c11_h_y = c11_b;
    c11_g_x = c11_c_psi[1];
    c11_h_x = c11_g_x;
    c11_i_x = c11_h_x;
    c11_h_x = c11_i_x;
    c11_h_x = muDoubleScalarCos(c11_h_x);
    c11_a = c11_h_y;
    c11_b_b = c11_h_x;
    c11_i_y = c11_a * c11_b_b;
    c11_b_a = c11_i_y;
    c11_c_b = c11_c_psi[0] - 1.5707963267948966E+000;
    c11_j_y = c11_b_a * c11_c_b;
    c11_d_b = c11_c_r;
    c11_k_y = c11_d_b;
    c11_j_x = c11_c_psi[1] + 2.0943951023931953E+000;
    c11_k_x = c11_j_x;
    c11_l_x = c11_k_x;
    c11_k_x = c11_l_x;
    c11_k_x = muDoubleScalarCos(c11_k_x);
    c11_c_a = c11_k_y;
    c11_e_b = c11_k_x;
    c11_l_y = c11_c_a * c11_e_b;
    c11_d_a = c11_l_y;
    c11_f_b = c11_c_psi[0] - 1.5707963267948966E+000;
    c11_m_y = c11_d_a * c11_f_b;
    c11_g_b = c11_c_r;
    c11_n_y = c11_g_b;
    c11_m_x = c11_c_psi[1] + 4.1887902047863905E+000;
    c11_n_x = c11_m_x;
    c11_o_x = c11_n_x;
    c11_n_x = c11_o_x;
    c11_n_x = muDoubleScalarCos(c11_n_x);
    c11_e_a = c11_n_y;
    c11_h_b = c11_n_x;
    c11_o_y = c11_e_a * c11_h_b;
    c11_f_a = c11_o_y;
    c11_i_b = c11_c_psi[0] - 1.5707963267948966E+000;
    c11_p_y = c11_f_a * c11_i_b;
    c11_dq_wires[0] = c11_j_y;
    c11_dq_wires[1] = c11_m_y;
    c11_dq_wires[2] = c11_p_y;
    _SFD_SCRIPT_CALL(1,-8);
    sf_debug_symbol_scope_pop();
    _SFD_SCRIPT_CALL(0,25);
    for (c11_i8 = 0; c11_i8 < 3; c11_i8 = c11_i8 + 1) {
      c11_c_unusedU0[c11_i8] = c11_b_qs + c11_dq_wires[c11_i8];
    }
  } else {
    _SFD_SCRIPT_CALL(0,27);
    c11_j_b = c11_b_qs;
    for (c11_i9 = 0; c11_i9 < 3; c11_i9 = c11_i9 + 1) {
      c11_c_unusedU0[c11_i9] = c11_j_b;
    }
  }

  _SFD_SCRIPT_CALL(0,29);
  for (c11_i10 = 0; c11_i10 < 3; c11_i10 = c11_i10 + 1) {
    c11_b_q_wire_pos[c11_i10] = c11_c_unusedU0[c11_i10] - c11_b_L;
  }

  _SFD_SCRIPT_CALL(0,-29);
  sf_debug_symbol_scope_pop();
  for (c11_i11 = 0; c11_i11 < 3; c11_i11 = c11_i11 + 1) {
    c11_q_wire_pos[c11_i11] = c11_b_q_wire_pos[c11_i11];
  }

  for (c11_i12 = 0; c11_i12 < 3; c11_i12 = c11_i12 + 1) {
    c11_unusedU0[c11_i12] = c11_c_unusedU0[c11_i12];
  }

  sf_debug_symbol_switch(0U, 0U);
  _SFD_EML_CALL(0,3);
  c11_b_unusedU0 = 0.0;
  sf_debug_symbol_switch(0U, 1U);
  _SFD_EML_CALL(0,-3);
  sf_debug_symbol_scope_pop();
  for (c11_i13 = 0; c11_i13 < 3; c11_i13 = c11_i13 + 1) {
    (*c11_c_q_wire_pos)[c11_i13] = c11_q_wire_pos[c11_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
  _sfEvent_ = c11_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/wire_insertion_coordination.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 1U, sf_debug_get_script_id(
    "C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/BS_config_invkin.m"));
}

static const mxArray *c11_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i14;
  real_T c11_b_u[3];
  const mxArray *c11_b_y = NULL;
  SFc11_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc11_large_snakeInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i14 = 0; c11_i14 < 3; c11_i14 = c11_i14 + 1) {
    c11_b_u[c11_i14] = (*((real_T (*)[3])c11_u))[c11_i14];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_b_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  SFc11_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc11_large_snakeInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_b_u = *((real_T *)c11_u);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_c_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i15;
  real_T c11_b_u[2];
  const mxArray *c11_b_y = NULL;
  SFc11_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc11_large_snakeInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i15 = 0; c11_i15 < 2; c11_i15 = c11_i15 + 1) {
    c11_b_u[c11_i15] = (*((real_T (*)[2])c11_u))[c11_i15];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_d_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i16;
  real_T c11_b_u[2];
  const mxArray *c11_b_y = NULL;
  SFc11_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc11_large_snakeInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i16 = 0; c11_i16 < 2; c11_i16 = c11_i16 + 1) {
    c11_b_u[c11_i16] = (*((real_T (*)[2])c11_u))[c11_i16];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

const mxArray *sf_c11_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_ResolvedFunctionInfo c11_info[24];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i17;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 24));
  for (c11_i17 = 0; c11_i17 < 24; c11_i17 = c11_i17 + 1) {
    c11_r0 = &c11_info[c11_i17];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context"
                    , "nameCaptureInfo", c11_i17);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name",
                    "nameCaptureInfo", c11_i17);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i17);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)),
                    "resolved", "nameCaptureInfo", c11_i17);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c11_i17);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c11_i17);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c11_i17);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[24])
{
  c11_info[0].context = "";
  c11_info[0].name = "wire_insertion_coordination";
  c11_info[0].dominantType = "double";
  c11_info[0].resolved =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/wire_insertion_coordination.m";
  c11_info[0].fileLength = 1161U;
  c11_info[0].fileTime1 = 1509484509U;
  c11_info[0].fileTime2 = 0U;
  c11_info[1].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/wire_insertion_coordination.m";
  c11_info[1].name = "pi";
  c11_info[1].dominantType = "";
  c11_info[1].resolved = "[B]pi";
  c11_info[1].fileLength = 0U;
  c11_info[1].fileTime1 = 0U;
  c11_info[1].fileTime2 = 0U;
  c11_info[2].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/wire_insertion_coordination.m";
  c11_info[2].name = "mrdivide";
  c11_info[2].dominantType = "double";
  c11_info[2].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[2].fileLength = 800U;
  c11_info[2].fileTime1 = 1238459490U;
  c11_info[2].fileTime2 = 0U;
  c11_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[3].name = "nargin";
  c11_info[3].dominantType = "";
  c11_info[3].resolved = "[B]nargin";
  c11_info[3].fileLength = 0U;
  c11_info[3].fileTime1 = 0U;
  c11_info[3].fileTime2 = 0U;
  c11_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[4].name = "ge";
  c11_info[4].dominantType = "double";
  c11_info[4].resolved = "[B]ge";
  c11_info[4].fileLength = 0U;
  c11_info[4].fileTime1 = 0U;
  c11_info[4].fileTime2 = 0U;
  c11_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[5].name = "isscalar";
  c11_info[5].dominantType = "double";
  c11_info[5].resolved = "[B]isscalar";
  c11_info[5].fileLength = 0U;
  c11_info[5].fileTime1 = 0U;
  c11_info[5].fileTime2 = 0U;
  c11_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[6].name = "rdivide";
  c11_info[6].dominantType = "double";
  c11_info[6].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[6].fileLength = 403U;
  c11_info[6].fileTime1 = 1244760752U;
  c11_info[6].fileTime2 = 0U;
  c11_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[7].name = "gt";
  c11_info[7].dominantType = "double";
  c11_info[7].resolved = "[B]gt";
  c11_info[7].fileLength = 0U;
  c11_info[7].fileTime1 = 0U;
  c11_info[7].fileTime2 = 0U;
  c11_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[8].name = "isa";
  c11_info[8].dominantType = "double";
  c11_info[8].resolved = "[B]isa";
  c11_info[8].fileLength = 0U;
  c11_info[8].fileTime1 = 0U;
  c11_info[8].fileTime2 = 0U;
  c11_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[9].name = "eml_div";
  c11_info[9].dominantType = "double";
  c11_info[9].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c11_info[9].fileLength = 4269U;
  c11_info[9].fileTime1 = 1228119026U;
  c11_info[9].fileTime2 = 0U;
  c11_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c11_info[10].name = "isinteger";
  c11_info[10].dominantType = "double";
  c11_info[10].resolved = "[B]isinteger";
  c11_info[10].fileLength = 0U;
  c11_info[10].fileTime1 = 0U;
  c11_info[10].fileTime2 = 0U;
  c11_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c11_info[11].name = "isreal";
  c11_info[11].dominantType = "double";
  c11_info[11].resolved = "[B]isreal";
  c11_info[11].fileLength = 0U;
  c11_info[11].fileTime1 = 0U;
  c11_info[11].fileTime2 = 0U;
  c11_info[12].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/wire_insertion_coordination.m";
  c11_info[12].name = "minus";
  c11_info[12].dominantType = "double";
  c11_info[12].resolved = "[B]minus";
  c11_info[12].fileLength = 0U;
  c11_info[12].fileTime1 = 0U;
  c11_info[12].fileTime2 = 0U;
  c11_info[13].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/wire_insertion_coordination.m";
  c11_info[13].name = "BS_config_invkin";
  c11_info[13].dominantType = "double";
  c11_info[13].resolved =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/BS_config_invkin.m";
  c11_info[13].fileLength = 360U;
  c11_info[13].fileTime1 = 1509461397U;
  c11_info[13].fileTime2 = 0U;
  c11_info[14].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/BS_config_invkin.m";
  c11_info[14].name = "mtimes";
  c11_info[14].dominantType = "double";
  c11_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[14].fileLength = 3425U;
  c11_info[14].fileTime1 = 1250697966U;
  c11_info[14].fileTime2 = 0U;
  c11_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[15].name = "strcmp";
  c11_info[15].dominantType = "char";
  c11_info[15].resolved = "[B]strcmp";
  c11_info[15].fileLength = 0U;
  c11_info[15].fileTime1 = 0U;
  c11_info[15].fileTime2 = 0U;
  c11_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[16].name = "size";
  c11_info[16].dominantType = "double";
  c11_info[16].resolved = "[B]size";
  c11_info[16].fileLength = 0U;
  c11_info[16].fileTime1 = 0U;
  c11_info[16].fileTime2 = 0U;
  c11_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[17].name = "eq";
  c11_info[17].dominantType = "double";
  c11_info[17].resolved = "[B]eq";
  c11_info[17].fileLength = 0U;
  c11_info[17].fileTime1 = 0U;
  c11_info[17].fileTime2 = 0U;
  c11_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[18].name = "class";
  c11_info[18].dominantType = "double";
  c11_info[18].resolved = "[B]class";
  c11_info[18].fileLength = 0U;
  c11_info[18].fileTime1 = 0U;
  c11_info[18].fileTime2 = 0U;
  c11_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[19].name = "not";
  c11_info[19].dominantType = "logical";
  c11_info[19].resolved = "[B]not";
  c11_info[19].fileLength = 0U;
  c11_info[19].fileTime1 = 0U;
  c11_info[19].fileTime2 = 0U;
  c11_info[20].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/BS_config_invkin.m";
  c11_info[20].name = "cos";
  c11_info[20].dominantType = "double";
  c11_info[20].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[20].fileLength = 324U;
  c11_info[20].fileTime1 = 1203473150U;
  c11_info[20].fileTime2 = 0U;
  c11_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[21].name = "eml_scalar_cos";
  c11_info[21].dominantType = "double";
  c11_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c11_info[21].fileLength = 602U;
  c11_info[21].fileTime1 = 1209355986U;
  c11_info[21].fileTime2 = 0U;
  c11_info[22].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/BS_config_invkin.m";
  c11_info[22].name = "plus";
  c11_info[22].dominantType = "double";
  c11_info[22].resolved = "[B]plus";
  c11_info[22].fileLength = 0U;
  c11_info[22].fileTime1 = 0U;
  c11_info[22].fileTime2 = 0U;
  c11_info[23].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/wire_insertion_coordination.m";
  c11_info[23].name = "ones";
  c11_info[23].dominantType = "double";
  c11_info[23].resolved = "[B]ones";
  c11_info[23].fileLength = 0U;
  c11_info[23].fileTime1 = 0U;
  c11_info[23].fileTime2 = 0U;
}

static const mxArray *c11_e_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  boolean_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  SFc11_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc11_large_snakeInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_b_u = *((boolean_T *)c11_u);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static void c11_emlrt_marshallIn(SFc11_large_snakeInstanceStruct *chartInstance,
  const mxArray *c11_q_wire_pos, const char_T *
  c11_name, real_T c11_y[3])
{
  real_T c11_dv1[3];
  int32_T c11_i18;
  sf_mex_import(c11_name, sf_mex_dup(c11_q_wire_pos), &c11_dv1, 1, 0, 0U, 1, 0U,
                1, 3);
  for (c11_i18 = 0; c11_i18 < 3; c11_i18 = c11_i18 + 1) {
    c11_y[c11_i18] = c11_dv1[c11_i18];
  }

  sf_mex_destroy(&c11_q_wire_pos);
}

static uint8_T c11_b_emlrt_marshallIn(SFc11_large_snakeInstanceStruct
  *chartInstance, const mxArray *c11_is_active_c11_large_snake,
  const char_T *c11_name)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_name, sf_mex_dup(c11_is_active_c11_large_snake), &c11_u0, 1,
                3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_is_active_c11_large_snake);
  return c11_y;
}

static void init_dsm_address_info(SFc11_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c11_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3040851703U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1895486318U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2770763251U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(986238510U);
}

mxArray *sf_c11_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1290823749U);
    pr[1] = (double)(3817752839U);
    pr[2] = (double)(3299023018U);
    pr[3] = (double)(924208551U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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

static mxArray *sf_get_sim_state_info_c11_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"q_wire_pos\",},{M[8],M[0],T\"is_active_c11_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc11_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           11,
           1,
           1,
           5,
           0,
           0,
           0,
           0,
           2,
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
            dimVector[0]= 2;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"psi",0,(MexFcnForType)c11_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"q_wire_pos",0,(MexFcnForType)
                                c11_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"qs",0,
                              (MexFcnForType)c11_b_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"r",0,
                              (MexFcnForType)c11_b_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"L",0,
                              (MexFcnForType)c11_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1);
        _SFD_CV_INIT_SCRIPT(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"wire_insertion_coordination",0,-1,1161);
        _SFD_CV_INIT_SCRIPT_IF(0,0,926,949,1090,1126);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"BS_config_invkin",0,-1,358);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c11_psi)[2];
          real_T (*c11_q_wire_pos)[3];
          real_T *c11_qs;
          real_T *c11_r;
          real_T *c11_L;
          c11_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c11_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c11_qs = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_q_wire_pos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            1);
          c11_psi = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_psi);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_q_wire_pos);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_qs);
          _SFD_SET_DATA_VALUE_PTR(3U, c11_r);
          _SFD_SET_DATA_VALUE_PTR(4U, c11_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c11_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_large_snakeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_large_snake((SFc11_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c11_large_snake((SFc11_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_large_snake(void *chartInstanceVar)
{
  enable_c11_large_snake((SFc11_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_large_snake(void *chartInstanceVar)
{
  disable_c11_large_snake((SFc11_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_large_snake(void *chartInstanceVar)
{
  sf_c11_large_snake((SFc11_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c11_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c11_large_snake((SFc11_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c11_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_large_snake
    ((SFc11_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c11_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c11_large_snake(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_large_snake((SFc11_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c11_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c11_large_snake(S);
}

static void sf_opaque_set_sim_state_c11_large_snake(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c11_large_snake(S, st);
}

static void sf_opaque_terminate_c11_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c11_large_snake((SFc11_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_large_snake((SFc11_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c11_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",11,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",11,4);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",11,1);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2164174352U));
  ssSetChecksum1(S,(336957168U));
  ssSetChecksum2(S,(29948067U));
  ssSetChecksum3(S,(855458366U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c11_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",11);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_large_snake(SimStruct *S)
{
  SFc11_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc11_large_snakeInstanceStruct *)malloc(sizeof
    (SFc11_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c11_large_snake;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c11_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c11_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c11_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c11_large_snake;
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

void c11_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
