#include <stdio.h>

int main(void) {
    /**
     * `getchar()` returns an ascii character as an integer (0-127)
     * or EOF (-1) if Ctrl-D is pressed which signals the end of file.
     * 
     * We capture the value in `ch` which then gets compared with `EOF`
     */
    int ch;
    int count = 0;
    while ((ch = getchar()) != EOF) {
        count += 1;
    }

    printf("Characters entered = %d\n", count);

}