#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    printf("\n  Hello %s\n\n", name);
}