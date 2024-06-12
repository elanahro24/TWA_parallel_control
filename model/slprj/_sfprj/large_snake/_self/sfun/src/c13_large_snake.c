/* Include files */

#include "blascompat32.h"
#include "large_snake_sfun.h"
#include "c13_large_snake.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "large_snake_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c13_debug_family_names[5] = { "nargin", "nargout", "trig",
  "trig_history", "enable" };

/* Function Declarations */
static void initialize_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance);
static void initialize_params_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance);
static void enable_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance);
static void disable_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance);
static void c13_update_debugger_state_c13_large_snake
  (SFc13_large_snakeInstanceStruct *chartInstance);
static void ext_mode_exec_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c13_large_snake
  (SFc13_large_snakeInstanceStruct *chartInstance);
static void set_sim_state_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance, const mxArray *c13_st);
static void finalize_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance);
static void sf_c13_large_snake(SFc13_large_snakeInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshall(void *chartInstanceVoid, void *c13_u);
static const mxArray *c13_b_sf_marshall(void *chartInstanceVoid, void *c13_u);
static real_T c13_emlrt_marshallIn(SFc13_large_snakeInstanceStruct
  *chartInstance, const mxArray *c13_enable, const char_T *c13_name);
static uint8_T c13_b_emlrt_marshallIn(SFc13_large_snakeInstanceStruct
  *chartInstance, const mxArray *c13_is_active_c13_large_snake, const char_T
  *c13_name);
static void init_dsm_address_info(SFc13_large_snakeInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance)
{
  uint8_T *c13_is_active_c13_large_snake;
  c13_is_active_c13_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c13_is_active_c13_large_snake = 0U;
}

static void initialize_params_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance)
{
}

static void enable_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c13_update_debugger_state_c13_large_snake
  (SFc13_large_snakeInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance)
{
  c13_update_debugger_state_c13_large_snake(chartInstance);
}

static const mxArray *get_sim_state_c13_large_snake
  (SFc13_large_snakeInstanceStruct *chartInstance)
{
  const mxArray *c13_st = NULL;
  const mxArray *c13_y = NULL;
  real_T c13_hoistedGlobal;
  real_T c13_u;
  const mxArray *c13_b_y = NULL;
  uint8_T c13_b_hoistedGlobal;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  real_T *c13_enable;
  uint8_T *c13_is_active_c13_large_snake;
  c13_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_is_active_c13_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(2));
  c13_hoistedGlobal = *c13_enable;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = *c13_is_active_c13_large_snake;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c13_y, 1, c13_c_y);
  sf_mex_assign(&c13_st, c13_y);
  return c13_st;
}

