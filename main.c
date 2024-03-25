#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double dotproduct(int n, double* vec1, double* vec2);
int main() {
	int n = 3;
	double vec1[3] = {1.2, 2.0, 3.5};
	double vec2[3] = {2.0, 3.0, 7.2};
	double sdot = dotproduct(n, vec1, vec2);
	printf("Answer is %lf", sdot);



	return 0;
}