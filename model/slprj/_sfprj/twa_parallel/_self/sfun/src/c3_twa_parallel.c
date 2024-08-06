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
static const char *c3_debug_family_names[62] = { "z0", "p_in_w", "n1hat",
  "n2hat", "n3hat", "a13", "a23", "a33", "idk_jac", "q1_mu", "q2_mu", "q3_mu",
  "l1_hat", "l2_hat", "l3_hat", "a1", "a2", "a3", "c1", "c2", "c3", "h1", "h2",
  "h3", "h1dot", "h2dot", "h3dot", "e1", "e2", "e3", "b_mu", "b_m", "iik_jac",
  "w_mat", "full_jac", "qdot", "tdot", "v", "w", "del_r", "i", "nargin",
  "nargout", "qcur", "eqeps", "kp", "dt", "p_in_m", "b_in_w", "m_in_w", "f_in_w",
  "measured_len", "velmex_pitch", "macro_leg_len", "eq", "twave", "rwave",
  "qcmd", "des_leg_len", "eq_out", "twave_out", "rwave_out" };

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
static void c3_b_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static real_T c3_norm(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                      c3_x[3]);
static real_T c3_ceval_xnrm2(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T c3_incx);
static void c3_c_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static void c3_cross(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                     c3_a[3], real_T c3_b[3], real_T c3_c[3]);
static void c3_d_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static real_T c3_eml_xdotu(SFc3_twa_parallelInstanceStruct *chartInstance,
  real_T c3_x[3], real_T c3_y[3]);
static real_T c3_ceval_xdot(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[3], int32_T c3_ix0, int32_T c3_incx, real_T c3_y[3],
  int32_T c3_iy0, int32_T c3_incy);
static real_T c3_mpower(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_a);
static real_T c3_power(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_a, real_T c3_b);
static void c3_eml_error(SFc3_twa_parallelInstanceStruct *chartInstance);
static real_T c3_sqrt(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                      c3_x);
static void c3_b_eml_error(SFc3_twa_parallelInstanceStruct *chartInstance);
static void c3_mldivide(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_A[36], real_T c3_B[18], real_T c3_Y[18]);
static void c3_eml_xgetrf(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_A[36], real_T c3_b_A[36], int32_T c3_ipiv[6], int32_T *c3_info);
static int32_T c3_eml_ixamax(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[36], int32_T c3_ix0);
static int32_T c3_ceval_ixamax(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[36], int32_T c3_ix0, int32_T c3_incx);
static void c3_ceval_xswap(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[36], int32_T c3_ix0, int32_T c3_incx, int32_T c3_iy0,
  int32_T c3_incy, real_T c3_b_x[36]);
static void c3_ceval_xger(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, int32_T c3_ix0, int32_T c3_incx,
  int32_T c3_iy0, int32_T c3_incy, real_T c3_A[36], int32_T c3_ia0, int32_T
  c3_lda, real_T c3_b_A[36]);
static void c3_eml_warning(SFc3_twa_parallelInstanceStruct *chartInstance);
static void c3_eml_blas_xtrsm(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, real_T c3_A[36], int32_T c3_ia0,
  int32_T c3_lda, real_T c3_B[18], int32_T c3_ib0, int32_T c3_ldb, real_T
  c3_b_B[18]);
static void c3_ceval_xtrsm(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, real_T c3_A[36], int32_T c3_ia0,
  int32_T c3_lda, real_T c3_B[18], int32_T c3_ib0, int32_T c3_ldb, real_T
  c3_b_B[18]);
static void c3_b_eml_blas_xtrsm(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, real_T c3_A[36], int32_T c3_ia0,
  int32_T c3_lda, real_T c3_B[18], int32_T c3_ib0, int32_T c3_ldb, real_T
  c3_b_B[18]);
static void c3_b_ceval_xtrsm(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, real_T c3_A[36], int32_T c3_ia0,
  int32_T c3_lda, real_T c3_B[18], int32_T c3_ib0, int32_T c3_ldb, real_T
  c3_b_B[18]);
