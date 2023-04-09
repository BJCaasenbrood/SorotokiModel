/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mtimes.h
 *
 * Code generation for function 'mtimes'
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
void b_mtimes(const emxArray_real_T *A, const emxArray_real_T *B, real_T C[6]);

void c_mtimes(const emlrtStack *sp, const real_T A[36],
              const emxArray_real_T *B, emxArray_real_T *C);

void d_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const real_T B[36], emxArray_real_T *C);

void e_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const emxArray_real_T *B, emxArray_real_T *C);

void f_mtimes(const emlrtStack *sp, const emxArray_real_T *A, const real_T B[6],
              emxArray_real_T *C);

void g_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const real_T B[36], emxArray_real_T *C);

void mtimes(const emlrtStack *sp, const emxArray_real_T *A,
            const emxArray_real_T *B, emxArray_real_T *C);

/* End of code generation (mtimes.h) */
