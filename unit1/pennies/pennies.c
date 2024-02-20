#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int days;
    do
    {
        days = get_int("Days in month: ");
    }
    while (days < 28 || days > 31);

    int pennies;
    do
    {
        pennies = get_int("Pennies on first day: ");
    }
    while (pennies < 1);

    double x = pennies * pow(2, days);
    double total = x / 100;

    printf("$%.2f\n", total);
}