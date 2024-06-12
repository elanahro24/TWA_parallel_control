/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c9_large_snake.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c9_debug_family_names[29] = { "result_flag", "tf", "p_acc",
  "p_dec", "t_acc", "t_dec", "q_acc", "q_dec", "traj_flag", "t0", "t_cur",
  "nargin", "nargout", "go", "t_clk", "q_goal", "q_prev", "stat_cur", "vmax",
  "t_spd_chg", "coefsConfig", "timeConfig", "breakPtsConfig", "q_ref", "dq_ref",
  "stat_next", "coefsConfig_n", "timeConfig_n", "breakPtsConfig_n" };

static const char *c9_b_debug_family_names[8] = { "A", "b_vec", "nargin",
  "nargout", "q0_vec", "qf_vec", "tf", "a_vec" };

static const char *c9_c_debug_family_names[8] = { "A", "b_vec", "nargin",
  "nargout", "q0_vec", "qf_vec", "tf", "a_vec" };

static const char *c9_d_debug_family_names[8] = { "A", "b_vec", "nargin",
  "nargout", "q0_vec", "qf_vec", "tf", "a_vec" };

static const char *c9_e_debug_family_names[16] = { "q_v_max", "t_linear",
  "nargin", "nargout", "q0", "qf", "v_max", "dt_acc_dec", "result_flag", "tf",
  "p_acc", "p_dec", "t_acc", "t_dec", "q_acc", "q_dec" };

static const char *c9_f_debug_family_names[8] = { "func_basis", "nargin",
  "nargout", "a_vec", "t", "tf", "q_cur", "q_dot" };

/* Function Declarations */
static void initialize_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance);
static void enable_c9_large_snake(SFc9_large_snakeInstanceStruct *chartInstance);
static void disable_c9_large_snake(SFc9_large_snakeInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_large_snake
  (SFc9_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c9_large_snake
  (SFc9_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance, const mxArray *c9_st);
static void finalize_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance);
static void sf_c9_large_snake(SFc9_large_snakeInstanceStruct *chartInstance);
static void c9_c9_large_snake(SFc9_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static void c9_modified_quintic_path_plan(SFc9_large_snakeInstanceStruct
  *chartInstance, real_T c9_q0, real_T c9_qf, real_T c9_v_max, real_T
  c9_dt_acc_dec, real_T *c9_result_flag, real_T *c9_tf, real_T c9_p_acc[6],
  real_T c9_p_dec[6], real_T *c9_t_acc, real_T *c9_t_dec, real_T *c9_q_acc,
  real_T *c9_q_dec);
static void c9_compute_quintic_5th_poly(SFc9_large_snakeInstanceStruct
  *chartInstance, real_T c9_q0_vec[3], real_T c9_qf_vec[3], real_T c9_tf, real_T
  c9_a_vec[6]);
static real_T c9_mpower(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a);
static real_T c9_power(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a, real_T c9_b);
static void c9_eml_scalar_eg(SFc9_large_snakeInstanceStruct *chartInstance);
static void c9_eml_error(SFc9_large_snakeInstanceStruct *chartInstance);
static real_T c9_b_mpower(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a);
static real_T c9_c_mpower(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a);
static real_T c9_d_mpower(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a);
static void c9_mldivide(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_A[36], real_T c9_B[6], real_T c9_Y[6]);
static void c9_eml_xgetrf(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_A[36], real_T c9_b_A[36], int32_T c9_ipiv[6], int32_T *c9_info);
static int32_T c9_eml_ixamax(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[36], int32_T c9_ix0);
static int32_T c9_ceval_ixamax(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[36], int32_T c9_ix0, int32_T c9_incx);
static void c9_ceval_xswap(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[36], int32_T c9_ix0, int32_T c9_incx, int32_T c9_iy0,
  int32_T c9_incy, real_T c9_b_x[36]);
static void c9_ceval_xger(SFc9_large_snakeInstanceStruct *chartInstance, int32_T
  c9_m, int32_T c9_n, real_T c9_alpha1, int32_T c9_ix0, int32_T c9_incx, int32_T
  c9_iy0, int32_T c9_incy, real_T c9_A[36], int32_T c9_ia0, int32_T c9_lda,
  real_T c9_b_A[36]);
static void c9_eml_warning(SFc9_large_snakeInstanceStruct *chartInstance);
static void c9_eml_blas_xtrsm(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_m, int32_T c9_n, real_T c9_alpha1, real_T c9_A[36], int32_T c9_ia0,
  int32_T c9_lda, real_T c9_B[6], int32_T c9_ib0, int32_T c9_ldb, real_T c9_b_B
  [6]);
static void c9_ceval_xtrsm(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_m, int32_T c9_n, real_T c9_alpha1, real_T c9_A[36], int32_T c9_ia0,
  int32_T c9_lda, real_T c9_B[6], int32_T c9_ib0, int32_T c9_ldb, real_T c9_b_B
  [6]);
static void c9_b_eml_blas_xtrsm(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_m, int32_T c9_n, real_T c9_alpha1, real_T c9_A[36], int32_T c9_ia0,
  int32_T c9_lda, real_T c9_B[6], int32_T c9_ib0, int32_T c9_ldb, real_T c9_b_B
  [6]);
static void c9_b_ceval_xtrsm(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_m, int32_T c9_n, real_T c9_alpha1, real_T c9_A[36], int32_T c9_ia0,
  int32_T c9_lda, real_T c9_B[6], int32_T c9_ib0, int32_T c9_ldb, real_T c9_b_B
  [6]);
static void c9_interp_quintic_5th_poly(SFc9_large_snakeInstanceStruct
  *chartInstance, real_T c9_a_vec[6], real_T c9_t, real_T c9_tf, real_T
  *c9_q_cur, real_T *c9_q_dot);
static void c9_b_eml_scalar_eg(SFc9_large_snakeInstanceStruct *chartInstance);
static real_T c9_ceval_xdot(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[6], int32_T c9_ix0, int32_T c9_incx, real_T c9_y[6],
  int32_T c9_iy0, int32_T c9_incy);
static void c9_c_eml_scalar_eg(SFc9_large_snakeInstanceStruct *chartInstance);
static void c9_d_eml_scalar_eg(SFc9_large_snakeInstanceStruct *chartInstance);
static real_T c9_b_ceval_xdot(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[5], int32_T c9_ix0, int32_T c9_incx, real_T c9_y[5],
  int32_T c9_iy0, int32_T c9_incy);
static real_T c9_interp1(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_varargin_1[2], real_T c9_varargin_2[2], real_T c9_varargin_3);
static void c9_b_eml_error(SFc9_large_snakeInstanceStruct *chartInstance);
static void c9_c_eml_error(SFc9_large_snakeInstanceStruct *chartInstance);
static const mxArray *c9_sf_marshall(void *chartInstanceVoid, void *c9_u);
static const mxArray *c9_b_sf_marshall(void *chartInstanceVoid, void *c9_u);
static const mxArray *c9_c_sf_marshall(void *chartInstanceVoid, void *c9_u);
static const mxArray *c9_d_sf_marshall(void *chartInstanceVoid, void *c9_u);
static const mxArray *c9_e_sf_marshall(void *chartInstanceVoid, void *c9_u);
static const mxArray *c9_f_sf_marshall(void *chartInstanceVoid, void *c9_u);
static const mxArray *c9_g_sf_marshall(void *chartInstanceVoid, void *c9_u);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[102]);
static void c9_b_info_helper(c9_ResolvedFunctionInfo c9_info[102]);
static const mxArray *c9_h_sf_marshall(void *chartInstanceVoid, void *c9_u);
static void c9_emlrt_marshallIn(SFc9_large_snakeInstanceStruct *chartInstance,
  const mxArray *c9_breakPtsConfig_n, const char_T *c9_name, real_T c9_y[3]);
static void c9_b_emlrt_marshallIn(SFc9_large_snakeInstanceStruct *chartInstance,
  const mxArray *c9_coefsConfig_n, const char_T *c9_name, real_T c9_y[12]);
static real_T c9_c_emlrt_marshallIn(SFc9_large_snakeInstanceStruct
  *chartInstance, const mxArray *c9_dq_ref, const char_T *c9_name);
static void c9_d_emlrt_marshallIn(SFc9_large_snakeInstanceStruct *chartInstance,
  const mxArray *c9_timeConfig_n, const char_T *c9_name, real_T c9_y[4]);
static uint8_T c9_e_emlrt_marshallIn(SFc9_large_snakeInstanceStruct
  *chartInstance, const mxArray *c9_is_active_c9_large_snake, const char_T
  *c9_name);
static void init_dsm_address_info(SFc9_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c9_is_active_c9_large_snake;
  c9_is_active_c9_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c9_is_active_c9_large_snake = 0U;
}

static void initialize_params_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c9_large_snake(SFc9_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_large_snake(SFc9_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_large_snake
  (SFc9_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance)
{
  c9_update_debugger_state_c9_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c9_large_snake
  (SFc9_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c9_st = NULL;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_hoistedGlobal[3];
  int32_T c9_i1;
  real_T c9_u[3];
  const mxArray *c9_b_y = NULL;
  int32_T c9_i2;
  real_T c9_b_hoistedGlobal[12];
  int32_T c9_i3;
  real_T c9_b_u[12];
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_e_hoistedGlobal;
  real_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  int32_T c9_i4;
  real_T c9_f_hoistedGlobal[4];
  int32_T c9_i5;
  real_T c9_f_u[4];
  const mxArray *c9_g_y = NULL;
  uint8_T c9_g_hoistedGlobal;
  uint8_T c9_g_u;
  const mxArray *c9_h_y = NULL;
  real_T *c9_dq_ref;
  real_T *c9_q_ref;
  real_T *c9_stat_next;
  uint8_T *c9_is_active_c9_large_snake;
  real_T (*c9_timeConfig_n)[4];
  real_T (*c9_coefsConfig_n)[12];
  real_T (*c9_breakPtsConfig_n)[3];
  c9_breakPtsConfig_n = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c9_timeConfig_n = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
  c9_coefsConfig_n = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 4);
  c9_stat_next = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_dq_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_q_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_is_active_c9_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(7));
  for (c9_i0 = 0; c9_i0 < 3; c9_i0 = c9_i0 + 1) {
    c9_hoistedGlobal[c9_i0] = (*c9_breakPtsConfig_n)[c9_i0];
  }

  for (c9_i1 = 0; c9_i1 < 3; c9_i1 = c9_i1 + 1) {
    c9_u[c9_i1] = c9_hoistedGlobal[c9_i1];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c9_y, 0, c9_b_y);
  for (c9_i2 = 0; c9_i2 < 12; c9_i2 = c9_i2 + 1) {
    c9_b_hoistedGlobal[c9_i2] = (*c9_coefsConfig_n)[c9_i2];
  }

  for (c9_i3 = 0; c9_i3 < 12; c9_i3 = c9_i3 + 1) {
    c9_b_u[c9_i3] = c9_b_hoistedGlobal[c9_i3];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 2, 6, 2));
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_dq_ref;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = *c9_q_ref;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_e_hoistedGlobal = *c9_stat_next;
  c9_e_u = c9_e_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 4, c9_f_y);
  for (c9_i4 = 0; c9_i4 < 4; c9_i4 = c9_i4 + 1) {
    c9_f_hoistedGlobal[c9_i4] = (*c9_timeConfig_n)[c9_i4];
  }

  for (c9_i5 = 0; c9_i5 < 4; c9_i5 = c9_i5 + 1) {
    c9_f_u[c9_i5] = c9_f_hoistedGlobal[c9_i5];
  }

  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_f_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c9_y, 5, c9_g_y);
  c9_g_hoistedGlobal = *c9_is_active_c9_large_snake;
  c9_g_u = c9_g_hoistedGlobal;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_g_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 6, c9_h_y);
  sf_mex_assign(&c9_st, c9_y);
  return c9_st;
}

