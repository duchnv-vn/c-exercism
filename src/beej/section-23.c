// ******************************************************
// Pointer III: Pointers to Pointers and More
#include "stdio.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    // Make local variables for src and dest, but of type unsigned char

    const unsigned char *s = src;
    unsigned char *d = dest;

    while (n-- > 0)  // For the given number of bytes
        *d++ = *s++; // Copy source byte to dest byte

    // Most copy functions return a pointer to the dest as a convenience
    // to the caller

    return dest;
}

int add(int a, int b)
{
    return a + b;
}

int print_math(int a, int b, int (*func_p)(int, int))
{
    return printf("Value: %d\n", func_p(a, b));
}

void main(void)
{
    //------------------------------------------------
    // Pointer of pointer
    if (0)
    {
        int x = 3490;
        int *x_p = &x;
        int **x_p_p = &x_p;

        printf("Value x: %d\n", *x_p);    // Value of x
        printf("Value x: %d\n", **x_p_p); // Value of x
        printf("Value x: %d\n", x_p);     // Address of x
        printf("Value x: %d\n", *x_p_p);  // Address of x
        printf("Value x: %d\n", x_p_p);   // Address of pointer of x
    }

    //------------------------------------------------
    // Copy byte to byte
    if (0)
    {
        typedef struct
        {
            int id;
            char *name;
        } Object;

        Object obj1 = {.id = 1, .name = "Object 1"};

        Object obj2;
        my_memcpy(&obj2, &obj1, sizeof(Object));

        printf("Size of Object: %d | Size of char: %d | Size of int: %d\n", sizeof(Object), sizeof(char), sizeof(int));
        printf("Obj2 - Id: %d, name: %s\n", obj2.id, obj2.name);

        obj2.name = "Object 2";

        printf("Obj1 - Id: %d, name: %s\n", obj1.id, obj1.name);

        printf("Obj2 - Id: %d, name: %s\n", obj2.id, obj2.name);

        printf("Size: %d\n", sizeof(0x1));
    }

    //------------------------------------------------
    // Function pointer
    if (1)
    {
        // Declare p to be a pointer to a function.
        // This function returns a int, and takes two ints as arguments.
        int (*add_p)(int, int) = add;
        print_math(5, 9, add_p);
    }
}