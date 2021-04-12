// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "ixamax.h"

// Function Definitions

//
// Arguments    : int n
//                const double x[2]
//                int ix0
// Return Type  : int
//
int ixamax(int n, const double x[2], int ix0)
{
  int idxmax;
  int ix;
  double smax;
  int k;
  double s;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      ix = ix0 - 1;
      smax = std::abs(x[ix0 - 1]);
      for (k = 2; k <= n; k++) {
        ix++;
        s = std::abs(x[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}