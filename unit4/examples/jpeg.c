#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // open file
    FILE *file = fopen(argv[1], "r");

    // Read first 3 bytes
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);

    //Check first 3 bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("This might be a jpeg file!\n");
    }
    else
    {
        printf("This is NOT a jpeg file!\n");
    }

    fclose(file);

    }