/*
 * twa_parallel_private.h
 *
 * Real-Time Workshop code generation for Simulink model "twa_parallel.mdl".
 *
 * Model version              : 1.7037
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Wed Aug 14 17:58:49 2024
 *
 * Target selection: xpctargetert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_twa_parallel_private_h_
#define RTW_HEADER_twa_parallel_private_h_
#include "rtwtypes.h"
#include "C:\ServoToGo\stg_comn.h"
#include "C:\ServoToGo\stgdefs.h"
#include "C:\ServoToGo\stgmembs.h"
#include "C:\ServoToGo\irq_defs.h"
#include "C:\ServoToGo\stg_comn.h"
#include "C:\ServoToGo\stgdefs.h"
#include "C:\ServoToGo\stgmembs.h"
#include "C:\ServoToGo\irq_defs.h"
#include "C:\ServoToGo\stg_comn.h"
#include "C:\ServoToGo\stgdefs.h"
#include "C:\ServoToGo\stgmembs.h"
#include "C:\ServoToGo\irq_defs.h"
#define CALL_EVENT                     (-1)
#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern serialfifoptr serialfifoground;
bcmsglist1553 bcmsg1553ground;
bcstatus1553 bcstatground;
bmmsglist1553 bmmsg1553ground;

/* private model entry point functions */
extern void twa_parallel_derivatives(void);

#endif                                 /* RTW_HEADER_twa_parallel_private_h_ */
