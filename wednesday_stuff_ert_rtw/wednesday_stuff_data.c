/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_data.c
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

/* Block parameters (default storage) */
P_wednesday_stuff_T wednesday_stuff_P = {
  /* Variable: A_d
   * Referenced by: '<S1>/System Matrix'
   */
  { 1.0, 0.0, 0.000996792215877889, 0.99359129902113907 },

  /* Variable: B_d
   * Referenced by: '<S1>/Input Matrix'
   */
  { 0.0014301370877746109, 2.8572125197421783 },

  /* Variable: C_d
   * Referenced by: '<S1>/Output Matrix'
   */
  { 1.0, 0.0 },

  /* Variable: K_SF
   * Referenced by: '<Root>/Feedback Gain3'
   */
  { 0.44520354374441606, 0.010766278677044369 },

  /* Variable: L_Pred
   * Referenced by: '<S1>/Observer Gain'
   */
  { 0.92661511683893238, 212.37621901076648 },

  /* Variable: N
   * Referenced by: '<Root>/Feedback Gain4'
   */
  0.4452035437444164,

  /* Variable: Stepsize
   * Referenced by: '<Root>/r'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/r'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/r'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Expression: -100000
   * Referenced by: '<Root>/Constant3'
   */
  -100000.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 3.14159/400
   * Referenced by: '<Root>/Gain'
   */
  0.007853975,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete FIR Filter2'
   */
  0.0,

  /* Expression: [1]
   * Referenced by: '<Root>/Discrete FIR Filter2'
   */
  1.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant2'
   */
  1000.0,

  /* Expression: 10.7
   * Referenced by: '<Root>/Output voltage to PWM1'
   */
  10.7,

  /* Expression: 1000/10.7
   * Referenced by: '<Root>/Output voltage to PWM'
   */
  93.45794392523365,

  /* Expression: 958.0466360856269
   * Referenced by: '<Root>/Constant'
   */
  958.04663608562691
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
