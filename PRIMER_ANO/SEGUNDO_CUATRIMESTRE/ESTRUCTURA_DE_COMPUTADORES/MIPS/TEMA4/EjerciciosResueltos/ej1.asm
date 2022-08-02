.data
	a:     .space	4
	b:     .space	4
	c:     .space	4
	d:     .space	4
	e:     .space	4
	
	signo: .space    1
	
	
.text
main:
	#e := a + (b*c) / 4 - d*(a+2)
	lw    $s0, a
	lw    $s1, b
	lw    $s2, c
	lw    $s3, d
	
	mul   $t0, $s1, $s2     # (b * c)
	li    $t5, 4
	div   $t1, $t0, $t5     # (b * c) / 4
	add   $t2, $s0, $t1     # a + (b * c) / 4
	addiu $s0, $s0, 2       # (a + 2)
	mul   $t3, $s3, $s0     # d * (a + 2)
	subu  $s4, $t2, $t3     # a + (b * c) / 4 - d * (a + 2)
	
	sw    $s4, e
	
	# if e > 0; signo = '+', else, signo = '-'
	if:
		bge   $s4, $zero, then
	
	else: 
		li    $s5, '-'
		sb    $s5, signo
		b     endif	
				
	then: 	
		li    $s5, '+'
		sb    $s5, signo		
	
	endif:
	
	
li    $v0, 10
syscall
	
	
	