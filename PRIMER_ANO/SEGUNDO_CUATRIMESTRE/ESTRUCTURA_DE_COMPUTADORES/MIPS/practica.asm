##define N 16
#int vectorX[N]; // N es una constante
#int vectorY[N]; // N es una constante
#register int i;
#...
#i = 0;
#while (i < N) {
#   vectorY[i] = vectorX[i];
#   i++;
#}

.data
	x:    .word     1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
#	x:    .space    64
	y:    .space    64
	      .eqv    N,16
	      
.text
	la        $s0, x            # $s0 <- puntero a x[0]
	la        $s1, y            # $s1 <- puntero a y[0]
	li        $t0, 0            # $t0 <- i = 0
	
	while:
	bge       $t0, N, end_while # Evaluamos si i < N, en caso contrario saltamos al final del while
	cuerpo_while:
	lw        $t1, 0($s0)       # $t1 <- x[i]
	sw        $t1, 0($s1)       # y[i] = x[i]
	
	addi      $s0, $s0, 4       # movemos el puntero de x a la siguiente posicion
	addi      $s1, $s1, 4       # movemos el puntero de y a la siguiente posicion       
	addi      $t0, $t0, 1       # i = i + 1
	j         while             # Saltamos al comienzo del while
	end_while:
	

li      $v0, 17
li      $at,  0
syscall 