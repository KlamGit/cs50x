// Implementing Luhn's algorithm for validating credit card numbers and printing out card type
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// using integer maths functions
bool check_luhn_maths(long long number);
string credit_card_type(long long card_number);

int main(void)
{
    long long card_number = get_long("Please type your credit card number here: ");
    // check_luhn_string(card_number);
    check_luhn_maths(card_number);
    // check if the card number is valid using Luhn's algorithm
    if (check_luhn_maths(card_number))
    {
        // If the card number is valid, print the card type
        printf("%s\n", credit_card_type(card_number));
    }
    else
    {
        // If the card number is invalid, print INVALID
        printf("INVALID\n");
    }
}

// Function to check if the credit card number is valid using Luhn's algorithm
bool check_luhn_maths(long long card_number)
{
    // Initialize a variable to hold the sum of digits
    int sum = 0;
    // Initialize variables to hold the sum of odd and even positioned digits
    int sum_odd = 0;
    int sum_even = 0;
    int digit_count = 0;
    // Initialize a temporary variable to hold the card number
    long long temp_number = card_number;
    // Loop through each digit of the card number
    while (temp_number > 0)
    {
        int digit = temp_number % 10; // Get the last digit
        temp_number /= 10;            // Remove the last digit
        digit_count++;
        // If the digit count is even, double the digit
        if (digit_count % 2 == 0)
        {
            digit *= 2;
            // If doubling the digit results in two-digit number, add the digits together
            sum_even += (digit > 9) ? (digit / 10 + digit % 10) : digit; // Subtract 9 if digit is greater than 9
        }
        else
        {
            // If the digit count is even, add the digit to the sum
            sum_odd += digit;
        }
    }

    // Add the sums of odd and even positioned digits
    sum = sum_odd + sum_even;
    // Check if the sum is a multiple of 10
    return (sum % 10 == 0) ? true : false;
}

string credit_card_type(long long card_number)
{

    // Create a buffer to hold the credit card number as a string
    char string_card_number[20];

    // convert the number to string for string manipulation
    // using snprintf to convert long long to string
    snprintf(string_card_number, sizeof(string_card_number), "%lld", card_number);

    // check length of credit card
    int length = strlen(string_card_number);
    int first_digit = string_card_number[0] - '0';                           // Convert first character to integer
    int first_two_digits = first_digit * 10 + (string_card_number[1] - '0'); // Convert first two characters to integer

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        // Check if the card number is 15 digits long and starts with 34 or 37
        return "AMEX";
    }
    else if (length == 16)
    {
        if (first_two_digits >= 51 && first_two_digits <= 55)
        {
            return "MASTERCARD";
        }
        else if (first_digit == 4)
        {
            return "VISA";
        }
        else
            return "INVALID";
    }
    else if (length == 13 && first_digit == 4)
    {
        return "VISA";
    }
    else
        return "INVALID";
}