static void c3_e_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static void c3_mrdivide(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_A[18], real_T c3_B[9], real_T c3_y[18]);
static void c3_f_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static void c3_g_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance);
static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_c_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_d_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_e_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_f_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_g_sf_marshall(void *chartInstanceVoid, void *c3_u);
static const mxArray *c3_h_sf_marshall(void *chartInstanceVoid, void *c3_u);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[101]);
static void c3_b_info_helper(c3_ResolvedFunctionInfo c3_info[101]);
static const mxArray *c3_i_sf_marshall(void *chartInstanceVoid, void *c3_u);
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
  int32_T c3_i28;
  int32_T c3_i29;
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
  real_T (*c3_f_in_w)[9];
  real_T (*c3_m_in_w)[9];
  real_T (*c3_b_in_w)[9];
  real_T (*c3_p_in_m)[9];
  real_T (*c3_des_leg_len)[3];
  real_T (*c3_qcmd)[6];
  real_T (*c3_qcur)[6];
  c3_rwave = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 13);
  c3_twave = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 12);
  c3_rwave_out = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_twave_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c3_eq_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_eq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 11);
  c3_macro_leg_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 10);
  c3_velmex_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_measured_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 8);
  c3_f_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 7);
  c3_m_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
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

  for (c3_i20 = 0; c3_i20 < 9; c3_i20 = c3_i20 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_m_in_w)[c3_i20], 8U);
  }

  for (c3_i21 = 0; c3_i21 < 9; c3_i21 = c3_i21 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_f_in_w)[c3_i21], 9U);
  }

  for (c3_i22 = 0; c3_i22 < 3; c3_i22 = c3_i22 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_measured_len)[c3_i22], 10U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_velmex_pitch, 11U);
  for (c3_i23 = 0; c3_i23 < 3; c3_i23 = c3_i23 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_macro_leg_len)[c3_i23], 12U);
  }

  for (c3_i24 = 0; c3_i24 < 3; c3_i24 = c3_i24 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_eq)[c3_i24], 13U);
  }

  for (c3_i25 = 0; c3_i25 < 3; c3_i25 = c3_i25 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_eq_out)[c3_i25], 14U);
  }

  for (c3_i26 = 0; c3_i26 < 3; c3_i26 = c3_i26 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_twave_out)[c3_i26], 15U);
  }

  for (c3_i27 = 0; c3_i27 < 9; c3_i27 = c3_i27 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_rwave_out)[c3_i27], 16U);
  }

  for (c3_i28 = 0; c3_i28 < 3; c3_i28 = c3_i28 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_twave)[c3_i28], 17U);
  }

  for (c3_i29 = 0; c3_i29 < 9; c3_i29 = c3_i29 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_rwave)[c3_i29], 18U);
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
  int32_T c3_i30;
  real_T c3_hoistedGlobal[6];
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  int32_T c3_i31;
  real_T c3_e_hoistedGlobal[9];
  int32_T c3_i32;
  real_T c3_f_hoistedGlobal[9];
  int32_T c3_i33;
  real_T c3_g_hoistedGlobal[9];
  int32_T c3_i34;
  real_T c3_h_hoistedGlobal[9];
  int32_T c3_i35;
  real_T c3_i_hoistedGlobal[3];
  real_T c3_j_hoistedGlobal;
  int32_T c3_i36;
  real_T c3_k_hoistedGlobal[3];
  int32_T c3_i37;
  real_T c3_l_hoistedGlobal[3];
  int32_T c3_i38;
  real_T c3_m_hoistedGlobal[3];
  int32_T c3_i39;
  real_T c3_n_hoistedGlobal[9];
  int32_T c3_i40;
  real_T c3_qcur[6];
  real_T c3_eqeps;
  real_T c3_kp;
  real_T c3_dt;
  int32_T c3_i41;
  real_T c3_p_in_m[9];
  int32_T c3_i42;
  real_T c3_b_in_w[9];
  int32_T c3_i43;
  real_T c3_m_in_w[9];
  int32_T c3_i44;
  real_T c3_f_in_w[9];
  int32_T c3_i45;
  real_T c3_measured_len[3];
  real_T c3_velmex_pitch;
  int32_T c3_i46;
  real_T c3_macro_leg_len[3];
  int32_T c3_i47;
  real_T c3_eq[3];
  int32_T c3_i48;
  real_T c3_twave[3];
  int32_T c3_i49;
  real_T c3_rwave[9];
  uint32_T c3_debug_family_var_map[62];
  static const char *c3_sv0[62] = { "z0", "p_in_w", "n1hat", "n2hat", "n3hat",
    "a13", "a23", "a33", "idk_jac", "q1_mu", "q2_mu",
    "q3_mu", "l1_hat", "l2_hat", "l3_hat", "a1", "a2", "a3", "c1", "c2", "c3",
    "h1", "h2", "h3",
    "h1dot", "h2dot", "h3dot", "e1", "e2", "e3", "b_mu", "b_m", "iik_jac",
    "w_mat", "full_jac", "qdot"
    , "tdot", "v", "w", "del_r", "i", "nargin", "nargout", "qcur", "eqeps", "kp",
    "dt", "p_in_m",
    "b_in_w", "m_in_w", "f_in_w", "measured_len", "velmex_pitch",
    "macro_leg_len", "eq", "twave",
    "rwave", "qcmd", "des_leg_len", "eq_out", "twave_out", "rwave_out" };

  real_T c3_z0[3];
  real_T c3_p_in_w[9];
  real_T c3_n1hat[3];
  real_T c3_n2hat[3];
  real_T c3_n3hat[3];
  real_T c3_a13;
  real_T c3_a23;
  real_T c3_a33;
  real_T c3_idk_jac[9];
  real_T c3_q1_mu;
  real_T c3_q2_mu;
  real_T c3_q3_mu;
  real_T c3_l1_hat[3];
  real_T c3_l2_hat[3];
  real_T c3_l3_hat[3];
  real_T c3_a1;
  real_T c3_a2;
  real_T c3_a3;
  real_T c3_c1;
  real_T c3_c2;
  real_T c3_c3;
  real_T c3_h1;
  real_T c3_h2;
  real_T c3_h3;
  real_T c3_h1dot;
  real_T c3_h2dot;
  real_T c3_h3dot;
  real_T c3_e1;
  real_T c3_e2;
  real_T c3_e3;
  real_T c3_b_mu[9];
  real_T c3_b_m[9];
  real_T c3_iik_jac[18];
  real_T c3_w_mat[36];
  real_T c3_full_jac[18];
  real_T c3_qdot[3];
  real_T c3_tdot[6];
  real_T c3_v[2];
  real_T c3_w;
  real_T c3_del_r[9];
  real_T c3_i;
  real_T c3_nargin = 14.0;
  real_T c3_nargout = 5.0;
  real_T c3_qcmd[6];
  real_T c3_des_leg_len[3];
  real_T c3_eq_out[3];
  real_T c3_twave_out[3];
  real_T c3_rwave_out[9];
  int32_T c3_i50;
  int32_T c3_i51;
  static real_T c3_dv5[3] = { 0.0, 0.0, 1.0 };

  int32_T c3_i52;
  real_T c3_a[3];
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  real_T c3_y[9];
  int32_T c3_i56;
  real_T c3_b_a[9];
  int32_T c3_i57;
  real_T c3_b[9];
  int32_T c3_i58;
  real_T c3_A[9];
  int32_T c3_i59;
  real_T c3_B[9];
  int32_T c3_i60;
  real_T c3_b_A[9];
  int32_T c3_i61;
  real_T c3_b_B[9];
  int32_T c3_i62;
  real_T c3_c_A[9];
  int32_T c3_i63;
  real_T c3_c_B[9];
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  real_T c3_b_y[9];
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i70;
  real_T c3_b_eq[3];
  int32_T c3_i71;
  real_T c3_x[3];
  int32_T c3_i72;
  real_T c3_b_b_in_w[3];
  real_T c3_c_y;
  int32_T c3_i73;
  real_T c3_b_x[3];
  real_T c3_d_y;
  int32_T c3_i74;
  real_T c3_c_x[3];
  real_T c3_e_y;
  int32_T c3_i75;
  int32_T c3_i76;
  real_T c3_d_x[3];
  int32_T c3_i77;
  real_T c3_c_b_in_w[3];
  real_T c3_f_y;
  int32_T c3_i78;
  real_T c3_e_x[3];
  real_T c3_g_y;
  int32_T c3_i79;
  real_T c3_f_x[3];
  real_T c3_h_y;
  int32_T c3_i80;
  int32_T c3_i81;
  real_T c3_g_x[3];
  int32_T c3_i82;
  real_T c3_d_b_in_w[3];
  real_T c3_i_y;
  int32_T c3_i83;
  real_T c3_h_x[3];
  real_T c3_j_y;
  int32_T c3_i84;
  real_T c3_i_x[3];
  real_T c3_k_y;
  int32_T c3_i85;
  int32_T c3_i86;
  real_T c3_c_a[9];
  int32_T c3_i87;
  real_T c3_b_b[3];
  int32_T c3_i88;
  real_T c3_d_A[9];
  int32_T c3_i89;
  real_T c3_d_B[3];
  int32_T c3_i90;
  real_T c3_e_A[9];
  int32_T c3_i91;
  real_T c3_e_B[3];
  int32_T c3_i92;
  real_T c3_f_A[9];
  int32_T c3_i93;
  real_T c3_f_B[3];
  int32_T c3_i94;
  real_T c3_l_y[3];
  int32_T c3_i95;
  int32_T c3_i96;
  int32_T c3_i97;
  real_T c3_m_y[3];
  int32_T c3_i98;
  real_T c3_b_n1hat[3];
  real_T c3_c_b[3];
  int32_T c3_i99;
  real_T c3_dv6[3];
  int32_T c3_i100;
  real_T c3_d_b[3];
  int32_T c3_i101;
  real_T c3_d_a[9];
  int32_T c3_i102;
  real_T c3_e_b[3];
  int32_T c3_i103;
  real_T c3_g_A[9];
  int32_T c3_i104;
  real_T c3_g_B[3];
  int32_T c3_i105;
  real_T c3_h_A[9];
  int32_T c3_i106;
  real_T c3_h_B[3];
  int32_T c3_i107;
  real_T c3_i_A[9];
  int32_T c3_i108;
  real_T c3_i_B[3];
  int32_T c3_i109;
  real_T c3_n_y[3];
  int32_T c3_i110;
  int32_T c3_i111;
  int32_T c3_i112;
  real_T c3_o_y[3];
  int32_T c3_i113;
  real_T c3_b_n2hat[3];
  real_T c3_f_b[3];
  int32_T c3_i114;
  real_T c3_dv7[3];
  int32_T c3_i115;
  real_T c3_g_b[3];
  int32_T c3_i116;
  real_T c3_e_a[9];
  int32_T c3_i117;
  real_T c3_h_b[3];
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
  real_T c3_p_y[3];
  int32_T c3_i125;
  int32_T c3_i126;
  int32_T c3_i127;
  real_T c3_q_y[3];
  int32_T c3_i128;
  real_T c3_b_n3hat[3];
  real_T c3_i_b[3];
  int32_T c3_i129;
  real_T c3_dv8[3];
  int32_T c3_i130;
  real_T c3_j_b[3];
  int32_T c3_i131;
  real_T c3_e_b_in_w[3];
  int32_T c3_i132;
  real_T c3_f_b_in_w[3];
  int32_T c3_i133;
  real_T c3_g_b_in_w[3];
  int32_T c3_i134;
  real_T c3_j_x[3];
  int32_T c3_i135;
  real_T c3_b_m_in_w[3];
  real_T c3_r_y;
  int32_T c3_i136;
  real_T c3_k_x[3];
  real_T c3_s_y;
  int32_T c3_i137;
  real_T c3_l_x[3];
  real_T c3_t_y;
  int32_T c3_i138;
  int32_T c3_i139;
  real_T c3_m_x[3];
  int32_T c3_i140;
  real_T c3_c_m_in_w[3];
  real_T c3_u_y;
  int32_T c3_i141;
  real_T c3_n_x[3];
  real_T c3_v_y;
  int32_T c3_i142;
  real_T c3_o_x[3];
  real_T c3_w_y;
  int32_T c3_i143;
  int32_T c3_i144;
  real_T c3_p_x[3];
  int32_T c3_i145;
  real_T c3_d_m_in_w[3];
  real_T c3_x_y;
  int32_T c3_i146;
  real_T c3_q_x[3];
  real_T c3_y_y;
  int32_T c3_i147;
  real_T c3_r_x[3];
  real_T c3_ab_y;
  int32_T c3_i148;
  int32_T c3_i149;
  real_T c3_e_m_in_w[3];
  int32_T c3_i150;
  real_T c3_f_m_in_w[3];
  int32_T c3_i151;
  real_T c3_g_m_in_w[3];
  int32_T c3_i152;
  real_T c3_h_b_in_w[3];
  int32_T c3_i153;
  real_T c3_i_b_in_w[3];
  int32_T c3_i154;
  real_T c3_j_b_in_w[3];
  real_T c3_k_b;
  real_T c3_bb_y;
  real_T c3_f_a;
  real_T c3_l_b;
  real_T c3_cb_y;
  real_T c3_m_A;
  real_T c3_m_B;
  real_T c3_s_x;
  real_T c3_db_y;
  real_T c3_t_x;
  real_T c3_eb_y;
  real_T c3_u_x;
  real_T c3_fb_y;
  real_T c3_m_b;
  real_T c3_gb_y;
  real_T c3_g_a;
  real_T c3_n_b;
  real_T c3_hb_y;
  real_T c3_n_A;
  real_T c3_n_B;
  real_T c3_v_x;
  real_T c3_ib_y;
  real_T c3_w_x;
  real_T c3_jb_y;
  real_T c3_x_x;
  real_T c3_kb_y;
  real_T c3_o_b;
  real_T c3_lb_y;
  real_T c3_h_a;
  real_T c3_p_b;
  real_T c3_mb_y;
  real_T c3_o_A;
  real_T c3_o_B;
  real_T c3_y_x;
  real_T c3_nb_y;
  real_T c3_ab_x;
  real_T c3_ob_y;
  real_T c3_bb_x;
  real_T c3_pb_y;
  real_T c3_q_b;
  real_T c3_qb_y;
  real_T c3_i_a;
  real_T c3_r_b;
  real_T c3_rb_y;
  real_T c3_j_a;
  real_T c3_sb_y;
  real_T c3_k_a;
  real_T c3_s_b;
  real_T c3_tb_y;
  real_T c3_t_b;
  real_T c3_ub_y;
  real_T c3_l_a;
  real_T c3_u_b;
  real_T c3_vb_y;
  real_T c3_p_A;
  real_T c3_p_B;
  real_T c3_cb_x;
  real_T c3_wb_y;
  real_T c3_db_x;
  real_T c3_xb_y;
  real_T c3_eb_x;
  real_T c3_yb_y;
  real_T c3_v_b;
  real_T c3_ac_y;
  real_T c3_m_a;
  real_T c3_w_b;
  real_T c3_bc_y;
  real_T c3_n_a;
  real_T c3_cc_y;
  real_T c3_o_a;
  real_T c3_x_b;
  real_T c3_dc_y;
  real_T c3_y_b;
  real_T c3_ec_y;
  real_T c3_p_a;
  real_T c3_ab_b;
  real_T c3_fc_y;
  real_T c3_q_A;
  real_T c3_q_B;
  real_T c3_fb_x;
  real_T c3_gc_y;
  real_T c3_gb_x;
  real_T c3_hc_y;
  real_T c3_hb_x;
  real_T c3_ic_y;
  real_T c3_bb_b;
  real_T c3_jc_y;
  real_T c3_q_a;
  real_T c3_cb_b;
  real_T c3_kc_y;
  real_T c3_r_a;
  real_T c3_lc_y;
  real_T c3_s_a;
  real_T c3_db_b;
  real_T c3_mc_y;
  real_T c3_eb_b;
  real_T c3_nc_y;
  real_T c3_t_a;
  real_T c3_fb_b;
  real_T c3_oc_y;
  real_T c3_r_A;
  real_T c3_r_B;
  real_T c3_ib_x;
  real_T c3_pc_y;
  real_T c3_jb_x;
  real_T c3_qc_y;
  real_T c3_kb_x;
  real_T c3_rc_y;
  int32_T c3_i155;
  real_T c3_u_a[3];
  int32_T c3_i156;
  real_T c3_gb_b[3];
  int32_T c3_i157;
  real_T c3_v_a[3];
  int32_T c3_i158;
  real_T c3_hb_b[3];
  real_T c3_sc_y;
  real_T c3_w_a;
  real_T c3_ib_b;
  real_T c3_tc_y;
  real_T c3_s_A;
  real_T c3_s_B;
  real_T c3_lb_x;
  real_T c3_uc_y;
  real_T c3_mb_x;
  real_T c3_vc_y;
  real_T c3_nb_x;
  real_T c3_wc_y;
  real_T c3_xc_y;
  real_T c3_x_a;
  int32_T c3_i159;
  real_T c3_jb_b[3];
  int32_T c3_i160;
  real_T c3_yc_y[3];
  int32_T c3_i161;
  real_T c3_y_a[3];
  int32_T c3_i162;
  real_T c3_dv9[3];
  int32_T c3_i163;
  real_T c3_b_l1_hat[3];
  real_T c3_kb_b[3];
  int32_T c3_i164;
  real_T c3_ab_a[3];
  int32_T c3_i165;
  real_T c3_lb_b[3];
  real_T c3_ad_y;
  int32_T c3_i166;
  real_T c3_bb_a[3];
  int32_T c3_i167;
  real_T c3_mb_b[3];
  int32_T c3_i168;
  real_T c3_cb_a[3];
  int32_T c3_i169;
  real_T c3_nb_b[3];
  real_T c3_bd_y;
  real_T c3_db_a;
  real_T c3_ob_b;
  real_T c3_cd_y;
  real_T c3_t_A;
  real_T c3_t_B;
  real_T c3_ob_x;
  real_T c3_dd_y;
  real_T c3_pb_x;
  real_T c3_ed_y;
  real_T c3_qb_x;
  real_T c3_fd_y;
  real_T c3_gd_y;
  real_T c3_eb_a;
  int32_T c3_i170;
  real_T c3_pb_b[3];
  int32_T c3_i171;
  real_T c3_hd_y[3];
  int32_T c3_i172;
  real_T c3_fb_a[3];
  int32_T c3_i173;
  real_T c3_dv10[3];
  int32_T c3_i174;
  real_T c3_b_l2_hat[3];
  real_T c3_qb_b[3];
  int32_T c3_i175;
  real_T c3_gb_a[3];
  int32_T c3_i176;
  real_T c3_rb_b[3];
  real_T c3_id_y;
  int32_T c3_i177;
  real_T c3_hb_a[3];
  int32_T c3_i178;
  real_T c3_sb_b[3];
  int32_T c3_i179;
  real_T c3_ib_a[3];
  int32_T c3_i180;
  real_T c3_tb_b[3];
  real_T c3_jd_y;
  real_T c3_jb_a;
  real_T c3_ub_b;
  real_T c3_kd_y;
  real_T c3_u_A;
  real_T c3_u_B;
  real_T c3_rb_x;
  real_T c3_ld_y;
  real_T c3_sb_x;
  real_T c3_md_y;
  real_T c3_tb_x;
  real_T c3_nd_y;
  real_T c3_od_y;
  real_T c3_kb_a;
  int32_T c3_i181;
  real_T c3_vb_b[3];
  int32_T c3_i182;
  real_T c3_pd_y[3];
  int32_T c3_i183;
  real_T c3_lb_a[3];
  int32_T c3_i184;
  real_T c3_dv11[3];
  int32_T c3_i185;
  real_T c3_b_l3_hat[3];
  real_T c3_wb_b[3];
  int32_T c3_i186;
  real_T c3_mb_a[3];
  int32_T c3_i187;
  real_T c3_xb_b[3];
  real_T c3_qd_y;
  int32_T c3_i188;
  static real_T c3_dv12[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c3_i189;
  int32_T c3_i190;
  int32_T c3_i191;
  int32_T c3_i192;
  int32_T c3_i193;
  int32_T c3_i194;
  int32_T c3_i195;
  static real_T c3_dv13[36] = { 1.0E+010, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E+010,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E+010, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0 };

  int32_T c3_i196;
  real_T c3_v_A[18];
  int32_T c3_i197;
  real_T c3_dv14[36];
  int32_T c3_i198;
  int32_T c3_i199;
  int32_T c3_i200;
  int32_T c3_i201;
  real_T c3_w_A[18];
  real_T c3_dv15[18];
  int32_T c3_i202;
  int32_T c3_i203;
  int32_T c3_i204;
  int32_T c3_i205;
  real_T c3_rd_y[18];
  int32_T c3_i206;
  real_T c3_nb_a[18];
  int32_T c3_i207;
  int32_T c3_i208;
  int32_T c3_i209;
  int32_T c3_i210;
  real_T c3_yb_b[18];
  int32_T c3_i211;
  real_T c3_x_A[18];
  int32_T c3_i212;
  real_T c3_v_B[18];
  int32_T c3_i213;
  real_T c3_y_A[18];
  int32_T c3_i214;
  real_T c3_w_B[18];
  int32_T c3_i215;
  real_T c3_ab_A[18];
  int32_T c3_i216;
  real_T c3_x_B[18];
  int32_T c3_i217;
  int32_T c3_i218;
  int32_T c3_i219;
  int32_T c3_i220;
  real_T c3_sd_y[9];
  int32_T c3_i221;
  int32_T c3_i222;
  int32_T c3_i223;
  real_T c3_dv16[36];
  int32_T c3_i224;
  int32_T c3_i225;
  int32_T c3_i226;
  int32_T c3_i227;
  real_T c3_b_iik_jac[18];
  real_T c3_dv17[18];
  int32_T c3_i228;
  real_T c3_dv18[18];
  int32_T c3_i229;
  real_T c3_td_y[9];
  real_T c3_ob_a[18];
  int32_T c3_i230;
  real_T c3_ac_b[9];
  int32_T c3_i231;
  real_T c3_bb_A[18];
  int32_T c3_i232;
  real_T c3_y_B[9];
  int32_T c3_i233;
  int32_T c3_i234;
  real_T c3_cb_A[18];
  int32_T c3_i235;
  real_T c3_ab_B[9];
  int32_T c3_i236;
  real_T c3_db_A[18];
  int32_T c3_i237;
  real_T c3_bb_B[9];
  int32_T c3_i238;
  int32_T c3_i239;
  int32_T c3_i240;
  int32_T c3_i241;
  int32_T c3_i242;
  int32_T c3_i243;
  real_T c3_pb_a;
  int32_T c3_i244;
  real_T c3_bc_b[3];
  int32_T c3_i245;
  int32_T c3_i246;
  real_T c3_qb_a[18];
  int32_T c3_i247;
  real_T c3_cc_b[3];
  int32_T c3_i248;
  real_T c3_eb_A[18];
  int32_T c3_i249;
  real_T c3_cb_B[3];
  int32_T c3_i250;
  int32_T c3_i251;
  real_T c3_fb_A[18];
  int32_T c3_i252;
  real_T c3_db_B[3];
  int32_T c3_i253;
  real_T c3_gb_A[18];
  int32_T c3_i254;
  real_T c3_eb_B[3];
  int32_T c3_i255;
  int32_T c3_i256;
  int32_T c3_i257;
  int32_T c3_i258;
  int32_T c3_i259;
  real_T c3_rb_a[2];
  real_T c3_dc_b;
  int32_T c3_i260;
  real_T c3_ud_y[2];
  int32_T c3_i261;
  real_T c3_b_twave[2];
  int32_T c3_i262;
  real_T c3_sb_a;
  real_T c3_ec_b;
  real_T c3_vd_y;
  real_T c3_ub_x;
  real_T c3_vb_x;
  real_T c3_wb_x;
  real_T c3_tb_a;
  real_T c3_fc_b;
  real_T c3_wd_y;
  real_T c3_xb_x;
  real_T c3_yb_x;
  real_T c3_ac_x;
  real_T c3_ub_a;
  real_T c3_gc_b;
  real_T c3_xd_y;
  real_T c3_bc_x;
  real_T c3_cc_x;
  real_T c3_dc_x;
  real_T c3_vb_a;
  real_T c3_hc_b;
  real_T c3_yd_y;
  real_T c3_ec_x;
  real_T c3_fc_x;
  real_T c3_gc_x;
  int32_T c3_i263;
  int32_T c3_i264;
  int32_T c3_i265;
  real_T c3_wb_a[9];
  int32_T c3_i266;
  real_T c3_ic_b[9];
  int32_T c3_i267;
  real_T c3_hb_A[9];
  int32_T c3_i268;
  real_T c3_fb_B[9];
  int32_T c3_i269;
  int32_T c3_i270;
  real_T c3_ib_A[9];
  int32_T c3_i271;
  real_T c3_gb_B[9];
  int32_T c3_i272;
  real_T c3_jb_A[9];
  int32_T c3_i273;
  real_T c3_hb_B[9];
  int32_T c3_i274;
  int32_T c3_i275;
  int32_T c3_i276;
  int32_T c3_i277;
  int32_T c3_i278;
  int32_T c3_i279;
  real_T c3_b_i;
  int32_T c3_i280;
  real_T c3_xb_a[9];
  int32_T c3_c_i;
  int32_T c3_i281;
  real_T c3_jc_b[3];
  int32_T c3_i282;
  real_T c3_kb_A[9];
  int32_T c3_i283;
  real_T c3_ib_B[3];
  int32_T c3_i284;
  real_T c3_lb_A[9];
  int32_T c3_i285;
  real_T c3_jb_B[3];
  int32_T c3_i286;
  real_T c3_mb_A[9];
  int32_T c3_i287;
  real_T c3_kb_B[3];
  int32_T c3_i288;
  real_T c3_ae_y[3];
  int32_T c3_i289;
  int32_T c3_i290;
  int32_T c3_d_i;
  int32_T c3_i291;
  int32_T c3_e_i;
  int32_T c3_f_i;
  int32_T c3_i292;
  real_T c3_b_p_in_w[3];
  int32_T c3_i293;
  int32_T c3_i294;
  real_T c3_nb_A[3];
  real_T c3_lb_B;
  int32_T c3_i295;
  real_T c3_hc_x[3];
  real_T c3_be_y;
  int32_T c3_i296;
  real_T c3_ic_x[3];
  real_T c3_ce_y;
  int32_T c3_i297;
  real_T c3_jc_x[3];
  real_T c3_de_y;
  int32_T c3_i298;
  real_T c3_ee_y[3];
  int32_T c3_i299;
  int32_T c3_i300;
  int32_T c3_i301;
  int32_T c3_i302;
  int32_T c3_i303;
  int32_T c3_i304;
  int32_T c3_i305;
  int32_T c3_i306;
  int32_T c3_i307;
  int32_T c3_i308;
  int32_T c3_i309;
  int32_T c3_i310;
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
  real_T (*c3_b_f_in_w)[9];
  real_T (*c3_h_m_in_w)[9];
  real_T (*c3_k_b_in_w)[9];
  real_T (*c3_b_p_in_m)[9];
  real_T (*c3_b_qcur)[6];
  c3_b_rwave = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 13);
  c3_c_twave = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 12);
  c3_b_rwave_out = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_b_twave_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_eq_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_c_eq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 11);
  c3_b_macro_leg_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 10);
  c3_b_velmex_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_b_measured_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 8);
  c3_b_f_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 7);
  c3_h_m_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
  c3_k_b_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_p_in_m = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_kp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_des_leg_len = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_qcmd = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_eqeps = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_qcur = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  for (c3_i30 = 0; c3_i30 < 6; c3_i30 = c3_i30 + 1) {
    c3_hoistedGlobal[c3_i30] = (*c3_b_qcur)[c3_i30];
  }

  c3_b_hoistedGlobal = *c3_b_eqeps;
  c3_c_hoistedGlobal = *c3_b_kp;
  c3_d_hoistedGlobal = *c3_b_dt;
  for (c3_i31 = 0; c3_i31 < 9; c3_i31 = c3_i31 + 1) {
    c3_e_hoistedGlobal[c3_i31] = (*c3_b_p_in_m)[c3_i31];
  }

  for (c3_i32 = 0; c3_i32 < 9; c3_i32 = c3_i32 + 1) {
    c3_f_hoistedGlobal[c3_i32] = (*c3_k_b_in_w)[c3_i32];
  }

  for (c3_i33 = 0; c3_i33 < 9; c3_i33 = c3_i33 + 1) {
    c3_g_hoistedGlobal[c3_i33] = (*c3_h_m_in_w)[c3_i33];
  }

  for (c3_i34 = 0; c3_i34 < 9; c3_i34 = c3_i34 + 1) {
    c3_h_hoistedGlobal[c3_i34] = (*c3_b_f_in_w)[c3_i34];
  }

  for (c3_i35 = 0; c3_i35 < 3; c3_i35 = c3_i35 + 1) {
    c3_i_hoistedGlobal[c3_i35] = (*c3_b_measured_len)[c3_i35];
  }

  c3_j_hoistedGlobal = *c3_b_velmex_pitch;
  for (c3_i36 = 0; c3_i36 < 3; c3_i36 = c3_i36 + 1) {
    c3_k_hoistedGlobal[c3_i36] = (*c3_b_macro_leg_len)[c3_i36];
  }

  for (c3_i37 = 0; c3_i37 < 3; c3_i37 = c3_i37 + 1) {
    c3_l_hoistedGlobal[c3_i37] = (*c3_c_eq)[c3_i37];
  }

  for (c3_i38 = 0; c3_i38 < 3; c3_i38 = c3_i38 + 1) {
    c3_m_hoistedGlobal[c3_i38] = (*c3_c_twave)[c3_i38];
  }

  for (c3_i39 = 0; c3_i39 < 9; c3_i39 = c3_i39 + 1) {
    c3_n_hoistedGlobal[c3_i39] = (*c3_b_rwave)[c3_i39];
  }

  for (c3_i40 = 0; c3_i40 < 6; c3_i40 = c3_i40 + 1) {
    c3_qcur[c3_i40] = c3_hoistedGlobal[c3_i40];
  }

  c3_eqeps = c3_b_hoistedGlobal;
  c3_kp = c3_c_hoistedGlobal;
  c3_dt = c3_d_hoistedGlobal;
  for (c3_i41 = 0; c3_i41 < 9; c3_i41 = c3_i41 + 1) {
    c3_p_in_m[c3_i41] = c3_e_hoistedGlobal[c3_i41];
  }

  for (c3_i42 = 0; c3_i42 < 9; c3_i42 = c3_i42 + 1) {
    c3_b_in_w[c3_i42] = c3_f_hoistedGlobal[c3_i42];
  }

  for (c3_i43 = 0; c3_i43 < 9; c3_i43 = c3_i43 + 1) {
    c3_m_in_w[c3_i43] = c3_g_hoistedGlobal[c3_i43];
  }

  for (c3_i44 = 0; c3_i44 < 9; c3_i44 = c3_i44 + 1) {
    c3_f_in_w[c3_i44] = c3_h_hoistedGlobal[c3_i44];
  }

  for (c3_i45 = 0; c3_i45 < 3; c3_i45 = c3_i45 + 1) {
    c3_measured_len[c3_i45] = c3_i_hoistedGlobal[c3_i45];
  }

  c3_velmex_pitch = c3_j_hoistedGlobal;
  for (c3_i46 = 0; c3_i46 < 3; c3_i46 = c3_i46 + 1) {
    c3_macro_leg_len[c3_i46] = c3_k_hoistedGlobal[c3_i46];
  }

  for (c3_i47 = 0; c3_i47 < 3; c3_i47 = c3_i47 + 1) {
    c3_eq[c3_i47] = c3_l_hoistedGlobal[c3_i47];
  }

  for (c3_i48 = 0; c3_i48 < 3; c3_i48 = c3_i48 + 1) {
    c3_twave[c3_i48] = c3_m_hoistedGlobal[c3_i48];
  }

  for (c3_i49 = 0; c3_i49 < 9; c3_i49 = c3_i49 + 1) {
    c3_rwave[c3_i49] = c3_n_hoistedGlobal[c3_i49];
  }

  sf_debug_symbol_scope_push_eml(0U, 62U, 62U, c3_sv0, c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_z0, c3_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c3_p_in_w, c3_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c3_n1hat, c3_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c3_n2hat, c3_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c3_n3hat, c3_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c3_a13, c3_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c3_a23, c3_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c3_a33, c3_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c3_idk_jac, c3_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c3_q1_mu, c3_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c3_q2_mu, c3_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c3_q3_mu, c3_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c3_l1_hat, c3_b_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c3_l2_hat, c3_b_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c3_l3_hat, c3_b_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c3_a1, c3_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c3_a2, c3_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c3_a3, c3_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c3_c1, c3_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c3_c2, c3_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c3_c3, c3_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c3_h1, c3_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c3_h2, c3_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c3_h3, c3_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c3_h1dot, c3_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c3_h2dot, c3_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c3_h3dot, c3_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c3_e1, c3_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c3_e2, c3_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c3_e3, c3_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c3_b_mu, c3_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c3_b_m, c3_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c3_iik_jac, c3_h_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c3_w_mat, c3_g_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c3_full_jac, c3_f_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c3_qdot, c3_b_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c3_tdot, c3_c_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c3_v, c3_e_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c3_w, c3_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c3_del_r, c3_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c3_i, c3_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c3_nargin, c3_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c3_nargout, c3_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c3_qcur, c3_c_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c3_eqeps, c3_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c3_kp, c3_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c3_dt, c3_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c3_p_in_m, c3_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c3_b_in_w, c3_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c3_m_in_w, c3_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c3_f_in_w, c3_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c3_measured_len, c3_b_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c3_velmex_pitch, c3_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c3_macro_leg_len, c3_b_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c3_eq, c3_b_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c3_twave, c3_b_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c3_rwave, c3_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c3_qcmd, c3_c_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c3_des_leg_len, c3_b_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c3_eq_out, c3_b_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c3_twave_out, c3_b_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c3_rwave_out, c3_sf_marshall, 61U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  for (c3_i50 = 0; c3_i50 < 6; c3_i50 = c3_i50 + 1) {
    c3_qcmd[c3_i50] = c3_qcur[c3_i50];
  }

  _SFD_EML_CALL(0,5);
  for (c3_i51 = 0; c3_i51 < 3; c3_i51 = c3_i51 + 1) {
    c3_z0[c3_i51] = c3_dv5[c3_i51];
  }

  /*  moving platform vertex locations */
  _SFD_EML_CALL(0,8);
  for (c3_i52 = 0; c3_i52 < 3; c3_i52 = c3_i52 + 1) {
    c3_a[c3_i52] = c3_twave[c3_i52];
  }

  c3_i53 = 0;
  for (c3_i54 = 0; c3_i54 < 3; c3_i54 = c3_i54 + 1) {
    for (c3_i55 = 0; c3_i55 < 3; c3_i55 = c3_i55 + 1) {
      c3_y[c3_i55 + c3_i53] = c3_a[c3_i55];
    }

    c3_i53 = c3_i53 + 3;
  }

  for (c3_i56 = 0; c3_i56 < 9; c3_i56 = c3_i56 + 1) {
    c3_b_a[c3_i56] = c3_rwave[c3_i56];
  }

  for (c3_i57 = 0; c3_i57 < 9; c3_i57 = c3_i57 + 1) {
    c3_b[c3_i57] = c3_p_in_m[c3_i57];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i58 = 0; c3_i58 < 9; c3_i58 = c3_i58 + 1) {
    c3_A[c3_i58] = c3_b_a[c3_i58];
  }

  for (c3_i59 = 0; c3_i59 < 9; c3_i59 = c3_i59 + 1) {
    c3_B[c3_i59] = c3_b[c3_i59];
  }

  for (c3_i60 = 0; c3_i60 < 9; c3_i60 = c3_i60 + 1) {
    c3_b_A[c3_i60] = c3_A[c3_i60];
  }

  for (c3_i61 = 0; c3_i61 < 9; c3_i61 = c3_i61 + 1) {
    c3_b_B[c3_i61] = c3_B[c3_i61];
  }

  for (c3_i62 = 0; c3_i62 < 9; c3_i62 = c3_i62 + 1) {
    c3_c_A[c3_i62] = c3_b_A[c3_i62];
  }

  for (c3_i63 = 0; c3_i63 < 9; c3_i63 = c3_i63 + 1) {
    c3_c_B[c3_i63] = c3_b_B[c3_i63];
  }

  for (c3_i64 = 0; c3_i64 < 3; c3_i64 = c3_i64 + 1) {
    c3_i65 = 0;
    for (c3_i66 = 0; c3_i66 < 3; c3_i66 = c3_i66 + 1) {
      c3_b_y[c3_i65 + c3_i64] = 0.0;
      c3_i67 = 0;
      for (c3_i68 = 0; c3_i68 < 3; c3_i68 = c3_i68 + 1) {
        c3_b_y[c3_i65 + c3_i64] = c3_b_y[c3_i65 + c3_i64] + c3_c_A[c3_i67 +
          c3_i64] * c3_c_B[c3_i68 + c3_i65];
        c3_i67 = c3_i67 + 3;
      }

      c3_i65 = c3_i65 + 3;
    }
  }

  for (c3_i69 = 0; c3_i69 < 9; c3_i69 = c3_i69 + 1) {
    c3_p_in_w[c3_i69] = c3_y[c3_i69] + c3_b_y[c3_i69];
  }

  _SFD_EML_CALL(0,10);
  for (c3_i70 = 0; c3_i70 < 3; c3_i70 = c3_i70 + 1) {
    c3_b_eq[c3_i70] = c3_eq[c3_i70];
  }

  if (CV_EML_IF(0, 0, c3_norm(chartInstance, c3_b_eq) > c3_eqeps)) {
    /*     %% instantaneous direct kinematics jacobian */
    /*  vector from base vertex to moving platform vertex */
    _SFD_EML_CALL(0,13);
    for (c3_i71 = 0; c3_i71 < 3; c3_i71 = c3_i71 + 1) {
      c3_x[c3_i71] = c3_p_in_w[c3_i71] - c3_b_in_w[c3_i71];
    }

    for (c3_i72 = 0; c3_i72 < 3; c3_i72 = c3_i72 + 1) {
      c3_b_b_in_w[c3_i72] = c3_b_in_w[c3_i72] - c3_p_in_w[c3_i72];
    }

    c3_c_y = c3_norm(chartInstance, c3_b_b_in_w);
    for (c3_i73 = 0; c3_i73 < 3; c3_i73 = c3_i73 + 1) {
      c3_b_x[c3_i73] = c3_x[c3_i73];
    }

    c3_d_y = c3_c_y;
    for (c3_i74 = 0; c3_i74 < 3; c3_i74 = c3_i74 + 1) {
      c3_c_x[c3_i74] = c3_b_x[c3_i74];
    }

    c3_e_y = c3_d_y;
    for (c3_i75 = 0; c3_i75 < 3; c3_i75 = c3_i75 + 1) {
      c3_n1hat[c3_i75] = c3_c_x[c3_i75] / c3_e_y;
    }

    _SFD_EML_CALL(0,14);
    for (c3_i76 = 0; c3_i76 < 3; c3_i76 = c3_i76 + 1) {
      c3_d_x[c3_i76] = c3_p_in_w[c3_i76 + 3] - c3_b_in_w[c3_i76 + 3];
    }

    for (c3_i77 = 0; c3_i77 < 3; c3_i77 = c3_i77 + 1) {
      c3_c_b_in_w[c3_i77] = c3_b_in_w[c3_i77 + 3] - c3_p_in_w[c3_i77 + 3];
    }

    c3_f_y = c3_norm(chartInstance, c3_c_b_in_w);
    for (c3_i78 = 0; c3_i78 < 3; c3_i78 = c3_i78 + 1) {
      c3_e_x[c3_i78] = c3_d_x[c3_i78];
    }

    c3_g_y = c3_f_y;
    for (c3_i79 = 0; c3_i79 < 3; c3_i79 = c3_i79 + 1) {
      c3_f_x[c3_i79] = c3_e_x[c3_i79];
    }

    c3_h_y = c3_g_y;
    for (c3_i80 = 0; c3_i80 < 3; c3_i80 = c3_i80 + 1) {
      c3_n2hat[c3_i80] = c3_f_x[c3_i80] / c3_h_y;
    }

    _SFD_EML_CALL(0,15);
    for (c3_i81 = 0; c3_i81 < 3; c3_i81 = c3_i81 + 1) {
      c3_g_x[c3_i81] = c3_p_in_w[c3_i81 + 6] - c3_b_in_w[c3_i81 + 6];
    }

    for (c3_i82 = 0; c3_i82 < 3; c3_i82 = c3_i82 + 1) {
      c3_d_b_in_w[c3_i82] = c3_b_in_w[c3_i82 + 6] - c3_p_in_w[c3_i82 + 6];
    }

    c3_i_y = c3_norm(chartInstance, c3_d_b_in_w);
    for (c3_i83 = 0; c3_i83 < 3; c3_i83 = c3_i83 + 1) {
      c3_h_x[c3_i83] = c3_g_x[c3_i83];
    }

    c3_j_y = c3_i_y;
    for (c3_i84 = 0; c3_i84 < 3; c3_i84 = c3_i84 + 1) {
      c3_i_x[c3_i84] = c3_h_x[c3_i84];
    }

    c3_k_y = c3_j_y;
    for (c3_i85 = 0; c3_i85 < 3; c3_i85 = c3_i85 + 1) {
      c3_n3hat[c3_i85] = c3_i_x[c3_i85] / c3_k_y;
    }

    _SFD_EML_CALL(0,17);
    for (c3_i86 = 0; c3_i86 < 9; c3_i86 = c3_i86 + 1) {
      c3_c_a[c3_i86] = c3_rwave[c3_i86];
    }

    for (c3_i87 = 0; c3_i87 < 3; c3_i87 = c3_i87 + 1) {
      c3_b_b[c3_i87] = c3_p_in_m[c3_i87];
    }

    c3_c_eml_scalar_eg(chartInstance);
    c3_c_eml_scalar_eg(chartInstance);
    for (c3_i88 = 0; c3_i88 < 9; c3_i88 = c3_i88 + 1) {
      c3_d_A[c3_i88] = c3_c_a[c3_i88];
    }

    for (c3_i89 = 0; c3_i89 < 3; c3_i89 = c3_i89 + 1) {
      c3_d_B[c3_i89] = c3_b_b[c3_i89];
    }

    for (c3_i90 = 0; c3_i90 < 9; c3_i90 = c3_i90 + 1) {
      c3_e_A[c3_i90] = c3_d_A[c3_i90];
    }

    for (c3_i91 = 0; c3_i91 < 3; c3_i91 = c3_i91 + 1) {
      c3_e_B[c3_i91] = c3_d_B[c3_i91];
    }

    for (c3_i92 = 0; c3_i92 < 9; c3_i92 = c3_i92 + 1) {
      c3_f_A[c3_i92] = c3_e_A[c3_i92];
    }

    for (c3_i93 = 0; c3_i93 < 3; c3_i93 = c3_i93 + 1) {
      c3_f_B[c3_i93] = c3_e_B[c3_i93];
    }

    for (c3_i94 = 0; c3_i94 < 3; c3_i94 = c3_i94 + 1) {
      c3_l_y[c3_i94] = 0.0;
      c3_i95 = 0;
      for (c3_i96 = 0; c3_i96 < 3; c3_i96 = c3_i96 + 1) {
        c3_l_y[c3_i94] = c3_l_y[c3_i94] + c3_f_A[c3_i95 + c3_i94] *
          c3_f_B[c3_i96];
        c3_i95 = c3_i95 + 3;
      }
    }

    for (c3_i97 = 0; c3_i97 < 3; c3_i97 = c3_i97 + 1) {
      c3_m_y[c3_i97] = c3_l_y[c3_i97];
    }

    for (c3_i98 = 0; c3_i98 < 3; c3_i98 = c3_i98 + 1) {
      c3_b_n1hat[c3_i98] = c3_n1hat[c3_i98];
    }

    c3_cross(chartInstance, c3_m_y, c3_b_n1hat, c3_c_b);
    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i99 = 0; c3_i99 < 3; c3_i99 = c3_i99 + 1) {
      c3_dv6[c3_i99] = c3_dv5[c3_i99];
    }

    for (c3_i100 = 0; c3_i100 < 3; c3_i100 = c3_i100 + 1) {
      c3_d_b[c3_i100] = c3_c_b[c3_i100];
    }

    c3_a13 = c3_eml_xdotu(chartInstance, c3_dv6, c3_d_b);
    _SFD_EML_CALL(0,18);
    for (c3_i101 = 0; c3_i101 < 9; c3_i101 = c3_i101 + 1) {
      c3_d_a[c3_i101] = c3_rwave[c3_i101];
    }

    for (c3_i102 = 0; c3_i102 < 3; c3_i102 = c3_i102 + 1) {
      c3_e_b[c3_i102] = c3_p_in_m[c3_i102 + 3];
    }

    c3_c_eml_scalar_eg(chartInstance);
    c3_c_eml_scalar_eg(chartInstance);
    for (c3_i103 = 0; c3_i103 < 9; c3_i103 = c3_i103 + 1) {
      c3_g_A[c3_i103] = c3_d_a[c3_i103];
    }

    for (c3_i104 = 0; c3_i104 < 3; c3_i104 = c3_i104 + 1) {
      c3_g_B[c3_i104] = c3_e_b[c3_i104];
    }

    for (c3_i105 = 0; c3_i105 < 9; c3_i105 = c3_i105 + 1) {
      c3_h_A[c3_i105] = c3_g_A[c3_i105];
    }

    for (c3_i106 = 0; c3_i106 < 3; c3_i106 = c3_i106 + 1) {
      c3_h_B[c3_i106] = c3_g_B[c3_i106];
    }

    for (c3_i107 = 0; c3_i107 < 9; c3_i107 = c3_i107 + 1) {
      c3_i_A[c3_i107] = c3_h_A[c3_i107];
    }

    for (c3_i108 = 0; c3_i108 < 3; c3_i108 = c3_i108 + 1) {
      c3_i_B[c3_i108] = c3_h_B[c3_i108];
    }

    for (c3_i109 = 0; c3_i109 < 3; c3_i109 = c3_i109 + 1) {
      c3_n_y[c3_i109] = 0.0;
      c3_i110 = 0;
      for (c3_i111 = 0; c3_i111 < 3; c3_i111 = c3_i111 + 1) {
        c3_n_y[c3_i109] = c3_n_y[c3_i109] + c3_i_A[c3_i110 + c3_i109] *
          c3_i_B[c3_i111];
        c3_i110 = c3_i110 + 3;
      }
    }

    for (c3_i112 = 0; c3_i112 < 3; c3_i112 = c3_i112 + 1) {
      c3_o_y[c3_i112] = c3_n_y[c3_i112];
    }

    for (c3_i113 = 0; c3_i113 < 3; c3_i113 = c3_i113 + 1) {
      c3_b_n2hat[c3_i113] = c3_n2hat[c3_i113];
    }

    c3_cross(chartInstance, c3_o_y, c3_b_n2hat, c3_f_b);
    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i114 = 0; c3_i114 < 3; c3_i114 = c3_i114 + 1) {
      c3_dv7[c3_i114] = c3_dv5[c3_i114];
    }

    for (c3_i115 = 0; c3_i115 < 3; c3_i115 = c3_i115 + 1) {
      c3_g_b[c3_i115] = c3_f_b[c3_i115];
    }

    c3_a23 = c3_eml_xdotu(chartInstance, c3_dv7, c3_g_b);
    _SFD_EML_CALL(0,19);
    for (c3_i116 = 0; c3_i116 < 9; c3_i116 = c3_i116 + 1) {
      c3_e_a[c3_i116] = c3_rwave[c3_i116];
    }

    for (c3_i117 = 0; c3_i117 < 3; c3_i117 = c3_i117 + 1) {
      c3_h_b[c3_i117] = c3_p_in_m[c3_i117 + 6];
    }

    c3_c_eml_scalar_eg(chartInstance);
    c3_c_eml_scalar_eg(chartInstance);
    for (c3_i118 = 0; c3_i118 < 9; c3_i118 = c3_i118 + 1) {
      c3_j_A[c3_i118] = c3_e_a[c3_i118];
    }

    for (c3_i119 = 0; c3_i119 < 3; c3_i119 = c3_i119 + 1) {
      c3_j_B[c3_i119] = c3_h_b[c3_i119];
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
      c3_p_y[c3_i124] = 0.0;
      c3_i125 = 0;
      for (c3_i126 = 0; c3_i126 < 3; c3_i126 = c3_i126 + 1) {
        c3_p_y[c3_i124] = c3_p_y[c3_i124] + c3_l_A[c3_i125 + c3_i124] *
          c3_l_B[c3_i126];
        c3_i125 = c3_i125 + 3;
      }
    }

    for (c3_i127 = 0; c3_i127 < 3; c3_i127 = c3_i127 + 1) {
      c3_q_y[c3_i127] = c3_p_y[c3_i127];
    }

    for (c3_i128 = 0; c3_i128 < 3; c3_i128 = c3_i128 + 1) {
      c3_b_n3hat[c3_i128] = c3_n3hat[c3_i128];
    }

    c3_cross(chartInstance, c3_q_y, c3_b_n3hat, c3_i_b);
    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i129 = 0; c3_i129 < 3; c3_i129 = c3_i129 + 1) {
      c3_dv8[c3_i129] = c3_dv5[c3_i129];
    }

    for (c3_i130 = 0; c3_i130 < 3; c3_i130 = c3_i130 + 1) {
      c3_j_b[c3_i130] = c3_i_b[c3_i130];
    }

    c3_a33 = c3_eml_xdotu(chartInstance, c3_dv8, c3_j_b);
    _SFD_EML_CALL(0,21);
    c3_idk_jac[0] = c3_n1hat[0];
    c3_idk_jac[3] = c3_n1hat[1];
    c3_idk_jac[6] = c3_a13;
    c3_idk_jac[1] = c3_n2hat[0];
    c3_idk_jac[4] = c3_n2hat[1];
    c3_idk_jac[7] = c3_a23;
    c3_idk_jac[2] = c3_n3hat[0];
    c3_idk_jac[5] = c3_n3hat[1];
    c3_idk_jac[8] = c3_a33;

    /*     %% instantaneous inverse kinematics jacobian */
    /*  micro actuator (TWA) lengths */
    _SFD_EML_CALL(0,27);
    for (c3_i131 = 0; c3_i131 < 3; c3_i131 = c3_i131 + 1) {
      c3_e_b_in_w[c3_i131] = c3_b_in_w[c3_i131] - c3_m_in_w[c3_i131];
    }

    c3_q1_mu = c3_norm(chartInstance, c3_e_b_in_w);
    _SFD_EML_CALL(0,28);
    for (c3_i132 = 0; c3_i132 < 3; c3_i132 = c3_i132 + 1) {
      c3_f_b_in_w[c3_i132] = c3_b_in_w[c3_i132 + 3] - c3_m_in_w[c3_i132 + 3];
    }

    c3_q2_mu = c3_norm(chartInstance, c3_f_b_in_w);
    _SFD_EML_CALL(0,29);
    for (c3_i133 = 0; c3_i133 < 3; c3_i133 = c3_i133 + 1) {
      c3_g_b_in_w[c3_i133] = c3_b_in_w[c3_i133 + 6] - c3_m_in_w[c3_i133 + 6];
    }

    c3_q3_mu = c3_norm(chartInstance, c3_g_b_in_w);

    /*  vector from base vertex to twa motor attachment point */
    _SFD_EML_CALL(0,32);
    for (c3_i134 = 0; c3_i134 < 3; c3_i134 = c3_i134 + 1) {
      c3_j_x[c3_i134] = c3_m_in_w[c3_i134] - c3_b_in_w[c3_i134];
    }

    for (c3_i135 = 0; c3_i135 < 3; c3_i135 = c3_i135 + 1) {
      c3_b_m_in_w[c3_i135] = c3_m_in_w[c3_i135] - c3_b_in_w[c3_i135];
    }

    c3_r_y = c3_norm(chartInstance, c3_b_m_in_w);
    for (c3_i136 = 0; c3_i136 < 3; c3_i136 = c3_i136 + 1) {
      c3_k_x[c3_i136] = c3_j_x[c3_i136];
    }

    c3_s_y = c3_r_y;
    for (c3_i137 = 0; c3_i137 < 3; c3_i137 = c3_i137 + 1) {
      c3_l_x[c3_i137] = c3_k_x[c3_i137];
    }

    c3_t_y = c3_s_y;
    for (c3_i138 = 0; c3_i138 < 3; c3_i138 = c3_i138 + 1) {
      c3_l1_hat[c3_i138] = c3_l_x[c3_i138] / c3_t_y;
    }

    _SFD_EML_CALL(0,33);
    for (c3_i139 = 0; c3_i139 < 3; c3_i139 = c3_i139 + 1) {
      c3_m_x[c3_i139] = c3_m_in_w[c3_i139 + 3] - c3_b_in_w[c3_i139 + 3];
    }

    for (c3_i140 = 0; c3_i140 < 3; c3_i140 = c3_i140 + 1) {
      c3_c_m_in_w[c3_i140] = c3_m_in_w[c3_i140 + 3] - c3_b_in_w[c3_i140 + 3];
    }

    c3_u_y = c3_norm(chartInstance, c3_c_m_in_w);
    for (c3_i141 = 0; c3_i141 < 3; c3_i141 = c3_i141 + 1) {
      c3_n_x[c3_i141] = c3_m_x[c3_i141];
    }

    c3_v_y = c3_u_y;
    for (c3_i142 = 0; c3_i142 < 3; c3_i142 = c3_i142 + 1) {
      c3_o_x[c3_i142] = c3_n_x[c3_i142];
    }

    c3_w_y = c3_v_y;
    for (c3_i143 = 0; c3_i143 < 3; c3_i143 = c3_i143 + 1) {
      c3_l2_hat[c3_i143] = c3_o_x[c3_i143] / c3_w_y;
    }

    _SFD_EML_CALL(0,34);
    for (c3_i144 = 0; c3_i144 < 3; c3_i144 = c3_i144 + 1) {
      c3_p_x[c3_i144] = c3_m_in_w[c3_i144 + 6] - c3_b_in_w[c3_i144 + 6];
    }

    for (c3_i145 = 0; c3_i145 < 3; c3_i145 = c3_i145 + 1) {
      c3_d_m_in_w[c3_i145] = c3_m_in_w[c3_i145 + 6] - c3_b_in_w[c3_i145 + 6];
    }

    c3_x_y = c3_norm(chartInstance, c3_d_m_in_w);
    for (c3_i146 = 0; c3_i146 < 3; c3_i146 = c3_i146 + 1) {
      c3_q_x[c3_i146] = c3_p_x[c3_i146];
    }

    c3_y_y = c3_x_y;
    for (c3_i147 = 0; c3_i147 < 3; c3_i147 = c3_i147 + 1) {
      c3_r_x[c3_i147] = c3_q_x[c3_i147];
    }

    c3_ab_y = c3_y_y;
    for (c3_i148 = 0; c3_i148 < 3; c3_i148 = c3_i148 + 1) {
      c3_l3_hat[c3_i148] = c3_r_x[c3_i148] / c3_ab_y;
    }

    /*  distance from micro actuator attachmnet point (m_i) to flexure rotation */
    /* center (f_i) */
    _SFD_EML_CALL(0,38);
    for (c3_i149 = 0; c3_i149 < 3; c3_i149 = c3_i149 + 1) {
      c3_e_m_in_w[c3_i149] = c3_m_in_w[c3_i149] - c3_f_in_w[c3_i149];
    }

    c3_a1 = c3_norm(chartInstance, c3_e_m_in_w);
    _SFD_EML_CALL(0,39);
    for (c3_i150 = 0; c3_i150 < 3; c3_i150 = c3_i150 + 1) {
      c3_f_m_in_w[c3_i150] = c3_m_in_w[c3_i150 + 3] - c3_f_in_w[c3_i150 + 3];
    }

    c3_a2 = c3_norm(chartInstance, c3_f_m_in_w);
    _SFD_EML_CALL(0,40);
    for (c3_i151 = 0; c3_i151 < 3; c3_i151 = c3_i151 + 1) {
      c3_g_m_in_w[c3_i151] = c3_m_in_w[c3_i151 + 6] - c3_f_in_w[c3_i151 + 6];
    }

    c3_a3 = c3_norm(chartInstance, c3_g_m_in_w);

    /*  distance from flexure rotation center (f_i) to base vertex */
    _SFD_EML_CALL(0,43);
    for (c3_i152 = 0; c3_i152 < 3; c3_i152 = c3_i152 + 1) {
      c3_h_b_in_w[c3_i152] = c3_b_in_w[c3_i152] - c3_f_in_w[c3_i152];
    }

    c3_c1 = c3_norm(chartInstance, c3_h_b_in_w);
    _SFD_EML_CALL(0,44);
    for (c3_i153 = 0; c3_i153 < 3; c3_i153 = c3_i153 + 1) {
      c3_i_b_in_w[c3_i153] = c3_b_in_w[c3_i153 + 3] - c3_f_in_w[c3_i153 + 3];
    }

    c3_c2 = c3_norm(chartInstance, c3_i_b_in_w);
    _SFD_EML_CALL(0,45);
    for (c3_i154 = 0; c3_i154 < 3; c3_i154 = c3_i154 + 1) {
      c3_j_b_in_w[c3_i154] = c3_b_in_w[c3_i154 + 6] - c3_f_in_w[c3_i154 + 6];
    }

    c3_c3 = c3_norm(chartInstance, c3_j_b_in_w);

    /*  term to paramterize angle between a_i and qimu, delta */
    _SFD_EML_CALL(0,48);
    c3_k_b = c3_a1;
    c3_bb_y = -2.0 * c3_k_b;
    c3_f_a = c3_bb_y;
    c3_l_b = c3_q1_mu;
    c3_cb_y = c3_f_a * c3_l_b;
    c3_m_A = (c3_mpower(chartInstance, c3_c1) - c3_mpower(chartInstance, c3_a1))
      - c3_mpower(chartInstance, c3_q1_mu);
    c3_m_B = c3_cb_y;
    c3_s_x = c3_m_A;
    c3_db_y = c3_m_B;
    c3_t_x = c3_s_x;
    c3_eb_y = c3_db_y;
    c3_u_x = c3_t_x;
    c3_fb_y = c3_eb_y;
    c3_h1 = c3_u_x / c3_fb_y;
    _SFD_EML_CALL(0,49);
    c3_m_b = c3_a2;
    c3_gb_y = -2.0 * c3_m_b;
    c3_g_a = c3_gb_y;
    c3_n_b = c3_q2_mu;
    c3_hb_y = c3_g_a * c3_n_b;
    c3_n_A = (c3_mpower(chartInstance, c3_c2) - c3_mpower(chartInstance, c3_a2))
      - c3_mpower(chartInstance, c3_q2_mu);
    c3_n_B = c3_hb_y;
    c3_v_x = c3_n_A;
    c3_ib_y = c3_n_B;
    c3_w_x = c3_v_x;
    c3_jb_y = c3_ib_y;
    c3_x_x = c3_w_x;
    c3_kb_y = c3_jb_y;
    c3_h2 = c3_x_x / c3_kb_y;
    _SFD_EML_CALL(0,50);
    c3_o_b = c3_a3;
    c3_lb_y = -2.0 * c3_o_b;
    c3_h_a = c3_lb_y;
    c3_p_b = c3_q3_mu;
    c3_mb_y = c3_h_a * c3_p_b;
    c3_o_A = (c3_mpower(chartInstance, c3_c3) - c3_mpower(chartInstance, c3_a3))
      - c3_mpower(chartInstance, c3_q3_mu);
    c3_o_B = c3_mb_y;
    c3_y_x = c3_o_A;
    c3_nb_y = c3_o_B;
    c3_ab_x = c3_y_x;
    c3_ob_y = c3_nb_y;
    c3_bb_x = c3_ab_x;
    c3_pb_y = c3_ob_y;
    c3_h3 = c3_bb_x / c3_pb_y;

    /*  time derivatives */
    _SFD_EML_CALL(0,53);
    c3_q_b = c3_a1;
    c3_qb_y = 4.0 * c3_q_b;
    c3_i_a = c3_qb_y;
    c3_r_b = c3_mpower(chartInstance, c3_q1_mu);
    c3_rb_y = c3_i_a * c3_r_b;
    c3_j_a = (c3_mpower(chartInstance, c3_c1) - c3_mpower(chartInstance, c3_a1))
      - c3_mpower(chartInstance, c3_q1_mu);
    c3_sb_y = c3_j_a * 2.0;
    c3_k_a = c3_sb_y;
    c3_s_b = c3_a1;
    c3_tb_y = c3_k_a * c3_s_b;
    c3_t_b = c3_mpower(chartInstance, c3_a1);
    c3_ub_y = 4.0 * c3_t_b;
    c3_l_a = c3_ub_y;
    c3_u_b = c3_mpower(chartInstance, c3_q1_mu);
    c3_vb_y = c3_l_a * c3_u_b;
    c3_p_A = c3_rb_y + c3_tb_y;
    c3_p_B = c3_vb_y;
    c3_cb_x = c3_p_A;
    c3_wb_y = c3_p_B;
    c3_db_x = c3_cb_x;
    c3_xb_y = c3_wb_y;
    c3_eb_x = c3_db_x;
    c3_yb_y = c3_xb_y;
    c3_h1dot = c3_eb_x / c3_yb_y;
    _SFD_EML_CALL(0,54);
    c3_v_b = c3_a2;
    c3_ac_y = 4.0 * c3_v_b;
    c3_m_a = c3_ac_y;
    c3_w_b = c3_mpower(chartInstance, c3_q2_mu);
    c3_bc_y = c3_m_a * c3_w_b;
    c3_n_a = (c3_mpower(chartInstance, c3_c2) - c3_mpower(chartInstance, c3_a2))
      - c3_mpower(chartInstance, c3_q2_mu);
    c3_cc_y = c3_n_a * 2.0;
    c3_o_a = c3_cc_y;
    c3_x_b = c3_a2;
    c3_dc_y = c3_o_a * c3_x_b;
    c3_y_b = c3_mpower(chartInstance, c3_a2);
    c3_ec_y = 4.0 * c3_y_b;
    c3_p_a = c3_ec_y;
    c3_ab_b = c3_mpower(chartInstance, c3_q2_mu);
    c3_fc_y = c3_p_a * c3_ab_b;
    c3_q_A = c3_bc_y + c3_dc_y;
    c3_q_B = c3_fc_y;
    c3_fb_x = c3_q_A;
    c3_gc_y = c3_q_B;
    c3_gb_x = c3_fb_x;
    c3_hc_y = c3_gc_y;
    c3_hb_x = c3_gb_x;
    c3_ic_y = c3_hc_y;
    c3_h2dot = c3_hb_x / c3_ic_y;
    _SFD_EML_CALL(0,55);
    c3_bb_b = c3_a3;
    c3_jc_y = 4.0 * c3_bb_b;
    c3_q_a = c3_jc_y;
    c3_cb_b = c3_mpower(chartInstance, c3_q3_mu);
    c3_kc_y = c3_q_a * c3_cb_b;
    c3_r_a = (c3_mpower(chartInstance, c3_c3) - c3_mpower(chartInstance, c3_a3))
      - c3_mpower(chartInstance, c3_q3_mu);
    c3_lc_y = c3_r_a * 2.0;
    c3_s_a = c3_lc_y;
    c3_db_b = c3_a3;
    c3_mc_y = c3_s_a * c3_db_b;
    c3_eb_b = c3_mpower(chartInstance, c3_a3);
    c3_nc_y = 4.0 * c3_eb_b;
    c3_t_a = c3_nc_y;
    c3_fb_b = c3_mpower(chartInstance, c3_q3_mu);
    c3_oc_y = c3_t_a * c3_fb_b;
    c3_r_A = c3_kc_y + c3_mc_y;
    c3_r_B = c3_oc_y;
    c3_ib_x = c3_r_A;
    c3_pc_y = c3_r_B;
    c3_jb_x = c3_ib_x;
    c3_qc_y = c3_pc_y;
    c3_kb_x = c3_jb_x;
    c3_rc_y = c3_qc_y;
    c3_h3dot = c3_kb_x / c3_rc_y;
    _SFD_EML_CALL(0,57);
    for (c3_i155 = 0; c3_i155 < 3; c3_i155 = c3_i155 + 1) {
      c3_u_a[c3_i155] = c3_n1hat[c3_i155];
    }

    for (c3_i156 = 0; c3_i156 < 3; c3_i156 = c3_i156 + 1) {
      c3_gb_b[c3_i156] = c3_l1_hat[c3_i156];
    }

    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i157 = 0; c3_i157 < 3; c3_i157 = c3_i157 + 1) {
      c3_v_a[c3_i157] = c3_u_a[c3_i157];
    }

    for (c3_i158 = 0; c3_i158 < 3; c3_i158 = c3_i158 + 1) {
      c3_hb_b[c3_i158] = c3_gb_b[c3_i158];
    }

    c3_sc_y = c3_eml_xdotu(chartInstance, c3_v_a, c3_hb_b);
    c3_w_a = c3_q1_mu;
    c3_ib_b = c3_h1dot;
    c3_tc_y = c3_w_a * c3_ib_b;
    c3_s_A = c3_tc_y;
    c3_s_B = c3_sqrt(chartInstance, 1.0 - c3_mpower(chartInstance, c3_h1));
    c3_lb_x = c3_s_A;
    c3_uc_y = c3_s_B;
    c3_mb_x = c3_lb_x;
    c3_vc_y = c3_uc_y;
    c3_nb_x = c3_mb_x;
    c3_wc_y = c3_vc_y;
    c3_xc_y = c3_nb_x / c3_wc_y;
    c3_x_a = c3_xc_y;
    for (c3_i159 = 0; c3_i159 < 3; c3_i159 = c3_i159 + 1) {
      c3_jb_b[c3_i159] = c3_n1hat[c3_i159];
    }

    for (c3_i160 = 0; c3_i160 < 3; c3_i160 = c3_i160 + 1) {
      c3_yc_y[c3_i160] = c3_x_a * c3_jb_b[c3_i160];
    }

    for (c3_i161 = 0; c3_i161 < 3; c3_i161 = c3_i161 + 1) {
      c3_y_a[c3_i161] = c3_yc_y[c3_i161];
    }

    for (c3_i162 = 0; c3_i162 < 3; c3_i162 = c3_i162 + 1) {
      c3_dv9[c3_i162] = c3_dv5[c3_i162];
    }

    for (c3_i163 = 0; c3_i163 < 3; c3_i163 = c3_i163 + 1) {
      c3_b_l1_hat[c3_i163] = c3_l1_hat[c3_i163];
    }

    c3_cross(chartInstance, c3_dv9, c3_b_l1_hat, c3_kb_b);
    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i164 = 0; c3_i164 < 3; c3_i164 = c3_i164 + 1) {
      c3_ab_a[c3_i164] = c3_y_a[c3_i164];
    }

    for (c3_i165 = 0; c3_i165 < 3; c3_i165 = c3_i165 + 1) {
      c3_lb_b[c3_i165] = c3_kb_b[c3_i165];
    }

    c3_ad_y = c3_eml_xdotu(chartInstance, c3_ab_a, c3_lb_b);
    c3_e1 = c3_sc_y + c3_ad_y;
    _SFD_EML_CALL(0,58);
    for (c3_i166 = 0; c3_i166 < 3; c3_i166 = c3_i166 + 1) {
      c3_bb_a[c3_i166] = c3_n2hat[c3_i166];
    }

    for (c3_i167 = 0; c3_i167 < 3; c3_i167 = c3_i167 + 1) {
      c3_mb_b[c3_i167] = c3_l2_hat[c3_i167];
    }

    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i168 = 0; c3_i168 < 3; c3_i168 = c3_i168 + 1) {
      c3_cb_a[c3_i168] = c3_bb_a[c3_i168];
    }

    for (c3_i169 = 0; c3_i169 < 3; c3_i169 = c3_i169 + 1) {
      c3_nb_b[c3_i169] = c3_mb_b[c3_i169];
    }

    c3_bd_y = c3_eml_xdotu(chartInstance, c3_cb_a, c3_nb_b);
    c3_db_a = c3_q2_mu;
    c3_ob_b = c3_h2dot;
    c3_cd_y = c3_db_a * c3_ob_b;
    c3_t_A = c3_cd_y;
    c3_t_B = c3_sqrt(chartInstance, 1.0 - c3_mpower(chartInstance, c3_h2));
    c3_ob_x = c3_t_A;
    c3_dd_y = c3_t_B;
    c3_pb_x = c3_ob_x;
    c3_ed_y = c3_dd_y;
    c3_qb_x = c3_pb_x;
    c3_fd_y = c3_ed_y;
    c3_gd_y = c3_qb_x / c3_fd_y;
    c3_eb_a = c3_gd_y;
    for (c3_i170 = 0; c3_i170 < 3; c3_i170 = c3_i170 + 1) {
      c3_pb_b[c3_i170] = c3_n2hat[c3_i170];
    }

    for (c3_i171 = 0; c3_i171 < 3; c3_i171 = c3_i171 + 1) {
      c3_hd_y[c3_i171] = c3_eb_a * c3_pb_b[c3_i171];
    }

    for (c3_i172 = 0; c3_i172 < 3; c3_i172 = c3_i172 + 1) {
      c3_fb_a[c3_i172] = c3_hd_y[c3_i172];
    }

    for (c3_i173 = 0; c3_i173 < 3; c3_i173 = c3_i173 + 1) {
      c3_dv10[c3_i173] = c3_dv5[c3_i173];
    }

    for (c3_i174 = 0; c3_i174 < 3; c3_i174 = c3_i174 + 1) {
      c3_b_l2_hat[c3_i174] = c3_l2_hat[c3_i174];
    }

    c3_cross(chartInstance, c3_dv10, c3_b_l2_hat, c3_qb_b);
    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i175 = 0; c3_i175 < 3; c3_i175 = c3_i175 + 1) {
      c3_gb_a[c3_i175] = c3_fb_a[c3_i175];
    }

    for (c3_i176 = 0; c3_i176 < 3; c3_i176 = c3_i176 + 1) {
      c3_rb_b[c3_i176] = c3_qb_b[c3_i176];
    }

    c3_id_y = c3_eml_xdotu(chartInstance, c3_gb_a, c3_rb_b);
    c3_e2 = c3_bd_y + c3_id_y;
    _SFD_EML_CALL(0,59);
    for (c3_i177 = 0; c3_i177 < 3; c3_i177 = c3_i177 + 1) {
      c3_hb_a[c3_i177] = c3_n3hat[c3_i177];
    }

    for (c3_i178 = 0; c3_i178 < 3; c3_i178 = c3_i178 + 1) {
      c3_sb_b[c3_i178] = c3_l3_hat[c3_i178];
    }

    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i179 = 0; c3_i179 < 3; c3_i179 = c3_i179 + 1) {
      c3_ib_a[c3_i179] = c3_hb_a[c3_i179];
    }

    for (c3_i180 = 0; c3_i180 < 3; c3_i180 = c3_i180 + 1) {
      c3_tb_b[c3_i180] = c3_sb_b[c3_i180];
    }

    c3_jd_y = c3_eml_xdotu(chartInstance, c3_ib_a, c3_tb_b);
    c3_jb_a = c3_q3_mu;
    c3_ub_b = c3_h3dot;
    c3_kd_y = c3_jb_a * c3_ub_b;
    c3_u_A = c3_kd_y;
    c3_u_B = c3_sqrt(chartInstance, 1.0 - c3_mpower(chartInstance, c3_h3));
    c3_rb_x = c3_u_A;
    c3_ld_y = c3_u_B;
    c3_sb_x = c3_rb_x;
    c3_md_y = c3_ld_y;
    c3_tb_x = c3_sb_x;
    c3_nd_y = c3_md_y;
    c3_od_y = c3_tb_x / c3_nd_y;
    c3_kb_a = c3_od_y;
    for (c3_i181 = 0; c3_i181 < 3; c3_i181 = c3_i181 + 1) {
      c3_vb_b[c3_i181] = c3_n3hat[c3_i181];
    }

    for (c3_i182 = 0; c3_i182 < 3; c3_i182 = c3_i182 + 1) {
      c3_pd_y[c3_i182] = c3_kb_a * c3_vb_b[c3_i182];
    }

    for (c3_i183 = 0; c3_i183 < 3; c3_i183 = c3_i183 + 1) {
      c3_lb_a[c3_i183] = c3_pd_y[c3_i183];
    }

    for (c3_i184 = 0; c3_i184 < 3; c3_i184 = c3_i184 + 1) {
      c3_dv11[c3_i184] = c3_dv5[c3_i184];
    }

    for (c3_i185 = 0; c3_i185 < 3; c3_i185 = c3_i185 + 1) {
      c3_b_l3_hat[c3_i185] = c3_l3_hat[c3_i185];
    }

    c3_cross(chartInstance, c3_dv11, c3_b_l3_hat, c3_wb_b);
    c3_d_eml_scalar_eg(chartInstance);
    for (c3_i186 = 0; c3_i186 < 3; c3_i186 = c3_i186 + 1) {
      c3_mb_a[c3_i186] = c3_lb_a[c3_i186];
    }

    for (c3_i187 = 0; c3_i187 < 3; c3_i187 = c3_i187 + 1) {
      c3_xb_b[c3_i187] = c3_wb_b[c3_i187];
    }

    c3_qd_y = c3_eml_xdotu(chartInstance, c3_mb_a, c3_xb_b);
    c3_e3 = c3_jd_y + c3_qd_y;

    /*  micro motion instantaneous inverse kinematics jacobian */
    _SFD_EML_CALL(0,62);
    c3_b_mu[0] = c3_e1;
    c3_b_mu[3] = 0.0;
    c3_b_mu[6] = 0.0;
    c3_b_mu[1] = 0.0;
    c3_b_mu[4] = c3_e2;
    c3_b_mu[7] = 0.0;
    c3_b_mu[2] = 0.0;
    c3_b_mu[5] = 0.0;
    c3_b_mu[8] = c3_e3;

    /*  macro motion instantaneous inverse kinematics jacobian */
    _SFD_EML_CALL(0,67);
    for (c3_i188 = 0; c3_i188 < 9; c3_i188 = c3_i188 + 1) {
      c3_b_m[c3_i188] = c3_dv12[c3_i188];
    }

    /*  combined macro-micro motion IIK jacobian */
    _SFD_EML_CALL(0,70);
    c3_i189 = 0;
    for (c3_i190 = 0; c3_i190 < 3; c3_i190 = c3_i190 + 1) {
      for (c3_i191 = 0; c3_i191 < 3; c3_i191 = c3_i191 + 1) {
        c3_iik_jac[c3_i191 + c3_i189] = c3_b_m[c3_i191 + c3_i189];
      }

      c3_i189 = c3_i189 + 3;
    }

    c3_i192 = 0;
    for (c3_i193 = 0; c3_i193 < 3; c3_i193 = c3_i193 + 1) {
      for (c3_i194 = 0; c3_i194 < 3; c3_i194 = c3_i194 + 1) {
        c3_iik_jac[(c3_i194 + c3_i192) + 9] = c3_b_mu[c3_i194 + c3_i192];
      }

      c3_i192 = c3_i192 + 3;
    }

    /*  the full manipulator jacobian with redundancy resolution weighting */
    _SFD_EML_CALL(0,73);
    for (c3_i195 = 0; c3_i195 < 36; c3_i195 = c3_i195 + 1) {
      c3_w_mat[c3_i195] = c3_dv13[c3_i195];
    }

    _SFD_EML_CALL(0,74);
    for (c3_i196 = 0; c3_i196 < 18; c3_i196 = c3_i196 + 1) {
      c3_v_A[c3_i196] = c3_iik_jac[c3_i196];
    }

    for (c3_i197 = 0; c3_i197 < 36; c3_i197 = c3_i197 + 1) {
      c3_dv14[c3_i197] = c3_dv13[c3_i197];
    }

    c3_i198 = 0;
    for (c3_i199 = 0; c3_i199 < 3; c3_i199 = c3_i199 + 1) {
      c3_i200 = 0;
      for (c3_i201 = 0; c3_i201 < 6; c3_i201 = c3_i201 + 1) {
        c3_w_A[c3_i201 + c3_i198] = c3_v_A[c3_i200 + c3_i199];
        c3_i200 = c3_i200 + 3;
      }

      c3_i198 = c3_i198 + 6;
    }

    c3_mldivide(chartInstance, c3_dv14, c3_w_A, c3_dv15);
    c3_i202 = 0;
    for (c3_i203 = 0; c3_i203 < 6; c3_i203 = c3_i203 + 1) {
      c3_i204 = 0;
      for (c3_i205 = 0; c3_i205 < 3; c3_i205 = c3_i205 + 1) {
        c3_rd_y[c3_i205 + c3_i202] = c3_dv15[c3_i204 + c3_i203];
        c3_i204 = c3_i204 + 6;
      }

      c3_i202 = c3_i202 + 3;
    }

    for (c3_i206 = 0; c3_i206 < 18; c3_i206 = c3_i206 + 1) {
      c3_nb_a[c3_i206] = c3_rd_y[c3_i206];
    }

    c3_i207 = 0;
    for (c3_i208 = 0; c3_i208 < 3; c3_i208 = c3_i208 + 1) {
      c3_i209 = 0;
      for (c3_i210 = 0; c3_i210 < 6; c3_i210 = c3_i210 + 1) {
        c3_yb_b[c3_i210 + c3_i207] = c3_iik_jac[c3_i209 + c3_i208];
        c3_i209 = c3_i209 + 3;
      }

      c3_i207 = c3_i207 + 6;
    }

    c3_e_eml_scalar_eg(chartInstance);
    c3_e_eml_scalar_eg(chartInstance);
    for (c3_i211 = 0; c3_i211 < 18; c3_i211 = c3_i211 + 1) {
      c3_x_A[c3_i211] = c3_nb_a[c3_i211];
    }

    for (c3_i212 = 0; c3_i212 < 18; c3_i212 = c3_i212 + 1) {
      c3_v_B[c3_i212] = c3_yb_b[c3_i212];
    }

    for (c3_i213 = 0; c3_i213 < 18; c3_i213 = c3_i213 + 1) {
      c3_y_A[c3_i213] = c3_x_A[c3_i213];
    }

    for (c3_i214 = 0; c3_i214 < 18; c3_i214 = c3_i214 + 1) {
      c3_w_B[c3_i214] = c3_v_B[c3_i214];
    }

    for (c3_i215 = 0; c3_i215 < 18; c3_i215 = c3_i215 + 1) {
      c3_ab_A[c3_i215] = c3_y_A[c3_i215];
    }

    for (c3_i216 = 0; c3_i216 < 18; c3_i216 = c3_i216 + 1) {
      c3_x_B[c3_i216] = c3_w_B[c3_i216];
    }

    for (c3_i217 = 0; c3_i217 < 3; c3_i217 = c3_i217 + 1) {
      c3_i218 = 0;
      c3_i219 = 0;
      for (c3_i220 = 0; c3_i220 < 3; c3_i220 = c3_i220 + 1) {
        c3_sd_y[c3_i218 + c3_i217] = 0.0;
        c3_i221 = 0;
        for (c3_i222 = 0; c3_i222 < 6; c3_i222 = c3_i222 + 1) {
          c3_sd_y[c3_i218 + c3_i217] = c3_sd_y[c3_i218 + c3_i217] +
            c3_ab_A[c3_i221 + c3_i217] * c3_x_B[c3_i222 + c3_i219];
          c3_i221 = c3_i221 + 3;
        }

        c3_i218 = c3_i218 + 3;
        c3_i219 = c3_i219 + 6;
      }
    }

    for (c3_i223 = 0; c3_i223 < 36; c3_i223 = c3_i223 + 1) {
      c3_dv16[c3_i223] = c3_dv13[c3_i223];
    }

    c3_i224 = 0;
    for (c3_i225 = 0; c3_i225 < 3; c3_i225 = c3_i225 + 1) {
      c3_i226 = 0;
      for (c3_i227 = 0; c3_i227 < 6; c3_i227 = c3_i227 + 1) {
        c3_b_iik_jac[c3_i227 + c3_i224] = c3_iik_jac[c3_i226 + c3_i225];
        c3_i226 = c3_i226 + 3;
      }

      c3_i224 = c3_i224 + 6;
    }

    c3_mldivide(chartInstance, c3_dv16, c3_b_iik_jac, c3_dv17);
    for (c3_i228 = 0; c3_i228 < 18; c3_i228 = c3_i228 + 1) {
      c3_dv18[c3_i228] = c3_dv17[c3_i228];
    }

    for (c3_i229 = 0; c3_i229 < 9; c3_i229 = c3_i229 + 1) {
      c3_td_y[c3_i229] = c3_sd_y[c3_i229];
    }

    c3_mrdivide(chartInstance, c3_dv18, c3_td_y, c3_ob_a);
    for (c3_i230 = 0; c3_i230 < 9; c3_i230 = c3_i230 + 1) {
      c3_ac_b[c3_i230] = c3_idk_jac[c3_i230];
    }

    c3_f_eml_scalar_eg(chartInstance);
    c3_f_eml_scalar_eg(chartInstance);
    for (c3_i231 = 0; c3_i231 < 18; c3_i231 = c3_i231 + 1) {
      c3_bb_A[c3_i231] = c3_ob_a[c3_i231];
    }

    for (c3_i232 = 0; c3_i232 < 9; c3_i232 = c3_i232 + 1) {
      c3_y_B[c3_i232] = c3_ac_b[c3_i232];
    }

    for (c3_i233 = 0; c3_i233 < 18; c3_i233 = c3_i233 + 1) {
      c3_full_jac[c3_i233] = 0.0;
    }

    for (c3_i234 = 0; c3_i234 < 18; c3_i234 = c3_i234 + 1) {
      c3_cb_A[c3_i234] = c3_bb_A[c3_i234];
    }

    for (c3_i235 = 0; c3_i235 < 9; c3_i235 = c3_i235 + 1) {
      c3_ab_B[c3_i235] = c3_y_B[c3_i235];
    }

    for (c3_i236 = 0; c3_i236 < 18; c3_i236 = c3_i236 + 1) {
      c3_db_A[c3_i236] = c3_cb_A[c3_i236];
    }

    for (c3_i237 = 0; c3_i237 < 9; c3_i237 = c3_i237 + 1) {
      c3_bb_B[c3_i237] = c3_ab_B[c3_i237];
    }

    for (c3_i238 = 0; c3_i238 < 6; c3_i238 = c3_i238 + 1) {
      c3_i239 = 0;
      c3_i240 = 0;
      for (c3_i241 = 0; c3_i241 < 3; c3_i241 = c3_i241 + 1) {
        c3_full_jac[c3_i239 + c3_i238] = 0.0;
        c3_i242 = 0;
        for (c3_i243 = 0; c3_i243 < 3; c3_i243 = c3_i243 + 1) {
          c3_full_jac[c3_i239 + c3_i238] = c3_full_jac[c3_i239 + c3_i238] +
            c3_db_A[c3_i242 + c3_i238] * c3_bb_B[c3_i243 + c3_i240];
          c3_i242 = c3_i242 + 6;
        }

        c3_i239 = c3_i239 + 6;
        c3_i240 = c3_i240 + 3;
      }
    }

    /*     %% */
    /*  joint velocities and ee velocity proportional to joint error */
    _SFD_EML_CALL(0,78);
    c3_pb_a = c3_kp;
    for (c3_i244 = 0; c3_i244 < 3; c3_i244 = c3_i244 + 1) {
      c3_bc_b[c3_i244] = c3_eq[c3_i244];
    }

    for (c3_i245 = 0; c3_i245 < 3; c3_i245 = c3_i245 + 1) {
      c3_qdot[c3_i245] = c3_pb_a * c3_bc_b[c3_i245];
    }

    _SFD_EML_CALL(0,79);
    for (c3_i246 = 0; c3_i246 < 18; c3_i246 = c3_i246 + 1) {
      c3_qb_a[c3_i246] = c3_full_jac[c3_i246];
    }

    for (c3_i247 = 0; c3_i247 < 3; c3_i247 = c3_i247 + 1) {
      c3_cc_b[c3_i247] = c3_qdot[c3_i247];
    }

    c3_g_eml_scalar_eg(chartInstance);
    c3_g_eml_scalar_eg(chartInstance);
    for (c3_i248 = 0; c3_i248 < 18; c3_i248 = c3_i248 + 1) {
      c3_eb_A[c3_i248] = c3_qb_a[c3_i248];
    }

    for (c3_i249 = 0; c3_i249 < 3; c3_i249 = c3_i249 + 1) {
      c3_cb_B[c3_i249] = c3_cc_b[c3_i249];
    }

    for (c3_i250 = 0; c3_i250 < 6; c3_i250 = c3_i250 + 1) {
      c3_tdot[c3_i250] = 0.0;
    }

    for (c3_i251 = 0; c3_i251 < 18; c3_i251 = c3_i251 + 1) {
      c3_fb_A[c3_i251] = c3_eb_A[c3_i251];
    }

    for (c3_i252 = 0; c3_i252 < 3; c3_i252 = c3_i252 + 1) {
      c3_db_B[c3_i252] = c3_cb_B[c3_i252];
    }

    for (c3_i253 = 0; c3_i253 < 18; c3_i253 = c3_i253 + 1) {
      c3_gb_A[c3_i253] = c3_fb_A[c3_i253];
    }

    for (c3_i254 = 0; c3_i254 < 3; c3_i254 = c3_i254 + 1) {
      c3_eb_B[c3_i254] = c3_db_B[c3_i254];
    }

    for (c3_i255 = 0; c3_i255 < 6; c3_i255 = c3_i255 + 1) {
      c3_tdot[c3_i255] = 0.0;
      c3_i256 = 0;
      for (c3_i257 = 0; c3_i257 < 3; c3_i257 = c3_i257 + 1) {
        c3_tdot[c3_i255] = c3_tdot[c3_i255] + c3_gb_A[c3_i256 + c3_i255] *
          c3_eb_B[c3_i257];
        c3_i256 = c3_i256 + 6;
      }
    }

    /*  separate translational and rotational components of twist */
    _SFD_EML_CALL(0,82);
    for (c3_i258 = 0; c3_i258 < 2; c3_i258 = c3_i258 + 1) {
      c3_v[c3_i258] = c3_tdot[c3_i258];
    }

    _SFD_EML_CALL(0,83);
    c3_w = c3_tdot[2];

    /*  new end effector position */
    _SFD_EML_CALL(0,86);
    for (c3_i259 = 0; c3_i259 < 2; c3_i259 = c3_i259 + 1) {
      c3_rb_a[c3_i259] = c3_v[c3_i259];
    }

    c3_dc_b = c3_dt;
    for (c3_i260 = 0; c3_i260 < 2; c3_i260 = c3_i260 + 1) {
      c3_ud_y[c3_i260] = c3_rb_a[c3_i260] * c3_dc_b;
    }

    for (c3_i261 = 0; c3_i261 < 2; c3_i261 = c3_i261 + 1) {
      c3_b_twave[c3_i261] = c3_twave[c3_i261] + c3_ud_y[c3_i261];
    }

    for (c3_i262 = 0; c3_i262 < 2; c3_i262 = c3_i262 + 1) {
      c3_twave[c3_i262] = c3_b_twave[c3_i262];
    }

    /*  change in end effector orientation */
    _SFD_EML_CALL(0,89);
    c3_sb_a = c3_w;
    c3_ec_b = c3_dt;
    c3_vd_y = c3_sb_a * c3_ec_b;
    c3_ub_x = c3_vd_y;
    c3_vb_x = c3_ub_x;
    c3_wb_x = c3_vb_x;
    c3_vb_x = c3_wb_x;
    c3_vb_x = muDoubleScalarCos(c3_vb_x);
    c3_tb_a = c3_w;
    c3_fc_b = c3_dt;
    c3_wd_y = c3_tb_a * c3_fc_b;
    c3_xb_x = c3_wd_y;
    c3_yb_x = c3_xb_x;
    c3_ac_x = c3_yb_x;
    c3_yb_x = c3_ac_x;
    c3_yb_x = muDoubleScalarSin(c3_yb_x);
    c3_ub_a = c3_w;
    c3_gc_b = c3_dt;
    c3_xd_y = c3_ub_a * c3_gc_b;
    c3_bc_x = c3_xd_y;
    c3_cc_x = c3_bc_x;
    c3_dc_x = c3_cc_x;
    c3_cc_x = c3_dc_x;
    c3_cc_x = muDoubleScalarSin(c3_cc_x);
    c3_vb_a = c3_w;
    c3_hc_b = c3_dt;
    c3_yd_y = c3_vb_a * c3_hc_b;
    c3_ec_x = c3_yd_y;
    c3_fc_x = c3_ec_x;
    c3_gc_x = c3_fc_x;
    c3_fc_x = c3_gc_x;
    c3_fc_x = muDoubleScalarCos(c3_fc_x);
    c3_del_r[0] = c3_vb_x;
    c3_del_r[3] = -c3_yb_x;
    c3_del_r[6] = 0.0;
    c3_del_r[1] = c3_cc_x;
    c3_del_r[4] = c3_fc_x;
    c3_del_r[7] = 0.0;
    c3_i263 = 0;
    for (c3_i264 = 0; c3_i264 < 3; c3_i264 = c3_i264 + 1) {
      c3_del_r[c3_i263 + 2] = c3_dv5[c3_i264];
      c3_i263 = c3_i263 + 3;
    }

    /*  new end effector orientation */
    _SFD_EML_CALL(0,92);
    for (c3_i265 = 0; c3_i265 < 9; c3_i265 = c3_i265 + 1) {
      c3_wb_a[c3_i265] = c3_del_r[c3_i265];
    }

    for (c3_i266 = 0; c3_i266 < 9; c3_i266 = c3_i266 + 1) {
      c3_ic_b[c3_i266] = c3_rwave[c3_i266];
    }

    c3_eml_scalar_eg(chartInstance);
    c3_eml_scalar_eg(chartInstance);
    for (c3_i267 = 0; c3_i267 < 9; c3_i267 = c3_i267 + 1) {
      c3_hb_A[c3_i267] = c3_wb_a[c3_i267];
    }

    for (c3_i268 = 0; c3_i268 < 9; c3_i268 = c3_i268 + 1) {
      c3_fb_B[c3_i268] = c3_ic_b[c3_i268];
    }

    for (c3_i269 = 0; c3_i269 < 9; c3_i269 = c3_i269 + 1) {
      c3_rwave[c3_i269] = 0.0;
    }

    for (c3_i270 = 0; c3_i270 < 9; c3_i270 = c3_i270 + 1) {
      c3_ib_A[c3_i270] = c3_hb_A[c3_i270];
    }

    for (c3_i271 = 0; c3_i271 < 9; c3_i271 = c3_i271 + 1) {
      c3_gb_B[c3_i271] = c3_fb_B[c3_i271];
    }

    for (c3_i272 = 0; c3_i272 < 9; c3_i272 = c3_i272 + 1) {
      c3_jb_A[c3_i272] = c3_ib_A[c3_i272];
    }

    for (c3_i273 = 0; c3_i273 < 9; c3_i273 = c3_i273 + 1) {
      c3_hb_B[c3_i273] = c3_gb_B[c3_i273];
    }

    for (c3_i274 = 0; c3_i274 < 3; c3_i274 = c3_i274 + 1) {
      c3_i275 = 0;
      for (c3_i276 = 0; c3_i276 < 3; c3_i276 = c3_i276 + 1) {
        c3_rwave[c3_i275 + c3_i274] = 0.0;
        c3_i277 = 0;
        for (c3_i278 = 0; c3_i278 < 3; c3_i278 = c3_i278 + 1) {
          c3_rwave[c3_i275 + c3_i274] = c3_rwave[c3_i275 + c3_i274] +
            c3_jb_A[c3_i277 + c3_i274] * c3_hb_B[c3_i278 + c3_i275];
          c3_i277 = c3_i277 + 3;
        }

        c3_i275 = c3_i275 + 3;
      }
    }

    _SFD_EML_CALL(0,94);
    for (c3_i279 = 0; c3_i279 < 3; c3_i279 = c3_i279 + 1) {
      c3_des_leg_len[c3_i279] = 0.0;
    }

    c3_i = 1.0;
    c3_b_i = 1.0;
    while (c3_b_i <= 3.0) {
      c3_i = c3_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0,96);
      for (c3_i280 = 0; c3_i280 < 9; c3_i280 = c3_i280 + 1) {
        c3_xb_a[c3_i280] = c3_rwave[c3_i280];
      }

      c3_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("p_in_m", (int32_T)_SFD_INTEGER_CHECK
        ("i", c3_i), 1, 3, 2, 0) - 1;
      for (c3_i281 = 0; c3_i281 < 3; c3_i281 = c3_i281 + 1) {
        c3_jc_b[c3_i281] = c3_p_in_m[c3_i281 + 3 * c3_c_i];
      }

      c3_c_eml_scalar_eg(chartInstance);
      c3_c_eml_scalar_eg(chartInstance);
      for (c3_i282 = 0; c3_i282 < 9; c3_i282 = c3_i282 + 1) {
        c3_kb_A[c3_i282] = c3_xb_a[c3_i282];
      }

      for (c3_i283 = 0; c3_i283 < 3; c3_i283 = c3_i283 + 1) {
        c3_ib_B[c3_i283] = c3_jc_b[c3_i283];
      }

      for (c3_i284 = 0; c3_i284 < 9; c3_i284 = c3_i284 + 1) {
        c3_lb_A[c3_i284] = c3_kb_A[c3_i284];
      }

      for (c3_i285 = 0; c3_i285 < 3; c3_i285 = c3_i285 + 1) {
        c3_jb_B[c3_i285] = c3_ib_B[c3_i285];
      }

      for (c3_i286 = 0; c3_i286 < 9; c3_i286 = c3_i286 + 1) {
        c3_mb_A[c3_i286] = c3_lb_A[c3_i286];
      }

      for (c3_i287 = 0; c3_i287 < 3; c3_i287 = c3_i287 + 1) {
        c3_kb_B[c3_i287] = c3_jb_B[c3_i287];
      }

      for (c3_i288 = 0; c3_i288 < 3; c3_i288 = c3_i288 + 1) {
        c3_ae_y[c3_i288] = 0.0;
        c3_i289 = 0;
        for (c3_i290 = 0; c3_i290 < 3; c3_i290 = c3_i290 + 1) {
          c3_ae_y[c3_i288] = c3_ae_y[c3_i288] + c3_mb_A[c3_i289 + c3_i288] *
            c3_kb_B[c3_i290];
          c3_i289 = c3_i289 + 3;
        }
      }

      c3_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("p_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c3_i), 1, 3, 2, 0) - 1;
      for (c3_i291 = 0; c3_i291 < 3; c3_i291 = c3_i291 + 1) {
        c3_p_in_w[c3_i291 + 3 * c3_d_i] = c3_twave[c3_i291] + c3_ae_y[c3_i291];
      }

      _SFD_EML_CALL(0,97);
      c3_e_i = _SFD_EML_ARRAY_BOUNDS_CHECK("p_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c3_i), 1, 3, 2, 0) - 1;
      c3_f_i = _SFD_EML_ARRAY_BOUNDS_CHECK("b_in_w", (int32_T)_SFD_INTEGER_CHECK
        ("i", c3_i), 1, 3, 2, 0) - 1;
      for (c3_i292 = 0; c3_i292 < 3; c3_i292 = c3_i292 + 1) {
        c3_b_p_in_w[c3_i292] = c3_p_in_w[c3_i292 + 3 * c3_e_i] -
          c3_b_in_w[c3_i292 + 3 * c3_f_i];
      }

      c3_des_leg_len[_SFD_EML_ARRAY_BOUNDS_CHECK("des_leg_len", (int32_T)
        _SFD_INTEGER_CHECK("i", c3_i), 1, 3, 1, 0) - 1] = c3_norm(
        chartInstance, c3_b_p_in_w);
      c3_b_i = c3_b_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_EML_FOR(0, 0, 0);
    _SFD_EML_CALL(0,100);
    for (c3_i293 = 0; c3_i293 < 3; c3_i293 = c3_i293 + 1) {
      c3_eq_out[c3_i293] = c3_macro_leg_len[c3_i293] - c3_des_leg_len[c3_i293];
    }

    /*  the amount each velmex slides need to move is the difference between */
    /*  the last leg length and the new leg length */
    /*      qcmd(1:3,1) = (measured_len - des_leg_len)/velmex_pitch */
    _SFD_EML_CALL(0,105);
    for (c3_i294 = 0; c3_i294 < 3; c3_i294 = c3_i294 + 1) {
      c3_nb_A[c3_i294] = c3_des_leg_len[c3_i294] - c3_measured_len[c3_i294];
    }

    c3_lb_B = c3_velmex_pitch;
    for (c3_i295 = 0; c3_i295 < 3; c3_i295 = c3_i295 + 1) {
      c3_hc_x[c3_i295] = c3_nb_A[c3_i295];
    }

    c3_be_y = c3_lb_B;
    for (c3_i296 = 0; c3_i296 < 3; c3_i296 = c3_i296 + 1) {
      c3_ic_x[c3_i296] = c3_hc_x[c3_i296];
    }

    c3_ce_y = c3_be_y;
    for (c3_i297 = 0; c3_i297 < 3; c3_i297 = c3_i297 + 1) {
      c3_jc_x[c3_i297] = c3_ic_x[c3_i297];
    }

    c3_de_y = c3_ce_y;
    for (c3_i298 = 0; c3_i298 < 3; c3_i298 = c3_i298 + 1) {
      c3_ee_y[c3_i298] = c3_jc_x[c3_i298] / c3_de_y;
    }

    for (c3_i299 = 0; c3_i299 < 3; c3_i299 = c3_i299 + 1) {
      c3_qcmd[c3_i299] = c3_ee_y[c3_i299];
    }

    _SFD_EML_CALL(0,107);
    for (c3_i300 = 0; c3_i300 < 3; c3_i300 = c3_i300 + 1) {
      c3_twave_out[c3_i300] = c3_twave[c3_i300];
    }

    _SFD_EML_CALL(0,108);
    for (c3_i301 = 0; c3_i301 < 9; c3_i301 = c3_i301 + 1) {
      c3_rwave_out[c3_i301] = c3_rwave[c3_i301];
    }
  } else {
    _SFD_EML_CALL(0,110);
    for (c3_i302 = 0; c3_i302 < 3; c3_i302 = c3_i302 + 1) {
      c3_des_leg_len[c3_i302] = c3_macro_leg_len[c3_i302];
    }

    _SFD_EML_CALL(0,111);
    for (c3_i303 = 0; c3_i303 < 3; c3_i303 = c3_i303 + 1) {
      c3_eq_out[c3_i303] = c3_eq[c3_i303];
    }

    _SFD_EML_CALL(0,112);
    for (c3_i304 = 0; c3_i304 < 3; c3_i304 = c3_i304 + 1) {
      c3_twave_out[c3_i304] = c3_twave[c3_i304];
    }

    _SFD_EML_CALL(0,113);
    for (c3_i305 = 0; c3_i305 < 9; c3_i305 = c3_i305 + 1) {
      c3_rwave_out[c3_i305] = c3_rwave[c3_i305];
    }
  }

  _SFD_EML_CALL(0,-113);
  sf_debug_symbol_scope_pop();
  for (c3_i306 = 0; c3_i306 < 6; c3_i306 = c3_i306 + 1) {
    (*c3_b_qcmd)[c3_i306] = c3_qcmd[c3_i306];
  }

  for (c3_i307 = 0; c3_i307 < 3; c3_i307 = c3_i307 + 1) {
    (*c3_b_des_leg_len)[c3_i307] = c3_des_leg_len[c3_i307];
  }

  for (c3_i308 = 0; c3_i308 < 3; c3_i308 = c3_i308 + 1) {
    (*c3_b_eq_out)[c3_i308] = c3_eq_out[c3_i308];
  }

  for (c3_i309 = 0; c3_i309 < 3; c3_i309 = c3_i309 + 1) {
    (*c3_b_twave_out)[c3_i309] = c3_twave_out[c3_i309];
  }

  for (c3_i310 = 0; c3_i310 < 9; c3_i310 = c3_i310 + 1) {
    (*c3_b_rwave_out)[c3_i310] = c3_rwave_out[c3_i310];
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

static void c3_b_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c3_norm(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                      c3_x[3])
{
  int32_T c3_i311;
  real_T c3_b_x[3];
  int32_T c3_i312;
  real_T c3_c_x[3];
  int32_T c3_i313;
  real_T c3_d_x[3];
  int32_T c3_i314;
  real_T c3_e_x[3];
  for (c3_i311 = 0; c3_i311 < 3; c3_i311 = c3_i311 + 1) {
    c3_b_x[c3_i311] = c3_x[c3_i311];
  }

  for (c3_i312 = 0; c3_i312 < 3; c3_i312 = c3_i312 + 1) {
    c3_c_x[c3_i312] = c3_b_x[c3_i312];
  }

  for (c3_i313 = 0; c3_i313 < 3; c3_i313 = c3_i313 + 1) {
    c3_d_x[c3_i313] = c3_c_x[c3_i313];
  }

  for (c3_i314 = 0; c3_i314 < 3; c3_i314 = c3_i314 + 1) {
    c3_e_x[c3_i314] = c3_d_x[c3_i314];
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

static void c3_c_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
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

static void c3_d_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static real_T c3_eml_xdotu(SFc3_twa_parallelInstanceStruct *chartInstance,
  real_T c3_x[3], real_T c3_y[3])
{
  int32_T c3_i315;
  real_T c3_b_x[3];
  int32_T c3_i316;
  real_T c3_b_y[3];
  int32_T c3_i317;
  real_T c3_c_x[3];
  int32_T c3_i318;
  real_T c3_c_y[3];
  int32_T c3_i319;
  real_T c3_d_x[3];
  int32_T c3_i320;
  real_T c3_d_y[3];
  for (c3_i315 = 0; c3_i315 < 3; c3_i315 = c3_i315 + 1) {
    c3_b_x[c3_i315] = c3_x[c3_i315];
  }

  for (c3_i316 = 0; c3_i316 < 3; c3_i316 = c3_i316 + 1) {
    c3_b_y[c3_i316] = c3_y[c3_i316];
  }

  for (c3_i317 = 0; c3_i317 < 3; c3_i317 = c3_i317 + 1) {
    c3_c_x[c3_i317] = c3_b_x[c3_i317];
  }

  for (c3_i318 = 0; c3_i318 < 3; c3_i318 = c3_i318 + 1) {
    c3_c_y[c3_i318] = c3_b_y[c3_i318];
  }

  for (c3_i319 = 0; c3_i319 < 3; c3_i319 = c3_i319 + 1) {
    c3_d_x[c3_i319] = c3_c_x[c3_i319];
  }

  for (c3_i320 = 0; c3_i320 < 3; c3_i320 = c3_i320 + 1) {
    c3_d_y[c3_i320] = c3_c_y[c3_i320];
  }

  return c3_ceval_xdot(chartInstance, 3, c3_d_x, 1, 1, c3_d_y, 1, 1);
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

static real_T c3_mpower(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_a)
{
  return c3_power(chartInstance, c3_a, 2.0);
}

static real_T c3_power(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_a, real_T c3_b)
{
  real_T c3_ak;
  real_T c3_bk;
  real_T c3_x;
  real_T c3_b_x;
  c3_b_eml_scalar_eg(chartInstance);
  c3_ak = c3_a;
  c3_bk = c3_b;
  if (c3_ak < 0.0) {
    c3_x = c3_bk;
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarFloor(c3_b_x);
    if (c3_b_x != c3_bk) {
      c3_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c3_ak, c3_bk);
}

static void c3_eml_error(SFc3_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c3_i321;
  static char_T c3_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[32];
  const mxArray *c3_y = NULL;
  int32_T c3_i322;
  static char_T c3_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
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

  char_T c3_b_u[102];
  const mxArray *c3_b_y = NULL;
  for (c3_i321 = 0; c3_i321 < 32; c3_i321 = c3_i321 + 1) {
    c3_u[c3_i321] = c3_cv0[c3_i321];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c3_i322 = 0; c3_i322 < 102; c3_i322 = c3_i322 + 1) {
    c3_b_u[c3_i322] = c3_cv1[c3_i322];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c3_y, 14, c3_b_y);
}

static real_T c3_sqrt(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
                      c3_x)
{
  real_T c3_b_x;
  real_T c3_c_x;
  c3_b_x = c3_x;
  if (c3_b_x < 0.0) {
    c3_b_eml_error(chartInstance);
  }

  c3_c_x = c3_b_x;
  c3_b_x = c3_c_x;
  return muDoubleScalarSqrt(c3_b_x);
}

static void c3_b_eml_error(SFc3_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c3_i323;
  static char_T c3_cv2[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[31];
  const mxArray *c3_y = NULL;
  int32_T c3_i324;
  static char_T c3_cv3[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c3_b_u[77];
  const mxArray *c3_b_y = NULL;
  for (c3_i323 = 0; c3_i323 < 31; c3_i323 = c3_i323 + 1) {
    c3_u[c3_i323] = c3_cv2[c3_i323];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c3_i324 = 0; c3_i324 < 77; c3_i324 = c3_i324 + 1) {
    c3_b_u[c3_i324] = c3_cv3[c3_i324];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c3_y, 14, c3_b_y);
}

static void c3_mldivide(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_A[36], real_T c3_B[18], real_T c3_Y[18])
{
  int32_T c3_i325;
  real_T c3_b_A[36];
  int32_T c3_i326;
  real_T c3_b_B[18];
  int32_T c3_i327;
  real_T c3_c_A[36];
  int32_T c3_i328;
  real_T c3_c_B[18];
  int32_T c3_i329;
  real_T c3_d_A[36];
  int32_T c3_info;
  int32_T c3_ipiv[6];
  real_T c3_e_A[36];
  int32_T c3_i330;
  int32_T c3_i331;
  int32_T c3_b_ipiv[6];
  int32_T c3_b_info;
  int32_T c3_i332;
  int32_T c3_i;
  int32_T c3_b_i;
  int32_T c3_ip;
  int32_T c3_j;
  int32_T c3_b_j;
  real_T c3_temp;
  int32_T c3_i333;
  real_T c3_f_A[36];
  int32_T c3_i334;
  real_T c3_d_B[18];
  int32_T c3_i335;
  int32_T c3_i336;
  real_T c3_g_A[36];
  int32_T c3_i337;
  real_T c3_b_Y[18];
  int32_T c3_i338;
  real_T c3_h_A[36];
  int32_T c3_i339;
  real_T c3_e_B[18];
  int32_T c3_i340;
  int32_T c3_i341;
  real_T c3_i_A[36];
  int32_T c3_i342;
  real_T c3_c_Y[18];
  for (c3_i325 = 0; c3_i325 < 36; c3_i325 = c3_i325 + 1) {
    c3_b_A[c3_i325] = c3_A[c3_i325];
  }

  for (c3_i326 = 0; c3_i326 < 18; c3_i326 = c3_i326 + 1) {
    c3_b_B[c3_i326] = c3_B[c3_i326];
  }

  for (c3_i327 = 0; c3_i327 < 36; c3_i327 = c3_i327 + 1) {
    c3_c_A[c3_i327] = c3_b_A[c3_i327];
  }

  for (c3_i328 = 0; c3_i328 < 18; c3_i328 = c3_i328 + 1) {
    c3_c_B[c3_i328] = c3_b_B[c3_i328];
  }

  for (c3_i329 = 0; c3_i329 < 36; c3_i329 = c3_i329 + 1) {
    c3_d_A[c3_i329] = c3_c_A[c3_i329];
  }

  c3_eml_xgetrf(chartInstance, c3_d_A, c3_e_A, c3_ipiv, &c3_info);
  for (c3_i330 = 0; c3_i330 < 36; c3_i330 = c3_i330 + 1) {
    c3_c_A[c3_i330] = c3_e_A[c3_i330];
  }

  for (c3_i331 = 0; c3_i331 < 6; c3_i331 = c3_i331 + 1) {
    c3_b_ipiv[c3_i331] = c3_ipiv[c3_i331];
  }

  c3_b_info = c3_info;
  if ((real_T)c3_b_info > 0.0) {
    c3_eml_warning(chartInstance);
  }

  for (c3_i332 = 0; c3_i332 < 18; c3_i332 = c3_i332 + 1) {
    c3_Y[c3_i332] = c3_c_B[c3_i332];
  }

  for (c3_i = 1; c3_i < 7; c3_i = c3_i + 1) {
    c3_b_i = c3_i;
    if (c3_b_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_b_i), 1, 6, 1, 0) - 1] != c3_b_i) {
      c3_ip = c3_b_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c3_b_i), 1, 6, 1, 0) - 1];
      for (c3_j = 1; c3_j < 4; c3_j = c3_j + 1) {
        c3_b_j = c3_j;
        c3_temp = c3_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_b_i), 1, 6, 1, 0) - 1) + 6 * (
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_b_j), 1, 3, 2, 0) - 1)];
        c3_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_i), 1, 6, 1, 0) - 1) + 6 * (
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_b_j), 1, 3, 2, 0) - 1)] = c3_Y[(
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_ip), 1, 6, 1, 0) - 1) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_j), 1, 3, 2, 0) - 1)];
        c3_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_ip), 1, 6, 1, 0) - 1) + 6 * (
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_b_j), 1, 3, 2, 0) - 1)] = c3_temp;
      }
    }
  }

  for (c3_i333 = 0; c3_i333 < 36; c3_i333 = c3_i333 + 1) {
    c3_f_A[c3_i333] = c3_c_A[c3_i333];
  }

  for (c3_i334 = 0; c3_i334 < 18; c3_i334 = c3_i334 + 1) {
    c3_d_B[c3_i334] = c3_Y[c3_i334];
  }

  for (c3_i335 = 0; c3_i335 < 18; c3_i335 = c3_i335 + 1) {
    c3_Y[c3_i335] = c3_d_B[c3_i335];
  }

  for (c3_i336 = 0; c3_i336 < 36; c3_i336 = c3_i336 + 1) {
    c3_g_A[c3_i336] = c3_f_A[c3_i336];
  }

  for (c3_i337 = 0; c3_i337 < 18; c3_i337 = c3_i337 + 1) {
    c3_b_Y[c3_i337] = c3_Y[c3_i337];
  }

  c3_eml_blas_xtrsm(chartInstance, 6, 3, 1.0, c3_g_A, 1, 6, c3_b_Y, 1, 6, c3_Y);
  for (c3_i338 = 0; c3_i338 < 36; c3_i338 = c3_i338 + 1) {
    c3_h_A[c3_i338] = c3_c_A[c3_i338];
  }

  for (c3_i339 = 0; c3_i339 < 18; c3_i339 = c3_i339 + 1) {
    c3_e_B[c3_i339] = c3_Y[c3_i339];
  }

  for (c3_i340 = 0; c3_i340 < 18; c3_i340 = c3_i340 + 1) {
    c3_Y[c3_i340] = c3_e_B[c3_i340];
  }

  for (c3_i341 = 0; c3_i341 < 36; c3_i341 = c3_i341 + 1) {
    c3_i_A[c3_i341] = c3_h_A[c3_i341];
  }

  for (c3_i342 = 0; c3_i342 < 18; c3_i342 = c3_i342 + 1) {
    c3_c_Y[c3_i342] = c3_Y[c3_i342];
  }

  c3_b_eml_blas_xtrsm(chartInstance, 6, 3, 1.0, c3_i_A, 1, 6, c3_c_Y, 1, 6, c3_Y);
}

