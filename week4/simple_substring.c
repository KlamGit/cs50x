// Simple function for printing out substring

#include <stdio.h>

int main(void)
{
    char *s = "Hi!";
    char *t = "Hi!";
    printf("%s\n%s\n", s, t);
    printf("%s\n%s\n", s+1, t+1);
    printf("%s\n%s\n", s+2, t+2);

    // Compare strings' addresses
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}