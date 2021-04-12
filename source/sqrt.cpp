// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "sqrt.h"

// Function Definitions

//
// Arguments    : double *x
// Return Type  : void
//
void b_sqrt(double *x)
{
  *x = std::sqrt(*x);
}