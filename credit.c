#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void luhn(long number);

int main(void)
{
    char continuar;

    do
    {
        long number;
        printf("Insert card number: ");
        if (scanf("%ld", &number) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        luhn(number);

        printf("Continue? (y/n): ");
        scanf(" %c", &continuar);
    }
    while (continuar == 'y');

    return 0;
}

void luhn(long number)
{
    int sum1 = 0, sum2 = 0;
    int digits = 0;
    bool second = false;
    long original = number;

    // Count the number of digits
    long temp = original;
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }

    if (digits < 13 || digits == 14 || digits > 16)
    {
        printf("Invalid card length!\n");
        return;
    }

    // Perform Luhn's algorithm
    while (number > 0)
    {
        int digit = number % 10;

        if (second)
        {
            int num = digit * 2;
            sum1 += (num > 9) ? (num % 10) + (num / 10) : num;
        }
        else
        {
            sum2 += digit;
        }

        number /= 10;
        second = !second;
    }

    int total = sum1 + sum2;
    printf("Total: %d\n", total);

    if (total % 10 != 0)
    {
        printf("Checksum failed!\n");
        return;
    }

    // Extract the first two digits
    long temp2 = original;
    while (temp2 >= 100)
    {
        temp2 /= 10;
    }
    int first_two_digits = temp2;

    printf("First two digits: %d\n", first_two_digits);
    printf("Digits: %d\n", digits);

    // Determine card type
    if ((first_two_digits == 34 || first_two_digits == 37) && digits == 15)
    {
        printf("AMEX\n");
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && digits == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((first_two_digits / 10 == 4) && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("Unknown card type!\n");
    }
}
