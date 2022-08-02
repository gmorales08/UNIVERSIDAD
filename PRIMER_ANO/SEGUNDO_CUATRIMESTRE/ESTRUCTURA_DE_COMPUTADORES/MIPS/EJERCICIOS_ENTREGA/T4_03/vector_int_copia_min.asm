##define N 16
#int X[N], Y[N], Z[N];
#register int i, temp1, temp2;
#int main (void) {
#	i = 0;
#	while (i < N) {
#		temp1 = X[i];
#		temp2 = Y[i];
#		if (temp1 < temp2)
#			Z[i]=temp1;
#		else
#			Z[i]=temp2;
#		i++;
#	}
#	return 0;
#}

.data
	x:    .space    64
	y:    .space    64
	z:    .space    64
	      .eqv    N,16
	
.text
	la       $t3, x      # $t3 <- x[0] (puntero)
	la       $t4, y      # $t4 <- y[0] (puntero)
	la       $t5, z      # $t5 <- z[0] (puntero)
	li       $t0, 0      # $t0 <- i = 0
	
	while:
	bge      $t0, N, end_while
	cuerpo_while:
	lw       $t1, 0($t3) # $t1 <- temp1
	lw       $t2, 0($t4) # $t2 <- temp2
		 if:
		 bge       $t1, $t2, else
		 cuerpo_if:
		 sw        $t1, 0($t5)
		 j         end_if
		 else:
		 sw        $t2, 0($t5)
		 end_if:
	
	addiu    $t3, $t3, 4
	addiu    $t4, $t4, 4
	addiu    $t5, $t5, 4
	addiu    $t0, $t0, 1
	j        while
	end_while:
	

li    $v0, 17
li    $at,  0
syscall