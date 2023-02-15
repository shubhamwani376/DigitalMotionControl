/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: wednesday_stuff_NL_data.c
 *
 * Code generated for Simulink model 'wednesday_stuff_NL'.
 *
<<<<<<< Updated upstream
 * Model version                  : 1.69
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Feb 14 12:55:02 2023
=======
 * Model version                  : 1.74
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Feb 10 10:10:41 2023
>>>>>>> Stashed changes
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
  { 2.1445899761310132, 0.058485310590860741, 0.043231484309058862 },

  /* Variable: L_Pred
   * Referenced by: '<Root>/SOFC integral1'
   */
  { 0.73207279476869525, -0.07945750888719795 },

  /* Variable: N
   * Referenced by: '<Root>/SOFC integral1'
   */
  2.3253254432794255,

  /* Variable: Tcomp
   * Referenced by: '<Root>/Transport Delay2'
   */
  7.0E-6,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Expression: sps.Delay
   * Referenced by: '<S4>/Constant3'
   */
  0.25,

<<<<<<< Updated upstream
  /* Expression: sps.Period
   * Referenced by: '<S4>/Constant1'
=======
  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/Step'
>>>>>>> Stashed changes
   */
  0.2,

  /* Expression: -100000
   * Referenced by: '<Root>/Constant3'
   */
  -100000.0,

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
