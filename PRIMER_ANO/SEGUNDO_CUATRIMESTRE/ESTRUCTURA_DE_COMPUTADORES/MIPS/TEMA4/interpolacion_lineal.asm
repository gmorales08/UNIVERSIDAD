.data 

x:     .space	 4
y:     .space	 4
xb:    .space	 4
yb:    .space    4
zb:    .space    4

		
.text

lw     $s0,x
lw     $s1,y
lw     $s2,xb
lw     $s3,yb

sle    $t0, $s0, $s1
and    $t1, $s2, $s3
or     $t3, $t0, $t1

sw     $t3, sb



li     $v0,17
li     $a0,0
syscall