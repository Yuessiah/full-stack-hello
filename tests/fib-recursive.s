jmp @start
fib:
jnz #2 @n!=0
ret
n!=0:
sub #2 $1 #3
jnz #3 @n!=1
add #6 $1 #6
ret
n!=1:
sub #2 $1 #2
call @fib
add #2 $1 #2
sub #2 $2 #2
call @fib
add #2 $2 #2
ret
start:
add $0 $6 #2
call @fib
print #6
