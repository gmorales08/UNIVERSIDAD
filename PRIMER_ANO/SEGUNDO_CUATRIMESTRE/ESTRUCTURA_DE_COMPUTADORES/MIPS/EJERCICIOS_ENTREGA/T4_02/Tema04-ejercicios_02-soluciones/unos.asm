	.data
# int dato, unos;
dato:	.space	4  # Copia en $s0
unos:	.space	4  # Copia en $s1
# Las variables tmp y mascara son temporales y pueden residir en registros
	.text
main:				# int main (void) {
	li	$s1,0		#	unos = 0;
	lw	$t0,dato	#	tmp = dato;
	li	$t1,0x80000000	#	mascara = 0x80000000;
while:				#	while (tmp != 0) {
	beq	$t0,$zero,end_while
if:				#		if (tmp & mascara != 0)
	and	$t2,$t0,$t1
	beq	$t2,$zero,end_if
then:				#		then (parte cierto)
	addi	$s1,$s1,1	#       		unos = unos + 1;
end_if:
	sll	$t0,$t0,1	#		tmp = tmp << 1;
	b	while		#	}
end_while:
	sw	$s1,unos	#	Sincronizar resultado
	li	$v0,17		# 	return 0;
	li	$a0,0
	syscall
end_main:			# }
