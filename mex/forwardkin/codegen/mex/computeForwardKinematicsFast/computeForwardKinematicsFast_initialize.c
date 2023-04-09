/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeForwardKinematicsFast_initialize.c
 *
 * Code generation for function 'computeForwardKinematicsFast_initialize'
 *
 */

/* Include files */
#include "computeForwardKinematicsFast_initialize.h"
#include "_coder_computeForwardKinematicsFast_mex.h"
#include "computeForwardKinematicsFast_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void computeForwardKinematicsFast_once(void);

/* Function Definitions */
static void computeForwardKinematicsFast_once(void)
{
  mex_InitInfAndNan();
}

void computeForwardKinematicsFast_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    computeForwardKinematicsFast_once();
  }
}

/* End of code generation (computeForwardKinematicsFast_initialize.c) */
