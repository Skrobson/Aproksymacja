#include "aproxymationUtilities.h"
#include <iostream>

int factorial2(int n)
{
	int tempFactorial = 1;
	for (int i = n; i > 1; --i)
		tempFactorial *= i;
	return tempFactorial;
}

double newtonSymbol2(int n, int k)
{
	return factorial2(n)/(factorial2(k)*factorial2(n-k));
}

double linearTransformation( double range,double x0, double x)
{
	return (x-x0)/range;
}

double grammProduct(double r, int n)
{
	
	if (n == 0)
		return 1;
	else if (n == 1)
		return r;

	double tempProduct = r;
	for (int i = 1; i < n; ++i)
		tempProduct *= (r - i);
	return tempProduct;
}

double grammPolymonial(int nodeAmount, int degree, double q) //std::vector<double> normalizeValue)
{
	double sum = 0.0;
	for (int i = 0; i <= degree; ++i)
	{
		double temp = 0.0;
		temp = pow(-1, i);
		temp *= newtonSymbol2(degree,i);
		temp *= newtonSymbol2(degree + i, i);
		temp *= grammProduct(q, i)/grammProduct(nodeAmount,i);
		sum += temp;

	}
	return sum;
}

double cj(int nodesAmount,int degree ,std::vector<node> nodes,std::vector<double> q)
{
	double sum = 0;

	for (int i = 0; i <= nodesAmount; ++i)
	{
		sum += nodes[i].y* grammPolymonial(nodesAmount,degree, q[i]);
	}
	return sum;
}

double sj(int nodesAmount,int degree, std::vector<double> q)
{
	double sum = 0.0;
	for (int i=0;i<=nodesAmount;++i)
	{
		sum+=pow(grammPolymonial(nodesAmount, degree, q[i]), 2);
	}
	return sum;
}

double aj(int nodesAmount, int degree, std::vector<node> nodes, std::vector<double> q)
{
	double cJ = cj(nodesAmount, degree, nodes, q);
	double sJ = sj(nodesAmount, degree, q);
	double aj = cJ/sJ;
	std::cout << "c" << degree << " " << cJ << "s" << degree << " " << sJ << std::endl;
	return aj;
}

double aproximation(int nodesAmount, int degree, std::vector<double> q, std::vector<node> nodes)
{
	double sum = 0.0;
	for (int i = 0; i <= degree; ++i)
	{
		double p = grammPolymonial(nodesAmount, i, q[i]);
		std::cout << "P" <<i<<" :"<< p << " "<<std::endl;
		sum += (cj(nodesAmount, i, nodes, q) / sj(nodesAmount, i, q)) * p;
	}
	return sum;
}
