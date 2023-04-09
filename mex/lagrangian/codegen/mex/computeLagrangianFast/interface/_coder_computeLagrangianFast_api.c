/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_computeLagrangianFast_api.c
 *
 * Code generation for function '_coder_computeLagrangianFast_api'
 *
 */

/* Include files */
#include "_coder_computeLagrangianFast_api.h"
#include "computeLagrangianFast.h"
#include "computeLagrangianFast_data.h"
#include "computeLagrangianFast_emxutil.h"
#include "computeLagrangianFast_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo ac_emlrtRTEI = {
    1,                                  /* lineNo */
    1,                                  /* colNo */
    "_coder_computeLagrangianFast_api", /* fName */
    ""                                  /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ds,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u[3]);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const real_T u[9]);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *p0,
                                   const char_T *identifier))[3];

static const mxArray *e_emlrt_marshallOut(const real_T u);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Phi0,
                                   const char_T *identifier))[9];

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9];

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *xia0,
                               const char_T *identifier, emxArray_real_T *y);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Th,
                               const char_T *identifier, emxArray_real_T *y);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ba,
                               const char_T *identifier, emxArray_real_T *y);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ktt,
                               const char_T *identifier, emxArray_real_T *y);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9];

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ds,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(ds), &thisId);
  emlrtDestroyArray(&ds);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T i = 0;
  static const int32_T i1 = 3;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const real_T u[9])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {3, 3};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *p0,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(p0), &thisId);
  emlrtDestroyArray(&p0);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
  emlrtDestroyArray(&x);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Phi0,
                                   const char_T *identifier))[9]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[9];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(Phi0), &thisId);
  emlrtDestroyArray(&Phi0);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9]
{
  real_T(*y)[9];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *xia0,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(xia0), &thisId, y);
  emlrtDestroyArray(&xia0);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Th,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(Th), &thisId, y);
  emlrtDestroyArray(&Th);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ba,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(Ba), &thisId, y);
  emlrtDestroyArray(&Ba);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ktt,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  p_emlrt_marshallIn(sp, emlrtAlias(Ktt), &thisId, y);
  emlrtDestroyArray(&Ktt);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims = 3;
  real_T(*ret)[3];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9]
{
  static const int32_T dims[2] = {3, 3};
  real_T(*ret)[9];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[3] = {6, 1, -1};
  int32_T iv[3];
  int32_T i;
  boolean_T bv[3] = {false, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1] * iv[2];
  i = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  ret->size[2] = iv[2];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[3] = {-1, -1, -1};
  int32_T iv[3];
  int32_T i;
  boolean_T bv[3] = {true, true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1] * iv[2];
  i = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  ret->size[2] = iv[2];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {6, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[3] = {6, 6, -1};
  int32_T iv[3];
  int32_T i;
  boolean_T bv[3] = {false, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1] * iv[2];
  i = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  ret->size[2] = iv[2];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void computeLagrangianFast_api(const mxArray *const prhs[13], int32_T nlhs,
                               const mxArray *plhs[12])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *B;
  emxArray_real_T *Ba;
  emxArray_real_T *C;
  emxArray_real_T *G;
  emxArray_real_T *J;
  emxArray_real_T *K;
  emxArray_real_T *Ktt;
  emxArray_real_T *M;
  emxArray_real_T *Ms;
  emxArray_real_T *Mtt;
  emxArray_real_T *R;
  emxArray_real_T *Th;
  emxArray_real_T *dJdt;
  emxArray_real_T *dx;
  emxArray_real_T *x;
  emxArray_real_T *xia0;
  real_T(*Phi)[9];
  real_T(*Phi0)[9];
  real_T(*Gvec)[3];
  real_T(*p)[3];
  real_T(*p0)[3];
  real_T Kin;
  real_T Vg;
  real_T Zeta;
  real_T ds;
  st.tls = emlrtRootTLSGlobal;
  p = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  Phi = (real_T(*)[9])mxMalloc(sizeof(real_T[9]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInit_real_T(&st, &x, 1, &ac_emlrtRTEI);
  x->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x", x);
  emxInit_real_T(&st, &dx, 1, &ac_emlrtRTEI);
  dx->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "dx", dx);
  ds = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "ds");
  p0 = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "p0");
  Phi0 = g_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "Phi0");
  emxInit_real_T(&st, &xia0, 3, &ac_emlrtRTEI);
  xia0->canFreeData = false;
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "xia0", xia0);
  emxInit_real_T(&st, &Th, 3, &ac_emlrtRTEI);
  Th->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "Th", Th);
  emxInit_real_T(&st, &Ms, 3, &ac_emlrtRTEI);
  Ms->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "Ms", Ms);
  emxInit_real_T(&st, &Ba, 2, &ac_emlrtRTEI);
  Ba->canFreeData = false;
  m_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "Ba", Ba);
  emxInit_real_T(&st, &Ktt, 3, &ac_emlrtRTEI);
  Ktt->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "Ktt", Ktt);
  emxInit_real_T(&st, &Mtt, 3, &ac_emlrtRTEI);
  Mtt->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "Mtt", Mtt);
  Zeta = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "Zeta");
  Gvec = e_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "Gvec");
  /* Invoke the target function */
  emxInit_real_T(&st, &M, 2, &ac_emlrtRTEI);
  emxInit_real_T(&st, &C, 2, &ac_emlrtRTEI);
  emxInit_real_T(&st, &K, 2, &ac_emlrtRTEI);
  emxInit_real_T(&st, &R, 2, &ac_emlrtRTEI);
  emxInit_real_T(&st, &G, 1, &ac_emlrtRTEI);
  emxInit_real_T(&st, &B, 2, &ac_emlrtRTEI);
  emxInit_real_T(&st, &J, 2, &ac_emlrtRTEI);
  emxInit_real_T(&st, &dJdt, 2, &ac_emlrtRTEI);
  computeLagrangianFast(&st, x, dx, ds, *p0, *Phi0, xia0, Th, Ms, Ba, Ktt, Mtt,
                        Zeta, *Gvec, M, C, K, R, G, B, *p, *Phi, J, dJdt, &Vg,
                        &Kin);
  emxFree_real_T(&st, &Mtt);
  emxFree_real_T(&st, &Ktt);
  emxFree_real_T(&st, &Ba);
  emxFree_real_T(&st, &Ms);
  emxFree_real_T(&st, &Th);
  emxFree_real_T(&st, &xia0);
  emxFree_real_T(&st, &dx);
  emxFree_real_T(&st, &x);
  /* Marshall function outputs */
  M->canFreeData = false;
  plhs[0] = emlrt_marshallOut(M);
  emxFree_real_T(&st, &M);
  if (nlhs > 1) {
    C->canFreeData = false;
    plhs[1] = emlrt_marshallOut(C);
  }
  emxFree_real_T(&st, &C);
  if (nlhs > 2) {
    K->canFreeData = false;
    plhs[2] = emlrt_marshallOut(K);
  }
  emxFree_real_T(&st, &K);
  if (nlhs > 3) {
    R->canFreeData = false;
    plhs[3] = emlrt_marshallOut(R);
  }
  emxFree_real_T(&st, &R);
  if (nlhs > 4) {
    G->canFreeData = false;
    plhs[4] = b_emlrt_marshallOut(G);
  }
  emxFree_real_T(&st, &G);
  if (nlhs > 5) {
    B->canFreeData = false;
    plhs[5] = emlrt_marshallOut(B);
  }
  emxFree_real_T(&st, &B);
  if (nlhs > 6) {
    plhs[6] = c_emlrt_marshallOut(*p);
  }
  if (nlhs > 7) {
    plhs[7] = d_emlrt_marshallOut(*Phi);
  }
  if (nlhs > 8) {
    J->canFreeData = false;
    plhs[8] = emlrt_marshallOut(J);
  }
  emxFree_real_T(&st, &J);
  if (nlhs > 9) {
    dJdt->canFreeData = false;
    plhs[9] = emlrt_marshallOut(dJdt);
  }
  emxFree_real_T(&st, &dJdt);
  if (nlhs > 10) {
    plhs[10] = e_emlrt_marshallOut(Vg);
  }
  if (nlhs > 11) {
    plhs[11] = e_emlrt_marshallOut(Kin);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_computeLagrangianFast_api.c) */
