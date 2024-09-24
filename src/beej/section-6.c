#include "stdio.h"

#define COUNT 5

void times2(int *a, int len)
{
    printf("----times2-----\n");
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 2);
    printf("---------\n");
}
void times3(int a[], int len)
{
    printf("----times3-----\n");
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 3);
    printf("---------\n");
}
void times4(int a[5], int len)
{
    printf("----times4-----\n");
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 4);
    printf("---------\n");
}

void print_2D_array(int a[][3])
{
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}

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

    int intArr3[COUNT] = {6, [COUNT - 3] = 3, 2, 1};
    int lengthOfIntArr3 = sizeof(intArr3) / sizeof(intArr3[0]);
    // for (int i = 0; i < lengthOfIntArr3; i++)
    // {
    //     printf("%d: %d\n", i, intArr3[i]);
    // }

    int *pointerOfIntArr3 = intArr3;
    // printf("address: %d | value: %d\n", pointerOfIntArr3, *pointerOfIntArr3);

    int x[5] = {11, 22, 33, 44, 55};
    // times2(x, 5);
    // times3(x, 5);
    // times4(x, 5);

    int y[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    print_2D_array(y);
}