/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_computeLagrangianFast_mex.c
 *
 * Code generation for function '_coder_computeLagrangianFast_mex'
 *
 */

/* Include files */
#include "_coder_computeLagrangianFast_mex.h"
#include "_coder_computeLagrangianFast_api.h"
#include "computeLagrangianFast_data.h"
#include "computeLagrangianFast_initialize.h"
#include "computeLagrangianFast_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void computeLagrangianFast_mexFunction(int32_T nlhs, mxArray *plhs[12],
                                       int32_T nrhs, const mxArray *prhs[13])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[12];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 13) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 13, 4,
                        21, "computeLagrangianFast");
  }
  if (nlhs > 12) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "computeLagrangianFast");
  }
  /* Call the function. */
  computeLagrangianFast_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&computeLagrangianFast_atexit);
  /* Module initialization. */
  computeLagrangianFast_initialize();
  /* Dispatch the entry-point. */
  computeLagrangianFast_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  computeLagrangianFast_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_computeLagrangianFast_mex.c) */
