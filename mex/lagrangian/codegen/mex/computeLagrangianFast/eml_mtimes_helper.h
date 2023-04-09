/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_mtimes_helper.h
 *
 * Code generation for function 'eml_mtimes_helper'
 *
 */

#pragma once

/* Include files */
#include "computeLagrangianFast_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *b,
                           int32_T innerDimA, int32_T innerDimB);

void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1, real_T in2,
                      const emxArray_real_T *in3);

void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                        const emlrtRSInfo in2, const real_T in3[36],
                        const emxArray_real_T *in4);

void d_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                        const emlrtRSInfo in2, const emxArray_real_T *in3,
                        const emxArray_real_T *in4, const emxArray_real_T *in5);

void dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *b,
                         int32_T innerDimA, int32_T innerDimB);

/* End of code generation (eml_mtimes_helper.h) */
