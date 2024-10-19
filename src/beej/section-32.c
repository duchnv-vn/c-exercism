// ******************************************************
// Compound Literals and Generic Selections

#include <stdio.h>

#define TYPESTR(x) _Generic((x), \
    int: "int",                  \
    long: "long",                \
    float: "float",              \
    double: "double",            \
    default: "something else")

#define FMTSPEC(x) _Generic((x), \
    int: "%d",                   \
    long: "%ld",                 \
    float: "%f",                 \
    double: "%f",                \
    char *: "%s")

// Macro that prints a variable in the form "name = value"
#define PRINT_VAL(x)                                         \
    {                                                        \
        char fmt[512];                                       \
        snprintf(fmt, sizeof fmt, #x " = %s\n", FMTSPEC(x)); \
        printf(fmt, (x));                                    \
    }

int sum(int p[], int count)
{
    int total = 0;

    for (int i = 0; i < count; i++)
        total += p[i];

    return total;
}

struct coord
{
    int x, y;
};
void print_coord(struct coord c)
{
    printf("%d, %d\n", c.x, c.y);
}
void print_coord_by_pointer(struct coord *c)
{
    printf("%d, %d\n", c->x, c->y);
}

void main(void)
{
    //------------------------------------------------
    // Unnamed array & struct
    if (0)
    {
        int a[] = {1, 2, 3, 4};
        int s = sum(a, 4);
        sum((int[]){2, 3, 4, 5}, 4);

        print_coord((struct coord){.x = 10, .y = 100});
        print_coord_by_pointer(&(struct coord){.x = 9, .y = 99});
    }

    //------------------------------------------------
    // Generic Selections by type
    if (1)
    {
        int i;
        float f;
        char c;

        char *s = _Generic(i,
            int: "that variable is an int",
            float: "that variable is a float",
            default: "that variable is some type");

        char *s2 = _Generic(f,
            int: "that variable is an int",
            float: "that variable is a float",
            default: "that variable is some type");

        printf("S: %s\n", s);
        printf("S2: %s\n", s2);

        int i2;
        long l2;
        float f2;
        double d2;
        char c2;

        printf("i is type %s\n", TYPESTR(i2));
        printf("l is type %s\n", TYPESTR(l2));
        printf("f is type %s\n", TYPESTR(f2));
        printf("d is type %s\n", TYPESTR(d2));
        printf("c is type %s\n", TYPESTR(c2));

        int i3 = 10;
        float f3 = 3.14159;
        char *s3 = "Hello, world!";

        PRINT_VAL(i3);
        PRINT_VAL(f3);
        PRINT_VAL(s3);
    }
}