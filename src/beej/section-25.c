// ******************************************************
// Variadic functions

#include <stdio.h>
#include <stdarg.h>

int add(int count, ...)
{
    int total = 0;
    va_list va;

    va_start(va, count);

    for (int i = 0; i < count; i++)
    {
        int num = va_arg(va, int);
        printf("Num: %d\n", num);
        total += num;
    }

    va_end(va);

    return total;
}

void main(void)
{
    printf("Result: %d\n", add(5, 1, 2, 3, 4, 5));
}
