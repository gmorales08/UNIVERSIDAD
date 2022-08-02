#float x1, y1, x2, y2, xp, yp;
#int main (void) {
#	yp = ((xp-x1) * (y2-y1)) / (x2-x1) + y1;
#	return 0;
#}

.data
	x1:    .space    4
	y1:    .space    4
	x2:    .space    4
	y2:    .space    4
	xp:    .space    4
	yp:    .space    4
	
.text
	l.s      $f20, x1
	l.s      $f21, y1
	l.s      $f22, x2
	l.s      $f23, y2
	l.s      $f24, xp
	l.s      $f25, yp
	
	sub.s    $f2, $f24, $f20
	sub.s    $f3, $f23, $f21
	mul.s    $f2, $f2, $f3
	
	sub.s    $f3, $f22, $f20
	add.s    $f3, $f3, $f21
	
	div.s    $f2, $f2, $f3
	s.s      $f2, yp
	

li      $v0, 17
li      $at,  0
syscall