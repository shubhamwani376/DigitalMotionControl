/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_NL.h
 *
 * Code generated for Simulink model 'wednesday_stuff_NL'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Feb  9 11:53:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_wednesday_stuff_NL_h_
#define RTW_HEADER_wednesday_stuff_NL_h_
#ifndef wednesday_stuff_NL_COMMON_INCLUDES_
#define wednesday_stuff_NL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* wednesday_stuff_NL_COMMON_INCLUDES_ */

#include "wednesday_stuff_NL_types.h"
#include <float.h>
#include <math.h>
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
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
  real_T ZeroOrderHold2;               /* '<Root>/Zero-Order Hold2' */
  real_T TmpSignalConversionAtTAQSigLogg[4];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T eQEP_o1;                      /* '<Root>/eQEP' */
  real_T eQEP_o2;                      /* '<Root>/eQEP' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T TmpSignalConversionAtTAQSigLo_d[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux5_at_outport_0Inport1' */
  real_T TmpSignalConversionAtTAQSigLo_n[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' */
  real_T Diff;                         /* '<S1>/Diff' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T u;                            /* '<Root>/SOFC integral1' */
} B_wednesday_stuff_NL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T xhat[2];                      /* '<Root>/SOFC integral1' */
  real_T xint;                         /* '<Root>/SOFC integral1' */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[8192];
  } TransportDelay2_RWORK;             /* '<Root>/Transport Delay2' */

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
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<Root>/To Workspace5' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay2_PWORK;             /* '<Root>/Transport Delay2' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } ToWorkspace8_PWORK;                /* '<Root>/To Workspace8' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay2_IWORK;             /* '<Root>/Transport Delay2' */
} DW_wednesday_stuff_NL_T;

/* Parameters (default storage) */
struct P_wednesday_stuff_NL_T_ {
  real_T A_d[4];                       /* Variable: A_d
                                        * Referenced by: '<Root>/SOFC integral1'
                                        */
  real_T B_d[2];                       /* Variable: B_d
                                        * Referenced by: '<Root>/SOFC integral1'
                                        */
  real_T C_d[2];                       /* Variable: C_d
                                        * Referenced by: '<Root>/SOFC integral1'
                                        */
  real_T K_aug[3];                     /* Variable: K_aug
                                        * Referenced by: '<Root>/SOFC integral1'
                                        */
  real_T L_Pred[2];                    /* Variable: L_Pred
                                        * Referenced by: '<Root>/SOFC integral1'
                                        */
  real_T N;                            /* Variable: N
                                        * Referenced by: '<Root>/SOFC integral1'
                                        */
  real_T Tcomp;                        /* Variable: Tcomp
                                        * Referenced by: '<Root>/Transport Delay2'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
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
  real_T Constant2_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T TransportDelay2_InitOutput;   /* Expression: 0
                                        * Referenced by: '<Root>/Transport Delay2'
                                        */
  real_T OutputvoltagetoPWM1_Gain;     /* Expression: 10.5
                                        * Referenced by: '<Root>/Output voltage to PWM1'
                                        */
  real_T OutputvoltagetoPWM_Gain;      /* Expression: 1000/10.5
                                        * Referenced by: '<Root>/Output voltage to PWM'
                                        */
  real_T Constant_Value;               /* Expression: 958.0466360856269
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_wednesday_stuff_NL_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_wednesday_stuff_NL_T wednesday_stuff_NL_P;

/* Block signals (default storage) */
extern B_wednesday_stuff_NL_T wednesday_stuff_NL_B;

/* Block states (default storage) */
extern DW_wednesday_stuff_NL_T wednesday_stuff_NL_DW;

/* Model entry point functions */
extern void wednesday_stuff_NL_initialize(void);
extern void wednesday_stuff_NL_step(void);
extern void wednesday_stuff_NL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_wednesday_stuff_NL_T *const wednesday_stuff_NL_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Zero-Order Hold1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'wednesday_stuff_NL'
 * '<S1>'   : 'wednesday_stuff_NL/Discrete Derivative'
 * '<S2>'   : 'wednesday_stuff_NL/SOFC integral1'
 */
#endif                                 /* RTW_HEADER_wednesday_stuff_NL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
