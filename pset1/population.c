#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for start size
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);

    //Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < n);


    //Calculate number of years until we reach threshold
    int years = 0;
    if (n < end)
    {
        do
        {
            n = n + ((int)(n / 3)) - ((int)(n / 4));
            years ++;
        }
        while (n < end);
    }
    
    //Print number of years
    printf("Years: %i\n", years);
}
