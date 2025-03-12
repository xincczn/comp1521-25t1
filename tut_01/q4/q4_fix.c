#include <stdio.h>

/**
 * There are many ways to fix the code.
 */
int main(void) {
    char str_1[10];
    str_1[0] = 'H';
    str_1[1] = 'i';
    str_1[2] = '\0';  // `str_1` is fixed by adding the null-terminator at the end

    printf("%s\n", str_1);

    char str_2[10] = {0};  // `str_2` is fixed by initialising all elements to 0
    str_2[0] = 'H';        // Since '\0' is just 0, `str[2]` defaults to being
    str_2[1] = 'i';        // a null-terminator.

    printf("%s\n", str_2);
    
    char str_3[10] = "Hi";  // `str_3` is fixed by being initialised with a
                            // string literal are always null-terminated.
    printf("%s\n", str_3);  // Note: Convention wise, we should always declare 
                            //       strings like `str_3` as its the safest.

    return 0;
}