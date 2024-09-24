#include "stdio.h"
#include "math.h"

void powerByTwo(int *p)
{
    *p = pow(*p, 2);
}

void main(void)
{
    int num1 = 2;

    /*
        pointer/address of num1
        type of pointer and num1 must be same
     */
    int *num1Pointer = &num1;
    // printf("pointer: %d\n", num1Pointer);

    int num2 = (*num1Pointer) * 3; // Access num1 address to get value
    // printf("num2 value: %d\n", num2);

    powerByTwo(num1Pointer);
    // printf("num1 value: %d\n", num1);

    int *p;
    // printf("%zu\n", sizeof(int)); // 4
    // printf("%zu\n", sizeof p);    // 8
    // printf("%zu\n", sizeof *p);   // 4
}