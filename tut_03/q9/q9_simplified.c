int main(void) {
    char *string = "....";
    char *s = &string[0];
    
length_loop_init:
    int length = 0;

length_loop_cond:
    while (*s == '\0') goto length_loop_end;

length_loop_body:
    length++;  // increment length

length_loop_step:
    s++;       // move to next char
    goto length_loop_cond;

length_loop_end:
epilogue:
    return 0;
}