static void c3_eml_xgetrf(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_A[36], real_T c3_b_A[36], int32_T c3_ipiv[6],
  int32_T *c3_info)
{
  int32_T c3_i343;
  int32_T c3_i344;
  int32_T c3_j;
  int32_T c3_b_j;
  int32_T c3_a;
  int32_T c3_jm1;
  int32_T c3_b;
  int32_T c3_mmj;
  int32_T c3_b_a;
  int32_T c3_c;
  int32_T c3_b_b;
  int32_T c3_jj;
  int32_T c3_c_a;
  int32_T c3_jp1j;
  int32_T c3_d_a;
  int32_T c3_b_c;
  int32_T c3_i345;
  real_T c3_c_A[36];
  int32_T c3_e_a;
  int32_T c3_jpiv_offset;
  int32_T c3_f_a;
  int32_T c3_c_b;
  int32_T c3_jpiv;
  int32_T c3_g_a;
  int32_T c3_d_b;
  int32_T c3_c_c;
  int32_T c3_e_b;
  int32_T c3_jrow;
  int32_T c3_h_a;
  int32_T c3_f_b;
  int32_T c3_jprow;
  int32_T c3_i346;
  real_T c3_x[36];
  int32_T c3_ix0;
  int32_T c3_iy0;
  int32_T c3_i347;
  int32_T c3_i348;
  real_T c3_b_x[36];
  int32_T c3_b_ix0;
  int32_T c3_b_iy0;
  int32_T c3_i349;
  real_T c3_c_x[36];
  int32_T c3_i350;
  real_T c3_d_x[36];
  real_T c3_e_x[36];
  int32_T c3_i351;
  int32_T c3_i352;
  int32_T c3_b_jp1j;
  int32_T c3_i_a;
  int32_T c3_d_c;
  int32_T c3_j_a;
  int32_T c3_g_b;
  int32_T c3_loop_ub;
  int32_T c3_i;
  int32_T c3_b_i;
  real_T c3_f_x;
  real_T c3_y;
  real_T c3_g_x;
  real_T c3_b_y;
  real_T c3_z;
  int32_T c3_h_b;
  int32_T c3_e_c;
  int32_T c3_k_a;
  int32_T c3_f_c;
  int32_T c3_l_a;
  int32_T c3_g_c;
  int32_T c3_m;
  int32_T c3_n;
  int32_T c3_c_ix0;
  int32_T c3_c_iy0;
  int32_T c3_i353;
  real_T c3_d_A[36];
  int32_T c3_ia0;
  int32_T c3_i354;
  int32_T c3_b_m;
  int32_T c3_b_n;
  int32_T c3_d_ix0;
  int32_T c3_d_iy0;
  int32_T c3_i355;
  real_T c3_e_A[36];
  int32_T c3_b_ia0;
  int32_T c3_i356;
  int32_T c3_c_m;
  int32_T c3_c_n;
  int32_T c3_e_ix0;
  int32_T c3_e_iy0;
  int32_T c3_i357;
  real_T c3_f_A[36];
  int32_T c3_c_ia0;
  int32_T c3_i358;
  int32_T c3_i359;
  real_T c3_g_A[36];
  for (c3_i343 = 0; c3_i343 < 36; c3_i343 = c3_i343 + 1) {
    c3_b_A[c3_i343] = c3_A[c3_i343];
  }

  for (c3_i344 = 0; c3_i344 < 6; c3_i344 = c3_i344 + 1) {
    c3_ipiv[c3_i344] = 1 + c3_i344;
  }

  *c3_info = 0;
  for (c3_j = 1; c3_j < 6; c3_j = c3_j + 1) {
    c3_b_j = c3_j;
    c3_a = c3_b_j;
    c3_jm1 = c3_a - 1;
    c3_b = c3_b_j;
    c3_mmj = 6 - c3_b;
    c3_b_a = c3_jm1;
    c3_c = c3_b_a * 7;
    c3_b_b = c3_c;
    c3_jj = 1 + c3_b_b;
    c3_c_a = c3_jj;
    c3_jp1j = c3_c_a + 1;
    c3_d_a = c3_mmj;
    c3_b_c = c3_d_a + 1;
    for (c3_i345 = 0; c3_i345 < 36; c3_i345 = c3_i345 + 1) {
      c3_c_A[c3_i345] = c3_b_A[c3_i345];
    }

    c3_e_a = c3_eml_ixamax(chartInstance, c3_b_c, c3_c_A, c3_jj);
    c3_jpiv_offset = c3_e_a - 1;
    c3_f_a = c3_jj;
    c3_c_b = c3_jpiv_offset;
    c3_jpiv = c3_f_a + c3_c_b;
    if (c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if ((real_T)c3_jpiv_offset != 0.0) {
        c3_g_a = c3_b_j;
        c3_d_b = c3_jpiv_offset;
        c3_c_c = c3_g_a + c3_d_b;
        c3_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_b_j), 1, 6, 1, 0) - 1] = c3_c_c;
        c3_e_b = c3_jm1;
        c3_jrow = 1 + c3_e_b;
        c3_h_a = c3_jrow;
        c3_f_b = c3_jpiv_offset;
        c3_jprow = c3_h_a + c3_f_b;
        for (c3_i346 = 0; c3_i346 < 36; c3_i346 = c3_i346 + 1) {
          c3_x[c3_i346] = c3_b_A[c3_i346];
        }

        c3_ix0 = c3_jrow;
        c3_iy0 = c3_jprow;
        for (c3_i347 = 0; c3_i347 < 36; c3_i347 = c3_i347 + 1) {
          c3_b_A[c3_i347] = c3_x[c3_i347];
        }

        for (c3_i348 = 0; c3_i348 < 36; c3_i348 = c3_i348 + 1) {
          c3_b_x[c3_i348] = c3_b_A[c3_i348];
        }

        c3_b_ix0 = c3_ix0;
        c3_b_iy0 = c3_iy0;
        for (c3_i349 = 0; c3_i349 < 36; c3_i349 = c3_i349 + 1) {
          c3_c_x[c3_i349] = c3_b_x[c3_i349];
        }

        for (c3_i350 = 0; c3_i350 < 36; c3_i350 = c3_i350 + 1) {
          c3_d_x[c3_i350] = c3_c_x[c3_i350];
        }

        c3_ceval_xswap(chartInstance, 6, c3_d_x, c3_b_ix0, 6, c3_b_iy0, 6,
                       c3_e_x);
        for (c3_i351 = 0; c3_i351 < 36; c3_i351 = c3_i351 + 1) {
          c3_c_x[c3_i351] = c3_e_x[c3_i351];
        }

        for (c3_i352 = 0; c3_i352 < 36; c3_i352 = c3_i352 + 1) {
          c3_b_A[c3_i352] = c3_c_x[c3_i352];
        }
      }

      c3_b_jp1j = c3_jp1j;
      c3_i_a = c3_mmj;
      c3_d_c = c3_i_a - 1;
      c3_j_a = c3_jp1j;
      c3_g_b = c3_d_c;
      c3_loop_ub = c3_j_a + c3_g_b;
      for (c3_i = c3_b_jp1j; c3_i <= c3_loop_ub; c3_i = c3_i + 1) {
        c3_b_i = c3_i;
        c3_f_x = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_b_i), 1, 36, 1, 0) - 1];
        c3_y = c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_jj), 1, 36, 1, 0) - 1];
        c3_g_x = c3_f_x;
        c3_b_y = c3_y;
        c3_z = c3_g_x / c3_b_y;
        c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_b_i), 1, 36, 1, 0) - 1] = c3_z;
      }
    } else {
      *c3_info = c3_b_j;
    }

    c3_h_b = c3_b_j;
    c3_e_c = 6 - c3_h_b;
    c3_k_a = c3_jj;
    c3_f_c = c3_k_a + 6;
    c3_l_a = c3_jj;
    c3_g_c = c3_l_a + 7;
    c3_m = c3_mmj;
    c3_n = c3_e_c;
    c3_c_ix0 = c3_jp1j;
    c3_c_iy0 = c3_f_c;
    for (c3_i353 = 0; c3_i353 < 36; c3_i353 = c3_i353 + 1) {
      c3_d_A[c3_i353] = c3_b_A[c3_i353];
    }

    c3_ia0 = c3_g_c;
    for (c3_i354 = 0; c3_i354 < 36; c3_i354 = c3_i354 + 1) {
      c3_b_A[c3_i354] = c3_d_A[c3_i354];
    }

    c3_b_m = c3_m;
    c3_b_n = c3_n;
    c3_d_ix0 = c3_c_ix0;
    c3_d_iy0 = c3_c_iy0;
    for (c3_i355 = 0; c3_i355 < 36; c3_i355 = c3_i355 + 1) {
      c3_e_A[c3_i355] = c3_b_A[c3_i355];
    }

    c3_b_ia0 = c3_ia0;
    for (c3_i356 = 0; c3_i356 < 36; c3_i356 = c3_i356 + 1) {
      c3_b_A[c3_i356] = c3_e_A[c3_i356];
    }

    c3_c_m = c3_b_m;
    c3_c_n = c3_b_n;
    c3_e_ix0 = c3_d_ix0;
    c3_e_iy0 = c3_d_iy0;
    for (c3_i357 = 0; c3_i357 < 36; c3_i357 = c3_i357 + 1) {
      c3_f_A[c3_i357] = c3_b_A[c3_i357];
    }

    c3_c_ia0 = c3_b_ia0;
    for (c3_i358 = 0; c3_i358 < 36; c3_i358 = c3_i358 + 1) {
      c3_b_A[c3_i358] = c3_f_A[c3_i358];
    }

    if ((real_T)c3_c_m < 1.0) {
    } else if ((real_T)c3_c_n < 1.0) {
    } else {
      for (c3_i359 = 0; c3_i359 < 36; c3_i359 = c3_i359 + 1) {
        c3_g_A[c3_i359] = c3_b_A[c3_i359];
      }

      c3_ceval_xger(chartInstance, c3_c_m, c3_c_n, -1.0, c3_e_ix0, 1, c3_e_iy0,
                    6, c3_g_A, c3_c_ia0, 6, c3_b_A);
      goto label_1;
    }

   label_1:
    ;
  }

  if ((real_T)*c3_info == 0.0) {
    if (!(c3_b_A[35] != 0.0)) {
      *c3_info = 6;
      return;
    }
  }
}

