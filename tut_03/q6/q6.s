# A simple program that will print 10 numbers from an array

N_SIZE = 10


	.text
	# Registers:
	# - $t0: int i, the loop counter (i.e. the index of the array)
	# - $t1: The number of bytes in the array we need to offset
	# - $t2: The base address of the array we are reading from
	# - $t3: The memory address we will load a 4-byte integer from
main:
print_loop_init:
	li	$t0, 0				# i = 0;

print_loop_cond:
	bge	$t0, N_SIZE, print_loop_end	# if (i >= N_SIZE) goto print_loop_end; 

print_loop_body:
	mul	$t1, $t0, 4			# find offset for numbers[i]
	la	$t2, numbers
	add	$t3, $t1, $t2 
	lw	$a0, ($t3)

	li	$v0, 1				# printf("%d", numbers[i]);
	syscall

	li	$a0, '\n'			# printf("\n");
	li	$v0, 11
	syscall

print_loop_step:
	addi	$t0, $t0, 1			# i++;
	j	print_loop_cond			# goto print_loop_cond;

print_loop_end:
epilogue:
	jr	$ra				# return 0;

	.data
numbers:
	.word	0, 1, 2, 3, 4, 5, 6, 7, 8, 9	# int numbers[N_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};