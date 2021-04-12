#ifndef XZLARF_H
#define XZLARF_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "NTPredict_types.h"

// Function Declarations
extern void xzlarf(int m, int n, int iv0, double tau, double C[1002], int ic0,
                   double work[2]);

#endif