/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeLagrangianFast.c
 *
 * Code generation for function 'computeLagrangianFast'
 *
 */

/* Include files */
#include "computeLagrangianFast.h"
#include "computeLagrangianFast_data.h"
#include "computeLagrangianFast_emxutil.h"
#include "computeLagrangianFast_types.h"
#include "eml_mtimes_helper.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    33,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    38,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    55,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    56,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    58,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    64,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    65,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    66,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    92,               /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    105,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    106,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    107,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    110,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    112,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    113,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    121,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    122,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    123,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    131,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    165,              /* lineNo */
    "LagrangianODEX", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    30,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    34,                      /* lineNo */
    16,                      /* colNo */
    "Th",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    34,                      /* lineNo */
    34,                      /* colNo */
    "xia0",                  /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    34,                      /* lineNo */
    46,                      /* colNo */
    "Ms",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    35,                      /* lineNo */
    21,                      /* colNo */
    "Mtt",                   /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    35,                      /* lineNo */
    38,                      /* colNo */
    "Ktt",                   /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo emlrtECI = {
    2,                       /* nDims */
    38,                      /* lineNo */
    46,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    2,                       /* nDims */
    44,                      /* lineNo */
    24,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    2,                       /* nDims */
    44,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    1,                       /* nDims */
    45,                      /* lineNo */
    24,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    2,                       /* nDims */
    45,                      /* lineNo */
    24,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    1,                       /* nDims */
    45,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    2,                       /* nDims */
    45,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    1,                       /* nDims */
    46,                      /* lineNo */
    24,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    2,                       /* nDims */
    46,                      /* lineNo */
    24,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo j_emlrtECI = {
    1,                       /* nDims */
    46,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo k_emlrtECI = {
    2,                       /* nDims */
    46,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    51,                      /* lineNo */
    15,                      /* colNo */
    "Z1",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    53,                      /* lineNo */
    15,                      /* colNo */
    "Z1",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    53,                      /* lineNo */
    17,                      /* colNo */
    "Z1",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    54,                      /* lineNo */
    15,                      /* colNo */
    "Z1",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    54,                      /* lineNo */
    21,                      /* colNo */
    "Z1",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo l_emlrtECI = {
    2,                       /* nDims */
    66,                      /* lineNo */
    28,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtECInfo m_emlrtECI = {
    2,                       /* nDims */
    65,                      /* lineNo */
    8,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    69,                      /* lineNo */
    9,                       /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    69,                      /* lineNo */
    11,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    69,                      /* lineNo */
    13,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    69,                      /* lineNo */
    15,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    70,                      /* lineNo */
    9,                       /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    70,                      /* lineNo */
    11,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    70,                      /* lineNo */
    13,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    70,                      /* lineNo */
    17,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    71,                      /* lineNo */
    9,                       /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    71,                      /* lineNo */
    11,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    71,                      /* lineNo */
    13,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    71,                      /* lineNo */
    19,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    72,                      /* lineNo */
    9,                       /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    72,                      /* lineNo */
    11,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    72,                      /* lineNo */
    13,                      /* colNo */
    "Z2",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    74,                      /* lineNo */
    12,                      /* colNo */
    "Z1",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    75,                      /* lineNo */
    12,                      /* colNo */
    "Z1",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    21,                      /* lineNo */
    14,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    1                          /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    22,                      /* lineNo */
    14,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    1                          /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    39,                      /* lineNo */
    16,                      /* colNo */
    "Th",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    39,                      /* lineNo */
    32,                      /* colNo */
    "xia0",                  /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    39,                      /* lineNo */
    42,                      /* colNo */
    "Ms",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    40,                      /* lineNo */
    21,                      /* colNo */
    "Mtt",                   /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    40,                      /* lineNo */
    36,                      /* colNo */
    "Ktt",                   /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    21,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    1                          /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    22,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    1                          /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                      /* iFirst */
    -1,                      /* iLast */
    52,                      /* lineNo */
    15,                      /* colNo */
    "Z1",                    /* aName */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    86,               /* lineNo */
    16,               /* colNo */
    "Z1",             /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    88,               /* lineNo */
    16,               /* colNo */
    "Z1",             /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    88,               /* lineNo */
    18,               /* colNo */
    "Z1",             /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    89,               /* lineNo */
    16,               /* colNo */
    "Z1",             /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    89,               /* lineNo */
    22,               /* colNo */
    "Z1",             /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo n_emlrtECI = {
    2,                /* nDims */
    122,              /* lineNo */
    22,               /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    157,              /* lineNo */
    23,               /* colNo */
    "Mscl",           /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    158,              /* lineNo */
    23,               /* colNo */
    "Mscl",           /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    165,              /* lineNo */
    11,               /* colNo */
    "dZ3",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo o_emlrtECI = {
    -1,               /* nDims */
    165,              /* lineNo */
    5,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    148,              /* lineNo */
    11,               /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo p_emlrtECI = {
    -1,               /* nDims */
    148,              /* lineNo */
    1,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    149,              /* lineNo */
    5,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    149,              /* lineNo */
    7,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    149,              /* lineNo */
    9,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    149,              /* lineNo */
    13,               /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo q_emlrtECI = {
    -1,               /* nDims */
    149,              /* lineNo */
    1,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    150,              /* lineNo */
    5,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    150,              /* lineNo */
    7,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    150,              /* lineNo */
    9,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    150,              /* lineNo */
    15,               /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo r_emlrtECI = {
    -1,               /* nDims */
    150,              /* lineNo */
    1,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    151,              /* lineNo */
    5,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    151,              /* lineNo */
    7,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    151,              /* lineNo */
    9,                /* colNo */
    "dZ2",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo s_emlrtECI = {
    -1,               /* nDims */
    151,              /* lineNo */
    1,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    141,              /* lineNo */
    9,                /* colNo */
    "dZ1",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    141,              /* lineNo */
    11,               /* colNo */
    "dZ1",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo t_emlrtECI = {
    -1,               /* nDims */
    141,              /* lineNo */
    1,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    142,              /* lineNo */
    9,                /* colNo */
    "dZ1",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    142,              /* lineNo */
    15,               /* colNo */
    "dZ1",            /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtECInfo u_emlrtECI = {
    -1,               /* nDims */
    142,              /* lineNo */
    1,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtDCInfo e_emlrtDCI = {
    137,              /* lineNo */
    36,               /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    1                          /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    147,              /* lineNo */
    15,               /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    1                          /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    137,              /* lineNo */
    1,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    1                          /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    147,              /* lineNo */
    1,                /* colNo */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    1                          /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    158,              /* lineNo */
    19,               /* colNo */
    "Mscl",           /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    157,              /* lineNo */
    12,               /* colNo */
    "Mscl",           /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    87,               /* lineNo */
    16,               /* colNo */
    "Z1",             /* aName */
    "LagrangianODEX", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m", /* pName */
    0                          /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    21,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    22,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    23,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    34,                      /* lineNo */
    9,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    34,                      /* lineNo */
    43,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    38,                      /* lineNo */
    51,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    53,                      /* lineNo */
    8,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    44,                      /* lineNo */
    31,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    38,                      /* lineNo */
    46,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    44,                      /* lineNo */
    15,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    54,                      /* lineNo */
    8,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    39,                      /* lineNo */
    9,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    44,                      /* lineNo */
    5,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    39,                      /* lineNo */
    39,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    65,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    69,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    70,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    71,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    72,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    77,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    55,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    56,                      /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    45,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    46,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    45,                      /* lineNo */
    24,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    46,                      /* lineNo */
    24,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    88,                      /* lineNo */
    9,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    89,                      /* lineNo */
    9,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    118,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    123,                     /* lineNo */
    6,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    137,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    147,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    153,                     /* lineNo */
    7,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    105,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    106,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    110,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    112,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    113,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    121,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    122,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    123,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    131,                     /* lineNo */
    1,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    121,                     /* lineNo */
    6,                       /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    44,                      /* lineNo */
    10,                      /* colNo */
    "computeLagrangianFast", /* fName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pName */
};

static emlrtRSInfo y_emlrtRSI = {
    46,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    45,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI =
    {
        76,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    44,                      /* lineNo */
    "computeLagrangianFast", /* fcnName */
    "/home/brandon/Documents/MATLAB/SorotokiCode/src/model/mex/lagrangian/"
    "computeLagrangianFast.m" /* pathName */
};

/* Function Declarations */
static void LagrangianODEX(const emlrtStack *sp, const emxArray_real_T *x,
                           const emxArray_real_T *dx, const emxArray_real_T *Z1,
                           const emxArray_real_T *Theta, const real_T xia0[6],
                           const emxArray_real_T *Mscl,
                           const emxArray_real_T *Ba, const real_T Mtt[36],
                           const real_T Ktt[36], const real_T Gvec[3],
                           emxArray_real_T *dZ1, emxArray_real_T *dZ2,
                           emxArray_real_T *dZ3);

static void b_binary_expand_op(
    const emlrtStack *sp, const emlrtRSInfo in1, const emxArray_real_T *in2,
    const emxArray_real_T *in3, const emxArray_real_T *in4,
    const emxArray_real_T *in5, const emxArray_real_T *in6, int32_T in7,
    const emxArray_real_T *in8, const emxArray_real_T *in9,
    const emxArray_real_T *in10, const emxArray_real_T *in11,
    const emxArray_real_T *in12, const real_T in13[3], emxArray_real_T *in14,
    emxArray_real_T *in15, emxArray_real_T *in16);

static void b_plus(const emlrtStack *sp, emxArray_real_T *in1,
                   const emxArray_real_T *in2);

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2);

/* Function Definitions */
static void LagrangianODEX(const emlrtStack *sp, const emxArray_real_T *x,
                           const emxArray_real_T *dx, const emxArray_real_T *Z1,
                           const emxArray_real_T *Theta, const real_T xia0[6],
                           const emxArray_real_T *Mscl,
                           const emxArray_real_T *Ba, const real_T Mtt[36],
                           const real_T Ktt[36], const real_T Gvec[3],
                           emxArray_real_T *dZ1, emxArray_real_T *dZ2,
                           emxArray_real_T *dZ3)
{
  __m128d r;
  __m128d r2;
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
  emxArray_real_T *Jg;
  emxArray_real_T *Jg_transpose;
  emxArray_real_T *Jgt;
  emxArray_real_T *b_Z1;
  emxArray_real_T *dC;
  emxArray_real_T *dG;
  emxArray_real_T *dJ;
  emxArray_real_T *dJt;
  emxArray_real_T *dK;
  emxArray_real_T *dM;
  emxArray_real_T *r1;
  emxArray_real_T *y;
  real_T A[36];
  real_T Ai[36];
  real_T adV[36];
  real_T b_A[36];
  real_T XiHat[16];
  real_T Phi_[9];
  real_T Rt[9];
  real_T Wh[9];
  real_T V[6];
  real_T XI[6];
  real_T b_Ai[6];
  real_T dv[6];
  real_T d_Mscl[4];
  real_T tangentRaw[4];
  real_T ti[3];
  const real_T *Mscl_data;
  const real_T *Z1_data;
  real_T di_idx_0;
  real_T di_idx_1;
  real_T di_idx_2;
  real_T scale;
  real_T *BTh_data;
  real_T *Jg_data;
  real_T *Jg_transpose_data;
  real_T *dC_data;
  real_T *dG_data;
  real_T *dJ_data;
  real_T *dJt_data;
  real_T *dM_data;
  real_T *dZ1_data;
  int32_T iv[2];
  int32_T A_tmp;
  int32_T Ai_tmp;
  int32_T b_Mscl;
  int32_T c_Mscl;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T loop_ub;
  uint32_T u;
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
  Mscl_data = Mscl->data;
  Z1_data = Z1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (Z1->size[1] < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Z1->size[1], &ib_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  for (i = 0; i < 3; i++) {
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &jc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi_[3 * i] = Z1_data[6 * i];
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &jc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi_[3 * i + 1] = Z1_data[6 * i + 1];
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &jc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi_[3 * i + 2] = Z1_data[6 * i + 2];
  }
  if ((uint32_T)x->size[0] + 4U < 5U) {
    i = 0;
    i1 = 0;
  } else {
    if (Z1->size[1] < 5) {
      emlrtDynamicBoundsCheckR2012b(5, 1, Z1->size[1], &jb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = 4;
    if (((int32_T)((uint32_T)x->size[0] + 4U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 4U) > Z1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 4U), 1,
                                    Z1->size[1], &kb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = (int32_T)((uint32_T)x->size[0] + 4U);
  }
  scale = 2.0 * ((real_T)x->size[0] - 1.0) + 6.0;
  if (((real_T)x->size[0] + 6.0) - 1.0 > scale) {
    i2 = 0;
    i3 = 0;
  } else {
    if (((int32_T)((uint32_T)x->size[0] + 5U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 5U) > Z1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 5U), 1,
                                    Z1->size[1], &lb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i2 = x->size[0] + 4;
    if (((int32_T)scale < 1) || ((int32_T)scale > Z1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)scale, 1, Z1->size[1],
                                    &mb_emlrtBCI, (emlrtConstCTX)sp);
    }
    i3 = (int32_T)scale;
  }
  /* build geometric strain */
  emxInit_real_T(sp, &Jg, 2, &ob_emlrtRTEI);
  st.site = &i_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  dynamic_size_checks(&b_st, Theta, Ba->size[1], Theta->size[0]);
  b_st.site = &u_emlrtRSI;
  mtimes(&b_st, Ba, Theta, Jg);
  st.site = &i_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  b_dynamic_size_checks(&b_st, x, Jg->size[1], x->size[0]);
  b_st.site = &u_emlrtRSI;
  b_mtimes(Jg, x, XI);
  r = _mm_loadu_pd(&XI[0]);
  _mm_storeu_pd(&XI[0], _mm_add_pd(r, _mm_loadu_pd(&xia0[0])));
  r = _mm_loadu_pd(&XI[2]);
  _mm_storeu_pd(&XI[2], _mm_add_pd(r, _mm_loadu_pd(&xia0[2])));
  r = _mm_loadu_pd(&XI[4]);
  _mm_storeu_pd(&XI[4], _mm_add_pd(r, _mm_loadu_pd(&xia0[4])));
  /*  build forward kin - position */
  /* --------------------------------------------------------------------------
   */
  Wh[0] = 0.0;
  Wh[3] = -Z1_data[20];
  Wh[6] = Z1_data[19];
  Wh[1] = Z1_data[20];
  Wh[4] = 0.0;
  Wh[7] = -Z1_data[18];
  Wh[2] = -Z1_data[19];
  Wh[5] = Z1_data[18];
  Wh[8] = 0.0;
  memset(&A[0], 0, 36U * sizeof(real_T));
  for (i4 = 0; i4 < 3; i4++) {
    di_idx_0 = Phi_[3 * i4];
    A[6 * i4] = di_idx_0;
    A_tmp = 6 * (i4 + 3);
    A[A_tmp + 3] = di_idx_0;
    di_idx_0 = Phi_[3 * i4 + 1];
    A[6 * i4 + 1] = di_idx_0;
    A[A_tmp + 4] = di_idx_0;
    di_idx_0 = Phi_[3 * i4 + 2];
    A[6 * i4 + 2] = di_idx_0;
    A[A_tmp + 5] = di_idx_0;
  }
  /* --------------------------------------------------------------------------
   */
  for (i4 = 0; i4 < 3; i4++) {
    di_idx_0 = Wh[i4];
    di_idx_1 = Wh[i4 + 3];
    di_idx_2 = Wh[i4 + 6];
    for (A_tmp = 0; A_tmp < 3; A_tmp++) {
      A[(i4 + 6 * A_tmp) + 3] =
          (di_idx_0 * Phi_[3 * A_tmp] + di_idx_1 * Phi_[3 * A_tmp + 1]) +
          di_idx_2 * Phi_[3 * A_tmp + 2];
      Rt[A_tmp + 3 * i4] = Phi_[i4 + 3 * A_tmp];
    }
  }
  /* --------------------------------------------------------------------------
   */
  memset(&Ai[0], 0, 36U * sizeof(real_T));
  for (i4 = 0; i4 < 3; i4++) {
    di_idx_0 = Rt[3 * i4];
    Ai[6 * i4] = di_idx_0;
    Ai_tmp = 6 * (i4 + 3);
    Ai[Ai_tmp + 3] = di_idx_0;
    di_idx_0 = Rt[3 * i4 + 1];
    Ai[6 * i4 + 1] = di_idx_0;
    Ai[Ai_tmp + 4] = di_idx_0;
    di_idx_0 = Rt[3 * i4 + 2];
    Ai[6 * i4 + 2] = di_idx_0;
    Ai[Ai_tmp + 5] = di_idx_0;
  }
  for (i4 = 0; i4 < 3; i4++) {
    di_idx_0 = Rt[i4];
    di_idx_1 = Rt[i4 + 3];
    di_idx_2 = Rt[i4 + 6];
    for (A_tmp = 0; A_tmp < 3; A_tmp++) {
      Ai[(i4 + 6 * A_tmp) + 3] =
          (di_idx_0 * Wh[A_tmp] + di_idx_1 * Wh[A_tmp + 3]) +
          di_idx_2 * Wh[A_tmp + 6];
    }
  }
  /*  build jacobian */
  st.site = &j_emlrtRSI;
  emxInit_real_T(&st, &b_Z1, 2, &fb_emlrtRTEI);
  i4 = b_Z1->size[0] * b_Z1->size[1];
  b_Z1->size[0] = 6;
  loop_ub = i1 - i;
  b_Z1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, b_Z1, i4, &fb_emlrtRTEI);
  dZ1_data = b_Z1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i4 = 0; i4 < 6; i4++) {
      dZ1_data[i4 + 6 * i1] = Z1_data[i4 + 6 * (i + i1)];
    }
  }
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, Ai, b_Z1, Jg);
  Jg_data = Jg->data;
  st.site = &k_emlrtRSI;
  i = b_Z1->size[0] * b_Z1->size[1];
  b_Z1->size[0] = 6;
  loop_ub = i3 - i2;
  b_Z1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, b_Z1, i, &gb_emlrtRTEI);
  dZ1_data = b_Z1->data;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      dZ1_data[i1 + 6 * i] = Z1_data[i1 + 6 * (i2 + i)];
    }
  }
  emxInit_real_T(&st, &Jgt, 2, &pb_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, Ai, b_Z1, Jgt);
  st.site = &l_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  b_dynamic_size_checks(&b_st, dx, Jg->size[1], dx->size[0]);
  b_st.site = &u_emlrtRSI;
  b_mtimes(Jg, dx, V);
  /* --------------------------------------------------------------------------
   */
  Wh[0] = 0.0;
  Wh[3] = -V[2];
  Wh[6] = V[1];
  Wh[1] = V[2];
  Wh[4] = 0.0;
  Wh[7] = -V[0];
  Wh[2] = -V[1];
  Wh[5] = V[0];
  Wh[8] = 0.0;
  /* --------------------------------------------------------------------------
   */
  adV[3] = 0.0;
  adV[9] = -V[5];
  adV[15] = V[4];
  adV[4] = V[5];
  adV[10] = 0.0;
  adV[16] = -V[3];
  adV[5] = -V[4];
  adV[11] = V[3];
  adV[17] = 0.0;
  for (i = 0; i < 3; i++) {
    di_idx_0 = Wh[3 * i];
    adV[6 * i] = di_idx_0;
    A_tmp = 6 * (i + 3);
    adV[A_tmp] = 0.0;
    adV[A_tmp + 3] = di_idx_0;
    di_idx_0 = Wh[3 * i + 1];
    adV[6 * i + 1] = di_idx_0;
    adV[A_tmp + 1] = 0.0;
    adV[A_tmp + 4] = di_idx_0;
    di_idx_0 = Wh[3 * i + 2];
    adV[6 * i + 2] = di_idx_0;
    adV[A_tmp + 2] = 0.0;
    adV[A_tmp + 5] = di_idx_0;
  }
  st.site = &m_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  dynamic_size_checks(&b_st, Theta, Ba->size[1], Theta->size[0]);
  emxInit_real_T(&st, &BTh, 2, &qb_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  mtimes(&b_st, Ba, Theta, BTh);
  BTh_data = BTh->data;
  st.site = &n_emlrtRSI;
  emxInit_real_T(&st, &dJ, 2, &rb_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, A, BTh, dJ);
  dJ_data = dJ->data;
  st.site = &o_emlrtRSI;
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      di_idx_0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        di_idx_0 += A[i + 6 * i2] * adV[i2 + 6 * i1];
      }
      b_A[i + 6 * i1] = di_idx_0;
    }
  }
  emxInit_real_T(&st, &dJt, 2, &sb_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, b_A, BTh, dJt);
  dJt_data = dJt->data;
  /*  Precompute commonly used variables */
  emxInit_real_T(sp, &Jg_transpose, 2, &hb_emlrtRTEI);
  i = Jg_transpose->size[0] * Jg_transpose->size[1];
  Jg_transpose->size[0] = Jg->size[1];
  Jg_transpose->size[1] = 6;
  emxEnsureCapacity_real_T(sp, Jg_transpose, i, &hb_emlrtRTEI);
  Jg_transpose_data = Jg_transpose->data;
  loop_ub = Jg->size[1];
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      Jg_transpose_data[i1 + Jg_transpose->size[0] * i] = Jg_data[i + 6 * i1];
    }
  }
  /*  Compute dM, dC, and dG */
  emxInit_real_T(sp, &y, 2, &xb_emlrtRTEI);
  st.site = &p_emlrtRSI;
  b_st.site = &u_emlrtRSI;
  d_mtimes(&b_st, Jg_transpose, Mtt, y);
  st.site = &p_emlrtRSI;
  emxInit_real_T(&st, &dM, 2, &tb_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  e_mtimes(&b_st, y, Jg, dM);
  dM_data = dM->data;
  st.site = &q_emlrtRSI;
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      di_idx_0 = 0.0;
      di_idx_1 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        i3 = i2 + 6 * i1;
        di_idx_0 += Mtt[i + 6 * i2] * adV[i3];
        di_idx_1 += adV[i2 + 6 * i] * Mtt[i3];
      }
      A_tmp = i + 6 * i1;
      b_A[A_tmp] = di_idx_1;
      A[A_tmp] = di_idx_0;
    }
  }
  for (i = 0; i <= 34; i += 2) {
    r = _mm_loadu_pd(&A[i]);
    r2 = _mm_loadu_pd(&b_A[i]);
    _mm_storeu_pd(&A[i], _mm_sub_pd(r, r2));
  }
  emxInit_real_T(&st, &r1, 2, &ib_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, A, Jg, r1);
  dG_data = r1->data;
  st.site = &q_emlrtRSI;
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, Mtt, Jgt, Jg);
  Jg_data = Jg->data;
  emxFree_real_T(&st, &Jgt);
  if ((r1->size[1] != Jg->size[1]) &&
      ((r1->size[1] != 1) && (Jg->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r1->size[1], Jg->size[1], &n_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &q_emlrtRSI;
  emxInit_real_T(&st, &dC, 2, &ub_emlrtRTEI);
  if (r1->size[1] == Jg->size[1]) {
    i = b_Z1->size[0] * b_Z1->size[1];
    b_Z1->size[0] = 6;
    b_Z1->size[1] = r1->size[1];
    emxEnsureCapacity_real_T(&st, b_Z1, i, &ib_emlrtRTEI);
    dZ1_data = b_Z1->data;
    loop_ub = 6 * r1->size[1];
    A_tmp = (loop_ub / 2) << 1;
    Ai_tmp = A_tmp - 2;
    for (i = 0; i <= Ai_tmp; i += 2) {
      r = _mm_loadu_pd(&dG_data[i]);
      r2 = _mm_loadu_pd(&Jg_data[i]);
      _mm_storeu_pd(&dZ1_data[i], _mm_add_pd(r, r2));
    }
    for (i = A_tmp; i < loop_ub; i++) {
      dZ1_data[i] = dG_data[i] + Jg_data[i];
    }
    b_st.site = &u_emlrtRSI;
    e_mtimes(&b_st, Jg_transpose, b_Z1, dC);
    dC_data = dC->data;
  } else {
    b_st.site = &u_emlrtRSI;
    d_binary_expand_op(&b_st, dC, u_emlrtRSI, Jg_transpose, r1, Jg);
    dC_data = dC->data;
  }
  emxFree_real_T(&st, &b_Z1);
  emxFree_real_T(&st, &r1);
  emxFree_real_T(&st, &Jg);
  st.site = &r_emlrtRSI;
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      di_idx_0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        di_idx_0 += Ai[i + 6 * i2] * Mtt[i2 + 6 * i1];
      }
      A[i + 6 * i1] = di_idx_0;
    }
  }
  dv[0] = 0.0;
  dv[1] = 0.0;
  dv[2] = 0.0;
  dv[3] = Gvec[0];
  dv[4] = Gvec[1];
  dv[5] = Gvec[2];
  i = y->size[0] * y->size[1];
  y->size[0] = Jg_transpose->size[0];
  y->size[1] = 6;
  emxEnsureCapacity_real_T(&st, y, i, &jb_emlrtRTEI);
  dZ1_data = y->data;
  loop_ub = Jg_transpose->size[0] * 6;
  A_tmp = (loop_ub / 2) << 1;
  Ai_tmp = A_tmp - 2;
  for (i = 0; i <= Ai_tmp; i += 2) {
    r = _mm_loadu_pd(&Jg_transpose_data[i]);
    _mm_storeu_pd(&dZ1_data[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  }
  for (i = A_tmp; i < loop_ub; i++) {
    dZ1_data[i] = -Jg_transpose_data[i];
  }
  emxFree_real_T(&st, &Jg_transpose);
  for (i = 0; i < 6; i++) {
    di_idx_0 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      di_idx_0 += A[i + 6 * i1] * dv[i1];
    }
    b_Ai[i] = di_idx_0;
  }
  emxInit_real_T(&st, &dG, 1, &vb_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  f_mtimes(&b_st, y, b_Ai, dG);
  dG_data = dG->data;
  /*  dM = (Jg).'*Mtt*Jg; */
  /*  dC = (Jg).'*((Mtt*adV - adV.'*Mtt)*Jg  + Mtt*Jgt); */
  /*  dG = -(Jg).'*(Ai*Mtt*[0;0;0;Gvec]); */
  /* dF = -0.5*(Jg).'* */
  /*  compute (nonlinear stiffness) */
  st.site = &s_emlrtRSI;
  b_st.site = &u_emlrtRSI;
  g_mtimes(&b_st, BTh, Ktt, y);
  st.site = &s_emlrtRSI;
  emxInit_real_T(&st, &dK, 2, &wb_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  e_mtimes(&b_st, y, BTh, dK);
  Jg_data = dK->data;
  emxFree_real_T(&st, &y);
  /*  compute grav. potential energy */
  i = dZ1->size[0] * dZ1->size[1];
  dZ1->size[0] = 6;
  emxEnsureCapacity_real_T(sp, dZ1, i, &kb_emlrtRTEI);
  if (scale != (int32_T)scale) {
    emlrtIntegerCheckR2012b(scale, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = dZ1->size[0] * dZ1->size[1];
  dZ1->size[1] = (int32_T)scale;
  emxEnsureCapacity_real_T(sp, dZ1, i, &kb_emlrtRTEI);
  dZ1_data = dZ1->data;
  if (scale != (int32_T)scale) {
    emlrtIntegerCheckR2012b(scale, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = 6 * (int32_T)scale;
  for (i = 0; i < loop_ub; i++) {
    dZ1_data[i] = 0.0;
  }
  Wh[0] = 0.0;
  Wh[3] = -XI[2];
  Wh[6] = XI[1];
  Wh[1] = XI[2];
  Wh[4] = 0.0;
  Wh[7] = -XI[0];
  Wh[2] = -XI[1];
  Wh[5] = XI[0];
  Wh[8] = 0.0;
  for (i = 0; i < 3; i++) {
    dZ1_data[i + 18] = 0.0;
    for (i1 = 0; i1 < 3; i1++) {
      dZ1_data[i + 6 * i1] =
          (Phi_[i] * Wh[3 * i1] + Phi_[i + 3] * Wh[3 * i1 + 1]) +
          Phi_[i + 6] * Wh[3 * i1 + 2];
      dZ1_data[i + 18] += Phi_[i + 3 * i1] * XI[i1 + 3];
    }
  }
  if ((uint32_T)x->size[0] + 4U < 5U) {
    i = 0;
    i1 = 0;
  } else {
    if (dZ1->size[1] < 5) {
      emlrtDynamicBoundsCheckR2012b(5, 1, dZ1->size[1], &dc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = 4;
    if (((int32_T)((uint32_T)x->size[0] + 4U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 4U) > dZ1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 4U), 1,
                                    dZ1->size[1], &ec_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = (int32_T)((uint32_T)x->size[0] + 4U);
  }
  iv[0] = 6;
  iv[1] = i1 - i;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &dJ->size[0], 2, &t_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = dJ->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < 6; i2++) {
      dZ1_data[i2 + 6 * (i + i1)] = dJ_data[i2 + 6 * i1];
    }
  }
  emxFree_real_T(sp, &dJ);
  if (((real_T)x->size[0] + 6.0) - 1.0 > scale) {
    i = 0;
    i1 = 0;
  } else {
    if (((int32_T)((uint32_T)x->size[0] + 5U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 5U) > dZ1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 5U), 1,
                                    dZ1->size[1], &fc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = x->size[0] + 4;
    if (((int32_T)scale < 1) || ((int32_T)scale > dZ1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)scale, 1, dZ1->size[1],
                                    &gc_emlrtBCI, (emlrtConstCTX)sp);
    }
    i1 = (int32_T)scale;
  }
  iv[0] = 6;
  iv[1] = i1 - i;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &dJt->size[0], 2, &u_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = dJt->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < 6; i2++) {
      dZ1_data[i2 + 6 * (i + i1)] = dJt_data[i2 + 6 * i1];
    }
  }
  emxFree_real_T(sp, &dJt);
  dZ1_data[22] =
      (Mtt[21] * Z1_data[18] * Gvec[0] + Mtt[21] * Z1_data[19] * Gvec[1]) +
      Mtt[21] * Z1_data[20] * Gvec[2];
  scale = 0.0;
  for (i = 0; i < 6; i++) {
    di_idx_0 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      di_idx_0 += 0.5 * V[i1] * Mtt[i1 + 6 * i];
    }
    scale += di_idx_0 * V[i];
  }
  dZ1_data[23] = scale;
  i = dZ2->size[0] * dZ2->size[1];
  dZ2->size[0] = x->size[0];
  emxEnsureCapacity_real_T(sp, dZ2, i, &lb_emlrtRTEI);
  scale = 3.0 * (real_T)x->size[0];
  if (scale + 1.0 != (int32_T)(scale + 1.0)) {
    emlrtIntegerCheckR2012b(scale + 1.0, &f_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = dZ2->size[0] * dZ2->size[1];
  dZ2->size[1] = (int32_T)(scale + 1.0);
  emxEnsureCapacity_real_T(sp, dZ2, i, &lb_emlrtRTEI);
  dZ1_data = dZ2->data;
  if (scale + 1.0 != (int32_T)(scale + 1.0)) {
    emlrtIntegerCheckR2012b(scale + 1.0, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = x->size[0] * (int32_T)(scale + 1.0);
  for (i = 0; i < loop_ub; i++) {
    dZ1_data[i] = 0.0;
  }
  if (x->size[0] < 1) {
    i = 0;
    i1 = 0;
  } else {
    i = x->size[0];
    i1 = 3 * x->size[0] + 1;
    if (x->size[0] > i1) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, i1, &qb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = x->size[0];
  }
  iv[0] = i;
  iv[1] = i1;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &dM->size[0], 2, &p_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = dM->size[1];
  for (i = 0; i < loop_ub; i++) {
    A_tmp = dM->size[0];
    for (i1 = 0; i1 < A_tmp; i1++) {
      dZ1_data[i1 + dZ2->size[0] * i] = dM_data[i1 + dM->size[0] * i];
    }
  }
  emxFree_real_T(sp, &dM);
  if (x->size[0] < 1) {
    i = 0;
  } else {
    if (dZ2->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, dZ2->size[0], &rb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (x->size[0] > dZ2->size[0]) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, dZ2->size[0], &sb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = x->size[0];
  }
  u = (uint32_T)x->size[0] << 1;
  if ((uint32_T)x->size[0] + 1U > u) {
    i1 = 0;
    i2 = 0;
  } else {
    if (((int32_T)((uint32_T)x->size[0] + 1U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 1U) > dZ2->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 1U), 1,
                                    dZ2->size[1], &tb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = x->size[0];
    if (((int32_T)u < 1) || ((int32_T)u > dZ2->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, dZ2->size[1], &ub_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i2 = (int32_T)u;
  }
  iv[0] = i;
  iv[1] = i2 - i1;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &dC->size[0], 2, &q_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = dC->size[1];
  for (i = 0; i < loop_ub; i++) {
    A_tmp = dC->size[0];
    for (i2 = 0; i2 < A_tmp; i2++) {
      dZ1_data[i2 + dZ2->size[0] * (i1 + i)] = dC_data[i2 + dC->size[0] * i];
    }
  }
  emxFree_real_T(sp, &dC);
  if (x->size[0] < 1) {
    i = 0;
  } else {
    if (dZ2->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, dZ2->size[0], &vb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (x->size[0] > dZ2->size[0]) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, dZ2->size[0], &wb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = x->size[0];
  }
  if (u + 1U > scale) {
    i1 = 0;
    i2 = 0;
  } else {
    if (((int32_T)(u + 1U) < 1) || ((int32_T)(u + 1U) > dZ2->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u + 1U), 1, dZ2->size[1],
                                    &xb_emlrtBCI, (emlrtConstCTX)sp);
    }
    i1 = (int32_T)u;
    if (((int32_T)scale < 1) || ((int32_T)scale > dZ2->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)scale, 1, dZ2->size[1],
                                    &yb_emlrtBCI, (emlrtConstCTX)sp);
    }
    i2 = (int32_T)scale;
  }
  iv[0] = i;
  iv[1] = i2 - i1;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &dK->size[0], 2, &r_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = dK->size[1];
  for (i = 0; i < loop_ub; i++) {
    A_tmp = dK->size[0];
    for (i2 = 0; i2 < A_tmp; i2++) {
      dZ1_data[i2 + dZ2->size[0] * (i1 + i)] = Jg_data[i2 + dK->size[0] * i];
    }
  }
  emxFree_real_T(sp, &dK);
  if (x->size[0] < 1) {
    i = 0;
  } else {
    if (dZ2->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, dZ2->size[0], &ac_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (x->size[0] > dZ2->size[0]) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, dZ2->size[0], &bc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = x->size[0];
  }
  if (((int32_T)(scale + 1.0) < 1) || ((int32_T)(scale + 1.0) > dZ2->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(scale + 1.0), 1, dZ2->size[1],
                                  &cc_emlrtBCI, (emlrtConstCTX)sp);
  }
  emlrtSubAssignSizeCheckR2012b(&i, 1, &dG->size[0], 1, &s_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = dG->size[0];
  for (i = 0; i < loop_ub; i++) {
    dZ1_data[i + dZ2->size[0] * ((int32_T)(scale + 1.0) - 1)] = dG_data[i];
  }
  i = dZ3->size[0] * dZ3->size[1];
  dZ3->size[0] = x->size[0];
  dZ3->size[1] = Mscl->size[2];
  emxEnsureCapacity_real_T(sp, dZ3, i, &mb_emlrtRTEI);
  dZ1_data = dZ3->data;
  i = Mscl->size[2];
  if (Mscl->size[2] - 1 >= 0) {
    b_Mscl = Mscl->size[1];
    c_Mscl = Mscl->size[1];
    Wh[0] = 0.0;
    Wh[4] = 0.0;
    Wh[8] = 0.0;
  }
  if (i - 1 >= 0) {
    d_Mscl[3] = 1.0;
  }
  for (A_tmp = 0; A_tmp < i; A_tmp++) {
    real_T absxk;
    real_T b_y;
    real_T t;
    if (A_tmp + 1 > Mscl->size[2]) {
      emlrtDynamicBoundsCheckR2012b(A_tmp + 1, 1, Mscl->size[2], &nb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (b_Mscl < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, b_Mscl, &ic_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    di_idx_0 = Mscl_data[Mscl->size[1] * A_tmp];
    if (b_Mscl < 2) {
      emlrtDynamicBoundsCheckR2012b(2, 1, 1, &ic_emlrtBCI, (emlrtConstCTX)sp);
    }
    di_idx_1 = Mscl_data[Mscl->size[1] * A_tmp + 1];
    if (b_Mscl < 3) {
      emlrtDynamicBoundsCheckR2012b(3, 1, 2, &ic_emlrtBCI, (emlrtConstCTX)sp);
    }
    di_idx_2 = Mscl_data[Mscl->size[1] * A_tmp + 2];
    /*  lifted position vector */
    if (c_Mscl < 4) {
      emlrtDynamicBoundsCheckR2012b(4, 1, c_Mscl, &hc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (c_Mscl < 5) {
      emlrtDynamicBoundsCheckR2012b(5, 1, 4, &hc_emlrtBCI, (emlrtConstCTX)sp);
    }
    if (c_Mscl < 6) {
      emlrtDynamicBoundsCheckR2012b(6, 1, 5, &hc_emlrtBCI, (emlrtConstCTX)sp);
    }
    if (A_tmp + 1 > Mscl->size[2]) {
      emlrtDynamicBoundsCheckR2012b(A_tmp + 1, 1, Mscl->size[2], &ob_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    /*  lifted position vector deriv. */
    /* --------------------------------------------------------------------------
     */
    memset(&XiHat[0], 0, 16U * sizeof(real_T));
    XiHat[0] = 0.0;
    XiHat[4] = -XI[2];
    XiHat[8] = XI[1];
    XiHat[1] = XI[2];
    XiHat[5] = 0.0;
    XiHat[9] = -XI[0];
    XiHat[2] = -XI[1];
    XiHat[6] = XI[0];
    XiHat[10] = 0.0;
    XiHat[12] = XI[3];
    XiHat[13] = XI[4];
    XiHat[14] = XI[5];
    for (i1 = 0; i1 <= 2; i1 += 2) {
      r = _mm_loadu_pd(&XiHat[i1]);
      r = _mm_mul_pd(r, _mm_set1_pd(di_idx_0));
      r2 = _mm_loadu_pd(&XiHat[i1 + 4]);
      r2 = _mm_mul_pd(r2, _mm_set1_pd(di_idx_1));
      r = _mm_add_pd(r, r2);
      r2 = _mm_loadu_pd(&XiHat[i1 + 8]);
      r2 = _mm_mul_pd(r2, _mm_set1_pd(di_idx_2));
      r = _mm_add_pd(r, r2);
      r2 = _mm_loadu_pd(&XiHat[i1 + 12]);
      r = _mm_add_pd(r, r2);
      _mm_storeu_pd(&tangentRaw[i1], r);
    }
    d_Mscl[0] = Mscl_data[Mscl->size[1] * A_tmp + 3];
    d_Mscl[1] = Mscl_data[Mscl->size[1] * A_tmp + 4];
    d_Mscl[2] = Mscl_data[Mscl->size[1] * A_tmp + 5];
    r = _mm_loadu_pd(&tangentRaw[0]);
    r2 = _mm_loadu_pd(&d_Mscl[0]);
    _mm_storeu_pd(&tangentRaw[0], _mm_add_pd(r, r2));
    r = _mm_loadu_pd(&tangentRaw[2]);
    r2 = _mm_loadu_pd(&d_Mscl[2]);
    _mm_storeu_pd(&tangentRaw[2], _mm_add_pd(r, r2));
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(tangentRaw[0]);
    if (absxk > 3.3121686421112381E-170) {
      b_y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      b_y = t * t;
    }
    absxk = muDoubleScalarAbs(tangentRaw[1]);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    absxk = muDoubleScalarAbs(tangentRaw[2]);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = b_y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
    b_y = scale * muDoubleScalarSqrt(b_y);
    r = _mm_loadu_pd(&tangentRaw[0]);
    _mm_storeu_pd(&ti[0], _mm_div_pd(r, _mm_set1_pd(b_y)));
    ti[2] = tangentRaw[2] / b_y;
    /* --------------------------------------------------------------------------
     */
    if (A_tmp + 1 > dZ3->size[1]) {
      emlrtDynamicBoundsCheckR2012b(A_tmp + 1, 1, dZ3->size[1], &pb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    st.site = &t_emlrtRSI;
    b_st.site = &u_emlrtRSI;
    Wh[3] = -di_idx_2;
    Wh[6] = di_idx_1;
    Wh[1] = di_idx_2;
    Wh[7] = -di_idx_0;
    Wh[2] = -di_idx_1;
    Wh[5] = di_idx_0;
    r = _mm_loadu_pd(&Wh[0]);
    r = _mm_mul_pd(r, _mm_set1_pd(ti[0]));
    r2 = _mm_loadu_pd(&Wh[3]);
    r2 = _mm_mul_pd(r2, _mm_set1_pd(ti[1]));
    r = _mm_add_pd(r, r2);
    r2 = _mm_loadu_pd(&Wh[6]);
    r2 = _mm_mul_pd(r2, _mm_set1_pd(ti[2]));
    r = _mm_add_pd(r, r2);
    _mm_storeu_pd(&V[0], r);
    r = _mm_loadu_pd(&ti[0]);
    _mm_storeu_pd(&V[3], r);
    V[2] = (ti[0] * Wh[2] + ti[1] * Wh[5]) + ti[2] * Wh[8];
    V[5] = ti[2];
    if (BTh->size[1] == 0) {
      dG->size[0] = 0;
    } else {
      c_st.site = &w_emlrtRSI;
      d_st.site = &x_emlrtRSI;
      TRANSB1 = 'N';
      TRANSA1 = 'T';
      di_idx_0 = 1.0;
      di_idx_1 = 0.0;
      m_t = (ptrdiff_t)BTh->size[1];
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)6;
      lda_t = (ptrdiff_t)6;
      ldb_t = (ptrdiff_t)6;
      ldc_t = (ptrdiff_t)BTh->size[1];
      i1 = dG->size[0];
      dG->size[0] = BTh->size[1];
      emxEnsureCapacity_real_T(&d_st, dG, i1, &nb_emlrtRTEI);
      dG_data = dG->data;
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &di_idx_0, &BTh_data[0],
            &lda_t, &V[0], &ldb_t, &di_idx_1, &dG_data[0], &ldc_t);
    }
    emlrtSubAssignSizeCheckR2012b(&dZ3->size[0], 1, &dG->size[0], 1,
                                  &o_emlrtECI, (emlrtCTX)sp);
    loop_ub = dG->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      dZ1_data[i1 + dZ3->size[0] * A_tmp] = dG_data[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &dG);
  emxFree_real_T(sp, &BTh);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void b_binary_expand_op(
    const emlrtStack *sp, const emlrtRSInfo in1, const emxArray_real_T *in2,
    const emxArray_real_T *in3, const emxArray_real_T *in4,
    const emxArray_real_T *in5, const emxArray_real_T *in6, int32_T in7,
    const emxArray_real_T *in8, const emxArray_real_T *in9,
    const emxArray_real_T *in10, const emxArray_real_T *in11,
    const emxArray_real_T *in12, const real_T in13[3], emxArray_real_T *in14,
    emxArray_real_T *in15, emxArray_real_T *in16)
{
  emlrtStack st;
  emxArray_real_T *b_in4;
  emxArray_real_T *b_in6;
  emxArray_real_T *b_in9;
  real_T b_in11_data[36];
  real_T b_in12_data[36];
  real_T b_in8_data[6];
  const real_T *in11_data;
  const real_T *in12_data;
  const real_T *in4_data;
  const real_T *in5_data;
  const real_T *in6_data;
  const real_T *in8_data;
  const real_T *in9_data;
  real_T *b_in4_data;
  int32_T aux_0_1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T stride_0_1;
  st.prev = sp;
  st.tls = sp->tls;
  in12_data = in12->data;
  in11_data = in11->data;
  in9_data = in9->data;
  in8_data = in8->data;
  in6_data = in6->data;
  in5_data = in5->data;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  i = in6->size[2];
  i1 = (int32_T)((uint32_T)(in7 + 1) << 1);
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &cb_emlrtBCI, (emlrtConstCTX)sp);
  }
  i = in8->size[2];
  if (i1 > i) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &db_emlrtBCI, (emlrtConstCTX)sp);
  }
  i = in9->size[0];
  if (i1 > i) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &eb_emlrtBCI, (emlrtConstCTX)sp);
  }
  i = in11->size[2];
  if (i1 > i) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &fb_emlrtBCI, (emlrtConstCTX)sp);
  }
  i = in12->size[2];
  if (i1 > i) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &gb_emlrtBCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &b_in4, 2, &l_emlrtRTEI);
  i = b_in4->size[0] * b_in4->size[1];
  b_in4->size[0] = 6;
  b_in4->size[1] = in5->size[1];
  emxEnsureCapacity_real_T(sp, b_in4, i, &l_emlrtRTEI);
  b_in4_data = b_in4->data;
  stride_0_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  loop_ub = in5->size[1];
  for (i = 0; i < loop_ub; i++) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1]);
    r1 = _mm_loadu_pd(&in5_data[6 * i]);
    _mm_storeu_pd(&b_in4_data[6 * i], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1 + 2]);
    i2 = 6 * i + 2;
    r1 = _mm_loadu_pd(&in5_data[i2]);
    _mm_storeu_pd(&b_in4_data[i2], _mm_add_pd(r, r1));
    r = _mm_loadu_pd(&in4_data[6 * aux_0_1 + 4]);
    i2 = 6 * i + 4;
    r1 = _mm_loadu_pd(&in5_data[i2]);
    _mm_storeu_pd(&b_in4_data[i2], _mm_add_pd(r, r1));
    aux_0_1 += stride_0_1;
  }
  emxInit_real_T(sp, &b_in6, 2, &o_emlrtRTEI);
  i = b_in6->size[0] * b_in6->size[1];
  b_in6->size[0] = in6->size[0];
  b_in6->size[1] = in6->size[1];
  emxEnsureCapacity_real_T(sp, b_in6, i, &o_emlrtRTEI);
  b_in4_data = b_in6->data;
  loop_ub = in6->size[1];
  for (i = 0; i < loop_ub; i++) {
    stride_0_1 = in6->size[0];
    for (i2 = 0; i2 < stride_0_1; i2++) {
      b_in4_data[i2 + b_in6->size[0] * i] =
          in6_data[(i2 + in6->size[0] * i) +
                   in6->size[0] * in6->size[1] * (i1 - 1)];
    }
  }
  emxInit_real_T(sp, &b_in9, 3, &q_emlrtRTEI);
  i = b_in9->size[0] * b_in9->size[1] * b_in9->size[2];
  b_in9->size[0] = 1;
  b_in9->size[1] = in9->size[1];
  b_in9->size[2] = in9->size[2];
  emxEnsureCapacity_real_T(sp, b_in9, i, &q_emlrtRTEI);
  b_in4_data = b_in9->data;
  loop_ub = in9->size[2];
  for (i = 0; i < loop_ub; i++) {
    stride_0_1 = in9->size[1];
    for (i2 = 0; i2 < stride_0_1; i2++) {
      b_in4_data[i2 + b_in9->size[1] * i] = in9_data
          [((i1 + in9->size[0] * i2) + in9->size[0] * in9->size[1] * i) - 1];
    }
  }
  for (i3 = 0; i3 < 6; i3++) {
    b_in8_data[i3] = in8_data[i3 + 6 * (i1 - 1)];
  }
  memcpy(&b_in11_data[0], &(*(real_T(*)[36]) & in11_data[36 * (i1 - 1)])[0],
         36U * sizeof(real_T));
  memcpy(&b_in12_data[0], &(*(real_T(*)[36]) & in12_data[36 * (i1 - 1)])[0],
         36U * sizeof(real_T));
  st.site = (emlrtRSInfo *)&in1;
  LagrangianODEX(&st, in2, in3, b_in4, b_in6, b_in8_data, b_in9, in10,
                 b_in11_data, b_in12_data, in13, in14, in15, in16);
  emxFree_real_T(sp, &b_in9);
  emxFree_real_T(sp, &b_in6);
  emxFree_real_T(sp, &b_in4);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void b_plus(const emlrtStack *sp, emxArray_real_T *in1,
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
  emxInit_real_T(sp, &b_in1, 2, &cc_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 6;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  b_in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &cc_emlrtRTEI);
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
  emxEnsureCapacity_real_T(sp, in1, i, &cc_emlrtRTEI);
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

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
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
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &cb_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &cb_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &cb_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void computeLagrangianFast(
    const emlrtStack *sp, const emxArray_real_T *x, const emxArray_real_T *dx,
    real_T ds, const real_T p0[3], const real_T Phi0[9],
    const emxArray_real_T *xia0, const emxArray_real_T *Th,
    const emxArray_real_T *Ms, const emxArray_real_T *Ba,
    const emxArray_real_T *Ktt, const emxArray_real_T *Mtt, real_T Zeta,
    const real_T Gvec[3], emxArray_real_T *M, emxArray_real_T *C,
    emxArray_real_T *K, emxArray_real_T *R, emxArray_real_T *G,
    emxArray_real_T *B, real_T p[3], real_T Phi[9], emxArray_real_T *J,
    emxArray_real_T *dJdt, real_T *Vg, real_T *Kin)
{
  __m128d r1;
  __m128d r2;
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *J0;
  emxArray_real_T *K1Z2;
  emxArray_real_T *K1Z3;
  emxArray_real_T *K2Z2;
  emxArray_real_T *K2Z3;
  emxArray_real_T *Z1;
  emxArray_real_T *Z2;
  emxArray_real_T *b_Ms;
  emxArray_real_T *b_Th;
  emxArray_real_T *b_Z1;
  emxArray_real_T *dJ0;
  emxArray_real_T *r;
  real_T b_Ktt_data[36];
  real_T b_Mtt_data[36];
  real_T b_a[36];
  real_T Wh[9];
  real_T b_Wh[9];
  real_T V[6];
  const real_T *Ktt_data;
  const real_T *Ms_data;
  const real_T *Mtt_data;
  const real_T *Th_data;
  const real_T *xia0_data;
  real_T a;
  real_T d;
  real_T d1;
  real_T d2;
  real_T *B_data;
  real_T *J0_data;
  real_T *K1Z2_data;
  real_T *K1Z3_data;
  real_T *K2Z2_data;
  real_T *Z1_data;
  real_T *Z2_data;
  real_T *dJ0_data;
  real_T *dJdt_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ii;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T scalarLB;
  int32_T scalarLB_tmp;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  uint32_T u;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  Mtt_data = Mtt->data;
  Ktt_data = Ktt->data;
  Ms_data = Ms->data;
  Th_data = Th->data;
  xia0_data = xia0->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  % states */
  /*       % spatial steps */
  /*       % position zero */
  /*     % phi zero */
  /*     % intrinsic strain vector */
  /*       % evaluated Theta matrix */
  /*       % evaluated muscle vector */
  /*       % state to strain matrix */
  /*      % geometric stiffness */
  /*      % geometric inertia */
  /*     % dampings coefficient */
  /*  gravitional vector   */
  /*  compute total length */
  emxInit_real_T(sp, &Z1, 2, &d_emlrtRTEI);
  i = Z1->size[0] * Z1->size[1];
  Z1->size[0] = 6;
  emxEnsureCapacity_real_T(sp, Z1, i, &d_emlrtRTEI);
  d = 2.0 * ((real_T)x->size[0] - 1.0) + 6.0;
  if (d != (int32_T)d) {
    emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
  }
  i = Z1->size[0] * Z1->size[1];
  Z1->size[1] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, Z1, i, &d_emlrtRTEI);
  Z1_data = Z1->data;
  if (d != (int32_T)d) {
    emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = 6 * (int32_T)d;
  for (i = 0; i < loop_ub; i++) {
    Z1_data[i] = 0.0;
  }
  emxInit_real_T(sp, &Z2, 2, &e_emlrtRTEI);
  i = Z2->size[0] * Z2->size[1];
  Z2->size[0] = x->size[0];
  emxEnsureCapacity_real_T(sp, Z2, i, &e_emlrtRTEI);
  d1 = 3.0 * (real_T)x->size[0];
  if (d1 + 1.0 != (int32_T)(d1 + 1.0)) {
    emlrtIntegerCheckR2012b(d1 + 1.0, &b_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = Z2->size[0] * Z2->size[1];
  Z2->size[1] = (int32_T)(d1 + 1.0);
  emxEnsureCapacity_real_T(sp, Z2, i, &e_emlrtRTEI);
  Z2_data = Z2->data;
  if (d1 + 1.0 != (int32_T)(d1 + 1.0)) {
    emlrtIntegerCheckR2012b(d1 + 1.0, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = x->size[0] * (int32_T)(d1 + 1.0);
  for (i = 0; i < loop_ub; i++) {
    Z2_data[i] = 0.0;
  }
  i = B->size[0] * B->size[1];
  B->size[0] = x->size[0];
  B->size[1] = Ms->size[2];
  emxEnsureCapacity_real_T(sp, B, i, &f_emlrtRTEI);
  B_data = B->data;
  loop_ub = x->size[0] * Ms->size[2];
  for (i = 0; i < loop_ub; i++) {
    B_data[i] = 0.0;
  }
  for (i = 0; i < 3; i++) {
    Z1_data[6 * i] = Phi0[3 * i];
    Z1_data[6 * i + 1] = Phi0[3 * i + 1];
    Z1_data[6 * i + 2] = Phi0[3 * i + 2];
    Z1_data[i + 18] = p0[i];
  }
  /* NLStiff = false;  */
  a = (real_T)Th->size[2] / 2.0;
  i = (int32_T)a;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, a, mxDOUBLE_CLASS, (int32_T)a,
                                &emlrtRTEI, (emlrtConstCTX)sp);
  emxInit_real_T(sp, &J0, 2, &y_emlrtRTEI);
  emxInit_real_T(sp, &dJ0, 2, &ab_emlrtRTEI);
  emxInit_real_T(sp, &K1Z2, 2, &bb_emlrtRTEI);
  emxInit_real_T(sp, &K1Z3, 2, &cb_emlrtRTEI);
  emxInit_real_T(sp, &K2Z2, 2, &db_emlrtRTEI);
  emxInit_real_T(sp, &K2Z3, 2, &eb_emlrtRTEI);
  emxInit_real_T(sp, &r, 2, &l_emlrtRTEI);
  emxInit_real_T(sp, &b_Th, 2, &g_emlrtRTEI);
  emxInit_real_T(sp, &b_Ms, 3, &h_emlrtRTEI);
  emxInit_real_T(sp, &b_Z1, 2, &l_emlrtRTEI);
  for (ii = 0; ii < i; ii++) {
    /*  first EL-diff eval */
    u = (uint32_T)(ii + 1) << 1;
    if ((int32_T)(u - 1U) > Th->size[2]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u - 1U), 1, Th->size[2],
                                    &emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((int32_T)(u - 1U) > xia0->size[2]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u - 1U), 1, xia0->size[2],
                                    &b_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((int32_T)(u - 1U) > Ms->size[0]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u - 1U), 1, Ms->size[0],
                                    &c_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((int32_T)(u - 1U) > Mtt->size[2]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u - 1U), 1, Mtt->size[2],
                                    &d_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((int32_T)(u - 1U) > Ktt->size[2]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u - 1U), 1, Ktt->size[2],
                                    &e_emlrtBCI, (emlrtConstCTX)sp);
    }
    i1 = b_Th->size[0] * b_Th->size[1];
    b_Th->size[0] = Th->size[0];
    loop_ub = Th->size[1];
    b_Th->size[1] = Th->size[1];
    emxEnsureCapacity_real_T(sp, b_Th, i1, &g_emlrtRTEI);
    dJdt_data = b_Th->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = Th->size[0];
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        dJdt_data[i2 + b_Th->size[0] * i1] =
            Th_data[(i2 + Th->size[0] * i1) +
                    Th->size[0] * Th->size[1] * ((int32_T)u - 2)];
      }
    }
    i1 = b_Ms->size[0] * b_Ms->size[1] * b_Ms->size[2];
    b_Ms->size[0] = 1;
    b_Ms->size[1] = Ms->size[1];
    loop_ub = Ms->size[2];
    b_Ms->size[2] = Ms->size[2];
    emxEnsureCapacity_real_T(sp, b_Ms, i1, &h_emlrtRTEI);
    dJdt_data = b_Ms->data;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = Ms->size[1];
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        dJdt_data[i2 + b_Ms->size[1] * i1] =
            Ms_data[(((int32_T)u + Ms->size[0] * i2) +
                     Ms->size[0] * Ms->size[1] * i1) -
                    2];
      }
    }
    for (i3 = 0; i3 < 6; i3++) {
      V[i3] = xia0_data[i3 + 6 * ((int32_T)u - 2)];
    }
    memcpy(&b_Mtt_data[0],
           &(*(real_T(*)[36]) & Mtt_data[36 * ((int32_T)u - 2)])[0],
           36U * sizeof(real_T));
    memcpy(&b_Ktt_data[0],
           &(*(real_T(*)[36]) & Ktt_data[36 * ((int32_T)u - 2)])[0],
           36U * sizeof(real_T));
    st.site = &emlrtRSI;
    LagrangianODEX(&st, x, dx, Z1, b_Th, V, b_Ms, Ba, b_Mtt_data, b_Ktt_data,
                   Gvec, J0, K1Z2, K1Z3);
    K1Z3_data = K1Z3->data;
    K1Z2_data = K1Z2->data;
    J0_data = J0->data;
    /*  second EL-diff eval */
    a = 0.66666666666666663 * ds;
    i1 = r->size[0] * r->size[1];
    r->size[0] = 6;
    r->size[1] = J0->size[1];
    emxEnsureCapacity_real_T(sp, r, i1, &i_emlrtRTEI);
    K2Z2_data = r->data;
    loop_ub_tmp = 6 * J0->size[1];
    scalarLB_tmp = (loop_ub_tmp / 2) << 1;
    vectorUB_tmp = scalarLB_tmp - 2;
    for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
      r1 = _mm_loadu_pd(&J0_data[i1]);
      _mm_storeu_pd(&K2Z2_data[i1], _mm_mul_pd(_mm_set1_pd(a), r1));
    }
    for (i1 = scalarLB_tmp; i1 < loop_ub_tmp; i1++) {
      K2Z2_data[i1] = a * J0_data[i1];
    }
    if ((Z1->size[1] != r->size[1]) &&
        ((Z1->size[1] != 1) && (r->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Z1->size[1], r->size[1], &emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Z1->size[1] == r->size[1]) {
      if (((int32_T)u < 1) || ((int32_T)u > Th->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, Th->size[2], &cb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)u < 1) || ((int32_T)u > xia0->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, xia0->size[2],
                                      &db_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)u < 1) || ((int32_T)u > Ms->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, Ms->size[0], &eb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)u < 1) || ((int32_T)u > Mtt->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, Mtt->size[2], &fb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)u < 1) || ((int32_T)u > Ktt->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, Ktt->size[2], &gb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i1 = b_Z1->size[0] * b_Z1->size[1];
      b_Z1->size[0] = 6;
      b_Z1->size[1] = Z1->size[1];
      emxEnsureCapacity_real_T(sp, b_Z1, i1, &l_emlrtRTEI);
      dJdt_data = b_Z1->data;
      loop_ub = 6 * Z1->size[1];
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r1 = _mm_loadu_pd(&Z1_data[i1]);
        r2 = _mm_loadu_pd(&K2Z2_data[i1]);
        _mm_storeu_pd(&dJdt_data[i1], _mm_add_pd(r1, r2));
      }
      for (i1 = scalarLB; i1 < loop_ub; i1++) {
        dJdt_data[i1] = Z1_data[i1] + K2Z2_data[i1];
      }
      i1 = b_Th->size[0] * b_Th->size[1];
      b_Th->size[0] = Th->size[0];
      loop_ub = Th->size[1];
      b_Th->size[1] = Th->size[1];
      emxEnsureCapacity_real_T(sp, b_Th, i1, &o_emlrtRTEI);
      dJdt_data = b_Th->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = Th->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          dJdt_data[i2 + b_Th->size[0] * i1] =
              Th_data[(i2 + Th->size[0] * i1) +
                      Th->size[0] * Th->size[1] * ((int32_T)u - 1)];
        }
      }
      i1 = b_Ms->size[0] * b_Ms->size[1] * b_Ms->size[2];
      b_Ms->size[0] = 1;
      b_Ms->size[1] = Ms->size[1];
      loop_ub = Ms->size[2];
      b_Ms->size[2] = Ms->size[2];
      emxEnsureCapacity_real_T(sp, b_Ms, i1, &q_emlrtRTEI);
      dJdt_data = b_Ms->data;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = Ms->size[1];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          dJdt_data[i2 + b_Ms->size[1] * i1] =
              Ms_data[(((int32_T)u + Ms->size[0] * i2) +
                       Ms->size[0] * Ms->size[1] * i1) -
                      1];
        }
      }
      for (i4 = 0; i4 < 6; i4++) {
        V[i4] = xia0_data[i4 + 6 * ((int32_T)u - 1)];
      }
      memcpy(&b_Mtt_data[0],
             &(*(real_T(*)[36]) & Mtt_data[36 * ((int32_T)u - 1)])[0],
             36U * sizeof(real_T));
      memcpy(&b_Ktt_data[0],
             &(*(real_T(*)[36]) & Ktt_data[36 * ((int32_T)u - 1)])[0],
             36U * sizeof(real_T));
      st.site = &b_emlrtRSI;
      LagrangianODEX(&st, x, dx, b_Z1, b_Th, V, b_Ms, Ba, b_Mtt_data,
                     b_Ktt_data, Gvec, dJ0, K2Z2, K2Z3);
      dJdt_data = K2Z3->data;
      K2Z2_data = K2Z2->data;
    } else {
      st.site = &b_emlrtRSI;
      b_binary_expand_op(&st, b_emlrtRSI, x, dx, Z1, r, Th, ii, xia0, Ms, Ba,
                         Mtt, Ktt, Gvec, dJ0, K2Z2, K2Z3);
      dJdt_data = K2Z3->data;
      K2Z2_data = K2Z2->data;
    }
    /*  update integrands */
    loop_ub = 6 * dJ0->size[1];
    i1 = dJ0->size[0] * dJ0->size[1];
    dJ0->size[0] = 6;
    emxEnsureCapacity_real_T(sp, dJ0, i1, &k_emlrtRTEI);
    dJ0_data = dJ0->data;
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r1 = _mm_loadu_pd(&dJ0_data[i1]);
      _mm_storeu_pd(&dJ0_data[i1], _mm_mul_pd(_mm_set1_pd(3.0), r1));
    }
    for (i1 = scalarLB; i1 < loop_ub; i1++) {
      dJ0_data[i1] *= 3.0;
    }
    if ((J0->size[1] != dJ0->size[1]) &&
        ((J0->size[1] != 1) && (dJ0->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(J0->size[1], dJ0->size[1], &b_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    a = 0.25 * ds;
    i1 = J0->size[0] * J0->size[1];
    J0->size[0] = 6;
    emxEnsureCapacity_real_T(sp, J0, i1, &m_emlrtRTEI);
    J0_data = J0->data;
    for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
      r1 = _mm_loadu_pd(&J0_data[i1]);
      r2 = _mm_loadu_pd(&dJ0_data[i1]);
      _mm_storeu_pd(&J0_data[i1],
                    _mm_mul_pd(_mm_set1_pd(a), _mm_add_pd(r1, r2)));
    }
    for (i1 = scalarLB_tmp; i1 < loop_ub_tmp; i1++) {
      J0_data[i1] = a * (J0_data[i1] + dJ0_data[i1]);
    }
    if ((Z1->size[1] != J0->size[1]) &&
        ((Z1->size[1] != 1) && (J0->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Z1->size[1], J0->size[1], &c_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if (Z1->size[1] == J0->size[1]) {
      loop_ub = 6 * Z1->size[1];
      i1 = Z1->size[0] * Z1->size[1];
      Z1->size[0] = 6;
      emxEnsureCapacity_real_T(sp, Z1, i1, &p_emlrtRTEI);
      Z1_data = Z1->data;
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r1 = _mm_loadu_pd(&Z1_data[i1]);
        r2 = _mm_loadu_pd(&J0_data[i1]);
        _mm_storeu_pd(&Z1_data[i1], _mm_add_pd(r1, r2));
      }
      for (i1 = scalarLB; i1 < loop_ub; i1++) {
        Z1_data[i1] += J0_data[i1];
      }
    } else {
      st.site = &cb_emlrtRSI;
      b_plus(&st, Z1, J0);
      Z1_data = Z1->data;
    }
    loop_ub = K2Z2->size[0] * K2Z2->size[1];
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r1 = _mm_loadu_pd(&K2Z2_data[i1]);
      _mm_storeu_pd(&K2Z2_data[i1], _mm_mul_pd(_mm_set1_pd(3.0), r1));
    }
    for (i1 = scalarLB; i1 < loop_ub; i1++) {
      K2Z2_data[i1] *= 3.0;
    }
    if ((K1Z2->size[0] != K2Z2->size[0]) &&
        ((K1Z2->size[0] != 1) && (K2Z2->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(K1Z2->size[0], K2Z2->size[0], &d_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((K1Z2->size[1] != K2Z2->size[1]) &&
        ((K1Z2->size[1] != 1) && (K2Z2->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(K1Z2->size[1], K2Z2->size[1], &e_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((K1Z2->size[0] == K2Z2->size[0]) && (K1Z2->size[1] == K2Z2->size[1])) {
      loop_ub = K1Z2->size[0] * K1Z2->size[1];
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r1 = _mm_loadu_pd(&K1Z2_data[i1]);
        r2 = _mm_loadu_pd(&K2Z2_data[i1]);
        _mm_storeu_pd(&K1Z2_data[i1],
                      _mm_mul_pd(_mm_set1_pd(a), _mm_add_pd(r1, r2)));
      }
      for (i1 = scalarLB; i1 < loop_ub; i1++) {
        K1Z2_data[i1] = a * (K1Z2_data[i1] + K2Z2_data[i1]);
      }
    } else {
      st.site = &bb_emlrtRSI;
      binary_expand_op(&st, K1Z2, a, K2Z2);
      K1Z2_data = K1Z2->data;
    }
    if ((Z2->size[0] != K1Z2->size[0]) &&
        ((Z2->size[0] != 1) && (K1Z2->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Z2->size[0], K1Z2->size[0], &f_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((Z2->size[1] != K1Z2->size[1]) &&
        ((Z2->size[1] != 1) && (K1Z2->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(Z2->size[1], K1Z2->size[1], &g_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((Z2->size[0] == K1Z2->size[0]) && (Z2->size[1] == K1Z2->size[1])) {
      loop_ub = Z2->size[0] * Z2->size[1];
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r1 = _mm_loadu_pd(&Z2_data[i1]);
        r2 = _mm_loadu_pd(&K1Z2_data[i1]);
        _mm_storeu_pd(&Z2_data[i1], _mm_add_pd(r1, r2));
      }
      for (i1 = scalarLB; i1 < loop_ub; i1++) {
        Z2_data[i1] += K1Z2_data[i1];
      }
    } else {
      st.site = &ab_emlrtRSI;
      plus(&st, Z2, K1Z2);
      Z2_data = Z2->data;
    }
    loop_ub = K2Z3->size[0] * K2Z3->size[1];
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      r1 = _mm_loadu_pd(&dJdt_data[i1]);
      _mm_storeu_pd(&dJdt_data[i1], _mm_mul_pd(_mm_set1_pd(3.0), r1));
    }
    for (i1 = scalarLB; i1 < loop_ub; i1++) {
      dJdt_data[i1] *= 3.0;
    }
    if ((K1Z3->size[0] != K2Z3->size[0]) &&
        ((K1Z3->size[0] != 1) && (K2Z3->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(K1Z3->size[0], K2Z3->size[0], &h_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((K1Z3->size[1] != K2Z3->size[1]) &&
        ((K1Z3->size[1] != 1) && (K2Z3->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(K1Z3->size[1], K2Z3->size[1], &i_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((K1Z3->size[0] == K2Z3->size[0]) && (K1Z3->size[1] == K2Z3->size[1])) {
      loop_ub = K1Z3->size[0] * K1Z3->size[1];
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r1 = _mm_loadu_pd(&K1Z3_data[i1]);
        r2 = _mm_loadu_pd(&dJdt_data[i1]);
        _mm_storeu_pd(&K1Z3_data[i1],
                      _mm_mul_pd(_mm_set1_pd(a), _mm_add_pd(r1, r2)));
      }
      for (i1 = scalarLB; i1 < loop_ub; i1++) {
        K1Z3_data[i1] = a * (K1Z3_data[i1] + dJdt_data[i1]);
      }
    } else {
      st.site = &bb_emlrtRSI;
      binary_expand_op(&st, K1Z3, a, K2Z3);
      K1Z3_data = K1Z3->data;
    }
    if ((B->size[0] != K1Z3->size[0]) &&
        ((B->size[0] != 1) && (K1Z3->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(B->size[0], K1Z3->size[0], &j_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((B->size[1] != K1Z3->size[1]) &&
        ((B->size[1] != 1) && (K1Z3->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(B->size[1], K1Z3->size[1], &k_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((B->size[0] == K1Z3->size[0]) && (B->size[1] == K1Z3->size[1])) {
      loop_ub = B->size[0] * B->size[1];
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i1 = 0; i1 <= vectorUB; i1 += 2) {
        r1 = _mm_loadu_pd(&B_data[i1]);
        r2 = _mm_loadu_pd(&K1Z3_data[i1]);
        _mm_storeu_pd(&B_data[i1], _mm_add_pd(r1, r2));
      }
      for (i1 = scalarLB; i1 < loop_ub; i1++) {
        B_data[i1] += K1Z3_data[i1];
      }
    } else {
      st.site = &y_emlrtRSI;
      plus(&st, B, K1Z3);
      B_data = B->data;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &b_Ms);
  emxFree_real_T(sp, &b_Th);
  emxFree_real_T(sp, &K2Z3);
  emxFree_real_T(sp, &K2Z2);
  emxFree_real_T(sp, &K1Z3);
  emxFree_real_T(sp, &K1Z2);
  /*  recover the kinematics entities */
  if (Z1->size[1] < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Z1->size[1], &f_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  p[0] = Z1_data[18];
  p[1] = Z1_data[19];
  p[2] = Z1_data[20];
  for (i = 0; i < 3; i++) {
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &hb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi[3 * i] = Z1_data[6 * i];
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &hb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi[3 * i + 1] = Z1_data[6 * i + 1];
    if (i + 1 > Z1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, Z1->size[1], &hb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Phi[3 * i + 2] = Z1_data[6 * i + 2];
  }
  if ((uint32_T)x->size[0] + 4U < 5U) {
    i = 0;
    i1 = 0;
  } else {
    if (Z1->size[1] < 5) {
      emlrtDynamicBoundsCheckR2012b(5, 1, Z1->size[1], &g_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = 4;
    if (((int32_T)((uint32_T)x->size[0] + 4U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 4U) > Z1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 4U), 1,
                                    Z1->size[1], &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = (int32_T)((uint32_T)x->size[0] + 4U);
  }
  if (((real_T)x->size[0] + 6.0) - 1.0 > d) {
    i2 = 0;
    scalarLB_tmp = 0;
  } else {
    if (((int32_T)((uint32_T)x->size[0] + 5U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 5U) > Z1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 5U), 1,
                                    Z1->size[1], &i_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i2 = x->size[0] + 4;
    if (((int32_T)d < 1) || ((int32_T)d > Z1->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Z1->size[1], &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    scalarLB_tmp = (int32_T)d;
  }
  st.site = &c_emlrtRSI;
  /* --------------------------------------------------------------------------
   */
  for (vectorUB_tmp = 0; vectorUB_tmp < 3; vectorUB_tmp++) {
    Wh[3 * vectorUB_tmp] = Phi[vectorUB_tmp];
    Wh[3 * vectorUB_tmp + 1] = Phi[vectorUB_tmp + 3];
    Wh[3 * vectorUB_tmp + 2] = Phi[vectorUB_tmp + 6];
  }
  /* --------------------------------------------------------------------------
   */
  b_Wh[0] = 0.0;
  b_Wh[3] = -Z1_data[20];
  b_Wh[6] = Z1_data[19];
  b_Wh[1] = Z1_data[20];
  b_Wh[4] = 0.0;
  b_Wh[7] = -Z1_data[18];
  b_Wh[2] = -Z1_data[19];
  b_Wh[5] = Z1_data[18];
  b_Wh[8] = 0.0;
  memset(&b_Mtt_data[0], 0, 36U * sizeof(real_T));
  for (vectorUB_tmp = 0; vectorUB_tmp < 3; vectorUB_tmp++) {
    a = Wh[3 * vectorUB_tmp];
    b_Mtt_data[6 * vectorUB_tmp] = a;
    loop_ub_tmp = 6 * (vectorUB_tmp + 3);
    b_Mtt_data[loop_ub_tmp + 3] = a;
    a = Wh[3 * vectorUB_tmp + 1];
    b_Mtt_data[6 * vectorUB_tmp + 1] = a;
    b_Mtt_data[loop_ub_tmp + 4] = a;
    a = Wh[3 * vectorUB_tmp + 2];
    b_Mtt_data[6 * vectorUB_tmp + 2] = a;
    b_Mtt_data[loop_ub_tmp + 5] = a;
  }
  for (vectorUB_tmp = 0; vectorUB_tmp < 3; vectorUB_tmp++) {
    d = Wh[vectorUB_tmp];
    a = Wh[vectorUB_tmp + 3];
    d2 = Wh[vectorUB_tmp + 6];
    for (loop_ub_tmp = 0; loop_ub_tmp < 3; loop_ub_tmp++) {
      b_Mtt_data[(vectorUB_tmp + 6 * loop_ub_tmp) + 3] =
          (d * b_Wh[loop_ub_tmp] + a * b_Wh[loop_ub_tmp + 3]) +
          d2 * b_Wh[loop_ub_tmp + 6];
    }
  }
  vectorUB_tmp = b_Z1->size[0] * b_Z1->size[1];
  b_Z1->size[0] = 6;
  loop_ub = i1 - i;
  b_Z1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, b_Z1, vectorUB_tmp, &j_emlrtRTEI);
  dJdt_data = b_Z1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (vectorUB_tmp = 0; vectorUB_tmp < 6; vectorUB_tmp++) {
      dJdt_data[vectorUB_tmp + 6 * i1] = Z1_data[vectorUB_tmp + 6 * (i + i1)];
    }
  }
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, b_Mtt_data, b_Z1, J0);
  st.site = &d_emlrtRSI;
  /* --------------------------------------------------------------------------
   */
  memset(&b_Mtt_data[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    a = Wh[3 * i];
    b_Mtt_data[6 * i] = a;
    loop_ub_tmp = 6 * (i + 3);
    b_Mtt_data[loop_ub_tmp + 3] = a;
    a = Wh[3 * i + 1];
    b_Mtt_data[6 * i + 1] = a;
    b_Mtt_data[loop_ub_tmp + 4] = a;
    a = Wh[3 * i + 2];
    b_Mtt_data[6 * i + 2] = a;
    b_Mtt_data[loop_ub_tmp + 5] = a;
  }
  for (i = 0; i < 3; i++) {
    d = Wh[i];
    a = Wh[i + 3];
    d2 = Wh[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_Mtt_data[(i + 6 * i1) + 3] =
          (d * b_Wh[i1] + a * b_Wh[i1 + 3]) + d2 * b_Wh[i1 + 6];
    }
  }
  i = b_Z1->size[0] * b_Z1->size[1];
  b_Z1->size[0] = 6;
  loop_ub = scalarLB_tmp - i2;
  b_Z1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&st, b_Z1, i, &n_emlrtRTEI);
  dJdt_data = b_Z1->data;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      dJdt_data[i1 + 6 * i] = Z1_data[i1 + 6 * (i2 + i)];
    }
  }
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, b_Mtt_data, b_Z1, dJ0);
  dJ0_data = dJ0->data;
  st.site = &e_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  if (dx->size[0] != J0->size[1]) {
    if (dx->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &c_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_mtimes(J0, dx, V);
  /* --------------------------------------------------------------------------
   */
  Wh[0] = 0.0;
  Wh[3] = -V[2];
  Wh[6] = V[1];
  Wh[1] = V[2];
  Wh[4] = 0.0;
  Wh[7] = -V[0];
  Wh[2] = -V[1];
  Wh[5] = V[0];
  Wh[8] = 0.0;
  /* --------------------------------------------------------------------------
   */
  /*  set linear velocity zero -- dJ worldframe  */
  /* --------------------------------------------------------------------------
   */
  b_Wh[0] = 0.0;
  b_Wh[3] = -V[2];
  b_Wh[6] = V[1];
  b_Wh[1] = V[2];
  b_Wh[4] = 0.0;
  b_Wh[7] = -V[0];
  b_Wh[2] = -V[1];
  b_Wh[5] = V[0];
  b_Wh[8] = 0.0;
  /* --------------------------------------------------------------------------
   */
  st.site = &f_emlrtRSI;
  /* --------------------------------------------------------------------------
   */
  memset(&b_Mtt_data[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    a = Phi[3 * i];
    b_Mtt_data[6 * i] = a;
    loop_ub_tmp = 6 * (i + 3);
    b_Mtt_data[loop_ub_tmp + 3] = a;
    a = Phi[3 * i + 1];
    b_Mtt_data[6 * i + 1] = a;
    b_Mtt_data[loop_ub_tmp + 4] = a;
    a = Phi[3 * i + 2];
    b_Mtt_data[6 * i + 2] = a;
    b_Mtt_data[loop_ub_tmp + 5] = a;
  }
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_Mtt_data[(i + 6 * i1) + 3] =
          (0.0 * Phi[3 * i1] + 0.0 * Phi[3 * i1 + 1]) + 0.0 * Phi[3 * i1 + 2];
    }
  }
  __m128d r3;
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, b_Mtt_data, J0, J);
  /*  world-frame Jacobian */
  st.site = &h_emlrtRSI;
  b_Ktt_data[3] = -0.0;
  b_Ktt_data[9] = V[5];
  b_Ktt_data[15] = -V[4];
  b_Ktt_data[4] = -V[5];
  b_Ktt_data[10] = -0.0;
  b_Ktt_data[16] = V[3];
  b_Ktt_data[5] = V[4];
  b_Ktt_data[11] = -V[3];
  b_Ktt_data[17] = -0.0;
  r1 = _mm_loadu_pd(&Wh[0]);
  r2 = _mm_set1_pd(-1.0);
  r1 = _mm_mul_pd(r1, r2);
  _mm_storeu_pd(&b_Ktt_data[0], r1);
  r3 = _mm_set1_pd(-0.0);
  _mm_storeu_pd(&b_Ktt_data[18], r3);
  _mm_storeu_pd(&b_Ktt_data[21], r1);
  b_Ktt_data[2] = V[1];
  b_Ktt_data[20] = -0.0;
  b_Ktt_data[23] = V[1];
  r1 = _mm_loadu_pd(&Wh[3]);
  r1 = _mm_mul_pd(r1, r2);
  _mm_storeu_pd(&b_Ktt_data[6], r1);
  _mm_storeu_pd(&b_Ktt_data[24], r3);
  _mm_storeu_pd(&b_Ktt_data[27], r1);
  b_Ktt_data[8] = -V[0];
  b_Ktt_data[26] = -0.0;
  b_Ktt_data[29] = -V[0];
  r1 = _mm_loadu_pd(&Wh[6]);
  r1 = _mm_mul_pd(r1, r2);
  _mm_storeu_pd(&b_Ktt_data[12], r1);
  _mm_storeu_pd(&b_Ktt_data[30], r3);
  _mm_storeu_pd(&b_Ktt_data[33], r1);
  b_Ktt_data[14] = -0.0;
  b_Ktt_data[32] = -0.0;
  b_Ktt_data[35] = -0.0;
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, b_Ktt_data, J0, r);
  K2Z2_data = r->data;
  if ((r->size[1] != dJ0->size[1]) &&
      ((r->size[1] != 1) && (dJ0->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[1], dJ0->size[1], &l_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  /* --------------------------------------------------------------------------
   */
  memset(&b_Mtt_data[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    a = Phi[3 * i];
    b_Mtt_data[6 * i] = a;
    loop_ub_tmp = 6 * (i + 3);
    b_Mtt_data[loop_ub_tmp + 3] = a;
    a = Phi[3 * i + 1];
    b_Mtt_data[6 * i + 1] = a;
    b_Mtt_data[loop_ub_tmp + 4] = a;
    a = Phi[3 * i + 2];
    b_Mtt_data[6 * i + 2] = a;
    b_Mtt_data[loop_ub_tmp + 5] = a;
  }
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_Mtt_data[(i + 6 * i1) + 3] =
          (0.0 * Phi[3 * i1] + 0.0 * Phi[3 * i1 + 1]) + 0.0 * Phi[3 * i1 + 2];
    }
  }
  st.site = &g_emlrtRSI;
  b_Ktt_data[3] = 0.0;
  b_Ktt_data[9] = -0.0;
  b_Ktt_data[15] = 0.0;
  b_Ktt_data[4] = 0.0;
  b_Ktt_data[10] = 0.0;
  b_Ktt_data[16] = -0.0;
  b_Ktt_data[5] = -0.0;
  b_Ktt_data[11] = 0.0;
  b_Ktt_data[17] = 0.0;
  for (i = 0; i < 3; i++) {
    d = b_Wh[3 * i];
    b_Ktt_data[6 * i] = d;
    loop_ub_tmp = 6 * (i + 3);
    b_Ktt_data[loop_ub_tmp] = 0.0;
    b_Ktt_data[loop_ub_tmp + 3] = d;
    d = b_Wh[3 * i + 1];
    b_Ktt_data[6 * i + 1] = d;
    b_Ktt_data[loop_ub_tmp + 1] = 0.0;
    b_Ktt_data[loop_ub_tmp + 4] = d;
    d = b_Wh[3 * i + 2];
    b_Ktt_data[6 * i + 2] = d;
    b_Ktt_data[loop_ub_tmp + 2] = 0.0;
    b_Ktt_data[loop_ub_tmp + 5] = d;
  }
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += b_Mtt_data[i + 6 * i2] * b_Ktt_data[i2 + 6 * i1];
      }
      b_a[i + 6 * i1] = d;
    }
  }
  b_st.site = &u_emlrtRSI;
  c_mtimes(&b_st, b_a, J0, dJdt);
  emxFree_real_T(&st, &J0);
  st.site = &h_emlrtRSI;
  /* --------------------------------------------------------------------------
   */
  memset(&b_Mtt_data[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    a = Phi[3 * i];
    b_Mtt_data[6 * i] = a;
    loop_ub_tmp = 6 * (i + 3);
    b_Mtt_data[loop_ub_tmp + 3] = a;
    a = Phi[3 * i + 1];
    b_Mtt_data[6 * i + 1] = a;
    b_Mtt_data[loop_ub_tmp + 4] = a;
    a = Phi[3 * i + 2];
    b_Mtt_data[6 * i + 2] = a;
    b_Mtt_data[loop_ub_tmp + 5] = a;
  }
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_Mtt_data[(i + 6 * i1) + 3] =
          (0.0 * Phi[3 * i1] + 0.0 * Phi[3 * i1 + 1]) + 0.0 * Phi[3 * i1 + 2];
    }
  }
  if (r->size[1] == dJ0->size[1]) {
    i = b_Z1->size[0] * b_Z1->size[1];
    b_Z1->size[0] = 6;
    b_Z1->size[1] = r->size[1];
    emxEnsureCapacity_real_T(&st, b_Z1, i, &r_emlrtRTEI);
    dJdt_data = b_Z1->data;
    loop_ub = 6 * r->size[1];
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r1 = _mm_loadu_pd(&K2Z2_data[i]);
      r2 = _mm_loadu_pd(&dJ0_data[i]);
      _mm_storeu_pd(&dJdt_data[i], _mm_add_pd(r1, r2));
    }
    for (i = scalarLB; i < loop_ub; i++) {
      dJdt_data[i] = K2Z2_data[i] + dJ0_data[i];
    }
    b_st.site = &u_emlrtRSI;
    c_mtimes(&b_st, b_Mtt_data, b_Z1, r);
    K2Z2_data = r->data;
  } else {
    b_st.site = &u_emlrtRSI;
    c_binary_expand_op(&b_st, r, u_emlrtRSI, b_Mtt_data, dJ0);
    K2Z2_data = r->data;
  }
  emxFree_real_T(&st, &b_Z1);
  emxFree_real_T(&st, &dJ0);
  if ((dJdt->size[1] != r->size[1]) &&
      ((dJdt->size[1] != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(dJdt->size[1], r->size[1], &m_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (dJdt->size[1] == r->size[1]) {
    loop_ub = 6 * dJdt->size[1];
    i = dJdt->size[0] * dJdt->size[1];
    dJdt->size[0] = 6;
    emxEnsureCapacity_real_T(sp, dJdt, i, &s_emlrtRTEI);
    dJdt_data = dJdt->data;
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r1 = _mm_loadu_pd(&dJdt_data[i]);
      r2 = _mm_loadu_pd(&K2Z2_data[i]);
      _mm_storeu_pd(&dJdt_data[i], _mm_add_pd(r1, r2));
    }
    for (i = scalarLB; i < loop_ub; i++) {
      dJdt_data[i] += K2Z2_data[i];
    }
  } else {
    st.site = &g_emlrtRSI;
    b_plus(&st, dJdt, r);
  }
  emxFree_real_T(sp, &r);
  /*  % world-frame dJacobian/dt */
  /*  recover the dynamics entities */
  if (x->size[0] < 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    if (Z2->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Z2->size[0], &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (x->size[0] > Z2->size[0]) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, Z2->size[0], &l_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = x->size[0];
    if (Z2->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Z2->size[1], &m_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (x->size[0] > Z2->size[1]) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, Z2->size[1], &n_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_loop_ub = x->size[0];
  }
  i = M->size[0] * M->size[1];
  M->size[0] = loop_ub;
  M->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, M, i, &t_emlrtRTEI);
  dJdt_data = M->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      dJdt_data[i1 + M->size[0] * i] = Z2_data[i1 + Z2->size[0] * i];
    }
  }
  if (x->size[0] < 1) {
    loop_ub = 0;
  } else {
    if (Z2->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Z2->size[0], &o_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (x->size[0] > Z2->size[0]) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, Z2->size[0], &p_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = x->size[0];
  }
  u = (uint32_T)x->size[0] << 1;
  if ((uint32_T)x->size[0] + 1U > u) {
    i = 0;
    i1 = 0;
  } else {
    if (((int32_T)((uint32_T)x->size[0] + 1U) < 1) ||
        ((int32_T)((uint32_T)x->size[0] + 1U) > Z2->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)x->size[0] + 1U), 1,
                                    Z2->size[1], &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = x->size[0];
    if (((int32_T)u < 1) || ((int32_T)u > Z2->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, Z2->size[1], &r_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = (int32_T)u;
  }
  i2 = C->size[0] * C->size[1];
  C->size[0] = loop_ub;
  b_loop_ub = i1 - i;
  C->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, C, i2, &u_emlrtRTEI);
  dJdt_data = C->data;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      dJdt_data[i2 + C->size[0] * i1] = Z2_data[i2 + Z2->size[0] * (i + i1)];
    }
  }
  if (x->size[0] < 1) {
    loop_ub = 0;
  } else {
    if (Z2->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Z2->size[0], &s_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (x->size[0] > Z2->size[0]) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, Z2->size[0], &t_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = x->size[0];
  }
  if (u + 1U > d1) {
    i = 0;
    i1 = 0;
  } else {
    if (((int32_T)(u + 1U) < 1) || ((int32_T)(u + 1U) > Z2->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(u + 1U), 1, Z2->size[1],
                                    &u_emlrtBCI, (emlrtConstCTX)sp);
    }
    i = (int32_T)u;
    if (((int32_T)d1 < 1) || ((int32_T)d1 > Z2->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, Z2->size[1], &v_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = (int32_T)d1;
  }
  i2 = K->size[0] * K->size[1];
  K->size[0] = loop_ub;
  b_loop_ub = i1 - i;
  K->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, K, i2, &v_emlrtRTEI);
  dJdt_data = K->data;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      dJdt_data[i2 + K->size[0] * i1] = Z2_data[i2 + Z2->size[0] * (i + i1)];
    }
  }
  if (x->size[0] < 1) {
    loop_ub_tmp = 0;
  } else {
    if (Z2->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Z2->size[0], &w_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (x->size[0] > Z2->size[0]) {
      emlrtDynamicBoundsCheckR2012b(x->size[0], 1, Z2->size[0], &x_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub_tmp = x->size[0];
  }
  if (((int32_T)(d1 + 1.0) < 1) || ((int32_T)(d1 + 1.0) > Z2->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(d1 + 1.0), 1, Z2->size[1],
                                  &y_emlrtBCI, (emlrtConstCTX)sp);
  }
  i1 = G->size[0];
  G->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, G, i1, &w_emlrtRTEI);
  dJdt_data = G->data;
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    dJdt_data[i1] = Z2_data[i1 + Z2->size[0] * ((int32_T)(d1 + 1.0) - 1)];
  }
  if (Z1->size[1] < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Z1->size[1], &ab_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  *Vg = Z1_data[22];
  if (Z1->size[1] < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Z1->size[1], &bb_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  *Kin = Z1_data[23];
  emxFree_real_T(sp, &Z1);
  i1 = R->size[0] * R->size[1];
  R->size[0] = loop_ub;
  R->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, R, i1, &x_emlrtRTEI);
  dJdt_data = R->data;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i2 = 0; i2 <= vectorUB; i2 += 2) {
      r1 = _mm_loadu_pd(&Z2_data[i2 + Z2->size[0] * (i + i1)]);
      _mm_storeu_pd(&dJdt_data[i2 + R->size[0] * i1],
                    _mm_mul_pd(_mm_set1_pd(Zeta), r1));
    }
    for (i2 = scalarLB; i2 < loop_ub; i2++) {
      dJdt_data[i2 + R->size[0] * i1] =
          Zeta * Z2_data[i2 + Z2->size[0] * (i + i1)];
    }
  }
  emxFree_real_T(sp, &Z2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (computeLagrangianFast.c) */
