#register char *ini, *fin;
#char string[32];
#char palin;
#int main (void) {
#	// Buscar el final de la tira
#	ini = fin = string;
#	while (*fin != ’\0’)
#		fin++;
#	fin--;
#	// Comparar los caracteres
#	palin = ’S’;
#	while (ini < fin) {
#		if (*ini == *fin) {
#			ini++;
#			fin--;
#		}
#		else {
#			palin = ’N’;
#			break;
#		}
#	}
#	return 0;
#}

.data
	string:    .space    32
	palin:     .space     1
	
.text
	la       $s0, string  # $s0 <- *string
	move     $t0, $s0     # $t0 <- *ini
	move     $t1, $s0     # $t1 <- *fin
	lb       $s1, palin   # $s1 <- palin
	
	while_1:
	lb       $t2, 0($s0)  # $t2 <- string[i]	
	beqz     $t2, end_while_1
	cuerpo_while_1:
	addiu    $t1, $t1,  1
	addiu    $s0, $s0,  1
	j        while_1
	end_while_1:
	addi     $t1, $t1, -1
	
	li       $s1, 'S'
	while_2:
	bge      $t0, $t1, end_while_2
	cuerpo_while_2:
		 if:
		 lb       $t2, 0($t0)
		 lb       $t3, 0($t1)
		 bne      $t2, $t3, else
		 cuerpo_if:
		 addiu    $t0, $t0,  1
		 addi     $t1, $t1, -1
		 j        end_if
		 else:
		 li       $s1, 'N'
		 j        end_while_2
		 end_if:
	j        while_2
	end_while_2:
	sb       $s1, palin

li      $v0, 17
li      $at,  0
syscall