#int numero;
#char string[10];
#register int i, cifra; // cifra tiene el ordinal del carácter leído
#int main (void) {
#	numero = 0;
#	i = 0;
#	while ( (cifra = string[i]) != ‘\0’ ) {
#		numero = numero * 10 + (cifra-'0');
#		i = i + 1;
#	}
#	return 0;
#}

.data
	numero:    .space    4
	string:    .space   10
	
.text
	lw       $s0, numero
	la       $s1, string
	li       $s0, 0
	li       $t0, 0      # $t1 <- i = 0
	
	while:
	lb       $t1, 0($s1) # $t1 <- cifra = string[i]
	beqz     $t1, end_while
	cuerpo_while:
	mul      $t2, $s0, 10
	subi     $t3, $t1, '0'
	add      $s0, $t2, $t3
	addiu    $t0, $t0, 1
	addiu    $s1, $s1, 1
	j        while
	end_while:
	sw       $s0, numero

li      $v0, 17
li      $at,  0
syscall    