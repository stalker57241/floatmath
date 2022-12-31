#include <floatmath/floatops.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int fmFloatOpAdd(FMFloat a, FMFloat b, FMFloat* p_result) {
    FMFloat a_mul;
    FMFloat b_mul;

    if (a.denominator != b.denominator) {
        // printf("%d dwr %d = %d\n", a.denominator, b.denominator, a.denominator % b.denominator);
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
    // printf("a_r.n(%d) + b_r.n(%d) = %d\n", a_r.numerator, b_r.numerator, a_r.numerator + b_r.numerator);
    p_result->numerator = a_r.numerator + b_r.numerator;
    p_result->denominator = a_r.denominator;

    return FM_ERR_OK;
}
unsigned int fmFloatOpSubstract(FMFloat a, FMFloat b, FMFloat* p_result) {
    FMFloat a_mul;
    FMFloat b_mul;

    if (a.denominator != b.denominator) {
        // printf("%d dwr %d = %d\n", a.denominator, b.denominator, a.denominator % b.denominator);
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
    // printf("a_r.n(%d) + b_r.n(%d) = %d\n", a_r.numerator, b_r.numerator, a_r.numerator + b_r.numerator);
    p_result->numerator = a_r.numerator - b_r.numerator;
    p_result->denominator = a_r.denominator;

    return FM_ERR_OK;
}
unsigned int fmFloatOpMultiply(FMFloat a, FMFloat b, FMFloat* p_result) {
    p_result->numerator = a.numerator * b.numerator;
    p_result->denominator = a.denominator * b.denominator;
    return FM_ERR_OK;
}
unsigned int fmFloatOpDivide(FMFloat a, FMFloat b, FMFloat* p_result) {
    p_result->numerator = a.numerator * b.denominator;
    p_result->denominator = a.denominator * b.numerator;
    return FM_ERR_OK;
}

unsigned int fmFloatOpToMixedNumber(FMFloat a, FMFloat* p_result_float, signed int* pdecimal) {
    if (a.numerator - a.numerator % a.denominator != 0) {
        *pdecimal = a.numerator / a.denominator;
    } else {
        // printf("\npdecimal: %d", 0);
        *pdecimal = 0;
    }
    p_result_float->numerator = a.numerator % a.denominator;
    p_result_float->denominator = a.denominator;
    return FM_ERR_OK;
}

unsigned int fmFloatOpSimplify(FMFloat a, FMFloat* p_result_float) {
    for (int i = min(a.numerator, a.denominator); i > 0; i--) {
        if (a.numerator % i == 0 && a.denominator % i == 0) {
            p_result_float->numerator = a.numerator / i;
            p_result_float->denominator = a.denominator / i;
            return FM_ERR_OK;
        }
    }
    p_result_float->numerator = a.numerator / 1;
    p_result_float->denominator = a.denominator / 1;

    return FM_ERR_CANT_SIMPLIFY;
}

unsigned int fmFloatPrintf(FMFloat fmfloat) {
    printf("%d/%d", fmfloat.numerator, fmfloat.denominator);

    return FM_ERR_OK;
}
