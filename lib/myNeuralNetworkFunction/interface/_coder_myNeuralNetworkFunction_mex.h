/*
 * File: _coder_myNeuralNetworkFunction_mex.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Aug-2021 13:41:50
 */

#ifndef _CODER_MYNEURALNETWORKFUNCTION_MEX_H
#define _CODER_MYNEURALNETWORKFUNCTION_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_myNeuralNetworkFunction_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                                int32_T nrhs,
                                                const mxArray *prhs[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_myNeuralNetworkFunction_mex.h
 *
 * [EOF]
 */
