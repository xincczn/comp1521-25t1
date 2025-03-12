// A simple program that will print 10 numbers from an array

#define N_SIZE 10

#include <stdio.h>

int main(void) {
    int i;
    int numbers[N_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

print_loop_init:
    i = 0;

print_loop_cond:
    if (i >= N_SIZE) goto print_loop_end; 

print_loop_body:
    printf("%d\n", numbers[i]);

print_loop_step:
    i++;
    goto print_loop_cond;

print_loop_end:
epilogue:
    return 0;
}