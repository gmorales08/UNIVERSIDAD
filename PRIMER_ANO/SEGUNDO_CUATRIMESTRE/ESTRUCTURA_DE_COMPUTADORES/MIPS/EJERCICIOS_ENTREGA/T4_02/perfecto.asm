#int n, perfecto;
#register int i, suma;
#int main (void) {
#	suma = 1;
#	i = 2;
#	while (i < n) {
#		if (n % i == 0)
#			suma = suma + i;
#		i++;
#	}
#	perfecto = (n == suma);
#	return 0;
#}

.data
	n:           .space    4
	perfecto:    .space    4

.text
	li    $t0, 1 # t0 <- suma
	li    $t1, 2 # t1 <- i
	
	while:
	lw    $s0, n
	bge     $t1, $s0, end_while
		if:
		rem      $t2, $s0, $t1
		bnez     $t2, end_if
			 add    $t0, $t0, $t1
		end_if:
		addiu    $t1, $t1, 1
		b        while
	end_while:
	seq     $s1, $s0, $t0
	sw      $s1, perfecto
	
li	$v0,17
li	$a0,0
syscall