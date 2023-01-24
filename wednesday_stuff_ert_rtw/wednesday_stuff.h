/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff.h
 *
 * Code generated for Simulink model 'wednesday_stuff'.
 *
 * Model version                  : 2.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jan 24 12:55:43 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_wednesday_stuff_h_
#define RTW_HEADER_wednesday_stuff_h_
#ifndef wednesday_stuff_COMMON_INCLUDES_
#define wednesday_stuff_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* wednesday_stuff_COMMON_INCLUDES_ */

#include "wednesday_stuff_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
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
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Diff;                         /* '<S1>/Diff' */
  real_T r;                            /* '<Root>/r' */
  real_T TmpSignalConversionAtTAQSigLogg[4];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T DiscreteFIRFilter2;           /* '<Root>/Discrete FIR Filter2' */
  real_T TmpSignalConversionAtTAQSigLo_d[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux5_at_outport_0Inport1' */
  real_T TmpSignalConversionAtTAQSigLo_n[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real32_T eQEP_o2;                    /* '<Root>/eQEP' */
} B_wednesday_stuff_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T UnitDelay_DSTATE[2];          /* '<S2>/Unit Delay' */
  real_T TmpRTBAtDiscreteFIRFilter2Inpor;/* synthesized block */
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
  } y_PWORK;                           /* '<Root>/y' */

  struct {
    void *LoggedData;
  } y_m_PWORK;                         /* '<Root>/y_m' */

  struct {
    void *LoggedData;
  } u_PWORK;                           /* '<Root>/u' */

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                /* '<Root>/To Workspace6' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace8_PWORK;                /* '<Root>/To Workspace8' */
} DW_wednesday_stuff_T;

/* Parameters (default storage) */
struct P_wednesday_stuff_T_ {
  real_T A_d[4];                       /* Variable: A_d
                                        * Referenced by: '<S2>/System Matrix'
                                        */
  real_T B_d[2];                       /* Variable: B_d
                                        * Referenced by: '<S2>/Input Matrix'
                                        */
  real_T C_d[2];                       /* Variable: C_d
                                        * Referenced by: '<S2>/Output Matrix'
                                        */
  real_T K_SF[2];                      /* Variable: K_SF
                                        * Referenced by: '<Root>/Feedback Gain3'
                                        */
  real_T L_Pred[2];                    /* Variable: L_Pred
                                        * Referenced by: '<S2>/Observer Gain'
                                        */
  real_T N;                            /* Variable: N
                                        * Referenced by: '<Root>/Feedback Gain4'
                                        */
  real_T Stepsize;                     /* Variable: Stepsize
                                        * Referenced by: '<Root>/r'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T Constant_Value;               /* Expression: 958.0466360856269
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: -100000
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain_Gain;                    /* Expression: 3.14159/400
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T r_Time;                       /* Expression: 1
                                        * Referenced by: '<Root>/r'
                                        */
  real_T r_Y0;                         /* Expression: 0
                                        * Referenced by: '<Root>/r'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T DiscreteFIRFilter2_InitialState;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete FIR Filter2'
                                          */
  real_T DiscreteFIRFilter2_Coefficients;/* Expression: [1]
                                          * Referenced by: '<Root>/Discrete FIR Filter2'
                                          */
  real_T OutputvoltagetoPWM1_Gain;     /* Expression: 10.7
                                        * Referenced by: '<Root>/Output voltage to PWM1'
                                        */
  real_T OutputvoltagetoPWM_Gain;      /* Expression: 1000/10.7
                                        * Referenced by: '<Root>/Output voltage to PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_wednesday_stuff_T {
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
extern P_wednesday_stuff_T wednesday_stuff_P;

/* Block signals (default storage) */
extern B_wednesday_stuff_T wednesday_stuff_B;

/* Block states (default storage) */
extern DW_wednesday_stuff_T wednesday_stuff_DW;

/* External function called from main */
extern void wednesday_stuff_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void wednesday_stuff_initialize(void);
extern void wednesday_stuff_step0(void);
extern void wednesday_stuff_step1(void);
extern void wednesday_stuff_terminate(void);

/* Real-time Model object */
extern RT_MODEL_wednesday_stuff_T *const wednesday_stuff_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Zero-Order Hold2' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'wednesday_stuff'
 * '<S1>'   : 'wednesday_stuff/Discrete Derivative'
 * '<S2>'   : 'wednesday_stuff/Observer2'
 */
#endif                                 /* RTW_HEADER_wednesday_stuff_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
