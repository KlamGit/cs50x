#include <cs50.h>
#include <stdio.h>

// Function prototype
void pyramid(int height);
int main(void)
{
    // Prompt user for an integer between 1 and 8
    int h = get_int("Height: ");
    // Ensure the input is between 1 and 8
    while (h < 1 || h > 8)
    {
        h = get_int("Height: ");
    }
    // Call the pyramid function with the valid height
    pyramid(h);
}

void pyramid(int height)
{
    // Loop through each row
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = height - i - 1; j >= 1; j--)
        {
            printf(" ");
        }
        // Print hashes for first pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Print 2 spaces between the two pyramids
        printf("  ");

        // Print hashes for the second pyramid
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        // Move to the next line after each row
        printf("\n");
    }
}