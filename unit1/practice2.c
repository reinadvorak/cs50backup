#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num = get_int("Number: ");

    for (int i = 0; i < num; i++)
    {
        if (i + 1 == num)
        {
            printf("%i!!!\n\n", i+1 );
        }
        else
        {
            printf("%i, ", i+1 );
        }
    }
}