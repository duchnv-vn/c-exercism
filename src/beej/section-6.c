#include "stdio.h"

#define COUNT 5

void main(void)
{
    int intArr1[5];
    intArr1[1] = 100;
    intArr1[3] = 399;
    int lengthOfIntArr1 = sizeof(intArr1) / sizeof(intArr1[0]); // 5
    // for (int i = 0; i < lengthOfIntArr1; i++)
    // {
    //     printf("%d: %d\n", i, intArr1[i]);
    // }

    int intArr2[5] = {11, 47, 96};
    int lengthOfIntArr2 = sizeof(intArr2) / sizeof(intArr2[0]); // 5
    // for (int i = 0; i < lengthOfIntArr2; i++)
    // {
    //     printf("%d: %d\n", i, intArr2[i]);
    // }

    char characters[5];
    int lengthOfString = sizeof characters;
    // printf("length of string: %d\n", lengthOfString); // 5

    int intArr3[COUNT] = {[COUNT - 3] = 3, 2, 1};
    int lengthOfIntArr3 = sizeof(intArr3) / sizeof(intArr3[0]);
    for (int i = 0; i < lengthOfIntArr3; i++)
    {
        printf("%d: %d\n", i, intArr3[i]);
    }
}