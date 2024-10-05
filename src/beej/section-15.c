// ******************************************************
// TYPE CONVERSION
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

void main(void)
{
    /*
        Number to string
    */
    {
        char s[10];
        float f = 3.14159;
        snprintf(s, 10, "%f", f);        // OR: sprintf(s, "%f", f);
        printf("String value: %s\n", s); // String value: 3.141590
    }

    /*
        String to number
    */
    {
        int a = atoi("109");
        float b = atof("0.10902");
        long c = atol("99999999");
        long long d = atoll("99999999999999999");

        printf("Number value of %s: %d\n", "109", a);
        printf("Number value of %s: %f\n", "0.10902", b);
        printf("Number value of %s: %ld\n", "99999999", c);
        printf("Number value of %s: %lld\n", "99999999999999999", d);

        // Convert string s, a number in base 10, to an unsigned long int.
        // NULL means we don't care to learn about any error information.
        char *s = "3490";
        unsigned long int x = strtoul(s, NULL, 10);
        printf("%lu\n", x); // 3490

        // Convert string s, a number in base 2, to an unsigned long int.
        char *s2 = "101010";
        unsigned long int x2 = strtoul(s2, NULL, 2);
        printf("%lu\n", x2); // 42

        // Convert string s, a number in base 10, to an unsigned long int.
        char *s3 = "34x90"; // "x" is not a valid digit in base 10!
        char *badchar;
        unsigned long int x3 = strtoul(s3, &badchar, 10);
        // It tries to convert as much as possible, so gets this far:
        printf("%lu\n", x3); // 34
        // Can see the offending bad character because badchar
        printf("Invalid character: %c\n", *badchar); // "x"

        char *badchar2;
        char *s4 = "3590";
        unsigned long int x4 = strtoul(s4, &badchar2, 10);
        if (*badchar2 == '\0')
        {
            printf("Successful conversion of %s: %lu\n", "3590", x4);
        }
        else
        {
            printf("Partial conversion: %lu\n", x4);
            printf("Invalid character: %c\n", *badchar2);
        }
    }

    /*
        Char to number
    */
    {
        char c = '6';
        int x = c;       // x = 54 -> code point for '6'
        int y = c - '0'; // y = 6
    }

    /*
        Integer and float
    */
    {
        int x = 3 + 1.2; // Mixing int and double
                         // 4.2 is converted to int
                         // 4 is stored in x

        float y = 12 * 2; // Mixing float and int
                          // 24 is converted to float
                          // 24.0 is stored in y
    }

    /*
        Void* to any type
    */
    {
        int x = 10;
        void *p = &x; // &x is type int*, but we store it in a void*
        int *q = p;   // p is void*, but we store it in an int*
    }

    /*
        Casting conversion
    */
    {
        int x = 10;
        long int y = (long int)x + 12;

        long x2 = 3490;
        long *p = &x2;
        unsigned char *c = (unsigned char *)p;
        printf("Value of c: %s\n", *c);
    }
}

int compar(const void *elem1, const void *elem2)
{
    if (*((const int *)elem2) > *((const int *)elem1))
        return 1;
    if (*((const int *)elem2) < *((const int *)elem1))
        return -1;
    return 0;
};

int compar2(const void *elem1, const void *elem2)
{
    const int *e1 = elem1;
    const int *e2 = elem2;

    return *e2 - *e1;
}