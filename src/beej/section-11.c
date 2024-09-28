#include <stdio.h>
#include <stdlib.h>

int arrayAndPointerEquivalent(void)
{
    int a[] = {11, 22, 33, 44, 55};

    int *p = a; // p points to the first element of a, 11

    // Print all elements of the array a variety of ways:

    for (int i = 0; i < 5; i++)
        printf("%d\n", a[i]); // Array notation with a

    for (int i = 0; i < 5; i++)
        printf("%d\n", p[i]); // Array notation with p

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(a + i)); // Pointer notation with a

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(p + i)); // Pointer notation with p

    for (int i = 0; i < 5; i++)
        printf("%d\n", *(p++)); // Moving pointer p
    // printf("%d\n", *(a++));    // Moving array variable a--ERROR!
}
// ---------------------------------------------------------
struct animal
{
    char *name;
    int leg_count;
};

int compar(const void *elem1, const void *elem2)
{
    const struct animal *animal1 = elem1;
    const struct animal *animal2 = elem2;

    if (animal1->leg_count > animal2->leg_count)
        return 1;

    if (animal1->leg_count < animal2->leg_count)
        return -1;

    return 0;
}

int sortingStruct(void)
{
    struct animal a[4] = {
        {.name = "Dog", .leg_count = 4},
        {.name = "Monkey", .leg_count = 2},
        {.name = "Antelope", .leg_count = 4},
        {.name = "Snake", .leg_count = 0}};

    qsort(a, 4, sizeof(struct animal), compar);

    // Print them all out
    for (int i = 0; i < 4; i++)
    {
        printf("%d: %s\n", a[i].leg_count, a[i].name);
    }
}

void main(void)
{
    // arrayAndPointerEquivalent();
    sortingStruct();
}