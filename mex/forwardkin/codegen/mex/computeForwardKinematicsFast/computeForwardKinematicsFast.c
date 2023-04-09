/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeForwardKinematicsFast.c
 *
 * Code generation for function 'computeForwardKinematicsFast'
 *
 */

/* Include files */
#include "computeForwardKinematicsFast.h"
#include "computeForwardKinematicsFast_data.h"
#include "computeForwardKinematicsFast_emxutil.h"
#include "computeForwardKinematicsFast_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    26,                             /* lineNo */
    "computeForwardKinematicsFast", /* fcnName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    30,                             /* lineNo */
    "computeForwardKinematicsFast", /* fcnName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    43,                             /* lineNo */
    "computeForwardKinematicsFast", /* fcnName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    44,                             /* lineNo */
    "computeForwardKinematicsFast", /* fcnName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    56,            /* lineNo */
    "ForwardODEX", /* fcnName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    57,            /* lineNo */
    "ForwardODEX", /* fcnName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    66,            /* lineNo */
    "ForwardODEX", /* fcnName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    27,                             /* lineNo */
    16,                             /* colNo */
    "Th",                           /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    27,                             /* lineNo */
    34,                             /* colNo */
    "xia0",                         /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtECInfo emlrtECI = {
    2,                              /* nDims */
    30,                             /* lineNo */
    29,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    2,                              /* nDims */
    35,                             /* lineNo */
    24,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    2,                              /* nDims */
    35,                             /* lineNo */
    10,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    38,                             /* lineNo */
    18,                             /* colNo */
    "Z1",                           /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    40,                             /* lineNo */
    18,                             /* colNo */
    "Z1",                           /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    40,                             /* lineNo */
    20,                             /* colNo */
    "Z1",                           /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    43,                             /* lineNo */
    14,                             /* colNo */
    "Jtmp",                         /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtECInfo d_emlrtECI = {
    -1,                             /* nDims */
    43,                             /* lineNo */
    5,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    44,                             /* lineNo */
    29,                             /* colNo */
    "Jtmp",                         /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    42,                             /* lineNo */
    14,                             /* colNo */
    "gtmp",                         /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtRTEInfo emlrtRTEI =
    {
        138,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI =
    {
        133,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    15,                             /* lineNo */
    14,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    1                                 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    31,                             /* lineNo */
    16,                             /* colNo */
    "Th",                           /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    31,                             /* lineNo */
    32,                             /* colNo */
    "xia0",                         /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    15,                             /* lineNo */
    1,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    1                                 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    19,                             /* lineNo */
    18,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    1                                 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    44,                             /* lineNo */
    14,                             /* colNo */
    "vtmp",                         /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    39,                             /* lineNo */
    18,                             /* colNo */
    "Z1",                           /* aName */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    53,            /* lineNo */
    16,            /* colNo */
    "Z1",          /* aName */
    "ForwardODEX", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    71,            /* lineNo */
    9,             /* colNo */
    "dZ1",         /* aName */
    "ForwardODEX", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    71,            /* lineNo */
    11,            /* colNo */
    "dZ1",         /* aName */
    "ForwardODEX", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtECInfo e_emlrtECI = {
    -1,            /* nDims */
    71,            /* lineNo */
    1,             /* colNo */
    "ForwardODEX", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtDCInfo d_emlrtDCI = {
    68,            /* lineNo */
    28,            /* colNo */
    "ForwardODEX", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    1                                 /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    68,            /* lineNo */
    1,             /* colNo */
    "ForwardODEX", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    1                                 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    54,            /* lineNo */
    16,            /* colNo */
    "Z1",          /* aName */
    "ForwardODEX", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m", /* pName */
    0                                 /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    15,                             /* lineNo */
    1,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    19,                             /* lineNo */
    8,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    20,                             /* lineNo */
    1,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    21,                             /* lineNo */
    8,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    27,                             /* lineNo */
    9,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    30,                             /* lineNo */
    34,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    35,                             /* lineNo */
    31,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    30,                             /* lineNo */
    29,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    35,                             /* lineNo */
    15,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    31,                             /* lineNo */
    9,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    35,                             /* lineNo */
    5,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    40,                             /* lineNo */
    11,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    44,                             /* lineNo */
    20,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    26,                             /* lineNo */
    6,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    30,                             /* lineNo */
    6,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    56,                             /* lineNo */
    1,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    68,                             /* lineNo */
    1,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    66,                             /* lineNo */
    1,                              /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    35,                             /* lineNo */
    10,                             /* colNo */
    "computeForwardKinematicsFast", /* fName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pName */
};

static emlrtRSInfo l_emlrtRSI = {
    35,                             /* lineNo */
    "computeForwardKinematicsFast", /* fcnName */
    "/home/brandon/Documents/projects/SorotokiModel/mex/forwardkin/"
    "computeForwardKinematicsFast.m" /* pathName */
};

/* Function Declarations */
static void ForwardODEX(const emlrtStack *sp, const emxArray_real_T *x,
                        const emxArray_real_T *Z1, const emxArray_real_T *Theta,
                        const real_T xia0[6], const emxArray_real_T *Ba,
                        emxArray_real_T *dZ1);

static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emlrtRSInfo in2, const emxArray_real_T *in3,
                             const emxArray_real_T *in4,
                             const emxArray_real_T *in5, int32_T in6,
                             const emxArray_real_T *in7,
                             const emxArray_real_T *in8);

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2);

/* Function Definitions */
static void ForwardODEX(const emlrtStack *sp, const emxArray_real_T *x,
                        const emxArray_real_T *Z1, const emxArray_real_T *Theta,
                        const real_T xia0[6], const emxArray_real_T *Ba,
                        emxArray_real_T *dZ1)
{
  __m128d r;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *BTh;
  emxArray_real_T *dJ;
  real_T A[36];
  real_T Phi_[9];
  real_T dv[9];
  real_T XI[6];
  const real_T *Ba_data;
  const real_T *Theta_data;
  const real_T *Z1_data;
  real_T alpha1;
  real_T beta1;
  real_T *BTh_data;
  real_T *dZ1_data;
  int32_T iv[2];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  Ba_data = Ba->data;
  Theta_data = Theta->data;
  Z1_data = Z1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /* --------------------------------------------------------------------------
   */
  if (Z1->size[1] < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Z1->size[1], &m_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  for (i = 0; i < 3; i++) {
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &p_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi_[3 * i] = Z1_data[6 * i];
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &p_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi_[3 * i + 1] = Z1_data[6 * i + 1];
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &p_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi_[3 * i + 2] = Z1_data[6 * i + 2];
  }
  st.site = &e_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  if (Theta->size[0] != Ba->size[1]) {
    if ((Theta->size[0] == 1) && (Theta->size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &b_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_st.site = &h_emlrtRSI;
  emxInit_real_T(&b_st, &BTh, 2, &r_emlrtRTEI);
  if ((Ba->size[1] == 0) || (Theta->size[0] == 0) || (Theta->size[1] == 0)) {
    i = BTh->size[0] * BTh->size[1];
    BTh->size[0] = 6;
    BTh->size[1] = Theta->size[1];
    emxEnsureCapacity_real_T(&b_st, BTh, i, &r_emlrtRTEI);
    BTh_data = BTh->data;
    loop_ub = 6 * Theta->size[1];
    for (i = 0; i < loop_ub; i++) {
      BTh_data[i] = 0.0;
    }
  } else {
    c_st.site = &j_emlrtRSI;
    d_st.site = &k_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)Theta->size[1];
    k_t = (ptrdiff_t)Ba->size[1];
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)Theta->size[0];
    ldc_t = (ptrdiff_t)6;
    i = BTh->size[0] * BTh->size[1];
    BTh->size[0] = 6;
    BTh->size[1] = Theta->size[1];
    emxEnsureCapacity_real_T(&d_st, BTh, i, &s_emlrtRTEI);
    BTh_data = BTh->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&Ba_data[0],
          &lda_t, (real_T *)&Theta_data[0], &ldb_t, &beta1, &BTh_data[0],
          &ldc_t);
  }
  st.site = &f_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  if (x->size[0] != BTh->size[1]) {
    if (x->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &b_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_st.site = &h_emlrtRSI;
  mtimes(BTh, x, XI);
  r = _mm_loadu_pd(&XI[0]);
  _mm_storeu_pd(&XI[0], _mm_add_pd(r, _mm_loadu_pd(&xia0[0])));
  r = _mm_loadu_pd(&XI[2]);
  _mm_storeu_pd(&XI[2], _mm_add_pd(r, _mm_loadu_pd(&xia0[2])));
  r = _mm_loadu_pd(&XI[4]);
  _mm_storeu_pd(&XI[4], _mm_add_pd(r, _mm_loadu_pd(&xia0[4])));
  /*  build forward kin - position */
  /* --------------------------------------------------------------------------
   */
  memset(&A[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    alpha1 = Phi_[3 * i];
    A[6 * i] = alpha1;
    loop_ub = 6 * (i + 3);
    A[loop_ub + 3] = alpha1;
    alpha1 = Phi_[3 * i + 1];
    A[6 * i + 1] = alpha1;
    A[loop_ub + 4] = alpha1;
    alpha1 = Phi_[3 * i + 2];
    A[6 * i + 2] = alpha1;
    A[loop_ub + 5] = alpha1;
  }
  dv[0] = 0.0;
  dv[3] = -Z1_data[20];
  dv[6] = Z1_data[19];
  dv[1] = Z1_data[20];
  dv[4] = 0.0;
  dv[7] = -Z1_data[18];
  dv[2] = -Z1_data[19];
  dv[5] = Z1_data[18];
  dv[8] = 0.0;
  for (i = 0; i < 3; i++) {
    real_T d;
    alpha1 = dv[i];
    beta1 = dv[i + 3];
    d = dv[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      A[(i + 6 * i1) + 3] = (alpha1 * Phi_[3 * i1] + beta1 * Phi_[3 * i1 + 1]) +
                            d * Phi_[3 * i1 + 2];
    }
  }
  st.site = &g_emlrtRSI;
  emxInit_real_T(&st, &dJ, 2, &u_emlrtRTEI);
  b_st.site = &h_emlrtRSI;
  b_mtimes(&b_st, A, BTh, dJ);
  BTh_data = dJ->data;
  emxFree_real_T(&st, &BTh);
  i = dZ1->size[0] * dZ1->size[1];
  dZ1->size[0] = 6;
  emxEnsureCapacity_real_T(sp, dZ1, i, &t_emlrtRTEI);
  if (((real_T)x->size[0] + 5.0) - 1.0 !=
      (int32_T)(((real_T)x->size[0] + 5.0) - 1.0)) {
    emlrtIntegerCheckR2012b(((real_T)x->size[0] + 5.0) - 1.0, &d_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  i = dZ1->size[0] * dZ1->size[1];
  dZ1->size[1] = (int32_T)(((real_T)x->size[0] + 5.0) - 1.0);
  emxEnsureCapacity_real_T(sp, dZ1, i, &t_emlrtRTEI);
  dZ1_data = dZ1->data;
  if (((real_T)x->size[0] + 5.0) - 1.0 !=
      (int32_T)(((real_T)x->size[0] + 5.0) - 1.0)) {
    emlrtIntegerCheckR2012b(((real_T)x->size[0] + 5.0) - 1.0, &e_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  loop_ub = 6 * (int32_T)(((real_T)x->size[0] + 5.0) - 1.0);
  for (i = 0; i < loop_ub; i++) {
    dZ1_data[i] = 0.0;
  }
  dv[0] = 0.0;
  dv[3] = -XI[2];
  dv[6] = XI[1];
  dv[1] = XI[2];
  dv[4] = 0.0;
  dv[7] = -XI[0];
  dv[2] = -XI[1];
  dv[5] = XI[0];
  dv[8] = 0.0;
  for (i = 0; i < 3; i++) {
    dZ1_data[i + 18] = 0.0;
    for (i1 = 0; i1 < 3; i1++) {
      dZ1_data[i + 6 * i1] =
          (Phi_[i] * dv[3 * i1] + Phi_[i + 3] * dv[3 * i1 + 1]) +
          Phi_[i + 6] * dv[3 * i1 + 2];
      dZ1_data[i + 18] += Phi_[i + 3 * i1] * XI[i1 + 3];
    }
  }
  if ((uint32_T)x->size[0] + 4U < 5U) {
    i = 0;
    i1 = 0;
  } else {
    if (dZ1->size[1] < 5) {
      emlrtDynamicBoundsCheckR2012b(5, 1, dZ1->size[1], &n_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = 4;
    if (((int32_T)((uint32_T)x->size[0] + 4U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 4U) > dZ1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 4U), 1,
                                    dZ1->size[1], &o_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = (int32_T)((uint32_T)x->size[0] + 4U);
  }
  iv[0] = 6;
  iv[1] = i1 - i;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &dJ->size[0], 2, &e_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = dJ->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < 6; i2++) {
      dZ1_data[i2 + 6 * (i + i1)] = BTh_data[i2 + 6 * i1];
    }
  }
  emxFree_real_T(sp, &dJ);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emlrtRSInfo in2, const emxArray_real_T *in3,
                             const emxArray_real_T *in4,
                             const emxArray_real_T *in5, int32_T in6,
                             const emxArray_real_T *in7,
                             const emxArray_real_T *in8)
{
  emlrtStack st;
  emxArray_real_T *b_in4;
  emxArray_real_T *b_in5;
  real_T b_in7_data[6];
  const real_T *in4_data;
  const real_T *in5_data;
  const real_T *in7_data;
  real_T *b_in4_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_1;
  st.prev = sp;
  st.tls = sp->tls;
  in7_data = in7->data;
  in5_data = in5->data;
  in4_data = in4->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  i = in5->size[2];
  i1 = (in6 + 1) << 1;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &i_emlrtBCI, (emlrtConstCTX)sp);
  }
  i = in7->size[2];
  if (i1 > i) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &j_emlrtBCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &b_in4, 2, &j_emlrtRTEI);
  i = b_in4->size[0] * b_in4->size[1];
  b_in4->size[0] = 6;
  b_in4->size[1] = in1->size[1];
  emxEnsureCapacity_real_T(sp, b_in4, i, &j_emlrtRTEI);
  b_in4_data = b_in4->data;
  stride_0_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  loop_ub = in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1]);
    r1 = _mm_loadu_pd(&in1_data[6 * i]);
    _mm_storeu_pd(&b_in4_data[6 * i], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1 + 2]);
    i2 = 6 * i + 2;
    r1 = _mm_loadu_pd(&in1_data[i2]);
    _mm_storeu_pd(&b_in4_data[i2], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1 + 4]);
    i2 = 6 * i + 4;
    r1 = _mm_loadu_pd(&in1_data[i2]);
    _mm_storeu_pd(&b_in4_data[i2], _mm_add_pd(r, r1));
    aux_0_1 += stride_0_1;
  }
  emxInit_real_T(sp, &b_in5, 2, &l_emlrtRTEI);
  i = b_in5->size[0] * b_in5->size[1];
  b_in5->size[0] = in5->size[0];
  b_in5->size[1] = in5->size[1];
  emxEnsureCapacity_real_T(sp, b_in5, i, &l_emlrtRTEI);
  in1_data = b_in5->data;
  loop_ub = in5->size[1];
  for (i = 0; i < loop_ub; i++) {
    stride_0_1 = in5->size[0];
    for (i2 = 0; i2 < stride_0_1; i2++) {
      in1_data[i2 + b_in5->size[0] * i] =
          in5_data[(i2 + in5->size[0] * i) +
                   in5->size[0] * in5->size[1] * (i1 - 1)];
    }
  }
  for (i3 = 0; i3 < 6; i3++) {
    b_in7_data[i3] = in7_data[i3 + 6 * (i1 - 1)];
  }
  st.site = (emlrtRSInfo *)&in2;
  ForwardODEX(&st, in3, b_in4, b_in5, b_in7_data, in8, in1);
  emxFree_real_T(sp, &b_in5);
  emxFree_real_T(sp, &b_in4);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &w_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 6;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &w_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&in1_data[6 * aux_0_1]);
    r1 = _mm_loadu_pd(&in2_data[6 * aux_1_1]);
    _mm_storeu_pd(&b_in1_data[6 * i], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in1_data[6 * aux_0_1 + 2]);
    r1 = _mm_loadu_pd(&in2_data[6 * aux_1_1 + 2]);
    _mm_storeu_pd(&b_in1_data[6 * i + 2], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in1_data[6 * aux_0_1 + 4]);
    r1 = _mm_loadu_pd(&in2_data[6 * aux_1_1 + 4]);
    _mm_storeu_pd(&b_in1_data[6 * i + 4], _mm_add_pd(r, r1));
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 6;
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &w_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    for (stride_1_1 = 0; stride_1_1 < 6; stride_1_1++) {
      stride_0_1 = stride_1_1 + 6 * i;
      in1_data[stride_0_1] = b_in1_data[stride_0_1];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void computeForwardKinematicsFast(
    const emlrtStack *sp, const emxArray_real_T *x, const emxArray_real_T *dx,
    real_T ds, const real_T p0[3], const real_T Phi0[9],
    const emxArray_real_T *xia0, const emxArray_real_T *Th,
    const emxArray_real_T *Ba, emxArray_real_T *gtmp, emxArray_real_T *Jtmp,
    emxArray_real_T *vtmp)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *K1Z1;
  emxArray_real_T *K2Z1;
  emxArray_real_T *Z1;
  emxArray_real_T *b_Th;
  emxArray_real_T *b_Z1;
  real_T b[36];
  real_T c_a[36];
  const real_T *Th_data;
  const real_T *xia0_data;
  real_T Ns;
  real_T a;
  real_T b_a;
  real_T *Jtmp_data;
  real_T *K1Z1_data;
  real_T *K2Z1_data;
  real_T *Z1_data;
  real_T *gtmp_data;
  real_T *vtmp_data;
  int32_T iv[2];
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T ii;
  int32_T loop_ub;
  int32_T n;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  Th_data = Th->data;
  xia0_data = xia0->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  % states */
  /*       % spatial steps */
  /*       % position zero */
  /*     % phi zero */
  /*     % intrinsic strain vector */
  /*       % evaluated Theta matrix */
  /*  state to strain matrix         */
  /*  compute total length */
  Ns = (real_T)Th->size[2] / 2.0;
  n = x->size[0];
  emxInit_real_T(sp, &Z1, 2, &c_emlrtRTEI);
  i = Z1->size[0] * Z1->size[1];
  Z1->size[0] = 6;
  emxEnsureCapacity_real_T(sp, Z1, i, &c_emlrtRTEI);
  if (((real_T)x->size[0] + 5.0) - 1.0 !=
      (int32_T)(((real_T)x->size[0] + 5.0) - 1.0)) {
    emlrtIntegerCheckR2012b(((real_T)x->size[0] + 5.0) - 1.0, &emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  i = Z1->size[0] * Z1->size[1];
  Z1->size[1] = (int32_T)(((real_T)x->size[0] + 5.0) - 1.0);
  emxEnsureCapacity_real_T(sp, Z1, i, &c_emlrtRTEI);
  Z1_data = Z1->data;
  if (((real_T)x->size[0] + 5.0) - 1.0 !=
      (int32_T)(((real_T)x->size[0] + 5.0) - 1.0)) {
    emlrtIntegerCheckR2012b(((real_T)x->size[0] + 5.0) - 1.0, &b_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  loop_ub = 6 * (int32_T)(((real_T)x->size[0] + 5.0) - 1.0);
  for (i = 0; i < loop_ub; i++) {
    Z1_data[i] = 0.0;
  }
  for (i = 0; i < 3; i++) {
    Z1_data[6 * i] = Phi0[3 * i];
    Z1_data[6 * i + 1] = Phi0[3 * i + 1];
    Z1_data[6 * i + 2] = Phi0[3 * i + 2];
    Z1_data[i + 18] = p0[i];
  }
  i = gtmp->size[0] * gtmp->size[1] * gtmp->size[2];
  gtmp->size[0] = 4;
  gtmp->size[1] = 4;
  emxEnsureCapacity_real_T(sp, gtmp, i, &d_emlrtRTEI);
  if (Ns != muDoubleScalarFloor(Ns)) {
    emlrtIntegerCheckR2012b(Ns, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = (int32_T)Ns;
  i1 = gtmp->size[0] * gtmp->size[1] * gtmp->size[2];
  gtmp->size[2] = (int32_T)Ns;
  emxEnsureCapacity_real_T(sp, gtmp, i1, &d_emlrtRTEI);
  gtmp_data = gtmp->data;
  i1 = Jtmp->size[0] * Jtmp->size[1] * Jtmp->size[2];
  Jtmp->size[0] = 6;
  Jtmp->size[1] = x->size[0];
  Jtmp->size[2] = (int32_T)Ns;
  emxEnsureCapacity_real_T(sp, Jtmp, i1, &e_emlrtRTEI);
  Jtmp_data = Jtmp->data;
  loop_ub = 6 * x->size[0] * (int32_T)Ns;
  for (i1 = 0; i1 < loop_ub; i1++) {
    Jtmp_data[i1] = 0.0;
  }
  i1 = vtmp->size[0] * vtmp->size[1] * vtmp->size[2];
  vtmp->size[0] = 6;
  vtmp->size[1] = 1;
  vtmp->size[2] = (int32_T)Ns;
  emxEnsureCapacity_real_T(sp, vtmp, i1, &f_emlrtRTEI);
  vtmp_data = vtmp->data;
  if ((int32_T)Ns - 1 >= 0) {
    b_loop_ub = Th->size[1];
    a = 0.66666666666666663 * ds;
    b_a = 0.25 * ds;
    iv[0] = 6;
  }
  emxInit_real_T(sp, &K1Z1, 2, &p_emlrtRTEI);
  emxInit_real_T(sp, &K2Z1, 2, &q_emlrtRTEI);
  emxInit_real_T(sp, &b_Th, 2, &g_emlrtRTEI);
  emxInit_real_T(sp, &b_Z1, 2, &j_emlrtRTEI);
  for (ii = 0; ii < i; ii++) {
    __m128d r;
    __m128d r1;
    real_T d_a[36];
    real_T Phi[9];
    real_T Rt[9];
    real_T b_xia0_data[6];
    int32_T loop_ub_tmp;
    int32_T scalarLB_tmp;
    /*  first EL-diff eval */
    i1 = (ii + 1) << 1;
    if ((i1 - 1 < 1) || (i1 - 1 > Th->size[2])) {
      emlrtDynamicBoundsCheckR2012b(i1 - 1, 1, Th->size[2], &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((i1 - 1 < 1) || (i1 - 1 > xia0->size[2])) {
      emlrtDynamicBoundsCheckR2012b(i1 - 1, 1, xia0->size[2], &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i2 = b_Th->size[0] * b_Th->size[1];
    b_Th->size[0] = Th->size[0];
    b_Th->size[1] = Th->size[1];
    emxEnsureCapacity_real_T(sp, b_Th, i2, &g_emlrtRTEI);
    K1Z1_data = b_Th->data;
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      loop_ub = Th->size[0];
      for (i4 = 0; i4 < loop_ub; i4++) {
        K1Z1_data[i4 + b_Th->size[0] * i2] =
            Th_data[(i4 + Th->size[0] * i2) +
                    Th->size[0] * Th->size[1] * (i1 - 2)];
      }
    }
    for (i3 = 0; i3 < 6; i3++) {
      b_xia0_data[i3] = xia0_data[i3 + 6 * (i1 - 2)];
    }
    st.site = &emlrtRSI;
    ForwardODEX(&st, x, Z1, b_Th, b_xia0_data, Ba, K1Z1);
    K1Z1_data = K1Z1->data;
    /*  second EL-diff eval */
    i2 = K2Z1->size[0] * K2Z1->size[1];
    K2Z1->size[0] = 6;
    K2Z1->size[1] = K1Z1->size[1];
    emxEnsureCapacity_real_T(sp, K2Z1, i2, &h_emlrtRTEI);
    K2Z1_data = K2Z1->data;
    loop_ub_tmp = 6 * K1Z1->size[1];
    scalarLB_tmp = (loop_ub_tmp / 2) << 1;
    vectorUB = scalarLB_tmp - 2;
    for (i2 = 0; i2 <= vectorUB; i2 += 2) {
      r = _mm_loadu_pd(&K1Z1_data[i2]);
      _mm_storeu_pd(&K2Z1_data[i2], _mm_mul_pd(_mm_set1_pd(a), r));
    }
    for (i2 = scalarLB_tmp; i2 < loop_ub_tmp; i2++) {
      K2Z1_data[i2] = a * K1Z1_data[i2];
    }
    if ((Z1->size[1] != K2Z1->size[1]) &&
        ((Z1->size[1] != 1) && (K2Z1->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Z1->size[1], K2Z1->size[1], &emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Z1->size[1] == K2Z1->size[1]) {
      if ((i1 < 1) || (i1 > Th->size[2])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, Th->size[2], &i_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (i1 > xia0->size[2]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xia0->size[2], &j_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i2 = b_Z1->size[0] * b_Z1->size[1];
      b_Z1->size[0] = 6;
      b_Z1->size[1] = Z1->size[1];
      emxEnsureCapacity_real_T(sp, b_Z1, i2, &j_emlrtRTEI);
      K1Z1_data = b_Z1->data;
      loop_ub = 6 * Z1->size[1];
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r = _mm_loadu_pd(&Z1_data[i2]);
        r1 = _mm_loadu_pd(&K2Z1_data[i2]);
        _mm_storeu_pd(&K1Z1_data[i2], _mm_add_pd(r, r1));
      }
      for (i2 = scalarLB; i2 < loop_ub; i2++) {
        K1Z1_data[i2] = Z1_data[i2] + K2Z1_data[i2];
      }
      i2 = b_Th->size[0] * b_Th->size[1];
      b_Th->size[0] = Th->size[0];
      loop_ub = Th->size[1];
      b_Th->size[1] = Th->size[1];
      emxEnsureCapacity_real_T(sp, b_Th, i2, &l_emlrtRTEI);
      K1Z1_data = b_Th->data;
      for (i2 = 0; i2 < loop_ub; i2++) {
        vectorUB = Th->size[0];
        for (i4 = 0; i4 < vectorUB; i4++) {
          K1Z1_data[i4 + b_Th->size[0] * i2] =
              Th_data[(i4 + Th->size[0] * i2) +
                      Th->size[0] * Th->size[1] * (i1 - 1)];
        }
      }
      for (i5 = 0; i5 < 6; i5++) {
        b_xia0_data[i5] = xia0_data[i5 + 6 * (i1 - 1)];
      }
      st.site = &b_emlrtRSI;
      ForwardODEX(&st, x, b_Z1, b_Th, b_xia0_data, Ba, K2Z1);
    } else {
      st.site = &b_emlrtRSI;
      binary_expand_op(&st, K2Z1, b_emlrtRSI, x, Z1, Th, ii, xia0, Ba);
    }
    /*  update integrands */
    loop_ub = 6 * K2Z1->size[1];
    i1 = K2Z1->size[0] * K2Z1->size[1];
    K2Z1->size[0] = 6;
    emxEnsureCapacity_real_T(sp, K2Z1, i1, &i_emlrtRTEI);
    K2Z1_data = K2Z1->data;
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&K2Z1_data[i1]);
      _mm_storeu_pd(&K2Z1_data[i1], _mm_mul_pd(_mm_set1_pd(3.0), r));
    }
    for (i1 = scalarLB; i1 < loop_ub; i1++) {
      K2Z1_data[i1] *= 3.0;
    }
    if ((K1Z1->size[1] != K2Z1->size[1]) &&
        ((K1Z1->size[1] != 1) && (K2Z1->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(K1Z1->size[1], K2Z1->size[1], &b_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    i1 = K1Z1->size[0] * K1Z1->size[1];
    K1Z1->size[0] = 6;
    emxEnsureCapacity_real_T(sp, K1Z1, i1, &k_emlrtRTEI);
    K1Z1_data = K1Z1->data;
    vectorUB = scalarLB_tmp - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r = _mm_loadu_pd(&K1Z1_data[i1]);
      r1 = _mm_loadu_pd(&K2Z1_data[i1]);
      _mm_storeu_pd(&K1Z1_data[i1],
                    _mm_mul_pd(_mm_set1_pd(b_a), _mm_add_pd(r, r1)));
    }
    for (i1 = scalarLB_tmp; i1 < loop_ub_tmp; i1++) {
      K1Z1_data[i1] = b_a * (K1Z1_data[i1] + K2Z1_data[i1]);
    }
    if ((Z1->size[1] != K1Z1->size[1]) &&
        ((Z1->size[1] != 1) && (K1Z1->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Z1->size[1], K1Z1->size[1], &c_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Z1->size[1] == K1Z1->size[1]) {
      loop_ub = 6 * Z1->size[1];
      i1 = Z1->size[0] * Z1->size[1];
      Z1->size[0] = 6;
      emxEnsureCapacity_real_T(sp, Z1, i1, &m_emlrtRTEI);
      Z1_data = Z1->data;
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&Z1_data[i1]);
        r1 = _mm_loadu_pd(&K1Z1_data[i1]);
        _mm_storeu_pd(&Z1_data[i1], _mm_add_pd(r, r1));
      }
      for (i1 = scalarLB; i1 < loop_ub; i1++) {
        Z1_data[i1] += K1Z1_data[i1];
      }
    } else {
      st.site = &l_emlrtRSI;
      plus(&st, Z1, K1Z1);
      Z1_data = Z1->data;
    }
    /*  recover the kinematics entities */
    if (Z1->size[1] < 4) {
      emlrtDynamicBoundsCheckR2012b(4, 1, Z1->size[1], &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    for (i1 = 0; i1 < 3; i1++) {
      if (i1 + 1 > Z1->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1 + 1, 1, Z1->size[1], &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Phi[3 * i1] = Z1_data[6 * i1];
      if (i1 + 1 > Z1->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1 + 1, 1, Z1->size[1], &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Phi[3 * i1 + 1] = Z1_data[6 * i1 + 1];
      if (i1 + 1 > Z1->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1 + 1, 1, Z1->size[1], &l_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Phi[3 * i1 + 2] = Z1_data[6 * i1 + 2];
    }
    if ((uint32_T)n + 4U < 5U) {
      i1 = 0;
      i2 = 0;
    } else {
      if (Z1->size[1] < 5) {
        emlrtDynamicBoundsCheckR2012b(5, 1, Z1->size[1], &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i1 = 4;
      if (((int32_T)((uint32_T)n + 4U) < 1) ||
          ((int32_T)((uint32_T)n + 4U) > Z1->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 4U), 1,
                                      Z1->size[1], &e_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i2 = (int32_T)((uint32_T)n + 4U);
    }
    /* --------------------------------------------------------------------------
     */
    if (ii + 1 > gtmp->size[2]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, gtmp->size[2], &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    for (i4 = 0; i4 < 4; i4++) {
      vectorUB = 4 * i4 + 16 * ii;
      gtmp_data[vectorUB] = 0.0;
      gtmp_data[vectorUB + 1] = 0.0;
      gtmp_data[vectorUB + 2] = 0.0;
      gtmp_data[vectorUB + 3] = 0.0;
    }
    if (ii + 1 > gtmp->size[2]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, gtmp->size[2], &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    gtmp_data[16 * ii + 15] = 1.0;
    if (ii + 1 > gtmp->size[2]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, gtmp->size[2], &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    for (i4 = 0; i4 < 3; i4++) {
      vectorUB = 4 * i4 + 16 * ii;
      gtmp_data[vectorUB] = Phi[3 * i4];
      gtmp_data[vectorUB + 1] = Phi[3 * i4 + 1];
      gtmp_data[vectorUB + 2] = Phi[3 * i4 + 2];
    }
    if (ii + 1 > gtmp->size[2]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, gtmp->size[2], &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    gtmp_data[16 * ii + 12] = Z1_data[18];
    gtmp_data[16 * ii + 13] = Z1_data[19];
    gtmp_data[16 * ii + 14] = Z1_data[20];
    if (ii + 1 > Jtmp->size[2]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Jtmp->size[2], &f_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    /* --------------------------------------------------------------------------
     */
    memset(&c_a[0], 0, 36U * sizeof(real_T));
    for (i4 = 0; i4 < 3; i4++) {
      Ns = Phi[3 * i4];
      c_a[6 * i4] = Ns;
      vectorUB = 6 * (i4 + 3);
      c_a[vectorUB + 3] = Ns;
      Ns = Phi[3 * i4 + 1];
      c_a[6 * i4 + 1] = Ns;
      c_a[vectorUB + 4] = Ns;
      Ns = Phi[3 * i4 + 2];
      c_a[6 * i4 + 2] = Ns;
      c_a[vectorUB + 5] = Ns;
    }
    /* --------------------------------------------------------------------------
     */
    for (i4 = 0; i4 < 3; i4++) {
      for (vectorUB = 0; vectorUB < 3; vectorUB++) {
        c_a[(i4 + 6 * vectorUB) + 3] =
            (0.0 * Phi[3 * vectorUB] + 0.0 * Phi[3 * vectorUB + 1]) +
            0.0 * Phi[3 * vectorUB + 2];
        Rt[vectorUB + 3 * i4] = Phi[i4 + 3 * vectorUB];
      }
    }
    /* --------------------------------------------------------------------------
     */
    memset(&b[0], 0, 36U * sizeof(real_T));
    for (i4 = 0; i4 < 3; i4++) {
      Ns = Rt[3 * i4];
      b[6 * i4] = Ns;
      vectorUB = 6 * (i4 + 3);
      b[vectorUB + 3] = Ns;
      Ns = Rt[3 * i4 + 1];
      b[6 * i4 + 1] = Ns;
      b[vectorUB + 4] = Ns;
      Ns = Rt[3 * i4 + 2];
      b[6 * i4 + 2] = Ns;
      b[vectorUB + 5] = Ns;
    }
    Phi[0] = 0.0;
    Phi[1] = -Z1_data[20];
    Phi[2] = Z1_data[19];
    Phi[3] = Z1_data[20];
    Phi[4] = 0.0;
    Phi[5] = -Z1_data[18];
    Phi[6] = -Z1_data[19];
    Phi[7] = Z1_data[18];
    Phi[8] = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      real_T d;
      real_T d1;
      Ns = Rt[i4];
      d = Rt[i4 + 3];
      d1 = Rt[i4 + 6];
      for (vectorUB = 0; vectorUB < 3; vectorUB++) {
        b[(i4 + 6 * vectorUB) + 3] =
            (Ns * Phi[3 * vectorUB] + d * Phi[3 * vectorUB + 1]) +
            d1 * Phi[3 * vectorUB + 2];
      }
    }
    st.site = &c_emlrtRSI;
    for (i4 = 0; i4 < 6; i4++) {
      for (vectorUB = 0; vectorUB < 6; vectorUB++) {
        Ns = 0.0;
        for (scalarLB = 0; scalarLB < 6; scalarLB++) {
          Ns += c_a[i4 + 6 * scalarLB] * b[scalarLB + 6 * vectorUB];
        }
        d_a[i4 + 6 * vectorUB] = Ns;
      }
    }
    i4 = b_Z1->size[0] * b_Z1->size[1];
    b_Z1->size[0] = 6;
    loop_ub = i2 - i1;
    b_Z1->size[1] = loop_ub;
    emxEnsureCapacity_real_T(&st, b_Z1, i4, &n_emlrtRTEI);
    K1Z1_data = b_Z1->data;
    for (i2 = 0; i2 < loop_ub; i2++) {
      for (i4 = 0; i4 < 6; i4++) {
        K1Z1_data[i4 + 6 * i2] = Z1_data[i4 + 6 * (i1 + i2)];
      }
    }
    b_st.site = &h_emlrtRSI;
    b_mtimes(&b_st, d_a, b_Z1, K2Z1);
    K2Z1_data = K2Z1->data;
    iv[1] = Jtmp->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &K2Z1->size[0], 2, &d_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = K2Z1->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        i4 = i2 + 6 * i1;
        Jtmp_data[i4 + 6 * Jtmp->size[1] * ii] = K2Z1_data[i4];
      }
    }
    st.site = &d_emlrtRSI;
    if (ii + 1 > Jtmp->size[2]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Jtmp->size[2], &g_emlrtBCI, &st);
    }
    b_st.site = &i_emlrtRSI;
    loop_ub = Jtmp->size[1];
    if (dx->size[0] != Jtmp->size[1]) {
      if (dx->size[0] == 1) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &b_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    i1 = K1Z1->size[0] * K1Z1->size[1];
    K1Z1->size[0] = 6;
    K1Z1->size[1] = Jtmp->size[1];
    emxEnsureCapacity_real_T(&st, K1Z1, i1, &o_emlrtRTEI);
    K1Z1_data = K1Z1->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 6; i2++) {
        i4 = i2 + 6 * i1;
        K1Z1_data[i4] = Jtmp_data[i4 + 6 * Jtmp->size[1] * ii];
      }
    }
    if (ii + 1 > vtmp->size[2]) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, vtmp->size[2], &k_emlrtBCI, &st);
    }
    mtimes(K1Z1, dx, b_xia0_data);
    for (i6 = 0; i6 < 6; i6++) {
      (*(real_T(*)[6]) & vtmp_data[6 * ii])[i6] = b_xia0_data[i6];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &b_Z1);
  emxFree_real_T(sp, &b_Th);
  emxFree_real_T(sp, &K2Z1);
  emxFree_real_T(sp, &K1Z1);
  emxFree_real_T(sp, &Z1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (computeForwardKinematicsFast.c) */
