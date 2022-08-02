#int x, y, mcd, mcm;
#register int tmp, resto;
#int main(void) {
#	tmp = x;
#	mcd = y;
#	do {
#		resto = tmp % mcd;
#		if (resto <> 0) {
#			tmp = mcd;
#			mcd = resto;
#		}
#	} while (resto != 0);
#	mcm = x * y / mcd;
#	return 0;
#}

.data
	x:      .space    4 
	y:      .space    4 
	mcd:    .space    4 
	mcm:    .space    4 

.text
	lw      $s0, x 
	move    $t0, $s0 # t0 <- tmp
	lw      $s1, y
	lw      $s2, mcd
	move    $s2, $s1
	
	do:
	rem     $t1, $t0, $s2 # t1 <- resto
	if:
	beqz    $t1, end_if
	then:
	move    $t0, $s2
	move    $s2, $t1
	end_if:
	while:
	bnez    $t1, do
	end_do_while:
	mul     $t0, $s0, $s1
	div     $s3, $t0, $s2
	
	sw      $s2, mcd
	sw      $s3, mcm

li	$v0,17
li	$a0,0
syscall