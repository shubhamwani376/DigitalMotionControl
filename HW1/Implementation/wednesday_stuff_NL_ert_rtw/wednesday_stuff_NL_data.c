/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_NL_data.c
 *
 * Code generated for Simulink model 'wednesday_stuff_NL'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Feb  3 15:15:07 2023
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
  { 1.0, 0.0, 0.0097065957769039563, 0.94189875324479411 },

  /* Variable: B_d
   * Referenced by: '<Root>/SOFC'
   */
  { 0.120989056376251, 23.958806540064497 },

  /* Variable: C_d
   * Referenced by: '<Root>/SOFC'
   */
  { 1.0, 0.0 },

  /* Variable: K_SF
   * Referenced by: '<Root>/SOFC'
   */
  { 0.44682652252884253, 0.012758098447356359 },

  /* Variable: L_Pred
   * Referenced by: '<Root>/SOFC'
   */
  { 1.9381638677813784, 91.0369490040518 },

  /* Variable: N
   * Referenced by: '<Root>/SOFC'
   */
  0.44682652252884253,

  /* Variable: Tcomp
   * Referenced by: '<Root>/Transport Delay1'
   */
  7.0000000000000007E-5,

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

  /* Expression: 0.2
   * Referenced by: '<Root>/Signal Generator'
   */
  0.2,

  /* Expression: 1
   * Referenced by: '<Root>/Signal Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/Step'
   */
  0.2,

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
