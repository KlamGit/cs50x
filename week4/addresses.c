// Stores and prints an integer via its address

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("The value of int n is %i.\nand it is located at %p\n", n, &n);
    printf("The value located at %p, the pointer address is %i\n", p,*p);
}