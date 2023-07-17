	.data
# int n, perfecto;
n:	.space	4
perfecto:
	.space	4
# Las variables i y suma son temporales
	.text
main:				# int main (void) {
	li	$t0,1		#	suma = 1;
	li	$t1,2		#	i = 2;
while:				# 	while (i < n) {
	lw	$s0,n
	bge	$t1,$s0,end_while
if:				# 		if (n % i == 0)
	rem	$t2,$s0,$t1
	bne	$t2,$zero,end_if
then:				#		then (parte cierto)
	add     $t0,$t0,$t1	#			suma = suma + i;
end_if:
	addi    $t1,$t1,1	#		i++;
	j	while		#	}
end_while:
	seq	$s1,$s0,$t0	#	perfecto = (n == suma);
	sw	$s1,perfecto
	li	$v0,17		# 	return 0;
	li	$a0,0
	syscall
end_main:			# }
