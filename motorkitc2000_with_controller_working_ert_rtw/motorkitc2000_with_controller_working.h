/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorkitc2000_with_controller_working.h
 *
 * Code generated for Simulink model 'motorkitc2000_with_controller_working'.
 *
 * Model version                  : 2.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jan 23 17:38:32 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motorkitc2000_with_controller_working_h_
#define RTW_HEADER_motorkitc2000_with_controller_working_h_
#ifndef motorkitc2000_with_controller_working_COMMON_INCLUDES_
#define motorkitc2000_with_controller_working_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif              /* motorkitc2000_with_controller_working_COMMON_INCLUDES_ */

#include "motorkitc2000_with_controller_working_types.h"
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

#define motorkitc2000_with_controller_working_M (motorkitc2000_with_controlle_M)

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
  real_T Counttoradian;                /* '<Root>/Count to radian' */
  real_T Sum4;                         /* '<Root>/Sum4' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T OutputUpperLimit;             /* '<Root>/Output Upper Limit' */
  real_T ZeroOrderHold;                /* '<Root>/Zero-Order Hold' */
  real_T PGain;                        /* '<Root>/P Gain' */
  real_T DGain;                        /* '<Root>/D Gain' */
  real_T N;                            /* '<Root>/N' */
  real_T OutputLowerLimit;             /* '<Root>/Output Lower Limit' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T IGain;                        /* '<Root>/I Gain' */
  real32_T eQEP_o2;                    /* '<Root>/eQEP' */
} B_motorkitc2000_with_controll_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S33>/Integrator' */
  real_T Filter_DSTATE;                /* '<S28>/Filter' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Error_PWORK;                       /* '<Root>/Error' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} DW_motorkitc2000_with_control_T;

/* Parameters (default storage) */
struct P_motorkitc2000_with_controll_T_ {
  real_T DiscreteVaryingPID_InitialCondi;
                              /* Mask Parameter: DiscreteVaryingPID_InitialCondi
                               * Referenced by: '<S28>/Filter'
                               */
  real_T DiscreteVaryingPID_InitialCon_a;
                              /* Mask Parameter: DiscreteVaryingPID_InitialCon_a
                               * Referenced by: '<S33>/Integrator'
                               */
  real_T Constant_Value;               /* Expression: 958.0466360856269
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Counttoradian_Gain;           /* Expression: 3.14159/200
                                        * Referenced by: '<Root>/Count to radian'
                                        */
  real_T Reference_Value;              /* Expression: 100000*3.14159/200
                                        * Referenced by: '<Root>/Reference'
                                        */
  real_T Constant2_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T OutputUpperLimit_Value;       /* Expression: 1
                                        * Referenced by: '<Root>/Output Upper Limit'
                                        */
  real_T PGain_Value;                  /* Expression: 1.2156
                                        * Referenced by: '<Root>/P Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S33>/Integrator'
                                        */
  real_T DGain_Value;                  /* Expression: 0.0405
                                        * Referenced by: '<Root>/D Gain'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S28>/Filter'
                                        */
  real_T N_Value;                      /* Expression: 100
                                        * Referenced by: '<Root>/N'
                                        */
  real_T OutputLowerLimit_Value;       /* Expression: -1
                                        * Referenced by: '<Root>/Output Lower Limit'
                                        */
  real_T OutputvoltagetoPWM1_Gain;     /* Expression: 10.7
                                        * Referenced by: '<Root>/Output voltage to PWM1'
                                        */
  real_T OutputvoltagetoPWM_Gain;      /* Expression: 1000/10.7
                                        * Referenced by: '<Root>/Output voltage to PWM'
                                        */
  real_T IGain_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/I Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motorkitc2000_with_co_T {
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

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_motorkitc2000_with_controll_T motorkitc2000_with_controller_P;

/* Block signals (default storage) */
extern B_motorkitc2000_with_controll_T motorkitc2000_with_controller_B;

/* Block states (default storage) */
extern DW_motorkitc2000_with_control_T motorkitc2000_with_controlle_DW;

/* External function called from main */
extern void motorkitc2000_with_controller_working_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void motorkitc2000_with_controller_working_initialize(void);
extern void motorkitc2000_with_controller_working_step0(void);
extern void motorkitc2000_with_controller_working_step1(void);
extern void motorkitc2000_with_controller_working_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motorkitc2000_with_c_T *const motorkitc2000_with_controlle_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Propagation' : Unused code path elimination
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
 * '<Root>' : 'motorkitc2000_with_controller_working'
 * '<S1>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID'
 * '<S2>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID/Anti-windup'
 * '<S3>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID/D Gain'
 * '<S4>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID/Filter'
 * '<S5>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID/Filter ICs'
 * '<S6>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID/I Gain'
 * '<S7>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID/Ideal P Gain'
 * '<S8>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S9>'   : 'motorkitc2000_with_controller_working/Discrete Varying PID/Integrator'
 * '<S10>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Integrator ICs'
 * '<S11>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/N Copy'
 * '<S12>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/N Gain'
 * '<S13>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/P Copy'
 * '<S14>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Parallel P Gain'
 * '<S15>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Reset Signal'
 * '<S16>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Saturation'
 * '<S17>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Saturation Fdbk'
 * '<S18>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Sum'
 * '<S19>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Sum Fdbk'
 * '<S20>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Tracking Mode'
 * '<S21>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Tracking Mode Sum'
 * '<S22>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Tsamp - Integral'
 * '<S23>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Tsamp - Ngain'
 * '<S24>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/postSat Signal'
 * '<S25>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/preSat Signal'
 * '<S26>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Anti-windup/Passthrough'
 * '<S27>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/D Gain/External Parameters'
 * '<S28>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Filter/Disc. Forward Euler Filter'
 * '<S29>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Filter ICs/Internal IC - Filter'
 * '<S30>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/I Gain/External Parameters'
 * '<S31>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S32>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Integrator/Discrete'
 * '<S34>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Integrator ICs/Internal IC'
 * '<S35>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/N Copy/Disabled'
 * '<S36>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/N Gain/External Parameters'
 * '<S37>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/P Copy/Disabled'
 * '<S38>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S39>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Reset Signal/Disabled'
 * '<S40>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Saturation/External'
 * '<S41>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Saturation/External/Saturation Dynamic'
 * '<S42>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S43>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Sum/Sum_PID'
 * '<S44>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S45>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S46>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S47>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Tsamp - Integral/Passthrough'
 * '<S48>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S49>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S50>'  : 'motorkitc2000_with_controller_working/Discrete Varying PID/preSat Signal/Forward_Path'
 */
#endif                 /* RTW_HEADER_motorkitc2000_with_controller_working_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
