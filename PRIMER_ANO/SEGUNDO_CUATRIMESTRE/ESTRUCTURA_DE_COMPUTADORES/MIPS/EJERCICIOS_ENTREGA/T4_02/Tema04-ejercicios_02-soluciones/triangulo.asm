	.data
# int lon1, lon2, lon3, triang;
lon1:	.space	4
lon2:	.space	4
lon3:	.space	4
triang:	.space	4
	.text
main:				# int main (void) {
	lw	$s2,lon2	#	tmp1 = lon2 + lon3;
	lw	$s3,lon3
	addu	$t1,$s2,$s3
	lw	$s1,lon1	#	tmp2 = lon1 + lon3;
	addu	$t2,$s1,$s3
	addu	$t3,$s1,$s2	#	tmp3 = lon1 + lon2;
if:				#	if ( (lon1 < tmp1) && (lon2 < tmp2)
				#			   && (lon3 < tmp3) )
	bge	$s1,$t1,else
	bge	$s2,$t2,else
	bge	$s3,$t3,else
then:				#		then (parte cierto)
	li	$s4,1		#			triang = 1;
	sw	$s4,triang
	b	endif
else:				#		else (parte falso)
	li	$s4,0		#			triang = 0;
	sw	$s4,triang
endif:
	li	$v0,17		#	return 0;
	li	$a0,0
	syscall
end_main:			# }