static int32_T c3_eml_ixamax(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[36], int32_T c3_ix0)
{
  int32_T c3_b_n;
  int32_T c3_i360;
  real_T c3_b_x[36];
  int32_T c3_b_ix0;
  int32_T c3_i361;
  real_T c3_c_x[36];
  c3_b_n = c3_n;
  for (c3_i360 = 0; c3_i360 < 36; c3_i360 = c3_i360 + 1) {
    c3_b_x[c3_i360] = c3_x[c3_i360];
  }

  c3_b_ix0 = c3_ix0;
  for (c3_i361 = 0; c3_i361 < 36; c3_i361 = c3_i361 + 1) {
    c3_c_x[c3_i361] = c3_b_x[c3_i361];
  }

  return c3_ceval_ixamax(chartInstance, c3_b_n, c3_c_x, c3_b_ix0, 1);
}

static int32_T c3_ceval_ixamax(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[36], int32_T c3_ix0,
  int32_T c3_incx)
{
  return idamax32(&c3_n, &c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 36, 1, 0) - 1], &
                  c3_incx);
}

static void c3_ceval_xswap(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_n, real_T c3_x[36], int32_T c3_ix0, int32_T
  c3_incx, int32_T c3_iy0, int32_T c3_incy, real_T c3_b_x[36])
{
  int32_T c3_i362;

  /* Empty Loop. */
  for (c3_i362 = 0; c3_i362 < 36; c3_i362 = c3_i362 + 1) {
    c3_b_x[c3_i362] = c3_x[c3_i362];
  }

  dswap32(&c3_n, &c3_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 36, 1, 0) - 1], &c3_incx
          , &c3_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c3_iy0), 1, 36, 1, 0) - 1], &c3_incy);
}

