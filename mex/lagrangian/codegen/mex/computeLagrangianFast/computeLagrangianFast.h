/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeLagrangianFast.h
 *
 * Code generation for function 'computeLagrangianFast'
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
void computeLagrangianFast(
    const emlrtStack *sp, const emxArray_real_T *x, const emxArray_real_T *dx,
    real_T ds, const real_T p0[3], const real_T Phi0[9],
    const emxArray_real_T *xia0, const emxArray_real_T *Th,
    const emxArray_real_T *Ms, const emxArray_real_T *Ba,
    const emxArray_real_T *Ktt, const emxArray_real_T *Mtt, real_T Zeta,
    const real_T Gvec[3], emxArray_real_T *M, emxArray_real_T *C,
    emxArray_real_T *K, emxArray_real_T *R, emxArray_real_T *G,
    emxArray_real_T *B, real_T p[3], real_T Phi[9], emxArray_real_T *J,
    emxArray_real_T *dJdt, real_T *Vg, real_T *Kin);

/* End of code generation (computeLagrangianFast.h) */
