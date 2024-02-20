#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    char *buffer[1];
    while(fread(buffer, 1, 1, input))
    {
        fwrite(buffer, 1, 1, output);
    }


    fclose(input);
    fclose(output);
}