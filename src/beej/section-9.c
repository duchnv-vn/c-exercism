#include "stdio.h"

char inputFileName[] = "input.txt";
char outputFileName[] = "output.txt";
char outputBinaryFileName[] = "output.bin";

void readByCharacter(void)
{
    FILE *fileReader = fopen(inputFileName, "r");

    int c;
    while ((c = fgetc(fileReader)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fileReader);
}

void readByLine(void)
{
    FILE *fileReader = fopen(inputFileName, "r");

    char s[1024];

    while (fgets(s, 100, fileReader) != NULL)
    {
        printf("%s", s);
    }

    fclose(fileReader);
}

void scanFileInput(void)
{
    FILE *fileReader = fopen(inputFileName, "r");

    char key[1024];
    int value;

    while (fscanf(fileReader, "%c=%d\n", key, &value) != EOF)
    {
        printf("Key: %s\n", key);
        printf("Value: %d\n", value);
        printf("-------------------\n");
    }

    fclose(fileReader);
}

void writeTextFile(void)
{
    FILE *fileWriter = fopen(outputFileName, "w");
    fputs("w=2\n", fileWriter);
    fprintf(fileWriter, "%c=%d\n", 'q', 1);

    fclose(fileWriter);
}

void writeBinaryFile(void)
{
    FILE *fileWriter = fopen(outputBinaryFileName, "wb");

    unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};
    fwrite(bytes, sizeof(char), 6, fileWriter);

    unsigned short v = 0x1234;
    fwrite(&v, sizeof(v), 1, fileWriter);

    fclose(fileWriter);
}

void readBinaryFile(void)
{
    FILE *fileReader = fopen(outputBinaryFileName, "rb");
    unsigned char c;
    while (fread(&c, sizeof(char), 1, fileReader) > 0)
    {
        printf("Value: %d\n", c);
    }

    fclose(fileReader);
}

void main(void)
{
    // TEXT FILES
    // readByCharacter();
    // readByLine();
    // scanFileInput();
    // writeTextFile();

    // BINARY FILES
    writeBinaryFile();
    readBinaryFile();
}