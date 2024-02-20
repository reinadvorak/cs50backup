#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(int argc, char *argv[])
{
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    float speed_factor = get_float("Sample Rate Factor: ");
    char reverse = get_char("Reverse (y or n)? ");

    //First 24 bytes
    uint8_t header24[24];
    fread(header24, 24, 1, input);
    fwrite(header24, 24, 1, output);

    //Sample Rate
    int32_t sample_rate;
    fread(&sample_rate, 4, 1, input);
    sample_rate = sample_rate * speed_factor;
    fwrite(&sample_rate, 4, 1, output);
    printf("Sample Rate = %i\n", sample_rate);

     //First 12 bytes
    uint8_t header12[12];
    fread(header12, 12, 1, input);
    fwrite(header12, 12, 1, output);

    //File Size
    int32_t file_size;
    fread(&file_size, 4, 1, input);
    fwrite(&file_size, 4, 1, output);
    printf("File Size = %i\n", file_size);
    int sample_size = file_size / 2;

    //copy audio
    int16_t buffer;
    int16_t audio[sample_size];
    int reverse_index = sample_size - 1;
    int forward_index = 0;
    if(reverse == 'y')
    {
        while(fread(&buffer, 2, 1, input))
        {
            audio[reverse_index] = buffer;
            reverse_index--;
        }
    }
    else
    {
        while(fread(&buffer, 2, 1, input))
        {
            audio[forward_index] = buffer;
            forward_index++;
        }
    }
    fwrite(audio, sizeof(audio), 1, output);

    fclose(input);
    fclose(output);
}