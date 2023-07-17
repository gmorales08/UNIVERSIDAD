#define N 16
#int x[N], y[N];
#register int i, j;
#int main (void) {
#	suma = 0;
#	i = 0;
#	j = N-1;
#	while (i < N) {
#		y[j] = x[i];
#		i++;
#		j--;
#	}
#	return 0;
#}

.data
	x:    .space       64
	y:    .space       64
	      .eqv      N, 16
	
.text
	la         $s0, x         # $s0 <- x[0] (puntero)
	la         $t0, y
	li         $t1, N
	subi       $t1, $t1, 1
	mul        $t1, $t1, 4
	add        $s1, $t0, $t1  # $s1 <- y[N] (puntero)
	
	li         $t0, 0         # $t0 <- suma =  0
	li         $t1, 0         # $t1 <- i    =  0
	li         $t2, N
	addi       $t2, $t2, -1   # $t2 <- j    = 15
	
	while:
	bge        $t1, N, end_while
	cuerpo_while:
	lw         $t3, 0($s0)    # $t3 <- x[i]
	sw         $t3, 0($s1)    # y[j] = x[i]
	addiu      $t1, $t1,  1
	addi       $t2, $t2, -1
	addiu      $s0, $s0,  4
	addi       $s1, $s1, -4
	j          while
	end_while:
	

li    $at,  0
li    $v0, 17
syscall