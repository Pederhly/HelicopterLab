/*
 * lab4_model_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab4_model".
 *
 * Model version              : 11.67
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Nov 22 00:36:30 2021
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab4_model.h"
#include "lab4_model_private.h"

/* Block parameters (default storage) */
P_lab4_model_T lab4_model_P = {
  /* Variable: A_d
   * Referenced by: '<S6>/Constant'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, -0.0019334441047090623, 0.002, 1.0, 0.0, 0.0, 0.0,
    -1.9334441047090622E-6, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: B_d
   * Referenced by: '<S6>/Constant2'
   */
  { 0.0, 0.0, 3.3692814947108145E-7, 0.00033692814947108146, 0.0, 0.0,
    1.9600399600399621E-6, 0.0019600399600399623, 0.0, 0.0, 0.0,
    -1.2632092352444836E-9 },

  /* Variable: C_d
   * Referenced by: '<S6>/Constant3'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: F_aug
   * Referenced by: '<Root>/F'
   */
  { 1.0763000799537023E-15, 7.06271809971847, 31.111010475579871,
    -2.05042694773381E-15 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S20>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S20>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K_aug
   * Referenced by: '<S7>/K'
   */
  { 1.0763000799537023E-15, 7.0627180997184711, 8.4904818964911661E-17,
    4.9409934780454865, 31.111010475579874, -2.05042694773381E-15,
    2.8387812903332332E-16, -1.0000000000000002, -14.142135623730955,
    8.2328111600910311E-16 },

  /* Variable: P_init_pred
   * Referenced by: '<S6>/Unit Delay1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: Q_d
   * Referenced by: '<S6>/Constant1'
   */
  { 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 },

  /* Variable: R_d
   * Referenced by: '<S6>/Constant6'
   */
  { 0.0028, 0.0035, 0.0028, -0.0042, 0.0013, 0.0035, 0.0308, 0.0172, -0.0103,
    -0.0238, 0.0028, 0.0172, 0.0123, -0.0071, -0.0098, -0.0042, -0.0103, -0.0071,
    0.0149, 0.004, 0.0013, -0.0238, -0.0098, 0.004, 0.0773 },

  /* Variable: Vs_0
   * Referenced by: '<S9>/Constant'
   */
  6.0,

  /* Variable: X_init_pred
   * Referenced by: '<S6>/Unit Delay'
   */
  { 0.0, 0.0, -0.4189, 0.0, 0.0, 0.0 },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S4>/HIL Write Analog'
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

  /* Expression: -2*pi /4096
   * Referenced by: '<S4>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: 0
   * Referenced by: '<S5>/Constant4'
   */
  0.0,

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S5>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S5>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: -2 * pi /4096
   * Referenced by: '<S4>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Expression: 2*pi/8192
   * Referenced by: '<S4>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  50.0,

  /* Expression: 25
   * Referenced by: '<S8>/Step2'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step2'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S8>/Step2'
   */
  0.5,

  /* Expression: 35
   * Referenced by: '<S8>/Step3'
   */
  35.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step3'
   */
  0.0,

  /* Expression: -0.5
   * Referenced by: '<S8>/Step3'
   */
  -0.5,

  /* Expression: 40
   * Referenced by: '<S8>/Step4'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step4'
   */
  0.0,

  /* Expression: -0.7
   * Referenced by: '<S8>/Step4'
   */
  -0.7,

  /* Expression: 45
   * Referenced by: '<S8>/Step5'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step5'
   */
  0.0,

  /* Expression: 0.7
   * Referenced by: '<S8>/Step5'
   */
  0.7,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S20>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S20>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S20>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S20>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S8>/Switch'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S8>/Step'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/Step'
   */
  0.1,

  /* Expression: 15
   * Referenced by: '<S8>/Step1'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step1'
   */
  0.0,

  /* Expression: -0.2
   * Referenced by: '<S8>/Step1'
   */
  -0.2,

  /* Expression: 20
   * Referenced by: '<S8>/Step6'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step6'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/Step6'
   */
  0.1,

  /* Expression: 40
   * Referenced by: '<S8>/Step7'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step7'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/Step7'
   */
  0.1,

  /* Expression: 45
   * Referenced by: '<S8>/Step8'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step8'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S8>/Step8'
   */
  -0.1,

  /* Expression: 0
   * Referenced by: '<S20>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S20>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S20>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S20>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: -1
   * Referenced by: '<S8>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Back gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Front gain'
   */
  0.5,

  /* Expression: 5
   * Referenced by: '<S4>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S4>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S4>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S4>/Back motor: Saturation'
   */
  -5.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S2>/Transfer Fcn'
   */
  -10.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S2>/Transfer Fcn'
   */
  10.0,

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
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: StreamCall2_SendBufferSize
   * Referenced by: '<S5>/Stream Call2'
   */
  8000,

  /* Computed Parameter: StreamCall2_ReceiveBufferSize
   * Referenced by: '<S5>/Stream Call2'
   */
  8000,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S10>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_i
   * Referenced by: '<S11>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_g
   * Referenced by: '<S12>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_k
   * Referenced by: '<S13>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_e
   * Referenced by: '<S14>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_o
   * Referenced by: '<S15>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: StreamFormattedRead_MaxUnits
   * Referenced by: '<S16>/Stream Formatted Read'
   */
  80U,

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
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: StreamFormattedRead1_MaxUnits
   * Referenced by: '<S5>/Stream Formatted Read1'
   */
  80U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S20>/Game Controller'
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
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: StreamCall2_NonBlocking
   * Referenced by: '<S5>/Stream Call2'
   */
  1,

  /* Computed Parameter: StreamCall2_Active
   * Referenced by: '<S5>/Stream Call2'
   */
  0,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S4>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S20>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S20>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  1U,

  /* Expression: value
   * Referenced by: '<S5>/String Constant1'
   */
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 52U,
    63U, 98U, 97U, 117U, 100U, 61U, 49U, 49U, 53U, 50U, 48U, 48U, 44U, 119U,
    111U, 114U, 100U, 61U, 56U, 44U, 112U, 97U, 114U, 105U, 116U, 121U, 61U,
    110U, 111U, 110U, 101U, 44U, 115U, 116U, 111U, 112U, 61U, 49U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Expression: uri_argument
   * Referenced by: '<S5>/Stream Call2'
   */
  0U,

  /* Computed Parameter: StreamCall2_Endian
   * Referenced by: '<S5>/Stream Call2'
   */
  1U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S20>/Game Controller'
   */
  1U
};
