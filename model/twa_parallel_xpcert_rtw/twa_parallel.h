/*
 * twa_parallel.h
 *
 * Real-Time Workshop code generation for Simulink model "twa_parallel.mdl".
 *
 * Model version              : 1.7049
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Aug 15 16:22:01 2024
 *
 * Target selection: xpctargetert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_twa_parallel_h_
#define RTW_HEADER_twa_parallel_h_
#include "rtw_modelmap.h"
#ifndef twa_parallel_COMMON_INCLUDES_
# define twa_parallel_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_SATURATE.h"
#include "rt_pow_snf.h"
#endif                                 /* twa_parallel_COMMON_INCLUDES_ */

#include "twa_parallel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeDeltaY
# define rtmGetOdeDeltaY(rtm)          ((rtm)->ModelData.OdeDeltaY)
#endif

#ifndef rtmSetOdeDeltaY
# define rtmSetOdeDeltaY(rtm, val)     ((rtm)->ModelData.OdeDeltaY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeX0
# define rtmGetOdeX0(rtm)              ((rtm)->ModelData.odeX0)
#endif

#ifndef rtmSetOdeX0
# define rtmSetOdeX0(rtm, val)         ((rtm)->ModelData.odeX0 = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define twa_parallel_M                 (twa_parallel_rtM)

