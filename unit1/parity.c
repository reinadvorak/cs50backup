// User input and integer. Output "even" or "odd".

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = get_int("integer: ");

    if (number % 2 == 0)
    {
        printf("This is an even number!\n");
    }
    else
    {
        printf("This is an odd number!\n");
    }
}