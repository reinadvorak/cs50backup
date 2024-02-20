#include <cs50.h>
#include <stdio.h>

int main(void){
    long x = get_long("First #: ");
    long y = get_long("Second #: ");
    long sum = x + y;
    printf("\nThe sum %li + %li = %li\n\n", x, y, sum);
}