# A short program that reverses an array by swapping elements.

N_SIZE = 10					# #define N_SIZE 10
N_SIZE_M_1 = N_SIZE - 1				# #define N_SIZE_M_1 N_SIZE - 1
N_SIZE_D_2 = N_SIZE / 2				# #define N_SIZE_D_2 N_SIZE / 2

	.text
	# Registers:
	# - $t0: int i, the loop counter and index of the first number in the array
	# - $t1: The number of bytes in the array we need to offset for the i'th position.
	# - $t2: The base address of the array we are working with
	# - $t3: The first memory address in the array we are working with
	# - $t4: int x, the first of the two numbers to swap
	# - $t5, N_SIZE_M_1 - i, the index of the second number to swap
	# - $t6: The number of bytes in the array we need to offset for the (N_SIZE_M_1 - i)'th position.
	# - $t7: The second memory address in the array we are working with
	# - $t8: int y, the second of the two numbers to swap
main:						# int main(void) {

reverses_loop_init:
	li	$t0, 0				# i = 0;

reverses_loop_cond:
	bge	$t0, N_SIZE_D_2, reverses_loop_end	# while (i < N_SIZE_D_2) goto reverses_loop_end;

reverses_loop_body:
	mul	$t1, $t0, 4			# find offset for numbers[i]
	la	$t2, numbers
	add	$t3, $t1, $t2
	lw	$t4, ($t3)			# int x = numbers[i];


	li	$t5, N_SIZE_M_1			# find offset for numbers[N_SIZE_M_1 - i]
	sub	$t5, $t5, $t0
	mul	$t6, $t5, 4
	add	$t7, $t6, $t2
	lw	$t8, ($t7)			# int y = numbers[N_SIZE_M_1 - i];

	sw	$t8, ($t3)			# numbers[i] = y;
	sw	$t4, ($t7)			# numbers[N_SIZE_M_1 - i] = x;

reverses_loop_step:
	addi	$t0, $t0, 1			# i++;
	j	reverses_loop_cond		# goto reverses_loop_cond;

reverses_loop_end:
epilogue:
	jr	$ra				# return 0;

	.data
numbers:					# int numbers[N_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	.word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9