static void set_sim_state_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[3];
  int32_T c9_i6;
  real_T c9_dv1[12];
  int32_T c9_i7;
  real_T c9_dv2[4];
  int32_T c9_i8;
  boolean_T *c9_doneDoubleBufferReInit;
  real_T *c9_dq_ref;
  real_T *c9_q_ref;
  real_T *c9_stat_next;
  uint8_T *c9_is_active_c9_large_snake;
  real_T (*c9_breakPtsConfig_n)[3];
  real_T (*c9_coefsConfig_n)[12];
  real_T (*c9_timeConfig_n)[4];
  c9_breakPtsConfig_n = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c9_timeConfig_n = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
  c9_coefsConfig_n = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 4);
  c9_stat_next = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_dq_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_q_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_is_active_c9_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c9_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
                      "breakPtsConfig_n", c9_dv0);
  for (c9_i6 = 0; c9_i6 < 3; c9_i6 = c9_i6 + 1) {
    (*c9_breakPtsConfig_n)[c9_i6] = c9_dv0[c9_i6];
  }

  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
                        "coefsConfig_n", c9_dv1);
  for (c9_i7 = 0; c9_i7 < 12; c9_i7 = c9_i7 + 1) {
    (*c9_coefsConfig_n)[c9_i7] = c9_dv1[c9_i7];
  }

  *c9_dq_ref = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 2)), "dq_ref");
  *c9_q_ref = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 3)), "q_ref");
  *c9_stat_next = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 4)), "stat_next");
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 5)),
                        "timeConfig_n", c9_dv2);
  for (c9_i8 = 0; c9_i8 < 4; c9_i8 = c9_i8 + 1) {
    (*c9_timeConfig_n)[c9_i8] = c9_dv2[c9_i8];
  }

  *c9_is_active_c9_large_snake = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 6)), "is_active_c9_large_snake");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_large_snake(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_large_snake(SFc9_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c9_large_snake(SFc9_large_snakeInstanceStruct *chartInstance)
{
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_previousEvent;
  real_T *c9_go;
  real_T *c9_q_ref;
  real_T *c9_dq_ref;
  real_T *c9_stat_next;
  real_T *c9_t_clk;
  real_T *c9_q_goal;
  real_T *c9_q_prev;
  real_T *c9_stat_cur;
  real_T *c9_vmax;
  real_T *c9_t_spd_chg;
  real_T (*c9_breakPtsConfig_n)[3];
  real_T (*c9_timeConfig_n)[4];
  real_T (*c9_coefsConfig_n)[12];
  real_T (*c9_breakPtsConfig)[3];
  real_T (*c9_timeConfig)[4];
  real_T (*c9_coefsConfig)[12];
  c9_breakPtsConfig_n = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c9_timeConfig_n = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
  c9_coefsConfig_n = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 4);
  c9_breakPtsConfig = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c9_timeConfig = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 8);
  c9_coefsConfig = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 7);
  c9_t_spd_chg = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c9_vmax = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c9_stat_cur = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c9_q_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_q_goal = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_t_clk = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_stat_next = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_dq_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_q_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_go = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,8);
  _SFD_DATA_RANGE_CHECK(*c9_go, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_q_ref, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_dq_ref, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_stat_next, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_t_clk, 4U);
  _SFD_DATA_RANGE_CHECK(*c9_q_goal, 5U);
  _SFD_DATA_RANGE_CHECK(*c9_q_prev, 6U);
  _SFD_DATA_RANGE_CHECK(*c9_stat_cur, 7U);
  _SFD_DATA_RANGE_CHECK(*c9_vmax, 8U);
  _SFD_DATA_RANGE_CHECK(*c9_t_spd_chg, 9U);
  for (c9_i9 = 0; c9_i9 < 12; c9_i9 = c9_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_coefsConfig)[c9_i9], 10U);
  }

  for (c9_i10 = 0; c9_i10 < 4; c9_i10 = c9_i10 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_timeConfig)[c9_i10], 11U);
  }

  for (c9_i11 = 0; c9_i11 < 3; c9_i11 = c9_i11 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_breakPtsConfig)[c9_i11], 12U);
  }

  for (c9_i12 = 0; c9_i12 < 12; c9_i12 = c9_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_coefsConfig_n)[c9_i12], 13U);
  }

  for (c9_i13 = 0; c9_i13 < 4; c9_i13 = c9_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_timeConfig_n)[c9_i13], 14U);
  }

  for (c9_i14 = 0; c9_i14 < 3; c9_i14 = c9_i14 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_breakPtsConfig_n)[c9_i14], 15U);
  }

  c9_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c9_c9_large_snake(chartInstance);
  _sfEvent_ = c9_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_c9_large_snake(SFc9_large_snakeInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_e_hoistedGlobal;
  real_T c9_f_hoistedGlobal;
  real_T c9_g_hoistedGlobal;
  int32_T c9_i15;
  real_T c9_h_hoistedGlobal[12];
  int32_T c9_i16;
  real_T c9_i_hoistedGlobal[4];
  int32_T c9_i17;
  real_T c9_j_hoistedGlobal[3];
  real_T c9_go;
  real_T c9_t_clk;
  real_T c9_q_goal;
  real_T c9_q_prev;
  real_T c9_stat_cur;
  real_T c9_vmax;
  real_T c9_t_spd_chg;
  int32_T c9_i18;
  real_T c9_coefsConfig[12];
  int32_T c9_i19;
  real_T c9_timeConfig[4];
  int32_T c9_i20;
  real_T c9_breakPtsConfig[3];
  uint32_T c9_debug_family_var_map[29];
  static const char *c9_sv0[29] = { "result_flag", "tf", "p_acc", "p_dec",
    "t_acc", "t_dec", "q_acc", "q_dec", "traj_flag", "t0",
    "t_cur", "nargin", "nargout", "go", "t_clk", "q_goal", "q_prev", "stat_cur",
    "vmax", "t_spd_chg",
    "coefsConfig", "timeConfig", "breakPtsConfig", "q_ref", "dq_ref",
    "stat_next", "coefsConfig_n",
    "timeConfig_n", "breakPtsConfig_n" };

  real_T c9_result_flag;
  real_T c9_tf;
  real_T c9_p_acc[6];
  real_T c9_p_dec[6];
  real_T c9_t_acc;
  real_T c9_t_dec;
  real_T c9_q_acc;
  real_T c9_q_dec;
  real_T c9_traj_flag;
  real_T c9_t0;
  real_T c9_t_cur;
  real_T c9_nargin = 10.0;
  real_T c9_nargout = 6.0;
  real_T c9_q_ref;
  real_T c9_dq_ref;
  real_T c9_stat_next;
  real_T c9_coefsConfig_n[12];
  real_T c9_timeConfig_n[4];
  real_T c9_breakPtsConfig_n[3];
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_y;
  real_T c9_b_q_dec;
  real_T c9_b_q_acc;
  real_T c9_b_t_dec;
  real_T c9_b_t_acc;
  real_T c9_b_p_dec[6];
  real_T c9_b_p_acc[6];
  real_T c9_b_tf;
  real_T c9_b_result_flag;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  real_T c9_c_p_acc[6];
  real_T c9_b_dq_ref;
  real_T c9_b_q_ref;
  real_T c9_c_t_acc[2];
  real_T c9_c_q_acc[2];
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  boolean_T c9_b;
  real_T c9_a;
  real_T c9_b_b;
  int32_T c9_i33;
  int32_T c9_i34;
  real_T c9_c_p_dec[6];
  real_T c9_c_dq_ref;
  real_T c9_c_q_ref;
  int32_T c9_i35;
  real_T c9_d_p_acc[6];
  real_T c9_d_dq_ref;
  real_T c9_d_q_ref;
  int32_T c9_i36;
  int32_T c9_i37;
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i40;
  int32_T c9_i41;
  real_T *c9_b_go;
  real_T *c9_b_t_clk;
  real_T *c9_b_q_goal;
  real_T *c9_b_q_prev;
  real_T *c9_b_stat_cur;
  real_T *c9_b_vmax;
  real_T *c9_b_t_spd_chg;
  real_T *c9_e_q_ref;
  real_T *c9_e_dq_ref;
  real_T *c9_b_stat_next;
  real_T (*c9_b_coefsConfig_n)[12];
  real_T (*c9_b_timeConfig_n)[4];
  real_T (*c9_b_breakPtsConfig_n)[3];
  real_T (*c9_b_breakPtsConfig)[3];
  real_T (*c9_b_timeConfig)[4];
  real_T (*c9_b_coefsConfig)[12];
  c9_b_breakPtsConfig_n = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
    6);
  c9_b_timeConfig_n = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 5);
  c9_b_coefsConfig_n = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 4);
  c9_b_breakPtsConfig = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c9_b_timeConfig = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 8);
  c9_b_coefsConfig = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 7);
  c9_b_t_spd_chg = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c9_b_vmax = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c9_b_stat_cur = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c9_b_q_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_q_goal = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_t_clk = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_stat_next = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_e_dq_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_e_q_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_go = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,8);
  c9_hoistedGlobal = *c9_b_go;
  c9_b_hoistedGlobal = *c9_b_t_clk;
  c9_c_hoistedGlobal = *c9_b_q_goal;
  c9_d_hoistedGlobal = *c9_b_q_prev;
  c9_e_hoistedGlobal = *c9_b_stat_cur;
  c9_f_hoistedGlobal = *c9_b_vmax;
  c9_g_hoistedGlobal = *c9_b_t_spd_chg;
  for (c9_i15 = 0; c9_i15 < 12; c9_i15 = c9_i15 + 1) {
    c9_h_hoistedGlobal[c9_i15] = (*c9_b_coefsConfig)[c9_i15];
  }

  for (c9_i16 = 0; c9_i16 < 4; c9_i16 = c9_i16 + 1) {
    c9_i_hoistedGlobal[c9_i16] = (*c9_b_timeConfig)[c9_i16];
  }

  for (c9_i17 = 0; c9_i17 < 3; c9_i17 = c9_i17 + 1) {
    c9_j_hoistedGlobal[c9_i17] = (*c9_b_breakPtsConfig)[c9_i17];
  }

  c9_go = c9_hoistedGlobal;
  c9_t_clk = c9_b_hoistedGlobal;
  c9_q_goal = c9_c_hoistedGlobal;
  c9_q_prev = c9_d_hoistedGlobal;
  c9_stat_cur = c9_e_hoistedGlobal;
  c9_vmax = c9_f_hoistedGlobal;
  c9_t_spd_chg = c9_g_hoistedGlobal;
  for (c9_i18 = 0; c9_i18 < 12; c9_i18 = c9_i18 + 1) {
    c9_coefsConfig[c9_i18] = c9_h_hoistedGlobal[c9_i18];
  }

  for (c9_i19 = 0; c9_i19 < 4; c9_i19 = c9_i19 + 1) {
    c9_timeConfig[c9_i19] = c9_i_hoistedGlobal[c9_i19];
  }

  for (c9_i20 = 0; c9_i20 < 3; c9_i20 = c9_i20 + 1) {
    c9_breakPtsConfig[c9_i20] = c9_j_hoistedGlobal[c9_i20];
  }

  sf_debug_symbol_scope_push_eml(0U, 29U, 29U, c9_sv0, c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c9_result_flag, c9_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c9_tf, c9_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c9_p_acc, c9_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c9_p_dec, c9_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c9_t_acc, c9_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c9_t_dec, c9_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c9_q_acc, c9_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c9_q_dec, c9_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c9_traj_flag, c9_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c9_t0, c9_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c9_t_cur, c9_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c9_nargin, c9_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c9_nargout, c9_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c9_go, c9_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c9_t_clk, c9_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c9_q_goal, c9_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c9_q_prev, c9_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c9_stat_cur, c9_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c9_vmax, c9_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c9_t_spd_chg, c9_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c9_coefsConfig, c9_c_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c9_timeConfig, c9_b_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c9_breakPtsConfig, c9_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c9_q_ref, c9_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c9_dq_ref, c9_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c9_stat_next, c9_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c9_coefsConfig_n, c9_c_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c9_timeConfig_n, c9_b_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c9_breakPtsConfig_n, c9_sf_marshall, 28U);
  CV_EML_FCN(0, 0);

  /* %  Modified quintic 5th order polynomial interpolation */
  /*    t_clk - the current system time from clock */
  /*    q_goal - the goal position */
  /*    q_prev - the previous commanded position */
  /*    vmax - the maximum allowable speed */
  /*    t_spd_chg - the time of each speed change period */
  /*    stat_cur - the current state */
  /*    coefsConfig - the current polynomial coefficients for motion interp */
  /*    timeConfig - the current time profile, t0, t_acc, t_dec, tf */
  /*    breakPtsConfig - the breakPts flag and the breakPts position. */
  /* %  Detailed explanation */
  /*    stat_cur, stat_next */
  /*        0 - disabled */
  /*        1 - trajectory finished (ready to caculate next trajectory) */
  /*          - trajectory calculated (ready to execute the trajectory) */
  /*        2 - trajectory being executed */
  /*    coefsConfig - [6 x 2] matrix, 1st column is the coefs for acceleration */
  /*                    2nd column is the coefs for deceleration */
  /*    timeConfig - [4 x 1] vector */
  /*            timeConfig(1) - t0, the start time of trajectory */
  /*            timeConfig(2) - t_acc, the end time of acceleration (relative) */
  /*            timeConfig(3) - t_dec, the start time of deceleration (relative) */
  /*            timeConfig(4) - tf, the final time of trajectory (relative) */
  /*    breakPtsConfig - [3 x 1] vector */
  /*            breakPtsConfig(1) - flag, 1 means three-segment trajectory */
  /*                                flag, 2 means one trajectory only */
  /*            breakPtsConfig(2) - q_acc, the end position of acceleration */
  /*            breakPtsConfig(3) - q_dec, the begining position of */
  /*            deceleration */
  _SFD_EML_CALL(0,36);
  if (CV_EML_IF(0, 0, c9_stat_cur == 1.0)) {
    /*     %%  state 1 - ready to calculate new trajectory */
    _SFD_EML_CALL(0,38);
    c9_x = c9_q_goal - c9_q_prev;
    c9_b_x = c9_x;
    c9_y = muDoubleScalarAbs(c9_b_x);
    if (CV_EML_IF(0, 1, c9_y > 0.0001)) {
      _SFD_EML_CALL(0,39);
      c9_modified_quintic_path_plan(chartInstance, c9_q_prev, c9_q_goal, c9_vmax,
        c9_t_spd_chg, &c9_b_result_flag, &c9_b_tf, c9_b_p_acc,
        c9_b_p_dec, &c9_b_t_acc, &c9_b_t_dec, &c9_b_q_acc, &c9_b_q_dec);
      c9_result_flag = c9_b_result_flag;
      c9_tf = c9_b_tf;
      for (c9_i21 = 0; c9_i21 < 6; c9_i21 = c9_i21 + 1) {
        c9_p_acc[c9_i21] = c9_b_p_acc[c9_i21];
      }

      for (c9_i22 = 0; c9_i22 < 6; c9_i22 = c9_i22 + 1) {
        c9_p_dec[c9_i22] = c9_b_p_dec[c9_i22];
      }

      c9_t_acc = c9_b_t_acc;
      c9_t_dec = c9_b_t_dec;
      c9_q_acc = c9_b_q_acc;
      c9_q_dec = c9_b_q_dec;
      _SFD_EML_CALL(0,41);
      for (c9_i23 = 0; c9_i23 < 6; c9_i23 = c9_i23 + 1) {
        c9_coefsConfig_n[c9_i23] = c9_p_acc[c9_i23];
      }

      for (c9_i24 = 0; c9_i24 < 6; c9_i24 = c9_i24 + 1) {
        c9_coefsConfig_n[c9_i24 + 6] = c9_p_dec[c9_i24];
      }

      _SFD_EML_CALL(0,42);
      c9_timeConfig_n[0] = c9_t_clk;
      c9_timeConfig_n[1] = c9_t_acc;
      c9_timeConfig_n[2] = c9_t_dec;
      c9_timeConfig_n[3] = c9_tf;
      _SFD_EML_CALL(0,43);
      c9_breakPtsConfig_n[0] = c9_result_flag;
      c9_breakPtsConfig_n[1] = c9_q_acc;
      c9_breakPtsConfig_n[2] = c9_q_dec;
      _SFD_EML_CALL(0,44);
      c9_stat_next = 2.0;
    } else {
      _SFD_EML_CALL(0,46);
      for (c9_i25 = 0; c9_i25 < 12; c9_i25 = c9_i25 + 1) {
        c9_coefsConfig_n[c9_i25] = 0.0;
      }

      _SFD_EML_CALL(0,47);
      for (c9_i26 = 0; c9_i26 < 4; c9_i26 = c9_i26 + 1) {
        c9_timeConfig_n[c9_i26] = 0.0;
      }

      _SFD_EML_CALL(0,48);
      for (c9_i27 = 0; c9_i27 < 3; c9_i27 = c9_i27 + 1) {
        c9_breakPtsConfig_n[c9_i27] = 0.0;
      }

      _SFD_EML_CALL(0,49);
      c9_stat_next = 1.0;
    }

    _SFD_EML_CALL(0,51);
    c9_q_ref = c9_q_prev;
    _SFD_EML_CALL(0,52);
    c9_dq_ref = 0.0;
    _SFD_EML_CALL(0,53);
    if (CV_EML_IF(0, 2, c9_go == 0.0)) {
      _SFD_EML_CALL(0,54);
      c9_stat_next = 0.0;
    }
  } else {
    _SFD_EML_CALL(0,56);
    if (CV_EML_IF(0, 3, c9_stat_cur == 2.0)) {
      /*     %%  state 2 - trajectory being executed */
      /*    all configs stay the same */
      _SFD_EML_CALL(0,59);
      for (c9_i28 = 0; c9_i28 < 4; c9_i28 = c9_i28 + 1) {
        c9_timeConfig_n[c9_i28] = c9_timeConfig[c9_i28];
      }

      _SFD_EML_CALL(0,60);
      for (c9_i29 = 0; c9_i29 < 12; c9_i29 = c9_i29 + 1) {
        c9_coefsConfig_n[c9_i29] = c9_coefsConfig[c9_i29];
      }

      _SFD_EML_CALL(0,61);
      for (c9_i30 = 0; c9_i30 < 3; c9_i30 = c9_i30 + 1) {
        c9_breakPtsConfig_n[c9_i30] = c9_breakPtsConfig[c9_i30];
      }

      /*    trajectory configs loading */
      _SFD_EML_CALL(0,63);
      c9_traj_flag = c9_breakPtsConfig[0];
      _SFD_EML_CALL(0,64);
      c9_t0 = c9_timeConfig[0];
      _SFD_EML_CALL(0,65);
      c9_t_cur = c9_t_clk - c9_t0;
      _SFD_EML_CALL(0,66);
      c9_tf = c9_timeConfig[3];
      _SFD_EML_CALL(0,67);
      for (c9_i31 = 0; c9_i31 < 6; c9_i31 = c9_i31 + 1) {
        c9_p_acc[c9_i31] = c9_coefsConfig[c9_i31];
      }

      _SFD_EML_CALL(0,68);
      if (CV_EML_IF(0, 4, c9_t_cur <= c9_tf)) {
        /*         %%  still being executed */
        _SFD_EML_CALL(0,70);
        if (CV_EML_IF(0, 5, c9_traj_flag == 1.0)) {
          _SFD_EML_CALL(0,71);
          c9_t_acc = c9_timeConfig[1];
          _SFD_EML_CALL(0,72);
          c9_t_dec = c9_timeConfig[2];
          _SFD_EML_CALL(0,73);
          if (CV_EML_IF(0, 6, c9_t_cur < c9_t_acc)) {
            _SFD_EML_CALL(0,74);
            for (c9_i32 = 0; c9_i32 < 6; c9_i32 = c9_i32 + 1) {
              c9_c_p_acc[c9_i32] = c9_p_acc[c9_i32];
            }

            c9_interp_quintic_5th_poly(chartInstance, c9_c_p_acc, c9_t_cur,
              c9_t_acc, &c9_b_q_ref, &c9_b_dq_ref);
            c9_q_ref = c9_b_q_ref;
            c9_dq_ref = c9_b_dq_ref;
          } else {
            _SFD_EML_CALL(0,75);
            if (CV_EML_COND(0, 0, c9_t_cur >= c9_t_acc)) {
              if (CV_EML_COND(0, 1, c9_t_cur < c9_t_dec)) {
                CV_EML_MCDC(0, 0, TRUE);
                CV_EML_IF(0, 7, TRUE);
                _SFD_EML_CALL(0,76);
                c9_q_acc = c9_breakPtsConfig[1];
                _SFD_EML_CALL(0,77);
                c9_q_dec = c9_breakPtsConfig[2];
                _SFD_EML_CALL(0,78);
                c9_c_t_acc[0] = c9_t_acc;
                c9_c_t_acc[1] = c9_t_dec;
                c9_c_q_acc[0] = c9_q_acc;
                c9_c_q_acc[1] = c9_q_dec;
                c9_q_ref = c9_interp1(chartInstance, c9_c_t_acc, c9_c_q_acc,
                                      c9_t_cur);
                _SFD_EML_CALL(0,79);
                c9_c_x = c9_q_dec - c9_q_acc;
                c9_d_x = c9_c_x;
                c9_e_x = c9_d_x;
                c9_d_x = c9_e_x;
                c9_f_x = c9_d_x;
                c9_b = muDoubleScalarIsNaN(c9_f_x);
                if (c9_b) {
                  c9_d_x = rtNaN;
                } else if (c9_d_x > 0.0) {
                  c9_d_x = 1.0;
                } else if (c9_d_x < 0.0) {
                  c9_d_x = -1.0;
                } else {
                  c9_d_x = 0.0;
                }

                c9_a = c9_d_x;
                c9_b_b = c9_vmax;
                c9_dq_ref = c9_a * c9_b_b;
                goto label_1;
              }
            }

            CV_EML_MCDC(0, 0, FALSE);
            CV_EML_IF(0, 7, FALSE);
            _SFD_EML_CALL(0,81);
            for (c9_i33 = 0; c9_i33 < 6; c9_i33 = c9_i33 + 1) {
              c9_p_dec[c9_i33] = c9_coefsConfig[c9_i33 + 6];
            }

            _SFD_EML_CALL(0,82);
            for (c9_i34 = 0; c9_i34 < 6; c9_i34 = c9_i34 + 1) {
              c9_c_p_dec[c9_i34] = c9_p_dec[c9_i34];
            }

            c9_interp_quintic_5th_poly(chartInstance, c9_c_p_dec, c9_t_cur -
              c9_t_dec, c9_tf - c9_t_dec, &c9_c_q_ref, &c9_c_dq_ref);
            c9_q_ref = c9_c_q_ref;
            c9_dq_ref = c9_c_dq_ref;
           label_1:
            ;
          }
        } else {
          _SFD_EML_CALL(0,86);
          for (c9_i35 = 0; c9_i35 < 6; c9_i35 = c9_i35 + 1) {
            c9_d_p_acc[c9_i35] = c9_p_acc[c9_i35];
          }

          c9_interp_quintic_5th_poly(chartInstance, c9_d_p_acc, c9_t_cur, c9_tf,
            &c9_d_q_ref, &c9_d_dq_ref);
          c9_q_ref = c9_d_q_ref;
          c9_dq_ref = c9_d_dq_ref;
        }

        _SFD_EML_CALL(0,88);
        c9_stat_next = 2.0;
      } else {
        _SFD_EML_CALL(0,90);
        c9_stat_next = 1.0;
        _SFD_EML_CALL(0,91);
        c9_q_ref = c9_q_prev;
        _SFD_EML_CALL(0,92);
        c9_dq_ref = 0.0;
      }
    } else {
      _SFD_EML_CALL(0,95);
      for (c9_i36 = 0; c9_i36 < 4; c9_i36 = c9_i36 + 1) {
        c9_timeConfig_n[c9_i36] = 0.0;
      }

      _SFD_EML_CALL(0,96);
      for (c9_i37 = 0; c9_i37 < 12; c9_i37 = c9_i37 + 1) {
        c9_coefsConfig_n[c9_i37] = 0.0;
      }

      _SFD_EML_CALL(0,97);
      for (c9_i38 = 0; c9_i38 < 3; c9_i38 = c9_i38 + 1) {
        c9_breakPtsConfig_n[c9_i38] = 0.0;
      }

      _SFD_EML_CALL(0,98);
      c9_q_ref = c9_q_prev;
      _SFD_EML_CALL(0,99);
      c9_dq_ref = 0.0;
      _SFD_EML_CALL(0,100);
      if (CV_EML_IF(0, 8, c9_go == 1.0)) {
        _SFD_EML_CALL(0,101);
        c9_stat_next = 1.0;
      } else {
        _SFD_EML_CALL(0,103);
        c9_stat_next = 0.0;
      }
    }
  }

  _SFD_EML_CALL(0,-103);
  sf_debug_symbol_scope_pop();
  *c9_e_q_ref = c9_q_ref;
  *c9_e_dq_ref = c9_dq_ref;
  *c9_b_stat_next = c9_stat_next;
  for (c9_i39 = 0; c9_i39 < 12; c9_i39 = c9_i39 + 1) {
    (*c9_b_coefsConfig_n)[c9_i39] = c9_coefsConfig_n[c9_i39];
  }

  for (c9_i40 = 0; c9_i40 < 4; c9_i40 = c9_i40 + 1) {
    (*c9_b_timeConfig_n)[c9_i40] = c9_timeConfig_n[c9_i40];
  }

  for (c9_i41 = 0; c9_i41 < 3; c9_i41 = c9_i41 + 1) {
    (*c9_b_breakPtsConfig_n)[c9_i41] = c9_breakPtsConfig_n[c9_i41];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/modified_quintic_path_plan.m"));
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, 1U, sf_debug_get_script_id(
    "C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/compute_quintic_5th_poly.m"));
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, 2U, sf_debug_get_script_id(
    "C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/interp_quintic_5th_poly.m"));
}

