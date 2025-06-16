// Prints a string's characters

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int main(void)
{
    char *s = NULL;
    size_t len = 0;

    printf("What would you like to write down today? ");
    ssize_t read = getline(&s, &len, stdin);

    if (read != -1)
    {
        printf("You said:\n%s - that has a length of %lu\n", s, strlen(s));
        
        for (int i = 0; i < strlen(s); i++)
        {
            printf("Address of %i-th place: %p\n", i, &s[i]); // Address of character
            printf("Current character in the %i-th place: %c\n", i, s[i]); // Using array indexing
            printf("Current character in the %i-th place (using pointer arithmatic): %c\n", i, *(s+i)); // Same as above using pointer arithmetic
            printf("Substring starting from the %i-th place, which has the address of %p: (prints substrings via pointer arithmetic): %s\n", i, &s[i], s+i); // Prints substrings via pointer arithmetic

        }
    }
    else
    {
        printf("Eror reading input.\n");
    }

    free(s); // Frees up allocated memory
    return 0;
}