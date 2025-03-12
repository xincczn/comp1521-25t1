#include <stdio.h>

char *s1 = "abc";  // global variable

void print_strings(char *local_string);

int main(void) {
  char *s2 = "def";  // local variable (main function)

  print_strings(s2);

  return 0;
}

void print_strings(char *local_string) {
    char *s3 = "ghi";  // local variable (print_strings function)

    // `s1` which is declared globally in this file, can be called and used anywhere.
    printf("s1: %s\n", s1);  

    // `s2` which is declared locally in the main function had to be passed into
    // this function as an argument `local_string` in order to be used.
    printf("s2: %s\n", local_string);

    // `s3` which is declared locally in this function and can be used within
    // this function.
    // Note: `s3` cannot be used in the main function since its impossible to
    //       pass `s3` back up. Whys that?
    printf("s3: %s\n", s3);
}
