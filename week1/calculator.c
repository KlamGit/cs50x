// Calculator program in C

#include <stdio.h>
#include <cs50.h>

void addition(void);
void long_int(void);
void truncation(void);
void float_division(void);

int main(void) {
    addition();
    long_int();
    truncation();
    float_division();
}

// Function for adding two integers
void addition (void) {

    // ask user for first number
    int x = get_int("Enter first number: ");
    
    // ask user for second number
    int y = get_int("Enter Second Number: ");

    // add the numbers
    int sum = x + y;

    // print the result
    printf("The sum of %d and %d is %d\n", x, y, sum);

}

// Function for doubling an integer

void long_int (void) {
    long int dollar = 1;
    while (true) {
        char c = get_char ("Here is $%li, make it double and give it to the next person? ", dollar);
        if (c == 'y' ||  c == 'Y') {
            dollar = dollar * 2;
            printf("Here is $%li\n", dollar);
        }
        else if (c == 'n' || c == 'N') {
            printf ("Fair enough, I guess..\n");
            break;
        }
        else {
            printf ("Please enter 'y' or 'n'.\n");
        }
    }
}

// Division with ints, demonstrating truncation

void truncation (void) {
    int x = get_int("Enter first number: ");
    int y = get_int("Enter second number: ");
    
    // Division with truncation
    int result = x / y;
    
    // Print the result
    printf("The result of %d divided by %d is %d\n", x, y, result);
}

// Division with floats, demonstrating no truncation

void float_division (void) {

    // prompt user for two numbers
    float x = get_float("Enter first number: ");
    float y = get_float("Enter second number: ");
    
    //divide the numbers
    float result = x / y;
    // print the result
    printf("The result of %.2f divided by %.2f is %.2f\n. In other words - The result of %.50f divided by %.50f is %.50f\n", x, y, result, x, y, result);
}
