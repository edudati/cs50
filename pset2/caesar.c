#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }

        }
        if ((int) argv[1] < 0)
        {
            printf("Usage: ./caesar Key\n");
            return 1;
        }
        printf("sucess\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
