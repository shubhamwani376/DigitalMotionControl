/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SystemIDlookuptable.h
 *
 * Code generated for Simulink model 'SystemIDlookuptable'.
 *
 * Model version                  : 1.66
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Feb 12 12:41:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SystemIDlookuptable_h_
#define RTW_HEADER_SystemIDlookuptable_h_
#ifndef SystemIDlookuptable_COMMON_INCLUDES_
#define SystemIDlookuptable_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                /* SystemIDlookuptable_COMMON_INCLUDES_ */

#include "SystemIDlookuptable_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);
extern void config_ePWM_TBSync(void);

/* Block signals (default storage) */
typedef struct {
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T eQEP_o1;                      /* '<Root>/eQEP' */
  real_T eQEP_o2;                      /* '<Root>/eQEP' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Diff;                         /* '<S1>/Diff' */
  real32_T TmpSignalConversionAtTAQSigLogg[4];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real32_T TmpSignalConversionAtTAQSigLo_n[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' */
  real32_T TmpSignalConversionAtTAQSigLo_d[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux5_at_outport_0Inport1' */
} B_SystemIDlookuptable_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  struct {
    void *LoggedData;
  } y_PWORK;                           /* '<Root>/y' */

  struct {
    void *LoggedData;
  } u_PWORK;                           /* '<Root>/u' */

  struct {
    void *LoggedData;
  } y_m_PWORK;                         /* '<Root>/y_m' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } ToWorkspace8_PWORK;                /* '<Root>/To Workspace8' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<Root>/To Workspace5' */
} DW_SystemIDlookuptable_T;

/* Parameters (default storage) */
struct P_SystemIDlookuptable_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T Constant2_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 1620.476554536188
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 3.14159/400
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SystemIDlookuptable_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_SystemIDlookuptable_T SystemIDlookuptable_P;

/* Block signals (default storage) */
extern B_SystemIDlookuptable_T SystemIDlookuptable_B;

/* Block states (default storage) */
extern DW_SystemIDlookuptable_T SystemIDlookuptable_DW;

/* Model entry point functions */
extern void SystemIDlookuptable_initialize(void);
extern void SystemIDlookuptable_step(void);
extern void SystemIDlookuptable_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SystemIDlookuptable_T *const SystemIDlookuptable_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 */

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
 * '<Root>' : 'SystemIDlookuptable'
 * '<S1>'   : 'SystemIDlookuptable/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_SystemIDlookuptable_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