static void c3_ceval_xger(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, int32_T
  c3_ix0, int32_T c3_incx, int32_T c3_iy0, int32_T c3_incy, real_T c3_A[36],
  int32_T c3_ia0, int32_T c3_lda, real_T c3_b_A[36])
{
  int32_T c3_i363;
  for (c3_i363 = 0; c3_i363 < 36; c3_i363 = c3_i363 + 1) {
    c3_b_A[c3_i363] = c3_A[c3_i363];
  }

  dger32(&c3_m, &c3_n, &c3_alpha1, &c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_ix0), 1, 36, 1,
          0) - 1], &c3_incx, &c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_iy0), 1, 36, 1, 0) - 1], &
         c3_incy, &c3_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_ia0), 1, 36, 1, 0) - 1], &c3_lda);
}

static void c3_eml_warning(SFc3_twa_parallelInstanceStruct *chartInstance)
{
  int32_T c3_i364;
  static char_T c3_cv4[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x'
  };

  char_T c3_u[21];
  const mxArray *c3_y = NULL;
  int32_T c3_i365;
  static char_T c3_cv5[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o'
    , ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char_T c3_b_u[40];
  const mxArray *c3_b_y = NULL;
  for (c3_i364 = 0; c3_i364 < 21; c3_i364 = c3_i364 + 1) {
    c3_u[c3_i364] = c3_cv4[c3_i364];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c3_i365 = 0; c3_i365 < 40; c3_i365 = c3_i365 + 1) {
    c3_b_u[c3_i365] = c3_cv5[c3_i365];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c3_y, 14, c3_b_y);
}

static void c3_eml_blas_xtrsm(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, real_T
  c3_A[36], int32_T c3_ia0, int32_T c3_lda, real_T c3_B[18], int32_T c3_ib0,
  int32_T c3_ldb, real_T c3_b_B[18])
{
  int32_T c3_i366;
  int32_T c3_i367;
  real_T c3_b_A[36];
  int32_T c3_i368;
  real_T c3_c_B[18];
  for (c3_i366 = 0; c3_i366 < 18; c3_i366 = c3_i366 + 1) {
    c3_b_B[c3_i366] = c3_B[c3_i366];
  }

  for (c3_i367 = 0; c3_i367 < 36; c3_i367 = c3_i367 + 1) {
    c3_b_A[c3_i367] = c3_A[c3_i367];
  }

  for (c3_i368 = 0; c3_i368 < 18; c3_i368 = c3_i368 + 1) {
    c3_c_B[c3_i368] = c3_b_B[c3_i368];
  }

  c3_ceval_xtrsm(chartInstance, c3_m, c3_n, c3_alpha1, c3_b_A, c3_ia0, c3_lda,
                 c3_c_B, c3_ib0, c3_ldb, c3_b_B);
}

static void c3_ceval_xtrsm(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, real_T c3_A
  [36], int32_T c3_ia0, int32_T c3_lda, real_T c3_B[18], int32_T c3_ib0, int32_T
  c3_ldb, real_T c3_b_B[18])
{
  char_T c3_SIDE;
  char_T c3_UPLO;
  char_T c3_TRANSA;
  char_T c3_DIAGA;
  int32_T c3_i369;
  c3_SIDE = 'L';
  c3_UPLO = 'L';
  c3_TRANSA = 'N';
  c3_DIAGA = 'U';
  for (c3_i369 = 0; c3_i369 < 18; c3_i369 = c3_i369 + 1) {
    c3_b_B[c3_i369] = c3_B[c3_i369];
  }

  dtrsm32(&c3_SIDE, &c3_UPLO, &c3_TRANSA, &c3_DIAGA, &c3_m, &c3_n, &c3_alpha1,
          &c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c3_ia0), 1, 36, 1, 0) - 1], &c3_lda,
          &c3_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c3_ib0), 1, 18, 1, 0) - 1], &c3_ldb);
}

