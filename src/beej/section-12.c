// ******************************************************
// MANUAL MEMORY ALLOCATION
#include "stdio.h"
#include "stdlib.h"

char *readFileLine(FILE *file)
{
    int offset = 0;
    int bufferSize = 4;
    int c;

    char *buffer = malloc(bufferSize);
    if (buffer == NULL)
        return NULL;

    while (c = fgetc(file), c != '\n' && c != EOF)
    {
        if (offset == (bufferSize - 1))
        {
            bufferSize *= 2;
            char *new_buffer = realloc(buffer, bufferSize);

            if (new_buffer == NULL)
            {
                free(buffer);
                return NULL;
            }

            buffer = new_buffer;
        }

        buffer[offset++] = c;
    }

    if (c == EOF && offset == 0)
    {
        free(buffer);
        return NULL;
    }

    if (offset < bufferSize - 1)
    {
        char *new_buffer = realloc(buffer, bufferSize + 1);
        if (new_buffer != NULL)
            buffer = new_buffer;
    }

    buffer[offset] = '\0';

    return buffer;
}

int main(void)
{
    /*
     **************** ALLOCATE ARRAY ****************
     */
    /* {
        int *p;

        // Allocate space for 3 ints
        int arrLength = 3;
        if ((p = malloc(sizeof(int) * arrLength)) == NULL)
        {
            // Handle allocating error
            printf("Allocating error");
        }

        p[0] = 1;
        p[1] = 2;
        p[2] = 3;
        for (int i = 0; i < arrLength; i++)
        {
            printf("Value of index %d: %d\n", i, p[i]);
        }
        free(p);

        // Initialize array with 0
        int *p2 = calloc(arrLength, sizeof(int));
        for (int i = 0; i < arrLength; i++)
        {
            printf("Value of index %d: %d\n", i, p2[i]); // All 0
        }
        free(p2);
    } */

    /*
     **************** RE-SIZE ALLOCATED ARRAY ****************
     */
    /* {
        int initLength = 3;
        int *p = calloc(initLength, sizeof(int));
        printf("Init size: %d\n", sizeof(*p));
        for (int i = 0; i < initLength; i++)
        {
            p[i] = (i + 1) * 2;
        }

        int changedLength = 10;
        int *new_p = realloc(p, changedLength * sizeof(*p));
        if (new_p == NULL)
        {
            printf("Error reallocing\n");
            return 1;
        }

        p = new_p;
        printf("Changed size: %d\n", sizeof(*p));
        for (int i = initLength; i < changedLength; i++)
        {
            p[i] = (i + 1) * 2;
        }

        for (int i = 0; i < changedLength; i++)
        {
            printf("Value of index %d: %d\n", i, p[i]);
        }

        free(p);
    } */

    /*
     **************** READ FILE & STORE CONTENT TO BUFFER ****************
     */
    /* {
        FILE *file = fopen("input.txt", "r");
        char *line;
        while ((line = readFileLine(file)) != NULL)
        {
            printf("%s\n", line);
            free(line);
        }
        fclose(file);
    } */
}