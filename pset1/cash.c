# include <stdio.h>
# include <cs50.h>
# include <math.h>


int main(void)
{
    //Prompt for imput
    float cash = 0;
    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash < 0);

    // Convert cash from dollars to cents and round to nearest cent
    cash = round(cash * 100);

    int coins [] = {25, 10, 5, 1};
    int count = 0;

    // Subtract the coins from cash and count
    for (int i = 0; i < 4; i++)
    {
        while (cash >= coins[i])
        {
            cash -= coins[i];
            count++;
        }
    }
    printf("%i\n", count);
}
