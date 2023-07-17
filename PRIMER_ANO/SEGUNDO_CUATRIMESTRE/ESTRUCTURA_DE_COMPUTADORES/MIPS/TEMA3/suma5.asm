# PROGRAM sumar;
# VAR
		.data
# A,B,C: INTEGER;
A:		.space	4   # Copia en $s1
B:		.space	4   # Copia en $s2
C:		.space	4   # Copia en $s3
# Tiras auxiliares para E/S por terminal
tiraB:		.asciiz	"Valor de B = "
tiraC:		.asciiz	"Valor de C = "
tiraA:		.asciiz	"B + C = "
tiraeoln:	.asciiz	"\n"
# BEGIN
		.text
main:
# Write(“Valor de B: “); 
		li	$v0,4
		la	$a0,tiraB
		syscall
# Readln(B);
		li	$v0,5
		syscall
		sw	$v0,B
# Write(“Valor de C: “);
		li	$v0,4
		la	$a0,tiraC
		syscall
# Readln(C);
		li	$v0,5
		syscall
		sw	$v0,C
# A := B + C;
		lw 	$s2,B
		lw	$s3,C
		add	$s1,$s2,$s3
		sw	$s1,A
# Writeln(“B + C = “,A);
		li	$v0,4
		la	$a0,tiraA
		syscall
		li	$v0,1
		lw	$a0,A
		syscall
		li	$v0,4
		la	$a0,tiraeoln
		syscall
		li	$v0,5000000
# END.
		li	$v0,17
		li	$a0,0
		syscall