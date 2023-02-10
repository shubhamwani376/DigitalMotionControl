/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_NL_data.c
 *
 * Code generated for Simulink model 'wednesday_stuff_NL'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Feb  9 11:53:06 2023
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
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 1.0, 0.0, 0.0097065957769039563, 0.94189875324479411 },

  /* Variable: B_d
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 0.120989056376251, 23.958806540064497 },

  /* Variable: C_d
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 1.0, 0.0 },

  /* Variable: K_aug
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 0.67823034857238684, 0.020786966005873486, 0.078709772750133869 },

  /* Variable: L_Pred
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 1.0226067622282855, 2.19369263535227 },

  /* Variable: N
   * Referenced by: '<Root>/SOFC integral1'
   */
  0.67823034857238673,

  /* Variable: Tcomp
   * Referenced by: '<Root>/Transport Delay2'
   */
  7.0000000000000007E-5,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

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
  100.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant2'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Transport Delay2'
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
