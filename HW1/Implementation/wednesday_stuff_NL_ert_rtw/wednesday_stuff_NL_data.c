/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_NL_data.c
 *
 * Code generated for Simulink model 'wednesday_stuff_NL'.
 *
 * Model version                  : 1.53
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Feb  9 19:04:55 2023
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
  { 1.0, 0.0, 0.00099701308806597068, 0.994032129823957 },

  /* Variable: B_d
   * Referenced by: '<Root>/SOFC'
   */
  { 0.0012316920750621374, 2.4609290676060303 },

  /* Variable: C_d
   * Referenced by: '<Root>/SOFC'
   */
  { 1.0, 0.0 },

  /* Variable: K_SF
   * Referenced by: '<Root>/SOFC'
   */
  { 0.51689467842222725, 0.012679123694011566 },

  /* Variable: L_Pred
   * Referenced by: '<Root>/SOFC'
   */
  { 0.92705594764175048, 212.73623601452047 },

  /* Variable: N
   * Referenced by: '<Root>/SOFC'
   */
  0.51689467842222681,

  /* Variable: Tcomp
   * Referenced by: '<Root>/Transport Delay1'
   */
  7.0E-6,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

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

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant2'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Transport Delay1'
   */
  0.0,

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
