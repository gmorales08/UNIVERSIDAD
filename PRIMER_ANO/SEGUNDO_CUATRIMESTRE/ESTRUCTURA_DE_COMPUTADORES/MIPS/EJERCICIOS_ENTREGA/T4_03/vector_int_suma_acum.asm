##define N 16
#int X[N], Y[N];
#register int i;
#int main (void) {
#	Y[0] = X[0];
#	i = 1;
#	while (i < N)
#		Y[i] = Y[i-1] + X[i];
#	return 0;
#}

.data
	x:    .space    64
	y:    .space    64
	      .eqv    N,16
	      
.text	
	la       $s0, y      # $s0 <- y[0] (puntero)
	la       $t1, x      # $t1 <- x[0] (puntero)
	lw       $t0, x      
	sw       $t0, 0($s0)
	li       $t0, 1      # $t0 <- i = 0
	
	while:
	bge      $t0, N, end_while
	cuerpo_while:
	lw       $t2, 0($t1) # x[i]
	addi     $t3, $s0, -4 
	lw       $t3, 0($t3) # y[i - 1]
	add      $t2, $t2, $t3
	sw       $t2, 0($s0)
	
	addiu    $s0, $s0,  4
	addiu    $t1, $t1,  4
	addiu    $t0, $t0,  1
	j        while
	end_while:
	

li    $at,  0
li    $v0, 17
syscall