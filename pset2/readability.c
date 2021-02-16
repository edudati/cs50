#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int letter = 0;
    int word = 0;
    int point = 0;
    string sentence = get_string("Text: ");
    for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        //printf("%c\n", s[i]);
        if (isalpha(sentence[i]))
        {
            letter++;
        }
        if (isspace(sentence[i]))
        {
            word++;
        }
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            point++;;
        }
    }
    if (letter > 0)
    {
        word++;
    }
    float index = 0.0588 * ((float)letter / (float)word * 100) - 0.296 * ((float)point / (float)word * 100) - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

}
