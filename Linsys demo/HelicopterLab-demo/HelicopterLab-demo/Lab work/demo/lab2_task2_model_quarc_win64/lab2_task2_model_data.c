/*
 * lab2_task2_model_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab2_task2_model".
 *
 * Model version              : 11.22
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Sun Nov 21 23:58:01 2021
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab2_task2_model.h"
#include "lab2_task2_model_private.h"

/* Block parameters (default storage) */
P_lab2_task2_model_T lab2_task2_model_P = {
  /* Variable: A_aug
   * Referenced by: '<S5>/State-Space'
   */
  { 0.0, 0.0, 0.0, -1.0, -0.0, 1.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, 0.0, -0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: B_aug
   * Referenced by: '<S5>/State-Space'
   */
  { 0.0, 0.0, 0.16846407473554073, 0.0, 0.0, 0.0, 0.980019980019981, 0.0, 0.0,
    0.0 },

  /* Variable: C_aug
   * Referenced by: '<S5>/Gain1'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: F_aug
   * Referenced by:
   *   '<Root>/F'
   *   '<S5>/F1'
   */
  { -2.4237737315572783E-14, 20.473410677421725, 47.596903900237209,
    1.6234207791078385E-15 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S11>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S11>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K_aug
   * Referenced by:
   *   '<Root>/K'
   *   '<S5>/K1'
   */
  { -2.4237737315572783E-14, 20.473410677421722, -1.0178308190670285E-14,
    9.5802723831831553, 47.596903900237209, 1.6234207791078387E-15,
    6.6803675558601863E-16, -1.0000000000000018, -22.360679774997894,
    -3.3859340200536244E-16 },

  /* Variable: Lab2TestToRun
   * Referenced by:
   *   '<S4>/Constant1'
   *   '<S4>/Constant4'
   */
  6.0,

  /* Variable: Vs_0
   * Referenced by: '<Root>/Constant'
   */
  6.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S6>/Constant'
   */
  5.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S7>/Constant'
   */
  6.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S9>/Constant'
   */
  4.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S10>/Constant'
   */
  7.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S8>/Constant'
   */
  6.0,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S3>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Reference selector'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S11>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S11>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S11>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S11>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: -2*pi /4096
   * Referenced by: '<S3>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: eye(5)
   * Referenced by: '<S5>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S5>/State-Space'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S4>/Step'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S4>/Step'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S4>/Step'
   */
  0.1,

  /* Expression: 15
   * Referenced by: '<S4>/Step1'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S4>/Step1'
   */
  0.0,

  /* Expression: -0.2
   * Referenced by: '<S4>/Step1'
   */
  -0.2,

  /* Expression: 20
   * Referenced by: '<S4>/Step6'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S4>/Step6'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S4>/Step6'
   */
  0.1,

  /* Expression: 40
   * Referenced by: '<S4>/Step7'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S4>/Step7'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S4>/Step7'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S4>/Constant2'
   */
  0.0,

  /* Expression: 45
   * Referenced by: '<S4>/Step2'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<S4>/Step2'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S4>/Step2'
   */
  -0.1,

  /* Expression: 0
   * Referenced by: '<S11>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S11>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S11>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S11>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: -1
   * Referenced by: '<S4>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch1'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -10.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  10.0,

  /* Expression: 2*pi/8192
   * Referenced by: '<S3>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S3>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S3>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S3>/Travel: Transfer Fcn'
   */
  50.0,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S3>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S3>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S3>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Expression: -2 * pi /4096
   * Referenced by: '<S3>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: TransferFcn_A_n
   * Referenced by: '<S2>/Transfer Fcn'
   */
  -10.0,

  /* Computed Parameter: TransferFcn_C_n
   * Referenced by: '<S2>/Transfer Fcn'
   */
  10.0,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S3>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S3>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S3>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Front gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Back gain'
   */
  0.5,

  /* Expression: 5
   * Referenced by: '<S3>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S3>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S3>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S3>/Back motor: Saturation'
   */
  -5.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S11>/Game Controller'
   */
  12U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S3>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S11>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S11>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  1U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S11>/Game Controller'
   */
  1U
};
