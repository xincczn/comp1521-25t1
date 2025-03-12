# A simple program that adds 42 to each element of an array

N_SIZE = 10					# #define N_SIZE 10

	.text
	# Registers:
	# - $t0: int i, the loop counter and the index of the array
	# - $t1: The number of bytes in the array we need to offset.
	# - $t2: The base address of the array we are working with
	# - $t3: The memory address we will load/store a 4-byte integer from
	# - $t5: The 4-byte integer we may modify and store back to memory
main:						# int main(void) {

add_42_loop_init:
	li	$t0, 0				# i = 0;

add_42_loop_cond:
	bge	$t0, N_SIZE, add_42_loop_end	# if (i >= N_SIZE) goto add_42_loop_end;

add_42_loop_body:
	mul	$t1, $t0, 4			# find offset for numbers[i]
	la	$t2, numbers
        add	$t3, $t1, $t2
        lw	$t5, ($t3)

negative_if_cond:
	bge	$t5, 0, negative_if_end		# if (numbers[i] >= 0) goto negative_if_end;

negative_if_body:
	addi	$t5, $t5, 42			# numbers[i] += 42;
	sw	$t5, ($t3) 

negative_if_end:
add_42_loop_step:
	addi	$t0, $t0, 1			# i++;
	j	add_42_loop_cond		# goto add_42_loop_cond;

add_42_loop_end:
epilogue:
	jr	$ra				# return 0;

	.data
numbers:					# int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};
	.word	0, 1, 2, -3, 4, -5, 6, -7, 8, 9