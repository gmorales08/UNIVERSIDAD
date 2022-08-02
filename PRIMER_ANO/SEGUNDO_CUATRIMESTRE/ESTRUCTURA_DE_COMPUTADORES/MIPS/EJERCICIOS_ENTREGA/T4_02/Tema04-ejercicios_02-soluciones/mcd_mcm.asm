	.data
# int x,y,mcd,mcm;
x:	.space	4
y:	.space	4
mcd:	.space	4
mcm:	.space	4
# Las variables tmp y resto son temporales y pueden residir en registros
	.text
main:				# int main (void) {
IF1:				# 	if (x >= y)  
	lw	$s0,x
	lw	$s1,y
	bge	$s0,$s1,THEN1 
ELSE1:				#	else { (parte falso)	 
	move	$t0,$s1		# 		tmp = y; 
	move	$s2,$s0		# 		mcd = x; 
	b	ENDIF1		#	}
THEN1:				#	then { (parte cierto)
	move	$t0,$s0		#		tmp = x;
	move	$s2,$s1		#		mcd = y;
ENDIF1:				#	}
DO:				#	do {
	rem	$t1,$t0,$s2	#		resto = tmp % mcd;
IF2:				#		if (resto != 0)
	beq	$t1,$zero,ENDIF2 
THEN2:				#		then { (parte cierto)
	move	$t0,$s2		#			tmp = mcd;
	move	$s2,$t1		#			mcd = resto;
ENDIF2:				#		}
WHILE:	bne	$t1,$zero,DO	#	} while (resto != 0); 
	mul	$s3,$s0,$s1	#	mcm = (x * y) / mcd;
	div	$s3,$s3,$s2
	sw	$s2,mcd		# 	Sincronizar variables
	sw	$s3,mcm
	li	$v0,17		# 	return 0;
	li	$a0,0
	syscall
end_main:			# }
