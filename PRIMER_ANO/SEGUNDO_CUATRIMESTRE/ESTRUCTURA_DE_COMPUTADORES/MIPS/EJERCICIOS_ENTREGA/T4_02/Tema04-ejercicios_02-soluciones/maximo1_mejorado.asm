
          .data
# int x,y,maximo;
x:        .space  4	# $s0
y:        .space  4	# $s2
maximo:   .space  4	

          .text
main:				# int main (void) {
          lw      $s0,x		# 	maximo = x;
          sw      $s0,maximo
if:				# 	if (maximo < y)
          #lw      $s1,maximo	Ya tenemos el máximo en $s0
          lw      $s2,y
          #bge     $s1,$s2,endif
          bge     $s0,$s2,endif	#comparamos con $s0 porque $s1 no lo hemos inicializado
then:				#       then (parte cierto)
          #lw      $s2,y	innecesario, ya tenemos y en $s2
          sw      $s2,maximo	# 		maximo = y;
endif:
          li       $v0,17	# 	return 0;
          li       $a0,0
          syscall
end_main:			# }




