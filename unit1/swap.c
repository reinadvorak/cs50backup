// This program will swap 2 values

#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    int temp = x;
    x=y;
    y=temp;
    printf("x = %i and y = %i \n", x, y);
}