// Declare string without cs50 library

#include <stdio.h>
#include <stdlib.h> // To use functions such as free, malloc
#include <sys/types.h>

int main(void)
{
    
    char *s =   NULL; // Represents an empty pointer
    size_t len = 0; // Type used to express sizes (always ≥ 0)

    printf("What would you like to say today?: ");
    ssize_t read = getline(&s, &len, stdin); // Like size_t, but can be negative (e.g., for errors)

    if (read != -1)
    {
        printf("You said: %s", s);

    }
    else
    {
        printf("Error reading input.\n");
    }

    free(s); // Frees up allocated memory
    return 0;
}