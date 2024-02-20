#include <cs50.h>
#include <stdio.h>

bool isprime(int test_num);
int main(void)
{
    int number = get_int("How many primes would you like?" );
    int count = 0;
    int check = 2;

    while (count < number)
    {
        if (isprime(check))
        {
            printf("%i ", check);
            count = count + 1;
        }
        check = check + 1;
    }
}

bool isprime(int test_num)
{
    int count = 0;
    for (int d = 1; d <= test_num; d = d + 1)
    {
        if (test_num % d == 0)
        {
            count = count + 1;
        }
    }
    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}