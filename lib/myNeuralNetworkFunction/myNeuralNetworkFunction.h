#ifndef MYNEURALNETWORKFUNCTION_H
#define MYNEURALNETWORKFUNCTION_H

/* Include Files */
#include "myNeuralNetworkFunction_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void myNeuralNetworkFunction(const emxArray_real_T *x1,
                                    const double xi1[1000],
                                    emxArray_real_T *b_y1, double xf1_data[],
                                    int xf1_size[2]);

#ifdef __cplusplus
}
#endif

#endif
