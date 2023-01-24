/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  enableTimer0Interrupt();
  currentTime = (extmodeSimulationTime_T) wednesday_stuff_M->Timing.clockTick0;
  wednesday_stuff_step();

  /* Get model outputs here */

  /* Trigger External Mode event */
  extmodeEvent(0, currentTime);
  disableTimer0Interrupt();
  OverrunFlag--;
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
  rtmSetErrorStatus(wednesday_stuff_M, 0);

  /* Set Final Simulation Time in Ticks */
  errorCode = extmodeSetFinalSimulationTime((extmodeSimulationTime_T) -1);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  wednesday_stuff_initialize();
  globalInterruptDisable();
  globalInterruptEnable();

  /* External Mode initialization */
  errorCode = extmodeInit(wednesday_stuff_M->extModeInfo, &rtmGetTFinal
    (wednesday_stuff_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(wednesday_stuff_M, true);
    }
  }

  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel = !extmodeSimulationComplete() && !extmodeStopRequested() &&
    !rtmGetStopRequested(wednesday_stuff_M);
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
                      !rtmGetStopRequested(wednesday_stuff_M));
    runModel = !(stopRequested);
    if (stopRequested)
      disableTimer0Interrupt();
  }

  /* Terminate model */
  wednesday_stuff_terminate();

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
