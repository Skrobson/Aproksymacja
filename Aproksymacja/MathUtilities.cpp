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
	if ((k > 0) && (k < n))
		return factorial(n) / (factorial(k)*factorial(n - k));
	else if ((k == 0) || (k == n))
		return 1;
	else
		//dobr� opcj� jest zrobienie tutaj wyj�tku kt�ry po prostu przerwa�by program bez dalszych ceregieli
		//i w mainie ponad g��wn� p�tl� zaj�� si� wszystkimi wyj�tkami, dla dzielenia przez 0 na przyk�ad kod -1
		//tu jest te� zamieszczony wypadek kiedy n < k lub kt�re� jest niedodatnie
		//throw -1 ;
		return -1;
}