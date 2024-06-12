/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c12_large_snake.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c12_debug_family_names[11] = { "q10_0", "UDP_info_mm",
  "UDP_t0_mm", "UDP_error", "nargin", "nargout", "px_ratio", "q10_set",
  "UDP_info", "UDP_t0", "q_10" };

/* Function Declarations */
static void initialize_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance);
static void enable_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance);
static void disable_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance);
static void c12_update_debugger_state_c12_large_snake
  (SFc12_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c12_large_snake
  (SFc12_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance, const mxArray *c12_st);
static void finalize_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance);
static void sf_c12_large_snake(SFc12_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshall(void *chartInstanceVoid, void *c12_u);
static const mxArray *c12_b_sf_marshall(void *chartInstanceVoid, void *c12_u);
static real_T c12_emlrt_marshallIn(SFc12_large_snakeInstanceStruct
  *chartInstance, const mxArray *c12_q_10, const char_T *c12_name);
static uint8_T c12_b_emlrt_marshallIn(SFc12_large_snakeInstanceStruct
  *chartInstance, const mxArray *c12_is_active_c12_large_snake, const char_T
  *c12_name);
static void init_dsm_address_info(SFc12_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c12_is_active_c12_large_snake;
  c12_is_active_c12_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c12_is_active_c12_large_snake = 0U;
}

static void initialize_params_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_large_snake
  (SFc12_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance)
{
  c12_update_debugger_state_c12_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c12_large_snake
  (SFc12_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c12_st = NULL;
  const mxArray *c12_y = NULL;
  real_T c12_hoistedGlobal;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  uint8_T c12_b_hoistedGlobal;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T *c12_q_10;
  uint8_T *c12_is_active_c12_large_snake;
  c12_q_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_is_active_c12_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(2));
  c12_hoistedGlobal = *c12_q_10;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = *c12_is_active_c12_large_snake;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y);
  return c12_st;
}

