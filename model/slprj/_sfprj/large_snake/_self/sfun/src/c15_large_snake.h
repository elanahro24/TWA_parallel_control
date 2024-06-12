#ifndef __c15_large_snake_h__
#define __c15_large_snake_h__

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
} c15_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc15_large_snakeInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_large_snake_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_large_snake_get_check_sum(mxArray *plhs[]);
extern void c15_large_snake_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
