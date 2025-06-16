// Implements linear search for integers

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // An array of integers
    int numbers[] = {1, 35, 4679, 7854, 0, 78, 55, 96};

    //Search for number
    int n = get_int("Number: ");
    for (int i = 0; i < sizeof(numbers); i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}