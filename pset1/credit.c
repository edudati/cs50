#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    // Prompt for Credit Card number
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

    // Count number of digits of the credit card
    int count = 0;
    long number = n; // preserve original credit card number as n
    do
    {
        number = number / 10;
        count ++;
    }
    while (number != 0);
    
    // Get the 2 first digits
    int digit = n / pow(10, count - 2);
    
    // Validation 1: 1st numbers and number os digits - Classify credit card by label
    string label = "INVALID";
    if (count == 15 && (digit == 34 || digit == 37))
    {
        label = "AMEX";
    }
    else if (count == 16 && digit > 50 && digit < 56)
    {
        label = "MASTERCARD";
    }
    else if ((count == 13 || count == 16) && digit > 39 && digit < 50)
    {
        label = "VISA";
    }
    else
    {
        printf("%s\n", label);
        return 0;
    }

    // Vaidation 2: Luhn's algorithm
    long for_mod;
    long divider = 1;
    int sum = 0;

    for (int i = 1; i < count + 1; i++) // separate digit per digit from end to begenning
    {
        for_mod = pow(10, i);
        if (i > 1)
        {
            divider = pow(10, i - 1);
        }
        digit = n % for_mod / divider;
        if (i % 2 == 0) // digits in even positions are multiplied by 2
        {
            digit *= 2;
            if (digit < 10) // considering diferent sum for results with 2 digits
            {
                sum += digit;
            }
            else
            {
                sum += (digit - 9);
            }
        }
        else // digits in odd positions are just add to sum
        {
            sum += digit;
        }
    }
    if (sum % 10 == 0)
    {
        printf("%s\n", label);
    }
    else
    {
        printf("INVALID\n");
    }
}
