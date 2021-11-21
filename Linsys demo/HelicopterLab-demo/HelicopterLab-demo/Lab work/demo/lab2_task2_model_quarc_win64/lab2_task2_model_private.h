/*
 * lab2_task2_model_private.h
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

#ifndef RTW_HEADER_lab2_task2_model_private_h_
#define RTW_HEADER_lab2_task2_model_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "lab2_task2_model.h"

/* Used by FromWorkspace Block: '<S13>/FromWs' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);
void lab2_task2_model_output0(void);
void lab2_task2_model_update0(void);
void lab2_task2_model_output2(void);
void lab2_task2_model_update2(void);   /* private model entry point functions */
extern void lab2_task2_model_derivatives(void);

#endif                              /* RTW_HEADER_lab2_task2_model_private_h_ */
