// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "Dataprocess.h"
#include "diff.h"
#include "SeisFilter.h"
#include "detrend.h"

// Function Definitions

//
// DATAPROCESS �˴���ʾ�йش˺�����ժҪ
//    �˴���ʾ��ϸ˵��
// Arguments    : const double SeisVector[501]
//                double ProcessedSeisVector[500]
// Return Type  : void
//
void Dataprocess(const double SeisVector[501], double ProcessedSeisVector[500])
{
  double dv4[501];
  double dv5[501];
  boolean_T b0;
  int idx;
  int k;
  boolean_T exitg1;
  double xmax;
  double d0;
  double xmin;
  memcpy(&dv4[0], &SeisVector[0], 501U * sizeof(double));
  detrend(dv4);
  SeisFilter(dv4, dv5);
  diff(dv5, ProcessedSeisVector);
  b0 = rtIsNaN(ProcessedSeisVector[0]);
  if (!b0) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 501)) {
      if (!rtIsNaN(ProcessedSeisVector[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    xmax = ProcessedSeisVector[0];
  } else {
    xmax = ProcessedSeisVector[idx - 1];
    idx++;
    for (k = idx; k < 501; k++) {
      d0 = ProcessedSeisVector[k - 1];
      if (xmax < d0) {
        xmax = d0;
      }
    }
  }

  if (!b0) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 501)) {
      if (!rtIsNaN(ProcessedSeisVector[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    xmin = ProcessedSeisVector[0];
  } else {
    xmin = ProcessedSeisVector[idx - 1];
    idx++;
    for (k = idx; k < 501; k++) {
      d0 = ProcessedSeisVector[k - 1];
      if (xmin > d0) {
        xmin = d0;
      }
    }
  }

  xmax -= xmin;
  for (idx = 0; idx < 500; idx++) {
    ProcessedSeisVector[idx] = 2.0 * (ProcessedSeisVector[idx] - xmin) / xmax +
      -1.0;
  }
}