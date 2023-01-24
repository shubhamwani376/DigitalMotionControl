/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorkitc2000_HW1.h
 *
 * Code generated for Simulink model 'motorkitc2000_HW1'.
 *
 * Model version                  : 2.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jan 23 18:00:17 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motorkitc2000_HW1_h_
#define RTW_HEADER_motorkitc2000_HW1_h_
#ifndef motorkitc2000_HW1_COMMON_INCLUDES_
#define motorkitc2000_HW1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* motorkitc2000_HW1_COMMON_INCLUDES_ */

#include "motorkitc2000_HW1_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
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
  real_T Constant;                     /* '<Root>/Constant' */
  real_T eQEP_o1;                      /* '<Root>/eQEP' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real32_T eQEP_o2;                    /* '<Root>/eQEP' */
} B_motorkitc2000_HW1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} DW_motorkitc2000_HW1_T;

/* Parameters (default storage) */
struct P_motorkitc2000_HW1_T_ {
  real_T Constant_Value;               /* Expression: 958.0466360856269
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 100000
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 5
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: -1
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T OutputvoltagetoPWM1_Gain;     /* Expression: 10.7
                                        * Referenced by: '<Root>/Output voltage to PWM1'
                                        */
  real_T OutputvoltagetoPWM_Gain;      /* Expression: 1000/10.7
                                        * Referenced by: '<Root>/Output voltage to PWM'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motorkitc2000_HW1_T {
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
    uint32_T clockTick1;
    struct {
      uint16_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_motorkitc2000_HW1_T motorkitc2000_HW1_P;

/* Block signals (default storage) */
extern B_motorkitc2000_HW1_T motorkitc2000_HW1_B;

/* Block states (default storage) */
extern DW_motorkitc2000_HW1_T motorkitc2000_HW1_DW;

/* External function called from main */
extern void motorkitc2000_HW1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void motorkitc2000_HW1_initialize(void);
extern void motorkitc2000_HW1_step0(void);
extern void motorkitc2000_HW1_step1(void);
extern void motorkitc2000_HW1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motorkitc2000_HW1_T *const motorkitc2000_HW1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Zero-Order Hold' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'motorkitc2000_HW1'
 */
#endif                                 /* RTW_HEADER_motorkitc2000_HW1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