static void c9_modified_quintic_path_plan(SFc9_large_snakeInstanceStruct
  *chartInstance, real_T c9_q0, real_T c9_qf, real_T c9_v_max
  , real_T c9_dt_acc_dec, real_T *c9_result_flag, real_T *c9_tf, real_T
  c9_p_acc[6], real_T c9_p_dec[6], real_T *c9_t_acc, real_T *
  c9_t_dec, real_T *c9_q_acc, real_T *c9_q_dec)
{
  uint32_T c9_debug_family_var_map[16];
  static const char *c9_sv1[16] = { "q_v_max", "t_linear", "nargin", "nargout",
    "q0", "qf", "v_max", "dt_acc_dec", "result_flag", "tf"
    , "p_acc", "p_dec", "t_acc", "t_dec", "q_acc", "q_dec" };

  real_T c9_q_v_max;
  real_T c9_t_linear;
  real_T c9_nargin = 4.0;
  real_T c9_nargout = 8.0;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_y;
  real_T c9_a;
  real_T c9_b;
  real_T c9_b_y;
  real_T c9_b_b;
  real_T c9_b_q0[3];
  real_T c9_b_qf[3];
  real_T c9_dv3[6];
  int32_T c9_i42;
  int32_T c9_i43;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  boolean_T c9_c_b;
  real_T c9_b_a;
  real_T c9_d_b;
  real_T c9_c_a;
  real_T c9_e_b;
  real_T c9_c_y;
  real_T c9_A;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_d_y;
  real_T c9_d_a;
  real_T c9_f_b;
  real_T c9_e_y;
  real_T c9_b_A;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_f_y;
  real_T c9_q0_vec[3];
  real_T c9_qf_vec[3];
  real_T c9_b_tf;
  uint32_T c9_b_debug_family_var_map[8];
  static const char *c9_sv2[8] = { "A", "b_vec", "nargin", "nargout", "q0_vec",
    "qf_vec", "tf", "a_vec" };

  real_T c9_c_A[36];
  real_T c9_b_vec[6];
  real_T c9_b_nargin = 3.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_e_a;
  real_T c9_c;
  real_T c9_f_a;
  real_T c9_b_c;
  real_T c9_g_a;
  real_T c9_c_c;
  real_T c9_h_a;
  real_T c9_d_c;
  real_T c9_g_b;
  real_T c9_g_y;
  real_T c9_i_a;
  real_T c9_e_c;
  real_T c9_h_b;
  real_T c9_h_y;
  real_T c9_j_a;
  real_T c9_f_c;
  real_T c9_i_b;
  real_T c9_i_y;
  real_T c9_k_a;
  real_T c9_g_c;
  real_T c9_j_b;
  real_T c9_j_y;
  real_T c9_k_b;
  real_T c9_k_y;
  real_T c9_l_a;
  real_T c9_h_c;
  real_T c9_l_b;
  real_T c9_l_y;
  real_T c9_m_a;
  real_T c9_i_c;
  real_T c9_m_b;
  real_T c9_m_y;
  int32_T c9_i44;
  int32_T c9_i45;
  static real_T c9_dv4[6] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c9_i46;
  int32_T c9_i47;
  static real_T c9_dv5[6] = { 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c9_i48;
  int32_T c9_i49;
  static real_T c9_dv6[6] = { 0.0, 0.0, 2.0, 0.0, 0.0, 0.0 };

  int32_T c9_i50;
  real_T c9_d_A[36];
  int32_T c9_i51;
  real_T c9_b_b_vec[6];
  real_T c9_dv7[6];
  int32_T c9_i52;
  real_T c9_b_q0_vec[3];
  real_T c9_b_qf_vec[3];
  real_T c9_c_tf;
  uint32_T c9_c_debug_family_var_map[8];
  real_T c9_e_A[36];
  real_T c9_c_b_vec[6];
  real_T c9_c_nargin = 3.0;
  real_T c9_c_nargout = 1.0;
  real_T c9_n_a;
  real_T c9_j_c;
  real_T c9_o_a;
  real_T c9_k_c;
  real_T c9_p_a;
  real_T c9_l_c;
  real_T c9_q_a;
  real_T c9_m_c;
  real_T c9_n_b;
  real_T c9_n_y;
  real_T c9_r_a;
  real_T c9_n_c;
  real_T c9_o_b;
  real_T c9_o_y;
  real_T c9_s_a;
  real_T c9_o_c;
  real_T c9_p_b;
  real_T c9_p_y;
  real_T c9_t_a;
  real_T c9_p_c;
  real_T c9_q_b;
  real_T c9_q_y;
  real_T c9_r_b;
  real_T c9_r_y;
  real_T c9_u_a;
  real_T c9_q_c;
  real_T c9_s_b;
  real_T c9_s_y;
  real_T c9_v_a;
  real_T c9_r_c;
  real_T c9_t_b;
  real_T c9_t_y;
  int32_T c9_i53;
  int32_T c9_i54;
  int32_T c9_i55;
  int32_T c9_i56;
  int32_T c9_i57;
  int32_T c9_i58;
  int32_T c9_i59;
  real_T c9_f_A[36];
  int32_T c9_i60;
  real_T c9_d_b_vec[6];
  real_T c9_dv8[6];
  int32_T c9_i61;
  real_T c9_m_x;
  real_T c9_n_x;
  real_T c9_u_y;
  real_T c9_g_A;
  real_T c9_B;
  real_T c9_o_x;
  real_T c9_v_y;
  real_T c9_p_x;
  real_T c9_w_y;
  real_T c9_q_x;
  real_T c9_x_y;
  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c9_sv1, c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c9_q_v_max, c9_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c9_t_linear, c9_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c9_nargin, c9_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c9_nargout, c9_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c9_q0, c9_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c9_qf, c9_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c9_v_max, c9_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c9_dt_acc_dec, c9_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c9_result_flag, c9_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c9_tf, c9_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c9_p_acc, c9_e_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c9_p_dec, c9_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(c9_t_acc, c9_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(c9_t_dec, c9_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(c9_q_acc, c9_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(c9_q_dec, c9_d_sf_marshall, 15U);
  CV_SCRIPT_FCN(0, 0);

  /* %  Modified approach for quintic path planning */
  /*    By Long Wang, 2017/2/6 */
  /*    This func calculate a modified quintic path planning which has the */
  /*    following feaures: */
  /*    1) an acceleration period to vmax, using 5th order polynomial */
  /*    2) a constant speed motion  */
  /*    3) a decceleration period to 0, using 5th order polynomial */
  /* %  The outputs: */
  /*    tf - time of the end */
  /*    p_acc - polynomial coefs of the acceleration period */
  /*    p_dec - polynomial coefs of the decceleration period */
  /*    t_acc - time of the end of acceleration, w.r.t the begin time t0 */
  /*    t_dec - time of the begining of deccelation, w.r.t the begin time t0 */
  /*    q_acc - the joint position at the end of the acceleration */
  /*    q_dec - the joint position at the beginning of the decceleration */
  /* %  result_flag */
  /*    1 - three sub trajectories are defined, all p_acc, p_dec, t_acc, t_dec */
  /*    and tf are needed. */
  /*    2 - v_max is not reached. only p_acc and tf are used for a standard */
  /*    quintic polynomial */
  /* %  Test if v_max will be reached */
  _SFD_SCRIPT_CALL(0,24);
  c9_x = c9_q0 - c9_qf;
  c9_b_x = c9_x;
  c9_y = muDoubleScalarAbs(c9_b_x);
  c9_a = c9_v_max;
  c9_b = c9_dt_acc_dec;
  c9_b_y = c9_a * c9_b;
  if (CV_SCRIPT_IF(0, 0, c9_y < c9_b_y)) {
    /*     %% In this case, no need to split to three tasks. */
    _SFD_SCRIPT_CALL(0,26);
    c9_b_b = c9_dt_acc_dec;
    *c9_tf = 2.0 * c9_b_b;
    _SFD_SCRIPT_CALL(0,27);
    c9_b_q0[0] = c9_q0;
    c9_b_q0[1] = 0.0;
    c9_b_q0[2] = 0.0;
    c9_b_qf[0] = c9_qf;
    c9_b_qf[1] = 0.0;
    c9_b_qf[2] = 0.0;
    c9_compute_quintic_5th_poly(chartInstance, c9_b_q0, c9_b_qf, *c9_tf, c9_dv3);
    for (c9_i42 = 0; c9_i42 < 6; c9_i42 = c9_i42 + 1) {
      c9_p_acc[c9_i42] = c9_dv3[c9_i42];
    }

    _SFD_SCRIPT_CALL(0,28);
    *c9_result_flag = 2.0;

    /*    the rest of the outputs are just meaningless and we give zeros */
    _SFD_SCRIPT_CALL(0,30);
    for (c9_i43 = 0; c9_i43 < 6; c9_i43 = c9_i43 + 1) {
      c9_p_dec[c9_i43] = 0.0;
    }

    _SFD_SCRIPT_CALL(0,31);
    *c9_t_acc = 0.0;
    _SFD_SCRIPT_CALL(0,32);
    *c9_t_dec = 0.0;
    _SFD_SCRIPT_CALL(0,33);
    *c9_q_acc = 0.0;
    _SFD_SCRIPT_CALL(0,34);
    *c9_q_dec = 0.0;
  } else {
    /*     %%  In this case, three sub trajectories are being defined */
    /*    Trajectory 1 - acceleration */
    /*    Trajectory 2 - linear */
    /*    Trajectory 3 - decceleration */
    _SFD_SCRIPT_CALL(0,40);
    c9_c_x = c9_qf - c9_q0;
    c9_d_x = c9_c_x;
    c9_e_x = c9_d_x;
    c9_d_x = c9_e_x;
    c9_f_x = c9_d_x;
    c9_c_b = muDoubleScalarIsNaN(c9_f_x);
    if (c9_c_b) {
      c9_d_x = rtNaN;
    } else if (c9_d_x > 0.0) {
      c9_d_x = 1.0;
    } else if (c9_d_x < 0.0) {
      c9_d_x = -1.0;
    } else {
      c9_d_x = 0.0;
    }

    c9_b_a = c9_d_x;
    c9_d_b = c9_v_max;
    c9_q_v_max = c9_b_a * c9_d_b;
    _SFD_SCRIPT_CALL(0,41);
    c9_c_a = c9_q_v_max;
    c9_e_b = c9_dt_acc_dec;
    c9_c_y = c9_c_a * c9_e_b;
    c9_A = c9_c_y;
    c9_g_x = c9_A;
    c9_h_x = c9_g_x;
    c9_i_x = c9_h_x;
    c9_d_y = c9_i_x / 2.0;
    *c9_q_acc = c9_q0 + c9_d_y;
    _SFD_SCRIPT_CALL(0,42);
    c9_d_a = c9_q_v_max;
    c9_f_b = c9_dt_acc_dec;
    c9_e_y = c9_d_a * c9_f_b;
    c9_b_A = c9_e_y;
    c9_j_x = c9_b_A;
    c9_k_x = c9_j_x;
    c9_l_x = c9_k_x;
    c9_f_y = c9_l_x / 2.0;
    *c9_q_dec = c9_qf - c9_f_y;
    _SFD_SCRIPT_CALL(0,43);
    *c9_t_acc = c9_dt_acc_dec;
    _SFD_SCRIPT_CALL(0,44);
    c9_q0_vec[0] = c9_q0;
    c9_q0_vec[1] = 0.0;
    c9_q0_vec[2] = 0.0;
    c9_qf_vec[0] = *c9_q_acc;
    c9_qf_vec[1] = c9_q_v_max;
    c9_qf_vec[2] = 0.0;
    c9_b_tf = *c9_t_acc;
    sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c9_sv2, c9_b_debug_family_var_map);
    sf_debug_symbol_scope_add_eml(&c9_c_A, c9_f_sf_marshall, 0U);
    sf_debug_symbol_scope_add_eml(&c9_b_vec, c9_e_sf_marshall, 1U);
    sf_debug_symbol_scope_add_eml(&c9_b_nargin, c9_d_sf_marshall, 2U);
    sf_debug_symbol_scope_add_eml(&c9_b_nargout, c9_d_sf_marshall, 3U);
    sf_debug_symbol_scope_add_eml(&c9_q0_vec, c9_sf_marshall, 4U);
    sf_debug_symbol_scope_add_eml(&c9_qf_vec, c9_g_sf_marshall, 5U);
    sf_debug_symbol_scope_add_eml(&c9_b_tf, c9_d_sf_marshall, 6U);
    sf_debug_symbol_scope_add_eml(c9_p_acc, c9_e_sf_marshall, 7U);
    CV_SCRIPT_FCN(1, 0);

    /* %  compute quintic 5th order polynomial coefs */
    /*    By Long Wang, 2017/2/6 */
    /*    This func computes the quintic 5th order polynomial interpolation based */
    /*    on Nabil Simaa's notes. */
    /* %  Inputs:  */
    /*    q0_vec = [q0, q0dot,q0ddot]'; */
    /*    qf_vec = [qf, qfdot,qfddot]'; */
    /*    tf - the relative time from q0 to qf. */
    /* %  Notest on time */
    /*    In Nabil's notes, a normalized interpolation eta was used. */
    /*    In this version of code, absolute time is used because it is easier in */
    /*    the case where the final velocity goal is not zero. */
    /*    So the output coefs, they are corresponding to abosolute time. */
    _SFD_SCRIPT_CALL(1,16);
    c9_e_a = c9_b_tf;
    c9_c = c9_power(chartInstance, c9_e_a, 2.0);
    c9_f_a = c9_b_tf;
    c9_b_c = c9_power(chartInstance, c9_f_a, 3.0);
    c9_g_a = c9_b_tf;
    c9_c_c = c9_power(chartInstance, c9_g_a, 4.0);
    c9_h_a = c9_b_tf;
    c9_d_c = c9_power(chartInstance, c9_h_a, 5.0);
    c9_g_b = c9_b_tf;
    c9_g_y = 2.0 * c9_g_b;
    c9_i_a = c9_b_tf;
    c9_e_c = c9_power(chartInstance, c9_i_a, 2.0);
    c9_h_b = c9_e_c;
    c9_h_y = 3.0 * c9_h_b;
    c9_j_a = c9_b_tf;
    c9_f_c = c9_power(chartInstance, c9_j_a, 3.0);
    c9_i_b = c9_f_c;
    c9_i_y = 4.0 * c9_i_b;
    c9_k_a = c9_b_tf;
    c9_g_c = c9_power(chartInstance, c9_k_a, 4.0);
    c9_j_b = c9_g_c;
    c9_j_y = 5.0 * c9_j_b;
    c9_k_b = c9_b_tf;
    c9_k_y = 6.0 * c9_k_b;
    c9_l_a = c9_b_tf;
    c9_h_c = c9_power(chartInstance, c9_l_a, 2.0);
    c9_l_b = c9_h_c;
    c9_l_y = 12.0 * c9_l_b;
    c9_m_a = c9_b_tf;
    c9_i_c = c9_power(chartInstance, c9_m_a, 3.0);
    c9_m_b = c9_i_c;
    c9_m_y = 20.0 * c9_m_b;
    c9_i44 = 0;
    for (c9_i45 = 0; c9_i45 < 6; c9_i45 = c9_i45 + 1) {
      c9_c_A[c9_i44] = c9_dv4[c9_i45];
      c9_i44 = c9_i44 + 6;
    }

    c9_c_A[1] = 1.0;
    c9_c_A[7] = c9_b_tf;
    c9_c_A[13] = c9_c;
    c9_c_A[19] = c9_b_c;
    c9_c_A[25] = c9_c_c;
    c9_c_A[31] = c9_d_c;
    c9_i46 = 0;
    for (c9_i47 = 0; c9_i47 < 6; c9_i47 = c9_i47 + 1) {
      c9_c_A[c9_i46 + 2] = c9_dv5[c9_i47];
      c9_i46 = c9_i46 + 6;
    }

    c9_c_A[3] = 0.0;
    c9_c_A[9] = 1.0;
    c9_c_A[15] = c9_g_y;
    c9_c_A[21] = c9_h_y;
    c9_c_A[27] = c9_i_y;
    c9_c_A[33] = c9_j_y;
    c9_i48 = 0;
    for (c9_i49 = 0; c9_i49 < 6; c9_i49 = c9_i49 + 1) {
      c9_c_A[c9_i48 + 4] = c9_dv6[c9_i49];
      c9_i48 = c9_i48 + 6;
    }

    c9_c_A[5] = 0.0;
    c9_c_A[11] = 0.0;
    c9_c_A[17] = 2.0;
    c9_c_A[23] = c9_k_y;
    c9_c_A[29] = c9_l_y;
    c9_c_A[35] = c9_m_y;
    _SFD_SCRIPT_CALL(1,23);
    c9_b_vec[0] = c9_q0_vec[0];
    c9_b_vec[1] = c9_qf_vec[0];
    c9_b_vec[2] = c9_q0_vec[1];
    c9_b_vec[3] = c9_qf_vec[1];
    c9_b_vec[4] = c9_q0_vec[2];
    c9_b_vec[5] = c9_qf_vec[2];
    _SFD_SCRIPT_CALL(1,24);
    for (c9_i50 = 0; c9_i50 < 36; c9_i50 = c9_i50 + 1) {
      c9_d_A[c9_i50] = c9_c_A[c9_i50];
    }

    for (c9_i51 = 0; c9_i51 < 6; c9_i51 = c9_i51 + 1) {
      c9_b_b_vec[c9_i51] = c9_b_vec[c9_i51];
    }

    c9_mldivide(chartInstance, c9_d_A, c9_b_b_vec, c9_dv7);
    for (c9_i52 = 0; c9_i52 < 6; c9_i52 = c9_i52 + 1) {
      c9_p_acc[c9_i52] = c9_dv7[c9_i52];
    }

    _SFD_SCRIPT_CALL(1,-24);
    sf_debug_symbol_scope_pop();
    _SFD_SCRIPT_CALL(0,45);
    c9_b_q0_vec[0] = *c9_q_dec;
    c9_b_q0_vec[1] = c9_q_v_max;
    c9_b_q0_vec[2] = 0.0;
    c9_b_qf_vec[0] = c9_qf;
    c9_b_qf_vec[1] = 0.0;
    c9_b_qf_vec[2] = 0.0;
    c9_c_tf = *c9_t_acc;
    sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c9_sv2, c9_c_debug_family_var_map);
    sf_debug_symbol_scope_add_eml(&c9_e_A, c9_f_sf_marshall, 0U);
    sf_debug_symbol_scope_add_eml(&c9_c_b_vec, c9_e_sf_marshall, 1U);
    sf_debug_symbol_scope_add_eml(&c9_c_nargin, c9_d_sf_marshall, 2U);
    sf_debug_symbol_scope_add_eml(&c9_c_nargout, c9_d_sf_marshall, 3U);
    sf_debug_symbol_scope_add_eml(&c9_b_q0_vec, c9_g_sf_marshall, 4U);
    sf_debug_symbol_scope_add_eml(&c9_b_qf_vec, c9_g_sf_marshall, 5U);
    sf_debug_symbol_scope_add_eml(&c9_c_tf, c9_d_sf_marshall, 6U);
    sf_debug_symbol_scope_add_eml(c9_p_dec, c9_e_sf_marshall, 7U);
    CV_SCRIPT_FCN(1, 0);

    /* %  compute quintic 5th order polynomial coefs */
    /*    By Long Wang, 2017/2/6 */
    /*    This func computes the quintic 5th order polynomial interpolation based */
    /*    on Nabil Simaa's notes. */
    /* %  Inputs:  */
    /*    q0_vec = [q0, q0dot,q0ddot]'; */
    /*    qf_vec = [qf, qfdot,qfddot]'; */
    /*    tf - the relative time from q0 to qf. */
    /* %  Notest on time */
    /*    In Nabil's notes, a normalized interpolation eta was used. */
    /*    In this version of code, absolute time is used because it is easier in */
    /*    the case where the final velocity goal is not zero. */
    /*    So the output coefs, they are corresponding to abosolute time. */
    _SFD_SCRIPT_CALL(1,16);
    c9_n_a = c9_c_tf;
    c9_j_c = c9_power(chartInstance, c9_n_a, 2.0);
    c9_o_a = c9_c_tf;
    c9_k_c = c9_power(chartInstance, c9_o_a, 3.0);
    c9_p_a = c9_c_tf;
    c9_l_c = c9_power(chartInstance, c9_p_a, 4.0);
    c9_q_a = c9_c_tf;
    c9_m_c = c9_power(chartInstance, c9_q_a, 5.0);
    c9_n_b = c9_c_tf;
    c9_n_y = 2.0 * c9_n_b;
    c9_r_a = c9_c_tf;
    c9_n_c = c9_power(chartInstance, c9_r_a, 2.0);
    c9_o_b = c9_n_c;
    c9_o_y = 3.0 * c9_o_b;
    c9_s_a = c9_c_tf;
    c9_o_c = c9_power(chartInstance, c9_s_a, 3.0);
    c9_p_b = c9_o_c;
    c9_p_y = 4.0 * c9_p_b;
    c9_t_a = c9_c_tf;
    c9_p_c = c9_power(chartInstance, c9_t_a, 4.0);
    c9_q_b = c9_p_c;
    c9_q_y = 5.0 * c9_q_b;
    c9_r_b = c9_c_tf;
    c9_r_y = 6.0 * c9_r_b;
    c9_u_a = c9_c_tf;
    c9_q_c = c9_power(chartInstance, c9_u_a, 2.0);
    c9_s_b = c9_q_c;
    c9_s_y = 12.0 * c9_s_b;
    c9_v_a = c9_c_tf;
    c9_r_c = c9_power(chartInstance, c9_v_a, 3.0);
    c9_t_b = c9_r_c;
    c9_t_y = 20.0 * c9_t_b;
    c9_i53 = 0;
    for (c9_i54 = 0; c9_i54 < 6; c9_i54 = c9_i54 + 1) {
      c9_e_A[c9_i53] = c9_dv4[c9_i54];
      c9_i53 = c9_i53 + 6;
    }

    c9_e_A[1] = 1.0;
    c9_e_A[7] = c9_c_tf;
    c9_e_A[13] = c9_j_c;
    c9_e_A[19] = c9_k_c;
    c9_e_A[25] = c9_l_c;
    c9_e_A[31] = c9_m_c;
    c9_i55 = 0;
    for (c9_i56 = 0; c9_i56 < 6; c9_i56 = c9_i56 + 1) {
      c9_e_A[c9_i55 + 2] = c9_dv5[c9_i56];
      c9_i55 = c9_i55 + 6;
    }

    c9_e_A[3] = 0.0;
    c9_e_A[9] = 1.0;
    c9_e_A[15] = c9_n_y;
    c9_e_A[21] = c9_o_y;
    c9_e_A[27] = c9_p_y;
    c9_e_A[33] = c9_q_y;
    c9_i57 = 0;
    for (c9_i58 = 0; c9_i58 < 6; c9_i58 = c9_i58 + 1) {
      c9_e_A[c9_i57 + 4] = c9_dv6[c9_i58];
      c9_i57 = c9_i57 + 6;
    }

    c9_e_A[5] = 0.0;
    c9_e_A[11] = 0.0;
    c9_e_A[17] = 2.0;
    c9_e_A[23] = c9_r_y;
    c9_e_A[29] = c9_s_y;
    c9_e_A[35] = c9_t_y;
    _SFD_SCRIPT_CALL(1,23);
    c9_c_b_vec[0] = c9_b_q0_vec[0];
    c9_c_b_vec[1] = c9_b_qf_vec[0];
    c9_c_b_vec[2] = c9_b_q0_vec[1];
    c9_c_b_vec[3] = c9_b_qf_vec[1];
    c9_c_b_vec[4] = c9_b_q0_vec[2];
    c9_c_b_vec[5] = c9_b_qf_vec[2];
    _SFD_SCRIPT_CALL(1,24);
    for (c9_i59 = 0; c9_i59 < 36; c9_i59 = c9_i59 + 1) {
      c9_f_A[c9_i59] = c9_e_A[c9_i59];
    }

    for (c9_i60 = 0; c9_i60 < 6; c9_i60 = c9_i60 + 1) {
      c9_d_b_vec[c9_i60] = c9_c_b_vec[c9_i60];
    }

    c9_mldivide(chartInstance, c9_f_A, c9_d_b_vec, c9_dv8);
    for (c9_i61 = 0; c9_i61 < 6; c9_i61 = c9_i61 + 1) {
      c9_p_dec[c9_i61] = c9_dv8[c9_i61];
    }

    _SFD_SCRIPT_CALL(1,-24);
    sf_debug_symbol_scope_pop();
    _SFD_SCRIPT_CALL(0,46);
    c9_m_x = *c9_q_dec - *c9_q_acc;
    c9_n_x = c9_m_x;
    c9_u_y = muDoubleScalarAbs(c9_n_x);
    c9_g_A = c9_u_y;
    c9_B = c9_v_max;
    c9_o_x = c9_g_A;
    c9_v_y = c9_B;
    c9_p_x = c9_o_x;
    c9_w_y = c9_v_y;
    c9_q_x = c9_p_x;
    c9_x_y = c9_w_y;
    c9_t_linear = c9_q_x / c9_x_y;
    _SFD_SCRIPT_CALL(0,47);
    *c9_t_dec = *c9_t_acc + c9_t_linear;
    _SFD_SCRIPT_CALL(0,48);
    *c9_tf = *c9_t_dec + c9_dt_acc_dec;
    _SFD_SCRIPT_CALL(0,49);
    *c9_result_flag = 1.0;
  }

  _SFD_SCRIPT_CALL(0,-49);
  sf_debug_symbol_scope_pop();
}

static void c9_compute_quintic_5th_poly(SFc9_large_snakeInstanceStruct
  *chartInstance, real_T c9_q0_vec[3], real_T c9_qf_vec[3],
  real_T c9_tf, real_T c9_a_vec[6])
{
  uint32_T c9_debug_family_var_map[8];
  static const char *c9_sv3[8] = { "A", "b_vec", "nargin", "nargout", "q0_vec",
    "qf_vec", "tf", "a_vec" };

  real_T c9_A[36];
  real_T c9_b_vec[6];
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 1.0;
  real_T c9_a;
  real_T c9_c;
  real_T c9_b_a;
  real_T c9_b_c;
  real_T c9_c_a;
  real_T c9_c_c;
  real_T c9_d_a;
  real_T c9_d_c;
  real_T c9_b;
  real_T c9_y;
  real_T c9_e_a;
  real_T c9_e_c;
  real_T c9_b_b;
  real_T c9_b_y;
  real_T c9_f_a;
  real_T c9_f_c;
  real_T c9_c_b;
  real_T c9_c_y;
  real_T c9_g_a;
  real_T c9_g_c;
  real_T c9_d_b;
  real_T c9_d_y;
  real_T c9_e_b;
  real_T c9_e_y;
  real_T c9_h_a;
  real_T c9_h_c;
  real_T c9_f_b;
  real_T c9_f_y;
  real_T c9_i_a;
  real_T c9_i_c;
  real_T c9_g_b;
  real_T c9_g_y;
  int32_T c9_i62;
  int32_T c9_i63;
  static real_T c9_dv9[6] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c9_i64;
  int32_T c9_i65;
  static real_T c9_dv10[6] = { 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c9_i66;
  int32_T c9_i67;
  static real_T c9_dv11[6] = { 0.0, 0.0, 2.0, 0.0, 0.0, 0.0 };

  int32_T c9_i68;
  real_T c9_b_A[36];
  int32_T c9_i69;
  real_T c9_b_b_vec[6];
  real_T c9_dv12[6];
  int32_T c9_i70;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c9_sv3, c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c9_A, c9_f_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c9_b_vec, c9_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c9_nargin, c9_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c9_nargout, c9_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c9_q0_vec, c9_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c9_qf_vec, c9_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c9_tf, c9_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c9_a_vec, c9_e_sf_marshall, 7U);
  CV_SCRIPT_FCN(1, 0);

  /* %  compute quintic 5th order polynomial coefs */
  /*    By Long Wang, 2017/2/6 */
  /*    This func computes the quintic 5th order polynomial interpolation based */
  /*    on Nabil Simaa's notes. */
  /* %  Inputs:  */
  /*    q0_vec = [q0, q0dot,q0ddot]'; */
  /*    qf_vec = [qf, qfdot,qfddot]'; */
  /*    tf - the relative time from q0 to qf. */
  /* %  Notest on time */
  /*    In Nabil's notes, a normalized interpolation eta was used. */
  /*    In this version of code, absolute time is used because it is easier in */
  /*    the case where the final velocity goal is not zero. */
  /*    So the output coefs, they are corresponding to abosolute time. */
  _SFD_SCRIPT_CALL(1,16);
  c9_a = c9_tf;
  c9_c = c9_power(chartInstance, c9_a, 2.0);
  c9_b_a = c9_tf;
  c9_b_c = c9_power(chartInstance, c9_b_a, 3.0);
  c9_c_a = c9_tf;
  c9_c_c = c9_power(chartInstance, c9_c_a, 4.0);
  c9_d_a = c9_tf;
  c9_d_c = c9_power(chartInstance, c9_d_a, 5.0);
  c9_b = c9_tf;
  c9_y = 2.0 * c9_b;
  c9_e_a = c9_tf;
  c9_e_c = c9_power(chartInstance, c9_e_a, 2.0);
  c9_b_b = c9_e_c;
  c9_b_y = 3.0 * c9_b_b;
  c9_f_a = c9_tf;
  c9_f_c = c9_power(chartInstance, c9_f_a, 3.0);
  c9_c_b = c9_f_c;
  c9_c_y = 4.0 * c9_c_b;
  c9_g_a = c9_tf;
  c9_g_c = c9_power(chartInstance, c9_g_a, 4.0);
  c9_d_b = c9_g_c;
  c9_d_y = 5.0 * c9_d_b;
  c9_e_b = c9_tf;
  c9_e_y = 6.0 * c9_e_b;
  c9_h_a = c9_tf;
  c9_h_c = c9_power(chartInstance, c9_h_a, 2.0);
  c9_f_b = c9_h_c;
  c9_f_y = 12.0 * c9_f_b;
  c9_i_a = c9_tf;
  c9_i_c = c9_power(chartInstance, c9_i_a, 3.0);
  c9_g_b = c9_i_c;
  c9_g_y = 20.0 * c9_g_b;
  c9_i62 = 0;
  for (c9_i63 = 0; c9_i63 < 6; c9_i63 = c9_i63 + 1) {
    c9_A[c9_i62] = c9_dv9[c9_i63];
    c9_i62 = c9_i62 + 6;
  }

  c9_A[1] = 1.0;
  c9_A[7] = c9_tf;
  c9_A[13] = c9_c;
  c9_A[19] = c9_b_c;
  c9_A[25] = c9_c_c;
  c9_A[31] = c9_d_c;
  c9_i64 = 0;
  for (c9_i65 = 0; c9_i65 < 6; c9_i65 = c9_i65 + 1) {
    c9_A[c9_i64 + 2] = c9_dv10[c9_i65];
    c9_i64 = c9_i64 + 6;
  }

  c9_A[3] = 0.0;
  c9_A[9] = 1.0;
  c9_A[15] = c9_y;
  c9_A[21] = c9_b_y;
  c9_A[27] = c9_c_y;
  c9_A[33] = c9_d_y;
  c9_i66 = 0;
  for (c9_i67 = 0; c9_i67 < 6; c9_i67 = c9_i67 + 1) {
    c9_A[c9_i66 + 4] = c9_dv11[c9_i67];
    c9_i66 = c9_i66 + 6;
  }

  c9_A[5] = 0.0;
  c9_A[11] = 0.0;
  c9_A[17] = 2.0;
  c9_A[23] = c9_e_y;
  c9_A[29] = c9_f_y;
  c9_A[35] = c9_g_y;
  _SFD_SCRIPT_CALL(1,23);
  c9_b_vec[0] = c9_q0_vec[0];
  c9_b_vec[1] = c9_qf_vec[0];
  c9_b_vec[2] = c9_q0_vec[1];
  c9_b_vec[3] = c9_qf_vec[1];
  c9_b_vec[4] = c9_q0_vec[2];
  c9_b_vec[5] = c9_qf_vec[2];
  _SFD_SCRIPT_CALL(1,24);
  for (c9_i68 = 0; c9_i68 < 36; c9_i68 = c9_i68 + 1) {
    c9_b_A[c9_i68] = c9_A[c9_i68];
  }

  for (c9_i69 = 0; c9_i69 < 6; c9_i69 = c9_i69 + 1) {
    c9_b_b_vec[c9_i69] = c9_b_vec[c9_i69];
  }

  c9_mldivide(chartInstance, c9_b_A, c9_b_b_vec, c9_dv12);
  for (c9_i70 = 0; c9_i70 < 6; c9_i70 = c9_i70 + 1) {
    c9_a_vec[c9_i70] = c9_dv12[c9_i70];
  }

  _SFD_SCRIPT_CALL(1,-24);
  sf_debug_symbol_scope_pop();
}

static real_T c9_mpower(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a)
{
  return c9_power(chartInstance, c9_a, 2.0);
}

static real_T c9_power(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a, real_T c9_b)
{
  real_T c9_ak;
  real_T c9_bk;
  real_T c9_x;
  real_T c9_b_x;
  c9_eml_scalar_eg(chartInstance);
  c9_ak = c9_a;
  c9_bk = c9_b;
  if (c9_ak < 0.0) {
    c9_x = c9_bk;
    c9_b_x = c9_x;
    c9_b_x = muDoubleScalarFloor(c9_b_x);
    if (c9_b_x != c9_bk) {
      c9_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c9_ak, c9_bk);
}

static void c9_eml_scalar_eg(SFc9_large_snakeInstanceStruct *chartInstance)
{
}

static void c9_eml_error(SFc9_large_snakeInstanceStruct *chartInstance)
{
  int32_T c9_i71;
  static char_T c9_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c9_u[32];
  const mxArray *c9_y = NULL;
  int32_T c9_i72;
  static char_T c9_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
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

  char_T c9_b_u[102];
  const mxArray *c9_b_y = NULL;
  for (c9_i71 = 0; c9_i71 < 32; c9_i71 = c9_i71 + 1) {
    c9_u[c9_i71] = c9_cv0[c9_i71];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c9_i72 = 0; c9_i72 < 102; c9_i72 = c9_i72 + 1) {
    c9_b_u[c9_i72] = c9_cv1[c9_i72];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c9_y, 14, c9_b_y);
}

static real_T c9_b_mpower(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a)
{
  return c9_power(chartInstance, c9_a, 3.0);
}

static real_T c9_c_mpower(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a)
{
  return c9_power(chartInstance, c9_a, 4.0);
}

static real_T c9_d_mpower(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_a)
{
  return c9_power(chartInstance, c9_a, 5.0);
}

static void c9_mldivide(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_A[36], real_T c9_B[6], real_T c9_Y[6])
{
  int32_T c9_i73;
  real_T c9_b_A[36];
  int32_T c9_i74;
  real_T c9_b_B[6];
  int32_T c9_i75;
  real_T c9_c_A[36];
  int32_T c9_i76;
  real_T c9_c_B[6];
  int32_T c9_i77;
  real_T c9_d_A[36];
  int32_T c9_info;
  int32_T c9_ipiv[6];
  real_T c9_e_A[36];
  int32_T c9_i78;
  int32_T c9_i79;
  int32_T c9_b_ipiv[6];
  int32_T c9_b_info;
  int32_T c9_i80;
  int32_T c9_i;
  int32_T c9_b_i;
  int32_T c9_ip;
  real_T c9_temp;
  int32_T c9_i81;
  real_T c9_f_A[36];
  int32_T c9_i82;
  real_T c9_d_B[6];
  int32_T c9_i83;
  int32_T c9_i84;
  real_T c9_g_A[36];
  int32_T c9_i85;
  real_T c9_b_Y[6];
  int32_T c9_i86;
  real_T c9_h_A[36];
  int32_T c9_i87;
  real_T c9_e_B[6];
  int32_T c9_i88;
  int32_T c9_i89;
  real_T c9_i_A[36];
  int32_T c9_i90;
  real_T c9_c_Y[6];
  for (c9_i73 = 0; c9_i73 < 36; c9_i73 = c9_i73 + 1) {
    c9_b_A[c9_i73] = c9_A[c9_i73];
  }

  for (c9_i74 = 0; c9_i74 < 6; c9_i74 = c9_i74 + 1) {
    c9_b_B[c9_i74] = c9_B[c9_i74];
  }

  for (c9_i75 = 0; c9_i75 < 36; c9_i75 = c9_i75 + 1) {
    c9_c_A[c9_i75] = c9_b_A[c9_i75];
  }

  for (c9_i76 = 0; c9_i76 < 6; c9_i76 = c9_i76 + 1) {
    c9_c_B[c9_i76] = c9_b_B[c9_i76];
  }

  for (c9_i77 = 0; c9_i77 < 36; c9_i77 = c9_i77 + 1) {
    c9_d_A[c9_i77] = c9_c_A[c9_i77];
  }

  c9_eml_xgetrf(chartInstance, c9_d_A, c9_e_A, c9_ipiv, &c9_info);
  for (c9_i78 = 0; c9_i78 < 36; c9_i78 = c9_i78 + 1) {
    c9_c_A[c9_i78] = c9_e_A[c9_i78];
  }

  for (c9_i79 = 0; c9_i79 < 6; c9_i79 = c9_i79 + 1) {
    c9_b_ipiv[c9_i79] = c9_ipiv[c9_i79];
  }

  c9_b_info = c9_info;
  if ((real_T)c9_b_info > 0.0) {
    c9_eml_warning(chartInstance);
  }

  for (c9_i80 = 0; c9_i80 < 6; c9_i80 = c9_i80 + 1) {
    c9_Y[c9_i80] = c9_c_B[c9_i80];
  }

  for (c9_i = 1; c9_i < 7; c9_i = c9_i + 1) {
    c9_b_i = c9_i;
    if (c9_b_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c9_b_i), 1, 6, 1, 0) - 1] != c9_b_i) {
      c9_ip = c9_b_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c9_b_i), 1, 6, 1, 0) - 1];
      c9_temp = c9_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c9_b_i), 1, 6, 1, 0) - 1];
      c9_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c9_b_i), 1, 6, 1, 0) - 1] = c9_Y[
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c9_ip), 1, 6, 1, 0) - 1];
      c9_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c9_ip), 1, 6, 1, 0) - 1] = c9_temp;
    }
  }

  for (c9_i81 = 0; c9_i81 < 36; c9_i81 = c9_i81 + 1) {
    c9_f_A[c9_i81] = c9_c_A[c9_i81];
  }

  for (c9_i82 = 0; c9_i82 < 6; c9_i82 = c9_i82 + 1) {
    c9_d_B[c9_i82] = c9_Y[c9_i82];
  }

  for (c9_i83 = 0; c9_i83 < 6; c9_i83 = c9_i83 + 1) {
    c9_Y[c9_i83] = c9_d_B[c9_i83];
  }

  for (c9_i84 = 0; c9_i84 < 36; c9_i84 = c9_i84 + 1) {
    c9_g_A[c9_i84] = c9_f_A[c9_i84];
  }

  for (c9_i85 = 0; c9_i85 < 6; c9_i85 = c9_i85 + 1) {
    c9_b_Y[c9_i85] = c9_Y[c9_i85];
  }

  c9_eml_blas_xtrsm(chartInstance, 6, 1, 1.0, c9_g_A, 1, 6, c9_b_Y, 1, 6, c9_Y);
  for (c9_i86 = 0; c9_i86 < 36; c9_i86 = c9_i86 + 1) {
    c9_h_A[c9_i86] = c9_c_A[c9_i86];
  }

  for (c9_i87 = 0; c9_i87 < 6; c9_i87 = c9_i87 + 1) {
    c9_e_B[c9_i87] = c9_Y[c9_i87];
  }

  for (c9_i88 = 0; c9_i88 < 6; c9_i88 = c9_i88 + 1) {
    c9_Y[c9_i88] = c9_e_B[c9_i88];
  }

  for (c9_i89 = 0; c9_i89 < 36; c9_i89 = c9_i89 + 1) {
    c9_i_A[c9_i89] = c9_h_A[c9_i89];
  }

  for (c9_i90 = 0; c9_i90 < 6; c9_i90 = c9_i90 + 1) {
    c9_c_Y[c9_i90] = c9_Y[c9_i90];
  }

  c9_b_eml_blas_xtrsm(chartInstance, 6, 1, 1.0, c9_i_A, 1, 6, c9_c_Y, 1, 6, c9_Y);
}

