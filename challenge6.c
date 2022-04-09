// Challenge 6 Linear Algebra
//
// Author: Tian(Maxwell) Yang
//
// Implement vector-to-vector and matrix-to-matrix products
// I know how to perform matrix inversion but I'm too lazy to write the code

#include <stdio.h>
#include <stdlib.h>

double vectorDotProduct(double v1[], double v2[], size_t size) {
	double result = 0;

	for (size_t i = 0; i < size; ++i) {
		result += v1[i] * v2[i];
	}

	return result;
}

void matrixProduct(size_t m, size_t n, size_t n2, double m1[n][m], double m2[m][n2], double result[n][n2]) {
	double localresult;

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n2; ++j) {
			localresult = 0;
			for (size_t k = 0; k < m; ++k) {
				localresult += m1[i][k] * m2[k][j];
			}
			result[i][j] = localresult;
		}
	}
}

int main() {
	double v1[3] = {1, 3, -5};
	double v2[3] = {4, -2, -1};
	double m1[4][3] = {
		{1, 0, 1},
		{2, 1, 1},
		{0, 1, 1},
		{1, 1, 2},
	};
	double m2[3][3] = {
		{1, 2, 1},
		{2, 3, 1},
		{4, 2, 2},
	};
	double result[4][3];

	printf("Dot product of v1 and v2: %g\n", vectorDotProduct(v1, v2, 3));

	matrixProduct(3, 4, 3, m1, m2, result);

	printf("Matrix product of m1 and m2:\n");
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			printf("%g ", result[i][j]);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
