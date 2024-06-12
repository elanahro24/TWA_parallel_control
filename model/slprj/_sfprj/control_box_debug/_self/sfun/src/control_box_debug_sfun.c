/* Include files */

#include "control_box_debug_sfun.h"
#include "c22_control_box_debug.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _control_box_debugMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void control_box_debug_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void control_box_debug_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_control_box_debug_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==22) {
    c22_control_box_debug_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_control_box_debug_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(638786768U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1171686912U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4490707U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(896666868U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3884373771U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1700096662U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3713596182U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(131752611U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 22:
        {
          extern void sf_c22_control_box_debug_get_check_sum(mxArray *plhs[]);
          sf_c22_control_box_debug_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3356190608U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(834038227U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(586987681U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2256529539U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_control_box_debug_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 22:
      {
        extern mxArray *sf_c22_control_box_debug_get_autoinheritance_info(void);
        plhs[0] = sf_c22_control_box_debug_get_autoinheritance_info();
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

unsigned int sf_control_box_debug_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 22:
      {
        extern const mxArray
          *sf_c22_control_box_debug_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_control_box_debug_get_eml_resolved_functions_info();
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

void control_box_debug_debug_initialize(void)
{
  _control_box_debugMachineNumber_ = sf_debug_initialize_machine(
    "control_box_debug","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_control_box_debugMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_control_box_debugMachineNumber_,0);
}

void control_box_debug_register_exported_symbols(SimStruct* S)
{
}
