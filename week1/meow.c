// Learning better design
// Abstraction
#include <stdio.h>
#include <cs50.h>

int get_positive_int (void);
void meow(int n);

int main(void)
{
    int n = get_positive_int();
    meow(n);
}

int get_positive_int(void)
{
    int n;
    do {
        n = get_int("Enter a positive integer: ");
    } while (n < 1);
    return n;
}   

// meow some number of times
void meow(int n)
{
    for (int j = 0; j < n; j++) {
        printf("meow %i\n", j);
    }
}