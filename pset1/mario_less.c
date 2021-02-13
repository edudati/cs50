#include <stdio.h>
#include <cs50.h>


// MARIO LESS COMFORTABLE

int main(void)
{
    // Prompt to imput Height
    int n;
    do
    {
        n = get_int("Height: \n");
    }
    while (n < 1 || n > 8);

    // Create the piramids of hashes
    int n_hash = n - 1;
    int n_blank = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - n_blank ; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < n - n_hash ; k++)
        {
            printf("#");
        }
        printf("\n");
        n_hash--;
        n_blank++;
    }
}