/* Definition for use in the target main file */
#define twa_parallel_rtModel           rtModel_twa_parallel

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals (auto storage) */
typedef struct {
  real_T EncoderInput_o1;              /* '<S1>/Encoder Input' */
  real_T EncoderInput_o2;              /* '<S1>/Encoder Input' */
  real_T EncoderInput_o3;              /* '<S1>/Encoder Input' */
  real_T EncoderInput_o4;              /* '<S1>/Encoder Input' */
  real_T EncoderInput_o5;              /* '<S1>/Encoder Input' */
  real_T EncoderInput_o6;              /* '<S1>/Encoder Input' */
  real_T enc_res;                      /* '<S7>/enc_res' */
  real_T gear_ratio;                   /* '<S7>/gear_ratio' */
  real_T velmex_pitch;                 /* '<S7>/velmex_pitch' */
  real_T enc_res_f;                    /* '<S8>/enc_res' */
  real_T gear_ratio_c;                 /* '<S8>/gear_ratio' */
  real_T velmex_pitch_e;               /* '<S8>/velmex_pitch' */
  real_T enc_res_c;                    /* '<S9>/enc_res' */
  real_T gear_ratio_l;                 /* '<S9>/gear_ratio' */
  real_T velmex_pitch_k;               /* '<S9>/velmex_pitch' */
  real_T enc_res_fa;                   /* '<S10>/enc_res' */
  real_T gear_ratio_j;                 /* '<S10>/gear_ratio' */
  real_T enc_res_b;                    /* '<S11>/enc_res' */
  real_T gear_ratio_n;                 /* '<S11>/gear_ratio' */
  real_T enc_res_e;                    /* '<S12>/enc_res' */
  real_T gear_ratio_f;                 /* '<S12>/gear_ratio' */
  real_T TmpSignalConversionAtDiscreteFI[6];
  real_T DiscreteFIRFilter[6];         /* '<S15>/Discrete FIR Filter' */
  real_T Gain[6];                      /* '<S15>/Gain' */
  real_T TSamp[6];                     /* '<S14>/TSamp' */
  real_T Uk1[6];                       /* '<S14>/UD' */
  real_T Diff[6];                      /* '<S14>/Diff' */
  real_T DiscreteFIRFilter_h[6];       /* '<S19>/Discrete FIR Filter' */
  real_T Gain_n[6];                    /* '<S19>/Gain' */
  real_T Uk1_p[6];                     /* '<S25>/Delay Input1' */
  real_T UnitDelay1[6];                /* '<Root>/Unit Delay1' */
  real_T Switch[6];                    /* '<S5>/Switch' */
  real_T UnitDelay1_i[6];              /* '<S6>/Unit Delay1' */
  real_T UnitDelay4[3];                /* '<S6>/Unit Delay4' */
  real_T UnitDelay3;                   /* '<S6>/Unit Delay3' */
  real_T cntrl_switch[6];              /* '<Root>/cntrl_switch' */
  real_T DigitalClock;                 /* '<S3>/Digital Clock' */
  real_T UnitDelay;                    /* '<S3>/Unit Delay' */
  real_T UnitDelay1_b;                 /* '<S3>/Unit Delay1' */
  real_T UnitDelay2[6];                /* '<S3>/Unit Delay2' */
  real_T Switch_f[6];                  /* '<S18>/Switch' */
  real_T Sum[6];                       /* '<S2>/Sum' */
  real_T Kp[6];                        /* '<S2>/Kp' */
  real_T Integrator[6];                /* '<S2>/Integrator' */
  real_T Ki[6];                        /* '<S2>/Ki' */
  real_T saturate_int[6];              /* '<S2>/saturate_int' */
  real_T TSamp_h[6];                   /* '<S16>/TSamp' */
  real_T Uk1_j[6];                     /* '<S16>/UD' */
  real_T Diff_d[6];                    /* '<S16>/Diff' */
  real_T Kd[6];                        /* '<S2>/Kd' */
  real_T Add[6];                       /* '<S2>/Add' */
  real_T Saturation[6];                /* '<S2>/Saturation' */
  real_T Switch_i[6];                  /* '<S2>/Switch' */
  real_T twa_gamma;                    /* '<S6>/twa_gamma' */
  real_T use_twa;                      /* '<S6>/use_twa' */
  real_T twa_flange_offset;            /* '<S6>/twa_flange_offset' */
  real_T t_in_w[9];                    /* '<S6>/t_in_w' */
  real_T TmpSignalConversionAtSFunctionI[6];/* '<S6>/ResolvedRates' */
  real_T qeps[6];                      /* '<S6>/ResolvedRates' */
  real_T qdes[6];                      /* '<S6>/ResolvedRates' */
  real_T xcur[3];                      /* '<S6>/ResolvedRates' */
  real_T eerot;                        /* '<S6>/ResolvedRates' */
  real_T TmpSignalConversionAtSFunctio_c[6];/* '<S3>/Embedded MATLAB Function' */
  real_T q_cmd[6];                     /* '<S3>/Embedded MATLAB Function' */
  real_T q_dot[6];                     /* '<S3>/Embedded MATLAB Function' */
  real_T q_dub_dot[6];                 /* '<S3>/Embedded MATLAB Function' */
  real_T confn;                        /* '<S3>/Embedded MATLAB Function' */
  real_T t0n;                          /* '<S3>/Embedded MATLAB Function' */
  real_T q0n[6];                       /* '<S3>/Embedded MATLAB Function' */
  real_T robot_mov;                    /* '<S3>/Embedded MATLAB Function' */
  uint8_T FixPtRelationalOperator[6];  /* '<S25>/FixPt Relational Operator' */
  boolean_T NSampleEnable;             /* '<S18>/N-Sample Enable' */
} BlockIO_twa_parallel;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteFIRFilter_states[6];  /* '<S15>/Discrete FIR Filter' */
  real_T UD_DSTATE[6];                 /* '<S14>/UD' */
  real_T DiscreteFIRFilter_states_m[6];/* '<S19>/Discrete FIR Filter' */
  real_T DelayInput1_DSTATE[6];        /* '<S25>/Delay Input1' */
  real_T UnitDelay1_DSTATE[6];         /* '<Root>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j[6];       /* '<S6>/Unit Delay1' */
  real_T UnitDelay4_DSTATE[3];         /* '<S6>/Unit Delay4' */
  real_T UnitDelay3_DSTATE;            /* '<S6>/Unit Delay3' */
  real_T UnitDelay_DSTATE;             /* '<S3>/Unit Delay' */
  real_T UnitDelay1_DSTATE_h;          /* '<S3>/Unit Delay1' */
  real_T UnitDelay2_DSTATE[6];         /* '<S3>/Unit Delay2' */
  real_T UD_DSTATE_o[6];               /* '<S16>/UD' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S15>/Discrete FIR Filter' */
  int32_T DiscreteFIRFilter_circBuf_l; /* '<S19>/Discrete FIR Filter' */
  uint32_T NSampleEnable_Counter;      /* '<S18>/N-Sample Enable' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S21>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_j;                 /* '<S20>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S22>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_ih;                /* '<S23>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_m;                 /* '<S24>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_l;                 /* '<S27>/S-Function' */

  uint8_T is_active_c5_twa_parallel;   /* '<S6>/ResolvedRates' */
  uint8_T is_active_c22_twa_parallel;  /* '<S3>/Embedded MATLAB Function' */
  boolean_T isStable;                  /* '<S6>/ResolvedRates' */
  boolean_T doneDoubleBufferReInit;    /* '<S6>/ResolvedRates' */
  boolean_T isStable_n;                /* '<S3>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S3>/Embedded MATLAB Function' */
} D_Work_twa_parallel;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[6];         /* '<S2>/Integrator' */
} ContinuousStates_twa_parallel;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[6];         /* '<S2>/Integrator' */
} StateDerivatives_twa_parallel;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[6];      /* '<S2>/Integrator' */
} StateDisabled_twa_parallel;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S2>/Integrator' */
} PrevZCSigStates_twa_parallel;

