// Compares two strings using strcmp

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings
    if (strcmp(s, t) == 0)
    {
        printf("Same same\n");
    }
    else
    {
        printf("Different\n");
    }
    
    // Compare strings' addresses
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    // print strings and their addresses
    printf("s: %s at %p\n", s, s);
    printf("t: %s at %p\n", t, t);

}