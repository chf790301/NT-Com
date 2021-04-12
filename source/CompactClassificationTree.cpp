#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "CompactClassificationTree.h"

// Function Definitions

//
// Arguments    : const double obj_CutVar[37]
//                const double obj_Children[74]
//                const double obj_ClassProb[74]
//                const double obj_CutPoint[37]
//                const double obj_ClassNames[2]
//                const double obj_Cost[4]
//                const double X[500]
// Return Type  : double
//
double c_CompactClassificationTree_pre(const double obj_CutVar[37], const double
  obj_Children[74], const double obj_ClassProb[74], const double obj_CutPoint[37],
  const double obj_ClassNames[2], const double obj_Cost[4], const double X[500])
{
  double m;
  boolean_T exitg1;
  double d1;
  int iidx;
  double unusedU4_idx_0;
  static const signed char pruneList[37] = { 10, 8, 9, 4, 2, 7, 6, 4, 4, 2, 1, 7,
    5, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  m = 1.0;
  exitg1 = false;
  while ((!exitg1) && (m <= 37.0)) {
    iidx = (int)m - 1;
    if ((pruneList[iidx] <= 0) || rtIsNaN(X[(int)obj_CutVar[iidx] - 1])) {
      exitg1 = true;
    } else if (X[(int)obj_CutVar[(int)m - 1] - 1] < obj_CutPoint[(int)m - 1]) {
      m = obj_Children[((int)m - 1) << 1];
    } else {
      m = obj_Children[1 + (((int)m - 1) << 1)];
    }
  }

  d1 = obj_ClassProb[(int)m + 36];
  unusedU4_idx_0 = obj_ClassProb[(int)m - 1] * obj_Cost[0] + d1 * obj_Cost[1];
  m = obj_ClassProb[(int)m - 1] * obj_Cost[2] + d1 * obj_Cost[3];
  if ((unusedU4_idx_0 > m) || (rtIsNaN(unusedU4_idx_0) && (!rtIsNaN(m)))) {
    iidx = 1;
  } else {
    iidx = 0;
  }

  return obj_ClassNames[iidx];
}