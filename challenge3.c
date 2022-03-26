// Challenge 3 Pi
//
// Author: Tian(Maxwell) Yang
//
// Compute the N first decimal places of Pi. Here I use Machin's formula but
// other ways should suffice as well

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double arctan_item(double coeff, double denominator, double nth) {
	return pow(-1, nth + 1) * coeff / ((2*nth - 1) * pow(denominator, 2*nth - 1));
}

double arctan(double coeff, double denominator, double N) {
	double error_budget = 5 * pow(10, -N-1);
	double result = 0;
	double item, i = 1;

	do {
		item = arctan_item(coeff, denominator, i++);
		result += item;
	} while(fabs(item) > error_budget);

	return result;
}

double calc_pi(double N) {
	return arctan(16, 5, N) - arctan(4, 239, N);
}

int main() {
	double N = 100;
	double pi = calc_pi(N) - 3; 
	int digit;

	printf("3.");
	for (int i = 0; i < N; ++i) {
		pi *= 10;
		digit = (int) pi; 
		printf("%d", digit);
		pi -= digit;
	}
	printf("\n");

	return EXIT_SUCCESS;
}
