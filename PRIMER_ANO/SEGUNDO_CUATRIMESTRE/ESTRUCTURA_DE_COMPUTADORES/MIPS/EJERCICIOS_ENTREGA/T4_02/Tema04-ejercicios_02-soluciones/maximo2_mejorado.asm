	.data
# int x,y,maximo;
x:	.space  4	# $s0
y:	.space  4	# $s1
maximo:	.space  4	
	.text
main:				# int main (void) {
if:				# if (x >= y)
	lw	$s0,x
	lw	$s1,y
	bge	$s0,$s1,then
else:				# else (parte falso)
        #lw	$s1,y	innecesario, ya hab�amos cargado y
	sw	$s1,maximo	#	maximo = y;
	j	endif
then:				# then (parte cierto)
	#lw	$s0,x	innecesario, ya hab�amos cargado x
	sw	$s0,maximo	#	maximo = x;
endif:
	li	$v0,17		# 	return 0;
	li	$a0,0
	syscall
end_main:			# }
