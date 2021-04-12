#ifndef _CODER_NTPREDICT_API_H
#define _CODER_NTPREDICT_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_NTPredict_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T NTPredict(real_T SeisVector[501]);
extern void NTPredict_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[1]);
extern void NTPredict_atexit(void);
extern void NTPredict_initialize(void);
extern void NTPredict_terminate(void);
extern void NTPredict_xil_terminate(void);

#endif