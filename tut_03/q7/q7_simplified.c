// A simple program that adds 42 to each element of an array

#define N_SIZE 10

int main(void) {
    int i;
    int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};

add_42_loop_init:
    i = 0;

add_42_loop_cond:
    if (i >= N_SIZE) goto add_42_loop_end;

add_42_loop_body:

negative_if_cond:
    if (numbers[i] >= 0) goto negative_if_end;

negative_if_body:
    numbers[i] += 42;

negative_if_end:
add_42_loop_step:
    i++;
    goto add_42_loop_cond;

    add_42_loop_end:
epilogue:
    return 0;
}