static void c3_b_eml_blas_xtrsm(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, real_T
  c3_A[36], int32_T c3_ia0, int32_T c3_lda, real_T c3_B[18], int32_T c3_ib0,
  int32_T c3_ldb, real_T c3_b_B[18])
{
  int32_T c3_i370;
  int32_T c3_i371;
  real_T c3_b_A[36];
  int32_T c3_i372;
  real_T c3_c_B[18];
  for (c3_i370 = 0; c3_i370 < 18; c3_i370 = c3_i370 + 1) {
    c3_b_B[c3_i370] = c3_B[c3_i370];
  }

  for (c3_i371 = 0; c3_i371 < 36; c3_i371 = c3_i371 + 1) {
    c3_b_A[c3_i371] = c3_A[c3_i371];
  }

  for (c3_i372 = 0; c3_i372 < 18; c3_i372 = c3_i372 + 1) {
    c3_c_B[c3_i372] = c3_b_B[c3_i372];
  }

  c3_b_ceval_xtrsm(chartInstance, c3_m, c3_n, c3_alpha1, c3_b_A, c3_ia0, c3_lda,
                   c3_c_B, c3_ib0, c3_ldb, c3_b_B);
}

static void c3_b_ceval_xtrsm(SFc3_twa_parallelInstanceStruct *chartInstance,
  int32_T c3_m, int32_T c3_n, real_T c3_alpha1, real_T
  c3_A[36], int32_T c3_ia0, int32_T c3_lda, real_T c3_B[18], int32_T c3_ib0,
  int32_T c3_ldb, real_T c3_b_B[18])
{
  char_T c3_SIDE;
  char_T c3_UPLO;
  char_T c3_TRANSA;
  char_T c3_DIAGA;
  int32_T c3_i373;
  c3_SIDE = 'L';
  c3_UPLO = 'U';
  c3_TRANSA = 'N';
  c3_DIAGA = 'N';
  for (c3_i373 = 0; c3_i373 < 18; c3_i373 = c3_i373 + 1) {
    c3_b_B[c3_i373] = c3_B[c3_i373];
  }

  dtrsm32(&c3_SIDE, &c3_UPLO, &c3_TRANSA, &c3_DIAGA, &c3_m, &c3_n, &c3_alpha1,
          &c3_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c3_ia0), 1, 36, 1, 0) - 1], &c3_lda,
          &c3_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c3_ib0), 1, 18, 1, 0) - 1], &c3_ldb);
}

