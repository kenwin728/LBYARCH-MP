#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float dotproductinasm(int n, float* vec1, float* vec2);

float dotproductinc(int n, float vec1[], float vec2[]) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (vec1[i] * vec2[i]);
	}
	return sum;
}
int main() {
	int n = 3;
	float vec1[3] = {1.2, 2.0, 3.5};
	float vec2[3] = {2.0, 3.0, 7.2};
	float sdot = dotproductinasm(n, vec1, vec2);
	printf("Answer of assembly is %f\n", sdot);
	sdot = dotproductinc(n, vec1, vec2);
	printf("Answer of c is %f", sdot);


	return 0;
}