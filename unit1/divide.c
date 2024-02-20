#include <cs50.h>
#include <stdio.h>

float divide(int a, int b);

int main(void){
    int x = get_int("First number: ");
    int y = get_int("Second number: ");
    float z = divide(x,y);
    printf("%i / %i = %.2f \n", x, y, z);
}

float divide(int a, int b)
{
    float c = (float)a / (float)b;
    return c;
}