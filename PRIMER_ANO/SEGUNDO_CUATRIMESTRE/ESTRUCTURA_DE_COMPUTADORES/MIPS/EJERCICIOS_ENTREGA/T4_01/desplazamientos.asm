.data 
	x:       .space    4
	lon:     .space    4
	xsll:    .space    4   
	xsrl:    .space    4
	xsra:    .space    4
	xrol:    .space    4
	xror:    .space    4
	
	
.text
	lw      $s0, x
	lw      $s1, lon
	
	sllv    $s2, $s0, $s1
	sw      $s2, xsll
	srlv    $s3, $s0, $s1
	sw      $s3, xsrl
	srav    $s4, $s0, $s1
	sw      $s4, xsra
	rol     $s5, $s0, $s1
	sw      $s5, xrol
	ror     $s6, $s0, $s1
	sw      $s6, xror
	

li	$v0,17
li	$a0,0
syscall