#ifndef ODE8_INTG
#define ODE8_INTG

/* ODE8 Integration Data */
typedef struct {
  real_T *deltaY;                      /* output diff */
  real_T *f[13];                       /* derivatives */
  real_T *x0;                          /* Initial State */
} ODE8_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            twa_parallel_B
#define BlockIO                        BlockIO_twa_parallel
#define rtX                            twa_parallel_X
#define ContinuousStates               ContinuousStates_twa_parallel
#define rtP                            twa_parallel_P
#define Parameters                     Parameters_twa_parallel
#define rtDWork                        twa_parallel_DWork
#define D_Work                         D_Work_twa_parallel
#define rtPrevZCSigState               twa_parallel_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_twa_parallel

/* Parameters (auto storage) */
struct Parameters_twa_parallel_ {
  real_T Init_P1;                      /* Expression: sampletime
                                        * Referenced by: '<Root>/Init'
                                        */
  real_T Init_P2;                      /* Expression: baseaddressD
                                        * Referenced by: '<Root>/Init'
                                        */
  real_T Init_P3;                      /* Expression: irq_num
                                        * Referenced by: '<Root>/Init'
                                        */
  real_T Init_P4;                      /* Expression: debug_flag
                                        * Referenced by: '<Root>/Init'
                                        */
  real_T AnalogOutput_P1[6];           /* Expression: channels
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  real_T EncoderInput_P1[6];           /* Expression: channels
                                        * Referenced by: '<S1>/Encoder Input'
                                        */
  real_T EncoderInput_P2;              /* Expression: countrev
                                        * Referenced by: '<S1>/Encoder Input'
                                        */
  real_T enc_res_Gain;                 /* Expression: 1/enc_res
                                        * Referenced by: '<S7>/enc_res'
                                        */
  real_T gear_ratio_Gain;              /* Expression: 1/gear_rat
                                        * Referenced by: '<S7>/gear_ratio'
                                        */
  real_T velmex_pitch_Gain;            /* Expression: velmex_pitch
                                        * Referenced by: '<S7>/velmex_pitch'
                                        */
  real_T enc_res_Gain_j;               /* Expression: 1/enc_res
                                        * Referenced by: '<S8>/enc_res'
                                        */
  real_T gear_ratio_Gain_d;            /* Expression: 1/gear_rat
                                        * Referenced by: '<S8>/gear_ratio'
                                        */
  real_T velmex_pitch_Gain_j;          /* Expression: velmex_pitch
                                        * Referenced by: '<S8>/velmex_pitch'
                                        */
  real_T enc_res_Gain_i;               /* Expression: 1/enc_res
                                        * Referenced by: '<S9>/enc_res'
                                        */
  real_T gear_ratio_Gain_a;            /* Expression: 1/gear_rat
                                        * Referenced by: '<S9>/gear_ratio'
                                        */
  real_T velmex_pitch_Gain_je;         /* Expression: velmex_pitch
                                        * Referenced by: '<S9>/velmex_pitch'
                                        */
  real_T enc_res_Gain_g;               /* Expression: 1/twa_enc_res
                                        * Referenced by: '<S10>/enc_res'
                                        */
  real_T gear_ratio_Gain_o;            /* Expression: 1/twa_gear_rat
                                        * Referenced by: '<S10>/gear_ratio'
                                        */
  real_T enc_res_Gain_ij;              /* Expression: 1/twa_enc_res
                                        * Referenced by: '<S11>/enc_res'
                                        */
  real_T gear_ratio_Gain_da;           /* Expression: 1/twa_gear_rat
                                        * Referenced by: '<S11>/gear_ratio'
                                        */
  real_T enc_res_Gain_m;               /* Expression: 1/twa_enc_res
                                        * Referenced by: '<S12>/enc_res'
                                        */
  real_T gear_ratio_Gain_c;            /* Expression: 1/twa_gear_rat
                                        * Referenced by: '<S12>/gear_ratio'
                                        */
  real_T vel_filter_coeffs_Value[2];   /* Expression: vel_filter_coeffs
                                        * Referenced by: '<S15>/vel_filter_coeffs'
                                        */
  real_T DiscreteFIRFilter_IC;         /* Expression: 0
                                        * Referenced by: '<S15>/Discrete FIR Filter'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/N_velocity
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S14>/TSamp'
                                        */
  real_T UD_X0;                        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S14>/UD'
                                        */
  real_T enc_reset1_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset1'
                                        */
  real_T enc_reset2_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset2'
                                        */
  real_T enc_reset3_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset3'
                                        */
  real_T enc_reset4_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset4'
                                        */
  real_T enc_reset5_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset5'
                                        */
  real_T enc_reset6_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/enc_reset6'
                                        */
  real_T vel_filter_coeffs_Value_m[2]; /* Expression: vel_filter_coeffs
                                        * Referenced by: '<S19>/vel_filter_coeffs'
                                        */
  real_T DiscreteFIRFilter_IC_b;       /* Expression: 0
                                        * Referenced by: '<S19>/Discrete FIR Filter'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1/N_velocity
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T cntrl_mode_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/cntrl_mode'
                                        */
  real_T q_des_Value[6];               /* Expression: zeros(6,1)
                                        * Referenced by: '<Root>/q_des'
                                        */
  real_T DelayInput1_X0;               /* Expression: vinit
                                        * Referenced by: '<S25>/Delay Input1'
                                        */
  real_T UnitDelay1_X0[6];             /* Expression: zeros(6,1)
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T x_des_Value[3];               /* Expression: zeros(3,1)
                                        * Referenced by: '<S6>/x_des'
                                        */
  real_T ee_rot_des_Value;             /* Expression: pi/6
                                        * Referenced by: '<S6>/ee_rot_des'
                                        */
  real_T dt_Value;                     /* Expression: dt
                                        * Referenced by: '<S6>/dt'
                                        */
  real_T p_in_m_Value[9];              /* Expression: p_in_m
                                        * Referenced by: '<S6>/p_in_m'
                                        */
  real_T b_in_w_Value[9];              /* Expression: b_in_w
                                        * Referenced by: '<S6>/b_in_w'
                                        */
  real_T m_in_w_Value[9];              /* Expression: m_in_w
                                        * Referenced by: '<S6>/m_in_w'
                                        */
  real_T f_in_w_Value[9];              /* Expression: f_in_w
                                        * Referenced by: '<S6>/f_in_w'
                                        */
  real_T res_rate_param_Value[8];      /* Expression: res_rate_param
                                        * Referenced by: '<S6>/res_rate_param'
                                        */
  real_T UnitDelay1_X0_g[6];           /* Expression: zeros(6,1)
                                        * Referenced by: '<S6>/Unit Delay1'
                                        */
  real_T UnitDelay4_X0[3];             /* Expression: zeros(3,1)
                                        * Referenced by: '<S6>/Unit Delay4'
                                        */
  real_T UnitDelay3_X0;                /* Expression: pi/6
                                        * Referenced by: '<S6>/Unit Delay3'
                                        */
  real_T tf_Value;                     /* Expression: 1
                                        * Referenced by: '<S3>/tf'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_h;              /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0[6];             /* Expression: zeros(6,1)
                                        * Referenced by: '<S3>/Unit Delay2'
                                        */
  real_T quintic_enable_Value;         /* Expression: 1
                                        * Referenced by: '<S3>/quintic_enable'
                                        */
  real_T Kp_Gain[6];                   /* Expression: K_p
                                        * Referenced by: '<S2>/Kp'
                                        */
  real_T reset_integrator_Value;       /* Expression: 0
                                        * Referenced by: '<S2>/reset_integrator'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Ki_Gain[6];                   /* Expression: K_i
                                        * Referenced by: '<S2>/Ki'
                                        */
  real_T saturate_int_UpperSat[6];     /* Expression: [5,5,5,.25,0.25,0.25]
                                        * Referenced by: '<S2>/saturate_int'
                                        */
  real_T saturate_int_LowerSat[6];     /* Expression: -1*[5,5,5,.25,0.25,0.25]
                                        * Referenced by: '<S2>/saturate_int'
                                        */
  real_T TSamp_WtEt_p;                 /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S16>/TSamp'
                                        */
  real_T UD_X0_f;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S16>/UD'
                                        */
  real_T Kd_Gain[6];                   /* Expression: K_d
                                        * Referenced by: '<S2>/Kd'
                                        */
  real_T Saturation_UpperSat[6];       /* Expression: [10,10,10,2,2,2]
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat[6];       /* Expression: -1*[10,10,10,2,2,2]
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T pid_mode_Value;               /* Expression: 1
                                        * Referenced by: '<S2>/pid_mode'
                                        */
  real_T manual_current_Value[6];      /* Expression: zeros(6,1)
                                        * Referenced by: '<S2>/manual_current'
                                        */
  real_T twa_gamma_Value;              /* Expression: twa_gamma
                                        * Referenced by: '<S6>/twa_gamma'
                                        */
  real_T use_twa_Value;                /* Expression: use_twa
                                        * Referenced by: '<S6>/use_twa'
                                        */
  real_T twa_flange_offset_Value;      /* Expression: twa_flange_offset
                                        * Referenced by: '<S6>/twa_flange_offset'
                                        */
  real_T t_in_w_Value[9];              /* Expression: t_in_w
                                        * Referenced by: '<S6>/t_in_w'
                                        */
  uint32_T NSampleEnable_TARGETCNT;    /* Computed Parameter: NSampleEnable_TARGETCNT
                                        * Referenced by: '<S18>/N-Sample Enable'
                                        */
  uint32_T NSampleEnable_ACTLEVEL;     /* Computed Parameter: NSampleEnable_ACTLEVEL
                                        * Referenced by: '<S18>/N-Sample Enable'
                                        */
};

