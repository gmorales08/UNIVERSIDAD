#int dato, unos;
#register int tmp, mascara;
#int main (void) {
#	unos = 0;
#	tmp = dato;
#	mascara = 0x80000000;
#	while (tmp != 0) {
#		if (tmp & mascara != 0)
#			unos = unos + 1;
#		tmp = tmp << 1;
#	}
#	return 0;
#}
	
.data
	dato:    .space    4
	unos:    .space    4
	
.text
	lw      $s0, dato
	lw      $s1, unos
	
	li      $s0, 0
	move    $t0, $s0 # $t0 (tmp) = dato
	li      $t1, 0x80000000
	
	while:
	beqz    $t0, endwhile
		if:
		and      $t2, $t0, $t1
		beqz     $t2, endif
		addiu    $s1, $s1, 1
		endif:
	sll     $t0, $t0, 1
	b       while
	endwhile:
	sw      $s1, unos
	
li	$v0,17
li	$a0,0
syscall