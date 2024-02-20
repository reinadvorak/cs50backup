// Goal is to find the sum 1 + 2 + 3 + ... 123456

#include <stdio.h>

int main(void)
{
    int sum = 0;
    int counter = 0;
    int term = 1;
    while (counter < 12345)
    {
        sum = sum + term;
        term = term + 1;
        counter = counter + 1;
    }
    printf("The sum = %i \n", sum);


}