/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c8_large_snake.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c8_debug_family_names[8] = { "nargin", "nargout", "tin", "dt",
  "DelayTime", "yout", "finish", "tout" };

/* Function Declarations */
static void initialize_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance);
static void enable_c8_large_snake(SFc8_large_snakeInstanceStruct *chartInstance);
static void disable_c8_large_snake(SFc8_large_snakeInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_large_snake
  (SFc8_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c8_large_snake
  (SFc8_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance, const mxArray *c8_st);
static void finalize_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance);
static void sf_c8_large_snake(SFc8_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_b_sf_marshall(void *chartInstanceVoid, void *c8_u);
static real_T c8_emlrt_marshallIn(SFc8_large_snakeInstanceStruct *chartInstance,
  const mxArray *c8_finish, const char_T *c8_name);
static uint8_T c8_b_emlrt_marshallIn(SFc8_large_snakeInstanceStruct
  *chartInstance, const mxArray *c8_is_active_c8_large_snake, const char_T
  *c8_name);
static void init_dsm_address_info(SFc8_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c8_is_active_c8_large_snake;
  c8_is_active_c8_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c8_is_active_c8_large_snake = 0U;
}

static void initialize_params_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c8_large_snake(SFc8_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_large_snake(SFc8_large_snakeInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_large_snake
  (SFc8_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance)
{
  c8_update_debugger_state_c8_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c8_large_snake
  (SFc8_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c8_st = NULL;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  real_T c8_b_hoistedGlobal;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T c8_c_hoistedGlobal;
  real_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  uint8_T c8_d_hoistedGlobal;
  uint8_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  real_T *c8_finish;
  real_T *c8_tout;
  real_T *c8_yout;
  uint8_T *c8_is_active_c8_large_snake;
  c8_tout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_finish = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_yout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_is_active_c8_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(4));
  c8_hoistedGlobal = *c8_finish;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *c8_tout;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = *c8_yout;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = *c8_is_active_c8_large_snake;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 3, c8_e_y);
  sf_mex_assign(&c8_st, c8_y);
  return c8_st;
}

static void set_sim_state_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  boolean_T *c8_doneDoubleBufferReInit;
  real_T *c8_finish;
  real_T *c8_tout;
  real_T *c8_yout;
  uint8_T *c8_is_active_c8_large_snake;
  c8_tout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_finish = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_yout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_is_active_c8_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c8_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_finish = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    0)), "finish");
  *c8_tout = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    1)), "tout");
  *c8_yout = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    2)), "yout");
  *c8_is_active_c8_large_snake = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 3)), "is_active_c8_large_snake");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_large_snake(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_large_snake(SFc8_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c8_large_snake(SFc8_large_snakeInstanceStruct *chartInstance)
{
  int32_T c8_previousEvent;
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_c_hoistedGlobal;
  real_T c8_tin;
  real_T c8_dt;
  real_T c8_DelayTime;
  uint32_T c8_debug_family_var_map[8];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 3.0;
  real_T c8_yout;
  real_T c8_finish;
  real_T c8_tout;
  real_T *c8_b_tin;
  real_T *c8_b_yout;
  real_T *c8_b_finish;
  real_T *c8_b_tout;
  real_T *c8_b_dt;
  real_T *c8_b_DelayTime;
  c8_b_DelayTime = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_tout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_b_finish = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_b_yout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_tin = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,7);
  _SFD_DATA_RANGE_CHECK(*c8_b_tin, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_b_yout, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_b_finish, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_b_tout, 3U);
  _SFD_DATA_RANGE_CHECK(*c8_b_dt, 4U);
  _SFD_DATA_RANGE_CHECK(*c8_b_DelayTime, 5U);
  c8_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,7);
  c8_hoistedGlobal = *c8_b_tin;
  c8_b_hoistedGlobal = *c8_b_dt;
  c8_c_hoistedGlobal = *c8_b_DelayTime;
  c8_tin = c8_hoistedGlobal;
  c8_dt = c8_b_hoistedGlobal;
  c8_DelayTime = c8_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c8_tin, c8_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c8_dt, c8_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c8_DelayTime, c8_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c8_yout, c8_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c8_finish, c8_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c8_tout, c8_sf_marshall, 7U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  if (CV_EML_IF(0, 0, c8_tin <= c8_DelayTime)) {
    _SFD_EML_CALL(0,4);
    c8_yout = 1.0;
    _SFD_EML_CALL(0,5);
    c8_finish = 0.0;
    _SFD_EML_CALL(0,6);
    c8_tout = c8_tin + c8_dt;
  } else {
    _SFD_EML_CALL(0,8);
    c8_yout = 0.0;
    _SFD_EML_CALL(0,9);
    c8_tout = c8_tin;
    _SFD_EML_CALL(0,10);
    c8_finish = 1.0;
  }

  _SFD_EML_CALL(0,-10);
  sf_debug_symbol_scope_pop();
  *c8_b_yout = c8_yout;
  *c8_b_finish = c8_finish;
  *c8_b_tout = c8_tout;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
  _sfEvent_ = c8_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  real_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc8_large_snakeInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  c8_b_u = *((real_T *)c8_u);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

const mxArray *sf_c8_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_ResolvedFunctionInfo c8_info[2];
  c8_ResolvedFunctionInfo (*c8_b_info)[2];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i0;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_b_info = (c8_ResolvedFunctionInfo (*)[2])c8_info;
  (*c8_b_info)[0].context = "";
  (*c8_b_info)[0].name = "le";
  (*c8_b_info)[0].dominantType = "double";
  (*c8_b_info)[0].resolved = "[B]le";
  (*c8_b_info)[0].fileLength = 0U;
  (*c8_b_info)[0].fileTime1 = 0U;
  (*c8_b_info)[0].fileTime2 = 0U;
  (*c8_b_info)[1].context = "";
  (*c8_b_info)[1].name = "plus";
  (*c8_b_info)[1].dominantType = "double";
  (*c8_b_info)[1].resolved = "[B]plus";
  (*c8_b_info)[1].fileLength = 0U;
  (*c8_b_info)[1].fileTime1 = 0U;
  (*c8_b_info)[1].fileTime2 = 0U;
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for (c8_i0 = 0; c8_i0 < 2; c8_i0 = c8_i0 + 1) {
    c8_r0 = &c8_info[c8_i0];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context",
                    "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name",
                    "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c8_i0);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_b_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  boolean_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc8_large_snakeInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  c8_b_u = *((boolean_T *)c8_u);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static real_T c8_emlrt_marshallIn(SFc8_large_snakeInstanceStruct *chartInstance,
  const mxArray *c8_finish, const char_T *c8_name)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_name, sf_mex_dup(c8_finish), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_finish);
  return c8_y;
}

