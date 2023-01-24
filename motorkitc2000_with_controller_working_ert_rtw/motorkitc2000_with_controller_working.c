/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorkitc2000_with_controller_working.c
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

#include "motorkitc2000_with_controller_working.h"
#include "rtwtypes.h"
#include "motorkitc2000_with_controller_working_private.h"
#include <string.h>

/* Block signals (default storage) */
B_motorkitc2000_with_controll_T motorkitc2000_with_controller_B;

/* Block states (default storage) */
DW_motorkitc2000_with_control_T motorkitc2000_with_controlle_DW;

/* Real-time model */
static RT_MODEL_motorkitc2000_with_c_T motorkitc2000_with_controlle_M_;
RT_MODEL_motorkitc2000_with_c_T *const motorkitc2000_with_controlle_M =
  &motorkitc2000_with_controlle_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void motorkitc2000_with_controller_working_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(motorkitc2000_with_controlle_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  motorkitc2000_with_controlle_M->Timing.RateInteraction.TID0_1 =
    (motorkitc2000_with_controlle_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (motorkitc2000_with_controlle_M->Timing.TaskCounters.TID[1])++;
  if ((motorkitc2000_with_controlle_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    motorkitc2000_with_controlle_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void motorkitc2000_with_controller_working_step0(void) /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Constant: '<Root>/Constant' */
  motorkitc2000_with_controller_B.Constant =
    motorkitc2000_with_controller_P.Constant_Value;

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  {
    if (motorkitc2000_with_controller_P.Constant1_Value) {
      GpioDataRegs.GPASET.bit.GPIO2 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO2 = 1U;
    }
  }

  /* S-Function (c280xqep): '<Root>/eQEP' */
  {
    motorkitc2000_with_controller_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/

    /* V1.1 Added UPEVNT (bit 7) This reflects changes made as of F280x Rev A devices==>Currently, our target board "TMS320F2808eZdsp" is Rev 0.
     *         if(EQep1Regs.QEPSTS.bit.UPEVNT==1U){
     */
    if (EQep1Regs.QEPSTS.bit.COEF ==0U && EQep1Regs.QEPSTS.bit.CDEF ==0U)
      motorkitc2000_with_controller_B.eQEP_o2 = EQep1Regs.QCPRD;
                   /* eQEP Capture Period (QCPRD) Register : No Capture overflow
                      else
                      motorkitc2000_with_controller_B.eQEP_o2 = 65535;      eQEP Capture Period (QCPRD) Register : Capture overflow, saturate the result
                      EQep1Regs.QEPSTS.bit.UPEVNT==1U;
                      }*/
    if (EQep1Regs.QEPSTS.bit.COEF ==1U)
      EQep1Regs.QEPSTS.bit.COEF = 1U;
    if (EQep1Regs.QEPSTS.bit.CDEF ==1U)
      EQep1Regs.QEPSTS.bit.CDEF = 1U;
  }

  /* Gain: '<Root>/Count to radian' */
  motorkitc2000_with_controller_B.Counttoradian =
    motorkitc2000_with_controller_P.Counttoradian_Gain *
    motorkitc2000_with_controller_B.eQEP_o1;

  /* Sum: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/Reference'
   */
  motorkitc2000_with_controller_B.Sum4 =
    motorkitc2000_with_controller_P.Reference_Value -
    motorkitc2000_with_controller_B.Counttoradian;

  /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
  if (motorkitc2000_with_controlle_M->Timing.RateInteraction.TID0_1) {
    /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
    motorkitc2000_with_controller_B.ZeroOrderHold =
      motorkitc2000_with_controller_B.Sum4;
  }

  /* End of ZeroOrderHold: '<Root>/Zero-Order Hold' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  motorkitc2000_with_controlle_M->Timing.taskTime0 =
    ((time_T)(++motorkitc2000_with_controlle_M->Timing.clockTick0)) *
    motorkitc2000_with_controlle_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void motorkitc2000_with_controller_working_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_NProdOut;
  real_T rtb_Sum;

  /* Constant: '<Root>/Constant2' */
  motorkitc2000_with_controller_B.Constant2 =
    motorkitc2000_with_controller_P.Constant2_Value;

  /* Constant: '<Root>/Output Upper Limit' */
  motorkitc2000_with_controller_B.OutputUpperLimit =
    motorkitc2000_with_controller_P.OutputUpperLimit_Value;

  /* Constant: '<Root>/P Gain' */
  motorkitc2000_with_controller_B.PGain =
    motorkitc2000_with_controller_P.PGain_Value;

  /* Constant: '<Root>/D Gain' */
  motorkitc2000_with_controller_B.DGain =
    motorkitc2000_with_controller_P.DGain_Value;

  /* Constant: '<Root>/N' */
  motorkitc2000_with_controller_B.N = motorkitc2000_with_controller_P.N_Value;

  /* Product: '<S36>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S28>/Filter'
   *  Product: '<S27>/DProd Out'
   *  Sum: '<S28>/SumD'
   */
  rtb_NProdOut = (motorkitc2000_with_controller_B.ZeroOrderHold *
                  motorkitc2000_with_controller_B.DGain -
                  motorkitc2000_with_controlle_DW.Filter_DSTATE) *
    motorkitc2000_with_controller_B.N;

  /* Sum: '<S43>/Sum' incorporates:
   *  DiscreteIntegrator: '<S33>/Integrator'
   *  Product: '<S38>/PProd Out'
   */
  rtb_Sum = (motorkitc2000_with_controller_B.ZeroOrderHold *
             motorkitc2000_with_controller_B.PGain +
             motorkitc2000_with_controlle_DW.Integrator_DSTATE) + rtb_NProdOut;

  /* Constant: '<Root>/Output Lower Limit' */
  motorkitc2000_with_controller_B.OutputLowerLimit =
    motorkitc2000_with_controller_P.OutputLowerLimit_Value;

  /* Switch: '<S41>/Switch2' incorporates:
   *  RelationalOperator: '<S41>/LowerRelop1'
   *  RelationalOperator: '<S41>/UpperRelop'
   *  Switch: '<S41>/Switch'
   */
  if (rtb_Sum > motorkitc2000_with_controller_B.OutputUpperLimit) {
    rtb_Sum = motorkitc2000_with_controller_B.OutputUpperLimit;
  } else if (rtb_Sum < motorkitc2000_with_controller_B.OutputLowerLimit) {
    /* Switch: '<S41>/Switch' */
    rtb_Sum = motorkitc2000_with_controller_B.OutputLowerLimit;
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Output voltage to PWM'
   *  Gain: '<Root>/Output voltage to PWM1'
   *  Switch: '<S41>/Switch2'
   */
  motorkitc2000_with_controller_B.Sum1 =
    motorkitc2000_with_controller_P.OutputvoltagetoPWM1_Gain * rtb_Sum *
    motorkitc2000_with_controller_P.OutputvoltagetoPWM_Gain +
    motorkitc2000_with_controller_B.Constant2;

  /* S-Function (c2802xpwm): '<Root>/ePWM2' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(motorkitc2000_with_controller_B.Sum1);
  }

  /* Constant: '<Root>/I Gain' */
  motorkitc2000_with_controller_B.IGain =
    motorkitc2000_with_controller_P.IGain_Value;

  /* Update for DiscreteIntegrator: '<S33>/Integrator' incorporates:
   *  Product: '<S30>/IProd Out'
   */
  motorkitc2000_with_controlle_DW.Integrator_DSTATE +=
    motorkitc2000_with_controller_B.ZeroOrderHold *
    motorkitc2000_with_controller_B.IGain *
    motorkitc2000_with_controller_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S28>/Filter' */
  motorkitc2000_with_controlle_DW.Filter_DSTATE +=
    motorkitc2000_with_controller_P.Filter_gainval * rtb_NProdOut;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  motorkitc2000_with_controlle_M->Timing.clockTick1++;
}

/* Model initialize function */
void motorkitc2000_with_controller_working_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motorkitc2000_with_controlle_M, 0,
                sizeof(RT_MODEL_motorkitc2000_with_c_T));
  rtmSetTFinal(motorkitc2000_with_controlle_M, -1);
  motorkitc2000_with_controlle_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  motorkitc2000_with_controlle_M->Sizes.checksums[0] = (1362512706U);
  motorkitc2000_with_controlle_M->Sizes.checksums[1] = (1707127318U);
  motorkitc2000_with_controlle_M->Sizes.checksums[2] = (1274559669U);
  motorkitc2000_with_controlle_M->Sizes.checksums[3] = (2725942872U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    motorkitc2000_with_controlle_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motorkitc2000_with_controlle_M->extModeInfo,
      &motorkitc2000_with_controlle_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motorkitc2000_with_controlle_M->extModeInfo,
                        motorkitc2000_with_controlle_M->Sizes.checksums);
    rteiSetTPtr(motorkitc2000_with_controlle_M->extModeInfo, rtmGetTPtr
                (motorkitc2000_with_controlle_M));
  }

  /* block I/O */
  (void) memset(((void *) &motorkitc2000_with_controller_B), 0,
                sizeof(B_motorkitc2000_with_controll_T));

  /* states (dwork) */
  (void) memset((void *)&motorkitc2000_with_controlle_DW, 0,
                sizeof(DW_motorkitc2000_with_control_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPADIR.all |= 0x4U;
  EDIS;

  /* Start for S-Function (c280xqep): '<Root>/eQEP' */
  config_QEP_eQEP1((uint32_T)4294967295U,(uint32_T)100000U, (uint32_T)0,
                   (uint32_T)0,
                   (uint16_T)0, (uint16_T)0, (uint16_T)4232, (uint16_T)32768,
                   (uint16_T)32864,(uint16_T)0);

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM2' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       EPwm1Regs.TBCTL.bit.SWFSYNC              = 0U;          // Software Force Sync Pulse
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 2000U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 1001U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 1001U;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 1000U;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Integrator' */
  motorkitc2000_with_controlle_DW.Integrator_DSTATE =
    motorkitc2000_with_controller_P.DiscreteVaryingPID_InitialCon_a;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Filter' */
  motorkitc2000_with_controlle_DW.Filter_DSTATE =
    motorkitc2000_with_controller_P.DiscreteVaryingPID_InitialCondi;
}

/* Model terminate function */
void motorkitc2000_with_controller_working_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
