#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string n = "Hi!";
    string m = "Yes!";
    m = "Hi!";
    int x = 50;
    int *p = &x;
    printf("%p\n", n);
    printf("%p\n", &n[0]);
    printf("%p\n", &n[1]);
    printf("%p\n", &n[2]);
    printf("%i\n", *p);

}