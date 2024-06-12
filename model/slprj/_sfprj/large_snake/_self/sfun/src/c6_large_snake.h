#ifndef __c6_large_snake_h__
#define __c6_large_snake_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char *context;
  const char *name;
  const char *dominantType;
  const char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c6_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc6_large_snakeInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_large_snake_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_large_snake_get_check_sum(mxArray *plhs[]);
extern void c6_large_snake_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
