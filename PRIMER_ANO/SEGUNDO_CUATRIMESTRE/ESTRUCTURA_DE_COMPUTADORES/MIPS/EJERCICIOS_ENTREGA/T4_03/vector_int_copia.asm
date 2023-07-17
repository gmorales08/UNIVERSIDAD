##define N 16
#int x[N], y[N];
#register int i;
#int main (void) {
#	for (i = 0; i < N; i++)
#		y[i] = x[i];
#	return 0;
#}

.data
	x:    .space    64
	y:    .space    64
	
.text
	for:
	la       $s0, x       # x[0]
	la       $s1, y       # y[0]
	addiu    $t0, $s0, 64 # ultima pos. de x
	#addiu    $t1, $s1, 64 # ultima pos. de y
	condicion_for:
	beq      $s0, $t0, end_for
	# beq     $s1, $t1, end_for # tambien podría hacerse tomando y[i] de referencia
	cuerpo_for:
	lw       $t3, 0($s0)  # $t3 contiene x[i]
	sw       $t3, 0($s1)  # guardamos en y[i] el valor de x[i]
	addiu    $s0, $s0, 4  # pasamos a la siguiente pos. (+4 bytes)
	addiu    $s1, $s1, 4
	b        condicion_for
	end_for:

li	$v0,17
li	$a0,0
syscall