static void c9_eml_xgetrf(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_A[36], real_T c9_b_A[36], int32_T c9_ipiv[6],
  int32_T *c9_info)
{
  int32_T c9_i91;
  int32_T c9_i92;
  int32_T c9_j;
  int32_T c9_b_j;
  int32_T c9_a;
  int32_T c9_jm1;
  int32_T c9_b;
  int32_T c9_mmj;
  int32_T c9_b_a;
  int32_T c9_c;
  int32_T c9_b_b;
  int32_T c9_jj;
  int32_T c9_c_a;
  int32_T c9_jp1j;
  int32_T c9_d_a;
  int32_T c9_b_c;
  int32_T c9_i93;
  real_T c9_c_A[36];
  int32_T c9_e_a;
  int32_T c9_jpiv_offset;
  int32_T c9_f_a;
  int32_T c9_c_b;
  int32_T c9_jpiv;
  int32_T c9_g_a;
  int32_T c9_d_b;
  int32_T c9_c_c;
  int32_T c9_e_b;
  int32_T c9_jrow;
  int32_T c9_h_a;
  int32_T c9_f_b;
  int32_T c9_jprow;
  int32_T c9_i94;
  real_T c9_x[36];
  int32_T c9_ix0;
  int32_T c9_iy0;
  int32_T c9_i95;
  int32_T c9_i96;
  real_T c9_b_x[36];
  int32_T c9_b_ix0;
  int32_T c9_b_iy0;
  int32_T c9_i97;
  real_T c9_c_x[36];
  int32_T c9_i98;
  real_T c9_d_x[36];
  real_T c9_e_x[36];
  int32_T c9_i99;
  int32_T c9_i100;
  int32_T c9_b_jp1j;
  int32_T c9_i_a;
  int32_T c9_d_c;
  int32_T c9_j_a;
  int32_T c9_g_b;
  int32_T c9_loop_ub;
  int32_T c9_i;
  int32_T c9_b_i;
  real_T c9_f_x;
  real_T c9_y;
  real_T c9_g_x;
  real_T c9_b_y;
  real_T c9_z;
  int32_T c9_h_b;
  int32_T c9_e_c;
  int32_T c9_k_a;
  int32_T c9_f_c;
  int32_T c9_l_a;
  int32_T c9_g_c;
  int32_T c9_m;
  int32_T c9_n;
  int32_T c9_c_ix0;
  int32_T c9_c_iy0;
  int32_T c9_i101;
  real_T c9_d_A[36];
  int32_T c9_ia0;
  int32_T c9_i102;
  int32_T c9_b_m;
  int32_T c9_b_n;
  int32_T c9_d_ix0;
  int32_T c9_d_iy0;
  int32_T c9_i103;
  real_T c9_e_A[36];
  int32_T c9_b_ia0;
  int32_T c9_i104;
  int32_T c9_c_m;
  int32_T c9_c_n;
  int32_T c9_e_ix0;
  int32_T c9_e_iy0;
  int32_T c9_i105;
  real_T c9_f_A[36];
  int32_T c9_c_ia0;
  int32_T c9_i106;
  int32_T c9_i107;
  real_T c9_g_A[36];
  for (c9_i91 = 0; c9_i91 < 36; c9_i91 = c9_i91 + 1) {
    c9_b_A[c9_i91] = c9_A[c9_i91];
  }

  for (c9_i92 = 0; c9_i92 < 6; c9_i92 = c9_i92 + 1) {
    c9_ipiv[c9_i92] = 1 + c9_i92;
  }

  *c9_info = 0;
  for (c9_j = 1; c9_j < 6; c9_j = c9_j + 1) {
    c9_b_j = c9_j;
    c9_a = c9_b_j;
    c9_jm1 = c9_a - 1;
    c9_b = c9_b_j;
    c9_mmj = 6 - c9_b;
    c9_b_a = c9_jm1;
    c9_c = c9_b_a * 7;
    c9_b_b = c9_c;
    c9_jj = 1 + c9_b_b;
    c9_c_a = c9_jj;
    c9_jp1j = c9_c_a + 1;
    c9_d_a = c9_mmj;
    c9_b_c = c9_d_a + 1;
    for (c9_i93 = 0; c9_i93 < 36; c9_i93 = c9_i93 + 1) {
      c9_c_A[c9_i93] = c9_b_A[c9_i93];
    }

    c9_e_a = c9_eml_ixamax(chartInstance, c9_b_c, c9_c_A, c9_jj);
    c9_jpiv_offset = c9_e_a - 1;
    c9_f_a = c9_jj;
    c9_c_b = c9_jpiv_offset;
    c9_jpiv = c9_f_a + c9_c_b;
    if (c9_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c9_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if ((real_T)c9_jpiv_offset != 0.0) {
        c9_g_a = c9_b_j;
        c9_d_b = c9_jpiv_offset;
        c9_c_c = c9_g_a + c9_d_b;
        c9_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c9_b_j), 1, 6, 1, 0) - 1] = c9_c_c;
        c9_e_b = c9_jm1;
        c9_jrow = 1 + c9_e_b;
        c9_h_a = c9_jrow;
        c9_f_b = c9_jpiv_offset;
        c9_jprow = c9_h_a + c9_f_b;
        for (c9_i94 = 0; c9_i94 < 36; c9_i94 = c9_i94 + 1) {
          c9_x[c9_i94] = c9_b_A[c9_i94];
        }

        c9_ix0 = c9_jrow;
        c9_iy0 = c9_jprow;
        for (c9_i95 = 0; c9_i95 < 36; c9_i95 = c9_i95 + 1) {
          c9_b_A[c9_i95] = c9_x[c9_i95];
        }

        for (c9_i96 = 0; c9_i96 < 36; c9_i96 = c9_i96 + 1) {
          c9_b_x[c9_i96] = c9_b_A[c9_i96];
        }

        c9_b_ix0 = c9_ix0;
        c9_b_iy0 = c9_iy0;
        for (c9_i97 = 0; c9_i97 < 36; c9_i97 = c9_i97 + 1) {
          c9_c_x[c9_i97] = c9_b_x[c9_i97];
        }

        for (c9_i98 = 0; c9_i98 < 36; c9_i98 = c9_i98 + 1) {
          c9_d_x[c9_i98] = c9_c_x[c9_i98];
        }

        c9_ceval_xswap(chartInstance, 6, c9_d_x, c9_b_ix0, 6, c9_b_iy0, 6,
                       c9_e_x);
        for (c9_i99 = 0; c9_i99 < 36; c9_i99 = c9_i99 + 1) {
          c9_c_x[c9_i99] = c9_e_x[c9_i99];
        }

        for (c9_i100 = 0; c9_i100 < 36; c9_i100 = c9_i100 + 1) {
          c9_b_A[c9_i100] = c9_c_x[c9_i100];
        }
      }

      c9_b_jp1j = c9_jp1j;
      c9_i_a = c9_mmj;
      c9_d_c = c9_i_a - 1;
      c9_j_a = c9_jp1j;
      c9_g_b = c9_d_c;
      c9_loop_ub = c9_j_a + c9_g_b;
      for (c9_i = c9_b_jp1j; c9_i <= c9_loop_ub; c9_i = c9_i + 1) {
        c9_b_i = c9_i;
        c9_f_x = c9_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c9_b_i), 1, 36, 1, 0) - 1];
        c9_y = c9_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c9_jj), 1, 36, 1, 0) - 1];
        c9_g_x = c9_f_x;
        c9_b_y = c9_y;
        c9_z = c9_g_x / c9_b_y;
        c9_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c9_b_i), 1, 36, 1, 0) - 1] = c9_z;
      }
    } else {
      *c9_info = c9_b_j;
    }

    c9_h_b = c9_b_j;
    c9_e_c = 6 - c9_h_b;
    c9_k_a = c9_jj;
    c9_f_c = c9_k_a + 6;
    c9_l_a = c9_jj;
    c9_g_c = c9_l_a + 7;
    c9_m = c9_mmj;
    c9_n = c9_e_c;
    c9_c_ix0 = c9_jp1j;
    c9_c_iy0 = c9_f_c;
    for (c9_i101 = 0; c9_i101 < 36; c9_i101 = c9_i101 + 1) {
      c9_d_A[c9_i101] = c9_b_A[c9_i101];
    }

    c9_ia0 = c9_g_c;
    for (c9_i102 = 0; c9_i102 < 36; c9_i102 = c9_i102 + 1) {
      c9_b_A[c9_i102] = c9_d_A[c9_i102];
    }

    c9_b_m = c9_m;
    c9_b_n = c9_n;
    c9_d_ix0 = c9_c_ix0;
    c9_d_iy0 = c9_c_iy0;
    for (c9_i103 = 0; c9_i103 < 36; c9_i103 = c9_i103 + 1) {
      c9_e_A[c9_i103] = c9_b_A[c9_i103];
    }

    c9_b_ia0 = c9_ia0;
    for (c9_i104 = 0; c9_i104 < 36; c9_i104 = c9_i104 + 1) {
      c9_b_A[c9_i104] = c9_e_A[c9_i104];
    }

    c9_c_m = c9_b_m;
    c9_c_n = c9_b_n;
    c9_e_ix0 = c9_d_ix0;
    c9_e_iy0 = c9_d_iy0;
    for (c9_i105 = 0; c9_i105 < 36; c9_i105 = c9_i105 + 1) {
      c9_f_A[c9_i105] = c9_b_A[c9_i105];
    }

    c9_c_ia0 = c9_b_ia0;
    for (c9_i106 = 0; c9_i106 < 36; c9_i106 = c9_i106 + 1) {
      c9_b_A[c9_i106] = c9_f_A[c9_i106];
    }

    if ((real_T)c9_c_m < 1.0) {
    } else if ((real_T)c9_c_n < 1.0) {
    } else {
      for (c9_i107 = 0; c9_i107 < 36; c9_i107 = c9_i107 + 1) {
        c9_g_A[c9_i107] = c9_b_A[c9_i107];
      }

      c9_ceval_xger(chartInstance, c9_c_m, c9_c_n, -1.0, c9_e_ix0, 1, c9_e_iy0,
                    6, c9_g_A, c9_c_ia0, 6, c9_b_A);
      goto label_1;
    }

   label_1:
    ;
  }

  if ((real_T)*c9_info == 0.0) {
    if (!(c9_b_A[35] != 0.0)) {
      *c9_info = 6;
      return;
    }
  }
}

