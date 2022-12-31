#ifndef FLOATMATH_H
#define FLOATMATH_H

#define FM_ERR_OK 0
#define FM_ERR_CANT_SIMPLIFY 1


typedef struct sFMFloat {
    signed int numerator;
    signed int denominator;
} FMFloat;


unsigned int /*ERRORCODE*/ fmCreateFloat(signed int numerator, signed int denominator, FMFloat* p_fm_float);
unsigned int /*ERRORCODE*/ fmDestroyFloat(FMFloat* p_fmfloat);

#endif
