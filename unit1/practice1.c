#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = get_int("Number: ");

    int counter = 0;
    while (counter < number)
    {
        counter = counter + 1;
        printf("%i \n", counter);
    }
    printf("\n\n");
}