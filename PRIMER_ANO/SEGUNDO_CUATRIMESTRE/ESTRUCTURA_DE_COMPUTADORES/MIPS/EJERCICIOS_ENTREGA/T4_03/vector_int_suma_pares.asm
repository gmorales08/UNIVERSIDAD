#define N 16
#int vector[N], suma;
#register int i, temp;
#int main (void) {
#	suma = 0;
#	i = 0;
#	while (i < N) {
#		temp = vector[i];
#		if (temp % 2 == 0)
#			suma = suma + temp;
#		i++;
#	}
#	return 0;
#}

.data
	vector:    .space    64
	suma:      .space     4

.text
	la       $s0, vector
	lw       $s1, suma
	li       $s1, 0
	li       $t1, 0      # $t1 <- i = 0
	while:
	bge      $t1, 16, end_while
	cuerpo_while:
	lw       $t0, 0($s0) # $t0 <- vector[i]  # tambien uso $t0 para temp 
	         if:
	         rem     $t2, $t0, 2
	         bnez    $t2, end_if
	         cuerpo_if:
	         add     $s1, $s1, $t0
	         end_if:
	addiu    $s0, $s0, 4
	addiu    $t1, $t1, 1
	j        while
	end_while:
	sw       $s1, suma
		
li	$v0,17
li	$a0,0
syscall