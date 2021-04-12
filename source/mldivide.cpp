// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "mldivide.h"
#include "qrsolve.h"
#include "xgeqp3.h"

// Function Definitions

//
// Arguments    : const double A[1002]
//                const double B[501]
//                double Y[2]
// Return Type  : void
//
void mldivide(const double A[1002], const double B[501], double Y[2])
{
  double b_A[1002];
  double tau[2];
  int jpvt[2];
  int rankA;
  double b_B[501];
  double wj;
  int i;
  int j;
  int Y_tmp;
  int b_Y_tmp;
  memcpy(&b_A[0], &A[0], 1002U * sizeof(double));
  xgeqp3(b_A, tau, jpvt);
  rankA = rankFromQR(b_A);
  memcpy(&b_B[0], &B[0], 501U * sizeof(double));
  Y[0] = 0.0;
  if (tau[0] != 0.0) {
    wj = b_B[0];
    for (i = 2; i < 502; i++) {
      wj += b_A[i - 1] * b_B[i - 1];
    }

    wj *= tau[0];
    if (wj != 0.0) {
      b_B[0] -= wj;
      for (i = 2; i < 502; i++) {
        b_B[i - 1] -= b_A[i - 1] * wj;
      }
    }
  }

  Y[1] = 0.0;
  if (tau[1] != 0.0) {
    wj = b_B[1];
    for (i = 3; i < 502; i++) {
      wj += b_A[i + 500] * b_B[i - 1];
    }

    wj *= tau[1];
    if (wj != 0.0) {
      b_B[1] -= wj;
      for (i = 3; i < 502; i++) {
        b_B[i - 1] -= b_A[i + 500] * wj;
      }
    }
  }

  for (i = 0; i < rankA; i++) {
    Y[jpvt[i] - 1] = b_B[i];
  }

  for (j = rankA; j >= 1; j--) {
    Y_tmp = jpvt[j - 1] - 1;
    b_Y_tmp = 501 * (j - 1);
    Y[Y_tmp] /= b_A[(j + b_Y_tmp) - 1];
    for (i = 0; i <= j - 2; i++) {
      Y[jpvt[i] - 1] -= Y[Y_tmp] * b_A[i + b_Y_tmp];
    }
  }
}