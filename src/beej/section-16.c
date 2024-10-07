// ******************************************************
// QUALIFIERS & SPECIFIERS
#include "stdio.h"
// #include "section-16-2.c"

void swap(int *restrict a, int *restrict b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
};

void counter(void)
{
    static int i;
    printf("This has been called %d time(s)\n", ++i);
}

static void canBeSeenByOtherFiles()
{
    // do something...
}

void main(void)
{
    /*
    *************** Const ***************
    */
    {
        const int immutableVar1 = 1; // Can't modify value

        char *const text = "Hello World!"; // Can't modify string value
        // char **p = 1;
        // p++;    // OK!
        // (*p)++; // OK!

        // char **const p2;
        // // p2++;    // Error!
        // // (*p2)++; // OK!

        // char *const *p3;
        // p3++; // OK!
        // // (*p3)++; // Error!

        // char *const *const p4;
        // // p4++;    // Error!
        // // (*p4)++; // Error!

        int x[2] = {1, 2};
        const int *xPointer = x;        // Can't modify [x] value, but can modify [xPointer] value
        int *const xPointer2 = x;       // Can't modify [xPointer2] value, but can modify [x] value
        const int *const xPointer3 = x; // Can't modify both [xPointer3] and [x] value
    }

    /*
    *************** Restrict ***************
    */
    {

        int x = 1;
        int y = 2;
        swap(&x, &y); // OK
        swap(&x, &x); // May cause Error
    }

    /*
    *************** Volatile ***************
    */
    {
        volatile int *p;
    }

    /*
    *************** Static: block scope ***************
    */
    {
        counter(); // i = 1
        counter(); // i = 2
        counter(); // i = 3
    }
    // Static variables in file scope means invisible from other file scopes

    /*
    *************** Extern ***************
    */
    {
        extern int publicVar; // can access
        printf("publicVar value: %d\n", publicVar);
        // extern int privateVar; // can't access due to static specifier
        // printf("privateVar value: %d\n", privateVar);
    }
}
