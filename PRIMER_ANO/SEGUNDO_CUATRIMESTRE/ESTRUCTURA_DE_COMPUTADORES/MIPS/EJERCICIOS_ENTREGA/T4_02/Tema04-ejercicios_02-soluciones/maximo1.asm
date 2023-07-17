
          .data
# int x,y,maximo;
x:        .space  4	#$s0
y:        .space  4	#$s2
maximo:   .space  4	

          .text
main:				# int main (void) {
	lw      $s0,x		#	maximo = x;
	sw      $s0,maximo
if:				#	if (maximo < y)
	lw	$s1,maximo
	lw      $s2,y
	bge     $s1,$s2,endif
then:				#       then (parte cierto)
	lw      $s2,y		# 		maximo = y;
	sw      $s2,maximo
endif:
	li       $v0,17		#	return 0;
	li       $a0,0
	syscall
end_main:			# }




