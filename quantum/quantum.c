#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>

#define VECTOR_SIZE 2

double complex quibit1[VECTOR_SIZE][1] = {
	{0.0 + 0*I},
	{1.0 + 0*I}
};

double complex quibit2[VECTOR_SIZE][1] = {
	{(1.0/sqrt(2.0)) + 0*I},
       	{(1.0/sqrt(2.0)) + 0*I}
};	

double complex quibit3[VECTOR_SIZE][1] = {
	{(1.0/3.0) + (2.0/3.0)*I},
	{(-2.0/3.0) + 0*I}
};

//sum of abs(vector)^2
void euclidean_norm(double complex quibit[VECTOR_SIZE][1]) {
	double result = 0.0;
	for(size_t i = 0; i < VECTOR_SIZE; i++) {
		double magnitude = cabs(quibit[i][0]);
		result += pow(magnitude, 2.0);
	}
	printf("%.2f\n", result);
}
	
#define QUIBIT_SIZE (sizeof(quibit) / sizeof(quibit[0]))
void print_quibit(double complex quibit[VECTOR_SIZE][1]) {
	for(size_t i = 0; i < VECTOR_SIZE; i++) {
		printf("real: %.3f | imaginary: %.3f\n", creal(quibit[i][0]), 
							 cimag(quibit[i][0]));
	}
}

int main() {
	printf("quibit1\n");
	print_quibit(quibit1);
	printf("Euclidean Norm: ");
	euclidean_norm(quibit1);
	printf("-----------------------------------\n");

	printf("quibit2\n");
	print_quibit(quibit2);
	printf("Euclidean Norm: ");
	euclidean_norm(quibit2);
	printf("-----------------------------------\n");

	printf("quibit3\n");
	print_quibit(quibit3);
	printf("Euclidean Norm: ");
	euclidean_norm(quibit3);
	printf("-----------------------------------\n");

	return 0;
}

