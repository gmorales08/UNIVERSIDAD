#int n, f;
#register int f1, f2, i;
#int main (void) {
#	f2 = 0;
#	f1 = 0;
#	for (i = 2; i <= n; i++) {
#		f = f1 + f2;
#		f2 = f1;
#		f1 = f;
#	}
#	return 0;
#}

.data
	n:    .space    4
	f:    .space    4
	
.text
	lw    $s0, n

	li    $t2, 0 #f2
	li    $t1, 0 #f1
	li    $t0, 2 #i
	
	for:
		bgt      $t0, $s0, endfor
		add      $s1, $t1, $t2
		sw       $s1, f
		move     $t2, $t1
		lw       $t1, f
		addiu    $t0, $t0, 1
		b        for
	endfor:
		sw       $s1, f


li	$v0,17
li	$a0,0
syscall