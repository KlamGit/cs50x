// Prints a string's address as well as the addresses of its chars

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Type out a random word: ");
    printf("%s\n", s);
    printf("%p\n\n\n", s);
    for (int i = 0; i < strlen(s); i++) 
    {
        printf("%p\n", &s[i]);
    }
    printf("Length of string s is: %lu\n", strlen(s));
    printf("Length of pointer of string s is: %lu\n", sizeof(s));
}