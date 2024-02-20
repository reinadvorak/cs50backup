#include <stdio.h>
#include <cs50.h>

void print_hello(int n);
int main(void)
{
    int times = get_int("How many repeats? ");
    // times is called an "argument" in line 9
    print_hello(times);
}

// print_hello is called a "procedure"
// n is called a "parameter"
void print_hello(int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("Hello!!!\n");
    }
}