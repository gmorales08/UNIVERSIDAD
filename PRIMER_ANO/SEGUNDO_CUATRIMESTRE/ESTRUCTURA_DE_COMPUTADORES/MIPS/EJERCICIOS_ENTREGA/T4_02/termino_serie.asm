#int n, tn;
#register int i;
#int main (void) {
#	tn = 1;
#	for (i = 1; i <= n; i++) {
#		tn = 2 * tn;
#		if (i % 2 == 0)
#			tn = tn-1;
#	}
#	return 0;
#}

.data
	n:     .space    4
	tn:    .space    4

.text
	li    $s1, 1 # tn = 1
	li    $t0, 1 # i = 1
	
	for:
	lw    $s0, n	
	bgt      $t0, $s0, endfor
	cuerpo_for:
	mul      $s1, $s1, 2
		 if:
		 #li      $t2, 2
		 #div     $t0, $t2
		 #mflo    $t1
		 rem     $t1, $t0, 2
		 bnez    $t1, endif
		 cuerpo_if:
		 addi    $s1, $s1, -1
		 endif: 
	addiu    $t0, $t0, 1
	b        for
	endfor:	
	sw       $s1, tn
	
li	$v0,17
li	$a0,0
syscall