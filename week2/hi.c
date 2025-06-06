// Arrays of strings
// Prints string's ASCII codes, including NUL

#include<cs50.h>
#include <stdio.h>

int main(void)
{
    string words [2];
    words[0] = "Hi!"; 
    words[1] = "Bye!";
    
    printf("%i %i %i %i\n%i %i %i %i %i\n", words[0][0], words[0][1], words[0][2], words[0][3], words[1][0], words[1][1], words[1][2], words[1][3], words[1][4]);
    printf("%c %c %c %c\n %c %c %c %c %c\n", words[0][0], words[0][1], words[0][2], words[0][3], words[1][0], words[1][1], words[1][2], words[1][3], words[1][4]);
}