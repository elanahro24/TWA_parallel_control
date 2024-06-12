//
// adstgmodel2.c
//

#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	adstgmodel2
#include 	"simstruc.h" 

#include 	<stddef.h>
#include 	<stdlib.h>

#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif

#ifndef		MATLAB_MEX_FILE
#include 	<windows.h>
#include 	"io_xpcimport.h"	
#include	"stg_comn.h"
#include	"stgdefs.h"
#include	"stgmembs.h"
#include	"irq_defs.h"
#include	"global_vars.c"
#endif


/* Input Arguments */
#define NUMBER_OF_ARGS		(2)
#define CHANNEL_ARG			ssGetSFcnParam(S,0)
#define AUTO_ZERO			ssGetSFcnParam(S,1)

#define NUM_IWORKS			(0)
#define NUM_RWORKS			(0)

static char_T msg[256];

#define MDL_CHECK_PARAMETERS	/* Change to #undef to remove function */
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
static void mdlCheckParameters(SimStruct *S)
{
	boolean_T allParamsOK = 1;
	char classType[256];
	
	/* Number of Channels */
/*
	if (!mxIsDouble(CHANNEL_ARG)) {
		sprintf(msg, "Number of channels parameter must be a scaler.\n");
		allParamsOK = 0;
		goto EXIT_POINT;
	}
	if (!(1 <= CHANNEL_ARG[0] && CHANNEL_ARG[0] <= 8)) {
	sprintf(msg, "This is of class type %f.\n",CHANNEL_ARG[0]);
	//sprintf(msg, "This is of class type %s.\n",mxGetClassName(CHANNEL_ARG));
	//sprintf(msg, "Number of channels parameter must be between 1 and 8(blah).\n");
	allParamsOK = 0;
	goto EXIT_POINT;
	}
*/	
	
EXIT_POINT:
	if (!allParamsOK) {
		ssSetErrorStatus(S, msg);
	}
}
#endif	/* MDL_CHECK_PARAMETERS */


static void mdlInitializeSizes(SimStruct *S)
{
	int_T i;
	
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "time_xpcimport.c"
#endif
	
	ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
	if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
		mdlCheckParameters(S);
		if (ssGetErrorStatus(S) != NULL) {
			return;
		}
	} else {
		return; /* Parameter mismatch will be reported by Simulink */
	}
	
	ssSetNumContStates(S, 0);
	ssSetNumDiscStates(S, 0);
	
	
	if (!ssSetNumInputPorts(S, 0)) return;
	
	if (!ssSetNumOutputPorts(S, mxGetN(CHANNEL_ARG))) return;
	
	for (i = 0; i < mxGetN(CHANNEL_ARG); i++) {
		ssSetOutputPortWidth(S, i, 1);
	}
	
	ssSetNumSampleTimes(S, 1);
	
	ssSetNumRWork(S, NUM_RWORKS);
	ssSetNumIWork(S, NUM_IWORKS);
	ssSetNumPWork(S, 0);
	
	ssSetNumModes(S, 0);
	ssSetNumNonsampledZCs(S, 0);
	
    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        ssSetSFcnParamTunable(S,i,0);  /* None of the parameters are tunable */
    }
	
	ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
	
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static void mdlStart(SimStruct *S)
{
}


static void mdlOutputs(SimStruct *S, int_T tid)
{
}


static void mdlTerminate(SimStruct *S)
{
}


#ifdef	MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif

