	.data
# int n, tn: INTEGER;
n:	.space	4   # $s0
tn:	.space	4   # $s1
# La variable i es temporal y puede residir en registros
	.text
main:				# int main (void) {
	li	$s1,1		#	tn = 1;
for:				#	for (i = 1; i <= n; i++)
	li	$t0,1		#		i = 1
condicion:
	lw	$s0,n		#		i <= n
	bgt	$t0,$s0,end_for
cuerpo:				# 	{
	add	$s1,$s1,$s1	#		tn = 2 * tn;
if:				#		if (i % 2 == 0)
	rem	$t1,$t0,2
	bne	$t1,$zero,end_if
then:				#		then (parte cierto)
	addi	$s1,$s1,-1	#			tn = tn - 1;
end_if:
	addiu	$t0,$t0,1	#		i++
	b	condicion	#	}
end_for:
	sw	$s1,tn		# 	Sincronizar resultado
	li	$v0,17		# 	return 0;
	li	$a0,0
	syscall
end_main:			# }
