#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //An array (list) of integers
    int numbers[] = {4, 8, 15, 16, 23, 42};

    //Search for a value
    int value = get_int("Which integer would you like to search for?");

    for (int i = 0; i < 6; i = i + 1)
    {
        if (value == numbers[i])
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}