static void set_sim_state_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  boolean_T *c13_doneDoubleBufferReInit;
  real_T *c13_enable;
  uint8_T *c13_is_active_c13_large_snake;
  c13_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_is_active_c13_large_snake = (uint8_T *)ssGetDWork(chartInstance->S, 2);
  c13_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 1);
  *c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  *c13_enable = c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c13_u, 0)), "enable");
  *c13_is_active_c13_large_snake = c13_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 1)),
    "is_active_c13_large_snake");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_large_snake(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_large_snake(SFc13_large_snakeInstanceStruct
  *chartInstance)
{
}

static void sf_c13_large_snake(SFc13_large_snakeInstanceStruct *chartInstance)
{
  int32_T c13_previousEvent;
  real_T c13_hoistedGlobal;
  real_T c13_b_hoistedGlobal;
  real_T c13_trig;
  real_T c13_trig_history;
  uint32_T c13_debug_family_var_map[5];
  real_T c13_nargin = 2.0;
  real_T c13_nargout = 1.0;
  real_T c13_enable;
  real_T *c13_b_trig;
  real_T *c13_b_enable;
  real_T *c13_b_trig_history;
  c13_b_trig_history = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c13_b_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_trig = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,12);
  _SFD_DATA_RANGE_CHECK(*c13_b_trig, 0U);
  _SFD_DATA_RANGE_CHECK(*c13_b_enable, 1U);
  _SFD_DATA_RANGE_CHECK(*c13_b_trig_history, 2U);
  c13_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,12);
  c13_hoistedGlobal = *c13_b_trig;
  c13_b_hoistedGlobal = *c13_b_trig_history;
  c13_trig = c13_hoistedGlobal;
  c13_trig_history = c13_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c13_debug_family_names,
    c13_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c13_nargin, c13_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c13_nargout, c13_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c13_trig, c13_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c13_trig_history, c13_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c13_enable, c13_sf_marshall, 4U);
  CV_EML_FCN(0, 0);

  /* %  This func is just to detect a rising trigger */
  /*    Once this rising trigger detected, this manual enable will be locked */
  /*    until mode change */
  _SFD_EML_CALL(0,6);
  if (CV_EML_IF(0, 0, c13_trig_history == 0.0)) {
    _SFD_EML_CALL(0,7);
    if (CV_EML_IF(0, 1, c13_trig == 0.0)) {
      _SFD_EML_CALL(0,8);
      c13_enable = 0.0;
    } else {
      _SFD_EML_CALL(0,10);
      c13_enable = 1.0;
    }
  } else {
    _SFD_EML_CALL(0,13);
    c13_enable = 1.0;
  }

  _SFD_EML_CALL(0,-13);
  sf_debug_symbol_scope_pop();
  *c13_b_enable = c13_enable;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
  _sfEvent_ = c13_previousEvent;
  sf_debug_check_for_state_inconsistency(_large_snakeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshall(void *chartInstanceVoid, void *c13_u)
{
  const mxArray *c13_y = NULL;
  real_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  SFc13_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc13_large_snakeInstanceStruct *)chartInstanceVoid;
  c13_y = NULL;
  c13_b_u = *((real_T *)c13_u);
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

const mxArray *sf_c13_large_snake_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_ResolvedFunctionInfo c13_info[1];
  c13_ResolvedFunctionInfo (*c13_b_info)[1];
  const mxArray *c13_m0 = NULL;
  int32_T c13_i0;
  c13_ResolvedFunctionInfo *c13_r0;
  c13_nameCaptureInfo = NULL;
  c13_b_info = (c13_ResolvedFunctionInfo (*)[1])c13_info;
  (*c13_b_info)[0].context = "";
  (*c13_b_info)[0].name = "eq";
  (*c13_b_info)[0].dominantType = "double";
  (*c13_b_info)[0].resolved = "[B]eq";
  (*c13_b_info)[0].fileLength = 0U;
  (*c13_b_info)[0].fileTime1 = 0U;
  (*c13_b_info)[0].fileTime2 = 0U;
  sf_mex_assign(&c13_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for (c13_i0 = 0; c13_i0 < 1; c13_i0 = c13_i0 + 1) {
    c13_r0 = &c13_info[c13_i0];
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->context)), "context"
                    , "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->name)), "name",
                    "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      c13_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->resolved)),
                    "resolved", "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c13_i0);
  }

  sf_mex_assign(&c13_nameCaptureInfo, c13_m0);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_b_sf_marshall(void *chartInstanceVoid, void *c13_u)
{
  const mxArray *c13_y = NULL;
  boolean_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  SFc13_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc13_large_snakeInstanceStruct *)chartInstanceVoid;
  c13_y = NULL;
  c13_b_u = *((boolean_T *)c13_u);
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

static real_T c13_emlrt_marshallIn(SFc13_large_snakeInstanceStruct
  *chartInstance, const mxArray *c13_enable, const char_T *c13_name
  )
{
  real_T c13_y;
  real_T c13_d0;
  sf_mex_import(c13_name, sf_mex_dup(c13_enable), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_enable);
  return c13_y;
}

