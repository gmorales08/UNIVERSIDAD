	.data
# int n, f: INTEGER;
n:	.space  4   # $s0
f:	.space  4   # $s1
# Las variables i, f1 y f2 son temporales
	.text
main:				# int main (void) {
	li	$t2,0		#	f2 = 0;
	li	$t1,1		#	f1 = 1;
for:				#	for (i = 2; i <= n; i++)
	li	$t0,2		#       	i = 2
condicion:			#		i <= n
	lw	$s0,n
	bgt	$t0,$s0,end_for
cuerpo:				#	{
	add	$s1,$t1,$t2	#		f = f1 + f2;
	move	$t2,$t1		#		f2 = f1;
	move	$t1,$s1		#		f1 = f;
	addi	$t0,$t0,1	#		i++;
	j	condicion	#	}
end_for:
	sw	$s1,f		#	Sincronizar resultado
	li	$v0,17		#	return 0;
	li	$a0,0
	syscall
end_main:			# }
