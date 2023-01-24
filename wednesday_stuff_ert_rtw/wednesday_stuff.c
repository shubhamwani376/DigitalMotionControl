/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff.c
 *
 * Code generated for Simulink model 'wednesday_stuff'.
 *
 * Model version                  : 2.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jan 23 19:10:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "wednesday_stuff.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rtwtypes.h"
#include "wednesday_stuff_private.h"
#include <string.h>

/* Block signals (default storage) */
B_wednesday_stuff_T wednesday_stuff_B;

/* Block states (default storage) */
DW_wednesday_stuff_T wednesday_stuff_DW;

/* Real-time model */
static RT_MODEL_wednesday_stuff_T wednesday_stuff_M_;
RT_MODEL_wednesday_stuff_T *const wednesday_stuff_M = &wednesday_stuff_M_;

/* Model step function */
void wednesday_stuff_step(void)
{
  real_T rtb_Sum;
  real_T rtb_SystemMatrix_g;
  real_T rtb_SystemMatrix_i;
  real_T yTemp;

  /* Step: '<Root>/r' */
  if (wednesday_stuff_M->Timing.taskTime0 < wednesday_stuff_P.r_Time) {
    /* Step: '<Root>/r' */
    wednesday_stuff_B.r = wednesday_stuff_P.r_Y0;
  } else {
    /* Step: '<Root>/r' */
    wednesday_stuff_B.r = wednesday_stuff_P.Stepsize;
  }

  /* End of Step: '<Root>/r' */

  /* SignalConversion generated from: '<Root>/Mux1' */
  wednesday_stuff_B.TmpSignalConversionAtTAQSigLogg[0] = 0.0;
  wednesday_stuff_B.TmpSignalConversionAtTAQSigLogg[1] = 0.0;
  wednesday_stuff_B.TmpSignalConversionAtTAQSigLogg[2] = wednesday_stuff_B.r;
  wednesday_stuff_B.TmpSignalConversionAtTAQSigLogg[3] = 0.0;

  /* Gain: '<S1>/System Matrix' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_SystemMatrix_g = wednesday_stuff_P.A_d[0] *
    wednesday_stuff_DW.UnitDelay_DSTATE[0] +
    wednesday_stuff_DW.UnitDelay_DSTATE[1] * wednesday_stuff_P.A_d[2];
  rtb_SystemMatrix_i = wednesday_stuff_DW.UnitDelay_DSTATE[0] *
    wednesday_stuff_P.A_d[1] + wednesday_stuff_DW.UnitDelay_DSTATE[1] *
    wednesday_stuff_P.A_d[3];

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<Root>/Feedback Gain3'
   *  Gain: '<Root>/Feedback Gain4'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  wednesday_stuff_B.Sum3 = wednesday_stuff_P.N * wednesday_stuff_B.r -
    (wednesday_stuff_P.K_SF[0] * wednesday_stuff_DW.UnitDelay_DSTATE[0] +
     wednesday_stuff_P.K_SF[1] * wednesday_stuff_DW.UnitDelay_DSTATE[1]);

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  {
    if (wednesday_stuff_P.Constant1_Value) {
      GpioDataRegs.GPASET.bit.GPIO2 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO2 = 1U;
    }
  }

  /* S-Function (c280xqep): '<Root>/eQEP' */
  {
    wednesday_stuff_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/

    /* V1.1 Added UPEVNT (bit 7) This reflects changes made as of F280x Rev A devices==>Currently, our target board "TMS320F2808eZdsp" is Rev 0.
     *         if(EQep1Regs.QEPSTS.bit.UPEVNT==1U){
     */
    if (EQep1Regs.QEPSTS.bit.COEF ==0U && EQep1Regs.QEPSTS.bit.CDEF ==0U)
      wednesday_stuff_B.eQEP_o2 = EQep1Regs.QCPRD;
                   /* eQEP Capture Period (QCPRD) Register : No Capture overflow
                      else
                      wednesday_stuff_B.eQEP_o2 = 65535;      eQEP Capture Period (QCPRD) Register : Capture overflow, saturate the result
                      EQep1Regs.QEPSTS.bit.UPEVNT==1U;
                      }*/
    if (EQep1Regs.QEPSTS.bit.COEF ==1U)
      EQep1Regs.QEPSTS.bit.COEF = 1U;
    if (EQep1Regs.QEPSTS.bit.CDEF ==1U)
      EQep1Regs.QEPSTS.bit.CDEF = 1U;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_Sum = wednesday_stuff_P.Constant3_Value + wednesday_stuff_B.eQEP_o1;

  /* MATLABSystem: '<Root>/Modulo by Constant' */
  if (rtIsNaN(rtb_Sum) || rtIsInf(rtb_Sum)) {
    yTemp = (rtNaN);
  } else if (rtb_Sum == 0.0) {
    yTemp = 0.0;
  } else {
    yTemp = fmod(rtb_Sum, 400.0);
    if (yTemp == 0.0) {
      yTemp = 0.0;
    } else if (rtb_Sum < 0.0) {
      yTemp += 400.0;
    }
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Modulo by Constant'
   */
  wednesday_stuff_B.Gain = wednesday_stuff_P.Gain_Gain * yTemp;

  /* DiscreteFir: '<Root>/Discrete FIR Filter2' */
  wednesday_stuff_B.DiscreteFIRFilter2 = wednesday_stuff_B.Gain *
    wednesday_stuff_P.DiscreteFIRFilter2_Coefficients;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/Output Matrix'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Sum = wednesday_stuff_B.DiscreteFIRFilter2 - (wednesday_stuff_P.C_d[0] *
    wednesday_stuff_DW.UnitDelay_DSTATE[0] + wednesday_stuff_P.C_d[1] *
    wednesday_stuff_DW.UnitDelay_DSTATE[1]);

  /* Gain: '<S1>/Observer Gain' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  wednesday_stuff_DW.UnitDelay_DSTATE[0] = wednesday_stuff_P.L_Pred[0] * rtb_Sum;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Gain: '<S1>/Input Matrix'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  wednesday_stuff_DW.UnitDelay_DSTATE[0] = (wednesday_stuff_P.B_d[0] *
    wednesday_stuff_B.Sum3 + wednesday_stuff_DW.UnitDelay_DSTATE[0]) +
    rtb_SystemMatrix_g;

  /* Gain: '<S1>/Observer Gain' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  wednesday_stuff_DW.UnitDelay_DSTATE[1] = wednesday_stuff_P.L_Pred[1] * rtb_Sum;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Gain: '<S1>/Input Matrix'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  wednesday_stuff_DW.UnitDelay_DSTATE[1] = (wednesday_stuff_P.B_d[1] *
    wednesday_stuff_B.Sum3 + wednesday_stuff_DW.UnitDelay_DSTATE[1]) +
    rtb_SystemMatrix_i;

  /* SignalConversion generated from: '<Root>/Mux5' */
  wednesday_stuff_B.TmpSignalConversionAtTAQSigLo_d[0] = 0.0;
  wednesday_stuff_B.TmpSignalConversionAtTAQSigLo_d[1] =
    wednesday_stuff_B.DiscreteFIRFilter2;

  /* SignalConversion generated from: '<Root>/Mux3' */
  wednesday_stuff_B.TmpSignalConversionAtTAQSigLo_n[0] = 0.0;
  wednesday_stuff_B.TmpSignalConversionAtTAQSigLo_n[1] = wednesday_stuff_B.Sum3;

  /* Constant: '<Root>/Constant2' */
  wednesday_stuff_B.Constant2 = wednesday_stuff_P.Constant2_Value;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Output voltage to PWM'
   *  Gain: '<Root>/Output voltage to PWM1'
   */
  wednesday_stuff_B.Sum1 = wednesday_stuff_P.OutputvoltagetoPWM1_Gain *
    wednesday_stuff_B.Sum3 * wednesday_stuff_P.OutputvoltagetoPWM_Gain +
    wednesday_stuff_B.Constant2;

  /* S-Function (c2802xpwm): '<Root>/ePWM2' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(wednesday_stuff_B.Sum1);
  }

  /* Constant: '<Root>/Constant' */
  wednesday_stuff_B.Constant = wednesday_stuff_P.Constant_Value;

  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  wednesday_stuff_M->Timing.taskTime0 =
    ((time_T)(++wednesday_stuff_M->Timing.clockTick0)) *
    wednesday_stuff_M->Timing.stepSize0;
}

/* Model initialize function */
void wednesday_stuff_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)wednesday_stuff_M, 0,
                sizeof(RT_MODEL_wednesday_stuff_T));
  rtmSetTFinal(wednesday_stuff_M, -1);
  wednesday_stuff_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  wednesday_stuff_M->Sizes.checksums[0] = (573981002U);
  wednesday_stuff_M->Sizes.checksums[1] = (2430837229U);
  wednesday_stuff_M->Sizes.checksums[2] = (4158659281U);
  wednesday_stuff_M->Sizes.checksums[3] = (2002511567U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    wednesday_stuff_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(wednesday_stuff_M->extModeInfo,
      &wednesday_stuff_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(wednesday_stuff_M->extModeInfo,
                        wednesday_stuff_M->Sizes.checksums);
    rteiSetTPtr(wednesday_stuff_M->extModeInfo, rtmGetTPtr(wednesday_stuff_M));
  }

  /* block I/O */
  (void) memset(((void *) &wednesday_stuff_B), 0,
                sizeof(B_wednesday_stuff_T));

  /* states (dwork) */
  (void) memset((void *)&wednesday_stuff_DW, 0,
                sizeof(DW_wednesday_stuff_T));

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

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  wednesday_stuff_DW.UnitDelay_DSTATE[0] =
    wednesday_stuff_P.UnitDelay_InitialCondition;
  wednesday_stuff_DW.UnitDelay_DSTATE[1] =
    wednesday_stuff_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void wednesday_stuff_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
