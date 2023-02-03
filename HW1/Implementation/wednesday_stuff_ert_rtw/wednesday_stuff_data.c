/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_data.c
 *
 * Code generated for Simulink model 'wednesday_stuff'.
 *
 * Model version                  : 2.9
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Feb  3 11:26:13 2023
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
   * Referenced by: '<S2>/System Matrix'
   */
  { 1.0, 0.0, 0.00099701308806597068, 0.994032129823957 },

  /* Variable: B_d
   * Referenced by: '<S2>/Input Matrix'
   */
  { 0.0012316920750621374, 2.4609290676060303 },

  /* Variable: C_d
   * Referenced by: '<S2>/Output Matrix'
   */
  { 1.0, 0.0 },

  /* Variable: K_SF
   * Referenced by: '<Root>/Feedback Gain3'
   */
  { 0.51689467842222725, 0.012679123694011566 },

  /* Variable: L_Pred
   * Referenced by: '<S2>/Observer Gain'
   */
  { 0.92705594764175048, 212.73623601452047 },

  /* Variable: N
   * Referenced by: '<Root>/Feedback Gain4'
   */
  0.51689467842222681,

  /* Variable: Stepsize
   * Referenced by: '<Root>/r'
   */
  1.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/r'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/r'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay'
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

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant2'
   */
  1000.0,

  /* Expression: 10.5
   * Referenced by: '<Root>/Output voltage to PWM1'
   */
  10.5,

  /* Expression: 1000/10.5
   * Referenced by: '<Root>/Output voltage to PWM'
   */
  95.238095238095241,

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