static void c3_e_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static void c3_mrdivide(SFc3_twa_parallelInstanceStruct *chartInstance, real_T
  c3_A[18], real_T c3_B[9], real_T c3_y[18])
{
  int32_T c3_i374;
  int32_T c3_i375;
  int32_T c3_i376;
  int32_T c3_i377;
  real_T c3_b_A[9];
  int32_T c3_i378;
  int32_T c3_i379;
  int32_T c3_i380;
  int32_T c3_i381;
  real_T c3_b_B[18];
  int32_T c3_i382;
  real_T c3_c_A[9];
  int32_T c3_i383;
  real_T c3_c_B[18];
  int32_T c3_i384;
  real_T c3_d_A[9];
  int32_T c3_i385;
  real_T c3_d_B[18];
  int32_T c3_r1;
  int32_T c3_r2;
  int32_T c3_r3;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_b_y;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_c_y;
  real_T c3_maxval;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_d_y;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_e_y;
  real_T c3_a21;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_f_y;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_g_y;
  real_T c3_d;
  real_T c3_p_x;
  real_T c3_h_y;
  real_T c3_q_x;
  real_T c3_i_y;
  real_T c3_z;
  real_T c3_r_x;
  real_T c3_j_y;
  real_T c3_s_x;
  real_T c3_k_y;
  real_T c3_b_z;
  real_T c3_a;
  real_T c3_b;
  real_T c3_l_y;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_m_y;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_n_y;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_o_y;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_p_y;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_q_y;
  real_T c3_b_d;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_bb_x;
  real_T c3_r_y;
  real_T c3_cb_x;
  real_T c3_db_x;
  real_T c3_s_y;
  real_T c3_c_d;
  int32_T c3_rtemp;
  real_T c3_eb_x;
  real_T c3_t_y;
  real_T c3_fb_x;
  real_T c3_u_y;
  real_T c3_c_z;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_v_y;
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_Y[18];
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_w_y;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_x_y;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_y_y;
  real_T c3_gb_x;
  real_T c3_ab_y;
  real_T c3_hb_x;
  real_T c3_bb_y;
  real_T c3_d_z;
  real_T c3_i_a;
  real_T c3_i_b;
  real_T c3_cb_y;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_db_y;
  real_T c3_ib_x;
  real_T c3_eb_y;
  real_T c3_jb_x;
  real_T c3_fb_y;
  real_T c3_e_z;
  real_T c3_k_a;
  real_T c3_k_b;
  real_T c3_gb_y;
  real_T c3_kb_x;
  real_T c3_hb_y;
  real_T c3_lb_x;
  real_T c3_ib_y;
  real_T c3_f_z;
  int32_T c3_i386;
  int32_T c3_i387;
  int32_T c3_i388;
  int32_T c3_i389;
  c3_i374 = 0;
  for (c3_i375 = 0; c3_i375 < 3; c3_i375 = c3_i375 + 1) {
    c3_i376 = 0;
    for (c3_i377 = 0; c3_i377 < 3; c3_i377 = c3_i377 + 1) {
      c3_b_A[c3_i377 + c3_i374] = c3_B[c3_i376 + c3_i375];
      c3_i376 = c3_i376 + 3;
    }

    c3_i374 = c3_i374 + 3;
  }

  c3_i378 = 0;
  for (c3_i379 = 0; c3_i379 < 6; c3_i379 = c3_i379 + 1) {
    c3_i380 = 0;
    for (c3_i381 = 0; c3_i381 < 3; c3_i381 = c3_i381 + 1) {
      c3_b_B[c3_i381 + c3_i378] = c3_A[c3_i380 + c3_i379];
      c3_i380 = c3_i380 + 6;
    }

    c3_i378 = c3_i378 + 3;
  }

  for (c3_i382 = 0; c3_i382 < 9; c3_i382 = c3_i382 + 1) {
    c3_c_A[c3_i382] = c3_b_A[c3_i382];
  }

  for (c3_i383 = 0; c3_i383 < 18; c3_i383 = c3_i383 + 1) {
    c3_c_B[c3_i383] = c3_b_B[c3_i383];
  }

  for (c3_i384 = 0; c3_i384 < 9; c3_i384 = c3_i384 + 1) {
    c3_d_A[c3_i384] = c3_c_A[c3_i384];
  }

  for (c3_i385 = 0; c3_i385 < 18; c3_i385 = c3_i385 + 1) {
    c3_d_B[c3_i385] = c3_c_B[c3_i385];
  }

  c3_r1 = 1;
  c3_r2 = 2;
  c3_r3 = 3;
  c3_x = c3_d_A[0];
  c3_b_x = c3_x;
  c3_c_x = c3_b_x;
  c3_b_y = muDoubleScalarAbs(c3_c_x);
  c3_d_x = 0.0;
  c3_e_x = c3_d_x;
  c3_c_y = muDoubleScalarAbs(c3_e_x);
  c3_maxval = c3_b_y + c3_c_y;
  c3_f_x = c3_d_A[1];
  c3_g_x = c3_f_x;
  c3_h_x = c3_g_x;
  c3_d_y = muDoubleScalarAbs(c3_h_x);
  c3_i_x = 0.0;
  c3_j_x = c3_i_x;
  c3_e_y = muDoubleScalarAbs(c3_j_x);
  c3_a21 = c3_d_y + c3_e_y;
  if (c3_a21 > c3_maxval) {
    c3_maxval = c3_a21;
    c3_r1 = 2;
    c3_r2 = 1;
  }

  c3_k_x = c3_d_A[2];
  c3_l_x = c3_k_x;
  c3_m_x = c3_l_x;
  c3_f_y = muDoubleScalarAbs(c3_m_x);
  c3_n_x = 0.0;
  c3_o_x = c3_n_x;
  c3_g_y = muDoubleScalarAbs(c3_o_x);
  c3_d = c3_f_y + c3_g_y;
  if (c3_d > c3_maxval) {
    c3_r1 = 3;
    c3_r2 = 2;
    c3_r3 = 1;
  }

  c3_p_x = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) - 1];
  c3_h_y = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) - 1];
  c3_q_x = c3_p_x;
  c3_i_y = c3_h_y;
  c3_z = c3_q_x / c3_i_y;
  c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r2), 1, 3, 1, 0) - 1] = c3_z;
  c3_r_x = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) - 1];
  c3_j_y = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) - 1];
  c3_s_x = c3_r_x;
  c3_k_y = c3_j_y;
  c3_b_z = c3_s_x / c3_k_y;
  c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) - 1] = c3_b_z;
  c3_a = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) - 1];
  c3_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) + 2];
  c3_l_y = c3_a * c3_b;
  c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r2), 1, 3, 1, 0) + 2] = c3_d_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r2), 1, 3, 1, 0) + 2] - c3_l_y;
  c3_b_a = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) - 1];
  c3_b_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) + 2];
  c3_m_y = c3_b_a * c3_b_b;
  c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 2] = c3_d_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 2] - c3_m_y;
  c3_c_a = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) - 1];
  c3_c_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) + 5];
  c3_n_y = c3_c_a * c3_c_b;
  c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r2), 1, 3, 1, 0) + 5] = c3_d_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r2), 1, 3, 1, 0) + 5] - c3_n_y;
  c3_d_a = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) - 1];
  c3_d_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r1), 1, 3, 1, 0) + 5];
  c3_o_y = c3_d_a * c3_d_b;
  c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 5] = c3_d_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 5] - c3_o_y;
  c3_t_x = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) + 2];
  c3_u_x = c3_t_x;
  c3_v_x = c3_u_x;
  c3_p_y = muDoubleScalarAbs(c3_v_x);
  c3_w_x = 0.0;
  c3_x_x = c3_w_x;
  c3_q_y = muDoubleScalarAbs(c3_x_x);
  c3_b_d = c3_p_y + c3_q_y;
  c3_y_x = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) + 2];
  c3_ab_x = c3_y_x;
  c3_bb_x = c3_ab_x;
  c3_r_y = muDoubleScalarAbs(c3_bb_x);
  c3_cb_x = 0.0;
  c3_db_x = c3_cb_x;
  c3_s_y = muDoubleScalarAbs(c3_db_x);
  c3_c_d = c3_r_y + c3_s_y;
  if (c3_b_d > c3_c_d) {
    c3_rtemp = c3_r2;
    c3_r2 = c3_r3;
    c3_r3 = c3_rtemp;
  }

  c3_eb_x = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c3_r3), 1, 3, 1, 0) + 2];
  c3_t_y = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) + 2];
  c3_fb_x = c3_eb_x;
  c3_u_y = c3_t_y;
  c3_c_z = c3_fb_x / c3_u_y;
  c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 2] = c3_c_z;
  c3_e_a = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r3), 1, 3, 1, 0) + 2];
  c3_e_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c3_r2), 1, 3, 1, 0) + 5];
  c3_v_y = c3_e_a * c3_e_b;
  c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 5] = c3_d_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_r3), 1, 3, 1, 0) + 5] - c3_v_y;
  if (c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c3_r1), 1, 3, 1, 0) - 1] == 0.0) {
  } else if (c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
               "", (real_T)c3_r2), 1, 3, 1, 0) + 2] == 0.0) {
  } else if (c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
               "", (real_T)c3_r3), 1, 3, 1, 0) + 5] == 0.0) {
    goto label_1;
  } else {
    goto label_2;
  }

 label_1:
  ;
  c3_eml_warning(chartInstance);
 label_2:
  ;
  for (c3_k = 1; c3_k < 7; c3_k = c3_k + 1) {
    c3_b_k = c3_k;
    c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = c3_d_B[(
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c3_r1), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_f_a = c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_f_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r2), 1, 3, 1, 0) - 1];
    c3_w_y = c3_f_a * c3_f_b;
    c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = c3_d_B[(
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c3_r2), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)] -
      c3_w_y;
    c3_g_a = c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_g_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r3), 1, 3, 1, 0) - 1];
    c3_x_y = c3_g_a * c3_g_b;
    c3_h_a = c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_h_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r3), 1, 3, 1, 0) + 2];
    c3_y_y = c3_h_a * c3_h_b;
    c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = (c3_d_B[(
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c3_r3), 1, 3, 1, 0) - 1) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)] -
      c3_x_y) - c3_y_y;
    c3_gb_x = c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_ab_y = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c3_r3), 1, 3, 1, 0) + 5];
    c3_hb_x = c3_gb_x;
    c3_bb_y = c3_ab_y;
    c3_d_z = c3_hb_x / c3_bb_y;
    c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = c3_d_z;
    c3_i_a = c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_i_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r1), 1, 3, 1, 0) + 5];
    c3_cb_y = c3_i_a * c3_i_b;
    c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = c3_Y[3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c3_b_k), 1, 6, 2, 0) - 1)] - c3_cb_y;
    c3_j_a = c3_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_j_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r2), 1, 3, 1, 0) + 5];
    c3_db_y = c3_j_a * c3_j_b;
    c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = c3_Y[1 + 3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c3_b_k), 1, 6, 2, 0) - 1)] - c3_db_y;
    c3_ib_x = c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_eb_y = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c3_r2), 1, 3, 1, 0) + 2];
    c3_jb_x = c3_ib_x;
    c3_fb_y = c3_eb_y;
    c3_e_z = c3_jb_x / c3_fb_y;
    c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = c3_e_z;
    c3_k_a = c3_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_k_b = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c3_r1), 1, 3, 1, 0) + 2];
    c3_gb_y = c3_k_a * c3_k_b;
    c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = c3_Y[3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c3_b_k), 1, 6, 2, 0) - 1)] - c3_gb_y;
    c3_kb_x = c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 6, 2, 0) - 1)];
    c3_hb_y = c3_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c3_r1), 1, 3, 1, 0) - 1];
    c3_lb_x = c3_kb_x;
    c3_ib_y = c3_hb_y;
    c3_f_z = c3_lb_x / c3_ib_y;
    c3_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c3_b_k), 1, 6, 2, 0) - 1)] = c3_f_z;
  }

  c3_i386 = 0;
  for (c3_i387 = 0; c3_i387 < 3; c3_i387 = c3_i387 + 1) {
    c3_i388 = 0;
    for (c3_i389 = 0; c3_i389 < 6; c3_i389 = c3_i389 + 1) {
      c3_y[c3_i389 + c3_i386] = c3_Y[c3_i388 + c3_i387];
      c3_i388 = c3_i388 + 3;
    }

    c3_i386 = c3_i386 + 6;
  }
}

