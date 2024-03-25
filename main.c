// Reyes, Kenwin Hans (S16) || Racela, Mel Geoffrey (S16)
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
	/* 
	int n = 3;		// 3 elements
	float vec1[3] = {1.2, 2.0, 3.5};
	float vec2[3] = {2.0, 3.0, 7.2};
	
	int n = 1 << 20; // 2^20 elements
	float* vec1 = (float*)malloc(sizeof(float) * n);
	float* vec2 = (float*)malloc(sizeof(float) * n);

	int n = 1 << 24; // 2^24 elements
	float* vec1 = (float*)malloc(sizeof(float) * n);
	float* vec2 = (float*)malloc(sizeof(float) * n);

	int n = 1 << 29	; // 2^29 elements
	float* vec1 = (float*)malloc(sizeof(float) * n);
	float* vec2 = (float*)malloc(sizeof(float) * n);
	*/

	int n = 1 << 29;
	float* vec1 = (float*)malloc(sizeof(float) * n);
	float* vec2 = (float*)malloc(sizeof(float) * n);

	// Making sure the memory was allocated successfully
	if (!vec1 || !vec2) {
		fprintf(stderr, "Memory allocation failed!\n");
		free(vec1);
		free(vec2);
		return EXIT_FAILURE;
	}

	// Initializing the vectors with random float values between -10.0 and +10.0
	for (int i = 0; i < n; i++) {
		vec1[i] = (float)rand() / (RAND_MAX / 20.0f) - 10.0f;
		vec2[i] = (float)rand() / (RAND_MAX / 20.0f) - 10.0f;
	}

	// Timing the Assembly kernel
	clock_t start_asm = clock();
	float sdot_asm = dotproductinasm(n, vec1, vec2);
	clock_t end_asm = clock();

	// Timing the C kernel
	clock_t start_c = clock();
	float sdot_c = dotproductinc(n, vec1, vec2);
	clock_t end_c = clock();

	// Calculating the time taken by each kernel
	double time_asm = (double)(end_asm - start_asm) / CLOCKS_PER_SEC;
	double time_c = (double)(end_c - start_c) / CLOCKS_PER_SEC;

	printf("Answer of Assembly is: %f\n", sdot_asm);
	printf("Time taken by Assembly: %f seconds\n", time_asm);
	printf("Answer of C is: %f\n", sdot_c);
	printf("Time taken by C: %f seconds\n", time_c);

	// Free allocated memory
	free(vec1);
	free(vec2);
	return 0;
}