static uint8_T c8_b_emlrt_marshallIn(SFc8_large_snakeInstanceStruct
  *chartInstance, const mxArray *c8_is_active_c8_large_snake,
  const char_T *c8_name)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_name, sf_mex_dup(c8_is_active_c8_large_snake), &c8_u0, 1, 3,
                0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_is_active_c8_large_snake);
  return c8_y;
}

static void init_dsm_address_info(SFc8_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1247971618U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4113976710U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3189074126U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(114352275U);
}

mxArray *sf_c8_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1199529556U);
    pr[1] = (double)(3603907308U);
    pr[2] = (double)(608022758U);
    pr[3] = (double)(3594889403U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c8_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"finish\",},{M[1],M[8],T\"tout\",},{M[1],M[7],T\"yout\",},{M[8],M[0],T\"is_active_c8_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc8_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tin",0,
                              (MexFcnForType)c8_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"yout",0,
                              (MexFcnForType)c8_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"finish",
                              0,(MexFcnForType)c8_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"tout",0,
                              (MexFcnForType)c8_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dt",0,
                              (MexFcnForType)c8_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "DelayTime",0,(MexFcnForType)c8_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,177);
        _SFD_CV_INIT_EML_IF(0,0,64,81,127,177);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c8_tin;
          real_T *c8_yout;
          real_T *c8_finish;
          real_T *c8_tout;
          real_T *c8_dt;
          real_T *c8_DelayTime;
          c8_DelayTime = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c8_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_tout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c8_finish = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c8_yout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c8_tin = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_tin);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_yout);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_finish);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_tout);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_dt);
          _SFD_SET_DATA_VALUE_PTR(5U, c8_DelayTime);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c8_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_large_snakeInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c8_large_snake((SFc8_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c8_large_snake((SFc8_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_large_snake(void *chartInstanceVar)
{
  enable_c8_large_snake((SFc8_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_large_snake(void *chartInstanceVar)
{
  disable_c8_large_snake((SFc8_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_large_snake(void *chartInstanceVar)
{
  sf_c8_large_snake((SFc8_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c8_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c8_large_snake((SFc8_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c8_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_large_snake
    ((SFc8_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c8_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c8_large_snake(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_large_snake((SFc8_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c8_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_large_snake(S);
}

static void sf_opaque_set_sim_state_c8_large_snake(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c8_large_snake(S, st);
}

static void sf_opaque_terminate_c8_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_large_snake((SFc8_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_large_snake((SFc8_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c8_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",8,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",8,3);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",8,3);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1830612743U));
  ssSetChecksum1(S,(676436818U));
  ssSetChecksum2(S,(2763614329U));
  ssSetChecksum3(S,(2220548489U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_large_snake(SimStruct *S)
{
  SFc8_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc8_large_snakeInstanceStruct *)malloc(sizeof
    (SFc8_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_large_snake;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c8_large_snake;
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

void c8_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
