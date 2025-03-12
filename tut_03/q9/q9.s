	.text
main:						# int main(void) {
	li	$t1, 0				# int length = 0;


length_loop_init:
	la	$t0, string			# char *s = &string[0];

length_loop_cond:
	lb	$t2, ($t0)
	beq	$t2, $0, length_loop_end			# while (*s != '\0') {

length_loop_body:
	addi	$t1, $t1, 1			# length++;  // increment length

length_loop_step:
	addi	$t0, $t0, 1			# s++;       // move to next char
	j	length_loop_cond		# goto length_loop_cond;

length_loop_end:
epilogue:
	jr	$ra				# return 0;


	.data
string:						# char *string = "....";
	.asciiz	"...."