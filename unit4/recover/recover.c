#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    if (argv[1] == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    typedef uint8_t BYTE;
    BYTE buffer[512];
    char filename[8];
    FILE *picture;
    int var = 0;
    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if first JPEG
            // make 000.jpg and open it and write to it
            // else:
            // close the file that you have been writing to
            // open up the next file that you will be writing to
            // sprintf(filename, "%3i.jpg", var)
            if (var == 0)
            {
                sprintf(filename, "000.jpg");
                picture = fopen(filename, "w");
                fwrite(buffer, 512, 1, picture);
                var = 1;
            }
            else
            {
                fclose(picture);
                sprintf(filename, "%03i.jpg", var);
                picture = fopen(filename, "w");
                fwrite(buffer, 512, 1, picture);
                var++;
            }
        }
        else
        {
            if (!(var == 0))
            {
                fwrite(buffer, 512, 1, picture);
            }
        }
    }
    fclose(file);
    fclose(picture);
}
