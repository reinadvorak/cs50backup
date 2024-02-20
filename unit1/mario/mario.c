#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int x = 0; x < height; x = x + 1)
    {
        for (int z = height - 1; z > x; z = z - 1)
        {
            printf(" ");
        }
        for (int y = 0; y <= x; y = y + 1)
        {
            printf("#");
        }
        printf("\n");
    }
}