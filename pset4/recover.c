#include <stdio.h>
#include <stdlib.h>

#define BUFFER 512

int main(int argc, char *argv[])
{
    // Check if have 2 arguments
    if (argc != 2)
    {
        printf("error\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("error");
        return 1;
    }

    int jpgFound = 0;
    int fileCount = 0;
    unsigned char buffer[BUFFER];
    FILE *image = NULL;

    while (fread(buffer, BUFFER, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpgFound == 1)
            {
                fclose(image);
            }
            else
            {
                jpgFound = 1;
            }

            char name[8];
            sprintf(name, "%03d.jpg", fileCount);
            image = fopen(name, "a");
            fileCount ++;

        }
        if (jpgFound == 1)
        {
            fwrite(&buffer, BUFFER, 1, image);
        }
    }
    fclose(file);
    fclose(image);

    return 0;
}
