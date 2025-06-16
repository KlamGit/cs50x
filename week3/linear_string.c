// Implements linear search for integers

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of integers
    string strings[] = {"why", "britney", "Eid", "German", "Deutsche Welle", "Oops! I did it again!", "Bibliothek", "Lesen"};

    //Search for number
    string s = get_string("Word(s): ");
    for (int i = 0; i < (sizeof(strings) / sizeof(strings[0])); i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}