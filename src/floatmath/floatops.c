#include <floatmath/floatops.h>
#include <stdio.h>
#include <stdlib.h>


/** 
 ** Adds FMFloat b to FMFloat a and writes at p_result
*/
unsigned int fmFloatOpAdd(FMFloat a, FMFloat b, FMFloat* p_result) {
    FMFloat a_mul;
    FMFloat b_mul;

    if (a.denominator != b.denominator) {
        if (a.denominator % b.denominator != 0) {
            fmCreateFloat(b.denominator, b.denominator, &a_mul);
            fmCreateFloat(a.denominator, a.denominator, &b_mul);
        }
        if (a.denominator > b.denominator) {
            fmCreateFloat(1, 1, &a_mul);
            fmCreateFloat(a.denominator / b.denominator, a.denominator / b.denominator, &b_mul);
        }
        else if (a.denominator < b.denominator) {
            fmCreateFloat(b.denominator / a.denominator, b.denominator / a.denominator, &a_mul);
            fmCreateFloat(1, 1, &b_mul);
        }
    }
    else {
        fmCreateFloat(1, 1, &a_mul);
        fmCreateFloat(1, 1, &b_mul);
    }
    FMFloat a_r;
    FMFloat b_r;

    fmFloatOpMultiply(a, a_mul, &a_r);
    fmFloatOpMultiply(b, b_mul, &b_r);
    p_result->numerator = a_r.numerator + b_r.numerator;
    p_result->denominator = a_r.denominator;

    return FM_ERR_OK;
}

/** 
 ** Substracts FMFloat b from FMFloat a and writes at p_result
*/
unsigned int fmFloatOpSubstract(FMFloat a, FMFloat b, FMFloat* p_result) {
    FMFloat a_mul;
    FMFloat b_mul;

    if (a.denominator != b.denominator) {
        if (a.denominator % b.denominator != 0) {
            fmCreateFloat(b.denominator, b.denominator, &a_mul);
            fmCreateFloat(a.denominator, a.denominator, &b_mul);
        }
        if (a.denominator > b.denominator) {
            fmCreateFloat(1, 1, &a_mul);
            fmCreateFloat(a.denominator / b.denominator, a.denominator / b.denominator, &b_mul);
        }
        else if (a.denominator < b.denominator) {
            fmCreateFloat(b.denominator / a.denominator, b.denominator / a.denominator, &a_mul);
            fmCreateFloat(1, 1, &b_mul);
        }
    }
    else {
        fmCreateFloat(1, 1, &a_mul);
        fmCreateFloat(1, 1, &b_mul);
    }
    FMFloat a_r;
    FMFloat b_r;

    fmFloatOpMultiply(a, a_mul, &a_r);
    fmFloatOpMultiply(b, b_mul, &b_r);
    p_result->numerator = a_r.numerator - b_r.numerator;
    p_result->denominator = a_r.denominator;

    return FM_ERR_OK;
}
/**
 ** Multiplies FMFloat a with FMFloat b and writes at p_result
*/
unsigned int fmFloatOpMultiply(FMFloat a, FMFloat b, FMFloat* p_result) {
    p_result->numerator = a.numerator * b.numerator;
    p_result->denominator = a.denominator * b.denominator;
    return FM_ERR_OK;
}
/** 
 ** Divides FMFloat a by FMFloat b and writes at p_result
*/
unsigned int fmFloatOpDivide(FMFloat a, FMFloat b, FMFloat* p_result) {
    p_result->numerator = a.numerator * b.denominator;
    p_result->denominator = a.denominator * b.numerator;
    return FM_ERR_OK;
}

/**
 ** Returns right float in p_result_float and decimal number to pdecimal
*/
unsigned int fmFloatOpToMixedNumber(FMFloat a, FMFloat* presult, signed int* pdecimal) {
    if (a.numerator - a.numerator % a.denominator != 0) {
        *pdecimal = a.numerator / a.denominator;
    } else {
        *pdecimal = 0;
    }
    presult->numerator = a.numerator % a.denominator;
    presult->denominator = a.denominator;
    return FM_ERR_OK;
}
/**
 ** simplifies fraction number
*/
unsigned int fmFloatOpSimplify(FMFloat a, FMFloat* presult) {
    for (int i = min(a.numerator, a.denominator); i > 0; i--) {
        if (a.numerator % i == 0 && a.denominator % i == 0) {
            presult->numerator = a.numerator / i;
            presult->denominator = a.denominator / i;
            return FM_ERR_OK;
        }
    }
    presult->numerator = a.numerator / 1;
    presult->denominator = a.denominator / 1;

    return FM_ERR_CANT_SIMPLIFY;
}
/**
 ** Prints float as numerator/denomirator, like fraction
*/
unsigned int fmFloatPrintf(FMFloat fmfloat) {
    printf("%d/%d", fmfloat.numerator, fmfloat.denominator);

    return FM_ERR_OK;
}
