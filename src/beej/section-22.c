// ******************************************************
// enum
#include "stdio.h"

enum Numbers
{
    ONE,
    TWO
};

void main(void)
{
    printf("%d - %d\n", ONE, TWO);

    typedef enum
    {
        VALUE_1 = 200,
        VALUE_2 = 90
    } Values;

    Values value1 = VALUE_1;
    if (value1 == VALUE_1)
    {
        printf("This is value 1");
    }
}