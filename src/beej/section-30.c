// ******************************************************
// Variable-length array

#include <stdio.h>

// void do_something(int count, int v[count]); // With names
// void do_something(int, int v[*]);           // Without names

int print_array(int h, int w, int matrix[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            printf("%2d ", matrix[i][j]);
        printf("\n");
    }
}

void main(void)
{
    int w = 3, h = 5;
    int matrix[h][w];

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            matrix[i][j] = (i + 1) * (j + 2);

    print_array(h, w, matrix);
}