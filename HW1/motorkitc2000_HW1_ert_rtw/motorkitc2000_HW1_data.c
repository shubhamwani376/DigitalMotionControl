/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorkitc2000_HW1_data.c
 *
 * Code generated for Simulink model 'motorkitc2000_HW1'.
 *
 * Model version                  : 2.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb  1 17:33:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motorkitc2000_HW1.h"

/* Block parameters (default storage) */
P_motorkitc2000_HW1_T motorkitc2000_HW1_P = {
  /* Mask Parameter: ChirpSignal_T
   * Referenced by: '<S1>/targetTime'
   */
  50.0,

  /* Mask Parameter: ChirpSignal_f1
   * Referenced by:
   *   '<S1>/deltaFreq'
   *   '<S1>/initialFreq'
   */
  0.1,

  /* Mask Parameter: ChirpSignal_f2
   * Referenced by: '<S1>/deltaFreq'
   */
  20.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Gain'
   */
  0.5,

  /* Expression: 958.0466360856269
   * Referenced by: '<Root>/Constant'
   */
  958.04663608562691,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: -100000
   * Referenced by: '<Root>/Constant4'
   */
  -100000.0,

  /* Expression: 3.14159/400
   * Referenced by: '<Root>/Gain'
   */
  0.007853975,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant2'
   */
  1000.0,

  /* Expression: 10.48
   * Referenced by: '<Root>/Output voltage to PWM1'
   */
  10.48,

  /* Expression: 1000/10.48
   * Referenced by: '<Root>/Output voltage to PWM'
   */
  95.419847328244273
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
