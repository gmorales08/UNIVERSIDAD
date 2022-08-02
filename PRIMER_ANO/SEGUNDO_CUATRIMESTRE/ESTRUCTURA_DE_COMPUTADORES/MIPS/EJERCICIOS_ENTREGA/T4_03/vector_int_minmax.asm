#define N 16
#int v[N], maximo, minimo;
#register int i, aux;
#int main (void) {
#	maximo = v[0];
#	minimo = maximo;
#	for (i = 1; i < N; i++) {
#		aux = v[i];
#		if (aux < minimo)
#			minimo = aux;
#		else if (aux > maximo)
#			maximo = aux;
#	}
#	return 0;
#}

.data
	v:         .space    64
	maximo:    .space     4
	minimo:    .space     4

.text
	la       $s0, v       # $s0 <- v[0] este contiene la direccion de memoria
	lw       $t0, 0($s0)  # $t0 <- v[0] este contiene el valor 
	sw       $t0, maximo
	sw       $t0, minimo
	
	for:
	li       $t0, 1       # $t0 <- i = 1
	lw       $t1, maximo
	lw       $t2, minimo 
	condicion_for:
	bge      $t0, 16, end_for
	cuerpo_for:
	lw       $t3, 0($s0)  # $t3 <- aux = v[i]
		 if:
		 bge     $t3, $t2, else_if
		 cuerpo_if:
		 move    $t2, $t3
		 else_if:
		 ble     $t3, $t1, end_if
		 cuerpo_else_if:
		 move    $t1, $t3
		 end_if:
	addiu    $s0, $s0, 4
	addiu    $t0, $t0, 1
	j        condicion_for
	end_for:
	sw       $t1, maximo
	sw       $t2, minimo


li	$v0,17
li	$a0,0
syscall