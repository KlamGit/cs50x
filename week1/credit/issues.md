# **CS50 Credit Card Validation: Common Issues and Solutions**

## **Introduction**
Validating credit card numbers using **Luhn’s Algorithm** and identifying card types (VISA, Mastercard, AMEX) is a classic problem in CS50’s Week 1 assignment. Many students encounter similar issues, especially with:
1. **Luhn’s Algorithm implementation**
2. **Card type identification**
3. **String vs. numerical processing**

This post summarizes the **key problems, mistakes, and solutions**, including detailed explanations and corrected code.

---

## **Common Issues & Solutions**
### **1. Luhn’s Algorithm Implementation Errors**
#### **Problem:**
- The algorithm requires:
   - Doubling **every second digit from the right**.
   - Summing the digits of any two-digit results.
   - Checking if the total sum is divisible by 10.

#### **Mistakes in Original Code:**
1. **Incorrect Digit Position Handling**  
   - Using `digit_count % 2 != 0` instead of `digit_count % 2 == 0` to identify second digits from the right.
   - **Why?**  
     - The **rightmost digit is position 1 (odd)**.
     - The **second digit from the right is position 2 (even)**.  
     - Thus, we double digits where `digit_count % 2 == 0`.

2. **Incorrect Summing of Doubled Digits**  
   - If doubling a digit results in a two-digit number (e.g., `8 × 2 = 16`), we must **sum its digits (`1 + 6 = 7`)** before adding to the total.

#### **Solution: Correct Luhn Implementation**
```c
bool check_luhn_maths(long long card_number) {
    int sum = 0;
    int digit_count = 0;
    long long temp_number = card_number;
    
    while (temp_number > 0) {
        int digit = temp_number % 10; // Extract last digit
        temp_number /= 10; // Remove last digit
        digit_count++;
        
        if (digit_count % 2 == 0) { // Double every second digit from right
            digit *= 2;
            // If doubled digit is two digits, split and sum (e.g., 16 → 1 + 6 = 7)
            sum += (digit > 9) ? (digit / 10 + digit % 10) : digit;
        } else {
            sum += digit; // Add normally if not doubled
        }
    }
    
    return (sum % 10 == 0); // Valid if sum is divisible by 10
}
```

---

### **2. Card Type Identification Errors**
#### **Problem:**
- **AMEX**: 15 digits, starts with `34` or `37`.
- **Mastercard**: 16 digits, starts with `51-55`.
- **VISA**: 13 or 16 digits, starts with `4`.

#### **Mistakes in Original Code:**
1. **Using `strcmp()` on Full Card Number**  
   - `strcmp(string_card_number, "34")` compares the **entire card number** with `"34"`, which is wrong.
   - **Solution:** Extract the **first 1 or 2 digits** instead.

2. **Incorrect Length Checks**  
   - VISA can be **13 or 16 digits**, but the original code checked them separately.

#### **Solution: Correct Card Type Check**
```c
string credit_card_type(long long card_number) {
    char string_card_number[20];
    snprintf(string_card_number, sizeof(string_card_number), "%lld", card_number);
    
    int length = strlen(string_card_number);
    int first_digit = string_card_number[0] - '0';
    int first_two_digits = first_digit * 10 + (string_card_number[1] - '0');

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37)) {
        return "AMEX";
    }
    else if (length == 16) {
        if (first_two_digits >= 51 && first_two_digits <= 55) {
            return "MASTERCARD";
        }
        else if (first_digit == 4) {
            return "VISA";
        }
    }
    else if ((length == 13 || length == 16) && first_digit == 4) {
        return "VISA";
    }
    
    return "INVALID";
}
```

---

### **3. Key Takeaways**
1. **Luhn’s Algorithm:**
   - Double **every second digit from the right** (`digit_count % 2 == 0`).
   - Sum **digits** of any two-digit results (e.g., `16 → 1 + 6 = 7`).
   - Check if the **total sum is divisible by 10**.

2. **Card Type Identification:**
   - Use `snprintf()` to safely convert `long long` to a string.
   - Extract **first 1 or 2 digits** to check card type.
   - Ensure correct **length checks** (AMEX: 15, Mastercard: 16, VISA: 13 or 16).

3. **Debugging Tips:**
   - Test with known valid/invalid numbers (e.g., `378282246310005` should be AMEX if Luhn passes).
   - Print intermediate values (e.g., `sum` in Luhn’s algorithm) to verify logic.

---

## **Final Corrected Code**
```c
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
```

---

## **Conclusion**
The main issues were:
1. **Luhn’s Algorithm**:
   - Wrong digit doubling logic.
   - Incorrect summing of two-digit results.
2. **Card Type Identification**:
   - Comparing entire strings instead of prefixes.
   - Missing length checks.

By fixing these, the program now correctly:
✅ Validates card numbers using Luhn’s Algorithm.  
✅ Identifies AMEX, Mastercard, and VISA.  
✅ Returns "INVALID" for incorrect numbers.  

Hope this helps! Let me know if you have further questions.