// Count the number of vowels (a,e,i,o,u)
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Input: ");
    int vowels = 0;
    int length = strlen(text);
    char c;
    for (int i = 0; i < length; i = i + 1)
    {
        c = tolower(text[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowels = vowels + 1;
        }
    }
    printf("The number of vowels is ... %i\n", vowels);

    int words = 5;

    //calculate the average number of vowels per 5 words
    float average = (float)vowels / (float)words;
    printf("The average number of vowels per 5 words is %.2f\n", average);
}