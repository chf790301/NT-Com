/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Aug-2021 13:41:50
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "myNeuralNetworkFunction.h"
#include "myNeuralNetworkFunction_emxAPI.h"
#include "myNeuralNetworkFunction_terminate.h"
#include "myNeuralNetworkFunction_types.h"

/* Function Declarations */
static void argInit_10x100_real_T(double result[1000]);

static emxArray_real_T *argInit_10xUnbounded_real_T(void);

static double argInit_real_T(void);

static void main_myNeuralNetworkFunction(void);

/* Function Definitions */
/*
 * Arguments    : double result[1000]
 * Return Type  : void
 */
static void argInit_10x100_real_T(double result[1000])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 10; idx0++) {
    for (idx1 = 0; idx1 < 100; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + 10 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_10xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(10, 2);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 10; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result->data[idx0 + 10 * idx1] = argInit_real_T();
    }
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_myNeuralNetworkFunction(void)
{
  emxArray_real_T *b_y1;
  emxArray_real_T *x1;
  double xf1_data[2000];
  double dv[1000];
  int xf1_size[2];
  emxInitArray_real_T(&b_y1, 2);
  /* Initialize function 'myNeuralNetworkFunction' input arguments. */
  /* Initialize function input argument 'x1'. */
  x1 = argInit_10xUnbounded_real_T();
  /* Initialize function input argument 'xi1'. */
  /* Call the entry-point 'myNeuralNetworkFunction'. */
  argInit_10x100_real_T(dv);
  myNeuralNetworkFunction(x1, dv, b_y1, xf1_data, xf1_size);
  emxDestroyArray_real_T(b_y1);
  emxDestroyArray_real_T(x1);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_myNeuralNetworkFunction();
  /* Terminate the application.
You do not need to do this more than one time. */
  myNeuralNetworkFunction_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
