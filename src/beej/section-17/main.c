// ******************************************************
// MULTI-FILE PROJECT
#include "stdio.h"

/*
    SOLUTION 1:
    When compile, run: gcc -o main.exe main.c functions.c
    To use functions in functions.c file without using #include
 */
// int add(int a, int b); // Prototype

/*
    SOLUTION 2:
    When compile, run: gcc -o main.exe main.c functions.c
    Also need to use #include
*/

/*
    For small projects, can build from .c files directly to .exe file
    For large projects, should build .c files to object files first -> Combine object files to .exe file
*/

#include "functions.h"

void main(void)
{
    int result = add(1, 2);
    printf("Value: %d\n", result);
}
