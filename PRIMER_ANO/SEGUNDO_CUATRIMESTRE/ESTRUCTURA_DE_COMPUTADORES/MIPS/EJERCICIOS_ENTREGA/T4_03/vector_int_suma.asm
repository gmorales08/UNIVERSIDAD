#int v1[10], v2[10];
#register int i;
#int main (void) {
#	i = 0;
#	do {
#		v1[i] = v1[i] + v2[i];
#		i = i + 1;
#	} while (i <> 10);
#	return 0;
#}

.data
	v1:    .space    40
	v2:    .space    40

.text
	li      $t0, 0        # $t0 <- i = 0
	la      $s0, v1       # $s0 <- v1[0]
	la      $t1, v2       # $t1 <- v2[0]
	do:
	lw      $t2, 0($s0)   # $t2 <- v1[i]
	lw      $t3, 0($t1)   # $t3 <- v2[i]
	add     $t2, $t2, $t3 # $t2 <- v1[i] + v2[i]
	sw      $t2, 0($s0)
	addu    $s0, $s0, 4
	addu    $t1, $t1, 4
	addu    $t0, $t0, 1
	while:
	bne     $t0, 10, do
	end_do_while:


li	$v0,17
li	$a0,0
syscall