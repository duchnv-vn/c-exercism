// ******************************************************
// Array part II
#include <stdio.h>

int func1(int p[const volatile 10])
{
}

int func2(int p[static 4 /* Assume minimum size array is 4 */])
{
}

void main(void)
{
    int *const p;
    int *volatile p2;
    int *const volatile p3;

    /*
    *************** Equivalent initializer ***************
    */
    if (1)
    {
        int a[3][2] = {0};

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 2; col++)
                printf("%d ", a[row][col]);
            printf("\n");
        }
    }
}