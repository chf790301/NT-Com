#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "NTPredict_types.h"

// Function Declarations
extern double c_CompactClassificationTree_pre(const double obj_CutVar[37], const
  double obj_Children[74], const double obj_ClassProb[74], const double
  obj_CutPoint[37], const double obj_ClassNames[2], const double obj_Cost[4],
  const double X[500]);

#endif