static uint8_T c13_b_emlrt_marshallIn(SFc13_large_snakeInstanceStruct
  *chartInstance, const mxArray *c13_is_active_c13_large_snake,
  const char_T *c13_name)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_name, sf_mex_dup(c13_is_active_c13_large_snake), &c13_u0, 1,
                3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_is_active_c13_large_snake);
  return c13_y;
}

static void init_dsm_address_info(SFc13_large_snakeInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c13_large_snake_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3408859935U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3909217520U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1746813071U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(873242334U);
}

mxArray *sf_c13_large_snake_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2980927084U);
    pr[1] = (double)(1087622581U);
    pr[2] = (double)(4112635134U);
    pr[3] = (double)(2564210954U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static mxArray *sf_get_sim_state_info_c13_large_snake(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"enable\",},{M[8],M[0],T\"is_active_c13_large_snake\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_large_snake_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_large_snakeInstanceStruct *chartInstance;
    chartInstance = (SFc13_large_snakeInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_large_snakeMachineNumber_,
           13,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"trig",0,
                              (MexFcnForType)c13_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"enable",
                              0,(MexFcnForType)c13_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "trig_history",0,(MexFcnForType)c13_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,301);
        _SFD_CV_INIT_EML_IF(0,0,190,208,277,301);
        _SFD_CV_INIT_EML_IF(0,1,213,223,246,276);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c13_trig;
          real_T *c13_enable;
          real_T *c13_trig_history;
          c13_trig_history = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c13_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c13_trig = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_trig);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_enable);
          _SFD_SET_DATA_VALUE_PTR(2U, c13_trig_history);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_large_snakeMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c13_large_snake(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_large_snakeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_large_snake((SFc13_large_snakeInstanceStruct*)
    chartInstanceVar);
  initialize_c13_large_snake((SFc13_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c13_large_snake(void *chartInstanceVar)
{
  enable_c13_large_snake((SFc13_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c13_large_snake(void *chartInstanceVar)
{
  disable_c13_large_snake((SFc13_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c13_large_snake(void *chartInstanceVar)
{
  sf_c13_large_snake((SFc13_large_snakeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c13_large_snake(void *chartInstanceVar)
{
  ext_mode_exec_c13_large_snake((SFc13_large_snakeInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c13_large_snake(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_large_snake
    ((SFc13_large_snakeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c13_large_snake();/* state var info */
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

static void sf_internal_set_sim_state_c13_large_snake(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_large_snake();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_large_snake((SFc13_large_snakeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c13_large_snake(SimStruct* S)
{
  return sf_internal_get_sim_state_c13_large_snake(S);
}

static void sf_opaque_set_sim_state_c13_large_snake(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c13_large_snake(S, st);
}

static void sf_opaque_terminate_c13_large_snake(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_large_snakeInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c13_large_snake((SFc13_large_snakeInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_large_snake(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_large_snake((SFc13_large_snakeInstanceStruct*)
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

static void mdlSetWorkWidths_c13_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("large_snake","large_snake",13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("large_snake","large_snake",13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("large_snake",
      "large_snake",13,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"large_snake","large_snake",13,2);
      sf_mark_chart_reusable_outputs(S,"large_snake","large_snake",13,1);
    }

    sf_set_rtw_dwork_info(S,"large_snake","large_snake",13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1885227974U));
  ssSetChecksum1(S,(1322491768U));
  ssSetChecksum2(S,(3491330836U));
  ssSetChecksum3(S,(145755926U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c13_large_snake(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "large_snake", "large_snake",13);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_large_snake(SimStruct *S)
{
  SFc13_large_snakeInstanceStruct *chartInstance;
  chartInstance = (SFc13_large_snakeInstanceStruct *)malloc(sizeof
    (SFc13_large_snakeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_large_snakeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c13_large_snake;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_large_snake;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c13_large_snake;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_large_snake;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_large_snake;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c13_large_snake;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c13_large_snake;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_large_snake;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_large_snake;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_large_snake;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c13_large_snake;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c13_large_snake;
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

void c13_large_snake_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_large_snake(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_large_snake(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_large_snake(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_large_snake_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
