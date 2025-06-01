// conditional, boolean expression, relational operator
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for two integers
    // and store them in variables x and y
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    // Compare both integers
    if (x > y)
    {
        printf("x is greater than y\n");
    }
    else if (x < y)
    {
        printf("x is less than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}