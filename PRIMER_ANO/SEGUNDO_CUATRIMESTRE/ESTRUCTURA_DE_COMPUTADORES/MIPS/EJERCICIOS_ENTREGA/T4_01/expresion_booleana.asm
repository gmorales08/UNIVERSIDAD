.data
	x:     .space    4
	y:     .space    4
	xb:    .space    1
	yb:    .space    1
	zb:    .space    1
	
	
.text
	#zb = (x<=y) || (xb & yb)
	lw      $s0, x
	lw      $s1, y
	sleu    $t0, $s0, $s1
	
	lb      $s2, xb
	lb      $s3, yb
	and     $t1, $s2, $s3
	
	or      $s4, $t0, $t1
	sb      $s4, zb
	
	
li	$v0,17
li	$a0,0
syscall