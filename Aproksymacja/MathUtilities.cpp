#include "MathUtilities.h"

int factorial(int n)
{
	int tempFactorial = 1;
	for (int i = n; i > 1; --i)
		tempFactorial *= i;
	return tempFactorial;
}

double newtonSymbol(int n, int k)
{
	return factorial(n) / (factorial(k)*factorial(n - k));
}