#int digitos;
#register int i;
#char string[32];
#register char caracter;
#int main (void) {
#	digitos = 0;
#	i = 0;
#	while ( (caracter = string[i]) != ’\0’ ) {
#		if ( (caracter >= ’0’) && (caracter <= ’9’) )
#			digitos++;
#		i++;
#	}
#	return 0;
#}

.data
	digitos:    .space     4
	string:     .space    32

.text
	lw       $s0, digitos
	la       $s1, string
	li       $s0, 0
	li       $t0, 0      # $t0 <- i = 0
	
	while:
	lb       $t1, 0($s1) # $t1 <- caracter = string[i]
	beqz     $t1, end_while
	cuerpo_while:
		 if:
		 sgeu     $t2, $t1, '0'
		 sleu     $t3, $t1, '9'
		 and      $t2, $t2, $t3
		 beqz     $t2, end_if
		 cuerpo_if:
		 addiu    $s0, $s0, 1
		 end_if:
	addiu    $t0, $t0, 1
	addiu    $s1, $s1, 1
	j        while
	end_while:
	sw       $s0, digitos

li      $v0, 17
li      $at,  0
syscall