#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Prompt for string of text
    string sentence = get_string("Text: ");
    
    int letter = 0;
    int word = 0;
    int period = 0;
    
    // Check any character and count letters, words and periods
    for (int i = 0, n = strlen(sentence); i < n; i++)
    {
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
            period++;;
        }
    }
    
    // Count the first word that do not need any space
    if (letter > 0)
    {
        word++;
    }
    
    // Apply Coleman-Liau index
    float index = 0.0588 * ((float)letter / (float)word * 100) - 0.296 * ((float)period / (float)word * 100) - 15.8;
    
    // Classify sentence
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
