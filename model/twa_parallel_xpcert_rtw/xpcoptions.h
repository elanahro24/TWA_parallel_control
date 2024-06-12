#ifndef __twa_parallel_XPCOPTIONS_H___
#define __twa_parallel_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "twa_parallel.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_twa_parallel))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0

/* Change all stepsize using the newBaseRateStepSize */
void twa_parallel_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_twa_parallel *const twa_parallel_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.002;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  twa_parallel_rtM->Timing.stepSize0 = twa_parallel_rtM->Timing.stepSize0 *
    ratio;
  twa_parallel_rtM->Timing.stepSize1 = twa_parallel_rtM->Timing.stepSize1 *
    ratio;
  twa_parallel_rtM->Timing.stepSize = twa_parallel_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  twa_parallel_ChangeStepSize(stepSize, twa_parallel_rtM);
}

#endif                                 /* __twa_parallel_XPCOPTIONS_H___ */
