#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int sum = 0;
    for (int i = 0; i < 15; i=i+1)
    {
        int term = 1;
        for ( int j = 1; j <= i + 1; j = j + 1)
        {
            term = term * j;
        }
        sum = sum + term;
    }
    printf("Sum = %i\n", sum);
}