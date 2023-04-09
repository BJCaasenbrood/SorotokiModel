/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_computeForwardKinematicsFast_mex.c
 *
 * Code generation for function '_coder_computeForwardKinematicsFast_mex'
 *
 */

/* Include files */
#include "_coder_computeForwardKinematicsFast_mex.h"
#include "_coder_computeForwardKinematicsFast_api.h"
#include "computeForwardKinematicsFast_data.h"
#include "computeForwardKinematicsFast_initialize.h"
#include "computeForwardKinematicsFast_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void computeForwardKinematicsFast_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                              int32_T nrhs,
                                              const mxArray *prhs[8])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        28, "computeForwardKinematicsFast");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 28,
                        "computeForwardKinematicsFast");
  }
  /* Call the function. */
  c_computeForwardKinematicsFast_(prhs, nlhs, outputs);
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
  mexAtExit(&computeForwardKinematicsFast_atexit);
  /* Module initialization. */
  computeForwardKinematicsFast_initialize();
  /* Dispatch the entry-point. */
  computeForwardKinematicsFast_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  computeForwardKinematicsFast_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_computeForwardKinematicsFast_mex.c) */
