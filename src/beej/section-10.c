// Define struct types
typedef struct
{
    int id;
    char *name;
    float value;
} Item;

Item item1 = {.id = 1, .name = "Item 1", .value = 9.99};

// Used for managing type of multiple variables
typedef float common_x_var_type;
common_x_var_type x1, x2, x3, x4, x5;