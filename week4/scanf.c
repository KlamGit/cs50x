// Gets an int from user using scanf

#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n); // The \n in scanf does not mean “skip any whitespace” — instead, it tells scanf:
                    // “Wait until the user presses Enter and at least one non-whitespace character comes in after that.”
    printf("n: %i\n", n);
}