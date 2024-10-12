// ******************************************************
// struct
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSENGERS 8

void main(void)
{
    // ----------------------------------
    // Nested struct
    /*  {
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
     } */

    // ----------------------------------
    // Self-referential struct
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
}