;Dot product function for x86-64
section .data
var1 dq 0.0
section .text
bits 64
default rel

global dotproduct

dotproduct:
	xor RBX, RBX ;counter
	movsd xmm0, [var1]
	L1: movsd xmm1, [RDX + RBX]
	movsd xmm2, [R8 + RBX]
	mulsd xmm1, xmm2
	addsd xmm0, xmm1
	add RBX, 8
	LOOP L1

	ret