static void set_sim_state_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  boolean_T *c12_doneDoubleBufferReInit;
  real_T *c12_q_10;
  uint8_T *c12_is_active_c12_large_snake;
  c12_q_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_is_active_c12_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c12_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  *c12_q_10 = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c12_u, 0)), "q_10");
  *c12_is_active_c12_large_snake = c12_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 1)),
    "is_active_c12_large_snake");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_large_snake(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_large_snake(SFc12_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c12_large_snake(SFc12_large_snakeInstanceStruct *chartInstance)
{
  int32_T c12_previousEvent;
  real_T c12_hoistedGlobal;
  real_T c12_b_hoistedGlobal;
  real_T c12_c_hoistedGlobal;
  real_T c12_d_hoistedGlobal;
  real_T c12_px_ratio;
  real_T c12_q10_set;
  real_T c12_UDP_info;
  real_T c12_UDP_t0;
  uint32_T c12_debug_family_var_map[11];
  real_T c12_q10_0;
  real_T c12_UDP_info_mm;
  real_T c12_UDP_t0_mm;
  real_T c12_UDP_error;
  real_T c12_nargin = 4.0;
  real_T c12_nargout = 1.0;
  real_T c12_q_10;
  real_T c12_a;
  real_T c12_b;
  real_T c12_b_a;
  real_T c12_b_b;
  real_T *c12_b_px_ratio;
  real_T *c12_b_q10_set;
  real_T *c12_b_UDP_info;
  real_T *c12_b_q_10;
  real_T *c12_b_UDP_t0;
  c12_b_UDP_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c12_b_q_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_b_UDP_info = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c12_b_q10_set = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c12_b_px_ratio = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,11);
  _SFD_DATA_RANGE_CHECK(*c12_b_px_ratio, 0U);
  _SFD_DATA_RANGE_CHECK(*c12_b_q10_set, 1U);
  _SFD_DATA_RANGE_CHECK(*c12_b_UDP_info, 2U);
  _SFD_DATA_RANGE_CHECK(*c12_b_q_10, 3U);
  _SFD_DATA_RANGE_CHECK(*c12_b_UDP_t0, 4U);
  c12_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,11);
  c12_hoistedGlobal = *c12_b_px_ratio;
  c12_b_hoistedGlobal = *c12_b_q10_set;
  c12_c_hoistedGlobal = *c12_b_UDP_info;
  c12_d_hoistedGlobal = *c12_b_UDP_t0;
  c12_px_ratio = c12_hoistedGlobal;
  c12_q10_set = c12_b_hoistedGlobal;
  c12_UDP_info = c12_c_hoistedGlobal;
  c12_UDP_t0 = c12_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c12_debug_family_names,
    c12_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c12_q10_0, c12_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c12_UDP_info_mm, c12_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c12_UDP_t0_mm, c12_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c12_UDP_error, c12_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c12_nargin, c12_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c12_nargout, c12_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c12_px_ratio, c12_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c12_q10_set, c12_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c12_UDP_info, c12_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c12_UDP_t0, c12_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c12_q_10, c12_sf_marshall, 10U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c12_q10_0 = 0.0;
  _SFD_EML_CALL(0,4);
  c12_a = c12_UDP_info;
  c12_b = c12_px_ratio;
  c12_UDP_info_mm = c12_a * c12_b;
  _SFD_EML_CALL(0,5);
  c12_b_a = c12_UDP_t0;
  c12_b_b = c12_px_ratio;
  c12_UDP_t0_mm = c12_b_a * c12_b_b;
  _SFD_EML_CALL(0,6);
  c12_UDP_error = c12_UDP_t0_mm - c12_UDP_info_mm;
  _SFD_EML_CALL(0,7);
  c12_q_10 = c12_q10_0 - c12_UDP_error;
  _SFD_EML_CALL(0,-7);
  sf_debug_symbol_scope_pop();
  *c12_b_q_10 = c12_q_10;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
  _sfEvent_ = c12_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshall(void *chartInstanceVoid, void *c12_u)
{
  const mxArray *c12_y = NULL;
  real_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  SFc12_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc12_large_snakeInstanceStruct *)chartInstanceVoid;
  c12_y = NULL;
  c12_b_u = *((real_T *)c12_u);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

const mxArray *sf_c12_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_ResolvedFunctionInfo c12_info[12];
  c12_ResolvedFunctionInfo (*c12_b_info)[12];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i0;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_b_info = (c12_ResolvedFunctionInfo (*)[12])c12_info;
  (*c12_b_info)[0].context = "";
  (*c12_b_info)[0].name = "mtimes";
  (*c12_b_info)[0].dominantType = "double";
  (*c12_b_info)[0].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[0].fileLength = 3425U;
  (*c12_b_info)[0].fileTime1 = 1250697966U;
  (*c12_b_info)[0].fileTime2 = 0U;
  (*c12_b_info)[1].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[1].name = "nargin";
  (*c12_b_info)[1].dominantType = "";
  (*c12_b_info)[1].resolved = "[B]nargin";
  (*c12_b_info)[1].fileLength = 0U;
  (*c12_b_info)[1].fileTime1 = 0U;
  (*c12_b_info)[1].fileTime2 = 0U;
  (*c12_b_info)[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[2].name = "gt";
  (*c12_b_info)[2].dominantType = "double";
  (*c12_b_info)[2].resolved = "[B]gt";
  (*c12_b_info)[2].fileLength = 0U;
  (*c12_b_info)[2].fileTime1 = 0U;
  (*c12_b_info)[2].fileTime2 = 0U;
  (*c12_b_info)[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[3].name = "isa";
  (*c12_b_info)[3].dominantType = "double";
  (*c12_b_info)[3].resolved = "[B]isa";
  (*c12_b_info)[3].fileLength = 0U;
  (*c12_b_info)[3].fileTime1 = 0U;
  (*c12_b_info)[3].fileTime2 = 0U;
  (*c12_b_info)[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[4].name = "isinteger";
  (*c12_b_info)[4].dominantType = "double";
  (*c12_b_info)[4].resolved = "[B]isinteger";
  (*c12_b_info)[4].fileLength = 0U;
  (*c12_b_info)[4].fileTime1 = 0U;
  (*c12_b_info)[4].fileTime2 = 0U;
  (*c12_b_info)[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[5].name = "isscalar";
  (*c12_b_info)[5].dominantType = "double";
  (*c12_b_info)[5].resolved = "[B]isscalar";
  (*c12_b_info)[5].fileLength = 0U;
  (*c12_b_info)[5].fileTime1 = 0U;
  (*c12_b_info)[5].fileTime2 = 0U;
  (*c12_b_info)[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[6].name = "strcmp";
  (*c12_b_info)[6].dominantType = "char";
  (*c12_b_info)[6].resolved = "[B]strcmp";
  (*c12_b_info)[6].fileLength = 0U;
  (*c12_b_info)[6].fileTime1 = 0U;
  (*c12_b_info)[6].fileTime2 = 0U;
  (*c12_b_info)[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[7].name = "size";
  (*c12_b_info)[7].dominantType = "double";
  (*c12_b_info)[7].resolved = "[B]size";
  (*c12_b_info)[7].fileLength = 0U;
  (*c12_b_info)[7].fileTime1 = 0U;
  (*c12_b_info)[7].fileTime2 = 0U;
  (*c12_b_info)[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[8].name = "eq";
  (*c12_b_info)[8].dominantType = "double";
  (*c12_b_info)[8].resolved = "[B]eq";
  (*c12_b_info)[8].fileLength = 0U;
  (*c12_b_info)[8].fileTime1 = 0U;
  (*c12_b_info)[8].fileTime2 = 0U;
  (*c12_b_info)[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[9].name = "class";
  (*c12_b_info)[9].dominantType = "double";
  (*c12_b_info)[9].resolved = "[B]class";
  (*c12_b_info)[9].fileLength = 0U;
  (*c12_b_info)[9].fileTime1 = 0U;
  (*c12_b_info)[9].fileTime2 = 0U;
  (*c12_b_info)[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[10].name = "not";
  (*c12_b_info)[10].dominantType = "logical";
  (*c12_b_info)[10].resolved = "[B]not";
  (*c12_b_info)[10].fileLength = 0U;
  (*c12_b_info)[10].fileTime1 = 0U;
  (*c12_b_info)[10].fileTime2 = 0U;
  (*c12_b_info)[11].context = "";
  (*c12_b_info)[11].name = "minus";
  (*c12_b_info)[11].dominantType = "double";
  (*c12_b_info)[11].resolved = "[B]minus";
  (*c12_b_info)[11].fileLength = 0U;
  (*c12_b_info)[11].fileTime1 = 0U;
  (*c12_b_info)[11].fileTime2 = 0U;
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12));
  for (c12_i0 = 0; c12_i0 < 12; c12_i0 = c12_i0 + 1) {
    c12_r0 = &c12_info[c12_i0];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context"
                    , "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name",
                    "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)),
                    "resolved", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c12_i0);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_b_sf_marshall(void *chartInstanceVoid, void *c12_u)
{
  const mxArray *c12_y = NULL;
  boolean_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  SFc12_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc12_large_snakeInstanceStruct *)chartInstanceVoid;
  c12_y = NULL;
  c12_b_u = *((boolean_T *)c12_u);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

static real_T c12_emlrt_marshallIn(SFc12_large_snakeInstanceStruct
  *chartInstance, const mxArray *c12_q_10, const char_T *c12_name)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_name, sf_mex_dup(c12_q_10), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_q_10);
  return c12_y;
}

static uint8_T c12_b_emlrt_marshallIn(SFc12_large_snakeInstanceStruct
  *chartInstance, const mxArray *c12_is_active_c12_large_snake,
  const char_T *c12_name)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_name, sf_mex_dup(c12_is_active_c12_large_snake), &c12_u0, 1,
                3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_is_active_c12_large_snake);
  return c12_y;
}

static void init_dsm_address_info(SFc12_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c12_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3542904581U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4220207767U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2912714560U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(164046084U);
}

mxArray *sf_c12_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1476725925U);
    pr[1] = (double)(1034794053U);
    pr[2] = (double)(4208870189U);
    pr[3] = (double)(2917221903U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c12_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"q_10\",},{M[8],M[0],T\"is_active_c12_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc12_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           12,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "px_ratio",0,(MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"q10_set",
                              0,(MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "UDP_info",0,(MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"q_10",0,
                              (MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"UDP_t0",
                              0,(MexFcnForType)c12_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,200);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c12_px_ratio;
          real_T *c12_q10_set;
          real_T *c12_UDP_info;
          real_T *c12_q_10;
          real_T *c12_UDP_t0;
          c12_UDP_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c12_q_10 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c12_UDP_info = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c12_q10_set = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c12_px_ratio = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_px_ratio);
          _SFD_SET_DATA_VALUE_PTR(1U, c12_q10_set);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_UDP_info);
          _SFD_SET_DATA_VALUE_PTR(3U, c12_q_10);
          _SFD_SET_DATA_VALUE_PTR(4U, c12_UDP_t0);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c12_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_large_snakeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_large_snake((SFc12_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c12_large_snake((SFc12_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_large_snake(void *chartInstanceVar)
{
  enable_c12_large_snake((SFc12_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_large_snake(void *chartInstanceVar)
{
  disable_c12_large_snake((SFc12_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_large_snake(void *chartInstanceVar)
{
  sf_c12_large_snake((SFc12_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c12_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c12_large_snake((SFc12_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c12_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_large_snake
    ((SFc12_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c12_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c12_large_snake(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_large_snake((SFc12_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c12_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_large_snake(S);
}

static void sf_opaque_set_sim_state_c12_large_snake(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c12_large_snake(S, st);
}

static void sf_opaque_terminate_c12_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c12_large_snake((SFc12_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_large_snake((SFc12_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c12_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",12,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",12,4);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",12,1);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2647560333U));
  ssSetChecksum1(S,(2795310727U));
  ssSetChecksum2(S,(605031412U));
  ssSetChecksum3(S,(642150776U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c12_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",12);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_large_snake(SimStruct *S)
{
  SFc12_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc12_large_snakeInstanceStruct *)malloc(sizeof
    (SFc12_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_large_snake;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c12_large_snake;
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

void c12_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
