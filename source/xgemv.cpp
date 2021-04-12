// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "xgemv.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                const double A[1002]
//                int ia0
//                const double x[1002]
//                int ix0
//                double y[2]
// Return Type  : void
//
void xgemv(int m, int n, const double A[1002], int ia0, const double x[1002],
           int ix0, double y[2])
{
  int iy;
  int i1;
  int iac;
  int ix;
  double c;
  int i2;
  int ia;
  if ((m == 0) || (n == 0)) {
  } else {
    if (0 <= n - 1) {
      memset(&y[0], 0, (unsigned int)(n * (int)sizeof(double)));
    }

    iy = 0;
    i1 = ia0 + 501 * (n - 1);
    for (iac = ia0; iac <= i1; iac += 501) {
      ix = ix0;
      c = 0.0;
      i2 = (iac + m) - 1;
      for (ia = iac; ia <= i2; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}