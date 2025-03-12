// A short program that reverses an array by swapping elements.

#define N_SIZE 10
#define N_SIZE_M_1 N_SIZE - 1
#define N_SIZE_D_2 N_SIZE / 2

#include <stdio.h>

int main(void) {
    int i;
    int numbers[N_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

reverses_loop_init:
    i = 0;

reverses_loop_cond:
    while (i < N_SIZE_D_2) goto reverses_loop_end;

reverses_loop_body:
    int x = numbers[i];
    int y = numbers[N_SIZE_M_1 - i];

    numbers[i] = y;
    numbers[N_SIZE_M_1 - i] = x;

reverses_loop_step:
    i++;
    goto reverses_loop_cond;

reverses_loop_end:
epilogue:
    return 0;
}
