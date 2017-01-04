#pragma once
#include <vector>


int factorial(int n);
//TODO: w newtonie moze dojsc do dzielenia przez 0, zabezpieczyc sie przed tym
//ogarniete
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
/*
	nie chcê tu nic ruszaæ, bo nie wiem w którym momencie czegoœ nie popsujê, ale nie lepiej by³oby, w tym miejscu pobieraæ wskaŸnik na funkcjê?
	bo praktycznie zawsze korzystamy z jednoarkgumentowej funkcji, wiêc to by wystarczy³o, przynajmniej tak myœlê w tedy równie poprawna by³aby funkcja
	
void disctretization(int nodesAmount, double downRange, double upRange, std::vector<double>& x, std::vector<double>& y, double (*f)(double) )
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

	a póŸniejsze wywo³anie by siê odbywa³o w ten sposób który napisa³eœ w mainie, bo to co napisa³eœ wczeœniej nie dziwiê siê, ¿e zwraca³o b³¹d

*/