/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c4_large_snake.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c4_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance);
static void enable_c4_large_snake(SFc4_large_snakeInstanceStruct *chartInstance);
static void disable_c4_large_snake(SFc4_large_snakeInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_large_snake
  (SFc4_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_large_snake
  (SFc4_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance);
static void sf_c4_large_snake(SFc4_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u);
static const mxArray *c4_c_sf_marshall(void *chartInstanceVoid, void *c4_u);
static void c4_emlrt_marshallIn(SFc4_large_snakeInstanceStruct *chartInstance,
  const mxArray *c4_y, const char_T *c4_name, real_T c4_b_y[9]);
static uint8_T c4_b_emlrt_marshallIn(SFc4_large_snakeInstanceStruct
  *chartInstance, const mxArray *c4_is_active_c4_large_snake, const char_T
  *c4_name);
static void init_dsm_address_info(SFc4_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c4_is_active_c4_large_snake;
  c4_is_active_c4_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c4_is_active_c4_large_snake = 0U;
}

static void initialize_params_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c4_large_snake(SFc4_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_large_snake(SFc4_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_large_snake
  (SFc4_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance)
{
  c4_update_debugger_state_c4_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c4_large_snake
  (SFc4_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_hoistedGlobal[9];
  int32_T c4_i1;
  real_T c4_u[9];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T *c4_is_active_c4_large_snake;
  real_T (*c4_d_y)[9];
  c4_d_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_is_active_c4_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2));
  for (c4_i0 = 0; c4_i0 < 9; c4_i0 = c4_i0 + 1) {
    c4_hoistedGlobal[c4_i0] = (*c4_d_y)[c4_i0];
  }

  for (c4_i1 = 0; c4_i1 < 9; c4_i1 = c4_i1 + 1) {
    c4_u[c4_i1] = c4_hoistedGlobal[c4_i1];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 1U, 0U, 1, 9));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_is_active_c4_large_snake;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[9];
  int32_T c4_i2;
  boolean_T *c4_doneDoubleBufferReInit;
  uint8_T *c4_is_active_c4_large_snake;
  real_T (*c4_y)[9];
  c4_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_is_active_c4_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c4_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "y",
                      c4_dv0);
  for (c4_i2 = 0; c4_i2 < 9; c4_i2 = c4_i2 + 1) {
    (*c4_y)[c4_i2] = c4_dv0[c4_i2];
  }

  *c4_is_active_c4_large_snake = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "is_active_c4_large_snake");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_large_snake(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_large_snake(SFc4_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c4_large_snake(SFc4_large_snakeInstanceStruct *chartInstance)
{
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_previousEvent;
  int32_T c4_i5;
  real_T c4_hoistedGlobal[9];
  int32_T c4_i6;
  real_T c4_u[9];
  uint32_T c4_debug_family_var_map[4];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_y[9];
  int32_T c4_i7;
  real_T c4_x[9];
  int32_T c4_i8;
  real_T c4_k;
  real_T c4_b_k;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  int32_T c4_i9;
  real_T (*c4_b_y)[9];
  real_T (*c4_b_u)[9];
  c4_b_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_u = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,3);
  for (c4_i3 = 0; c4_i3 < 9; c4_i3 = c4_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_u)[c4_i3], 0U);
  }

  for (c4_i4 = 0; c4_i4 < 9; c4_i4 = c4_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c4_b_y)[c4_i4], 1U);
  }

  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  for (c4_i5 = 0; c4_i5 < 9; c4_i5 = c4_i5 + 1) {
    c4_hoistedGlobal[c4_i5] = (*c4_b_u)[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 9; c4_i6 = c4_i6 + 1) {
    c4_u[c4_i6] = c4_hoistedGlobal[c4_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c4_nargin, c4_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c4_nargout, c4_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c4_u, c4_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c4_y, c4_sf_marshall, 3U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,4);
  for (c4_i7 = 0; c4_i7 < 9; c4_i7 = c4_i7 + 1) {
    c4_x[c4_i7] = c4_u[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 9; c4_i8 = c4_i8 + 1) {
    c4_y[c4_i8] = c4_x[c4_i8];
  }

  for (c4_k = 1.0; c4_k <= 9.0; c4_k = c4_k + 1.0) {
    c4_b_k = c4_k;
    c4_b_x = c4_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c4_b_k), 1, 9, 1, 0) - 1];
    c4_c_x = c4_b_x;
    c4_d_x = c4_c_x;
    if (c4_d_x < 0.0) {
      c4_c_x = muDoubleScalarCeil(c4_d_x - 0.5);
    } else {
      c4_c_x = muDoubleScalarFloor(c4_d_x + 0.5);
    }

    c4_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c4_b_k),
      1, 9, 1, 0) - 1] = c4_c_x;
  }

  _SFD_EML_CALL(0,-4);
  sf_debug_symbol_scope_pop();
  for (c4_i9 = 0; c4_i9 < 9; c4_i9 = c4_i9 + 1) {
    (*c4_b_y)[c4_i9] = c4_y[c4_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  int32_T c4_i10;
  real_T c4_b_u[9];
  const mxArray *c4_b_y = NULL;
  SFc4_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc4_large_snakeInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  for (c4_i10 = 0; c4_i10 < 9; c4_i10 = c4_i10 + 1) {
    c4_b_u[c4_i10] = (*((real_T (*)[9])c4_u))[c4_i10];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 1U, 0U, 1, 9));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc4_large_snakeInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[10];
  c4_ResolvedFunctionInfo (*c4_b_info)[10];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i11;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[10])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "round";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c4_b_info)[0].fileLength = 331U;
  (*c4_b_info)[0].fileTime1 = 1203473236U;
  (*c4_b_info)[0].fileTime2 = 0U;
  (*c4_b_info)[1].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c4_b_info)[1].name = "nargin";
  (*c4_b_info)[1].dominantType = "";
  (*c4_b_info)[1].resolved = "[B]nargin";
  (*c4_b_info)[1].fileLength = 0U;
  (*c4_b_info)[1].fileTime1 = 0U;
  (*c4_b_info)[1].fileTime2 = 0U;
  (*c4_b_info)[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c4_b_info)[2].name = "gt";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved = "[B]gt";
  (*c4_b_info)[2].fileLength = 0U;
  (*c4_b_info)[2].fileTime1 = 0U;
  (*c4_b_info)[2].fileTime2 = 0U;
  (*c4_b_info)[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c4_b_info)[3].name = "isa";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved = "[B]isa";
  (*c4_b_info)[3].fileLength = 0U;
  (*c4_b_info)[3].fileTime1 = 0U;
  (*c4_b_info)[3].fileTime2 = 0U;
  (*c4_b_info)[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c4_b_info)[4].name = "eml_scalar_round";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c4_b_info)[4].fileLength = 523U;
  (*c4_b_info)[4].fileTime1 = 1203473208U;
  (*c4_b_info)[4].fileTime2 = 0U;
  (*c4_b_info)[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c4_b_info)[5].name = "isfloat";
  (*c4_b_info)[5].dominantType = "double";
  (*c4_b_info)[5].resolved = "[B]isfloat";
  (*c4_b_info)[5].fileLength = 0U;
  (*c4_b_info)[5].fileTime1 = 0U;
  (*c4_b_info)[5].fileTime2 = 0U;
  (*c4_b_info)[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c4_b_info)[6].name = "isreal";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved = "[B]isreal";
  (*c4_b_info)[6].fileLength = 0U;
  (*c4_b_info)[6].fileTime1 = 0U;
  (*c4_b_info)[6].fileTime2 = 0U;
  (*c4_b_info)[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  (*c4_b_info)[7].name = "lt";
  (*c4_b_info)[7].dominantType = "double";
  (*c4_b_info)[7].resolved = "[B]lt";
  (*c4_b_info)[7].fileLength = 0U;
  (*c4_b_info)[7].fileTime1 = 0U;
  (*c4_b_info)[7].fileTime2 = 0U;
  (*c4_b_info)[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  (*c4_b_info)[8].name = "minus";
  (*c4_b_info)[8].dominantType = "double";
  (*c4_b_info)[8].resolved = "[B]minus";
  (*c4_b_info)[8].fileLength = 0U;
  (*c4_b_info)[8].fileTime1 = 0U;
  (*c4_b_info)[8].fileTime2 = 0U;
  (*c4_b_info)[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m/scalar_round";
  (*c4_b_info)[9].name = "plus";
  (*c4_b_info)[9].dominantType = "double";
  (*c4_b_info)[9].resolved = "[B]plus";
  (*c4_b_info)[9].fileLength = 0U;
  (*c4_b_info)[9].fileTime1 = 0U;
  (*c4_b_info)[9].fileTime2 = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10));
  for (c4_i11 = 0; c4_i11 < 10; c4_i11 = c4_i11 + 1) {
    c4_r0 = &c4_info[c4_i11];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i11);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i11);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i11);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i11);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i11);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i11
                    );
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i11
                    );
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_c_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  boolean_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc4_large_snakeInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((boolean_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static void c4_emlrt_marshallIn(SFc4_large_snakeInstanceStruct *chartInstance,
  const mxArray *c4_y, const char_T *c4_name, real_T
  c4_b_y[9])
{
  real_T c4_dv1[9];
  int32_T c4_i12;
  sf_mex_import(c4_name, sf_mex_dup(c4_y), &c4_dv1, 1, 0, 0U, 1, 0U, 1, 9);
  for (c4_i12 = 0; c4_i12 < 9; c4_i12 = c4_i12 + 1) {
    c4_b_y[c4_i12] = c4_dv1[c4_i12];
  }

  sf_mex_destroy(&c4_y);
}

static uint8_T c4_b_emlrt_marshallIn(SFc4_large_snakeInstanceStruct
  *chartInstance, const mxArray *c4_is_active_c4_large_snake,
  const char_T *c4_name)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_name, sf_mex_dup(c4_is_active_c4_large_snake), &c4_u0, 1, 3,
                0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_is_active_c4_large_snake);
  return c4_y;
}

