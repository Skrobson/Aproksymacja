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
	nie chc� tu nic rusza�, bo nie wiem w kt�rym momencie czego� nie popsuj�, ale nie lepiej by�oby, w tym miejscu pobiera� wska�nik na funkcj�?
	bo praktycznie zawsze korzystamy z jednoarkgumentowej funkcji, wi�c to by wystarczy�o, przynajmniej tak my�l� w tedy r�wnie poprawna by�aby funkcja
	
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

	a p�niejsze wywo�anie by si� odbywa�o w ten spos�b kt�ry napisa�e� w mainie, bo to co napisa�e� wcze�niej nie dziwi� si�, �e zwraca�o b��d

*/