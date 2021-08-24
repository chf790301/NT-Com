/*
 * File: _coder_myNeuralNetworkFunction_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Aug-2021 13:41:50
 */

#ifndef _CODER_MYNEURALNETWORKFUNCTION_API_H
#define _CODER_MYNEURALNETWORKFUNCTION_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void myNeuralNetworkFunction(emxArray_real_T *x1, real_T xi1[1000],
                             emxArray_real_T *b_y1, real_T xf1_data[],
                             int32_T xf1_size[2]);

void myNeuralNetworkFunction_api(const mxArray *const prhs[2], int32_T nlhs,
                                 const mxArray *plhs[2]);

void myNeuralNetworkFunction_atexit(void);

void myNeuralNetworkFunction_initialize(void);

void myNeuralNetworkFunction_terminate(void);

void myNeuralNetworkFunction_xil_shutdown(void);

void myNeuralNetworkFunction_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_myNeuralNetworkFunction_api.h
 *
 * [EOF]
 */
