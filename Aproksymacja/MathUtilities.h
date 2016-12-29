#pragma once
#include <vector>


int factorial(int n);
//TODO: w newtonie moze dojsc do dzielenia przez 0, zabezpieczyc sie przed tym
double newtonSymbol(int n, int k);

template<typename function>
void disctretization(int nodesAmount, double downRange, double upRange, std::vector<double>& x, std::vector<double>& y, function f)
{
	double range = (upRange - downRange) / nodesAmount;
	
	double tempX = downRange;
	for (int i = 0; i <= nodesAmount; ++i)
	{	
		x.push_back( tempX);
		y.push_back(  f(tempX));
		tempX += range;
	}
}