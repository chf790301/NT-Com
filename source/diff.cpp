// Include Files
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "diff.h"

// Function Definitions

//
// Arguments    : const double x[501]
//                double y[500]
// Return Type  : void
//
void diff(const double x[501], double y[500])
{
  int ixLead;
  int iyLead;
  double work;
  int m;
  double tmp2;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 500; m++) {
    tmp2 = work;
    work = x[ixLead];
    y[iyLead] = x[ixLead] - tmp2;
    ixLead++;
    iyLead++;
  }
}