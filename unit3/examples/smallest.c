//Purpose is to find the smallest value in a list of numbers
// Usage: ./smallest 4(how may numbers in the list)

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

//function prototype
int find_smallest(int list[], int n);

int main(int argc, string argv[])
{
    //The number of values to be put in the list
    int count = atoi(argv[1]);
    int numbers[count];

    //To get all the numbers from the user and store them
    for (int i = 0; i < count; i = i + 1)
    {
        numbers[i] = get_int("Number %i: ", i + 1);
    }

    printf("The smallest number is %i.\n", find_smallest(numbers, count));
}


int find_smallest(int list[], int n)
{
    int smallest = list[0];
    for (int k = 0; k < n; k = k + 1)
    {
        if (smallest > list[k])
        {
            smallest = list[k];
        }
    }
    return smallest;
}