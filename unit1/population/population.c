#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_pop;
    do
    {
        start_pop = get_int("What is the starting population? ");
    }
    while (start_pop < 9);

    int end_pop;
    do
    {
        end_pop = get_int("What is the ending population? ");
    }
    while (start_pop > end_pop);

    int years = 0;
    int current_pop = start_pop;
    while (current_pop < end_pop)
    {
        current_pop = current_pop + current_pop / 3 - current_pop / 4;
        years = years + 1;
    }
    printf("Years: %i\n", years);
}