// Using malloc

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    if (s == NULL)
    {
        return 1;
    }
    printf("s: \n");
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);
    return 0;
}