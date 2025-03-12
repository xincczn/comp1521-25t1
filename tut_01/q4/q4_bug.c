#include <stdio.h>

/**
 * In C, we define strings as an array of characters terminated by '\0'.
 * All C library functions expects strings to be null-terminated.
 * 
 * A situation where a malformed string is used by a function that expects the 
 * string to be null-terminated is referred to as "undefined behaviour".
 * 
 * It is undefined as C library functions weren't coded to handle malformed 
 * strings and so anything could/can happen.
 */
int main(void) {
    char str[10];
    str[0] = 'H';
    str[1] = 'i';
    // `str` isn't null-terminated and will unfortunately cause
    // `printf()` to produce unintended behaviour.

    printf("%s", str);  // line of code that causes error

    /**
     * Ultimately what happens depends on the compiler that compiled the code.
     * 
     * dcc q4_bug.c -o q4_bug
     * `dcc` being a compiler that complains when uninitialised memory is
     * accessed will stop and report an error when `str[2]` is accessed by
     * `printf()`.
     * 
     * gcc q4_bug.c -o q4_bug
     * `gcc` on the other hand doesn't care when uninitialised memory is 
     * read as long as the memory isn't invalid. 
     */

    return 0;
}
