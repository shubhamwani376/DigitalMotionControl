/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_NL.c
 *
 * Code generated for Simulink model 'wednesday_stuff_NL'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jan 24 13:00:36 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "wednesday_stuff_NL.h"
#include "rtwtypes.h"
#include "wednesday_stuff_NL_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Block signals (default storage) */
B_wednesday_stuff_NL_T wednesday_stuff_NL_B;

/* Block states (default storage) */
DW_wednesday_stuff_NL_T wednesday_stuff_NL_DW;

/* Real-time model */
static RT_MODEL_wednesday_stuff_NL_T wednesday_stuff_NL_M_;
RT_MODEL_wednesday_stuff_NL_T *const wednesday_stuff_NL_M =
  &wednesday_stuff_NL_M_;
static void rate_monotonic_scheduler(void);

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 * (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 * (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;
  real_T* tBuf = uBuf + bufSz;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void wednesday_stuff_NL_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(wednesday_stuff_NL_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(wednesday_stuff_NL_M, 3));
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

  /* tid 1 shares data with slower tid rates: 2, 3 */
  if (wednesday_stuff_NL_M->Timing.TaskCounters.TID[1] == 0) {
    wednesday_stuff_NL_M->Timing.RateInteraction.TID1_2 =
      (wednesday_stuff_NL_M->Timing.TaskCounters.TID[2] == 0);
    wednesday_stuff_NL_M->Timing.RateInteraction.TID1_3 =
      (wednesday_stuff_NL_M->Timing.TaskCounters.TID[3] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (wednesday_stuff_NL_M->Timing.TaskCounters.TID[2])++;
  if ((wednesday_stuff_NL_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.001s, 0.0s] */
    wednesday_stuff_NL_M->Timing.TaskCounters.TID[2] = 0;
  }

  (wednesday_stuff_NL_M->Timing.TaskCounters.TID[3])++;
  if ((wednesday_stuff_NL_M->Timing.TaskCounters.TID[3]) > 1999) {/* Sample time: [0.1s, 0.0s] */
    wednesday_stuff_NL_M->Timing.TaskCounters.TID[3] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void wednesday_stuff_NL_step0(void)    /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_TransportDelay1;
  real_T acc1;
  int32_T cff;
  int32_T j;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Constant: '<Root>/Constant' */
  wednesday_stuff_NL_B.Constant = wednesday_stuff_NL_P.Constant_Value;

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  {
    if (wednesday_stuff_NL_P.Constant1_Value) {
      GpioDataRegs.GPASET.bit.GPIO2 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO2 = 1U;
    }
  }

  /* Constant: '<Root>/Constant2' */
  wednesday_stuff_NL_B.Constant2 = wednesday_stuff_NL_P.Constant2_Value;

  /* TransportDelay: '<Root>/Transport Delay1' */
  {
    real_T **uBuffer = (real_T**)
      &wednesday_stuff_NL_DW.TransportDelay1_PWORK.TUbufferPtrs[0];
    real_T simTime = wednesday_stuff_NL_M->Timing.t[0];
    real_T tMinusDelay = simTime - wednesday_stuff_NL_P.Tcomp;
    rtb_TransportDelay1 = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *uBuffer,
      wednesday_stuff_NL_DW.TransportDelay1_IWORK.CircularBufSize,
      &wednesday_stuff_NL_DW.TransportDelay1_IWORK.Last,
      wednesday_stuff_NL_DW.TransportDelay1_IWORK.Tail,
      wednesday_stuff_NL_DW.TransportDelay1_IWORK.Head,
      wednesday_stuff_NL_P.TransportDelay1_InitOutput,
      1,
      0);
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Output voltage to PWM'
   *  Gain: '<Root>/Output voltage to PWM1'
   */
  wednesday_stuff_NL_B.Sum1 = wednesday_stuff_NL_P.OutputvoltagetoPWM1_Gain *
    rtb_TransportDelay1 * wednesday_stuff_NL_P.OutputvoltagetoPWM_Gain +
    wednesday_stuff_NL_B.Constant2;

  /* S-Function (c2802xpwm): '<Root>/ePWM2' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(wednesday_stuff_NL_B.Sum1);
  }

  /* RateTransition generated from: '<Root>/Discrete FIR Filter' */
  if (wednesday_stuff_NL_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition generated from: '<Root>/Discrete FIR Filter' */
    wednesday_stuff_NL_B.TmpRTBAtDiscreteFIRFilterInport =
      wednesday_stuff_NL_DW.TmpRTBAtDiscreteFIRFilterInport;
  }

  /* End of RateTransition generated from: '<Root>/Discrete FIR Filter' */

  /* Quantizer: '<Root>/Quantizer' incorporates:
   *  DiscreteFir: '<Root>/Discrete FIR Filter'
   */
  wednesday_stuff_NL_B.Quantizer =
    wednesday_stuff_NL_B.TmpRTBAtDiscreteFIRFilterInport *
    wednesday_stuff_NL_P.DiscreteFIRFilter_Coefficients;
  wednesday_stuff_NL_B.Quantizer = rt_roundd_snf(wednesday_stuff_NL_B.Quantizer /
    wednesday_stuff_NL_P.encoder_resolution) *
    wednesday_stuff_NL_P.encoder_resolution;

  /* DiscreteFir: '<Root>/Discrete FIR Filter2' */
  acc1 = wednesday_stuff_NL_B.Quantizer *
    wednesday_stuff_NL_P.DiscreteFIRFilter2_Coefficients[0];
  cff = 1L;
  for (j = wednesday_stuff_NL_DW.DiscreteFIRFilter2_circBuf; j < 3L; j++) {
    acc1 += wednesday_stuff_NL_DW.DiscreteFIRFilter2_states[j] *
      wednesday_stuff_NL_P.DiscreteFIRFilter2_Coefficients[cff];
    cff++;
  }

  for (j = 0L; j < wednesday_stuff_NL_DW.DiscreteFIRFilter2_circBuf; j++) {
    acc1 += wednesday_stuff_NL_DW.DiscreteFIRFilter2_states[j] *
      wednesday_stuff_NL_P.DiscreteFIRFilter2_Coefficients[cff];
    cff++;
  }

  /* RateTransition generated from: '<Root>/Discrete FIR Filter3' incorporates:
   *  DiscreteFir: '<Root>/Discrete FIR Filter2'
   */
  if (wednesday_stuff_NL_M->Timing.RateInteraction.TID1_3) {
    wednesday_stuff_NL_DW.TmpRTBAtDiscreteFIRFilter3Inpor = acc1;

    /* RateTransition generated from: '<Root>/Transport Delay1' incorporates:
     *  DiscreteFir: '<Root>/Discrete FIR Filter2'
     */
    wednesday_stuff_NL_B.TmpRTBAtTransportDelay1Inport1 =
      wednesday_stuff_NL_DW.TmpRTBAtTransportDelay1Inport1_;
  }

  /* End of RateTransition generated from: '<Root>/Discrete FIR Filter3' */

  /* Update for TransportDelay: '<Root>/Transport Delay1' */
  {
    real_T **uBuffer = (real_T**)
      &wednesday_stuff_NL_DW.TransportDelay1_PWORK.TUbufferPtrs[0];
    real_T simTime = wednesday_stuff_NL_M->Timing.t[0];
    wednesday_stuff_NL_DW.TransportDelay1_IWORK.Head =
      ((wednesday_stuff_NL_DW.TransportDelay1_IWORK.Head <
        (wednesday_stuff_NL_DW.TransportDelay1_IWORK.CircularBufSize-1)) ?
       (wednesday_stuff_NL_DW.TransportDelay1_IWORK.Head+1) : 0);
    if (wednesday_stuff_NL_DW.TransportDelay1_IWORK.Head ==
        wednesday_stuff_NL_DW.TransportDelay1_IWORK.Tail) {
      wednesday_stuff_NL_DW.TransportDelay1_IWORK.Tail =
        ((wednesday_stuff_NL_DW.TransportDelay1_IWORK.Tail <
          (wednesday_stuff_NL_DW.TransportDelay1_IWORK.CircularBufSize-1)) ?
         (wednesday_stuff_NL_DW.TransportDelay1_IWORK.Tail+1) : 0);
    }

    (*uBuffer + wednesday_stuff_NL_DW.TransportDelay1_IWORK.CircularBufSize)
      [wednesday_stuff_NL_DW.TransportDelay1_IWORK.Head] = simTime;
    (*uBuffer)[wednesday_stuff_NL_DW.TransportDelay1_IWORK.Head] =
      wednesday_stuff_NL_B.TmpRTBAtTransportDelay1Inport1;
  }

  /* Update for DiscreteFir: '<Root>/Discrete FIR Filter2' */
  /* Update circular buffer index */
  wednesday_stuff_NL_DW.DiscreteFIRFilter2_circBuf--;
  if (wednesday_stuff_NL_DW.DiscreteFIRFilter2_circBuf < 0L) {
    wednesday_stuff_NL_DW.DiscreteFIRFilter2_circBuf = 2L;
  }

  /* Update circular buffer */
  wednesday_stuff_NL_DW.DiscreteFIRFilter2_states[wednesday_stuff_NL_DW.DiscreteFIRFilter2_circBuf]
    = wednesday_stuff_NL_B.Quantizer;

  /* End of Update for DiscreteFir: '<Root>/Discrete FIR Filter2' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  wednesday_stuff_NL_M->Timing.t[0] =
    ((time_T)(++wednesday_stuff_NL_M->Timing.clockTick0)) *
    wednesday_stuff_NL_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 5.0E-5, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  wednesday_stuff_NL_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void wednesday_stuff_NL_step2(void)    /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_Sum;
  real_T yTemp;

  /* S-Function (c280xqep): '<Root>/eQEP' */
  {
    wednesday_stuff_NL_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/

    /* V1.1 Added UPEVNT (bit 7) This reflects changes made as of F280x Rev A devices==>Currently, our target board "TMS320F2808eZdsp" is Rev 0.
     *         if(EQep1Regs.QEPSTS.bit.UPEVNT==1U){
     */
    if (EQep1Regs.QEPSTS.bit.COEF ==0U && EQep1Regs.QEPSTS.bit.CDEF ==0U)
      wednesday_stuff_NL_B.eQEP_o2 = EQep1Regs.QCPRD;
                   /* eQEP Capture Period (QCPRD) Register : No Capture overflow
                      else
                      wednesday_stuff_NL_B.eQEP_o2 = 65535;      eQEP Capture Period (QCPRD) Register : Capture overflow, saturate the result
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
  rtb_Sum = wednesday_stuff_NL_P.Constant3_Value + wednesday_stuff_NL_B.eQEP_o1;

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
  wednesday_stuff_NL_B.Gain = wednesday_stuff_NL_P.Gain_Gain * yTemp;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = wednesday_stuff_NL_B.Gain * wednesday_stuff_NL_P.TSamp_WtEt;

  /* Sum: '<S1>/Diff' incorporates:
   *  UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  wednesday_stuff_NL_B.Diff = rtb_TSamp - wednesday_stuff_NL_DW.UD_DSTATE;

  /* RateTransition generated from: '<Root>/Discrete FIR Filter' */
  wednesday_stuff_NL_DW.TmpRTBAtDiscreteFIRFilterInport =
    wednesday_stuff_NL_B.Gain;

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  wednesday_stuff_NL_DW.UD_DSTATE = rtb_TSamp;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  wednesday_stuff_NL_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void wednesday_stuff_NL_step3(void)    /* Sample time: [0.1s, 0.0s] */
{
  real_T u1;
  real_T u_unsat;

  /* Step: '<Root>/r' */
  if (((wednesday_stuff_NL_M->Timing.clockTick3) * 0.1) <
      wednesday_stuff_NL_P.r_Time) {
    /* Step: '<Root>/r' */
    wednesday_stuff_NL_B.r = wednesday_stuff_NL_P.r_Y0;
  } else {
    /* Step: '<Root>/r' */
    wednesday_stuff_NL_B.r = wednesday_stuff_NL_P.Stepsize;
  }

  /* End of Step: '<Root>/r' */

  /* SignalConversion generated from: '<Root>/Mux1' */
  wednesday_stuff_NL_B.TmpSignalConversionAtTAQSigLogg[0] = 0.0;
  wednesday_stuff_NL_B.TmpSignalConversionAtTAQSigLogg[1] = 0.0;
  wednesday_stuff_NL_B.TmpSignalConversionAtTAQSigLogg[2] =
    wednesday_stuff_NL_B.r;
  wednesday_stuff_NL_B.TmpSignalConversionAtTAQSigLogg[3] = 0.0;

  /* DiscreteFir: '<Root>/Discrete FIR Filter3' incorporates:
   *  RateTransition generated from: '<Root>/Discrete FIR Filter3'
   */
  wednesday_stuff_NL_B.DiscreteFIRFilter3 =
    wednesday_stuff_NL_DW.TmpRTBAtDiscreteFIRFilter3Inpor *
    wednesday_stuff_NL_P.DiscreteFIRFilter3_Coefficients;

  /* SignalConversion generated from: '<Root>/Mux5' */
  wednesday_stuff_NL_B.TmpSignalConversionAtTAQSigLo_d[0] =
    wednesday_stuff_NL_B.DiscreteFIRFilter3;
  wednesday_stuff_NL_B.TmpSignalConversionAtTAQSigLo_d[1] = 0.0;

  /* MATLAB Function: '<Root>/SOFC' */
  u_unsat = (-wednesday_stuff_NL_P.K_SF[0] * wednesday_stuff_NL_DW.xhat[0] +
             -wednesday_stuff_NL_P.K_SF[1] * wednesday_stuff_NL_DW.xhat[1]) +
    wednesday_stuff_NL_P.N * wednesday_stuff_NL_B.r;
  u1 = fabs(u_unsat);
  if (rtIsNaN(u_unsat)) {
    u_unsat = (rtNaN);
  } else if (u_unsat < 0.0) {
    u_unsat = -1.0;
  } else {
    u_unsat = (u_unsat > 0.0);
  }

  if ((u1 >= 1.0) || rtIsNaN(u1)) {
    u1 = 1.0;
  }

  wednesday_stuff_NL_B.u = u_unsat * u1;
  u_unsat = (wednesday_stuff_NL_P.A_d[0] - wednesday_stuff_NL_P.L_Pred[0] *
             wednesday_stuff_NL_P.C_d[0]) * wednesday_stuff_NL_DW.xhat[0] +
    (wednesday_stuff_NL_P.A_d[2] - wednesday_stuff_NL_P.L_Pred[0] *
     wednesday_stuff_NL_P.C_d[1]) * wednesday_stuff_NL_DW.xhat[1];
  u1 = (wednesday_stuff_NL_P.A_d[1] - wednesday_stuff_NL_P.C_d[0] *
        wednesday_stuff_NL_P.L_Pred[1]) * wednesday_stuff_NL_DW.xhat[0] +
    (wednesday_stuff_NL_P.A_d[3] - wednesday_stuff_NL_P.L_Pred[1] *
     wednesday_stuff_NL_P.C_d[1]) * wednesday_stuff_NL_DW.xhat[1];
  wednesday_stuff_NL_DW.xhat[0] = (wednesday_stuff_NL_P.B_d[0] *
    wednesday_stuff_NL_B.u + u_unsat) + wednesday_stuff_NL_P.L_Pred[0] *
    wednesday_stuff_NL_B.DiscreteFIRFilter3;
  wednesday_stuff_NL_DW.xhat[1] = (wednesday_stuff_NL_P.B_d[1] *
    wednesday_stuff_NL_B.u + u1) + wednesday_stuff_NL_P.L_Pred[1] *
    wednesday_stuff_NL_B.DiscreteFIRFilter3;

  /* End of MATLAB Function: '<Root>/SOFC' */

  /* SignalConversion generated from: '<Root>/Mux3' */
  wednesday_stuff_NL_B.TmpSignalConversionAtTAQSigLo_n[0] =
    wednesday_stuff_NL_B.u;
  wednesday_stuff_NL_B.TmpSignalConversionAtTAQSigLo_n[1] = 0.0;

  /* RateTransition generated from: '<Root>/Transport Delay1' */
  wednesday_stuff_NL_DW.TmpRTBAtTransportDelay1Inport1_ = wednesday_stuff_NL_B.u;

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   */
  wednesday_stuff_NL_M->Timing.clockTick3++;
}

/* Model initialize function */
void wednesday_stuff_NL_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)wednesday_stuff_NL_M, 0,
                sizeof(RT_MODEL_wednesday_stuff_NL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&wednesday_stuff_NL_M->solverInfo,
                          &wednesday_stuff_NL_M->Timing.simTimeStep);
    rtsiSetTPtr(&wednesday_stuff_NL_M->solverInfo, &rtmGetTPtr
                (wednesday_stuff_NL_M));
    rtsiSetStepSizePtr(&wednesday_stuff_NL_M->solverInfo,
                       &wednesday_stuff_NL_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&wednesday_stuff_NL_M->solverInfo, (&rtmGetErrorStatus
      (wednesday_stuff_NL_M)));
    rtsiSetRTModelPtr(&wednesday_stuff_NL_M->solverInfo, wednesday_stuff_NL_M);
  }

  rtsiSetSimTimeStep(&wednesday_stuff_NL_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&wednesday_stuff_NL_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(wednesday_stuff_NL_M, &wednesday_stuff_NL_M->Timing.tArray[0]);
  rtmSetTFinal(wednesday_stuff_NL_M, -1);
  wednesday_stuff_NL_M->Timing.stepSize0 = 5.0E-5;

  /* External mode info */
  wednesday_stuff_NL_M->Sizes.checksums[0] = (3381102501U);
  wednesday_stuff_NL_M->Sizes.checksums[1] = (1628600379U);
  wednesday_stuff_NL_M->Sizes.checksums[2] = (878028338U);
  wednesday_stuff_NL_M->Sizes.checksums[3] = (283144907U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    wednesday_stuff_NL_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(wednesday_stuff_NL_M->extModeInfo,
      &wednesday_stuff_NL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(wednesday_stuff_NL_M->extModeInfo,
                        wednesday_stuff_NL_M->Sizes.checksums);
    rteiSetTPtr(wednesday_stuff_NL_M->extModeInfo, rtmGetTPtr
                (wednesday_stuff_NL_M));
  }

  /* block I/O */
  (void) memset(((void *) &wednesday_stuff_NL_B), 0,
                sizeof(B_wednesday_stuff_NL_T));

  /* states (dwork) */
  (void) memset((void *)&wednesday_stuff_NL_DW, 0,
                sizeof(DW_wednesday_stuff_NL_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPADIR.all |= 0x4U;
  EDIS;

  /* Start for TransportDelay: '<Root>/Transport Delay1' */
  {
    real_T *pBuffer = &wednesday_stuff_NL_DW.TransportDelay1_RWORK.TUbufferArea
      [0];
    wednesday_stuff_NL_DW.TransportDelay1_IWORK.Tail = 0;
    wednesday_stuff_NL_DW.TransportDelay1_IWORK.Head = 0;
    wednesday_stuff_NL_DW.TransportDelay1_IWORK.Last = 0;
    wednesday_stuff_NL_DW.TransportDelay1_IWORK.CircularBufSize = 4096;
    pBuffer[0] = wednesday_stuff_NL_P.TransportDelay1_InitOutput;
    pBuffer[4096] = wednesday_stuff_NL_M->Timing.t[0];
    wednesday_stuff_NL_DW.TransportDelay1_PWORK.TUbufferPtrs[0] = (void *)
      &pBuffer[0];
  }

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

  /* Start for RateTransition generated from: '<Root>/Discrete FIR Filter' */
  wednesday_stuff_NL_B.TmpRTBAtDiscreteFIRFilterInport =
    wednesday_stuff_NL_P.TmpRTBAtDiscreteFIRFilterInport;

  /* Start for RateTransition generated from: '<Root>/Transport Delay1' */
  wednesday_stuff_NL_B.TmpRTBAtTransportDelay1Inport1 =
    wednesday_stuff_NL_P.TmpRTBAtTransportDelay1Inport1_;

  /* Start for S-Function (c280xqep): '<Root>/eQEP' */
  config_QEP_eQEP1((uint32_T)4294967295U,(uint32_T)100000U, (uint32_T)0,
                   (uint32_T)0,
                   (uint16_T)0, (uint16_T)0, (uint16_T)4232, (uint16_T)32768,
                   (uint16_T)32864,(uint16_T)0);

  /* InitializeConditions for RateTransition generated from: '<Root>/Discrete FIR Filter' */
  wednesday_stuff_NL_DW.TmpRTBAtDiscreteFIRFilterInport =
    wednesday_stuff_NL_P.TmpRTBAtDiscreteFIRFilterInport;

  /* InitializeConditions for DiscreteFir: '<Root>/Discrete FIR Filter2' */
  wednesday_stuff_NL_DW.DiscreteFIRFilter2_circBuf = 0L;
  wednesday_stuff_NL_DW.DiscreteFIRFilter2_states[0] =
    wednesday_stuff_NL_P.DiscreteFIRFilter2_InitialState;
  wednesday_stuff_NL_DW.DiscreteFIRFilter2_states[1] =
    wednesday_stuff_NL_P.DiscreteFIRFilter2_InitialState;
  wednesday_stuff_NL_DW.DiscreteFIRFilter2_states[2] =
    wednesday_stuff_NL_P.DiscreteFIRFilter2_InitialState;

  /* InitializeConditions for RateTransition generated from: '<Root>/Transport Delay1' */
  wednesday_stuff_NL_DW.TmpRTBAtTransportDelay1Inport1_ =
    wednesday_stuff_NL_P.TmpRTBAtTransportDelay1Inport1_;

  /* InitializeConditions for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  wednesday_stuff_NL_DW.UD_DSTATE =
    wednesday_stuff_NL_P.DiscreteDerivative_ICPrevScaled;

  /* SystemInitialize for MATLAB Function: '<Root>/SOFC' */
  wednesday_stuff_NL_DW.xhat[0] = 0.0;
  wednesday_stuff_NL_DW.xhat[1] = 0.0;
}

/* Model terminate function */
void wednesday_stuff_NL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
