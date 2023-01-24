/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorkitc2000_with_controller_working_data.c
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

/* Block parameters (default storage) */
P_motorkitc2000_with_controll_T motorkitc2000_with_controller_P = {
  /* Mask Parameter: DiscreteVaryingPID_InitialCondi
   * Referenced by: '<S28>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscreteVaryingPID_InitialCon_a
   * Referenced by: '<S33>/Integrator'
   */
  0.0,

  /* Expression: 958.0466360856269
   * Referenced by: '<Root>/Constant'
   */
  958.04663608562691,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 3.14159/200
   * Referenced by: '<Root>/Count to radian'
   */
  0.01570795,

  /* Expression: 100000*3.14159/200
   * Referenced by: '<Root>/Reference'
   */
  1570.795,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant2'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<Root>/Output Upper Limit'
   */
  1.0,

  /* Expression: 1.2156
   * Referenced by: '<Root>/P Gain'
   */
  1.2156,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S33>/Integrator'
   */
  0.01,

  /* Expression: 0.0405
   * Referenced by: '<Root>/D Gain'
   */
  0.0405,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S28>/Filter'
   */
  0.01,

  /* Expression: 100
   * Referenced by: '<Root>/N'
   */
  100.0,

  /* Expression: -1
   * Referenced by: '<Root>/Output Lower Limit'
   */
  -1.0,

  /* Expression: 10.7
   * Referenced by: '<Root>/Output voltage to PWM1'
   */
  10.7,

  /* Expression: 1000/10.7
   * Referenced by: '<Root>/Output voltage to PWM'
   */
  93.45794392523365,

  /* Expression: 0
   * Referenced by: '<Root>/I Gain'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
