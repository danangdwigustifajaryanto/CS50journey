#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for credit card number
    long long cc_num = get_long_long("Number: ");

    // Initialize variables
    int digit_count = 0, sum1 = 0, sum2 = 0, first_digit = 0, second_digit = 0;

    // Calculate checksum using Luhn's algorithm
    while (cc_num > 0)
    {
        // Get last digit
        int digit = cc_num % 10;

        // Check if we're at the second-to-last digit
        if (digit_count == 1)
        {
            second_digit = digit;
        }

        // Check if we're at the last digit
        if (digit_count == 0)
        {
            first_digit = digit;
        }

        // Multiply every other digit by 2, starting with the second-to-last
        if (digit_count % 2 == 1)
        {
            int product = digit * 2;

            // Add digits of product together
            while (product > 0)
            {
                int product_digit = product % 10;
                sum1 += product_digit;
                product /= 10;
            }
        }
        else
        {
            // Add other digits to sum2
            sum2 += digit;
        }

        // Increment digit_count and move on to next digit
        digit_count++;
        cc_num /= 10;
    }

    // Calculate total checksum
    int total_sum = sum1 + sum2;

    // Check if checksum is valid
    if (total_sum % 10 == 0)
    {
        // Determine card type based on first and second digits
        if ((first_digit == 3 && (second_digit == 4 || second_digit == 7)) && digit_count == 15)
        {
            printf("AMEX\n");
        }
        else if ((first_digit == 5 && second_digit >= 1 && second_digit <= 5) && digit_count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (first_digit == 4 && (digit_count == 13 || digit_count == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
