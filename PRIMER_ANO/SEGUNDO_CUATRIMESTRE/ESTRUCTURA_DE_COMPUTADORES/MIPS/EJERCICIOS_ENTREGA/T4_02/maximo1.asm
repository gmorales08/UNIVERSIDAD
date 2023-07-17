.data
	x:         .space    4
	y:         .space    4
	maximo:    .space    4


.text
	#int x, y, maximo;
	#int main (void) {
	#	maximo = x;
	#	if (maximo < y)
	#		maximo = y;
	#	return 0;
	#}
	
	lw    $s0, x
	lw    $s1, y
	
	sw    $s0, maximo
	lw    $s2, maximo
	
	if:
		bge    $s2, $s1, endif
	then:
		sw     $s1, maximo	
	endif:

		
li	$v0,17
li	$a0,0
syscall	
	
		