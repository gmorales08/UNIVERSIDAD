.data
	x:         .space    4
	y:         .space    4
	maximo:    .space    4


.text
	#int x, y, maximo;
	#int main (void) {
	#	if (x >= y)
	#		maximo = x;
	#	else
	#		maximo = y;
	#	return 0;
	#}
	
	lw    $s0, x
	lw    $s1, y
	
	if:
		bge    $s0, $s1, then
	else:
		sw     $s1, maximo
		j      endif
	then:
		sw     $s0, maximo
	endif:
	
		
li	$v0,17
li	$a0,0
syscall