#ifndef SEISFILTER_H
#define SEISFILTER_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "NTPredict_types.h"

// Function Declarations
extern void SeisFilter(const double Seis[501], double bb[501]);
extern void b_SeisFilter(const double Seis[500], double bb[500]);

#endif