.eqv val_x 2
.eqv v2 8

.text
.globl main
main:
	# 2x + 8
	ori $t0, $zero, val_x
	ori $t2, $0, v2
	add $t1, $t0, $t0  # y = x + x
	add $t1, $t0, $t2  # y += 8
	jr $ra