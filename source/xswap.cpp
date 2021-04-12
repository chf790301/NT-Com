// Include Files
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "xswap.h"

// Function Definitions

//
// Arguments    : double x[1002]
//                int ix0
//                int iy0
// Return Type  : void
//
void xswap(double x[1002], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 501; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}