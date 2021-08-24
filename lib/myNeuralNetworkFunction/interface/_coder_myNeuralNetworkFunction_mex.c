/*
 * File: _coder_myNeuralNetworkFunction_mex.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Aug-2021 13:41:50
 */

/* Include Files */
#include "_coder_myNeuralNetworkFunction_mex.h"
#include "_coder_myNeuralNetworkFunction_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&myNeuralNetworkFunction_atexit);
  /* Module initialization. */
  myNeuralNetworkFunction_initialize();
  /* Dispatch the entry-point. */
  unsafe_myNeuralNetworkFunction_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  myNeuralNetworkFunction_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[2]
 * Return Type  : void
 */
void unsafe_myNeuralNetworkFunction_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                                int32_T nrhs,
                                                const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        23, "myNeuralNetworkFunction");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "myNeuralNetworkFunction");
  }
  /* Call the function. */
  myNeuralNetworkFunction_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/*
 * File trailer for _coder_myNeuralNetworkFunction_mex.c
 *
 * [EOF]
 */
