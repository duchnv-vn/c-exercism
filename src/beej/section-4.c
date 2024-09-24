#include "stdio.h"

// Prototype
int add(int a, int b);

void main(void)
{
    int result = add(1, 2);
    printf("result = %d\n", result);
}

int add(int a, int b)
{
    return a + b;
}