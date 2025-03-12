#include <stdio.h>

/**
 * ./<program_name> <argument 1> <argument 2> ...
 * 
 * `argc` is short for "argument count" and is the total amount of arguments
 * passed into the program via the terminal.
 * 
 * Note: The program name itself counts as an argument.
 * 
 * 
 * `argv` is short for "argument vector" (math way of calling an array) 
 * and is an array of all the arguments (as strings) passed into the 
 * program via the terminal.
 * 
 * Hence the declaration:
 *      char *       -> string type
 *      []           -> variable is an array
 *      char *argv[] -> array of strings
 * 
 * Example: [<program_name>, <argument 1>, <argument 2>, ...]
 * 
 * Note: argv[0] will always be the program name.
 *  
 */
int main(int argc, char *argv[]) {
    printf("argc=%d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    return 0;
}