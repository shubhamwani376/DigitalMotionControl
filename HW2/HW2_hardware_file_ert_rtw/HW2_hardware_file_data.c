/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HW2_hardware_file_data.c
 *
 * Code generated for Simulink model 'HW2_hardware_file'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb 22 11:28:34 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HW2_hardware_file.h"

/* Block parameters (default storage) */
P_HW2_hardware_file_T HW2_hardware_file_P = {
  /* Variable: A_d
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 0.99989714784604444, -0.20560610777546162, 0.00099858567226493943,
    0.99713839434851925 },

  /* Variable: B_d
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 0.00056907565282184015, 1.1376079693678911 },

  /* Variable: C_d
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 1.0, 0.0 },

  /* Variable: K_aug
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 4.4675947903252826, 0.033926149031679675, 0.11025963793888265,
    -0.22051838534176135, 0.11026313143078589 },

  /* Variable: L_Pred
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 0.93005936001235723, 215.07046852596781 },

  /* Variable: N
   * Referenced by: '<Root>/SOFC integral1'
   */
  4.6483302574736971,

  /* Variable: Tcomp
   * Referenced by: '<Root>/Transport Delay2'
   */
  7.0E-6,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 3.14159/400
   * Referenced by: '<Root>/Gain'
   */
  0.007853975,

  /* Expression: sps.Delay
   * Referenced by: '<S4>/Constant3'
   */
  0.25,

  /* Expression: sps.Period
   * Referenced by: '<S4>/Constant1'
   */
  1.0,

  /* Expression: sps.Freq
   * Referenced by: '<S4>/1\ib1'
   */
  1.0,

  /* Expression: [0 2 0]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  { 0.0, 2.0, 0.0 },

  /* Expression: [0 .5 1]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  { 0.0, 0.5, 1.0 },

  /* Expression: 1
   * Referenced by: '<S4>/Constant2'
   */
  1.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/Gain1'
   */
  0.2,

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

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  1000.0,

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
