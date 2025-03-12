#include <stdio.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);

    free(num);  // malloc'd memory must be free'd (cleaned up) by you.
}

/**
 * To circumvent the issue and extend the local variable's lifetime,
 * we can allocate `x` onto the "heap" part of memory instead.
 * This can be done using `malloc()` which allocates memory in the heap.
 * 
 * Unlike the stack, the heap doesn't get cleaned up by the compiler 
 * and instead is cleaned up by you calling on a function like `free()`.
 * 
 * As such, even if `get_num_ptr()` finishes executing, the memory address
 * `x` is pointing to will be valid.  
 */
int *get_num_ptr(void) {
    int *x = malloc(sizeof(int));  // Note: `x` still lives and dies with the function
    *x = 42;                       //       But the value is no longer stored in `x`

    return x;  // We return an address stored in `x` back up 
}
