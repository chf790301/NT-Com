// Include Files
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "main.h"
#include "NTPredict_terminate.h"
#include "NTPredict_initialize.h"

// Function Declarations
static void argInit_1x501_real_T(double result[501]);
static double argInit_real_T();
static void main_NTPredict();

// Function Definitions

//
// Arguments    : double result[501]
// Return Type  : void
//
static void argInit_1x501_real_T(double result[501])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 501; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_NTPredict()
{
  double dv6[501];
  double label;

  // Initialize function 'NTPredict' input arguments.
  // Initialize function input argument 'SeisVector'.
  // Call the entry-point 'NTPredict'.
  argInit_1x501_real_T(dv6);
  label = NTPredict(dv6);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  NTPredict_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_NTPredict();

  // Terminate the application.
  // You do not need to do this more than one time.
  NTPredict_terminate();
  return 0;
}