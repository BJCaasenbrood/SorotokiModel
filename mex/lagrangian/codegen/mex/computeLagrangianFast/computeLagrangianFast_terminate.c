/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeLagrangianFast_terminate.c
 *
 * Code generation for function 'computeLagrangianFast_terminate'
 *
 */

/* Include files */
#include "computeLagrangianFast_terminate.h"
#include "_coder_computeLagrangianFast_mex.h"
#include "computeLagrangianFast_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void computeLagrangianFast_atexit(void)
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

void computeLagrangianFast_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (computeLagrangianFast_terminate.c) */
