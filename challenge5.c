#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

const double DELTA = 0.0001;

double complex F(double complex x) { return x*x; }

double complex f(double complex x) {
	return (F(x+DELTA) - F(x-DELTA)) / (2*DELTA);
}

double complex F_der(double complex x) { return 2*x; }

int main() {
	double complex x = 0.5 + 0.5*I;
	double complex f_res = f(x);
	double complex F_der_res = F_der(x);
	double diff = cabs(F_der_res - f_res);

	printf(
		"Calculated Derivative %f + %fi\nActual Derivative: %f + %fi\n",
		creal(f_res),
		cimag(f_res),
		creal(F_der_res),
		cimag(F_der_res)
	);

	if (diff < 0.0001)
		printf("The calculated derivative is correct\n");
	else
		printf("The calculatec derivative is incorrect\n");

	return EXIT_SUCCESS;
}
