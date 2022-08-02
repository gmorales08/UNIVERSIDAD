#int lon1, lon2, lon3, triang;
#register int tmp1, tmp2, tmp3; // Temporales
#int main(void) {
#	tmp1 = lon2 + lon3; tmp2 = lon1 + lon3; tmp3 = lon1 + lon2;
#	if ( (lon1<tmp1) && (lon2<tmp2) && (lon3<tmp3) )
#		triang = 1;
#	else
#		triang = 0;
#	return 0;
#}

.data
	lon1:      .space    4
	lon2:      .space    4
	lon3:      .space    4
	triang:    .space    4


.text
	lw      $s0, lon1
	lw      $s1, lon2
	lw      $s2, lon3
	lw      $s3, triang
	
	addu    $t0, $s1, $s2
	addu    $t1, $s0, $s2
	addu    $t2, $s0, $s1
	
	if:
		slt     $t0, $s0, $t0
		slt     $t1, $s1, $t1
		slt     $t2, $s2, $t2
		
		and     $t0, $t0, $t1
		and     $t1, $t0, $t2
		
		beqz    $t1, else
	then:
		li      $t0, 1
		sw      $t0, triang
		b       endif
	else:
		sw      $zero, triang
	endif:
	
	
li	$v0,17
li	$a0,0
syscall
	