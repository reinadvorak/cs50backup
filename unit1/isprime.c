#include <cs50.h>
#include <stdio.h>

//promt user for an integer greater than 1.
//tell the user whether or not it is a prime number.
//test 1299709

int main(void)
{
    int check_num;
    do
    {
        check_num = get_int("Number: ");
    }
    while (check_num < 2);

    int count_div = 0;
    for (int d = 1; d <= check_num; d = d + 1)
    {
        if (check_num % d == 0)
        {
            count_div = count_div + 1;
        }
    }
    if (count_div == 2)
    {
        printf("%i is PRIME!!!\n", check_num);
    }
    else
    {
        printf("%i is NOT PRIME!!!\n", check_num);
    }
}