/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_mtimes_helper.c
 *
 * Code generation for function 'eml_mtimes_helper'
 *
 */

/* Include files */
#include "eml_mtimes_helper.h"
#include "computeLagrangianFast_data.h"
#include "computeLagrangianFast_emxutil.h"
#include "computeLagrangianFast_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRTEInfo bc_emlrtRTEI =
    {
        76,                  /* lineNo */
        13,                  /* colNo */
        "eml_mtimes_helper", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

/* Function Definitions */
void b_dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *b,
                           int32_T innerDimA, int32_T innerDimB)
{
  if (innerDimA != innerDimB) {
    if (b->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(
          sp, &c_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
}

void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1, real_T in2,
                      const emxArray_real_T *in3)
{
  emxArray_real_T *b_in2;
  const real_T *in3_data;
  real_T *in1_data;
  real_T *in2_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in3_data = in3->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in2, 2, &bc_emlrtRTEI);
  if (in3->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = loop_ub;
  if (in3->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  b_in2->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, i, &bc_emlrtRTEI);
  in2_data = b_in2->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in2_data[i1 + b_in2->size[0] * i] =
          in2 * (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
                 in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in2->size[0];
  in1->size[1] = b_in2->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &bc_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in2->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in2->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = in2_data[i1 + b_in2->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                        const emlrtRSInfo in2, const real_T in3[36],
                        const emxArray_real_T *in4)
{
  emlrtStack st;
  emxArray_real_T *b_in1;
  const real_T *in4_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &r_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 6;
  if (in4->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in4->size[1];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &r_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&in1_data[6 * aux_0_1]);
    r1 = _mm_loadu_pd(&in4_data[6 * aux_1_1]);
    _mm_storeu_pd(&b_in1_data[6 * i], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in1_data[6 * aux_0_1 + 2]);
    r1 = _mm_loadu_pd(&in4_data[6 * aux_1_1 + 2]);
    _mm_storeu_pd(&b_in1_data[6 * i + 2], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in1_data[6 * aux_0_1 + 4]);
    r1 = _mm_loadu_pd(&in4_data[6 * aux_1_1 + 4]);
    _mm_storeu_pd(&b_in1_data[6 * i + 4], _mm_add_pd(r, r1));
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = (emlrtRSInfo *)&in2;
  c_mtimes(&st, in3, b_in1, in1);
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void d_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                        const emlrtRSInfo in2, const emxArray_real_T *in3,
                        const emxArray_real_T *in4, const emxArray_real_T *in5)
{
  emlrtStack st;
  emxArray_real_T *b_in4;
  const real_T *in4_data;
  const real_T *in5_data;
  real_T *b_in4_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  in5_data = in5->data;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in4, 2, &ib_emlrtRTEI);
  i = b_in4->size[0] * b_in4->size[1];
  b_in4->size[0] = 6;
  if (in5->size[1] == 1) {
    loop_ub = in4->size[1];
  } else {
    loop_ub = in5->size[1];
  }
  b_in4->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in4, i, &ib_emlrtRTEI);
  b_in4_data = b_in4->data;
  stride_0_1 = (in4->size[1] != 1);
  stride_1_1 = (in5->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1]);
    r1 = _mm_loadu_pd(&in5_data[6 * aux_1_1]);
    _mm_storeu_pd(&b_in4_data[6 * i], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1 + 2]);
    r1 = _mm_loadu_pd(&in5_data[6 * aux_1_1 + 2]);
    _mm_storeu_pd(&b_in4_data[6 * i + 2], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1 + 4]);
    r1 = _mm_loadu_pd(&in5_data[6 * aux_1_1 + 4]);
    _mm_storeu_pd(&b_in4_data[6 * i + 4], _mm_add_pd(r, r1));
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = (emlrtRSInfo *)&in2;
  e_mtimes(&st, in3, b_in4, in1);
  emxFree_real_T(sp, &b_in4);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *b,
                         int32_T innerDimA, int32_T innerDimB)
{
  if (innerDimA != innerDimB) {
    if ((b->size[0] == 1) && (b->size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(
          sp, &c_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
}

/* End of code generation (eml_mtimes_helper.c) */
