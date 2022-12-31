#ifndef FLOATOPS_H
#define FLOATOPS_H

#include "floatmath.h"

unsigned int fmFloatOpAdd(FMFloat a, FMFloat b, FMFloat* p_result);
unsigned int fmFloatOpSubstract(FMFloat a, FMFloat b, FMFloat* p_result);
unsigned int fmFloatOpMultiply(FMFloat a, FMFloat b, FMFloat* p_result);
unsigned int fmFloatOpDivide(FMFloat a, FMFloat b, FMFloat* p_result);

unsigned int fmFloatOpToMixedNumber(FMFloat a, FMFloat* p_result_float, signed int* pdecimal);
unsigned int fmFloatOpSimplify(FMFloat a, FMFloat* p_result_float);

unsigned int fmFloatPrintf(FMFloat fmfloat);


#endif