static void c3_f_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static void c3_g_eml_scalar_eg(SFc3_twa_parallelInstanceStruct *chartInstance)
{
}

static const mxArray *c3_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i390;
  int32_T c3_i391;
  int32_T c3_i392;
  real_T c3_b_u[9];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_i390 = 0;
  for (c3_i391 = 0; c3_i391 < 3; c3_i391 = c3_i391 + 1) {
    for (c3_i392 = 0; c3_i392 < 3; c3_i392 = c3_i392 + 1) {
      c3_b_u[c3_i392 + c3_i390] = (*((real_T (*)[9])c3_u))[c3_i392 + c3_i390];
    }

    c3_i390 = c3_i390 + 3;
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_b_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i393;
  real_T c3_b_u[3];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i393 = 0; c3_i393 < 3; c3_i393 = c3_i393 + 1) {
    c3_b_u[c3_i393] = (*((real_T (*)[3])c3_u))[c3_i393];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_c_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i394;
  real_T c3_b_u[6];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i394 = 0; c3_i394 < 6; c3_i394 = c3_i394 + 1) {
    c3_b_u[c3_i394] = (*((real_T (*)[6])c3_u))[c3_i394];
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
  int32_T c3_i395;
  real_T c3_b_u[2];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  for (c3_i395 = 0; c3_i395 < 2; c3_i395 = c3_i395 + 1) {
    c3_b_u[c3_i395] = (*((real_T (*)[2])c3_u))[c3_i395];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_f_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i396;
  int32_T c3_i397;
  int32_T c3_i398;
  real_T c3_b_u[18];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_i396 = 0;
  for (c3_i397 = 0; c3_i397 < 3; c3_i397 = c3_i397 + 1) {
    for (c3_i398 = 0; c3_i398 < 6; c3_i398 = c3_i398 + 1) {
      c3_b_u[c3_i398 + c3_i396] = (*((real_T (*)[18])c3_u))[c3_i398 + c3_i396];
    }

    c3_i396 = c3_i396 + 6;
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 2, 6, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_g_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i399;
  int32_T c3_i400;
  int32_T c3_i401;
  real_T c3_b_u[36];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_i399 = 0;
  for (c3_i400 = 0; c3_i400 < 6; c3_i400 = c3_i400 + 1) {
    for (c3_i401 = 0; c3_i401 < 6; c3_i401 = c3_i401 + 1) {
      c3_b_u[c3_i401 + c3_i399] = (*((real_T (*)[36])c3_u))[c3_i401 + c3_i399];
    }

    c3_i399 = c3_i399 + 6;
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_h_sf_marshall(void *chartInstanceVoid, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i402;
  int32_T c3_i403;
  int32_T c3_i404;
  real_T c3_b_u[18];
  const mxArray *c3_b_y = NULL;
  SFc3_twa_parallelInstanceStruct *chartInstance;
  chartInstance = (SFc3_twa_parallelInstanceStruct *)chartInstanceVoid;
  c3_y = NULL;
  c3_i402 = 0;
  for (c3_i403 = 0; c3_i403 < 6; c3_i403 = c3_i403 + 1) {
    for (c3_i404 = 0; c3_i404 < 3; c3_i404 = c3_i404 + 1) {
      c3_b_u[c3_i404 + c3_i402] = (*((real_T (*)[18])c3_u))[c3_i404 + c3_i402];
    }

    c3_i402 = c3_i402 + 3;
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 1U, 0U, 2, 3, 6));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_twa_parallel_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[101];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i405;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  c3_b_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 101));
  for (c3_i405 = 0; c3_i405 < 101; c3_i405 = c3_i405 + 1) {
    c3_r0 = &c3_info[c3_i405];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
                    "nameCaptureInfo", c3_i405);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name",
                    "nameCaptureInfo", c3_i405);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c3_i405);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c3_i405);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c3_i405);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c3_i405);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c3_i405);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[101])
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
  c3_info[61].name = "mpower";
  c3_info[61].dominantType = "double";
  c3_info[61].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[61].fileLength = 3710U;
  c3_info[61].fileTime1 = 1238459488U;
  c3_info[61].fileTime2 = 0U;
  c3_info[62].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[62].name = "power";
  c3_info[62].dominantType = "double";
  c3_info[62].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[62].fileLength = 5380U;
  c3_info[62].fileTime1 = 1228119098U;
  c3_info[62].fileTime2 = 0U;
  c3_info[63].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[63].name = "eml_scalar_floor";
  c3_info[63].dominantType = "double";
  c3_info[63].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[63].fileLength = 260U;
  c3_info[63].fileTime1 = 1209355990U;
  c3_info[63].fileTime2 = 0U;
}

static void c3_b_info_helper(c3_ResolvedFunctionInfo c3_info[101])
{
  c3_info[64].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[64].name = "eml_error";
  c3_info[64].dominantType = "char";
  c3_info[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[64].fileLength = 315U;
  c3_info[64].fileTime1 = 1213951944U;
  c3_info[64].fileTime2 = 0U;
  c3_info[65].context = "";
  c3_info[65].name = "mrdivide";
  c3_info[65].dominantType = "double";
  c3_info[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[65].fileLength = 800U;
  c3_info[65].fileTime1 = 1238459490U;
  c3_info[65].fileTime2 = 0U;
  c3_info[66].context = "";
  c3_info[66].name = "sqrt";
  c3_info[66].dominantType = "double";
  c3_info[66].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[66].fileLength = 572U;
  c3_info[66].fileTime1 = 1203473244U;
  c3_info[66].fileTime2 = 0U;
  c3_info[67].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[67].name = "eml_scalar_sqrt";
  c3_info[67].dominantType = "double";
  c3_info[67].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c3_info[67].fileLength = 664U;
  c3_info[67].fileTime1 = 1209355994U;
  c3_info[67].fileTime2 = 0U;
  c3_info[68].context = "";
  c3_info[68].name = "eye";
  c3_info[68].dominantType = "double";
  c3_info[68].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c3_info[68].fileLength = 1765U;
  c3_info[68].fileTime1 = 1219778088U;
  c3_info[68].fileTime2 = 0U;
  c3_info[69].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c3_info[69].name = "eml_assert_valid_size_arg";
  c3_info[69].dominantType = "double";
  c3_info[69].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[69].fileLength = 3315U;
  c3_info[69].fileTime1 = 1256070432U;
  c3_info[69].fileTime2 = 0U;
  c3_info[70].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c3_info[70].name = "isinf";
  c3_info[70].dominantType = "double";
  c3_info[70].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c3_info[70].fileLength = 506U;
  c3_info[70].fileTime1 = 1228119008U;
  c3_info[70].fileTime2 = 0U;
  c3_info[71].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c3_info[71].name = "double";
  c3_info[71].dominantType = "double";
  c3_info[71].resolved = "[B]double";
  c3_info[71].fileLength = 0U;
  c3_info[71].fileTime1 = 0U;
  c3_info[71].fileTime2 = 0U;
  c3_info[72].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[72].name = "intmax";
  c3_info[72].dominantType = "char";
  c3_info[72].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[72].fileLength = 1535U;
  c3_info[72].fileTime1 = 1192491928U;
  c3_info[72].fileTime2 = 0U;
  c3_info[73].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[73].name = "int32";
  c3_info[73].dominantType = "double";
  c3_info[73].resolved = "[B]int32";
  c3_info[73].fileLength = 0U;
  c3_info[73].fileTime1 = 0U;
  c3_info[73].fileTime2 = 0U;
  c3_info[74].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c3_info[74].name = "eml_is_float_class";
  c3_info[74].dominantType = "char";
  c3_info[74].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[74].fileLength = 226U;
  c3_info[74].fileTime1 = 1197875640U;
  c3_info[74].fileTime2 = 0U;
  c3_info[75].context = "";
  c3_info[75].name = "diag";
  c3_info[75].dominantType = "double";
  c3_info[75].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  c3_info[75].fileLength = 2774U;
  c3_info[75].fileTime1 = 1240287180U;
  c3_info[75].fileTime2 = 0U;
  c3_info[76].context = "";
  c3_info[76].name = "mldivide";
  c3_info[76].dominantType = "double";
  c3_info[76].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c3_info[76].fileLength = 998U;
  c3_info[76].fileTime1 = 1238459488U;
  c3_info[76].fileTime2 = 0U;
  c3_info[77].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c3_info[77].name = "eml_lusolve";
  c3_info[77].dominantType = "double";
  c3_info[77].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c3_info[77].fileLength = 4120U;
  c3_info[77].fileTime1 = 1228119032U;
  c3_info[77].fileTime2 = 0U;
  c3_info[78].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolveNxN";
  c3_info[78].name = "eml_xgetrf";
  c3_info[78].dominantType = "int32";
  c3_info[78].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c3_info[78].fileLength = 2229U;
  c3_info[78].fileTime1 = 1240287214U;
  c3_info[78].fileTime2 = 0U;
  c3_info[79].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c3_info[79].name = "colon";
  c3_info[79].dominantType = "int32";
  c3_info[79].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c3_info[79].fileLength = 8592U;
  c3_info[79].fileTime1 = 1257808582U;
  c3_info[79].fileTime2 = 0U;
  c3_info[80].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c3_info[80].name = "floor";
  c3_info[80].dominantType = "double";
  c3_info[80].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[80].fileLength = 332U;
  c3_info[80].fileTime1 = 1203473222U;
  c3_info[80].fileTime2 = 0U;
  c3_info[81].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c3_info[81].name = "intmin";
  c3_info[81].dominantType = "char";
  c3_info[81].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c3_info[81].fileLength = 1505U;
  c3_info[81].fileTime1 = 1192491928U;
  c3_info[81].fileTime2 = 0U;
  c3_info[82].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c3_info[82].name = "isnan";
  c3_info[82].dominantType = "double";
  c3_info[82].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[82].fileLength = 506U;
  c3_info[82].fileTime1 = 1228119010U;
  c3_info[82].fileTime2 = 0U;
  c3_info[83].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c3_info[83].name = "realmax";
  c3_info[83].dominantType = "";
  c3_info[83].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c3_info[83].fileLength = 771U;
  c3_info[83].fileTime1 = 1226602476U;
  c3_info[83].fileTime2 = 0U;
  c3_info[84].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c3_info[84].name = "transpose";
  c3_info[84].dominantType = "int32";
  c3_info[84].resolved = "[B]transpose";
  c3_info[84].fileLength = 0U;
  c3_info[84].fileTime1 = 0U;
  c3_info[84].fileTime2 = 0U;
  c3_info[85].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c3_info[85].name = "eml_ixamax";
  c3_info[85].dominantType = "int32";
  c3_info[85].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c3_info[85].fileLength = 731U;
  c3_info[85].fileTime1 = 1209356044U;
  c3_info[85].fileTime2 = 0U;
  c3_info[86].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c3_info[86].name = "eml_refblas_ixamax";
  c3_info[86].dominantType = "int32";
  c3_info[86].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c3_info[86].fileLength = 740U;
  c3_info[86].fileTime1 = 1192492066U;
  c3_info[86].fileTime2 = 0U;
  c3_info[87].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c3_info[87].name = "eml_xcabs1";
  c3_info[87].dominantType = "double";
  c3_info[87].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c3_info[87].fileLength = 419U;
  c3_info[87].fileTime1 = 1209356046U;
  c3_info[87].fileTime2 = 0U;
  c3_info[88].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c3_info[88].name = "eml_xswap";
  c3_info[88].dominantType = "int32";
  c3_info[88].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c3_info[88].fileLength = 1330U;
  c3_info[88].fileTime1 = 1209356060U;
  c3_info[88].fileTime2 = 0U;
  c3_info[89].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c3_info[89].name = "eml_refblas_xswap";
  c3_info[89].dominantType = "int32";
  c3_info[89].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c3_info[89].fileLength = 905U;
  c3_info[89].fileTime1 = 1238459470U;
  c3_info[89].fileTime2 = 0U;
  c3_info[90].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c3_info[90].name = "eml_xgeru";
  c3_info[90].dominantType = "int32";
  c3_info[90].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c3_info[90].fileLength = 2462U;
  c3_info[90].fileTime1 = 1209356056U;
  c3_info[90].fileTime2 = 0U;
  c3_info[91].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c3_info[91].name = "eml_xger";
  c3_info[91].dominantType = "int32";
  c3_info[91].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c3_info[91].fileLength = 2168U;
  c3_info[91].fileTime1 = 1209356054U;
  c3_info[91].fileTime2 = 0U;
  c3_info[92].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c3_info[92].name = "eml_refblas_xger";
  c3_info[92].dominantType = "int32";
  c3_info[92].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c3_info[92].fileLength = 411U;
  c3_info[92].fileTime1 = 1211241248U;
  c3_info[92].fileTime2 = 0U;
  c3_info[93].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c3_info[93].name = "eml_refblas_xgerx";
  c3_info[93].dominantType = "int32";
  c3_info[93].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c3_info[93].fileLength = 2231U;
  c3_info[93].fileTime1 = 1238459468U;
  c3_info[93].fileTime2 = 0U;
  c3_info[94].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/warn_singular";
  c3_info[94].name = "eml_warning";
  c3_info[94].dominantType = "char";
  c3_info[94].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c3_info[94].fileLength = 262U;
  c3_info[94].fileTime1 = 1236282478U;
  c3_info[94].fileTime2 = 0U;
  c3_info[95].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolveNxN";
  c3_info[95].name = "eml_xtrsm";
  c3_info[95].dominantType = "int32";
  c3_info[95].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c3_info[95].fileLength = 2383U;
  c3_info[95].fileTime1 = 1209356062U;
  c3_info[95].fileTime2 = 0U;
  c3_info[96].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c3_info[96].name = "eml_refblas_xtrsm";
  c3_info[96].dominantType = "int32";
  c3_info[96].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c3_info[96].fileLength = 13101U;
  c3_info[96].fileTime1 = 1252025302U;
  c3_info[96].fileTime2 = 0U;
  c3_info[97].context = "";
  c3_info[97].name = "cos";
  c3_info[97].dominantType = "double";
  c3_info[97].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[97].fileLength = 324U;
  c3_info[97].fileTime1 = 1203473150U;
  c3_info[97].fileTime2 = 0U;
  c3_info[98].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[98].name = "eml_scalar_cos";
  c3_info[98].dominantType = "double";
  c3_info[98].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[98].fileLength = 602U;
  c3_info[98].fileTime1 = 1209355986U;
  c3_info[98].fileTime2 = 0U;
  c3_info[99].context = "";
  c3_info[99].name = "sin";
  c3_info[99].dominantType = "double";
  c3_info[99].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[99].fileLength = 324U;
  c3_info[99].fileTime1 = 1203473242U;
  c3_info[99].fileTime2 = 0U;
  c3_info[100].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[100].name = "eml_scalar_sin";
  c3_info[100].dominantType = "double";
  c3_info[100].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[100].fileLength = 601U;
  c3_info[100].fileTime1 = 1209355990U;
  c3_info[100].fileTime2 = 0U;
}

static const mxArray *c3_i_sf_marshall(void *chartInstanceVoid, void *c3_u)
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
  real_T c3_dv19[3];
  int32_T c3_i406;
  sf_mex_import(c3_name, sf_mex_dup(c3_des_leg_len), &c3_dv19, 1, 0, 0U, 1, 0U,
                1, 3);
  for (c3_i406 = 0; c3_i406 < 3; c3_i406 = c3_i406 + 1) {
    c3_y[c3_i406] = c3_dv19[c3_i406];
  }

  sf_mex_destroy(&c3_des_leg_len);
}

static void c3_b_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c3_qcmd, const char_T *c3_name,
  real_T c3_y[6])
{
  real_T c3_dv20[6];
  int32_T c3_i407;
  sf_mex_import(c3_name, sf_mex_dup(c3_qcmd), &c3_dv20, 1, 0, 0U, 1, 0U, 1, 6);
  for (c3_i407 = 0; c3_i407 < 6; c3_i407 = c3_i407 + 1) {
    c3_y[c3_i407] = c3_dv20[c3_i407];
  }

  sf_mex_destroy(&c3_qcmd);
}

static void c3_c_emlrt_marshallIn(SFc3_twa_parallelInstanceStruct *chartInstance,
  const mxArray *c3_rwave_out, const char_T *c3_name
  , real_T c3_y[9])
{
  real_T c3_dv21[9];
  int32_T c3_i408;
  sf_mex_import(c3_name, sf_mex_dup(c3_rwave_out), &c3_dv21, 1, 0, 0U, 1, 0U, 2,
                3, 3);
  for (c3_i408 = 0; c3_i408 < 9; c3_i408 = c3_i408 + 1) {
    c3_y[c3_i408] = c3_dv21[c3_i408];
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3125513861U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3162348885U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2574572312U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1149452505U);
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
    pr[0] = (double)(3959066677U);
    pr[1] = (double)(3102943938U);
    pr[2] = (double)(4206513341U);
    pr[3] = (double)(2717381764U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,14,3,dataFields);

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
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(1);
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
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));
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
           19,
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
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"m_in_w",0,(MexFcnForType)c3_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"f_in_w",0,(MexFcnForType)c3_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"measured_len",0,(MexFcnForType)
                                c3_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "velmex_pitch",0,(MexFcnForType)c3_d_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(12,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"macro_leg_len",0,(MexFcnForType)
                                c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(13,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"eq",0,(MexFcnForType)c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(14,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"eq_out",0,(MexFcnForType)c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(15,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"twave_out",0,(MexFcnForType)
                                c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(16,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"rwave_out",0,(MexFcnForType)
                                c3_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(17,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"twave",0,(MexFcnForType)c3_b_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(18,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4151);
        _SFD_CV_INIT_EML_IF(0,0,275,294,4047,4151);
        _SFD_CV_INIT_EML_FOR(0,0,3564,3576,3692);
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
          real_T (*c3_m_in_w)[9];
          real_T (*c3_f_in_w)[9];
          real_T (*c3_measured_len)[3];
          real_T *c3_velmex_pitch;
          real_T (*c3_macro_leg_len)[3];
          real_T (*c3_eq)[3];
          real_T (*c3_eq_out)[3];
          real_T (*c3_twave_out)[3];
          real_T (*c3_rwave_out)[9];
          real_T (*c3_twave)[3];
          real_T (*c3_rwave)[9];
          c3_rwave = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 13);
          c3_twave = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 12);
          c3_rwave_out = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S,
            5);
          c3_twave_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            4);
          c3_eq_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c3_eq = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 11);
          c3_macro_leg_len = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 10);
          c3_velmex_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c3_measured_len = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            8);
          c3_f_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 7);
          c3_m_in_w = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
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
          _SFD_SET_DATA_VALUE_PTR(8U, c3_m_in_w);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_f_in_w);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_measured_len);
          _SFD_SET_DATA_VALUE_PTR(11U, c3_velmex_pitch);
          _SFD_SET_DATA_VALUE_PTR(12U, c3_macro_leg_len);
          _SFD_SET_DATA_VALUE_PTR(13U, c3_eq);
          _SFD_SET_DATA_VALUE_PTR(14U, c3_eq_out);
          _SFD_SET_DATA_VALUE_PTR(15U, c3_twave_out);
          _SFD_SET_DATA_VALUE_PTR(16U, c3_rwave_out);
          _SFD_SET_DATA_VALUE_PTR(17U, c3_twave);
          _SFD_SET_DATA_VALUE_PTR(18U, c3_rwave);
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
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"twa_parallel","twa_parallel",3,14);
      sf_mark_chart_reusable_outputs(S,"twa_parallel","twa_parallel",3,5);
    }

    sf_set_rtw_dwork_info(S,"twa_parallel","twa_parallel",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2668090163U));
  ssSetChecksum1(S,(3153357714U));
  ssSetChecksum2(S,(330800342U));
  ssSetChecksum3(S,(3998050496U));
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
