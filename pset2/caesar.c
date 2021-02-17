#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Validation if have exactly 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    // Validation - only numbers
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    // convert key to a number
    int key = atoi(argv[1]);
    
    //Validation - non-negative number
    if (key < 0)
    {
        printf("Usage: ./caesar Key\n");
        return 1;
    }

    // prompt to get plain text
    string plain = get_string("Plain text: ");

    printf("Ciphertext: ");

    // Apply Caesar's algorithym for each character preserving case and non alphabetic
    for (int i = 0; plain[i] != '\0'; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                int cipher = ((plain[i] - 'A' + key) % 26) + 'A';
                printf("%c", cipher);
            }
            else
            {
                int cipher = ((plain[i] - 'a' + key) % 26) + 'a';
                printf("%c", cipher);
            }
        }
        else
        {
            printf("%c", plain[i]);
        }   
    }
    printf("\n");
}
