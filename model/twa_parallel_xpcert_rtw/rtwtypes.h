/*
 * File: rtwtypes.h
 *
 * Real-Time Workshop code generation for Simulink model "twa_parallel.mdl".
 *
 * Model version              : 1.6680
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Wed Jun 12 15:41:39 2024
 *
 * Target selection: xpctargetert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rtwtypes_h_
#define RTW_HEADER_rtwtypes_h_
#ifndef __RTWTYPES_H__
#define __RTWTYPES_H__
#include "tmwtypes.h"

/* This ID is used to detect inclusion of an incompatible rtwtypes.h */
#define RTWTYPES_ID_C08S16I32L32N32F1
#include "simstruc_types.h"
#ifndef POINTER_T
# define POINTER_T

typedef void * pointer_T;

#endif

#ifndef TRUE
# define TRUE                          (1U)
#endif

#ifndef FALSE
# define FALSE                         (0U)
#endif

/*
 * Definitions supporting external data access
 */
typedef int32_T chunk_T;
typedef uint32_T uchunk_T;

#endif                                 /* __RTWTYPES_H__ */
#endif                                 /* RTW_HEADER_rtwtypes_h_ */
