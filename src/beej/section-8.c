
#include "stdio.h"

struct Item
{
    int id;
    char *name;
    float value;
};

void setValue(struct Item *item, float newValue)
{
    item->value = newValue;
}

struct Item filterValue(struct Item *item)
{
    struct Item copyItem = *item;
    copyItem.value = item->value * 2.0;

    return copyItem;
}

void main(void)
{
    struct Item item1;

    item1.id = 1;
    item1.name = "Item 1";
    item1.value = 100.99;

    struct Item item2 = {2, "Item 2", 1.99};
    struct Item item22 = filterValue(&item2);

    printf("Value 2: %.2f\n", item2.value);   // 1.99
    printf("Value 22: %.2f\n", item22.value); // 3.98

    struct Item item3 =
        {
            .value = 39.33,
            .id = 3,
            .name = "Item 3",
        };
    setValue(&item3, 50.5);
    // printf("Value: %.2f\n", item3.value); // 50.5

    // Deep copy struct
    struct Item item4 = item3;
    item4.name = "Item 4";
    // printf("Name 3: %s\n", item3.name); // Item 3
    // printf("Name 4: %s\n", item4.name); // Item 4
}