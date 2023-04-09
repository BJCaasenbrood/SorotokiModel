/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeForwardKinematicsFast.h
 *
 * Code generation for function 'computeForwardKinematicsFast'
 *
 */

#pragma once

/* Include files */
#include "computeForwardKinematicsFast_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void computeForwardKinematicsFast(
    const emlrtStack *sp, const emxArray_real_T *x, const emxArray_real_T *dx,
    real_T ds, const real_T p0[3], const real_T Phi0[9],
    const emxArray_real_T *xia0, const emxArray_real_T *Th,
    const emxArray_real_T *Ba, emxArray_real_T *gtmp, emxArray_real_T *Jtmp,
    emxArray_real_T *vtmp);

/* End of code generation (computeForwardKinematicsFast.h) */
