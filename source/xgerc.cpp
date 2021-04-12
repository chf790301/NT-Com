// Include Files
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "xgerc.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                double alpha1
//                int ix0
//                const double y[2]
//                double A[1002]
//                int ia0
// Return Type  : void
//
void xgerc(int m, int n, double alpha1, int ix0, const double y[2], double A
           [1002], int ia0)
{
  int jA;
  int jy;
  int j;
  double temp;
  int ix;
  int i3;
  int i4;
  int ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        i3 = jA + 1;
        i4 = m + jA;
        for (ijA = i3; ijA <= i4; ijA++) {
          A[ijA - 1] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 501;
    }
  }
}