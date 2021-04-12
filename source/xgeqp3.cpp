// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "xgeqp3.h"
#include "xzlarfg.h"
#include "xswap.h"
#include "ixamax.h"
#include "xnrm2.h"
#include "sqrt.h"
#include "xzlarf.h"

// Function Definitions

//
// Arguments    : double A[1002]
//                double tau[2]
//                int jpvt[2]
// Return Type  : void
//
void xgeqp3(double A[1002], double tau[2], int jpvt[2])
{
  double work[2];
  double TOL3Z;
  double atmp;
  double vn1[2];
  double vn2[2];
  int pvt;
  int itemp;
  double b_vn2;
  double temp1;
  double temp2;
  jpvt[0] = 1;
  work[0] = 0.0;
  jpvt[1] = 2;
  work[1] = 0.0;
  TOL3Z = 2.2204460492503131E-16;
  b_sqrt(&TOL3Z);
  atmp = xnrm2(A, 1);
  vn1[0] = atmp;
  vn2[0] = atmp;
  atmp = xnrm2(A, 502);
  vn1[1] = atmp;
  vn2[1] = atmp;
  pvt = ixamax(2, vn1, 1) - 1;
  if (pvt + 1 != 1) {
    xswap(A, 1 + 501 * pvt, 1);
    itemp = jpvt[pvt];
    jpvt[pvt] = 1;
    jpvt[0] = itemp;
    vn1[pvt] = vn1[0];
    vn2[pvt] = vn2[0];
  }

  atmp = A[0];
  tau[0] = xzlarfg(501, &atmp, A, 2);
  A[0] = atmp;
  atmp = A[0];
  A[0] = 1.0;
  xzlarf(501, 1, 1, tau[0], A, 502, work);
  A[0] = atmp;
  atmp = vn1[1];
  b_vn2 = vn2[1];
  for (pvt = 2; pvt < 3; pvt++) {
    if (atmp != 0.0) {
      temp1 = std::abs(A[501]) / atmp;
      temp1 = 1.0 - temp1 * temp1;
      if (temp1 < 0.0) {
        temp1 = 0.0;
      }

      temp2 = atmp / b_vn2;
      temp2 = temp1 * (temp2 * temp2);
      if (temp2 <= TOL3Z) {
        atmp = b_xnrm2(500, A, 503);
        b_vn2 = atmp;
      } else {
        b_sqrt(&temp1);
        atmp *= temp1;
      }
    }

    vn1[1] = atmp;
  }

  pvt = ixamax(1, vn1, 2);
  if (pvt + 1 != 2) {
    xswap(A, 1 + 501 * pvt, 502);
    itemp = jpvt[pvt];
    jpvt[pvt] = jpvt[1];
    jpvt[1] = itemp;
  }

  atmp = A[502];
  tau[1] = xzlarfg(500, &atmp, A, 504);
  A[502] = atmp;
}