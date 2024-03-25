;Dot product function for x86-64
section .data
var1 dw 0.0
section .text
bits 64
default rel

global dotproductinasm

dotproductinasm:
	xor RBX, RBX ;counter
	movss xmm0, [var1]
	L1: movsd xmm1, [RDX + RBX]
	movss xmm2, [R8 + RBX]
	mulss xmm1, xmm2
	addss xmm0, xmm1
	add RBX, 4
	LOOP L1

	ret