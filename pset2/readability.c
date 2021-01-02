#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int l = 0;
    int w = 0;
    int p = 0;
    string s = get_string("Text: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //printf("%c\n", s[i]);
        if (isalpha(s[i]))
        {
            l++;
        }
        if (isspace(s[i]))
        {
            w++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            p++;;
        }
    }
    if (l > 0)
    {
        w++;
    }
    float index = 0.0588 * ((float)l / (float)w * 100) - 0.296 * ((float)p / (float)w * 100) - 15.8;
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