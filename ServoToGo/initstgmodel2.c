//
// initstgmodel2.c
//

#define 	S_FUNCTION_LEVEL 	2
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	initstgmodel2
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
#define NUM_PARAMS			(4)
#define SAMPLE_TIME_ARG		ssGetSFcnParam(S,0)
#define BASE_ARG			ssGetSFcnParam(S,1)
#define IRQ_ARG				ssGetSFcnParam(S,2)
#define DEBUG_FLAG			ssGetSFcnParam(S,3)

#define NUM_IWORKS			(0)
#define NUM_RWORKS			(0)

static char_T msg[256];

#define MDL_CHECK_PARAMETERS	/* Change to #undef to remove function */
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
static void mdlCheckParameters(SimStruct *S)
{
	boolean_T allParamsOK = 1;
	char classType[256];
	
	/* Base Address */
	if (!mxIsNumeric(BASE_ARG)) {
		sprintf(msg, "Base address parameter must be in the form of 0x000.\n");
		allParamsOK = 0;
		goto EXIT_POINT;
	}
	
	/* Sample Time */
	if (!mxIsDouble(SAMPLE_TIME_ARG)) {
		sprintf(msg, "Sample time parameter must be a scaler.\n");
		allParamsOK = 0;
		goto EXIT_POINT;
	}
	
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
	
	ssSetNumSFcnParams(S, NUM_PARAMS);
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
	
	//if (!ssSetNumOutputPorts(S, 0)) return;

	
	if ((real_T) mxGetPr(DEBUG_FLAG)[0] == 0)
	{
		if (!ssSetNumOutputPorts(S, 0)) return;
	}
	else	//DEBUG_FLAG == 1
	{
		if (!ssSetNumOutputPorts(S, 6)) return;
		for (i = 0; i < 6; i++) {
			ssSetOutputPortWidth(S, i, 1);
		}
	}
	
	ssSetNumSampleTimes(S, 1);
	
	ssSetNumRWork(S, NUM_RWORKS);
	ssSetNumIWork(S, NUM_IWORKS);
	ssSetNumPWork(S, 0);
	
	ssSetNumModes(S, 0);
	ssSetNumNonsampledZCs(S, 0);
	
	ssSetSFcnParamTunable(S,0,0);
	ssSetSFcnParamTunable(S,1,0);
	ssSetSFcnParamTunable(S,2,0);
	
	ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
	
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
	ssSetSampleTime(S, 0, (real_T) mxGetPr(SAMPLE_TIME_ARG)[0]);
	ssSetOffsetTime(S, 0, 0.0);
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

