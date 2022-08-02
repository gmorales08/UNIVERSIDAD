.data
	x1:    .space    4
	y1:    .space    4
	x2:    .space    4
	y2:    .space    4
	xp:    .space    4
	yp:    .space    4
	
.text
	# xp - x1
	lw      $s0, xp
	lw      $s1, x1
	sub     $t0, $s0, $s1
	
	# y2 - y1
	lw      $s2, y2
	lw      $s3, y1
	sub     $t1, $s2, $s3
	
	mul     $t0, $t0, $t1
	
	
	# x2 - x1
	lw      $s4, x2
	lw      $s5, x1
	sub     $t1, $s4, $s5
	
	lw      $s6, y1
	add     $t1, $t1, $s6
	
	
	div     $s7, $t0, $t1
	sw      $s7, yp

		
li	$v0,17
li	$a0,0
syscall
	