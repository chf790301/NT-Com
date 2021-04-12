// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "SeisFilter.h"

// Variable Definitions
static const double dv0[4] = { 0.035373414794919761, 0.10612024438475928,
  0.10612024438475928, 0.035373414794919761 };

static const double dv1[4] = { 1.0, -1.3910511846247351, 0.85664656838125375,
  -0.18260806539716062 };

// Function Definitions

//
// Arguments    : const double Seis[501]
//                double bb[501]
// Return Type  : void
//
void SeisFilter(const double Seis[501], double bb[501])
{
  int k;
  int naxpy;
  int j;
  int bb_tmp;
  double as;
  memset(&bb[0], 0, 501U * sizeof(double));
  for (k = 0; k < 501; k++) {
    if (501 - k < 4) {
      naxpy = 500 - k;
    } else {
      naxpy = 3;
    }

    for (j = 0; j <= naxpy; j++) {
      bb_tmp = k + j;
      bb[bb_tmp] += Seis[k] * dv0[j];
    }

    if (500 - k < 3) {
      naxpy = 499 - k;
    } else {
      naxpy = 2;
    }

    as = -bb[k];
    for (j = 0; j <= naxpy; j++) {
      bb_tmp = (k + j) + 1;
      bb[bb_tmp] += as * dv1[j + 1];
    }
  }
}

//
// Arguments    : const double Seis[500]
//                double bb[500]
// Return Type  : void
//
void b_SeisFilter(const double Seis[500], double bb[500])
{
  int k;
  int naxpy;
  int j;
  int bb_tmp;
  double as;
  memset(&bb[0], 0, 500U * sizeof(double));
  for (k = 0; k < 500; k++) {
    if (500 - k < 4) {
      naxpy = 499 - k;
    } else {
      naxpy = 3;
    }

    for (j = 0; j <= naxpy; j++) {
      bb_tmp = k + j;
      bb[bb_tmp] += Seis[k] * dv0[j];
    }

    if (499 - k < 3) {
      naxpy = 498 - k;
    } else {
      naxpy = 2;
    }

    as = -bb[k];
    for (j = 0; j <= naxpy; j++) {
      bb_tmp = (k + j) + 1;
      bb[bb_tmp] += as * dv1[j + 1];
    }
  }
}