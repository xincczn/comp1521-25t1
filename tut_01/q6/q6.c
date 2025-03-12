#include <stdio.h>

/**
 * 
 * Variables can be accessible depending on which region they are declared in.
 * This is known as "scope".
 * There are a few such as global variables having "global scope" and
 * local variables having "local scope" to the function they are declared in.
 * 
 * You may recall functions, if-statements and loops all having their own scope
 * as well and this is because they all define a "region" via curly braces.
 * This can be referred to as "region/block scope".
 */
int main(void) {
    /*
     * The only difference between the first while and for loop is that 
     * the counter (iterator) is "scoped" differently. `i` is accessible 
     * outside the while loop whereas `j` is scoped in the for loop.
     * 
     * However we can also write a while loop that mimics the scoping of a 
     * for loop by defining a block around the loop. 
     * Likewise 'k' isn't accessible outside of the pair of outer curly braces.
     */

    // While Loop #1 ===========================================================

    int i = 0;  // `i` is locally scoped to the main function
    while (i < 10) {
        printf("%d\n", i);
        i++;
    }

    // For Loop ================================================================

    for (int j = 0; j < 10; j++) {  // `j` is scoped to the loop
        printf("%d\n", j);
    }

    // While Loop #2 ===========================================================
    {
        int k = 0;
        while (k < 10) {
            printf("%d\n", k);
            k++;
        }
    }


    return 0;
}