/* Real-time Model Data Structure */
struct rtModel_twa_parallel {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T OdeDeltaY[6];
    real_T odeF[13][6];
    real_T odeX0[6];
    ODE8_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_twa_parallel twa_parallel_P;

/* Block signals (auto storage) */
extern BlockIO_twa_parallel twa_parallel_B;

/* Continuous states (auto storage) */
extern ContinuousStates_twa_parallel twa_parallel_X;

/* Block states (auto storage) */
extern D_Work_twa_parallel twa_parallel_DWork;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_twa_parallel twa_parallel_PrevZCSigState;

/* Model entry point functions */
extern void twa_parallel_initialize(boolean_T firstTime);
extern void twa_parallel_output(int_T tid);
extern void twa_parallel_update(int_T tid);
extern void twa_parallel_terminate(void);

/* Real-time Model object */
extern struct rtModel_twa_parallel *twa_parallel_rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : twa_parallel
 * '<S1>'   : twa_parallel/Encoders
 * '<S2>'   : twa_parallel/PID Controller
 * '<S3>'   : twa_parallel/Quintic Poly
 * '<S4>'   : twa_parallel/Scopes
 * '<S5>'   : twa_parallel/detect change
 * '<S6>'   : twa_parallel/task_space
 * '<S7>'   : twa_parallel/Encoders/Counts To Turns1
 * '<S8>'   : twa_parallel/Encoders/Counts To Turns2
 * '<S9>'   : twa_parallel/Encoders/Counts To Turns3
 * '<S10>'  : twa_parallel/Encoders/Counts To Turns4
 * '<S11>'  : twa_parallel/Encoders/Counts To Turns5
 * '<S12>'  : twa_parallel/Encoders/Counts To Turns6
 * '<S13>'  : twa_parallel/Encoders/Derivative
 * '<S14>'  : twa_parallel/Encoders/Derivative/Discrete Derivative
 * '<S15>'  : twa_parallel/Encoders/Derivative/Fir Filter
 * '<S16>'  : twa_parallel/PID Controller/Discrete Derivative
 * '<S17>'  : twa_parallel/Quintic Poly/Embedded MATLAB Function
 * '<S18>'  : twa_parallel/Quintic Poly/N-Sample Switch
 * '<S19>'  : twa_parallel/Scopes/Fir Filter
 * '<S20>'  : twa_parallel/Scopes/q_cur_macro1
 * '<S21>'  : twa_parallel/Scopes/q_cur_macro2
 * '<S22>'  : twa_parallel/Scopes/q_cur_macro3
 * '<S23>'  : twa_parallel/Scopes/q_cur_macro4
 * '<S24>'  : twa_parallel/Scopes/q_cur_macro5
 * '<S25>'  : twa_parallel/detect change/Detect Change
 * '<S26>'  : twa_parallel/task_space/ResolvedRates
 * '<S27>'  : twa_parallel/task_space/q_cur_macro6
 */
#endif                                 /* RTW_HEADER_twa_parallel_h_ */
