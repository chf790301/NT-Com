#ifndef XGEMV_H
#define XGEMV_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "NTPredict_types.h"

// Function Declarations
extern void xgemv(int m, int n, const double A[1002], int ia0, const double x
                  [1002], int ix0, double y[2]);

#endif