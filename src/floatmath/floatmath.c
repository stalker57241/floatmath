#include <floatmath/floatmath.h>
#include <stdlib.h>

unsigned int /*ERRORCODE*/ fmCreateFloat(signed int numerator, signed int denominator, FMFloat* p_fm_float) {
    p_fm_float->numerator = numerator;
    p_fm_float->denominator = denominator;
    return FM_ERR_OK;
}

// unsigned int /*ERRORCODE*/ fmDestroyFloat(FMFloat* p_fmfloat) {
//     free(p_fmfloat);
//     return FM_ERR_OK;
// }