static void init_dsm_address_info(SFc4_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3491856654U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(495629402U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4003270423U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1792094919U);
}

mxArray *sf_c4_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1343387890U);
    pr[1] = (double)(1268462009U);
    pr[2] = (double)(145696283U);
    pr[3] = (double)(2034478074U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static mxArray *sf_get_sim_state_info_c4_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c4_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc4_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           4,
           1,
           1,
           2,
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
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"u",0,(MexFcnForType)c4_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 9;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"y",0,(MexFcnForType)c4_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,40);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c4_u)[9];
          real_T (*c4_y)[9];
          c4_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_u = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_large_snakeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c4_large_snake((SFc4_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c4_large_snake((SFc4_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_large_snake(void *chartInstanceVar)
{
  enable_c4_large_snake((SFc4_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_large_snake(void *chartInstanceVar)
{
  disable_c4_large_snake((SFc4_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_large_snake(void *chartInstanceVar)
{
  sf_c4_large_snake((SFc4_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c4_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c4_large_snake((SFc4_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c4_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_large_snake
    ((SFc4_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c4_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c4_large_snake(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_large_snake((SFc4_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c4_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_large_snake(S);
}

static void sf_opaque_set_sim_state_c4_large_snake(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_large_snake(S, st);
}

static void sf_opaque_terminate_c4_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_large_snake((SFc4_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_large_snake((SFc4_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c4_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",4,1);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",4,1);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(4236347380U));
  ssSetChecksum1(S,(4110996974U));
  ssSetChecksum2(S,(3217823891U));
  ssSetChecksum3(S,(508688570U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_large_snake(SimStruct *S)
{
  SFc4_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc4_large_snakeInstanceStruct *)malloc(sizeof
    (SFc4_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_large_snake;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c4_large_snake;
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

void c4_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