static int32_T c9_eml_ixamax(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[36], int32_T c9_ix0)
{
  int32_T c9_b_n;
  int32_T c9_i108;
  real_T c9_b_x[36];
  int32_T c9_b_ix0;
  int32_T c9_i109;
  real_T c9_c_x[36];
  c9_b_n = c9_n;
  for (c9_i108 = 0; c9_i108 < 36; c9_i108 = c9_i108 + 1) {
    c9_b_x[c9_i108] = c9_x[c9_i108];
  }

  c9_b_ix0 = c9_ix0;
  for (c9_i109 = 0; c9_i109 < 36; c9_i109 = c9_i109 + 1) {
    c9_c_x[c9_i109] = c9_b_x[c9_i109];
  }

  return c9_ceval_ixamax(chartInstance, c9_b_n, c9_c_x, c9_b_ix0, 1);
}

static int32_T c9_ceval_ixamax(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[36], int32_T c9_ix0, int32_T
  c9_incx)
{
  return idamax32(&c9_n, &c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c9_ix0), 1, 36, 1, 0) - 1], &
                  c9_incx);
}

static void c9_ceval_xswap(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[36], int32_T c9_ix0, int32_T
  c9_incx, int32_T c9_iy0, int32_T c9_incy, real_T c9_b_x[36])
{
  int32_T c9_i110;

  /* Empty Loop. */
  for (c9_i110 = 0; c9_i110 < 36; c9_i110 = c9_i110 + 1) {
    c9_b_x[c9_i110] = c9_x[c9_i110];
  }

  dswap32(&c9_n, &c9_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c9_ix0), 1, 36, 1, 0) - 1], &c9_incx
          , &c9_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c9_iy0), 1, 36, 1, 0) - 1], &c9_incy);
}

static void c9_ceval_xger(SFc9_large_snakeInstanceStruct *chartInstance, int32_T
  c9_m, int32_T c9_n, real_T c9_alpha1, int32_T
  c9_ix0, int32_T c9_incx, int32_T c9_iy0, int32_T c9_incy, real_T c9_A[36],
  int32_T c9_ia0, int32_T c9_lda, real_T c9_b_A[36])
{
  int32_T c9_i111;
  for (c9_i111 = 0; c9_i111 < 36; c9_i111 = c9_i111 + 1) {
    c9_b_A[c9_i111] = c9_A[c9_i111];
  }

  dger32(&c9_m, &c9_n, &c9_alpha1, &c9_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c9_ix0), 1, 36, 1,
          0) - 1], &c9_incx, &c9_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c9_iy0), 1, 36, 1, 0) - 1], &
         c9_incy, &c9_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c9_ia0), 1, 36, 1, 0) - 1], &c9_lda);
}

static void c9_eml_warning(SFc9_large_snakeInstanceStruct *chartInstance)
{
  int32_T c9_i112;
  static char_T c9_cv2[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x'
  };

  char_T c9_u[21];
  const mxArray *c9_y = NULL;
  int32_T c9_i113;
  static char_T c9_cv3[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o'
    , ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char_T c9_b_u[40];
  const mxArray *c9_b_y = NULL;
  for (c9_i112 = 0; c9_i112 < 21; c9_i112 = c9_i112 + 1) {
    c9_u[c9_i112] = c9_cv2[c9_i112];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c9_i113 = 0; c9_i113 < 40; c9_i113 = c9_i113 + 1) {
    c9_b_u[c9_i113] = c9_cv3[c9_i113];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c9_y, 14, c9_b_y);
}

static void c9_eml_blas_xtrsm(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_m, int32_T c9_n, real_T c9_alpha1, real_T
  c9_A[36], int32_T c9_ia0, int32_T c9_lda, real_T c9_B[6], int32_T c9_ib0,
  int32_T c9_ldb, real_T c9_b_B[6])
{
  int32_T c9_i114;
  int32_T c9_i115;
  real_T c9_b_A[36];
  int32_T c9_i116;
  real_T c9_c_B[6];
  for (c9_i114 = 0; c9_i114 < 6; c9_i114 = c9_i114 + 1) {
    c9_b_B[c9_i114] = c9_B[c9_i114];
  }

  for (c9_i115 = 0; c9_i115 < 36; c9_i115 = c9_i115 + 1) {
    c9_b_A[c9_i115] = c9_A[c9_i115];
  }

  for (c9_i116 = 0; c9_i116 < 6; c9_i116 = c9_i116 + 1) {
    c9_c_B[c9_i116] = c9_b_B[c9_i116];
  }

  c9_ceval_xtrsm(chartInstance, c9_m, c9_n, c9_alpha1, c9_b_A, c9_ia0, c9_lda,
                 c9_c_B, c9_ib0, c9_ldb, c9_b_B);
}

static void c9_ceval_xtrsm(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_m, int32_T c9_n, real_T c9_alpha1, real_T c9_A[
  36], int32_T c9_ia0, int32_T c9_lda, real_T c9_B[6], int32_T c9_ib0, int32_T
  c9_ldb, real_T c9_b_B[6])
{
  char_T c9_SIDE;
  char_T c9_UPLO;
  char_T c9_TRANSA;
  char_T c9_DIAGA;
  int32_T c9_i117;
  c9_SIDE = 'L';
  c9_UPLO = 'L';
  c9_TRANSA = 'N';
  c9_DIAGA = 'U';
  for (c9_i117 = 0; c9_i117 < 6; c9_i117 = c9_i117 + 1) {
    c9_b_B[c9_i117] = c9_B[c9_i117];
  }

  dtrsm32(&c9_SIDE, &c9_UPLO, &c9_TRANSA, &c9_DIAGA, &c9_m, &c9_n, &c9_alpha1,
          &c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c9_ia0), 1, 36, 1, 0) - 1], &c9_lda,
          &c9_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c9_ib0), 1, 6, 1, 0) - 1], &c9_ldb);
}

static void c9_b_eml_blas_xtrsm(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_m, int32_T c9_n, real_T c9_alpha1, real_T
  c9_A[36], int32_T c9_ia0, int32_T c9_lda, real_T c9_B[6], int32_T c9_ib0,
  int32_T c9_ldb, real_T c9_b_B[6])
{
  int32_T c9_i118;
  int32_T c9_i119;
  real_T c9_b_A[36];
  int32_T c9_i120;
  real_T c9_c_B[6];
  for (c9_i118 = 0; c9_i118 < 6; c9_i118 = c9_i118 + 1) {
    c9_b_B[c9_i118] = c9_B[c9_i118];
  }

  for (c9_i119 = 0; c9_i119 < 36; c9_i119 = c9_i119 + 1) {
    c9_b_A[c9_i119] = c9_A[c9_i119];
  }

  for (c9_i120 = 0; c9_i120 < 6; c9_i120 = c9_i120 + 1) {
    c9_c_B[c9_i120] = c9_b_B[c9_i120];
  }

  c9_b_ceval_xtrsm(chartInstance, c9_m, c9_n, c9_alpha1, c9_b_A, c9_ia0, c9_lda,
                   c9_c_B, c9_ib0, c9_ldb, c9_b_B);
}

static void c9_b_ceval_xtrsm(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_m, int32_T c9_n, real_T c9_alpha1, real_T
  c9_A[36], int32_T c9_ia0, int32_T c9_lda, real_T c9_B[6], int32_T c9_ib0,
  int32_T c9_ldb, real_T c9_b_B[6])
{
  char_T c9_SIDE;
  char_T c9_UPLO;
  char_T c9_TRANSA;
  char_T c9_DIAGA;
  int32_T c9_i121;
  c9_SIDE = 'L';
  c9_UPLO = 'U';
  c9_TRANSA = 'N';
  c9_DIAGA = 'N';
  for (c9_i121 = 0; c9_i121 < 6; c9_i121 = c9_i121 + 1) {
    c9_b_B[c9_i121] = c9_B[c9_i121];
  }

  dtrsm32(&c9_SIDE, &c9_UPLO, &c9_TRANSA, &c9_DIAGA, &c9_m, &c9_n, &c9_alpha1,
          &c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c9_ia0), 1, 36, 1, 0) - 1], &c9_lda,
          &c9_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c9_ib0), 1, 6, 1, 0) - 1], &c9_ldb);
}

