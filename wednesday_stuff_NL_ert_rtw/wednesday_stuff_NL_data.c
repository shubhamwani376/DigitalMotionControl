/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_NL_data.c
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

/* Block parameters (default storage) */
P_wednesday_stuff_NL_T wednesday_stuff_NL_P = {
  /* Variable: A_d
   * Referenced by: '<Root>/SOFC'
   */
  { 1.0, 0.0, 0.073763824168706471, 0.52574841112881621 },

  /* Variable: B_d
   * Referenced by: '<Root>/SOFC'
   */
  { 11.696961724785037, 211.43716670506942 },

  /* Variable: C_d
   * Referenced by: '<Root>/SOFC'
   */
  { 1.0, 0.0 },

  /* Variable: K_SF
   * Referenced by: '<Root>/SOFC'
   */
  { 0.063124163388838, 0.0051924598593751517 },

  /* Variable: L_Pred
   * Referenced by: '<Root>/SOFC'
   */
  { 1.5257484111288162, 3.7472486672096834 },

  /* Variable: N
   * Referenced by: '<Root>/SOFC'
   */
  0.063124163388837987,

  /* Variable: Stepsize
   * Referenced by: '<Root>/r'
   */
  1.0,

  /* Variable: Tcomp
   * Referenced by: '<Root>/Transport Delay1'
   */
  0.0007,

  /* Variable: encoder_resolution
   * Referenced by: '<Root>/Quantizer'
   */
  0.015707963267948967,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
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

  /* Expression: 1000
   * Referenced by: '<Root>/Constant2'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Transport Delay1'
   */
  0.0,

  /* Expression: 10.7
   * Referenced by: '<Root>/Output voltage to PWM1'
   */
  10.7,

  /* Expression: 1000/10.7
   * Referenced by: '<Root>/Output voltage to PWM'
   */
  93.45794392523365,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete FIR Filter'
   */
  0.0,

  /* Expression: [1]
   * Referenced by: '<Root>/Discrete FIR Filter'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete FIR Filter2'
   */
  0.0,

  /* Expression: [0.25 0.25 0.25 0.25]
   * Referenced by: '<Root>/Discrete FIR Filter2'
   */
  { 0.25, 0.25, 0.25, 0.25 },

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: -100000
   * Referenced by: '<Root>/Constant3'
   */
  -100000.0,

  /* Expression: 3.14159/400
   * Referenced by: '<Root>/Gain'
   */
  0.007853975,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<Root>/r'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/r'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete FIR Filter3'
   */
  0.0,

  /* Expression: [1]
   * Referenced by: '<Root>/Discrete FIR Filter3'
   */
  1.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
