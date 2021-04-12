#ifndef XGERC_H
#define XGERC_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "NTPredict_types.h"

// Function Declarations
extern void xgerc(int m, int n, double alpha1, int ix0, const double y[2],
                  double A[1002], int ia0);

#endif