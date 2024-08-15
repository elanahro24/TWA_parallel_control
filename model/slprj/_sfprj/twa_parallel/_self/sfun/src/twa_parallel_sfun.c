/* Include files */

#include "twa_parallel_sfun.h"
#include "c5_twa_parallel.h"
#include "c22_twa_parallel.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _twa_parallelMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void twa_parallel_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void twa_parallel_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_twa_parallel_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==5) {
    c5_twa_parallel_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_twa_parallel_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_twa_parallel_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2469026389U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1838723847U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(477532326U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1225643081U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3746993662U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1243141828U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(360922113U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2615001553U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 5:
        {
          extern void sf_c5_twa_parallel_get_check_sum(mxArray *plhs[]);
          sf_c5_twa_parallel_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_twa_parallel_get_check_sum(mxArray *plhs[]);
          sf_c22_twa_parallel_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3514052935U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2758863276U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3270605731U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3401986219U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1684293017U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(276678130U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3767360834U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4000222641U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_twa_parallel_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        extern mxArray *sf_c5_twa_parallel_get_autoinheritance_info(void);
        plhs[0] = sf_c5_twa_parallel_get_autoinheritance_info();
        break;
      }

     case 22:
      {
        extern mxArray *sf_c22_twa_parallel_get_autoinheritance_info(void);
        plhs[0] = sf_c22_twa_parallel_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_twa_parallel_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        extern const mxArray *sf_c5_twa_parallel_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_twa_parallel_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_twa_parallel_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_twa_parallel_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void twa_parallel_debug_initialize(void)
{
  _twa_parallelMachineNumber_ = sf_debug_initialize_machine("twa_parallel",
    "sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(_twa_parallelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_twa_parallelMachineNumber_,0);
}

void twa_parallel_register_exported_symbols(SimStruct* S)
{
}
