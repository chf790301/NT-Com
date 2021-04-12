#ifndef NTPREDICT_TYPES_H
#define NTPREDICT_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
typedef struct {
  double CutVar[37];
  double Children[74];
  double ClassProb[74];
  double CutPoint[37];
  double ClassNames[2];
  int ClassNamesLength[2];
  double Prior[2];
  double Cost[4];
} c_classreg_learning_coder_class;

#endif