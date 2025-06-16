// Compare two integers

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get 2 integers
    int i = get_int("i: ");
    int j = get_int("j: ");

    // Compare integers
    if (i == j)
    {
        printf("Same same\n");
    }
    else
    {
        printf("Different\n");
    }

    
}