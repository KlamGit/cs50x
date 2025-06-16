// Implements a phone book without structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Arrays of strings
    string names[] = {"Zinia", "Marius", "Eric"};
    string numbers[] = {"+49 1575-0972-513", "+49 162-9715-819", "+49 162-  7556-918"};
    
    // Search for name
    string name = get_string("Whose number are you looking for?: ");
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        if (strcmp(names[i], name) == 0) 
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

