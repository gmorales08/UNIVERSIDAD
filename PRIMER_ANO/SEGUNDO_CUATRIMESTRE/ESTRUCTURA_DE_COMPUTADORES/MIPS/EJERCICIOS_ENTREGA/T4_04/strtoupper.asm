#char string[32];
#register int i;
#register char caracter;
#int main (void) {
#	i = 0;
#	while ( (caracter = string[i]) != ’\0’ ) {
#		if ( (caracter >= ’a’) && (caracter <= ’z’) )
#			string[i] = caracter -’a’ + ’A’;
#		i++;
#	}
#	return 0;
#}

.data
	string:    .asciiz    32
	
.text
	la       $s0, string
	li       $t0, 0      # $t0 <- i = 0
	
	while:
	lb       $t1, 0($s0) # $t1 <- caracter = string[i]
	beqz     $t1, end_while
	cuerpo_while:
		 if:
		 sgeu     $t2, $t1, 'a'
		 sleu     $t3, $t1, 'z'
		 and      $t2, $t2, $t3
		 beqz     $t2, end_if
		 cuerpo_if:
		 subiu    $t2, $t1, 'a'
		 addiu    $t2, $t2, 'A'
		 sb       $t2, 0($s0)
		 end_if:
	addiu    $t0, $t0, 1
	addiu    $s0, $s0, 1
	j        while
	end_while:

li      $v0, 17
li      $at,  0
syscall	