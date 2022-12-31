#include "floatmath/floatmath.h"
#include "floatmath/floatops.h"
#include <stdio.h>


int main(int argc, char** argv) {
    FMFloat a;
    FMFloat b;
    FMFloat c;

    fmCreateFloat(17, 10, &a);
    fmCreateFloat(14, 10, &b);

    fmFloatOpDivide(a, b, &c);

    printf("a: ");
    fmFloatPrintf(a);
    printf("\t\t/\nb: ");
    fmFloatPrintf(b);

    signed int dec = 0;

    fmFloatOpToMixedNumber(c, &c, &dec);
    fmFloatOpSimplify(c, &c);

    printf("\t\t=\nc: %d", dec);

    if (c.numerator > 0) {
        printf(" + ");
        fmFloatPrintf(c);
    }
    printf("\n");

    return 0;
}