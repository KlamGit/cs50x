// Avoid garbage values by allocating and initialising memory

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[1024] = {0}; // Initialising allocated memory in order to avoid garbage memory
    for (int i = 0; i < 1024; i++)
{
    printf("%i\n", scores[i]);
}
}