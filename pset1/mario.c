#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;

    do
        n = get_int("Height:\n");
    while (n < 1 || n > 8);
    int nHash = n-1;
    int nBlank = 0;
    for (int i = 0; i < n; i++)
        {

        for (int j = 1; j < n - nBlank ; j++)
            {
            printf(" ");
            }
        for (int k = 0; k < n - nHash ; k++)
            {
            printf("#");
            }
        printf("  ");
        for (int l = 0; l < n - nHash ; l++)
            {
            printf("#");
            }
        printf("\n");
        nHash--;
        nBlank++;
        }
}