static void c9_interp_quintic_5th_poly(SFc9_large_snakeInstanceStruct
  *chartInstance, real_T c9_a_vec[6], real_T c9_t, real_T c9_tf
  , real_T *c9_q_cur, real_T *c9_q_dot)
{
  uint32_T c9_debug_family_var_map[8];
  static const char *c9_sv4[8] = { "func_basis", "nargin", "nargout", "a_vec",
    "t", "tf", "q_cur", "q_dot" };

  real_T c9_func_basis[6];
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 2.0;
  real_T c9_d0;
  real_T c9_d1;
  real_T c9_d2;
  real_T c9_d3;
  int32_T c9_i122;
  real_T c9_a[6];
  int32_T c9_i123;
  real_T c9_b[6];
  int32_T c9_i124;
  real_T c9_x[6];
  int32_T c9_i125;
  real_T c9_y[6];
  int32_T c9_i126;
  real_T c9_b_x[6];
  int32_T c9_i127;
  real_T c9_b_y[6];
  int32_T c9_i128;
  real_T c9_c_x[6];
  int32_T c9_i129;
  real_T c9_c_y[6];
  int32_T c9_i130;
  real_T c9_d_x[6];
  int32_T c9_i131;
  real_T c9_d_y[6];
  int32_T c9_i132;
  real_T c9_b_a[5];
  int32_T c9_i133;
  real_T c9_A[5];
  int32_T c9_i134;
  real_T c9_b_A[5];
  int32_T c9_i135;
  real_T c9_c_A[5];
  int32_T c9_i136;
  int32_T c9_i137;
  real_T c9_e_y[5];
  int32_T c9_i138;
  static real_T c9_dv13[25] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 5.0 };

  int32_T c9_i139;
  real_T c9_c_a[5];
  int32_T c9_i140;
  real_T c9_b_b[5];
  int32_T c9_i141;
  real_T c9_e_x[5];
  int32_T c9_i142;
  real_T c9_f_y[5];
  int32_T c9_i143;
  real_T c9_f_x[5];
  int32_T c9_i144;
  real_T c9_g_y[5];
  int32_T c9_i145;
  real_T c9_g_x[5];
  int32_T c9_i146;
  real_T c9_h_y[5];
  int32_T c9_i147;
  real_T c9_h_x[5];
  int32_T c9_i148;
  real_T c9_i_y[5];
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c9_sv4, c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c9_func_basis, c9_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c9_nargin, c9_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c9_nargout, c9_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c9_a_vec, c9_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c9_t, c9_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c9_tf, c9_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c9_q_cur, c9_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c9_q_dot, c9_d_sf_marshall, 7U);
  CV_SCRIPT_FCN(2, 0);

  /* %  compute quintic 5th order polynomial coefs */
  /*    By Long Wang, 2017/2/6 */
  /*    This func computes the quintic 5th order polynomial interpolation based */
  /*    on Nabil Simaa's notes. */
  /* %  Inputs: */
  /*    a_vec - the calculated 5th order poly coefs */
  /*    t_cur - the current time of this polynomial */
  /*    tf - the final time of this polynomial. */
  /* %  Notest on time */
  /*    In Nabil's notes, a normalized interpolation eta was used. */
  /*    In this version of code, the same normalization method is used. */
  /*    So the output coefs, they are corresponding to normalized time. */
  _SFD_SCRIPT_CALL(2,15);
  if (CV_SCRIPT_IF(2, 0, c9_t > c9_tf)) {
    _SFD_SCRIPT_CALL(2,16);
    c9_t = c9_tf;
  }

  /*  eta = t_cur/tf; */
  /*  func_basis = [1;eta;eta^2;eta^3;eta^4;eta^5]; */
  _SFD_SCRIPT_CALL(2,20);
  c9_d0 = c9_mpower(chartInstance, c9_t);
  c9_d1 = c9_b_mpower(chartInstance, c9_t);
  c9_d2 = c9_c_mpower(chartInstance, c9_t);
  c9_d3 = c9_d_mpower(chartInstance, c9_t);
  c9_func_basis[0] = 1.0;
  c9_func_basis[1] = c9_t;
  c9_func_basis[2] = c9_d0;
  c9_func_basis[3] = c9_d1;
  c9_func_basis[4] = c9_d2;
  c9_func_basis[5] = c9_d3;
  _SFD_SCRIPT_CALL(2,21);
  for (c9_i122 = 0; c9_i122 < 6; c9_i122 = c9_i122 + 1) {
    c9_a[c9_i122] = c9_a_vec[c9_i122];
  }

  for (c9_i123 = 0; c9_i123 < 6; c9_i123 = c9_i123 + 1) {
    c9_b[c9_i123] = c9_func_basis[c9_i123];
  }

  c9_b_eml_scalar_eg(chartInstance);
  for (c9_i124 = 0; c9_i124 < 6; c9_i124 = c9_i124 + 1) {
    c9_x[c9_i124] = c9_a[c9_i124];
  }

  for (c9_i125 = 0; c9_i125 < 6; c9_i125 = c9_i125 + 1) {
    c9_y[c9_i125] = c9_b[c9_i125];
  }

  for (c9_i126 = 0; c9_i126 < 6; c9_i126 = c9_i126 + 1) {
    c9_b_x[c9_i126] = c9_x[c9_i126];
  }

  for (c9_i127 = 0; c9_i127 < 6; c9_i127 = c9_i127 + 1) {
    c9_b_y[c9_i127] = c9_y[c9_i127];
  }

  for (c9_i128 = 0; c9_i128 < 6; c9_i128 = c9_i128 + 1) {
    c9_c_x[c9_i128] = c9_b_x[c9_i128];
  }

  for (c9_i129 = 0; c9_i129 < 6; c9_i129 = c9_i129 + 1) {
    c9_c_y[c9_i129] = c9_b_y[c9_i129];
  }

  for (c9_i130 = 0; c9_i130 < 6; c9_i130 = c9_i130 + 1) {
    c9_d_x[c9_i130] = c9_c_x[c9_i130];
  }

  for (c9_i131 = 0; c9_i131 < 6; c9_i131 = c9_i131 + 1) {
    c9_d_y[c9_i131] = c9_c_y[c9_i131];
  }

  *c9_q_cur = c9_ceval_xdot(chartInstance, 6, c9_d_x, 1, 1, c9_d_y, 1, 1);
  _SFD_SCRIPT_CALL(2,22);
  for (c9_i132 = 0; c9_i132 < 5; c9_i132 = c9_i132 + 1) {
    c9_b_a[c9_i132] = c9_a_vec[c9_i132 + 1];
  }

  c9_c_eml_scalar_eg(chartInstance);
  c9_c_eml_scalar_eg(chartInstance);
  for (c9_i133 = 0; c9_i133 < 5; c9_i133 = c9_i133 + 1) {
    c9_A[c9_i133] = c9_b_a[c9_i133];
  }

  for (c9_i134 = 0; c9_i134 < 5; c9_i134 = c9_i134 + 1) {
    c9_b_A[c9_i134] = c9_A[c9_i134];
  }

  for (c9_i135 = 0; c9_i135 < 5; c9_i135 = c9_i135 + 1) {
    c9_c_A[c9_i135] = c9_b_A[c9_i135];
  }

  c9_i136 = 0;
  for (c9_i137 = 0; c9_i137 < 5; c9_i137 = c9_i137 + 1) {
    c9_e_y[c9_i137] = 0.0;
    for (c9_i138 = 0; c9_i138 < 5; c9_i138 = c9_i138 + 1) {
      c9_e_y[c9_i137] = c9_e_y[c9_i137] + c9_c_A[c9_i138] * c9_dv13[c9_i138 +
        c9_i136];
    }

    c9_i136 = c9_i136 + 5;
  }

  for (c9_i139 = 0; c9_i139 < 5; c9_i139 = c9_i139 + 1) {
    c9_c_a[c9_i139] = c9_e_y[c9_i139];
  }

  for (c9_i140 = 0; c9_i140 < 5; c9_i140 = c9_i140 + 1) {
    c9_b_b[c9_i140] = c9_func_basis[c9_i140];
  }

  c9_d_eml_scalar_eg(chartInstance);
  for (c9_i141 = 0; c9_i141 < 5; c9_i141 = c9_i141 + 1) {
    c9_e_x[c9_i141] = c9_c_a[c9_i141];
  }

  for (c9_i142 = 0; c9_i142 < 5; c9_i142 = c9_i142 + 1) {
    c9_f_y[c9_i142] = c9_b_b[c9_i142];
  }

  for (c9_i143 = 0; c9_i143 < 5; c9_i143 = c9_i143 + 1) {
    c9_f_x[c9_i143] = c9_e_x[c9_i143];
  }

  for (c9_i144 = 0; c9_i144 < 5; c9_i144 = c9_i144 + 1) {
    c9_g_y[c9_i144] = c9_f_y[c9_i144];
  }

  for (c9_i145 = 0; c9_i145 < 5; c9_i145 = c9_i145 + 1) {
    c9_g_x[c9_i145] = c9_f_x[c9_i145];
  }

  for (c9_i146 = 0; c9_i146 < 5; c9_i146 = c9_i146 + 1) {
    c9_h_y[c9_i146] = c9_g_y[c9_i146];
  }

  for (c9_i147 = 0; c9_i147 < 5; c9_i147 = c9_i147 + 1) {
    c9_h_x[c9_i147] = c9_g_x[c9_i147];
  }

  for (c9_i148 = 0; c9_i148 < 5; c9_i148 = c9_i148 + 1) {
    c9_i_y[c9_i148] = c9_h_y[c9_i148];
  }

  *c9_q_dot = c9_b_ceval_xdot(chartInstance, 5, c9_h_x, 1, 1, c9_i_y, 1, 1);
  _SFD_SCRIPT_CALL(2,-22);
  sf_debug_symbol_scope_pop();
}

static void c9_b_eml_scalar_eg(SFc9_large_snakeInstanceStruct *chartInstance)
{
}

static real_T c9_ceval_xdot(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[6], int32_T c9_ix0, int32_T
  c9_incx, real_T c9_y[6], int32_T c9_iy0, int32_T c9_incy)
{
  real_T c9_d;
  c9_d = 0.0;
  if ((real_T)c9_n > 0.0) {
    return ddot32(&c9_n, &c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c9_ix0), 1, 6, 1, 0) - 1], &
                  c9_incx, &c9_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c9_iy0), 1, 6, 1, 0) - 1], &c9_incy);
  }

  return c9_d;
}

static void c9_c_eml_scalar_eg(SFc9_large_snakeInstanceStruct *chartInstance)
{
}

static void c9_d_eml_scalar_eg(SFc9_large_snakeInstanceStruct *chartInstance)
{
}

static real_T c9_b_ceval_xdot(SFc9_large_snakeInstanceStruct *chartInstance,
  int32_T c9_n, real_T c9_x[5], int32_T c9_ix0, int32_T
  c9_incx, real_T c9_y[5], int32_T c9_iy0, int32_T c9_incy)
{
  real_T c9_d;
  c9_d = 0.0;
  if ((real_T)c9_n > 0.0) {
    return ddot32(&c9_n, &c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c9_ix0), 1, 5, 1, 0) - 1], &
                  c9_incx, &c9_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c9_iy0), 1, 5, 1, 0) - 1], &c9_incy);
  }

  return c9_d;
}

static real_T c9_interp1(SFc9_large_snakeInstanceStruct *chartInstance, real_T
  c9_varargin_1[2], real_T c9_varargin_2[2], real_T
  c9_varargin_3)
{
  real_T c9_yi;
  int32_T c9_i149;
  real_T c9_y[2];
  real_T c9_xi;
  int32_T c9_i150;
  real_T c9_x[2];
  int32_T c9_k;
  int32_T c9_b_k;
  real_T c9_b_x;
  boolean_T c9_b;
  int32_T c9_i151;
  real_T c9_c_x[2];
  int32_T c9_i152;
  int32_T c9_i153;
  real_T c9_d_x[2];
  int32_T c9_i154;
  real_T c9_xtmp;
  real_T c9_xlo;
  real_T c9_xhi;
  real_T c9_r;
  int32_T c9_n;
  int32_T c9_i155;
  real_T c9_e_x[2];
  real_T c9_b_xi;
  uint32_T c9_low_i;
  uint32_T c9_low_ip1;
  uint32_T c9_high_i;
  uint32_T c9_b_low_i;
  uint32_T c9_b_high_i;
  uint32_T c9_mid_i;
  uint32_T c9_u0;
  int32_T c9_i156;
  real_T c9_xn;
  int32_T c9_a;
  int32_T c9_c;
  int32_T c9_iy;
  int32_T c9_b_a;
  int32_T c9_b_c;
  real_T c9_c_a;
  real_T c9_b_b;
  real_T c9_b_y;
  for (c9_i149 = 0; c9_i149 < 2; c9_i149 = c9_i149 + 1) {
    c9_y[c9_i149] = c9_varargin_2[c9_i149];
  }

  c9_xi = c9_varargin_3;
  for (c9_i150 = 0; c9_i150 < 2; c9_i150 = c9_i150 + 1) {
    c9_x[c9_i150] = c9_varargin_1[c9_i150];
  }

  c9_yi = rtNaN;
  c9_k = 1;
 label_1:
  ;
  if (c9_k < 3) {
    c9_b_k = c9_k;
    c9_b_x = c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c9_b_k), 1, 2, 1, 0) - 1];
    c9_b = muDoubleScalarIsNaN(c9_b_x);
    if (c9_b) {
      c9_b_eml_error(chartInstance);
    } else {
      c9_k = c9_k + 1;
      goto label_1;
    }
  } else {
    if (c9_x[1] < c9_x[0]) {
      for (c9_i151 = 0; c9_i151 < 2; c9_i151 = c9_i151 + 1) {
        c9_c_x[c9_i151] = c9_x[(-c9_i151) + 1];
      }

      for (c9_i152 = 0; c9_i152 < 2; c9_i152 = c9_i152 + 1) {
        c9_x[c9_i152] = c9_c_x[c9_i152];
      }

      for (c9_i153 = 0; c9_i153 < 2; c9_i153 = c9_i153 + 1) {
        c9_d_x[c9_i153] = c9_y[c9_i153];
      }

      for (c9_i154 = 0; c9_i154 < 2; c9_i154 = c9_i154 + 1) {
        c9_y[c9_i154] = c9_d_x[c9_i154];
      }

      c9_xtmp = c9_y[0];
      c9_y[0] = c9_y[1];
      c9_y[1] = c9_xtmp;
    }

    if (c9_x[1] <= c9_x[0]) {
      c9_c_eml_error(chartInstance);
    }

    c9_xlo = c9_x[0];
    c9_xhi = c9_x[1];
    c9_r = 0.0;
    c9_n = 0;
    if (c9_xi > c9_xhi) {
    } else if (c9_xi < c9_xlo) {
    } else {
      for (c9_i155 = 0; c9_i155 < 2; c9_i155 = c9_i155 + 1) {
        c9_e_x[c9_i155] = c9_x[c9_i155];
      }

      c9_b_xi = c9_xi;
      c9_low_i = 1U;
      c9_low_ip1 = 2U;
      c9_high_i = 2U;
      while (c9_high_i > c9_low_ip1) {
        c9_b_low_i = c9_low_i;
        c9_b_high_i = c9_high_i;
        c9_mid_i = (c9_b_low_i + c9_b_high_i) >> 1U;
        if (c9_b_xi >= c9_e_x[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c9_mid_i)
             , 1, 2, 1, 0) - 1]) {
          c9_low_i = c9_mid_i;
          c9_low_ip1 = c9_low_i + 1U;
        } else {
          c9_high_i = c9_mid_i;
        }
      }

      c9_u0 = c9_low_i;
      if (c9_u0 > 2147483647U) {
        c9_i156 = MAX_int32_T;
      } else {
        c9_i156 = (int32_T)c9_u0;
      }

      c9_n = c9_i156;
      c9_xn = c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c9_n), 1, 2, 1, 0) - 1];
      c9_a = c9_n;
      c9_c = c9_a + 1;
      c9_r = (c9_xi - c9_xn) / (c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c9_c), 1, 2, 1, 0) - 1] -
        c9_xn);
    }

    if (c9_n > 0) {
      c9_iy = c9_n;
      c9_b_a = c9_iy;
      c9_b_c = c9_b_a + 1;
      c9_c_a = c9_r;
      c9_b_b = c9_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c9_b_c), 1, 2, 1, 0) - 1] - c9_y[
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c9_iy), 1, 2, 1, 0) - 1];
      c9_b_y = c9_c_a * c9_b_b;
      return c9_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c9_iy), 1, 2, 1, 0) - 1] + c9_b_y;
    }
  }

  return c9_yi;
}

static void c9_b_eml_error(SFc9_large_snakeInstanceStruct *chartInstance)
{
  int32_T c9_i157;
  static char_T c9_cv4[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't',
    'e', 'r', 'p', '1', ':', 'N', 'a', 'N', 'i', 'n', 'X'
  };

  char_T c9_u[21];
  const mxArray *c9_y = NULL;
  int32_T c9_i158;
  static char_T c9_cv5[38] = { 'N', 'a', 'N', ' ', 'i', 's', ' ', 'n', 'o', 't',
    ' ', 'a', 'n', ' ', 'a', 'p', 'p', 'r', 'o', 'p', 'r'
    , 'i', 'a', 't', 'e', ' ', 'v', 'a', 'l', 'u', 'e', ' ', 'f', 'o', 'r', ' ',
    'X', '.' };

  char_T c9_b_u[38];
  const mxArray *c9_b_y = NULL;
  for (c9_i157 = 0; c9_i157 < 21; c9_i157 = c9_i157 + 1) {
    c9_u[c9_i157] = c9_cv4[c9_i157];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c9_i158 = 0; c9_i158 < 38; c9_i158 = c9_i158 + 1) {
    c9_b_u[c9_i158] = c9_cv5[c9_i158];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 10, 0U, 1U, 0U, 2, 1, 38));
  sf_mex_call_debug("error", 0U, 2U, 14, c9_y, 14, c9_b_y);
}

static void c9_c_eml_error(SFc9_large_snakeInstanceStruct *chartInstance)
{
  int32_T c9_i159;
  static char_T c9_cv6[36] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'n', 't', 'e', 'r', 'p'
    , '1', ':', 'n', 'o', 'n', 'M', 'o', 'n', 'o', 't', 'o', 'n', 'i', 'c', 'X'
  };

  char_T c9_u[36];
  const mxArray *c9_y = NULL;
  int32_T c9_i160;
  static char_T c9_cv7[61] = { 'T', 'h', 'e', ' ', 'd', 'a', 't', 'a', ' ', 'a',
    'b', 's', 'c', 'i', 's', 's', 'a', 'e', ' ', 's', 'h'
    , 'o', 'u', 'l', 'd', ' ', 'b', 'e', ' ', 'd', 'i', 's', 't', 'i', 'n', 'c',
    't', ' ', 'a', 'n', 'd',
    ' ', 's', 't', 'r', 'i', 'c', 't', 'l', 'y', ' ', 'm', 'o', 'n', 'o', 't',
    'o', 'n', 'i', 'c', '.' };

  char_T c9_b_u[61];
  const mxArray *c9_b_y = NULL;
  for (c9_i159 = 0; c9_i159 < 36; c9_i159 = c9_i159 + 1) {
    c9_u[c9_i159] = c9_cv6[c9_i159];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 1U, 0U, 2, 1, 36));
  for (c9_i160 = 0; c9_i160 < 61; c9_i160 = c9_i160 + 1) {
    c9_b_u[c9_i160] = c9_cv7[c9_i160];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 10, 0U, 1U, 0U, 2, 1, 61));
  sf_mex_call_debug("error", 0U, 2U, 14, c9_y, 14, c9_b_y);
}

