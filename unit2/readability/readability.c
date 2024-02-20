#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i = i + 1)
    {
        if (islower(text[i]))
        {
            letters = letters + 1;
        }
        if (isupper(text[i]))
        {
            letters = letters + 1;
        }
    }
    // printf("Letters = %i\n", letters);

    int sentences = 0;
    for (int i = 0; i < length; i = i + 1)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences = sentences + 1;
        }
    }
    // printf("Sentences = %i\n", sentences);

    int words = 1;
    for (int i = 0; i < length; i = i + 1)
    {
        if (text[i] == ' ')
        {
            words = words + 1;
        }
    }
    // printf("Words = %i\n", words);

    float L = 0;
    // L is the average number of letters per 100 words in the text
    L = (float) letters / (float) words * 100;
    // printf("letters per 100 words = %.2f\n", L);

    float S = 0;
    // S is the average number of sentences per 100 words in the text
    S = (float) sentences / (float) words * 100;
    // printf("sentences per 100 words = %.2f\n", S);

    float index = 0;
    index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}