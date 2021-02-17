#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //verify if have 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int n = strlen(argv[1]);
    int current = 0;
    int repeated = 0;


    //verify if have 26 letters
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //verify is there is only letters
    for (int i = 0; i < n; i++)
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only letters.\n");
            return 1;
        }

    //verify if there is a repeated letter
    for (int i = 0; i < n; i++)
    {
        current = argv[1][i];
        for (int j = 0; j < n; j++)
        {
            if (current == argv[1][j])
            {
                repeated++;
            }
        }
        if (repeated != 1)
        {
            printf("Key with repeated letters.\n");
            return 1;
        }
        else
        {
            repeated = 0;
        }
    }

    // substitution code
    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, j = strlen(plain); i < j; i++)
    {
        if (isalpha(plain[i]))
        {
            for (int k = 0; k < n; k++)
            {
                if (plain[i] == 65 + k)
                {
                    printf("%c", toupper(argv[1][k]));
                }
                else if (plain[i] == 97 + k)
                {
                    printf("%c", tolower(argv[1][k]));
                }
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}
