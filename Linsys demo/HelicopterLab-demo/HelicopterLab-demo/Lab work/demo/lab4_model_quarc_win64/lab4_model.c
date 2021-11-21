/*
 * lab4_model.c
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
#include "lab4_model_dt.h"

t_stream lab4_model_rtZt_stream = NULL;

/* Block signals (default storage) */
B_lab4_model_T lab4_model_B;

/* Continuous states */
X_lab4_model_T lab4_model_X;

/* Block states (default storage) */
DW_lab4_model_T lab4_model_DW;

/* Real-time model */
static RT_MODEL_lab4_model_T lab4_model_M_;
RT_MODEL_lab4_model_T *const lab4_model_M = &lab4_model_M_;
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
  rtmSampleHitPtr[1] = rtmStepTask(lab4_model_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(lab4_model_M, 2);
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
  if (lab4_model_M->Timing.TaskCounters.TID[1] == 0) {
    lab4_model_M->Timing.RateInteraction.TID1_2 =
      (lab4_model_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    lab4_model_M->Timing.perTaskSampleHits[5] =
      lab4_model_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab4_model_M->Timing.TaskCounters.TID[2])++;
  if ((lab4_model_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    lab4_model_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  lab4_model_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void lab4_model_output0(void)          /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall2_o1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_TmpSignalConversionAtToFile[39];
  real_T rtb_DeadZoney;
  int32_T rtb_StreamFormattedRead1_o8;
  int32_T rtb_StreamFormattedRead_o2;
  int32_T rtb_StreamCall2_o3;
  int32_T rtb_StreamFormattedRead1_o12;
  real_T P_kf_est_tmp[36];
  real_T b_I_0[36];
  real_T c_I_0[36];
  real_T c_I_1[36];
  real_T A_tmp[30];
  real_T rtb_L_kf[30];
  real_T tmp_0[30];
  real_T A[25];
  real_T b[25];
  real_T tmp[9];
  real_T tmp_3[6];
  real_T tmp_4[6];
  real_T tmp_5[5];
  real_T tmp_6[5];
  real_T tmp_7[5];
  real_T rtb_Gain2[3];
  real_T tmp_1[2];
  real_T tmp_2[2];
  real_T az;
  real_T euler_rates_tmp;
  real_T euler_rates_tmp_0;
  real_T phi;
  real_T theta;
  int32_T c_ix;
  int32_T d_k;
  int32_T e;
  int32_T i;
  int32_T ijA;
  int32_T ix;
  int32_T jA;
  int_T ri;
  int8_T b_I[36];
  int8_T c_I[36];
  int8_T ipiv[5];
  int8_T p[5];
  if (rtmIsMajorTimeStep(lab4_model_M)) {
    /* set solver stop time */
    if (!(lab4_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab4_model_M->solverInfo,
                            ((lab4_model_M->Timing.clockTickH0 + 1) *
        lab4_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab4_model_M->solverInfo,
                            ((lab4_model_M->Timing.clockTick0 + 1) *
        lab4_model_M->Timing.stepSize0 + lab4_model_M->Timing.clockTickH0 *
        lab4_model_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab4_model_M)) {
    lab4_model_M->Timing.t[0] = rtsiGetT(&lab4_model_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(lab4_model_DW.Skiptonextline_SubsysRanBC);
  if (rtmIsMajorTimeStep(lab4_model_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

    /* S-Function Block: lab4_model/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(lab4_model_DW.HILReadEncoderTimebase_Task,
        1, &lab4_model_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          lab4_model_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          lab4_model_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = lab4_model_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S4>/Pitch: Count to rad' */
    lab4_model_B.PitchCounttorad = lab4_model_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* S-Function (stream_call_block): '<S5>/Stream Call2' incorporates:
     *  Constant: '<S5>/Constant4'
     *  S-Function (string_constant_block): '<S5>/String Constant1'
     */

    /* S-Function Block: lab4_model/IMU_BT/Stream Call2 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (lab4_model_P.Constant4_Value != 0);
      rtb_StreamCall2_o1 = NULL;
      switch (lab4_model_DW.StreamCall2_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) lab4_model_P.StringConstant1_Value, 255) ==
                255) {
              rtmSetErrorStatus(lab4_model_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                lab4_model_P.StringConstant1_Value,
                lab4_model_P.StreamCall2_NonBlocking != 0,
                lab4_model_P.StreamCall2_SendBufferSize,
                lab4_model_P.StreamCall2_ReceiveBufferSize,
                &lab4_model_DW.StreamCall2_Stream);
              if (result == 0) {
                lab4_model_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(lab4_model_DW.StreamCall2_Stream,
                                      (t_stream_byte_order)
                                      lab4_model_P.StreamCall2_Endian);
                rtb_StreamCall2_o1 = &lab4_model_DW.StreamCall2_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                lab4_model_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(lab4_model_DW.StreamCall2_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              lab4_model_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(lab4_model_DW.StreamCall2_Stream,
                                    (t_stream_byte_order)
                                    lab4_model_P.StreamCall2_Endian);
              rtb_StreamCall2_o1 = &lab4_model_DW.StreamCall2_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall2_o1 = &lab4_model_DW.StreamCall2_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(lab4_model_DW.StreamCall2_Stream);
          if (close_result == 0) {
            lab4_model_DW.StreamCall2_State = STREAM_CALL_STATE_NOT_CONNECTED;
            lab4_model_DW.StreamCall2_Stream = NULL;
            rtb_StreamCall2_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      lab4_model_B.StreamCall2_o2 = lab4_model_DW.StreamCall2_State;
      rtb_StreamCall2_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_read_block): '<S5>/Stream Formatted Read1' */
    {
      t_error result;
      lab4_model_B.StreamFormattedRead1_o11 = false;
      if (rtb_StreamCall2_o1 != NULL) {
        result = stream_scan_utf8_char_array(*rtb_StreamCall2_o1,
          lab4_model_P.StreamFormattedRead1_MaxUnits,
          &rtb_StreamFormattedRead1_o8, " :%f,%f,%f,%f,%f,%f\r"
          , &lab4_model_B.StreamFormattedRead1_o2
          , &lab4_model_B.StreamFormattedRead1_o3
          , &lab4_model_B.StreamFormattedRead1_o4
          , &lab4_model_B.StreamFormattedRead1_o5
          , &lab4_model_B.StreamFormattedRead1_o6
          , &lab4_model_B.StreamFormattedRead1_o7
          );
        lab4_model_B.StreamFormattedRead1_o11 = (result == 0);
        if (result > 0) {
          result = 0;
        }
      } else {
        rtb_StreamFormattedRead1_o8 = 0;
        result = 0;
        lab4_model_B.StreamFormattedRead1_o2 = 0;
        lab4_model_B.StreamFormattedRead1_o3 = 0;
        lab4_model_B.StreamFormattedRead1_o4 = 0;
        lab4_model_B.StreamFormattedRead1_o5 = 0;
        lab4_model_B.StreamFormattedRead1_o6 = 0;
        lab4_model_B.StreamFormattedRead1_o7 = 0;
      }

      lab4_model_B.StreamFormattedRead1_o10 = (result ==
        -QERR_MISMATCHED_CHARACTER);
      if (result == -QERR_WOULD_BLOCK || result == -QERR_MISMATCHED_CHARACTER) {
        result = 0;
      }

      rtb_StreamFormattedRead1_o12 = result;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    lab4_model_B.DataTypeConversion2[0] = lab4_model_B.StreamFormattedRead1_o5;
    lab4_model_B.DataTypeConversion2[1] = lab4_model_B.StreamFormattedRead1_o6;
    lab4_model_B.DataTypeConversion2[2] = lab4_model_B.StreamFormattedRead1_o7;

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    lab4_model_B.DataTypeConversion1[0] = lab4_model_B.StreamFormattedRead1_o2;
    lab4_model_B.DataTypeConversion1[1] = lab4_model_B.StreamFormattedRead1_o3;
    lab4_model_B.DataTypeConversion1[2] = lab4_model_B.StreamFormattedRead1_o4;
    for (i = 0; i < 3; i++) {
      /* Gain: '<S5>/Gain1' */
      lab4_model_B.Gain1[i] = 0.0;
      lab4_model_B.Gain1[i] += lab4_model_P.Gain1_Gain[i] *
        lab4_model_B.DataTypeConversion2[0];
      lab4_model_B.Gain1[i] += lab4_model_P.Gain1_Gain[i + 3] *
        lab4_model_B.DataTypeConversion2[1];
      lab4_model_B.Gain1[i] += lab4_model_P.Gain1_Gain[i + 6] *
        lab4_model_B.DataTypeConversion2[2];

      /* Gain: '<S5>/Gain2' */
      rtb_Gain2[i] = lab4_model_P.Gain2_Gain[i + 6] *
        lab4_model_B.DataTypeConversion1[2] + (lab4_model_P.Gain2_Gain[i + 3] *
        lab4_model_B.DataTypeConversion1[1] + lab4_model_P.Gain2_Gain[i] *
        lab4_model_B.DataTypeConversion1[0]);
    }

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travle rate]': '<S3>:1' */
    /* '<S3>:1:4' */
    /* '<S3>:1:5' */
    /* '<S3>:1:7' */
    /* '<S3>:1:8' */
    /* '<S3>:1:9' */
    az = rtb_Gain2[2];
    if (rtb_Gain2[2] == 0.0) {
      /* '<S3>:1:12' */
      /* '<S3>:1:13' */
      az = 1.0E-7;
    }

    /* '<S3>:1:17' */
    phi = atan(rtb_Gain2[1] / az);

    /* '<S3>:1:18' */
    theta = atan(rtb_Gain2[0] / sqrt(rtb_Gain2[1] * rtb_Gain2[1] + az * az));

    /* '<S3>:1:19' */
    lab4_model_B.euler_angles[0] = phi + 0.03;
    lab4_model_B.euler_angles[1] = theta;

    /* '<S3>:1:27' */
    /* '<S3>:1:34' */
    euler_rates_tmp = tan(theta);
    euler_rates_tmp_0 = sin(phi);
    phi = cos(phi);
    theta = cos(theta);
    tmp[0] = 1.0;
    tmp[3] = euler_rates_tmp_0 * euler_rates_tmp;
    tmp[6] = phi * euler_rates_tmp;
    tmp[1] = 0.0;
    tmp[4] = phi;
    tmp[7] = -euler_rates_tmp_0;
    tmp[2] = 0.0;
    tmp[5] = euler_rates_tmp_0 / theta;
    tmp[8] = phi / theta;
    for (i = 0; i < 3; i++) {
      lab4_model_B.euler_rates[i] = 0.0;
      lab4_model_B.euler_rates[i] += tmp[i] * lab4_model_B.Gain1[0];
      lab4_model_B.euler_rates[i] += tmp[i + 3] * lab4_model_B.Gain1[1];
      lab4_model_B.euler_rates[i] += tmp[i + 6] * lab4_model_B.Gain1[2];
    }

    if (az > 0.0) {
      /* '<S3>:1:35' */
      /* '<S3>:1:36' */
      lab4_model_B.euler_rates[1] = -lab4_model_B.euler_rates[1];

      /* '<S3>:1:37' */
      lab4_model_B.euler_rates[2] = -lab4_model_B.euler_rates[2];
      if (lab4_model_B.euler_angles[0] > 0.0) {
        /* '<S3>:1:39' */
        /* '<S3>:1:40' */
        lab4_model_B.euler_angles[0] += -3.1415926535897931;
      } else {
        /* '<S3>:1:42' */
        lab4_model_B.euler_angles[0] += 3.1415926535897931;
      }
    }

    /* End of MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' */

    /* Gain: '<S4>/Elevation: Count to rad' */
    lab4_model_B.ElevationCounttorad = lab4_model_P.ElevationCounttorad_Gain *
      rtb_DeadZoney;

    /* Gain: '<S4>/Travel: Count to rad' */
    lab4_model_B.TravelCounttorad = lab4_model_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  lab4_model_B.PitchTransferFcn = 0.0;
  lab4_model_B.PitchTransferFcn += lab4_model_P.PitchTransferFcn_C *
    lab4_model_X.PitchTransferFcn_CSTATE;
  lab4_model_B.PitchTransferFcn += lab4_model_P.PitchTransferFcn_D *
    lab4_model_B.PitchCounttorad;

  /* TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  lab4_model_B.ElevationTransferFcn = 0.0;
  lab4_model_B.ElevationTransferFcn += lab4_model_P.ElevationTransferFcn_C *
    lab4_model_X.ElevationTransferFcn_CSTATE;
  lab4_model_B.ElevationTransferFcn += lab4_model_P.ElevationTransferFcn_D *
    lab4_model_B.ElevationCounttorad;

  /* TransferFcn: '<S4>/Travel: Transfer Fcn' */
  lab4_model_B.TravelTransferFcn = 0.0;
  lab4_model_B.TravelTransferFcn += lab4_model_P.TravelTransferFcn_C *
    lab4_model_X.TravelTransferFcn_CSTATE;
  lab4_model_B.TravelTransferFcn += lab4_model_P.TravelTransferFcn_D *
    lab4_model_B.TravelCounttorad;

  /* RateTransition: '<S20>/Rate Transition: x' incorporates:
   *  RateTransition: '<S20>/Rate Transition: y'
   */
  if (rtmIsMajorTimeStep(lab4_model_M)) {
    for (i = 0; i < 6; i++) {
      /* UnitDelay: '<S6>/Unit Delay' */
      lab4_model_B.UnitDelay[i] = lab4_model_DW.UnitDelay_DSTATE[i];
    }

    /* UnitDelay: '<S6>/Unit Delay1' */
    memcpy(&lab4_model_B.UnitDelay1[0], &lab4_model_DW.UnitDelay1_DSTATE[0], 36U
           * sizeof(real_T));

    /* MATLAB Function: '<S6>/Kalman_estimation' incorporates:
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant6'
     *  UnitDelay: '<S6>/Unit Delay1'
     */
    /* MATLAB Function 'Kalman filter/Kalman_estimation': '<S17>:1' */
    /* '<S17>:1:2' */
    for (i = 0; i < 25; i++) {
      b[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      for (ri = 0; ri < 6; ri++) {
        ix = 5 * ri + i;
        A_tmp[ri + 6 * i] = lab4_model_P.C_d[ix];
        tmp_0[ix] = 0.0;
        for (jA = 0; jA < 6; jA++) {
          tmp_0[ix] += lab4_model_P.C_d[5 * jA + i] * lab4_model_B.UnitDelay1[6 *
            ri + jA];
        }
      }
    }

    for (i = 0; i < 5; i++) {
      for (ri = 0; ri < 5; ri++) {
        az = 0.0;
        for (jA = 0; jA < 6; jA++) {
          az += tmp_0[5 * jA + i] * A_tmp[6 * ri + jA];
        }

        jA = 5 * ri + i;
        A[jA] = lab4_model_P.R_d[jA] + az;
      }

      ipiv[i] = (int8_T)(i + 1);
    }

    for (ri = 0; ri < 4; ri++) {
      i = ri * 6;
      jA = 0;
      ix = i;
      az = fabs(A[i]);
      for (d_k = 2; d_k <= 5 - ri; d_k++) {
        ix++;
        euler_rates_tmp = fabs(A[ix]);
        if (euler_rates_tmp > az) {
          jA = d_k - 1;
          az = euler_rates_tmp;
        }
      }

      if (A[i + jA] != 0.0) {
        if (jA != 0) {
          jA += ri;
          ipiv[ri] = (int8_T)(jA + 1);
          ix = ri;
          for (d_k = 0; d_k < 5; d_k++) {
            az = A[ix];
            A[ix] = A[jA];
            A[jA] = az;
            ix += 5;
            jA += 5;
          }
        }

        jA = (i - ri) + 5;
        for (ix = i + 1; ix < jA; ix++) {
          A[ix] /= A[i];
        }
      }

      jA = i;
      ix = i + 5;
      for (d_k = 0; d_k <= 3 - ri; d_k++) {
        if (A[ix] != 0.0) {
          az = -A[ix];
          c_ix = i + 1;
          e = (jA - ri) + 10;
          for (ijA = jA + 6; ijA < e; ijA++) {
            A[ijA] += A[c_ix] * az;
            c_ix++;
          }
        }

        ix += 5;
        jA += 5;
      }
    }

    for (i = 0; i < 5; i++) {
      p[i] = (int8_T)(i + 1);
    }

    if (ipiv[0] > 1) {
      i = p[ipiv[0] - 1];
      p[ipiv[0] - 1] = p[0];
      p[0] = (int8_T)i;
    }

    if (ipiv[1] > 2) {
      i = p[ipiv[1] - 1];
      p[ipiv[1] - 1] = p[1];
      p[1] = (int8_T)i;
    }

    if (ipiv[2] > 3) {
      i = p[ipiv[2] - 1];
      p[ipiv[2] - 1] = p[2];
      p[2] = (int8_T)i;
    }

    if (ipiv[3] > 4) {
      i = p[ipiv[3] - 1];
      p[ipiv[3] - 1] = p[3];
      p[3] = (int8_T)i;
    }

    for (ri = 0; ri < 5; ri++) {
      d_k = p[ri] - 1;
      b[ri + 5 * d_k] = 1.0;
      for (jA = ri; jA + 1 < 6; jA++) {
        i = 5 * d_k + jA;
        if (b[i] != 0.0) {
          for (ix = jA + 1; ix + 1 < 6; ix++) {
            c_ix = 5 * d_k + ix;
            b[c_ix] -= b[i] * A[5 * jA + ix];
          }
        }
      }
    }

    for (ri = 0; ri < 5; ri++) {
      i = 5 * ri;
      for (jA = 4; jA >= 0; jA--) {
        ix = 5 * jA;
        if (b[jA + i] != 0.0) {
          c_ix = jA + i;
          b[c_ix] /= A[jA + ix];
          for (d_k = 0; d_k < jA; d_k++) {
            e = d_k + i;
            b[e] -= b[c_ix] * A[d_k + ix];
          }
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (ri = 0; ri < 5; ri++) {
        jA = i + 6 * ri;
        tmp_0[jA] = 0.0;
        for (ix = 0; ix < 6; ix++) {
          tmp_0[jA] += lab4_model_B.UnitDelay1[6 * ix + i] * A_tmp[6 * ri + ix];
        }
      }

      for (ri = 0; ri < 5; ri++) {
        ix = i + 6 * ri;
        rtb_L_kf[ix] = 0.0;
        for (jA = 0; jA < 5; jA++) {
          rtb_L_kf[ix] += tmp_0[6 * jA + i] * b[5 * ri + jA];
        }
      }
    }

    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }

    for (ri = 0; ri < 6; ri++) {
      b_I[ri + 6 * ri] = 1;
    }

    /* '<S17>:1:4' */
    for (i = 0; i < 36; i++) {
      c_I[i] = 0;
    }

    for (ri = 0; ri < 6; ri++) {
      c_I[ri + 6 * ri] = 1;
    }

    /* SignalConversion generated from: '<S17>/ SFunction ' incorporates:
     *  MATLAB Function: '<S6>/Kalman_estimation'
     */
    /* '<S17>:1:5' */
    tmp_5[0] = lab4_model_B.euler_angles[0];
    tmp_5[1] = lab4_model_B.euler_rates[0];
    tmp_5[2] = lab4_model_B.euler_angles[1];
    tmp_5[3] = lab4_model_B.euler_rates[1];
    tmp_5[4] = lab4_model_B.euler_rates[2];

    /* MATLAB Function: '<S6>/Kalman_estimation' incorporates:
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant6'
     *  UnitDelay: '<S6>/Unit Delay1'
     */
    for (i = 0; i < 5; i++) {
      tmp_6[i] = 0.0;
      for (ri = 0; ri < 6; ri++) {
        tmp_6[i] += lab4_model_P.C_d[5 * ri + i] * lab4_model_B.UnitDelay[ri];
      }

      tmp_7[i] = tmp_5[i] - tmp_6[i];
    }

    for (i = 0; i < 6; i++) {
      az = 0.0;
      for (ri = 0; ri < 5; ri++) {
        az += rtb_L_kf[6 * ri + i] * tmp_7[ri];
      }

      lab4_model_B.x_kf_est[i] = lab4_model_B.UnitDelay[i] + az;
      for (ri = 0; ri < 6; ri++) {
        ix = i + 6 * ri;
        P_kf_est_tmp[ix] = 0.0;
        for (jA = 0; jA < 5; jA++) {
          P_kf_est_tmp[ix] += rtb_L_kf[6 * jA + i] * lab4_model_P.C_d[5 * ri +
            jA];
        }
      }
    }

    for (i = 0; i < 36; i++) {
      c_I_0[i] = (real_T)c_I[i] - P_kf_est_tmp[i];
    }

    for (i = 0; i < 6; i++) {
      for (ri = 0; ri < 6; ri++) {
        ix = i + 6 * ri;
        c_I_1[ix] = 0.0;
        for (jA = 0; jA < 6; jA++) {
          c_I_1[ix] += c_I_0[6 * jA + i] * lab4_model_B.UnitDelay1[6 * ri + jA];
        }

        b_I_0[ri + 6 * i] = (real_T)b_I[ix] - P_kf_est_tmp[ix];
      }

      for (ri = 0; ri < 5; ri++) {
        ix = i + 6 * ri;
        A_tmp[ix] = 0.0;
        for (jA = 0; jA < 5; jA++) {
          A_tmp[ix] += rtb_L_kf[6 * jA + i] * lab4_model_P.R_d[5 * ri + jA];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (ri = 0; ri < 6; ri++) {
        ix = i + 6 * ri;
        c_I_0[ix] = 0.0;
        for (jA = 0; jA < 6; jA++) {
          c_I_0[ix] += c_I_1[6 * jA + i] * b_I_0[6 * ri + jA];
        }

        P_kf_est_tmp[ix] = 0.0;
        for (jA = 0; jA < 5; jA++) {
          P_kf_est_tmp[ix] += A_tmp[6 * jA + i] * rtb_L_kf[6 * jA + ri];
        }
      }
    }

    for (i = 0; i < 36; i++) {
      lab4_model_B.P_kf_est[i] = c_I_0[i] + P_kf_est_tmp[i];
    }

    if (lab4_model_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S20>/Rate Transition: x' */
      lab4_model_B.RateTransitionx = lab4_model_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S20>/Dead Zone: x' */
    if (lab4_model_B.RateTransitionx > lab4_model_P.DeadZonex_End) {
      /* DeadZone: '<S20>/Dead Zone: y' */
      rtb_DeadZoney = lab4_model_B.RateTransitionx - lab4_model_P.DeadZonex_End;
    } else if (lab4_model_B.RateTransitionx >= lab4_model_P.DeadZonex_Start) {
      /* DeadZone: '<S20>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S20>/Dead Zone: y' */
      rtb_DeadZoney = lab4_model_B.RateTransitionx -
        lab4_model_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S20>/Dead Zone: x' */

    /* Gain: '<S20>/Joystick_gain_x' incorporates:
     *  Gain: '<S20>/Gain: x'
     */
    lab4_model_B.Joystick_gain_x = lab4_model_P.Gainx_Gain * rtb_DeadZoney *
      lab4_model_P.Joystick_gain_x;
    if (lab4_model_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S20>/Rate Transition: y' */
      lab4_model_B.RateTransitiony = lab4_model_DW.RateTransitiony_Buffer0;
    }

    /* DeadZone: '<S20>/Dead Zone: y' */
    if (lab4_model_B.RateTransitiony > lab4_model_P.DeadZoney_End) {
      /* DeadZone: '<S20>/Dead Zone: y' */
      rtb_DeadZoney = lab4_model_B.RateTransitiony - lab4_model_P.DeadZoney_End;
    } else if (lab4_model_B.RateTransitiony >= lab4_model_P.DeadZoney_Start) {
      /* DeadZone: '<S20>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S20>/Dead Zone: y' */
      rtb_DeadZoney = lab4_model_B.RateTransitiony -
        lab4_model_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S20>/Dead Zone: y' */

    /* Gain: '<S20>/Joystick_gain_y' incorporates:
     *  Gain: '<S20>/Gain: y'
     */
    lab4_model_B.Joystick_gain_y = lab4_model_P.Gainy_Gain * rtb_DeadZoney *
      lab4_model_P.Joystick_gain_y;

    /* Gain: '<S8>/Gain2' */
    lab4_model_B.Gain2 = lab4_model_P.Gain2_Gain_a *
      lab4_model_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S20>/Rate Transition: x' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (lab4_model_P.Constant1_Value > lab4_model_P.Switch_Threshold) {
    /* Step: '<S8>/Step2' incorporates:
     *  Step: '<S8>/Step3'
     *  Step: '<S8>/Step4'
     *  Step: '<S8>/Step5'
     */
    az = lab4_model_M->Timing.t[0];
    if (az < lab4_model_P.Step2_Time) {
      phi = lab4_model_P.Step2_Y0;
    } else {
      phi = lab4_model_P.Step2_YFinal;
    }

    /* End of Step: '<S8>/Step2' */

    /* Step: '<S8>/Step3' */
    if (az < lab4_model_P.Step3_Time) {
      theta = lab4_model_P.Step3_Y0;
    } else {
      theta = lab4_model_P.Step3_YFinal;
    }

    /* Step: '<S8>/Step4' */
    if (az < lab4_model_P.Step4_Time) {
      euler_rates_tmp = lab4_model_P.Step4_Y0;
    } else {
      euler_rates_tmp = lab4_model_P.Step4_YFinal;
    }

    /* Step: '<S8>/Step5' */
    if (az < lab4_model_P.Step5_Time) {
      az = lab4_model_P.Step5_Y0;
    } else {
      az = lab4_model_P.Step5_YFinal;
    }

    /* Switch: '<S8>/Switch' incorporates:
     *  Sum: '<S8>/y'
     */
    lab4_model_B.Switch = ((phi + theta) + euler_rates_tmp) + az;
  } else {
    /* Switch: '<S8>/Switch' */
    lab4_model_B.Switch = lab4_model_B.Joystick_gain_x;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (lab4_model_P.Constant1_Value > lab4_model_P.Switch1_Threshold) {
    /* Step: '<S8>/Step' incorporates:
     *  Step: '<S8>/Step1'
     *  Step: '<S8>/Step6'
     *  Step: '<S8>/Step7'
     *  Step: '<S8>/Step8'
     */
    az = lab4_model_M->Timing.t[0];
    if (az < lab4_model_P.Step_Time) {
      phi = lab4_model_P.Step_Y0;
    } else {
      phi = lab4_model_P.Step_YFinal;
    }

    /* End of Step: '<S8>/Step' */

    /* Step: '<S8>/Step1' */
    if (az < lab4_model_P.Step1_Time) {
      theta = lab4_model_P.Step1_Y0;
    } else {
      theta = lab4_model_P.Step1_YFinal;
    }

    /* Step: '<S8>/Step6' */
    if (az < lab4_model_P.Step6_Time) {
      euler_rates_tmp = lab4_model_P.Step6_Y0;
    } else {
      euler_rates_tmp = lab4_model_P.Step6_YFinal;
    }

    /* Step: '<S8>/Step7' */
    if (az < lab4_model_P.Step7_Time) {
      euler_rates_tmp_0 = lab4_model_P.Step7_Y0;
    } else {
      euler_rates_tmp_0 = lab4_model_P.Step7_YFinal;
    }

    /* Step: '<S8>/Step8' */
    if (az < lab4_model_P.Step8_Time) {
      az = lab4_model_P.Step8_Y0;
    } else {
      az = lab4_model_P.Step8_YFinal;
    }

    /* Switch: '<S8>/Switch1' incorporates:
     *  Sum: '<S8>/y1'
     */
    lab4_model_B.Switch1 = (((phi + theta) + euler_rates_tmp) +
      euler_rates_tmp_0) + az;
  } else {
    /* Switch: '<S8>/Switch1' */
    lab4_model_B.Switch1 = lab4_model_B.Gain2;
  }

  /* End of Switch: '<S8>/Switch1' */
  if (rtmIsMajorTimeStep(lab4_model_M)) {
  }

  /* SignalConversion generated from: '<S7>/K' */
  tmp_5[2] = lab4_model_B.x_kf_est[3];

  /* Integrator: '<S7>/Integrator' */
  lab4_model_B.Integrator[0] = lab4_model_X.Integrator_CSTATE[0];

  /* SignalConversion generated from: '<S7>/K' */
  tmp_5[0] = lab4_model_B.x_kf_est[0];
  tmp_5[3] = lab4_model_B.Integrator[0];

  /* Gain: '<Root>/F' incorporates:
   *  SignalConversion generated from: '<Root>/F'
   */
  tmp_1[0] = lab4_model_P.F_aug[0] * lab4_model_B.Switch + lab4_model_P.F_aug[2]
    * lab4_model_B.Switch1;

  /* Integrator: '<S7>/Integrator' */
  lab4_model_B.Integrator[1] = lab4_model_X.Integrator_CSTATE[1];

  /* SignalConversion generated from: '<S7>/K' */
  tmp_5[1] = lab4_model_B.x_kf_est[1];
  tmp_5[4] = lab4_model_B.Integrator[1];

  /* Gain: '<Root>/F' incorporates:
   *  SignalConversion generated from: '<Root>/F'
   */
  tmp_1[1] = lab4_model_P.F_aug[1] * lab4_model_B.Switch;
  tmp_1[1] += lab4_model_P.F_aug[3] * lab4_model_B.Switch1;
  for (i = 0; i < 2; i++) {
    /* Gain: '<S7>/K' */
    tmp_2[i] = 0.0;
    for (ri = 0; ri < 5; ri++) {
      tmp_2[i] += lab4_model_P.K_aug[(ri << 1) + i] * tmp_5[ri];
    }

    /* End of Gain: '<S7>/K' */

    /* Sum: '<Root>/Sum' */
    lab4_model_B.u[i] = tmp_1[i] - tmp_2[i];
  }

  if (rtmIsMajorTimeStep(lab4_model_M)) {
    /* UnitDelay: '<S10>/Unit Delay' */
    lab4_model_B.UnitDelay_c = lab4_model_DW.UnitDelay_DSTATE_d;

    /* RelationalOperator: '<S10>/Relational Operator' */
    lab4_model_B.RelationalOperator = (lab4_model_B.StreamFormattedRead1_o2 ==
      lab4_model_B.UnitDelay_c);

    /* UnitDelay: '<S11>/Unit Delay' */
    lab4_model_B.UnitDelay_d = lab4_model_DW.UnitDelay_DSTATE_h;

    /* RelationalOperator: '<S11>/Relational Operator' */
    lab4_model_B.RelationalOperator_k = (lab4_model_B.StreamFormattedRead1_o3 ==
      lab4_model_B.UnitDelay_d);

    /* UnitDelay: '<S12>/Unit Delay' */
    lab4_model_B.UnitDelay_n = lab4_model_DW.UnitDelay_DSTATE_f;

    /* RelationalOperator: '<S12>/Relational Operator' */
    lab4_model_B.RelationalOperator_p = (lab4_model_B.StreamFormattedRead1_o4 ==
      lab4_model_B.UnitDelay_n);

    /* UnitDelay: '<S13>/Unit Delay' */
    lab4_model_B.UnitDelay_i = lab4_model_DW.UnitDelay_DSTATE_e;

    /* RelationalOperator: '<S13>/Relational Operator' */
    lab4_model_B.RelationalOperator_n = (lab4_model_B.StreamFormattedRead1_o5 ==
      lab4_model_B.UnitDelay_i);

    /* UnitDelay: '<S14>/Unit Delay' */
    lab4_model_B.UnitDelay_c0 = lab4_model_DW.UnitDelay_DSTATE_j;

    /* RelationalOperator: '<S14>/Relational Operator' */
    lab4_model_B.RelationalOperator_g = (lab4_model_B.StreamFormattedRead1_o6 ==
      lab4_model_B.UnitDelay_c0);

    /* UnitDelay: '<S15>/Unit Delay' */
    lab4_model_B.UnitDelay_a = lab4_model_DW.UnitDelay_DSTATE_dd;

    /* RelationalOperator: '<S15>/Relational Operator' */
    lab4_model_B.RelationalOperator_m = (lab4_model_B.StreamFormattedRead1_o7 ==
      lab4_model_B.UnitDelay_a);

    /* Logic: '<S5>/Logical Operator1' incorporates:
     *  Logic: '<S5>/Logical Operator'
     */
    lab4_model_B.LogicalOperator1 = ((!lab4_model_B.RelationalOperator) ||
      (!lab4_model_B.RelationalOperator_k) ||
      (!lab4_model_B.RelationalOperator_p) ||
      (!lab4_model_B.RelationalOperator_n) ||
      (!lab4_model_B.RelationalOperator_g) ||
      (!lab4_model_B.RelationalOperator_m));
  }

  /* MATLAB Function: '<S6>/Kalman_predictor' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  for (i = 0; i < 6; i++) {
    lab4_model_B.x_kf_pred[i] = lab4_model_B.UnitDelay[i];
  }

  memcpy(&lab4_model_B.P_kf_pred[0], &lab4_model_B.UnitDelay1[0], 36U * sizeof
         (real_T));

  /* MATLAB Function 'Kalman filter/Kalman_predictor': '<S18>:1' */
  if (lab4_model_B.LogicalOperator1) {
    /* '<S18>:1:3' */
    /* '<S18>:1:4' */
    /* '<S18>:1:5' */
    for (i = 0; i < 6; i++) {
      for (ri = 0; ri < 6; ri++) {
        jA = i + 6 * ri;
        c_I_0[jA] = 0.0;
        for (ix = 0; ix < 6; ix++) {
          c_I_0[jA] += lab4_model_P.A_d[6 * ix + i] * lab4_model_B.P_kf_est[6 *
            ri + ix];
        }
      }

      tmp_3[i] = 0.0;
      for (ri = 0; ri < 6; ri++) {
        az = 0.0;
        for (jA = 0; jA < 6; jA++) {
          az += c_I_0[6 * jA + i] * lab4_model_P.A_d[6 * jA + ri];
        }

        jA = 6 * ri + i;
        lab4_model_B.P_kf_pred[jA] = lab4_model_P.Q_d[jA] + az;
        tmp_3[i] += lab4_model_P.A_d[jA] * lab4_model_B.x_kf_est[ri];
      }

      tmp_4[i] = 0.0;
      tmp_4[i] += lab4_model_P.B_d[i] * lab4_model_B.u[0];
      tmp_4[i] += lab4_model_P.B_d[i + 6] * lab4_model_B.u[1];
      lab4_model_B.x_kf_pred[i] = tmp_3[i] + tmp_4[i];
    }
  }

  /* End of MATLAB Function: '<S6>/Kalman_predictor' */
  if (rtmIsMajorTimeStep(lab4_model_M)) {
  }

  /* Sum: '<S9>/Sum1' incorporates:
   *  Constant: '<S9>/Constant'
   */
  lab4_model_B.Sum1 = lab4_model_P.Vs_0 + lab4_model_B.u[0];

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  lab4_model_B.Backgain = (lab4_model_B.Sum1 + lab4_model_B.u[1]) *
    lab4_model_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  lab4_model_B.Frontgain = (lab4_model_B.Sum1 - lab4_model_B.u[1]) *
    lab4_model_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(lab4_model_M)) {
  }

  /* Saturate: '<S4>/Front motor: Saturation' */
  if (lab4_model_B.Frontgain > lab4_model_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S4>/Front motor: Saturation' */
    lab4_model_B.FrontmotorSaturation =
      lab4_model_P.FrontmotorSaturation_UpperSat;
  } else if (lab4_model_B.Frontgain < lab4_model_P.FrontmotorSaturation_LowerSat)
  {
    /* Saturate: '<S4>/Front motor: Saturation' */
    lab4_model_B.FrontmotorSaturation =
      lab4_model_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Front motor: Saturation' */
    lab4_model_B.FrontmotorSaturation = lab4_model_B.Frontgain;
  }

  /* End of Saturate: '<S4>/Front motor: Saturation' */

  /* Saturate: '<S4>/Back motor: Saturation' */
  if (lab4_model_B.Backgain > lab4_model_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S4>/Back motor: Saturation' */
    lab4_model_B.BackmotorSaturation = lab4_model_P.BackmotorSaturation_UpperSat;
  } else if (lab4_model_B.Backgain < lab4_model_P.BackmotorSaturation_LowerSat)
  {
    /* Saturate: '<S4>/Back motor: Saturation' */
    lab4_model_B.BackmotorSaturation = lab4_model_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Back motor: Saturation' */
    lab4_model_B.BackmotorSaturation = lab4_model_B.Backgain;
  }

  /* End of Saturate: '<S4>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(lab4_model_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: lab4_model/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      lab4_model_DW.HILWriteAnalog_Buffer[0] = lab4_model_B.FrontmotorSaturation;
      lab4_model_DW.HILWriteAnalog_Buffer[1] = lab4_model_B.BackmotorSaturation;
      result = hil_write_analog(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILWriteAnalog_channels, 2,
        &lab4_model_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
      }
    }

    /* Outputs for Enabled SubSystem: '<S5>/Skip to next line' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    if (lab4_model_B.StreamFormattedRead1_o10) {
      /* S-Function (stream_formatted_read_block): '<S16>/Stream Formatted Read' incorporates:
       *  S-Function (stream_call_block): '<S5>/Stream Call2'
       *  S-Function (stream_formatted_read_block): '<S5>/Stream Formatted Read1'
       */
      {
        if (((t_stream_ptr)rtb_StreamCall2_o1) != NULL) {
          stream_scan_utf8_char_array(*((t_stream_ptr)rtb_StreamCall2_o1),
            lab4_model_P.StreamFormattedRead_MaxUnits,
            &rtb_StreamFormattedRead_o2, " %*[^\r]"
            );
        } else {
          rtb_StreamFormattedRead_o2 = 0;
        }
      }

      if (rtmIsMajorTimeStep(lab4_model_M)) {
        srUpdateBC(lab4_model_DW.Skiptonextline_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S5>/Skip to next line' */

    /* S-Function (stop_with_error_block): '<S5>/Stop with Error' */

    /* S-Function Block: lab4_model/IMU_BT/Stop with Error (stop_with_error_block) */
    {
      if (rtb_StreamCall2_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall2_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S5>/Stop with Error1' */

    /* S-Function Block: lab4_model/IMU_BT/Stop with Error1 (stop_with_error_block) */
    {
      if (rtb_StreamFormattedRead1_o12) {
        rtmSetErrorStatus(lab4_model_M, "Facka feil");
        return;
      }
    }
  }

  /* SignalConversion generated from: '<S7>/Integrator' incorporates:
   *  Sum: '<S7>/Sum3'
   *  Sum: '<S7>/Sum4'
   */
  lab4_model_B.TmpSignalConversionAtIntegrator[0] = lab4_model_B.Switch -
    lab4_model_B.x_kf_est[0];
  lab4_model_B.TmpSignalConversionAtIntegrator[1] = lab4_model_B.Switch1 -
    lab4_model_B.x_kf_est[3];
  if (rtmIsMajorTimeStep(lab4_model_M)) {
    /* SignalConversion generated from: '<Root>/To Workspace' */
    lab4_model_B.TmpSignalConversionAtToWorkspac[0] = lab4_model_B.euler_angles
      [0];
    lab4_model_B.TmpSignalConversionAtToWorkspac[1] = lab4_model_B.euler_rates[0];
    lab4_model_B.TmpSignalConversionAtToWorkspac[2] = lab4_model_B.euler_angles
      [1];
    lab4_model_B.TmpSignalConversionAtToWorkspac[3] = lab4_model_B.euler_rates[1];
    lab4_model_B.TmpSignalConversionAtToWorkspac[4] = lab4_model_B.euler_rates[2];
  }

  /* TransferFcn: '<S2>/Transfer Fcn' */
  lab4_model_B.elevationrateenc = 0.0;
  lab4_model_B.elevationrateenc += lab4_model_P.TransferFcn_C *
    lab4_model_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(lab4_model_M)) {
    /* SignalConversion generated from: '<S2>/To File' */
    rtb_TmpSignalConversionAtToFile[0] = lab4_model_B.TravelCounttorad;
    rtb_TmpSignalConversionAtToFile[1] = lab4_model_B.TravelTransferFcn;
    rtb_TmpSignalConversionAtToFile[2] = lab4_model_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[3] = lab4_model_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[4] = lab4_model_B.ElevationCounttorad;
    rtb_TmpSignalConversionAtToFile[5] = lab4_model_B.elevationrateenc;
    rtb_TmpSignalConversionAtToFile[6] = lab4_model_B.u[1];
    rtb_TmpSignalConversionAtToFile[7] = lab4_model_B.Sum1;
    rtb_TmpSignalConversionAtToFile[8] = lab4_model_B.Switch1;
    rtb_TmpSignalConversionAtToFile[9] = lab4_model_B.Switch;
    rtb_TmpSignalConversionAtToFile[10] = lab4_model_B.Frontgain;
    rtb_TmpSignalConversionAtToFile[11] = lab4_model_B.Backgain;
    rtb_TmpSignalConversionAtToFile[12] = lab4_model_B.Switch;
    rtb_TmpSignalConversionAtToFile[13] = lab4_model_B.Switch1;
    rtb_TmpSignalConversionAtToFile[14] = 0.0;
    rtb_TmpSignalConversionAtToFile[15] = 0.0;
    rtb_TmpSignalConversionAtToFile[16] = lab4_model_B.euler_angles[0];
    rtb_TmpSignalConversionAtToFile[17] = lab4_model_B.euler_angles[1];
    rtb_TmpSignalConversionAtToFile[18] = lab4_model_B.euler_rates[0];
    rtb_TmpSignalConversionAtToFile[21] = lab4_model_B.Gain1[0];
    rtb_TmpSignalConversionAtToFile[24] = rtb_Gain2[0];
    rtb_TmpSignalConversionAtToFile[19] = lab4_model_B.euler_rates[1];
    rtb_TmpSignalConversionAtToFile[22] = lab4_model_B.Gain1[1];
    rtb_TmpSignalConversionAtToFile[25] = rtb_Gain2[1];
    rtb_TmpSignalConversionAtToFile[20] = lab4_model_B.euler_rates[2];
    rtb_TmpSignalConversionAtToFile[23] = lab4_model_B.Gain1[2];
    rtb_TmpSignalConversionAtToFile[26] = rtb_Gain2[2];
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtToFile[i + 27] = lab4_model_B.x_kf_est[i];
      rtb_TmpSignalConversionAtToFile[i + 33] = lab4_model_B.x_kf_pred[i];
    }

    /* End of SignalConversion generated from: '<S2>/To File' */

    /* ToFile: '<S2>/To File' */
    if (rtmIsMajorTimeStep(lab4_model_M)) {
      if (rtmIsMajorTimeStep(lab4_model_M) ) {
        {
          if (!(++lab4_model_DW.ToFile_IWORK.Decimation % 1) &&
              (lab4_model_DW.ToFile_IWORK.Count * (39 + 1)) + 1 < 100000000 ) {
            FILE *fp = (FILE *) lab4_model_DW.ToFile_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[39 + 1];
              lab4_model_DW.ToFile_IWORK.Decimation = 0;
              u[0] = lab4_model_M->Timing.t[1];
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
              u[17] = rtb_TmpSignalConversionAtToFile[16];
              u[18] = rtb_TmpSignalConversionAtToFile[17];
              u[19] = rtb_TmpSignalConversionAtToFile[18];
              u[20] = rtb_TmpSignalConversionAtToFile[19];
              u[21] = rtb_TmpSignalConversionAtToFile[20];
              u[22] = rtb_TmpSignalConversionAtToFile[21];
              u[23] = rtb_TmpSignalConversionAtToFile[22];
              u[24] = rtb_TmpSignalConversionAtToFile[23];
              u[25] = rtb_TmpSignalConversionAtToFile[24];
              u[26] = rtb_TmpSignalConversionAtToFile[25];
              u[27] = rtb_TmpSignalConversionAtToFile[26];
              u[28] = rtb_TmpSignalConversionAtToFile[27];
              u[29] = rtb_TmpSignalConversionAtToFile[28];
              u[30] = rtb_TmpSignalConversionAtToFile[29];
              u[31] = rtb_TmpSignalConversionAtToFile[30];
              u[32] = rtb_TmpSignalConversionAtToFile[31];
              u[33] = rtb_TmpSignalConversionAtToFile[32];
              u[34] = rtb_TmpSignalConversionAtToFile[33];
              u[35] = rtb_TmpSignalConversionAtToFile[34];
              u[36] = rtb_TmpSignalConversionAtToFile[35];
              u[37] = rtb_TmpSignalConversionAtToFile[36];
              u[38] = rtb_TmpSignalConversionAtToFile[37];
              u[39] = rtb_TmpSignalConversionAtToFile[38];
              if (fwrite(u, sizeof(real_T), 39 + 1, fp) != 39 + 1) {
                rtmSetErrorStatus(lab4_model_M,
                                  "Error writing to MAT-file helicopter_state_log.mat");
                return;
              }

              if (((++lab4_model_DW.ToFile_IWORK.Count) * (39 + 1))+1 >=
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
}

/* Model update function for TID0 */
void lab4_model_update0(void)          /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(lab4_model_M)) {
    /* Update for UnitDelay: '<S6>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      lab4_model_DW.UnitDelay_DSTATE[i] = lab4_model_B.x_kf_pred[i];
    }

    /* End of Update for UnitDelay: '<S6>/Unit Delay' */

    /* Update for UnitDelay: '<S6>/Unit Delay1' */
    memcpy(&lab4_model_DW.UnitDelay1_DSTATE[0], &lab4_model_B.P_kf_pred[0], 36U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S10>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_d = lab4_model_B.StreamFormattedRead1_o2;

    /* Update for UnitDelay: '<S11>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_h = lab4_model_B.StreamFormattedRead1_o3;

    /* Update for UnitDelay: '<S12>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_f = lab4_model_B.StreamFormattedRead1_o4;

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_e = lab4_model_B.StreamFormattedRead1_o5;

    /* Update for UnitDelay: '<S14>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_j = lab4_model_B.StreamFormattedRead1_o6;

    /* Update for UnitDelay: '<S15>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_dd = lab4_model_B.StreamFormattedRead1_o7;
  }

  if (rtmIsMajorTimeStep(lab4_model_M)) {
    rt_ertODEUpdateContinuousStates(&lab4_model_M->solverInfo);
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
  if (!(++lab4_model_M->Timing.clockTick0)) {
    ++lab4_model_M->Timing.clockTickH0;
  }

  lab4_model_M->Timing.t[0] = rtsiGetSolverStopTime(&lab4_model_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab4_model_M->Timing.clockTick1)) {
    ++lab4_model_M->Timing.clockTickH1;
  }

  lab4_model_M->Timing.t[1] = lab4_model_M->Timing.clockTick1 *
    lab4_model_M->Timing.stepSize1 + lab4_model_M->Timing.clockTickH1 *
    lab4_model_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void lab4_model_derivatives(void)
{
  XDot_lab4_model_T *_rtXdot;
  _rtXdot = ((XDot_lab4_model_T *) lab4_model_M->derivs);

  /* Derivatives for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += lab4_model_P.PitchTransferFcn_A *
    lab4_model_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += lab4_model_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += lab4_model_P.ElevationTransferFcn_A *
    lab4_model_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += lab4_model_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += lab4_model_P.TravelTransferFcn_A *
    lab4_model_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += lab4_model_B.TravelCounttorad;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = lab4_model_B.TmpSignalConversionAtIntegrator[0];
  _rtXdot->Integrator_CSTATE[1] = lab4_model_B.TmpSignalConversionAtIntegrator[1];

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += lab4_model_P.TransferFcn_A *
    lab4_model_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += lab4_model_B.ElevationTransferFcn;
}

/* Model output function for TID2 */
void lab4_model_output2(void)          /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S20>/Game Controller' */

  /* S-Function Block: lab4_model/Reference1/Joystick/Game Controller (game_controller_block) */
  {
    if (lab4_model_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(lab4_model_DW.GameController_Controller,
        &state, &new_data);
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

  /* RateTransition: '<S20>/Rate Transition: x' */
  lab4_model_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S20>/Rate Transition: y' */
  lab4_model_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void lab4_model_update2(void)          /* Sample time: [0.01s, 0.0s] */
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
  if (!(++lab4_model_M->Timing.clockTick2)) {
    ++lab4_model_M->Timing.clockTickH2;
  }

  lab4_model_M->Timing.t[2] = lab4_model_M->Timing.clockTick2 *
    lab4_model_M->Timing.stepSize2 + lab4_model_M->Timing.clockTickH2 *
    lab4_model_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void lab4_model_output(int_T tid)
{
  switch (tid) {
   case 0 :
    lab4_model_output0();
    break;

   case 2 :
    lab4_model_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void lab4_model_update(int_T tid)
{
  switch (tid) {
   case 0 :
    lab4_model_update0();
    break;

   case 2 :
    lab4_model_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lab4_model_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab4_model/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &lab4_model_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_model_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab4_model_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_model_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(lab4_model_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_model_M, _rt_error_message);
      return;
    }

    if ((lab4_model_P.HILInitialize_AIPStart && !is_switching) ||
        (lab4_model_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &lab4_model_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (lab4_model_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &lab4_model_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = lab4_model_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_AIChannels, 8U,
        &lab4_model_DW.HILInitialize_AIMinimums[0],
        &lab4_model_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_model_P.HILInitialize_AOPStart && !is_switching) ||
        (lab4_model_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &lab4_model_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (lab4_model_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &lab4_model_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = lab4_model_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_AOChannels, 8U,
        &lab4_model_DW.HILInitialize_AOMinimums[0],
        &lab4_model_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_model_P.HILInitialize_AOStart && !is_switching) ||
        (lab4_model_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab4_model_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab4_model_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_AOChannels, 8U,
        &lab4_model_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    if (lab4_model_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab4_model_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab4_model_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (lab4_model_DW.HILInitialize_Card, lab4_model_P.HILInitialize_AOChannels,
         8U, &lab4_model_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_model_P.HILInitialize_EIPStart && !is_switching) ||
        (lab4_model_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &lab4_model_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = lab4_model_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &lab4_model_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_model_P.HILInitialize_EIStart && !is_switching) ||
        (lab4_model_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &lab4_model_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = lab4_model_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_EIChannels, 8U,
        &lab4_model_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_model_P.HILInitialize_POPStart && !is_switching) ||
        (lab4_model_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab4_model_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab4_model_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &lab4_model_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          lab4_model_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &lab4_model_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            lab4_model_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab4_model_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              lab4_model_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            lab4_model_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab4_model_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              lab4_model_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(lab4_model_DW.HILInitialize_Card,
          &lab4_model_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &lab4_model_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab4_model_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(lab4_model_DW.HILInitialize_Card,
          &lab4_model_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &lab4_model_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab4_model_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab4_model_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab4_model_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &lab4_model_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = lab4_model_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &lab4_model_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = lab4_model_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &lab4_model_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &lab4_model_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &lab4_model_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &lab4_model_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = lab4_model_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &lab4_model_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab4_model_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_POChannels, 8U,
        &lab4_model_DW.HILInitialize_POSortedFreqs[0],
        &lab4_model_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_model_P.HILInitialize_POStart && !is_switching) ||
        (lab4_model_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab4_model_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab4_model_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(lab4_model_DW.HILInitialize_Card,
        lab4_model_P.HILInitialize_POChannels, 8U,
        &lab4_model_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }

    if (lab4_model_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &lab4_model_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab4_model_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (lab4_model_DW.HILInitialize_Card, lab4_model_P.HILInitialize_POChannels,
         8U, &lab4_model_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: lab4_model/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(lab4_model_DW.HILInitialize_Card,
      lab4_model_P.HILReadEncoderTimebase_SamplesI,
      lab4_model_P.HILReadEncoderTimebase_Channels, 3,
      &lab4_model_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (lab4_model_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (lab4_model_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_model_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_call_block): '<S5>/Stream Call2' incorporates:
   *  Constant: '<S5>/Constant4'
   *  S-Function (string_constant_block): '<S5>/String Constant1'
   */

  /* S-Function Block: lab4_model/IMU_BT/Stream Call2 (stream_call_block) */
  {
    lab4_model_DW.StreamCall2_State = STREAM_CALL_STATE_NOT_CONNECTED;
    lab4_model_DW.StreamCall2_Stream = NULL;
  }

  /* Start for RateTransition: '<S20>/Rate Transition: x' */
  lab4_model_B.RateTransitionx = lab4_model_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S20>/Rate Transition: y' */
  lab4_model_B.RateTransitiony = lab4_model_P.RateTransitiony_InitialConditio;

  /* Start for ToFile: '<S2>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "helicopter_state_log.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(lab4_model_M,
                        "Error creating .mat file helicopter_state_log.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 39 + 1, 0, "var")) {
      rtmSetErrorStatus(lab4_model_M,
                        "Error writing mat file header to file helicopter_state_log.mat");
      return;
    }

    lab4_model_DW.ToFile_IWORK.Count = 0;
    lab4_model_DW.ToFile_IWORK.Decimation = -1;
    lab4_model_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for S-Function (game_controller_block): '<S20>/Game Controller' */

  /* S-Function Block: lab4_model/Reference1/Joystick/Game Controller (game_controller_block) */
  {
    if (lab4_model_P.GameController_Enabled) {
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

      result = game_controller_open(lab4_model_P.GameController_ControllerNumber,
        lab4_model_P.GameController_BufferSize, deadzone, saturation,
        lab4_model_P.GameController_AutoCenter, 0, 1.0,
        &lab4_model_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_model_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
    lab4_model_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
    lab4_model_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Travel: Transfer Fcn' */
    lab4_model_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      lab4_model_DW.UnitDelay_DSTATE[i] = lab4_model_P.X_init_pred[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S6>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
    memcpy(&lab4_model_DW.UnitDelay1_DSTATE[0], &lab4_model_P.P_init_pred[0],
           36U * sizeof(real_T));

    /* InitializeConditions for RateTransition: '<S20>/Rate Transition: x' */
    lab4_model_DW.RateTransitionx_Buffer0 =
      lab4_model_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S20>/Rate Transition: y' */
    lab4_model_DW.RateTransitiony_Buffer0 =
      lab4_model_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    lab4_model_X.Integrator_CSTATE[0] = lab4_model_P.Integrator_IC;
    lab4_model_X.Integrator_CSTATE[1] = lab4_model_P.Integrator_IC;

    /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_d = lab4_model_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_h = lab4_model_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_f = lab4_model_P.UnitDelay_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_e = lab4_model_P.UnitDelay_InitialCondition_k;

    /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_j = lab4_model_P.UnitDelay_InitialCondition_e;

    /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
    lab4_model_DW.UnitDelay_DSTATE_dd =
      lab4_model_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn' */
    lab4_model_X.TransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void lab4_model_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab4_model/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(lab4_model_DW.HILInitialize_Card);
    hil_monitor_stop_all(lab4_model_DW.HILInitialize_Card);
    is_switching = false;
    if ((lab4_model_P.HILInitialize_AOTerminate && !is_switching) ||
        (lab4_model_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab4_model_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab4_model_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((lab4_model_P.HILInitialize_POTerminate && !is_switching) ||
        (lab4_model_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab4_model_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab4_model_P.HILInitialize_POFinal;
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
      result = hil_write(lab4_model_DW.HILInitialize_Card
                         , lab4_model_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , lab4_model_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &lab4_model_DW.HILInitialize_AOVoltages[0]
                         , &lab4_model_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lab4_model_DW.HILInitialize_Card,
            lab4_model_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &lab4_model_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(lab4_model_DW.HILInitialize_Card,
            lab4_model_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &lab4_model_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab4_model_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lab4_model_DW.HILInitialize_Card);
    hil_monitor_delete_all(lab4_model_DW.HILInitialize_Card);
    hil_close(lab4_model_DW.HILInitialize_Card);
    lab4_model_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S5>/Stream Call2' incorporates:
   *  Constant: '<S5>/Constant4'
   *  S-Function (string_constant_block): '<S5>/String Constant1'
   */

  /* S-Function Block: lab4_model/IMU_BT/Stream Call2 (stream_call_block) */
  {
    if (lab4_model_DW.StreamCall2_Stream != NULL) {
      stream_close(lab4_model_DW.StreamCall2_Stream);
      lab4_model_DW.StreamCall2_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<S2>/To File' */
  {
    FILE *fp = (FILE *) lab4_model_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "helicopter_state_log.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab4_model_M,
                          "Error closing MAT-file helicopter_state_log.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(lab4_model_M,
                          "Error reopening MAT-file helicopter_state_log.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 39 + 1, lab4_model_DW.ToFile_IWORK.Count,
           "var")) {
        rtmSetErrorStatus(lab4_model_M,
                          "Error writing header for var to MAT-file helicopter_state_log.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab4_model_M,
                          "Error closing MAT-file helicopter_state_log.mat");
        return;
      }

      lab4_model_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S20>/Game Controller' */

  /* S-Function Block: lab4_model/Reference1/Joystick/Game Controller (game_controller_block) */
  {
    if (lab4_model_P.GameController_Enabled) {
      game_controller_close(lab4_model_DW.GameController_Controller);
      lab4_model_DW.GameController_Controller = NULL;
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
  lab4_model_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab4_model_update(tid);
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
  lab4_model_initialize();
}

void MdlTerminate(void)
{
  lab4_model_terminate();
}

/* Registration function */
RT_MODEL_lab4_model_T *lab4_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  lab4_model_P.UnitDelay_InitialCondition = rtNaNF;
  lab4_model_P.UnitDelay_InitialCondition_i = rtNaNF;
  lab4_model_P.UnitDelay_InitialCondition_g = rtNaNF;
  lab4_model_P.UnitDelay_InitialCondition_k = rtNaNF;
  lab4_model_P.UnitDelay_InitialCondition_e = rtNaNF;
  lab4_model_P.UnitDelay_InitialCondition_o = rtNaNF;

  /* initialize real-time model */
  (void) memset((void *)lab4_model_M, 0,
                sizeof(RT_MODEL_lab4_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab4_model_M->solverInfo,
                          &lab4_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab4_model_M->solverInfo, &rtmGetTPtr(lab4_model_M));
    rtsiSetStepSizePtr(&lab4_model_M->solverInfo,
                       &lab4_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab4_model_M->solverInfo, &lab4_model_M->derivs);
    rtsiSetContStatesPtr(&lab4_model_M->solverInfo, (real_T **)
                         &lab4_model_M->contStates);
    rtsiSetNumContStatesPtr(&lab4_model_M->solverInfo,
      &lab4_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab4_model_M->solverInfo,
      &lab4_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab4_model_M->solverInfo,
      &lab4_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab4_model_M->solverInfo,
      &lab4_model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab4_model_M->solverInfo, (&rtmGetErrorStatus
      (lab4_model_M)));
    rtsiSetRTModelPtr(&lab4_model_M->solverInfo, lab4_model_M);
  }

  rtsiSetSimTimeStep(&lab4_model_M->solverInfo, MAJOR_TIME_STEP);
  lab4_model_M->intgData.f[0] = lab4_model_M->odeF[0];
  lab4_model_M->contStates = ((real_T *) &lab4_model_X);
  rtsiSetSolverData(&lab4_model_M->solverInfo, (void *)&lab4_model_M->intgData);
  rtsiSetSolverName(&lab4_model_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab4_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab4_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab4_model_M->Timing.sampleTimes = (&lab4_model_M->Timing.sampleTimesArray[0]);
    lab4_model_M->Timing.offsetTimes = (&lab4_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab4_model_M->Timing.sampleTimes[0] = (0.0);
    lab4_model_M->Timing.sampleTimes[1] = (0.002);
    lab4_model_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    lab4_model_M->Timing.offsetTimes[0] = (0.0);
    lab4_model_M->Timing.offsetTimes[1] = (0.0);
    lab4_model_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab4_model_M, &lab4_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab4_model_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = lab4_model_M->Timing.perTaskSampleHitsArray;
    lab4_model_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    lab4_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab4_model_M, 50.0);
  lab4_model_M->Timing.stepSize0 = 0.002;
  lab4_model_M->Timing.stepSize1 = 0.002;
  lab4_model_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  lab4_model_M->Sizes.checksums[0] = (134543337U);
  lab4_model_M->Sizes.checksums[1] = (3563978026U);
  lab4_model_M->Sizes.checksums[2] = (205613908U);
  lab4_model_M->Sizes.checksums[3] = (249886328U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    lab4_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&lab4_model_DW.Skiptonextline_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab4_model_M->extModeInfo,
      &lab4_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab4_model_M->extModeInfo, lab4_model_M->Sizes.checksums);
    rteiSetTPtr(lab4_model_M->extModeInfo, rtmGetTPtr(lab4_model_M));
  }

  lab4_model_M->solverInfoPtr = (&lab4_model_M->solverInfo);
  lab4_model_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lab4_model_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lab4_model_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  lab4_model_M->blockIO = ((void *) &lab4_model_B);
  (void) memset(((void *) &lab4_model_B), 0,
                sizeof(B_lab4_model_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      lab4_model_B.UnitDelay[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      lab4_model_B.UnitDelay1[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab4_model_B.TmpSignalConversionAtToWorkspac[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      lab4_model_B.x_kf_pred[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      lab4_model_B.P_kf_pred[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      lab4_model_B.x_kf_est[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      lab4_model_B.P_kf_est[i] = 0.0;
    }

    lab4_model_B.PitchCounttorad = 0.0;
    lab4_model_B.DataTypeConversion2[0] = 0.0;
    lab4_model_B.DataTypeConversion2[1] = 0.0;
    lab4_model_B.DataTypeConversion2[2] = 0.0;
    lab4_model_B.Gain1[0] = 0.0;
    lab4_model_B.Gain1[1] = 0.0;
    lab4_model_B.Gain1[2] = 0.0;
    lab4_model_B.DataTypeConversion1[0] = 0.0;
    lab4_model_B.DataTypeConversion1[1] = 0.0;
    lab4_model_B.DataTypeConversion1[2] = 0.0;
    lab4_model_B.ElevationCounttorad = 0.0;
    lab4_model_B.PitchTransferFcn = 0.0;
    lab4_model_B.ElevationTransferFcn = 0.0;
    lab4_model_B.TravelCounttorad = 0.0;
    lab4_model_B.TravelTransferFcn = 0.0;
    lab4_model_B.RateTransitionx = 0.0;
    lab4_model_B.Joystick_gain_x = 0.0;
    lab4_model_B.Switch = 0.0;
    lab4_model_B.RateTransitiony = 0.0;
    lab4_model_B.Joystick_gain_y = 0.0;
    lab4_model_B.Gain2 = 0.0;
    lab4_model_B.Switch1 = 0.0;
    lab4_model_B.Integrator[0] = 0.0;
    lab4_model_B.Integrator[1] = 0.0;
    lab4_model_B.u[0] = 0.0;
    lab4_model_B.u[1] = 0.0;
    lab4_model_B.Sum1 = 0.0;
    lab4_model_B.Backgain = 0.0;
    lab4_model_B.Frontgain = 0.0;
    lab4_model_B.FrontmotorSaturation = 0.0;
    lab4_model_B.BackmotorSaturation = 0.0;
    lab4_model_B.TmpSignalConversionAtIntegrator[0] = 0.0;
    lab4_model_B.TmpSignalConversionAtIntegrator[1] = 0.0;
    lab4_model_B.elevationrateenc = 0.0;
    lab4_model_B.euler_rates[0] = 0.0;
    lab4_model_B.euler_rates[1] = 0.0;
    lab4_model_B.euler_rates[2] = 0.0;
    lab4_model_B.euler_angles[0] = 0.0;
    lab4_model_B.euler_angles[1] = 0.0;
    lab4_model_B.StreamFormattedRead1_o2 = 0.0F;
    lab4_model_B.StreamFormattedRead1_o3 = 0.0F;
    lab4_model_B.StreamFormattedRead1_o4 = 0.0F;
    lab4_model_B.StreamFormattedRead1_o5 = 0.0F;
    lab4_model_B.StreamFormattedRead1_o6 = 0.0F;
    lab4_model_B.StreamFormattedRead1_o7 = 0.0F;
    lab4_model_B.UnitDelay_c = 0.0F;
    lab4_model_B.UnitDelay_d = 0.0F;
    lab4_model_B.UnitDelay_n = 0.0F;
    lab4_model_B.UnitDelay_i = 0.0F;
    lab4_model_B.UnitDelay_c0 = 0.0F;
    lab4_model_B.UnitDelay_a = 0.0F;
  }

  /* parameters */
  lab4_model_M->defaultParam = ((real_T *)&lab4_model_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab4_model_X;
    lab4_model_M->contStates = (x);
    (void) memset((void *)&lab4_model_X, 0,
                  sizeof(X_lab4_model_T));
  }

  /* states (dwork) */
  lab4_model_M->dwork = ((void *) &lab4_model_DW);
  (void) memset((void *)&lab4_model_DW, 0,
                sizeof(DW_lab4_model_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      lab4_model_DW.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      lab4_model_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_model_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_model_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_model_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_model_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_model_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_model_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_model_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_model_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  lab4_model_DW.RateTransitionx_Buffer0 = 0.0;
  lab4_model_DW.RateTransitiony_Buffer0 = 0.0;
  lab4_model_DW.HILWriteAnalog_Buffer[0] = 0.0;
  lab4_model_DW.HILWriteAnalog_Buffer[1] = 0.0;
  lab4_model_DW.UnitDelay_DSTATE_d = 0.0F;
  lab4_model_DW.UnitDelay_DSTATE_h = 0.0F;
  lab4_model_DW.UnitDelay_DSTATE_f = 0.0F;
  lab4_model_DW.UnitDelay_DSTATE_e = 0.0F;
  lab4_model_DW.UnitDelay_DSTATE_j = 0.0F;
  lab4_model_DW.UnitDelay_DSTATE_dd = 0.0F;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab4_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab4_model_M->Sizes.numContStates = (6);/* Number of continuous states */
  lab4_model_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab4_model_M->Sizes.numY = (0);      /* Number of model outputs */
  lab4_model_M->Sizes.numU = (0);      /* Number of model inputs */
  lab4_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab4_model_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab4_model_M->Sizes.numBlocks = (129);/* Number of blocks */
  lab4_model_M->Sizes.numBlockIO = (56);/* Number of block outputs */
  lab4_model_M->Sizes.numBlockPrms = (654);/* Sum of parameter "widths" */
  return lab4_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
