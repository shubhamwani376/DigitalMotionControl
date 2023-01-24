/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorkitc2000_with_controller_working_private.h
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

#ifndef RTW_HEADER_motorkitc2000_with_controller_working_private_h_
#define RTW_HEADER_motorkitc2000_with_controller_working_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "motorkitc2000_with_controller_working_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void config_QEP_eQEP1(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);

#endif         /* RTW_HEADER_motorkitc2000_with_controller_working_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