static const mxArray *c9_sf_marshall(void *chartInstanceVoid, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i161;
  real_T c9_b_u[3];
  const mxArray *c9_b_y = NULL;
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)chartInstanceVoid;
  c9_y = NULL;
  for (c9_i161 = 0; c9_i161 < 3; c9_i161 = c9_i161 + 1) {
    c9_b_u[c9_i161] = (*((real_T (*)[3])c9_u))[c9_i161];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_b_sf_marshall(void *chartInstanceVoid, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i162;
  real_T c9_b_u[4];
  const mxArray *c9_b_y = NULL;
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)chartInstanceVoid;
  c9_y = NULL;
  for (c9_i162 = 0; c9_i162 < 4; c9_i162 = c9_i162 + 1) {
    c9_b_u[c9_i162] = (*((real_T (*)[4])c9_u))[c9_i162];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_c_sf_marshall(void *chartInstanceVoid, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i163;
  int32_T c9_i164;
  int32_T c9_i165;
  real_T c9_b_u[12];
  const mxArray *c9_b_y = NULL;
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)chartInstanceVoid;
  c9_y = NULL;
  c9_i163 = 0;
  for (c9_i164 = 0; c9_i164 < 2; c9_i164 = c9_i164 + 1) {
    for (c9_i165 = 0; c9_i165 < 6; c9_i165 = c9_i165 + 1) {
      c9_b_u[c9_i165 + c9_i163] = (*((real_T (*)[12])c9_u))[c9_i165 + c9_i163];
    }

    c9_i163 = c9_i163 + 6;
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 2, 6, 2));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_d_sf_marshall(void *chartInstanceVoid, void *c9_u)
{
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)chartInstanceVoid;
  c9_y = NULL;
  c9_b_u = *((real_T *)c9_u);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_e_sf_marshall(void *chartInstanceVoid, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i166;
  real_T c9_b_u[6];
  const mxArray *c9_b_y = NULL;
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)chartInstanceVoid;
  c9_y = NULL;
  for (c9_i166 = 0; c9_i166 < 6; c9_i166 = c9_i166 + 1) {
    c9_b_u[c9_i166] = (*((real_T (*)[6])c9_u))[c9_i166];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_f_sf_marshall(void *chartInstanceVoid, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i167;
  int32_T c9_i168;
  int32_T c9_i169;
  real_T c9_b_u[36];
  const mxArray *c9_b_y = NULL;
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)chartInstanceVoid;
  c9_y = NULL;
  c9_i167 = 0;
  for (c9_i168 = 0; c9_i168 < 6; c9_i168 = c9_i168 + 1) {
    for (c9_i169 = 0; c9_i169 < 6; c9_i169 = c9_i169 + 1) {
      c9_b_u[c9_i169 + c9_i167] = (*((real_T (*)[36])c9_u))[c9_i169 + c9_i167];
    }

    c9_i167 = c9_i167 + 6;
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_g_sf_marshall(void *chartInstanceVoid, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i170;
  real_T c9_b_u[3];
  const mxArray *c9_b_y = NULL;
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)chartInstanceVoid;
  c9_y = NULL;
  for (c9_i170 = 0; c9_i170 < 3; c9_i170 = c9_i170 + 1) {
    c9_b_u[c9_i170] = (*((real_T (*)[3])c9_u))[c9_i170];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

const mxArray *sf_c9_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_ResolvedFunctionInfo c9_info[102];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i171;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  c9_b_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 102));
  for (c9_i171 = 0; c9_i171 < 102; c9_i171 = c9_i171 + 1) {
    c9_r0 = &c9_info[c9_i171];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context",
                    "nameCaptureInfo", c9_i171);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name",
                    "nameCaptureInfo", c9_i171);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c9_i171);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c9_i171);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c9_i171);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c9_i171);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c9_i171);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[102])
{
  c9_info[0].context = "";
  c9_info[0].name = "eq";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[B]eq";
  c9_info[0].fileLength = 0U;
  c9_info[0].fileTime1 = 0U;
  c9_info[0].fileTime2 = 0U;
  c9_info[1].context = "";
  c9_info[1].name = "minus";
  c9_info[1].dominantType = "double";
  c9_info[1].resolved = "[B]minus";
  c9_info[1].fileLength = 0U;
  c9_info[1].fileTime1 = 0U;
  c9_info[1].fileTime2 = 0U;
  c9_info[2].context = "";
  c9_info[2].name = "abs";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[2].fileLength = 566U;
  c9_info[2].fileTime1 = 1221292332U;
  c9_info[2].fileTime2 = 0U;
  c9_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[3].name = "nargin";
  c9_info[3].dominantType = "";
  c9_info[3].resolved = "[B]nargin";
  c9_info[3].fileLength = 0U;
  c9_info[3].fileTime1 = 0U;
  c9_info[3].fileTime2 = 0U;
  c9_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[4].name = "gt";
  c9_info[4].dominantType = "double";
  c9_info[4].resolved = "[B]gt";
  c9_info[4].fileLength = 0U;
  c9_info[4].fileTime1 = 0U;
  c9_info[4].fileTime2 = 0U;
  c9_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[5].name = "isa";
  c9_info[5].dominantType = "double";
  c9_info[5].resolved = "[B]isa";
  c9_info[5].fileLength = 0U;
  c9_info[5].fileTime1 = 0U;
  c9_info[5].fileTime2 = 0U;
  c9_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[6].name = "ischar";
  c9_info[6].dominantType = "double";
  c9_info[6].resolved = "[B]ischar";
  c9_info[6].fileLength = 0U;
  c9_info[6].fileTime1 = 0U;
  c9_info[6].fileTime2 = 0U;
  c9_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[7].name = "islogical";
  c9_info[7].dominantType = "double";
  c9_info[7].resolved = "[B]islogical";
  c9_info[7].fileLength = 0U;
  c9_info[7].fileTime1 = 0U;
  c9_info[7].fileTime2 = 0U;
  c9_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[8].name = "size";
  c9_info[8].dominantType = "double";
  c9_info[8].resolved = "[B]size";
  c9_info[8].fileLength = 0U;
  c9_info[8].fileTime1 = 0U;
  c9_info[8].fileTime2 = 0U;
  c9_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[9].name = "class";
  c9_info[9].dominantType = "double";
  c9_info[9].resolved = "[B]class";
  c9_info[9].fileLength = 0U;
  c9_info[9].fileTime1 = 0U;
  c9_info[9].fileTime2 = 0U;
  c9_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[10].name = "zeros";
  c9_info[10].dominantType = "double";
  c9_info[10].resolved = "[B]zeros";
  c9_info[10].fileLength = 0U;
  c9_info[10].fileTime1 = 0U;
  c9_info[10].fileTime2 = 0U;
  c9_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[11].name = "eml_scalar_abs";
  c9_info[11].dominantType = "double";
  c9_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[11].fileLength = 461U;
  c9_info[11].fileTime1 = 1203473160U;
  c9_info[11].fileTime2 = 0U;
  c9_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[12].name = "isinteger";
  c9_info[12].dominantType = "double";
  c9_info[12].resolved = "[B]isinteger";
  c9_info[12].fileLength = 0U;
  c9_info[12].fileTime1 = 0U;
  c9_info[12].fileTime2 = 0U;
  c9_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[13].name = "isreal";
  c9_info[13].dominantType = "double";
  c9_info[13].resolved = "[B]isreal";
  c9_info[13].fileLength = 0U;
  c9_info[13].fileTime1 = 0U;
  c9_info[13].fileTime2 = 0U;
  c9_info[14].context = "";
  c9_info[14].name = "modified_quintic_path_plan";
  c9_info[14].dominantType = "double";
  c9_info[14].resolved =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/modified_quintic_path_plan.m";
  c9_info[14].fileLength = 2047U;
  c9_info[14].fileTime1 = 1509461397U;
  c9_info[14].fileTime2 = 0U;
  c9_info[15].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/modified_quintic_path_plan.m";
  c9_info[15].name = "mtimes";
  c9_info[15].dominantType = "double";
  c9_info[15].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[15].fileLength = 3425U;
  c9_info[15].fileTime1 = 1250697966U;
  c9_info[15].fileTime2 = 0U;
  c9_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[16].name = "isscalar";
  c9_info[16].dominantType = "double";
  c9_info[16].resolved = "[B]isscalar";
  c9_info[16].fileLength = 0U;
  c9_info[16].fileTime1 = 0U;
  c9_info[16].fileTime2 = 0U;
  c9_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[17].name = "strcmp";
  c9_info[17].dominantType = "char";
  c9_info[17].resolved = "[B]strcmp";
  c9_info[17].fileLength = 0U;
  c9_info[17].fileTime1 = 0U;
  c9_info[17].fileTime2 = 0U;
  c9_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[18].name = "not";
  c9_info[18].dominantType = "logical";
  c9_info[18].resolved = "[B]not";
  c9_info[18].fileLength = 0U;
  c9_info[18].fileTime1 = 0U;
  c9_info[18].fileTime2 = 0U;
  c9_info[19].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/modified_quintic_path_plan.m";
  c9_info[19].name = "lt";
  c9_info[19].dominantType = "double";
  c9_info[19].resolved = "[B]lt";
  c9_info[19].fileLength = 0U;
  c9_info[19].fileTime1 = 0U;
  c9_info[19].fileTime2 = 0U;
  c9_info[20].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/modified_quintic_path_plan.m";
  c9_info[20].name = "compute_quintic_5th_poly";
  c9_info[20].dominantType = "double";
  c9_info[20].resolved =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/compute_quintic_5th_poly.m";
  c9_info[20].fileLength = 940U;
  c9_info[20].fileTime1 = 1509461397U;
  c9_info[20].fileTime2 = 0U;
  c9_info[21].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/compute_quintic_5th_poly.m";
  c9_info[21].name = "mpower";
  c9_info[21].dominantType = "double";
  c9_info[21].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[21].fileLength = 3710U;
  c9_info[21].fileTime1 = 1238459488U;
  c9_info[21].fileTime2 = 0U;
  c9_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[22].name = "ndims";
  c9_info[22].dominantType = "double";
  c9_info[22].resolved = "[B]ndims";
  c9_info[22].fileLength = 0U;
  c9_info[22].fileTime1 = 0U;
  c9_info[22].fileTime2 = 0U;
  c9_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c9_info[23].name = "power";
  c9_info[23].dominantType = "double";
  c9_info[23].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[23].fileLength = 5380U;
  c9_info[23].fileTime1 = 1228119098U;
  c9_info[23].fileTime2 = 0U;
  c9_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[24].name = "eml_scalar_eg";
  c9_info[24].dominantType = "double";
  c9_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[24].fileLength = 3068U;
  c9_info[24].fileTime1 = 1240287210U;
  c9_info[24].fileTime2 = 0U;
  c9_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c9_info[25].name = "false";
  c9_info[25].dominantType = "";
  c9_info[25].resolved = "[B]false";
  c9_info[25].fileLength = 0U;
  c9_info[25].fileTime1 = 0U;
  c9_info[25].fileTime2 = 0U;
  c9_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[26].name = "isstruct";
  c9_info[26].dominantType = "double";
  c9_info[26].resolved = "[B]isstruct";
  c9_info[26].fileLength = 0U;
  c9_info[26].fileTime1 = 0U;
  c9_info[26].fileTime2 = 0U;
  c9_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[27].name = "cast";
  c9_info[27].dominantType = "double";
  c9_info[27].resolved = "[B]cast";
  c9_info[27].fileLength = 0U;
  c9_info[27].fileTime1 = 0U;
  c9_info[27].fileTime2 = 0U;
  c9_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[28].name = "plus";
  c9_info[28].dominantType = "double";
  c9_info[28].resolved = "[B]plus";
  c9_info[28].fileLength = 0U;
  c9_info[28].fileTime1 = 0U;
  c9_info[28].fileTime2 = 0U;
  c9_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[29].name = "eml_scalexp_alloc";
  c9_info[29].dominantType = "double";
  c9_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[29].fileLength = 808U;
  c9_info[29].fileTime1 = 1230519898U;
  c9_info[29].fileTime2 = 0U;
  c9_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[30].name = "eml_scalar_floor";
  c9_info[30].dominantType = "double";
  c9_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c9_info[30].fileLength = 260U;
  c9_info[30].fileTime1 = 1209355990U;
  c9_info[30].fileTime2 = 0U;
  c9_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[31].name = "ne";
  c9_info[31].dominantType = "double";
  c9_info[31].resolved = "[B]ne";
  c9_info[31].fileLength = 0U;
  c9_info[31].fileTime1 = 0U;
  c9_info[31].fileTime2 = 0U;
  c9_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[32].name = "eml_error";
  c9_info[32].dominantType = "char";
  c9_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c9_info[32].fileLength = 315U;
  c9_info[32].fileTime1 = 1213951944U;
  c9_info[32].fileTime2 = 0U;
  c9_info[33].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/compute_quintic_5th_poly.m";
  c9_info[33].name = "mldivide";
  c9_info[33].dominantType = "double";
  c9_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c9_info[33].fileLength = 998U;
  c9_info[33].fileTime1 = 1238459488U;
  c9_info[33].fileTime2 = 0U;
  c9_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c9_info[34].name = "ge";
  c9_info[34].dominantType = "double";
  c9_info[34].resolved = "[B]ge";
  c9_info[34].fileLength = 0U;
  c9_info[34].fileTime1 = 0U;
  c9_info[34].fileTime2 = 0U;
  c9_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c9_info[35].name = "isempty";
  c9_info[35].dominantType = "double";
  c9_info[35].resolved = "[B]isempty";
  c9_info[35].fileLength = 0U;
  c9_info[35].fileTime1 = 0U;
  c9_info[35].fileTime2 = 0U;
  c9_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c9_info[36].name = "eml_lusolve";
  c9_info[36].dominantType = "double";
  c9_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c9_info[36].fileLength = 4120U;
  c9_info[36].fileTime1 = 1228119032U;
  c9_info[36].fileTime2 = 0U;
  c9_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c9_info[37].name = "eml_index_class";
  c9_info[37].dominantType = "";
  c9_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[37].fileLength = 909U;
  c9_info[37].fileTime1 = 1192491982U;
  c9_info[37].fileTime2 = 0U;
  c9_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolveNxN";
  c9_info[38].name = "ones";
  c9_info[38].dominantType = "char";
  c9_info[38].resolved = "[B]ones";
  c9_info[38].fileLength = 0U;
  c9_info[38].fileTime1 = 0U;
  c9_info[38].fileTime2 = 0U;
  c9_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolveNxN";
  c9_info[39].name = "eml_xgetrf";
  c9_info[39].dominantType = "int32";
  c9_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[39].fileLength = 2229U;
  c9_info[39].fileTime1 = 1240287214U;
  c9_info[39].fileTime2 = 0U;
  c9_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[40].name = "min";
  c9_info[40].dominantType = "int32";
  c9_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[40].fileLength = 362U;
  c9_info[40].fileTime1 = 1244760752U;
  c9_info[40].fileTime2 = 0U;
  c9_info[41].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[41].name = "le";
  c9_info[41].dominantType = "double";
  c9_info[41].resolved = "[B]le";
  c9_info[41].fileLength = 0U;
  c9_info[41].fileTime1 = 0U;
  c9_info[41].fileTime2 = 0U;
  c9_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[42].name = "nargout";
  c9_info[42].dominantType = "";
  c9_info[42].resolved = "[B]nargout";
  c9_info[42].fileLength = 0U;
  c9_info[42].fileTime1 = 0U;
  c9_info[42].fileTime2 = 0U;
  c9_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[43].name = "eml_min_or_max";
  c9_info[43].dominantType = "int32";
  c9_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[43].fileLength = 9969U;
  c9_info[43].fileTime1 = 1240287206U;
  c9_info[43].fileTime2 = 0U;
  c9_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[44].name = "isnumeric";
  c9_info[44].dominantType = "int32";
  c9_info[44].resolved = "[B]isnumeric";
  c9_info[44].fileLength = 0U;
  c9_info[44].fileTime1 = 0U;
  c9_info[44].fileTime2 = 0U;
  c9_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[45].name = "colon";
  c9_info[45].dominantType = "int32";
  c9_info[45].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c9_info[45].fileLength = 8592U;
  c9_info[45].fileTime1 = 1257808582U;
  c9_info[45].fileTime2 = 0U;
  c9_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c9_info[46].name = "floor";
  c9_info[46].dominantType = "double";
  c9_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c9_info[46].fileLength = 332U;
  c9_info[46].fileTime1 = 1203473222U;
  c9_info[46].fileTime2 = 0U;
  c9_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c9_info[47].name = "intmin";
  c9_info[47].dominantType = "char";
  c9_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c9_info[47].fileLength = 1505U;
  c9_info[47].fileTime1 = 1192491928U;
  c9_info[47].fileTime2 = 0U;
  c9_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c9_info[48].name = "uminus";
  c9_info[48].dominantType = "double";
  c9_info[48].resolved = "[B]uminus";
  c9_info[48].fileLength = 0U;
  c9_info[48].fileTime1 = 0U;
  c9_info[48].fileTime2 = 0U;
  c9_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c9_info[49].name = "int32";
  c9_info[49].dominantType = "double";
  c9_info[49].resolved = "[B]int32";
  c9_info[49].fileLength = 0U;
  c9_info[49].fileTime1 = 0U;
  c9_info[49].fileTime2 = 0U;
  c9_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c9_info[50].name = "intmax";
  c9_info[50].dominantType = "char";
  c9_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c9_info[50].fileLength = 1535U;
  c9_info[50].fileTime1 = 1192491928U;
  c9_info[50].fileTime2 = 0U;
  c9_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c9_info[51].name = "double";
  c9_info[51].dominantType = "double";
  c9_info[51].resolved = "[B]double";
  c9_info[51].fileLength = 0U;
  c9_info[51].fileTime1 = 0U;
  c9_info[51].fileTime2 = 0U;
  c9_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c9_info[52].name = "isnan";
  c9_info[52].dominantType = "double";
  c9_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c9_info[52].fileLength = 506U;
  c9_info[52].fileTime1 = 1228119010U;
  c9_info[52].fileTime2 = 0U;
  c9_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c9_info[53].name = "isinf";
  c9_info[53].dominantType = "double";
  c9_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c9_info[53].fileLength = 506U;
  c9_info[53].fileTime1 = 1228119008U;
  c9_info[53].fileTime2 = 0U;
  c9_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c9_info[54].name = "realmax";
  c9_info[54].dominantType = "";
  c9_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c9_info[54].fileLength = 771U;
  c9_info[54].fileTime1 = 1226602476U;
  c9_info[54].fileTime2 = 0U;
  c9_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c9_info[55].name = "transpose";
  c9_info[55].dominantType = "int32";
  c9_info[55].resolved = "[B]transpose";
  c9_info[55].fileLength = 0U;
  c9_info[55].fileTime1 = 0U;
  c9_info[55].fileTime2 = 0U;
  c9_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[56].name = "eml_index_plus";
  c9_info[56].dominantType = "int32";
  c9_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[56].fileLength = 272U;
  c9_info[56].fileTime1 = 1192491984U;
  c9_info[56].fileTime2 = 0U;
  c9_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[57].name = "eml_index_minus";
  c9_info[57].dominantType = "int32";
  c9_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[57].fileLength = 277U;
  c9_info[57].fileTime1 = 1192491984U;
  c9_info[57].fileTime2 = 0U;
  c9_info[58].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[58].name = "eml_index_times";
  c9_info[58].dominantType = "int32";
  c9_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[58].fileLength = 280U;
  c9_info[58].fileTime1 = 1192491986U;
  c9_info[58].fileTime2 = 0U;
  c9_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[59].name = "eml_ixamax";
  c9_info[59].dominantType = "int32";
  c9_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c9_info[59].fileLength = 731U;
  c9_info[59].fileTime1 = 1209356044U;
  c9_info[59].fileTime2 = 0U;
  c9_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c9_info[60].name = "eml_refblas_ixamax";
  c9_info[60].dominantType = "int32";
  c9_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c9_info[60].fileLength = 740U;
  c9_info[60].fileTime1 = 1192492066U;
  c9_info[60].fileTime2 = 0U;
  c9_info[61].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c9_info[61].name = "eml_xcabs1";
  c9_info[61].dominantType = "double";
  c9_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c9_info[61].fileLength = 419U;
  c9_info[61].fileTime1 = 1209356046U;
  c9_info[61].fileTime2 = 0U;
  c9_info[62].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c9_info[62].name = "real";
  c9_info[62].dominantType = "double";
  c9_info[62].resolved = "[B]real";
  c9_info[62].fileLength = 0U;
  c9_info[62].fileTime1 = 0U;
  c9_info[62].fileTime2 = 0U;
  c9_info[63].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c9_info[63].name = "imag";
  c9_info[63].dominantType = "double";
  c9_info[63].resolved = "[B]imag";
  c9_info[63].fileLength = 0U;
  c9_info[63].fileTime1 = 0U;
  c9_info[63].fileTime2 = 0U;
}

