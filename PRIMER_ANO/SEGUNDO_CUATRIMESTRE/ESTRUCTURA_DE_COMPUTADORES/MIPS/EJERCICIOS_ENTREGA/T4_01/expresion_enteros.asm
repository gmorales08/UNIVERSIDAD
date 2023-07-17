.data
	x:    .space    4
	y:    .space    4
	z:    .space    4
	w:    .space    4

		
.text
	# w = x - y * (z + 2);
	
	lw      $s0, z
	addi	$t0, $s0, 2
	lw      $s1, y
	mul     $t0, $s1, $t0
	lw      $s2, x
	sub     $s3, $s2, $t0
	sw      $s3, w


li	$v0,17
li	$a0,0
syscall