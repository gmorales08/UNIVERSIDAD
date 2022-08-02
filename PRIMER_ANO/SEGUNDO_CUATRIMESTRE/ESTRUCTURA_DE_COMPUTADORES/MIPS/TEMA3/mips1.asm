.data

		.eqv N,16
vector: 	.word 1,-3,55,90
		.word 0,43,99,-34
maximo: 	.space 4
tira: 		.asciiz "El valor máximo es: "
tira_eoln: 	.asciiz "\n"
		.align 2
a: 		.word 25
b: 		.byte 0,1,2,3,4
		.align 1
c:		.half 10

.text
	li $v0,12
	li $0,0
	syscall