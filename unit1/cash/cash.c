#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Changed owed: ");
    }
    while (dollars < 0);
    int change;
    int coins;
    change = round(dollars * 100);
    coins = 0;

    while (change >= 25)
    {
        coins = coins + 1;
        change = change - 25;
    }
    while (change >= 10)
    {
        coins = coins + 1;
        change = change - 10;
    }
    while (change >= 5)
    {
        coins = coins + 1;
        change = change - 5;
    }
    while (change >= 1)
    {
        coins = coins + 1;
        change = change - 1;
    }
    printf("%i\n", coins);
}