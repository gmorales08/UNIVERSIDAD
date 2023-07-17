.data
	dato:    .space    4
	unos:    .space    4
	
	
.text
main:
	lw    $s0, dato
	lw    $s1, unos
	
	li    $s1, 0
	
	while:
		ble    $s0, $zero, end_while
	
	cuerpo_while:
		li     $t0, 2
		divu   $s0, $t0
		mflo   $t1
		#sw     $t1, dato
		mfhi   $t2
		
		if:
			beq    $t2, $zero, endif
			
		then:
			addiu  $s1, $s1, 1
		
		endif:
			divu   $s0, $s0, 2
		
		b      while	
			
	end_while:
		
		
li    $v0, 10
syscall