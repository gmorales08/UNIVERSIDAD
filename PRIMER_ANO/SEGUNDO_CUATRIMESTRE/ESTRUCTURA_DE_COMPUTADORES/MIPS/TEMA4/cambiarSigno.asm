.data

x:    .data    4
y:    .data    4


.text

li      $t0, 0xFFFFFFFF
lw      $s0, x
lw      $s1, y

xor     $t1, $t0, $s0
addi    $s4, $s3, 1


li      $v0,17
li      $a0,0
syscall