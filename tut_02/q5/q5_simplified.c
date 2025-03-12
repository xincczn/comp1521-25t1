// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.
// Simplified C version.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

x_le_square_cond:
    if (x <= SQUARE_MAX) goto x_le_square_else;
x_le_square_body:
    y = x * x;
    printf("%d\n", y);
    
    goto x_le_square_end;
    
x_le_square_else:
    printf("square too big for 32 bits\n");

x_le_square_end:
    return 0;
}
