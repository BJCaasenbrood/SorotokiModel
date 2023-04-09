/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeLagrangianFast_initialize.c
 *
 * Code generation for function 'computeLagrangianFast_initialize'
 *
 */

/* Include files */
#include "computeLagrangianFast_initialize.h"
#include "_coder_computeLagrangianFast_mex.h"
#include "computeLagrangianFast_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void computeLagrangianFast_once(void);

/* Function Definitions */
static void computeLagrangianFast_once(void)
{
  mex_InitInfAndNan();
}

void computeLagrangianFast_initialize(void)
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
    computeLagrangianFast_once();
  }
}

/* End of code generation (computeLagrangianFast_initialize.c) */
