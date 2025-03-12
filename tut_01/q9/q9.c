#include <stdio.h>
#include <stdlib.h>

/**
 * Because `argv` is an array of strings, all elements are strings which 
 * cannot be summed together.
 * 
 * Instead we need to convert the string into an int which is what `atoi()` does.
 * `atoi()` returns 0 is the string is not a number.
 */
int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 0; i < argc; i++) {
        sum += atoi(argv[i]);
    }

    printf("sum of command-line arguments = %d\n", sum);

    return 0;
}
