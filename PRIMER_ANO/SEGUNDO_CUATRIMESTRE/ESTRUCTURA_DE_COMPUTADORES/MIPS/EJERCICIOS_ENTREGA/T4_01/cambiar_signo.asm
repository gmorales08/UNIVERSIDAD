.data
	x:    .space    4
	y:    .space    4
	

.text 
	# y = (x ^ 0xFFFFFFFF) + 1
	lw      $s0, x
	xori    $t0, $s0, 0xFFFFFFFF
	addi    $s1, $t0, 1
	sw      $s1, y
	
	
li	$v0,17
li	$a0,0
syscall