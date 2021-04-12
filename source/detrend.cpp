// Include Files
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "detrend.h"
#include "mldivide.h"

// Function Definitions

//
// Arguments    : double x[501]
// Return Type  : void
//
void detrend(double x[501])
{
  int i;
  double a[1002];
  double dv7[2];
  for (i = 0; i < 501; i++) {
    a[i] = ((double)i + 1.0) / 501.0;
    a[501 + i] = 1.0;
  }

  mldivide(a, x, dv7);
  for (i = 0; i < 501; i++) {
    x[i] -= a[i] * dv7[0] + a[i + 501] * dv7[1];
  }
}