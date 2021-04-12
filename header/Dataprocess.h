#ifndef DATAPROCESS_H
#define DATAPROCESS_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "NTPredict_types.h"

// Function Declarations
extern void Dataprocess(const double SeisVector[501], double
  ProcessedSeisVector[500]);

#endif