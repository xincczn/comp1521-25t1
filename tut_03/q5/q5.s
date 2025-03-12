# A simple program that will read 10 numbers into an array

N_SIZE = 10

	.text
	# Registers:
	# - $t0: int i, the loop counter (i.e. the index of the array)
	# - $t1: The number of bytes in the array we need to offset
	# - $t2: The base address of the array we are reading into
	# - $t3: The memory address we will store a 4-byte integer into
main:
scan_loop_init:
	li	$t0, 0				# i = 0;

scan_loop_cond:
	bge	$t0, N_SIZE, scan_loop_end	# if (i >= N_SIZE) goto scan_loop_end;

scan_loop_body:
	li	$v0, 5				# scanf("%d", &numbers[i]);
	syscall

	mul	$t1, $t0, 4			# find offset for numbers[i]
	la	$t2, numbers
	add	$t3, $t1, $t2
	sw	$v0, ($t3)


scan_loop_step:
	addi	$t0, $t0, 1			# i++;
	j	scan_loop_cond			# goto scan_loop_cond;

scan_loop_end:
epilogue:
	jr	$ra				# return 0;

	.data
numbers:
	.word	0, 0, 0, 0, 0, 0, 0, 0, 0, 0	# int numbers[10] = {0};