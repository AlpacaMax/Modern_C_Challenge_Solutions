// Challenge 2 Numerical derivatives
//
// Author: Tian(Maxwell) Yang
//
// Implement the numerical derivative `double f(double x)` of a function `double F(double x)`

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double DELTA = 0.0001;

double F(double x) { return x*x; }

double f(double x) {
	return (F(x+DELTA) - F(x-DELTA)) / (2*DELTA);
}

double F_der(double x) { return 2*x; }

int main() {
	double x = 3.1415;
	double f_res = f(x);
	double F_der_res = F_der(x);

	printf("Calculated Derivative: %g\nActual Derivative: %g\n", f_res, F_der_res);
	if (fabs(F_der_res - f_res) < 0.0001)
		printf("The calculated derivative is correct\n");
	else
		printf("The calcualted derivative is incorrect\n");

	return EXIT_SUCCESS;
}
