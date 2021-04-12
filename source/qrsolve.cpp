// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "qrsolve.h"

// Function Definitions

//
// Arguments    : const double A[1002]
// Return Type  : int
//
int rankFromQR(const double A[1002])
{
  int r;
  double tol;
  r = 0;
  tol = 1.1124434706744069E-12 * std::abs(A[0]);
  while ((r < 2) && (!(std::abs(A[r + 501 * r]) <= tol))) {
    r++;
  }

  return r;
}