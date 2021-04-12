// Include Files
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "treemodel.h"
#include "CompactClassificationTree.h"
#include "CompactTree.h"

// Function Definitions

//
// TREEMODEL �˴���ʾ�йش˺�����ժҪ
//    �˴���ʾ��ϸ˵��
// Arguments    : const double input[500]
// Return Type  : double
//
double treemodel(const double input[500])
{
  c_classreg_learning_coder_class model;
  model.ClassNames[0] = 0.0;
  model.ClassNamesLength[0] = 1;
  model.ClassNames[1] = 1.0;
  model.ClassNamesLength[1] = 1;
  CompactTree_CompactTree(&model);
  model.Cost[0] = 0.0;
  model.Cost[1] = 1.0;
  model.Cost[2] = 1.0;
  model.Cost[3] = 0.0;
  return c_CompactClassificationTree_pre(model.CutVar, model.Children,
    model.ClassProb, model.CutPoint, model.ClassNames, model.Cost, input);
}