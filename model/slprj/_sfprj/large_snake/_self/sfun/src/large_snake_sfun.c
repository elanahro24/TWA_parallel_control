/* Include files */

#include "large_snake_sfun.h"
#include "c1_large_snake.h"
#include "c2_large_snake.h"
#include "c3_large_snake.h"
#include "c4_large_snake.h"
#include "c5_large_snake.h"
#include "c6_large_snake.h"
#include "c7_large_snake.h"
#include "c8_large_snake.h"
#include "c9_large_snake.h"
#include "c10_large_snake.h"
#include "c11_large_snake.h"
#include "c13_large_snake.h"
#include "c15_large_snake.h"
#include "c22_large_snake.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _large_snakeMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void large_snake_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void large_snake_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_large_snake_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_large_snake_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_large_snake_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3028493769U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2305170328U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2291039225U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2039229886U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3743695949U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1425710791U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1799759365U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2136622931U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c1_large_snake_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c2_large_snake_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c3_large_snake_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c4_large_snake_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c5_large_snake_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c6_large_snake_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c7_large_snake_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c8_large_snake_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c9_large_snake_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c10_large_snake_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c11_large_snake_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c13_large_snake_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c15_large_snake_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_large_snake_get_check_sum(mxArray *plhs[]);
          sf_c22_large_snake_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4030030584U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3076521570U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(648629333U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2204856764U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_large_snake_autoinheritance_info( int nlhs, mxArray * plhs[],
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
     case 1:
      {
        extern mxArray *sf_c1_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c1_large_snake_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c2_large_snake_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c3_large_snake_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c4_large_snake_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c5_large_snake_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c6_large_snake_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c7_large_snake_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c8_large_snake_get_autoinheritance_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c9_large_snake_get_autoinheritance_info();
        break;
      }

     case 10:
      {
        extern mxArray *sf_c10_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c10_large_snake_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c11_large_snake_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray *sf_c13_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c13_large_snake_get_autoinheritance_info();
        break;
      }

     case 15:
      {
        extern mxArray *sf_c15_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c15_large_snake_get_autoinheritance_info();
        break;
      }

     case 22:
      {
        extern mxArray *sf_c22_large_snake_get_autoinheritance_info(void);
        plhs[0] = sf_c22_large_snake_get_autoinheritance_info();
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

unsigned int sf_large_snake_get_eml_resolved_functions_info( int nlhs, mxArray *
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
     case 1:
      {
        extern const mxArray *sf_c1_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_large_snake_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_large_snake_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_large_snake_get_eml_resolved_functions_info();
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

void large_snake_debug_initialize(void)
{
  _large_snakeMachineNumber_ = sf_debug_initialize_machine("large_snake","sfun",
    0,14,0,0,0);
  sf_debug_set_machine_event_thresholds(_large_snakeMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_large_snakeMachineNumber_,0);
}

void large_snake_register_exported_symbols(SimStruct* S)
{
}
