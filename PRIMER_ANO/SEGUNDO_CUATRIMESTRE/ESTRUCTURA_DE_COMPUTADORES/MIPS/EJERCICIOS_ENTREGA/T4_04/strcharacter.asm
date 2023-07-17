#int veces;
#char string[32], caracter;
#register int i;
#int main (void) {
#	veces = 0;
#	i = 0;
#	while (string[i] != ‘\0’) {
#		if (string[i] == character)
#			veces++;
#		i++;
#	}
#	return 0;
#}

.data
	veces:       .space      4
	string:      .asciiz    32
	caracter:    .byte       1

.text
	lw       $s0, veces
	li       $s0, 0
	la       $s1, string
	lb       $s2, caracter
	li       $t0, 0     # $t0 <- i = 0
	
	while:
	lb       $t1, 0($s1)
	beqz     $t1, end_while
		 if:
		 bne      $t1, $s2, end_if
		 cuerpo_if:
		 addiu    $s0, $s0, 1
		 end_if:
	addiu    $t0, $t0, 1
	addiu    $s1, $s1, 1
	j        while
	end_while:
	sw       $s0, veces
	
li      $v0, 17
li      $at,  0
syscall