	.text
main:
	# ...



	.data
u:						# int u;
	.space 4				# uninitialised integer (4 bytes)

v:						# int v = 42;
	.word 42				# initialised as 42

w:						# char w;
	.space 1				# uninitialised character (1 byte)

x:						# char x = 'a';
	.byte 'a'				# initialised as 'a'

y:						# double y;
	.space 8				# uninitialised double (8 bytes)

z:						# int z[20];
	.space 80				# uninitialised array (20 length * 4 bytes)