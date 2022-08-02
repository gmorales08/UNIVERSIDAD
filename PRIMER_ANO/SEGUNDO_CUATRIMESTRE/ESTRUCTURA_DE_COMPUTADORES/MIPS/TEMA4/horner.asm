# TEMA 4 Hoja 5 Ej. 3

.data
	grado:     .word      4
	polinomio: .space    40
	x0:        .float     4
	valor:     .float     4   
	
	main:
		l.s    polinomio, $t1
		l.s    0($t1),    $f1
		l.s    valor,     $t2
		
		