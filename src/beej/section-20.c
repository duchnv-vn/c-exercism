// ******************************************************
// struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "stdbool.h"

#define MAX_PASSENGERS 8
#define ANTELOPE 1
#define OCTOPUS 2

typedef struct
{
    int length;
    char data[]; // must be placed in last position of struct
} FlexString;
FlexString *create_string_from(char *s)
{
    int len = strlen(s);

    // Allocate "len" more bytes than we'd normally need
    FlexString *ls = malloc(sizeof(FlexString) + len);

    ls->length = len;

    // Copy the string into those extra bytes
    memcpy(ls->data, s, len);

    return ls;
}

struct parent
{
    int a, b;
};

struct child
{
    struct parent super; // MUST be first
    int c, d;
};
void print_parent(void *p)
{
    struct parent *self = p;

    printf("Parent: %d, %d\n", self->a, self->b);
}
void print_child(struct child *self)
{
    printf("Child: %d, %d\n", self->c, self->d);
}

struct common
{
    int type; // common initial sequence
};
struct antelope
{
    int type; // common initial sequence

    int loudness;
};
struct octopus
{
    int type; // common initial sequence

    int sea_creature;
    float intelligence;
};
union animal
{
    struct common common;
    struct antelope antelope;
    struct octopus octopus;
};
void print_animal(union animal *x)
{
    switch (x->common.type)
    {
    case ANTELOPE:
        printf("Antelope: loudness=%d\n", x->antelope.loudness);
        break;

    case OCTOPUS:
        printf("Octopus : sea_creature=%d\n", x->octopus.sea_creature);
        printf("          intelligence=%f\n", x->octopus.intelligence);
        break;

    default:
        printf("Unknown animal type\n");
    }
}

struct foo3
{
    int id;
    char name[10];
};
struct foo3 pass_and_return_struct(struct foo3 data)
{
    data.id = 100;
    strcpy(data.name, "Duc");
    return data;
}

void main(void)
{
    // ----------------------------------
    // Nested struct
    if (0)
    {
        typedef struct
        {
            int window_count;
            int o2level;
        } Cabin_information;

        typedef struct
        {
            char *name;
            int covid_vaccinated; // Boolean
        } Passenger;

        typedef struct
        {
            char *manufacturer;
            Cabin_information ci;
            Passenger passengers[MAX_PASSENGERS];
        } Spaceship;

        Spaceship sp1 = {
            .manufacturer = "NASA",
            .ci.window_count = 100,
            .ci.o2level = 21,
            .passengers = {
                [0] = {
                    .name = "AAA",
                    .covid_vaccinated = 0,
                },
            },
        };

        Spaceship sp2 = {
            .manufacturer = "SpaceX",
            .ci = {
                .window_count = 10,
                .o2level = 20,
            },
        };
    }

    // ----------------------------------
    // Self-referential struct
    if (0)
    {
        struct Node
        {
            int data;
            struct Node *next;
        };

        struct Node *head;

        head = malloc(sizeof(struct Node));
        head->data = 1;
        head->next = malloc(sizeof(struct Node));
        head->next->data = 2;
        head->next->next = malloc(sizeof(struct Node));
        head->next->next->data = 3;
        head->next->next->next = NULL;

        for (struct Node *cur = head; cur != NULL; cur = cur->next)
        {
            printf("%d\n", cur->data);
        }

        free(head);
    }

    // ----------------------------------
    // Flexible array member
    if (0)
    {
        FlexString *text1 = malloc(sizeof(FlexString) + 40);
        strcpy(text1->data, "Hello, World!");
        printf("%s\n", text1->data);

        FlexString *text2 = create_string_from("My name is Duc");
        printf("%s\n", text2->data);
    }

    // ----------------------------------
    // Padding bytes
    if (0)
    {
        struct foo
        {
            int a;
            char b;
            int c;
            char d;
        };

        printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char)); // 10 bytes
        printf("%zu\n", sizeof(struct foo));                                      // 16 bytes
    }

    // ----------------------------------
    // offsetof
    if (0)
    {
        struct foo
        {
            int a;
            char b;
            int c;
            char d;
        };

        printf("%zu\n", offsetof(struct foo, a)); // Start from byte 0
        printf("%zu\n", offsetof(struct foo, b)); // Start from byte 4 (add 3 bytes padding)
        printf("%zu\n", offsetof(struct foo, c)); // Start from byte 8
        printf("%zu\n", offsetof(struct foo, d)); // Start from byte 12 (add 3 bytes padding)
    }

    // ----------------------------------
    // Fake OOP
    if (0)
    {
        struct child c = {.super.a = 1, .super.b = 2, .c = 3, .d = 4};
        print_child(&c);
        print_parent(&c);
    }

    // ----------------------------------
    // Bit-fields
    if (0)
    {
        struct foo
        {
            unsigned int a : 5;
            unsigned int b : 5;
            unsigned int c : 3;
            unsigned int d : 3;
        };
    }

    // ----------------------------------
    // Union
    if (0)
    {
        union foo
        {
            int a, b, c, d, e, f;
            float g, h;
            char i, j, k, l;
        };

        // printf("%zu\n", sizeof(union foo)); // 4 bytes = the largest field size (float/int)

        union foo u;
        u.g = 3.14159;

        // printf("%d\n", u.a); // 1078530000
        // printf("%f\n", u.g); // 3.141590
        // printf("%c\n", u.i); // ╨
        // ----------------------------------------

        union foo x;
        union foo *foo_x_p = &x;

        int *foo_int_p = (int *)&x;       // or (int *)foo_x_p
        float *foo_float_p = (float *)&x; // or (float *)foo_x_p

        x.a = 12;
        // printf("%d\n", x.a);        // 12
        // printf("%d\n", *foo_int_p); // 12

        x.g = 3.141592;
        // printf("%f\n", x.g);          // 3.141592
        // printf("%f\n", *foo_float_p); // 3.141592

        union foo y;
        int *foo_y_int_p = (int *)&y;            // Pointer to int field
        union foo *p = (union foo *)foo_y_int_p; // Back to pointer to union

        p->a = 12;
        // printf("%d\n", y.a); // 12

        // ----------------------------------------
        struct a
        {
            int x;   //
            float y; // Common initial sequence

            char *p;
        };
        struct b
        {
            int x;   //
            float y; // Common initial sequence

            double *p;
            short z;
        };
        union foo2
        {
            struct a a;
            struct b b;
        };
        union foo2 u2;
        // Can use: u2.a.x = 1 or u2.b.x = 1

        union animal a1 = {.antelope.type = ANTELOPE, .antelope.loudness = 10};
        union animal a2 = {.octopus.type = OCTOPUS, .octopus.sea_creature = 20, .octopus.intelligence = 3.14};
        print_animal(&a1);
        print_animal(&a2);
    }

    // ----------------------------------
    // Pass and return struct and union
    if (1)
    {
        struct foo3 d1;
        d1 = pass_and_return_struct(d1);
        printf("%d, %s\n", d1.id, d1.name);
    }
}