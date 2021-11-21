/*
 * lab2_task1_model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab2_task1_model".
 *
 * Model version              : 11.17
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Nov 22 00:02:41 2021
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab2_task1_model.h"
#include "lab2_task1_model_private.h"
#include "lab2_task1_model_dt.h"

/* Block signals (default storage) */
B_lab2_task1_model_T lab2_task1_model_B;

/* Continuous states */
X_lab2_task1_model_T lab2_task1_model_X;

/* Block states (default storage) */
DW_lab2_task1_model_T lab2_task1_model_DW;

/* Real-time model */
static RT_MODEL_lab2_task1_model_T lab2_task1_model_M_;
RT_MODEL_lab2_task1_model_T *const lab2_task1_model_M = &lab2_task1_model_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(lab2_task1_model_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(lab2_task1_model_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (lab2_task1_model_M->Timing.TaskCounters.TID[1] == 0) {
    lab2_task1_model_M->Timing.RateInteraction.TID1_2 =
      (lab2_task1_model_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    lab2_task1_model_M->Timing.perTaskSampleHits[5] =
      lab2_task1_model_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab2_task1_model_M->Timing.TaskCounters.TID[2])++;
  if ((lab2_task1_model_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    lab2_task1_model_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  lab2_task1_model_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void lab2_task1_model_output0(void)    /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_TmpSignalConversionAtToFile[16];
  real_T rtb_StateSpace[3];
  real_T u_tmp[2];
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T u_tmp_0;
  int_T iy;
  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
    /* set solver stop time */
    if (!(lab2_task1_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab2_task1_model_M->solverInfo,
                            ((lab2_task1_model_M->Timing.clockTickH0 + 1) *
        lab2_task1_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab2_task1_model_M->solverInfo,
                            ((lab2_task1_model_M->Timing.clockTick0 + 1) *
        lab2_task1_model_M->Timing.stepSize0 +
        lab2_task1_model_M->Timing.clockTickH0 *
        lab2_task1_model_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab2_task1_model_M)) {
    lab2_task1_model_M->Timing.t[0] = rtsiGetT(&lab2_task1_model_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: lab2_task1_model/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (lab2_task1_model_DW.HILReadEncoderTimebase_Task, 1,
         &lab2_task1_model_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          lab2_task1_model_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          lab2_task1_model_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          lab2_task1_model_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* Step: '<S5>/Step2' incorporates:
   *  Step: '<S5>/Step'
   *  Step: '<S5>/Step1'
   *  Step: '<S5>/Step3'
   *  Step: '<S5>/Step4'
   *  Step: '<S5>/Step5'
   *  Step: '<S5>/Step6'
   *  Step: '<S5>/Step7'
   *  Step: '<S5>/Step9'
   */
  u_tmp_0 = lab2_task1_model_M->Timing.t[0];
  if (u_tmp_0 < lab2_task1_model_P.Step2_Time) {
    tmp = lab2_task1_model_P.Step2_Y0;
  } else {
    tmp = lab2_task1_model_P.Step2_YFinal;
  }

  /* End of Step: '<S5>/Step2' */

  /* Step: '<S5>/Step3' */
  if (u_tmp_0 < lab2_task1_model_P.Step3_Time) {
    tmp_0 = lab2_task1_model_P.Step3_Y0;
  } else {
    tmp_0 = lab2_task1_model_P.Step3_YFinal;
  }

  /* Step: '<S5>/Step4' */
  if (u_tmp_0 < lab2_task1_model_P.Step4_Time) {
    tmp_1 = lab2_task1_model_P.Step4_Y0;
  } else {
    tmp_1 = lab2_task1_model_P.Step4_YFinal;
  }

  /* Step: '<S5>/Step5' */
  if (u_tmp_0 < lab2_task1_model_P.Step5_Time) {
    tmp_2 = lab2_task1_model_P.Step5_Y0;
  } else {
    tmp_2 = lab2_task1_model_P.Step5_YFinal;
  }

  /* Sum: '<S5>/y' */
  lab2_task1_model_B.y = ((tmp + tmp_0) + tmp_1) + tmp_2;

  /* RateTransition: '<S6>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
    if (lab2_task1_model_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S6>/Rate Transition: x' */
      lab2_task1_model_B.RateTransitionx =
        lab2_task1_model_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S6>/Dead Zone: x' */
    if (lab2_task1_model_B.RateTransitionx > lab2_task1_model_P.DeadZonex_End) {
      tmp = lab2_task1_model_B.RateTransitionx -
        lab2_task1_model_P.DeadZonex_End;
    } else if (lab2_task1_model_B.RateTransitionx >=
               lab2_task1_model_P.DeadZonex_Start) {
      tmp = 0.0;
    } else {
      tmp = lab2_task1_model_B.RateTransitionx -
        lab2_task1_model_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: x' */

    /* Gain: '<S6>/Joystick_gain_x' incorporates:
     *  Gain: '<S6>/Gain: x'
     */
    lab2_task1_model_B.Joystick_gain_x = lab2_task1_model_P.Gainx_Gain * tmp *
      lab2_task1_model_P.Joystick_gain_x;

    /* Gain: '<S3>/Pitch: Count to rad' */
    lab2_task1_model_B.PitchCounttorad = lab2_task1_model_P.PitchCounttorad_Gain
      * rtb_HILReadEncoderTimebase_o2;
  }

  /* End of RateTransition: '<S6>/Rate Transition: x' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (lab2_task1_model_P.Constant1_Value > lab2_task1_model_P.Switch_Threshold)
  {
    /* Switch: '<S5>/Switch' */
    lab2_task1_model_B.Switch = lab2_task1_model_B.y;
  } else {
    /* Switch: '<S5>/Switch' */
    lab2_task1_model_B.Switch = lab2_task1_model_B.Joystick_gain_x;
  }

  /* End of Switch: '<S5>/Switch' */

  /* StateSpace: '<S4>/State-Space' */
  for (iy = 0; iy < 3; iy++) {
    rtb_StateSpace[iy] = lab2_task1_model_P.StateSpace_C[iy + 6] *
      lab2_task1_model_X.StateSpace_CSTATE[2] +
      (lab2_task1_model_P.StateSpace_C[iy + 3] *
       lab2_task1_model_X.StateSpace_CSTATE[1] +
       lab2_task1_model_P.StateSpace_C[iy] *
       lab2_task1_model_X.StateSpace_CSTATE[0]);
  }

  /* End of StateSpace: '<S4>/State-Space' */
  for (iy = 0; iy < 2; iy++) {
    /* Gain: '<S4>/Gain1' */
    lab2_task1_model_B.Gain1[iy] = 0.0;
    lab2_task1_model_B.Gain1[iy] += lab2_task1_model_P.C[iy] * rtb_StateSpace[0];
    lab2_task1_model_B.Gain1[iy] += lab2_task1_model_P.C[iy + 2] *
      rtb_StateSpace[1];
    lab2_task1_model_B.Gain1[iy] += lab2_task1_model_P.C[iy + 4] *
      rtb_StateSpace[2];
  }

  /* Step: '<S5>/Step' */
  if (u_tmp_0 < lab2_task1_model_P.Step_Time) {
    tmp = lab2_task1_model_P.Step_Y0;
  } else {
    tmp = lab2_task1_model_P.Step_YFinal;
  }

  /* Step: '<S5>/Step1' */
  if (u_tmp_0 < lab2_task1_model_P.Step1_Time) {
    tmp_0 = lab2_task1_model_P.Step1_Y0;
  } else {
    tmp_0 = lab2_task1_model_P.Step1_YFinal;
  }

  /* Step: '<S5>/Step6' */
  if (u_tmp_0 < lab2_task1_model_P.Step6_Time) {
    tmp_1 = lab2_task1_model_P.Step6_Y0;
  } else {
    tmp_1 = lab2_task1_model_P.Step6_YFinal;
  }

  /* Step: '<S5>/Step7' */
  if (u_tmp_0 < lab2_task1_model_P.Step7_Time) {
    tmp_2 = lab2_task1_model_P.Step7_Y0;
  } else {
    tmp_2 = lab2_task1_model_P.Step7_YFinal;
  }

  /* Step: '<S5>/Step9' */
  if (u_tmp_0 < lab2_task1_model_P.Step9_Time) {
    u_tmp_0 = lab2_task1_model_P.Step9_Y0;
  } else {
    u_tmp_0 = lab2_task1_model_P.Step9_YFinal;
  }

  /* Sum: '<S5>/y1' */
  lab2_task1_model_B.y1 = (((tmp + tmp_0) + tmp_1) + tmp_2) + u_tmp_0;

  /* RateTransition: '<S6>/Rate Transition: y' */
  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
    if (lab2_task1_model_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S6>/Rate Transition: y' */
      lab2_task1_model_B.RateTransitiony =
        lab2_task1_model_DW.RateTransitiony_Buffer0;
    }

    /* DeadZone: '<S6>/Dead Zone: y' */
    if (lab2_task1_model_B.RateTransitiony > lab2_task1_model_P.DeadZoney_End) {
      u_tmp_0 = lab2_task1_model_B.RateTransitiony -
        lab2_task1_model_P.DeadZoney_End;
    } else if (lab2_task1_model_B.RateTransitiony >=
               lab2_task1_model_P.DeadZoney_Start) {
      u_tmp_0 = 0.0;
    } else {
      u_tmp_0 = lab2_task1_model_B.RateTransitiony -
        lab2_task1_model_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: y' */

    /* Gain: '<S6>/Joystick_gain_y' incorporates:
     *  Gain: '<S6>/Gain: y'
     */
    lab2_task1_model_B.Joystick_gain_y = lab2_task1_model_P.Gainy_Gain * u_tmp_0
      * lab2_task1_model_P.Joystick_gain_y;

    /* Gain: '<S5>/Gain2' */
    lab2_task1_model_B.Gain2 = lab2_task1_model_P.Gain2_Gain *
      lab2_task1_model_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S6>/Rate Transition: y' */

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (lab2_task1_model_P.Constant1_Value > lab2_task1_model_P.Switch1_Threshold)
  {
    /* Switch: '<S5>/Switch1' */
    lab2_task1_model_B.Switch1 = lab2_task1_model_B.y1;
  } else {
    /* Switch: '<S5>/Switch1' */
    lab2_task1_model_B.Switch1 = lab2_task1_model_B.Gain2;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  lab2_task1_model_B.elevation_rate = 0.0;
  lab2_task1_model_B.elevation_rate += lab2_task1_model_P.TransferFcn1_C *
    lab2_task1_model_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
    /* Gain: '<S3>/Travel: Count to rad' */
    lab2_task1_model_B.TravelCounttorad =
      lab2_task1_model_P.TravelCounttorad_Gain * rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S3>/Elevation: Count to rad' */
    lab2_task1_model_B.ElevationCounttorad =
      lab2_task1_model_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3;
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  lab2_task1_model_B.TravelTransferFcn = 0.0;
  lab2_task1_model_B.TravelTransferFcn += lab2_task1_model_P.TravelTransferFcn_C
    * lab2_task1_model_X.TravelTransferFcn_CSTATE;
  lab2_task1_model_B.TravelTransferFcn += lab2_task1_model_P.TravelTransferFcn_D
    * lab2_task1_model_B.TravelCounttorad;

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  lab2_task1_model_B.PitchTransferFcn = 0.0;
  lab2_task1_model_B.PitchTransferFcn += lab2_task1_model_P.PitchTransferFcn_C *
    lab2_task1_model_X.PitchTransferFcn_CSTATE;
  lab2_task1_model_B.PitchTransferFcn += lab2_task1_model_P.PitchTransferFcn_D *
    lab2_task1_model_B.PitchCounttorad;

  /* TransferFcn: '<S2>/Filter' */
  lab2_task1_model_B.Filter = 0.0;
  lab2_task1_model_B.Filter += lab2_task1_model_P.Filter_C *
    lab2_task1_model_X.Filter_CSTATE;

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  lab2_task1_model_B.ElevationTransferFcn = 0.0;
  lab2_task1_model_B.ElevationTransferFcn +=
    lab2_task1_model_P.ElevationTransferFcn_C *
    lab2_task1_model_X.ElevationTransferFcn_CSTATE;
  lab2_task1_model_B.ElevationTransferFcn +=
    lab2_task1_model_P.ElevationTransferFcn_D *
    lab2_task1_model_B.ElevationCounttorad;
  for (iy = 0; iy < 2; iy++) {
    /* Gain: '<Root>/F' incorporates:
     *  SignalConversion generated from: '<Root>/F'
     */
    u_tmp_0 = lab2_task1_model_P.F[iy + 2] * lab2_task1_model_B.Switch1 +
      lab2_task1_model_P.F[iy] * lab2_task1_model_B.Switch;

    /* Sum: '<Root>/Sum' incorporates:
     *  Gain: '<Root>/K'
     *  SignalConversion generated from: '<Root>/K'
     */
    lab2_task1_model_B.u[iy] = u_tmp_0 - ((lab2_task1_model_P.K[iy + 2] *
      lab2_task1_model_B.PitchTransferFcn + lab2_task1_model_P.K[iy] *
      lab2_task1_model_B.PitchCounttorad) + lab2_task1_model_P.K[iy + 4] *
      lab2_task1_model_B.ElevationTransferFcn);

    /* Gain: '<Root>/F' incorporates:
     *  Gain: '<S4>/F1'
     */
    u_tmp[iy] = u_tmp_0;
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  lab2_task1_model_B.Sum1 = lab2_task1_model_P.Vs_0 + lab2_task1_model_B.u[0];

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  lab2_task1_model_B.Frontgain = (lab2_task1_model_B.Sum1 -
    lab2_task1_model_B.u[1]) * lab2_task1_model_P.Frontgain_Gain;

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  lab2_task1_model_B.Backgain = (lab2_task1_model_B.u[1] +
    lab2_task1_model_B.Sum1) * lab2_task1_model_P.Backgain_Gain;
  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
    /* SignalConversion generated from: '<S2>/To File' */
    rtb_TmpSignalConversionAtToFile[0] = lab2_task1_model_B.TravelCounttorad;
    rtb_TmpSignalConversionAtToFile[1] = lab2_task1_model_B.TravelTransferFcn;
    rtb_TmpSignalConversionAtToFile[2] = lab2_task1_model_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[3] = lab2_task1_model_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[4] = lab2_task1_model_B.ElevationCounttorad;
    rtb_TmpSignalConversionAtToFile[5] = lab2_task1_model_B.Filter;
    rtb_TmpSignalConversionAtToFile[6] = lab2_task1_model_B.u[1];
    rtb_TmpSignalConversionAtToFile[7] = lab2_task1_model_B.Sum1;
    rtb_TmpSignalConversionAtToFile[8] = lab2_task1_model_B.Switch1;
    rtb_TmpSignalConversionAtToFile[9] = lab2_task1_model_B.Switch;
    rtb_TmpSignalConversionAtToFile[10] = lab2_task1_model_B.Frontgain;
    rtb_TmpSignalConversionAtToFile[11] = lab2_task1_model_B.Backgain;
    rtb_TmpSignalConversionAtToFile[12] = lab2_task1_model_B.Switch;
    rtb_TmpSignalConversionAtToFile[13] = lab2_task1_model_B.Switch1;
    rtb_TmpSignalConversionAtToFile[14] = lab2_task1_model_B.Gain1[0];
    rtb_TmpSignalConversionAtToFile[15] = lab2_task1_model_B.Gain1[1];

    /* ToFile: '<S2>/To File' */
    if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
      if (rtmIsMajorTimeStep(lab2_task1_model_M) ) {
        {
          if (!(++lab2_task1_model_DW.ToFile_IWORK.Decimation % 1) &&
              (lab2_task1_model_DW.ToFile_IWORK.Count * (16 + 1)) + 1 <
              100000000 ) {
            FILE *fp = (FILE *) lab2_task1_model_DW.ToFile_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[16 + 1];
              lab2_task1_model_DW.ToFile_IWORK.Decimation = 0;
              u[0] = lab2_task1_model_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFile[0];
              u[2] = rtb_TmpSignalConversionAtToFile[1];
              u[3] = rtb_TmpSignalConversionAtToFile[2];
              u[4] = rtb_TmpSignalConversionAtToFile[3];
              u[5] = rtb_TmpSignalConversionAtToFile[4];
              u[6] = rtb_TmpSignalConversionAtToFile[5];
              u[7] = rtb_TmpSignalConversionAtToFile[6];
              u[8] = rtb_TmpSignalConversionAtToFile[7];
              u[9] = rtb_TmpSignalConversionAtToFile[8];
              u[10] = rtb_TmpSignalConversionAtToFile[9];
              u[11] = rtb_TmpSignalConversionAtToFile[10];
              u[12] = rtb_TmpSignalConversionAtToFile[11];
              u[13] = rtb_TmpSignalConversionAtToFile[12];
              u[14] = rtb_TmpSignalConversionAtToFile[13];
              u[15] = rtb_TmpSignalConversionAtToFile[14];
              u[16] = rtb_TmpSignalConversionAtToFile[15];
              if (fwrite(u, sizeof(real_T), 16 + 1, fp) != 16 + 1) {
                rtmSetErrorStatus(lab2_task1_model_M,
                                  "Error writing to MAT-file helicopter_state_log.mat");
                return;
              }

              if (((++lab2_task1_model_DW.ToFile_IWORK.Count) * (16 + 1))+1 >=
                  100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file helicopter_state_log.mat.\n");
              }
            }
          }
        }
      }
    }
  }

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (lab2_task1_model_B.Frontgain >
      lab2_task1_model_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S3>/Front motor: Saturation' */
    lab2_task1_model_B.FrontmotorSaturation =
      lab2_task1_model_P.FrontmotorSaturation_UpperSat;
  } else if (lab2_task1_model_B.Frontgain <
             lab2_task1_model_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S3>/Front motor: Saturation' */
    lab2_task1_model_B.FrontmotorSaturation =
      lab2_task1_model_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Front motor: Saturation' */
    lab2_task1_model_B.FrontmotorSaturation = lab2_task1_model_B.Frontgain;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (lab2_task1_model_B.Backgain >
      lab2_task1_model_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S3>/Back motor: Saturation' */
    lab2_task1_model_B.BackmotorSaturation =
      lab2_task1_model_P.BackmotorSaturation_UpperSat;
  } else if (lab2_task1_model_B.Backgain <
             lab2_task1_model_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S3>/Back motor: Saturation' */
    lab2_task1_model_B.BackmotorSaturation =
      lab2_task1_model_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Back motor: Saturation' */
    lab2_task1_model_B.BackmotorSaturation = lab2_task1_model_B.Backgain;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: lab2_task1_model/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      lab2_task1_model_DW.HILWriteAnalog_Buffer[0] =
        lab2_task1_model_B.FrontmotorSaturation;
      lab2_task1_model_DW.HILWriteAnalog_Buffer[1] =
        lab2_task1_model_B.BackmotorSaturation;
      result = hil_write_analog(lab2_task1_model_DW.HILInitialize_Card,
        lab2_task1_model_P.HILWriteAnalog_channels, 2,
        &lab2_task1_model_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
      }
    }
  }

  for (iy = 0; iy < 2; iy++) {
    /* Sum: '<S4>/Sum2' incorporates:
     *  Gain: '<S4>/F1'
     *  Gain: '<S4>/K1'
     */
    lab2_task1_model_B.u_d[iy] = u_tmp[iy] - ((lab2_task1_model_P.K[iy + 2] *
      rtb_StateSpace[1] + lab2_task1_model_P.K[iy] * rtb_StateSpace[0]) +
      lab2_task1_model_P.K[iy + 4] * rtb_StateSpace[2]);
  }

  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
  }
}

/* Model update function for TID0 */
void lab2_task1_model_update0(void)    /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(lab2_task1_model_M)) {
    rt_ertODEUpdateContinuousStates(&lab2_task1_model_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2_task1_model_M->Timing.clockTick0)) {
    ++lab2_task1_model_M->Timing.clockTickH0;
  }

  lab2_task1_model_M->Timing.t[0] = rtsiGetSolverStopTime
    (&lab2_task1_model_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2_task1_model_M->Timing.clockTick1)) {
    ++lab2_task1_model_M->Timing.clockTickH1;
  }

  lab2_task1_model_M->Timing.t[1] = lab2_task1_model_M->Timing.clockTick1 *
    lab2_task1_model_M->Timing.stepSize1 +
    lab2_task1_model_M->Timing.clockTickH1 *
    lab2_task1_model_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void lab2_task1_model_derivatives(void)
{
  XDot_lab2_task1_model_T *_rtXdot;
  int_T is;
  _rtXdot = ((XDot_lab2_task1_model_T *) lab2_task1_model_M->derivs);

  /* Derivatives for StateSpace: '<S4>/State-Space' */
  for (is = 0; is < 3; is++) {
    _rtXdot->StateSpace_CSTATE[is] = 0.0;
    _rtXdot->StateSpace_CSTATE[is] += lab2_task1_model_P.A[is] *
      lab2_task1_model_X.StateSpace_CSTATE[0];
    _rtXdot->StateSpace_CSTATE[is] += lab2_task1_model_P.A[is + 3] *
      lab2_task1_model_X.StateSpace_CSTATE[1];
    _rtXdot->StateSpace_CSTATE[is] += lab2_task1_model_P.A[is + 6] *
      lab2_task1_model_X.StateSpace_CSTATE[2];
    _rtXdot->StateSpace_CSTATE[is] += lab2_task1_model_P.B[is] *
      lab2_task1_model_B.u_d[0];
    _rtXdot->StateSpace_CSTATE[is] += lab2_task1_model_P.B[is + 3] *
      lab2_task1_model_B.u_d[1];
  }

  /* End of Derivatives for StateSpace: '<S4>/State-Space' */

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += lab2_task1_model_P.TransferFcn1_A *
    lab2_task1_model_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += lab2_task1_model_B.ElevationTransferFcn;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += lab2_task1_model_P.TravelTransferFcn_A *
    lab2_task1_model_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += lab2_task1_model_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += lab2_task1_model_P.PitchTransferFcn_A *
    lab2_task1_model_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += lab2_task1_model_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Filter' */
  _rtXdot->Filter_CSTATE = 0.0;
  _rtXdot->Filter_CSTATE += lab2_task1_model_P.Filter_A *
    lab2_task1_model_X.Filter_CSTATE;
  _rtXdot->Filter_CSTATE += lab2_task1_model_B.ElevationTransferFcn;

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    lab2_task1_model_P.ElevationTransferFcn_A *
    lab2_task1_model_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += lab2_task1_model_B.ElevationCounttorad;
}

/* Model output function for TID2 */
void lab2_task1_model_output2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: lab2_task1_model/Reference/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_task1_model_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (lab2_task1_model_DW.GameController_Controller, &state, &new_data);
      if (result < 0) {
        new_data = false;
      }

      rtb_GameController_o4 = state.x;
      rtb_GameController_o5 = state.y;
    } else {
      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
    }
  }

  /* RateTransition: '<S6>/Rate Transition: x' */
  lab2_task1_model_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S6>/Rate Transition: y' */
  lab2_task1_model_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void lab2_task1_model_update2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2_task1_model_M->Timing.clockTick2)) {
    ++lab2_task1_model_M->Timing.clockTickH2;
  }

  lab2_task1_model_M->Timing.t[2] = lab2_task1_model_M->Timing.clockTick2 *
    lab2_task1_model_M->Timing.stepSize2 +
    lab2_task1_model_M->Timing.clockTickH2 *
    lab2_task1_model_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void lab2_task1_model_output(int_T tid)
{
  switch (tid) {
   case 0 :
    lab2_task1_model_output0();
    break;

   case 2 :
    lab2_task1_model_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void lab2_task1_model_update(int_T tid)
{
  switch (tid) {
   case 0 :
    lab2_task1_model_update0();
    break;

   case 2 :
    lab2_task1_model_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lab2_task1_model_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab2_task1_model/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &lab2_task1_model_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (lab2_task1_model_DW.HILInitialize_Card, "update_rate=normal;decimation=1",
       32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(lab2_task1_model_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
      return;
    }

    if ((lab2_task1_model_P.HILInitialize_AIPStart && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &lab2_task1_model_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (lab2_task1_model_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &lab2_task1_model_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = lab2_task1_model_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (lab2_task1_model_DW.HILInitialize_Card,
         lab2_task1_model_P.HILInitialize_AIChannels, 8U,
         &lab2_task1_model_DW.HILInitialize_AIMinimums[0],
         &lab2_task1_model_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_task1_model_P.HILInitialize_AOPStart && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &lab2_task1_model_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (lab2_task1_model_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &lab2_task1_model_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = lab2_task1_model_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (lab2_task1_model_DW.HILInitialize_Card,
         lab2_task1_model_P.HILInitialize_AOChannels, 8U,
         &lab2_task1_model_DW.HILInitialize_AOMinimums[0],
         &lab2_task1_model_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_task1_model_P.HILInitialize_AOStart && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_task1_model_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_task1_model_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(lab2_task1_model_DW.HILInitialize_Card,
        lab2_task1_model_P.HILInitialize_AOChannels, 8U,
        &lab2_task1_model_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }

    if (lab2_task1_model_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_task1_model_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_task1_model_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (lab2_task1_model_DW.HILInitialize_Card,
         lab2_task1_model_P.HILInitialize_AOChannels, 8U,
         &lab2_task1_model_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_task1_model_P.HILInitialize_EIPStart && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &lab2_task1_model_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = lab2_task1_model_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (lab2_task1_model_DW.HILInitialize_Card,
         lab2_task1_model_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &lab2_task1_model_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_task1_model_P.HILInitialize_EIStart && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &lab2_task1_model_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = lab2_task1_model_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(lab2_task1_model_DW.HILInitialize_Card,
        lab2_task1_model_P.HILInitialize_EIChannels, 8U,
        &lab2_task1_model_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_task1_model_P.HILInitialize_POPStart && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &lab2_task1_model_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab2_task1_model_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(lab2_task1_model_DW.HILInitialize_Card,
        lab2_task1_model_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &lab2_task1_model_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          lab2_task1_model_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &lab2_task1_model_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            lab2_task1_model_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            lab2_task1_model_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = lab2_task1_model_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            lab2_task1_model_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            lab2_task1_model_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              lab2_task1_model_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(lab2_task1_model_DW.HILInitialize_Card,
          &lab2_task1_model_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &lab2_task1_model_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(lab2_task1_model_DW.HILInitialize_Card,
          &lab2_task1_model_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &lab2_task1_model_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &lab2_task1_model_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab2_task1_model_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &lab2_task1_model_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = lab2_task1_model_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &lab2_task1_model_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = lab2_task1_model_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(lab2_task1_model_DW.HILInitialize_Card,
        lab2_task1_model_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &lab2_task1_model_DW.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &lab2_task1_model_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &lab2_task1_model_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &lab2_task1_model_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = lab2_task1_model_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &lab2_task1_model_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_task1_model_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(lab2_task1_model_DW.HILInitialize_Card,
        lab2_task1_model_P.HILInitialize_POChannels, 8U,
        &lab2_task1_model_DW.HILInitialize_POSortedFreqs[0],
        &lab2_task1_model_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_task1_model_P.HILInitialize_POStart && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_task1_model_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_task1_model_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(lab2_task1_model_DW.HILInitialize_Card,
        lab2_task1_model_P.HILInitialize_POChannels, 8U,
        &lab2_task1_model_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }

    if (lab2_task1_model_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_task1_model_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_task1_model_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (lab2_task1_model_DW.HILInitialize_Card,
         lab2_task1_model_P.HILInitialize_POChannels, 8U,
         &lab2_task1_model_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: lab2_task1_model/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (lab2_task1_model_DW.HILInitialize_Card,
       lab2_task1_model_P.HILReadEncoderTimebase_SamplesI,
       lab2_task1_model_P.HILReadEncoderTimebase_Channels, 3,
       &lab2_task1_model_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (lab2_task1_model_DW.HILReadEncoderTimebase_Task,
         (t_buffer_overflow_mode)
         (lab2_task1_model_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S6>/Rate Transition: x' */
  lab2_task1_model_B.RateTransitionx =
    lab2_task1_model_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S6>/Rate Transition: y' */
  lab2_task1_model_B.RateTransitiony =
    lab2_task1_model_P.RateTransitiony_InitialConditio;

  /* Start for ToFile: '<S2>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "helicopter_state_log.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(lab2_task1_model_M,
                        "Error creating .mat file helicopter_state_log.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 16 + 1, 0, "var")) {
      rtmSetErrorStatus(lab2_task1_model_M,
                        "Error writing mat file header to file helicopter_state_log.mat");
      return;
    }

    lab2_task1_model_DW.ToFile_IWORK.Count = 0;
    lab2_task1_model_DW.ToFile_IWORK.Decimation = -1;
    lab2_task1_model_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: lab2_task1_model/Reference/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_task1_model_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (lab2_task1_model_P.GameController_ControllerNumber,
         lab2_task1_model_P.GameController_BufferSize, deadzone, saturation,
         lab2_task1_model_P.GameController_AutoCenter, 0, 1.0,
         &lab2_task1_model_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for RateTransition: '<S6>/Rate Transition: x' */
  lab2_task1_model_DW.RateTransitionx_Buffer0 =
    lab2_task1_model_P.RateTransitionx_InitialConditio;

  /* InitializeConditions for StateSpace: '<S4>/State-Space' */
  lab2_task1_model_X.StateSpace_CSTATE[0] =
    lab2_task1_model_P.StateSpace_InitialCondition;
  lab2_task1_model_X.StateSpace_CSTATE[1] =
    lab2_task1_model_P.StateSpace_InitialCondition;
  lab2_task1_model_X.StateSpace_CSTATE[2] =
    lab2_task1_model_P.StateSpace_InitialCondition;

  /* InitializeConditions for RateTransition: '<S6>/Rate Transition: y' */
  lab2_task1_model_DW.RateTransitiony_Buffer0 =
    lab2_task1_model_P.RateTransitiony_InitialConditio;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  lab2_task1_model_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  lab2_task1_model_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  lab2_task1_model_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Filter' */
  lab2_task1_model_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  lab2_task1_model_X.ElevationTransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void lab2_task1_model_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab2_task1_model/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(lab2_task1_model_DW.HILInitialize_Card);
    hil_monitor_stop_all(lab2_task1_model_DW.HILInitialize_Card);
    is_switching = false;
    if ((lab2_task1_model_P.HILInitialize_AOTerminate && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_task1_model_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_task1_model_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((lab2_task1_model_P.HILInitialize_POTerminate && !is_switching) ||
        (lab2_task1_model_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_task1_model_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_task1_model_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(lab2_task1_model_DW.HILInitialize_Card
                         , lab2_task1_model_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , lab2_task1_model_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &lab2_task1_model_DW.HILInitialize_AOVoltages[0]
                         , &lab2_task1_model_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lab2_task1_model_DW.HILInitialize_Card,
            lab2_task1_model_P.HILInitialize_AOChannels,
            num_final_analog_outputs,
            &lab2_task1_model_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(lab2_task1_model_DW.HILInitialize_Card,
            lab2_task1_model_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &lab2_task1_model_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_task1_model_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lab2_task1_model_DW.HILInitialize_Card);
    hil_monitor_delete_all(lab2_task1_model_DW.HILInitialize_Card);
    hil_close(lab2_task1_model_DW.HILInitialize_Card);
    lab2_task1_model_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<S2>/To File' */
  {
    FILE *fp = (FILE *) lab2_task1_model_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "helicopter_state_log.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab2_task1_model_M,
                          "Error closing MAT-file helicopter_state_log.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(lab2_task1_model_M,
                          "Error reopening MAT-file helicopter_state_log.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 16 + 1,
           lab2_task1_model_DW.ToFile_IWORK.Count, "var")) {
        rtmSetErrorStatus(lab2_task1_model_M,
                          "Error writing header for var to MAT-file helicopter_state_log.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab2_task1_model_M,
                          "Error closing MAT-file helicopter_state_log.mat");
        return;
      }

      lab2_task1_model_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: lab2_task1_model/Reference/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_task1_model_P.GameController_Enabled) {
      game_controller_close(lab2_task1_model_DW.GameController_Controller);
      lab2_task1_model_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab2_task1_model_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab2_task1_model_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  lab2_task1_model_initialize();
}

void MdlTerminate(void)
{
  lab2_task1_model_terminate();
}

/* Registration function */
RT_MODEL_lab2_task1_model_T *lab2_task1_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab2_task1_model_M, 0,
                sizeof(RT_MODEL_lab2_task1_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab2_task1_model_M->solverInfo,
                          &lab2_task1_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab2_task1_model_M->solverInfo, &rtmGetTPtr(lab2_task1_model_M));
    rtsiSetStepSizePtr(&lab2_task1_model_M->solverInfo,
                       &lab2_task1_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab2_task1_model_M->solverInfo, &lab2_task1_model_M->derivs);
    rtsiSetContStatesPtr(&lab2_task1_model_M->solverInfo, (real_T **)
                         &lab2_task1_model_M->contStates);
    rtsiSetNumContStatesPtr(&lab2_task1_model_M->solverInfo,
      &lab2_task1_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab2_task1_model_M->solverInfo,
      &lab2_task1_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab2_task1_model_M->solverInfo,
      &lab2_task1_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab2_task1_model_M->solverInfo,
      &lab2_task1_model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab2_task1_model_M->solverInfo, (&rtmGetErrorStatus
      (lab2_task1_model_M)));
    rtsiSetRTModelPtr(&lab2_task1_model_M->solverInfo, lab2_task1_model_M);
  }

  rtsiSetSimTimeStep(&lab2_task1_model_M->solverInfo, MAJOR_TIME_STEP);
  lab2_task1_model_M->intgData.f[0] = lab2_task1_model_M->odeF[0];
  lab2_task1_model_M->contStates = ((real_T *) &lab2_task1_model_X);
  rtsiSetSolverData(&lab2_task1_model_M->solverInfo, (void *)
                    &lab2_task1_model_M->intgData);
  rtsiSetSolverName(&lab2_task1_model_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab2_task1_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab2_task1_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab2_task1_model_M->Timing.sampleTimes =
      (&lab2_task1_model_M->Timing.sampleTimesArray[0]);
    lab2_task1_model_M->Timing.offsetTimes =
      (&lab2_task1_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab2_task1_model_M->Timing.sampleTimes[0] = (0.0);
    lab2_task1_model_M->Timing.sampleTimes[1] = (0.002);
    lab2_task1_model_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    lab2_task1_model_M->Timing.offsetTimes[0] = (0.0);
    lab2_task1_model_M->Timing.offsetTimes[1] = (0.0);
    lab2_task1_model_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab2_task1_model_M, &lab2_task1_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab2_task1_model_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      lab2_task1_model_M->Timing.perTaskSampleHitsArray;
    lab2_task1_model_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    lab2_task1_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab2_task1_model_M, 50.0);
  lab2_task1_model_M->Timing.stepSize0 = 0.002;
  lab2_task1_model_M->Timing.stepSize1 = 0.002;
  lab2_task1_model_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  lab2_task1_model_M->Sizes.checksums[0] = (787492030U);
  lab2_task1_model_M->Sizes.checksums[1] = (1129890614U);
  lab2_task1_model_M->Sizes.checksums[2] = (1044369204U);
  lab2_task1_model_M->Sizes.checksums[3] = (699577681U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab2_task1_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab2_task1_model_M->extModeInfo,
      &lab2_task1_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab2_task1_model_M->extModeInfo,
                        lab2_task1_model_M->Sizes.checksums);
    rteiSetTPtr(lab2_task1_model_M->extModeInfo, rtmGetTPtr(lab2_task1_model_M));
  }

  lab2_task1_model_M->solverInfoPtr = (&lab2_task1_model_M->solverInfo);
  lab2_task1_model_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lab2_task1_model_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lab2_task1_model_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  lab2_task1_model_M->blockIO = ((void *) &lab2_task1_model_B);

  {
    lab2_task1_model_B.y = 0.0;
    lab2_task1_model_B.RateTransitionx = 0.0;
    lab2_task1_model_B.Joystick_gain_x = 0.0;
    lab2_task1_model_B.Switch = 0.0;
    lab2_task1_model_B.PitchCounttorad = 0.0;
    lab2_task1_model_B.Gain1[0] = 0.0;
    lab2_task1_model_B.Gain1[1] = 0.0;
    lab2_task1_model_B.y1 = 0.0;
    lab2_task1_model_B.RateTransitiony = 0.0;
    lab2_task1_model_B.Joystick_gain_y = 0.0;
    lab2_task1_model_B.Gain2 = 0.0;
    lab2_task1_model_B.Switch1 = 0.0;
    lab2_task1_model_B.elevation_rate = 0.0;
    lab2_task1_model_B.TravelCounttorad = 0.0;
    lab2_task1_model_B.TravelTransferFcn = 0.0;
    lab2_task1_model_B.PitchTransferFcn = 0.0;
    lab2_task1_model_B.ElevationCounttorad = 0.0;
    lab2_task1_model_B.Filter = 0.0;
    lab2_task1_model_B.ElevationTransferFcn = 0.0;
    lab2_task1_model_B.u[0] = 0.0;
    lab2_task1_model_B.u[1] = 0.0;
    lab2_task1_model_B.Sum1 = 0.0;
    lab2_task1_model_B.Frontgain = 0.0;
    lab2_task1_model_B.Backgain = 0.0;
    lab2_task1_model_B.FrontmotorSaturation = 0.0;
    lab2_task1_model_B.BackmotorSaturation = 0.0;
    lab2_task1_model_B.u_d[0] = 0.0;
    lab2_task1_model_B.u_d[1] = 0.0;
  }

  /* parameters */
  lab2_task1_model_M->defaultParam = ((real_T *)&lab2_task1_model_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab2_task1_model_X;
    lab2_task1_model_M->contStates = (x);
    (void) memset((void *)&lab2_task1_model_X, 0,
                  sizeof(X_lab2_task1_model_T));
  }

  /* states (dwork) */
  lab2_task1_model_M->dwork = ((void *) &lab2_task1_model_DW);
  (void) memset((void *)&lab2_task1_model_DW, 0,
                sizeof(DW_lab2_task1_model_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_task1_model_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_task1_model_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_task1_model_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_task1_model_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_task1_model_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_task1_model_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_task1_model_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_task1_model_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  lab2_task1_model_DW.RateTransitionx_Buffer0 = 0.0;
  lab2_task1_model_DW.RateTransitiony_Buffer0 = 0.0;
  lab2_task1_model_DW.HILWriteAnalog_Buffer[0] = 0.0;
  lab2_task1_model_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab2_task1_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab2_task1_model_M->Sizes.numContStates = (8);/* Number of continuous states */
  lab2_task1_model_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab2_task1_model_M->Sizes.numY = (0);/* Number of model outputs */
  lab2_task1_model_M->Sizes.numU = (0);/* Number of model inputs */
  lab2_task1_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab2_task1_model_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab2_task1_model_M->Sizes.numBlocks = (66);/* Number of blocks */
  lab2_task1_model_M->Sizes.numBlockIO = (25);/* Number of block outputs */
  lab2_task1_model_M->Sizes.numBlockPrms = (213);/* Sum of parameter "widths" */
  return lab2_task1_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
