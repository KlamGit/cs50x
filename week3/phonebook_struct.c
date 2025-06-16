// Implements a phone book with structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    /* data */
    string name;
    string number;
} person;

int main(void)
{
    person people[3];
    
    people[0].name = "Mishu";
    people[0].number = "+49 1575-0972-513";

    people[1].name = "Marius";
    people[1].number = "+49 162-9715-819";

    people[2].name = "Eric";
    people[2].number = "+49 162-7556-918";

    // Search for name
    string name = get_string("Name please?: ");
    for (int i = 0; i < sizeof(people) / sizeof(people[0]); i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf ("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf ("Not found\n");
    return 1;

}
