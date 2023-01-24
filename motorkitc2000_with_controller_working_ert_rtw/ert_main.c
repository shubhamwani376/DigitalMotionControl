/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "xcp.h"
#include "ext_mode.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  motorkitc2000_with_controller_working_SetEventsForThisBaseStep(eventFlags);
  enableTimer0Interrupt();
  currentTime = (extmodeSimulationTime_T)
    ((motorkitc2000_with_controlle_M->Timing.clockTick0 * 1) + 0)
    ;
  motorkitc2000_with_controller_working_step0();

  /* Get model outputs here */

  /* Trigger External Mode event */
  extmodeEvent(0, currentTime);
  disableTimer0Interrupt();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    enableTimer0Interrupt();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      currentTime = (extmodeSimulationTime_T)
        ((motorkitc2000_with_controlle_M->Timing.clockTick1 * 10) + 0)
        ;
      motorkitc2000_with_controller_working_step1();

      /* Get model outputs here */

      /* Trigger External Mode event */
      extmodeEvent(1, currentTime);
      break;

     default :
      break;
    }

    disableTimer0Interrupt();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.001;
  float systemClock = 200;
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  c2000_flash_init();
  init_board();

#if defined(MW_EXEC_PROFILER_ON) || (defined(MW_EXTMODE_RUNNING) && !defined(XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME))

  hardwareTimer1Init();

#endif

  ;
  rtmSetErrorStatus(motorkitc2000_with_controlle_M, 0);

  /* Set Final Simulation Time in Ticks */
  errorCode = extmodeSetFinalSimulationTime((extmodeSimulationTime_T) -1);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  motorkitc2000_with_controller_working_initialize();
  globalInterruptDisable();
  globalInterruptEnable();

  /* External Mode initialization */
  errorCode = extmodeInit(motorkitc2000_with_controlle_M->extModeInfo,
    &rtmGetTFinal(motorkitc2000_with_controlle_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(motorkitc2000_with_controlle_M, true);
    }
  }

  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel = !extmodeSimulationComplete() && !extmodeStopRequested() &&
    !rtmGetStopRequested(motorkitc2000_with_controlle_M);
  enableTimer0Interrupt();
  config_ePWM_TBSync();
  globalInterruptEnable();
  while (runModel) {
    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    stopRequested = !(!extmodeSimulationComplete() && !extmodeStopRequested() &&
                      !rtmGetStopRequested(motorkitc2000_with_controlle_M));
    runModel = !(stopRequested);
    if (stopRequested)
      disableTimer0Interrupt();
  }

  /* Terminate model */
  motorkitc2000_with_controller_working_terminate();

  /* External Mode reset */
  extmodeReset();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
