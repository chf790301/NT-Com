#ifndef _CODER_NTPREDICT_MEX_H
#define _CODER_NTPREDICT_MEX_H

/* Include Files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "_coder_NTPredict_api.h"

/* Function Declarations */
extern void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const
  mxArray *prhs[]);
extern emlrtCTX mexFunctionCreateRootTLS(void);

#endif