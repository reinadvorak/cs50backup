#include <stdio.h>

int main(void)
{
    int list[] = {1,2,3,4,5};
    int length = 5;
    int temp = 0;
    for (int i = 0; i < (length / 2); i++)
    {
        temp = list[i];
        list[i] = list[length - 1 - i];
        list[length - 1 - i] = temp;
    }

    printf("%i %i %i %i %i\n", list[0], list[1], list[2], list[3], list[4]);
}