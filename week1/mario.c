// prints a row of 4 question marks horizontally
#include <stdio.h>

void horizontal(int width);
void vertical(int height);
void grid(int width, int height);

int main (void) {
    const int rows = 3;
    const int columns = 4;
    horizontal(rows);
    vertical(columns);
    grid(rows, columns);
}

// prints a row of 4 question marks horizontally
void horizontal(int width) {
    for (int i = 0; i < width; i++) {
        printf("?");
    }
    printf("\n");
}

// prints a column of 4 bricks vertically
void vertical(int height) {
    for (int i = 0; i < height; i++) {
        printf("#\n");
    }
}

//prints a 3*3 grid of bricks with nested loops
void grid(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("#");
        }
        printf("\n");
    }
}
