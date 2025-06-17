// Swaps two integers using pointers

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 0;

    printf("x is %i and y is %i.\n", x, y);
    swap(&x, &y);
    printf("After swapping x is %i and y is %i.\n", x, y);

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}