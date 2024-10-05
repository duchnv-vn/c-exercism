// ******************************************************
// ADVANCED DATA TYPES
#include "stdio.h"
#include "limits.h"
#include "float.h"

void main(void)
{
    printf("Size of char: %d\n", sizeof(char));           // 1 bytes
    printf("Size of short: %d\n", sizeof(short));         // 2 bytes
    printf("Size of int: %d\n", sizeof(int));             // 4 bytes
    printf("Size of long: %d\n", sizeof(long));           // 4 bytes
    printf("Size of long long: %d\n", sizeof(long long)); // 8 bytes

    printf("System's char type: %d\n", CHAR_MAX == UCHAR_MAX); // False

    printf("Decimal digits can store in float type: %d\n", FLT_DIG);        // 6
    printf("Decimal digits can store in double type: %d\n", DBL_DIG);       // 15
    printf("Decimal digits can store in long double type: %d\n", LDBL_DIG); // 18

    float f = 3.14159f;
    float g = 0.00000265358f;
    printf("%.5f\n", f);  // 3.14159       -- correct!
    printf("%.11f\n", g); // 0.00000265358 -- correct!

    f += g;               // 3.14159265358 is what f _should_ be
    printf("%.11f\n", f); // 3.14159274101 -- wrong!

    printf("Decimal digits encoded in float type: %d\n", FLT_DECIMAL_DIG);   // 9
    printf("Decimal digits encoded in double type: %d\n", DBL_DECIMAL_DIG);  // 17
    printf("Decimal digits encoded in long double type: %d\n", DECIMAL_DIG); // 21

    double x = 0.12345678901234500;
    double y = 0.00000000000000060;
}