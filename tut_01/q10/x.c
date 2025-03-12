// Simple program that prints out Hi

#include <stdio.h>

#define N 10

int main(void) {
    char str[N] = { 'H', 'i', '\0' };
    
    printf("%s\n", str);

    return 0;
}