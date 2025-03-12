	.text
main:
	la	$t0, aa				# 0x10010000

	lw	$t0, bb				# 666

	lb	$t0, bb				# 0xffffff9a (on CSE)

	lb	$t0, aa+4			# 666

	la	$t1, cc
	lw	$t0, ($t1)			# 1

	la	$t1, cc
	lw	$t0, 8($t1)			# 5

	
	li	$t1, 8
	lw	$t0, cc($t1)			# 5

	la	$t1, cc
	lw	$t0, 2($t1)			# (memory alignment error)

	.data
aa:						# 0x10010000
	.word	42
bb:						# 0x10010004
	.word	666
cc:						# 0x10010008
	.word	1
	.word	3				# 0x1001000C
	.word	5				# 0x10010010
	.word	7				# 0x10010014
