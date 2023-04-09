/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeForwardKinematicsFast_terminate.c
 *
 * Code generation for function 'computeForwardKinematicsFast_terminate'
 *
 */

/* Include files */
#include "computeForwardKinematicsFast_terminate.h"
#include "_coder_computeForwardKinematicsFast_mex.h"
#include "computeForwardKinematicsFast_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void computeForwardKinematicsFast_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void computeForwardKinematicsFast_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (computeForwardKinematicsFast_terminate.c) */
