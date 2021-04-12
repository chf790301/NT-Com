// Include Files
#include "rt_nonfinite.h"
#include "NTPredict.h"
#include "NTPredict_initialize.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void NTPredict_initialize()
{
  rt_InitInfAndNaN(8U);
}