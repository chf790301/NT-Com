// Include Files
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "treemodel.h"
#include "SeisFilter.h"
#include "Dataprocess.h"

// Function Definitions

//
// PREDICT �˴���ʾ�йش˺�����ժҪ
//    �˴���ʾ��ϸ˵��
// Arguments    : const double SeisVector[501]
// Return Type  : double
//
double NTPredict(const double SeisVector[501])
{
  double dv2[500];
  double dv3[500];
  Dataprocess(SeisVector, dv2);
  b_SeisFilter(dv2, dv3);
  return treemodel(dv3);
}