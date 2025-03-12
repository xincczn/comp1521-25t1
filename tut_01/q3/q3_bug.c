#include <stdio.h>

int *get_num_ptr(void);
void fn(int *num);

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);

    return 0;
}

/**
 * All function calls are loaded onto the "stack" part of memory.
 * This means that local variables are also loaded on the stack.
 * 
 * Functions get "cleaned up" when they return (finish executing),
 * and this means that local variables live and die with their functions.
 * 
 * Because of this, the variable `x` doesn't exist once `get_num_ptr()`
 * returns and thus the address of `x` gets invalidated.
 */
int *get_num_ptr(void) {
    int x = 42;  // `x` exists while get_num_ptr() exists

    fn(&x);  // `x` would still exist during the execution of fn()

    // `x` still exists here as get_num_ptr() hasn't returned yet

    return &x;  // line of code that causes error
}

void fn(int *num) {
    printf("%d\n", *num);

    return; 
}