static void c9_b_info_helper(c9_ResolvedFunctionInfo c9_info[102])
{
  c9_info[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[64].name = "eml_xswap";
  c9_info[64].dominantType = "int32";
  c9_info[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c9_info[64].fileLength = 1330U;
  c9_info[64].fileTime1 = 1209356060U;
  c9_info[64].fileTime2 = 0U;
  c9_info[65].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c9_info[65].name = "eml_refblas_xswap";
  c9_info[65].dominantType = "int32";
  c9_info[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c9_info[65].fileLength = 905U;
  c9_info[65].fileTime1 = 1238459470U;
  c9_info[65].fileTime2 = 0U;
  c9_info[66].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[66].name = "eml_div";
  c9_info[66].dominantType = "double";
  c9_info[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[66].fileLength = 4269U;
  c9_info[66].fileTime1 = 1228119026U;
  c9_info[66].fileTime2 = 0U;
  c9_info[67].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c9_info[67].name = "eml_xgeru";
  c9_info[67].dominantType = "int32";
  c9_info[67].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c9_info[67].fileLength = 2462U;
  c9_info[67].fileTime1 = 1209356056U;
  c9_info[67].fileTime2 = 0U;
  c9_info[68].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c9_info[68].name = "eml_xger";
  c9_info[68].dominantType = "int32";
  c9_info[68].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c9_info[68].fileLength = 2168U;
  c9_info[68].fileTime1 = 1209356054U;
  c9_info[68].fileTime2 = 0U;
  c9_info[69].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c9_info[69].name = "eml_refblas_xger";
  c9_info[69].dominantType = "int32";
  c9_info[69].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c9_info[69].fileLength = 411U;
  c9_info[69].fileTime1 = 1211241248U;
  c9_info[69].fileTime2 = 0U;
  c9_info[70].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c9_info[70].name = "eml_refblas_xgerx";
  c9_info[70].dominantType = "int32";
  c9_info[70].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c9_info[70].fileLength = 2231U;
  c9_info[70].fileTime1 = 1238459468U;
  c9_info[70].fileTime2 = 0U;
  c9_info[71].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c9_info[71].name = "times";
  c9_info[71].dominantType = "double";
  c9_info[71].resolved = "[B]times";
  c9_info[71].fileLength = 0U;
  c9_info[71].fileTime1 = 0U;
  c9_info[71].fileTime2 = 0U;
  c9_info[72].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/warn_singular";
  c9_info[72].name = "eml_warning";
  c9_info[72].dominantType = "char";
  c9_info[72].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c9_info[72].fileLength = 262U;
  c9_info[72].fileTime1 = 1236282478U;
  c9_info[72].fileTime2 = 0U;
  c9_info[73].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolveNxN";
  c9_info[73].name = "eml_xtrsm";
  c9_info[73].dominantType = "int32";
  c9_info[73].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c9_info[73].fileLength = 2383U;
  c9_info[73].fileTime1 = 1209356062U;
  c9_info[73].fileTime2 = 0U;
  c9_info[74].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m/itcount";
  c9_info[74].name = "length";
  c9_info[74].dominantType = "double";
  c9_info[74].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c9_info[74].fileLength = 326U;
  c9_info[74].fileTime1 = 1226602474U;
  c9_info[74].fileTime2 = 0U;
  c9_info[75].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m/itcount";
  c9_info[75].name = "mrdivide";
  c9_info[75].dominantType = "double";
  c9_info[75].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[75].fileLength = 800U;
  c9_info[75].fileTime1 = 1238459490U;
  c9_info[75].fileTime2 = 0U;
  c9_info[76].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[76].name = "rdivide";
  c9_info[76].dominantType = "double";
  c9_info[76].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[76].fileLength = 403U;
  c9_info[76].fileTime1 = 1244760752U;
  c9_info[76].fileTime2 = 0U;
  c9_info[77].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c9_info[77].name = "eml_refblas_xtrsm";
  c9_info[77].dominantType = "int32";
  c9_info[77].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[77].fileLength = 13101U;
  c9_info[77].fileTime1 = 1252025302U;
  c9_info[77].fileTime2 = 0U;
  c9_info[78].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/modified_quintic_path_plan.m";
  c9_info[78].name = "sign";
  c9_info[78].dominantType = "double";
  c9_info[78].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c9_info[78].fileLength = 408U;
  c9_info[78].fileTime1 = 1203473240U;
  c9_info[78].fileTime2 = 0U;
  c9_info[79].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c9_info[79].name = "eml_scalar_sign";
  c9_info[79].dominantType = "double";
  c9_info[79].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c9_info[79].fileLength = 543U;
  c9_info[79].fileTime1 = 1203473212U;
  c9_info[79].fileTime2 = 0U;
  c9_info[80].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c9_info[80].name = "eml_guarded_nan";
  c9_info[80].dominantType = "char";
  c9_info[80].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c9_info[80].fileLength = 485U;
  c9_info[80].fileTime1 = 1192491980U;
  c9_info[80].fileTime2 = 0U;
  c9_info[81].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c9_info[81].name = "eml_is_float_class";
  c9_info[81].dominantType = "char";
  c9_info[81].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c9_info[81].fileLength = 226U;
  c9_info[81].fileTime1 = 1197875640U;
  c9_info[81].fileTime2 = 0U;
  c9_info[82].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c9_info[82].name = "nan";
  c9_info[82].dominantType = "char";
  c9_info[82].resolved = "[B]nan";
  c9_info[82].fileLength = 0U;
  c9_info[82].fileTime1 = 0U;
  c9_info[82].fileTime2 = 0U;
  c9_info[83].context = "";
  c9_info[83].name = "interp_quintic_5th_poly";
  c9_info[83].dominantType = "double";
  c9_info[83].resolved =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/interp_quintic_5th_poly.m";
  c9_info[83].fileLength = 834U;
  c9_info[83].fileTime1 = 1509461397U;
  c9_info[83].fileTime2 = 0U;
  c9_info[84].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/interp_quintic_5th_poly.m";
  c9_info[84].name = "ctranspose";
  c9_info[84].dominantType = "double";
  c9_info[84].resolved = "[B]ctranspose";
  c9_info[84].fileLength = 0U;
  c9_info[84].fileTime1 = 0U;
  c9_info[84].fileTime2 = 0U;
  c9_info[85].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[85].name = "eml_xdotu";
  c9_info[85].dominantType = "int32";
  c9_info[85].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c9_info[85].fileLength = 1453U;
  c9_info[85].fileTime1 = 1209356050U;
  c9_info[85].fileTime2 = 0U;
  c9_info[86].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c9_info[86].name = "eml_xdot";
  c9_info[86].dominantType = "int32";
  c9_info[86].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c9_info[86].fileLength = 1330U;
  c9_info[86].fileTime1 = 1209356048U;
  c9_info[86].fileTime2 = 0U;
  c9_info[87].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c9_info[87].name = "eml_refblas_xdot";
  c9_info[87].dominantType = "int32";
  c9_info[87].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c9_info[87].fileLength = 343U;
  c9_info[87].fileTime1 = 1211241242U;
  c9_info[87].fileTime2 = 0U;
  c9_info[88].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c9_info[88].name = "eml_refblas_xdotx";
  c9_info[88].dominantType = "int32";
  c9_info[88].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[88].fileLength = 1605U;
  c9_info[88].fileTime1 = 1236282478U;
  c9_info[88].fileTime2 = 0U;
  c9_info[89].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[89].name = "isequal";
  c9_info[89].dominantType = "char";
  c9_info[89].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c9_info[89].fileLength = 180U;
  c9_info[89].fileTime1 = 1226602470U;
  c9_info[89].fileTime2 = 0U;
  c9_info[90].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c9_info[90].name = "eml_isequal_core";
  c9_info[90].dominantType = "char";
  c9_info[90].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c9_info[90].fileLength = 4192U;
  c9_info[90].fileTime1 = 1257808582U;
  c9_info[90].fileTime2 = 0U;
  c9_info[91].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c9_info[91].name = "true";
  c9_info[91].dominantType = "";
  c9_info[91].resolved = "[B]true";
  c9_info[91].fileLength = 0U;
  c9_info[91].fileTime1 = 0U;
  c9_info[91].fileTime2 = 0U;
  c9_info[92].context =
    "[]C:/Users/arma/Desktop/Dev/MainBigSnake_working/Model/Embedded_Func/interp_quintic_5th_poly.m";
  c9_info[92].name = "diag";
  c9_info[92].dominantType = "double";
  c9_info[92].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[92].fileLength = 2774U;
  c9_info[92].fileTime1 = 1240287180U;
  c9_info[92].fileTime2 = 0U;
  c9_info[93].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[93].name = "isvector";
  c9_info[93].dominantType = "double";
  c9_info[93].resolved = "[B]isvector";
  c9_info[93].fileLength = 0U;
  c9_info[93].fileTime1 = 0U;
  c9_info[93].fileTime2 = 0U;
  c9_info[94].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[94].name = "eml_xgemm";
  c9_info[94].dominantType = "int32";
  c9_info[94].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[94].fileLength = 3184U;
  c9_info[94].fileTime1 = 1209356052U;
  c9_info[94].fileTime2 = 0U;
  c9_info[95].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[95].name = "eml_refblas_xgemm";
  c9_info[95].dominantType = "int32";
  c9_info[95].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[95].fileLength = 5748U;
  c9_info[95].fileTime1 = 1228119072U;
  c9_info[95].fileTime2 = 0U;
  c9_info[96].context = "";
  c9_info[96].name = "interp1";
  c9_info[96].dominantType = "double";
  c9_info[96].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m";
  c9_info[96].fileLength = 8178U;
  c9_info[96].fileTime1 = 1242323578U;
  c9_info[96].fileTime2 = 0U;
  c9_info[97].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m/interp1_work";
  c9_info[97].name = "fliplr";
  c9_info[97].dominantType = "double";
  c9_info[97].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/fliplr.m";
  c9_info[97].fileLength = 540U;
  c9_info[97].fileTime1 = 1226602468U;
  c9_info[97].fileTime2 = 0U;
  c9_info[98].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/fliplr.m";
  c9_info[98].name = "eml_index_rdivide";
  c9_info[98].dominantType = "int32";
  c9_info[98].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c9_info[98].fileLength = 332U;
  c9_info[98].fileTime1 = 1192491986U;
  c9_info[98].fileTime2 = 0U;
  c9_info[99].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/polyfun/interp1.m/interp1_work";
  c9_info[99].name = "eml_bsearch";
  c9_info[99].dominantType = "double";
  c9_info[99].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_bsearch.m";
  c9_info[99].fileLength = 2303U;
  c9_info[99].fileTime1 = 1238459446U;
  c9_info[99].fileTime2 = 0U;
  c9_info[100].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_bsearch.m";
  c9_info[100].name = "eml_unsigned_class";
  c9_info[100].dominantType = "char";
  c9_info[100].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c9_info[100].fileLength = 526U;
  c9_info[100].fileTime1 = 1192492010U;
  c9_info[100].fileTime2 = 0U;
  c9_info[101].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c9_info[101].name = "uint32";
  c9_info[101].dominantType = "double";
  c9_info[101].resolved = "[B]uint32";
  c9_info[101].fileLength = 0U;
  c9_info[101].fileTime1 = 0U;
  c9_info[101].fileTime2 = 0U;
}

static const mxArray *c9_h_sf_marshall(void *chartInstanceVoid, void *c9_u)
{
  const mxArray *c9_y = NULL;
  boolean_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)chartInstanceVoid;
  c9_y = NULL;
  c9_b_u = *((boolean_T *)c9_u);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static void c9_emlrt_marshallIn(SFc9_large_snakeInstanceStruct *chartInstance,
  const mxArray *c9_breakPtsConfig_n, const char_T *
  c9_name, real_T c9_y[3])
{
  real_T c9_dv14[3];
  int32_T c9_i172;
  sf_mex_import(c9_name, sf_mex_dup(c9_breakPtsConfig_n), &c9_dv14, 1, 0, 0U, 1,
                0U, 1, 3);
  for (c9_i172 = 0; c9_i172 < 3; c9_i172 = c9_i172 + 1) {
    c9_y[c9_i172] = c9_dv14[c9_i172];
  }

  sf_mex_destroy(&c9_breakPtsConfig_n);
}

static void c9_b_emlrt_marshallIn(SFc9_large_snakeInstanceStruct *chartInstance,
  const mxArray *c9_coefsConfig_n, const char_T *
  c9_name, real_T c9_y[12])
{
  real_T c9_dv15[12];
  int32_T c9_i173;
  sf_mex_import(c9_name, sf_mex_dup(c9_coefsConfig_n), &c9_dv15, 1, 0, 0U, 1, 0U,
                2, 6, 2);
  for (c9_i173 = 0; c9_i173 < 12; c9_i173 = c9_i173 + 1) {
    c9_y[c9_i173] = c9_dv15[c9_i173];
  }

  sf_mex_destroy(&c9_coefsConfig_n);
}

static real_T c9_c_emlrt_marshallIn(SFc9_large_snakeInstanceStruct
  *chartInstance, const mxArray *c9_dq_ref, const char_T *c9_name)
{
  real_T c9_y;
  real_T c9_d4;
  sf_mex_import(c9_name, sf_mex_dup(c9_dq_ref), &c9_d4, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d4;
  sf_mex_destroy(&c9_dq_ref);
  return c9_y;
}

static void c9_d_emlrt_marshallIn(SFc9_large_snakeInstanceStruct *chartInstance,
  const mxArray *c9_timeConfig_n, const char_T *
  c9_name, real_T c9_y[4])
{
  real_T c9_dv16[4];
  int32_T c9_i174;
  sf_mex_import(c9_name, sf_mex_dup(c9_timeConfig_n), &c9_dv16, 1, 0, 0U, 1, 0U,
                1, 4);
  for (c9_i174 = 0; c9_i174 < 4; c9_i174 = c9_i174 + 1) {
    c9_y[c9_i174] = c9_dv16[c9_i174];
  }

  sf_mex_destroy(&c9_timeConfig_n);
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_large_snakeInstanceStruct
  *chartInstance, const mxArray *c9_is_active_c9_large_snake,
  const char_T *c9_name)
{
  uint8_T c9_y;
  uint8_T c9_u1;
  sf_mex_import(c9_name, sf_mex_dup(c9_is_active_c9_large_snake), &c9_u1, 1, 3,
                0U, 0, 0U, 0);
  c9_y = c9_u1;
  sf_mex_destroy(&c9_is_active_c9_large_snake);
  return c9_y;
}

static void init_dsm_address_info(SFc9_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3170702417U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3789528990U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3260432908U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3359041665U);
}

mxArray *sf_c9_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1046916785U);
    pr[1] = (double)(101791403U);
    pr[2] = (double)(4084263813U);
    pr[3] = (double)(2707427587U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(6);
      pr[1] = (double)(2);
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
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(6);
      pr[1] = (double)(2);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c9_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[24],T\"breakPtsConfig_n\",},{M[1],M[22],T\"coefsConfig_n\",},{M[1],M[6],T\"dq_ref\",},{M[1],M[5],T\"q_ref\",},{M[1],M[8],T\"stat_next\",},{M[1],M[23],T\"timeConfig_n\",},{M[8],M[0],T\"is_active_c9_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc9_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           9,
           1,
           1,
           16,
           0,
           0,
           0,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"go",0,
                              (MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"q_ref",0,
                              (MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dq_ref",
                              0,(MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "stat_next",0,(MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t_clk",0,
                              (MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"q_goal",
                              0,(MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"q_prev",
                              0,(MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "stat_cur",0,(MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"vmax",0,
                              (MexFcnForType)c9_d_sf_marshall);
          _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "t_spd_chg",0,(MexFcnForType)c9_d_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 6;
            dimVector[1]= 2;
            _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"coefsConfig",0,(MexFcnForType)
                                c9_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"timeConfig",0,(MexFcnForType)
                                c9_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(12,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"breakPtsConfig",0,(MexFcnForType)
                                c9_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 6;
            dimVector[1]= 2;
            _SFD_SET_DATA_PROPS(13,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"coefsConfig_n",0,(MexFcnForType)
                                c9_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(14,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"timeConfig_n",0,(MexFcnForType)
                                c9_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(15,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"breakPtsConfig_n",0,(MexFcnForType)
                                c9_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,9,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3888);
        _SFD_CV_INIT_EML_IF(0,0,1766,1780,2398,3888);
        _SFD_CV_INIT_EML_IF(0,1,1837,1867,2172,2317);
        _SFD_CV_INIT_EML_IF(0,2,2358,2366,-1,2397);
        _SFD_CV_INIT_EML_IF(0,3,2398,2416,3670,3888);
        _SFD_CV_INIT_EML_IF(0,4,2774,2786,3590,3669);
        _SFD_CV_INIT_EML_IF(0,5,2828,2843,3469,3555);
        _SFD_CV_INIT_EML_IF(0,6,2926,2940,3030,3460);
        _SFD_CV_INIT_EML_IF(0,7,3030,3066,3284,3460);
        _SFD_CV_INIT_EML_IF(0,8,3813,3821,3849,3884);

        {
          static int condStart[] = { 3038, 3054 };

          static int condEnd[] = { 3050, 3065 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,3037,3066,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"modified_quintic_path_plan",0,-1,2045);
        _SFD_CV_INIT_SCRIPT_IF(0,0,1122,1152,1466,2040);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"compute_quintic_5th_poly",0,-1,938);
        _SFD_CV_INIT_SCRIPT(2,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"interp_quintic_5th_poly",0,-1,832);
        _SFD_CV_INIT_SCRIPT_IF(2,0,615,622,-1,638);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c9_go;
          real_T *c9_q_ref;
          real_T *c9_dq_ref;
          real_T *c9_stat_next;
          real_T *c9_t_clk;
          real_T *c9_q_goal;
          real_T *c9_q_prev;
          real_T *c9_stat_cur;
          real_T *c9_vmax;
          real_T *c9_t_spd_chg;
          real_T (*c9_coefsConfig)[12];
          real_T (*c9_timeConfig)[4];
          real_T (*c9_breakPtsConfig)[3];
          real_T (*c9_coefsConfig_n)[12];
          real_T (*c9_timeConfig_n)[4];
          real_T (*c9_breakPtsConfig_n)[3];
          c9_breakPtsConfig_n = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 6);
          c9_timeConfig_n = (real_T (*)[4])ssGetOutputPortSignal
            (chartInstance->S, 5);
          c9_coefsConfig_n = (real_T (*)[12])ssGetOutputPortSignal
            (chartInstance->S, 4);
          c9_breakPtsConfig = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 9);
          c9_timeConfig = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            8);
          c9_coefsConfig = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S,
            7);
          c9_t_spd_chg = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c9_vmax = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c9_stat_cur = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c9_q_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c9_q_goal = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_t_clk = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_stat_next = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_dq_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_q_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_go = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_go);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_q_ref);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_dq_ref);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_stat_next);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_t_clk);
          _SFD_SET_DATA_VALUE_PTR(5U, c9_q_goal);
          _SFD_SET_DATA_VALUE_PTR(6U, c9_q_prev);
          _SFD_SET_DATA_VALUE_PTR(7U, c9_stat_cur);
          _SFD_SET_DATA_VALUE_PTR(8U, c9_vmax);
          _SFD_SET_DATA_VALUE_PTR(9U, c9_t_spd_chg);
          _SFD_SET_DATA_VALUE_PTR(10U, c9_coefsConfig);
          _SFD_SET_DATA_VALUE_PTR(11U, c9_timeConfig);
          _SFD_SET_DATA_VALUE_PTR(12U, c9_breakPtsConfig);
          _SFD_SET_DATA_VALUE_PTR(13U, c9_coefsConfig_n);
          _SFD_SET_DATA_VALUE_PTR(14U, c9_timeConfig_n);
          _SFD_SET_DATA_VALUE_PTR(15U, c9_breakPtsConfig_n);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c9_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_large_snakeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c9_large_snake((SFc9_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c9_large_snake((SFc9_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_large_snake(void *chartInstanceVar)
{
  enable_c9_large_snake((SFc9_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_large_snake(void *chartInstanceVar)
{
  disable_c9_large_snake((SFc9_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_large_snake(void *chartInstanceVar)
{
  sf_c9_large_snake((SFc9_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c9_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c9_large_snake((SFc9_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c9_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_large_snake
    ((SFc9_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c9_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c9_large_snake(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_large_snake((SFc9_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c9_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_large_snake(S);
}

static void sf_opaque_set_sim_state_c9_large_snake(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c9_large_snake(S, st);
}

static void sf_opaque_terminate_c9_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_large_snake((SFc9_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_large_snake((SFc9_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c9_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",9,"gatewayCannotBeInlinedMultipleTimes"));
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
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",9,10);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",9,6);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(441815352U));
  ssSetChecksum1(S,(3627847046U));
  ssSetChecksum2(S,(2558015850U));
  ssSetChecksum3(S,(527165369U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",9);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_large_snake(SimStruct *S)
{
  SFc9_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc9_large_snakeInstanceStruct *)malloc(sizeof
    (SFc9_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_large_snake;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c9_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c9_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c9_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c9_large_snake;
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

void c9_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
