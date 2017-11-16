add $0 $1 #1 ; set f(1) = 1
add $0 $6 #3 ; for #3 = 6:
add #0 #1 #2 ; store f(n-1) + f(n) to #2
add #1 $0 #0 
add #2 $0 #1
sub #3 $1 #3 ; #3 -= 1
jnz #3 #2 ; end for if #3 == 0
print #0
