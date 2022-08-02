      .data
A:    .space 4
B:    .space 4
C:    .space 4
      .text
# A := B+C;
      lw $s2,B
      lw $s3,C
      add $s1,$s2,$s3
      sw  $s1,A